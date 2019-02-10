/*
 *  mdaRingModProcessor.cpp
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

#include "mdaRingModProcessor.h"
#include "mdaRingModController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID RingModProcessor::uid (0x935CB08D, 0xFE614CF5, 0xA3927AAA, 0x21B25D95);

//-----------------------------------------------------------------------------
RingModProcessor::RingModProcessor ()
{
	setControllerClass (RingModController::uid);
	allocParameters (4);
}

//-----------------------------------------------------------------------------
RingModProcessor::~RingModProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = (float)0.0625; //1kHz		
		params[1] = (float)0.0;
		params[2] = (float)0.0;

		fPhi = 0.0;			
		twoPi = (float)6.2831853;
		fprev = 0.f;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RingModProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void RingModProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d, g;	
	float p, dp, tp = twoPi, fb, fp, fp2;

	p = fPhi;
	dp = fdPhi;
	fb = ffb;
	fp = fprev;

	--in1;
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2;

		g = (float)sin(p);
		p = (float)fmod( p + dp, tp );

		fp = (fb * fp + a) * g;
		fp2 = (fb * fp + b) * g;

		c = fp;		
		d = fp2;

		*++out1 = c;	
		*++out2 = d;	
	}
	fPhi = p;
	fprev = fp;
}

//-----------------------------------------------------------------------------
void RingModProcessor::recalculate ()
{
	fdPhi = (float) (twoPi * 100.0 * (params[1] + (160.0 * params[0]))/ getSampleRate ());
	ffb = 0.95f * params[2];
}

}}} // namespaces

