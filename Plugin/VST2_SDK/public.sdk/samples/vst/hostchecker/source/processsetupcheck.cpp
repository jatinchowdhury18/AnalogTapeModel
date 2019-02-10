//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/processsetupcheck.cpp
// Created by  : Steinberg, 12/2012
// Description : VST::ProcessSetup check
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

#include "processsetupcheck.h"
#include "logevents.h"

//------------------------------------------------------------------------
//    ProcessSetupCheck
//------------------------------------------------------------------------
ProcessSetupCheck::ProcessSetupCheck ()
: mEventLogger (0)
{

}

//------------------------------------------------------------------------
void ProcessSetupCheck::setProcessSetup (Steinberg::Vst::ProcessSetup setup)
{
	mSetup = setup;
}

//------------------------------------------------------------------------
void ProcessSetupCheck::check (const Steinberg::Vst::ProcessData& data)
{
	if (data.symbolicSampleSize != mSetup.symbolicSampleSize)
	{
		mEventLogger->addLogEvent (kLogIdInvalidSymbolicSampleSize);
	}

	if (data.processMode != mSetup.processMode)
	{
		// exception toggle between kRealtime kPrefetch
		if (!((mSetup.processMode == Steinberg::Vst::kRealtime && data.processMode == Steinberg::Vst::kPrefetch) || 
			(mSetup.processMode == Steinberg::Vst::kPrefetch && data.processMode == Steinberg::Vst::kRealtime)))
			mEventLogger->addLogEvent (kLogIdInvalidProcessMode);
	}

	if (data.numSamples < 0 || data.numSamples > mSetup.maxSamplesPerBlock)
	{
		mEventLogger->addLogEvent (kLogIdInvalidBlockSize);
	}
}

//------------------------------------------------------------------------
void ProcessSetupCheck::setEventLogger (EventLogger* eventLogger)
{
	mEventLogger = eventLogger;
}

