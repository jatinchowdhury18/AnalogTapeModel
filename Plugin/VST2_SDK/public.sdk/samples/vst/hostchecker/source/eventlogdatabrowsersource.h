//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/eventlogdatabrowsersource.h
// Created by  : Steinberg, 04/2012
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

#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"
#include "vstgui/vstgui.h"
#include "logevents.h"

namespace VSTGUI {

//-----------------------------------------------------------------------------
class EventLogDataBrowserSource : public CBaseObject, public IDataBrowser
{
public:
	EventLogDataBrowserSource (Steinberg::Vst::EditControllerEx1* editController);
	~EventLogDataBrowserSource ();

	typedef std::vector<LogEvent> LogEvents;
	
	enum eColoumns
	{
		kType = 0,
		kDescription,
		kCount,
		kNumColumns
	};

	virtual int32_t dbGetNumRows (CDataBrowser* browser);
	virtual int32_t dbGetNumColumns (CDataBrowser* browser);
	virtual bool dbGetColumnDescription (int32_t index, CCoord& minWidth, CCoord& maxWidth, CDataBrowser* browser);
	virtual CCoord dbGetCurrentColumnWidth (int32_t index, CDataBrowser* browser);
	virtual void dbSetCurrentColumnWidth (int32_t index, const CCoord& width, CDataBrowser* browser);
	virtual CCoord dbGetRowHeight (CDataBrowser* browser);
	virtual bool dbGetLineWidthAndColor (CCoord& width, CColor& color, CDataBrowser* browser);

	virtual void dbDrawHeader (CDrawContext* context, const CRect& size, int32_t column, int32_t flags, CDataBrowser* browser);
	virtual void dbDrawCell (CDrawContext* context, const CRect& size, int32_t row, int32_t column, int32_t flags, CDataBrowser* browser);

	virtual CMouseEventResult dbOnMouseDown (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser);
	virtual CMouseEventResult dbOnMouseMoved (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser);
	virtual CMouseEventResult dbOnMouseUp (const CPoint& where, const CButtonState& buttons, int32_t row, int32_t column, CDataBrowser* browser);

	virtual void dbSelectionChanged (CDataBrowser* browser);

	virtual void dbCellTextChanged (int32_t row, int32_t column, UTF8StringPtr newText, CDataBrowser* browser);
	virtual void dbCellSetupTextEdit (int32_t row, int32_t column, CTextEdit* textEditControl, CDataBrowser* browser);

	virtual int32_t dbOnKeyDown (const VstKeyCode& key, CDataBrowser* browser);

	bool updateLog (const LogEvent& logEvent);
protected:
	LogEvents mLogEvents;

};

} // namespace
