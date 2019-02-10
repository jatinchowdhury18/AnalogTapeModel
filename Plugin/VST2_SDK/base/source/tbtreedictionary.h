//------------------------------------------------------------------------ 
// Project     : SDK Base
// Version     : 1.0
// 
// Category	   : Helpers
// Filename    : base/source/tbtreedictionary.h
// Created by  : Steinberg
// Description : B-Tree dictionary class template
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

#ifndef __tbtreedictionary__
#define __tbtreedictionary__

#include "base/source/tbtree.h"
#include "base/source/tassociation.h"

namespace Steinberg {

// -----------------------------------------------------------------
/** B-Tree dictionary template definition.
	@ingroup baseContainer
	
	TBTreeDictionary is a template class for managing (key, object) pairs
	in a TBTree. The (key, object) pairs are stored as TAssociation objects.
	Every key can only be used once in the dictionary.
	For more information about TBTree (which should not be confused with 
	a "binary tree", which is in tbinarytree.h) see the tbtree.h header. */
// -----------------------------------------------------------------
template <class K, class O>
class TBTreeDictionary : public TBTree< TAssociation<K,O> >
{
public:
	TBTreeDictionary (int32 order = 3);						///< Default constructor.
	TBTreeDictionary (const TBTreeDictionary<K,O>& dict);	///< Copy constructor.
	~TBTreeDictionary () {}									///< Destructor.

	TBTreeDictionary<K,O>& operator= (const TBTreeDictionary<K,O>& dict);	///< Assignment operator

	bool addKey (const K& key);								///< Add an association with a key and a default object.
	bool addKeyAndObject (const K& key, const O& object);	///< Add an association with a key and an object.
	bool addAssoc (const TAssociation<K,O>& assoc);			///< Add the passed association.
	bool replace (const K& key, const O& object);			///< Replace the object associated with key with the passed object.
	bool removeKey (const K& key);							///< Remove the association with the key.

	const K& lookupKey (const K& key) const;		///< Returns an equal key contained in the dictionary.
	const O& lookupObject (const K& key) const;		///< Returns the object associated with key.
	bool containsKey (const K& key) const;          ///< Returns if the key is contained in the dictionary.

	const TAssociation<K,O>& lookupAssoc (const K& key) const;  ///< Lookup an association, that has the passed key.
};


// -----------------------------------------------------------------
/*! "TBTreeDictionary" is the default dictionary constructor. 
	\param order the order of the B-Tree is the maximum number of children for each node.
				 Order has to be >= 3. */
// -----------------------------------------------------------------
template <class K, class O>
TBTreeDictionary<K,O>::TBTreeDictionary (int32 order)
: TBTree< TAssociation<K,O> > (order)
{}

// -----------------------------------------------------------------
/* Dictionary copy constructor. */
// -----------------------------------------------------------------
template <class K, class O>
TBTreeDictionary<K,O>::TBTreeDictionary (const TBTreeDictionary<K,O>& dict)
: TBTree< TAssociation<K,O> > (dict)
{}

// -----------------------------------------------------------------
/*! Assignment operator "=" copies the specified dictionary into this
	dictionary. */
// -----------------------------------------------------------------
template <class K, class O> TBTreeDictionary<K,O>&
TBTreeDictionary<K,O>::operator= (const TBTreeDictionary<K,O>& dict)
{
	return (TBTreeDictionary<K,O>&)	TBTree< TAssociation<K,O> >::operator= (dict);
}

// -----------------------------------------------------------------
/*! "addKey" adds an association with the specified key to the dictionary. 
	If the key is already contained in the dictionary nothing is added.
	\return was an association added? */
// -----------------------------------------------------------------
template <class K, class O>
bool TBTreeDictionary<K,O>::addKey (const K& key)
{
	TAssociation<K,O> assoc (key);
	return (contains (assoc)) ? false : add (assoc);
}

// -----------------------------------------------------------------
/*! "addKeyAndObject" adds an association with the specified key and the
	specified object to the dictionary.
	If the key is already contained in the dictionary nothing is added.
	\return was an association added? */
// -----------------------------------------------------------------
template <class K, class O>
bool TBTreeDictionary<K,O>::addKeyAndObject (const K& key, const O& obj)
{
	TAssociation<K,O> assoc (key, obj);
	return (contains (assoc)) ? false : add (assoc);
}

// -----------------------------------------------------------------
/*! "addAssoc" adds the specified association to the dictionary. 
	If the key of the association is already contained in the dictionary
	nothing is added.
	\return was the association added? */
// -----------------------------------------------------------------
template <class K, class O>
bool TBTreeDictionary<K,O>::addAssoc (const TAssociation<K,O>& assoc)
{
	return (contains (assoc)) ? false : add (assoc);
}

// -----------------------------------------------------------------
/*! "replace" finds the first occurrence of an association containing the
	specified key and replaces the object value. 
	If the key is not contained in the dictionary nothing is done.
	\return was the object value of key replaced? */
// -----------------------------------------------------------------
template <class K, class O>
bool TBTreeDictionary<K,O>::replace (const K& key, const O& obj)
{
	if (remove (TAssociation<K,O> (key)))
		return addKeyAndObject (key, obj);
	else
		return false;
}

// -----------------------------------------------------------------
/*! "removeKey" removes the first association containing the specified
	key from the dictionary. 
	\return was an association removed? */
// -----------------------------------------------------------------
template <class K, class O>
bool TBTreeDictionary<K,O>::removeKey (const K& key)
{
	return remove (TAssociation<K,O> (key));
}

// -----------------------------------------------------------------
/*! \return a copy of the key out of the first occurrence of an association
	containing the specified key. If no association with the key is found returns
	the key of the default error object (see error() in TContainer). */
// -----------------------------------------------------------------
template <class K, class O>
const K& TBTreeDictionary<K,O>::lookupKey (const K& key) const
{
	return lookup (TAssociation<K,O> (key)).key ();
}

// -----------------------------------------------------------------
/*! \return a copy of the object out of the first occurrence of an association
	containing the specified key. If no association with the key is found returns
	the object-part of the default error object (see error() in TContainer). */
// -----------------------------------------------------------------
template <class K, class O>
const O& TBTreeDictionary<K,O>::lookupObject (const K& key) const
{
	return lookup (TAssociation<K,O> (key)).object ();
}

// -----------------------------------------------------------------
/*! \return a copy of the first occurrence of an association containing
	the specified key. If no association with the key is found returns
	the default error object (see error() in TContainer). */
// -----------------------------------------------------------------
template <class K, class O> const TAssociation<K,O>&
TBTreeDictionary<K,O>::lookupAssoc (const K& key) const
{
	return lookup(TAssociation<K,O> (key));
}

// -----------------------------------------------------------------
/*! \return does the dictionary contain an association with the specified key? */
// -----------------------------------------------------------------
template <class K, class O>
bool TBTreeDictionary<K,O>::containsKey (const K& key) const
{
	return contains (TAssociation<K,O> (key));
}

}

#endif
