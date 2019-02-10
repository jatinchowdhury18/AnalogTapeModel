/*
 *  mdaThruZeroProcessor.cpp
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

#include "mdaThruZeroProcessor.h"
#include "mdaThruZeroController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

#define BUFMAX   2048

//-----------------------------------------------------------------------------
FUID ThruZeroProcessor::uid (0xE7B8149A, 0x63A54BF8, 0x82B6A95D, 0x94A3F6EE);

//-----------------------------------------------------------------------------
ThruZeroProcessor::ThruZeroProcessor ()
{
	setControllerClass (ThruZeroController::uid);
	allocParameters (5);
}

//-----------------------------------------------------------------------------
ThruZeroProcessor::~ThruZeroProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.30f;  //rate
		params[1] = 0.43f;  //depth
		params[2] = 0.47f;  //mix
		params[3] = 0.30f;  //feedback
		params[4] = 1.00f;  //minimum delay to stop LF buildup with feedback

		bufpos  = 0;
		buffer  = new float[BUFMAX];
		buffer2 = new float[BUFMAX];
		phi = fb = fb1 = fb2 = deps = 0.0f;

		if (buffer) memset (buffer , 0, BUFMAX * sizeof (float));
		if (buffer2) memset (buffer2, 0, BUFMAX * sizeof (float));

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ThruZeroProcessor::setActive (TBool state)
{
	if (state)
	{
		if (buffer) memset (buffer , 0, BUFMAX * sizeof (float));
		if (buffer2) memset (buffer2, 0, BUFMAX * sizeof (float));
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void ThruZeroProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, f=fb, f1=fb1, f2=fb2, ph=phi;	
	float ra=rat, de=dep, we=wet, dr = dry, ds=deps, dm=dem;
	int32  tmp, tmpi, bp=bufpos;
	float tmpf, dpt;

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1;		
		b = *++in2; 

		ph += ra; 
		if (ph > 1.0f) ph -= 2.0f;

		bp--; bp &= 0x7FF;
		*(buffer  + bp) = a + f * f1; 
		*(buffer2 + bp) = b + f * f2;

		//ds = 0.995f * (ds - de) + de;          //smoothed depth change ...try inc not mult
		dpt = tmpf = dm + de * (1.0f - ph * ph); //delay mod shape
		tmp  = int (tmpf);
		tmpf -= tmp;
		tmp = (tmp + bp) & 0x7FF;
		tmpi = (tmp + 1) & 0x7FF; 

		f1 = *(buffer  + tmp);  //try adding a constant to reduce denormalling
		f2 = *(buffer2 + tmp);
		f1 = tmpf * (*(buffer  + tmpi) - f1) + f1; //linear interpolation
		f2 = tmpf * (*(buffer2 + tmpi) - f2) + f2;

		a = a * dr - f1 * we; 
		b = b * dr - f2 * we;

		*++out1 = a;
		*++out2 = b;
	}
	if (fabs (f1) > 1.0e-10) { fb1 = f1; fb2 = f2; } else fb1 = fb2 = 0.0f; //catch denormals
	phi = ph;
	deps = ds;
	bufpos = bp;

}

//-----------------------------------------------------------------------------
void ThruZeroProcessor::recalculate ()
{
	rat = (float)(pow (10.0f, (float)(3.f * params[0] - 2.f)) * 2.f / getSampleRate ());
	dep = 2000.0f * params[1] * params[1];
	dem = dep - dep * params[4];
	dep -= dem;

	wet = params[2];
	dry = 1.f - wet;
	if (params[0] < 0.01f) { rat = 0.0f; phi = (float)0.0f; }
	fb = 1.9f * params[3] - 0.95f;
}

}}} // namespaces

