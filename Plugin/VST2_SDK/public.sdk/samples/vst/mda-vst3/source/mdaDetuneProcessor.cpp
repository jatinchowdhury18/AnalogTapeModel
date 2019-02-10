/*
 *  mdaDetuneProcessor.cpp
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

#include "mdaDetuneProcessor.h"
#include "mdaDetuneController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

#define BUFMAX   4096

//-----------------------------------------------------------------------------
FUID DetuneProcessor::uid (0x4CCBED11, 0xE28346A6, 0xA91EC86C, 0x9E85EDF8);

//-----------------------------------------------------------------------------
DetuneProcessor::DetuneProcessor ()
{
	setControllerClass (DetuneController::uid);
	allocParameters (4);
	buf=win=0;
}

//-----------------------------------------------------------------------------
DetuneProcessor::~DetuneProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DetuneProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.40f;  //fine
		params[1] = 0.40f;  //mix
		params[2] = 0.50f;  //output
		params[3] = 0.50f;  //chunksize
		
		buf = new float[BUFMAX];
		win = new float[BUFMAX];
		buflen=0;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DetuneProcessor::terminate ()
{
	if (buf) delete [] buf;
	if (win) delete [] win;
	buf=win=0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DetuneProcessor::setActive (TBool state)
{
	if (state)
	{
		memset (buf, 0, BUFMAX * sizeof (float));
		pos0 = 0; pos1 = pos2 = 0.0f;
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DetuneProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d;
	float x, w=wet, y =dry, p1=pos1, p1f, d1=dpos1;
	float                  p2=pos2,      d2=dpos2;
	int32  p0=pos0, p1i, p2i;
	int32  l=buflen-1, lh=buflen>>1;
	float lf = (float)buflen;

	--in1;
	--in2;
	--out1;
	--out2;
	while (--sampleFrames >= 0)  //had to disable optimization /Og in MSVC++5!
	{
		a = *++in1;
		b = *++in2;

		c = y * a;
		d = y * b;

		--p0 &= l;     
		*(buf + p0) = w * (a + b);      //input

		p1 -= d1;
		if (p1<0.0f) p1 += lf;           //output
		p1i = (int32)p1;
		p1f = p1 - (float)p1i;
		a = *(buf + p1i);
		++p1i &= l;
		a += p1f * (*(buf + p1i) - a);  //linear interpolation

		p2i = (p1i + lh) & l;           //180-degree ouptut
		b = *(buf + p2i);
		++p2i &= l;
		b += p1f * (*(buf + p2i) - b);  //linear interpolation

		p2i = (p1i - p0) & l;           //crossfade
		x = *(win + p2i);
		//++p2i &= l;
		//x += p1f * (*(win + p2i) - x); //linear interpolation (doesn't do much)
		c += b + x * (a - b);

		p2 -= d2;  //repeat for downwards shift - can't see a more efficient way?
		if (p2<0.0f) p2 += lf;           //output
		p1i = (int32)p2;
		p1f = p2 - (float)p1i;
		a = *(buf + p1i);
		++p1i &= l;
		a += p1f * (*(buf + p1i) - a);  //linear interpolation

		p2i = (p1i + lh) & l;           //180-degree ouptut
		b = *(buf + p2i);
		++p2i &= l;
		b += p1f * (*(buf + p2i) - b);  //linear interpolation

		p2i = (p1i - p0) & l;           //crossfade
		x = *(win + p2i);
		//++p2i &= l;
		//x += p1f * (*(win + p2i) - x); //linear interpolation (doesn't do much)
		d += b + x * (a - b);

		*++out1 = c;
		*++out2 = d;
	}
	pos0=p0; pos1=p1; pos2=p2;
}

//-----------------------------------------------------------------------------
void DetuneProcessor::recalculate ()
{
	int32 tmp;

	semi = 3.0f * params[0] * params[0] * params[0];
	dpos2 = (float)pow (1.0594631f, semi);
	dpos1 = 1.0f / dpos2;

	wet = (float)pow (10.0f, (float)(2.0f * params[2] - 1.0f));
	dry = wet - wet * params[1] * params[1];
	wet = (wet + wet - wet * params[1]) * params[1];

	tmp = 1 << (8 + (int32)(4.9f * params[3]));

	if (tmp!=buflen) //recalculate crossfade window
	{
		buflen = tmp;
		bufres = 1000.0f * (float)buflen / getSampleRate ();

		int32 i; //hanning half-overlap-and-add
		double p=0.0, dp=6.28318530718/buflen;
		for(i = 0;i<buflen;i++) { win[i] = (float)(0.5 - 0.5 * cos(p)); p+=dp; }
	}
}

}}} // namespaces

