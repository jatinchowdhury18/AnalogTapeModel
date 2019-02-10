//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/frect.cpp
// Created by  : Steinberg, 1995
// Description : 
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
//-----------------------------------------------------------------------------

#include "base/source/frect.h"

#include "pluginterfaces/gui/iplugview.h" // ViewRect
#include "pluginterfaces/base/futils.h"


namespace Steinberg
{

//------------------------------------------------------------------------------
// Rect
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
Rect::Rect (const ViewRect& vr)
: left (vr.left), top (vr.top), right (vr.right), bottom (vr.bottom)
{}

//------------------------------------------------------------------------------
Rect& Rect::moveTo (const Point& where)
{
	UCoord vDiff = where.v - top;
	UCoord hDiff = where.h - left;

	top += vDiff;
	bottom += vDiff;
	left += hDiff;
	right += hDiff;
	return *this;
}

//------------------------------------------------------------------------------
bool Rect::pointInside (const Point& where) const 
{
	return where.h >= left && where.h < right && where.v >= top && where.v < bottom;
}

//------------------------------------------------------------------------------
Rect& Rect::inset (UCoord delta) 
{
	top += delta;
	left += delta;
	bottom -= delta;
	right -= delta;
	return *this;
}

//------------------------------------------------------------------------------
Rect& Rect::inset (UCoord deltaH, UCoord deltaV) 
{
	top += deltaV;
	left += deltaH;
	bottom -= deltaV;
	right -= deltaH;
	return *this;
}

//------------------------------------------------------------------------------
Rect& Rect::inset (UCoord deltaL, UCoord deltaT, UCoord deltaR, UCoord deltaB) 
{
	top += deltaT;
	left += deltaL;
	bottom -= deltaB;
	right -= deltaR;
	return *this;
}

//------------------------------------------------------------------------------
bool Rect::slideInside (const Rect& rect) 
{

	UCoord w	= getWidth();
	UCoord h	= getHeight();

	// basic rejection conditions
	if ( ( w > rect.getWidth() ) || ( h > rect.getHeight() ) )
		return false;

		
	if ( left < rect.left )
	{
		left	= rect.left;
		right	= left + w;
	}
	else if ( right > rect.right )
	{
		right	= rect.right;
		left	= right - w;
	}	


	if ( top < rect.top )
	{
		top		= rect.top;
		bottom	= top + h;
	}
	else if ( bottom > rect.bottom )
	{
		bottom	= rect.bottom;
		top		= bottom - h;
	}	

	return true;
}

//------------------------------------------------------------------------------
bool Rect::join (const Rect& rect)
{
	if (isEmpty ())
	{
		if (rect.isEmpty ())
			return false;
		*this = rect;
		return true;
	}
	else if (rect.isEmpty ())
		return false;

	return joinEvenIfEmpty (rect);
}

//------------------------------------------------------------------------
bool Rect::joinEvenIfEmpty (const Rect& rect)
{
	if (rect.top < top)
		top = rect.top;
	if (rect.left < left)
		left = rect.left;
	if (rect.right > right)
		right = rect.right;
	if (rect.bottom > bottom)
		bottom = rect.bottom;
	return ! (right <= left) && ! (bottom <= top); 
}

//------------------------------------------------------------------------------
Rect& Rect::center (const Rect& rect)
{
	centerH (rect);
	return centerV (rect);
}

//------------------------------------------------------------------------------
Rect& Rect::centerH (const Rect& rect)
{
	UCoord width = getWidth ();
	left = rect.left + ((rect.getWidth () - getWidth ()) / 2);
	right = left + width;
	return *this;
}

//------------------------------------------------------------------------------
Rect& Rect::centerV (const Rect& rect)
{
	UCoord height = getHeight ();
	top = rect.top + ((rect.getHeight () - getHeight ()) / 2);
	bottom = top + height;
	return *this;
}

//------------------------------------------------------------------------------
bool Rect::isEmpty () const 
{
	if (right <= left)
		return true;
	if (bottom <= top)
		return true;
	return false;
}

//------------------------------------------------------------------------------
bool Rect::rectInside (const Rect& rect) const
{
	return rect.left >= left && rect.top >= top && rect.right <= right && rect.bottom <= bottom;
}

//------------------------------------------------------------------------------
bool Rect::rectIntersect (const Rect& rect ) const
{
	UCoord x1, y1, x2, y2;

	x1 = left	> rect.left   ? left   : rect.left;
	x2 = right  < rect.right  ? right  : rect.right;
	y1 = top	> rect.top	  ? top    : rect.top;
	y2 = bottom < rect.bottom ? bottom : rect.bottom;

//	return (x1 < x2 && y1 < y2);            // Right-Bottom Excluded
	return (x1 <= x2 && y1 <= y2);  		// Included
}

//------------------------------------------------------------------------------
bool Rect::rectIntersect (const Rect& rect, Rect& result) const
{
	UCoord  x1, y1, x2, y2;

    result.left   = x1 = left	   > rect.left   ? left   : rect.left;
    result.right  = x2 = right  < rect.right  ? right  : rect.right;
    result.top    = y1 = top	   > rect.top	 ? top    : rect.top;
    result.bottom = y2 = bottom < rect.bottom ? bottom : rect.bottom;

	if ((x1 <= x2 && y1 <= y2) )		// Right-Bottom Included		// Right-Bottom Excluded == (x1 <  x2 && y1 < y2) 
		return true;	

	result ( 0, 0, 0, 0 );
	return false;
}

//------------------------------------------------------------------------------
bool Rect::overlapHorizontal (const Rect& rect) const
{
	return (Max (left, rect.left) <= Min (right, rect.right));
}

//------------------------------------------------------------------------------
bool Rect::overlapVertical (const Rect& rect) const
{
	return (Max (top, rect.top) <= Min (bottom, rect.bottom));
}

//------------------------------------------------------------------------------
UCoord Rect::getOverlapHorizontal (const Rect& r2) const
{
	return Max<UCoord> (0, Min (right, r2.right) - Max (left, r2.left));
}

//------------------------------------------------------------------------------
UCoord Rect::getOverlapVertical (const Rect& r2) const
{
	return Max<UCoord> (0, Min (bottom, r2.bottom) - Max (top, r2.top));
}

//------------------------------------------------------------------------------
bool Rect::subtract (const Rect& rect)
{
	if (rect.rectInside (*this))
	{
		set (0,0,0,0);
		return false;
	}

	Rect r (*this);
	r.bound (rect);

	if (!r.isEmpty ()) 
	{
		if (r.getWidth () >= getWidth ()) 
		{
			if (r.top > top)
				bottom = r.top;
			else if (r.bottom < bottom)
				top = r.bottom;
		}
		if (r.getHeight () >= getHeight ()) 
		{
			if (r.left > left)
				right = r.left;
			else if (r.right < right)
				left = r.right;
		}
	}
	return isEmpty () == false;
}

//------------------------------------------------------------------------------
Point& Rect::constrain (Point& p) const
{
	if (p.h < left)
		p.h = left;
	if (p.h > right)
		p.h = right;
	if (p.v < top)
		p.v = top;
	if (p.v > bottom)
		p.v = bottom;
	return p;
}
	
//------------------------------------------------------------------------------
bool Rect::lineInside (const Point& p1, const Point& p2) const
{
	return pointInside (p1) && pointInside (p2);
}

//------------------------------------------------------------------------------
bool Rect::lineIntersect (const Point& _p1, const Point& _p2) const
{
	Point p1 (_p1);
	Point p2 (_p2);
	return boundLine (p1,p2);
}


//------------------------------------------------------------------------
// clipping of line
//------------------------------------------------------------------------

// Liang-Barsky algorithm
//------------------------------------------------------------------------------
static inline bool boundLineClipTest (double p, double q, double *u1, double *u2)
{
	double r;
	bool retval = true;

	if (p < 0.0)
	{
		r = q / p;
		if (r > *u2)
			retval = false;
		else if (r > *u1)
			*u1 = r;
	}
	else if (p > 0.0)
	{
		r = q / p;
		if (r < * u1)
			retval = false;
		else if (r < *u2)
			*u2 = r;
	}
	else if (q < 0.0)
	{
		retval = false;
	}
	return retval;
}

//------------------------------------------------------------------------------
bool Rect::boundLine (Point& p1, Point& p2) const           
{
	if (pointInside (p1) && pointInside (p2))
		return true;

	double u1 = 0.0;
	double u2 = 1.0;
	double dx = p2.h - p1.h;
	double dy;

	if (boundLineClipTest (-dx, p1.h - left, &u1, &u2))
	{
		if (boundLineClipTest (dx, right - p1.h, &u1, &u2))
		{
			dy = p2.v - p1.v;
			if (boundLineClipTest (-dy, p1.v - top, &u1, &u2))
			{
				if (boundLineClipTest (dy, bottom - p1.v, &u1, &u2))
				{
					if (u2 < 1.0)
					{
						p2.h = p1.h + (UCoord)(u2 * dx);
						p2.v = p1.v + (UCoord)(u2 * dy);
					}
					if (u1 > 0.0)
					{
						p1.h += (UCoord)(u1 * dx);
						p1.v += (UCoord)(u1 * dy);
					}
					return true;
				}
			}
		}
	}
	return false;
}

//------------------------------------------------------------------------------
ViewRect& Rect::toViewRect (ViewRect& vr) const
{
	vr.left = left;   
	vr.top = top;
	vr.right = right; 
	vr.bottom = bottom;
	return vr;
}

//------------------------------------------------------------------------------
void Rect::fromViewRect (const ViewRect& vr)
{
	left = vr.left;  
	top = vr.top;
	right = vr.right; 
	bottom = vr.bottom;
}

//------------------------------------------------------------------------------
Rect& Rect::operator = (const ViewRect& vr)
{
	fromViewRect (vr);
	return *this;
}

//------------------------------------------------------------------------------
Rect::operator ViewRect () const
{
	return ViewRect (left, top, right, bottom);
}

//------------------------------------------------------------------------
Point& Rect::toPoint (Direction dir, Point& p) const
{
	switch (dir) {
	case kSouthWest:		return p = getBottomLeft ();
	case kWest:				return p = getLeftCenter ();
	case kNorthWest:		return p = getTopLeft ();
	case kNorth:			return p = getTopCenter ();
	case kNorthEast:		return p = getTopRight ();
	case kEast:				return p = getRightCenter ();
	case kSouthEast:		return p = getBottomRight ();
	case kSouth:			return p = getBottomCenter ();
	case kNoDirection:		return p = getCenter ();
	}

	return p;
}

} // namespace Steinberg
