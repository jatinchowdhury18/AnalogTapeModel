/*
 *  mdaSplitterProcessor.cpp
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

#include "mdaSplitterProcessor.h"
#include "mdaSplitterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID SplitterProcessor::uid (0xEB4D7879, 0x67114968, 0xB8E865FB, 0xFC508DB9);

//-----------------------------------------------------------------------------
SplitterProcessor::SplitterProcessor ()
{
	setControllerClass (SplitterController::uid);
	allocParameters (7);
}

//-----------------------------------------------------------------------------
SplitterProcessor::~SplitterProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.10f;  //mode
		params[1] = 0.50f;  //freq
		params[2] = 0.25f;  //freq mode
		params[3] = 0.50f;  //level (was 2)
		params[4] = 0.50f;  //level mode
		params[5] = 0.50f;  //envelope
		params[6] = 0.50f;  //gain

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SplitterProcessor::setActive (TBool state)
{
	if (state)
		env = buf0 = buf1 = buf2 = buf3 = 0.0f;
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void SplitterProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b;
	float a0=buf0, a1=buf1, b0=buf2, b1=buf3, f=freq, fx=ff;
	float aa, bb, ee, e=env, at=att, re=rel, l=level, lx=ll, px=pp;
	float il=i2l, ir=i2r, ol=o2l, or_=o2r;

	--in1;
	--in2;
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;
		b = *++in2;

		a0 += f * (a - a0 - a1);  //frequency split
		a1 += f * a0;
		aa = a1 + fx * a;

		b0 += f * (b - b0 - b1);
		b1 += f * b0;
		bb = b1 + fx * b;

		ee = aa + bb;
		if (ee < 0.0f) ee = -ee;
		if (ee > l) e += at * (px - e);  //level split
		e *= re;

		a = il * a + ol * aa * (e + lx);
		b = ir * b + or_ * bb * (e + lx);

		*++out1 = a;
		*++out2 = b;
	}
	env = e;  if (fabs (e) < 1.0e-10) env = 0.0f;
	buf0 = a0;  buf1 = a1;  buf2 = b0;  buf3 = b1;
	if (fabs (a0) < 1.0e-10) { buf0 = buf1 = buf2 = buf3 = 0.0f; }  //catch denormals
}

//-----------------------------------------------------------------------------
void SplitterProcessor::recalculate ()
{
	int32 tmp;

	freq = params[1];
	fdisp = (float)pow (10.0f, 2.0f + 2.0f * freq);  //frequency
	freq = 5.5f * fdisp / getSampleRate ();
	if (freq>1.0f) freq = 1.0f;

	ff = -1.0f;               //above
	tmp = std::min<int32> (2, 3 * params[2]);  //frequency switching
	if (tmp == 0) ff = 0.0f;     //below
	if (tmp == 1) freq = 0.001f; //all

	ldisp = 40.0f * params[3] - 40.0f;  //level
	level = (float)pow (10.0f, 0.05f * ldisp + 0.3f);

	ll = 0.0f;                //above
	tmp = (int32)(2.9f * params[4]);  //level switching
	if (tmp == 0) ll = -1.0f;    //below
	if (tmp == 1) level = 0.0f;  //all

	pp = -1.0f;  //phase correction
	if (ff==ll) pp = 1.0f;
	if (ff==0.0f && ll==-1.0f) { ll *= -1.0f; }

	att = 0.05f - 0.05f * params[5];
	rel = 1.0f - (float)exp (-6.0f - 4.0f * params[5]); //envelope
	if (att>0.02f) att=0.02f;
	if (rel<0.9995f) rel = 0.9995f;

	i2l = i2r = o2l = o2r = (float)pow (10.0f, (float)(2.0f * params[6] - 1.0f));  //gain

	mode = std::min<int32> (3, 4 * params[0]);  //output routing
	switch (mode)
	{
		case  0: i2l  =  0.0f;  i2r  =  0.0f;  break;
		case  1: o2l *= -1.0f;  o2r *= -1.0f;  break;
		case  2: i2l  =  0.0f;  o2r *= -1.0f;  break;
		default: o2l *= -1.0f;  i2r  =  0.0f;  break;
	}
}

}}} // namespaces
