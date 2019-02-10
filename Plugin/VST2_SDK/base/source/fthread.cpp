//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fthread.cpp
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

#define DEBUG_LOCK 0
#define DEBUG_RWLOCK 0

#include "base/source/fthread.h"
#include "base/source/fdebug.h"

#if WINDOWS
#include "base/source/frwlock_windows.h"
#else
#include "base/source/frwlock_macosx.h"
#endif

#include <limits.h>
#include <stdlib.h>

//------------------------------------------------------------------------
#if PTHREADS
//------------------------------------------------------------------------
#if __MACH__
extern "C" {
	#include <mach/clock.h>
	#include <sched.h>
	#include <mach/mach_init.h>
	#include <mach/task.h>
	#include <mach/task_policy.h>
	#include <mach/thread_act.h>
	#include <mach/semaphore.h>
	#include <mach/thread_policy.h>
	#include <mach/mach.h>
	#include <mach/mach_time.h>
	#include <unistd.h>
}
	#include <dlfcn.h>

	typedef int	(*_pthread_setname_np)(const char*);
	static _pthread_setname_np ___pthread_setname_np = 0;

#else
#include <fcntl.h>
#endif

#include <errno.h>

#if MAC
#include <TargetConditionals.h>
#if !TARGET_OS_IPHONE
#include <CoreServices/CoreServices.h>
#endif
#ifdef verify
#undef verify
#endif
#endif

static void* entry (void* data);
#include <sys/time.h>

#if RECURSIVE_POSIX_LOCKS
// recursive locks for posix (not async safe, so don't use it in signal handlers!)

class PosixRecursiveLock 
{
public:
	static PosixRecursiveLock* initNew () {
		PosixRecursiveLock *sema = NEW PosixRecursiveLock;
		sema->count = 1;
		sema->waiters = 0;

		if (pthread_mutex_init (&(sema->plock), NULL) != 0 ||
				pthread_cond_init (&(sema->available), NULL) != 0) {
			delete sema;
			return 0;
		}

		return sema;
	}

	virtual ~PosixRecursiveLock () {
		pthread_cond_destroy (&available);
		pthread_mutex_destroy (&plock);
	}

	bool lock () {
		bool failed = false;

		if (pthread_mutex_lock (&plock) != 0)
			return false;

		if (count <= 0 && owner != pthread_self ())
			while (count <= 0) {
				waiters++;
				if (pthread_cond_wait (&available, &plock) != 0)
					failed = true;
				waiters--;
			}

		count--;
		if (count == 0)
			owner = pthread_self ();
		
		if (pthread_mutex_unlock (&plock) != 0)
			return false;

		return !failed;
	}
		
	bool unlock () {
		bool failed = false;

		if (pthread_mutex_lock (&plock) != 0)
			return false;

		if (waiters && count >= 0)
			if (pthread_cond_signal (&available) != 0)
				failed = true;

		if (count <= 0)
			count++;

		if (pthread_mutex_unlock (&plock) != 0)
			return false;

		return !failed;
	}

private:
	PosixRecursiveLock () {}

	pthread_mutex_t plock;
	pthread_cond_t available;
	Steinberg::int32 count;
	pthread_t owner;
	Steinberg::uint32 waiters;
};
#endif // RECURSIVE_POSIX_LOCKS

//------------------------------------------------------------------------
#elif WINDOWS
//------------------------------------------------------------------------
#ifndef WINVER
#define WINVER 0x0500
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT WINVER
#endif

#include <windows.h>
#include <objbase.h>
#define INIT_CS(cs) \
	InitializeCriticalSection ((LPCRITICAL_SECTION)&cs);

#include <tlhelp32.h>
#include <cstdio>
#include "base/source/tarray.h"

namespace Steinberg {
static uint32 entry (void* data);
}

#endif

#if WINDOWS

//------------------------------------------------------------------------
// mappings of the thread priorities for the different
// priority classes of the task
//------------------------------------------------------------------------

