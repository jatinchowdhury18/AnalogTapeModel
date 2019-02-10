/*
 *  mdaBaseController.cpp
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

#include "mdaBaseController.h"
#include "mdaParameter.h"
#include "helpers.h"
#include "pluginterfaces/base/ibstream.h"

namespace Steinberg {
namespace Vst {
namespace mda {

const TChar BaseController::kMicroSecondsString[] = { 0x00b5, 0x0073, 0x0 };

//-----------------------------------------------------------------------------
BaseController::BaseController ()
: sampleRate (44100)
, addBypassParameter (true)
{
	for (int32 i = 0; i < kCountCtrlNumber; i++)
		midiCCParamID[i] = -1;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseController::initialize (FUnknown* context)
{
	tresult res = EditControllerEx1::initialize (context);
	if (res == kResultOk)
	{
		UnitInfo uinfo;
		uinfo.id = kRootUnitId;
		uinfo.parentUnitId = kNoParentUnitId;
		uinfo.programListId = kPresetParam;
		UString name (uinfo.name, 128);
		name.fromAscii("Root");
		addUnit (new Unit (uinfo));

		if (addBypassParameter)
		{
			IndexedParameter* bypassParam = new IndexedParameter (USTRING("Bypass"), 0, 1, 0, ParameterInfo::kIsBypass | ParameterInfo::kCanAutomate, kBypassParam);
			bypassParam->setIndexString (0, UString128 ("off"));
			bypassParam->setIndexString (1, UString128 ("on"));
			parameters.addParameter (bypassParam);
		}
	}
	return res;
}

//-----------------------------------------------------------------------------
int32 PLUGIN_API BaseController::getProgramListCount ()
{
	if (parameters.getParameter (kPresetParam))
		return 1;
	return 0;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseController::getProgramListInfo (int32 listIndex, ProgramListInfo& info /*out*/)
{
	Parameter* param = parameters.getParameter (kPresetParam);
	if (param && listIndex == 0)
	{
		info.id = kPresetParam;
		info.programCount = (int32)param->toPlain (1) + 1;
		UString name (info.name, 128);
		name.fromAscii("Presets");
		return kResultTrue;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseController::getProgramName (ProgramListID listId, int32 programIndex, String128 name /*out*/)
{
	if (listId == kPresetParam)
	{
		Parameter* param = parameters.getParameter (kPresetParam);
		if (param)
		{
			ParamValue normalized = param->toNormalized (programIndex);
			param->toString (normalized, name);
			return kResultTrue;
		}
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseController::notify (IMessage* message)
{
	if (strcmp (message->getMessageID(), "activated") == 0)
	{
		message->getAttributes()->getFloat ("SampleRate", sampleRate);
		return kResultTrue;
	}
	return EditControllerEx1::notify (message);
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API BaseController::setComponentState (IBStream* state)
{
	int32 temp;
	state->read (&temp, sizeof (int32));
	SWAP32_BE(temp);
	for (int32 i = 0; i < temp; i++)
	{
		ParamValue value;
		if (state->read (&value, sizeof (ParamValue)) == kResultTrue)
		{
			SWAP64_BE(value);
			setParamNormalized (i, value);
		}
	}
	int32 bypassState;
	if (state->read (&bypassState, sizeof (bypassState)) == kResultTrue)
	{
		Parameter* bypassParam = parameters.getParameter (kBypassParam);
		if (bypassParam)
		{
			SWAP32_BE(bypassState);
			bypassParam->setNormalized (bypassState);
		}
	}
	
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API BaseController::getMidiControllerAssignment (int32 busIndex, int16 channel, CtrlNumber midiControllerNumber, ParamID& tag/*out*/)
{
	if (busIndex == 0 && midiCCParamID[midiControllerNumber] != -1)
	{
		tag = midiCCParamID[midiControllerNumber];
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API BaseController::queryInterface (const char* iid, void** obj)
{
	QUERY_INTERFACE (iid, obj, IMidiMapping::iid, IMidiMapping)
	return EditControllerEx1::queryInterface (iid, obj);
}

}}} // namespaces
