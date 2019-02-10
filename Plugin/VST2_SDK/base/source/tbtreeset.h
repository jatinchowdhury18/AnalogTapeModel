//------------------------------------------------------------------------ 
// Project     : SDK Base
// Version     : 1.0
// 
// Category	   : Helpers
// Filename    : base/source/tbtreeset.h
// Created by  : Steinberg
// Description : B-Tree set class template
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

#ifndef __tbtreeset__
#define __tbtreeset__

#include "base/source/tbtree.h"

namespace Steinberg {

// -----------------------------------------------------------------
/** B-Tree set template definition.
	@ingroup baseContainer
	TBTreeSet is a template class for managing unique items in a TBTree.
	Every item can only be inserted once in the set.
	For more information about TBTree (which should not be confused with 
	a "binary tree", which is in tbinarytree.h) see the tbtree.h header. */
// -----------------------------------------------------------------
template <class T> 
class TBTreeSet : public TBTree<T>
{
public:
// -----------------------------------------------------------------
	TBTreeSet (int32 order = 3);				///< Default constructor.
	TBTreeSet (const TBTreeSet<T>& set);		///< Copy constructor.
	TBTreeSet (const TContainer<T>& container);	///< Construct a set from the elements of the container.
	~TBTreeSet() {}								///< Destructor.

	TBTreeSet<T>& operator= (const TBTreeSet<T>& set);		///< Assignment operator.

	TBTreeSet<T> operator- (const TBTreeSet<T>& set) const; ///< Set difference.
	TBTreeSet<T> operator& (const TBTreeSet<T>& set) const; ///< Set intersection.
	TBTreeSet<T> operator| (const TBTreeSet<T>& set) const; ///< Set union.

	bool add (const T& item); ///< Add item to set.
};


// -----------------------------------------------------------------
/*! "TBTreeSet" is the default set constructor.
	\param order the order of the B-Tree is the maximum number of children for each node.
				 Order has to be >= 3. */
// -----------------------------------------------------------------
template <class T>
TBTreeSet<T>::TBTreeSet (int32 order)
: TBTree<T> (order)
{}

// -----------------------------------------------------------------
/* Set copy constructor. */
// -----------------------------------------------------------------
template <class T> 
TBTreeSet<T>::TBTreeSet (const TBTreeSet<T>& set)
: TBTree<T> (set)
{}

// -----------------------------------------------------------------
/*! Constructs a TBTreeSet of order 3 from the specified container by copying
	all elements of the container into the set. Elements, that appear multiple
	times in the container will only be once in the set. 
	\param container the source container.*/
// -----------------------------------------------------------------
template <class T> 
TBTreeSet<T>::TBTreeSet (const TContainer<T>& container)
: TBTree<T> (3)
{
	copy (container);
}

// -----------------------------------------------------------------
/*! Assignment operator copies the specified set into this set. */
// -----------------------------------------------------------------
template <class T>
TBTreeSet<T>& TBTreeSet<T>::operator= (const TBTreeSet<T>& set)
{
	return (TBTreeSet<T>&) TBTree<T>::operator= (set);
}

// -----------------------------------------------------------------
/*! "-" difference operator returns a set containing those items, that
	appear in this set, but that have no equal in the specified set.
	\param set the set that will be subtracted from this
	\return a new set containing all items, that are in this set, 
			but not in the specified set. */
// -----------------------------------------------------------------
template <class T>
TBTreeSet<T> TBTreeSet<T>::operator- (const TBTreeSet<T>& set) const
{
	TBTreeSet<T> result;
	TBTreeIterator<T> iter (*this);
	bool success = true;
	
	while (!iter.done () && success)
	{
		const T& item = iter.next ();
		if (!set.contains (item))
			success = result.add (item);
	}
	return result;
}

// -----------------------------------------------------------------
/*! "&" intersection operator returns a set containing only those
	items, that appear in this set and the input set.
	\param set the set that will be intersected with this
	\return a new set containing all items, that are in both sets. */
// -----------------------------------------------------------------
template <class T>
TBTreeSet<T> TBTreeSet<T>::operator& (const TBTreeSet<T>& set) const
{
	TBTreeSet<T> result;
	TBTreeIterator<T> iter (*this);
	bool success = true;
	
	while (!iter.done () && success)
	{
		const T& item = iter.next ();
		if (set.contains (item))
			success = result.add (item);
	}
	return result;
}

// -----------------------------------------------------------------
/*! "|" union operator returns a set containing those items, that
	appear in this set or the input set or both sets. 
	\param set the set that will be unified with this. 
	\return a new set containing all items, that are in this set or
			in the input set or in both sets. */
// -----------------------------------------------------------------
template <class T>
TBTreeSet<T> TBTreeSet<T>::operator| (const TBTreeSet<T>& set) const
{
	TBTreeSet<T> result;
	TBTreeIterator<T> iterThis (*this);
	while (!iterThis.done ())
		result.add (iterThis.next ());

	TBTreeIterator<T> iterOther (set);
	while (!iterOther.done ())
		result.add (iterOther.next ());

	return result;
}

// -----------------------------------------------------------------
/*! "add" adds a new item to this set. If it would be a duplicate,
	nothing is added.
	\param item the item to add
	\return was the item added successfully? */
// -----------------------------------------------------------------
template <class T>
bool TBTreeSet<T>::add (const T& item)
{
	return (this->contains (item)) ? false : TBTree<T>::add (item);
}

}
#endif
