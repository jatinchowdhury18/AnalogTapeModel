//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/frwlock_windows.h
// Created by  : Steinberg, 2014
// Description : WIN32 implementation for RW locks (multiple reader, single writer)
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

#ifndef __frwlock_windows__
#define __frwlock_windows__

#include "base/source/frwlock_generic.h"

#include <windows.h>

namespace Steinberg {

//---------------------------------------------
// WindowsWriterPreferenceRWLock:
// Windows SlimRWLock RWLock implementation (available since Windows Vista)
// Since SlimRWLock does not support recursive locking, manage
// per thread recursive locking calls with RWLockRecursion
//---------------------------------------------
struct WindowsWriterPreferenceRWLock
{
	enum
	{
		kErrorNotAvailable = -1
	};
public:
	//---------------------------------------------
	// creation available only from WindowsSlimRWLock::create ()
	//---------------------------------------------
	WindowsWriterPreferenceRWLock ()
	{
		PANIC_ASSERT (getProcs ().InitializeSRWLock != 0, kErrorNotAvailable)	// check at least once, that it could be successfully initialized
		
		RWLockRecursion::initializeGlobalRecursionData ();
		
		getProcs ().InitializeSRWLock (&slimRWLock);	// method does not have any result, initialize always succeeds
	};
	
	//---------------------------------------------
	bool verify ()
	{
		return true;	// SlimRWLock is defined in MSDN to always work (no return results whatsoever)
	}
	
	//---------------------------------------------
	void waitToRead ()
	{
		int32 recursionCount = RWLockRecursion::acquireRecursionCount (this, RWLockRecursion::kReadAccess);
		if (recursionCount == 1)	// only acquire read access in the first call
			getProcs ().AcquireSRWLockShared (&slimRWLock);
	}
	
	//---------------------------------------------
	void doneReading ()
	{
		int32 recursionCount = RWLockRecursion::releaseRecursionCount (this, RWLockRecursion::kReadAccess);
		if (recursionCount == 0)	// only release in the last round
			getProcs ().ReleaseSRWLockShared (&slimRWLock);
	}
	
	//---------------------------------------------
	void waitToWrite ()
	{
		int32 recursionCount = RWLockRecursion::acquireRecursionCount (this, RWLockRecursion::kWriteAccess);
		if (recursionCount <= 1)	// only acquire read access in the first call, or on error condition to force a deadlock
			getProcs ().AcquireSRWLockExclusive (&slimRWLock);
	}
	
	//---------------------------------------------
	void doneWriting ()
	{
		int32 recursionCount = RWLockRecursion::releaseRecursionCount(this, RWLockRecursion::kWriteAccess);
		if (recursionCount == 0)	// only acquire write access on the first acquisition
			getProcs ().ReleaseSRWLockExclusive (&slimRWLock);
	}
	
	//---------------------------------------------
	static bool supported ()
	{
		return getProcs ().InitializeSRWLock != 0 ? true : false;
	}
	
private:
	//---------------------------------------------
	SRWLOCK slimRWLock;
	
	//---------------------------------------------
	struct SlimRWLockProcs
	{
		typedef VOID (WINAPI *InitializeSRWLockFunc) (SRWLOCK*);
		typedef VOID (WINAPI *LockUnlockFunc) (SRWLOCK*);
		
		//---------------------------------------------
		SlimRWLockProcs ()
		{
			InitializeSRWLock = (InitializeSRWLockFunc) GetProcAddress (GetModuleHandle (STR("Kernel32")), "InitializeSRWLock");
			AcquireSRWLockShared = (LockUnlockFunc) GetProcAddress (GetModuleHandle (STR("Kernel32")), "AcquireSRWLockShared");
			ReleaseSRWLockShared = (LockUnlockFunc) GetProcAddress (GetModuleHandle (STR("Kernel32")), "ReleaseSRWLockShared");
			AcquireSRWLockExclusive = (LockUnlockFunc) GetProcAddress (GetModuleHandle (STR("Kernel32")), "AcquireSRWLockExclusive");
			ReleaseSRWLockExclusive = (LockUnlockFunc) GetProcAddress (GetModuleHandle (STR("Kernel32")), "ReleaseSRWLockExclusive");
		};
		
		InitializeSRWLockFunc InitializeSRWLock;
		LockUnlockFunc AcquireSRWLockShared;
		LockUnlockFunc ReleaseSRWLockShared;
		LockUnlockFunc AcquireSRWLockExclusive;
		LockUnlockFunc ReleaseSRWLockExclusive;
	};
	
	//---------------------------------------------
	static SlimRWLockProcs& getProcs ()
	{
		static SlimRWLockProcs procs;
		return procs;
	};
};

//---------------------------------------------
// WindowsReaderPreferenceRWLock:
// Windows XP compatible RWLock implementation
// Writers will be blocked until no reader exists
// Readers arriving while a writer waits, will delay the writer further
//---------------------------------------------
struct WindowsReaderPreferenceRWLock
{
public:
	//---------------------------------------------
	WindowsReaderPreferenceRWLock ()
	{
		// Initialize all data members to NULL so that we can
		// accurately check whether an error has occurred.
		hMutexNoWriter = 0;
		hEventNoReaders = 0;
		hSemNumReaders = 0;
		
		// This mutex guards access to the other objects
		// managed by this data structure and also indicates 
		// whether there are any writer threads writing.
		// Initially no thread owns the mutex.
		hMutexNoWriter = CreateMutex (0, false, 0);            // Mutex is recursive
		
		// Create the manual-reset event that is signalled when 
		// no reader threads are reading.
		// Initially no reader threads are reading.
		hEventNoReaders = CreateEvent (0, true, true, 0);
		
		// Initialize the variable that indicates the number of 
		// reader threads that are reading.
		// Initially no reader threads are reading.
		hSemNumReaders = CreateSemaphore (0, 0, 0x7FFFFFFF, 0);
	};
	
