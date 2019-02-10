//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fcontainer.h
// Created by  : Steinberg, 1998
// Description : Object Container
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

#ifndef __fcontainer__
#define __fcontainer__

#include "base/source/tarray.h"
#include "base/source/tlist.h"
#include "base/source/tqueue.h"
#include "base/source/fobject.h"

namespace Steinberg {

//------------------------------------------------------------------------
/** @defgroup baseUnknownContainer FUnknown/FObject Containers
@ingroup baseContainer

This group contains some classes and macros that allow collecting
instances of FUnknown or FObject in template containers. 

When instances of FUnknown or FObject should be stored in one of the 
template collection classes and reference counting is required, this
can be handled using the smart pointer class IPtr like this:

@code
TLinkedList <IPtr <StringObject> > stringList;
StringObject* test = new StringObject ("test");
stringList.add (test);
test->release ();

String tmp;
FOREACH_O (StringObject, str, stringList)
	tmp += str->text ();
ENDFOR
@endcode

@{ */

//------------------------------------------------------------------------
// Some Standard Container.
//------------------------------------------------------------------------

/** Array holding FUnknown pointers */
typedef TArray <IPtr <FUnknown> > FArray;
/** Linked List holding FUnknown pointers */
typedef TLinkedList <IPtr <FUnknown> > FLinkedList;
/** Template container holding FUnknown pointers - can be used as function parameter */
typedef TContainer <IPtr <FUnknown> > FContainer;

/** @} */

//------------------------------------------------------------------------
/** Extends IPtr to allow sorted containers.
@ingroup baseUnknownContainer

When an implementation of FObject defines comparison operators and a sorting 
container like TOrderedArray is used to store objects sorted, FSortablePtr
can be used instead of IPtr. 

Example:
@code
TOrderedArray <FSortablePtr <StringObject> > strings;
StringObject* test = new StringObject ("test");
strings.add (test);
test->release ();
@endcode
*/
//------------------------------------------------------------------------
template <class I>
class FSortablePtr : public IPtr<I>
{
public:
//------------------------------------------------------------------------
	inline FSortablePtr (I* _ptr, bool addRef = true) : IPtr<I> (_ptr, addRef) {}
	inline FSortablePtr (const FSortablePtr& p) : IPtr<I> (p) {}
	inline FSortablePtr () {}
	template <class T2> inline FSortablePtr (const T2& t2) : IPtr<I> (t2) {}

	inline bool operator==(const FSortablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr == *other.ptr;
		return false;
	}
	inline bool operator!=(const FSortablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr != *other.ptr;
		return false;
	}
	inline bool operator>(const FSortablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr > *other.ptr;
		return false;
	}
	inline bool operator<(const FSortablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr < *other.ptr;
		return false;
	}
	inline bool operator<=(const FSortablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr <= *other.ptr;
		return false;
	}
	inline bool operator>=(const FSortablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr >= *other.ptr;
		return false;
	}

	using IPtr<I>::operator =;
};

//------------------------------------------------------------------------
/** Extends IPtr to allow comparison in containers.
@ingroup baseUnknownContainer

When an implementation of FObject defines operators== and a lookup 
in a container should compare object data instead of addresses, FComparablePtr
can be used instead of IPtr. 

Example:
@code
TArray <FComparablePtr <StringObject> > strings;
StringObject* test = new StringObject ("test");
strings.add (test);
test->release ();

StringObject tmp ("test");
StringObject* lookup = strings.lookup (&tmp);
@endcode
*/
//------------------------------------------------------------------------
template <class I>
class FComparablePtr : public IPtr<I>
{
public:
//------------------------------------------------------------------------
	inline FComparablePtr (I* _ptr, bool addRef = true) : IPtr<I> (_ptr, addRef) {}
	inline FComparablePtr (const FComparablePtr& p) : IPtr<I> (p) {}
	inline FComparablePtr () {}
	template <class T2> inline FComparablePtr (const T2& t2) : IPtr<I> (t2) {}

