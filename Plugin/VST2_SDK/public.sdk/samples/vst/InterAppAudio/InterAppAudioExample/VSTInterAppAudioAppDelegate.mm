//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/interappaudio/InterAppAudioExample/VSTInterAppAudioAppDelegate.mm
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

#import "VSTInterAppAudioAppDelegate.h"
#import "VSTInterAppAudioHostUIControllerViewController.h"
#import "public.sdk/source/vst/interappaudio/AudioIO.h"

using namespace Steinberg::Vst::InterAppAudio;

//------------------------------------------------------------------------
@interface VSTInterAppAudioAppDelegate ()
//------------------------------------------------------------------------
{
	UIButton* showHostView;
}
@end

//------------------------------------------------------------------------
@implementation VSTInterAppAudioAppDelegate
//------------------------------------------------------------------------

//------------------------------------------------------------------------
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	if ([super application:application didFinishLaunchingWithOptions:launchOptions])
	{
		[self performSelector:@selector(createShowHostViewButton) withObject:nil afterDelay:0.2];
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(audioIOConnectionChanged) name:AudioIO::kConnectionStateChange object:nil];
		return YES;
	}
    return NO;
}

//------------------------------------------------------------------------
- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
	return UIInterfaceOrientationMaskLandscapeLeft|UIInterfaceOrientationMaskLandscapeRight;
}

//------------------------------------------------------------------------
- (void)audioIOConnectionChanged
{
	showHostView.hidden = AudioIO::instance ()->getInterAppAudioConnected () == false;
	if (showHostView.hidden)
	{
		for (id childController in [self.window.rootViewController childViewControllers])
		{
			if ([childController isKindOfClass:[VSTInterAppAudioHostUIControllerViewController class]])
			{
				[childController hideView:self];
			}
		}
	}
}

//------------------------------------------------------------------------
- (void)createShowHostViewButton
{
	showHostView = [UIButton buttonWithType:UIButtonTypeInfoDark];
	[showHostView addTarget:self action:@selector(showHostViewAction:) forControlEvents:UIControlEventTouchDown];
	
	const CGFloat margin = 15;
	CGRect frame = showHostView.frame;
	frame.origin.y = [self.window.rootViewController.view bounds].size.height - (frame.size.height + margin);
	frame.origin.x = margin;
	showHostView.frame = frame;
	
	[self.window.rootViewController.view addSubview:showHostView];
	
	if (AudioIO::instance ()->getInterAppAudioConnected () == false)
	{
		showHostView.hidden = YES;
	}
}

//------------------------------------------------------------------------
- (void)showHostViewAction:(id)sender
{
	VSTInterAppAudioHostUIControllerViewController* controller = [[VSTInterAppAudioHostUIControllerViewController alloc] init];
	[self.window.rootViewController addChildViewController:controller];
	CGRect frame = controller.view.frame;
	frame.origin.y = [self.window.rootViewController.view bounds].size.height;
	controller.view.frame = frame;

	[self.window.rootViewController.view addSubview:controller.view];

	frame.origin.y = [self.window.rootViewController.view bounds].size.height - frame.size.height;

	[UIView animateWithDuration:0.3 animations:^{
		controller.view.frame = frame;
	}];
}

@end
