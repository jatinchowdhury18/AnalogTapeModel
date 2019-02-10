//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fmemory.h
// Created by  : Steinberg, 1998
// Description : memory allocation helper functions and classes
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

//----------------------------------------------------------------------------------
/** @file base/source/fmemory.h
	Memory allocation helper functions and classes. */
//----------------------------------------------------------------------------------
#ifndef __fmemory__
#define __fmemory__

#include "base/source/fthread.h"
#include "base/source/tarray.h"

namespace Steinberg {

//------------------------------------------------------------------------
	/** Allocate memory aligned to a given alignment
	\param[in] size : size of the memory to be allocated
	\param[in] alignment : specifies the desired byte alignment of the returned address. This must be even and greater than 2.
		You will get undefined behavior if the alignment is not a power of 2.
	\return the aligned memory address, or 0 if the alignment is invalid or the allocation from the heap failed 
	
	Allocation is done on the heap of the standard runtime by allocating more memory and returning the first address that
	meets the alignment demands. 
	You must free the memory by calling alignedFree.
	*/
void* alignedMalloc (int32 size, int32 alignment = 16);

//------------------------------------------------------------------------
/** Free aligned memory allocated by alignedMalloc
	\param[in] buffer : pointer to the memory allocated by alignedMalloc
	*/
bool  alignedFree (void* buffer);

//------------------------------------------------------------------------

//------------------------------------------------------------------------
/** FMemoryPool provides a pool of equal sized cached memory blocks

When a lot of equal sized objects are needed, FMemoryPool can be used for fast allocation.
A standard application is overloading the new operator of a class that is often allocated and deallocated.

FMemoryPool starts empty and allocates requested memory blocks from the heap. If a block is returned 
to the pool, it is placed on top of a stack of cached objects that are used for fast handling of later
allocations.

The number of objects that are kept in memory for fast re-use is given with the constructor. Requests beyond this threshold
are returned to the heap.

FMemoryPool is thread safe, as it uses FLock to synchronize modifications to the pool.

\see FMemoryBlockPool
*/
//------------------------------------------------------------------------
class FMemoryPool
{
public:
//------------------------------------------------------------------------
	/**	Constructor specifying the properties of the pool
		\param[in] maxElements : the maximum number of unused memory blocks that are kept in memory
		\param[in] elementSize : the size of each memory block. It must be greater than sizeof(void*).
	*/
	FMemoryPool (int32 maxElements, int32 elementSize);
	~FMemoryPool ();			///< Destructor. Releases cached memory back to the heap.

	void* newElement ();		///< allocate an uninitialized memory block from the pool. If no unused block exists in the pool, allocate it from the heap.
	#if WINDOWS && DEVELOPMENT
	void* newElement (const char8 *, int32);	///< debug version of newElement () to trace filename and line number
	#endif
	void deleteElement (void* el); ///< return a block, that has been allocated with newElement ()
//------------------------------------------------------------------------
private:
	int32 maxElements;
	int32 elementSize;
	int32 elementCount;
	void** firstElement;
	FLock lock;
};

//------------------------------------------------------------------------
/** FMemoryBlockPool provides a pool of equal sized preallocated memory blocks

When a lot of equal sized objects are needed, FMemoryPool can be used for fast allocation and with
little memory overhead.
A standard application is overloading the new operator of a class that is often allocated and deallocated.

FMemoryPool starts empty and preallocates a given number of memory blocks from the heap. If a block is returned 
to the pool, it is placed on top of a stack of cached objects that are used for fast handling of later
allocations.

Memory is not released to the heap until the destructor.

FMemoryPool is thread safe, as it uses FLock to synchronize modifications to the pool.

\see FMemoryPool
*/
//------------------------------------------------------------------------
class FMemoryBlockPool
{
public:
//------------------------------------------------------------------------
	/**	Constructor specifying the properties of the pool
		\param[in] delta : number of memory blocks that are preallocated when there is no unused block available
		\param[in] elementSize : the size of each memory block. It must be greater than sizeof(void*).
	*/
	FMemoryBlockPool (uint32 delta, uint32 elementSize);
	~FMemoryBlockPool ();	///< destructor

	void* newElement ();			///< allocate an uninitialized memory block from the pool.
	void deleteElement (void* el);	///< return a block, that has been allocated with newElement ()
//------------------------------------------------------------------------
private:
	void** grow ();

	uint32 delta;
	uint32 elementSize;
	void** freeElement;
	TArray<void*> buffers;

	FLock lock;
};


//------------------------------------------------------------------------
/** FBlockAllocator provides a simple allocator that works on larger blocks of memory

FBlockAllocator is used to allocate chunks of memory that are placed in 
larger memory blocks.

Memory is not released to the heap until the destructor of FBlockAllocator.

FBlockAllocator is thread safe, as it uses FLock to synchronize modifications.
*/
class FBlockAllocator
{
public:
//------------------------------------------------------------------------
	/**	Constructor
		\param[in] blockSize : size of the memory blocks, that provide space for smaller allocations
	*/
	FBlockAllocator (uint32 blockSize);
	~FBlockAllocator (); ///< Destructor. Releases allocated memory back to the heap.

	void* allocate (uint32 size);	///< allocate memory from within a preallocated memory block. If size is larger than blockSize, blockSize is increased in multiples of 2.
	void free (void* p);			///< free memory allocated with allocate()

//------------------------------------------------------------------------
protected:
	///\cond ignore
	struct ChunkHeader // chunks are items of a block
	{
		uint32 magic;
		uint32 size; // size of chunk (without this header)
		bool used;	
	};
	
	struct Block
	{
		uint32 size; // size of data in bytes
		void* data; 
	
		int operator == (const Block& b) const {return b.size == size && b.data == data;}
	};
	///\endcond
	TArray<Block> blocks;
	uint32 blockSize;
	FLock lock;
};

class FObjectBlock;

//------------------------------------------------------------------------
/** FObjectPool allocates objects in blocks with MAX_USHORT elements per block

FObjectPool can be used, if a lot of small equal sized elements are needed. Allocation 
and deallocation are fast and have little memory overhead. FObjectPool should not
be used for large objects.

Memory is not released to the heap until the destructor of FBlockAllocator.

FObjectPool is thread safe, as it uses FLock to synchronize modifications.
*/
class FObjectPool 
{
public:
//------------------------------------------------------------------------
	/**	Constructor
		\param[in] elementSize : size of one element
	*/
	FObjectPool (uint16 elementSize);
	~FObjectPool ();					///< Destructor. Releases allocated memory back to the heap.

	void* newElement ();				///< allocate memory from within the preallocated memory block. If no more free entries are found, a new memory block is allocated.
	void deleteElement (void* el);		///< return element to the pool.

//------------------------------------------------------------------------
private:
	FLock lock;	
	uint16 objectSize;
	TArray <FObjectBlock*> blocks;
};

} // namespace Steinberg

#endif
