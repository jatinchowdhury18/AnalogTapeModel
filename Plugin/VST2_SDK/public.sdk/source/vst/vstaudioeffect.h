//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vstaudioeffect.h
// Created by  : Steinberg, 04/2005
// Description : Basic Audio Effect Implementation
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-----------------------------------------------------------------------------
// This Software Development Kit may not be distributed in parts or its entirety
// without prior written agreement by Steinberg Media Technologies GmbH.
// This SDK must not be used to re-engineer or manipulate any technology used
// in any Steinberg or Third-party application or software module,
// unless permitted by law.
// Neither the name of the Steinberg Media Technologies nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
//
// THIS SDK IS PROVIDED BY STEINBERG MEDIA TECHNOLOGIES GMBH "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL STEINBERG MEDIA TECHNOLOGIES GMBH BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//----------------------------------------------------------------------------------

#pragma once

#include "public.sdk/source/vst/vstcomponent.h"
#include "public.sdk/source/vst/vstbus.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"

//------------------------------------------------------------------------
namespace Steinberg {
namespace Vst {


//------------------------------------------------------------------------
/** Default implementation for a VST 3 audio effect.
\ingroup vstClasses
Can be used as base class for a VST 3 effect implementation. */
//------------------------------------------------------------------------
class AudioEffect: public Component,
				   public IAudioProcessor
{
public:
//------------------------------------------------------------------------
	/** Constructor */
	AudioEffect ();

	//---Internal Methods-----------
	/** Creates and adds a new Audio input bus with a given speaker arrangement, busType (kMain or kAux). */
	AudioBus* addAudioInput (const TChar* name, SpeakerArrangement arr,
							 BusType busType = kMain, int32 flags = BusInfo::kDefaultActive);

	/** Creates and adds a new Audio output bus with a given speaker arrangement, busType (kMain or kAux). */
	AudioBus* addAudioOutput (const TChar* name, SpeakerArrangement arr,
							  BusType busType = kMain, int32 flags = BusInfo::kDefaultActive);

	/** Retrieves an Audio Input Bus by index. */
	AudioBus* getAudioInput (int32 index);

	/** Retrieves an Audio Output Bus by index. */
	AudioBus* getAudioOutput (int32 index);

	/** Creates and adds a new Event input bus with a given speaker arrangement, busType (kMain or kAux). */
	EventBus* addEventInput (const TChar* name, int32 channels = 16,
						      BusType busType = kMain, int32 flags = BusInfo::kDefaultActive);

	/** Creates and adds a new Event output bus with a given speaker arrangement, busType (kMain or kAux). */
	EventBus* addEventOutput (const TChar* name, int32 channels = 16,
							  BusType busType = kMain, int32 flags = BusInfo::kDefaultActive);

	/** Retrieves an Event Input Bus by index. */
	EventBus* getEventInput (int32 index);

	/** Retrieves an Event Output Bus by index. */
	EventBus* getEventOutput (int32 index);

	//---from IAudioProcessor-------
	tresult PLUGIN_API setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts);
	tresult PLUGIN_API getBusArrangement (BusDirection dir, int32 busIndex, SpeakerArrangement& arr);
	tresult PLUGIN_API canProcessSampleSize (int32 symbolicSampleSize);
	uint32 PLUGIN_API getLatencySamples () { return 0; }
	tresult PLUGIN_API setupProcessing (ProcessSetup& setup);
	tresult PLUGIN_API setProcessing (TBool state);
	tresult PLUGIN_API process (ProcessData& data);
	uint32 PLUGIN_API getTailSamples () { return kNoTail; }

	//---Interface---------
	OBJ_METHODS (AudioEffect, Component)
	DEFINE_INTERFACES
		DEF_INTERFACE (IAudioProcessor)
	END_DEFINE_INTERFACES (Component)
	REFCOUNT_METHODS(Component)

//------------------------------------------------------------------------
protected:
	ProcessSetup processSetup;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
