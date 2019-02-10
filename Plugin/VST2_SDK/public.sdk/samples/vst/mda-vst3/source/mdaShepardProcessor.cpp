/*
 *  mdaShepardProcessor.cpp
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

#include "mdaShepardProcessor.h"
#include "mdaShepardController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID ShepardProcessor::uid (0xDA28F022, 0x6D3E4744, 0x88C9C4DA, 0xC690F337);

//-----------------------------------------------------------------------------
ShepardProcessor::ShepardProcessor ()
{
	setControllerClass (ShepardController::uid);
	allocParameters (3);
}

//-----------------------------------------------------------------------------
ShepardProcessor::~ShepardProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ShepardProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		double x, a, twopi=6.2831853;
		int i;

		//inits here!
		params[0] = 0.20f; //mode
		params[1] = 0.70f; //rate
		params[2] = 0.50f; //level

		max = 512;
		buf1 = new float[max]; 
		buf2 = new float[max]; 

		for(max = 0; max<511; max++)   
		{
			pos = (float)(twopi * max / 511.f); //generate wavetables
			x = 0.0;
			a=1.0;
			*(buf2 + max) = (float)sin(pos);
			for(i = 0; i<8; i++)
			{
				x+= a * sin(fmod((double)pos,twopi));
				a *= 0.5;
				pos *= 2.0;
			}
			*(buf1 + max) = (float)x;
		}
		*(buf1 + 511) = 0.f;
		*(buf2 + 511) = 0.f; //wrap end for interpolation
		pos=0.f; 
		rate=1.f; 

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ShepardProcessor::terminate ()
{
	if (buf1) delete [] buf1;
	if (buf2) delete [] buf2;
	buf1 = buf2 = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ShepardProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void ShepardProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b;
	float r = rate, dr = drate, o = out, p = pos, di;
	int32 x = max, m = mode, i1, i2;

	--in1;	
	--in2;	
	--out1;
	--out2;

	while (--sampleFrames >= 0)
	{
		a = *++in1 + *++in2;

		r *= dr; 
		if (r > 2.f) 
		{ 
			r *= 0.5f; 
			p *= 0.5f;
		}
		else if (r<1.f) 
		{
			r *= 2.f;
			p *= 2.f; if (p > x) p -= x;
		}

		p += r; 
		if (p > x) p -= x;

		i1 = int (p); //interpolate position
		i2 = i1 + 1;
		di = (float)i2 - p;

		b =         di  * ( *(buf1 + i1) + (r - 2.f) * *(buf2 + i1) );
		b += (1.f - di) * ( *(buf1 + i2) + (r - 2.f) * *(buf2 + i2) );
		b *= o / r;

		if (m > 0) if (m == 2) b += 0.5f * a; else b *= a; //ring mod or add

		*++out1 = b;
		*++out2 = b;
	}
	pos=p; rate=r;
}

//-----------------------------------------------------------------------------
void ShepardProcessor::recalculate ()
{
	mode = std::min<int32> (2, (int32)(params[0] * 3));
	drate = 1.f + 10.f * (float)pow (params[1]-0.5,3.0) / getSampleRate ();
	out = 0.4842f * (float)pow (10.0f, (float)(2.f * params[2] - 1.f));
}

}}} // namespaces

