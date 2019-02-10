/*
 *  mdaRoundPanProcessor.cpp
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

#include "mdaRoundPanProcessor.h"
#include "mdaRoundPanController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID RoundPanProcessor::uid (0x2BEB5541, 0xE9384235, 0x8AAAE0AE, 0xB555BF75);

//-----------------------------------------------------------------------------
RoundPanProcessor::RoundPanProcessor ()
{
	setControllerClass (RoundPanController::uid);
	allocParameters (2);
}

//-----------------------------------------------------------------------------
RoundPanProcessor::~RoundPanProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RoundPanProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = (float)0.5; //pan
		params[1] = (float)0.8; //auto

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RoundPanProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RoundPanProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void RoundPanProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, c, d, x = 0.5, y = (float)0.7854;	
	float ph, dph, fourpi= (float)12.566371;

	ph = phi;
	dph = dphi;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = x * (*++in1 + *++in2); //process from here...

		c = (float)(a * -sin((x * ph) - y)); // output
		d = (float)(a * sin((x * ph) + y));

		ph = ph + dph;

		*++out1 = c;
		*++out2 = d;
	}
	if (ph<0.0) ph = ph + fourpi; else if (ph>fourpi) ph = ph - fourpi;
	phi = ph;
}

//-----------------------------------------------------------------------------
void RoundPanProcessor::recalculate ()
{
	phi = (float)(6.2831853 * (params[0] - 0.5));
	if (params[1]>0.55)
	{
		dphi = (float)(20.0 * (params[1] - 0.55) / getSampleRate ());
	}
	else
	{
		if (params[1]<0.45)
		{
			dphi = (float)(-20.0 * (0.45 - params[1]) / getSampleRate ());
		}
		else
		{
			dphi = 0.0;
		}
	}
}

}}} // namespaces

