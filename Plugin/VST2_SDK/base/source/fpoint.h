//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fpoint.h
// Created by  : Steinberg, 1998
// Description : Representation of a Point
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

//----------------------------------------------------------------------------------
/** @file base/source/fpoint.h
	Representation of a Point. */
//----------------------------------------------------------------------------------

#ifndef __fpoint__
#define __fpoint__

#include "pluginterfaces/base/ftypes.h"
#include "pluginterfaces/base/geoconstants.h"

namespace Steinberg {

class Rect;

//------------------------------------------------------------------------
/** Point Representation.
@ingroup adt

@see Rect, UCoord */
//------------------------------------------------------------------------
class Point
{
public:
//------------------------------------------------------------------------
	Point (UCoord h = 0, UCoord v = 0); ///< Construct a Point from (h, v).

	/** @name Querying and Setting Values. */
	///@{
	UCoord getH() const; ///< Return the X value of this Point.
	UCoord getV() const; ///< Return the Y value of this Point.
	void setH(UCoord h); ///< Set the X value of this Point.
	void setV(UCoord v); ///< Set the Y value of this Point.
	void offset ( UCoord h, UCoord v = 0 ); ///< Offset this Point by (x, y).
	void offset (const Point& p); ///< Offset this Point by Point p.
	bool bound (const Rect& rect); ///< Set this to the intersection of this and rect.
	///@}

	/** @name Operations on Point. */
	///@{
	Point&  operator () (UCoord h, UCoord v); ///< Reinitialize to given coordinates.
	Point   operator+ (const Point& p) const; ///< Return  p + this Point as a Point.
	Point   operator- (const Point& p) const; ///< Return this Point minus p as a Point.
	Point   operator/ (int32 n) const; ///< Return this Point divided by n as a Point (scalar divide).
	Point   operator* (int32 n) const; ///< Return this Point times n as a Point (scalar multiply).
	Point&  operator+= (const Point& p); ///< Add p to this Point.
	Point&  operator-= (const Point& p); ///< Subtract p from this Point.
	Point&  operator*= (int32 n); ///< Scalar multiply n times this Point. 
	Point&  operator/= (int32 n); ///< Scalar divide this Point by n. 
	int32	 operator* (const Point& p) const; ///< Scalar multiply this point with p.
	bool     operator!= (const Point& p) const; ///< Not equal.
	Point&  operator= (const Point& p); ///< Assignment.
	Point operator- () const;
	///@}

	bool inside (const Rect& rect) const; ///< Checks if point is inside @c rect.
	double distance (const Point& other) const; ///< Distance from the other to this point.
	double angle (const Point& other) const; ///< Angle from other to this Point.
	double length () const; ///< Calculate length (absolute value) of vector.
	Point projection (const Point& other) const; ///< Orthogonal vector projection of "this" on "other".


	bool isLocated (Direction dir, const Point& from); 

	UCoord h;
	UCoord v;
//------------------------------------------------------------------------
};

typedef Point UPoint;

inline bool operator== (const Point& p1, const Point& p2) //Checks, if two points are equal
{
	return p1.v == p2.v && p1.h == p2.h;
}

inline bool operator< (const Point& p1, const Point& p2) //Checks, if two points are equal
{
	if (p1.h < p2.h) return true;
	return p1.h > p2.h ? false : p1.v < p2.v;
}

//------------------------------------------------------------------------------
// Construct a Point from (h, v).
//------------------------------------------------------------------------------
inline Point::Point (UCoord _h, UCoord _v)
{
	h = _h;
	v = _v;
}

// ---------------------------------------------------------------------------
// Return the X value of this Point.
//
inline UCoord Point::getH () const
{
	return h;
}

// ---------------------------------------------------------------------------
// Return the Y value of this Point.
//
inline UCoord Point::getV () const
{
	return v;
}

// ---------------------------------------------------------------------------
// Set the X value of this Point.
//
inline void Point::setH (UCoord _h)
{
	this->h = _h;
}

// ---------------------------------------------------------------------------
// Set the Y value of this Point.
//
inline void Point::setV (UCoord _v)
{
	this->v = _v;
}

// ---------------------------------------------------------------------------
// Offset this Point by (x, y)
//
inline void Point::offset ( UCoord _h, UCoord _v )
{
	this->v += _v;
	this->h += _h;
}

// ---------------------------------------------------------------------------
// Offset this Point by Point p
//
inline void Point::offset (const Point& p)
{
	this->offset (p.h, p.v);
}

// ---------------------------------------------------------------------------
// Set the values of this Location to (h,v).
//
inline Point& Point::operator () (UCoord _h, UCoord _v)
{
	this->h = _h;
	this->v = _v;
	return *this;
}

// ---------------------------------------------------------------------------
// Return  p + this Point as a Point.
//
inline Point Point::operator+ (const Point& p) const
{
	return Point (h + p.h, v + p.v);
}

// ---------------------------------------------------------------------------
// Return this Point minus p as a Point.
//
inline Point Point::operator- (const Point& p) const
{
	return Point (h - p.h, v - p.v);
}

// ---------------------------------------------------------------------------
// Return this Point divided by n as a Point (scalar divide).
//
inline Point Point::operator/ (int32 n) const
{
	return Point (h / n, v / n);
}

// ---------------------------------------------------------------------------
// Return this Point times n as a Point (scalar multiply).
//
inline Point Point::operator* (int32 n) const
{
	return Point (h * n, v * n);
}

// ---------------------------------------------------------------------------
// Add p to this Point.
//
inline Point& Point::operator+= (const Point& p)
{
	h += p.h;
	v += p.v;
	return *this;
}

// ---------------------------------------------------------------------------
// Subtract p from this Point.
//
inline Point& Point::operator-= (const Point& p)
{
	h -= p.h;
	v -= p.v;
	return *this;
}

// ---------------------------------------------------------------------------
// Scalar multiply n times this Point. 
//
inline Point& Point::operator*= (int32 n)
{
	h *= n;
	v *= n;
	return *this;
}

// ---------------------------------------------------------------------------
// Scalar multiply this point with p 
//
inline int32 Point::operator* (const Point& p) const
{
	return h * p.h + v * p.v;
}

// ---------------------------------------------------------------------------
// Scalar divide this Point by n. 
//
inline Point& Point::operator/= (int32 n)
{
	h /= n;
	v /= n;
	return *this;
}

// ---------------------------------------------------------------------------
inline Point Point::operator- () const
{
	return Point (-h, -v);
}



// ---------------------------------------------------------------------------
// Not equal 
//
inline bool Point::operator!= (const Point& p) const
{
	return v != p.v || h != p.h;
}

// ---------------------------------------------------------------------------
// Assign
//
inline Point& Point::operator= (const Point& p)
{
	h = p.h;
	v = p.v;
	return *this;
}

} // namespace Steinberg

#endif
