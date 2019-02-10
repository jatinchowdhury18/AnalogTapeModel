/*
 *  mdaBaseProcessor.cpp
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

#include "mdaBaseProcessor.h"
#include "mdaBaseController.h"
#include "helpers.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/base/ibstream.h"

#include <math.h>

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
BaseProcessor::BaseProcessor ()
: params (0)
, numParams (0)
, bypassState (false)
, bypassBuffer0 (0)
, bypassBuffer1 (0)
, bypassRamp (0)
{
}

//-----------------------------------------------------------------------------
BaseProcessor::~BaseProcessor ()
{
	if (bypassBuffer0)
		free (bypassBuffer0);
	if (bypassBuffer1)
		free (bypassBuffer1);
	if (params)
		delete [] params;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseProcessor::process (ProcessData& data)
{
	if (processParameterChanges (data.inputParameterChanges))
		recalculate ();

	processEvents (data.inputEvents);

	if (data.numSamples > 0 && !bypassProcessing (data))
	{
		doProcessing (data);
		checkSilence (data);
	}
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseProcessor::setupProcessing (ProcessSetup& setup)
{
	if (bypassBuffer0)
		free (bypassBuffer0);
	bypassBuffer0 = (float*)malloc (setup.maxSamplesPerBlock * sizeof (float));

	if (bypassBuffer1)
		free (bypassBuffer1);
	bypassBuffer1 = (float*)malloc (setup.maxSamplesPerBlock * sizeof (float));
	
	return AudioEffect::setupProcessing (setup);
}

//-----------------------------------------------------------------------------
bool BaseProcessor::bypassProcessing (ProcessData& data)
{
	if (data.numSamples == 0)
		return true;

	if (isBypassed () || bypassRamp != 0)
	{
		if (bypassRamp)
		{
			float* origOut0 = data.outputs[0].channelBuffers32[0];
			float* origOut1 = data.outputs[0].channelBuffers32[1];

			data.outputs[0].channelBuffers32[0] = bypassBuffer0;
			data.outputs[0].channelBuffers32[1] = bypassBuffer1;

			doProcessing (data);

			data.outputs[0].channelBuffers32[0] = origOut0;
			data.outputs[0].channelBuffers32[1] = origOut1;

			float* bpb0 = bypassBuffer0;
			float* bpb1 = bypassBuffer1;
			float origMix = 0;
			float plugMix = 0;
			float factor = 1.f / (float)data.numSamples;

			if (bypassRamp > 0)
			{
				for (int32 i = 0; i < data.numSamples; i++)
				{
					origMix = (float)i * factor;
					plugMix = (float)(data.numSamples - i) * factor;
					*origOut0 = *origOut0 * origMix + *bpb0 * plugMix;
					*origOut1 = *origOut1 * origMix + *bpb1 * plugMix;
					origOut0++;
					origOut1++;
					bpb0++;
					bpb1++;
				}
			}
			else
			{
				for (int32 i = 0; i < data.numSamples; i++)
				{
					plugMix = (float)i * factor;
					origMix = (float)(data.numSamples - i) * factor;
					*origOut0 = *origOut0 * origMix + *bpb0 * plugMix;
					*origOut1 = *origOut1 * origMix + *bpb1 * plugMix;
					origOut0++;
					origOut1++;
					bpb0++;
					bpb1++;
				}
			}
			data.outputs[0].silenceFlags = 0;
			bypassRamp = 0;
		}
		else
		{
			for (int32 bus = 0; bus < data.numInputs, bus < data.numOutputs; bus++)
			{
				Bus* output = getAudioOutput (bus);
				if (!output || !output->isActive ())
					continue;
				for (int32 channel = 0; channel < data.outputs[bus].numChannels; channel++)
				{
					if (data.numInputs <= bus || data.inputs[bus].numChannels <= channel)
					{
						memset (data.outputs[bus].channelBuffers32[channel], 0, sizeof (float) * data.numSamples);
						data.outputs[bus].silenceFlags |= (uint64)1 << channel;
					}
					else
					{
						if (data.outputs[bus].channelBuffers32[channel] != data.inputs[bus].channelBuffers32[channel])
							memcpy (data.outputs[bus].channelBuffers32[channel], data.inputs[bus].channelBuffers32[channel], sizeof (float) * data.numSamples);
 						data.outputs[bus].silenceFlags |= data.inputs[bus].silenceFlags & ((uint64)1 << channel);
					}
				}
			}
		}
		return true;
	}
	return false;
}

#define kSilenceThreshold 0.000132184039

//-----------------------------------------------------------------------------
void BaseProcessor::checkSilence (ProcessData& data)
{
	for (int32 bus = 0; bus < data.numOutputs; bus ++)
	{
		data.outputs[bus].silenceFlags = 0;
		
		if (!getAudioOutput (bus)->isActive ())
			continue;

		for (int32 channel = 0; channel < data.outputs[bus].numChannels; channel++)
		{
			bool channelIsSilent = true;
			for (int32 sample = 0; sample < data.numSamples; sample += 10)
			{
				if (fabs (data.outputs[bus].channelBuffers32[channel][sample]) > kSilenceThreshold)
				{
					channelIsSilent = false;
					break;
				}
			}
			if (channelIsSilent)
				data.outputs[bus].silenceFlags |= (uint64)1 << channel;
		}
	}
}

//-----------------------------------------------------------------------------
bool BaseProcessor::processParameterChanges (IParameterChanges* changes)
{
	if (changes)
	{
		int32 count = changes->getParameterCount ();
		if (count > 0)
		{
			for (int32 i = 0; i < count; i++)
			{
				IParamValueQueue* queue = changes->getParameterData (i);
				if (!queue)
					continue;
				ParamID paramId = queue->getParameterId ();
				int32 pointCount = queue->getPointCount ();
				int32 sampleOffset;
				ParamValue value;
				queue->getPoint (pointCount - 1, sampleOffset, value);
				if (paramId == BaseController::kBypassParam)
					setBypass (value >= 0.5, sampleOffset);
				else
					setParameter (paramId, value, sampleOffset);
			}
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------
void BaseProcessor::setBypass (bool state, int32 sampleOffset)
{
	if (state != bypassState)
	{
		bypassState = state;
		if (bypassState)
			bypassRamp = 1;
		else
			bypassRamp = -1;
	}
}

//-----------------------------------------------------------------------------
void BaseProcessor::setParameter (ParamID index, ParamValue newValue, int32 sampleOffset)
{
	if (numParams > index)
		params[index] = newValue;
}

//-----------------------------------------------------------------------------
void BaseProcessor::allocParameters (int32 _numParams)
{
	if (params)
		return;
	numParams = _numParams;
	params = new ParamValue[numParams];
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseProcessor::setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	if (numIns)
	{
		if (SpeakerArr::getChannelCount (inputs[0]) != 2)
			return kResultFalse;
	}
	if (numOuts)
	{
		if (SpeakerArr::getChannelCount (outputs[0]) != 2)
			return kResultFalse;
	}
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseProcessor::setActive (TBool state)
{
	if (state)
	{
		IMessage* msg = allocateMessage ();
		if (msg)
		{
			msg->setMessageID ("activated");
			msg->getAttributes ()->setFloat ("SampleRate", processSetup.sampleRate);
			sendMessage (msg);
			msg->release ();
		}
	}
	return AudioEffect::setActive (state);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseProcessor::setState (IBStream* state)
{
	uint32 temp;
	state->read (&temp, sizeof (uint32)); // numParams
	
	// read each parameter
	for (uint32 i = 0; i < temp, i < numParams; i++)
	{
		state->read (&params[i], sizeof (ParamValue));
		SWAP64_BE(params[i])
	}

	// bypass
	state->read (&temp, sizeof (uint32));
	SWAP32_BE(temp)
	bypassState = temp > 0;

	recalculate ();
	
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseProcessor::getState (IBStream* state)
{
	// save number of parameter
	uint32 temp = numParams;
	SWAP32_BE(temp);
	state->write (&temp, sizeof (uint32));
	
	// save each parameter
	for (uint32 i = 0; i < numParams; i++)
	{
		ParamValue value = params[i];
		SWAP64_BE(value)
		state->write (&value, sizeof (ParamValue));
	}
	
	// save bypass
	temp = bypassState ? 1 : 0;
	SWAP32_BE(temp)
	state->write (&temp, sizeof (uint32));
	
	return kResultTrue;
}

}}} // namespace
