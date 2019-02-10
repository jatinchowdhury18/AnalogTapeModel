//------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vstnoteexpressiontypes.cpp
// Created by  : Steinberg, 12/2010
// Description : VST Note Expression Type Info Implementation
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

#include "vstnoteexpressiontypes.h"
#include "vstparameters.h"
#include "pluginterfaces/base/ustring.h"
#include "pluginterfaces/base/futils.h"
#include "base/source/fstring.h"

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
NoteExpressionType::NoteExpressionType ()
: precision (4)
{
	memset (&info, 0, sizeof (info));
}

//-----------------------------------------------------------------------------
NoteExpressionType::NoteExpressionType (const NoteExpressionTypeInfo& _info)
: precision (4)
{
	memcpy (&info, &_info, sizeof (info));
}

//-----------------------------------------------------------------------------
NoteExpressionType::NoteExpressionType (NoteExpressionTypeID _typeId, const TChar* _title, const TChar* _shortTitle, const TChar* _units,
										int32 _unitId, NoteExpressionValue _defaultValue, NoteExpressionValue _minimum, NoteExpressionValue _maximum,
										int32 _stepCount, int32 _flags, int32 _precision)
: precision (_precision)
{
	memset (&info, 0, sizeof (info));
	info.typeId = _typeId;
	if (_title)
		UString (info.title, str16BufferSize (String128)).assign (_title);
	if (_shortTitle)
		UString (info.shortTitle, str16BufferSize (String128)).assign (_shortTitle);
	if (_units)
		UString (info.shortTitle, str16BufferSize (String128)).assign (_units);
	info.unitId = _unitId;
	info.valueDesc.defaultValue = _defaultValue;
	info.valueDesc.minimum = _minimum;
	info.valueDesc.maximum = _maximum;
	info.valueDesc.stepCount = _stepCount;
	info.flags = _flags;
}

//-----------------------------------------------------------------------------
NoteExpressionType::NoteExpressionType (NoteExpressionTypeID _typeId, const TChar* _title, const TChar* _shortTitle, const TChar* _units,
										int32 _unitId, Parameter* _associatedParameter, int32 _flags)
: associatedParameter (_associatedParameter)
, precision (4)
{
	memset (&info, 0, sizeof (info));
	info.typeId = _typeId;
	if (_title)
		UString (info.title, str16BufferSize (String128)).assign (_title);
	if (_shortTitle)
		UString (info.shortTitle, str16BufferSize (String128)).assign (_shortTitle);
	if (_units)
		UString (info.shortTitle, str16BufferSize (String128)).assign (_units);
	info.unitId = _unitId;
	info.valueDesc.defaultValue = 0.5;
	info.valueDesc.minimum = 0.;
	info.valueDesc.maximum = 1.;
	info.flags = _flags;
	if (_associatedParameter)
	{
		info.valueDesc.stepCount = _associatedParameter->getInfo ().stepCount;
		info.valueDesc.defaultValue = _associatedParameter->getInfo ().defaultNormalizedValue;
		info.associatedParameterId = associatedParameter->getInfo ().id;
		info.flags |= NoteExpressionTypeInfo::kAssociatedParameterIDValid;
	}
}

