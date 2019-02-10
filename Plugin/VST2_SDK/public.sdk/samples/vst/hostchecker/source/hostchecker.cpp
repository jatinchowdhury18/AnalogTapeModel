//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/hostchecker.cpp
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

#include "hostchecker.h"
#include "eventlogdatabrowsersource.h"

#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstcontextmenu.h"
#include "public.sdk/source/vst/vstcomponentbase.h"
#include "public.sdk/source/vst/vstrepresentation.h"

#include "logevents.h"

using namespace VSTGUI;

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
FUID HostCheckerController::cid (0x35AC5652, 0xC7D24CB1, 0xB1427D38, 0xEB690DAF);
FUID HostCheckerProcessor::cid (0x23FC190E, 0x02DD4499, 0xA8D2230E, 0x50617DA3);

static ProgramListID kProgramListID = 0;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::initialize (FUnknown* context)
{
	tresult result = EditControllerEx1::initialize (context);
	if (result == kResultOk)
	{
		parameters.addParameter (STR16 ("Param1"), STR16 (""), 1, 0, ParameterInfo::kCanAutomate);
		parameters.addParameter (STR16 ("Param2"), STR16 (""));
		parameters.addParameter (STR16 ("Param3"), STR16 (""));

		parameters.addParameter (STR16 ("Bypass"), STR16 (""), 1, 0,
								 ParameterInfo::kCanAutomate | ParameterInfo::kIsBypass);

		mDataBrowser = 0;
		mDataSource = 0;

		if (!mDataSource)
			mDataSource = new EventLogDataBrowserSource (this);

		if (!mDataBrowser)
			mDataBrowser =
				new CDataBrowser (CRect (0, 0, 100, 100), 0, mDataSource,
								  CDataBrowser::kDrawRowLines | CDataBrowser::kDrawColumnLines |
									  CDataBrowser::kDrawHeader | CDataBrowser::kVerticalScrollbar);
	}
	return result;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::terminate ()
{
	tresult result = EditControllerEx1::terminate ();
	if (result == kResultOk)
	{
		mDataSource = 0;
		mDataBrowser = 0;
	}
	return result;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::setComponentState (IBStream* state)
{
	float saved = 0.f;
	if (state->read (&saved, sizeof (float)) != kResultOk)
	{
		return kResultFalse;
	}

#if BYTEORDER == kBigEndian
	SWAP_32 (toSave)
#endif
	if (saved != 12345.67f)
	{
		ASSERT (false)
	}
	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::getUnitByBus (MediaType type, BusDirection dir,
														int32 busIndex, int32 channel,
														UnitID& unitId /*out*/)
{
	if (type == kEvent && dir == kInput)
	{
		if (busIndex == 0 && channel == 0)
		{
			unitId = kRootUnitId;
			return kResultTrue;
		}
	}
	addFeatureLog (kLogIdGetUnitByBusSupported);
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::setComponentHandler (IComponentHandler* handler)
{
	tresult res = EditControllerEx1::setComponentHandler (handler);
	if (componentHandler2)
	{
		addFeatureLog (kLogIdIComponentHandler2Supported);

		if (componentHandler2->requestOpenEditor () == kResultTrue)
			addFeatureLog (kLogIdIComponentHandler2RequestOpenEditorSupported);
	}

	FUnknownPtr<IComponentHandler3> handler3 (handler);
	if (handler3)
		addFeatureLog (kLogIdIComponentHandler3Supported);

	return res;
}

//-----------------------------------------------------------------------------
int32 PLUGIN_API HostCheckerController::getUnitCount ()
{
	addFeatureLog (kLogIdUnitSupported);
	return EditControllerEx1::getUnitCount ();
}

//-----------------------------------------------------------------------------
IPlugView* PLUGIN_API HostCheckerController::createView (FIDString name)
{
	if (ConstString (name) == ViewType::kEditor)
	{
		if (componentHandler2)
		{
			if (componentHandler2->setDirty (true) == kResultTrue)
				addFeatureLog (kLogIdIComponentHandler2SetDirtySupported);
		}

		return new VST3Editor (this, "HostCheckerEditor", "hostchecker.uidesc");
	}
	return nullptr;
}

//-----------------------------------------------------------------------------
CView* HostCheckerController::createCustomView (UTF8StringPtr name, const UIAttributes& attributes,
												IUIDescription* description, VST3Editor* editor)
{
	if (ConstString (name) == "HostCheckerDataBrowser")
	{
		if (mDataBrowser)
			mDataBrowser->remember ();
		return mDataBrowser;
	}
	return nullptr;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::connect (IConnectionPoint* other)
{
	Steinberg::tresult tResult = ComponentBase::connect (other);
	if (peerConnection)
	{
		for (Steinberg::int32 paramIdx = 0; paramIdx < getParameterCount (); ++paramIdx)
		{
			Steinberg::Vst::ParameterInfo paramInfo = {0};
			if (getParameterInfo (paramIdx, paramInfo) == Steinberg::kResultOk)
			{
				IMessage* newMsg = allocateMessage ();
				if (newMsg)
				{
					newMsg->setMessageID ("Parameter");
					Steinberg::Vst::IAttributeList* attr = newMsg->getAttributes ();
					if (attr)
					{
						attr->setInt ("ID", paramInfo.id);
					}

					sendMessage (newMsg);
				}
			}
		}

		FUnknownPtr<IAudioProcessor> proc (other);
		if (proc)
		{
			OPtr<IMessage> newMsg = allocateMessage ();
			if (newMsg)
			{
				newMsg->setMessageID ("LogEvent");
				Steinberg::Vst::IAttributeList* attr = newMsg->getAttributes ();
				if (attr)
				{
					attr->setInt ("ID", kLogIdProcessorControllerConnection);
					attr->setInt ("Count", 1);
				}

				notify (newMsg);
			}
		}
	}

	return tResult;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::notify (IMessage* message)
{
	if (!message)
		return kInvalidArgument;

	if (FIDStringsEqual (message->getMessageID (), "LogEvent"))
	{
		LogEvent logEvt;
		if (message->getAttributes ()->getInt ("ID", logEvt.id) != kResultOk)
			return kResultFalse;
		if (message->getAttributes ()->getInt ("Count", logEvt.count) != kResultOk)
			return kResultFalse;

		if (mDataSource && mDataBrowser && mDataSource->updateLog (logEvt))
			mDataBrowser->invalidateRow (logEvt.id);
	}

	return ComponentBase::notify (message);
}

//-----------------------------------------------------------------------------
void HostCheckerController::addFeatureLog (int32 iD)
{
	LogEvent logEvt;
	logEvt.id = iD;
	logEvt.count = 1;

	if (mDataSource && mDataBrowser && mDataSource->updateLog (logEvt))
		mDataBrowser->invalidateRow (logEvt.id);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::setKnobMode (KnobMode mode)
{
	addFeatureLog (kLogIdIEditController2Supported);
	return EditControllerEx1::setKnobMode (mode);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::openHelp (TBool onlyCheck)
{
	addFeatureLog (kLogIdIEditController2Supported);
	return EditControllerEx1::openHelp (onlyCheck);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::openAboutBox (TBool onlyCheck)
{
	addFeatureLog (kLogIdIEditController2Supported);
	return EditControllerEx1::openAboutBox (onlyCheck);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::setChannelContextInfos (IAttributeList* list)
{
	if (!list)
		return kResultFalse;

	// optional we can ask for the Channel Name Length
	int64 length;
	if (list->getInt (ChannelContext::kChannelNameLengthKey, length) == kResultTrue)
	{
	}

	// get the Channel Name where we, as Plug-in, are instantiated
	String128 name;
	if (list->getString (ChannelContext::kChannelNameKey, name, sizeof (name)) == kResultTrue)
	{
	}

	// get the Channel UID
	if (list->getString (ChannelContext::kChannelUIDKey, name, sizeof (name)) == kResultTrue)
	{
	}

	// get Channel Index
	int64 index;
	if (list->getInt (ChannelContext::kChannelIndexKey, index) == kResultTrue)
	{
	}

	// get the Channel Color
	int64 color;
	if (list->getInt (ChannelContext::kChannelColorKey, color) == kResultTrue)
	{
		//	ColorSpec channelColor = (ColorSpec)color;
	}

	addFeatureLog (kLogIdChannelContextSupported);

	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::getXmlRepresentationStream (
	RepresentationInfo& info /*in*/, IBStream* stream /*out*/)
{
	addFeatureLog (kLogIdIXmlRepresentationControllerSupported);

	String name (info.name);
	if (name == GENERIC_8_CELLS)
	{
		Vst::XmlRepresentationHelper helper (info, "Steinberg Media Technologies",
											 "VST3 Host Checker",
											 HostCheckerProcessor::cid.toTUID (), stream);

		helper.startPage ("Main Page");
		helper.startEndCellOneLayer (Vst::LayerType::kKnob, 0);
		helper.startEndCellOneLayer (Vst::LayerType::kKnob, 1);
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.endPage ();

		helper.startPage ("Page 2");
		helper.startEndCellOneLayer (Vst::LayerType::kSwitch, 2);
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty cell
		helper.startEndCell (); // empty
		helper.endPage ();

		return kResultTrue;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::getMidiControllerAssignment (
	int32 busIndex, int16 channel, CtrlNumber midiControllerNumber, ParamID& id /*out*/)
{
	addFeatureLog (kLogIdIMidiMappingSupported);

	if (busIndex != 0)
		return kResultFalse;

	switch (midiControllerNumber)
	{
		case 10: id = 0; break;

		case 11: id = 2; break;

		case 12: id = 3; break;
	}
	return kResultOk;
}

//-----------------------------------------------------------------------------
int32 PLUGIN_API HostCheckerController::getNoteExpressionCount (int32 busIndex, int16 channel)
{
	addFeatureLog (kLogIdINoteExpressionControllerSupported);
	return 0;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::getNoteExpressionInfo (
	int32 busIndex, int16 channel, int32 noteExpressionIndex, NoteExpressionTypeInfo& info /*out*/)
{
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::getNoteExpressionStringByValue (
	int32 busIndex, int16 channel, NoteExpressionTypeID id,
	NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
{
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerController::getNoteExpressionValueByString (
	int32 busIndex, int16 channel, NoteExpressionTypeID id, const TChar* string /*in*/,
	NoteExpressionValue& valueNormalized /*out*/)
{
	return kResultFalse;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
HostCheckerProcessor::HostCheckerProcessor () { setControllerClass (HostCheckerController::cid); }

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::initialize (FUnknown* context)
{
	tresult result = AudioEffect::initialize (context);
	if (result == kResultOk)
	{
		// addAudioInput (USTRING ("Audio Input"), SpeakerArr::kStereo);
		addAudioOutput (USTRING ("Audio Output"), SpeakerArr::kStereo);
		addEventInput (USTRING ("Event Input"), 1);

		mHostCheck.setComponent (this);
	}
	return result;
}

//------------------------------------------------------------------------
void HostCheckerProcessor::addLogEvent (Steinberg::int32 logId)
{
	mHostCheck.getEventLogger ().addLogEvent (logId);
}

//-----------------------------------------------------------------------------
void HostCheckerProcessor::sendLogEventMessage (const LogEvent& logEvent)
{
	IMessage* message = allocateMessage ();
	FReleaser msgReleaser (message);
	if (message)
	{
		message->setMessageID ("LogEvent");
		IAttributeList* attributes = message->getAttributes ();
		if (attributes)
		{
			ASSERT (logEvent.id >= 0);
			attributes->setInt ("ID", logEvent.id);
			attributes->setInt ("Count", logEvent.count);
			sendMessage (message);
		}
	}
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::setAudioPresentationLatencySamples (
	BusDirection dir, int32 busIndex, uint32 latencyInSamples)
{
	addLogEvent (kLogIdAudioPresentationLatencySamplesSupported);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::getPrefetchableSupport (
	PrefetchableSupport& prefetchable /*out*/)
{
	addLogEvent (kLogIdIPrefetchableSupportSupported);
	prefetchable = kIsYetPrefetchable;
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::process (ProcessData& data)
{
	mHostCheck.validate (data);

	if (data.numSamples && data.numOutputs)
	{
		for (int32 i = 0; i < data.outputs[0].numChannels; i++)
			memset (data.outputs[0].channelBuffers32[i], 0, data.numSamples * sizeof (float));
		data.outputs[0].silenceFlags = 0x3;
	}

	const EventLogger::Codes& errors = mHostCheck.getEventLogs ();
	EventLogger::Codes::const_iterator iter = errors.begin ();
	while (iter != errors.end ())
	{
		if ((*iter).fromProcessor)
			sendLogEventMessage ((*iter));
		++iter;
	}
	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::setupProcessing (ProcessSetup& setup)
{
	mHostCheck.setProcessSetup (setup);
	return AudioEffect::setupProcessing (setup);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::notify (IMessage* message)
{
	if (!message)
		return kInvalidArgument;

	if (FIDStringsEqual (message->getMessageID (), "Parameter"))
	{
		int64 paramId = -1;
		if (message->getAttributes ()->getInt ("ID", paramId) == kResultOk)
		{
			mHostCheck.addParameter (paramId);
		}
	}

	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::setState (IBStream* state)
{
	FUnknownPtr<IStreamAttributes> stream (state);
	if (stream)
	{
		IAttributeList* list = stream->getAttributes ();
		if (list)
		{
			addLogEvent (kLogIdIAttributeListInSetStateSupported);
		}
	}

	float saved = 0.f;
	if (state->read (&saved, sizeof (float)) != kResultOk)
	{
		return kResultFalse;
	}

#if BYTEORDER == kBigEndian
	SWAP_32 (toSave)
#endif
	if (saved != 12345.67f)
	{
		ASSERT (false)
	}
	return kResultOk;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API HostCheckerProcessor::getState (IBStream* state)
{
	if (!state)
		return kResultFalse;

	float toSave = 12345.67f;

#if BYTEORDER == kBigEndian
	SWAP_32 (toSave)
#endif

	state->write (&toSave, sizeof (float));

	return kResultOk;
}

//-----------------------------------------------------------------------------
}
} // namespaces
