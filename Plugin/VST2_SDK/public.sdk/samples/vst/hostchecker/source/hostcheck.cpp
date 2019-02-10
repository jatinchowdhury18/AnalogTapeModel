//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/hostcheck.cpp
// Created by  : Steinberg, 04/2012
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

#include "hostcheck.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivstevents.h"
#include "logevents.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstnoteexpression.h"

//------------------------------------------------------------------------
HostCheck::HostCheck () : mComponent (0)
{
	mProcessSetupCheck.setEventLogger (&mEventLogger);
	mProcessContextCheck.setEventLogger (&mEventLogger);
	mEventListCheck.setEventLogger (&mEventLogger);
	mParamChangesCheck.setEventLogger (&mEventLogger);
	mParamChangesCheck.setParamIDs (&mParameterIds);
}

//------------------------------------------------------------------------
void HostCheck::addParameter (Steinberg::Vst::ParamID paramId) { mParameterIds.insert (paramId); }

//------------------------------------------------------------------------
void HostCheck::addLogEvent (Steinberg::int32 logId) { mEventLogger.addLogEvent (logId); }

//------------------------------------------------------------------------
bool HostCheck::validate (Steinberg::Vst::ProcessData& data)
{
	mProcessSetupCheck.check (data);
	mProcessContextCheck.check (data.processContext);
	mEventListCheck.check (data.inputEvents);
	mParamChangesCheck.checkParameterChanges (data.inputParameterChanges);

	checkAudioBuffers (data.inputs, data.numInputs, Steinberg::Vst::kInput);
	checkAudioBuffers (data.outputs, data.numOutputs, Steinberg::Vst::kOutput);

	return mEventLogger.empty ();
}

//------------------------------------------------------------------------
void HostCheck::checkAudioBuffers (Steinberg::Vst::AudioBusBuffers* buffers,
								   Steinberg::int32 numBuffers, Steinberg::Vst::BusDirection dir)
{
	if (mComponent)
	{
		if (numBuffers > 0)
		{
			Steinberg::int32 audioBusCount = mComponent->getBusCount (Steinberg::Vst::kAudio, dir);
			bool isValid = audioBusCount == numBuffers;
			if (!isValid)
			{
				addLogEvent (kLogIdAudioBufNotMatchComponentBusCount);
			}
		}
	}

	if (numBuffers > 0)
	{
		if (!buffers)
		{
			addLogEvent (kLogIdNullPointerToAudioBusBuffer);
			return;
		}

		for (Steinberg::int32 bufferIdx = 0; bufferIdx < numBuffers; ++bufferIdx)
		{
			Steinberg::Vst::BusInfo busInfo = {0};
			mComponent->getBusInfo (Steinberg::Vst::kAudio, dir, bufferIdx, busInfo);
			Steinberg::Vst::AudioBusBuffers& tmpBuffers = buffers[bufferIdx];
			if (tmpBuffers.numChannels != busInfo.channelCount)
			{
				addLogEvent (kLogIdInvalidAudioBufNumOfChannels);
			}

			for (Steinberg::int32 chIdx = 0; chIdx < tmpBuffers.numChannels; ++chIdx)
			{
				if (!tmpBuffers.channelBuffers32[chIdx])
				{
					addLogEvent (kLogIdNullPointerToChannelBuf);
				}
			}
		}
	}
}

//------------------------------------------------------------------------
void HostCheck::setComponent (Steinberg::Vst::IComponent* component)
{
	mEventListCheck.setComponent (component);
	mComponent = component;
}

//------------------------------------------------------------------------
void HostCheck::setProcessSetup (Steinberg::Vst::ProcessSetup& setup)
{
	mProcessSetupCheck.setProcessSetup (setup);
	mEventListCheck.setProcessSetup (setup);
	mProcessContextCheck.setSampleRate (setup.sampleRate);
}
