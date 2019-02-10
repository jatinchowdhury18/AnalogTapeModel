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

#include "cdatabrowser.h"
#include "vstkeycode.h"

BEGIN_NAMESPACE_VSTGUI

/// \cond ignore
//-----------------------------------------------------------------------------------------------
class CDataBrowserView : public CView
//-----------------------------------------------------------------------------------------------
{
public:
	CDataBrowserView (const CRect& size, IDataBrowser* db, CDataBrowser* browser, long style);

	void draw (CDrawContext* context);
	void drawRect (CDrawContext* context, const CRect& updateRect);
	CMouseEventResult onMouseDown (CPoint &where, const long& buttons);
	CMouseEventResult onMouseMoved (CPoint &where, const long& buttons);
	CMouseEventResult onMouseUp (CPoint &where, const long& buttons);

	long onKeyDown (VstKeyCode& keyCode);

	CRect getRowBounds (long row);
	void invalidateRow (long row);

protected:
	bool getCell (CPoint& where, long& row, long& column);

	IDataBrowser* db;
	CDataBrowser* browser;
	long style;
};

//-----------------------------------------------------------------------------------------------
class CDataBrowserHeader : public CView
//-----------------------------------------------------------------------------------------------
{
public:
	CDataBrowserHeader (const CRect& size, IDataBrowser* db, CDataBrowser* browser, long style);

	void draw (CDrawContext* context);
	void drawRect (CDrawContext* context, const CRect& updateRect);
	CMouseEventResult onMouseDown (CPoint &where, const long& buttons);
	CMouseEventResult onMouseMoved (CPoint &where, const long& buttons);
	CMouseEventResult onMouseUp (CPoint &where, const long& buttons);
	CMouseEventResult onMouseExited (CPoint &where, const long& buttons);

protected:
	long getColumnAtPoint (CPoint& where);

	IDataBrowser* db;
	CDataBrowser* browser;
	long style;

	CPoint startMousePoint;
	long mouseColumn;
	CCoord startWidth;
};
/// \endcond

END_NAMESPACE_VSTGUI

#define FOREACHSUBVIEW for (CCView *pSv = pFirstView; pSv; pSv = pSv->pNext) {CView *pV = pSv->pView;
#define ENDFOR }

//-----------------------------------------------------------------------------------------------
/**
 * @param size size of data browser
 * @param pParent frame
 * @param db data browser interface. If db is inheritated from CBaseObject it will be remembered and released if data browser is destroyed
 * @param style data browser and scroll view style see #CDataBrowserStyle and #CScrollViewStyle
 * @param scrollbarWidth width of scrollbars
 * @param pBackground background bitmap
 */
CDataBrowser::CDataBrowser (const CRect& size, CFrame* pParent, IDataBrowser* db, long style, CCoord scrollbarWidth, CBitmap* pBackground)
: CScrollView (size, CRect (0, 0, 0, 0), pParent, style, scrollbarWidth, pBackground)
, db (db)
, dbView (0)
, dbHeader (0)
, dbHeaderContainer (0)
, selectedRow (kNoSelection)
{
	setTransparency (true);
	dbView = new CDataBrowserView (CRect (0, 0, 0, 0), db, this, style);
	addView (dbView);
	CBaseObject* obj = dynamic_cast<CBaseObject*>(db);
	if (obj)
		obj->remember ();
}

//-----------------------------------------------------------------------------------------------
CDataBrowser::~CDataBrowser ()
{
	CBaseObject* obj = dynamic_cast<CBaseObject*>(db);
	if (obj)
		obj->forget ();
}

//-----------------------------------------------------------------------------------------------
bool CDataBrowser::attached (CView *parent)
{
	recalculateLayout (true);
	return CScrollView::attached (parent);
}

