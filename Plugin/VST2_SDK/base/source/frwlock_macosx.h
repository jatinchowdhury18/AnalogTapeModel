//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/frwlock_macosx.h
// Created by  : Steinberg, 2014
// Description : MACOSX implementation for RW locks (multiple reader, single writer)
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-----------------------------------------------------------------------------
// This Software Development Kit may not be distributed in parts or its entirety  
// without prior written agreement by Steinberg Media Technologies GmbH. 
// This SDK must not be used to re-engineer or manipulate any technology used  
// in any Steinberg or Third-party application or software module, 
// unless permitted by law.
// Neither the name of the Steinberg Media Technologies nor the names of its
// contributors may be used to endorse or promote products derived from this 
// software without specific prior written permission.
// 
// THIS SDK IS PROVIDED BY STEINBERG MEDIA TECHNOLOGIES GMBH "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL STEINBERG MEDIA TECHNOLOGIES GMBH BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//----------------------------------------------------------------------------------

#ifndef __frwlock_macosx__
#define __frwlock_macosx__

#include "base/source/frwlock_generic.h"

namespace Steinberg {

//---------------------------------------------
// MacOSX supports since OSX 10.7 an efficient recursive RWLock (user space locking for readers)
// With a Writer preference.
//
// However OSX pthread_rwlock rejects "recursive read after write", as required for FRwLock
// Man Page: "The results of acquiring a read lock while the calling 
//	          thread holds a write lock are undefined."
// To catch this manage recursion counting outside the pthread_rwlock,
// Two strategies:
// 1. wrap recursion counting around read/write locks with RWLockRecursion (PThreadWriterPreferenceRWLock)
//    Advantages: extended debug support via ASSERT, to catch potential misuse
// 2. limit recursion counting to write lock holding thread only (PThreadSlimWriterPreferenceRWLock)
//    Advantages: low memory footprint
//    Note: Only calls from the write holding thread provide some debug checking before the deadlock
//
// For reader preference the PThreadReaderPreferenceRWLock is provided.
// It implements reader preference
// Any writer is blocked until all readers are done.
// New readers will block the writer further.
//---------------------------------------------


//---------------------------------------------
// PThreadWriterPreferenceRWLock
// Strategy 1
//---------------------------------------------
struct PThreadWriterPreferenceRWLock
{
public:
	//---------------------------------------------
	PThreadWriterPreferenceRWLock ()
	: valid (false)
	{
		RWLockRecursion::initializeGlobalRecursionData ();
		
		int result = pthread_rwlock_init (&rwLock, 0);
		PANIC_ASSERT (result == 0, result)
		valid = result == 0 ? true : false;
	};
	
	//---------------------------------------------
	~PThreadWriterPreferenceRWLock ()
	{
		if (valid)
		{
			int result = pthread_rwlock_destroy (&rwLock);
			PANIC_ASSERT (result == 0, result)
		}
	}

	//---------------------------------------------
	inline bool verify ()
	{
		return valid;
	}

	//---------------------------------------------
	inline bool waitToRead ()
	{
		int32 recursionCount = RWLockRecursion::acquireRecursionCount (this, RWLockRecursion::kReadAccess);
		if (recursionCount == 1)	// only acquire read access in the first call
		{
			int result = pthread_rwlock_rdlock (&rwLock);
			PANIC_ASSERT (result == 0, result)
			return result == 0;
		}
		return true;
	}
	
	//---------------------------------------------
	inline bool doneReading ()
	{
		return checked_unlock (RWLockRecursion::kReadAccess);
	}
	
	//---------------------------------------------
	inline bool waitToWrite ()
	{
		int32 recursionCount = RWLockRecursion::acquireRecursionCount (this, RWLockRecursion::kWriteAccess);
		if (recursionCount <= 1)	// only acquire write access in the first call, or for recursive lock force a deadlock
		{
			int result = pthread_rwlock_wrlock (&rwLock);
			PANIC_ASSERT (result == 0, result)
			return result == 0;
		}
		return true;
	}

