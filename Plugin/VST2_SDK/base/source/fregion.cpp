//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 2.05
// 
// Category    : Helpers
// Filename    : base/source/fregion.cpp
// Created by  : Steinberg, 10/2009
// Description : Region Class
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


#include "base/source/fregion.h"
#include "pluginterfaces/base/futils.h"

namespace Steinberg {

//------------------------------------------------------------------------------
// Helpers
//------------------------------------------------------------------------------
typedef void (*OverlapFunc) (register Region &dest, register const Rect *r1, const Rect *r1End,
                            register const Rect *r2, const Rect *r2End, register UCoord y1, register UCoord y2);
typedef void (*NonOverlapFunc) (register Region &dest, register const Rect *r, const Rect *rEnd,
                               register UCoord y1, register UCoord y2);

struct RegionHelper {
// 'translation' of XRegion implementation
static void miRegionOperation (register Region& dest, const Region& reg1, const Region& reg2,
                       OverlapFunc overlapFunc, NonOverlapFunc nonOverlap1Func,
                       NonOverlapFunc nonOverlap2Func);

static int32 miCoalesce (register Region &dest, int32 prevStart, int32 curStart);

static void miUnionNonO (register Region &dest, register const Rect *r, const Rect *rEnd,
                        register UCoord y1, register UCoord y2);

static void miUnionO (register Region &dest, register const Rect *r1, const Rect *r1End,
                     register const Rect *r2, const Rect *r2End, register UCoord y1, register UCoord y2);

static void miIntersectO (register Region& dest, register const Rect* r1, const Rect* r1End,
						 register const Rect* r2, const Rect* r2End, UCoord y1, UCoord y2);

static void miSubtractNonO1 (register Region &dest, register const Rect *r,
							const Rect *rEnd, register UCoord y1, register UCoord y2);

static void miSubtractO (register Region &dest, register const Rect *r1, const Rect *r1End,
                        register const Rect *r2, const Rect *r2End, register UCoord y1, register UCoord y2);

};


//------------------------------------------------------------------------------
// Region
//------------------------------------------------------------------------------
Region::Region ()
{
}

//------------------------------------------------------------------------------
Region::Region(const Rect& r)
{
	fromRect (r);
}

//------------------------------------------------------------------------------
Region::Region(const Region& r)
{
	copyFrom (r);
}

//------------------------------------------------------------------------------
Region& Region::copyFrom (const Region& r)
{
	if (&r != this)
	{
		rectangles = r.rectangles;
		extents = r.extents;
	}
	return *this;
}

//------------------------------------------------------------------------------
void Region::clear ()
{
	rectangles.removeAll ();
	extents (0,0,0,0);
}

//------------------------------------------------------------------------------
void Region::fromRect (const Rect& r)
{
	if (r.isEmpty()) 
	{
		clear ();
	}
	else
	{
		rectangles.removeAll ();
		rectangles.add (r);
		extents = r;
	}
}

//------------------------------------------------------------------------------
void Region::fromRects (const TContainer<Rect>& rects)
{
	rectangles.removeAll ();
	rectangles.addAllFrom (rects);        ///< Adds all the items from the specified container to this container
	updateExtents ();
}

//------------------------------------------------------------------------------
bool Region::getRects (TContainer<Rect>& rects, bool left2right,  bool topdown , int32 maxArea) const
{
	int32 nRects = countRects ();
	int32 xInc = left2right ? 1 : -1;
	int32 yInc = topdown ? 1 : -1;
	int32 i = topdown ? 0 : nRects-1;
	rects.removeAll ();
 
	while (nRects > 0) 
	{
		int32 firstInNextBand = i;
		int32 nRectsInBand = 0;

		while (nRects > 0 && rectangles[firstInNextBand].top == rectangles[i].top)
		{
			firstInNextBand += yInc;
			nRects--;
			nRectsInBand++;
		}

		if (xInc != yInc)
			i = firstInNextBand - yInc;

		while (nRectsInBand > 0) 
		{
			UCoord y = rectangles[i].top;
			UCoord rectWidth = rectangles[i].getWidth ();
			UCoord h = rectWidth != 0 ? (maxArea / rectWidth) : 0;
			if (!h) 
			{
				h = rectangles[i].bottom - y;
			}
				
			do 
			{
				if (h > rectangles[i].bottom - y)
					h = rectangles[i].bottom - y;
				Rect r(rectangles[i].left, y, rectangles[i].right, y+h);
				rects.add (r);
				y += h;
			} 
			while (y < rectangles[i].bottom);
			
			i += xInc;
			nRectsInBand--;
		}

		i = firstInNextBand;
	}

	return !rects.isEmpty ();
}

//------------------------------------------------------------------------------
bool Region::equals (const Region& r) const
{
	if (countRects () != r.countRects ()) 
		return false;
    else if (countRects () == 0 ) 
		return true;
    else if (extents != r.extents) 
		return false;
    else 
	{
		for (int32 i = 0; i < countRects (); i++)
		{
			if (rectangles[i] != r.rectangles [i])
				return false;
		}
    }
	return true;
}

//------------------------------------------------------------------------------
bool Region::pointInside (const Point& p) const
{
    if (countRects () == 0)
        return false;

	if (extents.pointInside (p) == false)
        return false;

	for (int32 i = 0; i < countRects (); i++)
	{
		if (rectangles[i].pointInside (p))
			return true;
	}
    return false;
}

//------------------------------------------------------------------------------
bool Region::rectInside (const Rect& r) const
{
    if (countRects () == 0)
        return false;
	
	if (extents.rectInside (r) == false)
        return false;

	Rect toCompare;
	Rect tmp;
	for (int32 i = 0; i < countRects (); i++)
	{
		if (rectangles[i].rectIntersect (r, tmp))
		{
			if (toCompare.isEmpty ())
				toCompare = tmp;
			else
				toCompare.join (tmp);
			if (toCompare == r)
				return true;
		}
	}
	return false;
}

//------------------------------------------------------------------------------
Region& Region::offset (const Point& p)
{
    if (countRects () > 0)
	{
		for (int32 i = 0; i < countRects (); i++)
			rectangles[i].offset (p);
		extents.offset (p);		
	}
	
	return *this;
}


//------------------------------------------------------------------------------
Region& Region::assignIntersection (const Region& r)
{
	return (*this) = getIntersection (r);
}

//------------------------------------------------------------------------------
Region& Region::assignUnion (const Region& r)
{
	return (*this) = getUnion (r);
}

//------------------------------------------------------------------------------
Region& Region::assignSubtraction (const Region& r)
{
	return (*this) = getSubtraction (r);
}

//------------------------------------------------------------------------------
Region Region::getIntersection(const Region& r) const
{
	Region result;
    
	if (isEmpty () || r.isEmpty () || extents.rectIntersect (r.extents) == false)
		return result;

	RegionHelper::miRegionOperation (result, *this, r, RegionHelper::miIntersectO, 0, 0);

	result.updateExtents ();

	return result;
}

//------------------------------------------------------------------------------
Region Region::getUnion (const Region& r) const
{
	Region result;

	if (equals (r) || isEmpty () || (r.countRects () == 1 && r.extents.rectInside (extents)))
		result = r;
	else if (r.isEmpty () || (countRects () == 1 && extents.rectInside (r.extents)))
		result = *this;
	else 
	{
		RegionHelper::miRegionOperation (result, *this, r, RegionHelper::miUnionO, RegionHelper::miUnionNonO, RegionHelper::miUnionNonO);

		result.extents = extents;
		result.extents.join (r.extents);
	}

	return result;
}

//------------------------------------------------------------------------------
Region Region::getSubtraction(const Region& r) const
{
	Region result;
	
	if (isEmpty () || r.isEmpty () || extents.rectIntersect (r.extents) == false)
	{
		result = *this;
	}
	else
	{
		RegionHelper::miRegionOperation (result, *this, r, RegionHelper::miSubtractO, RegionHelper::miSubtractNonO1, 0);
		result.updateExtents ();
	}
	return result;
}

//------------------------------------------------------------------------------
void Region::updateExtents ()
{
	if (countRects () == 0)
		extents (0,0,0,0);
	else
	{
		for (int32 i = 0; i < countRects (); i++)
		{
			if (i == 0)
				extents = rectangles[i];
			else
				extents.join (rectangles[i]);
		}
	}
}


//------------------------------------------------------------------------------
// Helpers
//------------------------------------------------------------------------------

/*-
 *-----------------------------------------------------------------------
 * miRegionOp --
 *      Apply an operation to two regions. Called by miUnion, miInverse,
 *      miSubtract, miIntersect...
 *
 * Results:
 *      None.
 *
 * Side Effects:
 *      The new region is overwritten.
 *
 * Notes:
 *      The idea behind this function is to view the two regions as sets.
 *      Together they cover a rectangle of area that this function divides
 *      into horizontal bands where points are covered only by one region
 *      or by both. For the first case, the nonOverlapFunc is called with
 *      each the band and the band's upper and lower extents. For the
 *      second, the overlapFunc is called to process the entire band. It
 *      is responsible for clipping the rectangles in the band, though
 *      this function provides the boundaries.
 *      At the end of each band, the new region is coalesced, if possible,
 *      to reduce the number of rectangles in the region.
 *
 *-----------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
void RegionHelper::miRegionOperation (register Region& dest,
                       const Region& reg1, const Region& reg2,
                       OverlapFunc overlapFunc, NonOverlapFunc nonOverlap1Func,
                       NonOverlapFunc nonOverlap2Func)
{
	const Rect* r1BandEnd;  // End of current band in r1
    const Rect* r2BandEnd;  // End of current band in r2

	UCoord ybot;          // Bottom of intersection
    UCoord ytop;          // Top of intersection
	UCoord top;                    // Top of non-overlapping band
    UCoord bot;                    // Bottom of non-overlapping band

	const Rect* r1 = &reg1.rectangles.at (0);         // Pointer into first region
    const Rect* r2 = &reg2.rectangles.at (0);         // Pointer into 2d region
    const Rect* r1End = r1 + reg1.countRects ();               // End of 1st region
    const Rect* r2End = r2 + reg2.countRects ();               // End of 2d region
	
	if (reg1.extents.top < reg2.extents.top)
        ybot = reg1.extents.top - 1;
    else
        ybot = reg2.extents.top - 1;

	int32 prevBand = 0;
	int32 curBand = 0;

	dest.rectangles.resize (Max(reg1.countRects (),reg2.countRects ()) * 2);

    do 
	{
		curBand = dest.countRects ();

        r1BandEnd = r1;
        while (r1BandEnd != r1End && r1BandEnd->top == r1->top)
            ++r1BandEnd;

        r2BandEnd = r2;
        while (r2BandEnd != r2End && r2BandEnd->top == r2->top)
            ++r2BandEnd;

        if (r1->top < r2->top) 
		{
            top = Max(r1->top, ybot + 1);
            bot = Min(r1->bottom, r2->top - 1);

            if (nonOverlap1Func != 0 && bot != top)
                (*nonOverlap1Func)(dest, r1, r1BandEnd, top, bot);
            ytop = r2->top;
        } 
		else if (r2->top < r1->top) 
		{
            top = Max(r2->top, ybot + 1);
            bot = Min(r2->bottom, r1->top - 1);

            if (nonOverlap2Func != 0 && bot != top)
                (*nonOverlap2Func)(dest, r2, r2BandEnd, top, bot);
            ytop = r1->top;
        } 
		else 
		{
            ytop = r1->top;
        }

        if (dest.countRects () != curBand)
            prevBand = miCoalesce (dest, prevBand, curBand);

        ybot = Min (r1->bottom, r2->bottom);
		curBand = dest.countRects ();
        if (ybot > ytop)
            (*overlapFunc)(dest, r1, r1BandEnd, r2, r2BandEnd, ytop, ybot);

        if (dest.countRects () != curBand)
            prevBand = miCoalesce (dest, prevBand, curBand);

        if (r1->bottom == ybot)
            r1 = r1BandEnd;

        if (r2->bottom == ybot)
            r2 = r2BandEnd;

    } while (r1 != r1End && r2 != r2End);

    curBand = dest.countRects ();
    if (r1 != r1End) 
	{
        if (nonOverlap1Func != 0) 
		{
            do 
			{
                r1BandEnd = r1;
                while (r1BandEnd < r1End && r1BandEnd->top == r1->top)
                    ++r1BandEnd;
                (*nonOverlap1Func)(dest, r1, r1BandEnd, Max (r1->top, ybot + 1), r1->bottom);
                r1 = r1BandEnd;
            } while (r1 != r1End);
        }
    } 
	else if ((r2 != r2End) && (nonOverlap2Func != 0)) 
	{
        do 
		{
            r2BandEnd = r2;
            while (r2BandEnd < r2End && r2BandEnd->top == r2->top)
                 ++r2BandEnd;
            (*nonOverlap2Func)(dest, r2, r2BandEnd, Max(r2->top, ybot + 1), r2->bottom);
            r2 = r2BandEnd;
        } while (r2 != r2End);
    }

    if (dest.countRects () != curBand)
        miCoalesce (dest, prevBand, curBand);

    if (Max<int32>(4, dest.countRects ()) < (dest.rectangles.size() >> 1))
        dest.rectangles.resize (dest.countRects ());
}


//------------------------------------------------------------------------------
int32 RegionHelper::miCoalesce(register Region &dest, int32 prevStart, int32 curStart)
{
	Rect* pPrevBox;   /* Current box in previous band */
    Rect* pCurBox;    /* Current box in current band */
    Rect* pRegEnd;    /* End of region */
    int32 curNumRects;    /* Number of rectangles in current band */
    int32 prevNumRects;   /* Number of rectangles in previous band */
    int32 bandY1;         /* Y1 coordinate for current band */
    
