//-------------------------------------------------------------------------------------
// Project      : SDK Base
// Version      : 1.0
//
// Category	    : Helpers
// Filename	    : base/source/tarray.h
// Created by   : Steinberg, 01/1998
// Description  : Array class template
//
//-------------------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------

#ifndef __tarray__
#define __tarray__

#include "base/source/tcontainer.h"
#include <stdlib.h> // for qsort

namespace Steinberg {

template <class T> class TArrayIterator; 

//------------------------------------------------------------------------
/** Template array base class.
@ingroup baseContainer
@see TArray, TOrderedArray, TSortableArray, TArrayIterator*/
//------------------------------------------------------------------------
template <class T>
class TArrayBase : public TContainer<T>
{
public:
//------------------------------------------------------------------------
	static const int32 kDefaultDelta = 10;
	static const int32 kExponentialDelta = -1;

	TArrayBase (int32 initSize = 0, int32 delta = kDefaultDelta);
	~TArrayBase ();
	TArrayBase<T>& operator= (const TArrayBase<T>&);	

	void delta (int32 d);								///< Set delta value.
	int32 delta () const;								///< Get delta value.
	void enableExponentialGroth (bool state);			///< Instead of using delta, always double the array size
	bool hasExponentialGroth () const;

	bool resize (int32 newSize);						///< Resize the array.
	
	virtual int32 total () const;						///< @copydoc TContainer::total
	virtual bool isEmpty () const;						///< @copydoc TContainer::isEmpty

	virtual bool add (const T&);						///< @copydoc TContainer::add
	virtual bool remove (const T&);						///< @copydoc TContainer::remove
	virtual bool remove (const TIterator<T>&);			///< @copydoc TContainer::remove(const TIterator<T>&)
	virtual bool removeAt (int32 index);				///< @copydoc TContainer::removeAt
	virtual void removeAll ();							///< @copydoc TContainer::removeAll
	bool removeRange (int32 from, int32 to);			///< Remove items from index 'from' to index 'to'.

	virtual T& at (int32) const;						///< @copydoc TContainer::at
	virtual T& lookup (const T& item) const;			///< @copydoc TContainer::lookup
	virtual bool contains (const T& item) const;		///< @copydoc TContainer::contains
	virtual int32 occurrences (const T& item) const;	///< @copydoc TContainer::occurrences

	virtual TIterator<T>* newIterator () const;			///< @copydoc TContainer::newIterator

	virtual int32 shouldGo (const T& item) const = 0;   ///< Get index for potential item.
	virtual int32 index (const T& item) const = 0;		///< Get index of item.

	T& first () const {return at (0);}
	T& last () const {return at (total ()-1);}

//------------------------------------------------------------------------
protected:
	// sorting support
	static int cmpData (const void*, const void*);		///< Quick sort compare function.
	int32 indexSorted (const T&) const;
	int32 indexUnsorted (const T&) const;
	int32 shouldGoSorted (const T&) const;				///< Get index for potential item.
	int32 shouldGoUnsorted (const T&) const;			///< Get index for potential item.

	void doQuickSort ();
	bool doInsertAt (int32 index, const T&);			///< Insert item at index.

	int32 _delta;										///< Delta value.
	int32 _total;										///< Number of items.
	T* _entries;										///< Array of "T" pointers.

	friend class TArrayIterator<T>;
};

//------------------------------------------------------------------------
/** Array container template. This container is intended for 
items that can or should not be sorted.
@ingroup baseContainer
@see TOrderedArray, TSortableArray, TArrayIterator*/
//------------------------------------------------------------------------
template <class T>
class TArray : public TArrayBase<T>
{
public:
//------------------------------------------------------------------------
	TArray (int32 initSize = 0, int32 delta = TArrayBase<T>::kDefaultDelta) : TArrayBase<T> (initSize, delta) {}
	TArray (const TArray<T>& a) : TArrayBase<T> (a.size (), a.delta ()) { this->copy (a); }
	TArray (const TContainer<T>& c): TArrayBase<T> (c.total ()) { this->copy (c); }
	using TArrayBase<T>::operator=;

	virtual TContainer<T>* newInstance () const {return NEW TArray<T> ();}           ///< @copydoc TArrayBase::newInstance
	virtual int32 index (const T& t)  const {return this->indexUnsorted (t);}              ///< @copydoc TArrayBase::index
	virtual int32 shouldGo (const T& t) const {return this->shouldGoUnsorted (t);}         ///< @copydoc TArrayBase::shouldGo

