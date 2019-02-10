//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/prefetchablesupport/source/plug.h
// Created by  : Steinberg, 04/2015
// Description : Plug-in Example for VST SDK 3.x using IPrefetchableSupport
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
#include "pluginterfaces/vst/ivstprefetchablesupport.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// Plug: directly derived from the helper class AudioEffect
//------------------------------------------------------------------------
class Plug : public AudioEffect, public Vst::IPrefetchableSupport
{
public:
	Plug ();

//------------------------------------------------------------------------
// create function required for Plug-in factory,
// it will be called to create new instances of this Plug-in
//------------------------------------------------------------------------
	static FUnknown* createInstance (void* context)
	{
		return (IAudioProcessor*)new Plug;
	}

//------------------------------------------------------------------------
// AudioEffect overrides:
//------------------------------------------------------------------------
	/** Called at first after constructor */
	tresult PLUGIN_API initialize (FUnknown* context);
		
	/** Here we go...the process call */
	tresult PLUGIN_API process (ProcessData& data);

	/** For persistence */
	tresult PLUGIN_API setState (IBStream* state);
	tresult PLUGIN_API getState (IBStream* state);

	//---------------------------------------------------------------------
	// IPrefetchableSupport
	//---------------------------------------------------------------------
	/** */
	tresult PLUGIN_API getPrefetchableSupport (PrefetchableSupport& prefetchable /*out*/) override;

	//---Interface---------
	OBJ_METHODS (Plug, AudioEffect)
	DEFINE_INTERFACES
		DEF_INTERFACE (Vst::IPrefetchableSupport)
	END_DEFINE_INTERFACES (AudioEffect)
	REFCOUNT_METHODS (AudioEffect)

//------------------------------------------------------------------------
protected:
	bool bBypass;
	int32 mPrefetchableMode;
};

}} // namespaces
