/*
 *  mdaDegradeProcessor.cpp
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

#include "mdaDegradeProcessor.h"
#include "mdaDegradeController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DegradeProcessor::uid (0xD31333A7, 0xA34E4690, 0xA279A0B0, 0x6C91BB85);

//-----------------------------------------------------------------------------
DegradeProcessor::DegradeProcessor ()
{
	setControllerClass (DegradeController::uid);
	allocParameters (6);
}

//-----------------------------------------------------------------------------
DegradeProcessor::~DegradeProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.8; //clip
		params[1] = 0.50; //bits
		params[2] = 0.65; //rate
		params[3] = 0.9; //postfilt
		params[4] = 0.58; //non-lin
		params[5] = 0.5; //level

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DegradeProcessor::setActive (TBool state)
{
	if (state)
		buf0 = buf1 = buf2 = buf3 = buf4 = buf5 = buf6 = buf7 = buf8 = buf9 = 0.0f;

	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DegradeProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float b0=buf0, l=lin, l2=lin2;
	float cl=clp, i2=fi2, o2=fo2;
	float b1=buf1, b2=buf2, b3=buf3, b4=buf4, b5=buf5;
	float b6=buf6, b7=buf7, b8=buf8, b9=buf9;
	float gi=g1, go=g2, ga=g3, m = mode;  
	int n=tn, t=tcount;   

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		b0 = (*++in1 + *++in2) + m * b0;

		if (t==n)
		{
			t=0;
			b5 = (float)(go * int (b0 * gi));
			if (b5>0)
				{ b5= (float)pow (b5,l2); if (b5>cl) b5=cl;}
			else
				{ b5=-(float)pow (-b5,l); if (b5<-cl) b5=-cl; }
			b0=0;
		} 
		t=t+1;

		b1 = i2 * (b5 * ga) + o2 * b1;
		b2 =      b1 + o2 * b2;
		b3 =      b2 + o2 * b3;
		b4 =      b3 + o2 * b4;
		b6 = i2 * b4 + o2 * b6;
		b7 =      b6 + o2 * b7;
		b8 =      b7 + o2 * b8;
		b9 =      b8 + o2 * b9;

		*++out1 = b9;
		*++out2 = b9;
	}
	if (fabs (b1) < 1.0e-10) 
		{ buf1=0.f; buf2=0.f; buf3=0.f; buf4=0.f; buf6=0.f; buf7=0.f;
		buf8=0.f; buf9=0.f; buf0=0.f; buf5=0.f; }
	else 
		{ buf1=b1; buf2=b2; buf3=b3; buf4=b4; buf6=b6; buf7=b7; 
		buf8=b8, buf9=b9; buf0=b0; buf5=b5; tcount=t; }
}

//-----------------------------------------------------------------------------
float DegradeProcessor::filterFreq(float hz)
{
	float j, k, r=0.999f;

	j = r * r - 1;
	k = (float)(2.f - 2.f * r * r * cos(0.647f * hz / getSampleRate () ));
	return (float)((sqrt (k*k - 4.f*j*j) - k) / (2.f*j));
}

//-----------------------------------------------------------------------------
void DegradeProcessor::recalculate ()
{
	float f;
	if (params[2]>0.5) { f = (float)params[2] - 0.5f;  mode = 1.0f; }
	else { f = 0.5f - (float)params[2];  mode = 0.0f; }

	tn = (int)exp (18.0f * f);

	//tn = (int)(18.0 * params[3 - 8.0); mode=1.f; }
	//         else { tn = (int)(10.0 - 18.0 * params[3); mode=0.f; }
	tcount = 1;
	clp = (float)(pow (10.0,(-1.5 + 1.5 * params[0])) );
	fo2 = filterFreq((float)pow (10.0f, (float)(2.30104f + 2.f*params[3])));
	fi2 = (1.f-fo2); fi2=fi2*fi2; fi2=fi2*fi2;
	float _g1 = (float)(pow (2.0,2.0 + int (params[1]*12.0))); 
	g2 = (float)(1.0/(2.0 * _g1));
	if (params[2]>0.5) g1 = -_g1/(float)tn; else g1= -_g1; 
	g3 = (float)(pow (10.0,2.0*params[5] - 1.0));
	if (params[4]>0.5) { lin = (float)(pow (10.0,0.3 * (0.5 - params[4]))); lin2=lin; }
	else { lin = (float)pow (10.0,0.3 * (params[4] - 0.5)); lin2=1.0; }
}

}}} // namespaces