	bool insertAt (int32 index, const T& t) {return this->doInsertAt (index, t);}          ///< Insert the item at the specified index shifting the other items to make room       
	bool replaceAt (int32 index, const T& item);	                                 ///< Replace item at index.
	void quickSort () {this->doQuickSort ();}	                                     ///< Quick sort the array.
};

//------------------------------------------------------------------------
/** Ordered Array container template. This class always adds items sorted.
@ingroup baseContainer 
@see TArray, TSortableArray, TArrayIterator */
//------------------------------------------------------------------------
template <class T>
class TOrderedArray : public TArrayBase<T>
{
public:
//------------------------------------------------------------------------
	TOrderedArray (int32 initSize = 0, int32 delta = TArrayBase<T>::kDefaultDelta) : TArrayBase<T> (initSize, delta) {}
	TOrderedArray (const TOrderedArray<T>& a) : TArrayBase<T> (a.size (), a.delta ()) { this->copy (a);}
	TOrderedArray (const TContainer<T>& c): TArrayBase<T> (c.total ()) { this->copy (c);}
	using TArrayBase<T>::operator=;

	virtual TContainer<T>* newInstance () const {return NEW TOrderedArray<T> ();}			///< @copydoc TArrayBase::newInstance

	virtual int32 index (const T& t) const {return this->indexSorted (t);}                  ///< @copydoc TArrayBase::index
	virtual int32 shouldGo (const T& t) const {return this->shouldGoSorted (t);}            ///< @copydoc TArrayBase::shouldGo
};

//------------------------------------------------------------------------
/** Sortable Array container template. Sorting can be switched on and off
during runtime.
@ingroup baseContainer 
@see TArray, TOrderedArray, TArrayIterator */
//------------------------------------------------------------------------
template <class T>
class TSortableArray : public TArrayBase<T>
{
public:
//------------------------------------------------------------------------
	TSortableArray (int32 initSize = 0, int32 delta = TArrayBase<T>::kDefaultDelta) : TArrayBase<T> (initSize, delta), sorting (false) {}
	TSortableArray (const TSortableArray<T>& a) : TArrayBase<T> (a.size (), a.delta ()), sorting (a.sorting) { this->copy (a);}
	TSortableArray (const TContainer<T>& c) : TArrayBase<T> (c.total ()), sorting (false) { this->copy (c);}
	using TArrayBase<T>::operator=;

	void enableSorting (bool state);                                       ///< Enable or disable sorting
	bool sortingEnabled () const {return sorting;}                         ///< Tell if sorting is currently enabled

	virtual TContainer<T>* newInstance () const {return NEW TSortableArray<T> ();}                          ///< @copydoc TArrayBase::newInstance
	virtual int32 index (const T& t) const {return sorting ? this->indexSorted (t) : this->indexUnsorted (t);}          ///< @copydoc TArrayBase::index
	virtual int32 shouldGo (const T& t) const {return sorting ? this->shouldGoSorted (t) : this->shouldGoUnsorted (t);} ///< @copydoc TArrayBase::shouldGo
private:
	bool sorting;
};


//------------------------------------------------------------------------
/** Iterator for array template container
@see TArrayBase, TArray, TOrderedArray, TSortableArray */
//------------------------------------------------------------------------
template <class T>
class TArrayIterator : public TIterator<T>
{
public:
//------------------------------------------------------------------------
	TArrayIterator (const TArrayBase<T>& arr)
	: TIterator<T>(arr), _index (0) {}		///< Iterator constructor.

	virtual bool done () const;				///< @copydoc TIterator::done
	virtual T& next ();						///< @copydoc TIterator::next
	virtual T& previous ();					///< @copydoc TIterator::previous
	virtual T& current () const;			///< @copydoc TIterator::current
	virtual void first ();					///< @copydoc TIterator::first
	virtual void last ();					///< @copydoc TIterator::last

