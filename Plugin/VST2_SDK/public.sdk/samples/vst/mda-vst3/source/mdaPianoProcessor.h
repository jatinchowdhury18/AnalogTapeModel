/*
 *  mdaPianoProcessor.h
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

#ifndef __mdaPianoProcessor__
#define __mdaPianoProcessor__

#include "mdaBaseProcessor.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
class PianoProcessor : public BaseProcessor
{
public:
	PianoProcessor ();
	~PianoProcessor ();
	
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate ();
	tresult PLUGIN_API setActive (TBool state);

	void doProcessing (ProcessData& data);

//-----------------------------------------------------------------------------
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new PianoProcessor; }
	static FUID uid;
//-----------------------------------------------------------------------------

	enum {
		EVENTBUFFER=120,
		EVENTS_DONE=99999999,
		NPARAMS=12,
		NPROGS=8,
		NVOICES=32,
		SUSTAIN=128,
		WAVELEN=586348
	};

	static float programParams[][NPARAMS];

protected:
	void setParameter (ParamID index, ParamValue newValue, int32 sampleOffset);
	void processEvents (IEventList* events);
	void noteOn(int32 note, int32 velocity);
	void recalculate ();
	void allNotesOff ();

	struct VOICE  //voice state
	{
		int32 delta;  //sample playback
		int32 frac;
		int32 pos;
		int32 end;
		int32 loop;

		float env;  //envelope
		float dec;

		float f0;   //first-order LPF
		float f1;
		float ff;

		float outl;
		float outr;
		int32 note; //remember what note triggered this
	};


	struct KGRP  //keygroup
	{
		int32  root;  //MIDI root note
		int32  high;  //highest note
		int32  pos;
		int32  end;
		int32  loop;
	};

	float Fs, iFs;

	int32 notes[EVENTBUFFER + 8];  //list of delta|note|velocity for current block

	///global internal variables
	KGRP  kgrp[16];
	VOICE voice[NVOICES];
	int32 activevoices, poly, cpos;
	short *waves;
	int32 cmax;
	float *comb, cdep, width, trim;
	int32 size, sustain;
	float tune, fine, random, stretch;
	float muff, muffvel, sizevel, velsens, volume;

	int32 eventPos;
};

}}} // namespaces

#endif
