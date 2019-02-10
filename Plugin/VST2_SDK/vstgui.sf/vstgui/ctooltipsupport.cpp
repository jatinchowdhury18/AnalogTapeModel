//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework not only for VST plugins : 
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

#include "ctooltipsupport.h"
#include "cvstguitimer.h"

#if WINDOWS
#define _WIN32_WINNT 0x0501	// Works only on Windows XP and above because of TTM_POPUP
#include <commctrl.h>
extern void* hInstance;
inline HINSTANCE GetInstance () { return (HINSTANCE)hInstance; }
static void* InitTooltip (CFrame* frame);
#endif

#if MAC_COCOA
#include "cocoasupport.h"
#endif

#if DEBUG
#define DEBUGLOG 0
#endif

enum {
	kHidden,
	kVisible,
	kHiding,
	kShowing,
	kForceVisible,
};

//------------------------------------------------------------------------
/*! @class VSTGUI::CTooltipSupport
A generic way to add tooltip support to VSTGUI.
@section ctooltipsupport_example Example
Adding a tooltip to a view
\code
const char* tooltipText = "This is a tooltip";
view->setAttribute (kCViewTooltipAttribute, strlen (tooltipText)+1, tooltipText);
\endcode
Adding CTooltipSupport
\code
CTooltipSupport* tooltipSupport = new CTooltipSupport (frame);
\endcode
------------------------------------------------------------------------*/
/**
 * @param frame CFrame object
 * @param delay tooltip delay time in milliseconds
 */
CTooltipSupport::CTooltipSupport (CFrame* frame, int delay)
: timer (0)
, frame (frame)
, currentView (0)
, platformObject (0)
, delay (delay)
, state (kHidden)
{
	timer = new CVSTGUITimer (this, delay);
	frame->setMouseObserver (this);
	frame->remember ();

	#if WINDOWS
	platformObject = InitTooltip (frame);

	#endif
}

//------------------------------------------------------------------------
CTooltipSupport::~CTooltipSupport ()
{
	timer->forget ();

	#if MAC_COCOA
	nsViewRemoveTooltip (frame, true);
	#endif

	frame->setMouseObserver (0);
	frame->forget ();

	#if WINDOWS
	if (platformObject)
		DestroyWindow ((HWND)platformObject);

	#endif
}

//------------------------------------------------------------------------
static char* getTooltipFromView (CView* view)
{
	char* tooltip = 0;
	long tooltipSize = 0;
	if (view->getAttributeSize (kCViewTooltipAttribute, tooltipSize))
	{
		tooltip = (char*)malloc (tooltipSize + 1);
		memset (tooltip, 0, tooltipSize+1);
		if (!view->getAttribute (kCViewTooltipAttribute, tooltipSize, tooltip, tooltipSize))
		{
			free (tooltip);
			tooltip = 0;
		}
	}
	return tooltip;
}

//------------------------------------------------------------------------
static bool viewHasTooltip (CView* view)
{
	long tooltipSize = 0;
	if (view->getAttributeSize (kCViewTooltipAttribute, tooltipSize))
	{
		if (tooltipSize > 0)
			return true;
	}
	return false;
}

//------------------------------------------------------------------------
void CTooltipSupport::onMouseEntered (CView* view, CFrame* frame)
{
	if (viewHasTooltip (view))
	{
		currentView = view;
		if (state == kHiding)
		{
			#if DEBUGLOG
			DebugPrint ("CTooltipSupport::onMouseEntered (%s) - show tooltip\n", view->getClassName ());
			#endif
			state = kShowing;
			timer->setFireTime (50);
			timer->start ();
		}
		else if (state == kHidden)
		{
			#if DEBUGLOG
			DebugPrint ("CTooltipSupport::onMouseEntered (%s) - start timer\n", view->getClassName ());
			#endif
			state = kShowing;
			timer->setFireTime (delay);
			timer->start ();
		}
		else
		{
			#if DEBUGLOG
			DebugPrint ("CTooltipSupport::onMouseEntered (%s) - unexpected internal state\n", view->getClassName ());
			#endif
		}
	}
}

//------------------------------------------------------------------------
void CTooltipSupport::onMouseExited (CView* view, CFrame* frame)
{
	if (currentView)
	{
		if (state == kHidden || state == kShowing)
		{
			hideTooltip ();
			timer->stop ();
			timer->setFireTime (delay);
		}
		else
		{
			state = kHiding;
			timer->setFireTime (200);
			timer->start ();
		}
		currentView = 0;
		#if DEBUGLOG
		DebugPrint ("CTooltipSupport::onMouseExited (%s)\n", view->getClassName ());
		#endif
	}
}

//------------------------------------------------------------------------
void CTooltipSupport::onMouseMoved (CFrame* frame, const CPoint& where)
{
	if (currentView && state != kForceVisible)
	{
		CRect r (lastMouseMove.x-2, lastMouseMove.y-2, lastMouseMove.x+2, lastMouseMove.y+2);
		if (!r.pointInside (where))
		{
			if (state == kHidden)
			{
				if (timer->stop ())
				{
					#if DEBUGLOG
					DebugPrint ("CTooltipSupport::onMouseMoved (%s) - Timer restarted\n", currentView->getClassName ());
					#endif
					timer->start ();
				}
			}
			else if (state == kVisible)
			{
				#if DEBUGLOG
				DebugPrint ("CTooltipSupport::onMouseMoved (%s) - will hide tooltip\n", currentView->getClassName ());
				#endif
				state = kHiding;
				timer->setFireTime (200);
				timer->start ();
			}
			else
			{
				#if DEBUGLOG
				DebugPrint ("CTooltipSupport::onMouseMoved (%s) - state: %d\n", currentView->getClassName (), state);
				#endif
			}
		}
		else
		{
			#if DEBUGLOG
			DebugPrint ("CTooltipSupport::onMouseMoved (%s) - small move\n", currentView->getClassName ());
			#endif
		}
	}
	lastMouseMove = where;
}