/*
The following table shows the base priority levels for combinations of 
priority class and priority value.

  	Process Priority Class 				Thread Priority Level 
    =========================       	============================
1 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_IDLE 
2 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_LOWEST 
3 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_BELOW_NORMAL 
4 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_NORMAL 
5 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_ABOVE_NORMAL 
6 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_HIGHEST 
15 	IDLE_PRIORITY_CLASS 				THREAD_PRIORITY_TIME_CRITICAL 

1 	BELOW_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_IDLE 
4 	BELOW_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_LOWEST 
5 	BELOW_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_BELOW_NORMAL 
6 	BELOW_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_NORMAL 
7 	BELOW_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_ABOVE_NORMAL 
8 	BELOW_NORMAL_PRIORITY_CLASS			THREAD_PRIORITY_HIGHEST 
15 	BELOW_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_TIME_CRITICAL 

1 	NORMAL_PRIORITY_CLASS 				THREAD_PRIORITY_IDLE 
5 	Background NORMAL_PRIORITY_CLASS 	THREAD_PRIORITY_LOWEST 
7 	Foreground NORMAL_PRIORITY_CLASS 	THREAD_PRIORITY_LOWEST 
6 	Background NORMAL_PRIORITY_CLASS 	THREAD_PRIORITY_BELOW_NORMAL 
8 	Foreground NORMAL_PRIORITY_CLASS	THREAD_PRIORITY_BELOW_NORMAL 
7 	Background NORMAL_PRIORITY_CLASS 	THREAD_PRIORITY_NORMAL 
9 	Foreground NORMAL_PRIORITY_CLASS	THREAD_PRIORITY_NORMAL 
8 	NORMAL_PRIORITY_CLASS				THREAD_PRIORITY_ABOVE_NORMAL 
10 	Foreground NORMAL_PRIORITY_CLASS	THREAD_PRIORITY_ABOVE_NORMAL 
9 	NORMAL_PRIORITY_CLASS				THREAD_PRIORITY_HIGHEST 
11 	Foreground NORMAL_PRIORITY_CLASS	THREAD_PRIORITY_HIGHEST 
15 	NORMAL_PRIORITY_CLASS 				THREAD_PRIORITY_TIME_CRITICAL 

1 	ABOVE_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_IDLE 
8 	ABOVE_NORMAL_PRIORITY_CLASS			THREAD_PRIORITY_LOWEST 
9 	ABOVE_NORMAL_PRIORITY_CLASS			THREAD_PRIORITY_BELOW_NORMAL 
10 	ABOVE_NORMAL_PRIORITY_CLASS			THREAD_PRIORITY_NORMAL 
11 	ABOVE_NORMAL_PRIORITY_CLASS			THREAD_PRIORITY_ABOVE_NORMAL 
12 	ABOVE_NORMAL_PRIORITY_CLASS			THREAD_PRIORITY_HIGHEST 
15 	ABOVE_NORMAL_PRIORITY_CLASS 		THREAD_PRIORITY_TIME_CRITICAL 

1 	HIGH_PRIORITY_CLASS 				THREAD_PRIORITY_IDLE 
11 	HIGH_PRIORITY_CLASS					THREAD_PRIORITY_LOWEST 
12 	HIGH_PRIORITY_CLASS					THREAD_PRIORITY_BELOW_NORMAL 
13 	HIGH_PRIORITY_CLASS					THREAD_PRIORITY_NORMAL 
14 	HIGH_PRIORITY_CLASS					THREAD_PRIORITY_ABOVE_NORMAL 
15 	HIGH_PRIORITY_CLASS 				THREAD_PRIORITY_HIGHEST 
15 	HIGH_PRIORITY_CLASS 				THREAD_PRIORITY_TIME_CRITICAL 

16 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_IDLE 
17 	REALTIME_PRIORITY_CLASS 			-7 
18 	REALTIME_PRIORITY_CLASS 			-6 
19 	REALTIME_PRIORITY_CLASS 			-5 
20 	REALTIME_PRIORITY_CLASS 			-4 
21 	REALTIME_PRIORITY_CLASS 			-3 
22 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_LOWEST 
23 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_BELOW_NORMAL 
24 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_NORMAL 
25 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_ABOVE_NORMAL 
26 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_HIGHEST 
27 	REALTIME_PRIORITY_CLASS 			3 
28 	REALTIME_PRIORITY_CLASS 			4 
29 	REALTIME_PRIORITY_CLASS 			5	 
30	REALTIME_PRIORITY_CLASS 			6 
31 	REALTIME_PRIORITY_CLASS 			THREAD_PRIORITY_TIME_CRITICAL 
*/

namespace Steinberg {

static int32 gWindowsPrioritiesNormal[] =		// standard 
{	
	THREAD_PRIORITY_IDLE,            // kLowPriority          1     |  1 
	THREAD_PRIORITY_BELOW_NORMAL,    // kBelowNormalPriority  6/8   |  9 
	THREAD_PRIORITY_NORMAL,          // kNormalPriority       7/9   | 10
	THREAD_PRIORITY_ABOVE_NORMAL,    // kAboveNormalPriority  8/10  | 11 
	THREAD_PRIORITY_HIGHEST,         // kHighPriority         9/11  | 12
	THREAD_PRIORITY_TIME_CRITICAL    // kRealtimePriority       15  | 15
 };
static int32 gWindowsPrioritiesHigh[] =		// standard 
{	
	THREAD_PRIORITY_IDLE,            // kLowPriority          1     
	THREAD_PRIORITY_LOWEST,          // kBelowNormalPriority  11
	THREAD_PRIORITY_BELOW_NORMAL,    // kNormalPriority       12 
	THREAD_PRIORITY_NORMAL,          // kAboveNormalPriority  13
	THREAD_PRIORITY_ABOVE_NORMAL,    // kHighPriority         14 
	THREAD_PRIORITY_TIME_CRITICAL,   // kRealtimePriority     15
};

} // namespace 
#endif // WINDOWS


//------------------------------------------------------------------------
//	 FThread implementation
//------------------------------------------------------------------------
namespace Steinberg {

// RWLockRecursion implementations (Hack for include file only solution, Stefan Jun 2014)
IMPLEMENT_FUNKNOWN_METHODS (RWLockRecursion, FUnknown, FUnknown::iid)

//------------------------------------------------------------------------
IThreadSpy* FThread::gSpy = 0;
void FThread::setSpy (IThreadSpy* spy) {gSpy = spy;}

//------------------------------------------------------------------------

FThread::FThread (const char8* _name) 
: priority (kNormalPriority)
, running (false)
, cpu (-1)
, name (_name)
#if WINDOWS
, threadHandle (0)
#elif PTHREADS
, thread (0)
#endif
{
	if (gSpy)
		gSpy->threadAdded (this);
}

//------------------------------------------------------------------------
FThread::~FThread ()
{
	if (gSpy)
		gSpy->threadRemoved (this);

#if PTHREADS
	if (thread)
	{
		if (pthread_self () == thread)
		{
			// make sure that if some other thread is in pthread_join for this thread, that it will be canceled
			pthread_cancel (thread);
		}
		pthread_detach (thread);
		thread = 0;
	}
#elif WINDOWS
	if (threadHandle)
	{
		CloseHandle (threadHandle);
		threadHandle = 0;
	}
#endif
}

//------------------------------------------------------------------------
void FThread::run ()
{
	running = true;
	
#if PTHREADS
	#if __MACH__
	int32 ret = pthread_create_suspended_np (&thread, 0, ::entry, this);
	ASSERT (ret == 0)
	if (ret != 0)
	{
		running = false;
		return;
	}
	setPriority (priority);

	thread_resume (pthread_mach_thread_np (thread));

	#else
	int32 ret = pthread_create (&thread, 0, ::entry, this);
	if (ret != 0) {
		PRINTSYSERROR;
	}

	#endif // __MACH__

#elif WINDOWS
	threadHandle = CreateThread (0, 0, (LPTHREAD_START_ROUTINE)Steinberg::entry, this, CREATE_SUSPENDED, &threadID);
	setPriority (priority);
	ResumeThread (threadHandle);
			
#else
	entry ();	
	setPriority (priority);
#endif
}

//------------------------------------------------------------------------
void FThread::terminate ()
{	
#if PTHREADS
	if (thread)
		pthread_cancel (thread);

#elif WINDOWS
	if (threadHandle)
	{
		TerminateThread (threadHandle, 0);
		CloseHandle (threadHandle);
		threadHandle = 0;
	}
	
#endif
}

//------------------------------------------------------------------------
bool FThread::isInThreadContext () const
{
#if PTHREADS
	return pthread_self () == thread;

#elif WINDOWS
	return GetCurrentThreadId () == threadID;

#endif
}

//------------------------------------------------------------------------
bool FThread::setCpuAffinity (int32 _cpu)
{	// bind thread to a specific CPU, or unbind (cpu == -1)
	cpu = _cpu;
#if WINDOWS
	if (threadHandle)
	{
		DWORD_PTR processAffinityMask = 0;
		DWORD_PTR systemAffinityMask = 0;
		DWORD_PTR threadAffinityMask = 0;
		if (GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask))
		{
			if (cpu >= 0)
				threadAffinityMask = (DWORD_PTR) 1 << cpu;	// bind
			else if (cpu == -1)
				threadAffinityMask = processAffinityMask; // unbind
			else
				return false;

			if (processAffinityMask & threadAffinityMask)
			{
				if (SetThreadAffinityMask (threadHandle, threadAffinityMask))
					return true;
			}
		}
	}

