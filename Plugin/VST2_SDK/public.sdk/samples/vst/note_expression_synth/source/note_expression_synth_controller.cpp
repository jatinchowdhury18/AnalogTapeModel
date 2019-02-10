//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/note_expression_synth/source/note_expression_synth_controller.cpp
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

#include "note_expression_synth_controller.h"
#include "note_expression_synth_voice.h" // only needed for setComponentState
#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/futils.h"
#include "pluginterfaces/vst/ivstmidicontrollers.h"
#include "base/source/fstring.h"

namespace Steinberg {
namespace Vst {
namespace NoteExpressionSynth {

FUID Controller::cid (0x2AC0A888, 0x9406497F, 0xBBA6EABF, 0xC78D1372);

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class PanNoteExpressionType : public RangeNoteExpressionType
{
public:
	PanNoteExpressionType ()
	: RangeNoteExpressionType (kPanTypeID, String ("Pan"), String ("Pan"), 0, -1, 0, -100, 100, NoteExpressionTypeInfo::kIsBipolar|NoteExpressionTypeInfo::kIsAbsolute, 0)
	{
	}

	tresult getStringByValue (NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
	{
		if (valueNormalized == 0.5)
			UString128 ("C").copyTo (string, 128);
		else if (valueNormalized == 0)
			UString128 ("L").copyTo (string, 128);
		else if (valueNormalized == 1)
			UString128 ("R").copyTo (string, 128);
		else
			RangeNoteExpressionType::getStringByValue (valueNormalized, string);
		return kResultTrue;
	}
	
	tresult getValueByString (const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
	{
		String str (string);
		if (str == "C")
		{
			valueNormalized = 0.5;
			return kResultTrue;
		}
		else if (str == "L")
		{
			valueNormalized = 0.;
			return kResultTrue;
		}
		else if (str == "R")
		{
			valueNormalized = 1.;
			return kResultTrue;
		}
		return RangeNoteExpressionType::getValueByString (string, valueNormalized);
	}
	OBJ_METHODS(PanNoteExpressionType, RangeNoteExpressionType)
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class ReleaseTimeModNoteExpressionType : public NoteExpressionType
{
public:
	ReleaseTimeModNoteExpressionType ()
	: NoteExpressionType (Controller::kReleaseTimeModTypeID, String ("Release Time"), String ("RelTime"), String ("%"),
	                     -1, 0.5, 0., 1., 0, NoteExpressionTypeInfo::kIsBipolar|NoteExpressionTypeInfo::kIsOneShot)
	{
	}
	
	tresult getStringByValue (NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
	{
		UString128 wrapper;
		double timeFactor = pow (100., 2 * (valueNormalized - 0.5));
		wrapper.printFloat (timeFactor, timeFactor > 10 ? 1 : 2);
		wrapper.copyTo (string, 128);
		return kResultTrue;
	}
	
	tresult getValueByString (const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
	{
		String wrapper ((TChar*)string);
		ParamValue tmp;
		if (wrapper.scanFloat (tmp))
		{
			valueNormalized = Bound (0.0, 1.0, log10 (tmp) / 4. + 0.5);
			return kResultTrue;
		}
		return kResultFalse;
	}
	OBJ_METHODS(ReleaseTimeModNoteExpressionType, NoteExpressionType)
};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::initialize (FUnknown* context)
{
	tresult result = EditController::initialize (context);
	if (result == kResultTrue)
	{
	// Init parameters
		Parameter* param;
		
		param = new RangeParameter (USTRING("Master Volume"), kParamMasterVolume, USTRING("%"), 0, 100, 80);
		param->setPrecision (1);
		parameters.addParameter (param);

		param = new RangeParameter (USTRING("Master Tuning"), kParamMasterTuning, USTRING("cent"), -200, 200, 0);
		param->setPrecision (0);
		parameters.addParameter (param);

		param = new RangeParameter (USTRING("Velocity To Level"), kParamVelToLevel, USTRING("%"), 0, 100, 100);
		param->setPrecision (1);
		parameters.addParameter (param);

		param = new RangeParameter (USTRING("Release Time"), kParamReleaseTime, USTRING("sec"), 0.005, MAX_RELEASE_TIME_SEC, 0.025);
		param->setPrecision (3);
		parameters.addParameter (param);
		
		param = new RangeParameter (USTRING("Noise Volume"), kParamNoiseVolume, USTRING("%"), 0, 100, 0);
		param->setPrecision (1);
		parameters.addParameter (param);
		param = new RangeParameter (USTRING("Sinus Volume"), kParamSinusVolume, USTRING("%"), 0, 100, 80);
		param->setPrecision (1);
		parameters.addParameter (param);
		param = new RangeParameter (USTRING("Triangle Volume"), kParamTriangleVolume, USTRING("%"), 0, 100, 20);
		param->setPrecision (1);
		parameters.addParameter (param);
		param = new RangeParameter (USTRING("Square Volume"), kParamSquareVolume, USTRING("%"), 0, 100, 80);
		param->setPrecision (1);
		parameters.addParameter (param);
		
		param = new RangeParameter (USTRING("Sinus Detune"), kParamSinusDetune, USTRING("cent"), -200, 200, 0);
		param->setPrecision (0);
		parameters.addParameter (param);

		param = new RangeParameter (USTRING("Triangle Slop"), kParamTriangleSlop, USTRING("%"), 0, 100, 50);
		param->setPrecision (0);
		parameters.addParameter (param);
		
		StringListParameter* filterTypeParam = new StringListParameter (USTRING("Filter Type"), kParamFilterType);
		filterTypeParam->appendString (USTRING("Lowpass"));
		filterTypeParam->appendString (USTRING("Highpass"));
		filterTypeParam->appendString (USTRING("Bandpass"));
		parameters.addParameter (filterTypeParam);
		
		param = new LogScaleParameter<ParamValue> (USTRING("Filter Frequency"), kParamFilterFreq, VoiceStatics::freqLogScale);
		param->setPrecision (1);
		parameters.addParameter (param);

		param = new RangeParameter (USTRING("Frequency Mod Depth"), kParamFilterFreqModDepth, USTRING("%"), -100, 100, 100);
		param->setPrecision (1);
		parameters.addParameter (param);

		param = parameters.addParameter (USTRING("Filter Q"), 0, 0, 0, ParameterInfo::kCanAutomate, kParamFilterQ);
		param->setPrecision (2);

		parameters.addParameter (USTRING("Bypass SNA"), 0, 1, 0, ParameterInfo::kCanAutomate, kParamBypassSNA);

		parameters.addParameter (new RangeParameter (USTRING("Active Voices"), kParamActiveVoices, 0, 0, MAX_VOICES, 0, MAX_VOICES, ParameterInfo::kIsReadOnly));

		StringListParameter* tuningRangeParam = new StringListParameter (USTRING("Tuning Range"), kParamTuningRange, 0, ParameterInfo::kIsList);
		tuningRangeParam->appendString (USTRING("[-1, +1] Octave"));
		tuningRangeParam->appendString (USTRING("[-3, +2] Tunes"));
		parameters.addParameter (tuningRangeParam);

	// Init Note Expression Types
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kVolumeTypeID, String ("Volume"), String ("Vol"), 0, -1, 1., 0., 1., 0, 0));
		noteExpressionTypes.addNoteExpressionType (new PanNoteExpressionType ());
		NoteExpressionType* panNoteExpression = new RangeNoteExpressionType (kTuningTypeID, String ("Tuning"), String ("Tun"), String ("Half Tone"), -1, 0, 120, -120, NoteExpressionTypeInfo::kIsBipolar);
		panNoteExpression->getInfo ().valueDesc.minimum = 0.5 - VoiceStatics::kNormTuningOneOctave;
		panNoteExpression->getInfo ().valueDesc.maximum = 0.5 + VoiceStatics::kNormTuningOneOctave;
		noteExpressionTypes.addNoteExpressionType (panNoteExpression);
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kSinusVolumeTypeID, String ("Sinus Volume"), String ("Sin Vol"), String ("%"), -1, getParameterObject (kParamSinusVolume), NoteExpressionTypeInfo::kIsAbsolute));
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kSinusDetuneTypeID, String ("Sinus Detune"), String ("Sin Detune"), String ("Cent"), -1, getParameterObject (kParamSinusDetune), NoteExpressionTypeInfo::kIsAbsolute|NoteExpressionTypeInfo::kIsBipolar));
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kTriangleVolumeTypeID, String ("Triangle Volume"), String ("Tri Vol"), String ("%"), -1, getParameterObject (kParamTriangleVolume), NoteExpressionTypeInfo::kIsAbsolute));
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kSquareVolumeTypeID, String ("Square Volume"), String ("Square Vol"), String ("%"), -1, getParameterObject (kParamSquareVolume), NoteExpressionTypeInfo::kIsAbsolute));
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kNoiseVolumeTypeID, String ("Noise Volume"), String ("Noise Vol"), String ("%"), -1, getParameterObject (kParamNoiseVolume), NoteExpressionTypeInfo::kIsAbsolute));
		noteExpressionTypes.addNoteExpressionType (new RangeNoteExpressionType (kFilterFreqModTypeID, String ("Filter Frequency Modulation"), String ("Freq Mod"), 0, -1, 0, -100, 100, NoteExpressionTypeInfo::kIsBipolar, 0));
		noteExpressionTypes.addNoteExpressionType (new RangeNoteExpressionType (kFilterQModTypeID, String ("Filter Q Modulation"), String ("Q Mod"), 0, -1, 0, -100, 100, NoteExpressionTypeInfo::kIsBipolar, 0));
		noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kFilterTypeTypeID, String ("Filter Type"), String ("Flt Type"), 0, -1, getParameterObject (kParamFilterType), NoteExpressionTypeInfo::kIsBipolar));
		noteExpressionTypes.addNoteExpressionType (new ReleaseTimeModNoteExpressionType ());
	}
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::terminate ()
{
	noteExpressionTypes.removeAll ();
	return EditController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::setComponentState (IBStream* state)
{
	GlobalParameterState gps;
	tresult result = gps.setState (state);
	if (result == kResultTrue)
	{
		setParamNormalized (kParamMasterVolume, gps.masterVolume);
		setParamNormalized (kParamMasterTuning, (gps.masterTuning + 1) / 2.);
		setParamNormalized (kParamVelToLevel, gps.velToLevel);
		setParamNormalized (kParamFilterFreqModDepth, (gps.freqModDepth + 1) / 2.);

		setParamNormalized (kParamReleaseTime, gps.releaseTime);
		setParamNormalized (kParamNoiseVolume, gps.noiseVolume);
		setParamNormalized (kParamSinusVolume, gps.sinusVolume);
		setParamNormalized (kParamTriangleVolume, gps.triangleVolume);
		setParamNormalized (kParamSquareVolume, gps.squareVolume);

		setParamNormalized (kParamSinusDetune, (gps.sinusDetune + 1) / 2.);
		setParamNormalized (kParamTriangleSlop, gps.triangleSlop);
		
		setParamNormalized (kParamFilterType, plainParamToNormalized (kParamFilterType, gps.filterType));
		setParamNormalized (kParamFilterFreq, gps.filterFreq);
		setParamNormalized (kParamFilterQ, gps.filterQ);
	
		setParamNormalized (kParamBypassSNA, gps.bypassSNA);

		setParamNormalized (kParamTuningRange, plainParamToNormalized (kParamTuningRange, gps.tuningRange));

	}
	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API Controller::setParamNormalized (ParamID tag, ParamValue value)
{
	bool newRange = false;
	if (tag == kParamTuningRange && getParamNormalized (tag) != value)
	{
		newRange = true;
		NoteExpressionType* net = noteExpressionTypes.getNoteExpressionType (kTuningTypeID);
		if (value > 0)
		{
			noteExpressionTypes.addNoteExpressionType (new NoteExpressionType (kTriangleSlopeTypeID, String ("Triangle Slope"), String ("Tri Slope"), String ("%"), -1, getParameterObject (kParamTriangleSlop), NoteExpressionTypeInfo::kIsAbsolute));
			if (net)
			{
				net->getInfo ().valueDesc.minimum = 0.5 - 3 * VoiceStatics::kNormTuningOneTune;
				net->getInfo ().valueDesc.maximum = 0.5 + 2 * VoiceStatics::kNormTuningOneTune;
			}
		}
		else
		{
			noteExpressionTypes.removeNoteExpressionType (kTriangleSlopeTypeID);
			if (net)
			{
				net->getInfo ().valueDesc.minimum = 0.5 - VoiceStatics::kNormTuningOneOctave;
				net->getInfo ().valueDesc.maximum = 0.5 + VoiceStatics::kNormTuningOneOctave;
			}
		}
	}

	tresult res = EditController::setParamNormalized (tag, value);

	if (newRange && componentHandler)
		componentHandler->restartComponent (kNoteExpressionChanged);

	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::getMidiControllerAssignment (int32 busIndex, int16 channel, CtrlNumber midiControllerNumber, ParamID& id/*out*/)
{
	if (busIndex == 0 && channel == 0)
	{
		id = 0;
		switch (midiControllerNumber)
		{
			case kPitchBend: id = kParamMasterTuning; break;
			case kCtrlVolume: id = kParamMasterVolume; break;
			case kCtrlFilterCutoff: id = kParamFilterFreq; break;
			case kCtrlFilterResonance: id = kParamFilterQ; break;
		}
		return id != 0 ? kResultTrue : kResultFalse;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
int32 PLUGIN_API Controller::getNoteExpressionCount (int32 busIndex, int16 channel)
{
	if (busIndex == 0 && channel == 0)
	{
		return noteExpressionTypes.getNoteExpressionCount ();
	}
	return 0;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::getNoteExpressionInfo (int32 busIndex, int16 channel, int32 noteExpressionIndex, NoteExpressionTypeInfo& info /*out*/)
{
	if (busIndex == 0 && channel == 0)
	{
		return noteExpressionTypes.getNoteExpressionInfo (noteExpressionIndex, info);
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::getNoteExpressionStringByValue (int32 busIndex, int16 channel, NoteExpressionTypeID id, NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
{
	if (busIndex == 0 && channel == 0)
	{
		return noteExpressionTypes.getNoteExpressionStringByValue (id, valueNormalized, string);
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API Controller::getNoteExpressionValueByString (int32 busIndex, int16 channel, NoteExpressionTypeID id, const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
{
	if (busIndex == 0 && channel == 0)
	{
		return noteExpressionTypes.getNoteExpressionValueByString (id, string, valueNormalized);

	}
	return kResultFalse;
}

}}} // namespaces
