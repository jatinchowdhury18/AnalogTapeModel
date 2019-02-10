//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/tringbuf.h
// Created by  : Steinberg, 01/2009
// Description : Class factory
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

#ifndef __tringbuffer__
#define __tringbuffer__

#include "pluginterfaces/base/ftypes.h"
#if DEVELOPMENT
#include "base/source/fdebug.h"
#endif

namespace Steinberg {

//------------------------------------------------------------------------
// TRingBuffer
//------------------------------------------------------------------------
/** RingBuffer template.

	\ingroup baseContainer
	A RingBuffer is a data structure that uses a fixed-size buffer with circular connections.
*/
template <class T> class TRingBuffer
{
public:
//------------------------------------------------------------------------
	TRingBuffer (int32 n = 0);					///< Default constructor
	TRingBuffer (T* data, int32 n);				///< construct a RingBuffer with n data objects
	virtual ~TRingBuffer();						///< Destructor
	
	bool setBuffer (T* data, int32 n);			///< fills the buffer with n data objects
	
	bool resize (int32 n);						///< resize buffer to size n
	bool isEmpty () const;						///< tells if the buffer is empty
	int32 countFree () const;					///< returns the number of free slots in the buffer
	inline int32 countFilled () const;			///< returns the number of items in the buffer
	inline int32 size () const;					///< returns the number of slots in the buffer

	template <int32 count>
	int32 write (const T* data);				///< write count items to buffer
	int32 write (const T* data, int32 count);	///< write count items to buffer
	bool write (const T& data);					///< write one item to buffer
	int32 read (T* data, int32 count);          ///< read count items from buffer
	bool read (T& data);						///< read one item from buffer
	const T& peek () const;						///< look at current item in buffer
	int32 peek (T* data, int32 count)const;		///< look at count items in buffer
	void flush ();								///< remove all items from buffer
	int32 trash (int32 count);					///< remove count items from buffer
	
//------------------------------------------------------------------------
private:
	T* buffer;
	int32 bufferSize;
	int32 writePos;
	int32 readPos;
	bool bufferOwner;
};

//------------------------------------------------------------------------
/** RingBuffer constructor
	\param[in] n : initial size of the buffer */
//------------------------------------------------------------------------
template <class T> TRingBuffer<T>::TRingBuffer (int32 n)
:	buffer (0), bufferSize (0), bufferOwner (true)
{
	resize (n);
}

//------------------------------------------------------------------------
/** RingBuffer constructor with specified data pointer
	\param[in] data : pointer to data objects to be held in the buffer 
	\param[in] n : initial size of the buffer */
//------------------------------------------------------------------------
template <class T> TRingBuffer<T>::TRingBuffer (T* data, int32 n)
:	buffer (data), bufferSize (n), bufferOwner (false)
{
}

//------------------------------------------------------------------------
/** RingBuffer destructor */
//------------------------------------------------------------------------
template <class T> TRingBuffer<T>::~TRingBuffer ()
{
	resize (0);
}

//------------------------------------------------------------------------
/** Sets the RingBuffer to specified data pointer and given size n
	\param[in] data : pointer to data objects to be held in the buffer 
	\param[in] n : size of the buffer 
	\return : true */
//------------------------------------------------------------------------
template <class T> bool TRingBuffer<T>::setBuffer (T* data, int32 n)
{
	buffer = data;
	bufferSize = n;
	bufferOwner = false;
	return true;
}

//------------------------------------------------------------------------
/** Tells if the buffer is empty */
//------------------------------------------------------------------------
template <class T> bool TRingBuffer<T>::isEmpty () const
{
	return readPos == writePos;
}

//------------------------------------------------------------------------
/** Returns the number of free slots in the buffer */
//------------------------------------------------------------------------
template <class T> int32 TRingBuffer<T>::countFree () const
{
	if (readPos == writePos)
		return bufferSize;
	else if (writePos > readPos)
		return bufferSize - (writePos - readPos);
	else
		return readPos - writePos;

	return 0;
}

//------------------------------------------------------------------------
/** Returns the number of items in the buffer */
//------------------------------------------------------------------------
template <class T> inline int32 TRingBuffer<T>::countFilled () const
{
	return bufferSize - countFree ();
}

//------------------------------------------------------------------------
/** Returns the number of slots in the buffer */
//------------------------------------------------------------------------
template <class T> inline int32 TRingBuffer<T>::size () const
{
	return bufferSize;
}

//------------------------------------------------------------------------
/** Write one item to buffer
	\param[in] data : reference to the data structure 
	\return : true if successful / false if overflow */
//------------------------------------------------------------------------
template <class T> bool TRingBuffer<T>::write (const T& data)
{
	if (writePos == (readPos - 1))
	{
		#if DEVELOPMENT
		FDebugPrint ("TRingBuffer<T>::write overflow\n");
		#endif
		return false;
	}
	
	int32 pos = writePos;
	
	buffer[pos++] = data;
	if (pos >= bufferSize)
		pos = 0;

	writePos = pos;
	return true;
}

//------------------------------------------------------------------------
/** Write count items to buffer 
	\param[in] data : pointer to the data structure
	\param[in] count : number of items to be written
	\return : number of written items */
//------------------------------------------------------------------------
template <class T> int32 TRingBuffer<T>::write (const T* data, int32 count)
{
	int32 pos = writePos;
	
	if (pos == (readPos - 1))
	{
		#if DEVELOPMENT && 0
		FDebugPrint ("TRingBuffer<T>::write %d\n", count);
		#endif
		return 0;
	}
	
	int32 i = 0;
	for (; i < count; i++)
	{			
		buffer[pos++] = data[i];
		if (pos >= bufferSize)
			pos = 0;

		if (pos == (readPos - 1))
			break;
	}
	writePos = pos;
	return i;
}

//------------------------------------------------------------------------
/** write count items to buffer 
	\param[in] data : pointer to the data structure
	\param[in] count : number of items to be written
	\return : number of written items */
//------------------------------------------------------------------------
template <class T> template<int32 count> int32 TRingBuffer<T>::write (const T* data)
{
	int32 pos = writePos;
	
	if (pos == (readPos - 1))
	{
		#if DEVELOPMENT && 0
		FDebugPrint ("TRingBuffer<T>::write %d\n", count);
		#endif
		return 0;
	}
	
	int32 i = 0;
	for (; i < count; i++)
	{			
		buffer[pos++] = data[i];
		if (pos >= bufferSize)
			pos = 0;

		if (pos == (readPos - 1))
			break;
	}
	writePos = pos;
	return i;
}

//------------------------------------------------------------------------
/** read count items from buffer
	\param[in,out] data	: pointer to the data structure
	\param[in] count : number of requested items 
	\return : number of read items */ 
//------------------------------------------------------------------------
template <class T> int32 TRingBuffer<T>::read (T* data, int32 count)
{
	int32 i = 0;
	int32 pos = readPos;
	for (; i < count; i++)
	{
		if (pos == writePos)
			break;

		data[i] = buffer[pos++];
		if (pos >= bufferSize)
			pos = 0;
	}
	readPos = pos;
	return i;
}

//------------------------------------------------------------------------
/** Read one item from buffer
	\param[in,out] data : reference to the data structure 
	\return : true if successful */
//------------------------------------------------------------------------
template <class T> bool TRingBuffer<T>::read (T& data)
{
	return read (&data, 1) == 1;
}

//------------------------------------------------------------------------
/** look at current item in buffer without changing the read position 
	\return : peeked item */
//------------------------------------------------------------------------
template <class T> const T& TRingBuffer<T>::peek () const
{
	return buffer[readPos];
}

//------------------------------------------------------------------------
/** look at count items in buffer without changing the read position
	\param[in,out] data	: pointer to the data structure
	\param[in] count : number of requested items
	\return : number of peeked items */
//------------------------------------------------------------------------
template <class T> int32 TRingBuffer<T>::peek (T* data, int32 count) const
{
	int32 i = 0;
	int32 pos = readPos;
	for (; i < count; i++)
	{
		if (pos == writePos)
			break;

		data[i] = buffer[pos++];
		if (pos >= bufferSize)
			pos = 0;
	}
	return i;
}

//------------------------------------------------------------------------
/** Remove all items from buffer */
//------------------------------------------------------------------------
template <class T> void TRingBuffer<T>::flush ()
{
	readPos = 0;
	writePos = 0;
}

//------------------------------------------------------------------------
/** Remove count items from buffer 
	\param[in] count : number of items to be removed
	\return : number of removed items */
//------------------------------------------------------------------------
template <class T> int32 TRingBuffer<T>::trash (int32 count)
{
	int32 f = countFilled ();
	if (f >= count)
	{
		int32 pos = readPos+count;
		if (pos >= bufferSize)
			pos -= bufferSize;
		readPos = pos;
		return count;
	}

	readPos = writePos;
	return f;
}

//------------------------------------------------------------------------
/** Resize buffer to size n, if the buffer is the owner of the data
	\param[in] n : number of requested slots in the buffer 
	\return true if successful */
//------------------------------------------------------------------------
template <class T> bool TRingBuffer<T>::resize (int32 n)
{
	bool result = true;
	
	if (!bufferOwner)
		return false;
		
	if (buffer)
	{
		delete[] buffer;
		buffer = 0;
		bufferSize = 0;
	}
	
	if (n)
	{
		buffer = new T[n];
		if (buffer)
			bufferSize = n;
		else
			result = false;
	}
	
	writePos = 0;
	readPos = 0;
	
	return result;
}

}
#endif
