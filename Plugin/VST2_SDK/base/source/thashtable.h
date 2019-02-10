//-------------------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category	   : Helpers
// Filename	   : base/source/thashtable.h
// Created by  : Steinberg, 04/2008
// Description : Hash Table class template 
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

#ifndef __thashtable__
#define __thashtable__

#include "base/source/tcontainer.h"

namespace Steinberg {

template <class T> class THashBucket;         
template <class T> class THashNode;           
template <class T> class THashTableIterator;  

//-------------------------------------------------------------------------------------
/** Hash Table template
@ingroup baseContainer
A hash table is a list of buckets. It assigns values to items (template) using a hash 
function and puts them into the bucket, which table index equals the item's calculated 
value.
@see TContainer, THashTableIterator, THashSet */
//-------------------------------------------------------------------------------------
template <class T>
class THashTable : public TContainer<T>
{
public:
//-------------------------------------------------------------------------------------
	typedef uint32 (*THashFunc) (const T&, uint32);   ///< Hash function type.

	THashTable (THashFunc, int32 = 10);              ///< Constructor with hash function.
	THashTable (const THashTable<T>&);               ///< Copy constructor.
	THashTable (THashFunc, const TContainer<T>&);    ///< Constructor with container.
	~THashTable ();                                  ///< Destructor.	

	THashTable<T>& operator= (const THashTable<T>&); ///< Assignment operator, uses copy.
	void setHashFunction (THashFunc);                ///< Set hash function.
	bool resize (int32);                             ///< Resize the table, set number of hash buckets.

	//-- TContainer -------------------------------------------------------------------
	virtual TContainer<T>* newInstance () const;	 ///< @copydoc TContainer::newInstance

	virtual int32 total () const;                    ///< @copydoc TContainer::total
	virtual bool isEmpty () const;                   ///< @copydoc TContainer::isEmpty

	virtual bool add (const T& item);                ///< @copydoc TContainer::add
	virtual bool remove (const T& item);             ///< @copydoc TContainer::remove
	virtual bool remove (const TIterator<T>& iter);  ///< @copydoc TContainer::remove(const TIterator<T>&)
	virtual bool removeAt (int32 index);             ///< @copydoc TContainer::removeAt
	virtual void removeAll ();                       ///< @copydoc TContainer::removeAll

	virtual T& lookup (const T& item) const;         ///< @copydoc TContainer::lookup
	virtual bool contains (const T& item) const;     ///< @copydoc TContainer::contains
	virtual int32 occurrences (const T&item) const;  ///< @copydoc TContainer::occurrences

	virtual TIterator<T>* newIterator () const;      ///< @copydoc TContainer::newIterator
//-------------------------------------------------------------------------------------
private:
	THashFunc _hFunc;                                ///< Pointer to hash function.
	int32 _total;                                    ///< Number of items in table.
	THashBucket<T>* _buckets;                        ///< Hash bucket array.

	friend class THashTableIterator<T>;              ///< Iterator can access.
};


//-------------------------------------------------------------------------------------
/** Private class to THashTable.
	A bucket consists of hash nodes. These node are linked together and form a linked list.
	An item which gets assigned to a bucket is wrapped into a node and appended to the list.
	@see THashTable THashNode
*/
//-------------------------------------------------------------------------------------
template <class T>
class THashBucket
{
private:
//-------------------------------------------------------------------------------------
	THashBucket () : _size (0), _first (0), _last (0) {}  ///< Constructor.
	~THashBucket () {removeAll ();}                       ///< Destructor.

	int32 size () const {return _size;}                    ///< Return bucket size.

	bool append (const T&);                               ///< Append item to bucket.
	bool contains (const T&) const;                       ///< Is item in bucket?
	bool remove (const T&);                               ///< Remove item from bucket.
	bool removeAt (int32);                                ///< Remove at index.
	T* lookup (const T&) const;                           ///< Return equal item.
	void removeAll ();                                    ///< Remove all items.

	int32 _size;                                          ///< Bucket size.
	THashNode<T>* _first;                                 ///< First node in bucket.
	THashNode<T>* _last;                                  ///< Last node in bucket.

	friend class THashTable<T>;                           ///< Table can access.
	friend class THashTableIterator<T>;                   ///< Iterator can access.
};


//-------------------------------------------------------------------------------------
/** Private class to THashTable.
	A hash node is a part of a hash bucket. It wraps an item an forms
	a linked list.
	@see THashBucket
*/
//-------------------------------------------------------------------------------------
template <class T>
class THashNode
{
private:
//-------------------------------------------------------------------------------------
	THashNode (const T& O) : _next (0), _data (O) {}  ///< Constructor.