	//---------------------------------------------
	inline bool doneWriting ()
	{
		return checked_unlock (RWLockRecursion::kWriteAccess);
	}

private:
	//---------------------------------------------
	bool checked_unlock (int accessType)
	{
		int32 recursionCount = RWLockRecursion::releaseRecursionCount (this, accessType);
		if (recursionCount == 0)	// only release in the last round
		{
			int result = pthread_rwlock_unlock (&rwLock);
			PANIC_ASSERT (result == 0, result)
			return result == 0;
		}
		return true;
	}

	pthread_rwlock_t rwLock;
	bool valid;
};

//---------------------------------------------
// PThreadSlimWriterPreferenceRWLock
// Strategy 2
//---------------------------------------------
struct PThreadSlimWriterPreferenceRWLock
{
public:
	//---------------------------------------------
	PThreadSlimWriterPreferenceRWLock ()
	: valid (false)
	{
		writerThread = 0;
		writerThreadRecursionCount = 0;
		
		int result = pthread_rwlock_init (&rwLock, 0);
		PANIC_ASSERT (result == 0, result)
		valid = result == 0 ? true : false;
	};
	
	//---------------------------------------------
	~PThreadSlimWriterPreferenceRWLock ()
	{
		if (valid)
		{
			int result = pthread_rwlock_destroy (&rwLock);
			PANIC_ASSERT (result == 0, result)
		}
	}
	
	//---------------------------------------------
	inline bool verify ()
	{
		return valid;
	}
	
	//---------------------------------------------
	inline bool waitToRead ()
	{
		if (writerThread == pthread_self ())
			return incrementWriterRecursionCount ();

		int result = pthread_rwlock_rdlock (&rwLock); // oops read lock could not be acquired, check result what was wrong
		PANIC_ASSERT (result == 0, result)
		return result == 0;
	}
	
	//---------------------------------------------
	inline bool doneReading ()
	{
		return performUnlock (true);
	}
	
	//---------------------------------------------
	inline bool waitToWrite ()
	{
		if (writerThread == pthread_self ())
			return incrementWriterRecursionCount ();

		int result = pthread_rwlock_wrlock (&rwLock);
		PANIC_ASSERT (result == 0, result)	// oops write lock could not be acquired, check result what was wrong

		if (result == 0)
		{
			PANIC_ASSERT (writerThreadRecursionCount == 0, RWLockRecursion::kErrorLockInbalance)
			PANIC_ASSERT (writerThread == 0, RWLockRecursion::kErrorLockInbalance)

			// write lock successfully acquired
			writerThread = pthread_self ();	// register yourself as the writer
			writerThreadRecursionCount = 1;	// start with a clean count
		}
		return result == 0;
	}

	//---------------------------------------------
	inline bool doneWriting ()
	{
		PANIC_ASSERT (writerThread == pthread_self (), RWLockRecursion::kErrorLockInbalance)	// doneWriting () without holding the write lock is really bad
		return performUnlock (false);
	}

private:
	//---------------------------------------------
	inline bool performUnlock (bool readlock)
	{
		// readlock is only used for minimal error checking, a write lock should finally not be released via readingDone()!

		if (writerThread == pthread_self ())
		{
			writerThreadRecursionCount--;

			if (readlock)
			{
				// final read unlock on a write access is the indicator for wrong use - but not fatal
				// unless the write unlock follows
				ASSERT (writerThreadRecursionCount > 0)
			}

			if (writerThreadRecursionCount > 0)
				return true;

			writerThread = 0;	// clear the holdind ID status before unlocking
		}

		int result = pthread_rwlock_unlock (&rwLock);
		PANIC_ASSERT (result == 0, result)
		return result == 0;
	}

