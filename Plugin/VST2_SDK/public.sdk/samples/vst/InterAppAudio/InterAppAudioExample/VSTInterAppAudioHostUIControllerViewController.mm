//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/interappaudio/InterAppAudioExample/VSTInterAppAudioHostUIControllerViewController.mm
// Created by  : Steinberg, 08/2013
// Description :
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
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

#import "VSTInterAppAudioHostUIControllerViewController.h"
#import "public.sdk/source/vst/interappaudio/AudioIO.h"

using namespace Steinberg::Vst::InterAppAudio;

//------------------------------------------------------------------------
static UIImage *scaleImageToSize (UIImage *image, CGSize newSize)
{
    UIGraphicsBeginImageContextWithOptions (newSize, NO, 0.0);
    [image drawInRect:CGRectMake (0, 0, newSize.width, newSize.height)];
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext ();
    UIGraphicsEndImageContext ();
	
    return newImage;
}

//------------------------------------------------------------------------
@interface VSTInterAppAudioHostUIControllerViewController ()
//------------------------------------------------------------------------
@property (assign) IBOutlet UIButton* hostButton;

@end

//------------------------------------------------------------------------
@implementation VSTInterAppAudioHostUIControllerViewController
//------------------------------------------------------------------------

//------------------------------------------------------------------------
- (id)init
{
    self = [super initWithNibName:@"VSTInterAppAudioHostUIControllerView" bundle:nil];
    if (self) {
    }
    return self;
}

//------------------------------------------------------------------------
- (void)viewDidLoad
{
    [super viewDidLoad];

	UIImage* image = AudioIO::instance ()->getHostIcon ();
	if (image)
	{
		image = scaleImageToSize(image, self.hostButton.bounds.size);
		[self.hostButton setTitle:@"" forState:UIControlStateNormal];
		[self.hostButton setImage:image forState:UIControlStateNormal];
	}

	self.view.layer.shadowColor = [[UIColor blackColor] CGColor];
	self.view.layer.shadowOpacity = 0.5;
	self.view.layer.shadowRadius = 5;
	self.view.layer.shadowOffset = CGSizeMake (5, -5);
}

//------------------------------------------------------------------------
- (IBAction)hideView:(id)sender
{
	[UIView animateWithDuration:0.3 animations:^{
		CGRect frame = self.view.frame;
		frame.origin.y += frame.size.height;
		self.view.frame = frame;
	} completion:^(BOOL finished) {
		[self.view removeFromSuperview];
		[self removeFromParentViewController];
	}];
}

//------------------------------------------------------------------------
- (IBAction)switchToHost:(id)sender
{
	AudioIO::instance ()->switchToHost ();
}

//------------------------------------------------------------------------
- (IBAction)play:(id)sender
{
	AudioIO::instance ()->sendRemoteControlEvent (kAudioUnitRemoteControlEvent_TogglePlayPause);
}

//------------------------------------------------------------------------
- (IBAction)rewind:(id)sender
{
	AudioIO::instance ()->sendRemoteControlEvent (kAudioUnitRemoteControlEvent_Rewind);
}

//------------------------------------------------------------------------
- (IBAction)record:(id)sender
{
	AudioIO::instance ()->sendRemoteControlEvent (kAudioUnitRemoteControlEvent_ToggleRecord);
}

@end
