//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/againsimple.cpp
// Created by  : Steinberg, 04/2005
// Description : AGain Example for VST SDK 3.0
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

#include "againsimple.h"	
#include "againparamids.h"
#include "version.h"	// for versionning

#include "public.sdk/source/main/pluginfactoryvst3.h"

#include "pluginterfaces/base/ibstream.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"
#include "pluginterfaces/vst/ivstevents.h"
#include "pluginterfaces/base/ustring.h"

#include <stdio.h>
#include <math.h>

#define AGAIN_TEST 1 // this allows to enable the communication example between again and its controller

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
		sprintf (text, "%.2f", 20 * log10f ((float)normValue));
	else
		strcpy (text, "-oo");

	Steinberg::UString (string, 128).fromAscii (text);
}

//------------------------------------------------------------------------
bool GainParameter::fromString (const TChar* string, ParamValue& normValue) const
{
	Steinberg::UString wrapper ((TChar*)string, -1); // don't know buffer size here!
	double tmp = 0.0;
	if (wrapper.scanFloat (tmp))
	{
		// allow only values between -oo and 0dB
		if (tmp > 0.0)
			tmp = -tmp;

		normValue = expf (logf (10.f) * (float)tmp / 20.f);
		return true;
	}
	return false;
}




//------------------------------------------------------------------------
// AGain Implementation
//------------------------------------------------------------------------
AGainSimple::AGainSimple ()
: fGain (1.f)
, fGainReduction (0.f)
, fVuPPMOld (0.f)
, currentProcessMode (-1) // -1 means not initialized
, bHalfGain (false)
, bBypass (false)
{
}


