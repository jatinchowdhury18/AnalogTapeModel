//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/common/logscale.h
// Created by  : Steinberg, 10/2010
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

#include "pluginterfaces/base/ftypes.h"
#include "pluginterfaces/base/ustring.h"
#include "public.sdk/source/vst/vstparameters.h"
#include <cmath>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
/** LogScale class.
Scales [srcMin srcMax] to [destMin destMax]

Scaling curve is defined by given outValue for given inValue

\subsection example1 Example for stretched lower range
LogScale myLogScale (0, 1, 0, 1, 0.5, 0.1); \n
means: input and output ranges are the same, but myLogScale.scale (0.5) is 0.1 ([0, 0.5, 1] => [0, 0.1, 1])

\subsection example2 Example for compressed lower range
LogScale myLogScale (0, 1, 0, 1, 0.5, 0.9); \n
means: input and output ranges are the same, but myLogScale.scale (0.5) is 0.9 ([0, 0.5, 1] => [0, 0.9, 1])

\subsection example3 Example for filter frequency range
LogScale myLogScale (0, 1, 80, 22000, 0.5, 2000); \n
means: input range is between 0 and 1 and output range is between 80 and 22000 and myLogScale.scale (0.5) is 2000 
([0, 0.5, 1] => [80, 2000, 22000])
*/
//-----------------------------------------------------------------------------
template <class T>
class LogScale 
{
public:
	/** Constructor. */
	LogScale (T srcMin, T srcMax, T destMin, T destMax, T inValue=0.5, T outValue=0.1);
	/** Default Constructor with [0, 0.5, 1] => [0, 0.1, 1]. */
	LogScale ();
	
	/** Applies a new scale setting. Note that destMin should be different than destMax! The same for srcMin and srcMax. */
	void changeScaling (T srcMin, T srcMax, T destMin, T destMax, T inValue, T outValue);

	/** Computes the scale from pIn input buffer to pOut output buffer (pIn and POut could be the same buffer). */
	void scale (T* pIn, T* pOut, int32 nSamples);
	/** Computes for one given value the scale. */
	T scale (T input) const;

	/** Computes the inverse scale from pIn input buffer to pOut output buffer (pIn and POut could be the same buffer). */
	void invscale (T* pIn, T* pOut, int32 nSamples);
	/** Computes for one given value the inverse scale. */
	T invscale (T input) const;
	/** Same than invscale with a check of the input. */
	T invscaleCheck (T in) const;

protected:

	void setScaling (T srcMin, T srcMax, T destMin, T destMax, T inValue, T outValue);
	T scaleFactor;
	T scaleFactorInv;
	T srcScale;
	T srcScaleInv;
	T srcMin;
	T expo;
	T expoInv;
	T destMin;
};

//-----------------------------------------------------------------------------
template <class T>
LogScale<T>::LogScale (T srcMin, T srcMax, T destMin, T destMax, T inValue, T outValue)
{
	setScaling (srcMin, srcMax, destMin, destMax, inValue, outValue);
}

//-----------------------------------------------------------------------------
template <class T>
LogScale<T>::LogScale ()
{
	setScaling (0.f, 1.f, 0.f, 1.f, 0.5f, 0.1f);
}

//-----------------------------------------------------------------------------
template <class T>
void LogScale<T>::changeScaling (T srcMin, T srcMax, T destMin, T destMax, T inValue, T outValue)
{
	setScaling (srcMin, srcMax, destMin, destMax, inValue, outValue);
}

//-----------------------------------------------------------------------------
template <class T>
void LogScale<T>::setScaling (T srcMin, T srcMax, T destMin, T destMax, T inValue, T outValue)
{
	this->srcMin = srcMin;
	this->destMin = destMin;
	
	scaleFactor = (destMax - destMin);
	scaleFactorInv = 1.f / scaleFactor;

	inValue = (inValue - srcMin) / (srcMax - srcMin);

	ASSERT (inValue > 0.);

	expo = ::log ((outValue - destMin) / scaleFactor) / ::log (inValue);
	expoInv = 1.f / expo;

	srcScale = (srcMax - srcMin);
	srcScaleInv = 1.f / srcScale;
}

//-----------------------------------------------------------------------------
template <class T>
void LogScale<T>::scale (T* pIn, T* pOut, int32 nSamples)
{
	int32 i;
	for (i = 0; i < nSamples; i++)
		pOut[i] = ::powf ((float)((pIn[i] - srcMin) * srcScaleInv), (float)expo) * scaleFactor + destMin;
}

//-----------------------------------------------------------------------------
template <class T>
T LogScale<T>::scale (T input) const
{
	return ::powf ((float)((input - srcMin) * srcScaleInv), (float)expo) * scaleFactor + destMin;
}

//-----------------------------------------------------------------------------
template <class T>
void LogScale<T>::invscale (T* pIn, T* pOut, int32 nSamples)
{
	int32 i;
	for (i = 0; i < nSamples; i++)
		pOut[i] = ::powf ((float)((pIn[i] - destMin) * scaleFactorInv), (float)expoInv) * srcScale + srcMin;
}

//-----------------------------------------------------------------------------
template <class T>
T LogScale<T>::invscale (T input) const
{
	return ::powf ((float)((input - destMin) * scaleFactorInv), (float)expoInv) * srcScale + srcMin;
}

//-----------------------------------------------------------------------------
template <class T>
T LogScale<T>::invscaleCheck (T input) const
{
	T basis = (float)((input - destMin) * scaleFactorInv);
	
	if (basis < 0.)
		basis = 0.;

	return ::powf ((float)basis, (float)expoInv) * srcScale + srcMin;
}

//-----------------------------------------------------------------------------
/** Parameter class with a LogScale.
Define a parameter using the LogScale.

\sa Steinberg::Vst::LogScale
*/
//-----------------------------------------------------------------------------
template <class T>
class LogScaleParameter : public Parameter
{
public:
	LogScaleParameter (const TChar* title, ParamID tag, LogScale<T>& logScale, const TChar* units = 0, int32 flags = ParameterInfo::kCanAutomate, UnitID unitID = kRootUnitId)
	: Parameter (title, tag, units, 0., 0, flags, unitID)
	, logScale (logScale)
	{
	}
	
	virtual void toString (ParamValue _valueNormalized, String128 string) const
	{
		UString128 wrapper;
		wrapper.printFloat (toPlain (_valueNormalized), precision);
		wrapper.copyTo (string, 128);
	}
	
	virtual bool fromString (const TChar* string, ParamValue& _valueNormalized) const
	{
		UString wrapper ((TChar*)string, strlen16 (string));
		if (wrapper.scanFloat (_valueNormalized))
		{
			_valueNormalized = toNormalized (_valueNormalized);
			return true;
		}
		return false;
	}
	
	virtual ParamValue toPlain (ParamValue _valueNormalized) const
	{
		return logScale.scale (_valueNormalized);
	}
	
	virtual ParamValue toNormalized (ParamValue plainValue) const
	{
		return logScale.invscale (plainValue);
	}

	OBJ_METHODS (LogScaleParameter<T>, Parameter)
protected:
	LogScale<T>& logScale;
	ParamValue multiplier;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
