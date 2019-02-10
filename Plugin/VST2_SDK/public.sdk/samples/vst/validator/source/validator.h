//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Validator
// Filename    : validator.h
// Created by  : Steinberg, 04/2005
// Description : VST 3 Plug-in Validator class
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

#include "pluginterfaces/base/ipluginbase.h"
#include "pluginterfaces/test/itest.h"
#include "base/source/tlist.h"
#include "base/source/fstring.h"
#include "public.sdk/source/vst/testsuite/vsttestsuite.h"
#include "public.sdk/source/vst/hosting/hostclasses.h"

namespace Steinberg {
namespace Vst {

class IComponent;
class IEditController;

class VstModule;
class VstTestBase;
class TestSuite;

//------------------------------------------------------------------------
// Some Definitions
//------------------------------------------------------------------------
#define SEPARATOR \
	"-------------------------------------------------------------\n"

#define VALIDATOR_INFO \
	SEPARATOR \
	kVstVersionString " Plug-in Validator\n" \
	"Program by Steinberg (Built on " __DATE__ ")\n" \
	SEPARATOR "\n"

#define VALIDATOR_USAGE \
	"Usage: vstvalidator [options] <component path> \n" \
	"  where options are -l (use a local instance for each test instead of a global one)\n"


//------------------------------------------------------------------------
/** Helper for creating and initializing component.
\ingroup Validator */
//------------------------------------------------------------------------
class PlugProvider : public FObject, public IPlugProvider
{
public:
//------------------------------------------------------------------------
	PlugProvider (IPluginFactory* factory, PClassInfo2 info, bool plugIsGlobal = true);
	~PlugProvider ();

	// IPlugProvider
	IComponent* getComponent ();
	IEditController* getController ();
	tresult releasePlugIn (IComponent* component, IEditController* controller);
	const char8* getSubCategories () const { return classInfo.subCategories; }
	
	tresult getPluginUID (FUID& uid) const;

	bool setupPlugin ();

//------------------------------------------------------------------------
	OBJ_METHODS(PlugProvider, FObject)
	REFCOUNT_METHODS(FObject)
	DEF_INTERFACES_1(IPlugProvider, FObject)
//------------------------------------------------------------------------
protected:
	void terminatePlugin ();

	IComponent* component;
	IEditController* controller;
	IPluginFactory* factory;
	PClassInfo2 classInfo;
	bool plugIsGlobal;
};

//------------------------------------------------------------------------
/** Main Class of Validator.
\ingroup Validator */
//------------------------------------------------------------------------
class Validator : public FObject, public ITestResult, public IHostApplication
{
public:
//------------------------------------------------------------------------
	Validator (int argc, char* argv[]);
	~Validator ();

	int run ();

//------------------------------------------------------------------------
	OBJ_METHODS(Validator, FObject)
	REFCOUNT_METHODS(FObject)
	DEFINE_INTERFACES
		DEF_INTERFACE(ITestResult)
		DEF_INTERFACE(IHostApplication)
	END_DEFINE_INTERFACES(FObject)
//------------------------------------------------------------------------
protected:
	// ITestResult
	void PLUGIN_API addErrorMessage (const tchar* msg);
	void PLUGIN_API addMessage (const tchar* msg);

	// IHostApplication
	tresult PLUGIN_API getName (String128 name);
	tresult PLUGIN_API createInstance (TUID cid, TUID iid, void** obj);
	
	bool filterClassCategory (FIDString category, FIDString classCategory) const;
	void createTests (IPlugProvider* plugProvider, const ConstString& plugName);
	void addTest (ITestSuite* testSuite, VstTestBase* test);
	void runTestSuite (TestSuite* suite, FIDString nameFilter = 0);

	int argc;
	char** argv;
	OPtr<VstModule> module;
	OPtr<VstModule> testModule;
	OPtr<TestSuite> testSuite;
	int32 numTestsFailed;
	int32 numTestsPassed;
};

//------------------------------------------------------------------------
/** This handles the Plug-in factory in its library.
\ingroup Validator */
//------------------------------------------------------------------------
class VstModule : public FObject
{
public:
//------------------------------------------------------------------------
	VstModule (const char* path);
	~VstModule ();

	bool isValid () const;
	IPluginFactory* getFactory () { return factory; }

//------------------------------------------------------------------------
	OBJ_METHODS(VstModule, FObject)
//------------------------------------------------------------------------
protected:
	void* libHandle;
	IPluginFactory* factory;
};

}} // namespaces
