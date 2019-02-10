/*
 *  mdaImageController.cpp
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

#include "mdaImageController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID ImageController::uid (0x18E85131, 0x09CE429D, 0x83E6621D, 0x74EF40FD);

//-----------------------------------------------------------------------------
ImageController::ImageController ()
{
}

//-----------------------------------------------------------------------------
ImageController::~ImageController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ImageController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		IndexedParameter* modeParam = new IndexedParameter (USTRING("Mode"), USTRING(""), 3, 0.15, ParameterInfo::kCanAutomate | ParameterInfo::kIsList, kParam0);
		modeParam->setIndexString (0, UString128("SM->LR"));
		modeParam->setIndexString (1, UString128("MS->LR"));
		modeParam->setIndexString (2, UString128("LR->LR"));
		modeParam->setIndexString (3, UString128("LR->MS"));
		parameters.addParameter (modeParam);
		parameters.addParameter (new ScaledParameter (USTRING("S Width"), USTRING("%"), 0, 0.6, ParameterInfo::kCanAutomate, kParam1, -200, 200, true));
		parameters.addParameter (new ScaledParameter (USTRING("S Pan"), USTRING("L<->R"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("M Level"), USTRING("%"), 0, 0.15, ParameterInfo::kCanAutomate, kParam3, -200, 200, true));
		parameters.addParameter (new ScaledParameter (USTRING("M Pan"), USTRING("L<->R"), 0, 0.15, ParameterInfo::kCanAutomate, kParam4, -100, 100, true));
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.15, ParameterInfo::kCanAutomate, kParam5, -20, 20, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ImageController::terminate ()
{
	return BaseController::terminate ();
}

}}} // namespaces
