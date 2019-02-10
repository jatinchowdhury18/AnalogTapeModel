//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/note_expression_synth/source/filter.h
// Created by  : Steinberg, 03/2010
// Description : 
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-----------------------------------------------------------------------------
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation 
//     and/or other materials provided with the distribution.
//   * Neither the name of the Steinberg Media Technologies nor the names of its
//     contributors may be used to endorse or promote products derived from this 
//     software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#pragma once

#include <cmath>
#include <algorithm>

#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif

namespace Steinberg {
namespace Vst {
namespace NoteExpressionSynth {

//-----------------------------------------------------------------------------
class Filter
{
public:
	enum Type {
		kLowpass,
		kHighpass,
		kBandpass,
		
		kNumTypes
	};

	Filter (Type type) : type (type), sampleRate (44100.) { reset (); }

	inline void setType (Type t) { type = t; }
	inline void setSampleRate (double sampleRate);
	inline void setFreqAndQ (double frequency, double q);
	
	inline double process (double sample);

	inline void reset ();
protected:
	Type type;

	double sampleRate;
	double invSampleRate;

	double in1;
	double in2;
	double out1;
	double out2;

	double b0a0;
	double b1a0;
	double b2a0;
	double a1a0;
	double a2a0;
};

//-----------------------------------------------------------------------------
void Filter::reset ()
{
	in1 = in2 = out1 = out2 = 0.;
	b0a0 = 1.;
	b1a0 = b2a0 = a1a0 = a2a0 = 0.;
}

//-----------------------------------------------------------------------------
void Filter::setSampleRate (double _sampleRate)
{
	sampleRate = _sampleRate;
	invSampleRate = 1. / _sampleRate;
}

//-----------------------------------------------------------------------------
void Filter::setFreqAndQ (double freq, double q)
{
	static const double M_LOG2 = log (2.0);

	double frequency = std::max<double> (80., freq);
	bool q_is_bandwidth = true;

	// temp coefficient vars
	double alpha = 1.;
	double a0 = 0.;
	double a1 = 0.;
	double a2 = 0.;
	double b0 = 0.;
	double b1 = 0.;
	double b2 = 0.;

	double const omega = 2.0 * M_PI * frequency * invSampleRate;
	double const tsin = sin (omega);
	double const tcos = cos (omega);

	if (type == kBandpass)
	{
		if (q_is_bandwidth)
			alpha = tsin * sinh (M_LOG2 * 0.5 * q * omega / tsin);
		else
			alpha = tsin / (2.0 * q);

		b0=tsin * 0.5;
		b1=0.0;
		b2=-tsin * 0.5;
		a0=1.0+alpha;
		a1=-2.0*tcos;
		a2=1.0-alpha;
	}
	else
	{
		if (q_is_bandwidth)
			alpha = tsin * sinh (M_LOG2 * 0.5 * q * omega / tsin);
		else
			alpha = tsin / (2.0 * q);

		if (type == kLowpass)
		{
			b0=(1.0-tcos) * 0.5;
			b1=1.0-tcos;
			b2=(1.0-tcos) * 0.5;
			a0=1.0+alpha;
			a1=-2.0*tcos;
			a2=1.0-alpha;
		}
		else if (type == kHighpass)
		{
			b0=(1.0+tcos) * 0.5;
			b1=-(1.0+tcos);
			b2=(1.0+tcos) * 0.5;
			a0=1.0+ alpha;
			a1=-2.0*tcos;
			a2=1.0-alpha;
		}
	}
	
	double invA0 = 1.0 / a0;
	b0a0=float(b0 * invA0);
	b1a0=float(b1 * invA0);
	b2a0=float(b2 * invA0);
	a1a0=float(a1 * invA0);
	a2a0=float(a2 * invA0);
}

//-----------------------------------------------------------------------------
double Filter::process (double sample)
{
	double output = b0a0 * sample + b1a0 * in1 + b2a0 * in2 - a1a0 * out1 - a2a0 * out2;
	in2 = in1;
	in1 = sample;
	out2 = out1;
	out1 = output;

	return output;
}

}}} // namespaces
