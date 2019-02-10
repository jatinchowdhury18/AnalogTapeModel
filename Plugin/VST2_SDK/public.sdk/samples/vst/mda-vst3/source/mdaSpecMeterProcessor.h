/*
 *  mdaSpecMeterProcessor.h
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

#ifndef __mdaSpecMeterProcessor__
#define __mdaSpecMeterProcessor__

#include "mdaBaseProcessor.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
class SpecMeterProcessor : public BaseProcessor
{
public:
	SpecMeterProcessor ();
	~SpecMeterProcessor ();
	
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate ();
	tresult PLUGIN_API setActive (TBool state);

	void doProcessing (ProcessData& data);
	bool bypassProcessing (ProcessData& data);

//-----------------------------------------------------------------------------
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new SpecMeterProcessor; }
	static FUID uid;
//-----------------------------------------------------------------------------
protected:
	void recalculate () {}
	void sendParameterChanges (IParameterChanges* changes, int32 numSamples);

	int32  counter;
	float Lpeak, Lhold, Lmin, Lrms, Rpeak, Rhold, Rmin, Rrms, Corr; // #11  #12
	float band[2][16]; //8  16  31  64  125  250  500  1k  2k  4k  8k  16k  32k

	float iK, lpeak, lmin, lrms, rpeak, rmin, rrms, corr, den;
	float lpp[6][16], rpp[6][16];
	int32  topband, K, kmax;
};

}}} // namespaces

#endif