//-----------------------------------------------------------------------------
void CDataBrowser::valueChanged (CControl *pControl)
{
	CPoint origOffset = getScrollOffset ();
	CScrollView::valueChanged (pControl);
	CPoint offset = getScrollOffset ();
	if (origOffset != offset)
	{
		switch (pControl->getTag ())
		{
			case kHSBTag:
			{
				if (dbHeader)
				{
					CRect viewSize = dbHeader->getViewSize (viewSize);
					CCoord width = viewSize.getWidth ();
					viewSize.left = offset.x;
					viewSize.setWidth (width);
					dbHeader->setViewSize (viewSize);
					dbHeader->setMouseableArea (viewSize);
					dbHeader->invalid ();
				}
				break;
			}
		}
	}
}

//-----------------------------------------------------------------------------------------------
/**
 * @param rememberSelection if true selection will be remembered
 */
void CDataBrowser::recalculateLayout (bool rememberSelection)
{
	CCoord lineWidth = 0;
	CColor lineColor;
	db->dbGetLineWidthAndColor (lineWidth, lineColor, this);
	CCoord rowHeight = db->dbGetRowHeight (this);
	long numRows = db->dbGetNumRows (this);
	long numColumns = db->dbGetNumColumns (this);
	CCoord allRowsHeight = rowHeight * numRows;
	if (style & kDrawRowLines)
		allRowsHeight += numRows * lineWidth;
	CCoord allColumnsWidth = 0;
	for (long i = 0; i < numColumns; i++)
		allColumnsWidth += db->dbGetCurrentColumnWidth (i, this);
	if (style & kDrawColumnLines)
		allColumnsWidth += numColumns * lineWidth;
	if (style & kDrawHeader)
	{
		FOREACHSUBVIEW
			CRect viewSize;
			pV->getViewSize (viewSize);
			if (pV != dbHeaderContainer && viewSize.top < rowHeight+lineWidth)
			{
				viewSize.top += rowHeight+lineWidth;
				pV->setViewSize (viewSize);
				pV->setMouseableArea (viewSize);
			}
		ENDFOR
	}

	CRect newContainerSize (0, 0, allColumnsWidth, allRowsHeight);
	if (style & kDrawHeader)
	{
		newContainerSize.offset (0, rowHeight+lineWidth);
		
		CRect headerSize (0, 0, newContainerSize.getWidth (), rowHeight+lineWidth);
		if (style & kHorizontalScrollbar && hsb)
			headerSize.right += hsb->getWidth ();
		if (dbHeader == 0)
		{
			CRect hcs (headerSize);
			if (!(style & kDontDrawFrame))
				hcs.left = hcs.top = 1;
			hcs.setWidth (size.getWidth () - ((style & kDontDrawFrame) ? 0 : 2));
			dbHeaderContainer = new CViewContainer (hcs, getFrame ());
			dbHeaderContainer->setTransparency (true);
			headerSize.offset (-headerSize.left, -headerSize.top);
			dbHeader = new CDataBrowserHeader (headerSize, db, this, style);
			dbHeaderContainer->addView (dbHeader);
			CViewContainer::addView (dbHeaderContainer);
		}
		else
		{
			headerSize.offset (getScrollOffset ().x, 0);
			dbHeader->setViewSize (headerSize);
			dbHeader->setMouseableArea (headerSize);
		}
	}
	setContainerSize (newContainerSize, true);
	newContainerSize.offset (getScrollOffset ().x, -getScrollOffset ().y);
	dbView->setViewSize (newContainerSize);
	dbView->setMouseableArea (newContainerSize);

	if (isAttached ())
		invalid ();
	if (!rememberSelection || numRows <= selectedRow)
		selectedRow = kNoSelection;
}

//-----------------------------------------------------------------------------------------------
/**
 * currently this will invalidate the whole row
 * @param row row to invalidate
 * @param column column to invalidate
 */
void CDataBrowser::invalidate (long row, long column)
{
	// TODO
	dbView->invalidateRow (row);
}

//-----------------------------------------------------------------------------------------------
/**
 * @param row row to invalidate
 */
