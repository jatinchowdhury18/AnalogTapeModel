/*
 *  mdaDegradeController.cpp
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

#include "mdaDegradeController.h"

#include "mdaDegradeController.h"
#include "pluginterfaces/base/ibstream.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DegradeController::uid (0x2C3AC40E, 0xA7754992, 0x87FE2BD7, 0x77829B03);

//-----------------------------------------------------------------------------
DegradeController::DegradeController ()
{
}

//-----------------------------------------------------------------------------
DegradeController::~DegradeController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		parameters.addParameter (USTRING("Headroom"), USTRING("dB"), 0, 0.8, ParameterInfo::kCanAutomate, kParam0);
		parameters.addParameter (new ScaledParameter (USTRING("Quant"), USTRING("bits"), 0, 0.5, ParameterInfo::kCanAutomate, kParam1, 4, 16, true));
		parameters.addParameter (USTRING("Rate"), USTRING("S<>S&&H"), 0, 0.65, ParameterInfo::kCanAutomate, kParam2);
		parameters.addParameter (USTRING("PostFilt"), USTRING("Hz"), 0, 0.9, ParameterInfo::kCanAutomate, kParam3);
		parameters.addParameter (USTRING("Non-Lin"), USTRING("Odd<>Eve"), 0, 0.58, ParameterInfo::kCanAutomate, kParam4);
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam5, -20, 20, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case kParam0:
		{
			result.printInt (-30 * (1 - valueNormalized));
			break;
		}
		case kParam2:
		{
			float f;
			int tn;
			if (valueNormalized > 0.5)
			{ 
				f = valueNormalized - 0.5f;
			}
			else 
			{ 
				f = 0.5f - valueNormalized; 
			}

			tn = (int)exp (18.0f * f);
			result.printInt (sampleRate / tn);
			break;
		}
		case kParam3:
		{
			result.printInt (pow (10.0f, (float)(2.30104f + 2.f * valueNormalized)));
			break;
		}
		case kParam4:
		{
			result.printInt (200.0 * fabs (valueNormalized - 0.5));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
