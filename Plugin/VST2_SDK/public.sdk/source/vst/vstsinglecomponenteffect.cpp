//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vstsinglecomponenteffect.cpp
// Created by  : Steinberg, 03/2008
// Description : Basic Audio Effect Implementation in one component
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
//-----------------------------------------------------------------------------

#include "vstsinglecomponenteffect.h"

//-----------------------------------------------------------------------------
namespace Steinberg {
namespace Vst {


//-----------------------------------------------------------------------------
// SingleComponentEffect Implementation
//-----------------------------------------------------------------------------
SingleComponentEffect::SingleComponentEffect ()
: audioInputs (kAudio, kInput)
, audioOutputs (kAudio, kOutput)
, eventInputs (kEvent, kInput)
, eventOutputs (kEvent, kOutput)
{
	processSetup.maxSamplesPerBlock = 1024;
	processSetup.processMode = Vst::kRealtime;
	processSetup.sampleRate = 44100.0;
	processSetup.symbolicSampleSize = Vst::kSample32;
}

//-----------------------------------------------------------------------------
SingleComponentEffect::~SingleComponentEffect ()
{
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::initialize (FUnknown* context)
{
	return EditController::initialize (context);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::terminate ()
{
	parameters.removeAll ();
	removeAllBusses ();

	return EditController::terminate ();
}

//-----------------------------------------------------------------------------
int32 PLUGIN_API SingleComponentEffect::getBusCount (MediaType type, BusDirection dir)
{
	BusList* busList = getBusList (type, dir);
	return busList ? busList->total () : 0;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::getBusInfo (MediaType type, BusDirection dir, int32 index, BusInfo& info)
{
	BusList* busList = getBusList (type, dir);
	Bus* bus = busList ? (Bus*)busList->at (index) : 0;
	if (bus)
	{
		info.mediaType = type;
		info.direction = dir;
		if (bus->getInfo (info))
			return kResultTrue;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::activateBus (MediaType type, BusDirection dir, int32 index, TBool state)
{
	BusList* busList = getBusList (type, dir);
	Bus* bus = busList ? (Bus*)busList->at (index) : 0;
	if (bus)
	{
		bus->setActive (state);
		return kResultTrue;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
AudioBus* SingleComponentEffect::addAudioInput (const TChar* name, SpeakerArrangement arr, 
									  BusType busType, int32 flags)
{
	AudioBus* newBus = new AudioBus (name, busType, flags, arr);
	audioInputs.append (IPtr<Vst::Bus> (newBus, false));
	return newBus;
}

//-----------------------------------------------------------------------------
AudioBus* SingleComponentEffect::addAudioOutput (const TChar* name, SpeakerArrangement arr, 
									   BusType busType, int32 flags)
{
	AudioBus* newBus = new AudioBus (name, busType, flags, arr);
	audioOutputs.append (IPtr<Vst::Bus> (newBus, false));
	return newBus;
}

//-----------------------------------------------------------------------------
EventBus* SingleComponentEffect::addEventInput (const TChar* name, int32 channels, 
									  BusType busType, int32 flags)
{
	EventBus* newBus = new EventBus (name, busType, flags, channels);
	eventInputs.append (IPtr<Vst::Bus> (newBus, false));
	return newBus;
}

//-----------------------------------------------------------------------------
EventBus* SingleComponentEffect::addEventOutput (const TChar* name, int32 channels, 
									   BusType busType, int32 flags)
{
	EventBus* newBus = new EventBus (name, busType, flags, channels);
	eventOutputs.append (IPtr<Vst::Bus> (newBus, false));
	return newBus;
}

//-----------------------------------------------------------------------------
tresult SingleComponentEffect::removeAudioBusses ()
{
	audioInputs.removeAll ();
	audioOutputs.removeAll ();

	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult SingleComponentEffect::removeEventBusses ()
{
	eventInputs.removeAll ();
	eventOutputs.removeAll ();

	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult SingleComponentEffect::removeAllBusses ()
{
	removeAudioBusses ();
	removeEventBusses ();

	return kResultOk;
}

//-----------------------------------------------------------------------------
// IAudioProcessor
//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::setBusArrangements (SpeakerArrangement* inputs, int32 numIns, 
													SpeakerArrangement* outputs, int32 numOuts)
{
	int32 counter = 0;
	FOREACH_CAST (IPtr<Vst::Bus>, Vst::AudioBus, bus, audioInputs)
		if (counter < numIns)
			bus->setArrangement (inputs[counter]);
		counter++;
	ENDFOR

	counter = 0;
	FOREACH_CAST (IPtr<Vst::Bus>, Vst::AudioBus, bus, audioOutputs)
		if (counter < numOuts)
			bus->setArrangement (outputs[counter]);
		counter++;
	ENDFOR

	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::getBusArrangement (BusDirection dir, int32 busIndex, SpeakerArrangement& arr)
{
	BusList* busList = getBusList (kAudio, dir);
	AudioBus* audioBus = busList ? FCast<Vst::AudioBus> (busList->at (busIndex)) : 0;
	if (audioBus)
	{
		arr = audioBus->getArrangement ();
		return kResultTrue;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::setupProcessing (ProcessSetup& newSetup)
{
	if (canProcessSampleSize (newSetup.symbolicSampleSize) != kResultTrue)
		return kResultFalse;

	processSetup = newSetup;
	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::canProcessSampleSize (int32 symbolicSampleSize)
{
	return symbolicSampleSize == kSample32 ? kResultTrue : kResultFalse;
}

//-----------------------------------------------------------------------------
BusList* SingleComponentEffect::getBusList (MediaType type, BusDirection dir)
{
	if (type == kAudio)
		return dir == kInput ? &audioInputs : &audioOutputs;
	else if (type == kEvent)
		return dir == kInput ? &eventInputs : &eventOutputs;
	return 0;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API SingleComponentEffect::queryInterface (const TUID iid, void** obj)
{
	if (memcmp (iid, IConnectionPoint::iid, sizeof (::Steinberg::TUID)) == 0)
	{
		// no need to expose IConnectionPoint to the host
		return kNoInterface;
	}
	DEF_INTERFACE (IComponent)
	DEF_INTERFACE (IAudioProcessor)
	return EditController::queryInterface (iid, obj);
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg

// work around for the name clash of IComponent::setState and IEditController::setState
// make sure that vsteditcontroller.cpp is otherwise excluded from your project
#define setState setEditorState
#define getState getEditorState
#include "public.sdk/source/vst/vsteditcontroller.cpp"
#undef setState
#undef getState
