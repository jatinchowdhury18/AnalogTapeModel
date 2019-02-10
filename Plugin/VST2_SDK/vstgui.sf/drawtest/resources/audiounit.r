#define kComponentSubType	'vgdt'
#define kComponentManuf		'Xxxx'
#define kVersionNumber		0x00010000

#include <AudioUnit/AudioUnit.r>
#include <AudioUnit/AudioUnitCarbonView.r>

// ____________________________________________________________________________
// component resources for Audio Unit
#define RES_ID			3000
#define COMP_TYPE		kAudioUnitType_Effect
#define COMP_SUBTYPE	kComponentSubType
#define COMP_MANUF		kComponentManuf
#define VERSION			kVersionNumber
#define NAME			"VSTGUI: DrawTest"
#define DESCRIPTION		"DrawTest"
#define ENTRY_POINT		"DrawTestAUEntry"

#include "AUResources.r"


// ____________________________________________________________________________
// component resources for Audio Unit Carbon View
#define RES_ID			9000
#define COMP_TYPE		kAudioUnitCarbonViewComponentType
#define COMP_SUBTYPE	kComponentSubType
#define COMP_MANUF		kComponentManuf
#define VERSION			kVersionNumber
#define NAME			"VSTGUI AUView"
#define DESCRIPTION		"VSTGUI AUView"
#define ENTRY_POINT		"VSTGUIAUViewEntry"

#include "AUResources.r"

