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

#include "pdrawtesteffect.h"

#if VST_2_4_EXTENSIONS

AudioEffect* createEffectInstance (audioMasterCallback audioMaster)
{
	return new DrawTestEffect (audioMaster);
}

#else

bool oome = false;

#if MAC
#pragma export on
#endif

//------------------------------------------------------------------------
// Prototype of the export function main
//------------------------------------------------------------------------
#if BEOS
#define main main_plugin
extern "C" __declspec(dllexport) AEffect *main_plugin (audioMasterCallback audioMaster);

#elif MACX
#define main main_macho
extern "C" AEffect *main_macho (audioMasterCallback audioMaster);

#else
AEffect *main (audioMasterCallback audioMaster);
#endif

//------------------------------------------------------------------------
AEffect *main (audioMasterCallback audioMaster)
{
	// Get VST Version
	if (!audioMaster (0, audioMasterVersion, 0, 0, 0, 0))
		return 0;  // old version

	// Create the AudioEffect
	DrawTestEffect* effect = new DrawTestEffect (audioMaster);
	if (!effect)
		return 0;

	// Check if no problem in constructor of AGain
	if (oome)
	{
		delete effect;
		return 0;
	}
	return effect->getAeffect ();
}

#if MAC
#pragma export off
#endif


#if WIN32
#include <windows.h>
void* hInstance;
BOOL WINAPI DllMain (HINSTANCE hInst, DWORD dwReason, LPVOID lpvReserved)
{
	hInstance = hInst;
	return 1;
}
#endif

#endif // VST_2_4_EXTENSIONS