	return false;

#elif PTHREADS && __MACH__

	// note: this should be called before thread was started!
	thread_affinity_policy ap;
	ap.affinity_tag = cpu + 1; // tag == 0 -> no affinity
	int ret = thread_policy_set (mach_thread_self (), THREAD_AFFINITY_POLICY, (integer_t*) &ap, THREAD_AFFINITY_POLICY_COUNT);
	return ret == 0;

#else
	return false;
#endif
}

#if WINDOWS
//------------------------------------------------------------------------
bool FThread::setHighProcessPriority (bool state)
{	
	if (state)
	{
		SetPriorityClass (GetCurrentProcess (), HIGH_PRIORITY_CLASS);
	}
	else
	{
		SetPriorityClass (GetCurrentProcess (), NORMAL_PRIORITY_CLASS);
	}
	
	return true;
}

//------------------------------------------------------------------------
bool FThread::setNormalProcessPriority (bool aboveNormal)
{	
	// following not defined in VC6 includes
	#ifndef ABOVE_NORMAL_PRIORITY_CLASS
	#define ABOVE_NORMAL_PRIORITY_CLASS         0x00008000
	#endif
	#ifndef BELOW_NORMAL_PRIORITY_CLASS
	#define BELOW_NORMAL_PRIORITY_CLASS         0x00004000
	#endif

	if (aboveNormal)
	{
		SetPriorityClass (GetCurrentProcess (), ABOVE_NORMAL_PRIORITY_CLASS);
	}
	else
	{
		SetPriorityClass (GetCurrentProcess (), BELOW_NORMAL_PRIORITY_CLASS);
	}
	
	return true;
}

//------------------------------------------------------------------------
bool FThread::enablePriorityBoosting (bool state)
{
	//  now update the priority boost (Still make it compatible with Win9x/ME)
	typedef BOOL (WINAPI *SETPROCESSPRIORITYBOOST_FUNC) (HANDLE, BOOL);
	SETPROCESSPRIORITYBOOST_FUNC _SetProcessPriorityBoost_ = (SETPROCESSPRIORITYBOOST_FUNC) GetProcAddress (GetModuleHandle (STR("Kernel32")), "SetProcessPriorityBoost");

	if (_SetProcessPriorityBoost_)
	{
		(*_SetProcessPriorityBoost_) (GetCurrentProcess (), !state);
		return true;
	}

	return false;
}
#endif

//------------------------------------------------------------------------
/** To boost priority a little bit permit a temporary raised task priority .....
  * taskPriority defaults to static taskPriority if not set*/
bool FThread::setPriority (int32 prio)
{
	priority = prio;
	
#if WINDOWS
	if (threadHandle == 0)
		return true;

	if (priority < kLowPriority || priority > kRealtimePriority)
		return false;

	bool highClass = GetPriorityClass (GetCurrentProcess()) != NORMAL_PRIORITY_CLASS;

	int32 windowsPriority = highClass ? gWindowsPrioritiesHigh [priority] : gWindowsPrioritiesNormal [priority];
	return SetThreadPriority (threadHandle, windowsPriority) != 0;
	
#elif PTHREADS
	if (thread == 0)
		return false;

	// to be tested
	int policy;
	struct sched_param sp;
	pthread_getschedparam (thread, &policy, &sp);

	int newP, newPolicy;

#if !__MACH__
	int32 maxP = sched_get_priority_max (SCHED_RR);
	int32 minP = sched_get_priority_min (SCHED_RR);
	switch (priority)
	{
		case kLowPriority:
			newP = minP;
			newPolicy = SCHED_OTHER;
			break;
		case kBelowNormalPriority:
			newP = (minP + maxP) / 3;		// 1/3
			newPolicy = SCHED_OTHER;
			break;
		case kNormalPriority:
			newP = (minP + maxP) / 2;		// 1/2
			newPolicy = SCHED_OTHER;
			break;
		case kAboveNormalPriority:
			newP = 2 * (minP + maxP) / 3;	// 2/3
			newPolicy = SCHED_OTHER;
			break;
		case kHighPriority:
			newP = (3 * (minP + maxP)) / 4;	// 3/4
			newPolicy = SCHED_RR;
			break;
		case kRealtimePriority:
			newP = maxP;
			newPolicy = SCHED_RR;
			break;
	}
#else
	// on MacOS X the policy and priority can't be detected at runtime, use some static ones
	switch (priority)
	{
		default:
		case kLowPriority:
			newP = 15;
			newPolicy = SCHED_OTHER;
			break;
		case kBelowNormalPriority:
			newP = 27;
			newPolicy = SCHED_OTHER;
			break;
		case kNormalPriority:
			newP = 31;
			newPolicy = SCHED_OTHER;
			break;
		case kAboveNormalPriority:
			//newP = 35 - cpu - 1;	// simulate cpu affinity (cpu 0 has highest prio, decrease for each "cpu")
			newP = 35;	// actually same priority will support OSX soft affinity behaviour in 10.2.4
			newPolicy = SCHED_RR;
			break;
		case kHighPriority:
			//newP = 39 - cpu - 1;	// simulate cpu affinity (cpu 0 has highest prio, decrease for each "cpu")
			newP = 39;	// actually same priority will support OSX soft affinity behaviour in 10.2.4
			newPolicy = SCHED_RR;
			break;
		case kRealtimePriority:
			newP = 48;
			newPolicy = SCHED_RR;
			break;
	}
#endif

	if (sp.sched_priority != newP || policy != newPolicy)
	{
		sp.sched_priority = newP;
		pthread_setschedparam (thread, newPolicy, &sp);
	}
	
	return true;


#else
	WARNING ("FThread::setPriority Not implemented")

	return true;
#endif
}

