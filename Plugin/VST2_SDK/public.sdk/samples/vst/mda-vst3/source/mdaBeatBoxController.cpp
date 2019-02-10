/*
 *  mdaBeatBoxController.cpp
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

#include "mdaBeatBoxController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID BeatBoxController::uid (0x7A668F2F, 0x42834CCF, 0xA4856D36, 0x891466F7);

//-----------------------------------------------------------------------------
BeatBoxController::BeatBoxController ()
{
}

//-----------------------------------------------------------------------------
BeatBoxController::~BeatBoxController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BeatBoxController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		//--- Create Units-------------
		UnitInfo unitInfo;
		Unit* unit;

		// create a unit for the HiHat
		unitInfo.id = 1;
		unitInfo.parentUnitId = kRootUnitId;	// attached to the root unit
		Steinberg::UString (unitInfo.name, USTRINGSIZE (unitInfo.name)).assign (USTRING ("HiHat"));
		unitInfo.programListId = kNoProgramListId;

		unit = new Unit (unitInfo);
		addUnit (unit);

		// create a unit for the Kick
		unitInfo.id = 2;
		unitInfo.parentUnitId = kRootUnitId;	// attached to the root unit
		Steinberg::UString (unitInfo.name, USTRINGSIZE (unitInfo.name)).assign (USTRING ("Kick"));
		unitInfo.programListId = kNoProgramListId;

		unit = new Unit (unitInfo);
		addUnit (unit);

		// create a unit for the Snare
		unitInfo.id = 3;
		unitInfo.parentUnitId = kRootUnitId;	// attached to the root unit
		Steinberg::UString (unitInfo.name, USTRINGSIZE (unitInfo.name)).assign (USTRING ("Snare"));
		unitInfo.programListId = kNoProgramListId;

		unit = new Unit (unitInfo);
		addUnit (unit);

		Parameter* param;
		
		param = new ScaledParameter (USTRING("Hat Thr"), USTRING("dB"), 0, 0.3, ParameterInfo::kCanAutomate, kParam0, -20, 20);
		parameters.addParameter (param);
		param->setUnitID (1);
		param = parameters.addParameter (USTRING("Hat Rate"), USTRING("ms"), 0, 0.45, ParameterInfo::kCanAutomate, kParam1);
		param->setUnitID (1);
		param = parameters.addParameter (USTRING("Hat Mix"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2);
		param->setUnitID (1);

		param = new ScaledParameter (USTRING("Kik Thr"), USTRING("dB"), 0, 0.46, ParameterInfo::kCanAutomate, kParam3, -20, 20);
		parameters.addParameter (param);
		param->setUnitID (2);
		param = parameters.addParameter (USTRING("Kik Trig"), USTRING("Hz"), 0, 0.15, ParameterInfo::kCanAutomate, kParam4);
		param->setUnitID (2);
		param = parameters.addParameter (USTRING("Kik Mix"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam5);
		param->setUnitID (2);

		param = new ScaledParameter (USTRING("Snr Thr"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam6, -20, 20);
		parameters.addParameter (param);
		param->setUnitID (3);
		param = parameters.addParameter (USTRING("Snr Trig"), USTRING("Hz"), 0, 0.7, ParameterInfo::kCanAutomate, kParam7);
		param->setUnitID (3);
		param = parameters.addParameter (USTRING("Snr Mix"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam8);
		param->setUnitID (3);

		parameters.addParameter (new ScaledParameter (USTRING("Dynamics"), USTRING("%"), 0, 0., ParameterInfo::kCanAutomate, kParam9, 0, 100));
		IndexedParameter* recParam = new IndexedParameter (USTRING("Record"), 0, 4, 0., ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam10);
		recParam->setIndexString (0, UString128("-"));
		recParam->setIndexString (1, UString128("MONITOR"));
		recParam->setIndexString (2, UString128("-> HAT"));
		recParam->setIndexString (3, UString128("-> KIK"));
		recParam->setIndexString (4, UString128("-> SNR"));
		parameters.addParameter (recParam);
		parameters.addParameter (USTRING("Thru Mix"), USTRING("dB"), 0, 0., ParameterInfo::kCanAutomate, kParam11);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BeatBoxController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BeatBoxController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	return BaseController::getParamStringByValue (tag, valueNormalized, string);
	/*
	UString128 result;
		switch (tag)
		{
			// TODO
			default:
				return BaseController::getParamStringByValue (tag, valueNormalized, string);
		}
		result.copyTo (string, 128);
		return kResultTrue;*/
	
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BeatBoxController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	return BaseController::getParamValueByString (tag, string, valueNormalized);
}

}}} // namespaces
