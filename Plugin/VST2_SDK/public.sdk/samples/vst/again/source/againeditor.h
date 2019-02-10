//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/againeditor.h
// Created by  : Steinberg, 04/2005
// Description : AGain Editor Example using VSTGUI 3.5
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
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
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#pragma once

#include "public.sdk/source/vst/vstguieditor.h"
#include "pluginterfaces/vst/ivstplugview.h"
#include "pluginterfaces/vst/ivstcontextmenu.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// AGainEditorView Declaration
//------------------------------------------------------------------------
class AGainEditorView:	public VSTGUIEditor,
						public CControlListener,
						public IParameterFinder,
						public IContextMenuTarget
{
public:
//------------------------------------------------------------------------
	AGainEditorView (void* controller);

	//---from VSTGUIEditor---------------
	bool PLUGIN_API open (void* parent);
	void PLUGIN_API close ();
	CMessageResult notify (CBaseObject* sender, const char* message);
	void beginEdit (long /*index*/) {}
	void endEdit (long /*index*/) {}

	//---from CControlListener---------
	void valueChanged (CControl* pControl);
	long controlModifierClicked (CControl* pControl, long button);
	void controlBeginEdit (CControl* pControl);
	void controlEndEdit (CControl* pControl);

	//---from EditorView---------------
	tresult PLUGIN_API onSize (ViewRect* newSize);
	tresult PLUGIN_API canResize () { return kResultFalse; }
	tresult PLUGIN_API checkSizeConstraint (ViewRect* rect);

	//---from IParameterFinder---------------
	tresult PLUGIN_API findParameter (int32 xPos, int32 yPos, ParamID& resultTag);

	//---from IContextMenuTarget---------------
	tresult PLUGIN_API executeMenuItem (int32 tag);

	DELEGATE_REFCOUNT (VSTGUIEditor)    
	tresult PLUGIN_API queryInterface (const char* iid, void** obj);

	//---Internal Function------------------
	void update (ParamID tag, ParamValue value);
	void messageTextChanged ();

//------------------------------------------------------------------------
protected:
	CTextEdit* textEdit;
	CHorizontalSlider* gainSlider;
	CTextEdit* gainTextEdit;
	CVuMeter* vuMeter;
	CBitmap* background;

	float lastVuMeterValue;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