//------------------------------------------------------------------------
void* FThread::getThreadReference () const
{
#if WINDOWS
	return threadHandle;
#elif PTHREADS
	return (void*)thread;
#else
	return 0;
#endif
}

//------------------------------------------------------------------------
bool FThread::waitDead (int32 timeOut)
{
	if (!running)
		return true;
		
#if WINDOWS
	if (threadHandle == 0)
		return true;

	if (timeOut == -1)
		timeOut = INFINITE;
	return WaitForSingleObject (threadHandle, timeOut) == WAIT_OBJECT_0;

#elif PTHREADS
	void* thread_return;
	int32 result = pthread_join (thread, &thread_return);
	thread = 0;
	return (result == 0);

#else
	return true;
#endif
}

//------------------------------------------------------------------------
void FThread::cleanup ()
{
}

//------------------------------------------------------------------------
uint32 FThread::entry ()
{
	return 0;
}

#if __MACH__
//------------------------------------------------------------------------
bool FThread::setTaskPriorityToForegroundApplication ()
{
	int ret;
    struct task_category_policy tcatpolicy;
 
    tcatpolicy.role = TASK_FOREGROUND_APPLICATION;
 
    ret = task_policy_set (mach_task_self (),
						   TASK_CATEGORY_POLICY, (thread_policy_t)&tcatpolicy,
						   TASK_CATEGORY_POLICY_COUNT);
	return ret == KERN_SUCCESS ? true : false;
}

#endif // PTHREADS

} // namespace Steinberg

//------------------------------------------------------------------------
#if PTHREADS
void* entry (void* data)
{
	Steinberg::FThread* fthread = (Steinberg::FThread*)data;
	#if __MACH__
	// thread name API is only available in MAC OS X 10.6 and newer so check if function is available
	static bool once = false;
	if (!once)
	{
		___pthread_setname_np = (_pthread_setname_np)dlsym (RTLD_DEFAULT, "pthread_setname_np");
		once = true;
	}
	if (___pthread_setname_np && !fthread->getName ().isEmpty ())
		___pthread_setname_np (fthread->getName ().text8 ());
	#endif

	return (void*)(Steinberg::TPtrInt)fthread->entry ();
}
#elif WINDOWS

#define MS_VC_EXCEPTION 0x406D1388
struct THREADNAME_INFO
{
	DWORD dwType; 	// Must be 0x1000.
	LPCSTR szName; 	// Pointer to name (in user addr space).
	DWORD dwThreadID; // Thread ID (-1=caller thread).
	DWORD dwFlags; 	// Reserved for future use, must be zero.
};

namespace Steinberg {

uint32 entry (void* data)
{
	CoInitialize (0);

	FThread* thread = (FThread*)data;

	#if !PLATFORM_64 && !defined(__GNUC__)
	if (thread->getName ().isEmpty () == false)
	{
		THREADNAME_INFO info;
		info.dwType = 0x1000;
		info.szName = thread->getName ().text8 ();
		info.dwThreadID = thread->getID ();
		info.dwFlags = 0;

		__try
		{
			RaiseException (MS_VC_EXCEPTION, 0, sizeof(info)/sizeof(DWORD), (DWORD*)&info );
		}
		__except(EXCEPTION_CONTINUE_EXECUTION)
		{
		}
	}
	#endif

	uint32 result = thread->entry ();

	FLocalThreadStorage::onThreadDestruction ();

	CoUninitialize ();
	return result;
}

}

#endif

