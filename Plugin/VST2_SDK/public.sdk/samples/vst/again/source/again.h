//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/again.h
// Created by  : Steinberg, 04/2005
// Description : AGain Example for VST SDK 3.0
//               Simple gain Plug-in with gain, bypass values and 1 midi input
//               and the same Plug-in with sidechain 
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

#include "public.sdk/source/vst/vstaudioeffect.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// AGain: directly derived from the helper class AudioEffect
//------------------------------------------------------------------------
class AGain: public AudioEffect
{
public:
	AGain ();
	virtual ~AGain ();	// dont forget virtual here

//------------------------------------------------------------------------
// create function required for Plug-in factory,
// it will be called to create new instances of this Plug-in
//------------------------------------------------------------------------
	static FUnknown* createInstance (void* context)
	{
		return (IAudioProcessor*)new AGain;
	}

//------------------------------------------------------------------------
// AudioEffect overrides:
//------------------------------------------------------------------------
	/** Called at first after constructor */
	tresult PLUGIN_API initialize (FUnknown* context);
	
	/** Called at the end before destructor */
	tresult PLUGIN_API terminate  ();
	
	/** Switch the Plug-in on/off */
	tresult PLUGIN_API setActive (TBool state);

	/** Here we go...the process call */
	tresult PLUGIN_API process (ProcessData& data);

	/** Test of a communication channel between controller and component */
	tresult receiveText (const char* text);
	
	/** For persistence */
	tresult PLUGIN_API setState (IBStream* state);
	tresult PLUGIN_API getState (IBStream* state);

	/** Will be called before any process call */
	tresult PLUGIN_API setupProcessing (ProcessSetup& newSetup);

	/** Bus arrangement managing: in this example the 'again' will be mono for mono input/output and stereo for other arrangements. */
	tresult PLUGIN_API setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts);

	/** We want to receive message. */
	tresult PLUGIN_API notify (IMessage* message);

//------------------------------------------------------------------------
protected:
	// our model values
	float fGain;
	float fGainReduction;
	float fVuPPMOld;

	int32 currentProcessMode;

	bool  bHalfGain;
	bool  bBypass;
};


//------------------------------------------------------------------------
// AGainWithSideChain: directly derived from AGain
//------------------------------------------------------------------------
class AGainWithSideChain: public AGain
{
public:
	// just overwrite some functions
	static FUnknown* createInstance (void* context)
	{
		return (IAudioProcessor*)new AGainWithSideChain;
	}

	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API process (ProcessData& data);
	tresult PLUGIN_API setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts);
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
