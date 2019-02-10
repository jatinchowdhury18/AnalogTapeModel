/*
 *  mdaRingModController.cpp
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

#include "mdaRingModController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID RingModController::uid (0x3D03E713, 0xED334913, 0x8D47116B, 0x1B6045CB);

//-----------------------------------------------------------------------------
RingModController::RingModController ()
{
}

//-----------------------------------------------------------------------------
RingModController::~RingModController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (USTRING("Freq"), USTRING("Hz"), 0, 0.15, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Fine"), USTRING("Hz"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Feedback"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 0:
		{
			result.printInt (100. * floor(160. * valueNormalized));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	switch (tag)
	{
		case 0: break;
		default:
			return BaseController::getParamValueByString (tag, string, valueNormalized);
	}
	return kResultFalse;
}

}}} // namespaces
