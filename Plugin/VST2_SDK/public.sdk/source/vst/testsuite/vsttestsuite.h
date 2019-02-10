//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Validator
// Filename    : public.sdk/source/vst/vsttestsuite.h
// Created by  : Steinberg, 04/2005
// Description : VST Test Suite
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

#include "pluginterfaces/test/itest.h"
#include "public.sdk/source/vst/hosting/processdata.h"

// VST 3 interfaces
#include "pluginterfaces/base/ipluginbase.h"
#include "pluginterfaces/vst/ivstcomponent.h"
#include "pluginterfaces/vst/ivstaudioprocessor.h"
#include "pluginterfaces/vst/ivsteditcontroller.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"

namespace Steinberg {
namespace Vst {

typedef int32 ProcessSampleSize;

//------------------------------------------------------------------------
#define DECLARE_VSTTEST(name) \
virtual const tchar* getName () const { return name; }

/** Set from outside the plug-in context (simulating a host context) */
extern void setStandardPluginContext (FUnknown* context);

//------------------------------------------------------------------------
/** Test Helper.
\ingroup TestClass */
//------------------------------------------------------------------------
class IPlugProvider : public FUnknown
{
public:
//------------------------------------------------------------------------
	virtual IComponent* getComponent () = 0;
	virtual IEditController* getController () = 0;
	virtual tresult releasePlugIn (IComponent* component, IEditController* controller) = 0;
	virtual const char8* getSubCategories () const = 0;
	virtual tresult getPluginUID (FUID& uid) const = 0;

//------------------------------------------------------------------------
	static const FUID iid;
};

DECLARE_CLASS_IID (IPlugProvider, 0xDB014121, 0x09144BAA, 0x87627896, 0xBE41AF5D)

//------------------------------------------------------------------------
// VstAutomationTest helper classes
//------------------------------------------------------------------------
class ParamPoint
{
public:
	ParamPoint () : offsetSamples (-1), value (0.), read (false) {}
	void set (int32 offsetSamples, double value)
	{
		this->offsetSamples = offsetSamples;
		this->value = value;
	}
	void get (int32& offsetSamples, double& value)
	{
		offsetSamples = this->offsetSamples;
		value = this->value;
		read = true;
	}
	bool wasRead () const { return read; }

private:
	int32 offsetSamples;
	double value;
	bool read;
};

//------------------------------------------------------------------------
class ParamChanges : public IParamValueQueue
{
public:
	ParamChanges () : id (-1), numPoints (0), points (0), numUsedPoints (0), processedFrames (0)
	{
		FUNKNOWN_CTOR
	}
	~ParamChanges ()
	{
		if (points)
			delete[] points;
		FUNKNOWN_DTOR
	}

	DECLARE_FUNKNOWN_METHODS

	void init (ParamID id, int32 numPoints)
	{
		this->id = id;
		this->numPoints = numPoints;
		numUsedPoints = 0;
		if (points)
			delete[] points;
		points = new ParamPoint[numPoints];
		processedFrames = 0;
	}
	bool setPoint (int32 index, int32 offsetSamples, double value)
	{
		if (points && (index >= 0) && (index == numUsedPoints) && (index < numPoints))
		{
			points[index].set (offsetSamples, value);
			numUsedPoints++;
			return true;
		}
		if (!points)
			return true;
		return false;
	}
	void resetPoints ()
	{
		numUsedPoints = 0;
		processedFrames = 0;
	}
	int32 getProcessedFrames () const { return processedFrames; }
	void setProcessedFrames (int32 amount) { processedFrames = amount; }
	bool havePointsBeenRead (bool atAll)
	{
		for (int32 i = 0; i < getPointCount (); ++i)
		{
			if (points[i].wasRead ())
			{
				if (atAll)
					return true;
			}
			else if (!atAll)
				return false;
		}
		return !atAll;
	}

