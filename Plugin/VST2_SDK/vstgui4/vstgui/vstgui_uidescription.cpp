//-----------------------------------------------------------------------------
// VST Plug-Ins SDK
// VSTGUI: Graphical User Interface Framework for VST plugins
//
// Version 4.2
//
//-----------------------------------------------------------------------------
// VSTGUI LICENSE
// (c) 2013, Steinberg Media Technologies, All Rights Reserved
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
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#include "vstgui_uidescription.h"

#include "uidescription/uidescription.cpp"
#include "uidescription/uiviewcreator.cpp"
#include "uidescription/uiviewfactory.cpp"
#include "uidescription/uiviewswitchcontainer.cpp"
#include "uidescription/cstream.cpp"

#include "uidescription/editing/uiactions.cpp"
#include "uidescription/editing/uiattributescontroller.cpp"
#include "uidescription/editing/uibitmapscontroller.cpp"
#include "uidescription/editing/uicolorscontroller.cpp"
#include "uidescription/editing/uicrosslines.cpp"
#include "uidescription/editing/uidialogcontroller.cpp"
#include "uidescription/editing/uieditcontroller.cpp"
#include "uidescription/editing/uieditmenucontroller.cpp"
#include "uidescription/editing/uieditview.cpp"
#include "uidescription/editing/uifocussettingscontroller.cpp"
#include "uidescription/editing/uifontscontroller.cpp"
#include "uidescription/editing/uigridcontroller.cpp"
#include "uidescription/editing/uisearchtextfield.cpp"
#include "uidescription/editing/uiselection.cpp"
#include "uidescription/editing/uitagscontroller.cpp"
#include "uidescription/editing/uitemplatecontroller.cpp"
#include "uidescription/editing/uitemplatesettingscontroller.cpp"
#include "uidescription/editing/uiundomanager.cpp"
#include "uidescription/editing/uiviewcreatecontroller.cpp"

#include "uidescription/xmlparser.cpp" // needs to be last
