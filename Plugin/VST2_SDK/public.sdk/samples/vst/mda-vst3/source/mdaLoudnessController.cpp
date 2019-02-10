/*
 *  mdaLoudnessController.cpp
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

#include "mdaLoudnessController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID LoudnessController::uid (0x9184DDF5, 0x6A2B4C5B, 0xA51BF670, 0x2A8B1BB0);

//-----------------------------------------------------------------------------
LoudnessController::LoudnessController ()
{
}

//-----------------------------------------------------------------------------
LoudnessController::~LoudnessController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (USTRING("Loudness"), USTRING("dB"), 0, 0.15, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Output"), USTRING("dB"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		IndexedParameter* linkParam = new IndexedParameter (USTRING("Link"), USTRING(""), 1, 0.5, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		linkParam->setIndexString (0, UString128("Off"));
		linkParam->setIndexString (1, UString128("On"));
		parameters.addParameter (linkParam);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 0:
		case 1:
		{
			float tmp = valueNormalized + valueNormalized - 1.0f;
			float igain = 60.0f * tmp * tmp;
			if (tmp<0.0f) igain *= -1.0f;
			result.printFloat (igain);
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
