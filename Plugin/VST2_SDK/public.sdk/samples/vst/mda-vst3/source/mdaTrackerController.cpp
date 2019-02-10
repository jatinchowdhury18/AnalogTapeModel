/*
 *  mdaTrackerController.cpp
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

#include "mdaTrackerController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID TrackerController::uid (0xBBF731F0, 0x94A848F0, 0xAEE9C5F6, 0x5DA3D3BA);

//-----------------------------------------------------------------------------
TrackerController::TrackerController ()
{
}

//-----------------------------------------------------------------------------
TrackerController::~TrackerController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		IndexedParameter* modeParam = new IndexedParameter (USTRING("Mode"), USTRING(""), 4, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		modeParam->setIndexString (0, UString128("SINE"));
		modeParam->setIndexString (1, UString128("SQUARE"));
		modeParam->setIndexString (2, UString128("SAW"));
		modeParam->setIndexString (3, UString128("RING"));
		modeParam->setIndexString (4, UString128("EQ"));
		parameters.addParameter (modeParam);
		parameters.addParameter (new ScaledParameter (USTRING("Dynamics"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Mix"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Glide"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Trnspose"), USTRING("semi"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -36, 36, true));
		parameters.addParameter (new ScaledParameter (USTRING("Maximum"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Trigger"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -60, 0, true));
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	return BaseController::getParamStringByValue (tag, valueNormalized, string);

	/*
	UString128 result;
	 	switch (tag)
	 	{
			default:
				return BaseController::getParamStringByValue (tag, valueNormalized, string);
		}
		result.copyTo (string, 128);
		return kResultTrue;*/
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
