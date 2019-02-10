//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/prefetchablesupport/source/plugentry.cpp
// Created by  : Steinberg, 04/2015
// Description : prefetchablesupport Example for VST 3
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


#include "plug.h"
#include "plugcontroller.h"
#include "plugcids.h"	// for class ids
#include "version.h"	// for versioning

#include "public.sdk/source/main/pluginfactoryvst3.h"

#define stringPluginName "Test Prefetchable Support"

//------------------------------------------------------------------------
//  Module init/exit
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// called after library was loaded
bool InitModule ()   
{
	return true; 
}

//------------------------------------------------------------------------
// called after library is unloaded
bool DeinitModule ()
{
	return true; 
}

using namespace Steinberg;
using namespace Steinberg::Vst;


//------------------------------------------------------------------------
//  VST Plug-in Entry
//------------------------------------------------------------------------
// Windows: do not forget to include a .def file in your project to export
// GetPluginFactory function!
//------------------------------------------------------------------------

BEGIN_FACTORY_DEF ("Steinberg Media Technologies", 
			   "http://www.steinberg.net", 
			   "mailto:info@steinberg.de")

	//---First Plug-in included in this factory-------
	// its kVstAudioEffectClass component
	DEF_CLASS2 (INLINE_UID_FROM_FUID(PlugProcessorUID),
				PClassInfo::kManyInstances,	// cardinality  
				kVstAudioEffectClass,		// the component category (dont changed this)
				stringPluginName,			// here the Plug-in name (to be changed)
				Vst::kDistributable,	// means that component and controller could be distributed on different computers
				"Fx",					// Subcategory for this Plug-in (to be changed)
				FULL_VERSION_STR,		// Plug-in version (to be changed)
				kVstVersionString,		// the VST 3 SDK version (dont changed this, use always this define)
				Steinberg::Vst::Plug::createInstance)	// function pointer called when this component should be instanciated

	// its kVstComponentControllerClass component
	DEF_CLASS2 (INLINE_UID_FROM_FUID (PlugControllerUID),
				PClassInfo::kManyInstances,  // cardinality   
				kVstComponentControllerClass,// the Controller category (dont changed this)
				stringPluginName "Controller",	// controller name (could be the same than component name)
				0,						// not used here
				"",						// not used here
				FULL_VERSION_STR,		// Plug-in version (to be changed)
				kVstVersionString,		// the VST 3 SDK version (dont changed this, use always this define)
				Steinberg::Vst::PlugController::createInstance)// function pointer called when this component should be instanciated
END_FACTORY
