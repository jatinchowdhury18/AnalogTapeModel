//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vstrepresentation.cpp
// Created by  : Steinberg, 08/2010
// Description : VST Representation Helper
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
//-----------------------------------------------------------------------------

#include "vstrepresentation.h"

#include "base/source/fstring.h"
#include "base/source/fstreamer.h"

namespace Steinberg {
namespace Vst {

#define START_TAG_STRING(string) "<" string">"
#define END_TAG_STRING(string)	 "</" string">"
#define MEDIUM_TITLE_LIMIT			8
#define SHORT_TITLE_LIMIT			4

//------------------------------------------------------------------------
// XmlRepresentationHelper Implementation
//------------------------------------------------------------------------
XmlRepresentationHelper::XmlRepresentationHelper (const Vst::RepresentationInfo& info, const FIDString companyName, 
	const FIDString pluginName, const TUID& pluginUID, IBStream* stream)
{
	streamer = NEW IBStreamer (stream, kLittleEndian);

	String string;
	streamer->writeString8 ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
	streamer->writeString8 (ENDLINE_A);
	string.printf ("<!DOCTYPE %s PUBLIC \"-//Steinberg//DTD VST Remote 1.1//EN\" \"http://dtd.steinberg.net/VST-Remote-1.1.dtd\">", ROOTXML_TAG);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);
	
	string.printf ("<%s %s=\"1.0\">", ROOTXML_TAG, ATTR_VERSION);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	//---Plug-in Tag----------------
	FUID uid (pluginUID);
	char uidText[33];
	uid.toString (uidText);

	string.printf ("<%s %s=\"%s\" %s=\"%s\" %s=\"%s\"/>", PLUGIN_TAG, ATTR_CLASSID, uidText, ATTR_NAME, pluginName, ATTR_VENDOR, companyName);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	//---Representation Tag----------------
	string.printf ("\t<%s", REPRESENTATION_TAG);
	streamer->writeString8 (string.text8 ());
	string.printf (" %s=\"%s\"", ATTR_NAME, info.name);
	streamer->writeString8 (string.text8 ());
	string.printf (" %s=\"%s\"", ATTR_VENDOR, info.vendor);
	streamer->writeString8 (string.text8 ());
	string.printf (" %s=\"%s\"", ATTR_VERSION, info.version);
	streamer->writeString8 (string.text8 ());
	if (strcmp ((char*)info.host, ""))
	{
		string.printf (" %s=\"%s\"", ATTR_HOST, info.host);
		streamer->writeString8 (string.text8 ());
	}
	streamer->writeString8 (">");
	streamer->writeString8 (ENDLINE_A);

