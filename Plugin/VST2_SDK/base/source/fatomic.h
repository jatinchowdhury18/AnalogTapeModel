//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fatomic.h
// Created by  : Steinberg, 05/2006
// Description : Atomic operations
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

#ifndef __fatomic__
#define __fatomic__

#include "pluginterfaces/base/ftypes.h"

namespace Steinberg {

//------------------------------------------------------------------------
/** Thread and multiprocessor safe increment 
	\param[in,out] var : the value to increment
	\return : old value of var */
int32 FAtomicIncrement (volatile int32& var);

//------------------------------------------------------------------------
/** Thread and multiprocessor safe decrement
	\param[in,out] var : the value to decrement
	\return : old value of var */
int32 FAtomicDecrement (volatile int32& var);

//------------------------------------------------------------------------
/**	Thread & multiprocessor safe addition
	\param[in,out] var : the initial value and the result
	\param[in] d : the value to add
	\return : old value of var */
//------------------------------------------------------------------------
int32 FAtomicAdd (volatile int32& var, int32 d);

//------------------------------------------------------------------------
/**	Thread & multiprocessor safe compare and swap
	compare var with oldVar and if they are equal set var to newVar
	\return : true if swap occured */
bool FAtomicCompareAndSwap (volatile int32& var, int32 oldVar, int32 newVar);

	//------------------------------------------------------------------------
	/**	Thread & multiprocessor safe compare and swap
	 compare var with oldVar and if they are equal set var to newVar.
	 Parameter are based on pointer, so it can be used in 32 and 64bit version.
	 \return : true if swap occured */
bool FAtomicCompareAndSwap (volatile void*& var, void* oldVar, void* newVar);
	
} // namespace Steinberg

#endif
