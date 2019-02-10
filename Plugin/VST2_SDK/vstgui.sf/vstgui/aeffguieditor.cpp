//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins
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

#ifndef __aeffguieditor__
#include "aeffguieditor.h"
#endif

#ifndef __audioeffectx__
#include "audioeffectx.h"
#endif

#define kIdleRate    100 // host idle rate in ms
#define kIdleRate2    50
#define kIdleRateMin   4 // minimum time between 2 idles in ms

#if WINDOWS
static struct tagMSG windowsMessage;
#endif

#if MAC
#include <Carbon/Carbon.h>
#endif

//-----------------------------------------------------------------------------
// AEffGUIEditor Implementation
//-----------------------------------------------------------------------------
AEffGUIEditor::AEffGUIEditor (void* pEffect) 
: AEffEditor ((AudioEffect*)pEffect)
, inIdleStuff (false)
{
	((AudioEffect*)pEffect)->setEditor (this);
	systemWindow = 0;
	lLastTicks   = getTicks ();

	#if WINDOWS
	OleInitialize (0);
	#endif
	#if MAC
	void InitMachOLibrary ();
	InitMachOLibrary ();
	#endif
}

//-----------------------------------------------------------------------------
AEffGUIEditor::~AEffGUIEditor () 
{
	#if WINDOWS
	OleUninitialize ();
	#endif
	#if MAC
	void ExitMachOLibrary ();
	ExitMachOLibrary ();
	#endif
}

//-----------------------------------------------------------------------------
#if VST_2_1_EXTENSIONS
bool AEffGUIEditor::onKeyDown (VstKeyCode& keyCode)
{
	return frame ? frame->onKeyDown (keyCode) > 0 : false;
}

//-----------------------------------------------------------------------------
bool AEffGUIEditor::onKeyUp (VstKeyCode& keyCode)
{
	return frame ? frame->onKeyUp (keyCode) > 0 : false;
}
#endif

//-----------------------------------------------------------------------------
void AEffGUIEditor::draw (ERect* ppErect)
{
	if (frame)
	{
		CRect r;
		if (ppErect)
			r (ppErect->left, ppErect->top, ppErect->right, ppErect->bottom);
		else
			r = frame->getViewSize ();
		CDrawContext* context = frame->createDrawContext();
		frame->drawRect (context, r);
		context->forget();
	}
}

#if MAC
//-----------------------------------------------------------------------------
long AEffGUIEditor::mouse (long x, long y)
{
	#if VSTGUI_ENABLE_DEPRECATED_METHODS
	if (frame)
	{
		CDrawContext* context = frame->createDrawContext();
		CPoint where (x, y);
		frame->mouse (context, where);
		context->forget ();
		return 1;
	}
	#endif	// #if VSTGUI_ENABLE_DEPRECATED_METHODS
	return 0;
}
#endif

//-----------------------------------------------------------------------------
bool AEffGUIEditor::open (void* ptr)
{
	return AEffEditor::open (ptr);
}

//-----------------------------------------------------------------------------
void AEffGUIEditor::idle ()
{
	if (inIdleStuff)
		return;

	AEffEditor::idle ();
	if (frame)
		frame->idle ();
}

//-----------------------------------------------------------------------------
long AEffGUIEditor::knobMode = kCircularMode;

//-----------------------------------------------------------------------------
bool AEffGUIEditor::setKnobMode (int val) 
{
	AEffGUIEditor::knobMode = val;
	return true;
}

//-----------------------------------------------------------------------------
bool AEffGUIEditor::onWheel (float distance)
{
	#if VSTGUI_ENABLE_DEPRECATED_METHODS
	if (frame)
	{
		CDrawContext* context = frame->createDrawContext ();
		CPoint where;
		context->getMouseLocation (where);
		long buttons = context->getMouseButtons ();
		bool result = frame->onWheel (where, distance, buttons);
		context->forget ();
		return result;
	}
	#endif	
	return false;
}

//-----------------------------------------------------------------------------
void AEffGUIEditor::wait (unsigned long ms)
{
	#if MAC
	RunCurrentEventLoop (kEventDurationMillisecond * ms);
	
	#elif WINDOWS
	Sleep (ms);

	#endif
}

//-----------------------------------------------------------------------------
unsigned long AEffGUIEditor::getTicks ()
{
	#if MAC
	return (TickCount () * 1000) / 60;
	
	#elif WINDOWS
	return (unsigned long)GetTickCount ();
	
	#endif

	return 0;
}

//-----------------------------------------------------------------------------
void AEffGUIEditor::doIdleStuff ()
{
	// get the current time
	unsigned long currentTicks = getTicks ();

	if (currentTicks < lLastTicks)
	{
		wait (kIdleRateMin);
		currentTicks += kIdleRateMin;
		if (currentTicks < lLastTicks - kIdleRate2)
			return;
	}

	idle ();

	#if WINDOWS
	if (PeekMessage (&windowsMessage, NULL, WM_PAINT, WM_PAINT, PM_REMOVE))
		DispatchMessage (&windowsMessage);

	#endif

	// save the next time
 	lLastTicks = currentTicks + kIdleRate;

	inIdleStuff = true;

	if (effect)
		effect->masterIdle ();

	inIdleStuff = false;
}

//-----------------------------------------------------------------------------
bool AEffGUIEditor::getRect (ERect **ppErect)
{
	*ppErect = &rect;
	return true;
}

#if MAC
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include <dlfcn.h>
#include <CoreFoundation/CFBundle.h>
#include <string>

BEGIN_NAMESPACE_VSTGUI

void* gBundleRef = 0;

END_NAMESPACE_VSTGUI

#if USE_NAMESPACE
#define VSTGUI_BUNDLEREF VSTGUI::gBundleRef
#else
#define VSTGUI_BUNDLEREF gBundleRef
#endif

// -----------------------------------------------------------------------------
void InitMachOLibrary ();
void InitMachOLibrary ()
{
	Dl_info info;
	if (dladdr ((const void*)InitMachOLibrary, &info))
	{
		if (info.dli_fname)
		{
			std::string name;
			name.assign (info.dli_fname);
			for (int i = 0; i < 3; i++)
			{
				int delPos = name.find_last_of ('/');
				if (delPos == -1)
				{
					fprintf (stdout, "Could not determine bundle location.\n");
					return; // unexpected
				}
				name.erase (delPos, name.length () - delPos);
			}
			CFURLRef bundleUrl = CFURLCreateFromFileSystemRepresentation (0, (const UInt8*)name.c_str (), name.length (), true);
			if (bundleUrl)
			{
				VSTGUI_BUNDLEREF = CFBundleCreate (0, bundleUrl);
				CFRelease (bundleUrl);
			}
		}
	}
}

// -----------------------------------------------------------------------------
void ExitMachOLibrary ();
void ExitMachOLibrary ()
{
	if (VSTGUI_BUNDLEREF)
		CFRelease (VSTGUI_BUNDLEREF);
}

#endif
