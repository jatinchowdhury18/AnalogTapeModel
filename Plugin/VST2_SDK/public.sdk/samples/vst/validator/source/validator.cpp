//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Validator
// Filename    : validator.cpp
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
#include "validator.h"

#include "pluginterfaces/vst/ivstcomponent.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivsthostapplication.h"
#include "pluginterfaces/vst/ivsteditcontroller.h"
#include "pluginterfaces/vst/ivstunits.h"

#include "base/source/fstring.h"
#include "base/source/fcontainer.h"
#include "base/source/tarray.h"
#include "base/source/tdictionary.h"
#include "base/source/fcommandline.h"

namespace Steinberg {
FUnknown* gStandardPluginContext = 0;
}

#if WINDOWS
#include <windows.h>
#include <conio.h>
extern "C"
{
	typedef bool (PLUGIN_API *InitModuleProc) ();
	typedef bool (PLUGIN_API *ExitModuleProc) ();
}
static const Steinberg::FIDString kInitModuleProcName = "InitDll";
static const Steinberg::FIDString kExitModuleProcName = "ExitDll";

#elif MAC
#include <CoreFoundation/CoreFoundation.h>
#include <curses.h>
typedef bool (*bundleEntryPtr)(CFBundleRef);
typedef bool (*bundleExitPtr)(void);

#endif

#include <cstdio>
#include <iostream>

namespace Steinberg {
namespace Vst {

//------------------------------------------------------------------------
// TestSuite
//------------------------------------------------------------------------
class TestSuite : public ITestSuite, public FObject
{
public:
	TestSuite (FIDString _name) : name (_name) {}
	
	tresult PLUGIN_API addTest (FIDString name, ITest* test)
	{
		return tests.add (IPtr<Test> (NEW Test (name, test), false)) ? kResultTrue : kResultFalse;
	}
	
	tresult PLUGIN_API addTestSuite (FIDString name, ITestSuite* testSuite)
	{
		return testSuites.addKeyAndObject (name, testSuite);
	}
	
	tresult PLUGIN_API setEnvironment (ITest* environment)
	{
		return kNotImplemented;
	}

	int32 getTestCount () const { return tests.total (); }

	tresult getTest (int32 index, ITest*& test, String& name) const
	{
		Test* _test = tests.at (index);
		if (_test)
		{
			test = _test->test;
			name = _test->name;
			return kResultTrue;
		}
		return kResultFalse;
	}
	
	tresult getTestSuite (int32 index, ITestSuite*& testSuite, String& name) const
	{
		const TAssociation<String, IPtr<ITestSuite> >& assoc = testSuites.at (index);
		if (assoc.object ())
		{
			testSuite = assoc.object ();
			name = assoc.key ();
			return kResultTrue;
		}
		return kResultFalse;
	}
	
	ITestSuite* getTestSuite (FIDString name) const
	{
		return testSuites.lookupObject (name);
	}
	
	const ConstString& getName () const { return name; }
	OBJ_METHODS(TestSuite, FObject)
	REFCOUNT_METHODS(FObject)
	DEF_INTERFACES_1(ITestSuite, FObject)
protected:
	class Test : public FObject
	{
	public:
		Test (FIDString _name, ITest* _test) : name (_name), test (_test) {}
		
