/*
 *  mdaDynamicsProcessor.cpp
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

#include "mdaDynamicsProcessor.h"
#include "mdaDynamicsController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID DynamicsProcessor::uid (0x9CCF20FE, 0x76CD489C, 0xA9D7EA13, 0xB489CA55);

//-----------------------------------------------------------------------------
DynamicsProcessor::DynamicsProcessor ()
{
	setControllerClass (DynamicsController::uid);
	allocParameters (10);
}

//-----------------------------------------------------------------------------
DynamicsProcessor::~DynamicsProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.60; //thresh 		///Note : special version for ardislarge
		params[1] = 0.40; //ratio
		params[2] = 0.10; //level      ///was 0.6
		params[3] = 0.18; //attack
		params[4] = 0.55; //release
		params[5] = 1.00; //Limiter
		params[6] = 0.00; //gate thresh
		params[7] = 0.10; //gate attack
		params[8] = 0.50; //gate decay
		params[9] = 1.00; //fx mix

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DynamicsProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DynamicsProcessor::checkSilence (ProcessData& data)
{
}

//-----------------------------------------------------------------------------
void DynamicsProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	if (data.inputs[0].silenceFlags & 3)	// don't process if input is silent
	{
		if (in1 != out1)
			memset (out1, 0, sampleFrames * sizeof (float));
		if (in2 != out2)
			memset (out2, 0, sampleFrames * sizeof (float));
		data.outputs[0].silenceFlags = 3;
		return;
	}

	data.outputs[0].silenceFlags = 0;

	float a, b, i, j, g, e=env, e2=env2, ra=rat, re= (1.f-rel), at=att, ga=gatt;
	float tr=trim, th=thr, lth=lthr, xth=xthr, ge=genv, y =dry;  
	--in1;	
	--in2;	
	--out1;
	--out2;

	if (mode) //comp/gate/lim
	{
		if (lth==0.f) lth=1000.f;
		while (--sampleFrames >= 0)
		{
			a = *++in1;
			b = *++in2;

			i = (a<0.f)? -a : a;
			j = (b<0.f)? -b : b;
			i = (j>i)? j : i;

			e = (i>e)? e + at * (i - e) : e * re;
			e2 = (i>e)? i : e2 * re; //ir;

			g = (e>th)? tr / (1.f + ra * ((e / th) - 1.f)) : tr;

			if (g<0.f) g=0.f; 
			if (g*e2>lth) g = lth/e2; //limit 

			ge = (e>xth)? ge + ga - ga * ge : ge * xrat; //gate

			*++out1 = a * (g * ge + y);	
			*++out2 = b * (g * ge + y);	
		}
	}
	else //compressor only
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1;
			b = *++in2;

			i = (a<0.f)? -a : a;
			j = (b<0.f)? -b : b;
			i = (j>i)? j : i; //get peak level

			e = (i>e)? e + at * (i - e) : e * re; //envelope
			g = (e>th)? tr / (1.f + ra * ((e / th) - 1.f)) : tr; //gain

			*++out1 = a * (g + y); //vca
			*++out2 = b * (g + y);	
		}
	}
	if (e <1.0e-10) env =0.f; else env =e;
	if (e2<1.0e-10) env2=0.f; else env2=e2;
	if (ge<1.0e-10) genv=0.f; else genv=ge;
}

//-----------------------------------------------------------------------------
void DynamicsProcessor::recalculate ()
{
	mode=0;
	thr = (float)pow (10.f, (float)(2.f * params[0] - 2.f));
	rat = 2.5f * params[1] - 0.5f; 
	if (rat>1.0) { rat = 1.f + 16.f*(rat-1.f) * (rat - 1.f); mode = 1; }
	if (rat<0.0) { rat = 0.6f*rat; mode=1; }
	trim = (float)pow (10.f,(float)(2.f * params[2])); //was  - 1.f);
	att = (float)pow (10.f, (float)(-0.002f - 2.f * params[3]));
	rel = (float)pow (10.f, (float)(-2.f - 3.f * params[4]));

	if (params[5]>0.98) lthr=0.f; //limiter
	else { lthr=0.99f*(float)pow (10.0f,int (30.0*params[5] - 20.0)/20.f); 
		mode=1; } 

	if (params[6]<0.02) { xthr=0.f; } //expander
	else { xthr= (float)pow (10.f,(float)(3.f * params[6] - 3.f)); mode=1; } 
	xrat = 1.f - (float)pow (10.f, (float)(-2.0 - 3.3 * params[8]));
	irel = (float)pow (10.0,-2.0/getSampleRate ());
	gatt = (float)pow (10.f, (float)(-0.002 - 3.0 * params[7]));

	if (rat<0.0f && thr<0.1f) rat *= thr*15.f;

	dry = 1.0f - params[9];  trim *= params[9]; //fx mix
}

}}} // namespaces