void CDataBrowser::invalidateRow (long row)
{
	dbView->invalidateRow (row);
}

//-----------------------------------------------------------------------------------------------
/**
 * @param row row to make visible
 */
void CDataBrowser::makeRowVisible (long row)
{
	CRect r = dbView->getRowBounds (row);
	makeRectVisible (r);
}

//-----------------------------------------------------------------------------------------------
/**
 * @param index row to select
 * @param makeVisible if true makes row visible
 */
void CDataBrowser::setSelectedRow (long index, bool makeVisible)
{
	long numRows = db->dbGetNumRows (this);
	if (index >= numRows)
		index = numRows-1;
	if (index != selectedRow)
	{
		dbView->invalidateRow (selectedRow);
		dbView->invalidateRow (index);
		selectedRow = index;
		db->dbSelectionChanged (this);
	}
}

//-----------------------------------------------------------------------------------------------
/**
 * @param row row number
 * @param column column number
 * @return bounds of cell
 */
CRect CDataBrowser::getCellBounds (long row, long column)
{
	CCoord lineWidth = 0;
	if (style & kDrawRowLines || style & kDrawColumnLines)
	{
		CColor lineColor;
		db->dbGetLineWidthAndColor (lineWidth, lineColor, this);
	}
	CCoord rowHeight = db->dbGetRowHeight (this);
	if (style & kDrawRowLines)
		rowHeight += lineWidth;
	CRect result (0, rowHeight * row, 0, rowHeight * (row+1));
	for (long i = 0; i <= column; i++)
	{
		CCoord colWidth = db->dbGetCurrentColumnWidth (i, this);
		if (i != column)
		{
			result.offset (colWidth, 0);
			if (style & kDrawColumnLines)
				result.offset (lineWidth, 0);
		}
		result.setWidth (colWidth);
	}
	CRect viewSize = dbView->getViewSize (viewSize);
	result.offset (viewSize.left, viewSize.top);
	return result;
}

//-----------------------------------------------------------------------------------------------
/**
 * @param row row number
 * @param column column number
 * @param initialText UTF-8 string the text edit field will be initialized with
 */
void CDataBrowser::beginTextEdit (long row, long column, const char* initialText)
{
	CRect r = getCellBounds (row, column);
	makeRectVisible (r);
	CRect cellRect = getCellBounds (row, column);
	CTextEdit* te = new CTextEdit (cellRect, 0, -1, initialText);
	db->dbCellSetupTextEdit(row, column, te, this);
	addView (te);
	te->takeFocus ();
	getFrame ()->setFocusView (te);
	// save row and column
	te->setAttribute ('row ', sizeof (long), &row);
	te->setAttribute ('col ', sizeof (long), &column);
}

//-----------------------------------------------------------------------------------------------
CMessageResult CDataBrowser::notify (CBaseObject* sender, const char* message)
{
	if (message == kMsgLooseFocus)
	{
		CTextEdit* te = dynamic_cast<CTextEdit*>(sender);
		if (te)
		{
			// get row and column
			long row = kNoSelection;
			long col = kNoSelection;
			long outSize;
			te->getAttribute ('row ', sizeof (long), &row, outSize);
			te->getAttribute ('col ', sizeof (long), &col, outSize);
			char newText[256] = {0};
			te->getText (newText);
			getFrame ()->setFocusView (0);
			removeView (te);
			db->dbCellTextChanged (row, col, newText, this);
			return kMessageNotified;
		}
	}
	return CViewContainer::notify (sender, message);
}

/// \cond ignore
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
CDataBrowserHeader::CDataBrowserHeader (const CRect& size, IDataBrowser* db, CDataBrowser* browser, long style)
: CView (size)
, db (db)
, browser (browser)
, style (style)
{
	setTransparency (true);
}

//-----------------------------------------------------------------------------------------------
void CDataBrowserHeader::draw (CDrawContext* context)
{
	drawRect (context, size);
}

