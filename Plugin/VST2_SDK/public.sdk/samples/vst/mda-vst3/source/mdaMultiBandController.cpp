/*
 *  mdaMultiBandController.cpp
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

#include "mdaMultiBandController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID MultiBandController::uid (0x9C79B3F9, 0xD9C949CB, 0xA961571A, 0xFE118C95);

//-----------------------------------------------------------------------------
MultiBandController::MultiBandController ()
{
}

//-----------------------------------------------------------------------------
MultiBandController::~MultiBandController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		IndexedParameter* listenParam = new IndexedParameter (USTRING("Listen"), USTRING(""), 3, 0., ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		listenParam->setIndexString (0, UString128("Low"));
		listenParam->setIndexString (1, UString128("Mid"));
		listenParam->setIndexString (2, UString128("High"));
		listenParam->setIndexString (3, UString128("Output"));
		parameters.addParameter (listenParam);
		parameters.addParameter (USTRING("L <> M"), USTRING("Hz"), 0, 0.15, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("M <> H"), USTRING("Hz"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("L Comp"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 30, true));
		parameters.addParameter (new ScaledParameter (USTRING("M Comp"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 30, true));
		parameters.addParameter (new ScaledParameter (USTRING("H Comp"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 30, true));
		parameters.addParameter (new ScaledParameter (USTRING("L Out"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
		parameters.addParameter (new ScaledParameter (USTRING("M Out"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
		parameters.addParameter (new ScaledParameter (USTRING("H Out"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
		parameters.addParameter (USTRING("Attack"), UString128(kMicroSecondsString), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Release"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Stereo Width"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Stereo"), USTRING(""), 1, 0.5, ParameterInfo::kCanAutomate, pid++);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 1:
		{
			float fi1 = (float)pow (10.0,valueNormalized - 1.70);
			result.printInt (getSampleRate () * fi1 * (0.098 + 0.09*fi1 + 0.5*(float)pow (fi1,8.2f)));
			break;
		}
		case 2:
		{
			float fi2 = (float)pow (10.0,valueNormalized - 1.05);
			result.printInt (getSampleRate () * fi2 * (0.015 + 0.15*fi2 + 0.9*(float)pow (fi2,8.2f)));
			break;
		}
		case 9:
		{
			float att2 = (float)pow (10.0, -0.05 -(2.0 * valueNormalized));
			result.printInt (-301030.1 / (getSampleRate () * log10(1.0 - att2)));
			break;
		}
		case 10:
		{
			float rel2 = (float)pow (10.0, -2.0 - (3.0 * valueNormalized));
			result.printInt (-301.0301 / (getSampleRate () * log10(1.0 - rel2)));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
