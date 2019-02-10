//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/timer.cpp
// Created by  : Steinberg, 05/2006
// Description : Timer class for receiving triggers at regular intervals
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

#include "base/source/timer.h"

namespace Steinberg {
static bool timersEnabled = true;

DisableDispatchingTimers::DisableDispatchingTimers ()
{
	oldState = timersEnabled;
	timersEnabled = false;
}

DisableDispatchingTimers::~DisableDispatchingTimers ()
{
	timersEnabled = oldState;
}

//------------------------------------------------------------------------
namespace SystemTime {

//------------------------------------------------------------------------
struct ZeroStartTicks
{
	static const uint64 startTicks;
	
	static int32 getTicks32 ()
	{
		return static_cast<int32> (SystemTime::getTicks64 () - startTicks);
	}
};
const uint64 ZeroStartTicks::startTicks = SystemTime::getTicks64 ();

//------------------------------------------------------------------------
int32 getTicks ()
{
	return ZeroStartTicks::getTicks32 ();
}

//------------------------------------------------------------------------
} // SystemTime

} // namespace

#if MAC
#include <CoreFoundation/CoreFoundation.h>
#include <mach/mach_time.h>

#ifdef verify
#undef verify
#endif

namespace Steinberg {

namespace SystemTime {
	struct MachTimeBase {
	private:
		struct mach_timebase_info timebaseInfo;

		MachTimeBase ()
		{
			mach_timebase_info (&timebaseInfo);
		}

		static const MachTimeBase& instance ()
		{
			static MachTimeBase gInstance;
			return gInstance;
		}
	public:
		static double getTimeNanos ()
		{
			const MachTimeBase& timeBase = instance ();
			double absTime = static_cast<double> (mach_absolute_time ());
			double d = (absTime / timeBase.timebaseInfo.denom) * timeBase.timebaseInfo.numer;	// nano seconds
			return d;
		}
	};

	//------------------------------------------------------------------------
	uint64 getTicks64 ()
	{
		return static_cast<uint64> (MachTimeBase::getTimeNanos () / 1000000.);
	}
} // namespace SystemTime

//------------------------------------------------------------------------
class MacPlatformTimer : public Timer
{
public:
	MacPlatformTimer (ITimerCallback* callback, uint32 milliseconds);
	~MacPlatformTimer ();

	void stop ();
	bool verify () const { return platformTimer != 0; }

	static void timerCallback (CFRunLoopTimerRef timer, void *info);
protected:
	CFRunLoopTimerRef platformTimer;
	ITimerCallback* callback;
};

//------------------------------------------------------------------------
MacPlatformTimer::MacPlatformTimer (ITimerCallback* callback, uint32 milliseconds)
: callback (callback)
, platformTimer (0)
{
	if (callback)
	{
		CFRunLoopTimerContext timerContext = {0};
		timerContext.info = this;
		platformTimer = CFRunLoopTimerCreate (kCFAllocatorDefault, CFAbsoluteTimeGetCurrent () + milliseconds * 0.001, milliseconds * 0.001f, 0, 0, timerCallback, &timerContext);
		if (platformTimer)
			CFRunLoopAddTimer (CFRunLoopGetMain (), platformTimer, kCFRunLoopCommonModes);
	}
}


//------------------------------------------------------------------------
MacPlatformTimer::~MacPlatformTimer ()
{
	stop ();
}

//------------------------------------------------------------------------
void MacPlatformTimer::stop ()
{
	if (platformTimer)
	{
		CFRunLoopRemoveTimer (CFRunLoopGetMain (), platformTimer, kCFRunLoopCommonModes);
		CFRelease (platformTimer);
		platformTimer = 0;
	}
}

//------------------------------------------------------------------------
void MacPlatformTimer::timerCallback (CFRunLoopTimerRef , void *info)
{
	if (timersEnabled)
	{
		MacPlatformTimer* timer = (MacPlatformTimer*)info;
		if (timer)
		{
			timer->callback->onTimer (timer);
		}
	}
}

//------------------------------------------------------------------------
Timer* Timer::create (ITimerCallback* callback, uint32 milliseconds)
{
	MacPlatformTimer* timer = NEW MacPlatformTimer (callback, milliseconds);
	if (timer->verify ())
		return timer;
	timer->release ();
	return 0;
}

}

#elif WINDOWS

#include "base/source/tarray.h"

#include <windows.h>

namespace Steinberg {

namespace SystemTime {
	uint64 getTicks64 ()
	{
		return GetTickCount64 ();
	}

}

//------------------------------------------------------------------------
// WinPlatformTimer
//------------------------------------------------------------------------
class WinPlatformTimer : public Timer
{
public:
//------------------------------------------------------------------------
	WinPlatformTimer (ITimerCallback* callback, uint32 milliseconds);
	~WinPlatformTimer ();

	void stop ();
	bool verify () const {return id != 0;}

//------------------------------------------------------------------------
private:
	UINT_PTR id;
	ITimerCallback* callback;

	static void addTimer (WinPlatformTimer* t);
	static void removeTimer (WinPlatformTimer* t);

	static void CALLBACK TimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	static TArray<WinPlatformTimer*>* timers;
};

//------------------------------------------------------------------------
TArray<WinPlatformTimer*>* WinPlatformTimer::timers = 0;

//------------------------------------------------------------------------
WinPlatformTimer::WinPlatformTimer (ITimerCallback* callback, uint32 milliseconds)
: callback (callback)
{
	id = SetTimer (0, 0, milliseconds, TimerProc);
	if (id)
		addTimer (this);
}

//------------------------------------------------------------------------
WinPlatformTimer::~WinPlatformTimer ()
{
	stop ();
}

//------------------------------------------------------------------------
void WinPlatformTimer::addTimer (WinPlatformTimer* t)
{
	if (timers == 0)
		timers = NEW TArray<WinPlatformTimer*>;
	timers->add (t);
}

//------------------------------------------------------------------------
void WinPlatformTimer::removeTimer (WinPlatformTimer* t)
{
	if (timers)
	{
		timers->remove (t);
		if (timers->total () == 0)
		{
			delete timers;
			timers = 0;
		}
	}
}

//------------------------------------------------------------------------
void WinPlatformTimer::stop ()
{
	if (id)
	{
		KillTimer (0, id);
		removeTimer (this);
		id = 0;
	}
}

//------------------------------------------------------------------------
void CALLBACK WinPlatformTimer::TimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
	if (timersEnabled && timers)
	{
		for (int32 i = 0; i < timers->total (); i++)
		{	
			WinPlatformTimer* timer = (WinPlatformTimer*)timers->at (i);
			if (timer->id == idEvent)
			{
				if (timer->callback)
					timer->callback->onTimer (timer);
				return;
			}
		}
	}
}

//------------------------------------------------------------------------
Timer* Timer::create (ITimerCallback* callback, uint32 milliseconds)
{
	WinPlatformTimer* platformTimer = NEW WinPlatformTimer (callback, milliseconds);
	if (platformTimer->verify ())
		return platformTimer;
	platformTimer->release ();
	return 0;
}

} // namespace Steinberg

#endif
