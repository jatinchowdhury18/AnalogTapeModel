//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fmemory.h
// Created by  : Steinberg, 1998
// Description : 
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

#include "base/source/fmemory.h"

#include <stdlib.h>
#include <limits.h>

namespace Steinberg {

//------------------------------------------------------------------------
void* alignedMalloc (int32 size, int32 alignment /*= 16*/)
{
	if (alignment < 2 || alignment % 2 != 0)
		return 0;

	int32 padding = alignment + sizeof (void*);
	size += padding;								// padding for alignment and storage of original address

	void* buffer = malloc (size);
	if (buffer)
	{
		TPtrInt address = (TPtrInt) buffer;			// take address and store it in int (dependent on size of int)
		address += padding;
		address &= ~((TPtrInt) (alignment - 1));	// align address

		void* alignedBuffer = (void*) address;		// aligned memory
		address -= sizeof (void*);					// give way for pointer
		*(void**) address = buffer;					// store originally allocated address

		return alignedBuffer;
	}
	else
		//exception will be thrown. Sometimes returning 0 is not enough, for example, if memory allocation fails 
		// in constructor, you have no chance to return from constructor with false or kResultFalse
		throw ("Not enough memory!");

	return 0;
}

//------------------------------------------------------------------------
bool alignedFree (void* buffer)
{
	if (buffer)
	{
		TPtrInt address = (TPtrInt) buffer;	// take address and store it in int (dependent on size of int)
		address -= sizeof (void*);
		buffer = *(void**) address;			// get originally allocated address
	}

	free (buffer);							// free all allocated memory

	return true;
}

//------------------------------------------------------------------------------
FMemoryPool::FMemoryPool (int32 maxElements, int32 elementSize) 
: maxElements (maxElements)
, elementSize (elementSize)
, elementCount (0)
, firstElement (0)
{
}

//------------------------------------------------------------------------------
FMemoryPool::~FMemoryPool ()
{	
	while (elementCount > 0 && firstElement)
	{
		void** element = firstElement;
		if (element)
		{
			firstElement = (void**)*element;
			elementCount--;
			delete[] (int8*)element;
		}			
	}
}

#if WINDOWS && DEVELOPMENT
//------------------------------------------------------------------------------
void* FMemoryPool::newElement (const char8* file, int32 line)
{
	if (firstElement)
	{
		FGuard g (lock);
		
		void** e = firstElement;
		if (e)
		{
			firstElement = (void**)*e;
			elementCount--;
			return e;
		}
	}
	return new (1, file, line) int8[elementSize];
}
#endif

//------------------------------------------------------------------------------
void* FMemoryPool::newElement ()
{
	if (firstElement)
	{
		FGuard g (lock);
		
		void** e = firstElement;
		if (e)
		{
			firstElement = (void**)*e;
			elementCount--;
			return e;
		}
	}
	return NEWVEC int8[elementSize];
}

//------------------------------------------------------------------------------
void FMemoryPool::deleteElement (void* el)
{
	if (elementCount >= maxElements)
		delete[] (int8*)el;
	else
	{
		FGuard g (lock);
			
		void** eNext = (void**)el;
		*eNext = firstElement;
		firstElement = eNext;
		elementCount++;
	}
}

//------------------------------------------------------------------------
// FMemoryBlockPool
//------------------------------------------------------------------------
FMemoryBlockPool::FMemoryBlockPool (uint32 delta, uint32 elementSize)
: delta (delta)
, elementSize (elementSize)
, freeElement (0)
{
}

//------------------------------------------------------------------------
FMemoryBlockPool::~FMemoryBlockPool ()
{
	for (int32 i = 0; i < buffers.total (); i++)
		delete [] (uint8*) buffers [i];
}

//------------------------------------------------------------------------
void** FMemoryBlockPool::grow ()
{
	uint8* data = NEWVEC uint8 [delta * elementSize];
	buffers.add (data);

	void** result = (void**)data;

	for (uint32 i = 0; i < delta; i++, data += elementSize)
	{
		void** nextFreeIndexPtr = (void**)data;
		if (i == delta - 1)
			*nextFreeIndexPtr = 0;
		else
		{
			void* nextFreeAdress = (void*)(data + elementSize);
			*nextFreeIndexPtr = nextFreeAdress;
		}
	}
	
	return result;
}


//------------------------------------------------------------------------
void* FMemoryBlockPool::newElement ()
{
	FGuard g (lock);

	if (freeElement == 0)
		freeElement = grow ();

	void** e = freeElement;
	if (e)
	{
		freeElement = (void**)*e;		
		return e;
	}

	ASSERT (0)
	return 0;
}

//------------------------------------------------------------------------
void FMemoryBlockPool::deleteElement (void* el)
{
	FGuard g (lock);

	void** eNext = (void**)el;
	*eNext = freeElement;
	freeElement = eNext;
}


//------------------------------------------------------------------------
// FBlockAllocator
//------------------------------------------------------------------------
/*
  - the block allocator is an array of 'blocks' 
  - memory is organized in multiple blocks with a minimal size of 'blockSize'
  - a block is divided into chunks (the chunks are returned in 'allocate' calls)
  - the size of a block is the size of the internally allocated memory
  - the size of a chunk is maximum space that can be allocated. A chunk gets its size when it is first allocated.
    the real size of a chunk is chunk-size + chunk-header-size
  - a chunk can is marked as unused when 'free' is called

  Block:
	|--------------------------------|
	|C1*******C2***************C3****|
	|*****************C4*************|
	|*C5*****************000000000000|
	|00000000000000000000000000000000|
	|--------------------------------|

  Chunk:
    |--------------------------------|
    | Header (size, used)            |  size is without header size
	|--------------------------------|
	| Memory                         |
	|                                |
	|                                |
	|--------------------------------|

*/

static const uint32 kBlockAllocChunkMagic = 0x40834779;
//------------------------------------------------------------------------
FBlockAllocator::FBlockAllocator (uint32 blockSize)
: blockSize (blockSize)
{
}

//------------------------------------------------------------------------
FBlockAllocator::~FBlockAllocator ()
{
	for (int32 i = 0; i < blocks.total (); i++)
		delete [] (uint8*) blocks.at (i).data;
}

//------------------------------------------------------------------------
void* FBlockAllocator::allocate (uint32 size)
{
	if (size == 0)
		return 0;

	int32 chunkSizeNeeded = size + sizeof (ChunkHeader);
	if (chunkSizeNeeded < 0)
		return 0;

	FGuard g (lock);

	ChunkHeader* destChunk = 0;
	for (int32 i = 0; i < blocks.total (); i++)
	{
		void* blockData =  blocks.at (i).data;
		uint32 currentBlockSize = blocks.at (i).size;	

		ChunkHeader* header = (ChunkHeader*) blockData;
		int32 remainingBlockSpace = currentBlockSize;	
		ChunkHeader* lastUnused = 0;

		while (remainingBlockSpace >= chunkSizeNeeded)
		{
			if (header->size == 0) // untouched at the end
			{
				header->size = size;
				header->magic = kBlockAllocChunkMagic;
				destChunk = header;
				break;
			}
			else 
			{
				if (header->magic != kBlockAllocChunkMagic) 
				{
					ASSERT (0) // corrupt block!
					break;				
				}

				uint32 chunkSize = header->size + sizeof (ChunkHeader);

				if (header->used == false)
				{
					if (header->size >= size)
					{					
						if (header->size > (size + sizeof (ChunkHeader)) * 2) // twice as big -> split the chunk
						{
							header->size = size;

							uint32 upperChunkSize = size + sizeof (ChunkHeader); 
							uint32 lowerChunkSize = chunkSize - upperChunkSize;
						
							uint8* blockData2 = (uint8*)header;
							blockData2 += upperChunkSize;
							ChunkHeader* lowerChunk = (ChunkHeader*)blockData2;
							
							lowerChunk->size = lowerChunkSize - sizeof (ChunkHeader);
							lowerChunk->used = false;
							lowerChunk->magic = kBlockAllocChunkMagic;
						}
						
						destChunk = header;
						break;
					}

					if (lastUnused && lastUnused->size + chunkSize >= size) // combine chunks
					{
						lastUnused->size += chunkSize;
						destChunk = lastUnused;
						break;
					}

					lastUnused = header;
				}
				else
					lastUnused = 0;

				// next
				remainingBlockSpace -= chunkSize;

				uint8* newBlockData = (uint8*)header;
				newBlockData += chunkSize;
				header = (ChunkHeader*)newBlockData;


				// security checks
				ASSERT (remainingBlockSpace >= 0)
				int32 diffToBlockStart = static_cast<int32> ((uint8*)header - (uint8*)blockData);
				if (diffToBlockStart > (int32)currentBlockSize || diffToBlockStart < 0)
				{
					ASSERT (0) // corrupt block!
					break;
				}						
			}
		}

		if (destChunk)
			break;
	}

	if (destChunk == 0)
	{
		while (size > blockSize / 2)
			blockSize *= 2;
		
		void* data = NEWVEC uint8 [blockSize];
		if (data)
		{
			memset (data, 0, blockSize);
			Block b;
			b.data = data;
			b.size = blockSize;
			blocks.add (b);
	
			destChunk = (ChunkHeader*)data;
			destChunk->magic = kBlockAllocChunkMagic;
			destChunk->size = size;
		}
		else
			return 0;
	}
	
	destChunk->used = true;
	uint8* data = (uint8*)destChunk;
	return data + sizeof (ChunkHeader);
}

//------------------------------------------------------------------------
void FBlockAllocator::free (void* p)
{
	if (p == 0)
		return;
	FGuard g (lock);
	uint8* data = (uint8*)p;
	data -= sizeof (ChunkHeader);
	ChunkHeader* header = (ChunkHeader*) data;
	if (header->magic != kBlockAllocChunkMagic)
	{
		ASSERT (0)
		return;
	}
	header->used = false;
}


//------------------------------------------------------------------------
// FObjectBlock
//------------------------------------------------------------------------
class FObjectBlock
{
	friend class FObjectPool;
	FObjectBlock (uint16 elementSize);
	~FObjectBlock ();

