//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/eventlogdatabrowsersource.cpp
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

#include "eventlogdatabrowsersource.h"
#include "pluginterfaces/base/ustring.h"
#include "logevents.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

namespace VSTGUI {

//-----------------------------------------------------------------------------
EventLogDataBrowserSource::EventLogDataBrowserSource (EditControllerEx1* editController)
{
	mLogEvents.resize (kNumLogEvents);
	for (Steinberg::uint32 i = 0; i < mLogEvents.size (); ++i)
		mLogEvents[i].id = i;
}

//-----------------------------------------------------------------------------
EventLogDataBrowserSource::~EventLogDataBrowserSource ()
{
}

//-----------------------------------------------------------------------------
int32_t EventLogDataBrowserSource::dbGetNumRows (CDataBrowser* browser)
{
	return kNumLogEvents;
}

//-----------------------------------------------------------------------------
int32_t EventLogDataBrowserSource::dbGetNumColumns (CDataBrowser* browser)
{
	return kNumColumns;
}

//-----------------------------------------------------------------------------
bool EventLogDataBrowserSource::dbGetColumnDescription (int32_t index, CCoord& minWidth, CCoord& maxWidth, CDataBrowser* browser)
{
	return false;
}

//-----------------------------------------------------------------------------
CCoord EventLogDataBrowserSource::dbGetCurrentColumnWidth (int32_t index, CDataBrowser* browser)
{
	static const CCoord typeWidth = 40;
	static const int32 countWidth = 80;
	if (index == kType)
		return typeWidth;
	else if (index == kCount)
		return countWidth;

	return browser->getWidth () - (typeWidth + countWidth);
}

//-----------------------------------------------------------------------------
void EventLogDataBrowserSource::dbSetCurrentColumnWidth (int32_t index, const CCoord& width, CDataBrowser* browser)
{
}

//-----------------------------------------------------------------------------
CCoord EventLogDataBrowserSource::dbGetRowHeight (CDataBrowser* browser)
{
	return 18;
}

//-----------------------------------------------------------------------------
bool EventLogDataBrowserSource::dbGetLineWidthAndColor (CCoord& width, CColor& color, CDataBrowser* browser)
{
	width = 1.;
	color = kGreyCColor;
	return true;
}

//-----------------------------------------------------------------------------
void EventLogDataBrowserSource::dbDrawHeader (CDrawContext* context, const CRect& size, int32_t column, int32_t flags, CDataBrowser* browser)
{
	context->setDrawMode (kAliasing);
	context->setFillColor (kGreyCColor);
	context->drawRect (size, kDrawFilled);

	String name;
	switch (column)
	{
		case kType: name = "Type"; break;
		case kCount: name = "Count"; break;
		case kDescription: name = "Description"; break;
	}
	context->setFont (kNormalFont);
	context->setFontColor (kBlackCColor);
	context->drawString (name.text8 (), size);
}

//-----------------------------------------------------------------------------
void EventLogDataBrowserSource::dbDrawCell (CDrawContext* context, const CRect& size, int32_t row, int32_t column, int32_t flags, CDataBrowser* browser)
{
	CColor cellColor (kWhiteCColor);
	bool oddRow = row % 2 != 0;
	if (oddRow)
	{
		cellColor = kBlackCColor;
		cellColor.alpha /= 16;
	}
	String cellValue;
	
	LogEvent& logEvent = mLogEvents.at (row);
	if (logEvent.count > 0)
	{
		if (String (LOG_ERR) == logEventSeverity[logEvent.id])
			cellColor = kRedCColor;
		else if (String (LOG_WARN) == logEventSeverity[logEvent.id])
			cellColor = kYellowCColor;
		else if (String (LOG_INFO) == logEventSeverity[logEvent.id])
			cellColor = kBlueCColor;
		
		if (oddRow)
			cellColor.alpha /= 2;
		else
			cellColor.alpha /= 3.;
	}

	context->setFillColor (cellColor);
	context->drawRect (size, kDrawFilled);

	switch (column)
	{
		case kType:
		{
			if (logEvent.count > 0)
				cellValue.printf (logEventSeverity[logEvent.id]);

			break;
		}
		case kDescription:
		{
			cellValue.assign (logEventDescriptions[row]);
			break;
		}
		case kCount:
		{
			cellValue.printf ("%d", logEvent.count);

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
CMouseEventResult EventLogDataBrowserSource::dbOnMouseDown (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser)
{
	return kMouseDownEventHandledButDontNeedMovedOrUpEvents;
}

//-----------------------------------------------------------------------------
CMouseEventResult EventLogDataBrowserSource::dbOnMouseMoved (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser)
{
	return kMouseEventNotHandled;
}

//-----------------------------------------------------------------------------
CMouseEventResult EventLogDataBrowserSource::dbOnMouseUp (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser)
{
	return kMouseEventNotHandled;
}

//-----------------------------------------------------------------------------
void EventLogDataBrowserSource::dbSelectionChanged (CDataBrowser* browser)
{
}

//-----------------------------------------------------------------------------
void EventLogDataBrowserSource::dbCellTextChanged (int32_t row, int32_t column, UTF8StringPtr newText, CDataBrowser* browser)
{
}

//-----------------------------------------------------------------------------
void EventLogDataBrowserSource::dbCellSetupTextEdit (int32_t row, int32_t column, CTextEdit* textEditControl, CDataBrowser* browser)
{
	textEditControl->setBackColor (kWhiteCColor);
	textEditControl->setFont (kNormalFontSmall);
	textEditControl->setFontColor (kRedCColor);
	textEditControl->setTextInset (CPoint (5, 0));
	textEditControl->setHoriAlign (kLeftText);
}

//-----------------------------------------------------------------------------
int32_t EventLogDataBrowserSource::dbOnKeyDown (const VstKeyCode& key, CDataBrowser* browser)
{
	return -1;
}

//-----------------------------------------------------------------------------
bool EventLogDataBrowserSource::updateLog (const LogEvent& logEvent)
{
	bool bResult = mLogEvents[logEvent.id].count != logEvent.count;

	LogEvent& tmpEvent = mLogEvents.at (logEvent.id);
	tmpEvent.count = logEvent.count;

	return bResult;
}

//-----------------------------------------------------------------------------
} // namespace
