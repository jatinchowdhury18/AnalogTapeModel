//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/again.cpp
// Created by  : Steinberg, 04/2005
// Description : AGain Example for VST SDK 3
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

#include "again.h"
#include "againparamids.h"
#include "againcids.h"	// for class ids

#include "pluginterfaces/base/ustring.h"	// for UString128
#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstevents.h"
#include "pluginterfaces/vst/vstpresetkeys.h"	// for use of IStreamAttributes

#include <stdio.h>

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// AGain Implementation
//------------------------------------------------------------------------
AGain::AGain ()
: fGain (1.f)
, fGainReduction (0.f)
, fVuPPMOld (0.f)
, currentProcessMode (-1) // -1 means not initialized
, bHalfGain (false)
, bBypass (false)
{
	// register its editor class (the same than used in againentry.cpp)
	setControllerClass (AGainControllerUID);
}

//------------------------------------------------------------------------
AGain::~AGain ()
{
	// nothing to do here yet..
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::initialize (FUnknown* context)
{
	//---always initialize the parent-------
	tresult result = AudioEffect::initialize (context);
	// if everything Ok, continue
	if (result != kResultOk)
	{
		return result;
	}

	//---create Audio In/Out buses------
	// we want a stereo Input and a Stereo Output
	addAudioInput  (STR16 ("Stereo In"),  SpeakerArr::kStereo);
	addAudioOutput (STR16 ("Stereo Out"), SpeakerArr::kStereo);

	//---create Event In/Out buses (1 bus with only 1 channel)------
	addEventInput (STR16 ("Event In"), 1);

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::terminate  ()
{
	// nothing to do here yet...except calling our parent terminate
	return AudioEffect::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::setActive (TBool state)
{
	if (state)
	{
		sendTextMessage ("AGain::setActive (true)");
	}
	else
	{
		sendTextMessage ("AGain::setActive (false)");
	}
	
	// reset the VuMeter value
	fVuPPMOld = 0.f;

	// call our parent setActive
	return AudioEffect::setActive (state);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::process (ProcessData& data)
{
	// finally the process function
	// In this example there are 4 steps:
	// 1) Read inputs parameters coming from host (in order to adapt our model values)
	// 2) Read inputs events coming from host (we apply a gain reduction depending of the velocity of pressed key)
	// 3) Process the gain of the input buffer to the output buffer
	// 4) Write the new VUmeter value to the output Parameters queue


	//---1) Read inputs parameter changes-----------
	IParameterChanges* paramChanges = data.inputParameterChanges;
	if (paramChanges)
	{
		int32 numParamsChanged = paramChanges->getParameterCount ();
		// for each parameter which are some changes in this audio block:
		for (int32 i = 0; i < numParamsChanged; i++)
		{
			IParamValueQueue* paramQueue = paramChanges->getParameterData (i);
			if (paramQueue)
			{
				ParamValue value;
				int32 sampleOffset;
				int32 numPoints = paramQueue->getPointCount ();
				switch (paramQueue->getParameterId ())
				{
					case kGainId:
						// we use in this example only the last point of the queue.
						// in some wanted case for specific kind of parameter it makes sense to retrieve all points
						// and process the whole audio block in small blocks.
						if (paramQueue->getPoint (numPoints - 1, sampleOffset, value) == kResultTrue)
						{
							fGain = (float)value;
						}
						break;

					case kBypassId:
						if (paramQueue->getPoint (numPoints - 1, sampleOffset, value) == kResultTrue)
						{
							bBypass = (value > 0.5f);
						}
						break;
				}
			}
		}
	}
	
	//---2) Read input events-------------
	IEventList* eventList = data.inputEvents;
	if (eventList) 
	{
		int32 numEvent = eventList->getEventCount ();
		for (int32 i = 0; i < numEvent; i++)
		{
			Event event;
			if (eventList->getEvent (i, event) == kResultOk)
			{
				switch (event.type)
				{
					//----------------------
					case Event::kNoteOnEvent:
						// use the velocity as gain modifier
						fGainReduction = event.noteOn.velocity;
						break;
					
					//----------------------
					case Event::kNoteOffEvent:
						// noteOff reset the reduction
						fGainReduction = 0.f;
						break;
				}
			}
		}
	}
		
	//-------------------------------------
	//---3) Process Audio---------------------
	//-------------------------------------
	if (data.numInputs == 0 || data.numOutputs == 0)
	{
		// nothing to do
		return kResultOk;
	}

	// (simplification) we suppose in this example that we have the same input channel count than the output
	int32 numChannels = data.inputs[0].numChannels;

	//---get audio buffers----------------
	float** in  = data.inputs[0].channelBuffers32;
	float** out = data.outputs[0].channelBuffers32;

	//---check if silence---------------
	// normally we have to check each channel (simplification)
	if (data.inputs[0].silenceFlags != 0)
	{
		// mark output silence too
		data.outputs[0].silenceFlags = data.inputs[0].silenceFlags;
		
		// the Plug-in has to be sure that if it sets the flags silence that the output buffer are clear
		int32 sampleFrames = data.numSamples;
		for (int32 i = 0; i < numChannels; i++)
		{
			// dont need to be cleared if the buffers are the same (in this case input buffer are already cleared by the host)
			if (in[i] != out[i])
			{
				memset (out[i], 0, sampleFrames * sizeof (float));
			}
		}

		// nothing to do at this point
		return kResultOk;
	}

	// mark our outputs has not silent
	data.outputs[0].silenceFlags = 0;

	//---in bypass mode outputs should be like inputs-----
	if (bBypass)
	{
		int32 sampleFrames = data.numSamples;
		for (int32 i = 0; i < numChannels; i++)
		{
			// dont need to be copied if the buffers are the same
			if (in[i] != out[i])
			{
				memcpy (out[i], in[i], sampleFrames * sizeof (float));
			}
		}
		// in this example we dont update the VuMeter in Bypass
	}
	else
	{
		float fVuPPM = 0.f;

		//---apply gain factor----------
		float gain = (fGain - fGainReduction);
		if (bHalfGain)
		{
			gain = gain * 0.5f;
		}
		
		// if the applied gain is nearly zero, we could say that the outputs are zeroed and we set the silence flags. 
		if (gain < 0.0000001)
		{
			int32 sampleFrames = data.numSamples;
			for (int32 i = 0; i < numChannels; i++)
			{
				memset (out[i], 0, sampleFrames * sizeof (float));
			}
			data.outputs[0].silenceFlags = (1 << numChannels) - 1;  // this will set to 1 all channels
		}
		else
		{
			// in real Plug-in it would be better to do dezippering to avoid jump (click) in gain value
			for (int32 i = 0; i < numChannels; i++)
			{
				int32 sampleFrames = data.numSamples;
				float* ptrIn  = in[i];
				float* ptrOut = out[i];
				float tmp;
				while (--sampleFrames >= 0)
				{
					// apply gain
					tmp = (*ptrIn++) * gain;
					(*ptrOut++) = tmp;

					// check only positive values
					if (tmp > fVuPPM)
					{
						fVuPPM = tmp;
					}
				}
			}
		}

		//---3) Write outputs parameter changes-----------
		IParameterChanges* outParamChanges = data.outputParameterChanges;
		// a new value of VuMeter will be send to the host 
		// (the host will send it back in sync to our controller for updating our editor)
		if (outParamChanges && fVuPPMOld != fVuPPM)
		{
			int32 index = 0;
			IParamValueQueue* paramQueue = outParamChanges->addParameterData (kVuPPMId, index);
			if (paramQueue)
			{
				int32 index2 = 0;
				paramQueue->addPoint (0, fVuPPM, index2); 
			}
		}
		fVuPPMOld = fVuPPM;
	}

	return kResultOk;
}

//------------------------------------------------------------------------
tresult AGain::receiveText (const char* text)
{
	// received from Controller
	fprintf (stderr, "[AGain] received: ");
	fprintf (stderr, text);
	fprintf (stderr, "\n");
	
	bHalfGain = !bHalfGain;

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::setState (IBStream* state)
{
	// called when we load a preset, the model has to be reloaded

	float savedGain = 0.f;
	if (state->read (&savedGain, sizeof (float)) != kResultOk)
	{
		return kResultFalse;
	}

	float savedGainReduction = 0.f;
	if (state->read (&savedGainReduction, sizeof (float)) != kResultOk)
	{
		return kResultFalse;
	}

	int32 savedBypass = 0;
	if (state->read (&savedBypass, sizeof (int32)) != kResultOk)
	{
		return kResultFalse;
	}

#if BYTEORDER == kBigEndian
	SWAP_32 (savedGain)
	SWAP_32 (savedGainReduction)
	SWAP_32 (savedBypass)
#endif
	
	fGain = savedGain;
	fGainReduction = savedGainReduction;
	bBypass = savedBypass > 0;

	// Example of using the IStreamAttributes interface
	FUnknownPtr<IStreamAttributes> stream (state);
	if (stream)
	{
		IAttributeList* list = stream->getAttributes ();
		if (list)
		{
			// get the current type (project/Default..) of this state
			String128 string = {0};
			if (list->getString (PresetAttributes::kStateType, string, 128 * sizeof (TChar)) == kResultTrue)
			{
				UString128 tmp (string);
				char ascii[128];
				tmp.toAscii (ascii, 128);
				if (!strncmp (ascii, StateType::kProject, strlen (StateType::kProject)))
				{
					// we are in project loading context...
				}
			}

			// get the full file path of this state
			TChar fullPath[1024];
			memset (fullPath, 0, 1024 * sizeof (TChar));
			if (list->getString (PresetAttributes::kFilePathStringType, fullPath, 1024 * sizeof (TChar)) == kResultTrue)
			{
				// here we have the full path ...
			}
		}
	}

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::getState (IBStream* state)
{
	// here we need to save the model

	float toSaveGain = fGain;
	float toSaveGainReduction = fGainReduction;
	int32 toSaveBypass = bBypass ? 1 : 0;

#if BYTEORDER == kBigEndian
	SWAP_32 (toSaveGain)
	SWAP_32 (toSaveGainReduction)
	SWAP_32 (toSaveBypass)
#endif

	state->write (&toSaveGain, sizeof (float));
	state->write (&toSaveGainReduction, sizeof (float));
	state->write (&toSaveBypass, sizeof (int32));

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::setupProcessing (ProcessSetup& newSetup)
{
	// called before the process call, always in a disable state (not active)
	
	// here we keep a trace of the processing mode (offline,...) for example.
	currentProcessMode = newSetup.processMode;
	
	return AudioEffect::setupProcessing (newSetup);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	if (numIns == 1 && numOuts == 1)
	{
		// the host wants Mono => Mono (or 1 channel -> 1 channel)
		if (SpeakerArr::getChannelCount (inputs[0]) == 1 && SpeakerArr::getChannelCount (outputs[0]) == 1)
		{
			AudioBus* bus = FCast<AudioBus> (audioInputs.at (0));
			if (bus)
			{
				// check if we are Mono => Mono, if not we need to recreate the buses
				if (bus->getArrangement () != inputs[0])
				{
					removeAudioBusses ();
					addAudioInput  (STR16 ("Mono In"),  inputs[0]);
					addAudioOutput (STR16 ("Mono Out"), inputs[0]);
				}
				return kResultOk;
			}
		}
		// the host wants something else than Mono => Mono, in this case we are always Stereo => Stereo
		else
		{
			AudioBus* bus = FCast<AudioBus> (audioInputs.at (0));
			if (bus)
			{
				tresult result = kResultFalse;
				
				// the host wants 2->2 (could be LsRs -> LsRs)
				if (SpeakerArr::getChannelCount (inputs[0]) == 2 && SpeakerArr::getChannelCount (outputs[0]) == 2)
				{
					removeAudioBusses ();
					addAudioInput  (STR16 ("Stereo In"),  inputs[0]);
					addAudioOutput (STR16 ("Stereo Out"), outputs[0]);
					result = kResultTrue;
				}
				// the host want something different than 1->1 or 2->2 : in this case we want stereo
				else if (bus->getArrangement () != SpeakerArr::kStereo)
				{
					removeAudioBusses ();
					addAudioInput  (STR16 ("Stereo In"),  SpeakerArr::kStereo);
					addAudioOutput (STR16 ("Stereo Out"), SpeakerArr::kStereo);
					result = kResultFalse;
				}

				return result;
			}
		}
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGain::notify (IMessage* message)
{
	if (!message)
		return kInvalidArgument;

	if (!strcmp (message->getMessageID (), "BinaryMessage"))
	{
		const void* data;
		uint32 size;
		if (message->getAttributes ()->getBinary ("MyData", data, size) == kResultOk)
		{
			// we are in UI thread
			// size should be 100
			if (size == 100 && ((char*)data)[1] == 1) // yeah...
			{
				
			}
			return kResultOk;
		}
	}

	return AudioEffect::notify (message);
}

//------------------------------------------------------------------------
// AGainWithSideChain Implementation
//------------------------------------------------------------------------

//------------------------------------------------------------------------
tresult PLUGIN_API AGainWithSideChain::initialize (FUnknown* context)
{
	//---always initialize the parent-------
	tresult result = AGain::initialize (context);
	// if everything Ok, continue
	if (result != kResultOk)
	{
		return result;
	}

	// create a Mono SideChain input bus
	addAudioInput (STR16 ("Mono Aux In"), SpeakerArr::kMono, kAux, 0);

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainWithSideChain::process (ProcessData& data)
{
	// finally the process function
	// In this example there are 4 steps:
	// 1) Read inputs parameters coming from host (in order to adapt our model values)
	// 2) Read inputs events coming from host (we apply a gain reduction depending of the velocity of pressed key)
	// 3) Process the gain of the input buffer to the output buffer
	// 4) Write the new VUmeter value to the output Parameters queue


	//---1) Read inputs parameter changes-----------
	IParameterChanges* paramChanges = data.inputParameterChanges;
	if (paramChanges)
	{
		int32 numParamsChanged = paramChanges->getParameterCount ();
		// for each parameter which are some changes in this audio block:
		for (int32 i = 0; i < numParamsChanged; i++)
		{
			IParamValueQueue* paramQueue = paramChanges->getParameterData (i);
			if (paramQueue)
			{
				int32 offsetSamples;
				double value;
				int32 numPoints = paramQueue->getPointCount ();				
				switch (paramQueue->getParameterId ())
				{
					case kGainId:
						// we use in this example only the last point of the queue.
						// in some wanted case for specific kind of parameter it makes sense to retrieve all points
						// and process the whole audio block in small blocks.
						if (paramQueue->getPoint (numPoints - 1,  offsetSamples, value) == kResultTrue)
						{
							fGain = (float)value;
						}
						break;

					case kBypassId:
						if (paramQueue->getPoint (numPoints - 1,  offsetSamples, value) == kResultTrue)
						{
							bBypass = (value > 0.5f);
						}
						break;
				}
			}
		}
	}

	//---2) Read input events-------------
	IEventList* eventList = data.inputEvents;
	if (eventList) 
	{
		int32 numEvent = eventList->getEventCount ();
		for (int32 i = 0; i < numEvent; i++)
		{
			Event event;
			if (eventList->getEvent (i, event) == kResultOk)
			{
				switch (event.type)
				{
					//----------------------
					case Event::kNoteOnEvent:
						// use the velocity as gain modifier
						fGainReduction = event.noteOn.velocity;
						break;

						//----------------------
					case Event::kNoteOffEvent:
						// noteOff reset the reduction
						fGainReduction = 0.f;
						break;
				}
			}
		}
	}

	//-------------------------------------
	//---3) Process Audio---------------------
	//-------------------------------------
	if (data.numInputs == 0 || data.numOutputs == 0)
	{
		// nothing to do
		return kResultOk;
	}

	// (simplification) we suppose in this example that we have the same input channel count than the output
	int32 numChannels = data.inputs[0].numChannels;

	//---get audio buffers----------------
	float** in  = data.inputs[0].channelBuffers32;
	float** out = data.outputs[0].channelBuffers32;
	float** auxIn  = 0;
	bool auxActive = false;
	if (getAudioInput (1)->isActive ())
	{
		auxIn = data.inputs[1].channelBuffers32;
		auxActive = true;
	}

	//---check if silence---------------
	// normally we have to check each channel (simplification)
	if (data.inputs[0].silenceFlags != 0)
	{
		// mark output silence too
		data.outputs[0].silenceFlags = data.inputs[0].silenceFlags;

		// the Plug-in has to be sure that if it sets the flags silence that the output buffer are clear
		int32 sampleFrames = data.numSamples;
		for (int32 i = 0; i < numChannels; i++)
		{
			// dont need to be cleared if the buffers are the same (in this case input buffer are already cleared by the host)
			if (in[i] != out[i])
			{
				memset (out[i], 0, sampleFrames * sizeof (float));
			}
		}

		// nothing to do at this point
		return kResultOk;
	}

	// mark our outputs has not silent
	data.outputs[0].silenceFlags = 0;

	//---in bypass mode outputs should be like inputs-----
	if (bBypass)
	{
		int32 sampleFrames = data.numSamples;
		for (int32 i = 0; i < numChannels; i++)
		{
			// dont need to be copied if the buffers are the same
			if (in[i] != out[i])
			{
				memcpy (out[i], in[i], sampleFrames * sizeof (float));
			}
		}
		// in this example we dont update the VuMeter in Bypass
	}
	else
	{
		float fVuPPM = 0.f;

		//---apply gain factor----------
		float gain = (fGain - fGainReduction);
		if (bHalfGain)
		{
			gain = gain * 0.5f;
		}
		
		// if the applied gain is nearly zero, we could say that the outputs are zeroed and we set the silence flags. 
		if (gain < 0.0000001)
		{
			int32 sampleFrames = data.numSamples;
			for (int32 i = 0; i < numChannels; i++)
			{
				memset (out[i], 0, sampleFrames * sizeof (float));
			}
			data.outputs[0].silenceFlags = (1 << numChannels) - 1;  // this will set to 1 all channels
			fVuPPM = 0.f;
		}
		else
		{
			// in real Plug-in it would be better to do dezippering to avoid jump (click) in gain value
			if (auxActive)
			{
				// we add the sidechain to the input signal
				for (int32 i = 0; i < numChannels; i++)
				{
					float* ptrAuxIn  = auxIn[0];
					int32 sampleFrames = data.numSamples;
					float* ptrIn  = in[i];
					float* ptrOut = out[i];
					float tmp;
					while (--sampleFrames >= 0)
					{
						// apply gain
						tmp = (*ptrIn++ + *ptrAuxIn++) * gain;
						(*ptrOut++) = tmp;

						// check only positiv values
						if (tmp > fVuPPM)
						{
							fVuPPM = tmp;
						}
					}
				}
			}
			else
			{
				for (int32 i = 0; i < numChannels; i++)
				{
					int32 sampleFrames = data.numSamples;
					float* ptrIn  = in[i];
					float* ptrOut = out[i];
					float tmp;
					while (--sampleFrames >= 0)
					{
						// apply gain
						tmp = (*ptrIn++) * gain;
						(*ptrOut++) = tmp;

						// check only positiv values
						if (tmp > fVuPPM)
						{
							fVuPPM = tmp;
						}
					}
				}
			}
		}

		//---3) Write outputs parameter changes-----------
		IParameterChanges* outParamChanges = data.outputParameterChanges;
		// a new value of VuMeter will be send to the host 
		// (the host will send it back in sync to our controller for updating our editor)
		if (outParamChanges && fVuPPMOld != fVuPPM)
		{
			int32 index = 0;
			IParamValueQueue* paramQueue = outParamChanges->addParameterData (kVuPPMId, index);
			if (paramQueue)
			{
				int32 index2 = 0;
				paramQueue->addPoint (0, fVuPPM, index2); 
			}
		}
		fVuPPMOld = fVuPPM;
	}

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainWithSideChain::setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	// the first input is the Main Input and the second is the SideChain Input
	if (numIns == 2 && numOuts == 1)
	{
		// the host wants Mono => Mono (or 1 channel -> 1 channel)
		if (SpeakerArr::getChannelCount (inputs[0]) == 1 && SpeakerArr::getChannelCount (outputs[0]) == 1)
		{
			AudioBus* bus = FCast<AudioBus> (audioInputs.at (0));
			if (bus)
			{
				// check if we are Mono => Mono, if not we need to recreate the buses
				if (bus->getArrangement () != inputs[0])
				{
					removeAudioBusses ();
					addAudioInput  (STR16 ("Mono In"),  inputs[0]);
					addAudioOutput (STR16 ("Mono Out"), inputs[0]);

					// recreate the Mono SideChain input bus
					addAudioInput  (STR16 ("Mono Aux In"), SpeakerArr::kMono, kAux, 0);
				}
				return kResultOk;
			}
		}
		// the host wants something else than Mono => Mono, in this case we are always Stereo => Stereo
		else
		{
			AudioBus* bus = FCast<AudioBus> (audioInputs.at (0));
			if (bus)
			{
				tresult result = kResultFalse;
		
				// the host wants 2->2 (could be LsRs -> LsRs)
				if (SpeakerArr::getChannelCount (inputs[0]) == 2 && SpeakerArr::getChannelCount (outputs[0]) == 2)
				{
					removeAudioBusses ();
					addAudioInput  (STR16 ("Stereo In"),  inputs[0]);
					addAudioOutput (STR16 ("Stereo Out"), outputs[0]);
				
					// recreate the Mono SideChain input bus
					addAudioInput  (STR16 ("Mono Aux In"), SpeakerArr::kMono, kAux, 0);

					result = kResultTrue;		
				}
				// the host want something different than 1->1 or 2->2 : in this case we want stereo
				else if (bus->getArrangement () != SpeakerArr::kStereo)
				{
					removeAudioBusses ();
					addAudioInput  (STR16 ("Stereo In"),  SpeakerArr::kStereo);
					addAudioOutput (STR16 ("Stereo Out"), SpeakerArr::kStereo);
				
					// recreate the Mono SideChain input bus
					addAudioInput  (STR16 ("Mono Aux In"), SpeakerArr::kMono, kAux, 0);

					result = kResultFalse;
				}

				return result;
			}
		}
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
