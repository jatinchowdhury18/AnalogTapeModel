//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins : 
//
// Version 3.6
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

#ifndef __cscrollview__
#include "cscrollview.h"
#endif

#include "cvstguitimer.h"

/// \cond ignore

#define FOREACHSUBVIEW for (CCView *pSv = pFirstView; pSv; pSv = pSv->pNext) {CView *pV = pSv->pView;
#define ENDFOR }

BEGIN_NAMESPACE_VSTGUI

// CScrollContainer is private
//-----------------------------------------------------------------------------
class CScrollContainer : public CViewContainer
//-----------------------------------------------------------------------------
{
public:
	CScrollContainer (const CRect &size, const CRect &containerSize, CFrame *pParent, CBitmap *pBackground = 0);
	CScrollContainer (const CScrollContainer& v);
	~CScrollContainer ();

	void setScrollOffset (CPoint offset, bool withRedraw = false);
	void getScrollOffset (CPoint& off) const { off = offset; }
	const CPoint& getScrollOffset () const { return offset; }

	CRect getContainerSize () const { return containerSize; }
	void setContainerSize (const CRect& cs);
	
	bool isDirty () const;

	CLASS_METHODS(CScrollContainer, CViewContainer)
//-----------------------------------------------------------------------------
protected:
	CRect containerSize;
	CPoint offset;
};

END_NAMESPACE_VSTGUI

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CScrollContainer::CScrollContainer (const CRect &size, const CRect &containerSize, CFrame *pParent, CBitmap *pBackground)
: CViewContainer (size, pParent, pBackground)
, containerSize (containerSize)
, offset (CPoint (0, 0))
{
}

//-----------------------------------------------------------------------------
CScrollContainer::CScrollContainer (const CScrollContainer& v)
: CViewContainer (v)
, containerSize (v.containerSize)
, offset (v.offset)
{
}

//-----------------------------------------------------------------------------
CScrollContainer::~CScrollContainer ()
{
}


//-----------------------------------------------------------------------------
void CScrollContainer::setContainerSize (const CRect& cs)
{
	containerSize = cs;
	setScrollOffset (offset, false);
}

//-----------------------------------------------------------------------------
void CScrollContainer::setScrollOffset (CPoint newOffset, bool redraw)
{
	if (newOffset.x < containerSize.left - containerSize.width ())
		newOffset.x = containerSize.left - containerSize.width ();
	if (newOffset.x > containerSize.right)
		newOffset.x = containerSize.right;
	if (newOffset.y < containerSize.top)
		newOffset.y = containerSize.top;
	if (newOffset.y > containerSize.bottom)
		newOffset.y = containerSize.bottom;
	CPoint diff ((CCoord)(newOffset.x - offset.x), (CCoord)(offset.y - newOffset.y));
	if (diff.x == 0 && diff.y == 0)
		return;
	CCView *pV = pFirstView;
	while (pV)
	{
		CRect r;
		pV->pView->getViewSize (r);
		r.offset (diff.x , diff.y);
		pV->pView->setViewSize (r, false);
		pV->pView->getMouseableArea (r);
		r.offset (diff.x , diff.y);
		pV->pView->setMouseableArea (r);

		pV = pV->pNext;
	}
	offset = newOffset;
	if (getTransparency ())
	{
		invalid ();
	}
	else
	{
		CRect scrollRect (0, 0, size.getWidth (), size.getHeight ());
		CPoint p;
		localToFrame (p);
		scrollRect.offset (p.x, p.y);
		CRect visibleRect = getVisibleSize (CRect (0, 0, size.getWidth (), size.getHeight ()));
		visibleRect.offset (p.x, p.y);
		scrollRect.bound (visibleRect);

		CPoint distance (diff.x, diff.y);
		if (distance.x > 0)
			scrollRect.right -= distance.x;
		else if (distance.x < 0)
			scrollRect.left -= distance.x;
		if (distance.y > 0)
			scrollRect.bottom -= distance.y;
		else if (distance.y < 0)
			scrollRect.top -= distance.y;
		getFrame ()->scrollRect (scrollRect, distance);
	}
}

//-----------------------------------------------------------------------------
bool CScrollContainer::isDirty () const
{
	if (bDirty)
		return true;
		
	FOREACHSUBVIEW
		if (pV->isDirty ())
		{
			CRect r = pV->getVisibleSize ();
			if (r.getWidth () > 0 && r.getHeight () > 0)
				return true;
			else
				pV->setDirty (false);
		}
	ENDFOR
	return false;
}

