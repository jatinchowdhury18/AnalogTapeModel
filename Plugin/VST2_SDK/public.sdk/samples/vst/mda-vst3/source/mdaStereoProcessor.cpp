/*
 *  mdaStereoProcessor.cpp
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

#include "mdaStereoProcessor.h"
#include "mdaStereoController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID StereoProcessor::uid (0xDB1EB642, 0x4838483D, 0xA7C7E5D2, 0x3686E943);

//-----------------------------------------------------------------------------
StereoProcessor::StereoProcessor ()
{
	setControllerClass (StereoController::uid);
	allocParameters (5);
}

//-----------------------------------------------------------------------------
StereoProcessor::~StereoProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API StereoProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = (float)0.78; //Haas/Comb width
		params[1] = (float)0.43; //delay
		params[2] = (float)0.50; //balance
		params[3] = (float)0.00; //mod
		params[4] = (float)0.50; //rate

		size = 4800;
		bufpos = 0;
		buffer = new float[size];
		memset (buffer, 0, size * sizeof (float));
		phi = 0;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API StereoProcessor::terminate ()
{
	if (buffer) delete [] buffer;
	buffer = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API StereoProcessor::setActive (TBool state)
{
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void StereoProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, c, d;	
	float li, ld, ri, rd, del, ph=phi, dph=dphi, mo=mod;
	int32 tmp, bp = bufpos;

	li = fli;
	ld = fld;
	ri = fri;
	rd = frd;
	del = fdel;

	--in1;	
	--in2;	
	--out1;
	--out2;
	if (mo>0.f) //modulated delay
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1 + *++in2; //sum to mono

			*(buffer + bp) = a; //write
			tmp = (bp + (int)(del + fabs (mo * sin(ph)) ) ) % 4410;
			b = *(buffer + tmp);

			c = (a * li) - (b * ld); // output
			d = (a * ri) - (b * rd);

			bp = (bp - 1); if (bp < 0) bp = 4410; //buffer position

			ph = ph + dph;

			*++out1 = c;
			*++out2 = d;
		}
	}
	else
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1 + *++in2; //sum to mono

			*(buffer + bp) = a; //write
			tmp = (bp + (int)(del) ) % 4410;
			b = *(buffer + tmp);

			c = (a * li) - (b * ld); // output
			d = (a * ri) - (b * rd);

			bp = (bp - 1); if (bp < 0) bp = 4410; //buffer position

			*++out1 = c;
			*++out2 = d;
		}
	}
	bufpos = bp;
	phi = (float)fmod(ph,6.2831853f);
}

//-----------------------------------------------------------------------------
void StereoProcessor::recalculate ()
{
	dphi= (float)(3.141 * pow (10.0,-2.0 + 3.0 * params[4]) / getSampleRate ()); 
	mod= (float)(2100.0 * pow (params[3], 2));

	if (params[0]<0.5)
	{
		fli = (float)(0.25 + (1.5 * params[0]));
		fld = 0.0;
		fri = (float)(2.0 * params[0]);
		frd = (float)(1.0 - fri);
	}
	else
	{
		fli = (float)(1.5 - params[0]);
		fld = (float)(params[0] - 0.5);
		fri = fli;
		frd = -fld;
	}
	fdel = (float)(20.0 + 2080.0 * pow (params[1], 2));
	if (params[2]>0.5)
	{
		fli *= (float)((1.0 - params[2]) * 2.0);
		fld *= (float)((1.0 - params[2]) * 2.0);
	}
	else
	{
		fri *= (2 * params[2]);
		frd *= (2 * params[2]);
	}
	fri *= (float)(0.5 + fabs (params[0] - 0.5));
	frd *= (float)(0.5 + fabs (params[0] - 0.5));
	fli *= (float)(0.5 + fabs (params[0] - 0.5));
	fld *= (float)(0.5 + fabs (params[0] - 0.5));
}

}}} // namespaces

