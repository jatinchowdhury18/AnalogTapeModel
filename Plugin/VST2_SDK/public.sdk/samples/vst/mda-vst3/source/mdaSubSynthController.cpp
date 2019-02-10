/*
 *  mdaSubSynthController.cpp
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

#include "mdaSubSynthController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID SubSynthController::uid (0xB33B6220, 0xFC224015, 0xB76118AD, 0x4F34A0D8);

//-----------------------------------------------------------------------------
SubSynthController::SubSynthController ()
{
}

//-----------------------------------------------------------------------------
SubSynthController::~SubSynthController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		IndexedParameter* typeParam = new IndexedParameter (USTRING("Type"), USTRING(""), 3, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		typeParam->setIndexString (0, UString128("Distort"));
		typeParam->setIndexString (1, UString128("Divide"));
		typeParam->setIndexString (2, UString128("Invert"));
		typeParam->setIndexString (3, UString128("Key Osc."));
		parameters.addParameter (typeParam);
		parameters.addParameter (new ScaledParameter (USTRING("Level"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (USTRING("Tune"), USTRING("Hz"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Dry Mix"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Thresh"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -60, 0, true));
		parameters.addParameter (USTRING("Release"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 2:
		{
			result.printInt (0.0726 * getSampleRate () * pow (10.0,-2.5 + (1.5 * valueNormalized)));
			break;
		}
		case 5:
		{
			result.printInt (-301.03 / (getSampleRate () * log10((1.0 - pow (10.0, -2.0 - (3.0 * valueNormalized))))));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	switch (tag)
	{
		case 2:
		case 5:
			break;
		default:
			return BaseController::getParamValueByString (tag, string, valueNormalized);
	}
	return kResultFalse;
}

}}} // namespaces