		String name;
		IPtr<ITest> test;
	};
	String name;
	TArray<IPtr<Test> > tests;
	TDictionary<String, IPtr<ITestSuite> > testSuites;
};

//------------------------------------------------------------------------
static std::ostream* infoStream = &std::cout;
static std::ostream* errorStream = &std::cout;

//------------------------------------------------------------------------
// Validator
//------------------------------------------------------------------------
Validator::Validator (int argc, char* argv[])
: argc (argc)
, argv (argv)
, testSuite (0)
, numTestsFailed (0)
, numTestsPassed (0)
{ 
	testSuite = new TestSuite ("Tests");
	
	gStandardPluginContext = this->unknownCast ();
	setStandardPluginContext (gStandardPluginContext);
}

//------------------------------------------------------------------------
Validator::~Validator ()
{
	testSuite = 0;
	testModule = 0;
	module = 0;
}

//------------------------------------------------------------------------
void PLUGIN_API Validator::addErrorMessage (const tchar* msg)
{
	if (errorStream)
	{
		String msgStr (msg);
		msgStr.toMultiByte (kCP_Utf8);
		*errorStream << "ERROR: " << msgStr.text8 () << "\n";
	}
}

//------------------------------------------------------------------------
void PLUGIN_API Validator::addMessage (const tchar* msg)
{
	if (infoStream)
	{
		String msgStr (msg);
		msgStr.toMultiByte (kCP_Utf8);
		*infoStream << "Info:  " << msgStr.text8 () << "\n";
	}
}

//------------------------------------------------------------------------
tresult PLUGIN_API Validator::getName (String128 name)
{
	static String hostName ("vstvalidator");
	hostName.toWideString ();
	hostName.copyTo16 (name, 0, 128);
	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API Validator::createInstance (TUID cid, TUID iid, void** obj)
{
	FUID classID (cid);
	FUID interfaceID (iid);
	if (classID == IMessage::iid && interfaceID == IMessage::iid)
	{
		*obj = new HostMessage;
		return kResultTrue;
	}
	else if (classID == IAttributeList::iid && interfaceID == IAttributeList::iid)
	{
		*obj = new HostAttributeList;
		return kResultTrue;
	}
	*obj = 0;
	return kResultFalse;
}

//------------------------------------------------------------------------
#define kHelpOption	"help"
#define kVersionOption "version"
#define kLocalInstanceOption "l"
#define kSuiteNameOption "suite"
#define kQuietOption "q"
#define kTestComponentPath "test-component"

//------------------------------------------------------------------------
int Validator::run ()
{
	// defaults
	bool useGlobalInstance = true;
	String testSuiteName;

	// parse command line
	CommandLine::Descriptions desc;
	CommandLine::VariablesMap valueMap;
	CommandLine::FilesVector files;
	
	desc.addOptions (kVstVersionString " Plug-in Validator")
		(kHelpOption, CommandLine::Description::kBool, "Print help")
		(kVersionOption, CommandLine::Description::kBool, "Print version")
		(kLocalInstanceOption, CommandLine::Description::kBool, "Use local instance per test")
		(kSuiteNameOption, CommandLine::Description::kString, "[name] Only run a special test suite")
		(kQuietOption, CommandLine::Description::kBool, "Only print errors")
		(kTestComponentPath, CommandLine::Description::kString, "[path] Path to an additional component which includes custom tests")
	;
	CommandLine::parse (argc, argv, desc, valueMap, &files);
	if (valueMap.count (kVersionOption))
	{
		std::cout << VALIDATOR_INFO;
		return 0;
	}
	else if (valueMap.hasError () || valueMap.count (kHelpOption) || files.size () != 1)
	{
		std::cout << "\n" << desc << "\n";
		std::cout << "Usage: vstvalidator [options] vst3module\n\n";
		return 1;
	}
	
	if (valueMap.count (kLocalInstanceOption))
		useGlobalInstance = false;
	if (valueMap.count (kQuietOption))
		infoStream = 0;
	if (valueMap.count (kSuiteNameOption))
		testSuiteName = valueMap[kSuiteNameOption].c_str ();

	String customTestComponentPath;
	if (valueMap.count (kTestComponentPath))
		customTestComponentPath = valueMap[kTestComponentPath].c_str ();

	const char* path = files.front ().c_str ();

#if MAC
	String absPath;
	// if path is not absolute, create one
	if (path[0] != '/')
	{
		char* realPath = realpath (path, NULL);
		if (realPath)
		{
			absPath.assign (realPath);
			path = absPath.text8 ();
			free (realPath);
		}
	}
	if (customTestComponentPath.isEmpty () == false && customTestComponentPath[0] != '/')
	{
		char* realPath = realpath (customTestComponentPath.text8 (), NULL);
		if (realPath)
		{
			customTestComponentPath.assign (realPath);
			free (realPath);
		}
		
	}
#endif

	//---load VST module-----------------
	if (infoStream)
		*infoStream << "* Loading module...\n\n\t" << path << "\n\n";

	module = new VstModule (path);
	if (!module->isValid ())
	{
		*errorStream << "Invalid Module!\n";
		return 0;
	}

	IPluginFactory* factory = module->getFactory ();

	//---print classes-------------------
	if (infoStream)
	{
		*infoStream << "* Scanning classes...\n\n";

		PFactoryInfo factoryInfo ;
		factory->getFactoryInfo (&factoryInfo);
		*infoStream << "  Factory Info:\n\tvendor = " << factoryInfo.vendor << "\n\turl = " << factoryInfo.url << "\n\temail = " << factoryInfo.email << "\n\n";

		//---print all included Plug-ins---------------
		for (int32 i = 0; i < factory->countClasses (); i++)
		{
			PClassInfo classInfo;
			factory->getClassInfo (i, &classInfo);
			
			char8 cidString[50];
			FUID (classInfo.cid).toRegistryString (cidString);
			String cidStr (cidString);
			*infoStream << "  Class Info " << i << ":\n\tname = " << classInfo.name << "\n\tcategory = " << classInfo.category << "\n\tcid = " << cidStr.text8 () << "\n\n";
		}
	}

	TArray<IPtr<PlugProvider> > plugProviders;
	TDictionary<FIDString, IPtr<ITestFactory> > testFactories;
	//---create tests---------------
	if (infoStream)
		*infoStream << "* Creating tests...\n\n";
	for (int32 i = 0; i < factory->countClasses (); i++)
	{
		PClassInfo2 classInfo;
		IPluginFactory2* factory2;
		if (factory->queryInterface (IPluginFactory2::iid, (void**)&factory2) == kResultTrue)
		{
			factory2->getClassInfo2 (i, &classInfo);
			factory2->release ();
		}
		if (filterClassCategory (kVstAudioEffectClass, classInfo.category))
		{
			PlugProvider* plugProvider = new PlugProvider (factory, classInfo, useGlobalInstance);
			if (plugProvider)
			{
				createTests (plugProvider, classInfo.name);
				plugProviders.add (plugProvider);
				plugProvider->release ();
			}
		}
		else if (filterClassCategory (kTestClass, classInfo.category))
		{	// gather test factories supplied by the Plug-in
			ITestFactory* testFactory = 0;
			if (factory->createInstance (classInfo.cid, ITestFactory::iid, (void**)&testFactory) == kResultTrue)
			{
				testFactories.addKeyAndObject (classInfo.name, testFactory);
				testFactory->release ();
			}
		}
	}

	// now check testModule if supplied
	if (customTestComponentPath.isEmpty () == false)
	{
		testModule = new VstModule (customTestComponentPath);
		if (testModule->isValid ())
		{
			IPluginFactory* factory = testModule->getFactory ();
			if (factory)
			{
				for (int32 i = 0; i < factory->countClasses (); i++)
				{
					PClassInfo2 classInfo;
					IPluginFactory2* factory2;
					if (factory->queryInterface (IPluginFactory2::iid, (void**)&factory2) == kResultTrue)
					{
						factory2->getClassInfo2 (i, &classInfo);
						factory2->release ();
					}
					if (filterClassCategory (kTestClass, classInfo.category))
					{	// gather test factories supplied by the Plug-in
						ITestFactory* testFactory = 0;
						if (factory->createInstance (classInfo.cid, ITestFactory::iid, (void**)&testFactory) == kResultTrue)
						{
							testFactories.addKeyAndObject (classInfo.name, testFactory);
							testFactory->release ();
						}
					}
				}
			}
		}

	}
	if (infoStream && testFactories.total () > 0)
		*infoStream << "* Creating Plug-in supplied tests...\n\n";
	// create Plug-in supplied tests
	typedef TAssociation<FIDString, IPtr<ITestFactory> > bla;
	FOREACH_T(bla, assoc, testFactories)
		FOREACH_T(IPtr<PlugProvider>, context, plugProviders)
			OPtr<TestSuite> plugTestSuite = new TestSuite (assoc.key ());
			if (assoc.object ()->createTests (context->unknownCast (), plugTestSuite) == kResultTrue)
			{
				testSuite->addTestSuite (plugTestSuite->getName (), plugTestSuite);
			}
		ENDFOR
	ENDFOR
	testFactories.removeAll ();

	//---run tests---------------------------
	if (infoStream)
		*infoStream << "* Running tests...\n\n";

	runTestSuite (testSuite, testSuiteName.isEmpty () ? 0 : testSuiteName.text8 ());

	if (infoStream)
	{
		*infoStream << SEPARATOR;
		*infoStream << "Result: " << numTestsPassed << " tests passed, " << numTestsFailed << " tests failed\n";
		*infoStream << SEPARATOR;

	#if WINDOWS && _DEBUG
		*infoStream << "Press any key to continue...";
		getch ();
	#endif
	}
	return numTestsFailed == 0 ? 0 : -1;
}

//------------------------------------------------------------------------
bool Validator::filterClassCategory (FIDString category, FIDString classCategory) const
{
	return strcmp (category, classCategory) == 0;
}

//------------------------------------------------------------------------
void Validator::createTests (IPlugProvider* plugProvider, const ConstString& plugName)
{
	OPtr<TestSuite> plugTestSuite = new TestSuite (plugName);
	
	OPtr<TestSuite> generalTests = new TestSuite ("General Tests");
	// todo: add tests here!
	addTest (generalTests, new VstEditorClassesTest (plugProvider));
	addTest (generalTests, new VstScanBussesTest (plugProvider));
	addTest (generalTests, new VstScanParametersTest (plugProvider));
	addTest (generalTests, new VstMidiMappingTest (plugProvider));
	addTest (generalTests, new VstUnitInfoTest (plugProvider));
	addTest (generalTests, new VstProgramInfoTest (plugProvider));
	addTest (generalTests, new VstTerminateInitializeTest (plugProvider));
	addTest (generalTests, new VstUnitStructureTest (plugProvider));
	
	addTest (generalTests, new VstValidStateTransitionTest (plugProvider));
//	addTest (generalTests, new VstInvalidStateTransitionTest (plugProvider));
//	addTest (generalTests, new VstRepeatIdenticalStateTransitionTest (plugProvider));
	
	addTest (generalTests, new VstBusConsistencyTest (plugProvider));
//	addTest (generalTests, new VstBusInvalidIndexTest (plugProvider));
	addTest (generalTests, new VstBusActivationTest (plugProvider));
	
	addTest (generalTests, new VstCheckAudioBusArrangementTest (plugProvider));

	addTest (generalTests, new VstSuspendResumeTest (plugProvider, kSample32));

	addTest (generalTests, new VstNoteExpressionTest (plugProvider));
	addTest (generalTests, new VstKeyswitchTest (plugProvider));
	
	plugTestSuite->addTestSuite (generalTests->getName (), generalTests);

	OPtr<TestSuite> singlePrecisionTests = new TestSuite ("Single Precision (32 bit) Tests");
	
	addTest (singlePrecisionTests, new VstProcessTest (plugProvider, kSample32));
	addTest (singlePrecisionTests, new VstSilenceFlagsTest (plugProvider, kSample32));
	addTest (singlePrecisionTests, new VstSilenceProcessingTest (plugProvider, kSample32));
	addTest (singlePrecisionTests, new VstFlushParamTest (plugProvider, kSample32));
	addTest (singlePrecisionTests, new VstVariableBlockSizeTest (plugProvider, kSample32));
	addTest (singlePrecisionTests, new VstProcessFormatTest (plugProvider, kSample32));

	SpeakerArrangement inSpArr = SpeakerArr::kStereo;
	SpeakerArrangement outSpArr = SpeakerArr::kStereo;
	addTest (singlePrecisionTests, new VstSpeakerArrangementTest (plugProvider, kSample32, inSpArr, outSpArr));

	inSpArr = SpeakerArr::kMono;
	outSpArr = SpeakerArr::kMono;
	addTest (singlePrecisionTests, new VstSpeakerArrangementTest (plugProvider, kSample32, inSpArr, outSpArr));

	//int32 everyNSamples, int32 numParams, bool sampleAccuracy;
	addTest (singlePrecisionTests, new VstAutomationTest (plugProvider, kSample32, 100, 1, false));
	addTest (singlePrecisionTests, new VstAutomationTest (plugProvider, kSample32, 100, 1, true));

	plugTestSuite->addTestSuite (singlePrecisionTests->getName (), singlePrecisionTests);

	OPtr<TestSuite> doublePrecisionTests = new TestSuite ("Double Precision (64 bit) Tests");

	addTest (doublePrecisionTests, new VstProcessTest (plugProvider, kSample64));
	addTest (doublePrecisionTests, new VstSilenceFlagsTest (plugProvider, kSample64));
	addTest (doublePrecisionTests, new VstSilenceProcessingTest (plugProvider, kSample64));
	addTest (doublePrecisionTests, new VstFlushParamTest (plugProvider, kSample64));
	addTest (doublePrecisionTests, new VstVariableBlockSizeTest (plugProvider, kSample64));
	addTest (doublePrecisionTests, new VstProcessFormatTest (plugProvider, kSample64));

	inSpArr = SpeakerArr::kStereo;
	outSpArr = SpeakerArr::kStereo;
	addTest (doublePrecisionTests, new VstSpeakerArrangementTest (plugProvider, kSample64, inSpArr, outSpArr));

	inSpArr = SpeakerArr::kMono;
	outSpArr = SpeakerArr::kMono;
	addTest (doublePrecisionTests, new VstSpeakerArrangementTest (plugProvider, kSample64, inSpArr, outSpArr));

	//int32 everyNSamples, int32 numParams, bool sampleAccuracy;
	addTest (doublePrecisionTests, new VstAutomationTest (plugProvider, kSample64, 100, 1, false));
	addTest (doublePrecisionTests, new VstAutomationTest (plugProvider, kSample64, 100, 1, true));

	plugTestSuite->addTestSuite (doublePrecisionTests->getName (), doublePrecisionTests);

	testSuite->addTestSuite (plugName, plugTestSuite);
}

//------------------------------------------------------------------------
void Validator::addTest (ITestSuite* testSuite, VstTestBase* testItem)
{
	testSuite->addTest (String (testItem->getName ()).text8 (), testItem);
	testItem->release ();
}

//------------------------------------------------------------------------
void Validator::runTestSuite (TestSuite* suite, FIDString nameFilter)
{
	String name;
	if (nameFilter == 0 || suite->getName () == nameFilter)
	{
		nameFilter = 0; // make sure if suiteName is the namefilter that sub suite will run
		ITest* testItem = 0;
		// first run all tests in the suite
		for (int32 i = 0; i < suite->getTestCount (); i++)
		{
			if (suite->getTest (i, testItem, name) == kResultTrue)
			{
				if (infoStream)
					*infoStream << "[" << name.text8 () << "]\n";

				if (testItem->setup ())
				{
					bool success = testItem->run (this);
					if (success)
					{
						if (infoStream)
							*infoStream << "[Succeeded]\n";
						numTestsPassed++;
					}
					else
					{
						if (infoStream)
							*infoStream << "[XXXXXXX Failed]\n";
						if (errorStream && errorStream != infoStream)
						{
							*errorStream << "Test [" << name.text8 () << "] ";
							*errorStream << "Failed\n";
						}
						numTestsFailed++;
					}

					if (!testItem->teardown ())
					{
						if (infoStream)
							*infoStream << "Failed to teardown test!\n";
						if (errorStream && errorStream != infoStream)
						{
							*errorStream << "[" << name.text8 () << "] ";
							*errorStream << "Failed to teardown test!\n";
						}
					}
				}
				else
				{
					testItem->teardown();
					if (infoStream)
						*infoStream << "Failed to setup test!\n";
					if (errorStream && errorStream != infoStream)
					{
						*errorStream << "[" << name.text8 () << "] ";
						*errorStream << "Failed to setup test!\n";
					}
				}
				if (infoStream)
					*infoStream << "\n";
			}
		}
	}
	// next run sub suites
	int32 subTestSuiteIndex = 0;
	ITestSuite* subSuite = 0;
	while (suite->getTestSuite (subTestSuiteIndex++, subSuite, name) == kResultTrue)
	{
		TestSuite* ts = FCast<TestSuite> (subSuite);
		if (ts)
		{
			if (infoStream)
			{
				*infoStream << SEPARATOR;
				*infoStream << "TestSuite : " << ts->getName ().text8 () << "\n";
				*infoStream << SEPARATOR << "\n";
			}
			runTestSuite (ts, nameFilter);
		}
	}
}

//------------------------------------------------------------------------
// VstModule
//------------------------------------------------------------------------
VstModule::VstModule (const char* path)
: libHandle (0)
, factory (0)
{
	GetFactoryProc entryProc = 0;

	// load library
#if WINDOWS
	libHandle = ::LoadLibraryA (path);
	if (libHandle)
	{
		InitModuleProc initProc = (InitModuleProc)::GetProcAddress ((HMODULE)libHandle, kInitModuleProcName);
		if (initProc)
		{
			if (initProc () == false)
			{
				FreeLibrary ((HMODULE)libHandle);
				libHandle = 0;	
			}
		}
	}
	if (libHandle)		
		entryProc = (GetFactoryProc)::GetProcAddress ((HMODULE)libHandle, "GetPluginFactory");

#elif MAC
	CFURLRef url = path ? CFURLCreateFromFileSystemRepresentation (0, (const UInt8*)path, strlen (path), true) : 0;
	if (url)
	{
		libHandle = (void*)CFBundleCreate (0, url);
		if (libHandle)
		{
			CFErrorRef errorRef = 0;
			if (CFBundleLoadExecutableAndReturnError ((CFBundleRef)libHandle, &errorRef))
			{
				bundleEntryPtr bundleEntry = (bundleEntryPtr)CFBundleGetFunctionPointerForName ((CFBundleRef)libHandle, CFSTR("bundleEntry"));
				if (bundleEntry)
				{
					if (bundleEntry ((CFBundleRef)libHandle) == false)
					{
						CFRelease ((CFBundleRef)libHandle);
						libHandle = 0;
					}
				}
				if (libHandle)
					entryProc = (GetFactoryProc)CFBundleGetFunctionPointerForName ((CFBundleRef)libHandle, CFSTR("GetPluginFactory"));
			}
			else if (errorRef)
			{
				CFStringRef failureString = CFErrorCopyFailureReason (errorRef);
				if (failureString)
				{
					CFShow (failureString);
					CFRelease (failureString);
				}
				CFRelease (errorRef);
			}
		}
		CFRelease (url);
	}
#endif

	// create factory
	if (entryProc)
		factory = entryProc ();
}

//------------------------------------------------------------------------
VstModule::~VstModule ()
{
	// release factory
	if (factory)
		factory->release ();

	// free library
	if (libHandle)
	{
	#if WINDOWS
		ExitModuleProc exitProc = (ExitModuleProc)::GetProcAddress ((HMODULE)libHandle, kExitModuleProcName);
		if (exitProc)
			exitProc ();

		::FreeLibrary ((HMODULE)libHandle);
	
	#elif MAC
		bundleExitPtr bundleExit = (bundleExitPtr)CFBundleGetFunctionPointerForName ((CFBundleRef)libHandle, CFSTR("bundleExit"));
		if (bundleExit)
			bundleExit ();
		CFRelease ((CFBundleRef)libHandle);
	#endif
	}
}

//------------------------------------------------------------------------
bool VstModule::isValid () const
{
	return libHandle != 0 && factory != 0;
}


//------------------------------------------------------------------------
// PlugProvider
//------------------------------------------------------------------------
PlugProvider::PlugProvider (IPluginFactory* factory, PClassInfo2 classInfo, bool plugIsGlobal)
: factory (factory)
, classInfo (classInfo)
, plugIsGlobal (plugIsGlobal)
, component (0)
, controller (0)
{
	if (plugIsGlobal)
	{
		setupPlugin ();
	}
}

//------------------------------------------------------------------------
PlugProvider::~PlugProvider ()
{
	terminatePlugin ();
}

//------------------------------------------------------------------------
IComponent* PlugProvider::getComponent ()
{
	if (!plugIsGlobal)
		setupPlugin ();

	if (component)
		component->addRef ();

	return component; 
}

//------------------------------------------------------------------------
IEditController* PlugProvider::getController ()
{
	if (controller)
		controller->addRef ();

	// 'iController == 0' is allowed! In this case the plug has no controller
	return controller;
}

//------------------------------------------------------------------------
tresult PlugProvider::getPluginUID (FUID& uid) const
{
	uid = classInfo.cid;
	return kResultOk;
}

//------------------------------------------------------------------------
tresult PlugProvider::releasePlugIn (IComponent* iComponent, IEditController* iController)
{
	if (iComponent)
		iComponent->release ();

	if (iController)
		iController->release ();

	if (!plugIsGlobal)
	{
		terminatePlugin ();
	}

	return kResultOk;
}

//------------------------------------------------------------------------
bool PlugProvider::setupPlugin ()
{
	bool res = false;
	
	//---create Plug-in here!--------------
	// create its component part
	tresult result = factory->createInstance (classInfo.cid, IComponent::iid, (void**)&component);
	if (component && (result == kResultOk))
	{
		// initialize the component with our context
		res = (component->initialize (gStandardPluginContext) == kResultOk);

		// try to create the controller part from the component 
		// (for Plug-ins which did not succeed to separate component from controller) 
		if (component->queryInterface (IEditController::iid, (void**)&controller) != kResultTrue)
		{
			FUID controllerCID;

			// ask for the associated controller class ID
			if (component->getControllerClassId (controllerCID) == kResultTrue && controllerCID.isValid ())
			{		
				// create its controller part created from the factory
				result = factory->createInstance (controllerCID, IEditController::iid, (void**)&controller);
				if (controller && (result == kResultOk))
				{
					// initialize the component with our context
					res = (controller->initialize (gStandardPluginContext) == kResultOk);
				}
			}
		}
	}
	else if (errorStream)
	{
		*errorStream << "Failed to create instance of " << classInfo.name << "!\n";
	}

	return res;
}

//------------------------------------------------------------------------
void PlugProvider::terminatePlugin ()
{
	bool controllerIsComponent = false;		
	if (component)
	{
		controllerIsComponent = FUnknownPtr<IEditController> (component).getInterface () != 0;
		component->terminate ();	
	}

	if (controller && controllerIsComponent == false)
		controller->terminate ();

	if (component)
	{
		component->release ();
		component = 0;
	}

	if (controller)
	{
		controller->release ();
		controller = 0;
	}
}

}} // namespaces
