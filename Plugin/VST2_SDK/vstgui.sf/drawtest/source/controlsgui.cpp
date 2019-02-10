#ifndef __controlsgui__
#include "controlsgui.h"
#endif

#include "cfileselector.h"

#include <stdio.h>

enum
{
	// bitmaps
	kBackgroundBitmap = 10001,
	
	kSliderHBgBitmap,
	kSliderVBgBitmap,
	kSliderHandleBitmap,

	kSwitchHBitmap,
	kSwitchVBitmap,

	kOnOffBitmap,

	kKnobHandleBitmap,
	kKnobBgBitmap,

	kDigitBitmap,
	kRockerBitmap,

	kVuOnBitmap,
	kVuOffBitmap,

	kSplashBitmap,

	kMovieKnobBitmap,

	kMovieBitmap,

	// others
	kBackgroundW = 420,
	kBackgroundH = 210
};
//-----------------------------------------------------------------------------
// CLabel declaration
//-----------------------------------------------------------------------------
class CLabel : public CTextLabel
{
public:
	CLabel (CRect &size, char *text);

	void draw (CDrawContext *pContext);
	virtual bool onDrop (CDragContainer* drag, const CPoint& where);
	virtual void onDragEnter (CDragContainer* drag, const CPoint& where);
	virtual void onDragLeave (CDragContainer* drag, const CPoint& where);
	virtual void onDragMove (CDragContainer* drag, const CPoint& where);

protected:
	bool focus;
};

//-----------------------------------------------------------------------------
// CLabel implementation
//-----------------------------------------------------------------------------
CLabel::CLabel (CRect &size, char *text)
: CTextLabel (size)
, focus (false)
{
	setText (text);
	setTransparency (true);
}

bool CLabel::onDrop (CDragContainer* drag, const CPoint& where)
{
	long size, type;
	void* ptr = drag->first (size, type);
	if (ptr)
	{
		if (type == CDragContainer::kText || type == CDragContainer::kFile || type == CDragContainer::kUnicodeText)
			setText ((char*)ptr);
		if (type == CDragContainer::kUnicodeText)
		{
			#if DEVELOPMENT
			for (long i = 0; i < size; i++)
			{
				DebugPrint ("%x", ((char*)ptr)[i]);
			}
			DebugPrint ("\n");
			#endif
		}
	}
	return true;
}

void CLabel::onDragEnter (CDragContainer* drag, const CPoint& where)
{
	getFrame ()->setCursor (kCursorCopy);
	focus = true;
	setDirty ();
}

void CLabel::onDragLeave (CDragContainer* drag, const CPoint& where)
{
	getFrame ()->setCursor (kCursorNotAllowed);
	focus = false;
	setDirty ();
}

void CLabel::onDragMove (CDragContainer* drag, const CPoint& where)
{
}

//------------------------------------------------------------------------
void CLabel::draw (CDrawContext *pContext)
{
	pContext->setFrameColor (kBlackCColor);
	if (focus)
	{
		pContext->setFillColor (kRedCColor);
		pContext->drawRect (size, kDrawFilledAndStroked);
	}
	else
		pContext->drawRect (size, kDrawStroked);
	CTextLabel::draw (pContext);
}

enum
{
	kSliderHTag = 0,
	kSliderVTag,
	kKnobTag,

	kNumParams,

	kOnOffTag,
	kKickTag,
	kMovieButtonTag,
	kAutoAnimationTag,
	kOptionMenuTag,

	kRockerSwitchTag,
	kSwitchHTag,
	kSwitchVTag,

	kSplashTag,
	kMovieBitmapTag,
	kAnimKnobTag,
	kDigitTag,
	kTextEditTag,

	kAbout
};

