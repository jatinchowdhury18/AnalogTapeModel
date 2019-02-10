//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fatomic.cpp
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

#include "pluginterfaces/base/ftypes.h"
#include "base/source/fatomic.h"

#if MAC
#include <libkern/OSAtomic.h>
#if MAC_OS_X_VERSION_MIN_REQUIRED > MAC_OS_X_VERSION_10_4
#define NATIVE_ATOMIC_TYPE	(volatile int32_t*)
#else
#define NATIVE_ATOMIC_TYPE	(int32_t*)
#endif

#elif WINDOWS
#include <windows.h>
#endif

namespace Steinberg {

//------------------------------------------------------------------------
int32 FAtomicIncrement (volatile int32& var)
{
	// ATTENTION! Return the value *before* the Increment operation!!!
#if WINDOWS
	return InterlockedExchangeAdd (&var, 1);
#elif MAC
	return OSAtomicIncrement32Barrier (NATIVE_ATOMIC_TYPE &var) - 1;
#else
	return var++;
#endif
}

//------------------------------------------------------------------------
int32 FAtomicDecrement (volatile int32& var)
{
#if WINDOWS
	return InterlockedExchangeAdd (&var, -1);
#elif MAC
	return OSAtomicDecrement32Barrier (NATIVE_ATOMIC_TYPE &var) + 1;
#else
	return var--;
#endif
}

//------------------------------------------------------------------------
int32 FAtomicAdd (volatile int32& var, int32 d)
{
#if WINDOWS
	return InterlockedExchangeAdd (&var, d);
#elif MAC
	return OSAtomicAdd32Barrier (d, NATIVE_ATOMIC_TYPE &var) - d;
#else
	int32 v = var;
	var += d;
	return v;
#endif
}

//------------------------------------------------------------------------
bool FAtomicCompareAndSwap (volatile int32& var, int32 oldVar, int32 newVar)
{
#if WINDOWS
	return InterlockedCompareExchange (&var, newVar, oldVar) == oldVar;
#elif MAC
	return OSAtomicCompareAndSwap32Barrier (oldVar, newVar, NATIVE_ATOMIC_TYPE &var);
#else
	if (var == oldVar)
	{
		var = newVar;
		return true;
	}
	return false;
#endif
}

//------------------------------------------------------------------------
bool FAtomicCompareAndSwap (volatile void*& var, void* oldVar, void* newVar)
{
#if WINDOWS
	return InterlockedCompareExchangePointer ((volatile PVOID*)&var, newVar, oldVar) == oldVar;
#elif MAC
	return OSAtomicCompareAndSwapPtrBarrier (oldVar, newVar, (void* volatile*) &var);
#else
	if (var == oldVar)
	{
		var = newVar;
		return true;
	}
	return false;
#endif
}

} // namespace Steinberg