	Rect* rData = &dest.rectangles.at (0);

    pRegEnd = rData + dest.countRects ();

    pPrevBox = rData + prevStart;
    prevNumRects = curStart - prevStart;

    pCurBox = rData + curStart;
    bandY1 = pCurBox->top;
    for (curNumRects = 0; pCurBox != pRegEnd && pCurBox->top == bandY1; ++curNumRects) 
	{
        ++pCurBox;
    }

    if (pCurBox != pRegEnd) 
	{
        --pRegEnd;
        while ((pRegEnd - 1)->top == pRegEnd->top)
            --pRegEnd;
        curStart = static_cast<int32> (pRegEnd - rData);
		pRegEnd = rData + dest.countRects ();
    }

    if (curNumRects == prevNumRects && curNumRects != 0) 
	{
        pCurBox -= curNumRects;
  
		if (pPrevBox->bottom == pCurBox->top) 
		{
            do 
			{
                if (pPrevBox->left != pCurBox->left || pPrevBox->right != pCurBox->right) 
				{
                     // The bands don't line up so they can't be coalesced.
                    return curStart;
                }
                ++pPrevBox;
                ++pCurBox;
                --prevNumRects;
            } while (prevNumRects != 0);

			for (int32 remCount = 0; remCount < curNumRects; remCount++)
				dest.rectangles.removeAt (dest.rectangles.total () - 1);
            pCurBox -= curNumRects;
            pPrevBox -= curNumRects;

            do 
			{
                pPrevBox->bottom = pCurBox->bottom;                
                ++pPrevBox;
                ++pCurBox;
                curNumRects -= 1;
            } while (curNumRects != 0);

            if (pCurBox == pRegEnd) 
			{
                curStart = prevStart;
            } 
			else 
			{
                do 
				{
                    *pPrevBox++ = *pCurBox++;
                } while (pCurBox != pRegEnd);
            }
        }
    }