	inline bool operator==(const FComparablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr == *other.ptr;
		return false;
	}
	inline bool operator!=(const FComparablePtr<I>& other) const
	{
		if (this->ptr && other.ptr)
			return *this->ptr != *other.ptr;
		return false;
	}
	using IPtr<I>::operator =;
};

} // namespace Steinberg

//------------------------------------------------------------------------
/** @addtogroup baseUnknownContainer
@{ */
//------------------------------------------------------------------------
// FOREACH_O
/** Iterates a IPtr container. This macro does not support casting. */
//------------------------------------------------------------------------
#define FOREACH_O(type, varName, cont) { \
	Steinberg::TIterator<IPtr<type > >* iter = (cont).newIterator (); \
	Steinberg::FDeleter <Steinberg::TIterator<IPtr<type > > > iterDeleter (iter);\
	while (!iter->done ()) { \
		type* varName = iter->next ();

//------------------------------------------------------------------------
// FOREACH_O_REVERSE
/** Iterates a IPtr container reverse. This macro does not support casting. */
//------------------------------------------------------------------------
#define FOREACH_O_REVERSE(type, varName, cont) { \
	Steinberg::TIterator<IPtr<type > >* iter = (cont).newIterator (); \
	Steinberg::FDeleter <Steinberg::TIterator<IPtr<type > > > iterDeleter (iter);\
	iter->last (); \
	while (!iter->done ()) { \
		type* varName = iter->previous ();


//------------------------------------------------------------------------
// FOREACH_CAST
/** Iterates a template container - used with a basic item type that can be
    converted to another type using \ref Steinberg::FCast. When the cast fails, the object is
	skipped.
Example:
@code
	TLinkedList <IPtr <FUnknown> > stringList;
	StringObject* test = new StringObject ("test");
	stringList.add (test->unknownCast ());
	test->release ();

	String tmp;
	FOREACH_CAST (IPtr <FUnknown>, StringObject, str, stringList)
		tmp += str->text ();
	ENDFOR
@endcode */
//------------------------------------------------------------------------
#define FOREACH_CAST(baseType, type, varName, cont) { \
	Steinberg::TIterator<baseType >* iter = (cont).newIterator (); \
	Steinberg::FDeleter <Steinberg::TIterator<baseType > > iterDeleter (iter);\
	while (!iter->done ()) { \
		type* varName = Steinberg::FCast<type >(iter->next ()); \
		if (varName == 0) continue;

//------------------------------------------------------------------------
// FOREACH_CAST_REVERSE
/** Just like /ref FOREACH_CAST only in reverse order */
//------------------------------------------------------------------------
#define FOREACH_CAST_REVERSE(baseType, type, varName, cont) { \
	Steinberg::TIterator<baseType >* iter = (cont).newIterator (); \
	Steinberg::FDeleter <Steinberg::TIterator<baseType > > iterDeleter (iter);\
	iter->last (); \
	while (!iter->done ()) { \
		type* varName = Steinberg::FCast<type >(iter->previous ()); \
		if (varName == 0) continue;


//------------------------------------------------------------------------
// SPECIAL ARRAY ITERATION MACROS
/** Special array iteration macro - can be used instead of \ref FOREACH_CAST */
//------------------------------------------------------------------------
#define ARRAY_FOR_EACH_CAST(type, obj, containter)                     \
{ for (int32 i = 0; i < containter.total (); i++)                      \
{ type* obj = Steinberg::FCast<type > (containter.at (i));                      \
if (!obj) continue;

//------------------------------------------------------------------------
/** Special array iteration macro - can be used instead of \ref FOREACH_CAST_REVERSE */
//------------------------------------------------------------------------
#define ARRAY_FOR_EACH_REVERSE_CAST(type, obj, containter)             \
{ for (int32 i = containter.total () - 1; i >= 0 ; i--)                \
{ type* obj = Steinberg::FCast<type > (containter.at (i));                      \
if (!obj) continue;


/*! @} */

namespace Steinberg
{
// more sorting options: pass the sorting method as template parameter

//------------------------------------------------------------------------
template <typename T> struct TSorterFunc 
{
	typedef const T& ConstTRef;
	typedef int32 (*TCompareRefFunc) (ConstTRef, ConstTRef);   
	typedef T* TPtr;
	typedef int32 (*TComparePtrFunc) (TPtr, TPtr);   
};

//------------------------------------------------------------------------
// sortable pointer (no refCount)
//------------------------------------------------------------------------
template <typename T, typename TSorterFunc<T>::TComparePtrFunc CompareFunc> 
class TSortablePtr
{
public:
	inline TSortablePtr (T* d = 0) : ptr (d) {}
	inline TSortablePtr (const TSortablePtr& s) : ptr (s.ptr) {}

	typedef const TSortablePtr<T, CompareFunc> ConstRef;
	inline bool operator==(ConstRef& other) const {	return CompareFunc (ptr, other.ptr) == 0; }
	inline bool operator!=(ConstRef& other) const {	return CompareFunc (ptr, other.ptr) != 0; }
	inline bool operator>(ConstRef& other) const { return CompareFunc (ptr, other.ptr) > 0; }
	inline bool operator<(ConstRef& other) const { return CompareFunc (ptr, other.ptr) < 0; }
	inline bool operator<=(ConstRef& other) const { return CompareFunc (ptr, other.ptr) <= 0; }
	inline bool operator>=(ConstRef& other) const { return CompareFunc (ptr, other.ptr) >= 0; }

	inline operator T* ()  const { return ptr; }      // act as I*
	inline T* operator->() const { return ptr; }      // act as I*
	inline const TSortablePtr& operator=(T* _ptr) { ptr = _ptr; return *this;}
protected:
	T* ptr;
};

//------------------------------------------------------------------------
// sortable pointer (with refCount)
//------------------------------------------------------------------------
template <typename T, typename TSorterFunc<T>::TComparePtrFunc CompareFunc> 
class ISortablePtr : public IPtr<T>
{
public:
	inline ISortablePtr (T* _ptr) : IPtr<T> (_ptr) {}
	inline ISortablePtr (const ISortablePtr& p) : IPtr<T> (p) {}
	inline ISortablePtr () {}
	template <class T2> inline ISortablePtr (const T2& t2) : IPtr<T> (t2) {}

	typedef const ISortablePtr<T, CompareFunc> ConstRef;
	inline bool operator==(ConstRef& other) const {	return CompareFunc (this->ptr, other.ptr) == 0; }
	inline bool operator!=(ConstRef& other) const {	return CompareFunc (this->ptr, other.ptr) != 0; }
	inline bool operator>(ConstRef& other) const { return CompareFunc (this->ptr, other.ptr) > 0; }
	inline bool operator<(ConstRef& other) const { return CompareFunc (this->ptr, other.ptr) < 0; }
	inline bool operator<=(ConstRef& other) const { return CompareFunc (this->ptr, other.ptr) <= 0; }
	inline bool operator>=(ConstRef& other) const { return CompareFunc (this->ptr, other.ptr) >= 0; }

	using IPtr<T>::operator =;
};

//------------------------------------------------------------------------
// compare data (value passed by const reference)
//------------------------------------------------------------------------
template <typename T, typename TSorterFunc<T>::TCompareRefFunc CompareFunc> 
class TSortable
{
public:
	typedef const TSortable<T, CompareFunc> ConstRef;
	inline TSortable (const T& d) : data (d) {}
	inline TSortable (const TSortable& s) : data (s.data) {}

	inline bool operator==(ConstRef& other) const {	return CompareFunc (data, other.data) == 0; }
	inline bool operator!=(ConstRef& other) const {	return CompareFunc (data, other.data) != 0; }
	inline bool operator>(ConstRef& other) const { return CompareFunc (data, other.data) > 0; }
	inline bool operator<(ConstRef& other) const { return CompareFunc (data, other.data) < 0; }
	inline bool operator<=(ConstRef& other) const { return CompareFunc (data, other.data) <= 0; }
	inline bool operator>=(ConstRef& other) const { return CompareFunc (data, other.data) >= 0; }

	T data;
};

}


#endif
