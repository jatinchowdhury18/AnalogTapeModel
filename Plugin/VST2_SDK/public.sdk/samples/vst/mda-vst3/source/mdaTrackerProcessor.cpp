/*
 *  mdaTrackerProcessor.cpp
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

#include "mdaTrackerProcessor.h"
#include "mdaTrackerController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID TrackerProcessor::uid (0x61EA12BB, 0xC25447EA, 0xABD8D344, 0xB21B8B40);

//-----------------------------------------------------------------------------
TrackerProcessor::TrackerProcessor ()
{
	setControllerClass (TrackerController::uid);
	allocParameters (8);
}

//-----------------------------------------------------------------------------
TrackerProcessor::~TrackerProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = (float)0.00; //Mode
		params[1] = (float)1.00; //Dynamics
		params[2] = (float)1.00; //Mix
		params[3] = (float)0.97; //Tracking
		params[4] = (float)0.50; //Trnspose
		params[5] = (float)0.80; //Maximum Hz
		params[6] = (float)0.50; //Trigger dB
		params[7] = (float)0.50; //Output

		res1 = (float)cos(0.01); //p
		res2 = (float)sin(0.01); //q

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TrackerProcessor::setActive (TBool state)
{
	if (state)
	{
		dphi = 100.f/getSampleRate (); //initial pitch
		min = (int32)(getSampleRate ()/30.0); //lower limit
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void TrackerProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, x, t=thr, p = phi, dp=dphi, ddp=ddphi, tmp, tmp2;
	float o=fo, i=fi, b1=buf1, b2=buf2, twopi=6.2831853f;
	float we=wet, dr = dry, bo=bold, r1=res1, r2=res2, b3=buf3, b4=buf4;
	float sw=saw, dsw=dsaw, dy =dyn, e=env, re=rel;
	int32  m = max, n=num, s=sig, mn=min, mo=mode;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;
		b = *++in2;
		x = a;// + b;

		tmp = (x>0.f)? x : -x; //dynamics envelope
		e = (tmp>e)? 0.5f*(tmp + e) : e * re;

		b1 = o*b1 + i*x; 
		b2 = o*b2 + b1; //low-pass filter

		if (b2>t) //if >thresh
		{  
			if (s<1) //and was <thresh
			{
				if (n<mn) //not long ago
				{
					tmp2 = b2 / (b2 - bo); //update period
					tmp = trans*twopi/(n + dn - tmp2); 
					dp = dp + ddp * (tmp - dp); 
					dn = tmp2;
					dsw = 0.3183098f * dp;
					if (mode==4) 
					{
						r1 = (float)cos(4.f*dp); //resonator
						r2 = (float)sin(4.f*dp);
					}  
				}
				n=0; //restart period measurement
			}
			s=1;
		}
		else 
		{
			if (n>m) s=0; //now <thresh 
		}
		n++;
		bo=b2;

		p = (float)fmod(p+dp,twopi);
		switch (mo)
		{ //sine
			case 0: x= (float)sin(p); break; 
					//square
			case 1: x= (sin(p)>0.f)? 0.5f : -0.5f; break; 
					//saw
			case 2: sw = (float)fmod(sw+dsw,2.0f); x = sw - 1.f; break; 
					//ring
			case 3: x *= (float)sin(p); break; 
					//filt
			case 4: x += (b3 * r1) - (b4 * r2); 
					b4 = 0.996f * ((b3 * r2) + (b4 * r1)); 
					b3 = 0.996f * x; break; 
		}    
		x *= (we + dy * e); 
		*++out1 = a;//dr*a + x;
		*++out2 = dr*b + x;
	}
	if (fabs (b1) < 1.0e-10) {buf1=0.f; buf2=0.f; buf3=0.f; buf4=0.f; } 
	else {buf1=b1; buf2=b2; buf3=b3; buf4=b4;}
	phi=p; dphi=dp; sig=s; bold=bo;
	num= (n>100000)? 100000: n; 
	env=e; saw=sw; dsaw=dsw; res1=r1; res2=r2;
}

//-----------------------------------------------------------------------------
float TrackerProcessor::filterFreq(float hz)
{
	float j, k, r=0.999f;

	j = r * r - 1;
	k = (float)(2.f - 2.f * r * r * cos(0.647f * hz / getSampleRate () ));
	return (float)((sqrt (k*k - 4.f*j*j) - k) / (2.f*j));
}

//-----------------------------------------------------------------------------
void TrackerProcessor::recalculate ()
{
	mode = std::min<int32> (4, (int32)(params[0]*5));
	fo = filterFreq(50.f); fi = (1.f - fo)*(1.f - fo);
	ddphi = params[3] * params[3];
	thr = (float)pow (10.0, 3.0*params[6] - 3.8);
	max = (int32)(getSampleRate () / pow (10.0f, (float)(1.6f + 2.2f * params[5])));
	trans = (float)pow (1.0594631,int (72.f*params[4] - 36.f));
	wet = (float)pow (10.0, 2.0*params[7] - 1.0);
	if (mode<4)
	{
		dyn = wet * 0.6f * params[2] * params[1];
		dry = wet * (float)sqrt (1.f - params[2]);
		wet = wet * 0.3f * params[2] * (1.f - params[1]);
	}
	else
	{
		dry = wet * (1.f - params[2]);
		wet *= (0.02f*params[2] - 0.004f);
		dyn = 0.f;
	}
	rel = (float)pow (10.0,-10.0/getSampleRate ());
}

}}} // namespaces

