/*
 *  mdaLimiterController.cpp
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

#include "mdaLimiterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID LimiterController::uid (0x886C856F, 0x7C164A28, 0x9AD212A9, 0x857386A0);

//-----------------------------------------------------------------------------
LimiterController::LimiterController ()
{
}

//-----------------------------------------------------------------------------
LimiterController::~LimiterController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (new ScaledParameter (USTRING("Thresh"), USTRING("dB"), 0, 0, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
		parameters.addParameter (USTRING("Release"), USTRING("ms"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Attack"), UString128(kMicroSecondsString), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		IndexedParameter* kneeParam = new IndexedParameter (USTRING("Knee"), 0, 1, 0, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		kneeParam->setIndexString (0, UString128("HARD"));
		kneeParam->setIndexString (1, UString128("SOFT"));
		parameters.addParameter (kneeParam);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 2:
		{
			float att = (float)pow (10.0, -2.0 * valueNormalized);
			result.printInt (-301030.1 / (getSampleRate () * log10(1.0 - att)));
			break;
		}
		case 3:
		{
			float rel = (float)pow (10.0, -2.0 - (3.0 * valueNormalized));
			result.printInt (-301.0301 / (getSampleRate () * log10(1.0 - rel)));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
