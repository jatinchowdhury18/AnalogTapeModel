//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/channelcontext/source/plug.cpp
// Created by  : Steinberg, 02/2014
// Description : Plug Example for VST SDK 3.x
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
#include "pluginterfaces/base/futils.h"

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

	//---create Audio In/Out busses------
	// we want a stereo Input and a Stereo Output
	addAudioInput  (STR16 ("Stereo In"),  SpeakerArr::kStereo);
	addAudioOutput (STR16 ("Stereo Out"), SpeakerArr::kStereo);

	return kResultOk;
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
	
	//-------------------------------------
	//---3) Process Audio---------------------
	//-------------------------------------
	if (data.numInputs == 0 || data.numOutputs == 0)
	{
		// nothing to do
		return kResultOk;
	}

	// (simplification) we suppose in this example that we have the same input channel count than the output
	int32 numChannels = Min (data.inputs[0].numChannels, data.outputs[0].numChannels);

	//---get audio buffers----------------
	float** in  = data.inputs[0].channelBuffers32;
	float** out = data.outputs[0].channelBuffers32;

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
		for (int32 i = numChannels; i < data.outputs[0].numChannels; i++)
		{
			memset (out[i], 0, sizeof (float)* data.numSamples);
		}
	}
	else
	{
		float gain = 0.5;

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
			}
		}
		for (int32 i = numChannels; i < data.outputs[0].numChannels; i++)
		{
			memset (out[i], 0, sizeof (float)* data.numSamples);
		}
	}

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

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
