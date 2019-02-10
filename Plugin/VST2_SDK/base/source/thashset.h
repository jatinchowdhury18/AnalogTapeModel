//------------------------------------------------------------------------ 
// Project     : SDK Base
// Version     : 1.0
// 
// Category	   : Helpers
// Filename	   : base/source/thashset.h
// Created by  : Steinberg, 04/2008
// Description : Hash Set class Template based on Hash Table class template
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

#ifndef __thashset__
#define __thashset__

#include "base/source/thashtable.h"

namespace Steinberg {

//-------------------------------------------------------------------------------------
/** @class THashSet
	@ingroup baseContainer
	A hash set is a collection of items, without any particular order and without 
	repetitions stored in a hash table. A hash table stores its items in hash buckets 
	whose pointers are stored in an array at the index given by the hash function, 
	which is a integer function of the item. The buckets are necessary to hold all items 
	with the same hash index. 
	@see THashTable
*/
//-------------------------------------------------------------------------------------
template <class T> class THashSet : public THashTable<T>
{
public:
	typedef uint32 (*THashFunc) (const T&, uint32);		///< Hash function type.
// -----------------------------------------------------------------
	THashSet(int32 = 10);								///< Default constructor, size = number of buckets.
	THashSet(THashFunc, int32 = 10);					///< Constructor with hash function, size = number of buckets.
	THashSet(const THashSet<T>&);						///< Copy constructor - uses copy, copy used add.
	THashSet(THashFunc, const TContainer<T>&);			///< Container with hash function and container to copy.
	~THashSet() {}										///< Destructor.

	THashSet<T>& operator=(const THashTable<T>&);		///< Assignment operator, uses copy.

	THashSet<T> operator-(const THashSet<T>&) const;	///< Difference operator.
	THashSet<T> operator&(const THashSet<T>&) const;	///< Intersection operator.
	THashSet<T> operator|(const THashSet<T>&) const;	///< Union operator.

	bool add(const T&);									///< Add item to set if not already contained.
};

// -----------------------------------------------------------------
// "THashSet" is the default set constructor.
// -----------------------------------------------------------------
/*!	@param[in] size Number of buckets in the new hash set. */
//-------------------------------------------------------------------------------------
template <class T>
THashSet<T>::THashSet(int32 size)
: THashTable<T>(size)
{}


// -----------------------------------------------------------------
// "THashSet" constructs a set which will use the specified function
// for hashing.
// -----------------------------------------------------------------
/*! @param[in] func Hash function the hash set uses.
	@param[in] size Number of buckets in the new hash set */
//-------------------------------------------------------------------------------------
template <class T>
THashSet<T>::THashSet(THashFunc func, int32 size)
: THashTable<T>(func, size)
{}


// -----------------------------------------------------------------
// "THashSet" is the set copy constructor.
// -----------------------------------------------------------------
/*! @param[in] set Hash set to copy. */
//-------------------------------------------------------------------------------------
template <class T>
THashSet<T>::THashSet(const THashSet<T>& set)
: THashTable<T>(set)
{}


// -----------------------------------------------------------------
// "THashSet" constructs a set from the specified container.
// -----------------------------------------------------------------
/*! @param[in] func Hash function the set uses.
	@param[in] cont Container to construct the table from. */
//-------------------------------------------------------------------------------------
template <class T>
THashSet<T>::THashSet(THashFunc func, const TContainer<T>& cont)
: THashTable<T>(func, cont.size())
{
	copy(cont);
}


// -----------------------------------------------------------------
// "=" assignment operator copies the specified set into this set.
// -----------------------------------------------------------------
/*! @param[in] table Assign input set or table to this set.
	@return Assigned hash set reference. */
//-------------------------------------------------------------------------------------
template <class T>
THashSet<T>& THashSet<T>::operator=(const THashTable<T>& table)
{
	return (THashSet<T>&) THashTable<T>::operator=(table);
}


// -----------------------------------------------------------------
// "-" difference operator returns a set containing those items
// appearing in this set that have no equal in the specified set.
// -----------------------------------------------------------------
/*! @param[in] set Contains items to be subtracted.
	@return Hash set containing those items appearing in this set 
	that have no equal in the specified set. */
//------------------------------------------------------------------
template <class T>
THashSet<T> THashSet<T>::operator-(const THashSet<T>& set) const
{
	THashSet<T> out;
	out.setHashFunction(this->_hFunc);
	THashTableIterator<T> iter1(*this);
	
	bool success = true;
	while (!iter1.done() && success)
	{
		const T& item = iter1.next();
		if (!set.lookup(item))
			success = out.add(item);
	}
	return out;
}


// -----------------------------------------------------------------
// "&" intersection operator returns a set containing only those
// items appearing in this set and the input set.
// -----------------------------------------------------------------
/*! @param[in] set Contains items to be intersected.
	@return Hash set containing those items appearing in this set 
	and the input set. */
//------------------------------------------------------------------
template <class T>
THashSet<T> THashSet<T>::operator&(const THashSet<T>& set) const
{
	THashSet<T> out;
	out.setHashFunction(this->_hFunc);
	THashTableIterator<T> iter(*this);
	
	bool  success = true;
	while (!iter.done() && success)
	{
		const T& item = iter.next();
		if (set.lookup(item))
			success = out.add(item);
	}
	return out;
}


// -----------------------------------------------------------------
// "|" union operator returns a set containing those items
// appearing in this set, the input set, or both sets.
// -----------------------------------------------------------------
/*! @param[in] set Contains items to be united.
	@return Hash set containing those items appearing in this set 
	or the input set. */
//------------------------------------------------------------------
template <class T>
THashSet<T> THashSet<T>::operator|(const THashSet<T>& set) const
{
	THashSet<T> out;
	out.setHashFunction(this->_hFunc);
	THashTableIterator<T> iter1(*this);
	while (!iter1.done())
		out.add(iter1.next());

	THashTableIterator<T> iter2(set);
	while (!iter2.done())
		out.add(iter2.next());
	return out;
}


// -----------------------------------------------------------------
// "add" adds a new item to this set making sure not to duplicate an
// existing item.
// -----------------------------------------------------------------
/*! @param[in] item Item that will be added if no similar item is 
	already contained by the set. */
// -----------------------------------------------------------------
template <class T>
bool THashSet<T>::add(const T& item)
{
	return (contains(item)) ? false : THashTable<T>::add(item);
}

}

#endif
