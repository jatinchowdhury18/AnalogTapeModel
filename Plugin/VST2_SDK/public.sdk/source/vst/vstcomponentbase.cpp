//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/vstcomponentbase.cpp
// Created by  : Steinberg, 05/2005
// Description : Base class for VST Component and Edit Controller
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

#include "vstcomponentbase.h"
#include "base/source/fstring.h"

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// ComponentBase Implementation
//------------------------------------------------------------------------
ComponentBase::ComponentBase ()
: hostContext (0)
, peerConnection (0)
{}

//------------------------------------------------------------------------
ComponentBase::~ComponentBase ()
{}

//------------------------------------------------------------------------
tresult PLUGIN_API ComponentBase::initialize (FUnknown* context)
{
	// check if already initialized
	if (hostContext)
		return kResultFalse;

	hostContext = context;
	if (hostContext)
		hostContext->addRef ();

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ComponentBase::terminate ()
{
	// release host interfaces
	if (hostContext)
	{
		hostContext->release ();
		hostContext = 0;
	}

	// in case host did not disconnect us,
	// release peer now
	if (peerConnection)
	{
		peerConnection->disconnect (this);
		peerConnection->release ();
		peerConnection = 0;
	}

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ComponentBase::connect (IConnectionPoint* other)
{
	if (!other)
		return kInvalidArgument;

	// check if already connected
	if (peerConnection)
		return kResultFalse;

	peerConnection = other;
	peerConnection->addRef ();
	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ComponentBase::disconnect (IConnectionPoint* other)
{
	if (peerConnection && other == peerConnection)
	{
		peerConnection->release (),
		peerConnection = 0;
		return kResultOk;
	}
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult PLUGIN_API ComponentBase::notify (IMessage* message)
{
	if (!message)
		return kInvalidArgument;

	if (!strcmp (message->getMessageID (), "TextMessage"))
	{
		TChar string[256] = {0};
		if (message->getAttributes ()->getString ("Text", string, sizeof (string) / sizeof (char16)) == kResultOk)
		{
			char8 cstr[256];
			String tmp (string);
			tmp.toMultiByte (kCP_US_ASCII);
			tmp.copyTo8 (cstr, 0, 255);
			return receiveText (cstr);
		}
	}

	return kResultFalse;
}

//------------------------------------------------------------------------
IMessage* ComponentBase::allocateMessage ()
{
	FUnknownPtr<IHostApplication> hostApp (hostContext);
	if (hostApp)
		return Vst::allocateMessage (hostApp);
	return 0;
}

//------------------------------------------------------------------------
tresult ComponentBase::sendMessage (IMessage* message)
{
	if (message != 0 && getPeer () != 0)
		return getPeer ()->notify (message);
	return kResultFalse;
}

//------------------------------------------------------------------------
tresult ComponentBase::sendTextMessage (const char8* text)
{
	IMessage* message = allocateMessage ();
	if (!message)
		return kResultFalse;

	FReleaser msgReleaser (message);
	message->setMessageID ("TextMessage");
	message->getAttributes ()->setString ("Text", String (text, kCP_US_ASCII));
	return sendMessage (message);
}

//------------------------------------------------------------------------
tresult ComponentBase::receiveText (const char8* /*text*/)
{
	return kResultOk;
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
