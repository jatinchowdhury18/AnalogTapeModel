/*
 *  mdaPianoProcessor.cpp
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

#include "mdaPianoProcessor.h"
#include "mdaPianoController.h"
#include "mdaPianoData.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

#define SILENCE 0.0001f  //voice choking

//-----------------------------------------------------------------------------
FUID PianoProcessor::uid (0xA77EA27C, 0x1F184322, 0xBBD2AD93, 0x73A2B7A0);

//-----------------------------------------------------------------------------
float PianoProcessor::programParams[][NPARAMS] = { 
	{0.500f, 0.500f, 0.500f, 0.5f, 0.803f, 0.251f, 0.376f, 0.500f, 0.330f, 0.500f, 0.246f, 0.500f},
	{0.500f, 0.500f, 0.500f, 0.5f, 0.751f, 0.000f, 0.452f, 0.000f, 0.000f, 0.500f, 0.000f, 0.500f},
	{0.902f, 0.399f, 0.623f, 0.5f, 1.000f, 0.331f, 0.299f, 0.499f, 0.330f, 0.500f, 0.000f, 0.500f},
	{0.399f, 0.251f, 1.000f, 0.5f, 0.672f, 0.124f, 0.127f, 0.249f, 0.330f, 0.500f, 0.283f, 0.667f},
	{0.648f, 0.500f, 0.500f, 0.5f, 0.298f, 0.602f, 0.550f, 0.850f, 0.356f, 0.500f, 0.339f, 0.660f},
	{0.500f, 0.602f, 0.000f, 0.5f, 0.304f, 0.200f, 0.336f, 0.651f, 0.330f, 0.500f, 0.317f, 0.500f},
	{0.450f, 0.598f, 0.626f, 0.5f, 0.603f, 0.500f, 0.174f, 0.331f, 0.330f, 0.500f, 0.421f, 0.801f},
	{0.050f, 0.957f, 0.500f, 0.5f, 0.299f, 1.000f, 0.000f, 0.500f, 0.330f, 0.450f, 0.718f, 0.000f},
};

//-----------------------------------------------------------------------------
PianoProcessor::PianoProcessor ()
{
	setControllerClass (PianoController::uid);
	allocParameters (NPARAMS);
}

//-----------------------------------------------------------------------------
PianoProcessor::~PianoProcessor ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoProcessor::initialize (FUnknown* context)
{
	tresult res = BaseProcessor::initialize (context);
	if (res == kResultTrue)
	{
		addEventInput (USTRING("MIDI in"), 1);
		addAudioOutput (USTRING("Stereo Out"), SpeakerArr::kStereo);

		Fs = 44100.0f;  iFs = 1.0f/Fs;  cmax = 0x7F;  //just in case...

		waves = pianoData;

		//Waveform data and keymapping is hard-wired in *this* version
		kgrp[ 0].root = 36;  kgrp[ 0].high = 37;  kgrp[ 0].pos = 0;       kgrp[ 0].end = 36275;   kgrp[ 0].loop = 14774;
		kgrp[ 1].root = 40;  kgrp[ 1].high = 41;  kgrp[ 1].pos = 36278;   kgrp[ 1].end = 83135;   kgrp[ 1].loop = 16268;
		kgrp[ 2].root = 43;  kgrp[ 2].high = 45;  kgrp[ 2].pos = 83137;   kgrp[ 2].end = 146756;  kgrp[ 2].loop = 33541;
		kgrp[ 3].root = 48;  kgrp[ 3].high = 49;  kgrp[ 3].pos = 146758;  kgrp[ 3].end = 204997;  kgrp[ 3].loop = 21156;
		kgrp[ 4].root = 52;  kgrp[ 4].high = 53;  kgrp[ 4].pos = 204999;  kgrp[ 4].end = 244908;  kgrp[ 4].loop = 17191;
		kgrp[ 5].root = 55;  kgrp[ 5].high = 57;  kgrp[ 5].pos = 244910;  kgrp[ 5].end = 290978;  kgrp[ 5].loop = 23286;
		kgrp[ 6].root = 60;  kgrp[ 6].high = 61;  kgrp[ 6].pos = 290980;  kgrp[ 6].end = 342948;  kgrp[ 6].loop = 18002;
		kgrp[ 7].root = 64;  kgrp[ 7].high = 65;  kgrp[ 7].pos = 342950;  kgrp[ 7].end = 391750;  kgrp[ 7].loop = 19746;
		kgrp[ 8].root = 67;  kgrp[ 8].high = 69;  kgrp[ 8].pos = 391752;  kgrp[ 8].end = 436915;  kgrp[ 8].loop = 22253;
		kgrp[ 9].root = 72;  kgrp[ 9].high = 73;  kgrp[ 9].pos = 436917;  kgrp[ 9].end = 468807;  kgrp[ 9].loop = 8852;
		kgrp[10].root = 76;  kgrp[10].high = 77;  kgrp[10].pos = 468809;  kgrp[10].end = 492772;  kgrp[10].loop = 9693;
		kgrp[11].root = 79;  kgrp[11].high = 81;  kgrp[11].pos = 492774;  kgrp[11].end = 532293;  kgrp[11].loop = 10596;
		kgrp[12].root = 84;  kgrp[12].high = 85;  kgrp[12].pos = 532295;  kgrp[12].end = 560192;  kgrp[12].loop = 6011;
		kgrp[13].root = 88;  kgrp[13].high = 89;  kgrp[13].pos = 560194;  kgrp[13].end = 574121;  kgrp[13].loop = 3414;
		kgrp[14].root = 93;  kgrp[14].high = 999; kgrp[14].pos = 574123;  kgrp[14].end = 586343;  kgrp[14].loop = 2399;

		//initialise...
		for(int32 v=0; v<NVOICES; v++) 
		{
			memset (&voice[v], 0, sizeof (VOICE));
			voice[v].env = 0.0f;
			voice[v].dec = 0.99f; //all notes off
		}
		notes[0] = EVENTS_DONE;
		volume = 0.2f;
		muff = 160.0f;
		cpos = sustain = activevoices = 0;
		comb = new float[256];

		for (int32 i = 0; i < NPARAMS; i++)
			params[i] = programParams[0][i];

		recalculate ();
	}
	return res;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoProcessor::terminate ()
{
	if (comb) delete[] comb;
	comb = 0;
	return BaseProcessor::terminate ();
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PianoProcessor::setActive (TBool state)
{
	if (state)
	{
		Fs = getSampleRate ();
		iFs = 1.0f / Fs;
		if (Fs > 64000.0f) cmax = 0xFF; else cmax = 0x7F;
		memset (comb, 0, sizeof (float) * 256);
		eventPos = 0;
		notes[0] = EVENTS_DONE;
	}
	else
		allNotesOff ();
	return BaseProcessor::setActive (state);
}

//-----------------------------------------------------------------------------
void PianoProcessor::setParameter (ParamID index, ParamValue newValue, int32 sampleOffset)
{
	if (index < NPARAMS)
		BaseProcessor::setParameter (index, newValue, sampleOffset);
	else if (index == BaseController::kPresetParam) // program change
	{
		int32 program = std::min<int32> (NPROGS-1, newValue * NPROGS);
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
		muff = 0.01f * (float)((127 - newValue) * (127 - newValue));
	}
	else if (index == BaseController::kSustainParam)
	{
		sustain = newValue > 0.5;
		if (sustain==0)
		{
			notes[eventPos++] = 0; // was: event->deltaFrames;
			notes[eventPos++] = SUSTAIN; //end all sustained notes
			notes[eventPos++] = 0;
			notes[eventPos++] = EVENTS_DONE;
		}
	}
}

//-----------------------------------------------------------------------------
void PianoProcessor::doProcessing (ProcessData& data)
{
	int32 sampleFrames = data.numSamples;
	
	float* out0 = data.outputs[0].channelBuffers32[0];
	float* out1 = data.outputs[0].channelBuffers32[1];

	int32 event=0, frame=0, frames, v;
	float x, l, r;
	int32 i;

	while (frame<sampleFrames)
	{
		frames = notes[event++];
		if (frames>sampleFrames) frames = sampleFrames;
		frames -= frame;
		frame += frames;

		while (--frames>=0)
		{
			VOICE *V = voice;
			l = r = 0.0f;

			for(v=0; v<activevoices; v++)
			{
				V->frac += V->delta;  //integer-based linear interpolation
				V->pos += V->frac >> 16;
				V->frac &= 0xFFFF;
				if (V->pos > V->end) V->pos -= V->loop;
				//i = (i << 7) + (V->frac >> 9) * (waves[V->pos + 1] - i) + 0x40400000;   //not working on intel mac !?!
				i = waves[V->pos] + ((V->frac * (waves[V->pos + 1] - waves[V->pos])) >> 16);
				x = V->env * (float)i / 32768.0f;
				//x = V->env * (*(float *)&i - 3.0f);  //fast int->float

				V->env = V->env * V->dec;  //envelope
				V->f0 += V->ff * (x + V->f1 - V->f0);  //muffle filter
				V->f1 = x;

				l += V->outl * V->f0;
				r += V->outr * V->f0;

				if (!(l > -2.0f) || !(l < 2.0f))
				{
					printf ("what is this shit?   %ld,  %f,  %f\n", i, x, V->f0);
					l = 0.0f;
				}  
				if (!(r > -2.0f) || !(r < 2.0f))
				{
					r = 0.0f;
				}  

				V++;
			}
			comb[cpos] = l + r;
			++cpos &= cmax;
			x = cdep * comb[cpos];  //stereo simulator

			*out0++ = l + x;
			*out1++ = r - x;
		}

		if (frame<sampleFrames)
		{
			int32 note = notes[event++];
			int32 vel  = notes[event++];
			noteOn(note, vel);
		}
	}
	for(v=0; v<activevoices; v++) if (voice[v].env < SILENCE) voice[v] = voice[--activevoices];
	notes[0] = EVENTS_DONE;  //mark events buffer as done
	eventPos = 0;
}

//-----------------------------------------------------------------------------
void PianoProcessor::noteOn(int32 note, int32 velocity)
{
	float l=99.0f;
	int32  v, vl=0, k, s;

	if (velocity>0) 
	{
		if (activevoices < poly) //add a note
		{
			vl = activevoices;
			activevoices++;
		}
		else //steal a note
		{
			for(v=0; v<poly; v++)  //find quietest voice
			{
				if (voice[v].env < l) { l = voice[v].env;  vl = v; }
			}
		}

		k = (note - 60) * (note - 60);
		l = fine + random * ((float)(k % 13) - 6.5f);  //random & fine tune
		if (note > 60) l += stretch * (float)k; //stretch

		s = size;
		if (velocity > 40) s += (int32)(sizevel * (float)(velocity - 40));  

		k = 0;
		while (note > (kgrp[k].high + s)) k++;  //find keygroup

		l += (float)(note - kgrp[k].root); //pitch
		l = 22050.0f * iFs * (float)exp (0.05776226505 * l);
		voice[vl].delta = (int32)(65536.0f * l);
		voice[vl].frac = 0;
		voice[vl].pos = kgrp[k].pos;
		voice[vl].end = kgrp[k].end;
		voice[vl].loop = kgrp[k].loop;

		voice[vl].env = (0.5f + velsens) * (float)pow (0.0078f * velocity, velsens); //velocity

		l = 50.0f + params[4] * params[4] * muff + muffvel * (float)(velocity - 64); //muffle
		if (l < (55.0f + 0.25f * (float)note)) l = 55.0f + 0.25f * (float)note;
		if (l > 210.0f) l = 210.0f;
		voice[vl].ff = l * l * iFs;
		voice[vl].f0 = voice[vl].f1 = 0.0f;

		voice[vl].note = note; //note->pan
		if (note <  12) note = 12;
		if (note > 108) note = 108;
		l = volume * trim;
		voice[vl].outr = l + l * width * (float)(note - 60);
		voice[vl].outl = l + l - voice[vl].outr;

		if (note < 44) note = 44; //limit max decay length
		l = 2.0f * params[0];
		if (l < 1.0f) l += 0.25f - 0.5f * params[0];
		voice[vl].dec = (float)exp (-iFs * exp (-0.6 + 0.033 * (double)note - l));
	}
	else //note off
	{
		for(v=0; v<NVOICES; v++) if (voice[v].note==note) //any voices playing that note?
		{
			if (sustain==0)
			{
				if (note < 94 || note == SUSTAIN) //no release on highest notes
				voice[v].dec = (float)exp (-iFs * exp (2.0 + 0.017 * (double)note - 2.0 * params[1]));
			}
			else voice[v].note = SUSTAIN;
		}
	}
}

//-----------------------------------------------------------------------------
void PianoProcessor::processEvents (IEventList* events)
{
	if (events)
	{
		int32 count = events->getEventCount ();
		for (int32 i = 0; i < count; i++)
		{
			Event e;
			events->getEvent (i, e);
			switch (e.type)
			{
				case Event::kNoteOnEvent:
				{
					notes[eventPos++] = e.sampleOffset;
					notes[eventPos++] = e.noteOn.pitch;
					notes[eventPos++] = e.noteOn.velocity * 127;
					break;
				}
				case Event::kNoteOffEvent:
				{
					notes[eventPos++] = e.sampleOffset;
					notes[eventPos++] = e.noteOff.pitch;
					notes[eventPos++] = 0;
					break;
				}
				default:
					continue;
			}
			if (eventPos > EVENTBUFFER) eventPos -= 3; //discard events if buffer full!!
		}
		notes[eventPos] = EVENTS_DONE;
	}
}

//-----------------------------------------------------------------------------
void PianoProcessor::allNotesOff ()
{
  for (int32 v=0; v<NVOICES; v++) voice[v].dec=0.99f;
  sustain = 0;
  muff = 160.0f;
}

//-----------------------------------------------------------------------------
void PianoProcessor::recalculate ()
{
	size = (int32)(12.0f * params[2] - 6.0f);
	sizevel = 0.12f * params[3];
	muffvel = params[5] * params[5] * 5.0f;

	velsens = 1.0f + params[6] + params[6];
	if (params[6] < 0.25f) velsens -= 0.75f - 3.0f * params[6];

	fine = params[9] - 0.5f;
	random = 0.077f * params[10] * params[10];
	stretch = 0.000434f * (params[11] - 0.5f);

	cdep = params[7] * params[7];
	trim = 1.50f - 0.79f * cdep;
	width = 0.04f * params[7];  if (width > 0.03f) width = 0.03f;

	poly = 8 + (int32)(24.9f * params[8]);
}

}}} // namespaces

