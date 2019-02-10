/*
 *  dmaDitherController.cpp
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

#include "mdaDitherController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DitherController::uid (0xE54A7007, 0x068149B4, 0xAEAF955C, 0x54760DBF);

//-----------------------------------------------------------------------------
DitherController::DitherController ()
{
}

//-----------------------------------------------------------------------------
DitherController::~DitherController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		parameters.addParameter (USTRING("Word Len"), USTRING("Bits"), 0, 0.15, ParameterInfo::kCanAutomate, kParam0);

		IndexedParameter* ditherParam = new IndexedParameter (USTRING("Dither"), USTRING(""), 3, 0.3, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam1);
		ditherParam->setIndexString (0, UString128("OFF"));
		ditherParam->setIndexString (1, UString128("TRI"));
		ditherParam->setIndexString (2, UString128("HP-TRI"));
		ditherParam->setIndexString (3, UString128("N.SHAPE"));
		parameters.addParameter (ditherParam);
		parameters.addParameter (new ScaledParameter (USTRING("Dith Amp"), USTRING("lsb"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2, 0, 4));
		parameters.addParameter (new ScaledParameter (USTRING("DC Trim"), USTRING("lsb"), 0, 0.5, ParameterInfo::kCanAutomate, kParam3, -2, 2));
		parameters.addParameter (new ScaledParameter (USTRING("Zoom"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam4, -2, 2));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case kParam0:
		{
			result.printInt (8.0f + 2.0f * (float)floor(8.9f * valueNormalized));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
