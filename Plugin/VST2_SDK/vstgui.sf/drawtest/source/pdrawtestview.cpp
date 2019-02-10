//-------------------------------------------------------------------------------------------------------
//  VSTGUI Test View plugin
//  Copyright (c) 2004 Arne Scheffler. All rights reserved.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//-------------------------------------------------------------------------------------------------------

#ifndef __pdrawtestview__
#include "pdrawtestview.h"
#endif

#include <stdio.h>

static long diffX, diffY;

CDrawTestView::CDrawTestView (const CRect& size)
: CView (size)
, value (0)
{
	diffX = diffY = 0;
}

static inline void testDrawRect (CDrawContext *pContext, CRect r, int _offset = 0)
{
	int offset = _offset ? _offset : pContext->getLineWidth ();
	int i = 0;
	while (r.width () > 1 && r.height () > 1)
	{
		if (i++ % 2)
			pContext->setFrameColor (kBlackCColor);
		else
			pContext->setFrameColor (kRedCColor);
		pContext->drawRect (r);
		r.inset (offset, offset);
	}
}

static inline void testFillRect (CDrawContext *pContext, CRect r)
{
	int i = 0;
	while (r.width () > 1 && r.height () > 1)
	{
		if (i++ % 2)
			pContext->setFillColor (kYellowCColor);
		else
			pContext->setFillColor (kCyanCColor);
		r.inset (1,1);
		pContext->drawRect (r, kDrawFilled);
	}
}

static inline void testDrawLine (CDrawContext *pContext, CRect r, int _offset = 0)
{
	int offset = _offset ? _offset : pContext->getLineWidth ();
	int i = 0;
	while (r.width () > 1 && r.height () > 1)
	{
		if (i++ % 2)
			pContext->setFrameColor (kBlueCColor);
		else
			pContext->setFrameColor (kGreenCColor);
//		pContext->setClipRect (r);
		pContext->moveTo (CPoint (r.left, r.top));
		pContext->lineTo (CPoint (r.right, r.top));
		pContext->lineTo (CPoint (r.right, r.bottom));
		pContext->lineTo (CPoint (r.left, r.bottom));
		pContext->lineTo (CPoint (r.left, r.top));
//		pContext->drawRect (r);
		r.inset (offset,offset);
	}
}

static inline void drawVerticalLines (CDrawContext *pContext, CRect r, int _offset = 0)
{
	int offset = _offset ? _offset : pContext->getLineWidth ();
	int i = 0;
	CPoint p (0, r.top);
	while (p.y < r.bottom)
	{
		if (i++ % 2)
			pContext->setFrameColor (kBlueCColor);
		else
			pContext->setFrameColor (kGreenCColor);
		pContext->moveTo (CPoint (r.left, p.y));
		pContext->lineTo (CPoint (r.right, p.y));
		p.offset (0,offset);
	}
}

static inline void clearRect (CDrawContext* pContext, const CRect& r)
{
	pContext->setFillColor (kWhiteCColor);
	pContext->setLineWidth (1);
	pContext->setFrameColor (kBlackCColor);
	pContext->drawRect (r, kDrawFilledAndStroked);
}

static inline void drawLines (CDrawContext* pContext, CRect r, int offset = 2)
{
	CRect size (r);
	pContext->setFrameColor (kBlueCColor);
	int i;
	for (i = 0; i < size.height (); i++)
	{
		pContext->moveTo (CPoint (r.left, r.top));
		pContext->lineTo (CPoint (r.right, r.bottom));
		r.offset (0, offset);
	}
	for (i = 0; i < size.height (); i++)
	{
		size.offset (0, -offset);
		pContext->moveTo (CPoint (size.left, size.top));
		pContext->lineTo (CPoint (size.right, size.bottom));
	}
}


CColor arcColors[] = { {0,0,255,255}, {255,0,255,255}, {0,255,0,255}, {255,0,0,255}, {255, 255, 0, 255} };

#define numArcColors	4

