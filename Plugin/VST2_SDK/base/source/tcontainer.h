//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/tcontainer.h
// Created by  : Steinberg, 2009
// Description : Template container base class
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


#ifndef __tcontainer__
#define __tcontainer__

#include "pluginterfaces/base/ftypes.h"
#include "base/source/fdebug.h"
#include "base/source/fcleanup.h"

namespace Steinberg {

template <class T> class TIterator;

//------------------------------------------------------------------------
/** 
@defgroup baseContainer Template Containers

Template based container classes.
This module contains a number of standard container template classes.
They all derive from TContainer. Each container has a corresponding
iterator class, that all derive from TIterator.

All container classes are intended to be used as they are. 
None of them should be used as base class to derive from!

@see TContainer
*/

//------------------------------------------------------------------------
/** Template container base class (abstract).
@ingroup baseContainer

This class defines the basic interface for any container implementation
in this module. 
\n Please note that:
- <b>total / size</b> : You should always use TContainer::total () to get the number of items in the container and \b NOT TContainer::size (). 
- <b>TContainer::error () </b> : There is a special item that is returned in error cases when a method returns a T&. This item is created using the 
T default constructor. So if you use a container template with build in types like 'int' or pointers, you might need to
initialize the error object yourself with a valid 'empty' value. This cannot be done automatically, since not every 
class has a constructor taking a NULL as argument! For example:
@code
TArray<int> myArray;
myArray.error () = -1;
@endcode

@see TIterator, TArray, TLinkedList, TDLinkedList
*/
//------------------------------------------------------------------------
template <class T> 
class TContainer
{
public:
//------------------------------------------------------------------------
	TContainer () : _size (0) {}                      
	TContainer (const TContainer<T>&);                
	virtual ~TContainer ();                           
	bool operator == (const TContainer<T>&) const;      
	bool operator != (const TContainer<T>&) const;      

	virtual TContainer<T>* newInstance () const = 0;    ///< Create a copy of this container

	inline T& operator[] (int32) const;                 ///< "[]" indexing operator returns the item at the specified index.

	virtual int32 total () const;                       ///< Return number of items.
	virtual bool isEmpty () const;                      ///< Is container empty?
	/** Returns the container size. 
	    The size of a container can be larger than the number of items it contains.
		For example the TArray implementation returns the number of items that fit 
		into the allocated memory and not the number of actually inserted items*/
	virtual int32 size () const;                        

	virtual bool add (const T& item) = 0;               ///< Add item to container.
	virtual bool remove (const T& item) = 0;            ///< Remove equal item.
	virtual bool remove (const TIterator<T>&) = 0;      ///< Remove item at current iterator position.
	virtual bool removeAt (int32 index) = 0;            ///< Remove item at given index.
	virtual void removeAll () = 0;                      ///< Remove all items from list.

	virtual T& at (int32 index) const;                  ///< Get item at index.
	virtual T& lookup (const T& item) const;            ///< Searches for the item equal to the specified item in the list and returns the first occurrence.
	virtual bool contains (const T& item) const;        ///< See if container has equal item.
	virtual int32 occurrences (const T& item) const;     ///< Count occurrences of equal items.

	virtual TIterator<T>* newIterator () const = 0;     ///< Create container iterator instance.

	TContainer< T >* lookupAll (const T& item) const;   ///< Allocate and returns a container with all items in this container equal to the specified item.
	bool addAllFrom (const TContainer<T>& container);   ///< Adds all the items from the specified container to this container
	bool addNewFrom (const TContainer<T>& container);   ///< Adds the items from the specified container to this container that are not in this container already

	T& error () const { return (T&)errorObject; }       ///< Access error object. 

//------------------------------------------------------------------------
protected:
	void copy (const TContainer<T>& container);         ///< Internal copy method. Copies the contents of the specified container into this container

