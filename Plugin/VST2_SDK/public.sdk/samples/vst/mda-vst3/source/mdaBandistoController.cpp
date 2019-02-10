/*
 *  mdaBandistoController.cpp
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

#include "mdaBandistoController.h"
#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID BandistoController::uid (0x302EA341, 0xB6AC46C6, 0xB54D65E5, 0x95E63FAB);

//-----------------------------------------------------------------------------
BandistoController::BandistoController ()
{
}

//-----------------------------------------------------------------------------
BandistoController::~BandistoController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BandistoController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* listenParam = new IndexedParameter (USTRING("Listen"), 0, 3, 0, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam0);
		listenParam->setIndexString (0, UString128("Low"));
		listenParam->setIndexString (1, UString128("Mid"));
		listenParam->setIndexString (2, UString128("High"));
		listenParam->setIndexString (3, UString128("Output"));
		parameters.addParameter (listenParam);

		parameters.addParameter (USTRING("L <> M"), USTRING("Hz"), 0, 0.4, ParameterInfo::kCanAutomate, kParam1);
		parameters.addParameter (USTRING("M <> H"), USTRING("Hz"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2);
		
		parameters.addParameter (new ScaledParameter (USTRING("L Dist"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam3, 0, 60));
		parameters.addParameter (new ScaledParameter (USTRING("M Dist"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam4, 0, 60));
		parameters.addParameter (new ScaledParameter (USTRING("H Dist"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam5, 0, 60));
		parameters.addParameter (new ScaledParameter (USTRING("L Out"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam6, -20, 20));
		parameters.addParameter (new ScaledParameter (USTRING("M Out"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam7, -20, 20));
		parameters.addParameter (new ScaledParameter (USTRING("H Out"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam8, -20, 20));
		
		IndexedParameter* modeParam = new IndexedParameter (USTRING("Mode"), 0, 1, 0., ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam9);
		modeParam->setIndexString (0, UString128("Bipolar"));
		modeParam->setIndexString (1, UString128("Unipolar"));
		parameters.addParameter (modeParam);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BandistoController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BandistoController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case kParam1:
		{
			double fi1 = pow (10.0,valueNormalized - 1.70);
			fi1 = sampleRate * fi1 * (0.098 + 0.09*fi1 + 0.5*pow (fi1,8.2));
			result.printFloat (fi1, 1);
			break;
		}
		case kParam2:
		{
			double fi1 = pow (10.0,valueNormalized - 1.05);
			fi1 = sampleRate * fi1 * (0.015 + 0.15*fi1 + 0.9*pow (fi1,8.2));
			result.printFloat (fi1, 1);
			break;
		}
		default:
			return EditController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BandistoController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	switch (tag)
	{
		case kParam1:
		{
			break;
		}
		case kParam2:
		{
			break;
		}
		default:
			return BaseController::getParamValueByString (tag, string, valueNormalized);
	}
	return kResultFalse;
}

}}} // namespaces
