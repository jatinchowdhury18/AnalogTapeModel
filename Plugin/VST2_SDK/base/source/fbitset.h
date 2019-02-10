//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fbitset.h
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

#ifndef __bitset__
#define __bitset__

#include "pluginterfaces/base/ftypes.h"

namespace Steinberg {

//------------------------------------------------------------------------
/** Bitset - A collection of bits.
@ingroup adt

	Individual indexed bits can be examined, set, or cleared.
	Its size is variable (grows as needed). 
	One BitSet may be used to modify the contents of another BitSet through logical AND, logical inclusive OR, and logical exclusive OR operations.
	By default, all bits in the set initially have the value 0 (Not Set).

\note Logical operations:
<pre>
	0 AND 0 = 0		0 OR 0 = 0		0 XOR 0 = 0
	0 AND 1 = 0		0 OR 1 = 1		0 XOR 1 = 1
	1 AND 0 = 0		1 OR 0 = 1		1 XOR 0 = 1
	1 AND 1 = 1		1 OR 1 = 1		1 XOR 1 = 0
</pre>
*/
//------------------------------------------------------------------------
class BitSet
{
public:
//---------------------------------------------------------------------
	BitSet ();					///< Default constructor (size is 0)
	BitSet (uint32 size);		///< Constructor with a given size (number of wanted bits)
	BitSet (const BitSet &);	///< Copy constructor 
	virtual ~BitSet ();			///< Virtual destructor

	BitSet& operator = (const BitSet &);	///< Assignment operator
	bool operator == (const BitSet&);		///< The equality operator
	bool operator != (const BitSet&);		///< The inequality operator

	BitSet& operator &= (const BitSet& toAnd);	///< Bitwise and (AND), both bitsets needs to have the same size, otherwise nothing happens
	BitSet& operator |= (const BitSet& toOr);	///< Bitwise inclusive or (OR), both bitsets needs to have the same size, otherwise nothing happens
	BitSet& operator ^= (const BitSet& toXOr);	///< Bitwise exclusive or (XOR), both bitsets needs to have the same size, otherwise nothing happens

	void setSize (uint32 size);				///< Resize to then number of bits that the bitset can hold, resize to 0 is allowed (free all), allocate memory is rounded to next kChunkSize
	uint32 getSize () const {return size;}	///< Return the current size of the BitSet
	
	void setBit (uint32 which);			///< Sets the bit (at 'which' position) to 1; resizes the bitSet if necessary when which > size
	void clearBit (uint32 which);		///< Sets the bit (at 'which' position) to 0; resizes the bitSet if necessary when which > size
	void toggleBit (uint32 which);		///< Changes the bits value (flip: 0=>1, 1=>0); resizes the bitSet if necessary when which > size
	void setAll ();						///< Sets all bits to 1
	void clearAll ();					///< Sets all bits to 0 (clears every bit)
	
	bool getBit (uint32 which) const;	///< Returns if the bit (at 'which' position) is set to 1
	bool isEmpty () const;				///< Returns true, if no bit is set (all 0)

	uint32 countSetBits (int32 toPos = -1) const;	///< Return the count of set bits from 0 to toPos position
	int64 getFirstSet () const;			///< Return the first found set bit (from 0 to size-1) or see \ref ReturnTypes
	int64 getFirstNotSet () const;		///< Return the first found NOT set bit (from 0 to size-1) or see \ref ReturnTypes
	int64 getLastSet () const;			///< Return the last found set bit (from size-1 to 0) or see \ref ReturnTypes

	enum ReturnTypes {
		kEmptySize   = -2L,				///< Return when the bitSet is empty when searching for a bit 
		kBitNotFound = -1L				///< Searched bit not found
	};

//---------------------------------------------------------------------
protected:
	typedef uint32 BSChunkType;
	static const uint32 kChunkSize = sizeof (BSChunkType) * 8;
	static const uint32 kChunkByteSize = sizeof (BSChunkType);
	static const BSChunkType kFullChunk = 0xfffffffful;

	virtual void onChange () {} ///< is called when bits are changed, derived classes can overwrite this.

	inline uint32 getChunkCount () const {return chunkCount;}	///< Return the count of chunk currently used and allocate
	BSChunkType getChunk (uint32 n) const;			///< Return the wanted chunk by index (return 0 if not available)
	void setChunk (uint32 n, BSChunkType chunk);	///< Set/replace a given chunk

//---------------------------------------------------------------------
private:
	uint32 size;
	uint32 chunkCount;
	BSChunkType* bits;
};


//------------------------------------------------------------------------
/** IDSet is a BitSet allowing to generate/release IDs starting with a given start offset

\note Example
<code>
	IDSet myIDSet (100, 8);	// its current size is Null
	int32 id1 = myIDSet.newID ();	// id1 is 100 (internally bitchunk is 00000001)
	int32 id2 = myIDSet.newID ();	// id2 is 101 (internally bitchunk is 00000011)
	int32 id3 = myIDSet.newID ();	// id3 is 102 (internally bitchunk is 00000111)
	int32 id4 = myIDSet.newID ();	// id4 is 103 (internally bitchunk is 00001111)

	myIDSet.releaseID (101);		// 101 as ID is released and could be reused later (internally bitchunk is 00001101)
	int32 id5 = myIDSet.newID ();	// id5 is 101 (internally bitchunk is 00001111)
	int32 id6 = myIDSet.newID ();	// id6 is 104 (internally bitchunk is 00011111)
	int32 id7 = myIDSet.newID ();	// id7 is 105 (internally bitchunk is 00111111)
	int32 id8 = myIDSet.newID ();	// id8 is 106 (internally bitchunk is 01111111)
	int32 id9 = myIDSet.newID ();	// id9 is 107 (internally bitchunk is 11111111)
	int32 id10 = myIDSet.newID ();	// id10 is 108 (internally bitchunk is 00000001 11111111)
</code>
*/
//---------------------------------------------------------------------
class IDSet : private BitSet
{
public:
//---------------------------------------------------------------------
	IDSet (int32 startOffset = 0, int32 growSize = 128);	///< Constructor with a given starteOffset and a growing Size
	
	int32 newID ();				///< Return a new ID (starting from the startOffset) : set the first NOT set bit to 1 and return its position added to the startOffset (resizes the bitSet if necessary)
	void releaseID (int32 id);	///< Clear associated bit to the given id
 	
//---------------------------------------------------------------------
private:
	int32 start;
	int32 growSize;
};

} // namespace Steinberg
#endif
