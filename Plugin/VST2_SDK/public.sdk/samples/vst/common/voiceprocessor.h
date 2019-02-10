//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/common/voiceprocessor.h
// Created by  : Steinberg, 02/2010
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

#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivstevents.h"
#include "base/source/fdebug.h"
#include <algorithm>

#ifdef DEBUG_LOG
	#undef DEBUG_LOG
#endif

#define DEBUG_LOG	DEVELOPMENT

#ifndef VOICEPROCESSOR_BLOCKSIZE
	#define VOICEPROCESSOR_BLOCKSIZE	32
#endif

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
/** A Voice Processor class.

A virtual base class for a voice manager implementation.

The idea behind this class is to make it easier to support either single precision or double precision samples (float or double) or different channel layouts.

Example:
\code
class MySynthProcessor : public AudioEffect
{
public:
	tresult PLUGIN_API setActive (TBool state);
	tresult PLUGIN_API process (ProcessData& data);

protected:
	VoiceProcessor* voiceProcessor;
};

tresult PLUGIN_API MySynthProcessor::setActive (TBool state)
{
	if (state)
	{
		if (processSetup.symbolicSampleSize == kSample32)
			voiceProcessor = new VoiceProcessorImplementation<float, Voice<float>, 2, MAX_VOICES, void> (processSetup.sampleRate, 0);
		else if (processSetup.symbolicSampleSize == kSample64)
			voiceProcessor = new VoiceProcessorImplementation<double, Voice<double>, 2, MAX_VOICES, void> (processSetup.sampleRate, 0);
		else
			return kInvalidArgument;
	}
	else
	{
		delete voiceProcessor;
		voiceProcessor = 0;
	}
	return kResultTrue;
}

tresult PLUGIN_API MySynthProcessor::process (ProcessData& data)
{
	return voiceProcessor->process (data);
}

\endcode

\sa Steinberg::Vst::VoiceProcessorImplementation
*/
//-----------------------------------------------------------------------------
class VoiceProcessor
{
public:
	VoiceProcessor () : activeVoices (0), mClearOutputNeeded (true) {}
	virtual ~VoiceProcessor () {}

	virtual tresult process (ProcessData& data) = 0;

	/** Returns the number of active voices. */
	int32 getActiveVoices () const { return activeVoices; }

	void clearOutputNeeded (bool val) { mClearOutputNeeded = val; }
protected:
	int32 activeVoices;
	bool mClearOutputNeeded;
};

//-----------------------------------------------------------------------------
/** A Simple Voice Processor Implementation supporting note expression events.

\param Precision must be either float or double
\param VoiceClass the voice class
\param numChannels number of channels
\param maxVoices number of maximum voices
\param GlobalParameterStorage a class holding global parameters

The VoiceClass must implement the following methods:
\code
int32 getNoteId () const;
void setGlobalParameterStorage (GlobalParameterStorage* globalParameters);
void setSampleRate (ParamValue sampleRate);
void setNoteExpressionValue (int32 index, ParamValue value);
void noteOn (int32 pitch, ParamValue velocity, float tuning, int32 sampleOffset, int32 noteId);
void noteOff (ParamValue velocity, int32 sampleOffset);
bool process (SamplePrecision* outputBuffers[numChannels], int32 numSamples);
void reset () 
\endcode

See \ref Steinberg::Vst::VoiceBase for an example base class.

This implementation does not support advanced features like voice stealing when maxVoices is reached, etc ...
*/
//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
class VoiceProcessorImplementation : public VoiceProcessor
{
public:
	VoiceProcessorImplementation (float sampleRate, GlobalParameterStorage* globalParameters = 0);
	~VoiceProcessorImplementation ();

	tresult process (ProcessData& data);

protected:
	VoiceClass* getVoice (int32 noteId);
	VoiceClass* findVoice (int32 noteId);
	VoiceClass voices [maxVoices];
};


//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
VoiceProcessorImplementation<Precision, VoiceClass, numChannels, maxVoices, GlobalParameterStorage>::VoiceProcessorImplementation (float sampleRate, GlobalParameterStorage* globalParameters)
{
	for (int32 i = 0; i < maxVoices; i++)
	{
		voices[i].setGlobalParameterStorage (globalParameters);
		voices[i].setSampleRate (sampleRate);
		voices[i].reset ();
	}
}

