/*
 *  mdaSubSynthProcessor.cpp
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

#include "mdaSubSynthProcessor.h"
#include "mdaSubSynthController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID SubSynthProcessor::uid (0xA7CC7918, 0xA7D34EA3, 0xB51B6F2F, 0x9C0AF682);

//-----------------------------------------------------------------------------
SubSynthProcessor::SubSynthProcessor ()
{
	setControllerClass (SubSynthController::uid);
	allocParameters (6);
}

//-----------------------------------------------------------------------------
SubSynthProcessor::~SubSynthProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = (float)0.0; //type
		params[1] = (float)0.3; //level
		params[2] = (float)0.6; //tune
		params[3] = (float)1.0; //dry mix 
		params[4] = (float)0.6; //thresh
		params[5] = (float)0.65; //release
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SubSynthProcessor::setActive (TBool state)
{
	if (state)
	{
		phi = env = filt1 = filt2 = filt3 = filt4 = filti = filto = 0.0f;
		recalculate ();
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void SubSynthProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d;	
	float we, dr, fi, fo, f1, f2, f3, f4, sub, rl, th, dv, ph, phii, dph, os, en;

	dph = dphi;
	rl = rls;
	phii = phi;
	en = env;
	os = osc;
	th = thr;
	dv = dvd;
	ph = phs;
	we = wet;
	dr = dry;
	f1 = filt1;
	f2 = filt2;
	f3 = filt3;
	f4 = filt4;

	fi = filti;
	fo = filto;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2; //process from here...

		f1 = (fo * f1) + (fi * (a + b));
		f2 = (fo * f2) + (fi * f1);

		sub = f2;
		if (sub > th)
		{
			sub = 1.0;        
		}
		else
		{
			if (sub < -th)
			{
				sub = -1.0;
			}
			else
			{
				sub = 0.0;
			}
		}

		if ((sub * dv) < 0) //octave divider
		{
			dv = -dv; if (dv < 0.) ph = -ph;
		}

		if (typ == 1) //divide
		{
			sub = ph * sub;
		}
		if (typ == 2) //invert
		{
			sub = (float)(ph * f2 * 2.0);
		}
		if (typ == 3) //osc
		{
			if (f2 > th) {en = 1.0; } 
			else {en = en * rl;}
			sub = (float)(en * sin(phii));
			phii = (float)fmod( phii + dph, 6.283185f );
		}

		f3 = (fo * f3) + (fi * sub);
		f4 = (fo * f4) + (fi * f3);

		c = (a * dr) + (f4 * we); // output
		d = (b * dr) + (f4 * we);

		*++out1 = c;
		*++out2 = d;
	}
	if (fabs (f1) < 1.0e-10) filt1=0.f; else filt1=f1;
	if (fabs (f2) < 1.0e-10) filt2=0.f; else filt2=f2;
	if (fabs (f3) < 1.0e-10) filt3=0.f; else filt3=f3;
	if (fabs (f4) < 1.0e-10) filt4=0.f; else filt4=f4;
	dvd = dv;
	phs = ph;
	osc = os;
	phi = phii;
	env = en;
}

//-----------------------------------------------------------------------------
void SubSynthProcessor::recalculate ()
{
	dvd = 1.0;
	phs = 1.0;
	osc = 0.0; //oscillator phase
	typ = int (3.5 * params[0]);
	filti = (typ == 3)? 0.018f : (float)pow (10.0,-3.0 + (2.0 * params[2]));
	filto = 1.0f - filti;
	wet = params[1];
	dry = params[3];
	thr = (float)pow (10.0,-3.0 + (3.0 * params[4]));
	rls = (float)(1.0 - pow (10.0, -2.0 - (3.0 * params[5])));
	dphi = (float)(0.456159 * pow (10.0,-2.5 + (1.5 * params[2])));
}

}}} // namespaces

