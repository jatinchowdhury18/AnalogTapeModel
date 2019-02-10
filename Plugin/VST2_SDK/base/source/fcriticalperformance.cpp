//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fcriticalperformance.h
// Created by  : Steinberg, 2013
// Description : Critical Performance Mode for Realtime Threads
//
//               Note: When using this file, add it to your own project and 
//               not to "base" because you'll also need to include the Core 
//               Audio library on Mac.
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


#include "base/source/fcriticalperformance.h"
#include "base/source/fdebug.h"

#if __MACH__ && !TARGET_OS_IPHONE
extern "C" 
{
	#include <mach/mach_init.h>
	#include <mach/thread_act.h>
}
#include <CoreAudio/CoreAudio.h>
#elif WINDOWS
#include <windows.h>
#endif

namespace Steinberg {

#if WINDOWS

//----------------------------------------------------------------------------
// Windows Vista Multimedia Class Scheduler Service (MMCSS)
//----------------------------------------------------------------------------

typedef HANDLE (WINAPI *SetThreadCharacteristicsCall) (LPCSTR, LPDWORD);
typedef BOOL (WINAPI *SetThreadPriorityCall) (HANDLE, Performance::AVRT_PRIORITY);
typedef BOOL (WINAPI *RevertThreadCharacteristicsCall) (HANDLE);

static HMODULE avrtLibrary = 0; 
static int32 avrtUseCount = 0;
static bool avrtLoadFailed = false;

static SetThreadCharacteristicsCall setThreadCharacteristicsFunction = 0;
static SetThreadPriorityCall setThreadPriorityFunction = 0;
static RevertThreadCharacteristicsCall revertThreadCharacteristicsFunction = 0;

//----------------------------------------------------------------------------
void useAvrtLibrary ()
{
	if (!avrtLibrary && avrtLoadFailed == false)
	{
		// init
		ASSERT (avrtUseCount == 0)

		avrtLibrary = LoadLibraryA ("avrt.dll");

		if (avrtLibrary)
		{
			setThreadCharacteristicsFunction = (SetThreadCharacteristicsCall)(GetProcAddress (avrtLibrary, "AvSetMmThreadCharacteristicsA"));
			setThreadPriorityFunction = (SetThreadPriorityCall)(GetProcAddress (avrtLibrary, "AvSetMmThreadPriority"));
			revertThreadCharacteristicsFunction = (RevertThreadCharacteristicsCall)(GetProcAddress (avrtLibrary, "AvRevertMmThreadCharacteristics"));
		}
		else
			avrtLoadFailed = true;
	}

	if (avrtLibrary)
		avrtUseCount++;
}

//----------------------------------------------------------------------------
void unuseAvrtLibrary ()
{
	if (avrtLibrary)
	{
		avrtUseCount--;
		ASSERT (avrtUseCount >= 0)

		if (avrtUseCount == 0)
		{
			setThreadCharacteristicsFunction = 0;
			setThreadPriorityFunction = 0;
			revertThreadCharacteristicsFunction = 0;

			FreeLibrary (avrtLibrary);

			avrtLibrary = 0;
		}
	}
}
#endif // WINDOWS


//----------------------------------------------------------------------------
// Critical Performance Mode Implementation
//----------------------------------------------------------------------------
FCriticalPerformanceEnabler::FCriticalPerformanceEnabler ()
{
#if WINDOWS
	useAvrtLibrary ();
#endif
}

//----------------------------------------------------------------------------
FCriticalPerformanceEnabler::~FCriticalPerformanceEnabler ()
{
#if WINDOWS
	unuseAvrtLibrary ();
#endif
}

//----------------------------------------------------------------------------
FCriticalPerformanceEnabler& FCriticalPerformanceEnabler::getInstance ()
{
	static FCriticalPerformanceEnabler instance;
	return instance;
}

//----------------------------------------------------------------------------
void* FCriticalPerformanceEnabler::useCriticalPerformanceMode (
	const Performance::Mode& mode,
	uint64 timeConstraintNanoSeconds, void* handle)
{
#if WINDOWS
	void* newHandle = 0;
		
	// first, disable
	if (revertThreadCharacteristicsFunction && handle)
		revertThreadCharacteristicsFunction (handle);
		
	if (mode.windowsEnable)
	{
		if (setThreadCharacteristicsFunction)
		{
			DWORD taskIndex = 0;
			newHandle = setThreadCharacteristicsFunction (mode.avrtThreadCharacteristics, &taskIndex);
		}
			
		if (setThreadPriorityFunction && newHandle)
		{
			setThreadPriorityFunction (newHandle, mode.threadPriority);
		}
	}
		
	return newHandle;

#elif __MACH__ && !TARGET_OS_IPHONE
	if (mode.macEnable)
	{
		thread_time_constraint_policy policyInfo;
		UInt64 hostTime = AudioConvertNanosToHostTime (timeConstraintNanoSeconds);
		policyInfo.period = hostTime;
	
		if (mode.critical)
			policyInfo.computation = hostTime;
		else
			policyInfo.computation = hostTime / 2;
		
		policyInfo.constraint = hostTime;
		policyInfo.preemptible = 1;
		thread_policy_set (mach_thread_self (), THREAD_TIME_CONSTRAINT_POLICY, (int*)&policyInfo, THREAD_TIME_CONSTRAINT_POLICY_COUNT);
	}
	else 
	{
		ASSERT (false) // disabling is not supported on Mac!
	}

	return 0;
	
#else
	return 0;
#endif
}
	
//----------------------------------------------------------------------------
bool FCriticalPerformanceEnabler::isCriticalPerformanceModeSupported ()
{
#if WINDOWS
	return (setThreadCharacteristicsFunction && setThreadPriorityFunction && revertThreadCharacteristicsFunction);

#elif __MACH__
	return true;

#else
	return false;
#endif
}

} // namespace Steinberg
