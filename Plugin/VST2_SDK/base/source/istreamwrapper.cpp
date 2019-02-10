//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
//
// Category    : Helpers
// Filename    : base/source/istreamwrapper.cpp
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

#include "base/source/istreamwrapper.h"

#include "pluginterfaces/base/ibstream.h"

#if WINDOWS

//------------------------------------------------------------------------
//  IStreamWrapper implementation
//------------------------------------------------------------------------
IStreamWrapper::IStreamWrapper (Steinberg::IBStream* stream)
: refCount (1)
, stream (stream)
{
	if (stream)
		stream->addRef ();
}

//------------------------------------------------------------------------
IStreamWrapper::~IStreamWrapper ()
{
	if (stream)
		stream->release ();
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::QueryInterface(REFIID riid, void** ppv)
{
	if (IsEqualIID (riid, IID_IUnknown) ||
		IsEqualIID (riid, IID_ISequentialStream) ||
		IsEqualIID (riid, IID_IStream))
	{ 
		*ppv = this; 
		AddRef ();
		return S_OK; 
	}
	*ppv = 0;
	return E_NOINTERFACE;
}

//------------------------------------------------------------------------
STDMETHODIMP_ (ULONG) IStreamWrapper::AddRef ()
{ 
	return ++refCount; 
}

//------------------------------------------------------------------------
STDMETHODIMP_ (ULONG) IStreamWrapper::Release () 
{ 
	if (--refCount == 0)
	{ 
		delete this;
		return 0;
	}
	return refCount; 
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::Read (void *pv, ULONG cb, ULONG *pcbRead)
{
	Steinberg::int32 numBytesRead = 0;
	if (stream->read (pv, cb, &numBytesRead) != Steinberg::kResultTrue)
		return S_FALSE;
	if (pcbRead)
		*pcbRead = numBytesRead;
	return S_OK;
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::Write (const void *pv, ULONG cb, ULONG *pcbWritten)
{
	Steinberg::int32 numBytesWritten = 0;

	if (stream->write ((void*)pv, cb, &numBytesWritten) != Steinberg::kResultTrue)
		return S_FALSE;

	if (pcbWritten)
		*pcbWritten = numBytesWritten;
	return S_OK;
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::Seek (LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition)
{
	// STREAM_SEEK enum is equal to our FSeekMode
	Steinberg::int64 seekRes = 0;
	
	if (stream->seek (dlibMove.QuadPart, (Steinberg::IBStream::IStreamSeekMode)dwOrigin, &seekRes) != Steinberg::kResultTrue)
		return S_FALSE;
	
	if (plibNewPosition)
		plibNewPosition->QuadPart = (ULONGLONG)seekRes;

	return S_OK;
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::Stat (STATSTG *pstatstg, DWORD grfStatFlag)
{
	if (pstatstg)
	{
		memset (pstatstg, 0, sizeof (STATSTG));
		pstatstg->type = STGTY_STREAM;

		Steinberg::FUnknownPtr<Steinberg::ISizeableStream> sizeable (stream);
		if (sizeable)
		{
			Steinberg::int64 size = 0;
			if (sizeable->getStreamSize (size) == Steinberg::kResultTrue)
			{
				pstatstg->cbSize.QuadPart = size;
				return S_OK;
			}
		}

		// alternative 
		Steinberg::int64 oldPos;
		Steinberg::int64 endPos;
		if (stream->tell (&oldPos) == Steinberg::kResultTrue)
		{
			if (stream->seek (0, Steinberg::IBStream::kIBSeekEnd, &endPos) == Steinberg::kResultTrue)
				pstatstg->cbSize.QuadPart = endPos;
			
			stream->seek (oldPos, Steinberg::IBStream::kIBSeekSet);
		}
	}
	return S_OK;
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::SetSize (ULARGE_INTEGER libNewSize)
{
	Steinberg::FUnknownPtr<Steinberg::ISizeableStream> sizeable (stream);
	if (sizeable)
	{
		if (sizeable->setStreamSize (libNewSize.QuadPart) == Steinberg::kResultTrue)
			return S_OK;
		return S_FALSE;
	}
	
	return E_NOTIMPL;
}

//------------------------------------------------------------------------
STDMETHODIMP IStreamWrapper::CopyTo (IStream *pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten)
{
	return E_NOTIMPL;
}

#endif // WINDOWS
