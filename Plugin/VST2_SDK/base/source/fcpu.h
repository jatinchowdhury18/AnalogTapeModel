//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fcpu.h
// Created by  : Steinberg, 03.2007
// Description : CPU detection
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

//------------------------------------------------------------------------
/** @file base/source/fcpu.h
	CPU detection. */
//------------------------------------------------------------------------

#ifndef __fcpu__
#define __fcpu__

#include "pluginterfaces/base/ftypes.h"

namespace Steinberg {

//------------------------------------------------------------------------
/** CPU Info. */
//------------------------------------------------------------------------
class FCpuInfo
{
public:
//------------------------------------------------------------------------
	FCpuInfo ();
	~FCpuInfo ();

	//--------------------------------------------------------------------
	/** Returns the number of cpu-cores present
		@return number of available cpu-cores */
	int32 countLogical () const { return numLogical; }

	//--------------------------------------------------------------------
	/** Returns the number of cpu-cores currently available for processing
		@return number of available cpu-cores */
	int32 countAvailable () const { return numAvailable; }

	//--------------------------------------------------------------------
	/** Returns true if the core with the given index is available 
		@return true if the core with the given index is available */
	bool isLogicalAvailable (int32 index);

//------------------------------------------------------------------------
protected:
	void initialize ();

	int32 numLogical;
	int32 numAvailable;
};

} // namespace Steinberg
#endif