	T errorObject;                                      ///< Object used as return value when methods returning a T& fail.
	int32  _size;                                       ///< Container size.
};


//------------------------------------------------------------------------
/** Template container iterator base class (abstract).
@ingroup baseContainer

Each container implementation has a matching iterator.
This class defines the basic interface for any iterator implementation.
\n Please note that TIterator::next and TIterator::previous always return the 
current iterator item and switch to the new item afterwards. This allows iteration
loops in this style:
@code
TLinkedList<int> myList;
...
TLinkedListIterator<int> iter (myList);
while (iter.done () == false)
{
	int myInt = iter.next ();
}
@endcode

@see Steinberg::TContainer
*/
//------------------------------------------------------------------------
template <class T> class TIterator 
{          
public:
//------------------------------------------------------------------------
	explicit TIterator (const TContainer<T>& cont) : _container (cont) {}
	virtual ~TIterator () {}

	virtual bool done () const = 0;               ///< Check if end of container is reached.
	virtual T& next () = 0;                       ///< Returns the current data and advances the iterator. postfix as in t = c++;
	virtual T& previous () = 0;                   ///< Returns the current data and backup. postfix as in t = c--;
	virtual T& current () const = 0;              ///< Returns the current data.
	virtual void first () = 0;                    ///< Move to first data.
	virtual void last () = 0;                     ///< Move to last data.

	T& next     (const T&);                       ///< Advance to next equal.
	T& previous (const T&);                       ///< Backup to previous equal.

	const TContainer<T>& container () const;      ///< Return container reference.

	operator int32 () const;                      ///< Check if not end.

	T& operator++ ();                             ///< Advance the iterator to the next item and return it.
	T& operator++ (int);                          ///< Return the current item and advance the iterator to the next.
	T& operator+= (int32 n);                      ///< Advance the iterator n places and returns the item.
	T& operator-- ();                             ///< Decrement the iterator by one and return the item.
	T& operator-- (int);                          ///< Return the current item and decrement the iterator by one.
	T& operator-= (int32);						  ///< Decrement the iterator n places and returns the item.
	T& operator () () const;                      ///< Return current item.

//------------------------------------------------------------------------
protected:
  const TContainer<T>& _container;                ///< Iterated container.
};

} // namespace Steinberg

