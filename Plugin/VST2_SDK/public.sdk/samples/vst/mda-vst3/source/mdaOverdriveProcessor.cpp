/*
 *  mdaOverdriveProcessor.cpp
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

#include "mdaOverdriveProcessor.h"
#include "mdaOverdriveController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID OverdriveProcessor::uid (0x203C7009, 0x042A4AC2, 0xA515CFF1, 0xDF647E92);

//-----------------------------------------------------------------------------
OverdriveProcessor::OverdriveProcessor ()
{
	setControllerClass (OverdriveController::uid);
	allocParameters (3);
}

//-----------------------------------------------------------------------------
OverdriveProcessor::~OverdriveProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API OverdriveProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.0f; 		
		params[1] = 0.0f;
		params[2] = 0.5f;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API OverdriveProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API OverdriveProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void OverdriveProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d;
	float i=params[0], g=gain, aa, bb;
	float f=filt, fa=filt1, fb=filt2;

	--in1;	
	--in2;
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2;

		aa = (a > 0.0f)? (float)sqrt (a) : (float)-sqrt (-a); //overdrive
		bb = (b > 0.0f)? (float)sqrt (b) : (float)-sqrt (-b); 

		fa = fa + f * (i * (aa - a) + a - fa);                //filter 
		fb = fb + f * (i * (bb - b) + b - fb);   

		c = fa * g; 
		d = fb * g;

		*++out1 = c;	
		*++out2 = d;
	}
	if (fabs (fa) > 1.0e-10) filt1 = fa; else filt1 = 0.0f; //catch denormals
	if (fabs (fb) > 1.0e-10) filt2 = fb; else filt2 = 0.0f;
}

//-----------------------------------------------------------------------------
void OverdriveProcessor::recalculate ()
{
	filt = (float)pow (10.0, -1.6 * params[1]);
	gain = (float)pow (10.0f, (float)(2.0f * params[2] - 1.0f));
}

}}} // namespaces

