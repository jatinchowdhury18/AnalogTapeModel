//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework not only for VST plugins : 
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

#ifndef __ctabview__
#define __ctabview__

#ifndef __vstcontrols__
#include "vstcontrols.h"
#endif

BEGIN_NAMESPACE_VSTGUI

class CTabChildView;

//-----------------------------------------------------------------------------
class CTabView : public CViewContainer, public CControlListener
//! \brief a tab view
/// \nosubgrouping
/// \ingroup containerviews
//-----------------------------------------------------------------------------
{
public:
	enum TabPosition {
		kPositionLeft = 0,
		kPositionRight,
		kPositionTop,
		kPositionBottom,
	};

	enum TabAlignment {
		kAlignCenter = 0,
		kAlignLeft,
		kAlignRight,
		kAlignTop = kAlignLeft,
		kAlignBottom = kAlignRight
	};

	//-----------------------------------------------------------------------------
	/// \name Tab View Constructors
	//-----------------------------------------------------------------------------
	//@{
	CTabView (const CRect& size, CFrame* parent, CBitmap* tabBitmap, CBitmap* background = 0, TabPosition tabPosition = kPositionTop, long style = 0);
	CTabView (const CRect& size, CFrame* parent, const CRect& tabSize, CBitmap* background = 0, TabPosition tabPosition = kPositionTop, long style = 0);
	//@}
	virtual ~CTabView ();
	
	//-----------------------------------------------------------------------------
	/// \name Tab View Functions
	//-----------------------------------------------------------------------------
	//@{
	virtual bool addTab (CView* view, const char* name = 0, CBitmap* tabBitmap = 0);	///< add a tab
	virtual bool addTab (CView* view, CControl* button);	///< add a tab
	virtual bool removeTab (CView* view);	///< remove a tab
	virtual bool removeAllTabs ();			///< remove all tabs
	virtual bool selectTab (long index);	///< select tab at index
	virtual long getCurrentSelectedTab () const { return currentTab; } ///< get current index of selected tab

	virtual CRect& getTabViewSize (CRect& rect) const;	///< the the size of one tab

	virtual void setTabFontStyle (const CFontRef font, CCoord fontSize = 12, CColor selectedColor = kBlackCColor, CColor deselectedColor = kWhiteCColor); ///< call this after the tabs are added. Tabs added after this call will have the default font style.

	virtual void alignTabs (TabAlignment alignment = kAlignCenter); ///< call this after you have added all tabs to align them according to alignment
	//@}

	virtual void valueChanged (CControl *pControl);
	virtual void setViewSize (CRect &rect, bool invalid = true);
//-----------------------------------------------------------------------------
	CLASS_METHODS (CTabView, CViewContainer)
protected:
	void setCurrentChild (CTabChildView* childView);

	long numberOfChilds;
	long currentTab;
	TabPosition tabPosition;
	long style;
	CRect tabSize;
	CBitmap* tabBitmap;
	CTabChildView* firstChild;
	CTabChildView* lastChild;
	CTabChildView* currentChild;
};

END_NAMESPACE_VSTGUI

#endif
