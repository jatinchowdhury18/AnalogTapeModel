/*
 *  mdaTestToneController.cpp
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

#include "mdaTestToneController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID TestToneController::uid (0x2FE2D7CB, 0x074C4CF3, 0xAF3608D9, 0xCB3A8E7C);

//-----------------------------------------------------------------------------
TestToneController::TestToneController ()
{
}

//-----------------------------------------------------------------------------
TestToneController::~TestToneController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TestToneController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		IndexedParameter* modeParam = new IndexedParameter (USTRING("Mode"), USTRING(""), 7, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		modeParam->setIndexString (0, UString128("MIDI #"));
		modeParam->setIndexString (1, UString128("IMPULSE"));
		modeParam->setIndexString (2, UString128("WHITE"));
		modeParam->setIndexString (3, UString128("PINK"));
		modeParam->setIndexString (4, UString128("SINE"));
		modeParam->setIndexString (5, UString128("LOG SWP."));
		modeParam->setIndexString (6, UString128("LOG STEP"));
		modeParam->setIndexString (7, UString128("LIN SWP."));
		parameters.addParameter (modeParam);
		parameters.addParameter (new BaseParameter (USTRING("Level"), USTRING("dB"), 0, 0.6, ParameterInfo::kCanAutomate, pid++));
		IndexedParameter* channelParam = new IndexedParameter (USTRING("Channel"), USTRING("L <> R"), 2, 0.5, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		channelParam->setIndexString (0, UString128("LEFT"));
		channelParam->setIndexString (1, UString128("CENTER"));
		channelParam->setIndexString (2, UString128("RIGHT"));
		parameters.addParameter (channelParam);
		parameters.addParameter (new BaseParameter (USTRING("F1"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++));
		parameters.addParameter (new BaseParameter (USTRING("F2"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Thru"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++));
		parameters.addParameter (new ScaledParameter (USTRING("Sweep"), USTRING("ms"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -40, 0, true));
		parameters.addParameter (new BaseParameter (USTRING("0dB ="), USTRING("dBFS"), 0, 0.5, ParameterInfo::kCanAutomate, pid++));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TestToneController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TestToneController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	UString128 result;
	switch (tag)
	{
		case 6:
			if (valueNormalized == 0)
			{
				result.fromAscii ("OFF");
				break;
			}
		default:
			return BaseController::getParamStringByValue (tag, valueNormalized, string);
	}
	result.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TestToneController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
