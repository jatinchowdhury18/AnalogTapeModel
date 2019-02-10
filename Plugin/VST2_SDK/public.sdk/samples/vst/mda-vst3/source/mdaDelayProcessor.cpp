/*
 *  mdaDelayProcessor.cpp
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

#include "mdaDelayProcessor.h"
#include "mdaDelayController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DelayProcessor::uid (0xE5041336, 0xE9434B28, 0xB7B01267, 0x95F0C32F);

//-----------------------------------------------------------------------------
DelayProcessor::DelayProcessor ()
: buffer(0)
{
	setControllerClass (DelayController::uid);
	allocParameters (7);
}

//-----------------------------------------------------------------------------
DelayProcessor::~DelayProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.50f; //left delay
		params[1] = 0.27f; //right ratio
		params[2] = 0.70f; //feedback
		params[3] = 0.50f; //tone
		params[4] = 0.33f; //wet mix
		params[5] = 0.50f; //output
		
		size = 32766;  //set max delay time at max sample rate
		buffer = new float[size + 2]; //spare just in case!
		ipos = 0;
		fil0 = 0.0f;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayProcessor::terminate ()
{
	if (buffer) delete [] buffer;
	buffer = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DelayProcessor::setActive (TBool state)
{
	if (state)
		memset (buffer, 0, size * sizeof (float));
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DelayProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, ol, or_, w=wet, y =dry, fb=fbk;
	float lx=lmix, hx=hmix, f=fil, f0=fil0, tmp;
	int32 i=ipos, l, r, s=size;

	l = (i + ldel) % (s + 1);
	r = (i + rdel) % (s + 1);

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;
		b = *++in2;

		ol = *(buffer + l); //delay outputs
		or_ = *(buffer + r);

		tmp = w * (a + b) + fb * (ol + or_); //mix input & feedback
		f0 = f * (f0 - tmp) + tmp;    //low-pass filter
		*(buffer + i) = lx * f0 + hx * tmp; //delay input

		i--; if (i<0) i=s;
		l--; if (l<0) l=s;
		r--; if (r<0) r=s;

		*++out1 = y * a + ol; //mix wet & dry
		*++out2 = y * b + or_; 
	}
	ipos = i;
	if (fabs (f0) < 1.0e-10) fil0=0.0f; else fil0=f0; //trap denormals
}

//-----------------------------------------------------------------------------
void DelayProcessor::recalculate ()
{
	float tmp;
	ldel = (int32)(size * params[0] * params[0]);
	if (ldel<4) ldel=4;

	switch (int (params[1] * 17.9f)) //fixed left/right ratios
	{
		case  17: tmp = 0.5000f; break;
		case  16: tmp = 0.6667f; break;
		case  15: tmp = 0.7500f; break;
		case  14: tmp = 0.8333f; break;
		case  13: tmp = 1.0000f; break;
		case  12: tmp = 1.2000f; break;
		case  11: tmp = 1.3333f; break;
		case  10: tmp = 1.5000f; break;
		case   9: tmp = 2.0000f; break;
		default: tmp = 4.0f * params[1]; break; //variable ratio
	}
	rdel = (int32)(size * params[0] * params[0] * tmp);
	if (rdel>size) rdel=size;
	if (rdel<4) rdel=4;

	fil = params[3];

	if (params[3]>0.5f)  //simultaneously change crossover frequency & high/low mix
	{
		fil = 0.5f * fil - 0.25f; 
		lmix = -2.0f * fil;
		hmix = 1.0f;
	}
	else 
	{ 
		hmix = 2.0f * fil; 
		lmix = 1.0f - hmix;
	}
	fil = (float)exp (-6.2831853f * pow (10.0f, 2.2f + 4.5f * fil) / getSampleRate ());

	fbk = 0.495f * params[2];
	wet = 1.0f - params[4];
	wet = params[5] * (1.0f - wet * wet); //-3dB at 50% mix
	dry = params[5] * 2.0f * (1.0f - params[4] * params[4]);
}

}}} // namespaces


