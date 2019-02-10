/*
 *  mdaRezFilterProcessor.cpp
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

#include "mdaRezFilterProcessor.h"
#include "mdaRezFilterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID RezFilterProcessor::uid (0x86983C01, 0x8D684E3F, 0xBA2816C2, 0x03A1450D);

//-----------------------------------------------------------------------------
RezFilterProcessor::RezFilterProcessor ()
{
	setControllerClass (RezFilterController::uid);
	allocParameters (10);
}

//-----------------------------------------------------------------------------
RezFilterProcessor::~RezFilterProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.33f; //f
		params[1] = 0.70f; //q
		params[2] = 0.50f; //a
		params[3] = 0.85f; //fenv
		params[4] = 0.00f; //att
		params[5] = 0.50f; //rel
		params[6] = 0.70f; //lfo
		params[7] = 0.40f; //rate
		params[8] = 0.00f; //trigger
		params[9] = 0.75f; //max freq

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RezFilterProcessor::setActive (TBool state)
{
	if (state)
	{
		buf0=0.f; 
		buf1=0.f; 
		buf2=0.f;
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void RezFilterProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a;	
	float f, i, ff=fff, fe=fenv, q=fq, g=fg, e=env, tmp;
	float b0=buf0, b1=buf1, b2=buf2, at=att, re=rel, fm=fmax;
	float fl=flfo, dph=dphi, ph=phi, bl=bufl, th=tthr, e2=env2;
	int32 lm=lfomode, ta=tatt, tt=ttrig;

	--in1;	
	--in2;	
	--out1;
	--out2;

	if (th==0.f)
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1 + *++in2;

			i = (a>0)? a : -a; //envelope
			e = (i>e)?  e + at * (i - e) : e * re; 

			if (lm==0) bl = fl * (float)sin(ph); //lfo
			else if (ph>1.f) { bl = fl*(rand() % 2000 - 1000); ph=0.f; }
			ph += dph;

			f = ff + fe * e + bl; //freq
			if (f<0.f) i = 0.f; else i= (f>fm)? fm : f;
			//     o = 1.f - i; 

			//     tmp = g*a + q*(1.f + (1.f/o)) * (b0-b1);
			//     b0 = o * (b0 - tmp) + tmp; 
			//     b1 = o * (b1 - b0) + b0;

			tmp = q + q * (1.0f + i * (1.0f + 1.1f * i));
			//tmp = q + q/(1.0008 - i);
			b0 += i * (g * a - b0 + tmp * (b0 - b1));
			b1 += i * (b0 - b1);


			//    b2 = o * (b2 - b1) + b1; 

			*++out1 = b1;
			*++out2 = b1;
		}
	}
	else
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1 + *++in2;


			i = (a>0)? a : -a; //envelope
			e = (i>e)? i : e * re; 
			if (e>th) { if (tt==0) {ta=1; if (lm==1)ph=2.f; } tt=1; } else tt=0; 
			if (ta==1) { e2 += at*(1.f-e2); if (e2>0.999f)ta=0; } else e2*=re;

			if (lm==0) bl = fl * (float)sin(ph); //lfo
			else if (ph>1.f) { bl = fl*(rand() % 2000 - 1000); ph=0.f; }
			ph += dph;

			f = ff + fe * e + bl; //freq
			if (f<0.f) i = 0.f; else i= (f>fm)? fm : f;

			//    o = 1.f - i; 

			tmp = q + q * (1.0f + i * (1.0f + 1.1f * i));
			//tmp = q + q/(1.0008 - i);
			b0 += i * (g * a - b0 + tmp * (b0 - b1));
			b1 += i * (b0 - b1);


			//    tmp = g*a + q*(1.f + (1.f/o)) * (b0-b1);  //what about (q + q/f)*
			//    b0 = o * (b0 - tmp) + tmp;                // ^ what about div0 ?
			//    b1 = o * (b1 - b0) + b0;
			//    b2 = o * (b2 - b1) + b1; 


			*++out1 = b1;
			*++out2 = b1;
		}
	}
	if (fabs (b0) < 1.0e-10) { buf0=0.f; buf1=0.f; buf2=0.f; }
	else { buf0=b0; buf1=b1; buf2=b2; } 
	env=e; env2=e2; bufl=bl; tatt=ta; ttrig=tt;
	phi= (float)fmod(ph,6.2831853f);
}

//-----------------------------------------------------------------------------
void RezFilterProcessor::recalculate ()
{
	fff = 1.5f * params[0] * params[0] - 0.15f;
	fq = 0.99f * (float)pow ((float)(params[1]),0.3f); //was 0.99f * 
	fg = 0.5f * (float)pow (10.0f, (float)(2.f * params[2] - 1.f));

	fmax = 0.99f + 0.3f * params[1];
	if (fmax>(1.3f * params[9])) fmax=1.3f*params[9]; 
	//fmax = 1.0f;
	//fq *= 1.0f + 0.2f * params[9];

	fenv = 2.f*(0.5f - params[3])*(0.5f - params[3]); 
	fenv = (params[3]>0.5f)? fenv : -fenv;
	att = (float)pow (10.0, -0.01 - 4.0 * params[4]);
	rel = 1.f - (float)pow (10.0, -2.00 - 4.0 * params[5]);

	lfomode=0;
	flfo = 2.f * (params[6] - 0.5f)*(params[6] - 0.5f); 
	dphi = (float)(6.2832f * (float)pow (10.0f, (float)(3.f * params[7] - 1.5f)) / getSampleRate ());
	if (params[6]<0.5) { lfomode=1; dphi *= 0.15915f; flfo *= 0.001f; } //S&H

	if (params[8]<0.1f) tthr=0.f; else tthr = 3.f * params[8] * params[8];
}

}}} // namespaces