    return curStart;
}


//------------------------------------------------------------------------------
void RegionHelper::miUnionNonO (register Region &dest, register const Rect *r, const Rect *rEnd,
                        register int32 y1, register int32 y2)
{
    ASSERT (y1 <= y2)

    while (r != rEnd) 
	{
		ASSERT(r->left <= r->right)
        
		Rect next (r->left, y1, r->right, y2);
		dest.rectangles.add (next);
		
        ++r;
    }
}

//------------------------------------------------------------------------------
inline void MergeRect (register TArray<Rect>& destRects, const Rect*& r, register int32 y1, register int32 y2)
{
    int32 lastIndex = destRects.total () - 1;
	if ((destRects.total () != 0) &&  
        (destRects.at (lastIndex).top == y1) &&  
        (destRects.at (lastIndex).bottom == y2) &&  
        (destRects.at (lastIndex).right >= r->left)) 
	{ 
        Rect& destRect = destRects.at (lastIndex);
		if (destRect.right < r->right) 
		{ 
            destRect.right = r->right;  
            ASSERT(destRect.left <= destRect.right); 
        }  
    } 
	else 
	{
		Rect newRect (r->left, y1, r->right, y2);
		destRects.add (newRect);
    }  
    r++;
}

//------------------------------------------------------------------------------
void RegionHelper::miUnionO (register Region &dest, register const Rect* r1, const Rect* r1End,
                     register const Rect *r2, const Rect *r2End, register int32 y1, register int32 y2)
{
    ASSERT(y1 <= y2);
    while (r1 != r1End && r2 != r2End) 
	{
        if (r1->left < r2->left) 
		{
			MergeRect (dest.rectangles, r1, y1, y2);
        } 
		else 
		{
            MergeRect (dest.rectangles, r2, y1, y2);
        }
    }

    if (r1 != r1End) 
	{
        do 
		{
            MergeRect (dest.rectangles, r1, y1, y2);
        } 
		while (r1 != r1End);
    } 
	else 
	{
        while (r2 != r2End) 
		{
            MergeRect (dest.rectangles, r2, y1, y2);
        }
    }
}


