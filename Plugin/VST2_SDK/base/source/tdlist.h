//------------------------------------------------------------------------ 
// Project     : SDK Base 
// Version     : 1.0
//
// Category    : Helpers / Template Container
// Filename    : base/source/tdlist.h
// Created by  : Steinberg, 2009
// Description : Double linked list class template 
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

#ifndef __tdlist__
#define __tdlist__

#include "base/source/tcontainer.h"

namespace Steinberg {

// forward declarations
template <class T> class TDLinkedListIterator;   

//------------------------------------------------------------------------
/** <b>Doubly</b> linked template list.
@ingroup baseContainer

@see TDLinkedListIterator, TLinkedList
*/
//------------------------------------------------------------------------
template <class T> 
class TDLinkedList : public TContainer<T>
{
public:
//------------------------------------------------------------------------
	TDLinkedList () : _first (0), _last (0) {} 
	TDLinkedList (const TDLinkedList<T>&);               ///< Copy constructor.
	TDLinkedList (const TContainer<T>&);                 ///< Initializes with copy of the given container.
	~TDLinkedList ();                              
	TDLinkedList<T>& operator= (const TDLinkedList<T>&); 

	virtual TContainer<T>* newInstance () const;         ///< @copydoc TContainer::newInstance

	virtual bool add (const T& item);                    ///< Add item to end of list.
	bool append (const T& item);                         ///< Same as TDLinkedList::add.
	bool prepend (const T& item);                        ///< Add item to beginning of the list.
	bool insertAt (int32 index, const T& item);          ///< Insert item at the specified index.
	bool replaceAt (int32 index, const T& item);         ///< Replace item at the specified index.
	virtual bool remove (const T& item);                 ///< @copydoc TContainer::remove
	virtual bool remove (const TIterator<T>&);           ///< @copydoc TContainer::remove (const TIterator<T>&)
	virtual bool removeAt (int32 index);                 ///< @copydoc TContainer::removeAt
	virtual void removeAll ();                           ///< @copydoc TContainer::removeAll

	T removeFirst ();                                    ///< @copydoc TLinkedList::removeFirst
	T removeLast ();                                     ///< @copydoc TLinkedList::removeLast

	bool insertAfter (const T& after, const T& item);    ///< @copydoc TLinkedList::insertAfter
	bool insertBefore (const T& before, const T& item);  ///< @copydoc TLinkedList::insertBefore

	T& first () const;                                   ///< @copydoc TLinkedList::first
	T& last () const;                                    ///< @copydoc TLinkedList::last

	int32 index (const T& item) const;                   ///< Get index of equal item.

	virtual T& at (int32 index)      const;              ///< @copydoc TContainer::at
	virtual T& lookup (const T& item) const;             ///< @copydoc TContainer::lookup
	virtual bool contains (const T& item) const;         ///< @copydoc TContainer::contains
	virtual int32 occurrences (const T& item) const;     ///< @copydoc TContainer::occurrences

	virtual TIterator<T>* newIterator () const;          ///< @copydoc TContainer::newIterator

//------------------------------------------------------------------------
private:
	struct TDLink
	{
		TDLink (const T& D) : _next (0), _data (D), _prev (0) {} 
		
		TDLink* _next;                             
		T       _data;                           
		TDLink* _prev;                              
	};

	TDLink* _first;                             ///< First item in list.
	TDLink* _last;                              ///< Last item in list.

	friend class TDLinkedListIterator<T>;
};

//------------------------------------------------------------------------
/** Iterator for doubly linked template list.
Implements the TIterator interface for TDLinkedList.
@see TDLinkedList
*/
//------------------------------------------------------------------------
template <class T> 
class TDLinkedListIterator : public TIterator<T>
{
public:
//------------------------------------------------------------------------
	TDLinkedListIterator (const TDLinkedList<T>& list); 

	virtual bool done () const;                     ///< @copydoc TIterator::done
	virtual T& next ();                             ///< @copydoc TIterator::next
	virtual T& previous ();                         ///< @copydoc TIterator::previous
	virtual T& current () const;                    ///< @copydoc TIterator::current
	virtual void first ();                          ///< @copydoc TIterator::first
	virtual void last ();                           ///< @copydoc TIterator::last

