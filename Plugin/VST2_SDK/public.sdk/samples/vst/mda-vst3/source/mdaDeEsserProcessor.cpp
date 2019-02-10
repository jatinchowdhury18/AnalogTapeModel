/*
 *  mdaDeEsserProcessor.cpp
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

#include "mdaDeEsserProcessor.h"
#include "mdaDeEsserController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DeEsserProcessor::uid (0x174FD6D1, 0x856E4641, 0xBFB9851A, 0x1C544725);

//-----------------------------------------------------------------------------
DeEsserProcessor::DeEsserProcessor ()
{
	setControllerClass (DeEsserController::uid);
	allocParameters (3);
}

//-----------------------------------------------------------------------------
DeEsserProcessor::~DeEsserProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DeEsserProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.15; //thresh
		params[1] = 0.60; //f
		params[2] = 0.50; //drive
		
		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DeEsserProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DeEsserProcessor::setActive (TBool state)
{
	env=0.f;
	fbuf1 = fbuf2 = 0;
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DeEsserProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b;	
	float f1=fbuf1, f2=fbuf2, tmp, fi=fil, fo= (1.f-fil);
	float at=att, re=rel, en=env, th=thr, g, gg=gai;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2; 

		tmp = 0.5f * (a + b);       //2nd order crossover
		f1  = fo * f1 + fi * tmp;
		tmp -= f1;
		f2  = fo * f2 + fi * tmp;
		tmp = gg*(tmp - f2);        //extra HF gain

		en= (tmp>en)? en+at*(tmp-en) : en*re;             //envelope
		if (en>th) g=f1+f2+tmp*(th/en); else g=f1+f2+tmp; //limit 
		//brackets for full-band!!!
		*++out1 = g;
		*++out2 = g;
	}
	if (fabs (f1) < 1.0e-10) {fbuf1=0.f; fbuf2=0.f;} else {fbuf1=f1; fbuf2=f2;}
	if (fabs (en) < 1.0e-10) env=0.f; else env=en;
}

//-----------------------------------------------------------------------------
void DeEsserProcessor::recalculate ()
{
	thr= (float)pow (10.0f, (float)(3.f * params[0] - 3.f));
	att=0.01f;
	rel=0.992f;
	fil=0.05f + 0.94f * params[1] * params[1];
	gai= (float)pow (10.0f, (float)(2.f * params[2] - 1.f));
}

}}} // namespaces

