//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/mda-vst3/source/version.h
// Created by  : Steinberg, 06/2008
// Description : Example of handle the versionning and copyright info of mda-vst3 Plug-ins
//				 used for the resources (RC file for example)
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

#ifndef __version__
#define __version__

#define MAJOR_VERSION_STR "1"
#define MAJOR_VERSION_INT 1

#define SUB_VERSION_STR "0"
#define SUB_VERSION_INT 0

#define RELEASE_NUMBER_STR "0"
#define RELEASE_NUMBER_INT 0

#define BUILD_NUMBER_STR "1"
#define BUILD_NUMBER_INT 1

#define FULL_VERSION_STR "1.0.0"
#define VERSION_STR  FULL_VERSION_STR

#define stringPluginName "mda"
#define stringOriginalFilename stringPluginName".vst3"

#if PLATFORM_64
#define stringFileDescription	"VST3 version of MDA Plug-ins (64Bit)"
#else
#define stringFileDescription	"VST3 version of MDA Plug-ins"
#endif
#define stringCompanyName		"mda"
#define stringLegalCopyright	"© 2015 Steinberg Media Technologies"
#define stringLegalTrademarks	"VST is a trademark of Steinberg Media Technologies GmbH"

#endif //__version__
