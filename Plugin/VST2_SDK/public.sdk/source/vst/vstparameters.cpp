//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vstparameters.cpp
// Created by  : Steinberg, 03/2008
// Description : VST Parameter Implementation
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

#include "vstparameters.h"
#include "pluginterfaces/base/futils.h"
#include "pluginterfaces/base/ustring.h"
#include "base/source/fstring.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// Parameter Implementation
//------------------------------------------------------------------------
Parameter::Parameter ()
: valueNormalized (0.)
, precision (4)
{
	memset (&info, 0, sizeof (ParameterInfo));
}

//------------------------------------------------------------------------
Parameter::Parameter (const ParameterInfo& info)
: info (info)
, valueNormalized (info.defaultNormalizedValue)
, precision (4)
{}

//------------------------------------------------------------------------
Parameter::Parameter (const TChar* title, ParamID tag, const TChar* units, ParamValue defaultValueNormalized, int32 stepCount, int32 flags, UnitID unitID)
: precision (4)
{
	memset (&info, 0, sizeof (ParameterInfo));

	UString (info.title, str16BufferSize (String128)).assign (title);
	if (units)
		UString (info.units, str16BufferSize (String128)).assign (units);

	info.stepCount = stepCount;
	info.defaultNormalizedValue = valueNormalized = defaultValueNormalized;
	info.flags = flags;
	info.id = tag;
	info.unitId = unitID;
}

//------------------------------------------------------------------------
Parameter::~Parameter ()
{}

