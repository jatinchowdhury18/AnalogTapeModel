//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/frect.h
// Created by  : Steinberg, 11/2008
// Description : Rectangle Class
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-----------------------------------------------------------------------------
// This Software Development Kit may not be distributed in parts or its entirety  
// without prior written agreement by Steinberg Media Technologies GmbH. 
// This SDK must not be used to re-engineer or manipulate any technology used  
// in any Steinberg or Third-party application or software module, 
// unless permitted by law.
// Neither the name of the Steinberg Media Technologies nor the names of its
// contributors may be used to endorse or promote products derived from this 
// software without specific prior written permission.
// 
// THIS SDK IS PROVIDED BY STEINBERG MEDIA TECHNOLOGIES GMBH "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL STEINBERG MEDIA TECHNOLOGIES GMBH BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
/** @file base/source/frect.h
	Rectangle Class. */
//----------------------------------------------------------------------------------

#ifndef __frect__
#define __frect__

#include "base/source/fpoint.h"
#include "pluginterfaces/base/geoconstants.h"


namespace Steinberg
{

struct ViewRect;




//------------------------------------------------------------------------
/** Rectangle Class.
@ingroup adt
@see Point, UCoord */
//------------------------------------------------------------------------
class Rect
{
public:
//------------------------------------------------------------------------
	Rect ();																///< create empty rectangle with coordinates set to zero
	Rect (UCoord left, UCoord top, UCoord right, UCoord bottom);			///< create rectangle with four individual coordinates
	Rect (UCoord w, UCoord h);												///< create rectangle with zero left/top coordinates and right/bottom coordinates according to the given width and height 
	Rect (const Point& topLeft, const Point& bottomRight);					///< create rectangle defined by a top/left Point and a bottom/right Point
	Rect (const Point& topLeft, UCoord width, UCoord height);				///< create rectangle defined by a top/left Point and the given width and height
	Rect (const ViewRect& vr);												///< create rectangle defined by a ViewRect
	
	UCoord getWidth () const;				///< return width of rectangle (right coordinate - left coordinate)
	UCoord getHeight () const;				///< return height of rectangle (bottom coordinate - top coordinate)
	Rect& setWidth (const UCoord w);		///< set width by setting the right coordinate with respect to the left
	Rect& setHeight (const UCoord h);		///< set height by setting the bottom coordinate with respect to the top
	void setEmpty ();						///< resets coordinates to all zero - now isEmpty returns true
	
	Point  getTopLeft () const;						///< get top/left as Point
	Point& getTopLeft (Point&) const;				///< get top/left as Point 
	Point  getBottomRight () const;					///< get bottom/right as Point
	Point& getBottomRight (Point&) const;			///< get bottom/right as Point 
	Point  getTopRight () const;					///< get top/right as Point
	Point& getTopRight (Point&) const;				///< get top/right as Point 
	Point  getBottomLeft () const;					///< get bottom/left as Point
	Point& getBottomLeft (Point&) const;			///< get bottom/left as Point 

	
	Point& toPoint (Direction dir, Point& p) const;								///< convert rectangle to a point
	Point  toPoint (Direction dir) const { Point p (0,0); return toPoint (dir, p); }	///< convert rectangle to a point

	Rect& setTopLeft (const UCoord left, const UCoord top);							///< set top/left from coordinates
	Rect& setBottomRight (const UCoord right, const UCoord bottom);					///< set bottom/right from coordinates
	Rect& setSize (const UCoord w, const UCoord h);									///< set size by setting bottom/right with respect to left/top
	
	Rect& operator () (UCoord left, UCoord top, UCoord right, UCoord bottom);		///< set left/top/right/bottom from four individual coordinates 
	Rect& operator () (const Point& topLeft, const Point& bottomRight);				///< set left/top/right/bottom from top/left Point and bottom/right Point
	void set (UCoord left, UCoord top, UCoord right, UCoord bottom);				///< return height of rectangle (bottom coordinate - top coordinate) 
	
	Rect& moveTo (const Point& where);												///< move rectangle to a new top/left point while maintaining width and height
	Rect& offset (UCoord x, UCoord y = 0);											///< offset rectangle by x/y coordinates maintaining width and height 
	Rect& offset (const Point& where);												///< offset rectangle by a x/y Point maintaining width and height 
	Rect& inset (UCoord delta);														///< inset top/left and bottom/right by equal amounts to change rectangle size
	Rect& inset (UCoord deltaH, UCoord deltaV);										///< inset left/right by an equal amount similarly, inset top/bottom by an equal amount, to change rectangle size
	Rect& inset (UCoord deltaL, UCoord deltaT, UCoord deltaR, UCoord deltaB);		///< inset left/top/right/bottom each by a separate amount to change the rectangle size