/// \endcond

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
CScrollView::CScrollView (const CRect &size, const CRect &containerSize, CFrame* pParent, long style, CCoord scrollbarWidth, CBitmap* pBackground)
: CViewContainer (size, pParent, pBackground)
, sc (0)
, vsb (0)
, hsb (0)
, containerSize (containerSize)
, style (style)
{
	CRect scsize (0, 0, size.getWidth (), size.getHeight ());
	if (!(style & kDontDrawFrame))
	{
		scsize.left++; scsize.top++;
		scsize.right-=1; scsize.bottom--;
	}
	if (style & kHorizontalScrollbar)
	{
		CRect sbr (size);
		sbr.offset (-size.left, -size.top);
		sbr.top = sbr.bottom - scrollbarWidth;
		if (style & kVerticalScrollbar)
		{
			sbr.right -= (scrollbarWidth - 1);
		}
		hsb = new CScrollbar (sbr, this, kHSBTag, CScrollbar::kHorizontal, containerSize);
		hsb->setAutosizeFlags (kAutosizeLeft | kAutosizeRight | kAutosizeBottom);
		CViewContainer::addView (hsb);
		scsize.bottom = sbr.top;
	}
	if (style & kVerticalScrollbar)
	{
		CRect sbr (size);
		sbr.offset (-size.left, -size.top);
		sbr.left = sbr.right - scrollbarWidth;
		if (style & kHorizontalScrollbar)
		{
			sbr.bottom -= (scrollbarWidth - 1);
		}
		vsb = new CScrollbar (sbr, this, kVSBTag, CScrollbar::kVertical, containerSize);
		vsb->setAutosizeFlags (kAutosizeTop | kAutosizeRight | kAutosizeBottom);
		CViewContainer::addView (vsb);
		scsize.right = sbr.left;
	}

	sc = new CScrollContainer (scsize, this->containerSize, pParent);
	sc->setAutosizeFlags (kAutosizeAll);
	CViewContainer::addView (sc);
}

//-----------------------------------------------------------------------------
CScrollView::CScrollView (const CScrollView& v)
: CViewContainer (v)
, containerSize (v.containerSize)
, style (v.style)
{
	CViewContainer::removeAll ();
	if (style & kHorizontalScrollbar && v.hsb)
	{
		hsb = (CScrollbar*)v.hsb->newCopy ();
		hsb->setListener (this);
		CViewContainer::addView (hsb);
	}
	if (style & kVerticalScrollbar && v.vsb)
	{
		vsb = (CScrollbar*)v.vsb->newCopy ();
		vsb->setListener (this);
		CViewContainer::addView (vsb);
	}
	sc = (CScrollContainer*)v.sc->newCopy ();
	CViewContainer::addView (sc);
}

//-----------------------------------------------------------------------------
CScrollView::~CScrollView ()
{
}

//-----------------------------------------------------------------------------
void CScrollView::setViewSize (CRect &rect, bool invalid)
{
	CViewContainer::setViewSize (rect, invalid);
	setContainerSize (containerSize, true);
}

//-----------------------------------------------------------------------------
void CScrollView::setContainerSize (const CRect& cs, bool keepVisibleArea)
{
	CRect oldSize (containerSize);
	containerSize = cs;
	if (sc)
	{
		sc->setContainerSize (cs);
	}
	if (vsb)
	{
		CRect oldScrollSize = vsb->getScrollSize (oldScrollSize);
		float oldValue = vsb->getValue ();
		vsb->setScrollSize (cs);
		if (cs.getHeight () < size.getHeight ())
			vsb->setValue (0);
		else if (keepVisibleArea && oldScrollSize.getHeight () != cs.getHeight ())
		{
			CRect vSize = sc->getViewSize (vSize);
			float newValue = oldValue * ((float)(oldScrollSize.getHeight () - vSize.getHeight ()) / ((float)cs.getHeight () - vSize.getHeight ()));
			if (newValue > 1.f)
				newValue = 1.f;
			else if (newValue < 0.f)
				newValue = 0.f;
			vsb->setValue (newValue);
		}
		valueChanged (vsb);
	}
	if (hsb)
	{
		CRect oldScrollSize = hsb->getScrollSize (oldScrollSize);
		float oldValue = hsb->getValue ();
		hsb->setScrollSize (cs);
		if (cs.getWidth () < size.getWidth ())
			hsb->setValue (0);
		else if (keepVisibleArea && oldScrollSize.getWidth () != cs.getWidth ())
		{
			CRect vSize = sc->getViewSize (vSize);
			float newValue = oldValue * ((float)(oldScrollSize.getWidth () - vSize.getWidth ()) / ((float)cs.getWidth () - vSize.getWidth ()));
			if (newValue > 1.f)
				newValue = 1.f;
			else if (newValue < 0.f)
				newValue = 0.f;
			hsb->setValue (newValue);
		}
		valueChanged (hsb);
	}
}

