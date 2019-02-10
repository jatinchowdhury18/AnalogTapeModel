//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/again/source/againeditor.cpp
// Created by  : Steinberg, 04/2005
// Description : AGain Editor Example for VST 3 using VSTGUI 3.5
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

#include "againeditor.h"
#include "againcontroller.h"
#include "againparamids.h"

#include "base/source/fstring.h"

#include <stdio.h>
#include <math.h>

namespace Steinberg {
namespace Vst {

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
	AGainController* controller = dynamic_cast<AGainController*> (getController ());
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
			tmp.copyTo16 (string, 0, 127);

			ParamValue valueNormalized;
			controller->getParamValueByString (kGainId, string, valueNormalized);
			
			gainSlider->setValue ((float)valueNormalized);
			valueChanged (gainSlider);
			gainSlider->invalid ();
		}	break;

		//------------------
		case 'Text':
		{
			AGainController* controller = dynamic_cast<AGainController*> (getController ());
			if (controller)
			{
				char text[128];
				textEdit->getText (text);
				String tmp (text);
				String128 string;
				tmp.copyTo16 (string, 0, 127);

				controller->setDefaultMessageText (string);
			}
		}	break;
	}		
}

//------------------------------------------------------------------------
tresult AGainEditorView::executeMenuItem (int32 tag)
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
						ConstString ("Set Gain to Default").copyTo16 (item.name, 0, 127);
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
