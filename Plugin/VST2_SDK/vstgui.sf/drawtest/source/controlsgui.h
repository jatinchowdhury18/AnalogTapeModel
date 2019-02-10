#ifndef __controlsgui__
#define __controlsgui__

#ifndef __vstcontrols__
#include "vstcontrols.h"
#endif

#include "cvstguitimer.h"

class CLabel;

class ControlsGUI : public CViewContainer, CControlListener
{
public:
	ControlsGUI (const CRect &size, CFrame *pParent, CBitmap *pBackground = 0);

	// overwrites from CView
	void valueChanged (CControl *pControl);
	bool attached (CView* view);
	bool removed (CView* parent);
	CMessageResult notify (CBaseObject* sender, const char* message);

protected:

	COnOffButton      *cOnOffButton;
	CKickButton       *cKickButton;
	CKnob             *cKnob;
	CMovieButton      *cMovieButton;
	CAnimKnob         *cAnimKnob;
	COptionMenu       *cOptionMenu;

	CRockerSwitch     *cRockerSwitch;
	CHorizontalSwitch *cHorizontalSwitch;
	CVerticalSwitch   *cVerticalSwitch;
	CHorizontalSlider *cHorizontalSlider;
	CHorizontalSlider *cHorizontalSlider2;
	CVerticalSlider   *cVerticalSlider;
	CTextEdit         *cTextEdit;

	CSplashScreen     *cSplashScreen;
	CMovieBitmap      *cMovieBitmap;
	CAutoAnimation    *cAutoAnimation;
	CSpecialDigit     *cSpecialDigit;
	CParamDisplay     *cParamDisplay;
	CVuMeter          *cVuMeter;

	CViewContainer    *cViewContainer;

	// others
	CLabel            *cLabel;
	
	CTextLabel        *tooltipView;
	
	// animation timer
	CVSTGUITimer	  *animTimer;

	long              oldTicks;
};

#endif
