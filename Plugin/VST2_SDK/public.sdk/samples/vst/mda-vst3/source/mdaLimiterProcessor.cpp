/*
 *  mdaLimiterProcessor.cpp
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

#include "mdaLimiterProcessor.h"
#include "mdaLimiterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID LimiterProcessor::uid (0xE13C8DA0, 0x72DE4A97, 0xA0890C28, 0x0BDA61F8);

//-----------------------------------------------------------------------------
LimiterProcessor::LimiterProcessor ()
{
	setControllerClass (LimiterController::uid);
	allocParameters (5);
}

//-----------------------------------------------------------------------------
LimiterProcessor::~LimiterProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = (float)0.60; //thresh 		
		params[1] = (float)0.60; //trim
		params[2] = (float)0.15; //attack
		params[3] = (float)0.50; //release
		params[4] = (float)0.40; //knee

		gain = 1.0;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LimiterProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void LimiterProcessor::checkSilence (ProcessData& data)
{
}

//-----------------------------------------------------------------------------
void LimiterProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	if (gain > 0.9999f && data.inputs[0].silenceFlags & 3)	// don't process if input is silent
	{
		if (in1 != out1)
			memset (out1, 0, sampleFrames * sizeof (float));
		if (in2 != out2)
			memset (out2, 0, sampleFrames * sizeof (float));
		data.outputs[0].silenceFlags = 3;
		return;
	}

	data.outputs[0].silenceFlags = 0;

	float g, at, re, tr, th, lev, ol, or_;

	th = thresh;
	g = gain;
	at = att;
	re = rel;
	tr = trim;

	--in1;	
	--in2;	
	--out1;
	--out2;
	if (params[4]>0.5) //soft knee
	{
		while (--sampleFrames >= 0)
		{
			ol = *++in1;
			or_ = *++in2;

			lev = (float)(1.0 / (1.0 + th * fabs (ol + or_)));
			if (g>lev) { g=g-at*(g-lev); } else { g=g+re*(lev-g); }

			*++out1 = (ol * tr * g);	
			*++out2 = (or_ * tr * g);	
		}
	}
	else
	{
		while (--sampleFrames >= 0)
		{
			ol = *++in1;
			or_ = *++in2;

			lev = (float)(0.5 * g * fabs (ol + or_));

			if (lev > th)
			{
				g = g - (at * (lev - th));
			}
			else //below threshold
			{
				g = g + (float)(re * (1.0 - g));
			}

			*++out1 = (ol * tr * g);	
			*++out2 = (or_ * tr * g);	
		}
	}
	gain = g;

}

//-----------------------------------------------------------------------------
void LimiterProcessor::recalculate ()
{
	if (params[4]>0.5) //soft knee
	{
		thresh = (float)pow (10.0, 1.0 - (2.0 * params[0]));
	}
	else //hard knee
	{
		thresh = (float)pow (10.0, (2.0 * params[0]) - 2.0);
	}
	trim = (float)(pow (10.0, (2.0 * params[1]) - 1.0));
	att = (float)pow (10.0, -2.0 * params[2]);
	rel = (float)pow (10.0, -2.0 - (3.0 * params[3]));
}

}}} // namespaces

