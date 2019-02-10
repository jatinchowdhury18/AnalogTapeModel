//------------------------------------------------------------------------
// Project     : SDK Base
// Version     : 1.0
// 
// Category    : Helpers
// Filename    : base/source/funknownfactory.h
// Created by  : Steinberg, 11/2014
// Description : Creates FUnknown objects.
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

//------------------------------------------------------------------------
#include "base/source/classfactory.h"
#include "pluginterfaces/host/ihostclasses.h"

//------------------------------------------------------------------------
namespace Steinberg {

//------------------------------------------------------------------------
/** FUnknown factory singleton											*/
//------------------------------------------------------------------------
class FUnknownFactory
{
public:
//------------------------------------------------------------------------
	static FUnknownFactory& get ()
	{
		static FUnknownFactory instance;
		return instance;
	}

	IHostClasses* getHostClasses () const { return hostClasses; }
	void setHostClasses (IHostClasses* classes) { hostClasses = classes; }

	template <class Interface>
	inline Interface* createFUnknownClass ()
	{
		return reinterpret_cast<Interface*> (createClass (Interface::iid));
	}

	void* createClass (FIDString iid)
	{
		if (hostClasses)
		{
			void* obj = 0;
			if (hostClasses->createClassInstance (iid, &obj) == kResultTrue)
				return obj;
		}

		return ClassFactory::instance ()->createObjectByID (iid);
	}

	void updateHostClasses (FUnknown* context)
	{
		if (!hostClasses && context)
			if (FUnknownPtr<IHostClasses> hc = context)
				hostClasses = hc;
	}

//------------------------------------------------------------------------
private:
	FUnknownFactory () : hostClasses (0) {}
	FUnknownFactory (const FUnknownFactory&);
	FUnknownFactory& operator= (const FUnknownFactory&);

	IHostClasses* hostClasses;
};

//------------------------------------------------------------------------
template <typename T>
IPtr<T> newFUnknown ()
{
	return owned (FUnknownFactory::get ().createFUnknownClass<T> ());
}

//------------------------------------------------------------------------
} // Steinberg
