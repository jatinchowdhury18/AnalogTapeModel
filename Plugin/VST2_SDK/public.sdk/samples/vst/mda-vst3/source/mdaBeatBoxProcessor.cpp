/*
 *  mdaBeatBoxProcessor.cpp
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

#include "mdaBeatBoxProcessor.h"
#include "mdaBeatBoxController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
FUID BeatBoxProcessor::uid (0x9E6A6E95, 0x9B734440, 0x97D787BE, 0xBBDDD831);

//-----------------------------------------------------------------------------
BeatBoxProcessor::BeatBoxProcessor ()
{
	hbuf = kbuf = sbuf = sbuf2 = 0;
	hthr = hfil = sthr = kthr = kfil1 = kfil2 = mix = 0;
	klev = hlev = slev = 0;
	ww = wwx = sb1 = sb2 = sf1 = sf2 = sf3 = 0;
	kww = kwwx = ksb1 = ksb2 = ksf1 = ksf2 = 0;
	dyne = dyna = dynr = dynm = 0;

	allocParameters(12);
	setControllerClass (BeatBoxController::uid);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BeatBoxProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.30; //hat thresh
		params[1] = 0.45; //hat rate
		params[2] = 0.50; //hat mix
		params[3] = 0.46; //kick thresh 	
		params[4] = 0.15; //kick key
		params[5] = 0.50; //kick mix
		params[6] = 0.50; //snare thresh
		params[7] = 0.70; //snare key
		params[8] = 0.50; //snare mix
		params[9] = 0.00; //dynamics
		params[10] = 0.00; //record 
		params[11] = 0.00; //thru mix

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BeatBoxProcessor::setActive (TBool state)
{
	if (state)
	{
		sdel = (int32)(0.12 * getSampleRate ());
		kdel = (int32)(0.10 * getSampleRate ());
		sf3 = 0.991f; //r
		sfx = 0; ksfx = 0;
		rec = 0;

		hbuflen = 20000;
		kbuflen = 20000;
		sbuflen = 60000;
		if (getSampleRate ()>49000) { hbuflen*=2; kbuflen*=2; sbuflen*=2; }

		hbuf = new float[hbuflen];
		sbuf = new float[sbuflen];
		sbuf2 = new float[sbuflen];
		kbuf = new float[kbuflen];
		hbufpos = sbufpos = kbufpos = 0;

		memset (sbuf, 0, sbuflen * sizeof (float));
		memset (sbuf2, 0, sbuflen * sizeof (float));

		int32 t; 
		float e=0.00012f, de, o, o1=0.f, o2=0.f, p=0.2f, dp; 

		memset (hbuf, 0, hbuflen * sizeof (float)); //generate hi-hat
		de = (float)pow (10.0,-36.0/getSampleRate ());
		for(t=0;t<5000;t++) 
		{ 
			o = (float)((rand() % 2000) - 1000); 
			*(hbuf + t) =  e * ( 2.f * o1 - o2 - o); 
			e *= de; o2=o1; o1=o;
		}

		memset (kbuf, 0, kbuflen * sizeof (float)); //generate kick
		de = (float)pow (10.0,-3.8/getSampleRate ());
		e=0.5f; dp = 1588.f / getSampleRate ();
		for(t=0;t<14000;t++) 
		{ 
			*(kbuf + t) =  e * (float)sin(p); 
			e *= de; p = (float)fmod(p + dp * e ,6.2831853f);
		}

		memset (sbuf, 0, sbuflen * sizeof (float)); //generate snare
		de = (float)pow (10.0,-15.0/getSampleRate ());
		e=0.38f; dp = 1103.f / getSampleRate ();
		for(t=0;t<7000;t++) 
		{ 
			o = (0.3f * o) + (float)((rand() % 2000) - 1000); 
			*(sbuf + t) =  (float)(e * (sin(p) + 0.0004 * o)); 
			*(sbuf2 + t) = *(sbuf + t);
			e *= de; p = (float)fmod(p + 0.025,6.2831853);
		}
	}
	else
	{
		if (hbuf) delete [] hbuf;
		if (kbuf) delete [] kbuf;
		if (sbuf) delete [] sbuf;
		if (sbuf2) delete [] sbuf2;
		hbuf = kbuf = sbuf = sbuf2 = 0;
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void BeatBoxProcessor::doProcessing (ProcessData& data)
{ 
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	float a, b, e, o, hf=hfil, ht=hthr, mx3=0.f, mx1=mix;
	int32 hp=hbufpos, hl=hbuflen-2, hd=hdel;
	float kt=kthr;
	int32 kp=kbufpos, kl=kbuflen-2, kd=kdel;  
	float st=sthr, s, f1=sb1, f2=sb2, b1=sf1, b2=sf2, b3=sf3;
	float k, kf1=ksb1, kf2=ksb2, kb1=ksf1, kb2=ksf2;
	float hlv=hlev, klv=klev, slv=slev; 
	int32 sp=sbufpos, sl=sbuflen-2, sd=sdel;  
	float ya=dyna, yr = dynr, ye=dyne, ym=dynm, mx4;

	if (sfx>0) { mx3=0.08f; slv=0.f; klv=0.f; hlv=0.f; mx1=0.f; sfx-=sampleFrames;} //key listen (snare)
	if (ksfx>0) { mx3=0.03f; slv=0.f; klv=0.f; hlv=0.f; mx1=0.f; ksfx-=sampleFrames;
					b1=ksf1; b2=ksf2; } //key listen (kick)

	--in1;	
	--in2;	
	--out1;
	--out2;

	if (rec==0)
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1;
			b = *++in2;
			e = a + b;

			ye = (e<ye)? ye * yr : e - ya * (e - ye); //dynamics envelope

			hf = e - hf; //high filter
			if ((hp>hd) && (hf>ht)) hp=0; else { hp++; if (hp>hl)hp=hl; }
			o = hlv * *(hbuf + hp); //hat

			k = e + (kf1 * kb1) - (kf2 * kb2); //low filter
			kf2 = b3 * ((kf1 * kb2) + (kf2 * kb1)); 
			kf1 = b3 * k;
			if ((kp>kd) && (k>kt)) kp=0; else { kp++; if (kp>kl)kp=kl; }
			o += klv * *(kbuf + kp); //kick

			s = hf + (0.3f * e) + (f1 * b1) - (f2 * b2); //mid filter
			f2 = b3 * ((f1 * b2) + (f2 * b1)); 
			f1 = b3 * s;

			if ((sp>sd) && (s>st)) sp=0; else { sp++; if (sp>sl)sp=sl; }

			mx4 = 1.f + ym * (ye + ye - 1.f); //dynamics

			*++out1 = mx1*a + mx3*s + mx4*(o + slv * *(sbuf  + sp));	
			*++out2 = mx1*a + mx3*s + mx4*(o + slv * *(sbuf2 + sp));	

			hf=e;
		}
	}
	else //record
	{
		while (--sampleFrames >= 0)
		{
			a = *++in1;
			b = *++in2;
			e = 0.5f * (a + b);

			if ((recpos==0) && (fabs (e) < 0.004)) e=0.f;
			else 
			{ 
				switch (rec)
				{
					case 1: break; //echo
					case 2: if (recpos<hl) *(hbuf + recpos++) = e; else e=0.f; break;
					case 3: if (recpos<kl) *(kbuf + recpos++) = e; else e=0.f; break;
					case 4: if (recpos<sl) 
								{ *(sbuf+recpos)=a; *(sbuf2+recpos)=b; recpos++; }
							else e=0.f; break;
				}
			}
			*++out1 = e;	
			*++out2 = e;	
		}
	}
	hfil=hf; hbufpos=hp; 
	sbufpos=sp; sb1 = f1; sb2 = f2;
	kbufpos=kp; ksb1 = kf1; ksb2 = kf2;
	dyne=ye;

}

//-----------------------------------------------------------------------------
void BeatBoxProcessor::recalculate ()
{
	//calcs here
	hthr = (float)pow (10.f, (float)(2.f * params[0] - 2.f));
	hdel = (int32)((0.04 + 0.20 * params[1]) * getSampleRate ());
	sthr = (float)(40.0 * pow (10.f, (float)(2.f * params[6] - 2.f)));
	kthr = (float)(220.0 * pow (10.f, (float)(2.f * params[3] - 2.f)));

	hlev = (float)(0.0001f + params[2] * params[2] * 4.f);
	klev = (float)(0.0001f + params[5] * params[5] * 4.f);
	slev = (float)(0.0001f + params[8] * params[8] * 4.f);

	wwx=ww;
	ww = (float)pow (10.0,-3.0 + 2.2 * params[7]);
	sf1 = (float)cos(3.1415927 * ww);     //p
	sf2 = (float)sin(3.1415927 * ww);     //q
	//sfx = 0; ksfx = 0;

	kwwx=kww;
	kww = (float)pow (10.0,-3.0 + 2.2 * params[4]);
	ksf1 = (float)cos(3.1415927 * kww);     //p
	ksf2 = (float)sin(3.1415927 * kww);     //q

	if (wwx != ww) sfx = (int32)(2 * getSampleRate ()); 
	if (kwwx != kww) ksfx = (int32)(2 * getSampleRate ());

	rec = (int32)(4.9 * params[10]); 
	if ((rec!=recx) && (recpos>0)) //finish sample
	{
		switch (rec)
		{
			case 2: while (recpos<hbuflen) *(hbuf + recpos++) = 0.f; break;
			case 3: while (recpos<kbuflen) *(kbuf + recpos++) = 0.f; break;
			case 4: while (recpos<sbuflen) 
			{ 
				*(sbuf  + recpos) = 0.f; 
				*(sbuf2 + recpos) = 0.f; recpos++; 
			} break;
		}
	}
	recpos=0; recx=rec;
	mix = params[11];
	dynm = params[9];
}

}}} // namespaces
