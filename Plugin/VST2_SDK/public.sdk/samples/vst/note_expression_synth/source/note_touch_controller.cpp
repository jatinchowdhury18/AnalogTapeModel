//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/note_expression_synth/source/note_touch_controller.cpp
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

#include "note_touch_controller.h"
#include "pluginterfaces/vst/ivstevents.h"
#include "pluginterfaces/vst/ivstnoteexpression.h"

using namespace Steinberg;
using Steinberg::Vst::Event;

namespace VSTGUI {

//-----------------------------------------------------------------------------
NoteTouchController::NoteTouchController (int32_t pitch, Steinberg::Vst::IInterAppAudioHost* host)
: host (host)
, pad (0)
, pitch (pitch)
, noteID (-1)
, xNEType (-1)
, yNEType (-1)
{
	
}

//-----------------------------------------------------------------------------
void NoteTouchController::startNote (float velocity)
{
	Event e = {};
	e.type = Event::kNoteOnEvent;
	e.noteOn.pitch = pitch;
	e.noteOn.velocity = velocity;
	if (host->scheduleEventFromUI (e) == kResultTrue)
	{
		noteID = e.noteOn.noteId;
		pad->setBackColor (kGreyCColor);
	}
	
}

//-----------------------------------------------------------------------------
void NoteTouchController::stopNote (float velocity)
{
	if (noteID != -1)
	{
		Event e = {};
		e.type = Event::kNoteOffEvent;
		e.noteOff.noteId = noteID;
		e.noteOff.pitch = pitch;
		e.noteOff.velocity = velocity;
		host->scheduleEventFromUI (e);
		noteID = -1;
		pad->setBackColor (originalPadBackgroundColor);
	}
}

//-----------------------------------------------------------------------------
void NoteTouchController::sendNoteExpression (int32_t type, float value)
{
	if (type != -1 && noteID != -1)
	{
		Event e = {};
		e.type = Event::kNoteExpressionValueEvent;
		e.noteExpressionValue.noteId = noteID;
		e.noteExpressionValue.typeId = type;
		if (type == Vst::kTuningTypeID)
		{
			value = ((value - 0.5) * 0.1 + 0.5);
		}
		else if (type == Vst::kVolumeTypeID)
		{
			value = 0.3 * value;
		}
		e.noteExpressionValue.value = value;
		host->scheduleEventFromUI (e);
	}
}

//-----------------------------------------------------------------------------
void NoteTouchController::controlBeginEdit (CControl* pControl)
{
	if (pControl == pad)
	{
		
	}
}

//-----------------------------------------------------------------------------
void NoteTouchController::controlEndEdit (CControl* pControl)
{
	if (pControl == pad)
	{
		float x, y;
		CXYPad::calculateXY (pad->getValue (), x, y);
		stopNote (y);
	}
}

//-----------------------------------------------------------------------------
void NoteTouchController::valueChanged (CControl* pControl)
{
	if (pControl == pad)
	{
		float x, y;
		CXYPad::calculateXY (pad->getValue (), x, y);
		if (noteID == -1)
		{
			float velocity = logf (y + 0.4) + 0.8;
#if DEBUG_LOG
			FDebugPrint ("%f\n", velocity);
#endif
			startNote (velocity);
		}
		sendNoteExpression (xNEType, x);
		sendNoteExpression (yNEType, y);
	}
}

//-----------------------------------------------------------------------------
CView* NoteTouchController::verifyView (CView* view, const UIAttributes& attributes, IUIDescription* description)
{
	if (pad == 0)
	{
		pad = dynamic_cast<CXYPad*>(view);
		pad->setListener (this);
		pad->setStopTrackingOnMouseExit (true);
		originalPadBackgroundColor = pad->getBackColor ();
	}
	return view;
}

}
