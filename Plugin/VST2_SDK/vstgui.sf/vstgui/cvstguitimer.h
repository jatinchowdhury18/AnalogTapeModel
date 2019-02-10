//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins : 
//
// Version 3.6
//
//-----------------------------------------------------------------------------
// VSTGUI LICENSE
// (c) 2008, Steinberg Media Technologies, All Rights Reserved
//-----------------------------------------------------------------------------
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation 
//     and/or other materials provided with the distribution.
//   * Neither the name of the Steinberg Media Technologies nor the names of its
//     contributors may be used to endorse or promote products derived from this 
//     software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#ifndef __cvstguitimer__
#define __cvstguitimer__

#include "vstgui.h"

BEGIN_NAMESPACE_VSTGUI

//-----------------------------------------------------------------------------
// CVSTGUITimer Declaration
//! A timer class, which posts timer messages to CBaseObjects.
//-----------------------------------------------------------------------------
class CVSTGUITimer : public CBaseObject
{
public:
	CVSTGUITimer (CBaseObject* timerObject, int fireTime = 100);
	virtual ~CVSTGUITimer ();
	
	virtual bool start ();							///< starts the timer
	virtual bool stop ();							///< stops the timer, returns wheather timer was running or not

	virtual bool setFireTime (int newFireTime);		///< in milliseconds
	int getFireTime () const { return fireTime; }	///< in milliseconds

//-----------------------------------------------------------------------------
	static const char* kMsgTimer;					///< message string posted to CBaseObject's notify method
//-----------------------------------------------------------------------------
protected:
	int fireTime;
	CBaseObject* timerObject;

	void* platformTimer;
	#if MAC
	static void timerCallback (CFRunLoopTimerRef timer, void *info);
	#elif WINDOWS
	static VOID CALLBACK TimerProc (HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
	#endif
};

END_NAMESPACE_VSTGUI

#endif
