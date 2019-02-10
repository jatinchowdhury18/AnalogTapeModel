//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.0
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/adelay/source/exampletest.cpp
// Created by  : Steinberg, 10/2010
// Description : 
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2014, Steinberg Media Technologies GmbH, All Rights Reserved
//-----------------------------------------------------------------------------
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// 
//   * Redistributions of source code must retain the above copyright notice, 
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation 
//     and/or other materials provided with the distribution.
//   * Neither the name of the Steinberg Media Technologies nor the names of its
//     contributors may be used to endorse or promote products derived from this 
//     software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE 
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------

#include "exampletest.h"
#include "adelaycontroller.h"
#include "adelayprocessor.h"
#include "base/source/fstring.h"
#include "public.sdk/source/vst/testsuite/vsttestsuite.h"

namespace Steinberg {

DEF_CLASS_IID(ITest)
DEF_CLASS_IID(ITestSuite)
DEF_CLASS_IID(ITestFactory)

namespace Vst {
DEF_CLASS_IID(IPlugProvider)

//-----------------------------------------------------------------------------
FUID ADelayTestFactory::cid (0x60277237, 0x74CC4303, 0xB6737CA6, 0xEDD0F811);

//-----------------------------------------------------------------------------
tresult PLUGIN_API ADelayTestFactory::createTests (FUnknown* context, ITestSuite* parentSuite)
{
	FUnknownPtr<IPlugProvider> plugProvider (context);
	if (plugProvider)
	{
		parentSuite->addTest ("ExampleTest", new ADelayTest (plugProvider));
	}
	return kResultTrue;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
ADelayTest::ADelayTest (IPlugProvider* plugProvider)
: plugProvider (plugProvider)
{
}

//-----------------------------------------------------------------------------
bool PLUGIN_API ADelayTest::setup ()
{
	return true;
}

//-----------------------------------------------------------------------------
bool PLUGIN_API ADelayTest::run (ITestResult* testResult)
{
	ADelayController* controller = FCast<ADelayController> (plugProvider->getController ());
	ADelayProcessor* processor = FCast<ADelayProcessor> (plugProvider->getComponent ());
	if (controller)
		testResult->addMessage (String ("Correct IEditController"));
	else
		testResult->addErrorMessage (String ("Unknown IEditController"));
	if (processor)
		testResult->addMessage (String ("Correct IComponent"));
	else
		testResult->addErrorMessage (String ("Unknown IComponent"));
	return (controller && processor);
}

//-----------------------------------------------------------------------------
bool PLUGIN_API ADelayTest::teardown ()
{
	return true;
}

//-----------------------------------------------------------------------------
const tchar* PLUGIN_API ADelayTest::getDescription ()
{
	static String description ("Example Test");
#ifdef UNICODE
	return description.text16 ();
#else
	return description.text8 ();
#endif
}

}} // namespaces