	THashNode<T>* _next;                              ///< Link to next Node.
	T _data;                                          ///< Item.

	friend class THashTable<T>;                       ///< Table can access.
	friend class THashBucket<T>;                      ///< Bucket can access.
	friend class THashTableIterator<T>;               ///< Iterator can access.
};

//------------------------------------------------------------------------------------- 
/** Iterator for a THashTable*/
//-------------------------------------------------------------------------------------
template <class T>
class THashTableIterator : public TIterator<T>
{
public:
//-------------------------------------------------------------------------------------
	THashTableIterator (const THashTable<T>&);    ///< Constructor.
	
	virtual bool done () const;                   ///< @copydoc TIterator::done
	virtual T& next ();                           ///< @copydoc TIterator::next
	virtual T& previous ();                       ///< @copydoc TIterator::previous
	virtual T& current () const;                  ///< @copydoc TIterator::current
	virtual void first ();                        ///< @copydoc TIterator::first
	virtual void last ();                         ///< @copydoc TIterator::last

	const THashTable<T>& table () const;          ///< Return table reference.

//-------------------------------------------------------------------------------------
private:
	int32 _bucket;                                ///< Index of current hash bucket.
	THashNode<T>* _node;                          ///< Current bucket node.
};



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
// "THashTable" is the hash table constructor.


//-------------------------------------------------------------------------------------
// "THashTable" constructs a hash table that will use the specified
// function for hashing.
//-------------------------------------------------------------------------------------
/*! @param[in] func Hash function the table uses.
	@param[in] size Size (number of buckets) of new table. */
//-------------------------------------------------------------------------------------
template <class T>
THashTable<T>::THashTable (THashFunc func, int32 size)
: _hFunc (func)
, _total (0)
{
	ASSERT (size > 0)
	if (size <= 0)
		size = 1;
	_buckets = (size > 0) ? NEWVEC THashBucket<T>[size] : 0;
	this->_size = (_buckets) ? size : 0;
}


//-------------------------------------------------------------------------------------
// "THashTable" is the hash table copy constructor.
//-------------------------------------------------------------------------------------
/*! @param[in] table Hash table to copy. */
//-------------------------------------------------------------------------------------
template <class T>
THashTable<T>::THashTable (const THashTable<T>& table)
: TContainer<T> (table)
, _hFunc (table._hFunc)
, _total (0)
{
	int32 size = table._size;
	ASSERT (size > 0)
	if (size <= 0)
		size = 1;
	_buckets = (size > 0) ? NEWVEC THashBucket<T>[size] : 0;
	this->_size = (_buckets) ? size : 0;
	this->copy (table);
}


//-------------------------------------------------------------------------------------
// "THashTable" constructs a table from the specified container.
//-------------------------------------------------------------------------------------
/*! @param[in] func Hash function the table uses.
	@param[in] cont Container to construct the table from. */
//-------------------------------------------------------------------------------------
template <class T>
THashTable<T>::THashTable (THashFunc func, const TContainer<T>& cont)
: _hFunc (func)
, _total (0)
{
	int32 sz = cont.total ();
	ASSERT (sz > 0)
	if (sz <= 0)
		sz = 1;
	_buckets = (sz > 0) ? NEWVEC THashBucket<T>[sz] : 0;
	this->_size    = (_buckets) ? sz : 0;
	this->copy (cont);
}


//-------------------------------------------------------------------------------------
// "THashTable" is the hash table destructor.
//-------------------------------------------------------------------------------------
template <class T>
THashTable<T>::~THashTable ()
{
	removeAll ();
	delete[] _buckets;
}

//-------------------------------------------------------------------------------------
/*! @return New hash table instance. */
//-------------------------------------------------------------------------------------
template <class T>
TContainer<T>* THashTable<T>::newInstance () const
{
	return NEW THashTable<T> (_hFunc);
}


//-------------------------------------------------------------------------------------
// "=" assignment operator copies the specified hash table into this table.
//-------------------------------------------------------------------------------------
/*! @param[in] table Assign left side (this) to table.
	@return Assigned hash table. */
//-------------------------------------------------------------------------------------
template <class T>
THashTable<T>& THashTable<T>::operator= (const THashTable<T>& table)
{
	if (&table != this)
	{
		removeAll ();
		delete[] _buckets;
		_hFunc = table._hFunc;
		_total = 0;
		ASSERT (table._size > 0)
		_buckets = NEWVEC THashBucket<T>[table._size];
		this->_size = (_buckets != 0) ? table._size : 0;
		copy (table);
	}
	return *this;
}


//-------------------------------------------------------------------------------------
// "setHashFunction" sets the hash function to be used on the input items.
//-------------------------------------------------------------------------------------
/*! @param[in] func New hash function. */
//-------------------------------------------------------------------------------------
template <class T>
void THashTable<T>::setHashFunction (THashFunc func)
{
	_hFunc = func;
}


//-------------------------------------------------------------------------------------
// "total" returns the number of items in the table.
//-------------------------------------------------------------------------------------
/*! @return Total number of items in the table. */
//-------------------------------------------------------------------------------------
template <class T>
int32 THashTable<T>::total () const
{
	return _total;
}


//-------------------------------------------------------------------------------------
// "resize" resizes the hash table.
//-------------------------------------------------------------------------------------
/*! @param[in] newsize New number of hash buckets.
	@return true, if resized.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::resize (int32 newsize)
{
	if (!_hFunc)
		return false;
	if (newsize <= 0)
		newsize = 1;

	int32 newtotal = 0;
	THashBucket<T> *newbuckets = NEWVEC THashBucket<T>[newsize];
	if (!newbuckets)
		return false;

	THashTableIterator<T> iter (*this);
	while (!iter.done ())
	{
		T item = iter.next ();
		int32 idx = (*_hFunc) (item, newsize);
		newbuckets[idx].append (item);
		newtotal++;
	}

	delete[] _buckets;
	this->_size = newsize;
	_buckets = newbuckets;
	_total = newtotal;
	return true;
}

//-------------------------------------------------------------------------------------
// "isEmpty" checks whether or not the table is empty.
//-------------------------------------------------------------------------------------
/*! @return true, if empty.
	@return false, if not empty. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::isEmpty () const
{
	return (_total == 0) ? true : false;
}


//-------------------------------------------------------------------------------------
// "add" adds a new item to the table.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to add.
	@return true, if added.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::add (const T& rObj)
{
	if (!_hFunc)
		return false;
	int32 idx = (*_hFunc) (rObj, this->_size);
	bool success = _buckets[idx].append (rObj);
	if (success)
		_total++;
	return success;
}


//-------------------------------------------------------------------------------------
// "remove" removes the first occurrence of an item equal to the specified
// item from the table.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to remove.
	@return true, if removed.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::remove (const T& rObj)
{
	if (!_hFunc)
		return false;
	int32 idx = (*_hFunc) (rObj, this->_size);
	bool success = _buckets[idx].remove (rObj);
	if (success)
		_total--;
	return success;
}


//-------------------------------------------------------------------------------------
// "remove" removes the item pointed to by the iterator.
//-------------------------------------------------------------------------------------
/*! @param[in] iter Points to item to remove.
	@return true, if removed.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::remove (const TIterator<T>& iter)
{
	return remove (iter.current ());
}


//-------------------------------------------------------------------------------------
// "removeAt" removes the item at the specified index.
//-------------------------------------------------------------------------------------
/*! @param[in] idx Index of item to remove.
	@return true, if removed.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::removeAt (int32 idx)
{
	if (_total == 0)
		return false;

	int32 bucket = 0;
	int32 bidx = 0;

	THashNode<T> *node = 0;
	while (_buckets[bucket]._size == 0 && bucket < this->_size)
		bucket++;

	if (bucket < this->_size)
		node = _buckets[bucket]._first;

	int32 ix = 0;
	while (node && ix < idx)
	{
		if (node->_next)
		{
			node = node->_next;
			bidx++;
		}
		else
		{
			bucket++;
			bidx = 0;
			while (bucket < this->_size && _buckets[bucket]._size == 0)
				bucket++;
			node = (bucket < this->_size) ? _buckets[bucket]._first : 0;
		}
		ix++;
	}
	return (ix == idx) ? _buckets[bucket].removeAt (bidx) : false;
}


//-------------------------------------------------------------------------------------
// "removeAll" removes all items from the table.
//-------------------------------------------------------------------------------------
template <class T>
void THashTable<T>::removeAll ()
{
	for (int32 ii = 0; ii < this->_size; ii++)
		_buckets[ii].removeAll ();
	_total = 0;
}


//-------------------------------------------------------------------------------------
// "lookup" returns the first occurrence of an item equal to the specified
// item.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to look up.
	@return true, if removed.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
T& THashTable<T>::lookup (const T& rObj) const
{
	if (!_hFunc)
		return this->error ();
	int32 idx = (*_hFunc) (rObj, this->_size);
	T* out = _buckets[idx].lookup (rObj);
	return (out) ? *out : this->error ();
}


//-------------------------------------------------------------------------------------
// "contains" checks if an item equal to the specified item exists
// in the table.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to compare.
	@return true, if equal item exists.
	@return false, if no equal item exists. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTable<T>::contains (const T& rObj) const
{
	if (!_hFunc)
		return false;
	int32 idx = (*_hFunc) (rObj, this->_size);
	return _buckets[idx].contains (rObj);
}


//-------------------------------------------------------------------------------------
// "occurrences" counts the number of items in the table equal to the
// specified item.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to compare.
	@return number of equal items. */
//-------------------------------------------------------------------------------------
template <class T>
int32 THashTable<T>::occurrences (const T& rObj) const
{
	THashTableIterator<T> iter (*this);
	int32 num = 0;
	while (!iter.done ())
		if (iter.next () == rObj)
			num++;
	return num;
}


//-------------------------------------------------------------------------------------
// "newIterator" creates and returns a new table iterator.
//-------------------------------------------------------------------------------------
/*! @return New hash table iterator. */
//-------------------------------------------------------------------------------------
template <class T>
TIterator<T>* THashTable<T>::newIterator () const
{
	return NEW THashTableIterator<T> (*this);
}


//-------------------------------------------------------------------------------------
// "append" appends a new item to the hash bucket.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to append.
	@return true, if appended.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashBucket<T>::append (const T& rObj)
{
	THashNode<T> *newnode = NEW THashNode<T> (rObj);
	if (!newnode)
		return false;

	if (!_first)
		_first = _last = newnode;
	else
	{
		_last->_next = newnode;
		_last = newnode;
	}
	this->_size++;
	return true;
}


//-------------------------------------------------------------------------------------
// "contains" checks if an item equal to the specified item exists
// in this hash bucket.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to compare.
	@return true, if bucket contains item.
	@return false, if not. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashBucket<T>::contains (const T& rObj) const
{
	THashNode<T> *rover = _first;
	bool found = false;
	while (rover && !found)
	{
		if (rover->_data == rObj)
			found = true;
		else
			rover = rover->_next;
	}
	return found;
}


//-------------------------------------------------------------------------------------
// "remove" removes the first occurrence of an item equal to the
// specified item from this hash bucket.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to remove.
	@return true, if removed.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashBucket<T>::remove (const T& rObj)
{
	THashNode<T> *rover = _first;
	int32  ii = 0, idx = -1;
	while (idx < 0 && rover)
	{
		if (rover->_data == rObj) idx = ii;
		rover = rover->_next; ii++;
	}
	return (idx >= 0) ? removeAt (idx) : false;
}


//-------------------------------------------------------------------------------------
// "removeAt" removes the item at the specified index.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Index of item to remove.
	@return true, if removed.
	@return false, if failed. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashBucket<T>::removeAt (int32 idx)
{
	if (idx < 0 || idx >= this->_size)
		return false;

	if (idx == 0)                             // Object is first in the list.
	{
		THashNode<T> *temp = _first;
		if (_first == _last)
			_first = _last = 0;
		else
			_first = _first->_next;
		this->_size--;
		delete temp;
		return true;
	}

	int32 ii = 0;
	THashNode<T> *rover1 = _first;          // Search for object in list.
	THashNode<T> *rover2 = _last;

	while (rover1 != 0 && ii < idx)
	{
		rover2 = rover1;
		rover1 = rover1->_next;
		ii++;
	}

	if (rover1 == 0)
		return false;         // Object was not found.

	if (rover1 == _last)                      // Object is last in list.
	{
		_last = rover2;
		rover2->_next = 0;
	}
	else                                      // Remove object from list.
		rover2->_next = rover2->_next->_next;

	this->_size--;
	delete rover1;                            // Delete the hash node.
	return true;
}


//-------------------------------------------------------------------------------------
// "lookup" returns the first occurrence of an item equal to the
// specified item.
//-------------------------------------------------------------------------------------
/*! @param[in] rObj Item to look up.
	@return First occurence of item.
	@return 0, if no occurence. */
//-------------------------------------------------------------------------------------
template <class T>
T* THashBucket<T>::lookup (const T& rObj) const
{
	THashNode<T> *rover = _first;
	THashNode<T> *temp = 0;
	while (rover && !temp)
	{
		if (rover->_data == rObj)
			temp = rover;
		else
			rover = rover->_next;
	}
	return (temp) ? &(temp->_data) : 0;
}


//-------------------------------------------------------------------------------------
// "removeAll" removes all items from this hash bucket.
//-------------------------------------------------------------------------------------
template <class T>
void THashBucket<T>::removeAll ()
{
	THashNode<T> *temp, *rover = _first;
	while (rover)
	{
		temp = rover->_next;
		delete rover;
		rover = temp;
	}
	this->_size = 0;
	_first = _last = 0;
}


//-------------------------------------------------------------------------------------
// "THashTableIterator" is the iterator constructor.  The node
// pointer is positioned at the first bucket containing items.
//-------------------------------------------------------------------------------------
/*! @param[in] Tb (Table to iterate. */
//-------------------------------------------------------------------------------------
template <class T>
THashTableIterator<T>::THashTableIterator (const THashTable<T>& Tb)
: TIterator<T> (Tb)
, _bucket (0)
, _node (0)
{
	while (table ()._buckets[_bucket]._size == 0 && _bucket < table ()._size)
		_bucket++;
	if (_bucket < table ()._size)
		_node = table ()._buckets[_bucket]._first;
}


//-------------------------------------------------------------------------------------
// "table" returns a reference to the table being iterated.
//-------------------------------------------------------------------------------------
/*! @return Table of iterator. */
//-------------------------------------------------------------------------------------
template <class T>
const THashTable<T>& THashTableIterator<T>::table () const
{
	return (const THashTable<T>&) this->_container;
}


//-------------------------------------------------------------------------------------
// "done" checks if the iterator can advance any further.
//-------------------------------------------------------------------------------------
/*! @return true, if done iterating.
	@return false, if there are still items left. */
//-------------------------------------------------------------------------------------
template <class T>
bool THashTableIterator<T>::done () const
{
	return (!_node);
}


//-------------------------------------------------------------------------------------
// "next" returns the current item and advances the iterator to the
// next item.
//-------------------------------------------------------------------------------------
/*! @return Next item. */
//-------------------------------------------------------------------------------------
template <class T>
T& THashTableIterator<T>::next ()
{
	if (!_node)
		return table ().error ();

	T& rObj = _node->_data;               // Save current item reference.

	if (_node->_next)                     // Advance to next node.
		_node = _node->_next;
	else                                  // Advance to next bucket with items.
	{
		_bucket++;
		while (_bucket < table ()._size && table ()._buckets[_bucket]._size == 0)
			_bucket++;
		if (_bucket < table ()._size)
			_node = table ()._buckets[_bucket]._first;
		else
			_node = 0;
	}
	return rObj;
}


//-------------------------------------------------------------------------------------
// "previous" decrements the iterator by one object and then returns
// that object.
//-------------------------------------------------------------------------------------
/*! @return Previous item. */
//-------------------------------------------------------------------------------------
template <class T>
T& THashTableIterator<T>::previous ()
{
	if (!_node) 
		return table ().error ();
	
	T& rval = _node->_data;

	if (_node == table ()._buckets[_bucket]._first)
	{
		--_bucket;
		while (_bucket >= 0 && table ()._buckets[_bucket]._size == 0)
			_bucket--;
		if (_bucket >= 0)
			_node = table ()._buckets[_bucket]._last;
		else
			_node = 0;
	}
	else
	{
		THashNode<T> *rover = table ()._buckets[_bucket]._first;
		while (rover && rover->_next != _node)
			rover = rover->_next;
		_node = rover;
	}
	return rval;
}


//-------------------------------------------------------------------------------------
// "current" returns the current object.
//-------------------------------------------------------------------------------------
/*! @return Current item. */
//-------------------------------------------------------------------------------------
template <class T>
T& THashTableIterator<T>::current () const
{
	return (_node) ? _node->_data : table ().error ();
}


//-------------------------------------------------------------------------------------
// "first" moves the iterator to the first item.
//-------------------------------------------------------------------------------------
template <class T>
void THashTableIterator<T>::first ()
{
	_bucket = 0;
	_node   = 0;
	while (table ()._buckets[_bucket]._size == 0 && _bucket < table ()._size)
		_bucket++;
	if (_bucket < table ()._size)
		_node = table ()._buckets[_bucket]._first;
}


//-------------------------------------------------------------------------------------
// "last" moves the iterator to the last item.
//-------------------------------------------------------------------------------------
template <class T>
void THashTableIterator<T>::last ()
{
	_bucket = table ()._size - 1;
	_node = 0;
	while (_bucket >= 0 && table ()._buckets[_bucket]._size == 0)
		_bucket--;
	if(_bucket >= 0)
		_node = table ()._buckets[_bucket]._last;
}

} // namespace Steinberg

#endif