//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
VoiceProcessorImplementation<Precision, VoiceClass, numChannels, maxVoices, GlobalParameterStorage>::~VoiceProcessorImplementation ()
{
}

//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
VoiceClass* VoiceProcessorImplementation<Precision, VoiceClass, numChannels, maxVoices, GlobalParameterStorage>::getVoice (int32 noteId)
{
	VoiceClass* firstFreeVoice = 0;
	if (noteId != -1)
	{
		for (int32 i = 0; i < maxVoices; i++)
		{
			if (voices[i].getNoteId () == noteId)
			{
				return &voices[i];
			}
			else if (firstFreeVoice == 0 && voices[i].getNoteId () == -1)
			{
				firstFreeVoice = &voices[i];
			}
		}
	}
	return firstFreeVoice;
}

//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
VoiceClass* VoiceProcessorImplementation<Precision, VoiceClass, numChannels, maxVoices, GlobalParameterStorage>::findVoice (int32 noteId)
{
	if (noteId != -1)
	{
		for (int32 i = 0; i < maxVoices; i++)
		{
			if (voices[i].getNoteId () == noteId)
			{
				return &voices[i];
			}
		}
	}
	return 0;
}

#if VOICEPROCESSOR_BLOCKSIZE <= 0	// voice processing happens in chunks of the block size
//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
tresult VoiceProcessorImplementation<Precision, VoiceClass, numChannels, maxVoices, GlobalParameterStorage>::process (ProcessData& data)
{
	if (mClearOutputNeeded)
		for (int32 i = 0; i < numChannels; i++)
			memset (data.outputs[0].channelBuffers32[i], 0, data.numSamples * sizeof (Precision));

	IEventList* inputEvents = data.inputEvents;
	if (inputEvents)
	{
		Event e;
		int32 numEvents = inputEvents->getEventCount ();
		for (int32 i = 0; i < numEvents; i++)
		{
			if (inputEvents->getEvent (i, e) == kResultTrue)
			{
				switch (e.type)
				{
					//-----------------------
					case Event::kNoteOnEvent:
					{
						if (e.noteOn.noteId == -1) // for host which don't send unique noteId's
							e.noteOn.noteId = e.noteOn.pitch;
						VoiceClass* voice = getVoice (e.noteOn.noteId);
						if (voice)
						{
							voice->noteOn (e.noteOn.pitch, e.noteOn.velocity, e.noteOn.tuning, e.sampleOffset, e.noteOn.noteId);
							this->activeVoices++;
						}
						break;
					}
					//-----------------------
					case Event::kNoteOffEvent:
					{
						if (e.noteOff.noteId == -1) // for host which don't send unique noteId's
							e.noteOff.noteId = e.noteOff.pitch;
						VoiceClass* voice = findVoice (e.noteOff.noteId);
						if (voice)
						{
							voice->noteOff (e.noteOff.velocity, e.sampleOffset);
						}
					#if DEBUG_LOG
						else
						{
							FDebugPrint ("Voice for kNoteOffEvent not found : %d\n", e.noteOff.noteId);
						}
					#endif
						break;
					}
					//-----------------------
					case Event::kNoteExpressionValueEvent:
					{
						VoiceClass* voice = findVoice (e.noteExpressionValue.noteId);
						if (voice)
						{
							voice->setNoteExpressionValue (e.noteExpressionValue.typeId, e.noteExpressionValue.value);
						}
					#if DEBUG_LOG
						else
						{
							FDebugPrint ("Voice for kNoteExpressionValueEvent not found : %d\n", e.noteExpressionValue.noteId);
						}
					#endif
						break;
					}
				}
			}
		}
	}

	for (int32 i = 0; i < maxVoices; i++)
	{
		if (voices[i].getNoteId () != -1)
		{
			if (!voices[i].process ((Precision**)data.outputs[0].channelBuffers32, data.numSamples))
			{
				voices[i].reset ();
				this->activeVoices--;
			}
		}
	}
	return kResultTrue;
}

