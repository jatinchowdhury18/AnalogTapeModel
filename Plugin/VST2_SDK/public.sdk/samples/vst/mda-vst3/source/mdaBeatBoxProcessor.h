/*
 *  mdaBeatBoxProcessor.h
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

#ifndef __mdaBeatBoxProcessor__
#define __mdaBeatBoxProcessor__

#include "mdaBaseProcessor.h"

namespace Steinberg {
namespace Vst {
namespace mda {

class BeatBoxProcessor : public BaseProcessor
{
public:
	BeatBoxProcessor ();
	
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API setActive (TBool state);

	void doProcessing (ProcessData& data);

//-----------------------------------------------------------------------------
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new BeatBoxProcessor; }
	static FUID uid;
//-----------------------------------------------------------------------------
protected:
	void recalculate ();

	float hthr, hfil, sthr, kthr, kfil1, kfil2, mix;
	float klev, hlev, slev;
	float ww, wwx, sb1, sb2, sf1, sf2, sf3;
	float kww, kwwx, ksb1, ksb2, ksf1, ksf2;
	float dyne, dyna, dynr, dynm;

	float *hbuf;
	float *kbuf;
	float *sbuf, *sbuf2;
	int32 hbuflen, hbufpos, hdel;
	int32 sbuflen, sbufpos, sdel, sfx;
	int32 kbuflen, kbufpos, kdel, ksfx;
	int32 rec, recx, recpos;
};

}}} // namespaces

#endif
