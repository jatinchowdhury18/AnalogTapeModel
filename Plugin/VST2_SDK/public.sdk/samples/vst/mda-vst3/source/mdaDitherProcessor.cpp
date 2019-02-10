/*
 *  dmaDitherProcessor.cpp
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

#include "mdaDitherProcessor.h"

#include "mdaDitherController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DitherProcessor::uid (0xA155F267, 0xA6954095, 0xAFD8BFB1, 0x9E4F2293);

//-----------------------------------------------------------------------------
DitherProcessor::DitherProcessor ()
{
	setControllerClass (DitherController::uid);
	allocParameters (5);
}

//-----------------------------------------------------------------------------
DitherProcessor::~DitherProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.50f; //bits
		params[1] = 0.88f; //dither (off, rect, tri, hp-tri, hp-tri-2ndOrderShaped)
		params[2] = 0.50f; //dither level
		params[3] = 0.50f; //dc trim
		params[4] = 0.00f; //zoom (8 bit dither and fade audio out)

		sh1 = sh2 = sh3 = sh4 = 0.0f;
		rnd1 = rnd3 = 0;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DitherProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DitherProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, aa, bb;
	float sl=shap, s1=sh1, s2=sh2, s3=sh3, s4=sh4; //shaping level, buffers
	float dl=dith;                                 //dither level
	float o = offs, w=wlen, wi = 1.0f/wlen;            //DC offset, word length & inverse
	float g=gain;                                  //gain for Zoom mode
	int32  r1=rnd1, r2, r3=rnd3, r4;                //random numbers for dither
	int32  m=1;                                     //dither mode
	if ((int32)(params[1] * 3)==1) m=0;             //what is the fastest if (?)

	--in1;	
	--in2;	
	--out1;
	--out2;

	while (--sampleFrames >= 0)
	{
		a = *++in1;
		b = *++in2;

		r2=r1; r4=r3; //HP-TRI dither (also used when noise shaping)
		if (m==0) { r4=rand() & 0x7FFF; r2= (r4 & 0x7F)<<8; } //TRI dither
		r1=rand() & 0x7FFF; r3= (r1 & 0x7F)<<8;   //Assumes RAND_MAX=32767?

		a  = g * a + sl * (s1 + s1 - s2);    //target level + error feedback
		aa = a + o + dl * (float)(r1 - r2);  //             + offset + dither 
		if (aa<0.0f) aa-=wi;                 //(int32) truncates towards zero!
		aa = wi * (float)(int32)(w * aa);    //truncate 
		s2 = s1;                            
		s1 = a - aa;                        //error feedback: 2nd order noise shaping

		b  = g * b + sl * (s3 + s3 - s4);
		bb = b + o + dl * (float)(r3 - r4);
		if (bb<0.0f) bb-=wi;
		bb = wi * (float)(int32)(w * bb);
		s4 = s3;
		s3 = b - bb;

		*++out1 = aa;
		*++out2 = bb;
	}

	sh1=s1; sh2=s2; sh3=s3; sh4=s4; //doesn't actually matter if these are
	rnd1=r1; rnd3=r3;               //saved or not as effect is so small !
}

//-----------------------------------------------------------------------------
void DitherProcessor::recalculate ()
{
	gain = 1.0f;
	bits = 8.0f + 2.0f * (float)floor(8.9f * params[0]); 

	if (params[4]>0.1f) //zoom to 6 bit & fade out audio
	{
		wlen = 32.0f;
		gain = (1.0f - params[4]); gain*=gain;
	}
	else wlen = (float)pow (2.0f, bits - 1.0f); //word length in quanta

	//Using WaveLab 2.01 (unity gain) as a reference: 
	//  16-bit output is (int)floor(floating_point_value*32768.0f)

	offs = (4.0f * params[3] - 1.5f) / wlen; //DC offset (plus 0.5 to round dither not truncate)
	dith = 2.0f * params[2] / (wlen * (float)32767);
	shap=0.0f;

	switch ((int32)(params[1]*3)) //dither mode
	{  
		case 0: dith = 0.0f; break; //off
		case 3: shap = 0.5f; break; //noise shaping
		default: break; //tri, hp-tri
	}
}

}}} // namespaces

