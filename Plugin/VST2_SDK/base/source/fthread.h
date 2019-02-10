//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fthread.h
// Created by  : Steinberg, 1995
// Description : the threads and locks and signals...
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

//----------------------------------------------------------------------------------
/** @file base/source/fthread.h
	Threads, locks and signals. */
/** @defgroup baseThread Thread Handling */
//----------------------------------------------------------------------------------
#ifndef __fthread__
#define __fthread__

#include "base/source/fstring.h"
#include "base/source/fatomic.h"
#include "pluginterfaces/base/ftypes.h"

#if PTHREADS 
#include <pthread.h>
#include <semaphore.h>

#if defined (__MACH__)
	#include "mach/mach_types.h"
	#include <mach/semaphore.h>
	#define RECURSIVE_POSIX_LOCKS 0	///< use MacOS X recursive lock implementation (from 10.2 onwards)
	namespace Steinberg {
		class MACHSemaphore;
	}
#else
	#define RECURSIVE_POSIX_LOCKS 1
#endif
#if RECURSIVE_POSIX_LOCKS
	class PosixRecursiveLock;
#endif

#ifdef verify
#undef verify
#endif

#elif WINDOWS
struct CRITSECT							// CRITICAL_SECTION
{
	void* DebugInfo;					// PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
	Steinberg::int32 LockCount;			// LONG LockCount;
	Steinberg::int32 RecursionCount;	// LONG RecursionCount;
	void* OwningThread;					// HANDLE OwningThread
	void* LockSemaphore;				// HANDLE LockSemaphore
	Steinberg::int32 SpinCount;			// ULONG_PTR SpinCount
};

#endif

//------------------------------------------------------------------------
namespace Steinberg {

//------------------------------------------------------------------------
/** Thread priority enum												*/
//------------------------------------------------------------------------
enum FThreadPriority
{
	kLowPriority,
	kBelowNormalPriority,
	kNormalPriority,
	kAboveNormalPriority,
	kHighPriority,
	kRealtimePriority
};

//------------------------------------------------------------------------
struct IThreadSpy;

//------------------------------------------------------------------------
/**	FThread wraps threads for each platform.
    termination is best with waitDead and flags in the run loop....	
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FThread
{
public:
//------------------------------------------------------------------------
	
	/** Thread constructor.
	 *	@param name the name of the thread (can be seen in debugger)
	 */
	FThread (const char8* name = "FThread");

	/** Destructor.
	 */
	virtual ~FThread ();
	
	/** Starts the thread.
	 */
	void run ();

	/** Terminates the thread.
	 */
	void terminate ();

	/** Checks if thread is (still) running.
	 *  @return true if running
	 */
	bool isRunning () { return running; }

	/** Waits for thread dead. This is the best to terminate this thread.
	 *	@param timeOut timeout in ms
	 *  @return true if not timed out
	 */
	bool waitDead (int32 timeOut);
	
	/** Sets thread priority. Permit temporary raise of task priority.
	 *  @param priority thread priority, see \ref FThreadPriority
	 *  @return true if successful
	 */
	virtual bool setPriority (int32 priority);

	/** Gets the current priority of this thread.
	 *  @return priority, see \ref FThreadPriority
	 */
	int32 getPriority () { return priority; }

	/** Override this method for any cleanup code.
	 */
	virtual void cleanup ();

	/** Override this method for the thread loop.
	 *  @return thread return value.
	 */
	virtual uint32 entry ();

	/** Gets the name of this thread.
	 *  @return thread name
	 */
	const String& getName () const {return name; }

	/** Gets the reference of this thread.
	 *  @return thread reference
	 */
	void* getThreadReference () const;

	/** Sets cpu affinity. Binds thread to a specific cpu.
	 *  @param cpu cpu id
	 *  @return true if successful
	 */
	bool setCpuAffinity (int32 cpu);

	/** Check if current execution is in the thread context
	 *  @return true if successful
	 */
	bool isInThreadContext () const;
	
	/** Sets a thread spy which gets informed about new or removed threads.
	 *  There is only one spy allowed and it works without reference couting.
	 *  @param spy a thread spy
	 */
	static void setSpy (IThreadSpy* spy);

#if WINDOWS
	/** Sets high process priority. (Windows -> boost process level) (win only)
	 *  @param state state flag
	 *  @return true if successful
	 */
	static bool setHighProcessPriority (bool state);