static inline void drawArcs (CDrawContext* pContext, CRect r, int offset = 2)
{
	r.inset (diffX, diffY);
	int i = 0;
	while (r.width () > 1 && r.height () > 1)
	{
		pContext->setFrameColor (arcColors[i++]); if (i > numArcColors) i = 0;
		pContext->drawArc (r, CPoint (r.left, r.top + r.height () / 2), CPoint (r.left + r.width () / 2, r.bottom));
		pContext->setFrameColor (arcColors[i++]); if (i > numArcColors) i = 0;
		pContext->drawArc (r, CPoint (r.left + r.width () / 2, r.bottom), CPoint (r.right, r.top + r.height () / 2));
		pContext->setFrameColor (arcColors[i++]); if (i > numArcColors) i = 0;
		pContext->drawArc (r, CPoint (r.right, r.top + r.height () / 2), CPoint (r.left + r.width () / 2, r.top));
		pContext->setFrameColor (arcColors[i++]); if (i > numArcColors) i = 0;
		pContext->drawArc (r, CPoint (r.left + r.width () / 2, r.top), CPoint (r.left, r.top + r.height () / 2));
		r.inset (offset, offset);
	}
}

static inline void drawEllipses (CDrawContext* pContext, CRect r, int offset = 2)
{
	r.inset (diffX, diffY);
	int i = 0;
	while (r.width () > 1 && r.height () > 1)
	{
		pContext->setFrameColor (arcColors[i++]); if (i > numArcColors) i = 0;
		pContext->drawEllipse (r);
		r.inset (offset, offset);
	}
}

#define kMaxValue	10

void CDrawTestView::draw (CDrawContext *pContext)
{
	char str[256];
	str[0] = 0;
	sprintf (str, "Click for Next");
	CRect r (size);
	pContext->setDrawMode (kCopyMode);
	clearRect (pContext, r);
	r.inset (1, 1);
	switch (value)
	{
		case 0:
		{
			pContext->setLineWidth (1);
			testDrawRect (pContext, r);
			break;
		}
		case 1:
		{
			pContext->setLineWidth (1);
			testDrawLine (pContext, r, 2);
			break;
		}
		case 2:
		{
			testFillRect (pContext, r);
			break;
		}
		case 3:
		{
			pContext->setLineWidth (2);
			testDrawLine (pContext, r);
			break;
		}
		case 4:
		{
			pContext->setDrawMode (kAntialias);
			pContext->setLineWidth (2);
			testDrawLine (pContext, size);
			break;
		}
		case 5:
		{
			pContext->setDrawMode (kAntialias);
			pContext->setLineWidth (1);
			testDrawLine (pContext, r);
			break;
		}
		case 6:
		{
			pContext->setLineWidth (1);
			drawLines (pContext, r, 4);
			break;
		}
		case 7:
		{
			pContext->setDrawMode (kAntialias);
			pContext->setLineWidth (1);
			drawLines (pContext, r, 4);
			break;
		}
		case 8:
		{
			pContext->setDrawMode (kAntialias);
			pContext->setLineWidth (4);
			drawArcs (pContext, r, 8);
			break;
		}
		case 9:
		{
			pContext->setDrawMode (kAntialias);
			pContext->setLineWidth (4);
			drawEllipses (pContext, r, 8);
			break;
		}
		case 10:
		{
			pContext->setLineStyle (kLineOnOffDash);
			//pContext->setDrawMode (kAntialias);
			pContext->setLineWidth (1);
			drawVerticalLines (pContext, r, 3);
			break;
		}
	}
	pContext->setFont (kSystemFont);
	pContext->setFontColor (kWhiteCColor);
	pContext->drawString (str, r);
	pContext->setFontColor (kBlackCColor);
	r.offset (-1, -1);
	pContext->drawString (str, r, true);
	pContext->setDrawMode (kCopyMode);
	setDirty (false);
}

#if VSTGUI_ENABLE_DEPRECATED_METHODS
void CDrawTestView::mouse (CDrawContext* pContext, CPoint& where, long buttons)
{
	if (buttons & kLButton)
	{
		if (buttons & kShift)
		{
			CPoint start (where);
			while ((buttons = pContext->getMouseButtons ()))
			{
				if (pContext->waitDrag ())
				{
					CPoint now;
					getMouseLocation (pContext, now);
					diffX += start.x - now.x;
					diffY += start.y - now.y;
					start = now;
					setDirty (true);
					if (pParentFrame) pParentFrame->doIdleStuff ();
				}
			}
		}
		else
		{
			value++;
			if (value > kMaxValue)
				value = 0;
		}
	}
	else if (buttons & kRButton)
	{
		value--;
		if (value < 0)
			value = kMaxValue;
	}
	setDirty (true);
}
#endif