//------------------------------------------------------------------------
void CTooltipSupport::onMouseDown (CFrame* frame, const CPoint& where)
{
	if (state != kHidden)
	{
		timer->stop ();
		timer->setFireTime (delay);
		hideTooltip ();
	}
}

//------------------------------------------------------------------------
void CTooltipSupport::hideTooltip ()
{
	if (state != kHidden)
	{
		state = kHidden;
		#if MAC_COCOA
		if (frame->getNSView ())
		{
			nsViewRemoveTooltip (frame, false);
			return;
		}
		#endif
		
		#if MAC_CARBON
		HMHideTag ();
		#endif

		#if WINDOWS
		if (platformObject)
		{
			TOOLINFO ti = {0};
		    ti.cbSize = sizeof(TOOLINFO);
			ti.hwnd = (HWND)frame->getSystemWindow ();
			ti.uId = 0;
			ti.lpszText = 0;
			SendMessage ((HWND)platformObject, TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
			SendMessage ((HWND)platformObject, TTM_POP, 0, 0);
		}

		#endif

		#if DEBUGLOG
		DebugPrint ("CTooltipSupport::hideTooltip\n");
		#endif
	}
}

//------------------------------------------------------------------------
void CTooltipSupport::showTooltip ()
{
	if (currentView)
	{
		CRect r (currentView->getVisibleSize ());
		CPoint p;
		currentView->localToFrame (p);
		r.offset (p.x, p.y);

		char* tooltip = getTooltipFromView (currentView);
		
		if (tooltip)
		{
			state = kForceVisible;
			#if MAC_COCOA
			if (frame->getNSView ())
			{
				nsViewSetTooltip (currentView, tooltip);
				free (tooltip);
				return;
			}
			#endif

			#if MAC_CARBON
			CCoord x, y;
			currentView->getFrame ()->getPosition (x,y);
			r.offset (x, y);

			HMHelpContentRec helpContent = {0};
			helpContent.version = 0;
			helpContent.absHotRect.left = r.left;
			helpContent.absHotRect.right = r.right;
			helpContent.absHotRect.top = r.top;
			helpContent.absHotRect.bottom = r.bottom;
			helpContent.tagSide = kHMDefaultSide;
			helpContent.content[0].contentType = kHMCFStringContent;
			helpContent.content[0].u.tagCFString = CFStringCreateWithCString (0, tooltip, kCFStringEncodingUTF8);
			HMDisplayTag(&helpContent);
			CFRelease (helpContent.content[0].u.tagCFString);
			#endif // MAC_CARBON
			
			#if WINDOWS
			UTF8StringHelper tooltipText (tooltip);
			if (platformObject)
			{
				RECT rc;
				rc.left = (LONG)r.left;
				rc.top = (LONG)r.top;
				rc.right = (LONG)r.right;
				rc.bottom = (LONG)r.bottom;
				TOOLINFO ti = {0};
			    ti.cbSize = sizeof(TOOLINFO);
				ti.hwnd = (HWND)frame->getSystemWindow ();
				ti.uId = 0;
				ti.rect = rc;
				ti.lpszText = (TCHAR*)(const TCHAR*)tooltipText;
				SendMessage ((HWND)platformObject, TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
				SendMessage ((HWND)platformObject, TTM_NEWTOOLRECT, 0, (LPARAM)&ti);
 				SendMessage ((HWND)platformObject, TTM_POPUP, 0, 0);
			}
			#endif // WINDOWS
			free (tooltip);
			#if DEBUGLOG
			DebugPrint ("CTooltipSupport::showTooltip (%s)\n", currentView->getClassName ());
			#endif
		}
	}
}

//------------------------------------------------------------------------
CMessageResult CTooltipSupport::notify (CBaseObject* sender, const char* msg)
{
	if (msg == CVSTGUITimer::kMsgTimer)
	{
		if (state == kHiding)
		{
			hideTooltip ();
			timer->stop ();
			timer->setFireTime (delay);
		}
		else if (state == kShowing)
		{
			showTooltip ();
			timer->setFireTime (100);
		}
		else if (state == kForceVisible)
		{
			state = kVisible;
			timer->stop ();
			timer->setFireTime (delay);
		}
		return kMessageNotified;
	}
	return kMessageUnknown;
}

#if WINDOWS
void* InitTooltip (CFrame* frame)
{
    TOOLINFO    ti;
	// Create the ToolTip control.
    HWND hwndTT = CreateWindow (TOOLTIPS_CLASS, TEXT(""),
                          WS_POPUP,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, (HMENU)NULL, GetInstance (),
                          NULL);

    // Prepare TOOLINFO structure for use as tracking ToolTip.
    ti.cbSize = sizeof(TOOLINFO);
    ti.uFlags = TTF_SUBCLASS;
    ti.hwnd   = (HWND)frame->getSystemWindow ();
    ti.uId    = (UINT)0;
    ti.hinst  = GetInstance ();
    ti.lpszText  = TEXT("This is a tooltip");
	ti.rect.left = ti.rect.top = ti.rect.bottom = ti.rect.right = 0;

	// Add the tool to the control
    if (!SendMessage (hwndTT, TTM_ADDTOOL, 0, (LPARAM)&ti))
	{
		DestroyWindow (hwndTT);
		return 0;
    }

	return hwndTT;
}
#endif