//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::initialize (FUnknown* context)
{
	tresult result = SingleComponentEffect::initialize (context);
	if (result != kResultOk)
		return result;

	//---create Audio In/Out buses------
	// we want a stereo Input and a Stereo Output
	addAudioInput  (USTRING ("Stereo In"),  SpeakerArr::kStereo);
	addAudioOutput (USTRING ("Stereo Out"), SpeakerArr::kStereo);

	//---create MIDI In/Out buses (1 bus with only 1 channel)------
	addEventInput (USTRING ("MIDI In"), 1);


	//---Create Parameters------------
	
	//---Gain parameter--
	GainParameter* gainParam = new GainParameter (ParameterInfo::kCanAutomate, kGainId);
	parameters.addParameter (gainParam);

	//---VuMeter parameter---
	int32 stepCount = 0;
	ParamValue defaultVal = 0;
	int32 flags = ParameterInfo::kIsReadOnly;
	int32 tag = kVuPPMId;
	parameters.addParameter (USTRING ("VuPPM"), 0, stepCount, defaultVal, flags, tag);

	//---Bypass parameter---
	stepCount = 1;
	defaultVal = 0;
	flags = ParameterInfo::kCanAutomate|ParameterInfo::kIsBypass;
	tag = kBypassId;
	parameters.addParameter (USTRING ("Bypass"), 0, stepCount, defaultVal, flags, tag);

	//---Custom state init------------

	UString str (defaultMessageText, 128);
	str.fromAscii ("Hello World!");
	
	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::terminate  ()
{
	viewsArray.removeAll ();
	
	return SingleComponentEffect::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::setActive (TBool state)
{
#if AGAIN_TEST
	if (state)
		fprintf (stderr, "[AGainSimple] Activated \n");
	else
		fprintf (stderr, "[AGainSimple] Deactivated \n");
#endif
	
	// reset the VuMeter value
	fVuPPMOld = 0.f;

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::process (ProcessData& data)
{
	// finally the process function
	// In this example there are 4 steps:
	// 1) Read inputs parameters coming from host (in order to adapt our model values)
	// 2) Read inputs events coming from host (we apply a gain reduction depending of the velocity of pressed key)
	// 3) Process the gain of the input buffer to the output buffer
	// 4) Write the new VUmeter value to the output Parameters queue


	//---1) Read inputs parameter changes-----------
	IParameterChanges* paramChanges = data.inputParameterChanges;
	if (paramChanges)
	{
		int32 numParamsChanged = paramChanges->getParameterCount ();
		// for each parameter which are some changes in this audio block:
		for (int32 i = 0; i < numParamsChanged; i++)
		{
			IParamValueQueue* paramQueue = paramChanges->getParameterData (i);
			if (paramQueue)
			{
				int32 offsetSamples;
				double value;
				int32 numPoints = paramQueue->getPointCount ();				
				switch (paramQueue->getParameterId ())
				{
					case kGainId:
						// we use in this example only the last point of the queue.
						// in some wanted case for specific kind of parameter it makes sense to retrieve all points
						// and process the whole audio block in small blocks.
						if (paramQueue->getPoint (numPoints - 1,  offsetSamples, value) == kResultTrue)
							fGain = (float)value;
						break;

					case kBypassId:
						if (paramQueue->getPoint (numPoints - 1,  offsetSamples, value) == kResultTrue)
							bBypass = (value > 0.5f);
						break;
				}
			}
		}
	}
	
	//---2) Read input events-------------
	IEventList* eventList = data.inputEvents;
	if (eventList) 
	{
		int32 numEvent = eventList->getEventCount ();
		for (int32 i = 0; i < numEvent; i++)
		{
			Event event;
			if (eventList->getEvent (i, event) == kResultOk)
			{
				switch (event.type)
				{
					//----------------------
					case Event::kNoteOnEvent:
						// use the velocity as gain modifier
						fGainReduction = event.noteOn.velocity;
						break;
					
					//----------------------
					case Event::kNoteOffEvent:
						// noteOff reset the reduction
						fGainReduction = 0.f;
						break;
				}
			}
		}
	}
		
	//-------------------------------------
	//---3) Process Audio---------------------
	//-------------------------------------
	if (data.numInputs == 0 || data.numOutputs == 0)
	{
		// nothing to do
		return kResultOk;
	}

	// (simplification) we suppose in this example that we have the same input channel count than the output
	int32 numChannels = data.inputs[0].numChannels;
	//---get audio buffers----------------
	float** in  = data.inputs[0].channelBuffers32;
	float** out = data.outputs[0].channelBuffers32;

	//---check if silence---------------
	// normally we have to check each channel (simplification)
	if (data.inputs[0].silenceFlags != 0)
	{
		// mark output silence too
		data.outputs[0].silenceFlags = data.inputs[0].silenceFlags;
		
		// the Plug-in has to be sure that if it sets the flags silence that the output buffer are clear
		int32 sampleFrames = data.numSamples;
		for (int32 i = 0; i < numChannels; i++)
		{
			// dont need to be cleared if the buffers are the same (in this case input buffer are already cleared by the host)
			if (in[i] != out[i])
			{
				memset (out[i], 0, sampleFrames * sizeof (float));
			}
		}

		// nothing to do at this point
		return kResultOk;
	}

	// mark our outputs has not silent
	data.outputs[0].silenceFlags = 0;

	//---in bypass mode outputs should be like inputs-----
	if (bBypass)
	{
		int32 sampleFrames = data.numSamples;
		for (int32 i = 0; i < numChannels; i++)
		{
			// dont need to be copied if the buffers are the same
			if (in[i] != out[i])
				memcpy (out[i], in[i], sampleFrames * sizeof (float));
		}
		// in this example we dont update the VuMeter in Bypass
	}
	else
	{
		float fVuPPM = 0.f;

		//---apply gain factor----------
		float gain = (fGain - fGainReduction);
		if (bHalfGain)
		{
			gain = gain * 0.5f;
		}

		if (gain < 0.0000001)
		{
			int32 sampleFrames = data.numSamples;
			for (int32 i = 0; i < numChannels; i++)
			{
				memset (out[i], 0, sampleFrames * sizeof (float));
			}
			data.outputs[0].silenceFlags = (1 << numChannels) - 1;  // this will set to 1 all channels
			fVuPPM = 0.f;
		}
		else
		{
			// in real Plug-in it would be better to do dezippering to avoid jump (click) in gain value
			for (int32 i = 0; i < numChannels; i++)
			{
				int32 sampleFrames = data.numSamples;
				float* ptrIn  = in[i];
				float* ptrOut = out[i];
				float tmp;
				while (--sampleFrames >= 0)
				{
					// apply gain
					tmp = (*ptrIn++) * gain;
					(*ptrOut++) = tmp;

					// check only positiv values
					if (tmp > fVuPPM)
						fVuPPM = tmp;
				}
			}
		}

		//---3) Write outputs parameter changes-----------
		IParameterChanges* paramChanges = data.outputParameterChanges;
		// a new value of VuMeter will be send to the host 
		// (the host will send it back in sync to our controller for updating our editor)
		if (paramChanges && fVuPPMOld != fVuPPM)
		{
			int32 index = 0;
			IParamValueQueue* paramQueue = paramChanges->addParameterData (kVuPPMId, index);
			if (paramQueue)
			{
				int32 index2 = 0;
				paramQueue->addPoint (0, fVuPPM, index2); 
			}
		}
		fVuPPMOld = fVuPPM;
	}

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::setState (IBStream* state)
{
	// we receive the current  (processor part)
	if (state)
	{
		float savedGain = 0.f;
		if (state->read (&savedGain, 4) != kResultOk)
			return kResultFalse;

		float savedGainReduction = 0.f;
		if (state->read (&savedGainReduction, 4) != kResultOk)
			return kResultFalse;

		#if BYTEORDER == kBigEndian
			SWAP_32 (savedGain)
			SWAP_32 (savedGainReduction)
		#endif

		fGain = savedGain;
		fGainReduction = savedGainReduction;

		setParamNormalized (kGainId, savedGain);
	}

	return kResultOk;
}


//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::getState (IBStream* state)
{
	float savedGain = fGain;
	float savedGainReduction = fGainReduction;

#if BYTEORDER == kBigEndian
	SWAP_32 (savedGain)
	SWAP_32 (savedGainReduction)
#endif

	state->write (&savedGain, 4);
	return state->write (&savedGainReduction, 4);
}


//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::setupProcessing (ProcessSetup& newSetup)
{
	currentProcessMode = newSetup.processMode;
	
	return SingleComponentEffect::setupProcessing (newSetup);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts)
{
	if (numIns == 1 && numOuts == 1)
	{
		if (inputs[0] == SpeakerArr::kMono && outputs[0] == SpeakerArr::kMono)
		{
			AudioBus* bus = FCast<AudioBus> (audioInputs.at (0));
			if (bus)
			{
				if (bus->getArrangement () != SpeakerArr::kMono)
				{
					removeAudioBusses ();
					addAudioInput  (USTRING ("Mono In"),  SpeakerArr::kMono);
					addAudioOutput (USTRING ("Mono Out"), SpeakerArr::kMono);
				}
				return kResultOk;
			}
		}
		else
		{
			AudioBus* bus = FCast<AudioBus> (audioInputs.at (0));
			if (bus)
			{
				if (bus->getArrangement () != SpeakerArr::kStereo)
				{
					removeAudioBusses ();
					addAudioInput  (USTRING ("Stereo In"),  SpeakerArr::kStereo);
					addAudioOutput (USTRING ("Stereo Out"), SpeakerArr::kStereo);
				}
				return kResultOk;
			}
		}
	}
	return kResultFalse;
}


//------------------------------------------------------------------------
IPlugView* PLUGIN_API AGainSimple::createView (const char* name)
{
	// someone wants my editor
	if (name && strcmp (name, ViewType::kEditor) == 0)
	{
		AGainEditorView* view = new AGainEditorView (this);
		return view;
	}
	return 0;
}


//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::setEditorState (IBStream* state)
{
	tresult result = kResultFalse;

	int8 byteOrder;
	if ((result = state->read (&byteOrder, sizeof (int8))) != kResultTrue)
		return result;
	if ((result = state->read (defaultMessageText, 128 * sizeof (TChar))) != kResultTrue)
		return result;

	// if the byteorder doesn't match, byte swap the text array ...
	if (byteOrder != BYTEORDER)
	{
		for (int32 i = 0; i < 128; i++)
			SWAP_16 (defaultMessageText[i])
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
tresult PLUGIN_API AGainSimple::getEditorState (IBStream* state)
{
	// here we can save UI settings for example

	// as we save a Unicode string, we must know the byteorder when setState is called
	int8 byteOrder = BYTEORDER;
	if (state->write (&byteOrder, sizeof (int8)) == kResultTrue)
		return state->write (defaultMessageText, 128 * sizeof (TChar));
	
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::setParamNormalized (ParamID tag, ParamValue value)
{
	// called from host to update our parameters state
	tresult result = SingleComponentEffect::setParamNormalized (tag, value);
	
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
tresult PLUGIN_API AGainSimple::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	return SingleComponentEffect::getParamStringByValue (tag, valueNormalized, string);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainSimple::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	return SingleComponentEffect::getParamValueByString (tag, string, valueNormalized);
}

//------------------------------------------------------------------------
void AGainSimple::addDependentView (AGainEditorView* view)
{
	viewsArray.add (view);
}

//------------------------------------------------------------------------
void AGainSimple::removeDependentView (AGainEditorView* view)
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
void AGainSimple::editorAttached (EditorView* editor)
{
	AGainEditorView* view = dynamic_cast<AGainEditorView*> (editor);
	if (view)
	{
		addDependentView (view);
	}
}

//------------------------------------------------------------------------
void AGainSimple::editorRemoved (EditorView* editor)
{
	AGainEditorView* view = dynamic_cast<AGainEditorView*> (editor);
	if (view)
	{
		removeDependentView (view);
	}
}


//------------------------------------------------------------------------
void AGainSimple::setDefaultMessageText (String128 text)
{
	UString str (defaultMessageText, 128);
	str.assign (text, -1);
}

//------------------------------------------------------------------------
TChar* AGainSimple::getDefaultMessageText ()
{
	return defaultMessageText;
}

//------------------------------------------------------------------------
enum
{
	// UI size
	kEditorWidth  = 350,
	kEditorHeight = 120
};

/// \cond ignore
//------------------------------------------------------------------------
// CTextButton - define a simple text button
//------------------------------------------------------------------------
class CTextButton: public VSTGUI::CTextLabel
{
public:
//------------------------------------------------------------------------
	CTextButton (const CRect& size, CControlListener* listener = 0, long tag = 0, const char* _title = 0)
	: CTextLabel (size)
	{
		setListener (listener);
		setTag (tag);
		setText (_title);
	}

	///---from CTextLabel--------------
	virtual	void draw (CDrawContext* pContext)
	{
		pContext->setFillColor (kGreyCColor);
		pContext->setFrameColor (kBlackCColor);
		pContext->drawRect (size, kDrawFilledAndStroked);
		CTextLabel::draw (pContext);
	}

	virtual CMouseEventResult onMouseDown (CPoint& where, const long& buttons)
	{
		if (listener)
			listener->valueChanged (this);
		return kMouseEventHandled;
	}

	CLASS_METHODS (CTextButton, CControl)
//------------------------------------------------------------------------
};
/// \endcond


//------------------------------------------------------------------------
// AGainEditorView Implementation
//------------------------------------------------------------------------
AGainEditorView::AGainEditorView (void* controller)
: VSTGUIEditor (controller)
, textEdit (0)
, gainSlider (0)
, gainTextEdit (0)
, vuMeter (0)
, background (0)
, lastVuMeterValue (0.f)
{
	setIdleRate (50); // 1000ms/50ms = 20Hz

	// set the default View size
	ViewRect viewRect (0, 0, kEditorWidth, kEditorHeight);
	setRect (viewRect);
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainEditorView::onSize (ViewRect* newSize)
{
	tresult res = VSTGUIEditor::onSize (newSize);
	return res;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainEditorView::checkSizeConstraint (ViewRect* rect)
{
	if (rect->right - rect->left < kEditorWidth)
	{
		rect->right = rect->left + kEditorWidth;
	}
	else if (rect->right - rect->left > kEditorWidth+50)
	{
		rect->right = rect->left + kEditorWidth+50;
	}
	if (rect->bottom - rect->top < kEditorHeight)
	{
		rect->bottom = rect->top + kEditorHeight;
	}
	else if (rect->bottom - rect->top > kEditorHeight+50)
	{
		rect->bottom = rect->top + kEditorHeight+50;
	}
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainEditorView::findParameter (int32 xPos, int32 yPos, ParamID& resultTag)
{
	// look up the parameter (view) which is located at xPos/yPos.

	CPoint where (xPos, yPos);

	// Implementation 1:
	// The parameter xPos/yPos are relative coordinates to the AGainEditorView coordinates.
	// If the window of the VST 3 plugin is moved, xPos is always >= 0 and <= AGainEditorView width.
	// yPos is always >= 0 and <= AGainEditorView height.
	// 
	// gainSlider->hitTest() is a short cut for:
	// CRect sliderRect = gainSlider->getMouseableArea ();
	// if (where.isInside (sliderRect))
	// {
	//      resultTag = kGainId;
	//      return kResultOk;
	// }

	// test wether xPos/yPos is inside the gainSlider.
	if (gainSlider->hitTest (where, 0))
	{
		// return the VST 3 parameter ID, which is also used for IParamValueQueue::getParameterId(),
		// IComponentHandler::performEdit() or IEditController::getParamStringByValue() etc.
		resultTag = kGainId;
		return kResultOk;
	}

	// test wether xPos/yPos is inside the gain text view.
	if (gainTextEdit->hitTest (where, 0))
	{
		resultTag = kGainId;
		return kResultOk;
	}

	// Implementation 2:
	// An alternative solution with VSTGui can look like this. (This requires C++ RTTI)
	// 
	// if (frame)
	// {
	//  CControl* controlAtPos = dynamic_cast<CControl*>(frame->getViewAt (where, true);
	//  if (controlAtPos)
	//  {
	//      switch (controlAtPos->getTag ())
	//      {
	//          case 'Gain':
	//          case 'GaiT':
	//              resultTag = resultTag;
	//              return kResultOk;
	//      }
	//  }
	// 

	// Implementation 3:
	// The another "dirty" way is to hard code the coordinates for the views (see also AGainEditorView::open):
	// CRect gainSliderSize (0, 0, 130, 18);
	// gainSliderSize.offset (45, 40);
	// if (where.isInside (gainSliderSize))
	//  {
	//      resultTag = kGainId;
	//      return kResultOk;
	//  }
	// CRect gainTextSize (0, 0, 40, 18);
	// gainTextSize.offset (50 + gainSliderSize.getWidth (), 40);
	// if (where.isInside (gainTextSize))
	//  {
	//      resultTag = kGainId;
	//      return kResultOk;
	//  }
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainEditorView::queryInterface (const char* iid, void** obj)
{
	QUERY_INTERFACE (iid, obj, IParameterFinder::iid, IParameterFinder)
	QUERY_INTERFACE (iid, obj, IContextMenuTarget::iid, IContextMenuTarget)
	return VSTGUIEditor::queryInterface (iid, obj);
}

//------------------------------------------------------------------------
bool AGainEditorView::open (void* parent)
{
	if (frame) // already attached!
	{
		return false;
	}

	CRect editorSize (0, 0, kEditorWidth, kEditorHeight);

	frame = new CFrame (editorSize, parent, this);
	frame->setBackgroundColor (kGreyCColor);

	background = new CBitmap ("background.png");
	frame->setBackground (background);

	//---Test communication between Component and Controller------
	CRect size (0, 0, 200, 20);
	size.offset (10, 10);
	textEdit = new CTextEdit (size, this, 'Text', "Hello World!", 0, k3DOut);
	frame->addView (textEdit);

	size (0, 0, 50, 20);
	size.offset (220, 10);
	CTextButton* textButton = new CTextButton (size, this, 'Send', "Send!");
	frame->addView (textButton);
	//-----------------------------------------------------------

	//---Gain--------------------

	//---Gain Label--------
	size (0, 0, 30, 18);
	size.offset (10, 40);
	CTextLabel* label = new CTextLabel (size, "Gain", 0, kShadowText);
	frame->addView (label);

	//---Gain slider-------
	CBitmap* handle = new CBitmap ("slider_handle.png");
	CBitmap* backgroundSlider = new CBitmap ("slider_background.bmp");

	size (0, 0, 130, 18);
	size.offset (45, 40);
	CPoint offset;
	CPoint offsetHandle (0, 2);
	gainSlider = new CHorizontalSlider (size, this, 'Gain', offsetHandle, size.getWidth (), handle, backgroundSlider, offset, kLeft); 
	frame->addView (gainSlider);
	handle->forget ();
	backgroundSlider->forget ();

	//---Gain Textedit--------
	size (0, 0, 40, 18);
	size.offset (50 + gainSlider->getWidth (), 40);
	gainTextEdit = new CTextEdit (size, this, 'GaiT', "", 0, k3DIn);
	gainTextEdit->setFont (kNormalFontSmall);
	frame->addView (gainTextEdit);


	//---VuMeter--------------------
	CBitmap* onBitmap = new CBitmap ("vu_on.bmp");
	CBitmap* offBitmap = new CBitmap ("vu_off.bmp");
		 
	size (0, 0, 12, 105);
	size.offset (290, 10);
	vuMeter = new CVuMeter (size, onBitmap, offBitmap, 26, kVertical);
	frame->addView (vuMeter);
	onBitmap->forget ();
	offBitmap->forget ();

	// sync UI controls with controller parameter values
	ParamValue value = getController ()->getParamNormalized (kGainId);
	update (kGainId, value);

	messageTextChanged ();

	return true;
}

//------------------------------------------------------------------------
void AGainEditorView::messageTextChanged ()
{
	AGainSimple* controller = dynamic_cast<AGainSimple*> (getController ());
	if (controller)
	{
		String text (controller->getDefaultMessageText ());
		char8 asciiText[128];
		text.copyTo8 (asciiText, 0, 127);
		textEdit->setText (asciiText);
	}
}

//------------------------------------------------------------------------
void PLUGIN_API AGainEditorView::close ()
{
	if (frame)
	{
		delete frame;
		frame = 0;
	}
	
	if (background)
	{
		background->forget ();
		background = 0;
	}
	
	textEdit = 0;
	gainSlider = 0;
	gainTextEdit = 0;
	vuMeter = 0;
}

//------------------------------------------------------------------------
void AGainEditorView::valueChanged (CControl* pControl)
{
	switch (pControl->getTag ())
	{
		//------------------
		case 'Send':
		{
			//---send a text message
			char text[256] = {0};
			textEdit->getText (text);
			controller->sendTextMessage (text);

			//---send a binary message
			IMessage* message = controller->allocateMessage ();
			if (message)
			{
				FReleaser msgReleaser (message);
				message->setMessageID ("BinaryMessage");
				
				uint32 size = 100;
				char8 data[100];
				memset (data, 0, size * sizeof (char));
				// fill my data with dummy stuff
				for (uint32 i = 0; i < size; i++)
					data[i] = i;
				message->getAttributes ()->setBinary ("MyData", data, size);
				controller->sendMessage (message);
			}

			static bool bgToggle = false;
			if (bgToggle)
				frame->setBackground (background);
			else
				frame->setBackground (0);
			
			frame->invalid ();
			bgToggle = !bgToggle;
		}	break;

		//------------------
		case 'Gain':
		{
			controller->setParamNormalized (kGainId, pControl->getValue ());
			controller->performEdit (kGainId, pControl->getValue ());
		}	break;

		//------------------
		case 'GaiT':
		{
			char text[128];
			gainTextEdit->getText (text);
			
			String128 string;
			String tmp (text);
			tmp.copyTo (string, 0, 127);

			ParamValue valueNormalized;
			controller->getParamValueByString (kGainId, string, valueNormalized);
			
			gainSlider->setValue ((float)valueNormalized);
			valueChanged (gainSlider);
			gainSlider->invalid ();
		}	break;

		//------------------
		case 'Text':
		{
			AGainSimple* controller = dynamic_cast<AGainSimple*> (getController ());
			if (controller)
			{
				char text[128];
				textEdit->getText (text);
				String tmp (text);
				String128 string;
				tmp.copyTo (string, 0, 127);

				controller->setDefaultMessageText (string);
			}
		}	break;
	}		
}

//------------------------------------------------------------------------
tresult PLUGIN_API AGainEditorView::executeMenuItem (int32 tag)
{
	// our menu item was choosen by the user
	if (tag == 1234)
	{
		ParameterInfo paramInfo;
		controller->getParameterInfo (kGainId, paramInfo);
		
		controller->beginEdit (kGainId);
		controller->setParamNormalized (kGainId, paramInfo.defaultNormalizedValue);
		controller->performEdit (kGainId, paramInfo.defaultNormalizedValue);
		controller->endEdit (kGainId);

		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
long AGainEditorView::controlModifierClicked (CControl* pControl, long button)
{
	switch (pControl->getTag ())
	{
		//------------------
		case 'GaiT':
		case 'Gain':
		{
			if (button & kRButton)
			{
				FUnknownPtr<IComponentHandler3> ch3 (controller->getComponentHandler ());
				if (ch3)
				{
					ParamID pid = kGainId;
					IContextMenu* menu = ch3->createContextMenu (this, &pid);
					if (menu)
					{
						// here we add our item (optional)
						IContextMenu::Item item = {0};
						ConstString ("Set Gain to Default").copyTo (item.name, 0, 127);
						item.tag = 1234;
						menu->addItem (item, this);

						// now we could pop-up the menu
						CPoint pos;
						frame->getCurrentMouseLocation (pos);
						menu->popup (pos.x, pos.y);
						menu->release ();

						return 1;
					}
				}
			}
		}	break;
	}
	return 0;
}

//------------------------------------------------------------------------
void AGainEditorView::controlBeginEdit (CControl* pControl)
{
	switch (pControl->getTag ())
	{
		//------------------
		case 'Gain':
		{
			controller->beginEdit (kGainId);
		}	break;
	}
}

//------------------------------------------------------------------------
void AGainEditorView::controlEndEdit (CControl* pControl)
{
	switch (pControl->getTag ())
	{
		//------------------
		case 'Gain':
		{
			controller->endEdit (kGainId);
		}	break;
	}
}

//------------------------------------------------------------------------
void AGainEditorView::update (ParamID tag, ParamValue value)
{
	switch (tag)
	{
		//------------------
		case kGainId:
			if (gainSlider)
			{
				gainSlider->setValue ((float)value);
								
				if (gainTextEdit)
				{
					String128 string;
					controller->getParamStringByValue (kGainId, value, string);
					
					String tmp (string);
					char text[128];
					tmp.copyTo8 (text, 0, 127);
				
					gainTextEdit->setText (text);
				}
			}
			break;

		//------------------
		case kVuPPMId:
			lastVuMeterValue = (float)value;
			break;
	}
}

//------------------------------------------------------------------------
CMessageResult AGainEditorView::notify (CBaseObject* sender, const char* message)
{
	if (message == CVSTGUITimer::kMsgTimer)
	{
		if (vuMeter)
		{
			vuMeter->setValue (1.f - ((lastVuMeterValue - 1.f) * (lastVuMeterValue - 1.f)));
			lastVuMeterValue = 0.f;
		}
	}
	return VSTGUIEditor::notify (sender, message);
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// called when library is loaded
bool InitModule ()   
{
	return true; 
}

//------------------------------------------------------------------------
// called when library is unloaded
bool DeinitModule ()
{
	return true; 
}


//------------------------------------------------------------------------
BEGIN_FACTORY_DEF ("Steinberg Media Technologies", 
				   "http://www.steinberg.net", 
				   "mailto:info@steinberg.de")

	//---First Plug-in included in this factory-------
	// its kVstAudioEffectClass component
	DEF_CLASS2 (INLINE_UID (0xB9F9ADE1, 0xCD9C4B6D, 0xA57E61E3, 0x123535FD),
				PClassInfo::kManyInstances,					// cardinality  
				kVstAudioEffectClass,						// the component category (dont changed this)
				"AGainSimple VST3",							// here the Plug-in name (to be changed)
				0,											// single component effects can not be destributed so this is zero
				"Fx",										// Subcategory for this Plug-in (to be changed)
				FULL_VERSION_STR,							// Plug-in version (to be changed)
				kVstVersionString,							// the VST 3 SDK version (dont changed this, use always this define)
				Steinberg::Vst::AGainSimple::createInstance)// function pointer called when this component should be instanciated

END_FACTORY
