/*
 *  mdaDeEsserController.cpp
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

#include "mdaDeEsserController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DeEsserController::uid (0x370BA963, 0xE2D54BF8, 0x8D6838FA, 0x1567C8DD);

//-----------------------------------------------------------------------------
DeEsserController::DeEsserController ()
{
}

//-----------------------------------------------------------------------------
DeEsserController::~DeEsserController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DeEsserController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		parameters.addParameter (new ScaledParameter (USTRING("Thresh"), USTRING("dB"), 0, 0.15, ParameterInfo::kCanAutomate, kParam0, -60, 60, true));
		parameters.addParameter (new ScaledParameter (USTRING("Freq"), USTRING("Hz"), 0, 0.6, ParameterInfo::kCanAutomate, kParam1, 1000, 11100, true));
		parameters.addParameter (new ScaledParameter (USTRING("HF Drive"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, kParam2, -20, 20, true));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DeEsserController::terminate ()
{
	return BaseController::terminate ();
}

}}} // namespaces
