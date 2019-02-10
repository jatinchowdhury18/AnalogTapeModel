//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/tlist.h
// Created by  : Steinberg, 04/2008
// Description : Single linked list class template
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

#ifndef __tlist__
#define __tlist__

#include "base/source/tcontainer.h"

namespace Steinberg {

template <class T> class TLinkedListIterator;   // List iterator class stub.

//------------------------------------------------------------------------
/** <b>Single</b> linked list template definition.
@ingroup baseContainer
@see TLinkedListIterator, TDLinkedList */
//------------------------------------------------------------------------
template <class T> 
class TLinkedList : public TContainer<T>
{
public:
//------------------------------------------------------------------------
	TLinkedList () : _first (0), _last (0) {}          // Default list constructor.
	TLinkedList (const TLinkedList<T>&);               ///< List copy constructor.
	TLinkedList (const TContainer<T>&);                ///< Construct from container.
	~TLinkedList ();                                   ///< List destructor.

	TContainer<T>* newInstance () const;               ///< @copydoc TContainer::newInstance

	TLinkedList<T>& operator= (const TLinkedList<T>&); ///< Assignment operator.

	virtual bool add (const T&);                       ///< @copydoc TLinkedList::newInstance
	bool append (const T&);                            ///< Same as TLinkedList::add.
	bool prepend (const T&);                           ///< Add item to beginning of the list.
	bool insertAt (int32 index, const T&);             ///< Insert item at the specified index.
	bool replaceAt (int32 index, const T&);            ///< Replace item at the specified index.
	virtual bool remove (const T&);                    ///< @copydoc TContainer::remove
	virtual bool remove (const TIterator<T>&);         ///< @copydoc TContainer::remove(const TIterator<T>&)
	virtual bool removeAt (int32);                     ///< @copydoc TContainer::removeAt
	virtual void removeAll ();                         ///< @copydoc TContainer::removeAll

	T removeFirst ();                                  ///< Remove first item and return copy of the removed item 
	T removeLast ();                                   ///< Remove last item and return copy of the removed item 

	/** Search for the first item equal to the specified
	item in the list and inserts the second item immediately after.*/
	bool insertAfter (const T& after, const T& data);
	/** Search for the first item equal to the specified
	item in the list and inserts the second item immediately before. */
	bool insertBefore (const T& before, const T& data);

	T& first () const;                                 ///< Get first item in list.
	T& last () const;                                  ///< Get last item in list.

	int32 index (const T& item) const;                 ///< Get index of equal item.

	virtual T& at (int32 index) const;                 ///< @copydoc TContainer::at
	virtual T& lookup (const T& item) const;           ///< @copydoc TContainer::lookup
	virtual bool contains (const T& item) const;       ///< @copydoc TContainer::contains
	virtual int32 occurrences (const T& item) const;   ///< @copydoc TContainer::occurrences

	virtual TIterator<T>* newIterator () const;        ///< @copydoc TContainer::newIterator
//------------------------------------------------------------------------
private:
	struct TLink
	{
		TLink (const T& D) : _next (0), _data (D) {} 

		TLink* _next;                            
		T _data;                                    
	};

	TLink* _first;                                     ///< First item in list.
	TLink* _last;                                      ///< Last item in list.
 
	friend class TLinkedListIterator<T>;               // Iterator can access.
};

//------------------------------------------------------------------------
/** Iterator for single linked template list
@see TLinkedList */
//------------------------------------------------------------------------
template <class T> 
class TLinkedListIterator : public TIterator<T>
{
public:
//------------------------------------------------------------------------
	TLinkedListIterator (const TLinkedList<T>&);

	virtual bool done () const;                  ///< @copydoc TIterator::done
	virtual T& next ();                          ///< @copydoc TIterator::next
	virtual T& previous ();                      ///< @copydoc TIterator::previous
	virtual T& current () const;                 ///< @copydoc TIterator::current
	virtual void first ();                       ///< @copydoc TIterator::first
	virtual void last ();                        ///< @copydoc TIterator::last