	void* newElement ();
	void deleteElement (void* el);
	
	bool containsElement (void* el);
	bool isFull ();
	uint16* freeStack;
	int8* pool;
	uint16 freeCount;
	uint16 allocCount;
	uint16 objectSize;
};

//------------------------------------------------------------------------
inline FObjectBlock::FObjectBlock (uint16 objSize)
:	objectSize (objSize), freeCount (0), allocCount (0)
{
	freeStack = NEWVEC uint16 [USHRT_MAX];
	pool = NEWVEC int8 [USHRT_MAX*objectSize];
}

//------------------------------------------------------------------------
inline FObjectBlock::~FObjectBlock ()
{
	delete [] freeStack;
	delete [] pool;
}

//------------------------------------------------------------------------
inline void* FObjectBlock::newElement ()
{
	if (freeCount > 0)
		return pool + (freeStack[--freeCount] * objectSize);
	ASSERT (allocCount < USHRT_MAX)
	return pool + (allocCount++ * objectSize);
}

//------------------------------------------------------------------------
inline void FObjectBlock::deleteElement (void* el)
{
	freeStack [freeCount++] = (uint32)(((int8*)el) - pool) / objectSize;
}

//------------------------------------------------------------------------
inline bool FObjectBlock::containsElement (void* el)
{
	return el >= pool && el < (pool + USHRT_MAX*objectSize);
}

//------------------------------------------------------------------------
inline bool FObjectBlock::isFull ()
{
	return freeCount == 0 && allocCount == USHRT_MAX;
}



//------------------------------------------------------------------------
// FObjectPool
//------------------------------------------------------------------------
//------------------------------------------------------------------------
FObjectPool::FObjectPool (uint16 objSize)
:	objectSize (objSize)
{
	FObjectBlock* block = NEW FObjectBlock (objectSize);
	blocks.add (block);
}

//------------------------------------------------------------------------
FObjectPool::~FObjectPool ()
{
	for (int32 i = 0; i < blocks.total (); i++)
		delete blocks.at (i);
}

//------------------------------------------------------------------------
void* FObjectPool::newElement ()
{
	FGuard g (lock);
	for (int32 i = 0; i < blocks.total (); i++)
		if (blocks.at (i)->isFull () == false)
			return blocks.at (i)->newElement ();
	FObjectBlock* block = NEW FObjectBlock (objectSize);
	blocks.add (block);
	return block->newElement ();
}

//------------------------------------------------------------------------
void FObjectPool::deleteElement (void* el)
{
	FGuard g (lock);
	for (int32 i = 0; i < blocks.total (); i++)
		if (blocks.at (i)->containsElement (el))
			blocks.at (i)->deleteElement (el);
}

} // namespace Steinberg
