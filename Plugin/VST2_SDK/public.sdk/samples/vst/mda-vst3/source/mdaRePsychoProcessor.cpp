/*
 *  mdaRePsychoProcessor.cpp
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

#include "mdaRePsychoProcessor.h"
#include "mdaRePsychoController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID RePsychoProcessor::uid (0xC20CCF82, 0x90574B71, 0x98AE3FE1, 0x240C2704);

//-----------------------------------------------------------------------------
RePsychoProcessor::RePsychoProcessor ()
{
	setControllerClass (RePsychoController::uid);
	allocParameters (7);
}

//-----------------------------------------------------------------------------
RePsychoProcessor::~RePsychoProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RePsychoProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[3/**/] = (float)0.6; //thresh
		params[2/**/] = (float)0.5; //env
		params[0/**/] = (float)1.0; //tune
		params[5/**/] = (float)1.0; //mix
		params[4/**/] = (float)0.45; //minimum chunk length
		params[1/**/] = (float)1.0; //fine tune
		params[6/**/] = (float)1.; //quality
		size = 22050;
		buffer = new float[size];
		buffer2 = new float[size];

		buf = 0.0; buf2 = 0.0;
		tim = size + 1;
		fil = 0.0;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RePsychoProcessor::terminate ()
{
	if (buffer) delete [] buffer;
	if (buffer2) delete [] buffer2;
	buffer = buffer2 = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API RePsychoProcessor::setActive (TBool state)
{
	if (state)
	{
		memset (buffer, 0, size * sizeof (float));
		memset (buffer2, 0, size * sizeof (float));
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void RePsychoProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d;	
	float we=wet, dr = dry, tu=tun, en=env;
	float ga=gai, x = 0.0f, x2=0.0f, xx=buf, xx2=buf2;
	float it1, it2;
	int32 ti=tim, dti=dtim, of1, of2;

	--in1;	
	--in2;	
	--out1;
	--out2;

	if (params[6/**/]>0.5) //high quality
	{
		we= (float)(we*2.0);
		while (--sampleFrames >= 0)
		{
			a = *++in1;		
			b = *++in2; //process from here...

			if ((a+b > thr) && (ti > dti)) //trigger
			{
				ga = 1.0;
				ti = 0;
			}

			if (ti<22050) //play out
			{  
				if (ti<80) //fade in
				{
					if (ti==0) { xx=x; xx2=x2; }

					*(buffer + ti) = a;
					*(buffer2 + ti) = b;
					x = *(buffer + int (ti * tu));
					x2 = *(buffer2 + int (ti * tu));

					x = (float)(xx * (1.0 - (0.0125 * ti)) + (x * 0.0125 * ti)); 
					x2 = (float)(xx2 * (1.0 - (0.0125 * ti)) + (x2 * 0.0125 * ti)); 
				}
				else
				{
					//update to/from buffer
					*(buffer + ti) = a;
					*(buffer2 + ti) = b;

					it1 = (float)(ti * tu); //interpolation
					of1 = (int)it1; of2 = of1 + 1; it1 = it1 - of1; it2 = (float)(1.0 - it1);

					x = (it2* *(buffer + of1)) + (it1* *(buffer + of2));
					x2 = (it2* *(buffer2 + of1)) + (it1* *(buffer2 + of2));
				}

				ti++;
				ga*= en;
			}
			else //mute
			{
				ga = 0;
			}

			c = (a * dr) + (x * ga * we); // output
			d = (b * dr) + (x2 * ga * we);

			*++out1 = c;
			*++out2 = d;
		}
	}
	else
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1;		
			b = *++in2; //process from here...

			if ((a+b > thr) && (ti > dti)) //trigger
			{
				ga = 1.0;
				ti = 0;
			}

			if (ti<22050) //play out
			{  
				if (ti<80) //fade in
				{
					if (ti==0) xx = x;

					*(buffer + ti) = (a + b);
					x = *(buffer + int (ti * tu));

					x = (float)(xx * (1.0 - (0.0125 * ti)) + (x * 0.0125 * ti));
				}
				else
				{
					//update to/from buffer
					*(buffer + ti) = (a + b);
					x = *(buffer + int (ti * tu));
				}

				ti++;
				ga*= en;
			}
			else //mute
			{
				ga = 0;
			}

			c = (a * dr) + (x * ga * we); // output
			d = (b * dr) + (x * ga * we);

			*++out1 = c;
			*++out2 = d;
		}
	}
	tim = ti;
	gai = ga;
	buf = xx;
	buf2 = xx2;
}

//-----------------------------------------------------------------------------
void RePsychoProcessor::recalculate ()
{
	dtim = 441 + int (0.5 * size * params[4/**/]);
	thr = (float)pow (10.0,(1.5 * params[3/**/]) - 1.5);

	if (params[2/**/]>0.5) 
	{ env = (float)(1.0 + 0.003 * pow (params[2/**/] - 0.5,5.0)); }
	else
	{ env = (float)(1.0 + 0.025 * pow (params[2/**/] - 0.5,5.0)); }

	//if (params[2/**/]>0.5) 
	//{ env = (float)(1.0 + 0.01 * (params[2/**/] - 0.5)); }
	//else
	//{ env = (float)(1.0 + 0.01 * (params[2/**/] - 0.5)); }

	tun = (float)(((int (params[0/**/] * 24.0) - 24.0) + (params[1/**/] - 1.0)) / 24.0);
	tun = (float)pow (10.0, 0.60206 * tun);
	wet = (float)(0.5 * sqrt (params[5/**/]));
	dry = (float)sqrt (1.0 - params[5/**/]);
}

}}} // namespaces