//------------------------------------------------------------------------
/*! Template Iteration Macros.
@addtogroup baseContainer
The Iteration Macros \ref FOREACH_T , \ref FOREACH_T_REVERSE and \ref ENDFOR 
define a foreach loop where the item, type and collection are passed in and 
the item will be set equal to the next item in the collection for each loop 
iteration. These macros are supposed to work on any container derived from 
Steinberg::TContainer
\n Example:
@code
	TLinkedList<int> myList;
	myList.add (10);
	...
	int sum = 0;
	FOREACH_T (int, i, myList)
		sum += i;
	ENDFOR
@endcode
For containers of type TArrayBase some special iteration macros are supplied that 
support iteration without the need to allocate an iterator (\ref ARRAY_FOR_EACH_TYPE ,
\ref ARRAY_FOR_EACH_TYPE_I)
@{
*/
//------------------------------------------------------------------------
/** Defines a forward loop.*/
#define FOREACH_T(type, varName, cont) { \
	Steinberg::TIterator<type>* iter = (cont).newIterator (); \
	Steinberg::FDeleter <Steinberg::TIterator<type> > iterDeleter (iter);\
	while (!iter->done ()) { \
		type& varName = iter->next ();

//------------------------------------------------------------------------
/** Defines a reverse loop.*/
#define FOREACH_T_REVERSE(type, varName, cont) { \
	Steinberg::TIterator<type>* iter = (cont).newIterator (); \
	Steinberg::FDeleter <Steinberg::TIterator<type> > iterDeleter (iter);\
	iter->last (); \
	while (!iter->done ()) { \
		type& varName = iter->previous ();

//------------------------------------------------------------------------
/** Terminates the loop. */
#ifndef ENDFOR
#define ENDFOR } }
#endif

/*! @} */

//------------------------------------------------------------------------
//------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------
//------------------------------------------------------------------------


namespace Steinberg {


//------------------------------------------------------------------------
// TContainer
//------------------------------------------------------------------------

//------------------------------------------------------------------------
template <class T>
TContainer<T>::TContainer (const TContainer<T>&)
: _size (0)
{
}

//------------------------------------------------------------------------
template <class T>
TContainer<T>::~TContainer ()
{
}

//------------------------------------------------------------------------
template <class T>
inline T& TContainer<T>::operator[] (int32 idx) const
{
	return at (idx);
}

//------------------------------------------------------------------------
template <class T>
bool TContainer<T>::operator == (const TContainer<T>& other) const
{
	if (total () != other.total ())
		return false;

	TIterator<T>* iter1 = newIterator ();
	TIterator<T>* iter2 = other.newIterator ();
	FDeleter <TIterator<T> > iterDeleter1 (iter1);
	FDeleter <TIterator<T> > iterDeleter2 (iter2);
	while (!iter1->done ())
	{
		if (iter1->next () != iter2->next ())
			return false;
	}
	return true;
}

//------------------------------------------------------------------------
template <class T>
bool TContainer<T>::operator != (const TContainer<T>& other) const
{
	return (TContainer<T>::operator== (other) == false);
}

//------------------------------------------------------------------------
template <class T>
int32 TContainer<T>::size () const
{
	return _size;
}

//------------------------------------------------------------------------
template <class T>
int32 TContainer<T>::total () const
{
	return _size;
}

//------------------------------------------------------------------------
template <class T>
bool TContainer<T>::isEmpty () const
{
	return (total () == 0);
}

//------------------------------------------------------------------------
template <class T>
T& TContainer<T>::at (int32 idx) const
{
	if (idx < 0 || idx >= total ())
		return error ();
	TIterator<T> *iter = newIterator ();
	int32 ii = 0;
	T* out = 0;

	while (!iter->done () && ii <= idx)
	{
		if (ii++ == idx)
			out = &iter->current ();
		iter->next ();
	}
	delete iter;
	return *out;
}

//------------------------------------------------------------------------
template <class T>
T& TContainer<T>::lookup (const T& rItem) const
{
	TIterator<T> *iter = newIterator ();
	T* out = 0;
	while (!iter->done () && !out)
	{
		T& temp = iter->next ();
		if (temp == rItem)
			out = &temp;
	}
	delete iter;
	return out ? *out : error ();
}


//------------------------------------------------------------------------
template <class T>
bool TContainer<T>::contains (const T& rItem) const
{
	TIterator<T> *iter  = newIterator ();
	bool found = false;
	while (!iter->done () && !found)
		if (rItem == iter->next ())
			found = true;
	delete iter;
	return found;
}

//------------------------------------------------------------------------
template <class T>
int32 TContainer<T>::occurrences (const T& rItem) const
{
	TIterator<T> *iter = newIterator ();
	int32 occur = 0;
	while (!iter->done ())
		if (rItem == iter->next ())
			occur++;
	delete iter;
	return occur;
}

//------------------------------------------------------------------------
template <class T>
TContainer <T>* TContainer <T>::lookupAll (const T& rItem) const
{
	TContainer<T> *pList = newInstance ();
	TIterator<T> *iter  = newIterator ();
	while (!iter->done ())
	{
		T& temp = iter->next ();
		if (temp == rItem)
			pList->add (temp);
	}
	delete iter;
	return pList;
}

//------------------------------------------------------------------------
template <class T>
bool TContainer<T>::addAllFrom (const TContainer<T>& container)
{
	bool success = true;
	if (container.total ())
	{
		TIterator<T> *iter = container.newIterator ();
		while (!iter->done () && success)
			success = add (iter->next ());
		delete iter;
	}
	return success;
}


//------------------------------------------------------------------------
template <class T>
bool TContainer<T>::addNewFrom (const TContainer<T>& container)
{
	bool success = true;
	if (container.total ())
	{
		TIterator<T> *iter = container.newIterator ();
		while (!iter->done ())
		{
			T& item = iter->next ();
			if (contains (item) == false)
			{
				if (add (item) == false)
				{
					success = false;
					break;
				}
			}
		}
		delete iter;
	}
	return success;
}

//------------------------------------------------------------------------
template <class T>
void TContainer<T>::copy (const TContainer<T>& container)
{
	TIterator<T> *iter = container.newIterator ();
	while (!iter->done ())
		add (iter->next ());
	delete iter;
}



// -----------------------------------------------------------------
// "container" returns a reference to the container being iterated.
template <class T> 
const TContainer<T>& TIterator<T>::container () const
{
	return _container;
}


//------------------------------------------------------------------------
// TIterator
//------------------------------------------------------------------------

//------------------------------------------------------------------------
template <class T> 
TIterator<T>::operator int32 () const
{
	return !done ();
}

//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator++ ()
{
	next ();
	return current ();
}


//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator++ (int)
{
	return next ();
}

//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator+= (int32 num)
{
	for (int32 ii = 0; ii < num; ii++) 
		next ();
	return current ();
}

//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator-- ()
{
	previous ();
	return current ();
}


//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator-- (int)
{
	return previous ();
}

//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator-= (int32 num)
{
	for (int32 ii = 0; ii < num; ii++) 
		previous ();
	return current ();
}


//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::operator() () const
{
	return current ();
}


//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::next (const T& rItem)
{
	while (!done () && !(current () == rItem)) 
		next ();
	T& out = current (); 
	next ();
	while (!done () && !(current () == out)) 
		next ();
	return out;
}

//------------------------------------------------------------------------
template <class T> 
T& TIterator<T>::previous(const T& rItem)
{
	while (!done () && !(current () == rItem)) 
		previous ();
	T& out = current (); 
	previous ();
	while (!done () && !(current () == out)) 
		previous ();
	return out;
}


} // namespace Steinberg


#endif
