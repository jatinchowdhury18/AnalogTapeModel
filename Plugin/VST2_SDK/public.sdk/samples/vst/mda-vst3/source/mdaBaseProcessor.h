/*
 *  mdaBaseProcessor.h
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/14/08.
 *
 *  mda VST Plug-ins
 *
 *  Copyright (c) 2008 Paul Kellett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __mdaBaseProcessor__
#define __mdaBaseProcessor__

#include "public.sdk/source/vst/vstaudioeffect.h"
#include "pluginterfaces/vst/ivstevents.h"
#include "pluginterfaces/vst/ivstparameterchanges.h"

namespace Steinberg {
namespace Vst {
namespace mda {

//-----------------------------------------------------------------------------
class BaseProcessor : public AudioEffect
{
protected:
	BaseProcessor ();
	~BaseProcessor ();

	virtual void doProcessing (ProcessData& data) = 0;
	virtual bool bypassProcessing (ProcessData& data);
	virtual void processEvents (IEventList* /*events*/) {}
	virtual void checkSilence (ProcessData& data);
	virtual void setBypass (bool state, int32 sampleOffset);
	virtual bool processParameterChanges (IParameterChanges* changes);
	virtual void setParameter (ParamID index, ParamValue newValue, int32 sampleOffset);
	virtual void allocParameters (int32 numParams);
	virtual void recalculate () {}
	
	bool isBypassed () const { return bypassState; }
	double getSampleRate () const { return processSetup.sampleRate; }

	tresult PLUGIN_API process (ProcessData& data);

	tresult PLUGIN_API setupProcessing (ProcessSetup& setup);
	tresult PLUGIN_API setActive (TBool state);
	tresult PLUGIN_API setBusArrangements (SpeakerArrangement* inputs, int32 numIns, SpeakerArrangement* outputs, int32 numOuts);

	tresult PLUGIN_API setState (IBStream* state);
	tresult PLUGIN_API getState (IBStream* state);

	ParamValue* params;
	uint32 numParams;
	int32 bypassRamp;
	
	float* bypassBuffer0;
	float* bypassBuffer1;

	bool bypassState;
};

}}} // namespace

#endif
