//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/auwrapper/auresource.r
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

#include <AudioUnit/AudioUnit.r>
#include <AudioUnit/AudioUnitCarbonView.r>

#include "audiounitconfig.h"
/*	----------------------------------------------------------------------------------------------------------------------------------------
//	audiounitconfig.h needs the following definitions:
	#define kAudioUnitVersion			0xFFFFFFFF							// Version Number, needs to be in hex
	#define kAudioUnitName				"Steinberg: MyVST3 as AudioUnit"	// Company Name + Effect Name
	#define kAudioUnitDescription		"My VST3 as AudioUnit"				// Effect Description
	#define kAudioUnitType				kAudioUnitType_Effect				// can be kAudioUnitType_Effect or kAudioUnitType_MusicDevice
	#define kAudioUnitComponentSubType	'test'								// unique id
	#define kAudioUnitComponentManuf	'SMTG'								// registered company id
	#define kAudioUnitCarbonView		1									// if 0 no Carbon view support will be added
*/


#define kAudioUnitResID_Processor				1000
#define kAudioUnitResID_CarbonView				9000

//----------------------Processor----------------------------------------------

#define RES_ID			kAudioUnitResID_Processor
#define COMP_TYPE		kAudioUnitType
#define COMP_SUBTYPE	kAudioUnitComponentSubType
#define COMP_MANUF		kAudioUnitComponentManuf	

#define VERSION			kAudioUnitVersion
#define NAME			kAudioUnitName
#define DESCRIPTION		kAudioUnitDescription
#define ENTRY_POINT		"AUWrapperEntry"

#include "AUResources.r"

#if kAudioUnitCarbonView
//----------------------View----------------------------------------------

#define RES_ID			kAudioUnitResID_CarbonView
#define COMP_TYPE		kAudioUnitCarbonViewComponentType
#define COMP_SUBTYPE	kAudioUnitComponentSubType
#define COMP_MANUF		kAudioUnitComponentManuf	

#define VERSION			kAudioUnitVersion
#define NAME			"CarbonView"
#define DESCRIPTION		"CarbonView"
#define ENTRY_POINT		"AUCarbonViewEntry"

#include "AUResources.r"

#endif
