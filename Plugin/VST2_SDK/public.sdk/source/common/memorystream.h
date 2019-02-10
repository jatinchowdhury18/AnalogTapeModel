//-----------------------------------------------------------------------------
// Project     : SDK Core
//
// Category    : Common Classes
// Filename    : memorystream.h
// Created by  : Steinberg, 03/2008
// Description : IBStream Implementation for memory blocks
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

#pragma once

#include "pluginterfaces/base/ibstream.h"

namespace Steinberg {

//--------------------------------------------------------------------------------------------------------------
// MemoryStream
//--------------------------------------------------------------------------------------------------------------
class MemoryStream : public IBStream
{
public:
//--------------------------------------------------------------------------------------------------------------
	MemoryStream ();
	MemoryStream (void* memory, TSize memorySize);
	virtual ~MemoryStream ();

	virtual tresult PLUGIN_API read  (void* buffer, int32 numBytes, int32* numBytesRead);
	virtual tresult PLUGIN_API write (void* buffer, int32 numBytes, int32* numBytesWritten);
	virtual tresult PLUGIN_API seek  (int64 pos, int32 mode, int64* result);
	virtual tresult PLUGIN_API tell  (int64* pos);

	TSize getSize ();
	void setSize (TSize);
	char* getData ();
	char* detachData (); // give up ownership
	bool truncate ();
	bool truncateToCursor ();

//--------------------------------------------------------------------------------------------------------------
	DECLARE_FUNKNOWN_METHODS
protected:
	char* memory;				// memory block
	TSize memorySize;			// size of the memory block
	TSize size;					// size of the stream
	int64 cursor;				// stream pointer
	bool ownMemory;				// stream has allocated memory itself
	bool allocationError;       // stream invalid
};

} // namespace
