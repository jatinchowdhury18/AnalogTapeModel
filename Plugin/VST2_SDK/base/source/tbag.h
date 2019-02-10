//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/tbag.h
// Created by  : Steinberg, 01/2009
// Description : Bag class template
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

#ifndef __tbag__
#define __tbag__

#include "base/source/thashtable.h"
#include "base/source/thashset.h"

namespace Steinberg 
{

//------------------------------------------------------------------------
// Bag template declaration
//------------------------------------------------------------------------
/** Bag template.

	\ingroup baseContainer
	A bag is a hash table that adds a few convenient functions to the super class,
	regarding the handling of identical items
	\see THashTable, THashSet
*/
template <class T> class TBag : public THashTable<T>
{
public:
	typedef uint32 (*THashFunc) (const T&, uint32);   ///< Hash function type.
//------------------------------------------------------------------------
	TBag (int32 size = 10);
	TBag (THashFunc hashFunction, int32 size = 10);
	TBag (THashTable<T>& hashTable);
	TBag (THashFunc hashFunction, const TContainer<T>& container);

	TBag<T>& operator= (const THashTable<T>& hashTable);

	virtual bool add (const T& item);
	virtual bool add (const T& item, int32 numCopies);

	virtual bool remove (const T& item);
	virtual bool remove (const T& item, int32 numCopies);
	virtual void removeAll (const T& item);
	virtual void removeAll ();

	int32 getCount (const T& item);

	THashSet<T>* createUniqueSet ();
};

//------------------------------------------------------------------------
/** Bag constructor.
	Before using this bag, a hash function has to be assigned via the
	THashTable<T>::setHashFunction() method
	\param[in] _size - initial size of the container */
//------------------------------------------------------------------------
template <class T> TBag<T>::TBag (int32 _size /*= 10*/)
: THashTable<T> (_size)
{
}

//------------------------------------------------------------------------
/** Bag constructor with a specified hash function.
	\param[in] hashFunction - hash function
	\param[in] _size - initial size of the container */
//------------------------------------------------------------------------
template <class T> TBag<T>::TBag (THashFunc hashFunction, int32 _size /*= 10*/)
: THashTable<T> (hashFunction, _size)
{
}

//------------------------------------------------------------------------
/** Bag copy constructor.
	\param[in] hashTable - hashTable to copy (including the hash function) */
//------------------------------------------------------------------------
template <class T> TBag<T>::TBag (THashTable<T>& hashTable)
: THashTable<T> (hashTable)
{}

//------------------------------------------------------------------------
/** Bag constructor with a specified hash function and a container.
	\param[in] hashFunction - hash function
	\param[in] container - container, which will be used to construct the bag */
//------------------------------------------------------------------------
template <class T> TBag<T>::TBag (THashFunc hashFunction, const TContainer<T>& container)
: THashTable<T> (hashFunction, container)
{
}

//------------------------------------------------------------------------
/** Assignment operator.
	\param[in] hashTable - hashTable to copy (including the hash function) */
//------------------------------------------------------------------------
template <class T> TBag<T>& TBag<T>::operator= (const THashTable<T>& hashTable)
{
	return (TBag<T>&) THashTable<T>::operator= (hashTable);
}

//------------------------------------------------------------------------
/** Adds a new item to the bag.
	\param[in] item - item to add
	\return true, if item was added successfully, else false */
//------------------------------------------------------------------------
template <class T> bool TBag<T>::add (const T& item)
{
	return THashTable<T>::add (item);
}

//------------------------------------------------------------------------
/** Adds a number of copies of a new item to the bag.
	\param[in] item - item to add
	\param[in] numCopies - number of copies
	\return true, if items were added successfully, else false */
//------------------------------------------------------------------------
template <class T> bool TBag<T>::add (const T& item, int32 numCopies)
{
	bool result = true;
	for (int32 i = 0; i < numCopies; i++)
	{
		if (add (item) == false)
			result = false;
	}
	return result;
}

//------------------------------------------------------------------------
/** Removes the first occurrence of an item from the bag.
	\param[in] item - item to remove
	\return true, if item was removed successfully, else false */
//------------------------------------------------------------------------
template <class T> bool TBag<T>::remove (const T& item)
{
	return THashTable<T>::remove (item);
}

//------------------------------------------------------------------------
/** Removes a number of copies of an item from the bag.
	\param[in] item - item to remove
	\param[in] numCopies - number of copies
	\return true, if items were removed successfully, else false */
//------------------------------------------------------------------------
template <class T> bool TBag<T>::remove (const T& item, int32 numCopies)
{
	bool result = true;
	if (numCopies > 0)
	{
		for (int32 i = 0; i < numCopies; i++)
		{
			if (remove (item) == false)
				result = false;
		}
	}
	return result;
}

//------------------------------------------------------------------------
/** Removes all occurrences of the specific item from the bag.
	\param[in] item - item to remove
	\return true, if all occurrences were removed successfully, else false */
//------------------------------------------------------------------------
template <class T> void TBag<T>::removeAll (const T& item)
{
	remove (item, getCount (item));
}

//------------------------------------------------------------------------
/** Removes all items from the bag. */
//------------------------------------------------------------------------
template <class T> void TBag<T>::removeAll ()
{
	THashTable<T>::removeAll ();
}

//------------------------------------------------------------------------
/** Number of occurrences (cardinality) of the given item.
	\param[in] item - item to count
	\return number of occurrences */
//------------------------------------------------------------------------
template <class T> int32 TBag<T>::getCount (const T& item)
{
	return occurrences (item);
}

//------------------------------------------------------------------------
/** Creates a hash set of unique items.
	The hash set contains exactly one copy of each item in the bag
	\return hash set */
//------------------------------------------------------------------------
template <class T> THashSet<T>* TBag<T>::createUniqueSet ()
{
	THashSet<T>* result = NEW THashSet<T> ();
	result->operator= (*this);

	return result;
}

} // namespace Steinberg

#endif // __tbag__
