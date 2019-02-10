/*
 *  mdaDelayController.cpp
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

#include "mdaDelayController.h"

#include "pluginterfaces/base/ibstream.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DelayController::uid (0xF9AB9778, 0xEF1943F2, 0x86F911A3, 0x50C7AACB);

//-----------------------------------------------------------------------------
DelayController::DelayController ()
{
}

//-----------------------------------------------------------------------------
DelayController::~DelayController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		parameters.addParameter (USTRING("L Delay"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, kParam0);
		parameters.addParameter (USTRING("R Delay"), USTRING("%"), 0, 0.27, ParameterInfo::kCanAutomate, kParam1);
		parameters.addParameter (new ScaledParameter (USTRING("Feedback"), USTRING("%"), 0, 0.7, ParameterInfo::kCanAutomate, kParam2, 0, 99, true));
		parameters.addParameter (new ScaledParameter (USTRING("Fb Tone"), USTRING("Lo <> Hi"), 0, 0.5, ParameterInfo::kCanAutomate, kParam3, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Fb Mix"), USTRING("%"), 0, 0.33, ParameterInfo::kCanAutomate, kParam4, 0, 100, true));
		parameters.addParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam5);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case kParam0:
		{
			int ldel = (int32)(32766 * valueNormalized * valueNormalized);
			if (ldel<4) ldel=4;
			result.printInt (ldel * 1000. / sampleRate);
			break;
		}
		case kParam1:
		{
			int ldel = (int32)(32766 * valueNormalized * valueNormalized);
			if (ldel<4) ldel=4;
			float tmp;
			switch (int (valueNormalized * 17.9f)) //fixed left/right ratios
			{
				case  17: tmp = 0.5000f; break;
				case  16: tmp = 0.6667f; break;
				case  15: tmp = 0.7500f; break;
				case  14: tmp = 0.8333f; break;
				case  13: tmp = 1.0000f; break;
				case  12: tmp = 1.2000f; break;
				case  11: tmp = 1.3333f; break;
				case  10: tmp = 1.5000f; break;
				case   9: tmp = 2.0000f; break;
				default: tmp = 4.0f * valueNormalized; break; //variable ratio
			}
			int rdel = (int32)(32766 * valueNormalized * valueNormalized * tmp);
			if (rdel>32766) rdel=32766;
			if (rdel<4) rdel=4;
			result.printInt (100 * rdel / ldel);
			break;
		}
		case kParam5:
		{
			if (valueNormalized == 0)
				result.fromAscii ("oo");
			else
				result.printFloat (20 * log10(2.0 * valueNormalized), 2);
			break;
		}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