	state = kInRepresentation;
}

//------------------------------------------------------------------------
XmlRepresentationHelper::~XmlRepresentationHelper ()
{
	if (state == kInLayer)
		endLayer ();
	if (state == kInCell)
		endCell ();
	if (state == kInPage)
		endPage ();

	String string;
	
	// end representation
	string.printf ("\t%s", END_TAG_STRING(REPRESENTATION_TAG));
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	// end piper
	streamer->writeString8 (END_TAG_STRING(ROOTXML_TAG));
	streamer->writeString8 (ENDLINE_A);

	delete streamer;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::checkState (int32 newState)
{
	if (newState - state == 1 || state - newState == 1) // we go down or up
	{
		state = newState;
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startPage (FIDString name, int32 unitID)
{
	if (!checkState (kInPage))
		return false;

	String string;
	if (unitID != -1)
		string.printf ("<%s %s=\"%s\" %s=\"%d\">", PAGE_TAG, ATTR_NAME, name, ATTR_UNITID, unitID);
	else
		string.printf ("<%s %s=\"%s\">", PAGE_TAG, ATTR_NAME, name);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::endPage ()
{
	if (!checkState (kInRepresentation))
		return false;

	String string;
	string.printf ("%s", END_TAG_STRING(PAGE_TAG));
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startCell ()
{
	if (!checkState (kInCell))
		return false;

	String string;
	string.printf ("%s", START_TAG_STRING(CELL_TAG));
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::endCell ()
{
	if (!checkState (kInPage))
		return false;

	String string;
	string.printf ("%s", END_TAG_STRING(CELL_TAG));
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndCell ()
{
	if (!checkState (kInCell))
		return false;

	String string;
	string.printf ("<%s/>", CELL_TAG);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	if (!checkState (kInPage))
		return false;
	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startLayer (int32 type, int32 id, FIDString _function, FIDString style)
{
	return startLayer (type, id, _function, style, false);
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::endLayer ()
{
	if (!checkState (kInCell))
		return false;

	String string;
	string.printf ("%s", END_TAG_STRING(LAYER_TAG));
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndLayer (int32 type, int32 id, FIDString _function, FIDString style)
{
	return startLayer (type, id, _function, style, true);
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startLayer (int32 type, int32 id, FIDString _function, FIDString style, bool ended)
{
	if (!checkState (kInLayer))
		return false;

	String string;

	string.printf ("<%s %s=\"%s\" %s=\"%d\"", LAYER_TAG, ATTR_TYPE, Vst::LayerType::layerTypeFIDString[type], ATTR_PARAMID, id);
	streamer->writeString8 (string.text8 ());

	if (_function)
	{
		string.printf (" %s=\"%s\"", Vst::Attributes::kFunction, _function);
		streamer->writeString8 (string.text8 ());
	}
	if (style)
	{
		string = Vst::LayerType::layerTypeFIDString[type];
		if (type == Vst::LayerType::kSwitch)
			string.printf (" %s=\"%s\"", Vst::Attributes::kSwitchStyle, style);
		else if (type == Vst::LayerType::kLED)
			string.printf (" %s=\"%s\"", Vst::Attributes::kLEDStyle, style);
		else
			string.printf (" %s=\"%s\"",  Vst::Attributes::kStyle, style);
		streamer->writeString8 (string.text8 ());
	}

	if (ended)
	{
		streamer->writeString8 ("/>");
		if (!checkState (kInCell))
			return false;
	}
	else
		streamer->writeString8 (">");
	streamer->writeString8 (ENDLINE_A);

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndCellOneLayer (int32 type, int32 id, FIDString _function, FIDString style)
{
	if (!startCell ())
		return false;
	startEndLayer (type, id, _function, style);
	endCell ();

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startLayer (Vst::ParameterInfo& info, FIDString _function)
{
	return startLayer (info, _function, false);
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startLayer (Vst::ParameterInfo& info, FIDString _function, bool ended)
{
	FIDString style = 0;
	int32 type = Vst::LayerType::kKnob;
	if (info.flags & Vst::ParameterInfo::kIsReadOnly)
		type = Vst::LayerType::kLED;
	else if (info.stepCount == 1)
	{
		type = Vst::LayerType::kSwitch;
		style = Vst::AttributesStyle::kSwitchPushIncLoopedStyle;
	}

	return startLayer (type, info.id, _function, style, ended);
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndLayer (Vst::ParameterInfo& info, FIDString _function)
{
	return startLayer (info, _function, true);
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndCellOneLayer (Vst::ParameterInfo& info, FIDString _function)
{
	if (!startCell ())
		return false;
	startEndLayer (info, _function);
	endCell ();

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndCellOneLayerWithParamName (Vst::ParameterInfo& info, FIDString _function /*= 0*/)
{
	if (!startCell ())
		return false;
	startLayer (info, _function, false);
	startEndTitleDisplay (info);
	endLayer ();
	endCell ();

	return true;
}

//------------------------------------------------------------------------
bool XmlRepresentationHelper::startEndTitleDisplay (Vst::ParameterInfo& info)
{
	String nameString (info.title);

	if (nameString.isEmpty ())
		return false;

	if (!checkState (kInTitleDisplay))
		return false;

	String string;

	string.printf ("<%s>", TITLEDISPLAY_TAG);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	// start of name scope

	if (!checkState (kInName))
	{
		string.printf ("%s", END_TAG_STRING (TITLEDISPLAY_TAG));
		streamer->writeString8 (string.text8 ());
		streamer->writeString8 (ENDLINE_A);
		return false;
	}
	
	string.printf ("<%s>%s</%s>", NAME_TAG, nameString.text8 (), NAME_TAG);
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);
	
	if (nameString.length () > MEDIUM_TITLE_LIMIT)
	{
		nameString.assign (info.shortTitle);

		if (! nameString.isEmpty ())
		{
			nameString.removeChars ();							// remove space

			if (nameString.length () > MEDIUM_TITLE_LIMIT)
				nameString.remove (MEDIUM_TITLE_LIMIT);			// Trimming the rest to get a short string

			string.printf ("<%s>%s</%s>", NAME_TAG, nameString.text8 (), NAME_TAG);
			streamer->writeString8 (string.text8 ());
			streamer->writeString8 (ENDLINE_A);
		}
	}

	if (nameString.length () > SHORT_TITLE_LIMIT)
	{
		nameString.remove (SHORT_TITLE_LIMIT);					// Trimming the rest to get a short string

		string.printf ("<%s>%s</%s>", NAME_TAG, nameString.text8 (), NAME_TAG);
		streamer->writeString8 (string.text8 ());
		streamer->writeString8 (ENDLINE_A);
	}

	if (!checkState (kInTitleDisplay))
		return false;

	// end of name scope

	string.printf ("%s", END_TAG_STRING (TITLEDISPLAY_TAG));
	streamer->writeString8 (string.text8 ());
	streamer->writeString8 (ENDLINE_A);

	if (!checkState (kInLayer))
		return false;

	return true;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