ControlsGUI::ControlsGUI (const CRect &inSize, CFrame *frame, CBitmap *pBackground)
: CViewContainer (inSize, frame, pBackground), animTimer (0)
{
	// get version
	int version = (VSTGUI_VERSION_MAJOR << 16) + VSTGUI_VERSION_MINOR;
	int verMaj = (version & 0xFF00) >> 16;
	int verMin = (version & 0x00FF);

	// init the background bitmap
	CBitmap *background = new CBitmap (kBackgroundBitmap);

	setBackground (background);

	background->forget ();

	CPoint point (0, 0);

	//--COnOffButton-----------------------------------------------
	CBitmap *onOffButton = new CBitmap (kOnOffBitmap);

	CRect size (0, 0, onOffButton->getWidth (), onOffButton->getHeight () / 2);
	size.offset (20, 20);
	cOnOffButton = new COnOffButton (size, this, kOnOffTag, onOffButton);
	addView (cOnOffButton);
	cOnOffButton->setAttribute (kCViewTooltipAttribute,strlen ("COnOffButton")+1,"COnOffButton");


	//--CKickButton-----------------------------------------------
 	size.offset (70, 0);
	point (0, 0);
	cKickButton = new CKickButton (size, this, kKickTag, onOffButton->getHeight() / 2, onOffButton, point);
	addView (cKickButton);
	cKickButton->setAttribute (kCViewTooltipAttribute,strlen ("CKickButton")+1,"CKickButton");


	//--CKnob--------------------------------------
	CBitmap *knob   = new CBitmap (kKnobHandleBitmap);
	CBitmap *bgKnob = new CBitmap (kKnobBgBitmap);

 	size (0, 0, bgKnob->getWidth (), bgKnob->getHeight ());
	size.offset (140 + 15, 15);
	point (0, 0);
	cKnob = new CKnob (size, this, kKnobTag, bgKnob, knob, point);
	cKnob->setInsetValue (7);
	addView (cKnob);
	knob->forget ();
	bgKnob->forget ();
	cKnob->setAttribute (kCViewTooltipAttribute,strlen ("CKnob")+1,"CKnob");


	//--CMovieButton--------------------------------------
 	size (0, 0, onOffButton->getWidth (), onOffButton->getHeight () / 2);
	size.offset (210 + 20, 20);
	point (0, 0);
	cMovieButton = new CMovieButton (size, this, kMovieButtonTag, onOffButton->getHeight () / 2, onOffButton, point);
	addView (cMovieButton);
	cMovieButton->setAttribute (kCViewTooltipAttribute,strlen ("CMovieButton")+1,"CMovieButton");

	onOffButton->forget ();


	//--CAnimKnob--------------------------------------
	CBitmap *movieKnobBitmap = new CBitmap (kMovieKnobBitmap);

	size (0, 0, movieKnobBitmap->getWidth (), movieKnobBitmap->getHeight () / 7);
	size.offset (280 + 15, 15);
	point (0, 0);
	cAnimKnob = new CAnimKnob (size, this, kAnimKnobTag, 7, movieKnobBitmap->getHeight () / 7, movieKnobBitmap, point);
	addView (cAnimKnob);
	cAnimKnob->setAttribute (kCViewTooltipAttribute,strlen ("CAnimKnob")+1,"CAnimKnob");
	
	movieKnobBitmap->forget ();


	//--COptionMenu--------------------------------------
	size (0, 0, 50, 14);
	size.offset (350 + 10, 30);

	long style = k3DIn | kMultipleCheckStyle;
	cOptionMenu = new COptionMenu (size, this, kOptionMenuTag, bgKnob, 0, style);
	if (cOptionMenu)
	{
		cOptionMenu->setFont (kNormalFont);
		cOptionMenu->setFontColor (kWhiteCColor);
		cOptionMenu->setBackColor (kRedCColor);
		cOptionMenu->setFrameColor (kWhiteCColor);
		cOptionMenu->setHoriAlign (kLeftText);
		int i;
		for (i = 0; i < 3; i++)
		{
			char txt[256];
			sprintf (txt, "Entry %d", i);
			cOptionMenu->addEntry (txt);
		}
		cOptionMenu->addEntry ("-");
		for (i = 3; i < 60; i++)
		{
			char txt[256];
			sprintf (txt, "Entry %d", i);
			cOptionMenu->addEntry (txt);
		}

		addView (cOptionMenu);
		cOptionMenu->setAttribute (kCViewTooltipAttribute,strlen ("COptionMenu")+1,"COptionMenu");
	}


	//--CRockerSwitch--------------------------------------
	CBitmap *rocker = new CBitmap (kRockerBitmap);
 	size (0, 0, rocker->getWidth (), rocker->getHeight () / 3);
	size.offset (9, 70 + 29);
	point (0, 0);
	cRockerSwitch = new CRockerSwitch (size, this, kRockerSwitchTag, rocker->getHeight () / 3, rocker, point);
	addView (cRockerSwitch);
	rocker->forget ();
	cRockerSwitch->setAttribute (kCViewTooltipAttribute,strlen ("CRockerSwitch")+1,"CRockerSwitch");


	//--CHorizontalSwitch--------------------------------------
	CBitmap *switchHBitmap = new CBitmap (kSwitchHBitmap);
	size (0, 0, switchHBitmap->getWidth (), switchHBitmap->getHeight () / 4);
	size.offset (70 + 10, 70 + 30);
	point (0, 0);
	cHorizontalSwitch = new CHorizontalSwitch (size, this, kSwitchHTag, 4, switchHBitmap->getHeight () / 4, 4, switchHBitmap, point);
	addView (cHorizontalSwitch);
	switchHBitmap->forget ();
	cHorizontalSwitch->setAttribute (kCViewTooltipAttribute,strlen ("CHoriontalSwitch")+1,"CHorizontalSwitch");


	//--CVerticalSwitch--------------------------------------
	CBitmap *switchVBitmap = new CBitmap (kSwitchVBitmap);

	size (0, 0, switchVBitmap->getWidth (), switchVBitmap->getHeight () / 4);
	size.offset (140 + 30, 70 + 5);
	cVerticalSwitch = new CVerticalSwitch (size, this, kSwitchVTag, 4, switchVBitmap->getHeight () / 4, 4, switchVBitmap, point);
	addView (cVerticalSwitch);
	switchVBitmap->forget ();
	cVerticalSwitch->setAttribute (kCViewTooltipAttribute,strlen ("CVerticalSwitch")+1,"CVerticalSwitch");


	//--CHorizontalSlider--------------------------------------
	CBitmap *sliderHBgBitmap = new CBitmap (kSliderHBgBitmap);
	CBitmap *sliderHandleBitmap = new CBitmap (kSliderHandleBitmap);

	size (0, 0, sliderHBgBitmap->getWidth (), sliderHBgBitmap->getHeight ());
	size.offset (10, 30);

	point (0, 0);
#if 1
	cHorizontalSlider = new CHorizontalSlider (size, this, kSliderHTag, size.left + 2, size.left + sliderHBgBitmap->getWidth () - sliderHandleBitmap->getWidth () - 1, sliderHandleBitmap, sliderHBgBitmap, point, kLeft);
	point (0, 2);
	cHorizontalSlider->setOffsetHandle (point);
#else
	CPoint handleOffset (2, 2);
	cHorizontalSlider = new CHorizontalSlider (size, this, kSliderHTag, handleOffset, size.width () - 2 * handleOffset.h, sliderHandleBitmap, sliderHBgBitmap, point, kLeft);
#endif
	cHorizontalSlider->setFreeClick (false);
	size.offset (0, -30 + 10);
	cHorizontalSlider->setAttribute (kCViewTooltipAttribute,strlen ("CHorizontalSlider")+1,"CHorizontalSlider");

	style =  k3DIn | kCheckStyle;
	COptionMenu *cOptionMenu2 = new COptionMenu (size, this, kOptionMenuTag, bgKnob, 0, style);
	if (cOptionMenu2)
	{
		cOptionMenu2->setFont (kNormalFont);
		cOptionMenu2->setFontColor (kWhiteCColor);
		cOptionMenu2->setBackColor (kRedCColor);
		cOptionMenu2->setFrameColor (kWhiteCColor);
		cOptionMenu2->setHoriAlign (kLeftText);
		int i;
		for (i = 0; i < 3; i++)
		{
			char txt[256];
			sprintf (txt, "Entry %d", i);
			cOptionMenu2->addEntry (txt);
		}
		cOptionMenu2->setAttribute (kCViewTooltipAttribute,strlen ("COptionMenu")+1,"COptionMenu");
	}

	// add this 2 control in a CViewContainer
	size (0, 0, 70, 45);
	size.offset (210, 70);
	cViewContainer = new CViewContainer (size, frame, background);
	cViewContainer->addView (cHorizontalSlider);
	cViewContainer->addView (cOptionMenu2);
	addView (cViewContainer);

	sliderHBgBitmap->forget ();


	//--CVerticalSlider--------------------------------------
	CBitmap *sliderVBgBitmap = new CBitmap (kSliderVBgBitmap);

	size (0, 0, sliderVBgBitmap->getWidth (), sliderVBgBitmap->getHeight ());
	size.offset (280 + 30, 70 + 5);
#if 1
	point (0, 0);
	cVerticalSlider = new CVerticalSlider (size, this, kSliderVTag, size.top + 2, size.top + sliderVBgBitmap->getHeight () - sliderHandleBitmap->getHeight () - 1, sliderHandleBitmap, sliderVBgBitmap, point, kBottom);
	point (2, 0);
	cVerticalSlider->setOffsetHandle (point);
#else
	point (0, 0);
	CPoint handleOffset (2, 2);
	cVerticalSlider = new CVerticalSlider (size, this, kSliderVTag, handleOffset, 
		size.height () - 2 * handleOffset.v, sliderHandleBitmap, sliderVBgBitmap, point, kBottom);
#endif
	cVerticalSlider->setFreeClick (false);
	addView (cVerticalSlider);
	cVerticalSlider->setAttribute (kCViewTooltipAttribute,strlen ("CVerticalSlider")+1,"CVerticalSlider");

	sliderVBgBitmap->forget ();
	sliderHandleBitmap->forget ();


	//--CTextEdit--------------------------------------
	size (0, 0, 50, 12);
	size.offset (350 + 10, 70 + 30);
	cTextEdit = new CTextEdit (size, this, kTextEditTag, 0, 0, k3DIn|kDoubleClickStyle);
	if (cTextEdit)
	{
		cTextEdit->setFont (kNormalFontVerySmall);
		cTextEdit->setFontColor (kWhiteCColor);
		cTextEdit->setBackColor (kBlackCColor);
		cTextEdit->setFrameColor (kWhiteCColor);
		cTextEdit->setHoriAlign (kCenterText);
		addView (cTextEdit);
		cTextEdit->setAttribute (kCViewTooltipAttribute,strlen ("CTextEdit")+1,"CTextEdit");
	}

	//--CSplashScreen--------------------------------------
	CBitmap *splashBitmap = new CBitmap (kSplashBitmap);

	size (0, 0, 70, 70);
	size.offset (0, 140);
	point (0, 0);
	CRect toDisplay (0, 0, splashBitmap->getWidth (), splashBitmap->getHeight ());
	toDisplay.offset (100, 50);

	cSplashScreen = new CSplashScreen (size, this, kAbout, splashBitmap, toDisplay, point);
	addView (cSplashScreen);
	splashBitmap->forget ();
	cSplashScreen->setAttribute (kCViewTooltipAttribute,strlen ("CSplashScreen")+1,"CSplashScreen");


	//--CMovieBitmap--------------------------------------
  	CBitmap *movieBitmap = new CBitmap (kMovieBitmap);

	size (0, 0, movieBitmap->getWidth (), movieBitmap->getHeight () / 10);
	size.offset (70 + 15, 140 + 15);
	point (0, 0);	
	cMovieBitmap = new CMovieBitmap (size, this, kMovieBitmapTag, 10, movieBitmap->getHeight () / 10, movieBitmap, point);
	addView (cMovieBitmap);
	cMovieBitmap->setAttribute (kCViewTooltipAttribute,strlen ("CMovieBitmap")+1,"CMovieBitmap");


	//--CAutoAnimation--------------------------------------
	size (0, 0, movieBitmap->getWidth (), movieBitmap->getHeight () / 10);
	size.offset (140 + 15, 140 + 15);
	point (0, 0);
	cAutoAnimation = new CAutoAnimation (size, this, kAutoAnimationTag, 10, movieBitmap->getHeight () / 10, movieBitmap, point);
	addView (cAutoAnimation);
	movieBitmap->forget ();
	cAutoAnimation->setAttribute (kCViewTooltipAttribute,strlen ("CAutoAnimation")+1,"CAutoAnimation");


	//--CSpecialDigit--------------------------------------
	CBitmap *specialDigitBitmap = new CBitmap (kDigitBitmap);

 	size (0, 0, specialDigitBitmap->getWidth () * 7, specialDigitBitmap->getHeight () / 10);
	size.offset (210 + 10, 140 + 30);

	cSpecialDigit = new CSpecialDigit (size, this, kDigitTag, 0, 7, 0, 0, specialDigitBitmap->getWidth (), specialDigitBitmap->getHeight () / 10 , specialDigitBitmap);
	addView (cSpecialDigit);
	specialDigitBitmap->forget ();
	cSpecialDigit->setAttribute (kCViewTooltipAttribute,strlen ("CSpecialDigit")+1,"CSpecialDigit");


	//--CParamDisplay--------------------------------------
	size (0, 0, 50, 15);
	size.offset (280 + 10, 140 + 30);
	cParamDisplay = new CParamDisplay (size);
	if (cParamDisplay)
	{
		cParamDisplay->setFont (kNormalFontSmall);
		cParamDisplay->setFontColor (kWhiteCColor);
		cParamDisplay->setBackColor (kBlackCColor);
		addView (cParamDisplay);
		cParamDisplay->setAttribute (kCViewTooltipAttribute,strlen ("CParamDisplay")+1,"CParamDisplay");
	}


	//--CVuMeter--------------------------------------
	CBitmap* vuOnBitmap  = new CBitmap (kVuOnBitmap);
	CBitmap* vuOffBitmap = new CBitmap (kVuOffBitmap);

	size (0, 0, vuOnBitmap->getWidth (), vuOnBitmap->getHeight ());
	size.offset (350 + 30, 140 + 5);
	cVuMeter = new CVuMeter (size, vuOnBitmap, vuOffBitmap, 14);
	cVuMeter->setDecreaseStepValue (0.1f);
	addView (cVuMeter);
	vuOnBitmap->forget ();
	vuOffBitmap->forget ();
	cVuMeter->setAttribute (kCViewTooltipAttribute,strlen ("CVuMeter")+1,"CVuMeter");

	//--My controls---------------------------------
	//--CLabel--------------------------------------
	size (0, 0, 349, 14);
	size.offset (0, 140);
	cLabel = new CLabel (size, "Type a Key or Drop a file...");
	if (cLabel)
	{
		cLabel->setFont (kNormalFontSmall);
		cLabel->setFontColor (kWhiteCColor);
		cLabel->setBackColor (kGreyCColor);
		addView (cLabel);
		cLabel->setAttribute (kCViewTooltipAttribute,strlen ("CLabel")+1,"CLabel");
	}

	//--CLabel--------------------------------------
	size (0, 0, 65, 12);
	size.offset (1, 40);
	CLabel *cLabel2 = new CLabel (size, "FileSelector");
	if (cLabel2)
	{
		cLabel2->setFont (kNormalFontSmaller);
		cLabel2->setFontColor (kWhiteCColor);
		cLabel2->setBackColor (kGreyCColor);
		addView (cLabel2);
		cLabel2->setAttribute (kCViewTooltipAttribute,strlen ("CLabel")+1,"CLabel");
	}
	
	size (inSize.right, inSize.bottom, inSize.right + 100, inSize.bottom + 100);
	CLabel* outsideLabel = new CLabel (size, "This label is outside its superview");
	addView (outsideLabel);
	outsideLabel->setDirty (true);
	outsideLabel->setAttribute (kCViewTooltipAttribute,strlen ("outsideLabel")+1,"outsideLabel");
}