	const TDLinkedList<T>& list () const;           ///< Return list reference.

//------------------------------------------------------------------------
private:
	typename TDLinkedList<T>::TDLink *_link;                             
};


//------------------------------------------------------------------------
//------------------------------------------------------------------------
//------------------------------------------------------------------------

//------------------------------------------------------------------------
// TDLinkedList
//------------------------------------------------------------------------
template <class T>
TDLinkedList<T>::TDLinkedList (const TDLinkedList<T>& l)
: TContainer<T>(l)
, _first (0)
, _last (0)
{
	this->copy(l);
}

//------------------------------------------------------------------------
template <class T>
TDLinkedList<T>::TDLinkedList (const TContainer<T>& cont)
: _first (0)
, _last (0)
{
	copy (cont);
}

//------------------------------------------------------------------------
template <class T>
TDLinkedList<T>::~TDLinkedList ()
{
	removeAll ();
}

//------------------------------------------------------------------------
template <class T>
TDLinkedList<T>& TDLinkedList<T>::operator= (const TDLinkedList<T>& l)
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
TContainer<T>* TDLinkedList<T>::newInstance () const
{
	return NEW TDLinkedList<T> ();
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::add (const T& rObj)
{
	return append (rObj);
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::append (const T& obj)
{
	TDLink *newlink = NEW TDLink (obj);
	if (!newlink)
		return false;

	if (!_first)
		_first = _last = newlink;
	else
	{
		_last->_next   = newlink;
		newlink->_prev = _last;
		_last          = newlink;
	}
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::prepend (const T& obj)
{
	TDLink* newlink = NEW TDLink (obj);
	if (!newlink)
		return false;

	if (!_first)
		_first = _last = newlink;
	else
	{
		newlink->_next = _first;
		_first->_prev  = newlink;
		_first         = newlink;
	}
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T> 
bool TDLinkedList<T>::insertAt (int32 idx, const T& rObj)
{
	if (idx < 0 || idx >= this->_size)
		return false;

	int32 ii = 0;
	TDLink* rover = _first;
	while (rover && ii < idx)
	{
		rover = rover->_next;
		ii++;
	}
	if (!rover)
		return false;

	if (rover == _first)
		return prepend (rObj);

	TDLink* newlink = NEW TDLink (rObj);
	newlink->_prev      = rover->_prev;
	rover->_prev->_next = newlink;
	newlink->_next      = rover;
	rover->_prev        = newlink;
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::replaceAt (int32 idx, const T& rObj)
{
	if (idx < 0 || idx >= this->_size)
		return false;

	int32 ii = 0;
	TDLink* rover = _first;
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
bool TDLinkedList<T>::remove (const T& rObj)
{
	TDLink *rover = _first;
	int32 ii = 0, idx = -1;
	while (idx < 0 && rover)
	{
		if (rover->_data == rObj)
			idx = ii;
		rover = rover->_next; ii++;
	}
	return (idx >= 0) ? removeAt (idx) : false;
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::remove (const TIterator<T>& iter)
{
	return remove (iter.current ());
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::removeAt (int32 idx)
{
	if (idx < 0 || idx >= this->_size)
		return false;

	if (idx == 0)                                   // Item to remove is
	{                                               // first in the list.
		removeFirst ();
		return true;
	}

	if (idx == this->_size - 1)                           // Item to remove is
	{                                               // last in the list.
		removeLast ();
		return true;
	}

	int32  ii = 0;                                    // Position to item.
	TDLink *rover = _first;
	while (rover && ii < idx)
	{
		rover = rover->_next;
		ii++;
	}

	if (rover == 0)
		return false;                               // Item was not found.
	rover->_prev->_next = rover->_next;             // Remove item.
	rover->_next->_prev = rover->_prev;

	delete rover;                                   // Delete the link.
	this->_size--;
	return true;
}

//------------------------------------------------------------------------
template <class T>
void TDLinkedList<T>::removeAll ()
{
	TDLink *temp, *rover = _first;
	while (rover)
	{
		temp = rover->_next;
		delete rover;
		rover = temp;
	}
	_first = _last = 0;
	this->_size  = 0;
}

//------------------------------------------------------------------------
template <class T> 
T TDLinkedList<T>::removeFirst ()
{
	if (!_first)
		return this->error ();
	
	T ret = _first->_data;
	TDLink *temp = _first;
	
	_first = _first->_next;
	if (!_first)
		_last = 0;
	else
		_first->_prev = 0;
	
	delete temp;
	this->_size--;
	return ret;
}

//------------------------------------------------------------------------
template <class T>
T TDLinkedList<T>::removeLast ()
{
	if (!_last)
		return this->error ();
	T ret = _last->_data;
	TDLink *temp = _last;
	_last = _last->_prev;
	
	if (!_last)
		_first = 0;
	else
		_last->_next  = 0;
	
	delete temp;
	this->_size--;
	return ret;
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::insertAfter (const T& after, const T& rObj)
{
	if (!_first)
		return false;

	TDLink *rover = _first;
	bool found = false;
	while (rover && !found)
	{
		if (rover->_data == after)
			found = true;
		else 
			rover = rover->_next;
	}
	if (!found) return false;

	TDLink *newlink = NEW TDLink (rObj);
	if (!newlink)
		return false;

	if (rover->_next)
		rover->_next->_prev = newlink;
	else
		_last = newlink;
	newlink->_next = rover->_next;
	newlink->_prev = rover;
	rover->_next   = newlink;
	this->_size++;
	return true;
}

//-----------------------------------------------------------------
template <class T>
bool TDLinkedList<T>::insertBefore (const T& before, const T& rObj)
{
	if (!_first)
		return false;

	TDLink *rover = _first;
	bool found = false;
	while (rover && !found)
	{
		if (rover->_data == before)
			found = true;
		else
			rover = rover->_next;
	}
	if (!found)
		return false;

	TDLink *newlink = NEW TDLink (rObj);
	if (!newlink)
		return false;

	if (rover->_prev)
		rover->_prev->_next = newlink;
	else
		_first = newlink;
	newlink->_prev = rover->_prev;
	newlink->_next = rover;
	rover->_prev   = newlink;
	this->_size++;
	return true;
}

//------------------------------------------------------------------------
template <class T>
T& TDLinkedList<T>::first () const
{
	return (_first) ? _first->_data : this->error ();
}

//------------------------------------------------------------------------
template <class T>
T& TDLinkedList<T>::last () const
{
	return (_last ) ? _last->_data  : this->error ();
}

//------------------------------------------------------------------------
template <class T>
int32 TDLinkedList<T>::index (const T& rObj) const
{
	TDLink *rover  = _first;
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
T& TDLinkedList<T>::at (int32 idx) const
{
	if (idx < 0 || idx >= this->_size)
		return this->error ();

	int32 ii = 0;
	TDLink *rover = _first;
	while (rover && ii < idx)
	{
		rover = rover->_next;
		ii++;
	}
	return (rover) ? rover->_data : this->error ();
}

//------------------------------------------------------------------------
template <class T>
T& TDLinkedList<T>::lookup (const T& rObj) const
{
	TDLink *rover = _first;
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
bool TDLinkedList<T>::contains (const T& rObj) const
{
	TDLink *rover = _first;
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
int32 TDLinkedList<T>::occurrences (const T& rObj) const
{
	TDLink *rover = _first;
	int32 occur = 0;
	while (rover)
	{
		if (rover->_data == rObj)
			occur++;
		rover = rover->_next;
	}
	return occur;
}

//------------------------------------------------------------------------
template <class T>
TIterator<T>* TDLinkedList<T>::newIterator () const
{
	return NEW TDLinkedListIterator<T>(*this);
}


//------------------------------------------------------------------------
// TDLinkedListIterator
//------------------------------------------------------------------------
template <class T>
TDLinkedListIterator<T>::TDLinkedListIterator (const TDLinkedList<T>& L)
: TIterator<T>(L)
, _link(L._first)
{}

//------------------------------------------------------------------------
template <class T>
const TDLinkedList<T>& TDLinkedListIterator<T>::list () const
{
	return (const TDLinkedList<T>&) this->_container;
}

//------------------------------------------------------------------------
template <class T>
bool TDLinkedListIterator<T>::done () const
{
	return (!_link);
}

//------------------------------------------------------------------------
template <class T>
T& TDLinkedListIterator<T>::next ()
{
	if (!_link)
		return list ().error ();

	typename TDLinkedList<T>::TDLink *temp = _link;
	_link = _link->_next;

	return temp->_data;
}

//------------------------------------------------------------------------
template <class T>
T& TDLinkedListIterator<T>::previous ()
{
	if (!_link)
		return list ().error ();
	
	typename TDLinkedList<T>::TDLink *temp = _link;
	_link = _link->_prev;
	
	return temp->_data;
}

//------------------------------------------------------------------------
template <class T>
T& TDLinkedListIterator<T>::current () const
{
	return (_link) ? _link->_data : list ().error ();
}

//------------------------------------------------------------------------
template <class T>
void TDLinkedListIterator<T>::first ()
{
	_link = list ()._first;
}

//------------------------------------------------------------------------
template <class T>
void TDLinkedListIterator<T>::last ()
{
	_link = list ()._last;
}

}

#endif
