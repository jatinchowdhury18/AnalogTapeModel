#ifndef __pprimitivesviews__
#define __pprimitivesviews__

#ifndef __vstgui__
#include "vstgui.h"
#endif

class PLinesView : public CView
{
public:
	PLinesView (const CRect& size);
	
	virtual void draw (CDrawContext *pContext);
};

class PRectsView : public CView
{
public:
	PRectsView (const CRect& size);
	
	virtual void draw (CDrawContext *pContext);
};

class PMiscView : public CView
{
public:
	PMiscView (const CRect& size);
	
	virtual void draw (CDrawContext* pContext);
#if VSTGUI_ENABLE_DEPRECATED_METHODS
	virtual void mouse (CDrawContext* pContext, CPoint &where, long buttons = -1);
#endif
protected:
	void drawGrid (CDrawContext* pContext);
	long xOffset;
	long yOffset;
};

#endif