bool ControlsGUI::attached (CView* view)
{
	if (animTimer)
		animTimer->start ();
	return CViewContainer::attached (view);
}

bool ControlsGUI::removed (CView* parent)
{
	if (animTimer)
	{
		animTimer->stop();
	}
	return CViewContainer::removed (parent);
}

CMessageResult ControlsGUI::notify (CBaseObject* sender, const char* message)
{
	if (message == CVSTGUITimer::kMsgTimer)
	{
		cAutoAnimation->nextPixmap ();
		cAutoAnimation->invalid ();
		return kMessageNotified;
	}
	return CViewContainer::notify (sender, message);
}

void ControlsGUI::valueChanged (CControl *pControl)
{
	// this is only to provide the same behaviour as the original controlsgui editor class in the vst sdk 2.3
	// do not take this as an example on how to code !!!

	float value = pControl->getValue ();
	switch (pControl->getTag ())
	{
		case kSliderVTag:
		case kSliderHTag:
		case kKnobTag:
		case kAnimKnobTag:
		{
			cHorizontalSlider->setValue (value);
			cVerticalSlider->setValue (value);
			cKnob->setValue (value);
			cAnimKnob->setValue (value);
			cSpecialDigit->setValue (1000000 * value);
			cParamDisplay->setValue (value);
			cVuMeter->setValue (value);
			cMovieBitmap->setValue (value);
			break;
		}
		case kAutoAnimationTag:
		{
			if (animTimer)
			{
				delete animTimer;
				animTimer = 0;
			}
			else
			{
				animTimer = new CVSTGUITimer (this, 10);
				animTimer->start ();
			}
			break;
		}
		case kOnOffTag:
		{
			if (value > 0.5f)
			{
				VstFileType aiffType ("AIFF File", "AIFF", "aif", "aiff", "audio/aiff", "audio/x-aiff");
				VstFileType aifcType ("AIFC File", "AIFC", "aif", "aifc", "audio/x-aifc");
				VstFileType waveType ("Wave File", "WAVE", "wav", "wav",  "audio/wav", "audio/x-wav");
				VstFileType sdIIType ("SoundDesigner II File", "Sd2f", "sd2", "sd2");
				VstFileType types[] = {aiffType, aifcType, waveType, sdIIType};

				VstFileSelect vstFileSelect;
				memset (&vstFileSelect, 0, sizeof (VstFileSelect));

				vstFileSelect.command     = kVstFileLoad;
				vstFileSelect.type        = kVstFileType;
				strcpy (vstFileSelect.title, "Test for open file selector");
				vstFileSelect.nbFileTypes = 4;
				vstFileSelect.fileTypes   = (VstFileType*)&types;
				vstFileSelect.returnPath  = new char[1024];
				vstFileSelect.initialPath = 0;
				vstFileSelect.future[0] = 1;	// utf-8 path on macosx
				CFileSelector selector (NULL);
				if (selector.run (&vstFileSelect))
				{
					if (cLabel)
						cLabel->setText (vstFileSelect.returnPath);
				}
				else
				{
					if (cLabel)
						cLabel->setText ("OpenFileSelector: canceled!!!!");
				}
				delete []vstFileSelect.returnPath;
				if (vstFileSelect.initialPath)
					delete []vstFileSelect.initialPath;
			}
			break;
		}
	}
}