//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/pitchnames/source/pitchnames.cpp
// Created by  : Steinberg, 12/2010
// Description : A VST 3 instrument which shows the usage of pitch names for the most simple
//				case that only the root Unit is defined
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

#include "pitchnames.h"
#include "pitchnamesdatabrowsersource.h"
#include "pluginterfaces/base/ustring.h"

using namespace VSTGUI;

#define MULTI_CHANNEL_SCENARIO	1

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
FUID PitchNamesController::cid (0xB9123C35, 0x0FFD404C, 0x826774E0, 0x00819A0C);
FUID PitchNamesProcessor::cid (0x32ECDB17, 0xD0894B22, 0xAF9759F8, 0xF5D58DD4);

#if MULTI_CHANNEL_SCENARIO
static ProgramListID kProgramList0ID = 0;
static ProgramListID kProgramList1ID = 1;
static UnitID kChannel0UnitId = 'ch00';
static UnitID kChannel1UnitId = 'ch01';

#else
static ProgramListID kProgramListID = 0;

#endif

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
tresult PLUGIN_API PitchNamesController::initialize (FUnknown* context)
{
	tresult result = EditControllerEx1::initialize (context);
	if (result == kResultOk)
	{
	#if MULTI_CHANNEL_SCENARIO
		addUnit (new Unit (String ("Root"), kRootUnitId, kNoParentUnitId));
		addUnit (new Unit (String ("Channel 0"), kChannel0UnitId, kRootUnitId, kProgramList0ID));
		addUnit (new Unit (String ("Channel 1"), kChannel1UnitId, kRootUnitId, kProgramList1ID));

		ProgramListWithPitchNames* list = new ProgramListWithPitchNames (String ("ProgramList 0"), kProgramList0ID, kChannel0UnitId);
		list->addProgram (String ("Init 1"));
		list->setPitchName (0, 0, String ("Channel 0 First Item"));
		addProgramList (list);
		parameters.addParameter (list->getParameter ());

		list = new ProgramListWithPitchNames (String ("ProgramList 1"), kProgramList1ID, kChannel1UnitId);
		list->addProgram (String ("Init 1"));
		list->setPitchName (0, 0, String ("Channel 1 First Item"));
		addProgramList (list);
		parameters.addParameter (list->getParameter ());

	#else
		addUnit (new Unit (String ("Root"), kRootUnitId, kNoParentUnitId, kProgramListID));
		ProgramListWithPitchNames* list = new ProgramListWithPitchNames (String ("ProgramList"), kProgramListID, kRootUnitId);
		list->addProgram (String ("Init 1"));
		list->setPitchName (0, 38, String ("Snare"));
		list->setPitchName (0, 42, String ("Closed Hi-Hat"));
		list->setPitchName (0, 45, String ("Low Tom"));
		
		addProgramList (list);
		
		parameters.addParameter (list->getParameter ());

	#endif
	}
	return result;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PitchNamesController::getUnitByBus (MediaType type, BusDirection dir, int32 busIndex, int32 channel, UnitID& unitId /*out*/)
{
	if (type == kEvent && dir == kInput)
	{
	#if MULTI_CHANNEL_SCENARIO
		if (busIndex == 0)
		{
			if (channel == 0)
			{
				unitId = kChannel0UnitId;
				return kResultTrue;
			}
			else if (channel == 1)
			{
				unitId = kChannel1UnitId;
				return kResultTrue;
			}
		}
	#else
		if (busIndex == 0 && channel == 0)
		{
			unitId = kRootUnitId;
			return kResultTrue;
		}
	#endif
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
IPlugView* PLUGIN_API PitchNamesController::createView (FIDString name)
{
	if (ConstString (name) == ViewType::kEditor)
	{
		return new VST3Editor (this, "PitchNamesEditor", "pitchnames.uidesc");
	}
	return 0;
}

//-----------------------------------------------------------------------------
CView* PitchNamesController::createCustomView (UTF8StringPtr name, const UIAttributes& attributes, IUIDescription* description, VST3Editor* editor)
{
#if MULTI_CHANNEL_SCENARIO
	if (ConstString (name) == "PitchNamesDataBrowser")
	{
		IDataBrowser* dataSource = new PitchNamesDataBrowserSource (this, kChannel0UnitId);
		return new CDataBrowser (CRect (0, 0, 100, 100), 0, dataSource, CDataBrowser::kDrawRowLines|CDataBrowser::kDrawColumnLines|CDataBrowser::kDrawHeader|CDataBrowser::kVerticalScrollbar);
	}
#else
	if (ConstString (name) == "PitchNamesDataBrowser")
	{
		IDataBrowser* dataSource = new PitchNamesDataBrowserSource (this, kRootUnitId);
		return new CDataBrowser (CRect (0, 0, 100, 100), 0, dataSource, CDataBrowser::kDrawRowLines|CDataBrowser::kDrawColumnLines|CDataBrowser::kDrawHeader|CDataBrowser::kVerticalScrollbar);
	}
#endif
	return 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
PitchNamesProcessor::PitchNamesProcessor ()
{
	setControllerClass (PitchNamesController::cid);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PitchNamesProcessor::initialize (FUnknown* context)
{
	tresult result = AudioEffect::initialize (context);
	if (result == kResultOk)
	{
		addAudioOutput (USTRING("Audio Output"), SpeakerArr::kStereo);
	#if MULTI_CHANNEL_SCENARIO
		addEventInput (USTRING("Event Input"), 2);
	#else
		addEventInput (USTRING("Event Input"), 1);
	#endif
	}
	return result;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API PitchNamesProcessor::process (ProcessData& data)
{
	if (data.numSamples && data.numOutputs)
	{
		for (int32 i = 0; i < data.outputs[0].numChannels; i++)
			memset (data.outputs[0].channelBuffers32[i], 0, data.numSamples * sizeof (float));
		data.outputs[0].silenceFlags = 0x3;
	}
	return kResultOk;
}

}} // namespaces
