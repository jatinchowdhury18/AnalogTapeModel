//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/againsimple.h
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

#pragma once

#include "public.sdk/source/vst/vstsinglecomponenteffect.h"
#include "public.sdk/source/vst/vstguieditor.h"
#include "pluginterfaces/vst/ivstcontextmenu.h"
#include "pluginterfaces/vst/ivstplugview.h"

#include "vstgui.sf/vstgui/vstgui.h"
#include "vstgui.sf/vstgui/cvstguitimer.h"

namespace Steinberg {
namespace Vst {

class AGainEditorView;

//------------------------------------------------------------------------
// AGain as combined processor and controller 
//------------------------------------------------------------------------
class AGainSimple: public SingleComponentEffect
{
public:
//------------------------------------------------------------------------
	AGainSimple ();

	static FUnknown* createInstance (void* context)
	{
		return (IAudioProcessor*)new AGainSimple;
	}

	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate  ();
	tresult PLUGIN_API setActive (TBool state);
	tresult PLUGIN_API process (ProcessData& data);
	tresult PLUGIN_API setState (IBStream* state);
	tresult PLUGIN_API getState (IBStream* state);
	tresult PLUGIN_API setupProcessing (ProcessSetup& newSetup);
	tresult PLUGIN_API setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts);

	IPlugView* PLUGIN_API createView (const char* name);
	tresult PLUGIN_API setEditorState (IBStream* state);
	tresult PLUGIN_API getEditorState (IBStream* state);
	tresult PLUGIN_API setParamNormalized (ParamID tag, ParamValue value);
	tresult PLUGIN_API getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string);
	tresult PLUGIN_API getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized);

	//---BaseEditController-------
	virtual void editorAttached (EditorView* editor);
	virtual void editorRemoved (EditorView* editor);

	//---Internal functions-------
	void addDependentView (AGainEditorView* view);
	void removeDependentView (AGainEditorView* view);
	void setDefaultMessageText (String128 text);
	TChar* getDefaultMessageText ();

//------------------------------------------------------------------------
private:
	// our model values
	float fGain;
	float fGainReduction;
	float fVuPPMOld;

	int32 currentProcessMode;

	bool  bHalfGain;
	bool  bBypass;

	TArray <AGainEditorView*> viewsArray;
	String128 defaultMessageText;
};

//------------------------------------------------------------------------
// AGainEditorView Declaration
//------------------------------------------------------------------------
class AGainEditorView:	public VSTGUIEditor,
						public CControlListener,
						public IParameterFinder,
						public IContextMenuTarget
{
public:
//------------------------------------------------------------------------
	AGainEditorView (void* controller);

	//---from VSTGUIEditor---------------
	bool PLUGIN_API open (void* parent);
	void PLUGIN_API close ();
	CMessageResult notify (CBaseObject* sender, const char* message);
	void beginEdit (long /*index*/) {}
	void endEdit (long /*index*/) {}

	//---from CControlListener---------
	void valueChanged (CControl* pControl);
	long controlModifierClicked (CControl* pControl, long button);
	void controlBeginEdit (CControl* pControl);
	void controlEndEdit (CControl* pControl);

	//---from EditorView---------------
	tresult PLUGIN_API onSize (ViewRect* newSize);
	tresult PLUGIN_API canResize () { return kResultFalse; }
	tresult PLUGIN_API checkSizeConstraint (ViewRect* rect);

	//---from IParameterFinder---------------
	tresult PLUGIN_API findParameter (int32 xPos, int32 yPos, ParamID& resultTag);

	//---from IContextMenuTarget---------------
	tresult PLUGIN_API executeMenuItem (int32 tag);

	DELEGATE_REFCOUNT (VSTGUIEditor)    
	tresult PLUGIN_API queryInterface (const char* iid, void** obj);

	//---Internal Function------------------
	void update (ParamID tag, ParamValue value);
	void messageTextChanged ();

//------------------------------------------------------------------------
protected:
	CTextEdit* textEdit;
	CHorizontalSlider* gainSlider;
	CTextEdit* gainTextEdit;
	CVuMeter* vuMeter;
	CBitmap* background;

	float lastVuMeterValue;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
