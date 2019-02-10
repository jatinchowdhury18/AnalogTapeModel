//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/common/voicebase.h
// Created by  : Steinberg, 02/2010
// Description : 
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2015, Steinberg Media Technologies GmbH, All Rights Reserved
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

#pragma once

#include "pluginterfaces/vst/vsttypes.h"
#include "base/source/fdebug.h"

#ifdef DEBUG_LOG
	#undef DEBUG_LOG
#endif

#define DEBUG_LOG	DEVELOPMENT

namespace Steinberg {
namespace Vst {

//-----------------------------------------------------------------------------
/** Example Voice class for the Steinberg::Vst::VoiceProcessorImplementation 

Implementation classes need to implement the following additional method:
\code
	bool process (SamplePrecision* outputBuffers[numChannels], int32 numSamples);
\endcode
*/
//-----------------------------------------------------------------------------
template<uint32 numValues, class SamplePrecision, uint32 numChannels, class GlobalParameterStorage> 
class VoiceBase
{
public:
	/** Returns the current note id of this voice. */
	int32 getNoteId () const { return noteId; }

	/** Sets a new GlobalParameterStorage. */
	virtual void setGlobalParameterStorage (GlobalParameterStorage* globalParameters) { this->globalParameters = globalParameters; }
	/** Sets the sampleRate. */
	virtual void setSampleRate (ParamValue sampleRate) { this->sampleRate = sampleRate; }
	/** Returns the sampleRate. */
	float getSampleRate () const { return (float)sampleRate; }

	virtual void setNoteExpressionValue (int32 index, ParamValue value) { if (index < numValues) values[index] = value; }

	virtual void noteOn (int32 pitch, ParamValue velocity, float tuning, int32 sampleOffset, int32 noteId);
	virtual void noteOff (ParamValue velocity, int32 sampleOffset);

	virtual void reset () 
	{ 
		noteOnSampleOffset = -1;
		noteOffSampleOffset = -1;
		noteId = -1;
		tuning = 0;
	}

//-----------------------------------------------------------------------------
protected:
	VoiceBase ();
	VoiceBase (const VoiceBase& vb);
	virtual ~VoiceBase ();

	GlobalParameterStorage* globalParameters;

	int32 noteId;
	int32 pitch;
	int32 noteOnSampleOffset;
	int32 noteOffSampleOffset;
	float tuning;

	ParamValue sampleRate;
	ParamValue noteOnVelocity;
	ParamValue noteOffVelocity;
	ParamValue values[numValues];
};

//-----------------------------------------------------------------------------
template<uint32 numValues, class SamplePrecision, uint32 numChannels, class GlobalParameterStorage>
VoiceBase<numValues, SamplePrecision, numChannels, GlobalParameterStorage>::VoiceBase ()
: globalParameters (0)
, noteId (-1)
, pitch (-1)
, noteOnSampleOffset (0)
, noteOffSampleOffset (0)
, sampleRate (44100.)
, noteOnVelocity (0.)
, noteOffVelocity (0.)
{
}

//-----------------------------------------------------------------------------
template<uint32 numValues, class SamplePrecision, uint32 numChannels, class GlobalParameterStorage>
VoiceBase<numValues, SamplePrecision, numChannels, GlobalParameterStorage>::VoiceBase (const VoiceBase<numValues, SamplePrecision, numChannels, GlobalParameterStorage>& vb)
: globalParameters (vb.globalParameters)
, noteId (vb.noteId)
, pitch (vb.pitch)
, noteOnSampleOffset (vb.noteOnSampleOffset)
, noteOffSampleOffset (vb.noteOffSampleOffset)
, noteOnVelocity (vb.noteOnVelocity)
, noteOffVelocity (vb.noteOffVelocity)
, sampleRate (vb.sampleRate)
, values (0)
{
	for (uint32 i = 0; i < numValues; i++)
		values[i] = vb.values[i];
}

//-----------------------------------------------------------------------------
template<uint32 numValues, class SamplePrecision, uint32 numChannels, class GlobalParameterStorage>
VoiceBase<numValues, SamplePrecision, numChannels, GlobalParameterStorage>::~VoiceBase ()
{
}

//-----------------------------------------------------------------------------
template<uint32 numValues, class SamplePrecision, uint32 numChannels, class GlobalParameterStorage>
void VoiceBase<numValues, SamplePrecision, numChannels, GlobalParameterStorage>::noteOn (int32 pitch, ParamValue velocity,  float tuning, int32 sampleOffset, int32 nId)
{
	this->pitch = pitch;
	noteOnVelocity = velocity;
	noteOnSampleOffset = sampleOffset;
	noteId = nId;
	this->tuning = tuning;

#if DEBUG_LOG
	FDebugPrint ("NoteOn :%d\n", nId);
#endif
}

//-----------------------------------------------------------------------------
template<uint32 numValues, class SamplePrecision, uint32 numChannels, class GlobalParameterStorage>
void VoiceBase<numValues, SamplePrecision, numChannels, GlobalParameterStorage>::noteOff (ParamValue velocity, int32 sampleOffset)
{
	noteOffVelocity = velocity;
	noteOffSampleOffset = sampleOffset;

#if DEBUG_LOG
	FDebugPrint ("NoteOff:%d\n", this->noteId);
#endif
}

//------------------------------------------------------------------------
} // namespace Vst
} // namespace Steinberg
