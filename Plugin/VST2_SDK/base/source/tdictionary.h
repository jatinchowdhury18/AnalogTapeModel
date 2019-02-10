//------------------------------------------------------------------------ 
// Project     : SDK Base
// Version     : 1.0
// 
// Category	   : Helpers
// Filename    : base/source/tdictionary.h
// Created by  : Steinberg
// Description : Dictionary class template (based on linked list)
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

#ifndef __tdictionary__
#define __tdictionary__

#include "base/source/tdlist.h"
#include "base/source/thashtable.h"
#include "base/source/tassociation.h"

namespace Steinberg {

//------------------------------------------------------------------------
/// Dictionary template definition.
/// A dictionary is a container that holds value pairs, a key and its
/// associated value object. The container is sorted by key and thus allows
/// for quick finding of a key and the lookup of the corresponding value.
//------------------------------------------------------------------------
template <class TKey, class TObject>
class TDictionary : public TDLinkedList< TAssociation<TKey, TObject> >
{
//------------------------------------------------------------------------
public:
	TDictionary () {} ///< Default constructor.
	TDictionary (const TKey& errKey, const TObject& errObj) {this->error () = TAssociation<TKey, TObject> (errKey, errObj);} ///< Constructor passing error values.
	TDictionary (const TDictionary<TKey, TObject>&); ///< Copy constructor.
	~TDictionary () {} ///< Destructor.

	TDictionary<TKey, TObject>& operator= (const TDictionary<TKey, TObject>&); ///< Assignment operator.

	bool addKey (const TKey&); ///< Add key.
	bool addKeyAndObject (const TKey&, const TObject&); ///< Add key/object.
	bool addAssoc (const TAssociation<TKey, TObject>&); ///< Add association.
	bool replace (const TKey&, const TObject&); ///< Replace object at key.
	bool removeKey (const TKey&); ///< Remove association at key.

	const TKey& lookupKey (const TKey&) const; ///< Return equal key.
	const TObject& lookupObject (const TKey&) const; ///< Return object by key.
	bool containsKey (const TKey&) const; ///< Test if key is in dictionary.
	int32 occurrencesOfKey (const TKey&) const; ///< How many equal keys.

	const TAssociation<TKey, TObject>& lookupAssoc (const TKey&) const; ///< Lookup association at key.
};

//-------------------------------------------------------------------------------------
// Dictionary Iterator
//-------------------------------------------------------------------------------------
template <class TKey, class TObject>
class TDictionaryIterator : public TDLinkedListIterator< TAssociation<TKey, TObject> > 
{
public:
	//-------------------------------------------------------------------------------------
	TDictionaryIterator (const TDictionary< TKey, TObject> & dict)
		: TDLinkedListIterator< TAssociation<TKey, TObject> > (dict)
	{}
};

//------------------------------------------------------------------------
/// Hash dictionary template definition.
/// A dictionary is a container that holds value pairs, a key and its
/// associated value object. \n\n
/// The difference to the normal TDictionary template is, that THashDictionary
/// gets implemented as a hash table. The interface and usage of both is same. \n\n
/// To understand the benefits and implications
/// of hashes see e.g.: http://en.wikipedia.org/wiki/Hash_table
//------------------------------------------------------------------------
template <class TKey, class TObject>
class THashDictionary : public THashTable< TAssociation<TKey, TObject> > 
{
public:
// -----------------------------------------------------------------
	typedef uint32 (*THashFunc) (const TAssociation<TKey, TObject>&, uint32);   ///< Hash function type.

	THashDictionary (THashFunc hashFunc, int32 = 10); ///< Default constructor.
	THashDictionary (const THashDictionary<TKey, TObject>&); ///< Copy constructor.
	~THashDictionary () {} ///< Destructor.

	THashDictionary<TKey, TObject>& operator= (const THashDictionary<TKey, TObject>&); ///< Assignment operator.

	bool addKey (const TKey&); ///< Add key.
	bool addKeyAndObject (const TKey&, const TObject&); ///< Add key/object.
	bool addAssoc (const TAssociation<TKey, TObject>&); ///< Add association.
	bool replace (const TKey&, const TObject&); ///< Replace object at key.
	bool removeKey (const TKey&); ///< Remove association at key.

	const TKey& lookupKey (const TKey&) const; ///< Return equal key.
	const TObject& lookupObject (const TKey&) const; ///< Return object by key.
	bool containsKey (const TKey&) const; ///< Test if key is in dictionary.
	int32 occurrencesOfKey (const TKey&) const; ///< How many equal keys.