#else	// voice processing happens in chunks of VOICEPROCESSOR_BLOCKSIZE samples
//-----------------------------------------------------------------------------
template<class Precision, class VoiceClass, int32 numChannels, int32 maxVoices, class GlobalParameterStorage>
tresult VoiceProcessorImplementation<Precision, VoiceClass, numChannels, maxVoices, GlobalParameterStorage>::process (ProcessData& data)
{	
	const int32 kBlockSize = VOICEPROCESSOR_BLOCKSIZE;

	int32 numSamples = data.numSamples;
	int32 samplesProcessed = 0;
	int32 i;

	IEventList* inputEvents = data.inputEvents;
	Event e = {0};
	Event* eventPtr = 0;
	int32 eventIndex = 0;
	int32 numEvents = inputEvents ? inputEvents->getEventCount () : 0;
	
	// get the first event
	if (numEvents)
	{
		inputEvents->getEvent (0, e);
		eventPtr = &e;
	}

	// initialize audio output buffers
	Precision* buffers[numChannels];
	for (i = 0; i < numChannels; i++)
	{
		buffers[i] = (Precision*)data.outputs[0].channelBuffers32[i];
		if (mClearOutputNeeded)
			memset (buffers[i], 0, data.numSamples * sizeof (Precision));
	}
	
	while (numSamples > 0)
	{
		int32 samplesToProcess = std::min<int32> (kBlockSize, numSamples);
		while (eventPtr != 0)
		{
			// if the event is not in the current processing block then adapt offset for next block
			if (e.sampleOffset > samplesToProcess)
			{
				e.sampleOffset -= samplesToProcess;
				break;
			}

			switch (e.type)
			{
				//-----------------------
				case Event::kNoteOnEvent:
				{
					if (e.noteOn.noteId == -1)
						e.noteOn.noteId = e.noteOn.pitch;
					VoiceClass* voice = getVoice (e.noteOn.noteId);
					if (voice)
					{
						voice->noteOn (e.noteOn.pitch, e.noteOn.velocity, e.noteOn.tuning, e.sampleOffset, e.noteOn.noteId);
						this->activeVoices++;
						//data.outputEvents->addEvent (e);
					}
					break;
				}
				//-----------------------
				case Event::kNoteOffEvent:
				{
					if (e.noteOff.noteId == -1)
						e.noteOff.noteId = e.noteOff.pitch;
					VoiceClass* voice = findVoice (e.noteOff.noteId);
					if (voice)
					{
						voice->noteOff (e.noteOff.velocity, e.sampleOffset);
						//data.outputEvents->addEvent (e);
					}
				#if DEBUG_LOG
					else
					{
						FDebugPrint ("Voice for kNoteOffEvent not found : %d\n", e.noteOff.noteId);
					}
				#endif
					break;
				}
				//-----------------------
				case Event::kNoteExpressionValueEvent:
				{
					VoiceClass* voice = findVoice (e.noteExpressionValue.noteId);
					if (voice)
					{
						voice->setNoteExpressionValue (e.noteExpressionValue.typeId, e.noteExpressionValue.value);
						//data.outputEvents->addEvent (e);
					}
				#if DEBUG_LOG
					else
					{
						FDebugPrint ("Voice for kNoteExpressionValueEvent not found : %d\n", e.noteExpressionValue.noteId);
					}
				#endif
					break;
				}
			}
			
			// get next event
			eventIndex++;
			if (eventIndex < numEvents)
			{
				if (inputEvents->getEvent (eventIndex, e) == kResultTrue)
				{
					e.sampleOffset -= samplesProcessed;
				}
				else
				{
					eventPtr = 0;
				}
			}
			else
			{
				eventPtr = 0;
			}
		}	// end while (event != 0)

		// now process the block
		for (i = 0; i < maxVoices; i++)
		{
			if (voices[i].getNoteId () != -1)
			{
				if (!voices[i].process (buffers, samplesToProcess))
				{
					voices[i].reset ();
					this->activeVoices--;
				}
			}
		}

		// update the counters
		for (i = 0; i < numChannels; i++)
			buffers[i] += samplesToProcess;
		numSamples -= samplesToProcess;
		samplesProcessed += samplesToProcess;

	} // end while (numSamples > 0)

	return kResultTrue;
}

#endif

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
