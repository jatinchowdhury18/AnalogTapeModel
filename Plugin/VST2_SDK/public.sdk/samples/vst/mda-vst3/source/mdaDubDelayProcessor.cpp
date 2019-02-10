/*
 *  mdaDubDelayProcessor.cpp
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

#include "mdaDubDelayProcessor.h"

#include "mdaDubDelayController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DubDelayProcessor::uid (0xA49D1232, 0x24794649, 0xA57337B4, 0xDDC5041C);

//-----------------------------------------------------------------------------
DubDelayProcessor::DubDelayProcessor ()
{
	setControllerClass (DubDelayController::uid);
	allocParameters (7);
}

//-----------------------------------------------------------------------------
DubDelayProcessor::~DubDelayProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.30f; //delay
		params[1] = 0.70f; //feedback
		params[2] = 0.40f; //tone
		params[3] = 0.00f; //lfo depth
		params[4] = 0.50f; //lfo speed
		params[5] = 0.33f; //wet mix
		params[6] = 0.50f; //output
		///CHANGED///too long?
		size = 323766; //705600; //95998; //32766;  //set max delay time at max sample rate
		buffer = new float[size + 2]; //spare just in case!
		memset (buffer, 0, sizeof (float) * (size + 2));

		ipos = 0;
		fil0 = 0.0f;
		env  = 0.0f;
		phi  = 0.0f;
		dlbuf= 0.0f;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayProcessor::terminate ()
{
	if (buffer) delete [] buffer;
	buffer = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DubDelayProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DubDelayProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, ol, w=wet, y =dry, fb=fbk, dl=dlbuf, db=dlbuf, ddl=0.0f;
	float lx=lmix, hx=hmix, f=fil, f0=fil0, tmp;
	float e=env, g, r = rel; //limiter envelope, gain, release
	float twopi=6.2831853f;
	int32  i=ipos, l, s=size, k=0;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;
		b = *++in2;

		if (k==0) //update delay length at slower rate (could be improved!)
		{
			db += 0.01f * (del - db - mod - mod * (float)sin(phi)); //smoothed delay+lfo
			ddl = 0.01f * (db - dl); //linear step
			phi+=dphi; if (phi>twopi) phi-=twopi;
			k=100;
		}
		k--;
		dl += ddl; //lin interp between points

		i--; if (i<0) i=s;                         //delay positions

		l = (int32)dl;
		tmp = dl - (float)l; //remainder
		l += i; if (l>s) l-= (s+1);

		ol = *(buffer + l);                       //delay output

		l++; if (l>s) l=0; 
		ol += tmp * (*(buffer + l) - ol); //lin interp

		tmp = a + fb * ol;                        //mix input (left only!) & feedback

		f0 = f * (f0 - tmp) + tmp;                //low-pass filter
		tmp = lx * f0 + hx * tmp;

		g = (tmp<0.0f)? -tmp : tmp;                //simple limiter
		e *= r; if (g>e) e = g;
		if (e>1.0f) tmp /= e;

		*(buffer + i) = tmp;                      //delay input

		ol *= w;                                  //wet

		*++out1 = y * a + ol;                     //dry
		*++out2 = y * b + ol; 
	}
	ipos = i;
	dlbuf=dl;
	if (fabs (f0) < 1.0e-10) { fil0=0.0f; env=0.0f; } else { fil0=f0; env=e; } //trap denormals
}

//-----------------------------------------------------------------------------
void DubDelayProcessor::recalculate ()
{
	float fs=(float)getSampleRate ();
	///CHANGED///del = fParam0 * fParam0 * fParam0 * (float)size;
	del = params[0] * params[0] * (float)size;
	mod = 0.049f * params[3] * del;

	fil = params[2];
	if (params[2]>0.5f)  //simultaneously change crossover frequency & high/low mix
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
	fil = (float)exp (-6.2831853f * pow (10.0f, 2.2f + 4.5f * fil) / fs);

	fbk = (float)fabs (2.2f * params[1] - 1.1f);
	if (params[1]>0.5f) rel=0.9997f; else rel=0.8f; //limit or clip

	wet = 1.0f - params[5];
	wet = params[6] * (1.0f - wet * wet); //-3dB at 50% mix
	dry = params[6] * 2.0f * (1.0f - params[5] * params[5]);

	dphi = 628.31853f * (float)pow (10.0f, (float)(3.0f * params[4] - 2.0f)) / fs; //100-sample steps
}

}}} // namespaces