//-----------------------------------------------------------------------------
tresult NoteExpressionType::getStringByValue (NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
{
	if (associatedParameter)
	{
		associatedParameter->toString (valueNormalized, string);
		return kResultTrue;
	}
	UString128 wrapper;
	if (info.valueDesc.stepCount > 0)
	{
		int32 value = Min<int32> (info.valueDesc.stepCount, (int32)(valueNormalized * (info.valueDesc.stepCount + 1)));
		wrapper.printInt (value);
	}
	else
	{
		wrapper.printFloat (valueNormalized, precision);
	}
	wrapper.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult NoteExpressionType::getValueByString (const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
{
	if (associatedParameter)
	{
		return associatedParameter->fromString (string, valueNormalized) ? kResultTrue : kResultFalse;
	}
	String wrapper (string);
	if (info.valueDesc.stepCount > 0)
	{
		int32 value;
		if (wrapper.scanInt32 (value) && value <= info.valueDesc.stepCount)
		{
			valueNormalized = (NoteExpressionValue)value / (NoteExpressionValue)info.valueDesc.stepCount;
			return kResultTrue;
		}
		return kResultFalse;
	}
	double value;
	wrapper.scanFloat (value);
	if (value < info.valueDesc.minimum)
		return kResultFalse;
	if (value > info.valueDesc.maximum)
		return kResultFalse;
	valueNormalized = value;
	return kResultTrue;
}

//-----------------------------------------------------------------------------
RangeNoteExpressionType::RangeNoteExpressionType (NoteExpressionTypeID _typeId, const TChar* _title, const TChar* _shortTitle, const TChar* _units,
						 int32 _unitId, NoteExpressionValue _defaultPlainValue, NoteExpressionValue _plainMin, NoteExpressionValue _plainMax,
						 int32 _flags, int32 _precision)
: NoteExpressionType (_typeId, _title, _shortTitle, _units, _unitId, 0, 0, 1, 0, _flags, _precision)
, plainMin (_plainMin)
, plainMax (_plainMax)
{
	info.valueDesc.defaultValue = (_defaultPlainValue - getMin ()) / (getMax () - getMin ());
}

//-----------------------------------------------------------------------------
tresult RangeNoteExpressionType::getStringByValue (NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
{
	NoteExpressionValue plain = valueNormalized * (getMax () - getMin ()) + getMin ();
	UString128 wrapper;
	wrapper.printFloat (plain, precision);
	wrapper.copyTo (string, 128);
	return kResultTrue;
}

//-----------------------------------------------------------------------------
tresult RangeNoteExpressionType::getValueByString (const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
{
	String wrapper (string);
	double value = 0;
	if (wrapper.scanFloat (value))
	{
		value = (value - getMin ()) / (getMax () - getMin ());
		if (value >= 0. && value <= 1.)
		{
			valueNormalized = value;
			return kResultTrue;
		}
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
NoteExpressionTypeContainer::NoteExpressionTypeContainer ()
{
}

//-----------------------------------------------------------------------------
bool NoteExpressionTypeContainer::addNoteExpressionType (NoteExpressionType* noteExpType)
{
	return noteExps.addKeyAndObject (noteExpType->getInfo ().typeId, IPtr<NoteExpressionType> (noteExpType, false));
}

//-----------------------------------------------------------------------------
bool NoteExpressionTypeContainer::removeNoteExpressionType (NoteExpressionTypeID typeId)
{
	return noteExps.removeKey (typeId);
}

//-----------------------------------------------------------------------------
void NoteExpressionTypeContainer::removeAll ()
{
	noteExps.removeAll ();
}

//-----------------------------------------------------------------------------
NoteExpressionType* NoteExpressionTypeContainer::getNoteExpressionType (NoteExpressionTypeID typeId)
{
	return noteExps.lookupObject (typeId);
}

//-----------------------------------------------------------------------------
int32 NoteExpressionTypeContainer::getNoteExpressionCount ()
{
	return noteExps.total ();
}

//-----------------------------------------------------------------------------
tresult NoteExpressionTypeContainer::getNoteExpressionInfo (int32 noteExpressionIndex, NoteExpressionTypeInfo& info /*out*/)
{
	TAssociation<NoteExpressionTypeID, IPtr<NoteExpressionType> > assoc = noteExps.at (noteExpressionIndex);
	if (assoc.object ())
	{
		memcpy (&info, &assoc.object ()->getInfo (), sizeof (info));
		return kResultTrue;
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult NoteExpressionTypeContainer::getNoteExpressionStringByValue (NoteExpressionTypeID id, NoteExpressionValue valueNormalized /*in*/, String128 string /*out*/)
{
	NoteExpressionType* noteExpType = getNoteExpressionType (id);
	if (noteExpType)
	{
		return noteExpType->getStringByValue (valueNormalized, string);
	}
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult NoteExpressionTypeContainer::getNoteExpressionValueByString (NoteExpressionTypeID id, const TChar* string /*in*/, NoteExpressionValue& valueNormalized /*out*/)
{
	NoteExpressionType* noteExpType = getNoteExpressionType (id);
	if (noteExpType)
	{
		return noteExpType->getValueByString (string, valueNormalized);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
