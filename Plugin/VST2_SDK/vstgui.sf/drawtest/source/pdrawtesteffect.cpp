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

#if AU
#include "AUEffectBase.h"
#include "pdrawtesteditor.h"

#define kComponentSubType	'vgdt'
#define kComponentManuf		'Xxxx'
#define kVersionNumber		0x00010000

class DrawTestAU : public AUEffectBase
{
public:
	DrawTestAU (AudioUnit au)
	: AUEffectBase (au)
	{
	//	editor = new DrawTestEditor (this);
	}

	virtual ~DrawTestAU ()
	{
		//if (editor)
			//delete editor;
	}
	
	virtual int GetNumCustomUIComponents ()
	{
		return 1;
	}

	virtual ComponentResult Version () { return kVersionNumber; }

	virtual void GetUIComponentDescs (ComponentDescription* inDescArray)
	{
	    inDescArray[0].componentType = kAudioUnitCarbonViewComponentType;
	    inDescArray[0].componentSubType = kComponentSubType;
	    inDescArray[0].componentManufacturer = kComponentManuf;
	    inDescArray[0].componentFlags = 0;
	    inDescArray[0].componentFlagsMask = 0;
	}

/*	ComponentResult GetPropertyInfo (AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, UInt32 &outDataSize, Boolean &outWritable)
	{
		if (inID == 64000)
		{
			if (editor)
			{
				outDataSize = sizeof (PluginGUIEditor*);
				outWritable = false;
				return noErr;
			}
			return kAudioUnitErr_InvalidProperty;
		}
		return AUEffectBase::GetPropertyInfo (inID, inScope, inElement, outDataSize, outWritable);
	}

	ComponentResult GetProperty (AudioUnitPropertyID inID, AudioUnitScope inScope, AudioUnitElement inElement, void *outData)
	{
		if (inID == 64000)
		{
			if (editor)
			{
				long ptr = (long)editor;
				*((long*)outData) = ptr;
				return noErr;
			}
			else
				*((long*)outData) = 0;
			return kAudioUnitErr_InvalidProperty;
		}
			return AUEffectBase::GetProperty (inID, inScope, inElement, outData);
	}
*/
protected:
	DrawTestEditor* editor;
};


#include "AUCarbonViewBase.h"
#include "plugguieditor.h"

class VSTGUIAUView : public AUCarbonViewBase 
{
public:
	VSTGUIAUView (AudioUnitCarbonView auv) 
	: AUCarbonViewBase (auv)
	, editor (0)
	, xOffset (0)
	, yOffset (0)
	{
	}

	virtual ~VSTGUIAUView ()
	{
		if (editor)
		{
			editor->close ();
		}
	}
	
	void RespondToEventTimer (EventLoopTimerRef inTimer) 
	{
		if (editor)
			editor->doIdleStuff ();
	}

	virtual OSStatus CreateUI(Float32 xoffset, Float32 yoffset)
	{
		AudioUnit unit = GetEditAudioUnit ();
		if (unit)
		{
			editor = new DrawTestEditor (unit);
			WindowRef window = GetCarbonWindow ();
			editor->open (window);
			HIViewMoveBy ((HIViewRef)editor->getFrame ()->getPlatformControl (), xoffset, yoffset);
			EmbedControl ((HIViewRef)editor->getFrame ()->getPlatformControl ());
			CRect fsize = editor->getFrame ()->getViewSize (fsize);
			SizeControl (mCarbonPane, fsize.width (), fsize.height ());
			CreateEventLoopTimer (kEventDurationSecond, kEventDurationSecond / 24);
			HIViewSetVisible ((HIViewRef)editor->getFrame ()->getPlatformControl (), true);
			HIViewSetNeedsDisplay ((HIViewRef)editor->getFrame ()->getPlatformControl (), true);
		}
		return noErr;
	}

	Float32 xOffset, yOffset;
protected:
	PluginGUIEditor* editor;
};

COMPONENT_ENTRY(VSTGUIAUView);
COMPONENT_ENTRY(DrawTestAU);


#else
#include "pdrawtesteffect.h"
#include "pdrawtesteditor.h"

DrawTestEffect::DrawTestEffect (audioMasterCallback audioMaster)
: AudioEffectX (audioMaster, 1, 0)
{
	editor = new DrawTestEditor (this);
}

DrawTestEffect::~DrawTestEffect ()
{
}

void DrawTestEffect::processReplacing (float **inputs, float **outputs, VstInt32 sampleFrames)
{
}

VstInt32 DrawTestEffect::canDo (char* text)
{
	return 0;
}

#endif
