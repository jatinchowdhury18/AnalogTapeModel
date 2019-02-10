/*
 *  mdaLoudnessProcessor.cpp
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

#include "mdaLoudnessProcessor.h"
#include "mdaLoudnessController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

static
float loudness[14][3] = { {402.f,  0.0025f,  0.00f},  //-60dB
                          {334.f,  0.0121f,  0.00f},
                          {256.f,  0.0353f,  0.00f},
                          {192.f,  0.0900f,  0.00f},
                          {150.f,  0.2116f,  0.00f},
                          {150.f,  0.5185f,  0.00f},
                          { 1.0f,     0.0f,  0.00f},  //0dB
                          {33.7f,     5.5f,  1.00f},
                          {92.0f,     8.7f,  0.62f},
                          {63.7f,    18.4f,  0.44f},
                          {42.9f,    48.2f,  0.30f},
                          {37.6f,   116.2f,  0.18f},
                          {22.9f,   428.7f,  0.09f},  //+60dB
                          { 0.0f,     0.0f,  0.00f}  };

//-----------------------------------------------------------------------------
FUID LoudnessProcessor::uid (0xF2351D3C, 0xA6E94D47, 0x9E17EB3B, 0x6F30BA7C);

//-----------------------------------------------------------------------------
LoudnessProcessor::LoudnessProcessor ()
{
	setControllerClass (LoudnessController::uid);
	allocParameters (3);
}

//-----------------------------------------------------------------------------
LoudnessProcessor::~LoudnessProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.70f;  //loudness
		params[1] = 0.50f;  //output
		params[2] = 0.35f;  //link

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LoudnessProcessor::setActive (TBool state)
{
	if (state)
	{
		Z0 = Z1 = Z2 = Z3 = 0.0f;
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void LoudnessProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	if (data.inputs[0].silenceFlags & 3 && Z0 == 0 && Z1 == 0 && Z2 == 0 && Z3 == 0)	// don't process if input is silent
	{
		if (in1 != out1)
			memset (out1, 0, sampleFrames * sizeof (float));
		if (in2 != out2)
			memset (out2, 0, sampleFrames * sizeof (float));
		data.outputs[0].silenceFlags = 3;
		return;
	}

	data.outputs[0].silenceFlags = 0;
	
	float a, b, c, d;
	float z0=Z0, z1=Z1, z2=Z2, z3=Z3;
	float a0=A0, a1=A1, a2=A2, g=gain;

	--in1;
	--in2;
	--out1;
	--out2;

	if (mode==0) //cut
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1;
			b = *++in2;

			z0 += a0 * (a - z0 + 0.3f * z1);	a -= z0;
			z1 += a0 * (a - z1);				a -= z1;
												a -= z0 * a1;
			z2 += a0 * (b - z2 + 0.3f * z1);	b -= z2;
			z3 += a0 * (b - z3);				b -= z3;
												b -= z2 * a1;
												c = a * g;
												d = b * g;

			*++out1 = c;
			*++out2 = d;
		}
	}
	else //boost
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1;
			b = *++in2;

			z0 += a0 * (a  - z0);
			z1 += a0 * (z0 - z1);   a += a1 * (z1 - a2 * z0);

			z2 += a0 * (b  - z2);
			z3 += a0 * (z2 - z3);   b += a1 * (z3 - a2 * z2);

			c = g * a;
			d = g * b;

			*++out1 = c;
			*++out2 = d;
		}
	}
	if (fabs (z1) < 1.0e-10 || fabs (z1)>100.0f) { Z0 = Z1 = 0.0f; } else { Z0 = z0; Z1 = z1; } //catch denormals
	if (fabs (z3) < 1.0e-10 || fabs (z3)>100.0f) { Z2 = Z3 = 0.0f; } else { Z2 = z2; Z3 = z3; }
}

//-----------------------------------------------------------------------------
void LoudnessProcessor::recalculate ()
{
	float f, tmp;
	int32  i;

	tmp = params[0] + params[0] - 1.0f;
	igain = 60.0f * tmp * tmp;
	if (tmp<0.0f) igain *= -1.0f;

	tmp = params[1] + params[1] - 1.0f;
	ogain = 60.0f * tmp * tmp;
	if (tmp<0.0f) ogain *= -1.0f;

	f = 0.1f * igain + 6.0f;  //coefficient index + fractional part
	i = (int32)f;
	f -= (float)i;

	tmp = loudness[i][0];  A0 = tmp + f * (loudness[i + 1][0] - tmp);
	tmp = loudness[i][1];  A1 = tmp + f * (loudness[i + 1][1] - tmp);
	tmp = loudness[i][2];  A2 = tmp + f * (loudness[i + 1][2] - tmp);

	A0 = 1.0f - (float)exp (-6.283153f * A0 / getSampleRate ());

	if (igain>0) 
	{
		//if (mode==0) suspend();  //don't click when switching mode
		mode=1; 
	}
	else 
	{
		//if (mode==1) suspend();
		mode=0;
	}

	tmp = ogain;
	if (params[2]>0.5f)  //linked gain
	{
		tmp -= igain;  if (tmp>0.0f) tmp = 0.0f;  //limit max gain
	}
	gain = (float)pow (10.0f, 0.05f * tmp);
}

}}} // namespaces