//-----------------------------------------------------------------------------
void CScrollView::makeRectVisible (const CRect& rect)
{
	CRect r (rect);
	const CPoint& scrollOffset = sc->getScrollOffset ();
	CPoint newOffset (scrollOffset);
	CRect vs;
	sc->getViewSize (vs);
	if (!(style & kDontDrawFrame))
	{
		vs.left--; //vs.top--;
		vs.right++; //vs.bottom++;
	}
	CRect cs (containerSize);
	cs.offset (-cs.left, -cs.top);
	cs.setWidth (vs.getWidth ());
	cs.setHeight (vs.getHeight ());
	if (r.top >= cs.top && r.bottom <= cs.bottom && r.left >= cs.left && r.right <= cs.right)
		return;
	if (r.top < cs.top)
	{
		newOffset.y -= (cs.top - r.top);
	}
	else if (r.bottom > cs.bottom)
	{
		newOffset.y += (r.bottom - cs.bottom);
	}
	if (r.left < cs.left)
	{
		newOffset.x += (cs.left - r.left);
	}
	else if (r.right > cs.right && r.left != cs.left)
	{
		newOffset.x += (r.right - cs.right);
	}
	if (newOffset != scrollOffset)
	{
		if (vsb)
		{
			vsb->setValue ((float)(newOffset.y - vs.top) / (float)(containerSize.getHeight () - vs.getHeight ()));
			valueChanged (vsb);
		}
		if (hsb)
		{
			hsb->setValue ((float)(newOffset.x - vs.left) / (float)(containerSize.getWidth () - vs.getWidth ()));
			valueChanged (hsb);
		}
	}
}

//-----------------------------------------------------------------------------
const CPoint& CScrollView::getScrollOffset () const
{
	return sc->getScrollOffset ();
}

//-----------------------------------------------------------------------------
bool CScrollView::addView (CView *pView)
{
	return sc->addView (pView);
}

//-----------------------------------------------------------------------------
bool CScrollView::addView (CView *pView, CRect &mouseableArea, bool mouseEnabled)
{
	return sc->addView (pView, mouseableArea, mouseEnabled);
}

//-----------------------------------------------------------------------------
bool CScrollView::removeView (CView *pView, const bool &withForget)
{
	return sc->removeView (pView, withForget);
}

//-----------------------------------------------------------------------------
bool CScrollView::removeAll (const bool &withForget)
{
	return sc->removeAll ();
}

//-----------------------------------------------------------------------------
bool CScrollView::isChild (CView *pView) const
{
	return sc->isChild (pView);
}

//-----------------------------------------------------------------------------
long CScrollView::getNbViews () const
{
	return sc->getNbViews ();
}

//-----------------------------------------------------------------------------
CView* CScrollView::getView (long index) const
{
	return sc->getView (index);
}

//-----------------------------------------------------------------------------
void CScrollView::setTransparency (bool val)
{
	CViewContainer::setTransparency (val);
	sc->setTransparency (val);
}

//-----------------------------------------------------------------------------
void CScrollView::setBackgroundColor (const CColor& color)
{
	CViewContainer::setBackgroundColor (color);
	sc->setBackgroundColor (color);
}