//-----------------------------------------------------------------------------------------------
void CDataBrowserHeader::drawRect (CDrawContext* context, const CRect& updateRect)
{
	CColor lineColor;
	CCoord lineWidth = 0;
	if (style & CDataBrowser::kDrawRowLines || style & CDataBrowser::kDrawColumnLines)
	{
		db->dbGetLineWidthAndColor (lineWidth, lineColor, browser);
	}
	CCoord rowHeight = db->dbGetRowHeight (browser);
	if (style & CDataBrowser::kDrawRowLines)
		rowHeight += lineWidth;
	long numColumns = db->dbGetNumColumns (browser);

	CRect r (size.left, size.top, 0, 0);
	r.setHeight (rowHeight);
	for (long col = 0; col < numColumns; col++)
	{
		CCoord columnWidth = db->dbGetCurrentColumnWidth (col, browser);
		r.setWidth (columnWidth);
		CRect testRect (r);
		testRect.bound (updateRect);
		if (!testRect.isEmpty ())
		{
			db->dbDrawHeader (context, r, col, 0, browser);
		}
		r.offset (columnWidth, 0);
		if (style & CDataBrowser::kDrawColumnLines)
			r.offset (lineWidth, 0);
	}
	setDirty (false);
}

//-----------------------------------------------------------------------------------------------
long CDataBrowserHeader::getColumnAtPoint (CPoint& where)
{
	// calculate column at point
	CCoord lineWidth = 0;
	if (style & CDataBrowser::kDrawRowLines || style & CDataBrowser::kDrawColumnLines)
	{
		CColor lineColor;
		db->dbGetLineWidthAndColor (lineWidth, lineColor, browser);
	}
	long col = -1;
	long numColumns = db->dbGetNumColumns (browser);
	CRect r (size.left, size.top, 0, size.bottom);
	for (long c = 0; c < numColumns; c++)
	{
		CCoord columnWidth = db->dbGetCurrentColumnWidth (c, browser);
		if (style & CDataBrowser::kDrawColumnLines)
			columnWidth += lineWidth;
		r.setWidth (columnWidth);
		if (r.pointInside (where))
		{
			if (r.right - where.x < 5)
				col = c;
			break;
		}
		r.offset (columnWidth, 0);
	}
	return col;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserHeader::onMouseDown (CPoint &where, const long& buttons)
{
	mouseColumn = getColumnAtPoint (where);
	CCoord minWidth;
	CCoord maxWidth;
	if (mouseColumn >= 0 && db->dbGetColumnDescription (mouseColumn, minWidth, maxWidth, browser) && minWidth != maxWidth)
	{
		startWidth = db->dbGetCurrentColumnWidth (mouseColumn, browser);
		startMousePoint = where;
		getFrame ()->setCursor (kCursorHSize);
		return onMouseMoved (where, buttons);
	}
	return kMouseDownEventHandledButDontNeedMovedOrUpEvents;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserHeader::onMouseMoved (CPoint &where, const long& buttons)
{
	if (buttons & kLButton)
	{
		CCoord xOffset = where.x - startMousePoint.x;
		if (xOffset != 0)
		{
			CCoord minWidth;
			CCoord maxWidth;
			if (db->dbGetColumnDescription (mouseColumn, minWidth, maxWidth, browser))
			{
				CCoord columnWidth = db->dbGetCurrentColumnWidth (mouseColumn, browser);
				CCoord newWidth = startWidth + xOffset;
				if (newWidth < minWidth)
					newWidth = minWidth;
				if (newWidth > maxWidth)
					newWidth = maxWidth;
				if (newWidth != columnWidth)
				{
					db->dbSetCurrentColumnWidth (mouseColumn, newWidth, browser);
					browser->recalculateLayout (true);
				}
			}
			else
				return kMouseEventNotHandled;
		}
	}
	else
	{
		long col = getColumnAtPoint (where);
		CCoord minWidth;
		CCoord maxWidth;
		if (col >= 0 && db->dbGetColumnDescription (mouseColumn, minWidth, maxWidth, browser) && minWidth != maxWidth)
			getFrame ()->setCursor (kCursorHSize);
		else
			getFrame ()->setCursor (kCursorDefault);
	}
	return kMouseEventHandled;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserHeader::onMouseExited (CPoint &where, const long& buttons)
{
	getFrame ()->setCursor (kCursorDefault);
	return kMouseEventHandled;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserHeader::onMouseUp (CPoint &where, const long& buttons)
{
	getFrame ()->setCursor (kCursorDefault);
	return kMouseEventHandled;
}

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
CDataBrowserView::CDataBrowserView (const CRect& size, IDataBrowser* db, CDataBrowser* browser, long style)
: CView (size)
, db (db)
, browser (browser)
, style (style)
{
	setTransparency (true);
	setWantsFocus (true);
}

//-----------------------------------------------------------------------------------------------
CRect CDataBrowserView::getRowBounds (long row)
{
	CCoord lineWidth = 0;
	if (style & CDataBrowser::kDrawRowLines || style & CDataBrowser::kDrawColumnLines)
	{
		CColor lineColor;
		db->dbGetLineWidthAndColor (lineWidth, lineColor, browser);
	}
	CCoord rowHeight = db->dbGetRowHeight (browser);

	CRect where (size);
	where.offset (-size.left, -size.top);
	if (style & CDataBrowser::kDrawRowLines)
		rowHeight+=lineWidth;

	CRect r (size.left, size.top + rowHeight * row, size.right, size.top + rowHeight * (row+1));
	return r;
}

//-----------------------------------------------------------------------------------------------
void CDataBrowserView::invalidateRow (long row)
{
	if (row == CDataBrowser::kNoSelection)
		return;

	CRect ia = getRowBounds (row);
	invalidRect (ia);
}

//-----------------------------------------------------------------------------------------------
void CDataBrowserView::draw (CDrawContext* context)
{
	drawRect (context, size);
}

//-----------------------------------------------------------------------------------------------
void CDataBrowserView::drawRect (CDrawContext* context, const CRect& updateRect)
{
	CCoord lineWidth = 0;
	CColor lineColor;
	if (style & CDataBrowser::kDrawRowLines || style & CDataBrowser::kDrawColumnLines)
	{
		db->dbGetLineWidthAndColor (lineWidth, lineColor, browser);
	}
	CCoord rowHeight = db->dbGetRowHeight (browser);
	if (style & CDataBrowser::kDrawRowLines)
		rowHeight += lineWidth;
	long numRows = db->dbGetNumRows (browser);
	long numColumns = db->dbGetNumColumns (browser);

	CRect r (size.left, size.top, 0, 0);
	for (long col = 0; col < numColumns; col++)
	{
		CCoord columnWidth = db->dbGetCurrentColumnWidth (col, browser);
		r.setWidth (columnWidth);
		r.setHeight (size.getHeight ());
		CRect testRect (r);
		testRect.bound (updateRect);
		if (testRect.isEmpty ())
		{
			r.offset (columnWidth, 0);
			if (style & CDataBrowser::kDrawColumnLines)
				r.offset (lineWidth, 0);
			continue;
		}
		r.setHeight (rowHeight);
		for (long row = 0; row < numRows; row++)
		{
			CRect testRect2 (r);
			testRect2.bound (updateRect);
			if (!testRect2.isEmpty ())
				db->dbDrawCell (context, r, row, col, browser->getSelectedRow () == row ? IDataBrowser::kRowSelected : 0, browser);
			r.offset (0, rowHeight);
		}
		r.offset (columnWidth, 0);
		if (style & CDataBrowser::kDrawColumnLines)
		{
			context->setLineWidth (lineWidth);
			context->setFrameColor (lineColor);
			context->moveTo (CPoint (r.left + lineWidth/2, size.top));
			context->lineTo (CPoint (r.left + lineWidth/2, size.bottom));
			r.offset (lineWidth, 0);
		}
		r.top = size.top;
	}
	if (style & CDataBrowser::kDrawRowLines)
	{
		context->setLineWidth (lineWidth);
		context->setFrameColor (lineColor);
		CRect rr (size.left, size.top, size.right, size.top + rowHeight);
		for (long row = 0; row < numRows; row++)
		{
			context->moveTo (CPoint (rr.left, rr.bottom));
			context->lineTo (CPoint (rr.right, rr.bottom));
			rr.offset (0, rowHeight);
		}
	}
	setDirty (false);
}

//-----------------------------------------------------------------------------------------------
bool CDataBrowserView::getCell (CPoint& where, long& row, long& column)
{
	CCoord lineWidth = 0;
	if (style & CDataBrowser::kDrawRowLines || style & CDataBrowser::kDrawColumnLines)
	{
		CColor lineColor;
		db->dbGetLineWidthAndColor (lineWidth, lineColor, browser);
	}
	CCoord rowHeight = db->dbGetRowHeight (browser);
	long numColumns = db->dbGetNumColumns (browser);

	CPoint _where (where);
	_where.offset (-size.left, -size.top);
	if (style & CDataBrowser::kDrawRowLines)
		rowHeight += lineWidth;
	long rowNum = (long)(_where.y / rowHeight);
	long colNum = 0;
	CCoord cw = 0;
	for (long i = 0; i < numColumns; i++)
	{
		cw += db->dbGetCurrentColumnWidth (i, browser);
		if (style & CDataBrowser::kDrawColumnLines)
			cw += lineWidth;
		if (_where.x < cw)
		{
			colNum = i;
			row = rowNum;
			column = colNum;
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserView::onMouseDown (CPoint &where, const long& buttons)
{
	long rowNum = -1;
	long colNum = -1;
	if (getCell (where, rowNum, colNum))
	{
		if (rowNum != browser->getSelectedRow ())
		{
			invalidateRow (rowNum);
			invalidateRow (browser->getSelectedRow ());
			browser->setSelectedRow (rowNum);
		}
		return db->dbOnMouseDown (where, buttons, rowNum, colNum, browser);
	}
	return kMouseEventHandled;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserView::onMouseMoved (CPoint &where, const long& buttons)
{
	long rowNum = -1;
	long colNum = -1;
	if (getCell (where, rowNum, colNum))
	{
		return db->dbOnMouseMoved (where, buttons, rowNum, colNum, browser);
	}
	return kMouseEventNotHandled;
}

//-----------------------------------------------------------------------------------------------
CMouseEventResult CDataBrowserView::onMouseUp (CPoint &where, const long& buttons)
{
	long rowNum = -1;
	long colNum = -1;
	if (getCell (where, rowNum, colNum))
	{
		return db->dbOnMouseUp (where, buttons, rowNum, colNum, browser);
	}
	return kMouseEventNotHandled;
}

//-----------------------------------------------------------------------------------------------
long CDataBrowserView::onKeyDown (VstKeyCode& keyCode)
{
	if (keyCode.virt == VKEY_UP || keyCode.virt == VKEY_DOWN)
	{
		long numRows = db->dbGetNumRows (browser);
		long selRow = browser->getSelectedRow ();
		if ((selRow > 0 && keyCode.virt == VKEY_UP) || (selRow < numRows-1 && keyCode.virt == VKEY_DOWN))
		{
			invalidateRow (selRow);
			selRow += keyCode.virt == VKEY_UP ? -1 : 1;
			invalidateRow (selRow);
			browser->setSelectedRow (selRow, true);
			CRect rect = getRowBounds (selRow);
			
			browser->makeRectVisible (rect);
		}
		return 1;
	}
	return -1;
}
/// \endcond