	Rect& originize ();								///< move rectangle so the left/top coordinate are zero while maintaining the width and height
	Rect& normalize ();								///< flips left/right and top/bottom values if value pairs are such that right<left or bottom<top coordinates

	Rect& center (const Rect& rect);           		///< centers this with respect to rect
	Rect& centerH (const Rect& rect);          		///< centers this with respect to rect
	Rect& centerV (const Rect& rect);          		///< centers this with respect to rect
	
	bool bound (const Rect& rect);             		///< set this to the intersection of this and rect; returns false if intersection is empty
	bool slideInside (const Rect& rect);       		///< fit this inside the larger rect. if not possible return false.
	bool join (const Rect& rect);              		///< set this to the union of this and rect
	bool joinEvenIfEmpty (const Rect& rect);		///< set this to the union of this and rect and do not skip if both rect areas are 'empty'
	bool subtract (const Rect& rect);				///< trim this by the rect given			      
	bool isEmpty () const;
	
	bool rectInside (const Rect& rect) const;					///< checks if rect is enclosed by this
	bool rectIntersect (const Rect& rect) const;				///< checks if rect touches this
	bool rectIntersect (const Rect& rect, Rect& result ) const; ///< checks if rect touches this: if true intersection is in result

	Point getCenter () const;                                   ///< get point in the middle of the rect (might not be precise for even sized rects)
	Point getLeftCenter	() const;
	Point getRightCenter () const;
	Point getTopCenter () const;
	Point getBottomCenter () const;

	bool overlapHorizontal (const Rect& rect) const;			///< checks if the horizontal coord ranges overlap
	bool overlapVertical   (const Rect& rect) const;			///< checks if the vertical coord ranges overlap
	UCoord getOverlapHorizontal (const Rect& rect) const;       ///< get horizontal overlapping area, returns 0 if not overlapping
	UCoord getOverlapVertical (const Rect& rect) const;         ///< get vertical overlapping area, returns 0 if not overlapping

	bool pointInside (const Point& where) const;				///< checks if point is inside this rect
	Point& constrain (Point& p) const;							///< constrains the point such that is lies within this rect
	
	bool lineInside (const Point& p1, const Point& p2) const;    ///< is line inside rect ?
	bool lineIntersect (const Point& p1, const Point& p2) const; ///< is line intersecting rect?
	bool boundLine (Point& p1, Point& p2) const;				 ///< bound line to rect, returns false if line does not intersect rect

	Rect& operator+= (const Point& p);							///< performs a 'offset' operation on this
	Rect& operator+= (const Rect& rect);						///< performs a 'join' operation on this
	
	ViewRect& toViewRect (ViewRect& vr) const;					///< sets the ViewRect coordinates to the current coordinates of this
	void fromViewRect (const ViewRect& vr);						///< sets the current coordinates of this to the ViewRect coordinates
	Rect& operator = (const ViewRect& vr);						///< performs a 'fromViewRect' operation
	operator ViewRect () const;									///< conversion operator to ViewRect

