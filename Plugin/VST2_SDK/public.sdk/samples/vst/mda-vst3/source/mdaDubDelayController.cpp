/*
 *  mdaDubDelayController.cpp
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

#include "mdaDubDelayController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DubDelayController::uid (0x812A9763, 0xA27F4D74, 0x8A272139, 0x6F1D35BB);

//-----------------------------------------------------------------------------
DubDelayController::DubDelayController ()
{
}

//-----------------------------------------------------------------------------
DubDelayController::~DubDelayController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		parameters.addParameter (USTRING("Delay"), USTRING("ms"), 0, 0.3, ParameterInfo::kCanAutomate, kParam0);
		parameters.addParameter (new ScaledParameter (USTRING("Feedback"), USTRING("Sat<>Lim"), 0, 0.7, ParameterInfo::kCanAutomate, kParam1, -110, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Fb Tone"), USTRING("Lo <> Hi"), 0, 0.4, ParameterInfo::kCanAutomate, kParam2, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("LFO Dep."), USTRING("%"), 0, 0.0, ParameterInfo::kCanAutomate, kParam3, 0, 100, true));
		parameters.addParameter (USTRING("LFO Rate"), USTRING("sec."), 0, 0.5, ParameterInfo::kCanAutomate, kParam4);
		parameters.addParameter (new ScaledParameter (USTRING("FX Mix"), USTRING("%"), 0, 0.33, ParameterInfo::kCanAutomate, kParam5, 0, 100, true));
		parameters.addParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam6);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case kParam0:
		{
			result.printInt ((valueNormalized*valueNormalized*323766) * 1000. / sampleRate);
			break;
		}
		case kParam4:
		{
			result.printFloat (pow (10.0f, (float)(2.0f - 3.0f * valueNormalized)), 2);
			break;
		}
		case kParam6:
		{
			result.printFloat (20 * log10(2.0 * valueNormalized), 2);
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	return BaseController::getParamValueByString (tag, string, valueNormalized);
/*
	switch (tag)
	{
		default:
			return BaseController::getParamValueByString (tag, string, valueNormalized);
	}
	return kResultFalse;
*/
}

}}} // namespaces
