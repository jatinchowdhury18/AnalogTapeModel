//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins : 
//
// Version 3.6
//
// CDataBrowser written 2006 by Arne Scheffler
//
//-----------------------------------------------------------------------------
// VSTGUI LICENSE
// (c) 2008, Steinberg Media Technologies, All Rights Reserved
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

#ifndef __cdatabrowser__
#define __cdatabrowser__

#include "cscrollview.h"

BEGIN_NAMESPACE_VSTGUI

class CDataBrowser;
class CDataBrowserView;
class CDataBrowserHeader;

//-----------------------------------------------------------------------------
// IDataBrowser Declaration
//! \brief DataBrowser Interface
/// \nosubgrouping
//-----------------------------------------------------------------------------------------------
class IDataBrowser
{
public:
	virtual long dbGetNumRows (CDataBrowser* browser) = 0;	///< return number of rows for CDataBrowser browser
	virtual long dbGetNumColumns (CDataBrowser* browser) = 0;	///< return number of columns for CDataBrowser browser
	virtual bool dbGetColumnDescription (long index, CCoord& minWidth, CCoord& maxWidth, CDataBrowser* browser) { return false; }
	virtual CCoord dbGetCurrentColumnWidth (long index, CDataBrowser* browser) = 0;	///< return current width of index column
	virtual void dbSetCurrentColumnWidth (long index, const CCoord& width, CDataBrowser* browser) {}	///< the width of a column has changed
	virtual CCoord dbGetRowHeight (CDataBrowser* browser) = 0;	///< return height of one row
	virtual bool dbGetLineWidthAndColor (CCoord& width, CColor& color, CDataBrowser* browser) { return false; } ///< return the line width and color

	virtual void dbDrawHeader (CDrawContext* context, const CRect& size, long column, long flags, CDataBrowser* browser) = 0;	///< draw the db header
	virtual void dbDrawCell (CDrawContext* context, const CRect& size, long row, long column, long flags, CDataBrowser* browser) = 0;	///< draw a db cell

	virtual CMouseEventResult dbOnMouseDown (const CPoint& where, const long& buttons, long row, long column, CDataBrowser* browser) { return kMouseDownEventHandledButDontNeedMovedOrUpEvents; } ///< mouse button was pressed on a cell
	virtual CMouseEventResult dbOnMouseMoved (const CPoint& where, const long& buttons, long row, long column, CDataBrowser* browser) { return kMouseEventNotHandled; } ///< mouse was moved over a cell
	virtual CMouseEventResult dbOnMouseUp (const CPoint& where, const long& buttons, long row, long column, CDataBrowser* browser) { return kMouseEventNotHandled; } ///< mouse button was released on a cell

	virtual void dbSelectionChanged (CDataBrowser* browser) {}	///< the selection of the db changed

	virtual void dbCellTextChanged (long row, long column, const char* newText, CDataBrowser* browser) {} ///< the text of the cell changed beginTextEdit was called for
	virtual void dbCellSetupTextEdit (long row, long column, CTextEdit* textEditControl, CDataBrowser* browser) {} ///< beginTextEdit calls this, so you can setup the textedit control

	enum {
		kRowSelected = 1 << 1,
	};

	virtual ~IDataBrowser () {}
};

//-----------------------------------------------------------------------------
// CDataBrowser Declaration
//! \brief DataBrowser view
/// \nosubgrouping
/// \ingroup controls
//-----------------------------------------------------------------------------------------------
class CDataBrowser : public CScrollView
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructor
	//-----------------------------------------------------------------------------
	//@{
	CDataBrowser (const CRect& size, CFrame* pParent, IDataBrowser* db, long style = 0, CCoord scrollbarWidth = 16, CBitmap* pBackground = 0);
	//@}

	~CDataBrowser ();

	enum CDataBrowserStyle 
	{
		// see CScrollView for more styles
		kDrawRowLines			= 1 << 4,
		kDrawColumnLines		= 1 << 5,
		kDrawHeader				= 1 << 6,
	};
	
	enum 
	{
		kNoSelection	= -1
	};

	//-----------------------------------------------------------------------------
	/// \name CDataBrowser Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual void recalculateLayout (bool rememberSelection = false);				///< trigger recalculation, call if numRows or numColumns changed
	virtual void invalidate (long row, long column);								///< invalidates an individual cell
	virtual void invalidateRow (long row);											///< invalidates a complete row
	virtual void makeRowVisible (long row);											///< scrolls the scrollview so that row is visible

	virtual CRect getCellBounds (long row, long column);							///< get bounds of a cell

	virtual long getSelectedRow () const { return selectedRow; }					///< get selected row
	virtual void setSelectedRow (long row, bool makeVisible = false);				///< set the exclusive selected row

	virtual void beginTextEdit (long row, long column, const char* initialText);	///< starts a text edit for a cell
	//@}

protected:
	void valueChanged (CControl *pControl);
	CMessageResult notify (CBaseObject* sender, const char* message);
	bool attached (CView *parent);

	IDataBrowser* db;
	CDataBrowserView* dbView;
	CDataBrowserHeader* dbHeader;
	CViewContainer* dbHeaderContainer;
	long selectedRow;
};

END_NAMESPACE_VSTGUI

#endif
