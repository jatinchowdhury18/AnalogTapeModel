//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/auwrapper/aucocoaview.mm
// Created by  : Steinberg, 12/2007
// Description : VST 3 -> AU Wrapper
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

/// \cond ignore

#import "aucocoaview.h"
#import "auwrapper.h"
#import "pluginterfaces/vst/ivsteditcontroller.h"
#import "pluginterfaces/gui/iplugview.h"
#import "base/source/fobject.h"


namespace Steinberg {
DEF_CLASS_IID(IPlugFrame)

//--------------------------------------------------------------------------------------------------------------
class AUPlugFrame : public FObject, public IPlugFrame
//--------------------------------------------------------------------------------------------------------------
{
public:
	AUPlugFrame (NSView* parent) : parent (parent) {}
	tresult PLUGIN_API resizeView (IPlugView* view, ViewRect* vr)
	{
		NSRect newSize = NSMakeRect ([parent frame].origin.x, [parent frame].origin.y, vr->right - vr->left, vr->bottom - vr->top);
		[parent setFrame:newSize];
		return kResultTrue;
	}
	
	OBJ_METHODS(AUPlugFrame, FObject)
	DEF_INTERFACES_1(IPlugFrame, FObject)
	REFCOUNT_METHODS(FObject)
protected:
	NSView* parent;
};
	
} // namespace Steinberg

using namespace Steinberg;

//--------------------------------------------------------------------------------------------------------------
@interface SMTGCocoa_NSViewWrapperForAU : NSView {
//--------------------------------------------------------------------------------------------------------------
	IPlugView* plugView;
	Vst::IEditController* editController;
	AudioUnit audioUnit;
	FObject* dynlib;
	AUPlugFrame* plugFrame;
	
	BOOL isAttached;
}

- (id) initWithEditController: (Vst::IEditController*) editController audioUnit: (AudioUnit) au preferredSize: (NSSize) size;

@end

//--------------------------------------------------------------------------------------------------------------
// SMTG_AU_PLUGIN_NAMESPACE (SMTGAUPluginCocoaView)
//--------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------------
@implementation SMTG_AU_PLUGIN_NAMESPACE (SMTGAUPluginCocoaView)

//--------------------------------------------------------------------------------------------------------------
- (unsigned) interfaceVersion
{
    return 0;
}

//--------------------------------------------------------------------------------------------------------------
- (NSString *) description
{
    return @"Cocoa View";
}

//--------------------------------------------------------------------------------------------------------------
- (NSView *)uiViewForAudioUnit:(AudioUnit)inAU withSize:(NSSize)inPreferredSize
{
    Vst::IEditController* editController = 0;
    UInt32 size = sizeof (Vst::IEditController*);
    if (AudioUnitGetProperty (inAU, 64000, kAudioUnitScope_Global, 0, &editController, &size) != noErr)
        return nil;
    return [[[SMTGCocoa_NSViewWrapperForAU alloc] initWithEditController:editController audioUnit:inAU preferredSize:inPreferredSize] autorelease];
}

@end

//--------------------------------------------------------------------------------------------------------------
@implementation SMTGCocoa_NSViewWrapperForAU
//--------------------------------------------------------------------------------------------------------------
- (id) initWithEditController: (Vst::IEditController*) _editController audioUnit: (AudioUnit) au preferredSize: (NSSize) size
{
	self = [super initWithFrame: NSMakeRect (0, 0, size.width, size.height)];
	if (self)
	{
		editController = _editController;
		editController->addRef ();
		audioUnit = au;
		plugView = editController->createView (Vst::ViewType::kEditor);
		if (!plugView || plugView->isPlatformTypeSupported (kPlatformTypeNSView) != kResultTrue)
		{
			[self dealloc];
			return nil;
		}
		
		plugFrame = NEW AUPlugFrame (self);
		plugView->setFrame (plugFrame);
		
		if (plugView->attached (self, kPlatformTypeNSView) != kResultTrue)
		{
			[self dealloc];
			return nil;
		}
		ViewRect vr;
		if (plugView->getSize (&vr) == kResultTrue)
		{
			NSRect newSize = NSMakeRect (0, 0, vr.right - vr.left, vr.bottom - vr.top);
			[self setFrame:newSize];
		}

		isAttached = YES;
		UInt32 size = sizeof (FObject*);
		if (AudioUnitGetProperty (audioUnit, 64001, kAudioUnitScope_Global, 0, &dynlib, &size) == noErr)
			dynlib->addRef ();
	}
	return self;
}


//--------------------------------------------------------------------------------------------------------------
- (void) setFrame: (NSRect) newSize
{
	[super setFrame: newSize];
	ViewRect viewRect (0, 0, newSize.size.width, newSize.size.height);
	
	if (plugView)
		plugView->onSize (&viewRect);
}


//--------------------------------------------------------------------------------------------------------------
- (BOOL)isFlipped { return YES; }

//--------------------------------------------------------------------------------------------------------------
- (void)viewDidMoveToSuperview
{
	if (plugView)
	{
		if ([self superview])
		{
			if (!isAttached)
			{
				isAttached = plugView->attached (self, kPlatformTypeNSView) == kResultTrue;
			}
		}
		else
		{
			if (isAttached)
			{
				plugView->removed ();
				isAttached = NO;
			}
		}
	}
}

//--------------------------------------------------------------------------------------------------------------
- (void) dealloc
{
	if (plugView)
	{
		if (isAttached)
		{
			plugView->setFrame (0);
			plugView->removed ();
		}
		plugView->release ();
		if (plugFrame)
			plugFrame->release ();
		
		if (editController)
		{
			Steinberg::uint32 refCount= editController->addRef ();
			if (refCount == 2)
				editController->terminate ();
			
			editController->release ();
			editController->release ();
			editController = 0;
		}		
	}
	if (dynlib)
		dynlib->release ();
	[super dealloc];
}

@end

/// \endcond
