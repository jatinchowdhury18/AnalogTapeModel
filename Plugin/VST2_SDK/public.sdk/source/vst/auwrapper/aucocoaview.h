//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/auwrapper/aucocoaview.h
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

/// \cond ignore

#pragma once

#import "aucocoaclassprefix.h"

#import <Cocoa/Cocoa.h>
#import <AudioUnit/AUCocoaUIView.h>

#ifndef SMTG_AU_NAMESPACE
# error define SMTG_AU_NAMESPACE
#endif

//-----------------------------------------------------------------------------
#define SMTG_AU_PLUGIN_NAMESPACE0(x) x
#define SMTG_AU_PLUGIN_NAMESPACE1(a, b) a##_##b
#define SMTG_AU_PLUGIN_NAMESPACE2(a, b) SMTG_AU_PLUGIN_NAMESPACE1(a,b)
#define SMTG_AU_PLUGIN_NAMESPACE(name) SMTG_AU_PLUGIN_NAMESPACE2(SMTG_AU_PLUGIN_NAMESPACE0(name), SMTG_AU_PLUGIN_NAMESPACE0(SMTG_AU_NAMESPACE))

//-----------------------------------------------------------------------------
// SMTG_AU_PLUGIN_NAMESPACE (SMTGAUPluginCocoaView)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
@interface SMTG_AU_PLUGIN_NAMESPACE (SMTGAUPluginCocoaView) : NSObject <AUCocoaUIBase>
{
}

//-----------------------------------------------------------------------------
@end

/// \endcond
