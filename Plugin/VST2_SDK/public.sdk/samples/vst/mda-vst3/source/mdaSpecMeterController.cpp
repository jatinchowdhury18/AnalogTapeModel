/*
 *  mdaSpecMeterController.cpp
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

#include "mdaSpecMeterController.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID SpecMeterController::uid (0xA47D4D56, 0x58AE42CD, 0x8EA0714B, 0x39CD3FC0);

//-----------------------------------------------------------------------------
SpecMeterController::SpecMeterController ()
{
}

//-----------------------------------------------------------------------------
SpecMeterController::~SpecMeterController ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SpecMeterController::initialize (FUnknown* context)
{
	tresult res = BaseController::initialize (context);
	if (res == kResultTrue)
	{
		ParamID pid = kBandParamStart;
		parameters.addParameter (new BaseParameter (USTRING("Left Band 1"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 2"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 3"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 4"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 5"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 6"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 7"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 8"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 9"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 10"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 11"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 12"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left Band 13"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));

		parameters.addParameter (new BaseParameter (USTRING("Right Band 1"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 2"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 3"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 4"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 5"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 6"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 7"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 8"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 9"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 10"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 11"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 12"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right Band 13"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));

		pid = kLeftPeakParam;
		parameters.addParameter (new ScaledParameter (USTRING("Left Peak"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++, 0, 2));
		parameters.addParameter (new ScaledParameter (USTRING("Left Hold"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++, 0, 2));
		parameters.addParameter (new BaseParameter (USTRING("Left Min"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Left RMS"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));

		parameters.addParameter (new ScaledParameter (USTRING("Right Peak"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++, 0, 2));
		parameters.addParameter (new ScaledParameter (USTRING("Right Hold"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++, 0, 2));
		parameters.addParameter (new BaseParameter (USTRING("Right Min"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
		parameters.addParameter (new BaseParameter (USTRING("Right RMS"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));

		parameters.addParameter (new BaseParameter (USTRING("Correlation"), 0, 0, 0, ParameterInfo::kIsReadOnly, pid++));
	}
	return res;
}

}}} // namespaces
