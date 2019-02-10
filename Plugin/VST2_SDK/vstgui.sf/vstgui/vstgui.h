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

#ifndef __vstgui__
#define __vstgui__

// define global defines
#if WIN32
	#define WINDOWS 1
#elif (__MWERKS__ || __APPLE_CC__)
	#include <AvailabilityMacros.h>
	#ifndef MAC_OS_X_VERSION_10_5
		#define MAC_OS_X_VERSION_10_5 1050
	#endif
	#ifndef MAC_COCOA
		#define MAC_COCOA (MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_5)
	#endif
	#ifndef MAC
		#define MAC 1
	#endif
	#define VSTGUI_USES_COREGRAPHICS 1
	#if !__LP64__
		#define MAC_CARBON 1
		#ifndef TARGET_API_MAC_CARBON
			#define TARGET_API_MAC_CARBON 1
		#endif
		#ifndef __CF_USE_FRAMEWORK_INCLUDES__
			#define __CF_USE_FRAMEWORK_INCLUDES__ 1
		#endif
	#else
		#ifndef NO_QUICKDRAW
			#define NO_QUICKDRAW	1
		#endif
	#endif
#endif

#if WINDOWS
 #define _WIN32_WINNT 0x0501
 #ifndef GDIPLUS
 #define GDIPLUS		1	// by default we use GDIPlus
 #endif
#endif

#ifndef USE_NAMESPACE
#define USE_NAMESPACE 1
#endif

#if USE_NAMESPACE
 #define BEGIN_NAMESPACE_VSTGUI  namespace VSTGUI {
 #define END_NAMESPACE_VSTGUI    }
 #define USING_NAMESPACE_VSTGUI using namespace VSTGUI;
#else
 #define BEGIN_NAMESPACE_VSTGUI
 #define END_NAMESPACE_VSTGUI
 #define USING_NAMESPACE_VSTGUI
#endif

#ifndef VSTGUI_USES_UTF8
#define VSTGUI_USES_UTF8 1
#endif
 
// VSTGUI Version
#define VSTGUI_VERSION_MAJOR  3
#define VSTGUI_VERSION_MINOR  6

//----------------------------------------------------
// Deprecation setting
//----------------------------------------------------
#ifndef VSTGUI_ENABLE_DEPRECATED_METHODS
#define VSTGUI_ENABLE_DEPRECATED_METHODS 0
#endif

#ifndef DEPRECATED_ATTRIBUTE
#define DEPRECATED_ATTRIBUTE
#endif

#if VSTGUI_ENABLE_DEPRECATED_METHODS
#define VSTGUI_DEPRECATED(x)	DEPRECATED_ATTRIBUTE	x
#else
#define VSTGUI_DEPRECATED(x)
#endif

//----------------------------------------------------
//----------------------------------------------------
BEGIN_NAMESPACE_VSTGUI

class CFrame;
class CDrawContext;
class COffscreenContext;
class CControl;
class CBitmap;

//----------------------------------------------------
class VSTGUIEditorInterface
{
public:
	virtual void doIdleStuff () {}
	virtual long getKnobMode () const { return 0; }
	
	virtual void beginEdit (long index) {}
	virtual void endEdit (long index) {}

protected:
	VSTGUIEditorInterface () : frame (0) {}
	virtual ~VSTGUIEditorInterface () {}

	CFrame* frame;
};
END_NAMESPACE_VSTGUI

//----------------------------------------------------
#if WINDOWS
	#if VSTGUI_USES_UTF8
		#undef UNICODE
		#define UNICODE 1
		#define VSTGUI_STRCMP	wcscmp
		#define VSTGUI_STRCPY	wcscpy
		#define VSTGUI_SPRINTF	wsprintf
		#define VSTGUI_STRRCHR	wcschr
		#define VSTGUI_STRICMP	_wcsicmp
		#define VSTGUI_STRLEN	wcslen
		#define VSTGUI_STRCAT	wcscat
	#else
		#define VSTGUI_STRCMP	strcmp
		#define VSTGUI_STRCPY	strcpy
		#define VSTGUI_SPRINTF	sprintf
		#define VSTGUI_STRRCHR	strrchr
		#define VSTGUI_STRICMP	_stricmp
		#define VSTGUI_STRLEN	strlen
		#define VSTGUI_STRCAT	strcat
	#endif
	#include <windows.h>

	#if GDIPLUS
	#include <objidl.h>
	#include <gdiplus.h>
	#endif
#endif // WINDOWS

//----------------------------------------------------
#if MAC_CARBON
	#include <Carbon/Carbon.h>
#endif // MAC_CARBON

#if MAC_COCOA
	#include <CoreFoundation/CoreFoundation.h>
	#include <ApplicationServices/ApplicationServices.h>
#endif

#if MAC
	BEGIN_NAMESPACE_VSTGUI
	extern CFBundleRef getBundleRef ();
	#ifndef VSTGUI_NEW_BUNDLE_REF_DEFINITION	// You can define this in your preprocessor definitions and supply the above function somewhere in your code if you don't want to use the following gBundleRef variable.
		extern void* gBundleRef;	///< must be set to the current CFBundleRef somewhere early in the code
	#endif
	END_NAMESPACE_VSTGUI
#endif
//----------------------------------------------------
struct VstKeyCode;

#include "vstguidebug.h"

BEGIN_NAMESPACE_VSTGUI

struct CPoint;