//-----------------------------------------------------------------------------
void CScrollView::valueChanged (CControl *pControl)
{
	if (sc)
	{
		float value = pControl->getValue ();
		long tag = pControl->getTag ();
		CPoint offset;
		CRect vsize = sc->getViewSize (vsize);
		CRect csize = sc->getContainerSize ();
		sc->getScrollOffset (offset);
			
		switch (tag)
		{
			case kHSBTag:
			{
				if (csize.getWidth () > vsize.getWidth ())
				{
					offset.x = (CCoord) (csize.left - (csize.width () - vsize.width ()) * value);
					sc->setScrollOffset (offset, false);
				}
				else if (offset.x > 0)
				{
					offset.x = 0;
					sc->setScrollOffset (offset, false);
				}
				break;
			}
			case kVSBTag:
			{
				if (csize.getHeight () > vsize.getHeight ())
				{
					offset.y = (CCoord) (csize.top + (csize.height () - vsize.height ()) * value);
					sc->setScrollOffset (offset, false);
				}
				else if (offset.y > 0)
				{
					offset.y = 0;
					sc->setScrollOffset (offset, false);
				}
				break;
			}
		}
	}
}

//-----------------------------------------------------------------------------
void CScrollView::drawBackgroundRect (CDrawContext *pContext, CRect& _updateRect)
{
	CViewContainer::drawBackgroundRect (pContext, _updateRect);
	if (!(style & kDontDrawFrame))
	{
		CRect r (size);
		r.offset (-r.left, -r.top);
		pContext->setFrameColor (kBlackCColor);
		pContext->setLineWidth (1);
		pContext->drawRect (r);
	}
}

//-----------------------------------------------------------------------------
bool CScrollView::onWheel (const CPoint &where, const CMouseWheelAxis &axis, const float &distance, const long &buttons)
{
	bool result = CViewContainer::onWheel (where, axis, distance, buttons);
	if (!result)
	{
		if (vsb && axis == kMouseWheelAxisY)
			result = vsb->onWheel (where, axis, distance, buttons);
		else if (hsb && axis == kMouseWheelAxisX)
			result = hsb->onWheel (where, axis, distance, buttons);
	}
	return result;
}

//-----------------------------------------------------------------------------
CScrollbar::CScrollbar (const CRect& size, CControlListener* listener, long tag, ScrollbarDirection direction, const CRect& scrollSize)
: CControl (size, listener, tag, 0)
, direction (direction)
, scrollSize (scrollSize)
, scrollerArea (size)
, stepValue (0.1f)
, scrollerLength (0)
, drawer (0)
, timer (0)
{
	setWheelInc (0.05f);
	scrollerArea.inset (2, 2);
	calculateScrollerLength ();
	frameColor (0, 0, 0, 255);
	scrollerColor (0, 0, 255, 255);
	backgroundColor (255, 255, 255, 200);
}

//-----------------------------------------------------------------------------
CScrollbar::CScrollbar (const CScrollbar& v)
: CControl (v)
, direction (v.direction)
, scrollSize (v.scrollSize)
, scrollerArea (v.scrollerArea)
, stepValue (v.stepValue)
, scrollerLength (v.scrollerLength)
, frameColor (v.frameColor)
, scrollerColor (v.scrollerColor)
, backgroundColor (v.backgroundColor)
, drawer (v.drawer)
, timer (0)
{
	calculateScrollerLength ();
}

//-----------------------------------------------------------------------------
CScrollbar::~CScrollbar ()
{
}

//-----------------------------------------------------------------------------
void CScrollbar::setViewSize (CRect &newSize, bool invalid)
{
	scrollerArea = newSize;
	scrollerArea.inset (2, 2);
	CControl::setViewSize (newSize, invalid);
}

//-----------------------------------------------------------------------------
void CScrollbar::setScrollSize (const CRect& ssize)
{
	scrollSize = ssize;
	calculateScrollerLength ();
	setDirty (true);
}

//-----------------------------------------------------------------------------
void CScrollbar::calculateScrollerLength ()
{
	CCoord newScrollerLength = scrollerLength;
	if (direction == kHorizontal)
	{
		float factor = (float)size.width () / (float)scrollSize.width ();
		if (factor >= 1.f)
			factor = 0;
		newScrollerLength = (CCoord) (size.width () * factor);
	}
	else
	{
		float factor = (float)size.height () / (float)scrollSize.height ();
		if (factor >= 1.f)
			factor = 0;
		newScrollerLength = (CCoord) (size.height () * factor);
	}
	if (newScrollerLength != scrollerLength)
	{
		scrollerLength = newScrollerLength;
		setDirty (true);
	}
}

