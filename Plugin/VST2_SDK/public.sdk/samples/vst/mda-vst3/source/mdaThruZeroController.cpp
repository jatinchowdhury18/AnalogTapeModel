/*
 *  mdaThruZeroController.cpp
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

#include "mdaThruZeroController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID ThruZeroController::uid (0x4A552BC9, 0x3F484476, 0x87608F28, 0xE34736DE);

//-----------------------------------------------------------------------------
ThruZeroController::ThruZeroController ()
{
}

//-----------------------------------------------------------------------------
ThruZeroController::~ThruZeroController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (USTRING("Rate"), USTRING("sec"), 0, 0.15, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Depth"), USTRING("ms"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Mix"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("DepthMod"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Feedback"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 0:
		{
			if (valueNormalized < 0.01)
				result.fromAscii("-");
			else
				result.printFloat (pow (10.0f, (float)(2.0f - 3.0f * valueNormalized)));
			break;
		}
		case 1:
		{
			float dep = 2000.0f * valueNormalized * valueNormalized;
			result.printFloat (1000.f * dep / getSampleRate ());
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
