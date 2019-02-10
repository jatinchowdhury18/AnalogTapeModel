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

#include "lib/cbitmap.cpp"
#include "lib/cbitmapfilter.cpp"
#include "lib/ccolor.cpp"
#include "lib/cdatabrowser.cpp"
#include "lib/cdrawcontext.cpp"
#include "lib/cdropsource.cpp"
#include "lib/cfileselector.cpp"
#include "lib/cfont.cpp"
#include "lib/cframe.cpp"
#include "lib/cgradientview.cpp"
#include "lib/cgraphicspath.cpp"
#include "lib/clayeredviewcontainer.cpp"
#include "lib/coffscreencontext.cpp"
#include "lib/copenglview.cpp"
#include "lib/cpoint.cpp"
#include "lib/crect.cpp"
#include "lib/crowcolumnview.cpp"
#include "lib/cscrollview.cpp"
#include "lib/cshadowviewcontainer.cpp"
#include "lib/csplitview.cpp"
#include "lib/cstring.cpp"
#include "lib/ctabview.cpp"
#include "lib/ctooltipsupport.cpp"
#include "lib/cview.cpp"
#include "lib/cviewcontainer.cpp"
#include "lib/cvstguitimer.cpp"
#include "lib/vstguidebug.cpp"

#include "lib/controls/ccontrol.cpp"
#include "lib/controls/cbuttons.cpp"
#include "lib/controls/ccolorchooser.cpp"
#include "lib/controls/cparamdisplay.cpp"
#include "lib/controls/ctextlabel.cpp"
#include "lib/controls/ctextedit.cpp"
#include "lib/controls/coptionmenu.cpp"
#include "lib/controls/cknob.cpp"
#include "lib/controls/cswitch.cpp"
#include "lib/controls/cslider.cpp"
#include "lib/controls/cmoviebitmap.cpp"
#include "lib/controls/cmoviebutton.cpp"
#include "lib/controls/cautoanimation.cpp"
#include "lib/controls/cspecialdigit.cpp"
#include "lib/controls/csplashscreen.cpp"
#include "lib/controls/cvumeter.cpp"
#include "lib/controls/cxypad.cpp"
#include "lib/controls/cfontchooser.cpp"

#include "lib/animation/animations.cpp"
#include "lib/animation/animator.cpp"
#include "lib/animation/timingfunctions.cpp"
