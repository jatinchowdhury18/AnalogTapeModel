//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/classfactory.h
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
//----------------------------------------------------------------------------------

#ifndef __classfactory__
#define __classfactory__

#include "base/source/fobject.h"

namespace Steinberg {

class IString;
namespace MetaClasses { struct Tables; }

//------------------------------------------------------------------------
/** Class whose instances are classes. */
//------------------------------------------------------------------------
class MetaClass 
{
public:	
	//------------------------------------------------------------------------------
	typedef FUnknown* (*CreateFunc) ();

	MetaClass (FClassID className, CreateFunc = 0, FIDString cid = 0, MetaClass* parent = 0, int16 version = 0);
	MetaClass (MetaClass* sourceClass, FClassID persistentName);

	FClassID getName () const {return name;}
	FClassID getPersistentName () const {return persistentName;}
	const FUID& getID () const {return cid;}
	MetaClass* getParent () const {return parent;}
	int16 getVersion () const {return version;}
	bool isTypeOf (FClassID);

	FUnknown* createUnknown () const {return (createFunction ? createFunction () : 0);}
	template <class T> inline T* createObject ();
	//------------------------------------------------------------------------------
private:
	FClassID name;
	FClassID persistentName;
	FUID cid;
	CreateFunc createFunction;
	MetaClass* parent;
	int16 version;
};

//------------------------------------------------------------------------
template <class T>
inline T* MetaClass::createObject ()
{
	FUnknown* unknown = createUnknown ();
	T* tPtr = FCast<T> (unknown);
	if (tPtr)
		return tPtr;
	FReleaser ur (unknown);
	return 0;
}


//------------------------------------------------------------------------
/** Registry for meta classes.

	Detailed Description
*/
//------------------------------------------------------------------------
class ClassFactory : public FObject
{
public:
//------------------------------------------------------------------------------
	ClassFactory ();
	~ClassFactory ();
	
	MetaClass* getMetaClassByName (FIDString className);
	MetaClass* getMetaClassByID (const TUID classID);
	
	/** TODO */
	bool getStorageID (FUnknown* unknown, IString& result, bool checkForMetaClass = true);
	
	FUnknown* createObjectByName (FClassID className);
	FUnknown* createObjectByID (const TUID classID);
	
	template <class T> inline T* createByName (FClassID className);

	OBJ_METHODS (ClassFactory, FObject) 
	SINGLETON (ClassFactory)

	/** TODO */
	void registerMetaClass (MetaClass* mc); // not owned
	/** TODO */
	void unregisterMetaClass (MetaClass* mc); // not owned

//------------------------------------------------------------------------------
private:
	MetaClasses::Tables* tables;
};

//------------------------------------------------------------------------ 
template <class T> 
inline T* ClassFactory::createByName (FClassID className)
{
	FUnknown* unknown = createObjectByName (className);
	T* tPtr = FCast<T> (unknown);
	if (tPtr)
		return tPtr;
	FReleaser ur (unknown);
	return 0;
}

} // namespace Steinberg


//------------------------------------------------------------------------------
// Helper Macros. Not intended for direct use.
// Use: 
//	META_CLASS(className),
//	META_CLASS_IFACE(className,Interface),
//	META_CLASS_SINGLE(className,Interface) 
// instead.
//------------------------------------------------------------------------------
#define META_CREATE_FUNC(funcName) \
	static FUnknown* funcName ()

#define CLASS_CREATE_FUNC(className) \
	namespace Meta { META_CREATE_FUNC (make##className) {return (NEW className)->unknownCast ();} }

#define SINGLE_CREATE_FUNC(className) \
	namespace Meta { META_CREATE_FUNC (make##className) {return className::instance ()->unknownCast ();} }

#define _META_CLASS(className) \
	namespace Meta { static Steinberg::MetaClass meta##className((#className), Meta::make##className); } 

#define _META_CLASS_IFACE(className,Interface) \
	namespace Meta { static Steinberg::MetaClass meta##Interface##className ((#className), Meta::make##className, Interface##_iid);}

/** TODO
*/ 
#define META_CLASS(className) \
	CLASS_CREATE_FUNC(className) \
	_META_CLASS(className) 

/** TODO
*/
#define META_CLASS_IFACE(className,Interface) \
	CLASS_CREATE_FUNC(className) \
	_META_CLASS_IFACE(className,Interface)

/** TODO
*/
#define META_CLASS_SINGLE(className,Interface) \
	SINGLE_CREATE_FUNC(className) \
	_META_CLASS_IFACE(className,Interface)

#endif	// __classfactory__
