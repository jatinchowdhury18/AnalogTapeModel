/*
 *  mdaLeslieProcessor.cpp
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

#include "mdaLeslieProcessor.h"
#include "mdaLeslieController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID LeslieProcessor::uid (0xFBD3AD80, 0x9E2847E0, 0xB87CDEC3, 0x5C0469B1);

//-----------------------------------------------------------------------------
LeslieProcessor::LeslieProcessor ()
{
	setControllerClass (LeslieController::uid);
	allocParameters (9);
}

//-----------------------------------------------------------------------------
LeslieProcessor::~LeslieProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[LeslieController::kParam0] = 0.66f;
		params[LeslieController::kParam7] = 0.50f;
		params[LeslieController::kParam6] = 0.48f;
		params[LeslieController::kParam3] = 0.70f;
		params[LeslieController::kParam4] = 0.60f;
		params[LeslieController::kParam5] = 0.70f;
		params[LeslieController::kParam2] = 0.50f;
		params[LeslieController::kParam1] = 0.50f;
		params[LeslieController::kParam8] = 0.60f;

		size = 256; hpos = 0;
		hbuf = new float[size];
		fbuf1 = fbuf2 = 0.0f;
		twopi = 6.2831853f;
		chp = dchp = clp = dclp = shp = dshp = slp = dslp = 0.0f;

		lspd = 0.0f; hspd = 0.0f;
		lphi = 0.0f; hphi = 1.6f; 

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieProcessor::terminate ()
{
	if (hbuf) delete [] hbuf;
	hbuf = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API LeslieProcessor::setActive (TBool state)
{
	if (state)
		memset (hbuf, 0, size * sizeof (float));
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void LeslieProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, c, d, g=gain, h, l;	
	float fo=filo, fb1=fbuf1, fb2=fbuf2;
	float hl=hlev, hs=hspd, ht, hm=hmom, hp=hphi, hw=hwid, hd=hdep;
	float ll=llev, ls=lspd, lt, lm=lmom, lp=lphi, lw=lwid;
	float hint, k0=0.03125f, k1=32.f; //k0 = 1/k1
	int32  hdd, hdd2, k=0, hps=hpos;

	ht=hset*(1.f-hm); //target speeds
	lt=lset*(1.f-lm);

	chp = (float)cos(hp); chp *= chp * chp; //set LFO values
	clp = (float)cos(lp);
	shp = (float)sin(hp);
	slp = (float)sin(lp);

	--in1;	
	--in2;	
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		a = *++in1 + *++in2; //mono input

		if (k) k--; else //linear piecewise approx to LFO waveforms
		{
			ls = (lm * ls) + lt; //tend to required speed
			hs = (hm * hs) + ht;
			lp += k1 * ls;
			hp += k1 * hs;
			   
			dchp = (float)cos(hp + k1*hs);
			dchp = k0 * (dchp * dchp * dchp - chp); //sin^3 level mod
			dclp = k0 * ((float)cos(lp + k1*ls) - clp);
			dshp = k0 * ((float)sin(hp + k1*hs) - shp);
			dslp = k0 * ((float)sin(lp + k1*ls) - slp);

			k= (int32)k1;
		}

		fb1 = fo * (fb1 - a) + a; //crossover
		fb2 = fo * (fb2 - fb1) + fb1;  
		h = (g - hl * chp) * (a - fb2); //volume
		l = (g - ll * clp) * fb2;

		if (hps>0) hps--; else hps=200;  //delay input pos
		hint = hps + hd * (1.0f + chp); //delay output pos 
		hdd = (int)hint; 
		hint = hint - hdd; //linear intrpolation
		hdd2 = hdd + 1;
		if (hdd>199) { if (hdd>200) hdd -= 201; hdd2 -= 201; }

		*(hbuf + hps) = h; //delay input
		a = *(hbuf + hdd);
		h += a + hint * ( *(hbuf + hdd2) - a); //delay output

		c = l + h; 
		d = l + h;
		h *= hw * shp;
		l *= lw * slp;
		d += l - h;
		c += h - l;

		*++out1 = c; //output
		*++out2 = d;

		chp += dchp;
		clp += dclp;
		shp += dshp;
		slp += dslp;
	}
	lspd = ls;
	hspd = hs;
	hpos = hps;
	lphi = (float)fmod(lp+(k1 -k)*ls,twopi);
	hphi = (float)fmod(hp+(k1 -k)*hs,twopi);
	if (fabs (fb1)>1.0e-10) fbuf1=fb1; else fbuf1=0.0f; //catch denormals
	if (fabs (fb2)>1.0e-10) fbuf2=fb2; else fbuf2=0.0f; 
}

//-----------------------------------------------------------------------------
void LeslieProcessor::recalculate ()
{
	float ifs = 1.0f / (float)getSampleRate ();
	float spd = twopi * ifs * 2.0f * params[LeslieController::kParam8];

	filo = 1.f - (float)pow (10.0f, (float)(params[LeslieController::kParam6] * (2.27f - 0.54f * params[LeslieController::kParam6]) - 1.92f));

	switch ((int)(params[LeslieController::kParam0]*2.))
	{
		case 0:
		{
			lset = 0.00f; hset = 0.00f;
			lmom = 0.12f; hmom = 0.10f; 
			break;
		}
		case 1:
		{
			lset = 0.49f; hset = 0.66f;
			lmom = 0.27f; hmom = 0.18f;
			break;
		}
		case 2:
		{
			lset = 5.31f; hset = 6.40f;
			lmom = 0.14f; hmom = 0.09f;
			break;
		}
	}

	hmom = (float)pow (10.0f, -ifs / hmom);
	lmom = (float)pow (10.0f, -ifs / lmom); 
	hset *= spd;
	lset *= spd;

	gain = 0.4f * (float)pow (10.0f, (float)(2.0f * params[LeslieController::kParam7] - 1.0f));
	lwid = params[LeslieController::kParam1] * params[LeslieController::kParam1];
	llev = gain * 0.9f * params[LeslieController::kParam2] * params[LeslieController::kParam2];
	hwid = params[LeslieController::kParam3] * params[LeslieController::kParam3];
	hdep = params[LeslieController::kParam4] * params[LeslieController::kParam4] * getSampleRate () / 760.0f;
	hlev = gain * 0.9f * params[LeslieController::kParam5] * params[LeslieController::kParam5];
}

}}} // namespaces