	//---for IParamValueQueue-------------------------
	ParamID PLUGIN_API getParameterId () { return id; }
	int32 PLUGIN_API getPointCount () { return numUsedPoints; }
	tresult PLUGIN_API getPoint (int32 index, int32& offsetSamples, double& value)
	{
		if (points && (index < numUsedPoints) && (index >= 0))
		{
			points[index].get (offsetSamples, value);
			return kResultTrue;
		}
		return kResultFalse;
	}
	tresult PLUGIN_API addPoint (int32 offsetSamples, double value, int32& index)
	{
		return kResultFalse;
	}
//---------------------------------------------------------

private:
	ParamID id;
	int32 numPoints;
	int32 numUsedPoints;
	ParamPoint* points;
	int32 processedFrames;
};

//------------------------------------------------------------------------
/** Test Helper.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstTestBase: public ITest
{
public:
//------------------------------------------------------------------------
	VstTestBase (IPlugProvider* plugProvider);
	virtual ~VstTestBase ();
	
	DECLARE_VSTTEST (STR ("VST Test Base"))
	DECLARE_FUNKNOWN_METHODS

	bool PLUGIN_API setup ();
	bool PLUGIN_API run (ITestResult* testResult) {return false;}	// implement me
	bool PLUGIN_API teardown ();
//------------------------------------------------------------------------
protected:
	IPlugProvider* plugProvider;
	IComponent* vstPlug;
	IEditController* controller;

private:
	VstTestBase ();
};

//------------------------------------------------------------------------
/** Test Helper.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstTestEnh : public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstTestEnh (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	virtual ~VstTestEnh ();

	enum AudioDefaults
	{
		kBlockSize = 64,
		kMaxSamplesPerBlock = 8192,
		kSampleRate = 44100,
	};

	bool PLUGIN_API setup ();
	bool PLUGIN_API teardown ();
//------------------------------------------------------------------------
protected:
	// interfaces
	IAudioProcessor* audioEffect;

	ProcessSetup processSetup;
};

//------------------------------------------------------------------------
/** Test Suspend/Resume.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstSuspendResumeTest: public VstTestEnh
{
public:
//------------------------------------------------------------------------
	VstSuspendResumeTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);

	DECLARE_VSTTEST (STR ("Suspend/Resume"))
	
	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};


//------------------------------------------------------------------------
/** Test Terminate/Initialize.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstTerminateInitializeTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstTerminateInitializeTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Terminate/Initialize"))

	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Scan Buses.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstScanBussesTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstScanBussesTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Scan Buses"))
	
	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Scan Parameters.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstScanParametersTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstScanParametersTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Scan Parameters"))
	
	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test MIDI Mapping.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstMidiMappingTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstMidiMappingTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("MIDI Mapping"))
	
	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};



//------------------------------------------------------------------------
/** Test Note Expression.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstNoteExpressionTest: public VstTestBase
{
public:
	//------------------------------------------------------------------------
	VstNoteExpressionTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Note Expression"))

	bool PLUGIN_API run (ITestResult* testResult);
	//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Keyswitch.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstKeyswitchTest: public VstTestBase
{
public:
	//------------------------------------------------------------------------
	VstKeyswitchTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Keyswitch"))

	bool PLUGIN_API run (ITestResult* testResult);
	//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Scan Editor Classes.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstEditorClassesTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstEditorClassesTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Scan Editor Classes"))
	
	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Scan Units.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstUnitInfoTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstUnitInfoTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Scan Units"))
	
	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Scan Programs.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstProgramInfoTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstProgramInfoTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Scan Programs"))

	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Check Unit Structure.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstUnitStructureTest: public VstTestBase
{
public:
//------------------------------------------------------------------------
	VstUnitStructureTest (IPlugProvider* plugProvider);

	DECLARE_VSTTEST (STR ("Check Unit Structure"))

	bool PLUGIN_API run (ITestResult* testResult);
//------------------------------------------------------------------------
};

//------------------------------------------------------------------------
/** Test Process Test.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstProcessTest : public VstTestEnh
{
public:
//------------------------------------------------------------------------
	VstProcessTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);

	DECLARE_VSTTEST (STR ("Process Test"))
	
	// ITest
	bool PLUGIN_API setup ();
	bool PLUGIN_API run (ITestResult* testResult);
	bool PLUGIN_API teardown ();

//------------------------------------------------------------------------
protected:
	virtual bool prepareProcessing ();						///< setup ProcessData and allocate buffers
	virtual bool unprepareProcessing ();					///< free dynamic memory of ProcessData
	virtual bool preProcess (ITestResult* testResult);		///< is called just before the process call
	virtual bool postProcess (ITestResult* testResult);		///< is called right after the process call

	bool setupBuffers (int32 numBusses, AudioBusBuffers* audioBuffers, BusDirection dir);
	bool setupBuffers (AudioBusBuffers& audioBuffers);
	bool freeBuffers (int32 numBuses, AudioBusBuffers* buses);
	bool canProcessSampleSize (ITestResult* testResult);	///< audioEffect has to be available

	HostProcessData processData;
};

//------------------------------------------------------------------------
/** Test Speaker Arrangement.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstSpeakerArrangementTest : public VstProcessTest
{
public:
//------------------------------------------------------------------------
	VstSpeakerArrangementTest (IPlugProvider* plugProvider, ProcessSampleSize sampl, SpeakerArrangement inSpArr, SpeakerArrangement outSpArr);

	const tchar* getName () const;
	static const tchar* getSpeakerArrangementName (SpeakerArrangement spArr);
	
	// ITest
	bool PLUGIN_API run (ITestResult* testResult);

//------------------------------------------------------------------------
protected:
	bool prepareProcessing ();
	bool verifySA (int32 numBusses, AudioBusBuffers* buses, SpeakerArrangement spArr, ITestResult* testResult);
private:
	SpeakerArrangement inSpArr;
	SpeakerArrangement outSpArr;
};


class ParamChanges;
//------------------------------------------------------------------------
/** Test Automation.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstAutomationTest : public VstProcessTest, public IParameterChanges
{
public:
//------------------------------------------------------------------------
	VstAutomationTest (IPlugProvider* plugProvider, ProcessSampleSize sampl, int32 everyNSamples, int32 numParams, bool sampleAccuracy);
	virtual ~VstAutomationTest ();

	DECLARE_FUNKNOWN_METHODS
	const tchar* getName () const;
	// ITest
	bool PLUGIN_API setup ();
	bool PLUGIN_API run (ITestResult* testResult);
	bool PLUGIN_API teardown ();

	// IParameterChanges
	int32 PLUGIN_API getParameterCount ();
	IParamValueQueue* PLUGIN_API getParameterData (int32 index);
	IParamValueQueue* PLUGIN_API addParameterData (const ParamID& id, int32& index);

//------------------------------------------------------------------------
protected:
	bool preProcess (ITestResult* testResult);
	bool postProcess (ITestResult* testResult);
	ParamID bypassId;

	ParamChanges* paramChanges;
	int32 countParamChanges;
	int32 everyNSamples;
	int32 numParams;
	bool sampleAccuracy;
	bool onceExecuted;
};

//------------------------------------------------------------------------
/** Test Valid State Transition.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstValidStateTransitionTest : public VstTestBase
{
public:
	VstValidStateTransitionTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Valid State Transition"))
};

//------------------------------------------------------------------------
/** Test Invalid State Transition.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstInvalidStateTransitionTest : public VstTestBase
{
public:
	VstInvalidStateTransitionTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Invalid State Transition"))
};

//------------------------------------------------------------------------
/** Test Repeat Identical State Transition.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstRepeatIdenticalStateTransitionTest : public VstTestBase
{
public:
	VstRepeatIdenticalStateTransitionTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Repeat Identical State Transition"))
};

//------------------------------------------------------------------------
/** Test Bus Consistency.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstBusConsistencyTest : public VstTestBase
{
public:
	VstBusConsistencyTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Bus Consistency"))
};

//------------------------------------------------------------------------
/** Test Bus Invalid Index.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstBusInvalidIndexTest : public VstTestBase
{
public:
	VstBusInvalidIndexTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Bus Invalid Index"))
};

//------------------------------------------------------------------------
/** Test Silence Flags.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstSilenceFlagsTest : public VstProcessTest
{
public:
	VstSilenceFlagsTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Silence Flags"))
};

//------------------------------------------------------------------------
/** Test Silence Processing.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstSilenceProcessingTest : public VstProcessTest
{
public:
	VstSilenceProcessingTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Silence Processing"))
protected:
	bool isBufferSilent (void* buffer, int32 numSamples, ProcessSampleSize sampl);
};

//------------------------------------------------------------------------
/** Test Parameters Flush (no Buffer).
\ingroup TestClass */
//------------------------------------------------------------------------
class VstFlushParamTest : public VstAutomationTest
{
public:
	VstFlushParamTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Parameters Flush (no Buffer)"))
};

//------------------------------------------------------------------------
/** Test Bus Activation.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstBusActivationTest : public VstTestBase
{
public:
	VstBusActivationTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Bus Activation"))
};

//------------------------------------------------------------------------
/** Test Variable Block Size.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstVariableBlockSizeTest : public VstProcessTest
{
public:
	VstVariableBlockSizeTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Variable Block Size"))
};

//------------------------------------------------------------------------
/** Test Process Format.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstProcessFormatTest : public VstProcessTest
{
public:
	VstProcessFormatTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Process Format"))
};

//------------------------------------------------------------------------
/** Test Check Audio Bus Arrangement.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstCheckAudioBusArrangementTest : public VstTestBase
{
public:
	VstCheckAudioBusArrangementTest (IPlugProvider* plugProvider);
	bool PLUGIN_API run (ITestResult* testResult);

	DECLARE_VSTTEST (STR ("Check Audio Bus Arrangement"))
};


//------------------------------------------------------------------------
/** Test ProcesTail.
\ingroup TestClass */
//------------------------------------------------------------------------
class VstProcessTailTest : public VstProcessTest
{
public:
	//------------------------------------------------------------------------
	VstProcessTailTest (IPlugProvider* plugProvider, ProcessSampleSize sampl);
	virtual ~VstProcessTailTest ();

	DECLARE_VSTTEST (STR ("Check Tail processing"))

	// ITest
	bool PLUGIN_API setup ();
	bool PLUGIN_API run (ITestResult* testResult);
	bool preProcess (ITestResult* testResult);
	bool postProcess (ITestResult* testResult);
	
	//------------------------------------------------------------------------
protected:
	
private:
	uint32 mTailSamples;
	uint32 mInTail;

	float* dataPtrFloat;
	double* dataPtrDouble;
	bool mInSilenceInput;
	bool mDontTest;
};

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg

