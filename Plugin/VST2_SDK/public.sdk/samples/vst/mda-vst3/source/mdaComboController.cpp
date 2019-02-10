/*
 *  mdaComboController.cpp
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

#include "mdaComboController.h"

#include "pluginterfaces/base/ibstream.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID ComboController::uid (0x2C9437A7, 0x1B4D4E35, 0x845E3159, 0xE72D7BC4);

//-----------------------------------------------------------------------------
ComboController::ComboController ()
{
}

//-----------------------------------------------------------------------------
ComboController::~ComboController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ComboController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* modelParam = new IndexedParameter (USTRING("Model"), 0, 6, 0.7, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam0);
		modelParam->setIndexString (0, UString128("D.I."));
		modelParam->setIndexString (1, UString128("Spkr Sim"));
		modelParam->setIndexString (2, UString128("Radio"));
		modelParam->setIndexString (3, UString128("MB 1\""));
		modelParam->setIndexString (4, UString128("MB 8\""));
		modelParam->setIndexString (5, UString128("4x12 ^"));
		modelParam->setIndexString (6, UString128("4x12 >"));
		parameters.addParameter (modelParam);
		parameters.addParameter (new ScaledParameter (USTRING("Drive"), USTRING("S <> H"), 0, 0.7, ParameterInfo::kCanAutomate, kParam1, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Bias"), 0, 0, 0.9, ParameterInfo::kCanAutomate, kParam2, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam3, -20, 20, true));
		IndexedParameter* modeParam = new IndexedParameter (USTRING("Process"), 0, 1, 0.5, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam4);
		modeParam->setIndexString (0, UString128("Stereo"));
		modeParam->setIndexString (1, UString128("Mono"));
		parameters.addParameter (modeParam);
		parameters.addParameter (new ScaledParameter (USTRING("HPF Freq"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, kParam5, 0, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("HPF Reso"), USTRING("%"), 0, 0.5, ParameterInfo::kCanAutomate, kParam6, 0, 100, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ComboController::terminate ()
{
	return BaseController::terminate ();
}

}}} // namespaces