	//---------------------------------------------
	inline bool incrementWriterRecursionCount ()
	{
		writerThreadRecursionCount++;
		
		// check against too many recursions (2^31-1 recursions should be enough)
		PANIC_ASSERT (writerThreadRecursionCount > 0, RWLockRecursion::kErrorOutOfMemory)

		if (writerThreadRecursionCount <= 0)
			return false;

		return true;
	}

	pthread_rwlock_t rwLock;
	bool valid;
	pthread_t writerThread;	// write lock holder thread ID, special recursion counting required to support read recursion after write
	int32 writerThreadRecursionCount;
};


//---------------------------------------------
// PThread RWLock with Mutex/Conditions (for systems without efficient support of pthread_rwlock, e.g. OSX 10.6)
// Can also be used as fallback if neither PTHREAD_POSIX_RWLOCK nor PTHREAD_SLIM_POSIX_RWLOCK are defined
//---------------------------------------------
struct PThreadReaderPreferenceRWLock
{
public:
	//---------------------------------------------
	PThreadReaderPreferenceRWLock ()
	{
		readersCount = 0;
		writersCount = 0;
		waitingReaders = 0;
		waitingWriters = 0;
	};
	
	//---------------------------------------------
	~PThreadReaderPreferenceRWLock ()
	{
	}
	
	//---------------------------------------------
	inline bool verify ()
	{
		return true;
	}
	
	//---------------------------------------------
	inline bool waitToRead ()
	{
	againWaitToRead:
		accLock.lock ();
		//rwlogger.log (readersCount, waitingReaders, writersCount, waitingWriters, "waitToRead");
		if (writersCount > 0 && writer != pthread_self ())
		{
			FAtomicIncrement (waitingReaders);
			accLock.unlock ();
			readersCond.wait ();
			FAtomicDecrement (waitingReaders);
			goto againWaitToRead;
		}
		else
		{
			FAtomicIncrement (readersCount);
			accLock.unlock ();
		}
		return true;
	}
	
	//---------------------------------------------
	inline bool doneReading ()
	{
		accLock.lock ();
		FAtomicDecrement (readersCount);
		//rwlogger.log (readersCount, waitingReaders, writersCount, waitingWriters, "doneReading");
		if (waitingWriters > 0)
			writersCond.signalAll ();
		accLock.unlock ();
		return true;
	}
	
	//---------------------------------------------
	inline bool waitToWrite ()
	{
	againWaitToWrite:
		accLock.lock ();
		//rwlogger.log (readersCount, waitingReaders, writersCount, waitingWriters, "waitToWrite");
		if (readersCount > 0 || (writersCount > 0 && writer != pthread_self ()))
		{
			FAtomicIncrement (waitingWriters);
			accLock.unlock ();
			writersCond.wait ();
			FAtomicDecrement (waitingWriters);
			goto againWaitToWrite;
		}
		else
		{
			writer = pthread_self ();
			FAtomicIncrement (writersCount);
			accLock.unlock ();
		}
		return true;
	}
	
	//---------------------------------------------
	inline bool doneWriting ()
	{
		accLock.lock ();
		FAtomicDecrement (writersCount);
		//rwlogger.log (readersCount, waitingReaders, writersCount, waitingWriters, "doneWriting");
		if (waitingWriters > 0)
			writersCond.signalAll ();
		if (waitingReaders > 0)
			readersCond.signalAll ();
		accLock.unlock ();
		return true;
	}

private:
	//---------------------------------------------
	FCondition readersCond;       ///< Readers condition
	FCondition writersCond;       ///< Writers condition
	FLock accLock;                ///< Access lock
	pthread_t writer;             ///< Writer thread
	
	int32 readersCount;           ///< Readers count
	int32 writersCount;           ///< Writers count
	int32 waitingReaders;         ///< Waiting readers count
	int32 waitingWriters;         ///< Waiting writers count
};

} // Steinberg

#endif
