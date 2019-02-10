/*
 *  mdaMultiBandProcessor.cpp
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

#include "mdaMultiBandProcessor.h"
#include "mdaMultiBandController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID MultiBandProcessor::uid (0x97C53059, 0x47FC442C, 0x8A858B04, 0x30C3AFE7);

//-----------------------------------------------------------------------------
MultiBandProcessor::MultiBandProcessor ()
{
	setControllerClass (MultiBandController::uid);
	allocParameters (13);
}

//-----------------------------------------------------------------------------
MultiBandProcessor::~MultiBandProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 1.00; //Listen: L/M/H/out
		params[1] = 0.103; //xover1
		params[2] = 0.878; //xover2
		params[3] = 0.54; //L drive    (1)
		params[4] = 0.00; //M drive
		params[5] = 0.60; //H drive
		params[6] = 0.45; //L trim     (2)
		params[7] = 0.50; //M trim
		params[8] = 0.50; //H trim
		params[9] = 0.22; //attack    (3) 
		params[10] = 0.602; //release   (4)
		params[11] = 0.55; //width
		params[12] = 0.; //MS swap

		fb1 = fb2 = fb3 = 0.f;
		gain1 = gain2 = gain3 = 0.f;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API MultiBandProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void MultiBandProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d, l=fb3, m, h, s, sl=slev, tmp1, tmp2, tmp3;	
	float f1i=fi1, f1o=fo1, f2i=fi2, f2o=fo2, b1=fb1, b2=fb2;
	float g1=gain1, d1=driv1, t1=trim1, a1=att1, r1=1.f - rel1;
	float g2=gain2, d2=driv2, t2=trim2, a2=att2, r2=1.f - rel2;
	float g3=gain3, d3=driv3, t3=trim3, a3=att3, r3=1.f - rel3;
	int32 ms=mswap;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2; //process from here...

		b = (ms)? -b : b;

		s = (a - b) * sl; //keep stereo component for later
		a += b;
		b2 = (f2i * a) + (f2o * b2); //crossovers
		b1 = (f1i * b2) + (f1o * b1); 
		l = (f1i * b1) + (f1o * l);
		m=b2-l; h=a-b2;

		tmp1 = (l>0)? l : -l;  //l
		g1 = (tmp1>g1)? g1+a1*(tmp1 -g1) : g1*r1;
		tmp1 = 1.f / (1.f + d1 * g1); 

		tmp2 = (m > 0)? m : -m;
		g2 = (tmp2>g2)? g2+a2*(tmp2-g2) : g2*r2;
		tmp2 = 1.f / (1.f + d2 * g2); 

		tmp3 = (h>0)? h : -h;
		g3 = (tmp3>g3)? g3+a3*(tmp3-g3) : g3*r3;
		tmp3 = 1.f / (1.f + d3 * g3); 

		a = (l*tmp3*t1) + (m*tmp2*t2) + (h*tmp3*t3);
		c = a + s; // output
		d = (ms)? s - a : a - s;

		*++out1 = c;
		*++out2 = d;
	}
	gain1= (g1<1.0e-10)? 0.f : g1;
	gain2= (g2<1.0e-10)? 0.f : g2;
	gain3= (g3<1.0e-10)? 0.f : g3;  // gain1=g1; gain2=g2; gain3=g3; 
	if (fabs (b1) < 1.0e-10) { fb1=0.f; fb2=0.f; fb3=0.f; }
	else { fb1=b1;  fb2=b2;  fb3=l;   }
}

//-----------------------------------------------------------------------------
void MultiBandProcessor::recalculate ()
{
	//calcs here
	driv1 = (float)pow (10.0,(2.5 * params[3]) - 1.0);
	trim1 = (float)(0.5 + (4.0 - 2.0 * params[9]) * (params[3] * params[3] * params[3])); 
	trim1 = (float)(trim1 * pow (10.0, 2.0 * params[6] - 1.0));
	att1 = (float)pow (10.0, -0.05 -(2.5 * params[9]));
	rel1 = (float)pow (10.0, -2.0 - (3.5 * params[10]));

	driv2 = (float)pow (10.0,(2.5 * params[4]) - 1.0);
	trim2 = (float)(0.5 + (4.0 - 2.0 * params[9]) * (params[4] * params[4] * params[4])); 
	trim2 = (float)(trim2 * pow (10.0, 2.0 * params[7] - 1.0));
	att2 = (float)pow (10.0, -0.05 -(2.0 * params[9]));
	rel2 = (float)pow (10.0, -2.0 - (3.0 * params[10]));

	driv3 = (float)pow (10.0,(2.5 * params[5]) - 1.0);
	trim3 = (float)(0.5 + (4.0 - 2.0 * params[9]) * (params[5] * params[5] * params[5])); 
	trim3 = (float)(trim3 * pow (10.0, 2.0 * params[8] - 1.0));
	att3 = (float)pow (10.0, -0.05 -(1.5 * params[9]));
	rel3 = (float)pow (10.0, -2.0 - (2.5 * params[10]));

	int32 listen = std::min<int32> (3, params[0] * (4));
	switch (listen)
	{
		case 0: trim2=0.0; trim3=0.0; slev=0.0; break;
		case 1: trim1=0.0; trim3=0.0; slev=0.0; break;
		case 2: trim1=0.0; trim2=0.0; slev=0.0; break;
		default: slev=params[11]; break;
	}
	fi1 = (float)pow (10.0,params[1] - 1.70); fo1= (float)(1.0 - fi1);
	fi2 = (float)pow (10.0,params[2] - 1.05); fo2= (float)(1.0 - fi2);

	if (params[12]>0.5) mswap=1; else mswap=0;
}

}}} // namespaces

