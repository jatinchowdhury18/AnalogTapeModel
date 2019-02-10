/*
 *  mdaBandistoProcessor.cpp
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

#include "mdaBandistoProcessor.h"
#include "mdaBandistoController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID BandistoProcessor::uid (0x79F1CDBB, 0x1F004396, 0x947E35BA, 0x22B4FA6D);

//-----------------------------------------------------------------------------
BandistoProcessor::BandistoProcessor ()
{
	setControllerClass (BandistoController::uid);
	allocParameters(10);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BandistoProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		//inits here!
		params[0] = (float)1.00; //Listen: L/M/H/out
		params[1] = (float)0.40; //xover1
		params[2] = (float)0.50; //xover2
		params[3] = (float)0.50; //L drive    (1)
		params[4] = (float)0.50; //M drive
		params[5] = (float)0.50; //H drive
		params[6] = (float)0.50; //L trim     (2)
		params[7] = (float)0.50; //M trim
		params[8] = (float)0.50; //H trim
		params[9] = (float)0.4; //transistor/valve

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
void BandistoProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];


	float a, b, c, d, g, l=fb3, m, h, s, sl=slev;	
	float f1i=fi1, f1o=fo1, f2i=fi2, f2o=fo2, b1=fb1, b2=fb2;
	float g1, d1=driv1, t1=trim1;
	float g2, d2=driv2, t2=trim2;
	float g3, d3=driv3, t3=trim3;
	int v=valve;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2; //process from here...
			
		s = (a - b) * sl; //keep stereo component for later
		a += (float)(b + 0.00002); //dope filter at low level
		b2 = (f2i * a) + (f2o * b2); //crossovers
		b1 = (f1i * b2) + (f1o * b1); 
		l = (f1i * b1) + (f1o * l);
		m=b2-l; h=a-b2;

		g = (l>0)? l : -l;
		g = (float)(1.0 / (1.0 + d1 * g) ); //distort
		g1=g;

		g = (m > 0)? m : -m;
		g = (float)(1.0 / (1.0 + d2 * g) );
		g2=g;

		g = (h>0)? h : -h;
		g = (float)(1.0 / (1.0 + d3 * g) );
		g3=g;

		if (v) { if (l>0)g1=1.0; if (m > 0)g2=1.0; if (h>0)g3=1.0; }

		a = (l*g1*t1) + (m*g2*t2) + (h*g3*t3);
			c = a + s; // output
			d = a - s;

		*++out1 = c;
		*++out2 = d;
	}
	fb1=b1; fb2=b2, fb3=l;

}

//-----------------------------------------------------------------------------
void BandistoProcessor::recalculate ()
{
	driv1 = (float)pow (10.0,(6.0 * params[3] * params[3]) - 1.0);
	driv2 = (float)pow (10.0,(6.0 * params[4] *params[4]) - 1.0);
	driv3 = (float)pow (10.0,(6.0 * params[5] *params[5]) - 1.0);

	valve = int (1.99 * params[9]);
	if (valve) 
	{
		trim1 = (float)(0.5); 
		trim2 = (float)(0.5); 
		trim3 = (float)(0.5); 
	}
	else
	{
		trim1 = 0.3f*(float)pow (10.0,(4.0 * pow ((float)(params[3]),3.f)));//(0.5 + 500.0 * pow (params[4,6.0)); 
		trim2 = 0.3f*(float)pow (10.0,(4.0 * pow ((float)(params[4]),3.f))); 
		trim3 = 0.3f*(float)pow (10.0,(4.0 * pow ((float)(params[5]),3.f))); 
	}
	trim1 = (float)(trim1 * pow (10.0, 2.0 * params[6] - 1.0));
	trim2 = (float)(trim2 * pow (10.0, 2.0 * params[7] - 1.0));
	trim3 = (float)(trim3 * pow (10.0, 2.0 * params[8] - 1.0));

	switch (int (params[0]*5.0))
	{
		case 0: trim2=0.0; trim3=0.0; slev=0.0; break;
		case 1: trim1=0.0; trim3=0.0; slev=0.0; break;
		case 2: trim1=0.0; trim2=0.0; slev=0.0; break;
		default: slev=0.5; break;
	}
	fi1 = (float)pow (10.0,params[1] - 1.70); fo1= (float)(1.0 - fi1);
	fi2 = (float)pow (10.0,params[2] - 1.05); fo2= (float)(1.0 - fi2);
}

}}} // namespaces
