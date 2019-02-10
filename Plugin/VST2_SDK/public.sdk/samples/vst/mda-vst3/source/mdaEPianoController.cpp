/*
 *  mdaEPianoController.cpp
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

#include "mdaEPianoController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID EPianoController::uid (0xDA4F8237, 0x290441D4, 0xAF96E580, 0xE22C01FF);

//-----------------------------------------------------------------------------
EPianoController::EPianoController ()
{
	addBypassParameter = false;
}

//-----------------------------------------------------------------------------
EPianoController::~EPianoController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API EPianoController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* presetParam = new IndexedParameter (USTRING("Factory Presets"), USTRING("%"), 4, 0.15, ParameterInfo::kIsProgramChange | ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kPresetParam);
		presetParam->setIndexString (0, UString128("Default"));
		presetParam->setIndexString (1, UString128("Bright"));
		presetParam->setIndexString (2, UString128("Mellow"));
		presetParam->setIndexString (3, UString128("Autopan"));
		presetParam->setIndexString (4, UString128("Tremolo"));
		parameters.addParameter (presetParam);

		ParamID pid = 0;
		parameters.addParameter (new ScaledParameter (USTRING("Envelope Decay"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Envelope Release"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Hardness"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -50, 50));
		parameters.addParameter (new ScaledParameter (USTRING("Treble Boost"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -50, 50));
		parameters.addParameter (USTRING("Modulation"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("LFO Rate"), USTRING("Hz"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Velocity Sense"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Stereo Width"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 200));
		parameters.addParameter (new ScaledParameter (USTRING("Polyphony"), USTRING("Voices"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 1, 32, true));
		parameters.addParameter (new ScaledParameter (USTRING("Fine Tuning"), USTRING("cents"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -50, 50));
		parameters.addParameter (USTRING("Random Tuning"), USTRING("cents"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Overdrive"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 100));

		midiCCParamID[kCtrlModWheel] = kModWheelParam;
		parameters.addParameter (USTRING("Mod Wheel"), USTRING(""), 0, 0, 0, kModWheelParam);

		midiCCParamID[kCtrlSustainOnOff] = kSustainParam;
		midiCCParamID[kCtrlSustenutoOnOff] = kSustainParam;
		parameters.addParameter (new IndexedParameter (USTRING("Sustain"), USTRING(""), 1, 0, 0, kSustainParam));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API EPianoController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API EPianoController::setParamNormalized (ParamID tag, ParamValue value)
{
	tresult res = BaseController::setParamNormalized (tag, value);
	if (res == kResultOk && tag == kPresetParam) // preset change
	{
		int32 program = (int32)parameters.getParameter (tag)->toPlain (value);
		for (int32 i = 0; i < 12; i++)
		{
			BaseController::setParamNormalized (i, EPianoProcessor::programParams[program][i]);
		}
		componentHandler->restartComponent (kParamValuesChanged);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API EPianoController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 4:
		{
			if (valueNormalized > 0.5)
			{
				result.printInt (200.0f * valueNormalized - 100.0f);
				result.append(USTRING(" Trem"));
			}
			else
			{
				result.printInt (100.0f - 200.0f * valueNormalized);
				result.append(USTRING(" Pan"));
			}
			break;
		}
		case 5:
		{
			result.printFloat (exp (6.22f * valueNormalized - 2.61f));
			break;
		}
		case 10:
		{
			result.printFloat (50 * valueNormalized * valueNormalized);
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API EPianoController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	switch (tag)
	{
		case 4:
		case 5:
		case 10:
			break;
		default:
			return BaseController::getParamValueByString (tag, string, valueNormalized);
	}
	return kResultFalse;
}

}}} // namespaces
