/*
 *  mdaTalkBoxController.cpp
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

#include "mdaTalkBoxController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID TalkBoxController::uid (0x64F420A3, 0xC25242A7, 0xAE8AAE63, 0xD0DC1C2D);

//-----------------------------------------------------------------------------
TalkBoxController::TalkBoxController ()
{
}

//-----------------------------------------------------------------------------
TalkBoxController::~TalkBoxController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TalkBoxController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (USTRING("Wet"), USTRING(""), 0, 0.15, ParameterInfo::kCanAutomate, pid++);
		parameters.addParameter (USTRING("Dry"), USTRING(""), 0, 0.6, ParameterInfo::kCanAutomate, pid++);
		IndexedParameter* carrierParam = new IndexedParameter (USTRING("Carrier"), USTRING(""), 1, 0.5, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, pid++);
		carrierParam->setIndexString (0, UString128("RIGHT"));
		carrierParam->setIndexString (1, UString128("LEFT"));
		parameters.addParameter (carrierParam);
		parameters.addParameter (USTRING("Quality"), USTRING(""), 0, 0.5, ParameterInfo::kCanAutomate, pid++);
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TalkBoxController::terminate ()
{
	return BaseController::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TalkBoxController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
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
tresult PLUGIN_API TalkBoxController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
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