	/** Sets normal process priority. (Windows -> boost process level) (win only)
	 *  @param aboveNormal true if above normal, false if below normal
	 *  @return true if successful
	 */
	static bool setNormalProcessPriority (bool aboveNormal);

	/** Enables priority boosting. (win only)
	 *  @param state state flag
	 *  @return true if successful
	 */
	static bool enablePriorityBoosting (bool state);

	/** Gets thread id. (win only)
	 *  @return thread id
	 */
	uint32 getID () const {return threadID;}

#elif __MACH__

	/** Sets the application task priority to foreground.
	 *  This is only for applications that have no GUI elements, e.g. services.
	 *  Note: Call it only once in main thread.
	 *  @return true if successful
	 */
	static bool setTaskPriorityToForegroundApplication ();

#endif
	
//------------------------------------------------------------------------
protected:	
	int32 priority;				///< Priority of thread
	int32 cpu;					///< Cpu used by this thread
	bool running;				///< Running state
	static IThreadSpy* gSpy;	///< Global thread spy

#if PTHREADS
	pthread_t thread;			///< Pthread handle (mac only)
	
#elif WINDOWS
	void* threadHandle;			///< Thread handle (win only)
	uint32 threadID;			///< Thread id (win only)
#endif

private:
	String name;		///< Thread name
};

//------------------------------------------------------------------------
/** Thread Spy interface declaration.
@ingroup baseThread	*/
//------------------------------------------------------------------------
struct IThreadSpy 
{
//------------------------------------------------------------------------

	/** Called when a thread was added.
	 *  @param f thread
	 */
	virtual void threadAdded (FThread* f) = 0;

	/** Called when a thread was removed.
	 *  @param f thread
	 */
	virtual void threadRemoved (FThread* f) = 0;

//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Lock interface declaration.
@ingroup baseThread	*/
//------------------------------------------------------------------------
struct ILock
{
//------------------------------------------------------------------------
	virtual ~ILock () {}

	/** Enables lock.
	 */
	virtual void lock () = 0;

	/** Disables lock.
	 */
	virtual void unlock () = 0;

	/** Tries to disable lock.
	 */
	virtual bool trylock () = 0;

//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/**	FLock declaration.
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FLock : public ILock
{
public:
//------------------------------------------------------------------------

	/** Lock constructor.
	 *  @param name lock name
	 */
	FLock (const char8* name = "FLock");

	/** Lock destructor.
	 */
	~FLock ();

	//-- ILock -----------------------------------------------------------
	virtual void lock ();
	virtual void unlock ();
	virtual bool trylock ();
	//--------------------------------------------------------------------

//------------------------------------------------------------------------
protected:
#if PTHREADS
	#if RECURSIVE_POSIX_LOCKS
	PosixRecursiveLock *rlock;		///< Recursive posix lock object
	#else	
	pthread_mutex_t mutex;			///< Mutex object
	#endif
	
#elif WINDOWS
	CRITSECT section;				///< Critical section object
		
#endif
};

//------------------------------------------------------------------------
/**	FLockObj declaration. Reference counted lock
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FLockObject : public FObject, public FLock
{
public:
	OBJ_METHODS (FLockObject, FObject)
};


//------------------------------------------------------------------------
/**	FCondition - wraps the signal and wait calls in win32
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FCondition
{
public:
//------------------------------------------------------------------------

	/** Condition constructor.
	 *  @param name name of consition
	 */
	FCondition (const char8* name = 0 /* "FCondition" */ );

	/** Condition destructor.
	 */
	~FCondition ();
	
	/** Signals one thread.
	 */
	void signal ();

	/** Signals all threads.
	 */
	void signalAll ();

	/** Waits for condition.
	 */
	void wait ();

	/** Waits for condtion with timeout
	 *  @param timeout time out in milliseconds
	 *  @return false if timed out
	 */
	bool waitTimeout (int32 timeout = -1);

	/** Resets condition.
	 */
	void reset ();

#if WINDOWS
	/** Gets condition handle.
	 *  @return handle
	 */
	void* getHandle () { return event; }
#endif

//------------------------------------------------------------------------
private:
#if PTHREADS
	pthread_mutex_t mutex;		///< Mutex object
	pthread_cond_t cond;		///< Condition object
	int32 state;				///< Use to hold the state of the signal
	int32 waiters;				///< Number of waiters

