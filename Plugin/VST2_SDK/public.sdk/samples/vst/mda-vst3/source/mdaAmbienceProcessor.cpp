/*
 *  mdaAmbienceProcessor.cpp
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/13/08.
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

#include "mdaAmbienceProcessor.h"
#include "mdaAmbienceController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID AmbienceProcessor::uid (0xAF799E3A, 0xC94B444A, 0xB5B24FD5, 0xD3E3F9E4);

//-----------------------------------------------------------------------------
AmbienceProcessor::AmbienceProcessor ()
: buf1 (0)
, buf2 (0)
, buf3 (0)
, buf4 (0)
{
	setControllerClass (AmbienceController::uid);
	allocParameters (4);
}

//-----------------------------------------------------------------------------
AmbienceProcessor::~AmbienceProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API AmbienceProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		//inits here!
		params[0] = 0.7; //size
		params[1] = 0.7; //hf
		params[2] = 0.9; //mix
		params[3] = 0.5; //output

		buf1 = new float[1024];
		buf2 = new float[1024];
		buf3 = new float[1024];
		buf4 = new float[1024];

		fil = 0.0f;
		den = pos = 0;
		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API AmbienceProcessor::terminate ()
{
	if (buf1)
		delete [] buf1;
	if (buf2)
		delete [] buf2;
	if (buf3)
		delete [] buf3;
	if (buf4)
		delete [] buf4;
	buf1 = buf2 = buf3 = buf4 = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API AmbienceProcessor::setActive (TBool state)
{
	if (state)
		clearBuffers();
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void AmbienceProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];
	float a, b, r;	
	float t, f=fil, fb=fbak, dmp=damp, y =dry, w=wet;
	int32  p = pos, d1, d2, d3, d4;

	if (rdy ==0)
		clearBuffers();

	d1 = (p + (int32)(107 * size)) & 1023;
	d2 = (p + (int32)(142 * size)) & 1023;
	d3 = (p + (int32)(277 * size)) & 1023;
	d4 = (p + (int32)(379 * size)) & 1023;

	--in1;	
	--in2;	
	--out1;
	--out2;

	while (--sampleFrames >= 0)
	{
		a = *++in1;
		b = *++in2;

		f += dmp * (w * (a + b) - f); //HF damping
		r = f;

		t = *(buf1 + p);
		r -= fb * t;
		*(buf1 + d1) = r; //allpass
		r += t;

		t = *(buf2 + p);
		r -= fb * t;
		*(buf2 + d2) = r; //allpass
		r += t;

		t = *(buf3 + p);
		r -= fb * t;
		*(buf3 + d3) = r; //allpass
		r += t;
		a = y * a + r - f; //left output

		t = *(buf4 + p);
		r -= fb * t;
		*(buf4 + d4) = r; //allpass
		r += t;
		b = y * b + r - f; //right output

		++p  &= 1023;
		++d1 &= 1023;
		++d2 &= 1023;
		++d3 &= 1023;
		++d4 &= 1023;

		*++out1 = a;
		*++out2 = b;
	}
	pos=p;
	if (fabs (f)>1.0e-10) { fil=f;  den=0; }  //catch denormals
	else { fil=0.0f;  if (den==0) { den=1;  clearBuffers(); } } 
}

//-----------------------------------------------------------------------------
void AmbienceProcessor::clearBuffers ()
{
	memset (buf1, 0, 1024 * sizeof (float));
	memset (buf2, 0, 1024 * sizeof (float));
	memset (buf3, 0, 1024 * sizeof (float));
	memset (buf4, 0, 1024 * sizeof (float));
	rdy = 1;
}

//-----------------------------------------------------------------------------
void AmbienceProcessor::recalculate ()
{
	float tmp;
	
	fbak = 0.8f;
	damp = 0.05f + 0.9f * params[1];
	tmp = (float)powf (10.0f, 2.0f * params[3] - 1.0f);
	dry = tmp - params[2] * params[2] * tmp;
	wet = (0.4f + 0.4f) * params[2] * tmp;  

	tmp = 0.025f + 2.665f * params[0];
	if (size!=tmp) rdy =0;  //need to flush buffer
	size = tmp;
}

}}} // namespaces