	const TArrayBase<T>& array () const;	///< Return array reference.

private:
	int32 _index;							///< Current array index.
};

//------------------------------------------------------------------------
//------------------------------------------------------------------------
// SPECIAL ARRAY ITERATION MACROS
//------------------------------------------------------------------------
//------------------------------------------------------------------------
/*! 
@addtogroup baseContainer
@{
*/

/** Special array iteration macro - can be used like \ref FOREACH_T only that type is assumed to be a pointer */
#define ARRAY_FOR_EACH_TYPE(type, obj, containter)                     \
{ for (int32 i = 0; i < containter.total (); i++)                      \
{ type* obj = containter.at (i);                      \
if (!obj) continue;

/** Special array iteration macro - can be used instead of \ref FOREACH_T_REVERSE only that type is assumed to be a pointer */
#define ARRAY_FOR_EACH_TYPE_REVERSE(type, obj, containter)             \
{ for (int32 i = containter.total () - 1; i >= 0 ; i--)                \
{ type* obj = containter.at (i);                      \
if (!obj) continue;

/** Special array iteration macro - Version with explicit loop variable index. */
#define ARRAY_FOR_EACH_TYPE_I(type, obj, containter, index)            \
{ for (int32 index = 0; index < containter.total (); index++)          \
{ type* obj = containter.at (index);                  \
if (!obj) continue;

/** Special array iteration macro - Like ARRAY_FOR_EACH_TYPE_I only backwards */
#define ARRAY_FOR_EACH_TYPE_REVERSE_I(type, obj, containter, index)    \
{ for (int32 index = containter.total () - 1; index >= 0 ; index--)    \
{ type* obj = containter.at (index);                  \
if (!obj) continue;

/*! @} */


//------------------------------------------------------------------------
//------------------------------------------------------------------------
// -- IMPLEMENTATION
//------------------------------------------------------------------------
//------------------------------------------------------------------------

// -----------------------------------------------------------------
/*! "TArrayBase" is the default constructor.
	\param sz   : initial size of array
	\param dt : initial delta value for automatic growing. */
// -----------------------------------------------------------------

template <class T>
TArrayBase<T>::TArrayBase (int32 sz, int32 dt)
: _delta (dt)
, _total (0)
{
	_entries = (sz > 0) ? NEWVEC T[sz] : 0;
	this->_size    = (_entries) ? sz : 0;
}

//------------------------------------------------------------------------
template <class T>
TArrayBase<T>::~TArrayBase ()
{
	if (_entries)
		delete[] _entries;
}

//------------------------------------------------------------------------
/*! "=" assignment operator copies the specified array into this array. */
//------------------------------------------------------------------------
template <class T>
TArrayBase<T>& TArrayBase<T>::operator=(const TArrayBase<T>& arr)
{
	if (&arr != this)
	{
		delete[] _entries;
		_delta = arr._delta;
		_total = 0;
		_entries = (arr._size > 0) ? NEWVEC T[arr._size] : 0;
		this->_size = (_entries) ? arr._size : 0;
		this->copy (arr);
	}
	return *this;
}

//------------------------------------------------------------------------
/*! "delta" sets a new delta value for automatic growing. */
//------------------------------------------------------------------------
template <class T>
void TArrayBase<T>::delta (int32 dt)
{
	_delta = dt;
}

//------------------------------------------------------------------------
/*! "delta" returns the current delta value. */
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::delta () const
{
	return _delta;
}

//------------------------------------------------------------------------
template <class T>
inline void TArrayBase<T>::enableExponentialGroth (bool state)
{
	if (state)
		_delta = kExponentialDelta;
	else
		_delta = kDefaultDelta;
}

//------------------------------------------------------------------------
template <class T>
inline bool TArrayBase<T>::hasExponentialGroth () const
{
	return _delta == kExponentialDelta;
}

//------------------------------------------------------------------------
/*! "total" returns the number of items in this array. */
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::total () const
{
	return _total;
}

//------------------------------------------------------------------------
/*! "resize" resizes the storage allocated for this array. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::resize (int32 newsize)
{
	T *newentries = 0;
	if (newsize == 0)
		removeAll ();

	else
	{
		newentries = NEWVEC T[newsize];
		if (!newentries)
			return false;

		if (newsize < _total)
			_total = newsize;

		for (int32 ii = 0; ii < _total; ii++)
			newentries[ii] = _entries[ii];
	}

	if (_entries)
		delete[] _entries;
	_entries = newentries;
	this->_size = newsize;
	return true;
}

//------------------------------------------------------------------------
/*! "isEmpty" returns whether or not this array has any items in it. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::isEmpty () const
{
	return (_total == 0) ? true : false;
}

//------------------------------------------------------------------------
/*! "add" appends the specified item to this array. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::add (const T& rObj)
{
	return doInsertAt (shouldGo (rObj), rObj);
}

//------------------------------------------------------------------------
/*! inserts the specified item at the specified index shifting the other items to make room. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::doInsertAt (int32 idx, const T& rObj)
{
	if (idx < 0 || idx > _total)
		return false;

	if (_total >= this->_size)
	{
		if (_delta <= 0 && _delta != kExponentialDelta)
			return false;

		int32 newSize = 0;
		if (hasExponentialGroth ())
			newSize = this->_size > 0 ? this->_size * 2 : kDefaultDelta;
		else
			newSize = this->_size + _delta;

		if (resize (newSize) == false)
			return false;
	}

	if (!_entries)
		return false;

	for (int32 ii = _total; ii > idx; ii--)
		_entries[ii] = _entries[ii - 1];
	_entries[idx] = rObj;
	_total++;
	return true;
}

//------------------------------------------------------------------------
/*! "remove" removes the first occurrence of an item equal to the specified
	item in the array. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::remove (const T& rObj)
{
	if (_total == 0)
		return false;
	int32 idx = index (rObj);
	if (idx >= 0)
		return removeAt (idx);
	return false;
}

//------------------------------------------------------------------------
/*! "remove" removes the item pointed to by the specified iterator. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::remove (const TIterator<T>& iter)
{
	return remove (iter.current ());
}

//------------------------------------------------------------------------
/*! "removeAt" removes the item at the specified index. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::removeAt (int32 idx)
{
	if (idx < 0 || idx >= _total)
		return false;

	// move entries behind idx one position to the left
	for (int32 ii = idx; ii < _total - 1; ii++)
		_entries[ii] = _entries[ii + 1];

	// assign error to last entry
	_entries[_total - 1] = this->error ();

	_total--;
	return true;
}

//------------------------------------------------------------------------
/*! "removeRange" removes all items in the specified index range including the index boundaries 
	\param from : start index
	\param to: end index 
	\return success */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::removeRange (int32 from, int32 to)
{
	if (from < 0 || from >= _total ||
		to < 0 || to >= _total || from > to)
		return false;

	int32 n = to - from + 1;

	for (int32 ii = from; ii < _total; ii++)
	{
		if (ii < _total - n)
			_entries[ii] = _entries[ii + n];
		else
			_entries[ii] = this->error ();
	}
	_total -= n;
	return true;
}

//------------------------------------------------------------------------
/*! "removeAll" sets the number of items in this array to zero. */
//------------------------------------------------------------------------
template <class T>
void TArrayBase<T>::removeAll ()
{
	for (int32 i = 0; i < _total; i++)
		_entries[i] = this->error ();

	_total = 0;
}

//------------------------------------------------------------------------
/*! "indexUnsorted" returns the index of the first occurrence of an item equal
	to the specified item. 
	\return index found or "-1" if not found */ 
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::indexUnsorted (const T& rObj) const
{
	int32 ii = 0, idx = -1;
	while (ii < _total && idx == -1)
		if (_entries[ii++] == rObj)
			idx = ii - 1;
	return idx;
}

//------------------------------------------------------------------------
/*! "indexSorted" returns the index of the first occurrence of an item equal
	to the specified item. 
	\return index found or "-1" if not found */ 
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::indexSorted (const T& rObj) const
{
	if (_total <= 3)
		return indexUnsorted (rObj);

	int32 low = 0;
	int32 high = _total - 1;
	int32 middle = high >> 1;

	T* p;
	while (high >= low)
	{
		p = &_entries[middle];
		if (*p == rObj)
		{
			while (middle && *(p - 1) == rObj)
			{
				p--;
				middle--;
			}
			return middle;
		}
		else if (*p > rObj)
			high = middle - 1;
		else
			low = middle + 1;
		middle = (high + low) >> 1;
	}
	return -1;
}

//------------------------------------------------------------------------
/*! "shouldGoUnsorted" returns the index for a  potential insert/add operation
	\return  index of last event + 1   "append item" */
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::shouldGoUnsorted (const T& /*rObj*/) const
{
	return _total;
}

//------------------------------------------------------------------------
/*! "shouldGoSorted" returns the index for a  potential insert/add operation
	using ">", "<", and  "==" operators
	\return  index found  */
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::shouldGoSorted (const T& rObj) const
{
	if (_total == 0 || (_entries[0] > rObj))
		return 0;
	if (!(rObj < _entries[_total - 1]))
		return _total;

	int32 low = 0;
	int32 high = _total - 1;
	int32 middle = high >> 1;

	T* p;
	while (high >= low)
	{
		p = _entries + middle;
		if (*p == rObj)
			break;
		else if (*p > rObj)
			high = middle - 1;
		else
			low = middle + 1;
		middle = (high + low) >> 1;
	}
	do
	{
		if (rObj < _entries[middle++])
			return middle - 1;
	} while (true);
}

//------------------------------------------------------------------------
/*! "at" returns the item at the specified index. 
	\return  item found or error object*/
//------------------------------------------------------------------------
template <class T>
T& TArrayBase<T>::at (int32 idx) const
{
	return (idx >= 0 && idx < _total) ? _entries[idx] : this->error ();
}

//------------------------------------------------------------------------
/*! "lookup" returns the first occurrence of the item equal to the
	specified item in the array. 
	\return  item found or error object */ 
//------------------------------------------------------------------------
template <class T>
T& TArrayBase<T>::lookup (const T& rObj) const
{
	int32 idx = index (rObj);
	return (idx > -1) ? _entries[idx] : this->error ();
}

//------------------------------------------------------------------------
/*! "contains" checks the array for an item equal to the input. */
//------------------------------------------------------------------------
template <class T>
bool TArrayBase<T>::contains (const T& rObj) const
{
	return (index (rObj) > -1) ? true : false;
}

//------------------------------------------------------------------------
/*! "occurrences" counts the number of occurrences of items equal to the
	specified item. */
//------------------------------------------------------------------------
template <class T>
int32 TArrayBase<T>::occurrences (const T& rObj) const
{
	int32 ii = 0;
	int32 num = 0;
	while (ii < _total)
		if (_entries[ii++] == rObj)
			num++;
	return num;
}

//------------------------------------------------------------------------
/*! "newIterator" creates and returns a new array iterator. */
//------------------------------------------------------------------------
template <class T>
TIterator<T>* TArrayBase<T>::newIterator () const
{
	return NEW TArrayIterator<T>(*this);
}

//------------------------------------------------------------------------
/*! "quickSort" uses the standard library to perform a quick sort
	on this array. */
//------------------------------------------------------------------------
template <class T>
void TArrayBase<T>::doQuickSort ()
{
	if (_total > 1)
		::qsort (_entries, _total, sizeof (T), &TArray<T>::cmpData);
}

//------------------------------------------------------------------------
/*! "cmpData" is called by the standard library qsort function for
	sorting the array into ascending order. */
//------------------------------------------------------------------------
template <class T>
int TArrayBase<T>::cmpData (const void* obj1, const void* obj2)
{
	T* t1 = (T*) obj1;
	T* t2 = (T*) obj2;
	return ((*t1 == *t2) ? 0 : ((*t1 > *t2) ? 1 : -1));
}

//------------------------------------------------------------------------
// TArray
//------------------------------------------------------------------------
/*! "replaceAt" replaces the item at the specified index with the specified item. 
	\return success  */
//------------------------------------------------------------------------
template <class T>
bool TArray<T>::replaceAt (int32 idx, const T& rObj)
{
	if (idx < 0 || idx >= this->_total)
		return false;
	this->_entries[idx] = rObj;
	return true;
}

//------------------------------------------------------------------------
/*! "enableSorting"    enables or disables sorting. On state change to enabled 
	"doQuickSort" is automatically called */
//------------------------------------------------------------------------
template <class T>
void TSortableArray<T>::enableSorting (bool state)
{
	if (state != sorting)
	{
		sorting = state;
		if (sorting)
			this->doQuickSort ();
	}
}

//------------------------------------------------------------------------
// TArrayIterator
//------------------------------------------------------------------------
/*! "array" returns a reference to the array being iterated. */
//------------------------------------------------------------------------
template <class T>
const TArrayBase<T>& TArrayIterator<T>::array () const
{
	return (const TArrayBase<T>&) this->_container;
}

//------------------------------------------------------------------------
/*! "done" returns whether or not this iterator can advance any further. */
//------------------------------------------------------------------------
template <class T>
bool TArrayIterator<T>::done () const
{
	return (_index >= 0 && _index < array ()._total) ? false : true;
}

//------------------------------------------------------------------------
/*! "next" returns the current item in the array and advances the
	iterator to the next item. */
//------------------------------------------------------------------------
template <class T>
T& TArrayIterator<T>::next ()
{
	return (_index >= 0 && _index < array ()._total) ?
		array ()._entries[_index++] : array ().error ();
}

//------------------------------------------------------------------------
/*! "previous" returns the current item in the array and decrements the
	iterator to the previous item. */
//------------------------------------------------------------------------
template <class T>
T& TArrayIterator<T>::previous ()
{
	return (_index >= 0 && _index < array ()._total) ?
		array ()._entries[_index--] : array ().error ();
}

//------------------------------------------------------------------------
/*! "current" returns the current array item. */
//------------------------------------------------------------------------
template <class T>
T& TArrayIterator<T>::current () const
{
	return (_index >= 0 && _index < array ()._total) ?
		array ()._entries[_index] : array ().error ();
}

//------------------------------------------------------------------------
/*! "first" moves the iterator to the first item. */
//------------------------------------------------------------------------
template <class T>
void TArrayIterator<T>::first ()
{
	_index = 0;
}

//------------------------------------------------------------------------
/*! "last" moves the iterator to the last item. */
//------------------------------------------------------------------------
template <class T>
void TArrayIterator<T>::last ()
{
	_index = array ()._total - 1;
}

}

#endif // __tarray__
