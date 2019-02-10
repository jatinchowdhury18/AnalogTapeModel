/*
 *  mdaJX10Processor.h
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

#ifndef __mdaJX10Processor__
#define __mdaJX10Processor__

#include "mdaBaseProcessor.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
class JX10Processor : public BaseProcessor
{
public:
	JX10Processor ();
	~JX10Processor ();
	
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate ();
	tresult PLUGIN_API setActive (TBool state);

	void doProcessing (ProcessData& data);

	enum {
		kNumPrograms = 52
	};
	
	static float programParams[kNumPrograms][24];

//-----------------------------------------------------------------------------
	static FUnknown* createInstance (void*) { return (IAudioProcessor*)new JX10Processor; }
	static FUID uid;
//-----------------------------------------------------------------------------
protected:
	void processEvents (IEventList* events);
	void recalculate ();
	void noteOn (int32 note, int32 velocity, int32 noteID);
	void setParameter (ParamID index, ParamValue newValue, int32 sampleOffset);

	struct VOICE  //voice state
	{
		float  period;
		float  p;    //sinc position
		float  pmax; //loop length
		float  dp;   //delta
		float  sin0; //sine osc
		float  sin1;
		float  sinx;
		float  dc;   //dc offset

		float  detune;
		float  p2;    //sinc position
		float  pmax2; //loop length
		float  dp2;   //delta
		float  sin02; //sine osc
		float  sin12;
		float  sinx2;
		float  dc2;   //dc offset

		float  fc;  //filter cutoff root
		float  ff;  //filter cutoff
		float  f0;  //filter buffers
		float  f1;
		float  f2;

		float  saw;
		//float  vca;  //current level  ///eliminate osc1 level when separate amp & filter envs?
		//float  env;  //envelope
		//float  att;  //attack
		//float  dec;  //decay
		float  env;
		float  envd;
		float  envl;
		float  fenv;
		float  fenvd;
		float  fenvl;

		float  lev;  //osc levels
		float  lev2;
		float  target; //period target
		int32  note; //remember what note triggered this
		int32 noteID;	// SNA addition
		float snaPitchbend;// SNA addition
		float snaVolume;// SNA addition
		float snaPanLeft;	// SNA addition
		float snaPanRight;	// SNA addition
	};

	enum {
		EVENTBUFFER = 160,
		EVENTS_DONE = 99999999,
		KMAX = 32,
		SUSTAIN = -1,
		NVOICES = 8
	};

	int32 notes[EVENTBUFFER + 8];  //list of delta|note|velocity for current block

	///global internal variables
	int32 sustain, activevoices;
	VOICE voice[NVOICES];

	float semi, cent;
	float tune, detune;
	float filtf, fzip, filtq, filtlfo, filtenv, filtvel, filtwhl;
	float oscmix, noisemix;
	float att, dec, sus, rel, fatt, fdec, fsus, frel;
	float lfo, dlfo, modwhl, press, pbend, ipbend, rezwhl;
	float velsens, volume, voltrim;
	float vibrato, pwmdep, lfoHz, glide, glidedisp;
	int32  K, lastnote, veloff, mode;
	Steinberg::uint32 noise;
};

}}} // namespaces

#endif
