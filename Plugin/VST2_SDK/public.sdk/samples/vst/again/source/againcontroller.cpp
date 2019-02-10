//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/againcontroller.cpp
// Created by  : Steinberg, 04/2005
// Description : AGain Controller Example for VST 3
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

#include "againcontroller.h"
#include "againparamids.h"
#include "againeditor.h"

#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/vst/ivstmidicontrollers.h"

#include "base/source/fstring.h"

#include <stdio.h>
#include <math.h>

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// GainParameter Declaration
// example of custom parameter (overwriting to and fromString)
//------------------------------------------------------------------------
class GainParameter : public Parameter
{
public:
	GainParameter (int32 flags, int32 id);

	virtual void toString (ParamValue normValue, String128 string) const;
	virtual bool fromString (const TChar* string, ParamValue& normValue) const;
};

//------------------------------------------------------------------------
// GainParameter Implementation
//------------------------------------------------------------------------
GainParameter::GainParameter (int32 flags, int32 id)
{
	Steinberg::UString (info.title, USTRINGSIZE (info.title)).assign (USTRING ("Gain"));
	Steinberg::UString (info.units, USTRINGSIZE (info.units)).assign (USTRING ("dB"));
	
	info.flags = flags;
	info.id = id;
	info.stepCount = 0;
	info.defaultNormalizedValue = 0.5f;
	info.unitId = kRootUnitId;
	
	setNormalized (1.f);
}

//------------------------------------------------------------------------
void GainParameter::toString (ParamValue normValue, String128 string) const
{
	char text[32];
	if (normValue > 0.0001)
	{
		sprintf (text, "%.2f", 20 * log10f ((float)normValue));
	}
	else
	{
		strcpy (text, "-oo");
	}

	Steinberg::UString (string, 128).fromAscii (text);
}

//------------------------------------------------------------------------
bool GainParameter::fromString (const TChar* string, ParamValue& normValue) const
{
	String wrapper ((TChar*)string); // don't know buffer size here!
	double tmp = 0.0;
	if (wrapper.scanFloat (tmp))
	{
		// allow only values between -oo and 0dB
		if (tmp > 0.0)
		{
			tmp = -tmp;
		}

		normValue = expf (logf (10.f) * (float)tmp / 20.f);
		return true;
	}
	return false;
}