	#if DEVELOPMENT
	int32     waits;			///< Waits count
	int32     signalCount;		///< Signals count
	#endif
#elif WINDOWS
	void* event;				///< Event handle
#endif
};

//------------------------------------------------------------------------
// Overwritable Panic hook
// have clear handling for failure returns for the low level sync calls
// which cannot report back to the caller, e.g. FLock, FRwLock etc.
// If these low level operation fail, correct program behaviour is not given anymore.
// Use a hook to enable unit testing, default behaviour is the process termination.
//------------------------------------------------------------------------
namespace FPanicAssert
{
	//------------------------------------------------------------------------
	typedef void (*PANIC_FUNC) (int32 code);

	//------------------------------------------------------------------------
	void setPanicHook (PANIC_FUNC newPanicHook);

	//------------------------------------------------------------------------
	void panic (int32 code);
}

// ASSERT with Panic call for low level operation
#define PANIC_ASSERT(test, code) if (!(test)) FPanicAssert::panic (code);

//------------------------------------------------------------------------
/**	FRwLock - read / write lock.
* Supports recursive locks from the same thread.
* Recursive read lock on a granted write lock is permitted.
* Recursive write lock on a granted write lock is permitted.
* Recursive write lock on a granted read lock is rejected. (unless the initial lock grant was a write request)
* Support selection of write preference and read preference.
* \note On modern OS write preference is implemented efficiently in the libraries, but it might result in deadlocks for nested reads from multiple threads.
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FRwLock
{
public:
//------------------------------------------------------------------------

	/** FRwLock constructor.
	 *  @param name name of RwLock
	 *  @param writerPreference if true RwLock will choose a writer preference (new read arrivals block until the write request was fulfilled)
	 */
	FRwLock (const char8* name = "FRwLock", bool writerPreference = false);

	/** FRwLock destructor.
	 */
	~FRwLock ();

	/** Verifies lock.
	 *  @return true if locked.
	 */
	bool verify ();

	/** Sets 'waits to read' state.
	 */
	void waitToRead ();

	/** Sets 'done reading' state.
	 */
	void doneReading ();

	/** Sets 'wait to write' state.
	 */
	void waitToWrite ();

	/** Sets 'done writing' state.
	 */
	void doneWriting ();

//------------------------------------------------------------------------
private:
	struct ImplWP;
	struct ImplRP;
	ImplWP* implWP;	// writer preference
	ImplRP* implRP; // reader preference

#if DEVELOPMENT
	int32 readers;                ///< Readers count
	int32 writers;                ///< Writers count
#endif
};

//------------------------------------------------------------------------
/**	FGuard - automatic object for locks.
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FGuard
{
public:
//------------------------------------------------------------------------

	/** FGuard constructor.
	 *  @param _lock guard this lock
	 */
	FGuard (ILock& _lock) : lock (_lock) {lock.lock ();}

	/** FGuard destructor.
	 */
	~FGuard () {lock.unlock ();}

//------------------------------------------------------------------------
private:
	ILock& lock;			///< guarded lock
};


//------------------------------------------------------------------------
/**	Conditional Guard - Locks only if valid lock is passed.								
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FConditionalGuard
{
public:
//------------------------------------------------------------------------

	/** FConditionGuard constructor.
	 *  @param _lock guard this lock
	 */
	FConditionalGuard (FLock* _lock) : lock (_lock) { if (lock) lock->lock (); }

	/** FConditionGuard destructor.
	 */
	~FConditionalGuard () { if (lock) lock->unlock (); }

//------------------------------------------------------------------------
private:
	FLock* lock;			///< guarded lock
};


//------------------------------------------------------------------------
/**	Conditional  Read Guard - Locks only if valid lock is passed.								
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FConditionalReadGuard
{
public:
//------------------------------------------------------------------------

	/** FConditionReadGuard constructor.
	 *  @param _lock guard this lock
	 */
	FConditionalReadGuard (FRwLock* _lock) : lock (_lock) { if (lock) lock->waitToRead (); }

	/** FConditionalReadGuard destructor.
	 */
	~FConditionalReadGuard () { if (lock) lock->doneReading (); }

//------------------------------------------------------------------------
private:
	FRwLock* lock;			///< guarded lock
};


