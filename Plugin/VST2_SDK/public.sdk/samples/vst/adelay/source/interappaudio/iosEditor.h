//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.0
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/adelay/source/interappaudio/iosEditor.h
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

#ifndef __iosEditor__
#define __iosEditor__

#include "base/source/fobject.h"
#include "pluginterfaces/gui/iplugview.h"

#if __OBJC__
@class ADelayViewController;
#else
struct ADelayViewController;
#endif

namespace Steinberg {
namespace Vst {
class EditController;

class ADelayEditorForIOS : public FObject, public IPlugView
{
public:
	ADelayEditorForIOS (EditController* editController);

	OBJ_METHODS(ADelayEditorForIOS, FObject)
	REFCOUNT_METHODS(FObject)
	DEFINE_INTERFACES
		DEF_INTERFACE(IPlugView)
	END_DEFINE_INTERFACES(FObject)
protected:
	tresult PLUGIN_API isPlatformTypeSupported (FIDString type) override;
	tresult PLUGIN_API attached (void* parent, FIDString type) override;
	tresult PLUGIN_API removed () override;
	tresult PLUGIN_API onWheel (float distance) override;
	tresult PLUGIN_API onKeyDown (char16 key, int16 keyCode, int16 modifiers) override;
	tresult PLUGIN_API onKeyUp (char16 key, int16 keyCode, int16 modifiers) override;
	tresult PLUGIN_API getSize (ViewRect* size) override;
	tresult PLUGIN_API onSize (ViewRect* newSize) override;
	tresult PLUGIN_API onFocus (TBool state) override;
	tresult PLUGIN_API setFrame (IPlugFrame* frame) override;
	tresult PLUGIN_API canResize () override;
	tresult PLUGIN_API checkSizeConstraint (ViewRect* rect) override;

	void PLUGIN_API update (FUnknown* changedUnknown, int32 message) override;

	EditController* editController;
	ADelayViewController* viewController;
};

}}

#endif // __iosEditor__
