/*
 *  mdaSplitterController.cpp
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

#include "mdaSplitterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID SplitterController::uid (0xD3766521, 0x24EF4691, 0xAB7CD29D, 0xB855BF1F);

//-----------------------------------------------------------------------------
SplitterController::SplitterController ()
{
}

//-----------------------------------------------------------------------------
SplitterController::~SplitterController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		IndexedParameter* modeParam = new IndexedParameter (USTRING("Mode"), USTRING(""), 3, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		modeParam->setIndexString (0, UString128("NORMAL"));
		modeParam->setIndexString (1, UString128("INVERSE"));
		modeParam->setIndexString (2, UString128("NORM/INV"));
		modeParam->setIndexString (3, UString128("INV/NORM"));
		parameters.addParameter (modeParam);
		parameters.addParameter (USTRING("Freq"), USTRING("Hz"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		IndexedParameter* modeParam2 = new IndexedParameter (USTRING("Freq Mode"), USTRING(""), 2, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		modeParam2->setIndexString (0, UString128("BELOW"));
		modeParam2->setIndexString (1, UString128("ALL"));
		modeParam2->setIndexString (2, UString128("ABOVE"));
		parameters.addParameter (modeParam2);
		parameters.addParameter (new ScaledParameter (USTRING("Level"), USTRING("Hz"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, -40, 0));
		parameters.addParameter (USTRING("Level"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Envelope"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 1:
		{
			float fdisp = (float)pow (10.0f, (float)(2.0f + 2.0f * valueNormalized));
			result.printFloat (fdisp);
			break;
		}
		case 5:
		{
			result.printFloat (pow (10.0f, (float)(1.0f + 2.0f * valueNormalized)));
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
