//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/multiplugsupport/source/plugcids.h
// Created by  : Steinberg, 12/2007
// Description : define the class IDs for multiplugsupport
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

#pragma once

namespace Steinberg {
namespace Vst {

#if PLUGIN_A
	// Plug A
	static const FUID PlugProcessorUID (0x8F2B1ED9, 0x1D2C40E0, 0xB60F4AF2, 0x0F27711F);
	static const FUID PlugControllerUID (0x001B3315, 0x818044BE, 0x8FBF4AA2, 0xC9993C47);
#else
	// Plug B
	static const FUID PlugProcessorUID (0x1E4DC62B, 0x974147D6, 0x9CAB1B86, 0x50D4B11C);
	static const FUID PlugControllerUID (0xA8D238C1, 0x97F54908, 0xB32EB808, 0x3EA43CEC);

	// Plug B will support Plug A (could replace it when Plug B not present)
	static const FUID PlugAProcessorUID (0x8F2B1ED9, 0x1D2C40E0, 0xB60F4AF2, 0x0F27711F);

	static const FUID PluginCompatibilityUID (0x7A8EA518, 0xECA24036, 0x9AD492D1, 0x70AD04FA);
#endif

}} // namespaces
