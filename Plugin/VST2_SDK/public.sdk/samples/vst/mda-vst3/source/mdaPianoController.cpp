/*
 *  mdaPianoController.cpp
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

#include "mdaPianoController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID PianoController::uid (0xBAC8AA21, 0x216D4754, 0xA7639173, 0xE3BB5F7A);

//-----------------------------------------------------------------------------
PianoController::PianoController ()
{
	addBypassParameter = false;
}

//-----------------------------------------------------------------------------
PianoController::~PianoController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* presetParam = new IndexedParameter (USTRING("Factory Presets"), USTRING("%"), 4, 0.15, ParameterInfo::kIsProgramChange | ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kPresetParam);
		presetParam->setIndexString (0, UString128("mda Piano"));
		presetParam->setIndexString (1, UString128("Plain Piano"));
		presetParam->setIndexString (2, UString128("Compressed Piano"));
		presetParam->setIndexString (3, UString128("Dance Piano"));
		presetParam->setIndexString (4, UString128("Convert Piano"));
		presetParam->setIndexString (4, UString128("Dark Piano"));
		presetParam->setIndexString (4, UString128("School Piano"));
		presetParam->setIndexString (4, UString128("Broken Piano"));
		parameters.addParameter (presetParam);

		ParamID pid = 0;
		parameters.addParameter (new ScaledParameter (USTRING("Envelope Decay"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Envelope Release"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Hardness Offset"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Velocity to Hardness"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Muffling Filter"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Velocity to Muffling"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Velocity Sensitivity"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Stereo Width"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 200));
		parameters.addParameter (new ScaledParameter (USTRING("Polyphony"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 8, 32, true));
		parameters.addParameter (new ScaledParameter (USTRING("Fine Tuning"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Random Detunging"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Stretch Tuning"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -50, 50));

		midiCCParamID[kCtrlModWheel] = kModWheelParam;
		midiCCParamID[kCtrlSoftPedalOnOff] = kModWheelParam;
		parameters.addParameter (USTRING("Mod Wheel"), USTRING(""), 0, 0, 0, kModWheelParam);

		midiCCParamID[kCtrlSustainOnOff] = kSustainParam;
		midiCCParamID[kCtrlSustenutoOnOff] = kSustainParam;
		parameters.addParameter (new IndexedParameter (USTRING("Sustain"), USTRING(""), 1, 0, 0, kSustainParam));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoController::setParamNormalized (ParamID tag, ParamValue value)
{
	tresult res = BaseController::setParamNormalized (tag, value);
	if (res == kResultOk && tag == kPresetParam) // preset change
	{
		int32 program = parameters.getParameter (tag)->toPlain (value);
		for (int32 i = 0; i < PianoProcessor::NPARAMS; i++)
		{
			BaseController::setParamNormalized (i, PianoProcessor::programParams[program][i]);
		}
		componentHandler->restartComponent (kParamValuesChanged);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
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
tresult PLUGIN_API PianoController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
