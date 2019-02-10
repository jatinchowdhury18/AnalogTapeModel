//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/fcpu.cpp
// Created by  : Steinberg, 03.2007
// Description : cpu detection
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

#include "base/source/fcpu.h"

#include "pluginterfaces/base/fplatform.h"

#if WINDOWS 
#include <windows.h>
#elif MAC
#include <sys/types.h>
#include <sys/sysctl.h>
#endif

namespace Steinberg {

//------------------------------------------------------------------------
// CPU Info
//------------------------------------------------------------------------
FCpuInfo::FCpuInfo()
: numLogical (0)
, numAvailable (0)
{
	initialize ();
}

//------------------------------------------------------------------------
FCpuInfo::~FCpuInfo()
{
}

//------------------------------------------------------------------------
void FCpuInfo::initialize ()
{
#if WINDOWS
	SYSTEM_INFO sinfo;
	GetSystemInfo (&sinfo);
	numLogical = sinfo.dwNumberOfProcessors;

	DWORD_PTR processAffinityMask = 0;
	DWORD_PTR systemAffinityMask = 0;
	if (GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask))
	{
		while (processAffinityMask != 0)
		{
			if (processAffinityMask & (DWORD_PTR) 1)
				numAvailable++;
			processAffinityMask >>= 1;
		}
	}

#elif MAC
	size_t len = sizeof (int);
	int value = 0;
	sysctlbyname ("hw.ncpu", &value, &len, NULL, 0);
	numLogical = value;
	sysctlbyname ("hw.availcpu", &value, &len, NULL, 0);
	numAvailable = value;
#endif
}

//------------------------------------------------------------------------
bool FCpuInfo::isLogicalAvailable (int32 index)
{
#if WINDOWS
	if (index >= numLogical)
		return false;

	DWORD_PTR processAffinityMask = 0;
	DWORD_PTR systemAffinityMask = 0;
	if (GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask))
		return (processAffinityMask & ((DWORD_PTR) 1 << index)) > 0;

	return false;
#elif MAC
	return (index < numAvailable);
#endif
}

} // namespace
