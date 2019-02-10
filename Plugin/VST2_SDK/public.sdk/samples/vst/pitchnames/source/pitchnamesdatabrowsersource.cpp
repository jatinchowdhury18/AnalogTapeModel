//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/pitchnames/source/pitchnamesdatabrowsersource.cpp
// Created by  : Steinberg, 12/2010
// Description : 
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

#include "pitchnamesdatabrowsersource.h"
#include "pluginterfaces/base/ustring.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace VSTGUI {

//-----------------------------------------------------------------------------
PitchNamesDataBrowserSource::PitchNamesDataBrowserSource (EditControllerEx1* editController, Steinberg::Vst::UnitID unitID)
: pitchnames (0)
{
	UnitInfo info;
	int32_t unitCount = editController->getUnitCount ();
	for (int32_t i = 0; i < unitCount; i++)
	{
		editController->getUnitInfo (i, info);
		if (info.id == unitID)
			break;
	}
	if (info.id == unitID && info.programListId != kNoProgramListId)
	{
		if (editController->hasProgramPitchNames (info.programListId, 0) == kResultTrue)
		{
			pitchnames = FCast<ProgramListWithPitchNames> (editController->getProgramList (info.programListId));
		}
	}
}

//-----------------------------------------------------------------------------
PitchNamesDataBrowserSource::~PitchNamesDataBrowserSource ()
{
}

//-----------------------------------------------------------------------------
int32_t PitchNamesDataBrowserSource::dbGetNumRows (CDataBrowser* browser)
{
	if (pitchnames)
		return 128;
	return 0;
}

//-----------------------------------------------------------------------------
int32_t PitchNamesDataBrowserSource::dbGetNumColumns (CDataBrowser* browser)
{
	return 2;
}

//-----------------------------------------------------------------------------
bool PitchNamesDataBrowserSource::dbGetColumnDescription (int32_t index, CCoord& minWidth, CCoord& maxWidth, CDataBrowser* browser)
{
	return false;
}

//-----------------------------------------------------------------------------
CCoord PitchNamesDataBrowserSource::dbGetCurrentColumnWidth (int32_t index, CDataBrowser* browser)
{
	const CCoord pitchWidth = 40;
	if (index == 0)
		return pitchWidth;
	return browser->getWidth () - pitchWidth;
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::dbSetCurrentColumnWidth (int32_t index, const CCoord& width, CDataBrowser* browser)
{
}

//-----------------------------------------------------------------------------
CCoord PitchNamesDataBrowserSource::dbGetRowHeight (CDataBrowser* browser)
{
	return 18;
}

//-----------------------------------------------------------------------------
bool PitchNamesDataBrowserSource::dbGetLineWidthAndColor (CCoord& width, CColor& color, CDataBrowser* browser)
{
	width = 1.;
	color = kGreyCColor;
	return true;
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::dbDrawHeader (CDrawContext* context, const CRect& size, int32_t column, int32_t flags, CDataBrowser* browser)
{
	context->setDrawMode (kAliasing);
	context->setFillColor (kGreyCColor);
	context->drawRect (size, kDrawFilled);

	String name;
	switch (column)
	{
		case 0: name = "Note"; break;
		case 1: name = "Pitch Name"; break;
	}
	context->setFont (kNormalFont);
	context->setFontColor (kBlackCColor);
	context->drawString (name.text8 (), size);
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::getPitchName (int16_t pitch, String& name)
{
	String128 pitchName;
	if (pitchnames->getPitchName (0, pitch, pitchName) == kResultTrue)
		name = pitchName;
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::dbDrawCell (CDrawContext* context, const CRect& size, int32_t row, int32_t column, int32_t flags, CDataBrowser* browser)
{
	if (pitchnames == 0)
		return;

	if (flags & kRowSelected)
	{
		CFrame* frame = browser->getFrame ();
		CColor focusColor (255, 0, 0, 100);
		if (frame && frame->focusDrawingEnabled ())
			focusColor = frame->getFocusColor ();
		focusColor.alpha /= 2;
		context->setFillColor (focusColor);
		context->drawRect (size, kDrawFilled);
	}

	String cellValue;
	switch (column)
	{
		case 0:
		{
			static const char* noteNames[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
			int32_t octave = row / 12;
			cellValue.printf ("%s%d", noteNames[row - octave * 12], octave - 2);
			break;
		}
		case 1:
		{
			getPitchName ((int16_t)row, cellValue);
			break;
		}
	}

	CRect cellSize (size);
	cellSize.inset (5, 0);
	context->setFont (kNormalFontSmall);
	context->setFontColor (kBlackCColor);
	context->drawString (cellValue.text8 (), cellSize, kLeftText);
}

//-----------------------------------------------------------------------------
CMouseEventResult PitchNamesDataBrowserSource::dbOnMouseDown (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser)
{
	if (buttons.isLeftButton () && buttons.isDoubleClick () && column == 1)
	{
		String pitchName;
		getPitchName ((int16_t)row, pitchName);
		browser->beginTextEdit (row, column, pitchName.text8 ());
	}
	return kMouseDownEventHandledButDontNeedMovedOrUpEvents;
}

//-----------------------------------------------------------------------------
CMouseEventResult PitchNamesDataBrowserSource::dbOnMouseMoved (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser)
{
	return kMouseEventNotHandled;
}

//-----------------------------------------------------------------------------
CMouseEventResult PitchNamesDataBrowserSource::dbOnMouseUp (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser)
{
	return kMouseEventNotHandled;
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::dbSelectionChanged (CDataBrowser* browser)
{
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::dbCellTextChanged (int32_t row, int32_t column, UTF8StringPtr newText, CDataBrowser* browser)
{
	if (pitchnames)
	{
		UString128 str (newText);
		if (str.getLength () == 0)
			pitchnames->removePitchName (0, (int16)row);
		else
			pitchnames->setPitchName (0, (int16)row, str);
	}
}

//-----------------------------------------------------------------------------
void PitchNamesDataBrowserSource::dbCellSetupTextEdit (int32_t row, int32_t column, CTextEdit* textEditControl, CDataBrowser* browser)
{
	textEditControl->setBackColor (kWhiteCColor);
	textEditControl->setFont (kNormalFontSmall);
	textEditControl->setFontColor (kRedCColor);
	textEditControl->setTextInset (CPoint (5, 0));
	textEditControl->setHoriAlign (kLeftText);
}

//-----------------------------------------------------------------------------
int32_t PitchNamesDataBrowserSource::dbOnKeyDown (const VstKeyCode& key, CDataBrowser* browser)
{
	if (key.virt == VKEY_RETURN && browser->getSelectedRow () != CDataBrowser::kNoSelection)
	{
		String pitchName;
		getPitchName ((int16_t)browser->getSelectedRow (), pitchName);
		browser->beginTextEdit (browser->getSelectedRow (), 1, pitchName.text8 ());
		return 1;
	}
	return -1;
}

} // namespace
