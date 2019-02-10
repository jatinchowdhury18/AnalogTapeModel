/*
 *  mdaAmbienceController.cpp
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/13/08.
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

#include "mdaAmbienceController.h"
#include "pluginterfaces/base/ibstream.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID AmbienceController::uid (0x0D9DD331, 0xCCF044FF, 0xB7DCB8B9, 0xDF977096);

//-----------------------------------------------------------------------------
AmbienceController::AmbienceController ()
{
}

//-----------------------------------------------------------------------------
AmbienceController::~AmbienceController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API AmbienceController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = 0;
		parameters.addParameter (new ScaledParameter (USTRING("Size"), USTRING("m"), 0, 0.7, ParameterInfo::kCanAutomate, pid++, 0, 10));
		parameters.addParameter (new ScaledParameter (USTRING("HF Damp"), USTRING("%"), 0, 0.7, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Mix"), USTRING("%"), 0, 0.9, ParameterInfo::kCanAutomate, pid++, 0, 100));
		parameters.addParameter (new ScaledParameter (USTRING("Output"), USTRING("dB"), 0, 0.5, ParameterInfo::kCanAutomate, pid++, -20, 20));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API AmbienceController::terminate ()
{
	return BaseController::terminate ();
}

}}} // namespaces
