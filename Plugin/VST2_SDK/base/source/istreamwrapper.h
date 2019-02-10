//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/istreamwrapper.h
// Created by  : Steinberg, 2010
// Description : Translate Steinberg::IBStream to COM IStream
//
//-------------------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
//-------------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------------

#ifndef __istreamwrapper__
#define __istreamwrapper__

#include "pluginterfaces/base/ibstream.h"

#if WINDOWS

#include <oleidl.h>

//------------------------------------------------------------------------
//  IStreamWrapper
//------------------------------------------------------------------------
class IStreamWrapper: public IStream
{
public:
//------------------------------------------------------------------------
	IStreamWrapper (Steinberg::IBStream* stream);
	virtual ~IStreamWrapper ();

    // IUnknown
	STDMETHODIMP QueryInterface (REFIID riid, void** ppv);
	STDMETHODIMP_ (ULONG) AddRef ();
	STDMETHODIMP_ (ULONG) Release (); 

	// ISequentialStream
	STDMETHODIMP Read (void *pv, ULONG cb, ULONG *pcbRead);
	STDMETHODIMP Write (const void *pv, ULONG cb, ULONG *pcbWritten);

	// IStream
	STDMETHODIMP Seek (LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition);
	STDMETHODIMP SetSize (ULARGE_INTEGER libNewSize);
	STDMETHODIMP CopyTo (IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten);  
	STDMETHODIMP Commit (DWORD grfCommitFlags) { return S_OK; }
	STDMETHODIMP Revert () { return S_OK; }
	STDMETHODIMP LockRegion (ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) { return S_OK; }
	STDMETHODIMP UnlockRegion (ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) { return S_OK; }
	STDMETHODIMP Stat (STATSTG *pstatstg, DWORD grfStatFlag);
	STDMETHODIMP Clone (IStream **ppstm) { return STG_E_INSUFFICIENTMEMORY; }
//------------------------------------------------------------------------
protected:
	Steinberg::uint32 refCount;
	Steinberg::IBStream* stream;
};

#endif // WINDOWS

#endif