//------------------------------------------------------------------------------
void RegionHelper::miIntersectO(register Region& dest, register const Rect* r1, const Rect* r1End,
                         register const Rect* r2, const Rect* r2End, int32 y1, int32 y2)
{
	UCoord x1;
    UCoord x2;

    while (r1 != r1End && r2 != r2End) 
	{
        x1 = Max (r1->left, r2->left);
        x2 = Min (r1->right, r2->right);

		if (x1 <= x2) 
		{
            ASSERT(y1 <= y2)
			Rect newRect (x1, y1, x2, y2);
			dest.rectangles.add (newRect);
        }

        if (r1->right < r2->right) 
		{
            ++r1;
        } 
		else if (r2->right < r1->right) 
		{
            ++r2;
        } 
		else 
		{
            ++r1;
            ++r2;
        }
    }
}

//------------------------------------------------------------------------------
void RegionHelper::miSubtractNonO1(register Region &dest, register const Rect *r, const Rect *rEnd, register UCoord y1, register UCoord y2)
{
    ASSERT(y1<=y2)

    while (r != rEnd) 
	{
        ASSERT(r->left <= r->right)
     
		Rect newRect (r->left, y1, r->right, y2);
		dest.rectangles.add (newRect);
        ++r;
    }
}
//------------------------------------------------------------------------------
void RegionHelper::miSubtractO(register Region &dest, register const Rect *r1, const Rect *r1End,
                        register const Rect *r2, const Rect *r2End, register UCoord y1, register UCoord y2)
{
    UCoord x1 = r1->left;

    ASSERT(y1 <= y2)

    while (r1 != r1End && r2 != r2End) 
	{
        if (r2->right <= x1) 
		{
            ++r2;
        } 
		else if (r2->left <= x1) 
		{
            x1 = r2->right;
            if (x1 >= r1->right) 
			{
                ++r1;
                if (r1 != r1End)
                    x1 = r1->left;
            } 
			else 
			{
                ++r2;
            }
        } 
		else if (r2->left < r1->right) 
		{
            ASSERT(x1 < r2->left)
			Rect newRect (x1, y1, r2->left, y2);
			dest.rectangles.add (newRect);

            x1 = r2->right;
            if (x1 >= r1->right) 
			{
                ++r1;
                if (r1 != r1End)
                    x1 = r1->left;
            } 
			else 
			{
                ++r2;
            }
        } 
		else 
		{
            if (r1->right > x1) 
			{
				Rect newRect (x1, y1, r1->right, y2);
				dest.rectangles.add (newRect);
            }
            ++r1;
            if (r1 != r1End)
                x1 = r1->left;
        }
    }

    while (r1 != r1End) 
	{
        ASSERT(x1 <= r1->right)
		Rect newRect (x1, y1, r1->right, y2);
		dest.rectangles.add (newRect);

        ++r1;
        if (r1 != r1End)
            x1 = r1->left;
    }
}


} // namespace Steinberg
