//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vsteditcontroller.cpp
// Created by  : Steinberg, 04/2005
// Description : VST Edit Controller Implementation
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

#include "public.sdk/source/vst/vsteditcontroller.h"
#include "pluginterfaces/base/ustring.h"
#include "base/source/updatehandler.h"

#include <stdio.h>

namespace Steinberg {
namespace Vst {

KnobMode EditController::hostKnobMode = kCircularMode;

//------------------------------------------------------------------------
// EditController Implementation
//------------------------------------------------------------------------
EditController::EditController ()
: componentHandler (0)
, componentHandler2 (0)
{}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::initialize (FUnknown* context)
{
	return ComponentBase::initialize (context);
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::terminate ()
{
	parameters.removeAll ();

	if (componentHandler)
	{
		componentHandler->release ();
		componentHandler = 0;
	}

	if (componentHandler2)
	{
		componentHandler2->release ();
		componentHandler2 = 0;
	}

	return ComponentBase::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::setComponentState (IBStream* /*state*/)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::setState (IBStream* /*state*/)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::getState (IBStream* /*state*/)
{
	return kNotImplemented;
}

//------------------------------------------------------------------------
int32 PLUGIN_API EditController::getParameterCount ()
{
	return parameters.getParameterCount ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::getParameterInfo (int32 paramIndex, ParameterInfo& info)
{
	Parameter* parameter = parameters.getParameterByIndex (paramIndex);
	if (parameter)
	{
		info = parameter->getInfo ();
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		parameter->toString (valueNormalized, string);
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::getParamValueByString (ParamID tag, TChar* string, ParamValue& valueNormalized)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		if (parameter->fromString (string, valueNormalized))
		{
			return kResultTrue;
		}
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
ParamValue PLUGIN_API EditController::normalizedParamToPlain (ParamID tag, ParamValue valueNormalized)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		return parameter->toPlain (valueNormalized);
	}
	return valueNormalized;
}

//------------------------------------------------------------------------
ParamValue PLUGIN_API EditController::plainParamToNormalized (ParamID tag, ParamValue plainValue)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		return parameter->toNormalized (plainValue);
	}
	return plainValue;
}

//------------------------------------------------------------------------
ParamValue PLUGIN_API EditController::getParamNormalized (ParamID tag)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		return parameter->getNormalized ();
	}
	return 0.0;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::setParamNormalized (ParamID tag, ParamValue value)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		parameter->setNormalized (value);
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditController::setComponentHandler (IComponentHandler* newHandler)
{
	if (componentHandler == newHandler)
	{
		return kResultTrue;
	}

	if (componentHandler)
	{
		componentHandler->release ();
	}

	componentHandler = newHandler;
	if (componentHandler)
	{
		componentHandler->addRef ();
	}

	// try to get the extended version
	if (componentHandler2)
	{
		componentHandler2->release ();
		componentHandler2 = 0;
	}

	if (newHandler)
	{
		newHandler->queryInterface (IComponentHandler2::iid, (void**)&componentHandler2);
	}
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult EditController::beginEdit (ParamID tag)
{
	if (componentHandler)
	{
		return componentHandler->beginEdit (tag);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult EditController::performEdit (ParamID tag, ParamValue valueNormalized)
{
	if (componentHandler)
	{
		return componentHandler->performEdit (tag, valueNormalized);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult EditController::endEdit (ParamID tag)
{
	if (componentHandler)
	{
		return componentHandler->endEdit (tag);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult EditController::startGroupEdit ()
{
	if (componentHandler2)
	{
		return componentHandler2->startGroupEdit ();
	}
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult EditController::finishGroupEdit ()
{
	if (componentHandler2)
	{
		return componentHandler2->finishGroupEdit ();
	}
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult EditController::getParameterInfoByTag (ParamID tag, ParameterInfo& info)
{
	Parameter* parameter = getParameterObject (tag);
	if (parameter)
	{
		info = parameter->getInfo ();
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult EditController::setDirty (TBool state)
{
	if (componentHandler2)
	{
		return componentHandler2->setDirty (state);
	}
	return kNotImplemented;
}

//------------------------------------------------------------------------
tresult EditController::requestOpenEditor (FIDString name)
{
	if (componentHandler2)
	{
		return componentHandler2->requestOpenEditor (name);
	}
	return kNotImplemented;
}

//------------------------------------------------------------------------
// EditorView Implementation
//------------------------------------------------------------------------
EditorView::EditorView (EditController* controller, ViewRect* size)
: CPluginView (size)
, controller (controller)
{
	if (controller)
	{
		controller->addRef ();
	}
}

//------------------------------------------------------------------------
EditorView::~EditorView ()
{
	if (controller)
	{
		controller->editorDestroyed (this);
		controller->release ();
	}
}

//------------------------------------------------------------------------
void EditorView::attachedToParent ()
{
	if (controller)
	{
		controller->editorAttached (this);
	}
}

//------------------------------------------------------------------------
void EditorView::removedFromParent ()
{
	if (controller)
	{
		controller->editorRemoved (this);
	}
}

//------------------------------------------------------------------------
// EditControllerEx1 implementation
//------------------------------------------------------------------------
EditControllerEx1::EditControllerEx1 ()
: selectedUnit (kRootUnitId)
{
	UpdateHandler::instance ();
}

//------------------------------------------------------------------------
EditControllerEx1::~EditControllerEx1 ()
{
	for (int32 i = 0; i < programLists.total (); i++)
	{
		ProgramList* programList = programLists.at (i).object ();
		if (programList)
			programList->removeDependent (this);
	}
}

//------------------------------------------------------------------------
bool EditControllerEx1::addUnit (Unit* unit)
{
	return units.add (IPtr<Unit> (unit, false));
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditControllerEx1::getUnitInfo (int32 unitIndex, UnitInfo& info /*out*/)
{
	Unit* unit = units.at (unitIndex);
	if (unit)
	{
		info = unit->getInfo ();
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult EditControllerEx1::notifyUnitSelection ()
{
	tresult result = kResultFalse;
	FUnknownPtr<IUnitHandler> unitHandler (componentHandler);
	if (unitHandler)
		result = unitHandler->notifyUnitSelection (selectedUnit);
	return result;
}

//------------------------------------------------------------------------
bool EditControllerEx1::addProgramList (ProgramList* list)
{
	if (programLists.addKeyAndObject (list->getID (), IPtr<ProgramList> (list, false)))
	{
		list->addDependent (this);
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
ProgramList* EditControllerEx1::getProgramList (ProgramListID listId) const
{
	return programLists.lookupObject (listId);
}

//------------------------------------------------------------------------
tresult EditControllerEx1::notifyPogramListChange (ProgramListID listId, int32 programIndex)
{
	tresult result = kResultFalse;
	FUnknownPtr<IUnitHandler> unitHandler (componentHandler);
	if (unitHandler)
		result = unitHandler->notifyProgramListChange (listId, programIndex);
	return result;
}

//------------------------------------------------------------------------
int32 PLUGIN_API EditControllerEx1::getProgramListCount ()
{
	return programLists.total ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditControllerEx1::getProgramListInfo (int32 listIndex, ProgramListInfo& info /*out*/)
{
	TAssociation<ProgramListID, IPtr<ProgramList> > assoc = programLists.at (listIndex);
	if (assoc.object ())
	{
		info = assoc.object ()->getInfo ();
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditControllerEx1::getProgramName (ProgramListID listId, int32 programIndex, String128 name /*out*/)
{
	ProgramList* list = programLists.lookupObject (listId);
	if (list)
	{
		return list->getProgramName (programIndex, name);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult EditControllerEx1::setProgramName (ProgramListID listId, int32 programIndex, const String128 name /*in*/)
{
	ProgramList* list = programLists.lookupObject (listId);
	if (list)
	{
		return list->setProgramName (programIndex, name);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditControllerEx1::getProgramInfo (ProgramListID listId, int32 programIndex, CString attributeId /*in*/, String128 attributeValue /*out*/)
{
	ProgramList* list = programLists.lookupObject (listId);
	if (list)
	{
		return list->getProgramInfo (programIndex, attributeId, attributeValue);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditControllerEx1::hasProgramPitchNames (ProgramListID listId, int32 programIndex)
{
	ProgramList* list = programLists.lookupObject (listId);
	if (list)
	{
		return list->hasPitchNames (programIndex);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API EditControllerEx1::getProgramPitchName (ProgramListID listId, int32 programIndex, int16 midiPitch, String128 name /*out*/)
{
	ProgramList* list = programLists.lookupObject (listId);
	if (list)
	{
		return list->getPitchName (programIndex, midiPitch, name);
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
void PLUGIN_API EditControllerEx1::update (FUnknown* changedUnknown, int32 message)
{
	ProgramList* programList = FCast<ProgramList> (changedUnknown);
	if (programList)
	{
		FUnknownPtr<IUnitHandler> unitHandler (componentHandler);
		if (unitHandler)
			unitHandler->notifyProgramListChange (programList->getID (), kAllProgramInvalid);
	}
}

//------------------------------------------------------------------------
// Unit implementation
//------------------------------------------------------------------------
Unit::Unit ()
{
	memset (&info, 0, sizeof (UnitInfo));
}

//------------------------------------------------------------------------
Unit::Unit (const String128 name, UnitID unitId, UnitID parentUnitId, ProgramListID programListId)
{
	setName (name);
	info.id = unitId;
	info.parentUnitId = parentUnitId;
	info.programListId = programListId;
}

//------------------------------------------------------------------------
Unit::Unit (const UnitInfo& info)
: info (info)
{
}

//------------------------------------------------------------------------
void Unit::setName (const String128 newName)
{
	UString128 (newName).copyTo (info.name, 128);
}

//------------------------------------------------------------------------
// ProgramList implementation
//------------------------------------------------------------------------
ProgramList::ProgramList (const String128 name, ProgramListID listId, UnitID unitId)
: unitId (unitId)
, parameter (0)
{
	UString128 (name).copyTo (info.name, 128);
	info.id = listId;
	info.programCount = 0;
}

//------------------------------------------------------------------------
ProgramList::ProgramList (const ProgramList& programList)
: info (programList.info)
, unitId (programList.unitId)
, programNames (programList.programNames)
, parameter (0)
{
}

//------------------------------------------------------------------------
int32 ProgramList::addProgram (const String128 name)
{
	info.programCount++;
	if (programNames.add (name))
	{
		programInfos.add (TDictionary<String, String> ());
		return programNames.total () - 1;
	}
	return -1;
}

//------------------------------------------------------------------------
bool ProgramList::setProgramInfo (int32 programIndex, CString attributeId, const String128 value)
{
	if (programIndex < programNames.total ())
	{
		programInfos.at (programIndex).addKeyAndObject (attributeId, value);
		return true;
	}
	return false;
}

//------------------------------------------------------------------------
tresult ProgramList::getProgramInfo (int32 programIndex, CString attributeId, String128 value /*out*/)
{
	if (programIndex < programNames.total ())
	{
		const String& attValue = programInfos.at (programIndex).lookupObject (attributeId);
		if (!attValue.isEmpty ())
		{
			attValue.copyTo16 (value, 0, 128);
			return kResultTrue;
		}
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult ProgramList::getProgramName (int32 programIndex, String128 name /*out*/)
{
	if (programIndex < programNames.total ())
	{
		programNames.at (programIndex).copyTo16 (name, 0, 128);
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult ProgramList::setProgramName (int32 programIndex, const String128 name /*in*/)
{
	if (programIndex < programNames.total ())
	{
		programNames.at (programIndex) = name;
		if (parameter)
		{
			static_cast<StringListParameter*> (parameter)->replaceString (programIndex, name);
		}
		return kResultTrue;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
Parameter* ProgramList::getParameter ()
{
	if (parameter == 0)
	{
		StringListParameter* listParameter = new StringListParameter (info.name, info.id, 0, ParameterInfo::kCanAutomate | ParameterInfo::kIsList | ParameterInfo::kIsProgramChange, unitId);
		FOREACH_T(String, name, programNames)
			listParameter->appendString (name);
		ENDFOR
		parameter = listParameter;
	}
	return parameter;
}

//------------------------------------------------------------------------
// ProgramListWithPitchNames implementation
//-----------------------------------------------------------------------------
ProgramListWithPitchNames::ProgramListWithPitchNames (const String128 name, ProgramListID listId, UnitID unitId)
: ProgramList (name, listId, unitId)
{
}

//-----------------------------------------------------------------------------
int32 ProgramListWithPitchNames::addProgram (const String128 name)
{
	int32 index = ProgramList::addProgram (name);
	if (index >= 0)
		pitchNames.add (TDictionary<int16, String> ());
	return index;
}

//-----------------------------------------------------------------------------
bool ProgramListWithPitchNames::setPitchName (int32 programIndex, int16 pitch, const String128 pitchName)
{
	bool result = false;
	if (programIndex < getCount ())
	{
		if (pitchNames.at (programIndex).containsKey (pitch))
			result = pitchNames.at (programIndex).replace (pitch, pitchName);
		else
			result = pitchNames.at (programIndex).addKeyAndObject (pitch, pitchName);
	}
	if (result)
		changed ();
	return result;
}

//-----------------------------------------------------------------------------
bool ProgramListWithPitchNames::removePitchName (int32 programIndex, int16 pitch)
{
	bool result = false;
	if (programIndex < getCount ())
	{
		result = pitchNames.at (programIndex).removeKey (pitch);
	}
	if (result)
		changed ();
	return result;
}

//-----------------------------------------------------------------------------
tresult ProgramListWithPitchNames::hasPitchNames (int32 programIndex)
{
	if (programIndex < getCount ())
		return pitchNames.at (programIndex).total () > 0 ? kResultTrue : kResultFalse;
	return kResultFalse;
}

//-----------------------------------------------------------------------------
tresult ProgramListWithPitchNames::getPitchName (int32 programIndex, int16 midiPitch, String128 name /*out*/)
{
	if (programIndex < getCount ())
	{
		const String& str = pitchNames.at (programIndex).lookupObject (midiPitch);
		if (!str.isEmpty ())
		{
			str.copyTo16 (name, 0, 128);
			return kResultTrue;
		}
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
