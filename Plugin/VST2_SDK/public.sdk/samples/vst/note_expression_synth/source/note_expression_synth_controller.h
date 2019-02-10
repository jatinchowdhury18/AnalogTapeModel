//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/note_expression_synth/source/note_expression_synth_controller.h
// Created by  : Steinberg, 02/2010
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

#include "public.sdk/source/vst/vsteditcontroller.h"
#include "pluginterfaces/vst/ivstnoteexpression.h"
#include "public.sdk/source/vst/vstnoteexpressiontypes.h"

#define MAX_VOICES				64
#define MAX_RELEASE_TIME_SEC	5.0
#define NUM_FILTER_TYPE			3
#define NUM_TUNING_RANGE		2 

namespace Steinberg {
namespace Vst {
namespace NoteExpressionSynth {

//-----------------------------------------------------------------------------
// Global Parameters
//-----------------------------------------------------------------------------
enum {
	kParamReleaseTime,
	kParamNoiseVolume,
	kParamSinusVolume,
	kParamTriangleVolume,
	kParamSinusDetune,
	kParamBypassSNA,
	kParamTriangleSlop,
	kParamFilterType,
	kParamFilterFreq,
	kParamFilterQ,
	kParamMasterVolume,
	kParamMasterTuning,
	kParamVelToLevel,
	kParamFilterFreqModDepth,
	kParamTuningRange,
	kParamActiveVoices,
	kParamSquareVolume,

	kNumGlobalParameters
};

//-----------------------------------------------------------------------------
/** Example Note Expression Edit Controller

\sa Steinberg::Vst::INoteExpressionController
\sa Steinberg::Vst::NoteExpressionTypeContainer
\sa Steinberg::Vst::NoteExpressionType
*/
class Controller: public EditController, public INoteExpressionController, public IMidiMapping
{
public:
	
	// EditController
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate ();
	tresult PLUGIN_API setComponentState (IBStream* state);

	virtual tresult PLUGIN_API setParamNormalized (ParamID tag, ParamValue value);

	// IMidiMapping
	virtual tresult PLUGIN_API getMidiControllerAssignment (int32 busIndex, int16 channel, CtrlNumber midiControllerNumber, ParamID& id/*out*/);

	// INoteExpressionController
	virtual int32 PLUGIN_API getNoteExpressionCount (int32 busIndex, int16 channel);
	virtual tresult PLUGIN_API getNoteExpressionInfo (int32 busIndex, int16 channel, int32 noteExpressionIndex, NoteExpressionTypeInfo& info /*out*/);
	virtual tresult PLUGIN_API getNoteExpressionStringByValue (int32 busIndex, int16 channel, NoteExpressionTypeID id, NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/);
	virtual tresult PLUGIN_API getNoteExpressionValueByString (int32 busIndex, int16 channel, NoteExpressionTypeID id, const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/);
	
	enum NoteExpressionTypeIds {
		kNoiseVolumeTypeID = kCustomStart,
		kFilterFreqModTypeID,
		kFilterQModTypeID,
		kSinusVolumeTypeID,
		kTriangleVolumeTypeID,
		kFilterTypeTypeID,
		kTriangleSlopeTypeID,
		kSinusDetuneTypeID,
		kReleaseTimeModTypeID,
		kTextInputTypeID,
		kSquareVolumeTypeID,
	};
	
	static FUnknown* createInstance (void*) { return (IEditController*)new Controller (); }

	static FUID cid;

	OBJ_METHODS (Controller, EditController)
	DEFINE_INTERFACES
		DEF_INTERFACE (INoteExpressionController)
		DEF_INTERFACE (IMidiMapping)
	END_DEFINE_INTERFACES (EditController)
	REFCOUNT_METHODS(EditController)

protected:
	NoteExpressionTypeContainer noteExpressionTypes;
};

}}} // namespaces