	//---------------------------------------------
	virtual ~WindowsReaderPreferenceRWLock ()
	{
		if (hMutexNoWriter)
			CloseHandle (hMutexNoWriter);
		if (hEventNoReaders)
			CloseHandle (hEventNoReaders);
		if (hSemNumReaders)
			CloseHandle (hSemNumReaders);		
	}
	
	//---------------------------------------------
	bool verify ()
	{
		return true;
	}
	
	//---------------------------------------------
	void waitToRead ()
	{
		DWORD dw; 
		LONG lPreviousCount;
		
		// We can read if the mutex guard is available
		// and no threads are writing.
		dw = WaitForSingleObject (hMutexNoWriter, INFINITE);
		
		// Increment the number of reader threads.
		ReleaseSemaphore (hSemNumReaders, 1, &lPreviousCount);
		if (lPreviousCount == 0)
		{
			// If this is the first reader thread, 
			// set our event to reflect this.
			ResetEvent (hEventNoReaders);
		}
		
		// Allow other writer/reader threads to use
		// the SWMRG synchronization object.
		ReleaseMutex (hMutexNoWriter);
	}
	
	//---------------------------------------------
	void doneReading ()
	{
		HANDLE aHandles[2];
		LONG lNumReaders = 0;
		
		// We can stop reading if the mutex guard is available,
		// but when we stop reading we must also decrement the
		// number of reader threads.
		aHandles[0] = hMutexNoWriter;
		aHandles[1] = hSemNumReaders;
		WaitForMultipleObjects (2, aHandles, true, INFINITE);
		
		// Get the remaining number of readers by releasing the
		// semaphore and then restoring the count by immediately
		// performing a wait.
		ReleaseSemaphore (hSemNumReaders, 1, &lNumReaders);
		WaitForSingleObject (hSemNumReaders, INFINITE);
		
		// If there are no remaining readers, 
		// set the event to relect this.
		if (lNumReaders == 0) 
		{
			// If there are no reader threads, 
			// set our event to reflect this.
			SetEvent (hEventNoReaders);
		}
		
		// Allow other writer/reader threads to use
		// the SWMRG synchronization object.
		ReleaseMutex (hMutexNoWriter);
	}
	
	//---------------------------------------------
	void waitToWrite ()
	{
		DWORD dw; 
		HANDLE aHandles[2];
		
		
		// We can write if the following are true:
		// 1. The mutex guard is available and
		//    no other threads are writing.
		// 2. No threads are reading.
		aHandles[0] = hMutexNoWriter;
		aHandles[1] = hEventNoReaders;
		dw = WaitForMultipleObjects (2, aHandles, TRUE, INFINITE);
	}
	
	//---------------------------------------------
	void doneWriting ()
	{
		// Presumably, a writer thread calling this function has
		// successfully called WaitToWrite. This means that we
		// do not have to wait on any synchronization objects 
		// here because the writer already owns the mutex.
		
		// Allow other writer/reader threads to use
		// the SWMRG synchronization object.
		ReleaseMutex(hMutexNoWriter);
	}
	
private:
	void* hMutexNoWriter;         ///< Handle for no writer mutex
	void* hEventNoReaders;        ///< Handle to no readers event
	void* hSemNumReaders;         ///< Handle to number of readers
};


//---------------------------------------------
// provide a runtime check version using preferrably WindowsWriterPreferenceRWLock
// and fallback to WindowsReaderPreferenceRWLock (Windows XP and earlier)
//---------------------------------------------
class WindowsCompatibilityRWLock
{
public:
	//---------------------------------------------
	WindowsCompatibilityRWLock ()
	: srwLock (0)
	, xpLock (0)
	{
		if (WindowsWriterPreferenceRWLock::supported ())
			srwLock = NEW WindowsWriterPreferenceRWLock;
		else
			xpLock = NEW WindowsReaderPreferenceRWLock;
	}
	
	~WindowsCompatibilityRWLock ()
	{
		if (srwLock)
			delete srwLock;
		if (xpLock)
			delete xpLock;
	}
	
	//---------------------------------------------
	bool verify ()
	{
		if (srwLock)
			return srwLock->verify ();
		if (xpLock)
			return xpLock->verify ();
		return false;
	}
	
	//---------------------------------------------
	void waitToRead ()
	{
		if (srwLock)
			srwLock->waitToRead ();
		else
			xpLock->waitToRead ();
	}
	
	//---------------------------------------------
	void doneReading ()
	{
		if (srwLock)
			srwLock->doneReading ();
		else
			xpLock->doneReading ();
	}
	
	//---------------------------------------------
	void waitToWrite ()
	{
		if (srwLock)
			srwLock->waitToWrite ();
		else
			xpLock->waitToWrite ();
	}
	
	//---------------------------------------------
	void doneWriting ()
	{
		if (srwLock)
			srwLock->doneWriting ();
		else
			xpLock->doneWriting ();
	}
	
private:
	WindowsWriterPreferenceRWLock* srwLock;
	WindowsReaderPreferenceRWLock* xpLock;
};

} // Steinberg

#endif
