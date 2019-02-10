//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 2.4
//
// Category    : VST 2.x Classes
// Filename    : public.sdk/source/vst2.x/aeffeditor.h
// Created by  : Steinberg, 01/2004
// Description : Editor Class for VST Plug-Ins
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

#pragma once

#include "audioeffectx.h"

//-------------------------------------------------------------------------------------------------------
/** VST Effect Editor class. */
//-------------------------------------------------------------------------------------------------------
class AEffEditor
{
public:
//-------------------------------------------------------------------------------------------------------
	AEffEditor (AudioEffect* effect = 0)	///< Editor class constructor. Requires pointer to associated effect instance.
	: effect (effect)
	, systemWindow (0)
	{}

	virtual ~AEffEditor () ///< Editor class destructor.
	{}

	virtual AudioEffect* getEffect ()	{ return effect; }					///< Returns associated effect instance
	virtual bool getRect (ERect** rect)	{ *rect = 0; return false; }		///< Query editor size as #ERect
	virtual bool open (void* ptr)		{ systemWindow = ptr; return 0; }	///< Open editor, pointer to parent windows is platform-dependent (HWND on Windows, WindowRef on Mac).
	virtual void close ()				{ systemWindow = 0; }				///< Close editor (detach from parent window)
	virtual bool isOpen ()				{ return systemWindow != 0; }		///< Returns true if editor is currently open
	virtual void idle ()				{}									///< Idle call supplied by Host application

#if TARGET_API_MAC_CARBON
	virtual void DECLARE_VST_DEPRECATED (draw) (ERect* rect) {}
	virtual VstInt32 DECLARE_VST_DEPRECATED (mouse) (VstInt32 x, VstInt32 y) { return 0; }
	virtual VstInt32 DECLARE_VST_DEPRECATED (key) (VstInt32 keyCode) { return 0; }
	virtual void DECLARE_VST_DEPRECATED (top) () {}
	virtual void DECLARE_VST_DEPRECATED (sleep) () {}
#endif

#if VST_2_1_EXTENSIONS
	virtual bool onKeyDown (VstKeyCode& keyCode)	{ return false; }		///< Receive key down event. Return true only if key was really used!
	virtual bool onKeyUp (VstKeyCode& keyCode)		{ return false; }		///< Receive key up event. Return true only if key was really used!
	virtual bool onWheel (float distance)			{ return false; }		///< Handle mouse wheel event, distance is positive or negative to indicate wheel direction.
	virtual bool setKnobMode (VstInt32 val)			{ return false; }		///< Set knob mode (if supported by Host). See CKnobMode in VSTGUI.
#endif

//-------------------------------------------------------------------------------------------------------
protected:
	AudioEffect* effect;	///< associated effect instance
	void* systemWindow;		///< platform-dependent parent window (HWND or WindowRef)
};
