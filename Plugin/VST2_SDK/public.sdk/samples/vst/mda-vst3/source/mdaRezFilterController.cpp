/*
 *  mdaRezFilterController.cpp
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

#include "mdaRezFilterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID RezFilterController::uid (0xEB05C9E8, 0xD99E4797, 0x83E6F33E, 0x90D9378B);

//-----------------------------------------------------------------------------
RezFilterController::RezFilterController ()
{
}

//-----------------------------------------------------------------------------
RezFilterController::~RezFilterController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (new ScaledParameter (USTRING("Freq"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Res"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
		parameters.addParameter (new ScaledParameter (USTRING("Env->VCF"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, -100, 100, true));
		parameters.addParameter (USTRING("Attack"), USTRING("ms"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Release"), USTRING("ms"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("LFO->VCF"), USTRING("S+H<>Sin"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, -100, 100, true));
		parameters.addParameter (USTRING("LFO Rate"), USTRING("Hz"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Trigger"), USTRING("dB"), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (new ScaledParameter (USTRING("Max Freq"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 4:
		{
			float att = (float)pow (10.0, -0.01 - 4.0 * valueNormalized);
			result.printFloat (-301.0301 / (getSampleRate () * log10(1.0 - att)), 2);
			break;
		}
		case 5:
		{
			float rel = 1.f - (float)pow (10.0, -2.00 - 4.0 * valueNormalized);
			result.printFloat (-301.0301 / (getSampleRate () * log10(rel)), 2);
			break;
		}
		case 7:
		{
			result.printFloat (pow (10.0f, (float)(4.f*valueNormalized - 2.f)), 2);
			break;
		}
		case 8:
		{
			float tthr = 0;
			if (valueNormalized<0.1f) tthr=0.f; else tthr = 3.f * valueNormalized * valueNormalized;
			if (tthr == 0)
				result.fromAscii("FREE RUN");
			else
				result.printFloat (20*log10 (0.5*tthr), 2);
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	// TODO
	switch (tag)
	{
		case 4:
		case 5:
		case 7:
		case 8:
			break;
		default:
			return BaseController::getParamValueByString (tag, string, valueNormalized);
	}
	return kResultFalse;
}

}}} // namespaces
