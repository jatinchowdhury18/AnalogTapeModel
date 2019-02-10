//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.0
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/adelay/source/interappaudio/iosEditor.mm
// Created by  : Steinberg, 08/2013
// Description :
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2014, Steinberg Media Technologies GmbH, All Rights Reserved
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
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#import "iosEditor.h"
#import "public.sdk/source/vst/vsteditcontroller.h"
#import "adelayids.h"

using namespace Steinberg::Vst;

//------------------------------------------------------------------------
@interface ADelayViewController : UIViewController
{
	EditController* editController;
}
@property (assign) IBOutlet UISlider* slider;

@end

//------------------------------------------------------------------------
@implementation ADelayViewController

//------------------------------------------------------------------------
- (id)initWithVstEditController:(EditController*)_editController
{
	self = [super initWithNibName:@"ADelayIPAD" bundle:nil];
	if (self)
	{
		editController = _editController;
	}
	return self;
}

//------------------------------------------------------------------------
- (void)updateSlider
{
	[self.slider setValue:editController->getParamNormalized (kDelayId)];
}

//------------------------------------------------------------------------
- (IBAction)sliderChanged:(id)sender
{
	editController->setParamNormalized (kDelayId, self.slider.value);
	editController->performEdit(kDelayId, self.slider.value);
}

@end


namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
ADelayEditorForIOS::ADelayEditorForIOS (EditController* editController)
: editController (editController)
, viewController (nil)
{
	
}

//------------------------------------------------------------------------
void PLUGIN_API ADelayEditorForIOS::update (FUnknown* changedUnknown, int32 message)
{
	Parameter* param = FCast<Parameter> (changedUnknown);
	if (param && viewController)
	{
		[viewController updateSlider];
	}
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::isPlatformTypeSupported (FIDString type)
{
	if (strcmp (type, kPlatformTypeUIView) == 0)
		return kResultTrue;

	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::attached (void* parent, FIDString type)
{
	if (strcmp (type, kPlatformTypeUIView) != 0)
		return kResultFalse;
	
	UIView* parentView = (__bridge UIView*)parent;
	
	viewController = [[ADelayViewController alloc] initWithVstEditController:editController];
	if (viewController && viewController.view)
	{
		[parentView addSubview:viewController.view];
		
		[viewController updateSlider];
		Parameter* delayParam = editController->getParameterObject (kDelayId);
		if (delayParam)
		{
			delayParam->addDependent (this);
		}
	}
	
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::removed ()
{
	[viewController.view removeFromSuperview];
	Parameter* delayParam = editController->getParameterObject (kDelayId);
	if (delayParam)
	{
		delayParam->removeDependent (this);
	}
	viewController = nil;
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::onWheel (float distance)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::onKeyDown (char16 key, int16 keyCode, int16 modifiers)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::onKeyUp (char16 key, int16 keyCode, int16 modifiers)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::getSize (ViewRect* size)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::onSize (ViewRect* newSize)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::onFocus (TBool state)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::setFrame (IPlugFrame* frame)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::canResize ()
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ADelayEditorForIOS::checkSizeConstraint (ViewRect* rect)
{
	return kNotImplemented;
}

}}
