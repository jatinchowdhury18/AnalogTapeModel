//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/note_expression_synth/source/note_touch_controller.h
// Created by  : Steinberg, 08/2013
// Description :
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

#include "vstgui/vstgui.h"
#include "vstgui/vstgui_uidescription.h"
#include "pluginterfaces/vst/ivstinterappaudio.h"

namespace VSTGUI {

class NoteTouchController : public IController
{
public:
	NoteTouchController (int32_t pitch, Steinberg::Vst::IInterAppAudioHost* host);

	void setPitch (int32_t pitch) { this->pitch = pitch; }

	void setHorizontalNoteExpType (int32_t type) { xNEType = type; }
	void setVerticalNoteExpType (int32_t type) { yNEType = type; }

protected:
	void controlBeginEdit (CControl* pControl) VSTGUI_OVERRIDE_VMETHOD;
	void controlEndEdit (CControl* pControl) VSTGUI_OVERRIDE_VMETHOD;
	void valueChanged (CControl* pControl) VSTGUI_OVERRIDE_VMETHOD;
	CView* verifyView (CView* view, const UIAttributes& attributes, IUIDescription* description) VSTGUI_OVERRIDE_VMETHOD;

	void startNote (float velocity);
	void stopNote (float velocity);
	void sendNoteExpression (int32_t type, float value);
	
	Steinberg::Vst::IInterAppAudioHost* host;
	CXYPad* pad;
	CColor originalPadBackgroundColor;
	int32_t pitch;
	int32_t noteID;
	int32_t xNEType;
	int32_t yNEType;
};

}
