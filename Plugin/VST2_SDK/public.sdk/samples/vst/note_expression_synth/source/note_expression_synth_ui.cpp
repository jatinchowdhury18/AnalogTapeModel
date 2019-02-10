//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/note_expression_synth/source/note_expression_synth_ui.cpp
// Created by  : Steinberg, 12/2010
// Description : Note Expression Synth UI version using VSTGUI 4
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

#include "note_expression_synth_ui.h"
#include "note_touch_controller.h"
#include "pluginterfaces/vst/ivstinterappaudio.h"
#include "vstgui/plugin-bindings/vst3padcontroller.h"
#include "vstgui/plugin-bindings/vst3groupcontroller.h"

namespace Steinberg {
namespace Vst {
namespace NoteExpressionSynth {

class InterAppAudioControlsController : public IController
{
public:
	enum {
		kSettings = 5000,
		kLoadPreset,
		kSavePreset
	};
	
	InterAppAudioControlsController (IInterAppAudioHost* iaaHost)
	: host (iaaHost)
	{
	}
	
	void valueChanged (VSTGUI::CControl* pControl) VSTGUI_OVERRIDE_VMETHOD
	{
		if (pControl->getValue ())
		{
			switch (pControl->getTag ())
			{
				case kSettings:
				{
					host->showSettingsView ();
					break;
				}
				case kLoadPreset:
				{
					getPresetManager ()->runLoadPresetBrowser ();
					break;
				}
				case kSavePreset:
				{
					getPresetManager ()->runSavePresetBrowser ();
					break;
				}
			}
		}
	}
private:
	IInterAppAudioPresetManager* getPresetManager ()
	{
		if (presetManager == 0)
		{
			TUID uid;
			ProcessorWithUIController::cid.toTUID (uid);
			presetManager = owned (host->createPresetManager (uid));
		}
		return presetManager;
	}
	IInterAppAudioHost* host;
	IPtr<IInterAppAudioPresetManager> presetManager;
};

//-----------------------------------------------------------------------------
FUID ControllerWithUI::cid (0x1AA302B3, 0xE8384785, 0xB9C3FE3E, 0x08B056F5);
FUID ProcessorWithUIController::cid (0x41466D9B, 0xB0654576, 0xB641098F, 0x686371B3);

//-----------------------------------------------------------------------------
IPlugView* PLUGIN_API ControllerWithUI::createView (FIDString _name)
{
	ConstString name (_name);
	if (name == ViewType::kEditor)
	{
		FUnknownPtr<IInterAppAudioHost> interAudioApp (getHostContext ());
		if (interAudioApp)
		{
			ViewRect vr;
			float scale;
			if (interAudioApp->getScreenSize (&vr, &scale) == kResultTrue)
			{
				if (vr.right >= 1024)
				{
					return new VST3Editor (this, "EditorIPad", "note_expression_synth.uidesc");
				}
				else if (vr.right == 568)
				{
					return new VST3Editor (this, "EditorIPhone4Inch", "note_expression_synth.uidesc");
				}
			}
		}
		return new VST3Editor (this, "Editor", "note_expression_synth.uidesc");
	}
	return 0;
}

//-----------------------------------------------------------------------------
IController* ControllerWithUI::createSubController (UTF8StringPtr _name, IUIDescription* description, VST3Editor* editor)
{
	ConstString name (_name);
	if (name == "FilterPadController")
	{
		Parameter* freqParam = getParameterObject (kParamFilterFreq);
		Parameter* resoParam = getParameterObject (kParamFilterQ);
		PadController* padController = new PadController (editor, this, freqParam, resoParam);
		return padController;
	}
	else if (name == "FilterTypeController")
	{
		GroupController* controller = new GroupController (getParameterObject (kParamFilterType), this);
		return controller;
	}
	else if (name.findFirst ("NoteController") == 0)
	{
		FUnknownPtr<IInterAppAudioHost> interAudioApp (getHostContext ());
		if (interAudioApp)
		{
			int32 index = static_cast<int32> (name.getNumber ());
			NoteTouchController* noteTouchController = new NoteTouchController (index, interAudioApp);
			noteTouchController->setHorizontalNoteExpType (kFilterFreqModTypeID);
			noteTouchController->setVerticalNoteExpType (kVolumeTypeID);
			return noteTouchController;
		}
	}
	else if (name == "InterAppAudioControlsController")
	{
		FUnknownPtr<IInterAppAudioHost> interAudioApp (getHostContext ());
		if (interAudioApp)
		{
			return new InterAppAudioControlsController (interAudioApp);
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------
ProcessorWithUIController::ProcessorWithUIController ()
{
	setControllerClass (ControllerWithUI::cid);
}

}}} // namespaces