//------------------------------------------------------------------------
/**	Conditional Write Guard - Locks only if valid lock is passed.								
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FConditionalWriteGuard
{
public:
//------------------------------------------------------------------------

	/** FConditionalWriteGuard constructor.
	 *  @param _lock guard this lock
	 */
	FConditionalWriteGuard (FRwLock* _lock) : lock (_lock) { if (lock) lock->waitToWrite (); }

	/** FConditionalWriteGuard destructor.
	 */
	~FConditionalWriteGuard () { if (lock) lock->doneWriting (); }

//------------------------------------------------------------------------
private:
	FRwLock* lock;			///< guarded lock
};


//------------------------------------------------------------------------
/** Sets current thread to sleep for a while, while releasing the CPU. 
@ingroup baseThread	*/
//------------------------------------------------------------------------
void FThreadSleep (int32 milliseconds);

#if __MACH__
//------------------------------------------------------------------------
// semaphore wrapper class for Mach
//------------------------------------------------------------------------
class MachSemaphore
{
public:
	MachSemaphore (uint32 initialCount = 0);
	~MachSemaphore ();
	void wait ();
	void waitSignal (MachSemaphore& signalSemaphore);
	void signal ();
	void signalAll ();
	bool verify () {return sem != 0;}
	bool timedWait (uint32 milliseconds);
	
private:
	semaphore_t sem;
};
#endif

	//------------------------------------------------------------------------
/** Semaphore.
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FSemaphore 
{
public:
//------------------------------------------------------------------------

	/** FSemaphore constructor.
	 *  @param initialCount initial count for this semaphore
	 *  @param name name of semaphore (unused !!!)
	 */
	FSemaphore (int32 initialCount, const char8* name);

	/** FSemaphore destructor.
	 */
	~FSemaphore ();

	/** Verifies semaphore.
	 *  @return true if semaphore exists
	 */
	bool verify ();

	/** Acquires semaphore.
	 *  @param timeOut time out, -1 means infinite, 0 means never locks, ms
	 *  @return true if successful
	 */
	bool acquire (int32 millisecondsTimeOut = -1);

	/** Releases semaphore.
	 *  @param count how many?
	 */
	void release (int32 count = 1);

//------------------------------------------------------------------------
protected:
#if WINDOWS
	void* sem;			///< Handle to semaphore

#elif PTHREADS
	#if __MACH__
	MachSemaphore sem;	///< Handle to semaphore
	#else
	sem_t* sem;			///< Handle to semaphore
	#endif

#else
	#error implement me!
#endif
};

//------------------------------------------------------------------------
/** Semaphore Guard - automatic object for semaphores.
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FSemaphoreGuard
{
public:
//------------------------------------------------------------------------
	FSemaphoreGuard (FSemaphore& s, int32 timeOut = -1) : semaphore (s)
	{
		semaphore.acquire (timeOut);
	}
	~FSemaphoreGuard ()
	{
		semaphore.release ();
	}
//------------------------------------------------------------------------
private:
	FSemaphore& semaphore;
};


//------------------------------------------------------------------------
/**	Scope object for setting a read lock. 
    Can be used with a FRwLock + other locks that have waitToRead / doneReading methods.	
	@ingroup baseThread	*/
//------------------------------------------------------------------------
template<class T> 
class FReadGuardT
{
public:
//------------------------------------------------------------------------
	FReadGuardT (T& _lock) : lock (_lock) { lock.waitToRead (); }
	~FReadGuardT () { lock.doneReading (); }
//------------------------------------------------------------------------
private:
	T& lock;			
};


//------------------------------------------------------------------------
/**	Scope object for setting a write lock. 
    Can be used with a FRwLock + other locks that have waitToWrite / doneWriting methods.
	@ingroup baseThread	*/
//------------------------------------------------------------------------
template<class T> 
class FWriteGuardT
{
public:
//------------------------------------------------------------------------
	FWriteGuardT (T& _lock) : lock (_lock) { lock.waitToWrite (); }
	~FWriteGuardT () { lock.doneWriting (); }
//------------------------------------------------------------------------
private:
	T& lock;			
};

typedef FReadGuardT<FRwLock> FReadGuard;
typedef FWriteGuardT<FRwLock> FWriteGuard;


//------------------------------------------------------------------------
/** Prevent recursive calls or from another thread to a method
    use in combination with FRecursionGuard
	@ingroup baseThread	 */
