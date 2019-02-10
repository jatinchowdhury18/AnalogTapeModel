//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/tvector.h
// Created by  : Steinberg, 2008
// Description : Vector class template
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


//----------------------------------------------------------------------------------
/** @file base/source/tvector.h
 Vector class template for vectors of arbitrary size. */
//----------------------------------------------------------------------------------
#ifndef __tvector__
#define __tvector__

#include "pluginterfaces/base/ftypes.h"
#include "base/source/fdebug.h"

namespace Steinberg {

//------------------------------------------------------------------------
/** TVector provides a basic templated container for arrays of dynamic size
@ingroup baseContainer
 
TVector is a base class that is not meant to be derived from. Elements can be stored and
removed from the vector, always causing a resize to the appropriate new size.

Thus, the container always keeps a memory efficient perfect fit. TVector is not 
suited for high performance insert and removal operations. Consider to use a class
with a more sophisticated allocation algorithm if the size of your container is bound to change often.
 
Insertions and removals on TVector are neither suited for real time processing and are not thread safe
because reallocation of memory is neccesary. Random access to elements of the vector is lock free
and thread safe. 
 
Because of the TVectors policy to always reallocate new memory, it is not recommended to store pointers or
references to the contents of the vector outside of TVector.
 */
//------------------------------------------------------------------------
template <class T> class TVector 
{
public:
// -----------------------------------------------------------------
	/**	Default constructor specifying the properties of the TVector
	 \param[in] size: the number of items to be inserted on construction
	 \param[in] items: pointer to the memory were the items are stored
	 */	
	TVector (int32 size = 0, const T* items = 0); 
	
	/**	Constructor fills a given number of elements in the vector with copies of a given item
	 \param[in] size: the number of copies of the given item to be inserted on construction
	 \param[in] item: reference to the item that is to be copied
	 */		
	TVector (int32 size, const T& item);                      
	
	/**	Copy Constructor
	 \param[in] otherVector: the vector that is to be copied on construction
	 */			
	TVector (const TVector<T>& otherVector); 
	
	~TVector (); /// <	Destructor. Releases all memory allocated by the vector. The destructor is note declared virtual and thus derivation from TVector is not recommended.

	/**	Assignment operator. TVector always reallocated new memory on assignment. Even when both vectors have the same size.
	 \param[in] otherVector: the vector that is to be copied on assignment
	 */	
	TVector<T>& operator= (const TVector<T>& otherVector);

	/**	Append another vector to this vector
	 \param[in] otherVector: The vector that should be appended to this vector
	 */	
	TVector<T>& operator+= (const TVector<T>& otherVector); 
	
	/**	Create a new vector that appends the contents of another vector to this vector
	 \param[in] otherVector: The vector that should be appended to this vector
	 */		
	TVector<T>  operator+ (const TVector<T>& otherVector) const;

	/**	Access operator. Used for read and write access. Note that their is no const counterpart.
	 \param[in] idx: The index of the element to be accessed. If idx < 0, idx is set to 0. If idx >= (size of this vector), the vector is resized to idx to make access possible.
	 */			
	T&       operator[] (int32 idx); 
	T&       at (int32 idx) {return this->operator[] (idx);}

	/**	Function operator. Used to extract a subset of the vector. The returned vector is a new vector that contains copies of the elements in the requested subset.
	 \param[in] idx:  The index of the first element of the subvector. If idx < 0 or idx >= (size of this vector), an empty vector is returned.
	 \param[in] size: Number of elements to be contained in the new vector. If idx + size > (size of this vector), an empty vector is returned. 
	 */				
	TVector<T> operator() (int32 idx, int32 size) const; 

	int32 size () const {return _size;} /// < Returns the size of this vector
	const T* array () const { return _array; } /// < Returns a const pointer to the first element stored in this vector. The pointer should not be stored as it will change on insertion and deletion of new elements.

	/**	Assign function that replaces this vector with the elements stored at the given pointer location. Always allocates new memory.
	 \param[in] items: pointer to the memory were the items are stored.
	 \param[in] size: the number of items to be inserted.
	 */	
	TVector<T>& assign (const T* items, int32 size = 1); 
	
	/**	Assign function that replaces this vector with an arbitrary number of copies of a given element. Always allocates new memory.
	 \param[in] item: reference to the item that is to be copied.
	 \param[in] size: the number of copies of the given item to be inserted.
	 */		
	TVector<T>& assign (const T& item, int32 size = 1); 

	/**	Append function that appends elements stored at the given pointer location to this vector. Always allocates new memory.
	 \param[in] items: pointer to the memory were the items are stored.
	 \param[in] size: the number of items to be appended.
	 */			
	TVector<T>& append (const T* items, int32 size = 1);
	
	/**	Append function that appends an arbitrary number of copies of a given element to this vector. Always allocates new memory.
	 \param[in] item: reference to the item that is to be copied.
	 \param[in] size: the number of copies of the given item to bo appended. 
	 */		
	TVector<T>& append (const T& item, int32 size = 1);
	
	/**	Insert function that inserts another vector at a given position of this vector. Always allocates new memory.
	 \param[in] idx: index at wich to insert the new vector. If idx = 0, the other vector will be prepended to this vector.
	 \param[in] otherVector: const reference to the other vector that is to be inserted into this vector.
	 */			
	TVector<T>& insert (int32 idx, const TVector<T>& otherVector);
	
	/**	Insert function that inserts elements stored at the given pointer location at a given position into this vector. Always allocates new memory.
	 \param[in] idx: index at wich to insert the new items. If idx = 0, the other items will be prepended to this vector. If idx < 0 or index > (size of this vector), nothing will be inserted.
	 \param[in] items: pointer to the memory were the items are stored.
	 \param[in] size: the number of items to be inserted .
	 */				
	TVector<T>& insert (int32 idx, const T* items, int32 size = 1);
	
	/**	Insert function that inserts an arbitrary number of copies of a given element into a given position in this vector. Always allocates new memory.
	 \param[in] idx: index at wich to insert the new items. If idx = 0, the other items will be prepended to this vector. If idx < 0 or index > (size of this vector), nothing will be inserted.
	 \param[in] item: reference to the item that is to be copied.
	 \param[in] size: the number of copies of the given item to be inserted.
	 */			
	TVector<T>& insert (int32 idx, const T& item, int32 size = 1);

	
	/**	Removes items from the vector. Always allocates new memory.
	 \param[in] idx:  The index of the first element to be removed from the vector. If idx < 0 idx >= (size of this vector), the vector is returned unchanged.
	 \param[in] size: Number of elements to be removed from the vector. If idx + size >= (size of this vector), the vector is returned unchanged.
	 */						
	TVector<T>& remove (int32 idx, int32 size = 1);                

	/**	Used to extract a subset of the vector. The returned vector is a new vector that contains copies of the elements in the requested subset.
	 \param[in] idx:  The index of the first element of the subvector. If idx < 0 or idx > (size of this vector), an empty vector is returned.
	 \param[in] size: Number of elements to be contained in the new vector. If idx + size > (size of this vector), an empty vector is returned. 
	 */					
	TVector<T> subVector (int32 idx, int32 size) const;            // Get sub vector.

	void clear (); /// < Clears the vector and sets the size to 0

	/**	Resize the whole vector and copies the contained elements to a new location. Always allocates new memory. Even if size == (size of this vector)
	 \param[in] size: size of the vector after resize.
	 */						
	bool resize (int32 size);
	bool grow (int32 minSize, int32 delta = -1);
// -----------------------------------------------------------------

private:
	int32      _size;                                    // Number of objects.
	T       *_array;                                   // Array of objects.
};

	
// -----------------------------------------------------------------
template <class T>
TVector<T>::TVector (int32 sz, const T* items)
: _size (0)
, _array (0)
{
	assign (items, sz);
}


// -----------------------------------------------------------------
template <class T>
TVector<T>::TVector (int32 sz, const T& fill)
: _size (0)
, _array (0)
{
	assign (fill, sz);
}


// -----------------------------------------------------------------
template <class T>
TVector<T>::TVector (const TVector<T>& vec)
: _size (0),
_array (0)
{
	assign (vec._array, vec._size);
}


// -----------------------------------------------------------------
template <class T>
TVector<T>::~TVector ()
{
	clear ();
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator= (const TVector<T>& vec)
{
	if (&vec != this)
		assign (vec._array, vec._size);
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::operator+= (const TVector<T>& vec)
{
	return append (vec._array, vec._size);
}
	
	
// -----------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator+ (const TVector<T>& vec) const
{
	TVector<T> out (*this);
	out.append (vec._array, vec._size);
	return out;
}


// -----------------------------------------------------------------
template <class T>
T& TVector<T>::operator[] (int32 idx)
{
	if (idx < 0) idx = 0;
	if (idx >= _size)
		if (!resize (idx + 1))
			idx = _size;
	return _array[idx];
}


// -----------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::operator() (int32 idx, int32 n) const
{
	return subVector (idx, n);
}

	
// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::assign (const T* pItems, int32 sz)
{
	if (!pItems || !sz || !resize (sz))
		return *this;
	for (int32 ii = 0; ii < sz; ii++)
		_array[ii] = pItems[ii];
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::assign (const T& rItem, int32 sz)
{
	if (!sz || !resize (sz))
		return *this;
	for (int32 ii = 0; ii < sz; ii++)
		_array[ii] = rItem;
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::append (const T* pItems, int32 sz)
{
	int32 current = size ();
	if (!pItems || !sz || !resize (current + sz))
		return *this;
	for (int32 ii = current; ii < size (); ii++)
		_array[ii] = pItems[ii-current];
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::append (const T& rItem, int32 sz)
{
	int32 current = size ();
	if (!sz || !resize (current + sz)) 
		return *this;
	for (int32 ii = current; ii < size (); ii++)
		_array[ii] = rItem;
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::insert (int32 idx, const TVector<T>& vec)
{
	return insert (idx, vec.array (), vec.size ());
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::insert (int32 idx, const T* pItems, int32 sz)
{
	int32 size1 = size ();

	if (idx < 0 || idx > size1 || !pItems || !resize (size1+sz))
		return *this;

	int32 ii;
	for (ii = size ()-1; ii >= (idx+sz); ii--)
		_array[ii] = _array[ii-sz];
	for (ii = 0; ii < sz; ii++)
		_array[idx+ii] = pItems[ii];
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::insert (int32 idx, const T& rItem, int32 sz)
{
	int32 ii;
	int32 size1 = size ();

	if (idx < 0 || idx > size1 || !resize (size1+sz))
		return *this;

	for (ii = size()-1; ii >= (idx+sz); ii--)
		_array[ii] = _array[ii-sz];
	for (ii = 0; ii < sz; ii++)
		_array[idx+ii] = rItem;
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::remove (int32 idx, int32 nItems)
{
	int32 size1 = size ();

	if (idx < 0 || idx > size1 || nItems <= 0 || (idx+nItems) > size1)
		return *this;

	for (int32 ii = idx; ii < (size1-nItems); ii++)
		_array[ii] = _array[ii+nItems];
	resize (size1-nItems);
	return *this;
}


// -----------------------------------------------------------------
template <class T>
TVector<T> TVector<T>::subVector (int32 idx, int32 n) const
{
	if (idx < 0 || (idx+n) > _size)
		return TVector<T> ();
	return TVector<T>(n, &(_array[idx]));
}


// -----------------------------------------------------------------
template <class T>
void TVector<T>::clear ()
{
	if (_array)
	{
		delete[] _array;
		_size  = 0;
		_array = 0;
	}
}


// -----------------------------------------------------------------
template <class T>
bool TVector<T>::resize (int32 newsize)
{
	if (newsize == 0)
		clear();
	else
	{
		T *newentries = NEWVEC T[newsize];
		if (!newentries)
			return false;
		if (_size > 0)
		{
			int32 limit = (_size > newsize) ? newsize : _size;
			for (int32 ii = 0; ii < limit; ii++)
				newentries[ii] = _array[ii];
			delete[] _array;
		}
		_size  = newsize;
		_array = newentries;
	}
	return true;
}

template <class T>
bool TVector<T>::grow (int32 minSize, int32 delta)
{
	if (_size < minSize)
	{
		int32 newSize;
		if (delta < 0) // exponential
		{
			newSize = minSize * 2;
			if (newSize < 10)
				newSize = 10;
		}
		else
		{
			newSize = minSize + delta;
		}
		return resize (newSize);
	}
	return true;
}


}

#endif