	UCoord left;
	UCoord top;
	UCoord right;
	UCoord bottom;
//------------------------------------------------------------------------
};

typedef Rect URect;

//------------------------------------------------------------------------------
inline bool operator== (const Rect& r1, const Rect& r2)
{
	return r1.left == r2.left && r1.top == r2.top && r1.right == r2.right && r1.bottom == r2.bottom;
}

//------------------------------------------------------------------------------
inline bool operator!= (const Rect& r1, const Rect& r2) 
{
	return !(r1 == r2);
}

//------------------------------------------------------------------------------
inline bool operator< (const Rect& r1, const Rect& r2)
{
	if (r1.left < r2.left) return true;
	if (r1.left > r2.left) return false;
	if (r1.top < r2.top) return true;
	if (r1.top > r2.top) return false;
	if (r1.right < r2.right) return true;
	if (r1.right > r2.right) return false;
	return r1.bottom < r2.bottom;
}

//------------------------------------------------------------------------
/** Create empty rectangle with coordinates set to zero */
//------------------------------------------------------------------------
inline Rect::Rect () 
: left (0), top (0), right (0), bottom (0)
{}

//------------------------------------------------------------------------
/** Create rectangle with four individual coordinates */
//------------------------------------------------------------------------
inline Rect::Rect (UCoord left, UCoord top, UCoord right, UCoord bottom) 
: left (left), top (top), right (right), bottom (bottom)
{}

//------------------------------------------------------------------------
/** Create rectangle with zero left/top coordinates and right/bottom coordinates according to the given width and height */
//------------------------------------------------------------------------
inline Rect::Rect (UCoord w, UCoord h) 
: left (0), top (0), right (w), bottom (h)
{}

//------------------------------------------------------------------------
/** Create rectangle defined by a top/left Point and a bottom/right Point */
//------------------------------------------------------------------------
inline Rect::Rect (const Point& topLeft, const Point& bottomRight)
: left   (topLeft.h)
, top    (topLeft.v)
, right  (bottomRight.h)
, bottom (bottomRight.v)
{}

//------------------------------------------------------------------------
/** Create rectangle defined by a top/left Point and the given width and height */
//------------------------------------------------------------------------
inline Rect::Rect (const Point& topLeft, UCoord width, UCoord height)
: left   (topLeft.h)
, top    (topLeft.v)
, right  (topLeft.h + width)
, bottom (topLeft.v + height)
{}

//------------------------------------------------------------------------
/** Return width of rectangle (right coordinate - left coordinate) */
//------------------------------------------------------------------------
inline UCoord Rect::getWidth () const
{ 
	return right - left; 
}

//------------------------------------------------------------------------
/** Return height of rectangle (bottom coordinate - top coordinate) */
//------------------------------------------------------------------------
inline UCoord Rect::getHeight () const 
{ 
	return bottom - top; 
}

//------------------------------------------------------------------------
/** Return height of rectangle (bottom coordinate - top coordinate) */
//------------------------------------------------------------------------
inline void Rect::set (UCoord _left, UCoord _top, UCoord _right, UCoord _bottom)
{
	this->left = _left;
	this->top = _top;
	this->right = _right;
	this->bottom = _bottom;	
}

//------------------------------------------------------------------------
/** Set left/top/right/bottom from four individual coordinates */
//------------------------------------------------------------------------
inline Rect& Rect::operator () (UCoord _left, UCoord _top, UCoord _right, UCoord _bottom)
{
	this->left = _left;
	this->top = _top;
	this->right = _right;
	this->bottom = _bottom;	
	return *this;
}

//------------------------------------------------------------------------
/** Set left/top/right/bottom from top/left Point and bottom/right Point */
//------------------------------------------------------------------------
inline Rect& Rect::operator () (const Point& topLeft, const Point& bottomRight)
{
	left = topLeft.h;
	top = topLeft.v;
	right = bottomRight.h;
	bottom = bottomRight.v;
	return *this;
}

//------------------------------------------------------------------------
/** Get top/left as Point */
//------------------------------------------------------------------------
inline Point& Rect::getTopLeft (Point& p) const
{
	return p (left, top);
}

//------------------------------------------------------------------------
/** Get top/left as Point */
//------------------------------------------------------------------------
inline Point Rect::getTopLeft () const
{
	return Point (left, top);
}

//------------------------------------------------------------------------
/** Get top/right as Point */
//------------------------------------------------------------------------
inline Point& Rect::getTopRight (Point& p) const
{
	return p (right, top);
}

//------------------------------------------------------------------------
/** Get top/right as Point */
//------------------------------------------------------------------------
inline Point Rect::getTopRight () const
{
	return Point (right, top);
}

//------------------------------------------------------------------------
/** Get bottom/left as Point */
//------------------------------------------------------------------------
inline Point& Rect::getBottomLeft (Point& p) const
{
	return p (left, bottom);
}

//------------------------------------------------------------------------
/** Get bottom/left as Point */
//------------------------------------------------------------------------
inline Point Rect::getBottomLeft () const
{
	return Point (left, bottom);
}

//------------------------------------------------------------------------
/** Get bottom/right as Point */
//------------------------------------------------------------------------
inline Point& Rect::getBottomRight (Point& p) const
{
	return p (right, bottom);
}

//------------------------------------------------------------------------
/** Get bottom/right as Point */
//------------------------------------------------------------------------
inline Point Rect::getBottomRight () const
{
	return Point (right, bottom);
}

//------------------------------------------------------------------------
/** Performs a 'offset' operation on this */
//------------------------------------------------------------------------
inline Rect& Rect::operator+= (const Point& p)
{
	offset (p);
	return *this;
}

//------------------------------------------------------------------------
/** Performs a 'join' operation on this */
//------------------------------------------------------------------------
inline Rect& Rect::operator+= (const Rect& r)
{
	join (r);
	return *this;
}

//------------------------------------------------------------------------
/** Set width by setting the right coordinate with respect to the left */
//------------------------------------------------------------------------
inline Rect& Rect::setWidth (const UCoord w)
{
	right = left + w;	
	return *this;
}

//------------------------------------------------------------------------
/** Set height by setting the bottom coordinate with respect to the top */
//------------------------------------------------------------------------
inline Rect& Rect::setHeight (const UCoord h)
{
	bottom = top + h;	
	return *this;
}

//------------------------------------------------------------------------
/** Resets coordinates to all zero - now isEmpty returns true */
//------------------------------------------------------------------------
inline void Rect::setEmpty ()
{
	set (0, 0, 0, 0);
}

//------------------------------------------------------------------------
/** Set top/left from coordinates */
//------------------------------------------------------------------------
inline Rect& Rect::setTopLeft (const UCoord _left, const UCoord _top)
{
	this->left = _left;
	this->top  = _top;
	return *this;
}

//------------------------------------------------------------------------
/** Set bottom/right from coordinates */
//------------------------------------------------------------------------
inline Rect& Rect::setBottomRight (const UCoord _right, const UCoord _bottom)
{
	this->right  = _right;
	this->bottom = _bottom;
	return *this;
}

//------------------------------------------------------------------------
/** Set size by setting bottom/right with respect to left/top */
//------------------------------------------------------------------------
inline Rect& Rect::setSize (const UCoord w, const UCoord h)
{
	right = left + w;
	bottom = top + h;
	return *this;
}

//------------------------------------------------------------------------
/** move rectangle so the left/top coordinate are zero while maintaining the width and height */
//------------------------------------------------------------------------
inline Rect& Rect::originize ()
{
	right  -= left;
	bottom -= top;
	left   = 0;
	top    = 0;
	return *this;
}

//------------------------------------------------------------------------
/** flips left/right and top/bottom values if value pairs are such that right<left or bottom<top coordinates */
//------------------------------------------------------------------------
inline Rect& Rect::normalize ()
{
	UCoord help;
	if (left > right)
	{
		help = left;
		left = right;
		right = help;
	}
	if (top > bottom)
	{
		help = top;
		top = bottom;
		bottom = help;
	}
	return *this;
}

//------------------------------------------------------------------------------
/** Set this to the intersection of this and rect; returns false if intersection is empty */
//------------------------------------------------------------------------------
inline bool Rect::bound (const Rect& rect) 
{
	if (left < rect.left)
		left = rect.left;
	if (top < rect.top)
		top = rect.top;
	if (right > rect.right)
		right = rect.right;
	if (bottom > rect.bottom)
		bottom = rect.bottom;
	if (bottom < top)
		bottom = top;
	if (right < left)
		right = left;
	return ! (right <= left) && ! (bottom <= top); 
}

//------------------------------------------------------------------------------
/** offset rectangle by x/y coordinates maintaining width and height */
//------------------------------------------------------------------------------
inline Rect& Rect::offset (UCoord x, UCoord y) 
{
	left += x;
	right += x;
	top += y;
	bottom += y;
	return *this;
}

//------------------------------------------------------------------------------
/** offset rectangle by a x/y Point maintaining width and height */
//------------------------------------------------------------------------------
inline Rect& Rect::offset (const Point& p) 
{
	left += p.h;
	right += p.h;
	top += p.v;
	bottom += p.v;
	return *this;
}

//------------------------------------------------------------------------------
inline Point Rect::getCenter () const
{
	return Point (left + (getWidth () / 2), top + (getHeight () / 2));
}

//------------------------------------------------------------------------------
inline Point Rect::getLeftCenter () const
{
	return Point (left,					top + (getHeight ()/2));
}

//------------------------------------------------------------------------------
inline Point Rect::getRightCenter () const	
{
	return Point (right,					top + (getHeight ()/2));
}

//------------------------------------------------------------------------------
inline Point Rect::getTopCenter () const
{
	return Point (left + (getWidth ()/2),	top);
}

//------------------------------------------------------------------------------
inline Point Rect::getBottomCenter () const
{
	return Point (left + (getWidth ()/2),	bottom);
}

} // namespace Steinberg

#endif