//------------------------------------------------------------------------
class FRecursionCounter
{
public:
//------------------------------------------------------------------------
	FRecursionCounter () : recursionCounter (0) {}
	bool enter () {	return FAtomicIncrement (recursionCounter) == 0; }
	void leave () {	FAtomicDecrement (recursionCounter); }
//------------------------------------------------------------------------
private:
	volatile int32 recursionCounter;
};

//------------------------------------------------------------------------
/** Guard for a FRecursionCounter
@ingroup baseThread	
usage example: 

   void noRecursionNoOtherThreadMethod ()
   {
		static FRecursionCounter recurseCounter;
		FRecursionGuard recurseGuard (recurseCounter);
		if (recurseGuard.isInRecursion ())
			return;

		// perform protected operations...
	}
} */
//------------------------------------------------------------------------
class FRecursionGuard
{
//------------------------------------------------------------------------
public:
	FRecursionGuard (FRecursionCounter& _lock) : lock (_lock)
	{
		success = lock.enter ();
	}
	~FRecursionGuard ()
	{
		lock.leave ();
	}
	bool isInRecursion () const {return success == false;}
//------------------------------------------------------------------------
private:
	FRecursionCounter& lock;
	bool success;
};

//------------------------------------------------------------------------
/** Local storage for threads
@ingroup baseThread	
Local thread storage enables multiple threads to use the same ID
to store and retrieve an object that is local to the thread. */
//------------------------------------------------------------------------
class FLocalThreadStorage
{
public:
	/** Initiatlize FLocalThreadStorage states (optional)
	 *  @return new local storage object. Caller needs to delete it when done.
	 *
	 *	Remarks: This method is available for static's destruction ordering is
	 *			 necessary and the automatic init from creates() is too late.
	 */
	static void initStates ();

	/** Create a new local storage object
	 *  @return new local storage object. Caller needs to delete it when done.
	 *
	 *	Remarks: There's a race condition on Windows if a FLocalThreadStorage is deleted while
	 *			 a Thread is still running and has set a data object, this object is not released.
	 */
	static FLocalThreadStorage* create ();

	/** Destructor.
	 */
	~FLocalThreadStorage ();

	/** Store an object into the current thread context.
		The data object is shared while the thread lives or a new object is set.
	 *  @param data object
	 *  @return true on success else false
	 */
	bool setData (FUnknown* data);

	/** Retrieve data from the current thread context.
	 *  @return data object
	 */
	FUnknown* getData () const;

private:
	FLocalThreadStorage ();
	bool init ();
#if PTHREADS
	pthread_key_t platformKey;
#elif WINDOWS
	uint32 platformKey;
public:
	static void onThreadDestruction (); // do not use
#endif
};


#if WINDOWS
//------------------------------------------------------------------------
/** Thread Detector - detect threads being started.
@ingroup baseThread	*/
//------------------------------------------------------------------------
class FThreadDetector
{	
public:
//------------------------------------------------------------------------

	/** FThreadDetector constructor.
	 */
	FThreadDetector	();

	/** Starts detection.
	 *  @return true if started
	 */
	bool startDetection ();

	/** Stops detection.
	 */
	void stopDetection ();

	/** Gets count of threads.
	 *  @return thread count
	 */
	uint32 total () const {return newThreadCount;}

	/** Gets new thread.
	 *  @param index index of thread
	 *  @return thread id
	 */
	uint32 getNewThread (int32 index) const {return newThreads [index];}

	/** Opens a new thread.
	 *  @param index index of thread
	 *  @return thread handle
	 */
	void* openNewThread (int32 index) const;
//------------------------------------------------------------------------
private:

	/** Detects threads.
	 *  @param threadIDs list of thread ids
	 *  @return detected thread
	 */
	int32 detectThreads (uint32* threadIDs);

	static const uint32 kMaxThreads = 256;		///< Maximal threads
	static const uint32 kMaxNewThreads = 32;	///< Maximal new threads

	uint32 oldThreadIDs[kMaxThreads];			///< Array of old thread ids
	int32 oldThreadCount;						///< Count of old threads
	uint32 newThreads[kMaxNewThreads];			///< Array of new threads ids
	int32 newThreadCount;						///< Count of new threads
};
#endif

} // namespace Steinberg

#endif