namespace Steinberg {
	
	
#if __MACH__
//------------------------------------------------------------------------
MachSemaphore::MachSemaphore (uint32 initialCount)
{
	if (semaphore_create (mach_task_self (), &sem, SYNC_POLICY_FIFO, (int)initialCount) != KERN_SUCCESS)
		sem = 0;
	ASSERT (sem);
}

//------------------------------------------------------------------------
MachSemaphore::~MachSemaphore ()
{
	if (sem)
		semaphore_destroy (mach_task_self (), sem);
}

//------------------------------------------------------------------------
void MachSemaphore::wait ()
{
	kern_return_t ret;
	while ((ret = semaphore_wait (sem)) == KERN_ABORTED);
	ASSERT (ret == KERN_SUCCESS);
}

//------------------------------------------------------------------------
void MachSemaphore::waitSignal (MachSemaphore& signalSemaphore)
{
	kern_return_t ret;
	ret = semaphore_wait_signal (sem, signalSemaphore.sem);
	while (ret == KERN_ABORTED)
		ret = semaphore_wait (sem);
	ASSERT (ret == KERN_SUCCESS);
}

//------------------------------------------------------------------------
void MachSemaphore::signal ()
{
	kern_return_t ret;
	while ((ret = semaphore_signal (sem)) == KERN_ABORTED);
	ASSERT (ret == KERN_SUCCESS);
}

//------------------------------------------------------------------------
void MachSemaphore::signalAll ()
{
	kern_return_t ret;
	while ((ret = semaphore_signal_all (sem)) == KERN_ABORTED);
	ASSERT (ret == KERN_SUCCESS);
}

//------------------------------------------------------------------------
bool MachSemaphore::timedWait (uint32 milliseconds)
{
	kern_return_t ret;

	if (milliseconds == 0)
	{	// non blocking case
		static struct mach_timespec time = {0,0};
		do {
			ret = semaphore_timedwait (sem, time);

			// retry on KERN_ABORTED
			if (ret == KERN_ABORTED)
				continue;

			if (ret == KERN_SUCCESS)
				return true;
		} while (false);
		return false;
	}

	int64 nanosLeft = milliseconds;
	nanosLeft *= 1000000ULL;
	
	mach_timebase_info_data_t timeBaseInfo;
	mach_timebase_info (&timeBaseInfo);
	
	do {
		uint64 startTime = mach_absolute_time ();

		struct mach_timespec time;
		time.tv_sec = static_cast<unsigned int>(nanosLeft / 1000000000ULL);
		time.tv_nsec = (nanosLeft % 1000000000ULL);

		ret = semaphore_timedwait (sem, time);
		if (ret == KERN_ABORTED)
		{ // retry on KERN_ABORTED

			uint64_t absElapsed = mach_absolute_time () - startTime;
			uint64 nanosElapsed = (absElapsed * timeBaseInfo.numer) / timeBaseInfo.denom;

			// correct remaining time by elapsed time
			nanosLeft -= nanosElapsed;

			// abort if remaining wait time is less than 100 us
			if (nanosLeft < 100000ULL)
				return false;

			// continue waiting
			continue;
		}

		if (ret == KERN_SUCCESS)
			return true;
	} while (false);
	return false;
}
#endif


//------------------------------------------------------------------------
//	FLock implementation
//------------------------------------------------------------------------
FLock::FLock (const char8* name)
{
#if PTHREADS
	#if RECURSIVE_POSIX_LOCKS
	rlock = PosixRecursiveLock::initNew ();
	ASSERT (rlock);
	#else
	pthread_mutexattr_t mutexAttr;
	pthread_mutexattr_init (&mutexAttr);
	pthread_mutexattr_settype (&mutexAttr, PTHREAD_MUTEX_RECURSIVE);
	if (pthread_mutex_init (&mutex, &mutexAttr) != 0)
		{WARNING("mutex_init failed")}
	pthread_mutexattr_destroy (&mutexAttr);
	#endif

#elif WINDOWS
	INIT_CS (section)

#endif
}

//------------------------------------------------------------------------
FLock::~FLock ()
{
#if PTHREADS
	#if RECURSIVE_POSIX_LOCKS
	if (rlock)
		delete rlock;
	#else
	pthread_mutex_destroy (&mutex);
	#endif

#elif WINDOWS
	DeleteCriticalSection ((LPCRITICAL_SECTION)&section);
		
#endif
}

//------------------------------------------------------------------------
void FLock::lock ()
{
#if DEBUG_LOCK
	FDebugPrint ("FLock::lock () %x\n", this);
#endif

#if PTHREADS
	#if RECURSIVE_POSIX_LOCKS
	ASSERT (rlock);
	if (rlock)
		rlock->lock ();
	#else
	pthread_mutex_lock (&mutex);
	#endif

#elif WINDOWS
	EnterCriticalSection ((LPCRITICAL_SECTION)&section);

#endif
}

//------------------------------------------------------------------------
void FLock::unlock ()
{
#if DEBUG_LOCK
	FDebugPrint ("FLock::unlock () %x\n", this);
#endif
	
#if PTHREADS
	#if RECURSIVE_POSIX_LOCKS
	ASSERT (rlock);
	if (rlock)
		rlock->unlock ();
	#else
	pthread_mutex_unlock (&mutex);
	#endif

#elif WINDOWS
	LeaveCriticalSection ((LPCRITICAL_SECTION)&section);

#endif 
}

//------------------------------------------------------------------------
bool FLock::trylock ()
{
#if PTHREADS
	#if RECURSIVE_POSIX_LOCKS
	WARNING ("Implement FLock::trylock!");
	return false;
	#else
	return pthread_mutex_trylock (&mutex) == 0;
	#endif

#elif WINDOWS
	return TryEnterCriticalSection ((LPCRITICAL_SECTION)&section) != 0 ? true : false;

#else
	return false;
#endif 
}



//------------------------------------------------------------------------
//	Read writer lock implementation
//------------------------------------------------------------------------
/* debug 
   if thread is reading and requests writing deadlock occurs
   to find 
      remember each thread that reads

struct thread
{
	HANDLE threadHandle;
	int32 readerCount;
};
*/

//---------------------------------------------
// Windows FRwLock preparation
//---------------------------------------------
#if WINDOWS
	
// define strategies for the implementation
#define USE_WINDOWS_SLIMRWLOCK 1	// Use SlimRWLock, and manage per thread recursive calls with RWLockRecursion (WindowsSlimRWLock) - Requires Windows Vista and up
#define USE_SLIMRWLOCK_AND_XPFALLBACK 0 // Use WindowsSlimRWLock when available (Vista and up), or XP compatible version as fallback (WindowsCompatibilityRWLock)

// define concrete implementation for FRwLock
#if USE_WINDOWS_SLIMRWLOCK
	struct  FRwLock::ImplWP : public WindowsWriterPreferenceRWLock {};
	struct  FRwLock::ImplRP : public WindowsReaderPreferenceRWLock {};
#elif USE_SLIMRWLOCK_AND_XPFALLBACK
	struct  FRwLock::ImplWP : public WindowsCompatibilityRWLock {};	// actually this is a Reader Preference lock
	struct  FRwLock::ImplRP : public WindowsReaderPreferenceRWLock {};
#else
	#error FRwLock: neither USE_WINDOWS_SLIMRWLOCK nor USE_SLIMRWLOCK_AND_XPFALLBACK defined for WINDOWS support.
#endif

#endif

//---------------------------------------------
// MacOSX FRwLock preparation
//---------------------------------------------
#if PTHREADS
	
// define strategies for the implementation
#define PTHREAD_POSIX_RWLOCK 1	// PThreadWriterPreferenceRWLock: use pthread_rwlock, use recursion counting for read and write locks (adds a few debugging services)
#define PTHREAD_SLIM_POSIX_RWLOCK 0	// PThreadSlimWriterPreferenceRWLock: use pthread_rwlock, only handle the write recursion to support recursive read after write, recursive read grants are handled by pthread_rwlock

// define concrete implementation for FRwLock
#if PTHREAD_POSIX_RWLOCK
	struct  FRwLock::ImplWP : public PThreadWriterPreferenceRWLock {};
	struct  FRwLock::ImplRP : public PThreadReaderPreferenceRWLock {};
#elif PTHREAD_SLIM_POSIX_RWLOCK
	struct  FRwLock::ImplWP : public PThreadSlimWriterPreferenceRWLock {};
	struct  FRwLock::ImplRP : public PThreadReaderPreferenceRWLock {};
#else
	#error FRwLock: neither PTHREAD_POSIX_RWLOCK nor PTHREAD_SLIM_POSIX_RWLOCK defined for PTHREADS support.
#endif

#endif

//---------------------------------------------
FRwLock::FRwLock (const char8* name, bool writerPreference)
: implWP (0)
, implRP (0)
{
	if (writerPreference)
		implWP = NEW ImplWP;
	else
		implRP = NEW ImplRP;
}

//------------------------------------------------------------------------
FRwLock::~FRwLock ()
{
	if (implWP)
		delete implWP;
	if (implRP)
		delete implRP;
}

//------------------------------------------------------------------------
bool FRwLock::verify ()
{
	if (implWP)
		return implWP->verify ();
	if (implRP)
		return implRP->verify ();
	return false;
}

//------------------------------------------------------------------------
void FRwLock::waitToRead ()
{
	#if DEBUG_RWLOCK
	LOGINT ("Readers", ++readers)
	
	#if WINDOWS
	if (writers)
		DebugBreak ();
	#endif
	#endif

	if (implWP)
		implWP->waitToRead ();
	else
		implRP->waitToRead ();
}

//------------------------------------------------------------------------
void FRwLock::doneReading ()
{
	#if DEBUG_RWLOCK
	LOGINT ("Readers", --readers)
	#endif

	if (implWP)
		implWP->doneReading ();
	else
		implRP->doneReading ();
}

//------------------------------------------------------------------------
void FRwLock::waitToWrite ()
{	
	#if DEBUG_RWLOCK
	LOGINT ("Writers", ++writers)

	#if WINDOWS
	if (readers)
		DebugBreak ();
	#endif
	#endif

	if (implWP)
		implWP->waitToWrite ();
	else
		implRP->waitToWrite ();
}

//------------------------------------------------------------------------
void FRwLock::doneWriting ()
{  
	#if DEBUG_RWLOCK
	LOGINT ("Writers", --writers)
	#endif	

	if (implWP)
		implWP->doneWriting ();
	else
		implRP->doneWriting ();
}

//------------------------------------------------------------------------
/**	FCondition CTOR. 
 *  @param name - can be used to set the name of the event.
 */
FCondition::FCondition (const char8* name)
{
	#if PTHREADS
	pthread_mutex_init (&mutex, 0);
	pthread_cond_init (&cond, 0);
	state = 0;
	waiters = 0;
		#if DEVELOPMENT
		waits = 0;
		signalCount = 0;
		#endif

	#elif WINDOWS
	// use name if existing
	event = CreateEventA (0, FALSE, FALSE, name);

	#endif
}

//------------------------------------------------------------------------
FCondition::~FCondition ()
{
	#if PTHREADS
	pthread_mutex_destroy (&mutex);
	pthread_cond_destroy (&cond);

	#elif WINDOWS
	CloseHandle (event);
	
	#endif
}
	
//------------------------------------------------------------------------
void FCondition::signal ()
{
	#if PTHREADS
	pthread_mutex_lock(&mutex);
	state = 1;
		#if DEVELOPMENT
		signalCount++;
		#endif
	pthread_cond_signal (&cond);
	pthread_mutex_unlock (&mutex);

	#elif WINDOWS
	BOOL result = PulseEvent (event);
	if (!result)
	{
		PRINTSYSERROR;
	}

	#endif 
}

//------------------------------------------------------------------------
void FCondition::signalAll ()
{
	#if PTHREADS
	pthread_mutex_lock(&mutex);
	state = waiters + 1;

		#if DEVELOPMENT
		signalCount++;
		#endif
	pthread_cond_broadcast (&cond);
	pthread_mutex_unlock(&mutex);

	#elif WINDOWS
	BOOL result = SetEvent (event);
	if (!result)
	{
		PRINTSYSERROR;
	}
	
	#endif
}

//------------------------------------------------------------------------
void FCondition::wait ()
{
	#if PTHREADS
	pthread_mutex_lock(&mutex);
		#if DEVELOPMENT
		waits++;
		#endif
	waiters++;
	while (!state)
		pthread_cond_wait (&cond, &mutex);
	if (--waiters == 0)
		state = 0;
	else
		--state;
	pthread_mutex_unlock(&mutex);

	#elif WINDOWS
	WaitForSingleObject (event, INFINITE);
			
	#endif
}

//------------------------------------------------------------------------
bool FCondition::waitTimeout (int32 milliseconds)
{
#if LINUX
#elif PTHREADS
	if (milliseconds == -1)
	{	// infinite timeout
		wait ();
		return true;
	}

	struct timespec time;

	#if __MACH__
	time.tv_sec = milliseconds / 1000;
	time.tv_nsec = 1000000 * (milliseconds - (time.tv_sec * 1000));

	pthread_mutex_lock(&mutex);
	#if DEVELOPMENT
	waits++;
	#endif

	waiters++;

	bool result = true;
	while (!state)
	{
		int32 err = pthread_cond_timedwait_relative_np (&cond, &mutex, &time);
		if (err == ETIMEDOUT)
		{
			result = false;
			break;
		}
		else
			result = true;
	}
	if (--waiters == 0)
		state = 0;
	else
		--state;
	pthread_mutex_unlock(&mutex);
	return result;

	#else
	clock_gettime (CLOCK_REALTIME, &time);
	time.tv_nsec += milliseconds * 1000; // ?????????

	pthread_mutex_lock(&mutex);
	bool result = false;
	if (pthread_cond_timedwait (&cond, &mutex, &time) == 0)
		result = true;
	pthread_mutex_unlock(&mutex);
	return result;

	#endif

#elif WINDOWS
	if (milliseconds == -1)
		milliseconds = INFINITE;

	DWORD result = WaitForSingleObject (event, milliseconds);
	return result == WAIT_TIMEOUT ? false : true;

#endif 

#if !WINDOWS
//	WARNING ("Return false on time out not implemented!")
	return true;
#endif
}

//------------------------------------------------------------------------
void FCondition::reset ()
{
#if WINDOWS
	ResetEvent (event);
#elif PTHREADS
	state = 0;
#endif
}


//------------------------------------------------------------------------
void FThreadSleep (int32 milliseconds)
{
#if WINDOWS
	Sleep (milliseconds);
#elif PTHREADS
	static FSemaphore sem (0, "Sleep Semaphore");
	sem.acquire (milliseconds);	// be sure to do a passive wait (release CPU for other threads)
//	usleep (milliseconds * 1000);
#endif
}

//------------------------------------------------------------------------
// FSemaphore
//------------------------------------------------------------------------
FSemaphore::FSemaphore (int32 initialCount, const char8* name)
#if __MACH__
	:sem (initialCount)
#endif
{
	#if WINDOWS
	// Windows will *not* create a new semaphore if the name already is used!
	// In that case, it returns the existing semaphore!
	// So don't name your semaphores!
	sem = CreateSemaphore (0, initialCount, LONG_MAX, NULL);
	
	#elif PTHREADS
	#if __MACH__
	#else
	sem = sem_open (name, O_CREAT, 0644, initialCount);
	if (sem == (sem_t *)SEM_FAILED)
		sem = 0;
	else
	sem_init (sem, 0, initialCount);
	#endif
	
	#else
	WARNING ("Not implemented")
	#endif
}

//------------------------------------------------------------------------
FSemaphore::~FSemaphore ()
{
	#if WINDOWS
	CloseHandle (sem);

	#elif PTHREADS
	#if __MACH__

	#else
	if (sem)
	{
		sem_close (sem);
		sem_destroy (sem);
	}
	#endif
	
	#else
	WARNING ("Not implemented")
	#endif
}

//------------------------------------------------------------------------
bool FSemaphore::verify ()
{
	#if WINDOWS
	return sem != 0;

	#elif PTHREADS
		#if __MACH__
			return sem.verify ();
		#else
			return sem != 0;
		#endif
	
	#else
	WARNING ("Not implemented")
	return true;
	#endif
}

//------------------------------------------------------------------------
bool FSemaphore::acquire (int32 timeOut)
{
	// return "true" is sem acquired, false if timeout (or error)

	#if WINDOWS
	DWORD t = timeOut;
	if (timeOut < 0)
		t = INFINITE;
	return WaitForSingleObject (sem, t) == WAIT_OBJECT_0;

	#elif PTHREADS
	#if __MACH__
	if (sem.verify ())
	{
		if (timeOut >= 0)
		{
			return sem.timedWait (timeOut);
		}
		else
		{
			sem.wait ();
			return true;
		}
	}
	return false;
	
	#else
	if (sem)
	return (sem_wait (sem) == 0);
	return false;

	#endif

	#else
	WARNING ("Not implemented")
	return false;
	#endif
}

//------------------------------------------------------------------------
void FSemaphore::release (int32 count)
{
	#if WINDOWS
	ReleaseSemaphore (sem, count, NULL);

	#elif PTHREADS
	#if __MACH__
	if (count < 1)
	{
		sem.signalAll ();
	}
	else
	{
		while (count--)
			sem.signal ();
	}
	#else
	if (sem)
		sem_post (sem);
	#endif
	#else
	WARNING ("Not implemented")
	#endif
}

#if WINDOWS
//------------------------------------------------------------------------
static FLock gLTSLock;

//------------------------------------------------------------------------
static TArray<uint32>& getLTSKeys ()
{
	static TArray<uint32> gInstance;
	return gInstance;
}
#endif
	
//------------------------------------------------------------------------
FLocalThreadStorage* FLocalThreadStorage::create ()
{
	FLocalThreadStorage* localStorage = NEW FLocalThreadStorage ();
	if (localStorage->init ())
		return localStorage;
	delete localStorage;
	return 0;
}

//------------------------------------------------------------------------
void FLocalThreadStorage::initStates ()
{
#if WINDOWS
	getLTSKeys ();	// Hopefully the compiler does not remove during optimizations, only used to create the static LTS key instance
#endif
}

//------------------------------------------------------------------------
FLocalThreadStorage::FLocalThreadStorage ()
: platformKey (0)
{}

//------------------------------------------------------------------------
FLocalThreadStorage::~FLocalThreadStorage ()
{
#if PTHREADS
	if (platformKey)
		pthread_key_delete (platformKey);

#elif WINDOWS
	if (platformKey)
	{
		FGuard g (gLTSLock);
		TlsFree (platformKey);
		getLTSKeys ().remove (platformKey);
	}

#else
	ASSERT(false);
#endif
}

#if PTHREADS
//------------------------------------------------------------------------
static void FLocalThreadStoragePThreadDestructor (void* data)
{
	FUnknown* unknownData = (FUnknown*)data;
	unknownData->release ();
}

#endif
//------------------------------------------------------------------------
bool FLocalThreadStorage::init ()
{
#if PTHREADS
	return pthread_key_create (&platformKey, FLocalThreadStoragePThreadDestructor) == 0;

#elif WINDOWS
	platformKey = TlsAlloc ();
	if (platformKey != TLS_OUT_OF_INDEXES)
	{
		FGuard g (gLTSLock);
		getLTSKeys ().add (platformKey);
		return true;
	}
	return false;

#else
	ASSERT(false);
	return false;
#endif
}

//------------------------------------------------------------------------
bool FLocalThreadStorage::setData (FUnknown* data)
{
	FUnknown* currentData = getData ();
	if (currentData)
		currentData->release ();

	if (data)
		data->addRef ();

#if PTHREADS
	return pthread_setspecific (platformKey, data) == 0;

#elif WINDOWS
	return TlsSetValue (platformKey, (LPVOID)data) ? true : false;

#else
	ASSERT(false);
	return false;
#endif
}

//------------------------------------------------------------------------
FUnknown* FLocalThreadStorage::getData () const
{
#if PTHREADS
	return (FUnknown*)pthread_getspecific (platformKey);

#elif WINDOWS
	return (FUnknown*)TlsGetValue (platformKey);

#else
	ASSERT(false);
	return false;
#endif
}

#if WINDOWS
//------------------------------------------------------------------------
void FLocalThreadStorage::onThreadDestruction ()
{
	FGuard g (gLTSLock);
	if (getLTSKeys ().total () > 0)
	{
		FOREACH_T (uint32, key, getLTSKeys ())
			FUnknown* obj = (FUnknown*)TlsGetValue (key);
			if (obj)
				obj->release ();
		ENDFOR
	}
}
#endif

#if WINDOWS
//------------------------------------------------------------------------
FThreadDetector::FThreadDetector ()
: oldThreadCount (0)
, newThreadCount (0)
{
}

//------------------------------------------------------------------------
int32 FThreadDetector::detectThreads (uint32* idArray)
{
	// Take a snapshot of all threads currently in the system. 
	HANDLE hThreadSnap = CreateToolhelp32Snapshot (TH32CS_SNAPTHREAD, 0); 
	if (hThreadSnap == INVALID_HANDLE_VALUE) 
		return -1; 

	THREADENTRY32 te32 = {0}; 
	te32.dwSize = sizeof (THREADENTRY32); 
	int32 count = 0;
	uint32 pid = GetCurrentProcessId ();

	if (Thread32First (hThreadSnap, &te32))
	{
		do
		{
			if (te32.th32OwnerProcessID == pid)
			{
				idArray[count++] = te32.th32ThreadID;
				if (count >= kMaxThreads)
					break;
			}
		}
		while (Thread32Next (hThreadSnap, &te32));
	}
	else
		count = -1;		// could not walk the list of threads

	CloseHandle (hThreadSnap); 
	return count; 
}

//------------------------------------------------------------------------
bool FThreadDetector::startDetection ()
{
	oldThreadCount = detectThreads (oldThreadIDs);
	return oldThreadCount >= 0;
}

//------------------------------------------------------------------------
void FThreadDetector::stopDetection ()
{
	uint32 threadIDs[kMaxThreads];
	int32 count = detectThreads (threadIDs);
	if (count > oldThreadCount)
	{
		// find new
		for (int32 i = 0; i < count; i++)
		{
			bool found = false;
			
			for (int32 j = 0; j < oldThreadCount; j++)
			{
				if (threadIDs[i] == oldThreadIDs[j])
				{
					found = true;
					break;
				}
			}

			if (found == false)
			{
				newThreads [newThreadCount] = threadIDs[i];
				newThreadCount++;
				if (newThreadCount >= kMaxNewThreads)
					break;
			}
		}
	}
}

//------------------------------------------------------------------------
void* FThreadDetector::openNewThread (int32 index) const
{
	if (index < newThreadCount && index >= 0)
	{
		uint32 newThreadID = newThreads [index];
		
		// this is probably the Thread
		typedef HANDLE (WINAPI *OPENTHREAD_FUNC) (DWORD, BOOL, DWORD);
		OPENTHREAD_FUNC _OpenThread_ = (OPENTHREAD_FUNC) GetProcAddress (GetModuleHandle (STR("Kernel32")), "OpenThread");

		if (_OpenThread_)
			return (*_OpenThread_)(THREAD_SET_INFORMATION, FALSE, newThreadID);
	}
	return 0;
}

#endif

//------------------------------------------------------------------------
static void defaultPanic (int32 code)
{
	ASSERT (code == 0)
	ASSERT (code != 0)
#if 1 //DEVELOPMENT
	// Forced crash disabled for initial BONVILLE release per request from Michael/Werner
	// TODO: create SKI access to setup a "crasher" for internal use and special support cases for the future
#if PTHREADS
	// Also support pre OSX 10.7, they don't provide abort_report_np()
	// Older OSX version will simply call abort(), newer will provide more info for the crash report
	typedef void (*ABORT_REPORT_FUNC)(const char *, ...);	
	ABORT_REPORT_FUNC abort_report_np_addr = (ABORT_REPORT_FUNC)dlsym (RTLD_DEFAULT, "abort_report_np");
	if (abort_report_np_addr == 0)
		abort ();
	((ABORT_REPORT_FUNC)abort_report_np_addr)("Base Panic %d\n", code);
#elif WINDOWS
	// Windows does not have a proper way to present more information
	// but the generated dmp should be able to reveal "code".
	// Don't show any additional GUI message
	// abort() will result in a .dmp file on release builds
	_set_abort_behavior (0, _WRITE_ABORT_MSG);
	abort ();
#endif
#endif
}

//------------------------------------------------------------------------
static FPanicAssert::PANIC_FUNC panicHook = defaultPanic;

//------------------------------------------------------------------------
void FPanicAssert::setPanicHook (PANIC_FUNC newPanicHook)
{
	if (newPanicHook != 0)
	{
		ASSERT (panicHook == defaultPanic)	// don't allow nested custom panics
		panicHook = newPanicHook;
	}
	else
	{
		ASSERT (panicHook != defaultPanic)	// don't reset if is wasn't set before
		panicHook = defaultPanic;
	}
}

//------------------------------------------------------------------------
void FPanicAssert::panic (int32 code)
{
	if (panicHook)
		panicHook (code);
}


	
} // namespace Steinberg
