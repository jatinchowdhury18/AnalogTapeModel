//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/adelay/source/adelayprocessor.cpp
// Created by  : Steinberg, 06/2009
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

#include "adelayprocessor.h"
#include "adelayids.h"
#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include <algorithm>

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
ADelayProcessor::ADelayProcessor ()
: mDelay (1)
, mBuffer (0)
, mBufferPos (0)
, mBypass (false)
{
	setControllerClass (ADelayControllerUID);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ADelayProcessor::initialize (FUnknown* context)
{
	tresult result = AudioEffect::initialize (context);
	if (result == kResultTrue)
	{
		addAudioInput (STR16 ("AudioInput"), SpeakerArr::kStereo);
		addAudioOutput (STR16 ("AudioOutput"), SpeakerArr::kStereo);
	}
	return result;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ADelayProcessor::setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	// we only support one in and output bus and these buses must have the same number of channels
	if (numIns == 1 && numOuts == 1 && inputs[0] == outputs[0])
		return AudioEffect::setBusArrangements (inputs, numIns, outputs, numOuts);
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ADelayProcessor::setActive (TBool state)
{
	SpeakerArrangement arr;
	if (getBusArrangement (kOutput, 0, arr) != kResultTrue)
		return kResultFalse;
	int32 numChannels = SpeakerArr::getChannelCount (arr);
	if (numChannels == 0)
		return kResultFalse;

	if (state)
	{
		mBuffer = (float**)malloc (numChannels * sizeof (float*));
		
		size_t size = (size_t)(processSetup.sampleRate * sizeof (float) + 0.5);
		for (int32 channel = 0; channel < numChannels; channel++)
		{
			mBuffer[channel] = (float*)malloc (size);	// 1 second delay max
			memset (mBuffer[channel], 0, size);
		}
		mBufferPos = 0;
	}
	else
	{
		if (mBuffer)
		{
			for (int32 channel = 0; channel < numChannels; channel++)
			{
				free (mBuffer[channel]);
			}
			free (mBuffer);
			mBuffer = 0;
		}
	}
	return AudioEffect::setActive (state);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API ADelayProcessor::process (ProcessData& data)
{
	if (data.inputParameterChanges)
	{
		int32 numParamsChanged = data.inputParameterChanges->getParameterCount ();
		for (int32 index = 0; index < numParamsChanged; index++)
		{
			IParamValueQueue* paramQueue = data.inputParameterChanges->getParameterData (index);
			if (paramQueue)
			{
				ParamValue value;
				int32 sampleOffset;
				int32 numPoints = paramQueue->getPointCount ();
				switch (paramQueue->getParameterId ())
				{
					case kDelayId:
						if (paramQueue->getPoint (numPoints - 1, sampleOffset, value) == kResultTrue)
							mDelay = value;
						break;
					case kBypassId:
						if (paramQueue->getPoint (numPoints - 1,  sampleOffset, value) == kResultTrue)
						{
							mBypass = (value > 0.5f);
			}
						break;
		}
	}
		}
	}

	if (data.numSamples > 0)
	{
		SpeakerArrangement arr;
		getBusArrangement (kOutput, 0, arr);
		int32 numChannels = SpeakerArr::getChannelCount (arr);

		// TODO do something in Bypass : copy inpuit to output if necessary...

		// apply delay
		int32 delayInSamples = std::max<int32> (1, (int32)(mDelay * processSetup.sampleRate)); // we have a minimum of 1 sample delay here
		for (int32 channel = 0; channel < numChannels; channel++)
		{
			float* inputChannel = data.inputs[0].channelBuffers32[channel];
			float* outputChannel = data.outputs[0].channelBuffers32[channel];

			int32 tempBufferPos = mBufferPos;
			for (int32 sample = 0; sample < data.numSamples; sample++)
			{
				float tempSample = inputChannel[sample];
				outputChannel[sample] = mBuffer[channel][tempBufferPos];
				mBuffer[channel][tempBufferPos] = tempSample;
				tempBufferPos++;
				if (tempBufferPos >= delayInSamples)
					tempBufferPos = 0;
			}
		}
		mBufferPos += data.numSamples;
		while (delayInSamples && mBufferPos >= delayInSamples)
			mBufferPos -= delayInSamples;
	}	
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayProcessor::setState (IBStream* state)
{
	if (!state)
		return kResultFalse;

	// called when we load a preset, the model has to be reloaded

	float savedDelay = 0.f;
	if (state->read (&savedDelay, sizeof (float)) != kResultOk)
	{
		return kResultFalse;
	}

	int32 savedBypass = 0;
	if (state->read (&savedBypass, sizeof (int32)) != kResultOk)
	{
		// could be an old version, continue 
	}

#if BYTEORDER == kBigEndian
	SWAP_32 (savedDelay)
	SWAP_32 (savedBypass)
#endif

	mDelay = savedDelay;
	mBypass = savedBypass > 0;

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayProcessor::getState (IBStream* state)
{
	// here we need to save the model

	float toSaveDelay = mDelay;
	int32 toSaveBypass = mBypass ? 1 : 0;

#if BYTEORDER == kBigEndian
	SWAP_32 (toSaveDelay)
	SWAP_32 (toSaveBypass)
#endif

	state->write (&toSaveDelay, sizeof (float));
	state->write (&toSaveBypass, sizeof (int32));

	return kResultOk;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
