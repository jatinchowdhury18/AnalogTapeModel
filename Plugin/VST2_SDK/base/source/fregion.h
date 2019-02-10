//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 2.05
// 
// Category    : Helpers
// Filename    : base/source/fregion.h
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
//----------------------------------------------------------------------------------

//----------------------------------------------------------------------------------
/** @file base/source/fregion.h
	Region Class. */
//----------------------------------------------------------------------------------

#ifndef __fregion__
#define __fregion__

#include "base/source/frect.h"
#include "base/source/tarray.h"


namespace Steinberg {

typedef TArray<Rect> RectangleArray;

//------------------------------------------------------------------------
/** Region Class.
	@see Rect, Point, UCoord */
//------------------------------------------------------------------------
class Region
{
public:
	Region ();
    Region (const Rect& r);
    Region (const Region& r);
    
	Region& operator= (const Region& src) {return copyFrom (src);}
	Region& copyFrom (const Region& r);
  
	bool isEmpty () const {return countRects () == 0;}
	int32 countRects () const {return rectangles.total ();}
	
    void clear ();
    
	void fromRect (const Rect& r);
    void fromRects (const TContainer<Rect>& rects);
    bool getRects(TContainer<Rect>& rects, bool left2right = true,
                   bool topdown = true, int32 maxArea = 0) const;
	
	const Rect& getBoundingRect () const {return extents;}

    bool equals (const Region& r) const;
	bool operator== (const Region& r) const {return equals (r);}
	bool operator!= (const Region& r) const {return equals (r) == false;}

	bool pointInside (const Point& p) const;
	bool rectInside (const Rect& r) const;	

	Region& offset (const Point& off);
	
    Region& assignIntersection (const Region& r);
    Region& assignUnion (const Region& r);
    Region& assignSubtraction (const Region& r);

    Region getIntersection(const Region& r) const;
    Region getUnion (const Region& r) const;
    Region getSubtraction(const Region& r) const;

private:
	void updateExtents ();
	friend struct RegionHelper;

	RectangleArray rectangles;
	Rect extents;
};

} // namespace Steinberg

#endif
