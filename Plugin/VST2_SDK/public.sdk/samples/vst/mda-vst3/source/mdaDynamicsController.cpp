/*
 *  mdaDynamicsController.cpp
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

#include "mdaDynamicsController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DynamicsController::uid (0xDB1EC488, 0x88364B93, 0xB66C365C, 0x904C6D62);

//-----------------------------------------------------------------------------
DynamicsController::DynamicsController ()
{
}

//-----------------------------------------------------------------------------
DynamicsController::~DynamicsController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		parameters.addParameter (new ScaledParameter (USTRING("Thresh"), USTRING("dB"), 0, 0.15, ParameterInfo::kCanAutomate, kParam0, -40, 0, true));
		parameters.addParameter (USTRING("Ratio"), USTRING(":1"), 0, 0.6, ParameterInfo::kCanAutomate, kParam1);
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2, 0, 40, true));
		parameters.addParameter (USTRING("Attack"), UString128(kMicroSecondsString), 0, 0.5, ParameterInfo::kCanAutomate, kParam3);
		parameters.addParameter (USTRING("Release"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, kParam4);
		parameters.addParameter (USTRING("Limiter"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam5);
		parameters.addParameter (USTRING("Gate Thr"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam6);
		parameters.addParameter (USTRING("Gate Att"), UString128(kMicroSecondsString), 0, 0.5, ParameterInfo::kCanAutomate, kParam7);
		parameters.addParameter (USTRING("Gate Rel"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, kParam8);
		parameters.addParameter (new ScaledParameter (USTRING("Mix"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, kParam9, 0, 100, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	return BaseController::getParamStringByValue (tag, valueNormalized, string);
	/*
	UString128 result;
		switch (tag)
		{
			#if 0 // TODO
			case kParam1:
			{
				break;
			}
			#endif
			default:
				return BaseController::getParamStringByValue (tag, valueNormalized, string);
		}
		result.copyTo (string, 128);
		return kResultTrue;*/
	
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