//------------------------------------------------------------------------
bool Parameter::setNormalized (ParamValue normValue)
{
	if (normValue > 1.0)
	{
		normValue = 1.0;
	}
	else if (normValue < 0.)
	{
		normValue = 0.;
	}

	if (normValue != valueNormalized)
	{
		valueNormalized = normValue;
		changed ();
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
void Parameter::toString (ParamValue normValue, String128 string) const
{
	UString128 wrapper;
	if (info.stepCount == 1)
	{
		if (normValue > 0.5)
		{
			wrapper.assign (STR16 ("On"));
		}
		else
		{
			wrapper.assign (STR16 ("Off"));
		}
	}
	else
	{
		wrapper.printFloat (normValue, precision);
	}
	wrapper.copyTo (string, 128);
}

//------------------------------------------------------------------------
bool Parameter::fromString (const TChar* string, ParamValue& normValue) const
{
	String wrapper ((TChar*)string);
	return wrapper.scanFloat (normValue);
}

//------------------------------------------------------------------------
ParamValue Parameter::toPlain (ParamValue normValue) const
{
	return normValue;
}

//------------------------------------------------------------------------
ParamValue Parameter::toNormalized (ParamValue plainValue) const
{
	return plainValue;
}


//------------------------------------------------------------------------
// RangeParameter Implementation
//------------------------------------------------------------------------
RangeParameter::RangeParameter ()
: minPlain (0)
, maxPlain (1)
{
}

//------------------------------------------------------------------------
RangeParameter::RangeParameter (const ParameterInfo& paramInfo, ParamValue min, ParamValue max)
: Parameter (paramInfo)
, minPlain (min)
, maxPlain (max)
{
}

//------------------------------------------------------------------------
RangeParameter::RangeParameter (const TChar* title, ParamID tag, const TChar* units,
								ParamValue minPlain, ParamValue maxPlain, ParamValue defaultValuePlain,
								int32 stepCount, int32 flags, UnitID unitID)
: minPlain (minPlain)
, maxPlain (maxPlain)
{
	UString (info.title, str16BufferSize (String128)).assign (title);

	UString uUnits (info.units, str16BufferSize (String128));
	if (units)
	{
		uUnits.assign (units);
	}

	info.stepCount = stepCount;
	info.defaultNormalizedValue = valueNormalized = toNormalized (defaultValuePlain);
	info.flags = flags;
	info.id = tag;
	info.unitId = unitID;
}

//------------------------------------------------------------------------
void RangeParameter::toString (ParamValue _valueNormalized, String128 string) const
{
	if (info.stepCount > 1)
	{
		String wrapper;
		wrapper.printf (STR("%d"), (int32)toPlain (_valueNormalized));
		wrapper.copyTo16 (string, 0, str16BufferSize (String128) - 1);
	}
	else
	{
		Parameter::toString (toPlain (_valueNormalized), string);
	}
}

//------------------------------------------------------------------------
bool RangeParameter::fromString (const TChar* string, ParamValue& _valueNormalized) const
{
	String wrapper ((TChar*)string);
	if (info.stepCount > 1)
	{
		int64 plainValue;
		if (wrapper.scanInt64 (plainValue))
		{
			_valueNormalized = toNormalized ((ParamValue)plainValue);
			return true;
		}
		return false;
	}
	if (wrapper.scanFloat (_valueNormalized))
	{
		if (_valueNormalized < getMin ())
			_valueNormalized = getMin ();
		else if (_valueNormalized > getMax ())
			_valueNormalized = getMax ();
		_valueNormalized = toNormalized (_valueNormalized);
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
ParamValue RangeParameter::toPlain (ParamValue _valueNormalized) const
{
	if (info.stepCount > 1)
		return Min<int32> (info.stepCount, (int32)(_valueNormalized * (info.stepCount + 1))) + getMin ();
	return _valueNormalized * (getMax () - getMin ()) + getMin ();
}

//------------------------------------------------------------------------
ParamValue RangeParameter::toNormalized (ParamValue plainValue) const
{
	if (info.stepCount > 1)
		return (plainValue - getMin ()) / info.stepCount;
	return (plainValue - getMin ()) / (getMax () - getMin ());
}


//------------------------------------------------------------------------
// StringListParameter Implementation
//------------------------------------------------------------------------
StringListParameter::StringListParameter (const ParameterInfo& paramInfo)
: Parameter (paramInfo)
{
	strings.error () = 0;
}

//------------------------------------------------------------------------
StringListParameter::StringListParameter (const TChar* title, ParamID tag, const TChar* units,
										  int32 flags, UnitID unitID)
{
	strings.error () = 0;

	UString (info.title, str16BufferSize (String128)).assign (title);

	UString uUnits (info.units, str16BufferSize (String128));
	if (units)
	{
		uUnits.assign (units);
	}

	info.stepCount = -1;
	info.defaultNormalizedValue = 0;
	info.flags = flags;
	info.id = tag;
	info.unitId = unitID;
}

//------------------------------------------------------------------------
StringListParameter::~StringListParameter ()
{
	FOREACH_T(TChar*, str, strings)
		free (str);
	ENDFOR
}

//------------------------------------------------------------------------
void StringListParameter::appendString (const String128 string)
{
	int32 length = strlen16 (string);
	TChar* buffer = (TChar*)malloc ((length + 1) * sizeof (TChar));
	memcpy (buffer, string, length * sizeof (TChar));
	buffer[length] = 0;
	strings.add (buffer);
	info.stepCount++;
}

//------------------------------------------------------------------------
bool StringListParameter::replaceString (int32 index, const String128 string)
{
	TChar* str = strings.at (index);
	if (str)
	{
		int32 length = strlen16 (string);
		TChar* buffer = (TChar*)malloc ((length + 1) * sizeof (TChar));
		memcpy (buffer, string, length * sizeof (TChar));
		buffer[length] = 0;
		strings.replaceAt (index, buffer);
		free (str);
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
void StringListParameter::toString (ParamValue _valueNormalized, String128 string) const
{
	int32 index = (int32)toPlain (_valueNormalized);
	const TChar* valueString = strings.at (index);
	if (valueString)
	{
		UString (string, str16BufferSize (String128)).assign (valueString);
	}
	else
		string[0] = 0;
}

//------------------------------------------------------------------------
bool StringListParameter::fromString (const TChar* string, ParamValue& _valueNormalized) const
{
	int32 index = 0;
	FOREACH_T(TChar*, str, strings)
		if (strcmp16 (str, string) == 0)
		{
			_valueNormalized = toNormalized ((ParamValue)index);
			return true;
		}
		index++;
	ENDFOR
	return false;
}

//------------------------------------------------------------------------
ParamValue StringListParameter::toPlain (ParamValue _valueNormalized) const
{
	if (info.stepCount <= 0)
		return 0;
	return Min<int32> (info.stepCount, (int32)(_valueNormalized * (info.stepCount + 1)));
}

//------------------------------------------------------------------------
ParamValue StringListParameter::toNormalized (ParamValue plainValue) const
{
	if (info.stepCount <= 0)
		return 0;
	return plainValue / (ParamValue)info.stepCount;
}

//------------------------------------------------------------------------
static uint32 HashFunc (const TAssociation<ParamID, int32>& a, uint32 size)
{
	return a.key () % size;
}

//------------------------------------------------------------------------
// ParameterContainer Implementation
//------------------------------------------------------------------------
ParameterContainer::ParameterContainer ()
: params (0)
, id2index (THashDictionary<ParamID, int32>(HashFunc))
{
	id2index.error () = TAssociation<ParamID, int32> (0, -1);
}

//------------------------------------------------------------------------
ParameterContainer::~ParameterContainer ()
{
	if (params)
		delete params;
}

//------------------------------------------------------------------------
void ParameterContainer::init (int32 initialSize, int32 resizeDelta)
{
	if (!params)
		params = new TArray<IPtr<Parameter> > (initialSize, resizeDelta);
}

//------------------------------------------------------------------------
Parameter* ParameterContainer::addParameter (Parameter* p)
{
	if (!params)
		init ();
	id2index.addKeyAndObject (p->getInfo ().id, params->total ());
	if (params->add (IPtr<Parameter> (p, false)))
		return p;
	return 0;
}

//------------------------------------------------------------------------
Parameter* ParameterContainer::addParameter (const ParameterInfo& info)
{
	if (!params)
		init ();
	Parameter* p = new Parameter (info);
	if (addParameter (p))
		return p;
	p->release ();
	return 0;
}

//------------------------------------------------------------------------
Parameter* ParameterContainer::getParameter (ParamID tag)
{
	if (params)
	{
		int32 index = id2index.lookupObject (tag);
		if (index != id2index.error ().object ())
			return params->at (index);
	}
	return 0;
}

//------------------------------------------------------------------------
Parameter* ParameterContainer::addParameter (const TChar* title, const TChar* units,
											 int32 stepCount, ParamValue defaultNormalizedValue,
											 int32 flags, int32 tag, UnitID unitID)
{
	if (!title)
	{
		return 0;
	}

	ParameterInfo info = {0};

	UString (info.title, str16BufferSize (String128)).assign (title);

	UString uUnits (info.units, str16BufferSize (String128));
	if (units)
	{
		uUnits.assign (units);
	}

	info.stepCount = stepCount;
	info.defaultNormalizedValue = defaultNormalizedValue;
	info.flags = flags;
	info.id = (tag >= 0) ? tag : getParameterCount ();
	info.unitId = unitID;

	return addParameter (info);
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