//------------------------------------------------------------------------
// AGainController Implementation
//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::initialize (FUnknown* context)
{
	tresult result = EditControllerEx1::initialize (context);
	if (result != kResultOk)
	{
		return result;
	}

	//--- Create Units-------------
	UnitInfo unitInfo;
	Unit* unit;

	// create root only if you want to use the programListId
/*	unitInfo.id = kRootUnitId;	// always for Root Unit
	unitInfo.parentUnitId = kNoParentUnitId;	// always for Root Unit
	Steinberg::UString (unitInfo.name, USTRINGSIZE (unitInfo.name)).assign (USTRING ("Root"));
	unitInfo.programListId = kNoProgramListId;
	
	unit = new Unit (unitInfo);
	addUnitInfo (unit);*/

	// create a unit1 for the gain
	unitInfo.id = 1;
	unitInfo.parentUnitId = kRootUnitId;	// attached to the root unit
	
	Steinberg::UString (unitInfo.name, USTRINGSIZE (unitInfo.name)).assign (USTRING ("Unit1"));
	
	unitInfo.programListId = kNoProgramListId;
	
	unit = new Unit (unitInfo);
	addUnit (unit);

	//---Create Parameters------------
	
	//---Gain parameter--
	GainParameter* gainParam = new GainParameter (ParameterInfo::kCanAutomate, kGainId);
	parameters.addParameter (gainParam);

	gainParam->setUnitID (1);

	//---VuMeter parameter---
	int32 stepCount = 0;
	ParamValue defaultVal = 0;
	int32 flags = ParameterInfo::kIsReadOnly;
	int32 tag = kVuPPMId;
	parameters.addParameter (STR16 ("VuPPM"), 0, stepCount, defaultVal, flags, tag);

	//---Bypass parameter---
	stepCount = 1;
	defaultVal = 0;
	flags = ParameterInfo::kCanAutomate|ParameterInfo::kIsBypass;
	tag = kBypassId;
	parameters.addParameter (STR16 ("Bypass"), 0, stepCount, defaultVal, flags, tag);

	//---Custom state init------------

	String str ("Hello World!");
	str.copyTo16 (defaultMessageText, 0, 127);
	
	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::terminate  ()
{
	viewsArray.removeAll ();
	
	return EditControllerEx1::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::setComponentState (IBStream* state)
{
	// we receive the current state of the component (processor part)
	// we read only the gain and bypass value...
	if (state)
	{
		float savedGain = 0.f;
		if (state->read (&savedGain, sizeof (float)) != kResultOk)
		{
			return kResultFalse;
		}

	#if BYTEORDER == kBigEndian
		SWAP_32 (savedGain)
	#endif
		setParamNormalized (kGainId, savedGain);

		// jump the GainReduction
		state->seek (sizeof (float), IBStream::kIBSeekCur);
	
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
IPlugView* PLUGIN_API AGainController::createView (const char* name)
{
	// someone wants my editor
	if (name && strcmp (name, "editor") == 0)
	{
		AGainEditorView* view = new AGainEditorView (this);
		return view;
	}
	return 0;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::setState (IBStream* state)
{
	tresult result = kResultFalse;

	int8 byteOrder;
	if ((result = state->read (&byteOrder, sizeof (int8))) != kResultTrue)
	{
		return result;
	}
	if ((result = state->read (defaultMessageText, 128 * sizeof (TChar))) != kResultTrue)
	{
		return result;
	}

	// if the byteorder doesn't match, byte swap the text array ...
	if (byteOrder != BYTEORDER)
	{
		for (int32 i = 0; i < 128; i++)
		{
			SWAP_16 (defaultMessageText[i])
		}
	}

	// update our editors
	for (int32 i = 0; i < viewsArray.total (); i++)
	{
		if (viewsArray.at (i))
		{
			viewsArray.at (i)->messageTextChanged ();
		}
	}
	
	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::getState (IBStream* state)
{
	// here we can save UI settings for example

	// as we save a Unicode string, we must know the byteorder when setState is called
	int8 byteOrder = BYTEORDER;
	if (state->write (&byteOrder, sizeof (int8)) == kResultTrue)
	{
		return state->write (defaultMessageText, 128 * sizeof (TChar));
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult AGainController::receiveText (const char* text)
{
	// received from Component
	if (text)
	{
		fprintf (stderr, "[AGainController] received: ");
		fprintf (stderr, "%s", text);
		fprintf (stderr, "\n");
	}
	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::setParamNormalized (ParamID tag, ParamValue value)
{
	// called from host to update our parameters state
	tresult result = EditControllerEx1::setParamNormalized (tag, value);
	
	for (int32 i = 0; i < viewsArray.total (); i++)
	{
		if (viewsArray.at (i))
		{
			viewsArray.at (i)->update (tag, value);
		}
	}

	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	/* example, but better to use a custom Parameter as seen in GainParameter
	switch (tag)
	{
		case kGainId:
		{
			char text[32];
			if (valueNormalized > 0.0001)
			{
				sprintf (text, "%.2f", 20 * log10f ((float)valueNormalized));
			}
			else
				strcpy (text, "-oo");

			Steinberg::UString (string, 128).fromAscii (text);

			return kResultTrue;
		}
	}*/
	return EditControllerEx1::getParamStringByValue (tag, valueNormalized, string);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	/* example, but better to use a custom Parameter as seen in GainParameter
	switch (tag)
	{
		case kGainId:
		{
			Steinberg::UString wrapper ((TChar*)string, -1); // don't know buffer size here!
			double tmp = 0.0;
			if (wrapper.scanFloat (tmp))
			{
				valueNormalized = expf (logf (10.f) * (float)tmp / 20.f);
				return kResultTrue;
			}
			return kResultFalse;
		}
	}*/
	return EditControllerEx1::getParamValueByString (tag, string, valueNormalized);
}

//------------------------------------------------------------------------
void AGainController::addDependentView (AGainEditorView* view)
{
	viewsArray.add (view);
}

//------------------------------------------------------------------------
void AGainController::removeDependentView (AGainEditorView* view)
{
	for (int32 i = 0; i < viewsArray.total (); i++)
	{
		if (viewsArray.at (i) == view)
		{
			viewsArray.removeAt (i);
			break;
		}
	}
}

//------------------------------------------------------------------------
void AGainController::editorAttached (EditorView* editor)
{
	AGainEditorView* view = dynamic_cast<AGainEditorView*> (editor);
	if (view)
	{
		addDependentView (view);
	}
}

//------------------------------------------------------------------------
void AGainController::editorRemoved (EditorView* editor)
{
	AGainEditorView* view = dynamic_cast<AGainEditorView*> (editor);
	if (view)
	{
		removeDependentView (view);
	}
}

//------------------------------------------------------------------------
void AGainController::setDefaultMessageText (String128 text)
{
	String tmp (text);
	tmp.copyTo16 (defaultMessageText, 0, 127);
}

//------------------------------------------------------------------------
TChar* AGainController::getDefaultMessageText ()
{
	return defaultMessageText;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::queryInterface (const char* iid, void** obj)
{
	QUERY_INTERFACE (iid, obj, IMidiMapping::iid, IMidiMapping)
	return EditControllerEx1::queryInterface (iid, obj);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainController::getMidiControllerAssignment (int32 busIndex, int16 /*midiChannel*/,
																 CtrlNumber midiControllerNumber, ParamID& tag)
{
	// we support for the Gain parameter all MIDI Channel but only first bus (there is only one!)
	if (busIndex == 0 && midiControllerNumber == kCtrlVolume)
	{
		tag = kGainId;
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
