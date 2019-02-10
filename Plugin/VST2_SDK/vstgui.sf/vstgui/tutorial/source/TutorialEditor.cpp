//-----------------------------------------------------------------------------
// VSTGUI: Graphical User Interface Framework for VST plugins : 
//
// Version 3.5       $Date: 2008-01-09 15:48:56 +0100 (Wed, 09 Jan 2008) $
//
//-----------------------------------------------------------------------------
// VSTGUI LICENSE
// © 2008, Steinberg Media Technologies, All Rights Reserved
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
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#include "TutorialEditor.h"

//------------------------------------------------------------------------------------
AEffGUIEditor* createEditor (AudioEffectX* effect)
{
	return new TutorialEditor (effect);
}

//------------------------------------------------------------------------------------
TutorialEditor::TutorialEditor (void* ptr)
: AEffGUIEditor (ptr)
{
}

//------------------------------------------------------------------------------------
bool TutorialEditor::open (void* ptr)
{
	//-- first we create the frame with a size of 300, 300 and set the background to white
	CRect frameSize (0, 0, 300, 300);
	CFrame* newFrame = new CFrame (frameSize, ptr, this);
	newFrame->setBackgroundColor (kWhiteCColor);

	//-- load some bitmaps we need
	CBitmap* background = new CBitmap ("KnobBackground.png");
	CBitmap* handle = new CBitmap ("KnobHandle.png");

	//-- creating a knob and adding it to the frame
	CRect r (0, 0, background->getWidth (), background->getHeight ());
	CKnob* knob1 = new CKnob (r, this, kLeftVolumeParameter, background, handle, CPoint (0, 0));
	newFrame->addView (knob1);

	//-- creating another knob, we are offsetting the rect, so that the knob is next to the previous knob
	r.offset (background->getWidth () + 5, 0);
	CKnob* knob2 = new CKnob (r, this, kRightVolumeParameter, background, handle, CPoint (0, 0));
	newFrame->addView (knob2);

	//-- forget the bitmaps
	background->forget ();
	handle->forget ();

	//-- remember our controls so that we can sync them with the state of the effect
	controls[kLeftVolumeParameter] = knob1;
	controls[kRightVolumeParameter] = knob2;

	//-- set the member frame to the newly created frame
	//-- we do it this way because it is possible that the setParameter method is called 
	//-- in between of constructing the frame and it's controls
	frame = newFrame;

	//-- sync parameters
	for (int i = 0; i < kNumParameters; i++)
		setParameter (i, effect->getParameter (i));

	return true;
}

//------------------------------------------------------------------------------------
void TutorialEditor::close ()
{
	//-- on close we need to delete the frame object.
	//-- once again we make sure that the member frame variable is set to zero before we delete it
	//-- so that calls to setParameter won't crash.
	CFrame* oldFrame = frame;
	frame = 0;
	delete oldFrame;
}

//------------------------------------------------------------------------------------
void TutorialEditor::valueChanged (CControl* pControl)
{
	//-- valueChanged is called whenever the user changes one of the controls in the User Interface (UI)
	effect->setParameterAutomated (pControl->getTag (), pControl->getValue ());
}

//------------------------------------------------------------------------------------
void TutorialEditor::setParameter (VstInt32 index, float value)
{
	//-- setParameter is called when the host automates one of the effects parameter.
	//-- The UI should reflect this state so we set the value of the control to the new value.
	//-- VSTGUI will automaticly redraw changed controls in the next idle (as this call happens to be in the process thread).
	if (frame && index < kNumParameters)
	{
		controls[index]->setValue (value);
	}
}

