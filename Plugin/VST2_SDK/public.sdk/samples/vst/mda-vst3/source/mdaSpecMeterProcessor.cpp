/*
 *  mdaSpecMeterProcessor.cpp
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

#include "mdaSpecMeterProcessor.h"
#include "mdaSpecMeterController.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

#define SILENCE 0.00000001f

//-----------------------------------------------------------------------------
FUID SpecMeterProcessor::uid (0x67B9A082, 0xCF0B4BAC, 0x907AA8B7, 0x1D855F94);

//-----------------------------------------------------------------------------
SpecMeterProcessor::SpecMeterProcessor ()
{
	setControllerClass (SpecMeterController::uid);
}

//-----------------------------------------------------------------------------
SpecMeterProcessor::~SpecMeterProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SpecMeterProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addAudioInput (USTRING("Stereo In"), SpeakerArr::kStereo);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		K = 0;
		kmax = 2048;
		topband = 11;
		iK = 1.0f / (float)kmax;
		den = 1.0e-8f;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SpecMeterProcessor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SpecMeterProcessor::setActive (TBool state)
{
	if (state)
	{
		if (getSampleRate () > 64000)
			{ topband = 12;  kmax = 4096; }
		else
			{ topband = 11;  kmax = 2048; }
		iK = 1.0f / (float)kmax; 
		Lpeak = Rpeak = Lrms = Rrms = Corr = 0.0f;
		lpeak = rpeak = lrms = rrms = corr = 0.0f;
		Lhold = Rhold = 0.0f;
		Lmin = Rmin = 0.0000001f;
		for(int32 i = 0; i<16; i++) 
		{
			band[0][i] = band[1][i] = 0.0f;
			for(int32 j=0; j<6; j++) lpp[j][i] = rpp[j][i] = 0.0f;
		}
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
bool SpecMeterProcessor::bypassProcessing (ProcessData& data)
{
	if (isBypassed ())
	{
		int32 sampleFrames = data.numSamples;

		if (Lpeak > fabs (den) || Rpeak > fabs (den))
		{
			Lpeak *= 2.f;
			Rpeak *= 2.f;
			Lhold *= 2.f;
			Rhold *= 2.f;

			den = -den;
			float l, r, p, q, iN = iK;
			int32 k=K, j0=topband, mask, j;

			while (--sampleFrames >= 0)
			{
				l = den; //anti-denormal
				r = den;

				lrms += l * l; //RMS integrate
				rrms += r * r;

				p = (float)fabs (l); if (p > lpeak) lpeak = p; //peak detect
				q = (float)fabs (r); if (q > rpeak) rpeak = q;
				/*
				if (p > 1.0e-8f && p < lmin) lmin = p; //'trough' detect
				if (q > 1.0e-8f && q < rmin) rmin = q;
				*/
				if ((l * r) > 0.0f) corr += iN; //measure correlation

				j = j0;
				mask = k << 1;

				do //polyphase filter bank
				{
					p = lpp[0][j] + 0.208f * l;
					lpp[0][j] = lpp[1][j];
					lpp[1][j] = l - 0.208f * p;

					q = lpp[2][j] + lpp[4][j] * 0.682f;
					lpp[2][j] = lpp[3][j];
					lpp[3][j] = lpp[4][j] - 0.682f * q;
					lpp[4][j] = l;
					lpp[5][j] += (float)fabs (p - q); //top octave
					l = p + q;                    //lower octaves

					p = rpp[0][j] + 0.208f * r;
					rpp[0][j] = rpp[1][j];
					rpp[1][j] = r - 0.208f * p;

					q = rpp[2][j] + rpp[4][j] * 0.682f;
					rpp[2][j] = rpp[3][j];
					rpp[3][j] = rpp[4][j] - 0.682f * q;
					rpp[4][j] = r;
					rpp[5][j] += (float)fabs (p - q); //top octave
					r = p + q;                    //lower octaves

					j--;
					mask >>= 1;
				} while (mask & 1);

				if (++k == kmax)
				{
					k = 0;

					if (lpeak == 0.0f) Lpeak = Lrms = 0.0f; else ///add limits here!
					{
						if (lpeak > 2.0f) lpeak = 2.0f;
						if (lpeak >= Lpeak) 
						{
							Lpeak = lpeak;
							Lhold = 2.0f * Lpeak; 
						}
						else 
						{
							Lhold *= 0.95f;
							if (Lhold < Lpeak) Lpeak = Lhold;
						}
						Lmin = lmin;
						lmin *= 1.01f;
						Lrms += 0.2f * (iN * lrms - Lrms);
					}

					if (rpeak == 0.0f) Rpeak = Rrms = 0.0f; else
					{
						if (rpeak > 2.0f) rpeak = 2.0f;
						if (rpeak >= Rpeak) 
						{
							Rpeak = rpeak;
							Rhold = 2.0f * Rpeak; 
						}
						else 
						{
							Rhold *= 0.95f;
							if (Rhold < Rpeak) Rpeak = Rhold;
						}
						Rmin = rmin;
						rmin *= 1.01f;
						Rrms += 0.2f * (iN * rrms - Rrms);
					}

					rpeak = lpeak = lrms = rrms = 0.0f;
					Corr += 0.1f * (corr - Corr); //correlation
					corr = SILENCE;

					float dec = 0.08f;
					for(j=0; j<13; j++) //spectrum output
					{
						band[0][j] += dec * (iN * lpp[5][j] - band[0][j]);
						if (band[0][j] > 2.0f) band[0][j] = 2.0f; 
						//else if (band[0][j] < 0.014f) band[0][j] = 0.014f;

						band[1][j] += dec * (iN * rpp[5][j] - band[1][j]);
						if (band[1][j] > 2.0f) band[1][j] = 2.0f; 
						//else if (band[1][j] < 0.014f) band[1][j] = 0.014f;

						rpp[5][j] = lpp[5][j] = SILENCE;
						dec = dec * 1.1f;
					}
				}
			}
			Lpeak /= 2.f;
			Rpeak /= 2.f;
			Lhold /= 2.f;
			Rhold /= 2.f;

			K = k;
		}
		IParameterChanges* changes = data.outputParameterChanges;
		if (changes)
			sendParameterChanges (changes, data.numSamples);
		data.outputs[0].silenceFlags = data.inputs[0].silenceFlags;
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
void SpecMeterProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* in1 = data.inputs[0].channelBuffers32[0];
	float* in2 = data.inputs[0].channelBuffers32[1];
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	if (in1 != out1)
		memcpy (out1, in1, sampleFrames * sizeof (float));
	if (in2 != out2)
		memcpy (out2, in2, sampleFrames * sizeof (float));

	if (data.inputs[0].silenceFlags & 3 && Lpeak <= fabs (den) && Rpeak <= fabs (den))
	{
		data.outputs[0].silenceFlags = data.inputs[0].silenceFlags;
		return;
	}

	data.outputs[0].silenceFlags = 0;

	Lpeak *= 2.f;
	Rpeak *= 2.f;
	Lhold *= 2.f;
	Rhold *= 2.f;

	den = -den;
	float l, r, p, q, iN = iK;
	int32 k=K, j0=topband, mask, j;

	while (--sampleFrames >= 0)
	{
		l = *in1++;
		r = *in2++;

		l += den; //anti-denormal
		r += den;

		lrms += l * l; //RMS integrate
		rrms += r * r;

		p = (float)fabs (l); if (p > lpeak) lpeak = p; //peak detect
		q = (float)fabs (r); if (q > rpeak) rpeak = q;
		/*
		if (p > 1.0e-8f && p < lmin) lmin = p; //'trough' detect
		if (q > 1.0e-8f && q < rmin) rmin = q;
		*/
		if ((l * r) > 0.0f) corr += iN; //measure correlation

		j = j0;
		mask = k << 1;

		do //polyphase filter bank
		{
			p = lpp[0][j] + 0.208f * l;
			lpp[0][j] = lpp[1][j];
			lpp[1][j] = l - 0.208f * p;

			q = lpp[2][j] + lpp[4][j] * 0.682f;
			lpp[2][j] = lpp[3][j];
			lpp[3][j] = lpp[4][j] - 0.682f * q;
			lpp[4][j] = l;
			lpp[5][j] += (float)fabs (p - q); //top octave
			l = p + q;                    //lower octaves

			p = rpp[0][j] + 0.208f * r;
			rpp[0][j] = rpp[1][j];
			rpp[1][j] = r - 0.208f * p;

			q = rpp[2][j] + rpp[4][j] * 0.682f;
			rpp[2][j] = rpp[3][j];
			rpp[3][j] = rpp[4][j] - 0.682f * q;
			rpp[4][j] = r;
			rpp[5][j] += (float)fabs (p - q); //top octave
			r = p + q;                    //lower octaves

			j--;
			mask >>= 1;
		} while (mask & 1);

		if (++k == kmax)
		{
			k = 0;

			if (lpeak == 0.0f) Lpeak = Lrms = 0.0f; else ///add limits here!
			{
				if (lpeak > 2.0f) lpeak = 2.0f;
				if (lpeak >= Lpeak) 
				{
					Lpeak = lpeak;
					Lhold = 2.0f * Lpeak; 
				}
				else 
				{
					Lhold *= 0.95f;
					if (Lhold < Lpeak) Lpeak = Lhold;
				}
				Lmin = lmin;
				lmin *= 1.01f;
				Lrms += 0.2f * (iN * lrms - Lrms);
			}

			if (rpeak == 0.0f) Rpeak = Rrms = 0.0f; else
			{
				if (rpeak > 2.0f) rpeak = 2.0f;
				if (rpeak >= Rpeak) 
				{
					Rpeak = rpeak;
					Rhold = 2.0f * Rpeak; 
				}
				else 
				{
					Rhold *= 0.95f;
					if (Rhold < Rpeak) Rpeak = Rhold;
				}
				Rmin = rmin;
				rmin *= 1.01f;
				Rrms += 0.2f * (iN * rrms - Rrms);
			}

			rpeak = lpeak = lrms = rrms = 0.0f;
			Corr += 0.1f * (corr - Corr); //correlation
			corr = SILENCE;

			float dec = 0.08f;
			for(j=0; j<13; j++) //spectrum output
			{
				band[0][j] += dec * (iN * lpp[5][j] - band[0][j]);
				if (band[0][j] > 2.0f) band[0][j] = 2.0f; 
				//else if (band[0][j] < 0.014f) band[0][j] = 0.014f;

				band[1][j] += dec * (iN * rpp[5][j] - band[1][j]);
				if (band[1][j] > 2.0f) band[1][j] = 2.0f; 
				//else if (band[1][j] < 0.014f) band[1][j] = 0.014f;

				rpp[5][j] = lpp[5][j] = SILENCE;
				dec = dec * 1.1f;
			}
		}
	}
	Lpeak /= 2.f;
	Rpeak /= 2.f;
	Lhold /= 2.f;
	Rhold /= 2.f;

	K = k;

	IParameterChanges* changes = data.outputParameterChanges;
	if (changes)
		sendParameterChanges (changes, data.numSamples);
}

//-----------------------------------------------------------------------------
void SpecMeterProcessor::sendParameterChanges (IParameterChanges* changes, int32 numSamples)
{
	IParamValueQueue* queue = 0;
	int32 index;
	int32 pid = SpecMeterController::kBandParamStart;
	for (int32 ch = 0; ch < 2; ch++)
	{
		for (int32 bnd = 0; bnd < 13; bnd++, pid++)
		{
			queue = changes->addParameterData (pid, index);
			if (queue)
				queue->addPoint (numSamples, band[ch][bnd], index);
		}
	}
	pid = SpecMeterController::kLeftPeakParam;
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Lpeak, index);
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Lhold, index);
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Lmin, index);
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Lrms, index);

	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Rpeak, index);
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Rhold, index);
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Rmin, index);
	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Rrms, index);

	queue = changes->addParameterData (pid++, index);
	if (queue)
		queue->addPoint (numSamples, Corr, index);
}

}}} // namespaces

