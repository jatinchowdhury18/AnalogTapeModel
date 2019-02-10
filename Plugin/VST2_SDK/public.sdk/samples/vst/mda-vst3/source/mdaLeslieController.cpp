/*
 *  mdaLeslieController.cpp
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

#include "mdaLeslieController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID LeslieController::uid (0x3AC7BB1E, 0xE8C74788, 0x8D29C9BF, 0x9D9A51F8);

//-----------------------------------------------------------------------------
LeslieController::LeslieController ()
{
}

//-----------------------------------------------------------------------------
LeslieController::~LeslieController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* speedParam = new IndexedParameter (USTRING("Speed"), USTRING(""), 2, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam0);
		speedParam->setIndexString (0, UString128("STOP"));
		speedParam->setIndexString (1, UString128("SLOW"));
		speedParam->setIndexString (2, UString128("FAST"));
		parameters.addParameter (speedParam);
		parameters.addParameter (new ScaledParameter (USTRING("Lo Width"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, kParam1, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Lo Throb"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Hi Width"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, kParam3, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Hi Depth"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, kParam4, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Hi Throb"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, kParam5, 0, 100, true));
		parameters.addParameter (USTRING("X-Over"), USTRING("Hz"), 0, 0.15, ParameterInfo::kCanAutomate, kParam6);
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.15, ParameterInfo::kCanAutomate, kParam7, -20, 20, true));
		parameters.addParameter (new ScaledParameter (USTRING("Speed"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, kParam8, 0, 200, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case kParam6:
		{
			result.printInt (10*int ((float)pow (10.0f,(float)(1.179f + valueNormalized))));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
