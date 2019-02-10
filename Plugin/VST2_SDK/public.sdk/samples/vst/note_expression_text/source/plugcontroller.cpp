//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/PlugController.cpp
// Created by  : Steinberg, 04/2005
// Description : Plug Controller Example for VST 3
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

#include "plugcontroller.h"
#include "plugparamids.h"
#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/ibstream.h"


namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// PlugController Implementation
//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::initialize (FUnknown* context)
{
	mTextLabel = 0;
	
	tresult result = EditControllerEx1::initialize (context);
	if (result != kResultOk)
	{
		return result;
	}

	//---Create Parameters------------

	//---Bypass parameter---
	int32 stepCount = 1;
	ParamValue defaultVal = 0;
	int32 flags = ParameterInfo::kCanAutomate|ParameterInfo::kIsBypass;
	int32 tag = kBypassId;
	parameters.addParameter (STR16 ("Bypass"), 0, stepCount, defaultVal, flags, tag);


	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::setComponentState (IBStream* state)
{
	// we receive the current state of the component (processor part)
	// we read only the gain and bypass value...
	if (state)
	{
		// read the bypass
		int32 bypassState;
		if (state->read (&bypassState, sizeof (bypassState)) == kResultTrue)
		{
		#if BYTEORDER == kBigEndian
			SWAP_32 (bypassState)
		#endif
			setParamNormalized (kBypassId, bypassState ? 1 : 0);
		}
	}

	return kResultOk;
}

//------------------------------------------------------------------------
IPlugView* PLUGIN_API PlugController::createView (const char* name)
{
	// someone wants my editor
	if (name && strcmp (name, "editor") == 0)
	{
		return new VST3Editor (this, "Editor", "plug.uidesc");
	}
	return 0;
}

//------------------------------------------------------------------------
CView* PlugController::createCustomView (UTF8StringPtr name, const UIAttributes& attributes, IUIDescription* description, VST3Editor* editor)
{
	if (name && strcmp (name, "NoteExpressionText") == 0)
	{
		CRect size;
		mTextLabel = new CTextLabel (size);
		return mTextLabel;
	}
	return 0;
}

//------------------------------------------------------------------------
void PlugController::willClose (VST3Editor* editor) 
{
	mTextLabel = 0;
}

//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::notify (IMessage* message)
{
	if (!message)
		return kInvalidArgument;

	if (!strcmp (message->getMessageID (), "TextMessage") && mTextLabel)
	{
		TChar string[256] = {0};
		if (message->getAttributes ()->getString ("Text", string, sizeof (string) / sizeof (char16)) == kResultOk)
		{
			char8 cstr[256];
			String tmp (string);
			tmp.copyTo8 (cstr, 0, 255);
			mTextLabel->setText (cstr);
			return kResultOk;
		}
	}

	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PlugController::receiveText (const char8* text)
{
	if (mTextLabel)
		mTextLabel->setText (text);
	return kResultOk;
}


//------------------------------------------------------------------------
int32 PLUGIN_API PlugController::getNoteExpressionCount (int32 busIndex, int16 channel)
{
	if (busIndex == 0 && channel == 0)
		return 2;
	return 0;
}

//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::getNoteExpressionInfo (int32 busIndex, int16 channel, int32 noteExpressionIndex, NoteExpressionTypeInfo& info /*out*/)
{
	if (busIndex == 0 && channel == 0)
	{
		if (noteExpressionIndex == 0)
		{
			info.typeId = kTextTypeID;
			UString128 ("Lyrics").copyTo (info.title, 128);
			UString128 ("Lyrics").copyTo (info.shortTitle, 128);
			UString128 ("").copyTo (info.units, 128);
			info.unitId = -1;
			info.associatedParameterId = -1;
			info.flags = 0;	
		}
		else if (noteExpressionIndex == 1)
		{
			info.typeId = kTextTypeID;
			UString128 ("Phoneme").copyTo (info.title, 128);
			UString128 ("Phoneme").copyTo (info.shortTitle, 128);
			UString128 ("").copyTo (info.units, 128);
			info.unitId = -1;
			info.associatedParameterId = -1;
			info.flags = 0;	
		}
		return kResultTrue;
	}

	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::getNoteExpressionStringByValue (int32 busIndex, int16 channel, NoteExpressionTypeID id, NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
{
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::getNoteExpressionValueByString (int32 busIndex, int16 channel, NoteExpressionTypeID id, const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
{
	return kResultFalse;
}

}} // namespaces