//-----------------------------------------------------------------------------
CRect CScrollbar::getScrollerRect ()
{
	CRect scrollerRect (scrollerArea);
	CCoord l = (direction == kHorizontal) ? scrollerArea.width () : scrollerArea.height ();
	CCoord scrollerOffset = (CCoord) (value * (l - scrollerLength));
	if (direction == kHorizontal)
	{
		scrollerRect.setWidth (scrollerLength);
		scrollerRect.offset (scrollerOffset, 0);
	}
	else
	{
		scrollerRect.setHeight (scrollerLength);
		scrollerRect.offset (0, scrollerOffset);
	}
	return scrollerRect;
}

//-----------------------------------------------------------------------------
void CScrollbar::doStepping ()
{
	CRect scrollerRect = getScrollerRect ();
	if (timer)
	{
		if (!startPoint.isInside (size) || startPoint.isInside (scrollerRect))
			return;
	}
	bool dir = (direction == kHorizontal && startPoint.x < scrollerRect.left) || (direction == kVertical && startPoint.y < scrollerRect.top);
	float newValue = value;
	if (direction == kHorizontal)
	{
		if (dir)
			newValue = value - (float)scrollerLength / (float)scrollerArea.width ();
		else
			newValue = value + (float)scrollerLength / (float)scrollerArea.width ();
	}
	else
	{
		if (dir)
			newValue = value - (float)scrollerLength / (float)scrollerArea.height ();
		else
			newValue = value + (float)scrollerLength / (float)scrollerArea.height ();
	}
	if (newValue < 0.f) newValue = 0.f;
	if (newValue > 1.f) newValue = 1.f;
	if (newValue != value)
	{
		value = newValue;
		if (listener)
			listener->valueChanged (this);
		invalid ();
	}
}

//-----------------------------------------------------------------------------
CMessageResult CScrollbar::notify (CBaseObject* sender, const char* message)
{
	if (message == CVSTGUITimer::kMsgTimer && timer)
	{
		doStepping ();
		timer->setFireTime (80);
		return kMessageNotified;
	}
	return kMessageUnknown;
}

//-----------------------------------------------------------------------------
CMouseEventResult CScrollbar::onMouseDown (CPoint &where, const long& buttons)
{
	if (buttons != kLButton || scrollerLength == 0) 
		return kMouseDownEventHandledButDontNeedMovedOrUpEvents;

	startPoint = where;
	scrollerRect = getScrollerRect ();
	scrolling = where.isInside (scrollerRect);
	if (scrolling)
	{
		scrollerRect = getScrollerRect ();
		return kMouseEventHandled;
	}
	else if (where.isInside (scrollerArea))
	{
		doStepping ();
		timer = new CVSTGUITimer (this, 250);
		timer->start ();
		return kMouseEventHandled;
	}
	return kMouseDownEventHandledButDontNeedMovedOrUpEvents;
}

//-----------------------------------------------------------------------------
CMouseEventResult CScrollbar::onMouseUp (CPoint &where, const long& buttons)
{
	if (timer)
	{
		timer->forget ();
		timer = 0;
	}
	return kMouseEventHandled;
}

//-----------------------------------------------------------------------------
CMouseEventResult CScrollbar::onMouseMoved (CPoint &where, const long& buttons)
{
	if (buttons & kLButton)
	{
		if (scrolling)
		{
			float newValue = 0.f;
			CPoint newPoint (where);
			newPoint.x -= startPoint.x - scrollerRect.left;
			newPoint.y -= startPoint.y - scrollerRect.top;
			if (direction == kHorizontal)
			{
				newValue = (float)(newPoint.x - scrollerArea.left) / ((float)scrollerArea.width () - scrollerRect.width ());
			}
			else
			{
				newValue = (float)(newPoint.y - scrollerArea.top) / ((float)scrollerArea.height () - scrollerRect.height ());
			}
			if (newValue < 0.f) newValue = 0.f;
			if (newValue > 1.f) newValue = 1.f;
			if (newValue != value)
			{
				value = newValue;
				if (listener)
					listener->valueChanged (this);
				invalid ();
			}
		}
		else
		{
			CPoint old (startPoint);
			startPoint = where;
			CRect scollerRect = getScrollerRect ();
			if (where.isInside (size) && old.isInside (scollerRect) && !startPoint.isInside (scrollerRect))
				doStepping ();
		}
	}
	return kMouseEventHandled;
}

