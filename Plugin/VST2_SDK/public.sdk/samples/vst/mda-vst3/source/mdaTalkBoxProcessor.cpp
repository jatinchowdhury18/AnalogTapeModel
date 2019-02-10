/*
 *  mdaTalkBoxProcessor.cpp
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

#include "mdaTalkBoxProcessor.h"
#include "mdaTalkBoxController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

#define BUF_MAX         1600
#define ORD_MAX           50
#define TWO_PI     6.28318530717958647692528676655901f

//-----------------------------------------------------------------------------
FUID TalkBoxProcessor::uid (0xF235EEE4, 0x92084883, 0xAD5C8632, 0x34DFE073);

//-----------------------------------------------------------------------------
TalkBoxProcessor::TalkBoxProcessor ()
{
	setControllerClass (TalkBoxController::uid);
	allocParameters (4);
}

//-----------------------------------------------------------------------------
TalkBoxProcessor::~TalkBoxProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TalkBoxProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioInput (USTRING("Sidechain In"), SpeakerArr::kMono, kAux);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		params[0] = 0.5f;  //wet
		params[1] = 0.0f;  //dry
		params[2] = 0.0f;  //swap
		params[3] = 1.0f;  //quality

		buf0 = new float[BUF_MAX];
		buf1 = new float[BUF_MAX];
		window = new float[BUF_MAX];
		car0 = new float[BUF_MAX];
		car1 = new float[BUF_MAX];
		N = 1; //trigger window recalc
		K = 0;

		pos = K = 0;
		emphasis = 0.0f;
		FX = 0;

		u0 = u1 = u2 = u3 = u4 = 0.0f;
		d0 = d1 = d2 = d3 = d4 = 0.0f;

		memset (buf0, 0, BUF_MAX * sizeof (float));
		memset (buf1, 0, BUF_MAX * sizeof (float));
		memset (car0, 0, BUF_MAX * sizeof (float));
		memset (car1, 0, BUF_MAX * sizeof (float));
		memset (window, 0, BUF_MAX * sizeof (float));
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TalkBoxProcessor::terminate ()
{
	if (buf0) delete [] buf0;
	if (buf1) delete [] buf1;
	if (window) delete [] window;
	if (car0) delete [] car0;
	if (car1) delete [] car1;
	buf0=buf1=window=car0=car1=0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API TalkBoxProcessor::setActive (TBool state)
{
	if (state)
		recalculate ();
	else
	{
		pos = K = 0;
		emphasis = 0.0f;
		FX = 0;

		u0 = u1 = u2 = u3 = u4 = 0.0f;
		d0 = d1 = d2 = d3 = d4 = 0.0f;

		memset (buf0, 0, BUF_MAX * sizeof (float));
		memset (buf1, 0, BUF_MAX * sizeof (float));
		memset (car0, 0, BUF_MAX * sizeof (float));
		memset (car1, 0, BUF_MAX * sizeof (float));
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void TalkBoxProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	if (swap)
	{
		in1 = data.inputs[0].channelBuffers32[1];
		in2 = data.inputs[0].channelBuffers32[0];
	}
	if (getAudioInput (1)->isActive () && data.numInputs > 1)
	{
		in1 = data.inputs[1].channelBuffers32[0];
	}

	int32  p0=pos, p1 = (pos + N/2) % N;
	float e=emphasis, w, o, x, dr, fx=FX;
	float p, q, h0=0.3f, h1=0.77f;

	--in1;
	--in2;
	--out1;
	--out2;
	while (--sampleFrames >= 0)
	{
		o = *++in1;
		x = *++in2;
		dr = o;

		p = d0 + h0 *  x; d0 = d1;  d1 = x  - h0 * p;
		q = d2 + h1 * d4; d2 = d3;  d3 = d4 - h1 * q;  
		d4 = x;
		x = p + q;

		if (K++)
		{
			K = 0;

			car0[p0] = car1[p1] = x; //carrier input

			x = o - e;  e = o;  //6dB/oct pre-emphasis

			w = window[p0]; fx = buf0[p0] * w;  buf0[p0] = x * w;  //50% overlapping hanning windows
			if (++p0 >= N) { lpc(buf0, car0, N, O);  p0 = 0; }

			w = 1.0f - w;  fx += buf1[p1] * w;  buf1[p1] = x * w;
			if (++p1 >= N) { lpc(buf1, car1, N, O);  p1 = 0; }
		}

		p = u0 + h0 * fx; u0 = u1;  u1 = fx - h0 * p;
		q = u2 + h1 * u4; u2 = u3;  u3 = u4 - h1 * q;  
		u4 = fx;
		x = p + q;

		o = wet * x + dry * dr;
		*++out1 = o;
		*++out2 = o;
	}
	emphasis = e;
	pos = p0;
	FX = fx;

	float den = 1.0e-10f; //(float)pow (10.0f, -10.0f * params[4]);
	if (fabs (d0) < den) d0 = 0.0f; //anti-denormal (doesn't seem necessary but P4?)
	if (fabs (d1) < den) d1 = 0.0f;
	if (fabs (d2) < den) d2 = 0.0f;
	if (fabs (d3) < den) d3 = 0.0f;
	if (fabs (u0) < den) u0 = 0.0f;
	if (fabs (u1) < den) u1 = 0.0f;
	if (fabs (u2) < den) u2 = 0.0f;
	if (fabs (u3) < den) u3 = 0.0f;
}

//-----------------------------------------------------------------------------
void TalkBoxProcessor::recalculate ()
{
	float fs = (float)getSampleRate ();
	if (fs <  8000.0f) fs =  8000.0f;
	if (fs > 96000.0f) fs = 96000.0f;

	swap = (params[2] > 0.5f)? 1 : 0;

	int32 n = (int32)(0.01633f * fs);
	if (n > BUF_MAX) n = BUF_MAX;

	//O = (int32)(0.0005f * fs);
	O = (int32)((0.0001f + 0.0004f * params[3]) * fs);

	if (n != N) //recalc hanning window
	{
		N = n;
		float dp = TWO_PI / (float)N;
		float p = 0.0f;
		for(n=0; n<N; n++)
		{
			window[n] = 0.5f - 0.5f * (float)cos(p);
			p += dp;
		}
	}
	wet = 0.5f * params[0] * params[0];
	dry = 2.0f * params[1] * params[1];
}

void TalkBoxProcessor::lpc(float *buf, float *car, int32 n, int32 o)
{
  float z[ORD_MAX], r[ORD_MAX], k[ORD_MAX], G, x;
  int32 i, j, nn=n;

  for(j=0; j<=o; j++, nn--)  //buf[] is already emphasized and windowed
  {
    z[j] = r[j] = 0.0f;
    for(i = 0; i<nn; i++) r[j] += buf[i] * buf[i+j]; //autocorrelation
  }
  r[0] *= 1.001f;  //stability fix

  float min = 0.00001f;
  if (r[0] < min) { for(i = 0; i<n; i++) buf[i] = 0.0f; return; } 

  lpc_durbin(r, o, k, &G);  //calc reflection coeffs

  for(i = 0; i<=o; i++) 
  {
    if (k[i] > 0.995f) k[i] = 0.995f; else if (k[i] < -0.995f) k[i] = -.995f;
  }
  
  for(i = 0; i<n; i++)
  {
    x = G * car[i];
    for(j=o; j>0; j--)  //lattice filter
    { 
      x -= k[j] * z[j-1];
      z[j] = z[j-1] + k[j] * x;
    }
    buf[i] = z[0] = x;  //output buf[] will be windowed elsewhere
  }
}


void TalkBoxProcessor::lpc_durbin(float *r, int32 p, float *k, float *g)
{
  int32 i, j;
  float a[ORD_MAX], at[ORD_MAX], e=r[0];
    
  for(i = 0; i <= p; i++) a[i] = at[i] = 0.0f; //probably don't need to clear at[] or k[]

  for(i = 1; i <= p; i++) 
  {
    k[i] = -r[i];

    for(j = 1; j < i; j++) 
    { 
      at[j] = a[j];
      k[i] -= a[j] * r[i-j]; 
    }
    if (fabs (e) < 1.0e-20f) { e = 0.0f;  break; }
    k[i] /= e;
    
    a[i] = k[i];
    for(j = 1; j < i; j++) a[j] = at[j] + k[i] * at[i-j];
    
    e *= 1.0f - k[i] * k[i];
  }

  if (e < 1.0e-20f) e = 0.0f;
  *g = (float)sqrt (e);
}

}}} // namespaces

