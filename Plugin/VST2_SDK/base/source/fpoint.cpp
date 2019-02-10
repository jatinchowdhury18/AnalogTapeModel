//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fpoint.cpp
// Created by  : Steinberg, 1998
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

#include "base/source/fpoint.h"
#include "base/source/frect.h"
#include <math.h>

namespace Steinberg {

// ---------------------------------------------------------------------------
bool Point::bound (const Rect& rect)
{
	if (h < rect.left)
		h = rect.left;
	if (h > rect.right)
		h = rect.right;
	if (v < rect.top)
		v = rect.top;
	if (v > rect.bottom)
		v = rect.bottom;
	return true;
}

// ---------------------------------------------------------------------------
// Check if inside a rectangle
//
bool Point::inside (const Rect& rect) const
{
	return rect.pointInside (*this);
}
	
// ---------------------------------------------------------------------------
double Point::distance (const Point& other) const
{
	return sqrt ((double) (h - other.h) * (h - other.h) + (v - other.v) * (v - other.v));
}

// ---------------------------------------------------------------------------
double Point::angle (const Point& other) const
{
	return atan ((double) (other.v - v) / (other.h - h));
}

// ---------------------------------------------------------------------------
Point Point::projection (const Point& other) const
{
	double div = double (other * other);
	double skalar = double (*this * other) / (div ? div : 1.);
	return Point (UCoord (double (other.h) * skalar), UCoord (double (other.v) * skalar));
}

// ---------------------------------------------------------------------------
double Point::length () const
{
	return sqrt ((double) h * h + v * v);
}

//------------------------------------------------------------------------
bool Point::isLocated (Direction dir, const Point& from)
{
	switch (dir)
	{
		case kNorth:		return v < from.v;
		case kSouth:		return v > from.v;
		case kWest:			return h < from.h;
		case kEast:			return h > from.h;
		case kNorthEast:	return v < from.v && h > from.h;
		case kNorthWest:	return v < from.v && h < from.h;
		case kSouthEast:	return v > from.v && h > from.h;
		case kSouthWest:	return v > from.v && h < from.h;
		case kNoDirection:	return v == from.v && h == from.h;
	}
	return false;
}
} // namespace Steinberg
