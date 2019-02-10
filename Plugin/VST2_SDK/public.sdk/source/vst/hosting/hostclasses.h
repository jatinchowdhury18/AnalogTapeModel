//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Helpers
// Filename    : public.sdk/source/vst/hosting/hostclasses.h
// Created by  : Steinberg, 03/05/2008.
// Description : VST 3 hostclasses, example implementations for IHostApplication, IAttributeList and IMessage
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

#pragma once

#include "pluginterfaces/vst/ivsthostapplication.h"

#include "base/source/fstring.h"

#include <map>

namespace Steinberg {
namespace Vst {

//----------------------------------------------------------------------------------------------
class HostApplication : public IHostApplication
{
public:
	HostApplication () { FUNKNOWN_CTOR }
	virtual ~HostApplication () { FUNKNOWN_DTOR }

	tresult PLUGIN_API getName (String128 name);
	tresult PLUGIN_API createInstance (TUID cid, TUID _iid, void** obj);

	DECLARE_FUNKNOWN_METHODS
};

class HostAttribute;
//--------------------------------------------------------------------------------------------------------------
class HostAttributeList : public IAttributeList
{
public:
	HostAttributeList ();
	virtual ~HostAttributeList ();

	tresult PLUGIN_API setInt (AttrID aid, int64 value);
	tresult PLUGIN_API getInt (AttrID aid, int64& value);
	tresult PLUGIN_API setFloat (AttrID aid, double value);
	tresult PLUGIN_API getFloat (AttrID aid, double& value);
	tresult PLUGIN_API setString (AttrID aid, const TChar* string);
	tresult PLUGIN_API getString (AttrID aid, TChar* string, uint32 size);
	tresult PLUGIN_API setBinary (AttrID aid, const void* data, uint32 size);
	tresult PLUGIN_API getBinary (AttrID aid, const void*& data, uint32& size);

	DECLARE_FUNKNOWN_METHODS
protected:
	void removeAttrID (AttrID aid);
	std::map<String, HostAttribute*> list;
};

//--------------------------------------------------------------------------------------------------------------
class HostMessage : public IMessage
{
public:
	HostMessage ();
	virtual ~HostMessage ();

	const char* PLUGIN_API getMessageID ();
	void PLUGIN_API setMessageID (const char* messageID);
	IAttributeList* PLUGIN_API getAttributes ();

	DECLARE_FUNKNOWN_METHODS
protected:
	char* messageId;
	HostAttributeList* attributeList;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
