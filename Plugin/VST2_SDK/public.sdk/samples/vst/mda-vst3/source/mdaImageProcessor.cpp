/*
 *  mdaImageProcessor.cpp
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

#include "mdaImageProcessor.h"
#include "mdaImageController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID ImageProcessor::uid (0xE99952F1, 0x3CBD42DE, 0x98604990, 0xD4FB3212);

//-----------------------------------------------------------------------------
ImageProcessor::ImageProcessor ()
{
	setControllerClass (ImageController::uid);
	allocParameters (6);
}

//-----------------------------------------------------------------------------
ImageProcessor::~ImageProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ImageProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.6f; //mode
		params[1] = 0.75f; //width
		params[2] = 0.5f; //skew
		params[3] = 0.75f; //centre
		params[4] = 0.5f; //balance
		params[5] = 0.5f; //output

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ImageProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ImageProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void ImageProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d, ll=l2l, lr=l2r, rl=r2l, rr = r2r;	

	--in1;	
	--in2;	
	--out1;
	--out2;

	while (--sampleFrames >= 0)
	{
		a = *++in1; 
		b = *++in2;

		d = rr*b + lr*a; 
		c = ll*a + rl*b;

		*++out1 = c;	
		*++out2 = d;
	}
}

//-----------------------------------------------------------------------------
void ImageProcessor::recalculate ()
{
	float w, k, c, b, g;

	w = 4.f * params[1] - 2.f; //width
	k = 2.f * params[2];       //balance
	c = 4.f * params[3] - 2.f; //depth
	b = 2.f * params[4];       //pan
	g = (float)pow (10.0, 2.0 * params[5] - 1.0);

	switch (int (params[0]*3.9))
	{
		case 0: //SM->LR
			r2l =  g * c * (2.f - b);
			l2l =  g * w * (2.f - k);
			r2r =  g * c * b;
			l2r = -g * w * k;
			break;

		case 1: //MS->LR
			l2l =  g * c * (2.f - b);
			r2l =  g * w * (2.f - k);
			l2r =  g * c * b;
			r2r = -g * w * k;
			break;

		case 2: //LR->LR
			g *= 0.5f;
			l2l = g * (c * (2.f - b) + w * (2.f - k)); 
			r2l = g * (c * (2.f - b) - w * (2.f - k)); 
			l2r = g * (c * b - w * k); 
			r2r = g * (c * b + w * k);
			break;

		case 3: //LR->MS
			g *= 0.5f;
			l2l =  g * (2.f - b) * (2.f - k);
			r2l =  g * (2.f - b) * k;
			l2r = -g * b * (2.f - k); 
			r2r =  g * b * k;
			break;
	}
}

}}} // namespaces

