//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/interappaudio/HostApp.mm
// Created by  : Steinberg, 08/2013.
// Description : VST 3 InterAppAudio
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
//-----------------------------------------------------------------------------

#import "HostApp.h"
#import "AudioIO.h"
#import "VST3Plugin.h"
#import "PresetManager.h"
#import "SettingsViewController.h"
#import "base/source/updatehandler.h"
#import "pluginterfaces/gui/iplugview.h"

namespace Steinberg {
namespace Vst {
namespace InterAppAudio {

//------------------------------------------------------------------------
InterAppAudioHostApp* InterAppAudioHostApp::instance ()
{
	static InterAppAudioHostApp gInstance;
	return &gInstance;
}

//-----------------------------------------------------------------------------
InterAppAudioHostApp::InterAppAudioHostApp ()
: plugin (0)
{
}

//-----------------------------------------------------------------------------
void InterAppAudioHostApp::setPlugin (VST3Plugin* plugin)
{
	this->plugin = plugin;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::getName (String128 name)
{
	String str ("InterAppAudioHost");
	str.copyTo (name, 0, 127);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::getScreenSize (ViewRect* size, float* scale)
{
	if (size)
	{
		UIScreen* screen = [UIScreen mainScreen];
		CGSize s = [screen currentMode].size;
		UIWindow* window = [[[UIApplication sharedApplication] windows] objectAtIndex:0];
		if (window)
		{
			NSArray* subViews = [window subviews];
			if ([subViews count] == 1)
			{
				s = [[[window subviews] objectAtIndex:0] bounds].size;
			}
		}
		size->left = 0;
		size->top = 0;
		size->right = s.width;
		size->bottom = s.height;
		if (scale)
		{
			*scale = screen.scale;
		}
		return kResultTrue;
	}
	return kInvalidArgument;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::connectedToHost ()
{
	return AudioIO::instance ()->getInterAppAudioConnected () ? kResultTrue : kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::switchToHost ()
{
	return AudioIO::instance ()->switchToHost () ? kResultTrue : kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::sendRemoteControlEvent (uint32 event)
{
	return AudioIO::instance ()->sendRemoteControlEvent (event) ? kResultTrue : kResultFalse;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::getHostIcon (void** icon)
{
	if (icon)
	{
		UIImage* hostIcon = AudioIO::instance ()->getHostIcon ();
		if (hostIcon)
		{
			CGImageRef cgImage = [hostIcon CGImage];
			if (cgImage)
			{
				*icon = cgImage;
				return kResultTrue;
			}
		}
		return kNotImplemented;
	}
	return kInvalidArgument;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::scheduleEventFromUI (Event& event)
{
	if (plugin)
	{
		return plugin->scheduleEventFromUI (event);
	}
	return kNotInitialized;
}

//-----------------------------------------------------------------------------
IInterAppAudioPresetManager* PLUGIN_API InterAppAudioHostApp::createPresetManager (const TUID& cid)
{
	return plugin ? new PresetManager (plugin, cid) : nullptr;
}

//-----------------------------------------------------------------------------
tresult PLUGIN_API InterAppAudioHostApp::showSettingsView ()
{
	showIOSettings ();
	return kResultTrue;
}

}}}
