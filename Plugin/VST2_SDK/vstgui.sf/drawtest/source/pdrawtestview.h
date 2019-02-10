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
#define __pdrawtestview__

#ifndef __vstgui__
#include "vstgui.h"
#endif

BEGIN_NAMESPACE_VSTGUI

class CDrawTestView : public CView
{
public:
	CDrawTestView (const CRect& size);
	
	virtual void draw (CDrawContext *pContext);

#if VSTGUI_ENABLE_DEPRECATED_METHODS
	virtual void mouse (CDrawContext* pContext, CPoint& where, long buttons);
#endif

protected:
	int value;
};

END_NAMESPACE_VSTGUI

#endif