	const TAssociation<TKey, TObject>& lookupAssoc (const TKey&) const; ///< Lookup association at key.
};

//-------------------------------------------------------------------------------------
// Hash Dictionary Iterator
//-------------------------------------------------------------------------------------
template <class TKey, class TObject>
class THashDictionaryIterator : public THashTableIterator< TAssociation<TKey, TObject> > 
{
public:
	//-------------------------------------------------------------------------------------
	THashDictionaryIterator (const THashDictionary< TKey, TObject> & dict)
		: THashTableIterator< TAssociation<TKey, TObject> > (dict)
	{}
};


//------------------------------------------------------------------------
// TDictionary copy constructor
/// Creates a new dictionary and assigns it with a copy of the specified dictionary.
//------------------------------------------------------------------------
template <class TKey, class TObject>
TDictionary<TKey, TObject>::TDictionary (const TDictionary<TKey, TObject>& dict)
: TDLinkedList< TAssociation<TKey, TObject> > (dict)
{}


//------------------------------------------------------------------------
// TDictionary assignment operator
/// Copies the dictionary specified on the right side of the
/// operator into the dictionary on the left side.
//------------------------------------------------------------------------
template <class TKey, class TObject> TDictionary<TKey, TObject>&
TDictionary<TKey, TObject>::operator= (const TDictionary<TKey, TObject>& dict)
{
	return (TDictionary<TKey, TObject>&)
		TDLinkedList< TAssociation<TKey, TObject> >::operator= (dict);
}


// -----------------------------------------------------------------
// TDictionary addKey
/// A new association between the specified key and
///	a default constructed object value gets added.
// -----------------------------------------------------------------
template <class TKey, class TObject>
bool TDictionary<TKey, TObject>::addKey (const TKey& rKey)
{
	TAssociation<TKey, TObject> assoc (rKey);
	return (this->contains (assoc)) ? false : this->add (assoc);
}


//------------------------------------------------------------------------
// TDictionary addKeyAndObject
/// Adds a new association of specified key and object to the dicitonary.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool TDictionary<TKey, TObject>::addKeyAndObject (const TKey& rKey, const TObject& rObj)
{
	TAssociation<TKey, TObject> assoc (rKey, rObj);
	return (this->contains (assoc)) ? false : this->add (assoc);
}


//------------------------------------------------------------------------
// TDictionary addAssoc
/// Adds the specified association to the dictionary.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool TDictionary<TKey, TObject>::addAssoc (const TAssociation<TKey, TObject>& rAssoc)
{
	return (this->contains (rAssoc)) ? false : this->add (rAssoc);
}


//------------------------------------------------------------------------
// TDictionary replace
/// Finds the first occurrence of an association containing the
/// specified key and replaces its value by the specified object value.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool TDictionary<TKey, TObject>::replace (const TKey& rKey, const TObject& rObj)
{
	if (this->remove (TAssociation<TKey, TObject> (rKey)))
		return this->addKeyAndObject (rKey, rObj);
	else
		return false;
}


//------------------------------------------------------------------------
// TDictionary removeKey
/// Finds the first association at the specified key and
/// removes it if found.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool TDictionary<TKey, TObject>::removeKey (const TKey& rKey)
{
	return this->remove (TAssociation<TKey, TObject> (rKey));
}


//------------------------------------------------------------------------
// TDictionary lookupKey
/// Returns the key of the first occurrence of
/// an association containing the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
const TKey& TDictionary<TKey, TObject>::lookupKey (const TKey& rKey) const
{
	return this->lookup (TAssociation<TKey, TObject> (rKey)).key ();
}


//------------------------------------------------------------------------
// TDictionary lookupObject
/// Returns a copy of the object of the first occurrence
/// of an association containing the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
const TObject& TDictionary<TKey, TObject>::lookupObject (const TKey& rKey) const
{
	return this->lookup (TAssociation<TKey, TObject> (rKey)).object ();
}


//------------------------------------------------------------------------
// TDictionary lookupAssoc
/// Returns a copy of the first occurrence of an association
/// containing the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject> const TAssociation<TKey, TObject>&
TDictionary<TKey, TObject>::lookupAssoc (const TKey& rKey) const
{
	return this->lookup (TAssociation<TKey, TObject> (rKey));
}


//------------------------------------------------------------------------
// TDictionary containsKey
/// Returns true if the dictionary contains an association
/// with the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool TDictionary<TKey, TObject>::containsKey (const TKey& rKey) const
{
	return this->contains (TAssociation<TKey, TObject> (rKey));
}


//------------------------------------------------------------------------
// TDictionary occurencesOfKey
/// Returns the number of associations containing
/// the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
int32 TDictionary<TKey, TObject>::occurrencesOfKey (const TKey& rKey) const
{
	return this->occurrences (TAssociation<TKey, TObject> (rKey));
}

//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// THashDictionary default constructor
//------------------------------------------------------------------------
template <class TKey, class TObject>
THashDictionary<TKey, TObject>::THashDictionary (THashFunc hashFunc, int32 size)
: THashTable< TAssociation<TKey, TObject> > (hashFunc, size)
{}


//------------------------------------------------------------------------
// THashDictionary copy constructor
/// Creates a new dictionary and assigns it with a copy of the specified dictionary.
//------------------------------------------------------------------------
template <class TKey, class TObject>
THashDictionary<TKey, TObject>::THashDictionary (const THashDictionary<TKey, TObject>& dict)
: THashTable< TAssociation<TKey, TObject> > (dict)
{}


//------------------------------------------------------------------------
// THashDictionary assignment operator
/// Copies the dictionary specified on the right side of the
/// operator into the dictionary on the left side.
//------------------------------------------------------------------------
template <class TKey, class TObject> THashDictionary<TKey, TObject>&
THashDictionary<TKey, TObject>::operator= (const THashDictionary<TKey, TObject>& dict)
{
	return (THashDictionary<TKey, TObject>&)
		THashTable< TAssociation<TKey, TObject> >::operator= (dict);
}


//------------------------------------------------------------------------
// THashDictionary addKey
/// A new association between the specified key and
/// a default constructed object value gets added.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool THashDictionary<TKey, TObject>::addKey (const TKey& rKey)
{
	TAssociation<TKey, TObject> assoc (rKey);
	return (this->contains (assoc)) ? false : this->add (assoc);
}


//------------------------------------------------------------------------
// THashDictionary addKeyAndObject
/// Adds a new association of specified key and object to the dictionary.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool THashDictionary<TKey, TObject>::addKeyAndObject (const TKey& rKey, const TObject& rObj)
{
	TAssociation<TKey, TObject> assoc (rKey, rObj);
	return (this->contains (assoc)) ? false : this->add (assoc);
}


//------------------------------------------------------------------------
// THashDictionary addAssoc
/// Adds the specified association to the dictionary.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool THashDictionary<TKey, TObject>::addAssoc (const TAssociation<TKey, TObject>& rAssoc)
{
	return (this->contains (rAssoc)) ? false : this->add (rAssoc);
}


//------------------------------------------------------------------------
// THashDictionary replace
/// Finds the first occurrence of an association containing the
/// specified key and replaces its value by the specified object value.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool THashDictionary<TKey, TObject>::replace (const TKey& rKey, const TObject& rObj)
{
	if (this->remove (TAssociation<TKey, TObject> (rKey)))
		return this->addKeyAndObject (rKey, rObj);
	else
		return false;
}


//------------------------------------------------------------------------
// THashDictionary removeKey
/// Finds the first association at the specified key and
/// removes it if found.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool THashDictionary<TKey, TObject>::removeKey (const TKey& rKey)
{
	return this->remove (TAssociation<TKey, TObject> (rKey));
}


//------------------------------------------------------------------------
// THashDictionary lookupKey
/// Returns the key of the first occurrence of
/// an association containing the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
const TKey& THashDictionary<TKey, TObject>::lookupKey (const TKey& rKey) const
{
	return this->lookup (TAssociation<TKey, TObject> (rKey)).key ();
}


//------------------------------------------------------------------------
// THashDictionary lookupObject
/// Returns a copy of the object of the first occurrence
/// of an association containing the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
const TObject& THashDictionary<TKey, TObject>::lookupObject (const TKey& rKey) const
{
	return this->lookup (TAssociation<TKey, TObject> (rKey)).object ();
}


//------------------------------------------------------------------------
// THashDictionary lookupAssoc
/// Returns a copy of the first occurrence of an association
/// containing the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject> const TAssociation<TKey, TObject>&
THashDictionary<TKey, TObject>::lookupAssoc (const TKey& rKey) const
{
	return this->lookup (TAssociation<TKey, TObject> (rKey));
}


//------------------------------------------------------------------------
// THashDictionary containsKey
/// Returns true if the dictionary contains an association
/// with the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
bool THashDictionary<TKey, TObject>::containsKey (const TKey& rKey) const
{
	return this->contains (TAssociation<TKey, TObject> (rKey));
}


//------------------------------------------------------------------------
// THashDictionary
/// Returns the number of associations containing
/// the specified key.
//------------------------------------------------------------------------
template <class TKey, class TObject>
int32 THashDictionary<TKey, TObject>::occurrencesOfKey (const TKey& rKey) const
{
	return this->occurrences (TAssociation<TKey, TObject> (rKey));
}

} // namespace

#endif