	const TLinkedList<T>& list () const;         ///< Return list reference.

//------------------------------------------------------------------------
private:
	typename TLinkedList<T>::TLink *_link;     
};


//------------------------------------------------------------------------
//------------------------------------------------------------------------
// method defintions
//------------------------------------------------------------------------
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// TLinkedList
//------------------------------------------------------------------------
template <class T>
TLinkedList<T>::TLinkedList (const TLinkedList<T>& l)
: TContainer<T> (l), _first (0), _last (0)
{
	this->copy (l);
}

//------------------------------------------------------------------------
template <class T>
TLinkedList<T>::TLinkedList (const TContainer<T>& cont)
: _first (0), _last (0)
{
	this->copy (cont);
}

//------------------------------------------------------------------------
template <class T>
TLinkedList<T>::~TLinkedList ()
{
	removeAll ();
}

//------------------------------------------------------------------------
template <class T>
TContainer<T>* TLinkedList<T>::newInstance () const
{
	return NEW TLinkedList<T> ();
}

//------------------------------------------------------------------------
template <class T>
TLinkedList<T>& TLinkedList<T>::operator= (const TLinkedList<T>& l)
{
	if (&l != this)
	{
		removeAll ();
		this->copy (l);
	}
	return *this;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::add (const T& rObj)
{
	return append (rObj);
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::append (const T& obj)
{
	TLink* newlink = NEW TLink (obj);
	if (!newlink)
		return false;

	if (!_first)
		_first = _last = newlink;
	else
	{
		_last->_next = newlink;
		_last = newlink;
	}
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::prepend (const T& obj)
{
	TLink* newlink = NEW TLink (obj);
	if (!newlink)
		return false;

	if (!_first)
		_first = _last = newlink;
	else
	{
		newlink->_next = _first;
		_first = newlink;
	}
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::insertAt (int32 idx, const T& rObj)
{
	if (idx < 0 || idx > this->_size)
		return false;
	if (idx == this->_size)
		return append (rObj);
	if (idx == 0)
		return prepend (rObj);

	int32 ii = 0;
	TLink *rover1 = _first;
	TLink *rover2 = 0;

	while (rover1 && ii < idx)
	{
		rover2 = rover1;
		rover1 = rover1->_next;
		ii++;
	}

	if (!rover1)
		return false;

	TLink* newlink = NEW TLink (rObj);
	if (rover1 == rover2)
	{
		newlink->_next = _first;
		_first = newlink;
	}
	else
	{
		newlink->_next = rover2->_next;
		rover2->_next = newlink;
	}
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::replaceAt (int32 idx, const T& rObj)
{
	if (idx < 0 || idx >= this->_size)
		return false;

	int32 ii = 0;
	TLink* rover = _first;
	while (rover && ii < idx)
	{
		rover = rover->_next;
		ii++;
	}
	if (!rover)
		return false;
	rover->_data = rObj;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::remove (const T& rObj)
{
	TLink *rover = _first;
	int32 ii = 0, idx = -1;
	while (idx < 0 && rover)
	{
		if (rover->_data == rObj)
		{
			idx = ii;
		}
		rover = rover->_next;
		ii++;
	}
	return (idx >= 0) ? removeAt (idx) : false;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::remove (const TIterator<T>& iter)
{
	return remove (iter.current ());
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::removeAt (int32 idx)
{
	if (idx < 0 || idx >= this->_size)
		return false;

	if (idx == 0)                      // Item to remove is
	{                                  // first in the list.
		removeFirst ();
		return true;
	}

	if (idx == this->_size - 1)        // Item to remove is
	{                                  // last in the list.
		removeLast ();
		return true;
	}

	int32 ii = 0;                      // Position to item.
	TLink* rover = _first;
	TLink* prev = 0;
	while (rover && ii < idx)
	{
		prev = rover;
		rover = rover->_next;
		ii++;
	}

	if (rover == 0)
		return false;                  // Item was not found.
	prev->_next = prev->_next->_next;  // Remove link from list.

	delete rover;                      // Delete the link.
	this->_size--;
	return true;
}

//------------------------------------------------------------------------
template <class T>
void TLinkedList<T>::removeAll ()
{
	TLink *temp, *rover = _first;

	while (rover)
	{
		temp = rover->_next;
		delete rover;
		rover = temp;
	}
	_first = _last = 0;
	this->_size = 0;
}

//------------------------------------------------------------------------
template <class T> 
T TLinkedList<T>::removeFirst ()
{
	if (!_first)
		return this->error ();

	T ret = _first->_data;
	TLink* temp = _first;
	_first = _first->_next;
	if (!_first)
		_last = 0;
	delete temp;
	this->_size--;
	return ret;
}

//------------------------------------------------------------------------
template <class T>
T TLinkedList<T>::removeLast ()
{
	if (!_last)
		return this->error ();

	if (_last == _first)
	{
		T ret = _first->_data;
		delete _first;
		_first = _last = 0;
		this->_size = 0;
		return ret;
	}

	TLink* rover = _first;
	while (rover->_next->_next)
		rover = rover->_next;

	T ret = rover->_next->_data;
	delete rover->_next;
	_last = rover;
	_last->_next = 0;
	this->_size--;
	return ret;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::insertAfter (const T& after, const T& rObj)
{
	if (!_first)
		return false;

	TLink* rover = _first;
	bool found = false;

	while (rover && !found)
	{
		if (rover->_data == after)
			found = true;
		else
			rover = rover->_next;
	}

	if (!found)
		return false;

	TLink* newlink = NEW TLink (rObj);
	if (!newlink)
		return false;
	newlink->_next = rover->_next;
	rover->_next = newlink;
	if (rover == _last)
		_last = newlink;
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::insertBefore (const T& before, const T& rObj)
{
	if (!_first)
		return false;

	TLink* rover1 = _first;
	TLink* rover2 = _first;

	while (rover1 != 0 && rover1->_data != before)
	{
		rover2 = rover1;
		rover1 = rover1->_next;
	}

	if (rover1 == 0)
		return false;

	TLink* newlink = NEW TLink (rObj);
	if (rover1 == rover2)
	{
		newlink->_next = _first;
		_first = newlink;
	}
	else
	{
		newlink->_next = rover2->_next;
		rover2->_next = newlink;
	}
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedList<T>::first () const
{
	return (_first) ? _first->_data : this->error ();
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedList<T>::last () const
{
	return (_last ) ? _last->_data  : this->error ();
}

//------------------------------------------------------------------------
template <class T>
int32 TLinkedList<T>::index (const T& rObj) const
{
	TLink* rover = _first;
	int32 outidx = -1;
	int32 idx = 0;

	while (outidx < 0 && rover)
	{
		if (rover->_data == rObj)
			outidx = idx;
		rover = rover->_next;
		idx++;
	}
	return outidx;
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedList<T>::at (int32 idx) const
{
	if (idx < 0 || idx >= this->_size)
		return this->error ();

	int32 ii = 0;
	TLink* rover = _first;
	
	while (rover && ii < idx)
	{
		rover = rover->_next;
		ii++;
	}
	return (rover) ? rover->_data : this->error ();
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedList<T>::lookup (const T& rObj) const
{
	TLink *rover = _first;
	bool found = false;

	while (rover && !found)
	{
		if (rover->_data == rObj)
			found = true;
		else
			rover = rover->_next;
	}
	return (found) ? rover->_data : this->error ();
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedList<T>::contains (const T& rObj) const
{
	TLink* rover = _first;
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

//------------------------------------------------------------------------
template <class T>
int32 TLinkedList<T>::occurrences (const T& rObj) const
{
	TLink* rover = _first;
	int32 occur = 0;

	while (rover)
	{
		if (rover->_data == rObj)
		{
			occur++;
		}
		rover = rover->_next;
	}
	return occur;
}

//------------------------------------------------------------------------
template <class T>
TIterator<T>* TLinkedList<T>::newIterator () const
{
	return NEW TLinkedListIterator<T> (*this);
}

//------------------------------------------------------------------------
// TLinkedListIterator
//------------------------------------------------------------------------

//------------------------------------------------------------------------
template <class T>
TLinkedListIterator<T>::TLinkedListIterator (const TLinkedList<T>& L)
: TIterator<T> (L), _link (L._first)
{}

//------------------------------------------------------------------------
template <class T>
const TLinkedList<T>& TLinkedListIterator<T>::list () const
{
	return (const TLinkedList<T>&) this->_container;
}

//------------------------------------------------------------------------
template <class T>
bool TLinkedListIterator<T>::done () const
{
	return (!_link);
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedListIterator<T>::next ()
{
	if (!_link) 
		return list().error ();
	typename TLinkedList<T>::TLink* temp = _link;
	_link = _link->_next;
	return temp->_data;
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedListIterator<T>::previous ()
{
	if (!_link)
		return list().error ();
	typename TLinkedList<T>::TLink* temp = _link;
	if (_link == list()._first)
		_link = 0;
	else
	{
		typename TLinkedList<T>::TLink* rover = list()._first;
		while (rover && rover->_next != _link)
		{
			rover = rover->_next;
		}
		_link = rover;
	}
	return temp->_data;
}

//------------------------------------------------------------------------
template <class T>
T& TLinkedListIterator<T>::current () const
{
	return (_link) ? _link->_data : list ().error ();
}

//------------------------------------------------------------------------
template <class T>
void TLinkedListIterator<T>::first ()
{
	_link = list ()._first;
}

//------------------------------------------------------------------------
template <class T>
void TLinkedListIterator<T>::last ()
{
	_link = list ()._last;
}

} // namespace Steinberg

#endif