#if DEBUG
#define CLASS_METHODS(name, parent)             \
	virtual bool isTypeOf (const char* s) const \
		{ return (!strcmp (s, (#name))) ? true : parent::isTypeOf (s); }\
	virtual const char* getClassName () const { return (#name); } \
	virtual CView* newCopy () const { return new name (*this); }
#else
#define CLASS_METHODS(name, parent)             \
	virtual bool isTypeOf (const char* s) const \
		{ return (!strcmp (s, (#name))) ? true : parent::isTypeOf (s); } \
	virtual CView* newCopy () const { return (CView*)new name (*this); }
#endif
#define CLASS_METHODS_VIRTUAL(name, parent)             \
	virtual bool isTypeOf (const char* s) const \
		{ return (!strcmp (s, (#name))) ? true : parent::isTypeOf (s); } \
	virtual CView* newCopy () const = 0;

#ifdef VSTGUI_FLOAT_COORDINATES
typedef double CCoord;
#else
typedef long CCoord;
#endif

//-----------------------------------------------------------------------------
//! \brief Rect structure
//-----------------------------------------------------------------------------
struct CRect
{
	CRect (CCoord left = 0, CCoord top = 0, CCoord right = 0, CCoord bottom = 0)
	: left (left), top (top), right (right), bottom (bottom) {}

	CRect (const CRect& r)
	: left (r.left), top (r.top), right (r.right), bottom (r.bottom) {}

	CRect (const CPoint& origin, const CPoint& size) { setTopLeft (origin); setSize (size); }

	CRect& operator () (CCoord left, CCoord top, CCoord right, CCoord bottom)
	{
		if (left < right)
			this->left = left, this->right = right;
		else
			this->left = right, this->right = left;
		if (top < bottom)
			this->top = top, this->bottom = bottom;
		else
			this->top = bottom, this->bottom = top;
		return *this;
	}

	bool operator != (const CRect& other) const
		{ return (left != other.left || right != other.right ||
					top != other.top || bottom != other.bottom); }

	bool operator == (const CRect& other) const
		{ return (left == other.left && right == other.right &&
					top == other.top && bottom == other.bottom); }
	
	inline CCoord width () const  { return getWidth (); }
	inline CCoord height () const { return getHeight (); }

	inline CCoord getWidth () const  { return right - left; }
	inline CCoord getHeight () const { return bottom - top; }

	inline void setWidth (CCoord width) { right = left + width; }
	inline void setHeight (CCoord height) { bottom = top + height; }

	CPoint getTopLeft () const;
	CPoint getTopRight () const;
	CPoint getBottomLeft () const;
	CPoint getBottomRight () const;
	void setTopLeft (const CPoint& inPoint);
	void setTopRight (const CPoint& inPoint);
	void setBottomLeft (const CPoint& inPoint);
	void setBottomRight (const CPoint& inPoint);

	CPoint getSize () const;
	void setSize (const CPoint& size);

	CRect& offset (CCoord x, CCoord y)
		{ left += x; right += x; top += y; bottom += y; return *this; }

	CRect& inset (CCoord deltaX, CCoord deltaY)
		{ left += deltaX; right -= deltaX; top += deltaY; bottom -= deltaY;
    	return *this; }

	CRect& moveTo (CCoord x, CCoord y)
		{ CCoord vDiff = y - top; CCoord hDiff = x - left; 
		top += vDiff; bottom += vDiff; left += hDiff; right += hDiff;
		return *this; }

	bool pointInside (const CPoint& where) const;	///< Checks if point is inside this rect

	bool isEmpty () const;

	bool rectOverlap (const CRect& rect) const
	{
		if (right < rect.left) return false;
		if (left > rect.right) return false;
		if (bottom < rect.top) return false;
		if (top > rect.bottom) return false;
		return true;
	}

	void bound (const CRect& rect);
	void unite (const CRect& rect);

	void normalize ()
	{
		if (left > right)
		{
			CCoord tmp = left;
			left = right;
			right = tmp;
		}
		if (top > bottom)
		{
			CCoord tmp = top;
			top = bottom;
			bottom = tmp;
		}
	}

	union
	{ CCoord left; CCoord x;};

	union
	{ CCoord top; CCoord y;};

	union
	{ CCoord right; CCoord x2;};

	union
	{ CCoord bottom; CCoord y2;};
};

//-----------------------------------------------------------------------------
//! \brief Point structure
//-----------------------------------------------------------------------------
struct CPoint
{
	CPoint (CCoord h = 0, CCoord v = 0) : h (h), v (v) {}
	CPoint& operator () (CCoord h, CCoord v)
	{ this->h = h; this->v = v; return *this; }

	bool isInside (const CRect& r) const
	{ return h >= r.left && h <= r.right && v >= r.top && v <= r.bottom; } 

	bool operator != (const CPoint &other) const
	{ return (h != other.h || v != other.v); }

	bool operator == (const CPoint &other) const
	{ return (h == other.h && v == other.v); }

	CPoint &offset (const CCoord h, const CCoord v)
	{ this->h += h; this->v += v; return *this; }

	union
	{ CCoord h; CCoord x;};

	union
	{ CCoord v; CCoord y;};
};

//-----------------------------------------------------------------------------
//! \brief Color structure
//-----------------------------------------------------------------------------
struct CColor
{
	CColor& operator () (unsigned char red,
						unsigned char green,
						unsigned char blue,
						unsigned char alpha)
	{
		this->red   = red;
		this->green = green;
		this->blue  = blue;
		this->alpha = alpha;
		return *this; 
	}

	CColor& operator = (const CColor& newColor)
	{
		red   = newColor.red;
		green = newColor.green;
		blue  = newColor.blue;
		alpha = newColor.alpha;
		return *this; 
	}
	
	CColor operator ~ ()
	{
		CColor c;
		c.red   = ~red;
		c.green = ~green;
		c.blue  = ~blue;
		c.alpha = ~alpha;
		return c;
	}

	bool operator != (const CColor &other) const 
	{ return (red != other.red || green != other.green || blue  != other.blue || alpha != other.alpha); }

	bool operator == (const CColor &other) const
	{ return (red == other.red && green == other.green && blue  == other.blue && alpha == other.alpha); }
	
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

inline CColor MakeCColor (unsigned char red = 0, unsigned char green = 0, unsigned char blue = 0, unsigned char alpha = 255)
{
	CColor c;
	c.red = red;
	c.green = green;
	c.blue = blue;
	c.alpha = alpha;
	return c;
}

// define some basic colors
extern const CColor kTransparentCColor;
extern const CColor kBlackCColor;
extern const CColor kWhiteCColor;
extern const CColor kGreyCColor;
extern const CColor kRedCColor;
extern const CColor kGreenCColor;
extern const CColor kBlueCColor;
extern const CColor kYellowCColor;
extern const CColor kCyanCColor;
extern const CColor kMagentaCColor;

//-----------------------------------------------------------------------------
// Definitions of special characters in a platform independent way

#if VSTGUI_USES_UTF8
extern const char* kDegreeSymbol;			///< degree sign
extern const char* kInfiniteSymbol;			///< infinity
extern const char* kCopyrightSymbol;		///< copyright sign
extern const char* kTrademarkSymbol;		///< trade mark sign
extern const char* kRegisteredSymbol;		///< registered sign
extern const char* kMicroSymbol;			///< micro sign
extern const char* kPerthousandSymbol;		///< per mille sign
#else

#if WINDOWS
#define kDegreeSymbol      "\xB0"
#define kInfiniteSymbol    "oo"
#define kCopyrightSymbol   "\xA9"
#define kTrademarkSymbol   "\x99"
#define kRegisteredSymbol  "\xAE"
#define kMicroSymbol       "\x85"
#define kPerthousandSymbol "\x89"
#endif // WINDOWS

#if MAC
#define kDegreeSymbol      "\xA1"
#define kInfiniteSymbol    "oo"
#define kCopyrightSymbol   "\xA9"
#define kTrademarkSymbol   "\xAA"
#define kRegisteredSymbol  "\xA8"
#define kMicroSymbol       "\xB5"
#define kPerthousandSymbol "\xE4"
#endif // MAC

#endif // VSTGUI_USES_UTF8

class CDragContainer;
class CCView;
class CAttributeListEntry;
class IMouseObserver;

//-----------------------------------------------------------------------------
typedef unsigned int CViewAttributeID;
//-----------------------------------------------------------------------------
// Attributes
//		all attributes where the first letter is lowercase are reserved for the vstgui lib

extern const CViewAttributeID kCViewAttributeReferencePointer;	// 'cvrp'
extern const CViewAttributeID kCViewTooltipAttribute;			// 'cvtt'

//-----------------------------------------------------------------------------
//-----------
// \brief Text Face
//-----------
enum CTxtFace
{
	kNormalFace    = 0,
	kBoldFace      = 1,
	kItalicFace    = 2,
	kUnderlineFace = 4
};

//-----------
// \brief Line Style
//-----------
enum CLineStyle
{
	kLineSolid = 0,
	kLineOnOffDash
};

//-----------
// \brief Draw Mode
//-----------
enum CDrawMode
{
	kCopyMode = 0,					///< non antialiased drawing
	kOrMode,						///< not implementated on Mac OS X and GDI+ \deprecated
	kXorMode,						///< not implementated on Mac OS X and GDI+ \deprecated
	kAntialias						///< antialised drawing
};

//----------------------------
// \brief Text Alignment (Horizontal)
//----------------------------
enum CHoriTxtAlign
{
	kLeftText = 0,
	kCenterText,
	kRightText
};

//----------------------------
// \brief Buttons Type (+modifiers)
//----------------------------
enum CButton
{
	kLButton		= 1 << 1,		///< left mouse button
	kMButton		= 1 << 2,		///< middle mouse button
	kRButton		= 1 << 3,		///< right mouse button
	kShift			= 1 << 4,		///< shift modifier
	kControl		= 1 << 5,		///< control modifier
	kAlt			= 1 << 6,		///< alt modifier
	kApple			= 1 << 7,		///< apple modifier
	kButton4		= 1 << 8,		///< 4th mouse button
	kButton5		= 1 << 9,		///< 5th mouse button
	kDoubleClick	= 1 << 10		///< mouse button is double click
};

//----------------------------
// \brief Cursor Type
//----------------------------
enum CCursorType
{
	kCursorDefault = 0,				///< arrow cursor
	kCursorWait,					///< wait cursor
	kCursorHSize,					///< horizontal size cursor
	kCursorVSize,					///< vertical size cursor
	kCursorSizeAll,					///< size all cursor
	kCursorNESWSize,				///< northeast and southwest size cursor
	kCursorNWSESize,				///< northwest and southeast size cursor
	kCursorCopy,					///< copy cursor (mainly for drag&drop operations)
	kCursorNotAllowed,				///< not allowed cursor (mainly for drag&drop operations)
	kCursorHand						///< hand cursor
};

//----------------------------
// \brief Knob Mode
//----------------------------
enum CKnobMode
{
	kCircularMode = 0,
	kRelativCircularMode,
	kLinearMode
};

//----------------------------
// \brief Draw Style
//----------------------------
enum CDrawStyle
{
	kDrawStroked = 0,
	kDrawFilled,
	kDrawFilledAndStroked
};

//----------------------------
// \brief Mouse Wheel Axis
//----------------------------
enum CMouseWheelAxis
{
	kMouseWheelAxisX = 0,
	kMouseWheelAxisY
};

//----------------------------
// \brief Mouse Event Results
//----------------------------
enum CMouseEventResult
{
	kMouseEventNotImplemented = 0,
	kMouseEventHandled,
	kMouseEventNotHandled,
	kMouseDownEventHandledButDontNeedMovedOrUpEvents
};

//----------------------------
// \brief Message Results
//----------------------------
enum CMessageResult 
{
	kMessageUnknown = 0,
	kMessageNotified = 1
};

//----------------------------
// \brief View Autosizing
//----------------------------
enum CViewAutosizing
{
	kAutosizeNone			= 0,
	kAutosizeLeft			= 1 << 0,
	kAutosizeTop			= 1 << 1,
	kAutosizeRight			= 1 << 2,
	kAutosizeBottom			= 1 << 3,
	kAutosizeColumn			= 1 << 4,	///< view containers treat their children as columns
	kAutosizeRow			= 1 << 5,	///< view containers treat their children as rows
	kAutosizeAll			= kAutosizeLeft | kAutosizeTop | kAutosizeRight | kAutosizeBottom,
};

//-----------------------------------------------------------------------------
// CBaseObject Declaration
//! \brief Base Object with reference counter
/// \nosubgrouping
//-----------------------------------------------------------------------------
class CBaseObject
{
public:
	CBaseObject () : nbReference (1) {}
	virtual ~CBaseObject () {}

	//-----------------------------------------------------------------------------
	/// \name Reference Counting Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual void forget () { nbReference--; if (nbReference == 0) delete this; }	///< decrease refcount and delete object if refcount == 0
	virtual void remember () { nbReference++; }										///< increase refcount
	long getNbReference () const { return nbReference; }							///< get refcount
	//@}
	
	//-----------------------------------------------------------------------------
	/// \name Message Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual CMessageResult notify (CBaseObject* sender, const char* message) { return kMessageUnknown; }
	//@}

private:
	long nbReference;
};

//-----------------------------------------------------------------------------
// CFontDesc Declaration
//! \brief font class
/// \nosubgrouping
//-----------------------------------------------------------------------------
class CFontDesc : public CBaseObject
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructors
	//-----------------------------------------------------------------------------
	//@{
	CFontDesc (const char* name = 0, const CCoord& size = 0, const long style = 0);
	CFontDesc (const CFontDesc& font);
	//@}
	~CFontDesc ();

	//-----------------------------------------------------------------------------
	/// \name CFontDesc Methods
	//-----------------------------------------------------------------------------
	//@{
	const char* getName () const { return name; }		///< get the name of the font
	const CCoord& getSize () const { return size; }		///< get the height of the font
	const long& getStyle () const { return style; }		///< get the style of the font

	void setName (const char* newName);					///< set the name of the font
	void setSize (CCoord newSize);						///< set the height of the font
	void setStyle (long newStyle);						///< set the style of the font \sa CTxtFace
	//@}

	CFontDesc& operator = (const CFontDesc&);
	bool operator == (const CFontDesc&) const;

	void* getPlatformFont ();							///< get platform font object
	
	static void cleanup ();								///< does some cleanup, needed for GDIPLUS
protected:
	void freePlatformFont ();
	char* name;
	CCoord size;
	long style;
	void* platformFont;
};

typedef CFontDesc*	CFontRef;

extern const CFontRef kSystemFont;
extern const CFontRef kNormalFontVeryBig;
extern const CFontRef kNormalFontBig;
extern const CFontRef kNormalFont;
extern const CFontRef kNormalFontSmall;
extern const CFontRef kNormalFontSmaller;
extern const CFontRef kNormalFontVerySmall;
extern const CFontRef kSymbolFont;

//-----------------------------------------------------------------------------
// CDrawContext Declaration
//! \brief A drawing context encapsulates the drawing context of the underlying OS
/// \nosubgrouping
//-----------------------------------------------------------------------------
class CDrawContext : public CBaseObject
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructor
	//-----------------------------------------------------------------------------
	//@{
	CDrawContext (CFrame *pFrame, void *pSystemContext, void *pWindow = 0);
	//@}
	~CDrawContext ();	

	//-----------------------------------------------------------------------------
	/// \name Draw primitives
	//-----------------------------------------------------------------------------
	//@{
	void moveTo (const CPoint &point);	///< move line position to point
	void lineTo (const CPoint &point);	///< draw a line from current position to point
	void drawLines (const CPoint* points, const long& numberOfLines);	///< draw multiple lines at once
	void drawPolygon (const CPoint *pPoints, long numberOfPoints, const CDrawStyle drawStyle = kDrawStroked, bool closePolygon = true); ///< draw a polygon
	void drawRect (const CRect &rect, const CDrawStyle drawStyle = kDrawStroked);	///< draw a rect
	void drawArc (const CRect &rect, const float startAngle1, const float endAngle2, const CDrawStyle drawStyle = kDrawStroked);	///< draw an arc, angles are in degree
	void drawEllipse (const CRect &rect, const CDrawStyle drawStyle = kDrawStroked);	///< draw an ellipse
	void drawPoint (const CPoint &point, CColor color);	///< draw a point
	//@}

	//-----------------------------------------------------------------------------
	/// \name Line Mode
	//-----------------------------------------------------------------------------
	//@{
	void       setLineStyle (CLineStyle style);				///< set the current line style
	CLineStyle getLineStyle () const { return lineStyle; }	///< get the current line style

	void   setLineWidth (CCoord width);						///< set the current line width
	CCoord getLineWidth () const { return frameWidth; }		///< get the current line width
	//@}

	//-----------------------------------------------------------------------------
	/// \name Draw Mode
	//-----------------------------------------------------------------------------
	//@{
	void      setDrawMode (CDrawMode mode);					///< set the current draw mode, see CDrawMode
	CDrawMode getDrawMode () const { return drawMode; }		///< get the current draw mode, see CDrawMode
	//@}

	//-----------------------------------------------------------------------------
	/// \name Clipping
	//-----------------------------------------------------------------------------
	//@{
	void   setClipRect (const CRect &clip);																			///< set the current clip
	CRect &getClipRect (CRect &clip) const { clip = clipRect; clip.offset (-offset.h, -offset.v); return clip; }	///< get the current clip
	void   resetClipRect ();																						///< reset the clip to the default state
	//@}

	//-----------------------------------------------------------------------------
	/// \name Color
	//-----------------------------------------------------------------------------
	//@{
	void   setFillColor  (const CColor color);				///< set current fill color
	CColor getFillColor () const { return fillColor; }		///< get current fill color
	void   setFrameColor (const CColor color);				///< set current stroke color
	CColor getFrameColor () const { return frameColor; }	///< get current stroke color
	//@}

	//-----------------------------------------------------------------------------
	/// \name Font
	//-----------------------------------------------------------------------------
	//@{
	void   setFontColor (const CColor color);											///< set current font color
	CColor getFontColor () const { return fontColor; }									///< get current font color
	void   setFont (const CFontRef font, const long& size = 0, const long& style = -1);	///< set current font
	const CFontRef&  getFont () const { return font; }										///< get current font
	long   getFontSize () const { return (long)font->getSize (); }							///< get current font size
	//@}
	
	//-----------------------------------------------------------------------------
	/// \name Text
	//-----------------------------------------------------------------------------
	//@{
	CCoord getStringWidth (const char* pStr);																						///< get the width of an ASCII encoded string
	void drawString (const char *pString, const CRect &rect, const short opaque = false, const CHoriTxtAlign hAlign = kCenterText);	///< draw an ASCII encoded string
	CCoord getStringWidthUTF8 (const char* pStr);																					///< get the width of an UTF-8 encoded string
	void drawStringUTF8 (const char* pString, const CRect& rect, const CHoriTxtAlign hAlign = kCenterText, bool antialias = true);	///< draw an UTF-8 encoded string
	void drawStringUTF8 (const char* string, const CPoint& _point, bool antialias = true);											///< draw an UTF-8 encoded string
	//@}
	
	void *getWindow () { return pWindow; }
	void setWindow (void *ptr)  { pWindow = ptr; }
	void getLoc (CPoint &where) const { where = penLoc; }
	CFrame* getFrame () const { return pFrame; }

	CPoint offsetScreen;
	CPoint offset;

	void   *getSystemContext () const { return pSystemContext; }

	void forget ();

	VSTGUI_DEPRECATED(CColor getPoint (const CPoint& point);)	///< \deprecated
	VSTGUI_DEPRECATED(void floodFill (const CPoint& start);)	///< \deprecated
	VSTGUI_DEPRECATED(void drawArc (const CRect &rect, const CPoint &point1, const CPoint &point2);)	///< \deprecated
	VSTGUI_DEPRECATED(void fillArc (const CRect &rect, const CPoint &point1, const CPoint &point2);)	///< \deprecated
	VSTGUI_DEPRECATED(void polyLine (const CPoint *pPoint, long numberOfPoints);)	///< \deprecated
	VSTGUI_DEPRECATED(void fillPolygon (const CPoint *pPoint, long numberOfPoints);)	///< \deprecated use VSTGUI::CDrawContext::drawPolygon with kDrawFilled as draw style
	VSTGUI_DEPRECATED(void fillRect (const CRect &rect);)	///< \deprecated use VSTGUI::CDrawContext::drawRect with kDrawFilled as draw style
	VSTGUI_DEPRECATED(void fillEllipse (const CRect &rect);)	///< \deprecated use VSTGUI::CDrawContext::drawEllipse with kDrawFilled as draw style
	VSTGUI_DEPRECATED(long getMouseButtons ();)	///< \deprecated if you really need this call VSTGUI::CFrame::getCurrentMouseButtons
	VSTGUI_DEPRECATED(void getMouseLocation (CPoint &point);)	///< \deprecated if you really need this call VSTGUI::CFrame::getCurrentMouseLocation
	VSTGUI_DEPRECATED(bool waitDoubleClick ();)	///< \deprecated use kDoubleClick in the buttons parameter of the mouse methods instead
	VSTGUI_DEPRECATED(bool waitDrag ();)	///< \deprecated use the new mouse methods instead

	//-------------------------------------------
protected:

	friend class CBitmap;
	friend class COffscreenContext;

	void   *pSystemContext;
	void   *pWindow;
	CFrame *pFrame;

	CFontRef  font;
	CColor fontColor;
	CPoint penLoc;

	CCoord   frameWidth;
	CColor frameColor;
	CColor fillColor;
	CLineStyle lineStyle;
	CDrawMode  drawMode;
	CRect  clipRect;

#if WINDOWS
	#if GDIPLUS
	Gdiplus::Graphics	*pGraphics;
	Gdiplus::Pen		*pPen;
	Gdiplus::SolidBrush	*pBrush;
	Gdiplus::SolidBrush	*pFontBrush;
	public:
		Gdiplus::Graphics* getGraphics () const { return pGraphics; }
	protected:
	#else
	void *pBrush;
	void *pPen;
	void *pOldBrush;
	void *pOldPen;
	void *pOldFont;
	long iPenStyle;
	HDC  pHDC;
	#endif // GDIPLUS
#endif // WINDOWS

#if VSTGUI_USES_COREGRAPHICS
	CGContextRef gCGContext;
	bool needToSynchronizeCGContext;
	public:
	CGContextRef getCGContext () const { return gCGContext; }
	CGContextRef beginCGContext (bool swapYAxis = false);
	void releaseCGContext (CGContextRef context);
	void synchronizeCGContext ();
	
	virtual CGImageRef getCGImage () const;
	protected:
#endif

#if MAC_CARBON
	virtual BitMapPtr getBitmap ();
	virtual void releaseBitmap ();
	virtual CGrafPtr getPort ();
#endif // MAC_CARBON

};


//-----------------------------------------------------------------------------
// COffscreenContext Declaration
//! \brief A drawing device which uses a pixmap as its drawing surface
/// \nosubgrouping
//-----------------------------------------------------------------------------
class COffscreenContext : public CDrawContext
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructors
	//-----------------------------------------------------------------------------
	//@{
	COffscreenContext (CDrawContext *pContext, CBitmap *pBitmap, bool drawInBitmap = false);
	COffscreenContext (CFrame *pFrame, long width, long height, const CColor backgroundColor = kBlackCColor);
	//@}
	virtual ~COffscreenContext ();
	
	//-----------------------------------------------------------------------------
	/// \name COffscreenContext Methods
	//-----------------------------------------------------------------------------
	//@{
	void copyFrom (CDrawContext *pContext, CRect destRect, CPoint srcOffset = CPoint (0, 0));	///< copy from offscreen to pContext
	void copyTo (CDrawContext* pContext, CRect& srcRect, CPoint destOffset = CPoint (0, 0));	///< copy to offscreen from pContext

	inline CCoord getWidth () const { return width; }
	inline CCoord getHeight () const { return height; }
	//@}

	//-------------------------------------------
protected:
	CBitmap	*pBitmap;
	CBitmap	*pBitmapBg;
	CCoord	height;
	CCoord	width;
	bool    bDestroyPixmap;
	bool	bDrawInBitmap;

	CColor  backgroundColor;

#if WINDOWS
	void* oldBitmap;
#endif // WINDOWS

#if VSTGUI_USES_COREGRAPHICS
	void* offscreenBitmap;
	virtual CGImageRef getCGImage () const;
	void releaseCGContext (CGContextRef context);
#endif // VSTGUI_USES_COREGRAPHICS

#if MAC_CARBON
	BitMapPtr getBitmap ();
	void releaseBitmap ();
#endif // MAC_CARBON
};

//-----------------------------------------------------------------------------
// CResourceDescription Declaration
//! \brief Describes a resource by name or by ID
/// \nosubgrouping
//-----------------------------------------------------------------------------
class CResourceDescription
{
public:
	enum { kIntegerType, kStringType, kUnknownType };

	CResourceDescription () : type (kUnknownType) { u.name = 0; }
	CResourceDescription (int id) : type (kIntegerType) { u.id = id; }
	CResourceDescription (const char* name) : type (kStringType) { u.name = name; }

	CResourceDescription& operator= (int id) { u.id = id; type = kIntegerType; return *this; }
	CResourceDescription& operator= (const CResourceDescription& desc) { type = desc.type; u.id = desc.u.id; u.name = desc.u.name; return *this; }

	int type;
	union {
		int id;
		const char* name;
	} u;
};

//-----------------------------------------------------------------------------
// CBitmap Declaration
//! \brief Encapsulates various platform depended kinds of bitmaps
/// \nosubgrouping
//-----------------------------------------------------------------------------
class CBitmap : public CBaseObject
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructors
	//-----------------------------------------------------------------------------
	//@{
	CBitmap (const CResourceDescription& desc);				///< Create a pixmap from a resource identifier.
	CBitmap (CFrame &frame, CCoord width, CCoord height);	///< Create a pixmap with a given size.
	//@}
	virtual ~CBitmap ();

	//-----------------------------------------------------------------------------
	/// \name CBitmap Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual void draw (CDrawContext *pContext, CRect &rect, const CPoint &offset = CPoint (0, 0));	///< Draw the pixmap using a given rect as output position and a given offset of its source pixmap.
	virtual void drawTransparent (CDrawContext *pContext, CRect &rect, const CPoint &offset = CPoint (0, 0));
	virtual void drawAlphaBlend  (CDrawContext *pContext, CRect &rect, const CPoint &offset = CPoint (0, 0), unsigned char alpha = 128);	///< Same as CBitmap::draw except that it uses the alpha value to draw the bitmap alpha blended.

	inline CCoord getWidth () const { return width; }		///< get the width of the image
	inline CCoord getHeight () const { return height; }		///< get the height of the image

	bool isLoaded () const;									///< check if image is loaded
	void *getHandle () const;								///< get a platform image object. Normally you don't need this
	
	void setTransparentColor (const CColor color);						///< set the color of the image which should not be drawn. Works only once on some implementations/platforms.
	CColor getTransparentColor () const { return transparentCColor; }	///< get the current transparent color

	void setNoAlpha (bool state) { noAlpha = state; }
	bool getNoAlpha () const { return noAlpha; }

	const CResourceDescription& getResourceDescription () const { return resourceDesc; }
	//@}

#if VSTGUI_USES_COREGRAPHICS
	CBitmap (CGImageRef cgImage);							///< Create a pixmap from a CGImage
	virtual CGImageRef createCGImage (bool transparent = false);
	virtual void setBitsDirty ();
#endif // VSTGUI_USES_COREGRAPHICS

#if GDIPLUS
	CBitmap (Gdiplus::Bitmap* platformBitmap);							///< Create a pixmap from a Gdiplus Bitmap. 
	Gdiplus::Bitmap* getBitmap ();
#endif // GDIPLUS

	VSTGUI_DEPRECATED(void setTransparencyMask (CDrawContext* pContext, const CPoint& offset = CPoint (0, 0));)	///< \deprecated

	//-------------------------------------------
protected:
	CBitmap ();

	virtual void dispose ();
	virtual bool loadFromResource (const CResourceDescription& resourceDesc);
	virtual bool loadFromPath (const void* platformPath);	// load from a platform path. On Windows it's a C string and on Mac OS X its a CFURLRef.

	CResourceDescription resourceDesc;
	CCoord width;
	CCoord height;

	CColor transparentCColor;
	bool noAlpha;

	void *pHandle;
	void *pMask;
#if WINDOWS
	#if GDIPLUS
	Gdiplus::Bitmap	*pBitmap;
	void* bits;
	#endif // GDIPLUS
#endif // WINDOWS

#if VSTGUI_USES_COREGRAPHICS
	void* cgImage;
#endif // VSTGUI_USES_COREGRAPHICS

};

//-----------------------------------------------------------------------------
// CView Declaration
//! \brief Base Class of all view objects
/// \nosubgrouping
/// \ingroup views
//-----------------------------------------------------------------------------
class CView : public CBaseObject
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructor
	//-----------------------------------------------------------------------------
	//@{
	CView (const CRect &size);
	CView (const CView& view);
	//@}
	virtual ~CView ();

	//-----------------------------------------------------------------------------
	/// \name Draw and Update Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual void draw (CDrawContext *pContext);															///< called if the view should draw itself
	virtual void drawRect (CDrawContext *pContext, const CRect& updateRect) { draw (pContext); }		///< called if the view should draw itself
	virtual bool checkUpdate (const CRect& updateRect) const { return updateRect.rectOverlap (size); }

	virtual bool isDirty () const { return bDirty; }													///< check if view is dirty
	virtual void setDirty (const bool val = true) { bDirty = val; }										///< set the view to dirty so that it is redrawn in the next idle. Thread Safe !

	virtual void invalidRect (const CRect rect);														///< mark rect as invalid
	virtual void invalid () { setDirty (false); invalidRect (size); }									///< mark whole view as invalid

	virtual void setVisible (bool state);																///< set visibility state
	bool isVisible () const { return bVisible; }														///< get visibility state
	//@}

	//-----------------------------------------------------------------------------
	/// \name Mouse Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual CMouseEventResult onMouseDown (CPoint &where, const long& buttons);											///< called when a mouse down event occurs
	virtual CMouseEventResult onMouseUp (CPoint &where, const long& buttons);											///< called when a mouse up event occurs
	virtual CMouseEventResult onMouseMoved (CPoint &where, const long& buttons);										///< called when a mouse move event occurs

	virtual CMouseEventResult onMouseEntered (CPoint &where, const long& buttons) {return kMouseEventNotImplemented;}	///< called when the mouse enters this view
	virtual CMouseEventResult onMouseExited (CPoint &where, const long& buttons) {return kMouseEventNotImplemented;}	///< called when the mouse leaves this view
	
	virtual bool hitTest (const CPoint& where, const long buttons = -1) { return where.isInside (mouseableArea); }		///< check if where hits this view

	virtual bool onWheel (const CPoint &where, const float &distance, const long &buttons);									///< called if a mouse wheel event is happening over this view
	virtual bool onWheel (const CPoint &where, const CMouseWheelAxis &axis, const float &distance, const long &buttons);	///< called if a mouse wheel event is happening over this view

	virtual void setMouseEnabled (const bool bEnable = true) { bMouseEnabled = bEnable; }		///< turn on/off mouse usage for this view
	virtual bool getMouseEnabled () const { return bMouseEnabled; }								///< get the state of wheather this view uses the mouse or not

	virtual void setMouseableArea (const CRect &rect)  { mouseableArea = rect; }				///< set the area in which the view reacts to the mouse
	virtual CRect &getMouseableArea (CRect &rect) const { rect = mouseableArea; return rect;}	///< get the area in which the view reacts to the mouse
	virtual const CRect& getMouseableArea () const { return mouseableArea; }					///< read only access to the mouseable area
	//@}

	//-----------------------------------------------------------------------------
	/// \name Drag & Drop Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual bool onDrop (CDragContainer* drag, const CPoint& where) { return false; }			///< called if a drag is dropped onto this view
	virtual void onDragEnter (CDragContainer* drag, const CPoint& where) {}						///< called if a drag is entering this view
	virtual void onDragLeave (CDragContainer* drag, const CPoint& where) {}						///< called if a drag is leaving this view
	virtual void onDragMove (CDragContainer* drag, const CPoint& where) {}						///< called if a drag is moved inside this view
	//@}

	//-----------------------------------------------------------------------------
	/// \name Keyboard Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual long onKeyDown (VstKeyCode& keyCode);												///< called if a key down event occurs and this view has focus
	virtual long onKeyUp (VstKeyCode& keyCode);													///< called if a key up event occurs and this view has focus
	//@}

	//-----------------------------------------------------------------------------
	/// \name View Size Methods
	//-----------------------------------------------------------------------------
	//@{
	CCoord getHeight () const { return size.height (); }										///< get the height of the view
	CCoord getWidth ()  const { return size.width (); }											///< get the width of the view
	virtual void setViewSize (CRect &rect, bool invalid = true);								///< set views size
	virtual CRect &getViewSize (CRect &rect) const { rect = size; return rect; }				///< returns the current view size
	virtual const CRect& getViewSize () const { return size; }									///< read only access to view size
	virtual CRect getVisibleSize () const;														///< returns the visible size of the view
	virtual void parentSizeChanged () {}														///< notification that one of the views parent has changed its size
	virtual CPoint& frameToLocal (CPoint& point) const;											///< conversion from frame coordinates to local view coordinates
	virtual CPoint& localToFrame (CPoint& point) const;											///< conversion from local view coordinates to frame coordinates
	virtual void setAutosizeFlags (long flags) { autosizeFlags = flags; }						///< set autosize flags
	virtual long getAutosizeFlags () const { return autosizeFlags; }							///< get autosize flags
	//@}

	//-----------------------------------------------------------------------------
	/// \name Focus Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual void looseFocus ();																	///< called if view should loose focus
	virtual void takeFocus ();																	///< called if view should take focus
	virtual bool wantsFocus () const { return bWantsFocus; }									///< check if view supports focus
	virtual void setWantsFocus (bool state) { bWantsFocus = state; }							///< set focus support on/off
	//@}

	//-----------------------------------------------------------------------------
	/// \name Attribute Methods
	//-----------------------------------------------------------------------------
	//@{
	bool getAttributeSize (const CViewAttributeID id, long& outSize) const;									///< get the size of an attribute
	bool getAttribute (const CViewAttributeID id, const long inSize, void* outData, long& outSize) const;	///< get an attribute
	bool setAttribute (const CViewAttributeID id, const long inSize, const void* inData);					///< set an attribute
	bool removeAttribute (const CViewAttributeID id);														///< remove an attribute
	//@}

	virtual void setBackground (CBitmap *background);											///< set the background image of this view
	virtual CBitmap *getBackground () const { return pBackground; }								///< get the background image of this view

	virtual void setTransparency (bool val) { bTransparencyEnabled = val; }						///< set views transparent state
	virtual bool getTransparency () const { return bTransparencyEnabled; }						///< get views transparent state

	virtual bool removed (CView* parent);														///< view is removed from parent view
	virtual bool attached (CView* parent);														///< view is attached to a parent view
	bool isAttached () const { return bIsAttached; }											///< is view attached to a parentView

	//-----------------------------------------------------------------------------
	/// \name Parent Methods
	//-----------------------------------------------------------------------------
	//@{
	CView  *getParentView () const { return pParentView; }										///< get parent view
	CFrame *getFrame () const { return pParentFrame; }											///< get frame
	virtual VSTGUIEditorInterface *getEditor () const;											///< get editor
	//@}
	
	#if DEBUG
	virtual void dumpInfo ();
	#endif

	virtual bool isTypeOf (const char* s) const
		{ return (!strcmp (s, "CView")); }

	virtual CView* newCopy () const { return new CView (*this); }

	#if DEBUG
	virtual const char* getClassName () const { return "CView"; }
	#endif
	
	// overwrites
	CMessageResult notify (CBaseObject* sender, const char* message);

	//-------------------------------------------

	VSTGUI_DEPRECATED(virtual void mouse (CDrawContext *pContext, CPoint &where, long buttons = -1);)	///< \deprecated use the new mouse methods instead
	VSTGUI_DEPRECATED(virtual void getMouseLocation (CDrawContext* context, CPoint &point);)	///< \deprecated use VSTGUI::CFrame::getCurrentMouseLocation and process the point with VSTGUI::CView::frameToLocal
	VSTGUI_DEPRECATED(virtual void setParentView (CView *pParentView) { this->pParentView = pParentView; })	///< \deprecated
	VSTGUI_DEPRECATED(virtual void setFrame (CFrame *pParent) { this->pParentFrame = pParent; })	///< \deprecated
	VSTGUI_DEPRECATED(virtual void getFrameTopLeftPos (CPoint& topLeft) const;)	///< \deprecated use VSTGUI::CView::localToFrame

	//-------------------------------------------
protected:
	CRect  size;
	CRect  mouseableArea;

	CFrame *pParentFrame;
	CView  *pParentView;

	bool  bDirty;
	bool  bMouseEnabled;
	bool  bTransparencyEnabled;
	bool  bWantsFocus;
	bool  bIsAttached;
	bool  bVisible;
	
	long  autosizeFlags;
	
	CBitmap* pBackground;
	CAttributeListEntry* pAttributeList;
};

extern const char* kMsgCheckIfViewContainer;	///< Message to check if View is a CViewContainer
extern const char* kMsgLooseFocus;				///< Message of a view loosing focus (only CTextEdit and COptionMenu send this yet)
extern const char* kMsgNewFocusView;			///< Message send to all parents of the new focus view
extern const char* kMsgOldFocusView;			///< Message send to all parents of the old focus view

//-----------------------------------------------------------------------------
// CViewContainer Declaration
//! \brief Container Class of CView objects
/// \nosubgrouping
/// \ingroup containerviews
//-----------------------------------------------------------------------------
class CViewContainer : public CView
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructor
	//-----------------------------------------------------------------------------
	//@{
	CViewContainer (const CRect &size, CFrame *pParent, CBitmap *pBackground = 0);
	CViewContainer (const CViewContainer& viewContainer);
	//@}
	virtual ~CViewContainer ();

	//-----------------------------------------------------------------------------
	/// \name Sub View Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual bool addView (CView *pView);	///< add a child view
	virtual bool addView (CView *pView, CRect &mouseableArea, bool mouseEnabled = true);	///< add a child view
	virtual bool addView (CView *pView, CView* pBefore);	///< add a child view before another view
	virtual bool removeView (CView *pView, const bool &withForget = true);	///< remove a child view
	virtual bool removeAll (const bool &withForget = true);	///< remove all child views
	virtual bool isChild (CView *pView) const;	///< check if pView is a child view of this container
	virtual long getNbViews () const;			///< get the number of child views
	virtual CView* getView (long index) const;	///< get the child view at index
	virtual CView* getViewAt (const CPoint& where, bool deep = false) const;	///< get the view at point where
	virtual CViewContainer* getContainerAt (const CPoint& where, bool deep = true) const;		///< get the container at point where
	//@}

	//-----------------------------------------------------------------------------
	/// \name Background Methods
	//-----------------------------------------------------------------------------
	//@{
	virtual void setBackgroundColor (const CColor color);	///< set the background color (will only be drawn if this container is not set to transparent and does not have a background bitmap)
	virtual CColor getBackgroundColor () const { return backgroundColor; }	///< get the background color
	virtual void setBackgroundOffset (const CPoint &p) { backgroundOffset = p; }	///< set the offset of the background bitmap
	virtual const CPoint& getBackgroundOffset () const { return backgroundOffset; }	///< get the offset of the background bitmap
	virtual void drawBackgroundRect (CDrawContext *pContext, CRect& _updateRect);	///< draw the background
	//@}

	virtual void useOffscreen (bool b);	///< turn on/off using an offscreen. Not necessary with GDI+ on Windows, or on Mac OS X.

	void modifyDrawContext (CCoord save[4], CDrawContext* pContext);
	void restoreDrawContext (CDrawContext* pContext, CCoord save[4]);

	virtual bool advanceNextFocusView (CView* oldFocus, bool reverse = false);

	// CView
	virtual void draw (CDrawContext *pContext);
	virtual void drawRect (CDrawContext *pContext, const CRect& updateRect);
	virtual CMouseEventResult onMouseDown (CPoint &where, const long& buttons);
	virtual CMouseEventResult onMouseUp (CPoint &where, const long& buttons);
	virtual CMouseEventResult onMouseMoved (CPoint &where, const long& buttons);
	virtual bool onWheel (const CPoint &where, const float &distance, const long &buttons);
	virtual bool onWheel (const CPoint &where, const CMouseWheelAxis &axis, const float &distance, const long &buttons);
	virtual bool hitTest (const CPoint& where, const long buttons = -1);
	virtual long onKeyDown (VstKeyCode& keyCode);
	virtual long onKeyUp (VstKeyCode& keyCode);
	virtual CMessageResult notify (CBaseObject* sender, const char* message);

	virtual bool onDrop (CDragContainer* drag, const CPoint& where);
	virtual void onDragEnter (CDragContainer* drag, const CPoint& where);
	virtual void onDragLeave (CDragContainer* drag, const CPoint& where);
	virtual void onDragMove (CDragContainer* drag, const CPoint& where);

	virtual void looseFocus ();
	virtual void takeFocus ();

	virtual bool isDirty () const;

	virtual void invalid ();
	virtual void invalidRect (const CRect rect);
	virtual bool invalidateDirtyViews ();
	
	virtual void setViewSize (CRect &rect, bool invalid = true);
	virtual void parentSizeChanged ();
	virtual CRect getVisibleSize (const CRect rect) const;

	virtual bool removed (CView* parent);
	virtual bool attached (CView* parent);
		
	virtual CPoint& frameToLocal (CPoint& point) const;
	virtual CPoint& localToFrame (CPoint& point) const;

	CLASS_METHODS(CViewContainer, CView)

	#if DEBUG
	virtual void dumpInfo ();
	virtual void dumpHierarchy ();
	#endif

	VSTGUI_DEPRECATED(virtual void mouse (CDrawContext *pContext, CPoint &where, long buttons = -1);)	///< \deprecated use the new mouse methods instead
	VSTGUI_DEPRECATED(virtual CView *getCurrentView () const;)	///< \deprecated

	//-------------------------------------------
protected:
	virtual bool checkUpdateRect (CView* view, const CRect& rect);
	virtual bool hitTestSubViews (const CPoint& where, const long buttons = -1);
	void drawBackToFront (CDrawContext* context, const CRect& rect);

	CCView  *pFirstView;
	CCView  *pLastView;
	COffscreenContext *pOffscreenContext;
	CColor backgroundColor;
	CPoint backgroundOffset;
	bool bDrawInOffscreen;

	CView* currentDragView;
	CView* mouseDownView;
};

//-----------------------------------------------------------------------------
// CFrame Declaration
//! \brief The CFrame is the parent container of all views
/// \nosubgrouping
/// \ingroup containerviews
//-----------------------------------------------------------------------------
class CFrame : public CViewContainer
{
public:
	//-----------------------------------------------------------------------------
	/// \name Constructor
	//-----------------------------------------------------------------------------
	//@{
	CFrame (const CRect &size, void *pSystemWindow, VSTGUIEditorInterface *pEditor);
	#if ENABLE_VST_EXTENSION_IN_VSTGUI
	CFrame (const CRect &size, const char *pTitle, VSTGUIEditorInterface *pEditor, const long style = 0);	///< /deprecated
	#endif
	//@}
	virtual ~CFrame ();

	//-----------------------------------------------------------------------------
	/// \name CFrame Methods
	//-----------------------------------------------------------------------------
	//@{
	#if ENABLE_VST_EXTENSION_IN_VSTGUI
	virtual bool open (CPoint *pPoint = 0);	///< /deprecated
	virtual bool close ();					///< /deprecated
	#endif
	virtual bool isOpen () const { return bOpenFlag; }

	virtual void idle ();
	virtual void doIdleStuff ();

	virtual unsigned long getTicks () const;	///< get the current time (in ms)
	virtual long getKnobMode () const;			///< get hosts knob mode

	virtual bool setPosition (CCoord x, CCoord y);
	virtual bool getPosition (CCoord &x, CCoord &y) const;

	virtual bool setSize (CCoord width, CCoord height);
	virtual bool getSize (CRect *pSize) const;
	virtual bool getSize (CRect &pSize) const;

	virtual bool   setModalView (CView *pView);
	virtual CView *getModalView () const { return pModalView; }

	virtual void  beginEdit (long index);
	virtual void  endEdit (long index);

	virtual bool getCurrentMouseLocation (CPoint &where) const;				///< get current mouse location
	virtual long getCurrentMouseButtons () const;							///< get current mouse buttons and key modifiers
	virtual void setCursor (CCursorType type);								///< set mouse cursor

	virtual void   setFocusView (CView *pView);
	virtual CView *getFocusView () const { return pFocusView; }
	virtual bool advanceNextFocusView (CView* oldFocus, bool reverse = false);

	virtual void onViewRemoved (CView* pView);

	virtual bool setDropActive (bool val);
	virtual bool isDropActive () const { return bDropActive; };

	CDrawContext* createDrawContext ();

	virtual void setOpenFlag (bool val) { bOpenFlag = val;};
	virtual bool getOpenFlag () const { return bOpenFlag; };

	virtual void invalidate (const CRect &rect);

	void scrollRect (const CRect& src, const CPoint& distance);		///< scroll src rect by distance
	//@}

	void invalid () { invalidRect (size); bDirty = false; }
	void invalidRect (const CRect rect);

	#if MAC_COCOA && MAC_CARBON
	static void setCocoaMode (bool state);
	#endif

	#if WINDOWS
	HWND getOuterWindow () const;
	void *getParentSystemWindow () const { return pSystemWindow; }
	void setParentSystemWindow (void *val) { pSystemWindow = val; }
	COffscreenContext* getBackBuffer ();
	#endif // WINDOWS
	
	void *getSystemWindow () const;	///< get platform window
	
	bool removeView (CView *pView, const bool &withForget = true);
	bool removeAll (const bool &withForget = true);

	// CView
	void draw (CDrawContext *pContext);
	void drawRect (CDrawContext *pContext, const CRect& updateRect);
	CMouseEventResult onMouseDown (CPoint &where, const long& buttons);
	CMouseEventResult onMouseUp (CPoint &where, const long& buttons);
	CMouseEventResult onMouseMoved (CPoint &where, const long& buttons);
	CMouseEventResult onMouseExited (CPoint &where, const long& buttons);
	bool onWheel (const CPoint &where, const float &distance, const long &buttons);
	bool onWheel (const CPoint &where, const CMouseWheelAxis &axis, const float &distance, const long &buttons);
	long onKeyDown (VstKeyCode& keyCode);
	long onKeyUp (VstKeyCode& keyCode);
	void setViewSize (CRect& rect, bool invalid = true);

	virtual VSTGUIEditorInterface *getEditor () const { return pEditor; }
	virtual IMouseObserver *getMouseObserver () const { return pMouseObserver; }
	virtual void setMouseObserver (IMouseObserver* observer) { pMouseObserver = observer; }

	#if DEBUG
	virtual void dumpHierarchy ();
	#endif

	CLASS_METHODS(CFrame, CViewContainer)

	VSTGUI_DEPRECATED(virtual bool getCurrentLocation (CPoint &where);)	///< \deprecated use VSTGUI::CFrame::getCurrentMouseLocation instead
	VSTGUI_DEPRECATED(virtual void mouse (CDrawContext *pContext, CPoint &where, long buttons = -1);)	///< \deprecated use the new mouse methods
	VSTGUI_DEPRECATED(virtual CView *getCurrentView () const;)	///< \deprecated
	VSTGUI_DEPRECATED(void draw (CView *pView = 0);)	///< \deprecated use pView->invalid () instead

	//-------------------------------------------
protected:
	bool   initFrame (void *pSystemWin);

	VSTGUIEditorInterface   *pEditor;
	IMouseObserver			*pMouseObserver;
	
	void    *pSystemWindow;
	CView   *pModalView;
	CView   *pFocusView;
	CView   *pMouseOverView;

	bool    bFirstDraw;
	bool    bOpenFlag;
	bool    bDropActive;

#if WINDOWS
	void      *pHwnd;
	HINSTANCE hInstMsimg32dll;
	void*     dropTarget;
	COffscreenContext* backBuffer;
	bool      bMouseInside;
#endif // WINDOWS

#if MAC_CARBON
	void setDrawContext (CDrawContext* context) { pFrameContext = context; }
	friend class CDrawContext;

	static pascal OSStatus carbonMouseEventHandler (EventHandlerCallRef inHandlerCallRef, EventRef inEvent, void *inUserData);
	static pascal OSStatus carbonEventHandler (EventHandlerCallRef inHandlerCallRef, EventRef inEvent, void *inUserData);
	
	HIViewRef controlRef;
	bool hasFocus;
	EventHandlerRef dragEventHandler;
	EventHandlerRef mouseEventHandler;
	public:
	void* getPlatformControl () const { return controlRef; }
	CPoint hiScrollOffset;
	protected:
#endif // MAC_CARBON

#if MAC_COCOA
	void* nsView;
	public:
	void* getNSView () const { return nsView; }
	protected:
	
#endif // MAC_COCOA
	//-------------------------------------------
private:
	CDrawContext *pFrameContext;
	#if ENABLE_VST_EXTENSION_IN_VSTGUI
	bool     bAddedWindow;
	void     *pVstWindow;
	#endif
	void     *defaultCursor;
};

//-----------------------------------------------------------------------------
// IMouseObserver Declaration
//! \brief generic mouse observer interface
/// \nosubgrouping
//-----------------------------------------------------------------------------
class IMouseObserver
{
public:
	virtual ~IMouseObserver() {}
	virtual void onMouseEntered (CView* view, CFrame* frame) = 0;
	virtual void onMouseExited (CView* view, CFrame* frame) = 0;
	virtual void onMouseMoved (CFrame* frame, const CPoint& where) {}
	virtual void onMouseDown (CFrame* frame, const CPoint& where) {}
};

//-----------------------------------------------------------------------------
// CDragContainer Declaration
//! \brief drag container
/// \nosubgrouping
//-----------------------------------------------------------------------------
class CDragContainer : public CBaseObject
{
public:
	virtual void* first (long& size, long& type) = 0;		///< returns pointer on a char array if type is known
	virtual void* next (long& size, long& type) = 0;		///< returns pointer on a char array if type is known
	
	virtual long getType (long idx) const = 0;
	virtual long getCount () const = 0;

	enum CDragType {
		kFile = 0,								///< File (MacOSX = UTF8 String)
		kText,									///< ASCII Text
		kUnicodeText,							///< UTF8 Text

		kUnknown = -1,
		kError = -2
	};
};

/// \cond ignore
//-----------------------------------------------------------------------------
// CCView Declaration
//-----------------------------------------------------------------------------
class CCView
{
public:
	CCView (CView *pView);
	~CCView ();

	CView    *pView;
	CCView   *pNext;
	CCView   *pPrevious;
};
/// \endcond

#if GDIPLUS
class GDIPlusGlobals : public CBaseObject
{
public:
	static void enter ();	///< call this once before using VSTGUI. Can be nested.
	static void exit ();	///< call this after releasing all VSTGUI objects especially CBitmaps
protected:
	GDIPlusGlobals ();
	~GDIPlusGlobals ();

	static GDIPlusGlobals* gInstance;
	ULONG_PTR gdiplusToken;
};
#endif

#if WINDOWS
#include <malloc.h>

/// \cond ignore
class UTF8StringHelper
{
public:
	UTF8StringHelper (const char* utf8Str) : utf8Str (utf8Str), allocWideStr (0), allocStrIsWide (true) {}
	UTF8StringHelper (const WCHAR* wideStr) : wideStr (wideStr), allocUTF8Str (0), allocStrIsWide (false) {}
	~UTF8StringHelper () { if (allocUTF8Str) free (allocUTF8Str); }

	operator const char* () { return getUTF8String (); }
	operator const WCHAR*() { return getWideString (); }

	const WCHAR* getWideString ()
	{
		if (!allocStrIsWide)
			return wideStr;
		else
		{
			if (!allocWideStr && utf8Str)
			{
				int numChars = MultiByteToWideChar (CP_UTF8, 0, utf8Str, -1, 0, 0);
				allocWideStr = (WCHAR*)malloc ((numChars+1)*2);
				if (MultiByteToWideChar (CP_UTF8, 0, utf8Str, -1, allocWideStr, numChars) == 0)
				{
					allocWideStr[0] = 0;
				}
			}
			return allocWideStr;
		}
	}
	const char* getUTF8String ()
	{
		if (allocStrIsWide)
			return utf8Str;
		else
		{
			if (!allocUTF8Str && wideStr)
			{
				int allocSize = WideCharToMultiByte (CP_UTF8, 0, wideStr, -1, 0, 0, 0, 0);
				allocUTF8Str = (char*)malloc (allocSize+1);
				if (WideCharToMultiByte (CP_UTF8, 0, wideStr, -1, allocUTF8Str, allocSize, 0, 0) == 0)
				{
					allocUTF8Str[0] = 0;
				}
			}
			return allocUTF8Str;
		}
	}
protected:
	union {
		const char* utf8Str;
		const WCHAR* wideStr;
	};
	union {
		WCHAR* allocWideStr;
		char* allocUTF8Str;
	};

	bool allocStrIsWide;
};
/// \endcond
#endif


END_NAMESPACE_VSTGUI

/// \cond ignore
// include the control objects
#ifndef __vstcontrols__
#include "vstcontrols.h"
#endif
/// \endcond

USING_NAMESPACE_VSTGUI

//-End VSTGUI.H--------------------------------------
#endif	// __vstgui__
