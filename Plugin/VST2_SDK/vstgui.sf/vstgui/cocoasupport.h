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

#ifndef __cocoasupport__
#define __cocoasupport__

#include "vstgui.h"

#if MAC_COCOA

/// \cond ignore

// used by CFrame
void* createNSView (CFrame* frame, const CRect& size);
void destroyNSView (void* nsView);
void invalidNSViewRect (void* nsView, const CRect& size);
void resizeNSView (void* nsView, const CRect& newSize);
void getSizeOfNSView (void* nsView, CRect* rect);
bool nsViewGetCurrentMouseLocation (void* nsView, CPoint& where);
void nsViewSetMouseCursor (CCursorType type);
void nsViewScrollRect (void* nsView, const CRect& src, const CPoint& distance);

// used by CTextEdit
void* addNSTextField (CFrame* frame, CTextEdit* edit);
void removeNSTextField (void* control);
bool getNSTextFieldText (void* control, char* text, long maxSize);
void moveNSTextField (void* control, CTextEdit* edit);

// used by COptionMenu
long showNSContextMenu (COptionMenu* menu, COptionMenu** usedMenu);

// used by CTooltipSupport
void nsViewSetTooltip (CView* view, const char* tooltip);
void nsViewRemoveTooltip (CView* view, bool immediately);

// helpers
#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
CRect rectFromNSRect (const NSRect& rect);
#endif

#endif

/// \endcond

#endif
