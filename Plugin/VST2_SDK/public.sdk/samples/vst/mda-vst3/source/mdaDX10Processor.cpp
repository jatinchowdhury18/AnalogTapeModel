/*
 *  mdaDX10Processor.cpp
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

#include "mdaDX10Processor.h"
#include "mdaDX10Controller.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

#define NOUTS    2       //number of outputs
#define SILENCE 0.0003f  //voice choking

float DX10Processor::programParams[][NPARAMS] = { 
	{0.000f, 0.650f, 0.441f, 0.842f, 0.329f, 0.230f, 0.800f, 0.050f, 0.800f, 0.900f, 0.000f, 0.500f, 0.500f, 0.447f, 0.000f, 0.414f },
	{0.000f, 0.500f, 0.100f, 0.671f, 0.000f, 0.441f, 0.336f, 0.243f, 0.800f, 0.500f, 0.000f, 0.500f, 0.500f, 0.178f, 0.000f, 0.500f },
	{0.000f, 0.700f, 0.400f, 0.230f, 0.184f, 0.270f, 0.474f, 0.224f, 0.800f, 0.974f, 0.250f, 0.500f, 0.500f, 0.428f, 0.836f, 0.500f },
	{0.000f, 0.700f, 0.400f, 0.320f, 0.217f, 0.599f, 0.670f, 0.309f, 0.800f, 0.500f, 0.263f, 0.507f, 0.500f, 0.276f, 0.638f, 0.526f },
	{0.400f, 0.600f, 0.650f, 0.760f, 0.000f, 0.390f, 0.250f, 0.160f, 0.900f, 0.500f, 0.362f, 0.500f, 0.500f, 0.401f, 0.296f, 0.493f },
	{0.000f, 0.342f, 0.000f, 0.280f, 0.000f, 0.880f, 0.100f, 0.408f, 0.740f, 0.000f, 0.000f, 0.600f, 0.500f, 0.842f, 0.651f, 0.500f },
	{0.000f, 0.400f, 0.100f, 0.360f, 0.000f, 0.875f, 0.160f, 0.592f, 0.800f, 0.500f, 0.000f, 0.500f, 0.500f, 0.303f, 0.868f, 0.500f },
	{0.000f, 0.500f, 0.704f, 0.230f, 0.000f, 0.151f, 0.750f, 0.493f, 0.770f, 0.500f, 0.000f, 0.400f, 0.500f, 0.421f, 0.632f, 0.500f },
	{0.600f, 0.990f, 0.400f, 0.320f, 0.283f, 0.570f, 0.300f, 0.050f, 0.240f, 0.500f, 0.138f, 0.500f, 0.500f, 0.283f, 0.822f, 0.500f },
	{0.000f, 0.500f, 0.650f, 0.368f, 0.651f, 0.395f, 0.550f, 0.257f, 0.900f, 0.500f, 0.300f, 0.800f, 0.500f, 0.000f, 0.414f, 0.500f },
	{0.000f, 0.700f, 0.520f, 0.230f, 0.197f, 0.520f, 0.720f, 0.280f, 0.730f, 0.500f, 0.250f, 0.500f, 0.500f, 0.336f, 0.428f, 0.500f },
	{0.000f, 0.240f, 0.000f, 0.390f, 0.000f, 0.880f, 0.100f, 0.600f, 0.740f, 0.500f, 0.000f, 0.500f, 0.500f, 0.526f, 0.480f, 0.500f },
	{0.000f, 0.500f, 0.700f, 0.160f, 0.000f, 0.158f, 0.349f, 0.000f, 0.280f, 0.900f, 0.000f, 0.618f, 0.500f, 0.401f, 0.000f, 0.500f },
	{0.000f, 0.500f, 0.100f, 0.390f, 0.000f, 0.490f, 0.250f, 0.250f, 0.800f, 0.500f, 0.000f, 0.500f, 0.500f, 0.263f, 0.145f, 0.500f },
	{0.000f, 0.300f, 0.507f, 0.480f, 0.730f, 0.000f, 0.100f, 0.303f, 0.730f, 1.000f, 0.000f, 0.600f, 0.500f, 0.579f, 0.000f, 0.500f },
	{0.000f, 0.300f, 0.500f, 0.320f, 0.000f, 0.467f, 0.079f, 0.158f, 0.500f, 0.500f, 0.000f, 0.400f, 0.500f, 0.151f, 0.020f, 0.500f },
	{0.000f, 0.990f, 0.100f, 0.230f, 0.000f, 0.000f, 0.200f, 0.450f, 0.800f, 0.000f, 0.112f, 0.600f, 0.500f, 0.711f, 0.000f, 0.401f },
	{0.280f, 0.990f, 0.280f, 0.230f, 0.000f, 0.180f, 0.400f, 0.300f, 0.800f, 0.500f, 0.000f, 0.400f, 0.500f, 0.217f, 0.480f, 0.500f },
	{0.220f, 0.990f, 0.250f, 0.170f, 0.000f, 0.240f, 0.310f, 0.257f, 0.900f, 0.757f, 0.000f, 0.500f, 0.500f, 0.697f, 0.803f, 0.500f },
	{0.220f, 0.990f, 0.250f, 0.450f, 0.070f, 0.240f, 0.310f, 0.360f, 0.900f, 0.500f, 0.211f, 0.500f, 0.500f, 0.184f, 0.000f, 0.414f },
	{0.697f, 0.990f, 0.421f, 0.230f, 0.138f, 0.750f, 0.390f, 0.513f, 0.800f, 0.316f, 0.467f, 0.678f, 0.500f, 0.743f, 0.757f, 0.487f },
	{0.000f, 0.400f, 0.000f, 0.280f, 0.125f, 0.474f, 0.250f, 0.100f, 0.500f, 0.500f, 0.000f, 0.400f, 0.500f, 0.579f, 0.592f, 0.500f },
	{0.230f, 0.500f, 0.100f, 0.395f, 0.000f, 0.388f, 0.092f, 0.250f, 0.150f, 0.500f, 0.200f, 0.200f, 0.500f, 0.178f, 0.822f, 0.500f },
	{0.000f, 0.600f, 0.400f, 0.230f, 0.000f, 0.450f, 0.320f, 0.050f, 0.900f, 0.500f, 0.000f, 0.200f, 0.500f, 0.520f, 0.105f, 0.500f },
	{0.000f, 0.600f, 0.400f, 0.170f, 0.145f, 0.290f, 0.350f, 0.100f, 0.900f, 0.500f, 0.000f, 0.400f, 0.500f, 0.441f, 0.309f, 0.500f },
	{0.000f, 0.600f, 0.490f, 0.170f, 0.151f, 0.099f, 0.400f, 0.000f, 0.900f, 0.500f, 0.000f, 0.400f, 0.500f, 0.118f, 0.013f, 0.500f },
	{0.000f, 0.600f, 0.100f, 0.320f, 0.000f, 0.350f, 0.670f, 0.100f, 0.150f, 0.500f, 0.000f, 0.200f, 0.500f, 0.303f, 0.730f, 0.500f },
	{0.300f, 0.500f, 0.400f, 0.280f, 0.000f, 0.180f, 0.540f, 0.000f, 0.700f, 0.500f, 0.000f, 0.400f, 0.500f, 0.296f, 0.033f, 0.500f },
	{0.300f, 0.500f, 0.400f, 0.360f, 0.000f, 0.461f, 0.070f, 0.070f, 0.700f, 0.500f, 0.000f, 0.400f, 0.500f, 0.546f, 0.467f, 0.500f },
	{0.000f, 0.500f, 0.500f, 0.280f, 0.000f, 0.330f, 0.200f, 0.000f, 0.700f, 0.500f, 0.000f, 0.500f, 0.500f, 0.151f, 0.079f, 0.500f },
	{0.000f, 0.500f, 0.000f, 0.000f, 0.240f, 0.580f, 0.630f, 0.000f, 0.000f, 0.500f, 0.000f, 0.600f, 0.500f, 0.816f, 0.243f, 0.500f },
	{0.000f, 0.355f, 0.350f, 0.000f, 0.105f, 0.000f, 0.000f, 0.200f, 0.500f, 0.500f, 0.000f, 0.645f, 0.500f, 1.000f, 0.296f, 0.500f }
};

//-----------------------------------------------------------------------------
FUID DX10Processor::uid (0xF8713648, 0xE2444174, 0x8AAA3B62, 0xA77F9E2D);

//-----------------------------------------------------------------------------
DX10Processor::DX10Processor ()
{
	setControllerClass (DX10Controller::uid);
	allocParameters (NPARAMS);
}

//-----------------------------------------------------------------------------
DX10Processor::~DX10Processor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DX10Processor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addEventInput (USTRING("MIDI in"), 1);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		const float initParams[] = { 0.000f, 0.650f, 0.441f, 0.842f, 0.329f, 0.230f, 0.800f, 0.050f, 0.800f, 0.900f, 0.000f, 0.500f, 0.500f, 0.447f, 0.000f, 0.414f};
		for (int32 i = 0; i < NPARAMS; i++)
			params[i] = initParams[i];

		//initialise...
		for(int32 i = 0; i<NVOICES; i++) 
		{
			memset (&voice[i], 0, sizeof (VOICE));
			voice[i].env = 0.0f;
			voice[i].car = voice[i].dcar = 0.0f;
			voice[i].mod0 = voice[i].mod1 = voice[i].dmod = 0.0f;
			voice[i].cdec = 0.99f; //all notes off
		}
		notes[0] = EVENTS_DONE;
		lfo0 = dlfo = modwhl = 0.0f;
		lfo1 = pbend = 1.0f;
		volume = 0.0035f;
		sustain = activevoices = 0;
		K = 0;

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DX10Processor::terminate ()
{
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API DX10Processor::setActive (TBool state)
{
	if (state)
	{
		lfo0 = 0.0f;
		lfo1 = 1.0f; //reset LFO phase
	}
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void DX10Processor::setParameter (ParamID index, ParamValue newValue, int32 sampleOffset)
{
	if (index < NPARAMS)
		BaseProcessor::setParameter (index, newValue, sampleOffset);
	else if (index == BaseController::kPresetParam) // program change
	{
		int32 program = std::min<int32> (NPROGS, (int32)(newValue * (NPROGS+1)));
		const float* newParams = programParams[program];
		if (newParams)
		{
			for (int32 i = 0; i < NPARAMS; i++)
				params[i] = newParams[i];
		}
	}
	else if (index == BaseController::kModWheelParam) // mod wheel
	{
		newValue *= 127.;
		modwhl = 0.00000005f * (float)(newValue * newValue);
	}
	else if (index == BaseController::kPitchBendParam) // pitch bend
	{
		if (newValue <= 1)
			pbend = (newValue - 0.5) * 0x2000;
		else
			pbend = newValue;
        if (pbend>0.0f) pbend = 1.0f + 0.000014951f * pbend; 
                  else pbend = 1.0f + 0.000013318f * pbend; 
	}
}

//-----------------------------------------------------------------------------
void DX10Processor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* out1 = data.outputs[0].channelBuffers32[0];
	float* out2 = data.outputs[0].channelBuffers32[1];

	int32 event=0, frame=0, frames, v;
	float o, x, e, mw=MW, w=rich, m = modmix;
	int32 k=K;

	if (activevoices>0 || notes[event]<sampleFrames) //detect & bypass completely empty blocks
	{    
		while (frame<sampleFrames)  
		{
			frames = notes[event++];
			if (frames>sampleFrames) frames = sampleFrames;
			frames -= frame;
			frame += frames;

			while (--frames>=0)  //would be faster with voice loop outside frame loop!
			{                   //but then each voice would need it's own LFO...
				VOICE *V = voice;
				o = 0.0f;

				if (--k<0)
				{
					lfo0 += dlfo * lfo1; //sine LFO
					lfo1 -= dlfo * lfo0;
					mw = lfo1 * (modwhl + vibrato);
					k=100;
				}

				for(v=0; v<NVOICES; v++) //for each voice
				{
					e = V->env;
					if (e > SILENCE) //**** this is the synth ****
					{
						V->env = e * V->cdec; //decay & release
						V->cenv += V->catt * (e - V->cenv); //attack

						x = V->dmod * V->mod0 - V->mod1; //could add more modulator blocks like
						V->mod1 = V->mod0;               //this for a wider range of FM sounds
						V->mod0 = x;    
						V->menv += V->mdec * (V->mlev - V->menv);

						x = V->car + V->dcar + x * V->menv + mw; //carrier phase
						while (x >  1.0f) x -= 2.0f;  //wrap phase
						while (x < -1.0f) x += 2.0f;
						V->car = x;
						o += V->cenv * (m * V->mod1 + (x + x * x * x * (w * x * x - 1.0f - w))); 
					}      //amp env //mod thru-mix //5th-order sine approximation

					///  xx = x * x;
					///  x + x + x * xx * (xx - 3.0f);

					V++;
				}
				*out1++ = o;
				*out2++ = o;
			}

			if (frame<sampleFrames) //next note on/off
			{
				int32 note = notes[event++];
				int32 vel  = notes[event++];
				noteOn(note, vel);
			}
		}

		activevoices = NVOICES;
		for(v=0; v<NVOICES; v++)
		{
			if (voice[v].env < SILENCE)  //choke voices that have finished
			{
				voice[v].env = voice[v].cenv = 0.0f;
				activevoices--;
			}
			if (voice[v].menv < SILENCE) voice[v].menv = voice[v].mlev = 0.0f;
		}
	}
	else //completely empty block
	{
		while (--sampleFrames >= 0)
		{
			*out1++ = 0.0f;
			*out2++ = 0.0f;
		}
		data.outputs[0].silenceFlags = 3;
	}
	K=k; MW=mw; //remember these so vibrato speed not buffer size dependant!
	notes[0] = EVENTS_DONE;
}

//-----------------------------------------------------------------------------
void DX10Processor::processEvents (IEventList* events)
{
	if (events)
	{
		int32 npos=0;
		int32 count = events->getEventCount ();
		for (int32 i = 0; i < count; i++)
		{
			Event e;
			events->getEvent (i, e);
			switch (e.type)
			{
				case Event::kNoteOnEvent:
				{
					notes[npos++] = e.sampleOffset;
					notes[npos++] = e.noteOn.pitch;
					notes[npos++] = e.noteOn.velocity * 127;
					break;
				}
				case Event::kNoteOffEvent:
				{
					notes[npos++] = e.sampleOffset;
					notes[npos++] = e.noteOff.pitch;
					notes[npos++] = 0;
					break;
				}
				default:
					continue;
			}
			if (npos > EVENTBUFFER) npos -= 3; //discard events if buffer full!!
		}
		notes[npos] = EVENTS_DONE;
	}
}

//-----------------------------------------------------------------------------
void DX10Processor::noteOn(int32 note, int32 velocity)
{
	float l = 1.0f;
	int32  v, vl=0;

	if (velocity>0) 
	{
		for(v=0; v<NVOICES; v++)  //find quietest voice
		{
			if (voice[v].env<l) { l=voice[v].env;  vl=v; }
		}

		l = (float)exp (0.05776226505f * ((float)note + params[12] + params[12] - 1.0f));
		voice[vl].note = note;                         //fine tuning
		voice[vl].car  = 0.0f;
		voice[vl].dcar = tune * pbend * l; //pitch bend not updated during note as a bit tricky...

		if (l>50.0f) l = 50.0f; //key tracking
		l *= (64.0f + velsens * (velocity - 64)); //vel sens
		voice[vl].menv = depth * l;
		voice[vl].mlev = dept2 * l;
		voice[vl].mdec = mdec;

		voice[vl].dmod = ratio * voice[vl].dcar; //sine oscillator
		voice[vl].mod0 = 0.0f;
		voice[vl].mod1 = (float)sin(voice[vl].dmod); 
		voice[vl].dmod = 2.0f * (float)cos(voice[vl].dmod);
		//scale volume with richness
		voice[vl].env  = (1.5f - params[13]) * volume * (velocity + 10);
		voice[vl].catt = catt;
		voice[vl].cenv = 0.0f;
		voice[vl].cdec = cdec;
	}
	else //note off
	{
		for(v=0; v<NVOICES; v++) if (voice[v].note==note) //any voices playing that note?
		{
			if (sustain==0)
			{
				voice[v].cdec = crel; //release phase
				voice[v].env  = voice[v].cenv;
				voice[v].catt = 1.0f;
				voice[v].mlev = 0.0f;
				voice[v].mdec = mrel;
			}
			else voice[v].note = SUSTAIN;
		}
	}
}

//-----------------------------------------------------------------------------
void DX10Processor::recalculate ()
{
	float ifs = 1.0f / (float)getSampleRate ();

	tune = (float)(8.175798915644 * ifs * pow (2.0, floor(params[11] * 6.9) - 2.0));

	rati = params[3];
	rati = (float)floor(40.1f * rati * rati);
	if (params[4]<0.5f) 
		ratf = 0.2f * params[4] * params[4];
	else 
		switch ((int32)(8.9f * params[4]))
		{
			case  4: ratf = 0.25f;       break;
			case  5: ratf = 0.33333333f; break;
			case  6: ratf = 0.50f;       break;
			case  7: ratf = 0.66666667f; break;
			default: ratf = 0.75f;
		}
	ratio = 1.570796326795f * (rati + ratf);

	depth = 0.0002f * params[5] * params[5];
	dept2 = 0.0002f * params[7] * params[7];

	velsens = params[9];
	vibrato = 0.001f * params[10] * params[10];

	catt = 1.0f - (float)exp (-ifs * exp (8.0 - 8.0 * params[0]));
	if (params[1]>0.98f) cdec = 1.0f; else 
	cdec =        (float)exp (-ifs * exp (5.0 - 8.0 * params[1]));
	crel =        (float)exp (-ifs * exp (5.0 - 5.0 * params[2]));
	mdec = 1.0f - (float)exp (-ifs * exp (6.0 - 7.0 * params[6]));
	mrel = 1.0f - (float)exp (-ifs * exp (5.0 - 8.0 * params[8]));

	rich = 0.50f - 3.0f * params[13] * params[13];
	//rich = -1.0f + 2 * params[13];
	modmix = 0.25f * params[14] * params[14];
	dlfo = 628.3f * ifs * 25.0f * params[15] * params[15]; //these params not in original DX10
}

}}} // namespaces

