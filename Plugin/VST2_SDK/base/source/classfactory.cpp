//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/classfactory.cpp
// Created by  : Steinberg, 05/2006
// Description : Class factory
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

#include "base/source/classfactory.h"
#include "base/source/thashtable.h"
#include "base/source/tarray.h"
#include "base/source/fstring.h"
#include "base/source/fdebug.h"


namespace Steinberg {

namespace MetaClasses // this all is for avoiding forward declarations + includes
{
	//---Class Name  ---------------------------------------------------------------------
	static inline int32 compareClassIDs (FClassID ci1, FClassID ci2)
	{
		return strcmp (ci1, ci2);
	}
	struct SorterByName
	{
		SorterByName (MetaClass* c = 0) : c (c) {}
		SorterByName (const SorterByName& cw) : c (cw.c) {}
		bool operator== (const SorterByName& cw) const { return (c && cw.c) ? compareClassIDs (c->getName (), cw.c->getName ()) == 0 : false; }
		bool operator< (const SorterByName& cw) const { return (c && cw.c) ? compareClassIDs (c->getName (), cw.c->getName ()) < 0 : true; }
		bool operator>= (const SorterByName& cw) const { return (c && cw.c) ? compareClassIDs (c->getName (), cw.c->getName ()) >= 0 : false; }

		MetaClass* c;
	};

	uint32 hashByName (const SorterByName& s, uint32 m)
	{
		return Steinberg::hashString8 (s.c->getName (), m);
	}

	//---Class UID---------------------------------------------------------------------
	struct SorterByCID
	{
		SorterByCID (MetaClass* c = 0) : c (c) {}
		SorterByCID (const SorterByCID& cw) : c (cw.c) {}
		bool operator== (const SorterByCID& cw) const { return (c && cw.c) ? c->getID () == cw.c->getID () : false; }
		bool operator< (const SorterByCID& cw) const { return (c && cw.c) ? c->getID () < cw.c->getID () : true; }
		bool operator>= (const SorterByCID& cw) const { return (c && cw.c) ? c->getID () >= cw.c->getID () : false; }

		MetaClass* c;
	};

	uint32 hashByCID (const SorterByCID& s, uint32 m)
	{
		uint32 d1, d2, d3, d4;
		s.c->getID ().to4Int (d1, d2, d3, d4);
		return (d1 + d2 + d3 + d4) % m;
	}

	struct Tables
	{
		Tables () : nameTable (hashByName, 50), cidTable (hashByCID, 20) {}

		THashTable<SorterByName> nameTable;
		THashTable<SorterByCID> cidTable;
	};
}


//------------------------------------------------------------------------
ClassFactory::ClassFactory ()
: tables (0)
{
	tables = NEW MetaClasses::Tables;
}

//------------------------------------------------------------------------
ClassFactory::~ClassFactory ()
{
	delete tables;
}

//------------------------------------------------------------------------
void ClassFactory::registerMetaClass (MetaClass* mc)
{
	if (mc->getName ())
		tables->nameTable.add (mc);

	if (mc->getID ().isValid ())
		tables->cidTable.add (mc);
}

//------------------------------------------------------------------------
void ClassFactory::unregisterMetaClass (MetaClass* mc)
{
	if (mc->getName ())
		tables->nameTable.remove (mc);

	if (mc->getID ().isValid ())
		tables->cidTable.remove (mc);
}

//------------------------------------------------------------------------
MetaClass* ClassFactory::getMetaClassByName (FClassID className)
{
	MetaClass c (className);
	MetaClasses::SorterByName cw (&c);
	return tables->nameTable.lookup (cw).c;
}

//------------------------------------------------------------------------
MetaClass* ClassFactory::getMetaClassByID (const TUID classID)
{
	MetaClass c (0, 0, classID);
	MetaClasses::SorterByCID cw (&c);
	return tables->cidTable.lookup (cw).c;
}

//------------------------------------------------------------------------
bool ClassFactory::getStorageID (FUnknown* unknown, IString& result, 
								 bool checkForMetaclass)
{
	MetaClass* metaClass = 0;
	FObject* obj = FObject::unknownToObject (unknown);
	if (obj)
	{
		if (checkForMetaclass)
		{
			metaClass = getMetaClassByName (obj->isA ());
			if (metaClass)
			{
				result.setText8 (metaClass->getPersistentName ());
				return true;
			}
		}
		else
		{
			result.setText8 (obj->isA ());
			return true;
		}
	}
	
	FUnknownPtr <IPersistent> persistent (unknown);
	if (persistent)
	{
		FUID cid;
		if (persistent->getClassID (cid) == kResultTrue)
		{
			if (checkForMetaclass)
				metaClass = getMetaClassByID (cid);
			
			if (metaClass || checkForMetaclass == false)
			{
				FUID::String str = {0};
				cid.toString (str);
				result.setText8 (str);
				return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------------------------
FUnknown* ClassFactory::createObjectByName (FClassID className)
{
	MetaClass* metaClass = getMetaClassByName (className);
	if (metaClass == 0)
	{
		FUID cid;
		cid.fromString (className);
		if (cid.isValid ())
			metaClass = getMetaClassByID (cid);
	}

	if (metaClass)
		return metaClass->createUnknown ();

	return 0;
}

//------------------------------------------------------------------------
FUnknown* ClassFactory::createObjectByID (const TUID classID)
{
	MetaClass* metaClass = getMetaClassByID (classID);
	if (metaClass)
		return metaClass->createUnknown ();
	return 0;
}


//------------------------------------------------------------------------
// Meta Class
//------------------------------------------------------------------------
MetaClass::MetaClass (FClassID className, CreateFunc cFunc, FIDString _cid,  
					  MetaClass* parent, int16 version)
: name (className)
, persistentName (className)
, createFunction (cFunc)
, cid (_cid)
, version (version)
, parent (parent)
{
	if (createFunction || parent)
		ClassFactory::instance ()->registerMetaClass (this);
}

//------------------------------------------------------------------------
MetaClass::MetaClass (MetaClass* sourceClass, FClassID pName)
: name (pName)
, persistentName (pName)
, createFunction (sourceClass->createFunction)
, version (0)
, parent (0)
{
	sourceClass->persistentName = pName;
	if (createFunction || parent)
		ClassFactory::instance ()->registerMetaClass (this);
}

//------------------------------------------------------------------------
bool MetaClass::isTypeOf (FClassID id)
{
	if (FObject::classIDsEqual (id, name))
		return true;
	if (parent)
		return parent->isTypeOf (id);
	return false;
}

} // namespace Steinberg
