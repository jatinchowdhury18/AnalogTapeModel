//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fbitset.cpp
// Created by  : Steinberg, 1998
// Description : Bit Set + ID Set
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

#include "base/source/fbitset.h"
#include "base/source/fdebug.h" // for use of NEW
#include "pluginterfaces/base/futils.h" //  for use of Min

namespace Steinberg {


//-----------------------------------------------------------------------
BitSet::BitSet () 
: size (0)
, chunkCount (0)
, bits (0)
{
}

//-----------------------------------------------------------------------
BitSet::BitSet (uint32 initSize)
: size (0)
, chunkCount (0)
, bits (0)
{
	setSize (initSize);
}

//------------------------------------------------------------------------
BitSet::BitSet (const BitSet& from)
: size (0)
, chunkCount (0)
, bits (0)
{
	setSize (from.size);
	for (uint32 i = 0; i < chunkCount; i++)
	{
		bits[i] = from.bits[i];
	}
}

//-----------------------------------------------------------------------
BitSet::~BitSet ()
{
	if (bits)
		delete[] bits;
}

//------------------------------------------------------------------------
BitSet& BitSet::operator = (const BitSet& from)
{
	if (&from != this)
	{
		if (from.chunkCount != chunkCount)
			setSize (0);
	
		setSize (from.size);
		for (uint32 i = 0; i < chunkCount; i++)
		{
			bits[i] = from.bits[i];
		}
	}
	return *this;	
}

//------------------------------------------------------------------------
bool BitSet::operator == (const BitSet& toCompare)
{
	if (size == toCompare.size)
	{
		for (uint32 i = 0; i < chunkCount; i++)
		{
			if (bits[i] != toCompare.bits[i])
				return false;
		}
		return true;	
	}
	return false;
}

//------------------------------------------------------------------------
bool BitSet::operator != (const BitSet& toCompare)
{
	return !(*this == toCompare);
}

//------------------------------------------------------------------------
BitSet& BitSet::operator &= (const BitSet& toAnd)
{
	if (size == toAnd.size)
	{
		for (uint32 i = 0; i < chunkCount; i++)
		{
			bits[i] &= toAnd.bits[i];
		}
	}
	return *this;	
}

//------------------------------------------------------------------------
BitSet& BitSet::operator |= (const BitSet& toOr)
{
	if (size == toOr.size)
	{
		for (uint32 i = 0; i < chunkCount; i++)
		{
			bits[i] |= toOr.bits[i];
		}
	}
	return *this;	
}

//------------------------------------------------------------------------
BitSet& BitSet::operator ^= (const BitSet& toXOr)
{
	if (size == toXOr.size)
	{
		for (uint32 i = 0; i < chunkCount; i++)
		{
			bits[i] ^= toXOr.bits[i];
		}
	}
	return *this;	
}

//-----------------------------------------------------------------------
void BitSet::setBit (uint32 which)
{
	if (which >= size)
		setSize (which + 1);

	uint32 index = which / kChunkSize;
	uint16 remainder = which % kChunkSize;
	
	if (bits) 
		bits[index] |= (1ul << remainder);

	onChange ();
}

//-----------------------------------------------------------------------
void BitSet::clearBit (uint32 which)
{
	if (which >= size)
		setSize (which + 1);

	uint32 index = which / kChunkSize;
	uint16 remainder = which % kChunkSize;
	
	if (bits)
		bits[index] &= ~ (1ul << remainder);

	onChange ();
}

//------------------------------------------------------------------------
void BitSet::toggleBit (uint32 which)
{
	if (getBit (which))
		clearBit (which);
	else
		setBit (which);
}

//-----------------------------------------------------------------------
void BitSet::clearAll ()
{
	if (bits)
		memset (bits, 0, chunkCount * kChunkByteSize);

	onChange ();
}

//-----------------------------------------------------------------------
void BitSet::setAll ()
{
	if (bits)
		memset (bits, 0xFFFF, chunkCount * kChunkByteSize);

	onChange ();
}

//-----------------------------------------------------------------------
bool BitSet::getBit (uint32 which) const
{
	if (bits == 0 || which >= size)
		return false;

	int32 index = which / kChunkSize;
	int16 remainder = which % kChunkSize;
	
	return (bits[index] & (1ul << remainder)) != 0;	
}

//-----------------------------------------------------------------------
void BitSet::setSize (uint32 newSize)
{
	uint32* newBits	= 0;
	uint32 newChunkCount = 0;
	
	if (newSize) 
	{
		if (newSize % kChunkSize == 0)
		 	newChunkCount = (newSize / kChunkSize);
		else
		 	newChunkCount = (newSize / kChunkSize) + 1;
		
		if (newChunkCount == chunkCount)
		{
			if (newSize < size)
			{
				for (uint32 i = newSize; i < size; i++)
				{
					clearBit (i);
				}
			}
			size = newSize;
			return;
		}

		newBits = NEWVEC BSChunkType [newChunkCount];
	}
	
	if (newBits) 
	{
		memset (newBits, 0, newChunkCount * kChunkByteSize);
		int32 copyChunkCount = Min (newChunkCount, chunkCount); 
		if (bits)
			memcpy (newBits, bits, copyChunkCount * kChunkByteSize);				
	}
	
	if (bits)
		delete[] bits;

	bits = newBits;
	size = newSize;
	chunkCount = newChunkCount;
}

//-----------------------------------------------------------------------
bool BitSet::isEmpty () const
{
	bool empty = true;
	for (uint32 i = 0; i < chunkCount; i++) 
	{
		if (bits[i]) 
		{		
			if (i == chunkCount - 1 && (size % kChunkSize))
			{				
				BSChunkType tmp = (kFullChunk >> (kChunkSize - (size % kChunkSize)));
				if ((bits[i] & tmp) == 0)
					return true;			
			}
						
			empty = false;
			break;
		}
	}
	return empty;
}

//-----------------------------------------------------------------------
uint32 BitSet::countSetBits (int32 to) const
{
	uint32 tsize = (to == -1) ? getSize () : to;
	uint32 count = 0L;
	 
	for (uint32 i = 0; i < tsize; i++)
	{
		if (getBit (i))
			count++;
	}

	return count;
}

//-----------------------------------------------------------------------
int64 BitSet::getFirstSet () const
{
	uint32 tsize = getSize ();
	 
	if (isEmpty ())
		return (tsize == 0) ? kEmptySize : kBitNotFound;
	
	uint32 startIndex = tsize;
	for (uint32 c = 0; c < chunkCount; c++) 
	{
		if (bits[c] != 0)
		{
			startIndex = c * kChunkSize;
			break;
		}	
	}

	for (uint32 i = startIndex; i < tsize; i++)
	{
		if (getBit (i))
			return i;
	}

	return kBitNotFound;
}

//-----------------------------------------------------------------------
int64 BitSet::getFirstNotSet () const
{
	uint32 tsize = getSize ();

	if (isEmpty ())
		return (tsize == 0) ? kEmptySize : 0L; // return kEmptySize only if really empty
	 
	uint32 startIndex = tsize;
	for (uint32 c = 0; c < chunkCount; c++) 
	{
		if (bits[c] != kFullChunk)
		{
			startIndex = c * kChunkSize;
			break;
		}	
	}

	for (uint32 i = startIndex; i < tsize; i++)
	{
		if (!getBit (i))
			return i;
	}

	return kBitNotFound;
}

//-----------------------------------------------------------------------
int64 BitSet::getLastSet () const
{
	int64 tsize = getSize ();
	 
	if (isEmpty ())
		return (tsize == 0) ? kEmptySize : kBitNotFound;
	
	for (int64 i = tsize - 1; i > 0; i--)
	{
		if (getBit (static_cast<uint32> (i)))
			return i;
	}

	return 0;
}

//-----------------------------------------------------------------------
BitSet::BSChunkType BitSet::getChunk (uint32 n) const
{
	if (n < chunkCount)
		return bits[n];

	return 0;
}

//-----------------------------------------------------------------------
void BitSet::setChunk (uint32 n, BitSet::BSChunkType chunk)
{
	if (n < chunkCount)
		bits[n] = chunk;
}


//-----------------------------------------------------------------------
// IDSet
//-----------------------------------------------------------------------
IDSet::IDSet (int32 startOffset, int32 growSize) 
: BitSet (growSize)
, start (startOffset)
, growSize (growSize)
{
}

//-----------------------------------------------------------------------
int32 IDSet::newID ()
{
	int32 firstNotSet = (int32)getFirstNotSet ();
	if (firstNotSet < 0)
	{
		int32 currentSize = getSize ();
		setSize (currentSize + growSize);
		firstNotSet = currentSize;
	}
	setBit (firstNotSet);

	return firstNotSet + start;
}

//-----------------------------------------------------------------------
void IDSet::releaseID (int32 id)
{
	clearBit (id - start);
}

} // namespace Steinberg
