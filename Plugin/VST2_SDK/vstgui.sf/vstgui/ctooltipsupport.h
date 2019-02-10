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

#ifndef __ctooltipsupport__
#define __ctooltipsupport__

#include "vstgui.h"

BEGIN_NAMESPACE_VSTGUI

class CVSTGUITimer;

//-----------------------------------------------------------------------------
// CTooltipSupport Declaration
//! Generic Tooltip Support class
//-----------------------------------------------------------------------------
class CTooltipSupport : public CBaseObject, public IMouseObserver
{
public:
	CTooltipSupport (CFrame* frame, int delay = 1000);
	~CTooltipSupport ();

protected:
	void showTooltip ();
	void hideTooltip ();

	// CBaseObject
	CMessageResult notify (CBaseObject* sender, const char* msg);

	// IMouseObserver
	void onMouseEntered (CView* view, CFrame* frame);
	void onMouseExited (CView* view, CFrame* frame);
	void onMouseMoved (CFrame* frame, const CPoint& where);
	void onMouseDown (CFrame* frame, const CPoint& where);

	CVSTGUITimer* timer;
	CFrame* frame;
	CView* currentView;
	void* platformObject;

	int delay;
	int state;
	CPoint lastMouseMove;
};

END_NAMESPACE_VSTGUI

#endif

