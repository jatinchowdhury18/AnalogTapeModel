//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/again.cpp
// Created by  : Steinberg, 04/2005
// Description : Plug Example for VST SDK 3.0
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

#include "plug.h"
#include "plugparamids.h"
#include "plugcids.h"	// for class ids

#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstevents.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// Plug Implementation
//------------------------------------------------------------------------
Plug::Plug ()
: bBypass (false)
{
	// register its editor class (the same than used in plugentry.cpp)
	setControllerClass (PlugControllerUID);
}

//------------------------------------------------------------------------
tresult PLUGIN_API Plug::initialize (FUnknown* context)
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
	addEventInput  (STR16 ("Event In"), 1);
	addAudioOutput (STR16 ("Stereo Out"), SpeakerArr::kStereo);

	return kResultOk;
}

//------------------------------------------------------------------------
tresult Plug::sendTextMessage (const char16* text)
{
	IMessage* message = allocateMessage ();
	if (!message)
		return kResultFalse;
	FReleaser msgReleaser (message);
	message->setMessageID ("TextMessage");
	message->getAttributes ()->setString ("Text", text);
	return sendMessage (message);
}

//------------------------------------------------------------------------
tresult PLUGIN_API Plug::process (ProcessData& data)
{
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
						{
 							mLastNoteOnPitch = event.noteOn.pitch;
							mLastNoteOnId = event.noteOn.noteId;
							/*String str;
							str.printf (STR("noteON %d"), event.noteOff.noteId);
							sendTextMessage (str);*/
						}
						break;

					//----------------------
					case Event::kNoteOffEvent:
						{
						/*	String str;
							str.printf (STR("noteOff %d"), event.noteOff.noteId);
							sendTextMessage (str);
						*/}
						break;

						//----------------------
					case Event::kNoteExpressionTextEvent:
						// noteOff reset the reduction
						if (event.noteExpressionText.typeId == kTextTypeID)
						{
							//if (mLastNoteOnId == event.noteExpressionText.noteId)
							{
								String str (STR("Text: "));
								str += event.noteExpressionText.text;
								String tmp1;
								tmp1.printInt64 (mLastNoteOnId);
								String tmp2;
								tmp2.printInt64 (event.noteExpressionText.noteId);
								str += STR(" - id:");
								str += tmp2;
								str += STR(" - noteOn id:");
								str += tmp1;
								sendTextMessage (str);
							}
						}
						else if (event.noteExpressionText.typeId == kPhonemeTypeID)
						{
							//if (mLastNoteOnId == event.noteExpressionText.noteId)
							{
								String str (STR("Phoneme: "));
								str += event.noteExpressionText.text;
								String tmp1;
								tmp1.printInt64 (mLastNoteOnId);
								String tmp2;
								tmp2.printInt64 (event.noteExpressionText.noteId);
								str += STR(" - id:");
								str += tmp2;
								str += STR(" - noteOn id:");
								str += tmp1;
							}
						}
						break;
				}
			}
		}
	}
	//-------------------------------------
	//---3) Process Audio---------------------
	//-------------------------------------
	
	if (data.numOutputs == 0)
	{
		// nothing to do
		return kResultOk;
	}

	// no output
	float** out = data.outputs[0].channelBuffers32;
	for (int32 i = 0; i < data.outputs[0].numChannels; i++)
	{
		memset (out[i], 0, data.numSamples * sizeof (float));
	}
	data.outputs[0].silenceFlags = 0x7fff;

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API Plug::setState (IBStream* state)
{
	// called when we load a preset, the model has to be reloaded

	int32 savedBypass = 0;
	if (state->read (&savedBypass, sizeof (int32)) != kResultOk)
	{
		return kResultFalse;
	}

#if BYTEORDER == kBigEndian
	SWAP_32 (savedBypass)
#endif
	
	bBypass = savedBypass > 0;

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API Plug::getState (IBStream* state)
{
	// here we need to save the model

	int32 toSaveBypass = bBypass ? 1 : 0;

#if BYTEORDER == kBigEndian
	SWAP_32 (toSaveBypass)
#endif
	state->write (&toSaveBypass, sizeof (int32));

	return kResultOk;
}


}} // namespaces
