/*
 *  mdaJX10Controller.cpp
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/14/08.
 *
 *  mda VST Plug-ins
 *
 *  Copyright (c) 2008 Paul Kellett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "mdaJX10Controller.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID JX10Controller::uid (0x91E8798D, 0xEDE644C9, 0xB9EB444B, 0x5F0A8AA7);

//-----------------------------------------------------------------------------
JX10Controller::JX10Controller ()
{
	addBypassParameter = false;
}

//-----------------------------------------------------------------------------
JX10Controller::~JX10Controller ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API JX10Controller::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* presetParam = new IndexedParameter (USTRING("Factory Presets"), USTRING("%"), JX10Processor::kNumPrograms-1, 0, ParameterInfo::kIsProgramChange | ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kPresetParam);
		parameters.addParameter (presetParam);

		ParamID pid = 0;
		parameters.addParameter (USTRING("OSC Mix"), USTRING(""), 0, 0.15, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("OSC Tune"), USTRING(""), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("OSC Fine"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);

		IndexedParameter* glideModeParam = new IndexedParameter (USTRING("Glide"), 0, 5, 0, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		glideModeParam->setIndexString (0, UString128("Poly"));
		glideModeParam->setIndexString (1, UString128("Poly-Legato"));
		glideModeParam->setIndexString (2, UString128("Poly-Glide"));
		glideModeParam->setIndexString (3, UString128("Mono"));
		glideModeParam->setIndexString (4, UString128("Mono-Legato"));
		glideModeParam->setIndexString (5, UString128("Mono-Glide"));
		parameters.addParameter (glideModeParam);

		parameters.addParameter (USTRING("Gld Rate"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Gld Bend"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Freq"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Reso"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Env"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF LFO"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Vel"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Att"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Dec"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Sus"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("VCF Rel"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("ENV Att"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("ENV Dec"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("ENV Sus"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("ENV Rel"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("LFO Rate"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Vibrato"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Noise"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Octave"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Tuning"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);

		midiCCParamID[kCtrlModWheel] = kModWheelParam;
		parameters.addParameter (USTRING("Mod Wheel"), USTRING(""), 0, 0, 0, kModWheelParam);
		midiCCParamID[kPitchBend] = kPitchBendParam;
		parameters.addParameter (USTRING("Pitch Bend"), USTRING(""), 0, 0, 0.5, kPitchBendParam);
		midiCCParamID[kCtrlBreath] = kBreathParam;
		midiCCParamID[kCtrlFilterResonance] = kBreathParam;
		parameters.addParameter (USTRING("Filter Mod+"), USTRING(""), 0, 0, 0.5, kBreathParam);
		midiCCParamID[3] = kCtrler3Param;
		parameters.addParameter (USTRING("Filter Mod-"), USTRING(""), 0, 0, 0.5, kCtrler3Param);
		midiCCParamID[kCtrlExpression] = kCtrler3Param;
		parameters.addParameter (USTRING("Filter Resonance"), USTRING(""), 0, 0, 0.5, kExpressionParam);
		midiCCParamID[kAfterTouch] = kAftertouchParam;
		parameters.addParameter (USTRING("Aftertouch"), USTRING(""), 0, 0, 0.5, kAftertouchParam);
	

		int32 i = 0;
		presetParam->setIndexString (i++, UString128("5th Sweep Pad"));
		presetParam->setIndexString (i++, UString128("Echo Pad [SA]"));
		presetParam->setIndexString (i++, UString128("Space Chimes [SA]"));
		presetParam->setIndexString (i++, UString128("Solid Backing"));
		presetParam->setIndexString (i++, UString128("Velocity Backing [SA]"));
		presetParam->setIndexString (i++, UString128("Rubber Backing [ZF]"));
		presetParam->setIndexString (i++, UString128("808 State Lead"));
		presetParam->setIndexString (i++, UString128("Mono Glide"));
		presetParam->setIndexString (i++, UString128("Detuned Techno Lead"));
		presetParam->setIndexString (i++, UString128("Hard Lead [SA]"));
		presetParam->setIndexString (i++, UString128("Bubble"));
		presetParam->setIndexString (i++, UString128("Monosynth"));
		presetParam->setIndexString (i++, UString128("Moogcury Lite"));
		presetParam->setIndexString (i++, UString128("Gangsta Whine"));
		presetParam->setIndexString (i++, UString128("Higher Synth [ZF]"));
		presetParam->setIndexString (i++, UString128("303 Saw Bass"));
		presetParam->setIndexString (i++, UString128("303 Square Bass"));
		presetParam->setIndexString (i++, UString128("Analog Bass"));
		presetParam->setIndexString (i++, UString128("Analog Bass 2"));
		presetParam->setIndexString (i++, UString128("Low Pulses"));
		presetParam->setIndexString (i++, UString128("Sine Infra-Bass"));
		presetParam->setIndexString (i++, UString128("Wobble Bass [SA]"));
		presetParam->setIndexString (i++, UString128("Squelch Bass"));
		presetParam->setIndexString (i++, UString128("Rubber Bass [ZF]"));
		presetParam->setIndexString (i++, UString128("Soft Pick Bass"));
		presetParam->setIndexString (i++, UString128("Fretless Bass"));
		presetParam->setIndexString (i++, UString128("Whistler"));
		presetParam->setIndexString (i++, UString128("Very Soft Pad"));
		presetParam->setIndexString (i++, UString128("Pizzicato"));
		presetParam->setIndexString (i++, UString128("Synth Strings"));
		presetParam->setIndexString (i++, UString128("Synth Strings 2"));
		presetParam->setIndexString (i++, UString128("Leslie Organ"));
		presetParam->setIndexString (i++, UString128("Click Organ"));
		presetParam->setIndexString (i++, UString128("Hard Organ"));
		presetParam->setIndexString (i++, UString128("Bass Clarinet"));
		presetParam->setIndexString (i++, UString128("Trumpet"));
		presetParam->setIndexString (i++, UString128("Soft Horn"));
		presetParam->setIndexString (i++, UString128("Brass Section"));
		presetParam->setIndexString (i++, UString128("Synth Brass"));
		presetParam->setIndexString (i++, UString128("Detuned Syn Brass [ZF]"));
		presetParam->setIndexString (i++, UString128("Power PWM"));
		presetParam->setIndexString (i++, UString128("Water Velocity [SA]"));
		presetParam->setIndexString (i++, UString128("Ghost [SA]"));
		presetParam->setIndexString (i++, UString128("Soft E.Piano"));
		presetParam->setIndexString (i++, UString128("Thumb Piano"));
		presetParam->setIndexString (i++, UString128("Steel Drums [ZF]"));
		presetParam->setIndexString (i++, UString128("Car Horn"));
		presetParam->setIndexString (i++, UString128("Helicopter"));
		presetParam->setIndexString (i++, UString128("Arctic Wind"));
		presetParam->setIndexString (i++, UString128("Thip"));
		presetParam->setIndexString (i++, UString128("Synth Tom"));
		presetParam->setIndexString (i++, UString128("Squelchy Frog"));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API JX10Controller::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API JX10Controller::setParamNormalized (ParamID tag, ParamValue value)
{
	tresult res = BaseController::setParamNormalized (tag, value);
	if (res == kResultOk && tag == kPresetParam) // preset change
	{
		int32 program = parameters.getParameter (tag)->toPlain (value);
		for (int32 i = 0; i < 24; i++)
		{
			BaseController::setParamNormalized (i, JX10Processor::programParams[program][i]);
		}
		componentHandler->restartComponent (kParamValuesChanged);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API JX10Controller::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	return BaseController::getParamStringByValue (tag, valueNormalized, string);
	/*
	UString128 result;
		switch (tag)
		{
			default:
				return BaseController::getParamStringByValue (tag, valueNormalized, string);
		}
		result.copyTo (string, 128);
		return kResultTrue;*/
	
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API JX10Controller::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	return BaseController::getParamValueByString (tag, string, valueNormalized);
	/*
	switch (tag)
		{
			default:
				return BaseController::getParamValueByString (tag, string, valueNormalized);
		}
		return kResultFalse;*/
	
}

}}} // namespaces
