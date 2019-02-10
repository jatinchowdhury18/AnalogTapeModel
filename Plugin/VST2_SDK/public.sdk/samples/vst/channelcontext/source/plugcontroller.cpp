//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/channelcontext/source/PlugController.cpp
// Created by  : Steinberg, 02/2014
// Description : Plug Controller Example for VST SDK 3.x
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

#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/base/ustring.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// PlugController Implementation
//------------------------------------------------------------------------
tresult PLUGIN_API PlugController::initialize (FUnknown* context)
{
	tresult result = EditControllerEx1::initialize (context);
	if (result != kResultOk)
	{
		return result;
	}

	//---Create Parameters------------

	//---Bypass parameter---
	int32 stepCount = 1;
	ParamValue defaultVal = 0;
	int32 flags = ParameterInfo::kCanAutomate | ParameterInfo::kIsBypass;
	int32 tag = kBypassId;
	parameters.addParameter (STR16 ("Bypass"), nullptr, stepCount, defaultVal, flags, tag);

	//---Read only parameters
	String128 undefinedStr;
	Steinberg::UString (undefinedStr, 128).fromAscii ("undefined");

	flags = ParameterInfo::kIsReadOnly;
	StringListParameter* strParam =
		NEW StringListParameter (STR16 ("Ch Uid"), kChannelUIDId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Uid Len"), kChannelUIDLengthId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Name"), kChannelNameId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Name Len"), kChannelNameLengthId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Index"), kChannelIndexId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam =
		NEW StringListParameter (STR16 ("Ch Index Namespace Order"), kChannelIndexNamespaceOrderId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam); 
	
	strParam =
		NEW StringListParameter (STR16 ("Ch Index Namespace"), kChannelIndexNamespaceId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Index Namespace Len"),
		kChannelIndexNamespaceLengthId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Color"), kChannelColorId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

	strParam = NEW StringListParameter (STR16 ("Ch Plug Loc."), kChannelPluginLocationId, nullptr, flags);
	strParam->appendString (undefinedStr);
	parameters.addParameter (strParam);

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
tresult PLUGIN_API PlugController::setChannelContextInfos (IAttributeList* list)
{
	if (!list)
		return kResultFalse;

	String128 undefinedStr;
	Steinberg::UString (undefinedStr, 128).fromAscii ("undefined");

	// get the channel name length (optional) where we, as plugin, are instantiated
	StringListParameter* param =
		static_cast<StringListParameter*> (parameters.getParameter (kChannelNameLengthId));
	if (param)
	{
		int64 length;
		if (list->getInt (ChannelContext::kChannelNameLengthKey, length) == kResultTrue)
		{
			String128 string128;
			Steinberg::UString (string128, 128).printInt (length);
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// get the channel name where we, as plugin, are instantiated
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelNameId));
	if (param)
	{
		String128 name;
		if (list->getString (ChannelContext::kChannelNameKey, name, sizeof (name)) == kResultTrue)
			param->replaceString (0, name);
		else
			param->replaceString (0, undefinedStr);
	}

	// get the channel UID Length
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelUIDLengthId));
	if (param)
	{
		int64 length;
		if (list->getInt (ChannelContext::kChannelUIDLengthKey, length) == kResultTrue)
		{
			String128 string128;
			Steinberg::UString (string128, 128).printInt (length);
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// get the channel UID
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelUIDId));
	if (param)
	{
		String128 name;
		if (list->getString (ChannelContext::kChannelUIDKey, name, sizeof (name)) == kResultTrue)
			param->replaceString (0, name);
		else
			param->replaceString (0, undefinedStr);
	}

	// get Channel Index
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelIndexId));
	if (param)
	{
		int64 index;
		if (list->getInt (ChannelContext::kChannelIndexKey, index) == kResultTrue)
		{
			String128 string128;
			Steinberg::UString (string128, 128).printInt (index);
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// get Channel Index Namespace Order
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelIndexNamespaceOrderId));
	if (param)
	{
		int64 index;
		if (list->getInt (ChannelContext::kChannelIndexNamespaceOrderKey, index) == kResultTrue)
		{
			String128 string128;
			Steinberg::UString (string128, 128).printInt (index);
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// get the channel Index Namespace Length
	param = static_cast<StringListParameter*> (
		parameters.getParameter (kChannelIndexNamespaceLengthId));
	if (param)
	{
		int64 length;
		if (list->getInt (ChannelContext::kChannelIndexNamespaceLengthKey, length) == kResultTrue)
		{
			String128 string128;
			Steinberg::UString (string128, 128).printInt (length);
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// get the channel Index Namespace
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelIndexNamespaceId));
	if (param)
	{
		String128 name;
		if (list->getString (ChannelContext::kChannelIndexNamespaceKey, name, sizeof (name)) ==
			kResultTrue)
			param->replaceString (0, name);
		else
			param->replaceString (0, undefinedStr);
	}

	// get Plugin Channel Location
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelPluginLocationId));
	if (param)
	{
		int64 location;
		if (list->getInt (ChannelContext::kChannelPluginLocationKey, location) == kResultTrue)
		{
			String128 string128;
			switch (location)
			{
				case ChannelContext::kPreVolumeFader:
					Steinberg::UString (string128, 128).fromAscii ("PreVolFader");
					break;
				case ChannelContext::kPostVolumeFader:
					Steinberg::UString (string128, 128).fromAscii ("PostVolFader");
					break;
				case ChannelContext::kUsedAsPanner:
					Steinberg::UString (string128, 128).fromAscii ("UsedAsPanner");
					break;
				default: Steinberg::UString (string128, 128).fromAscii ("unknown!"); break;
			}
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// get Channel Color
	param = static_cast<StringListParameter*> (parameters.getParameter (kChannelColorId));
	if (param)
	{
		int64 color;
		if (list->getInt (ChannelContext::kChannelColorKey, color) == kResultTrue)
		{
			//	Color channelColor = (uint32)color;
			uint32 channelColor = (uint32)color;
			String str;
			str.printf ("%x%x%x%x", ChannelContext::GetAlpha (channelColor),
						ChannelContext::GetRed (channelColor),
						ChannelContext::GetGreen (channelColor),
						ChannelContext::GetBlue (channelColor));
			String128 string128;
			Steinberg::UString (string128, 128).fromAscii (str);
			param->replaceString (0, string128);
		}
		else
			param->replaceString (0, undefinedStr);
	}

	// we have to inform the host that our strings have changed (values not)
	if (componentHandler)
		componentHandler->restartComponent (kParamValuesChanged);

	return kResultTrue;
}
}
} // namespaces