#if VSTGUI_ENABLE_DEPRECATED_METHODS
//-----------------------------------------------------------------------------
void CScrollbar::mouse (CDrawContext* pContext, CPoint& where, long buttons)
{
	if (buttons == -1) buttons = pContext->getMouseButtons ();
	if (buttons != kLButton || scrollerLength == 0) return;

	float newValue = 0.f;

	// scrolling
	CRect scrollerRect = getScrollerRect ();
	if (where.isInside (scrollerRect))
	{
		CPoint newPoint (where);
		while (pContext->waitDrag ())
		{
			getMouseLocation (pContext, newPoint);
			newPoint.x -= where.x - scrollerRect.left;
			newPoint.y -= where.y - scrollerRect.top;
			if (direction == kHorizontal)
			{
				newValue = (float)(newPoint.x - scrollerArea.left) / ((float)scrollerArea.width () - scrollerRect.width ());
			}
			else
			{
				newValue = (float)(newPoint.y - scrollerArea.top) / ((float)scrollerArea.height () - scrollerRect.height ());
			}
			if (newValue < 0.f) newValue = 0.f;
			if (newValue > 1.f) newValue = 1.f;
			if (newValue != value)
			{
				value = newValue;
				if (listener)
					listener->valueChanged (this);
			}
			doIdleStuff ();
		}
	}
	// stepping
	else if (where.isInside (scrollerArea))
	{
		long kWaitTime = 100;
		long nextUpdateTime = getFrame ()->getTicks ();
		do
		{
			long ticks = getFrame ()->getTicks ();
			if (nextUpdateTime - ticks < 0)
			{
				if (direction == kHorizontal)
				{
					if (where.x < scrollerRect.left)
						newValue = value - (float)scrollerLength / (float)scrollerArea.width ();
					else
						newValue = value + (float)scrollerLength / (float)scrollerArea.width ();
				}
				else
				{
					if (where.y < scrollerRect.top)
						newValue = value - (float)scrollerLength / (float)scrollerArea.height ();
					else
						newValue = value + (float)scrollerLength / (float)scrollerArea.height ();
				}
				if (newValue < 0.f) newValue = 0.f;
				if (newValue > 1.f) newValue = 1.f;
				if (newValue != value)
				{
					value = newValue;
					if (listener)
						listener->valueChanged (this);
				}
				scrollerRect = getScrollerRect ();
				if (where.isInside (scrollerRect))
					break;
				nextUpdateTime = ticks + kWaitTime;
			}
			doIdleStuff ();
		} while (pContext->getMouseButtons () == kLButton);
	}
}
#endif

//------------------------------------------------------------------------
bool CScrollbar::onWheel (const CPoint &where, const CMouseWheelAxis &axis, const float &_distance, const long &buttons)
{
	if (!bMouseEnabled)
		return false;

	float distance = _distance;
	if (direction == kHorizontal && axis == kMouseWheelAxisY)
		distance *= -1;

	if (buttons & kShift)
		value -= 0.1f * distance * wheelInc;
	else
		value -= distance * wheelInc;
	bounceValue ();

	if (isDirty () && listener)
	{
		listener->valueChanged (this);
		invalid ();
	}
	return true;
}

//-----------------------------------------------------------------------------
void CScrollbar::drawBackground (CDrawContext* pContext)
{
	CRect r (size);
	if (drawer)
		drawer->drawScrollbarBackground (pContext, r, direction, this);
	else
	{
		pContext->setLineWidth (1);
		pContext->setFillColor (backgroundColor);
		pContext->setFrameColor (frameColor);
		pContext->drawRect (r, kDrawFilledAndStroked);
	}
}

//-----------------------------------------------------------------------------
void CScrollbar::drawScroller (CDrawContext* pContext, const CRect& size)
{
	CRect r (size);
	if (drawer)
		drawer->drawScrollbarScroller (pContext, r, direction, this);
	else
	{
		pContext->setLineWidth (1);
		pContext->setFillColor (scrollerColor);
		pContext->setFrameColor (frameColor);
		pContext->drawRect (r, kDrawFilledAndStroked);
	}
}

//-----------------------------------------------------------------------------
void CScrollbar::draw (CDrawContext* pContext)
{
	drawBackground (pContext);
	if (scrollerLength > 0)
	{
		CRect scrollerRect = getScrollerRect ();
		drawScroller (pContext, scrollerRect);
	}
	setDirty (false);
}

