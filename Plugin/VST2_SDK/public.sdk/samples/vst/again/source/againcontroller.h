//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/againcontroller.h
// Created by  : Steinberg, 04/2005
// Description : AGain Editor Example for VST 3
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

#include "public.sdk/source/vst/vsteditcontroller.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
class AGainEditorView;

//------------------------------------------------------------------------
// AGainController
//------------------------------------------------------------------------
class AGainController: public EditControllerEx1, public IMidiMapping
{
public:
//------------------------------------------------------------------------
// create function required for Plug-in factory,
// it will be called to create new instances of this controller
//------------------------------------------------------------------------
	static FUnknown* createInstance (void* context)
	{
		return (IEditController*)new AGainController;
	}

	//---from IPluginBase--------
	tresult PLUGIN_API initialize (FUnknown* context);
	tresult PLUGIN_API terminate  ();

	//---from EditController-----
	tresult PLUGIN_API setComponentState (IBStream* state);
	IPlugView* PLUGIN_API createView (const char* name);
	tresult PLUGIN_API setState (IBStream* state);
	tresult PLUGIN_API getState (IBStream* state);
	tresult PLUGIN_API setParamNormalized (ParamID tag, ParamValue value);
	tresult PLUGIN_API getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string);
	tresult PLUGIN_API getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized);
	void editorDestroyed (EditorView* editor) {} // nothing to do here
	void editorAttached (EditorView* editor);
	void editorRemoved (EditorView* editor);

	//---from ComponentBase-----
	tresult receiveText (const char* text);

	//---from IMidiMapping-----------------
	tresult PLUGIN_API getMidiControllerAssignment (int32 busIndex, int16 channel, CtrlNumber midiControllerNumber, ParamID& tag);

	DELEGATE_REFCOUNT (EditController)
	tresult PLUGIN_API queryInterface (const char* iid, void** obj);

	//---Internal functions-------
	void addDependentView (AGainEditorView* view);
	void removeDependentView (AGainEditorView* view);

	void setDefaultMessageText (String128 text);
	TChar* getDefaultMessageText ();
//------------------------------------------------------------------------

private:
	TArray <AGainEditorView*> viewsArray;
	String128 defaultMessageText;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
