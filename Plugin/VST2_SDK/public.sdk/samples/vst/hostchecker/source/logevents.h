//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/logevents.h
// Created by  : Steinberg, 04/2012
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

#include "pluginterfaces/base/ftypes.h"
#include <map>
#include "base/source/fstring.h"

//------------------------------------------------------------------------
struct LogEvent
{
	LogEvent () 
	: id (-1)
	, count (0)
	, fromProcessor (false) {}

	Steinberg::int64 id;
	Steinberg::int64 count;
	bool fromProcessor;
};

//------------------------------------------------------------------------
// Categories
#define SETUP_CONTEXT "SetupContext"
#define AUDIO_BUFFER "AudioBuffer"
#define EVENT_LIST "EventList"
#define PARAM_CHANGE "ParameterChanges"
#define PROCESS_DATA "ProcessData"
#define PROCESS_CONTEXT "ProcessContext"
#define FEATURE_SUPPORT "FeatureSupport"
#define FEATURE_PROCESSOR_SUPPORT "FeatureProcessSupport"

#define PROCESS true
#define CONTROL false

// Severity
#define LOG_ERR "Error"
#define LOG_WARN "Warn"
#define LOG_INFO "Info"

#define LOG_EVENT_LIST(LOG_DEF) \
	LOG_DEF(kLogIdProcessorControllerConnection,CONTROL,	LOG_WARN, SETUP_CONTEXT, "Processor and controller are directly connected (direct pointers no wrapper)."), \
	LOG_DEF(kLogIdInvalidSymbolicSampleSize,	PROCESS,	LOG_ERR, PROCESS_DATA, "Symbolic sample size does not match the one in ProcessSetup"), \
	LOG_DEF(kLogIdInvalidProcessMode,			PROCESS,	LOG_ERR, PROCESS_DATA, "Process mode does not match the one in ProcessSetup."),\
	LOG_DEF(kLogIdInvalidBlockSize,				PROCESS,	LOG_ERR, PROCESS_DATA, "Block size is either < 1 or >= max block size."),\
	LOG_DEF(kLogIdProcessContextPointerNull,	PROCESS,	LOG_WARN,	PROCESS_DATA, "Pointer to ProcessContext struct is null."),\
	LOG_DEF(kLogIdNullPointerToChannelBuf,		PROCESS,	LOG_ERR, AUDIO_BUFFER, "A pointer to a channel buffer is null although the index is valid."),\
	LOG_DEF(kLogIdNullPointerToAudioBusBuffer,	PROCESS,	LOG_ERR, AUDIO_BUFFER, "A pointer to an audio bus buffer is null although the index is valid."),\
	LOG_DEF(kLogIdAudioBufNotMatchComponentBusCount,PROCESS, LOG_ERR, AUDIO_BUFFER, "Number of Audio Buffers does not match the number of buses defined by IComponent."),\
	LOG_DEF(kLogIdInvalidAudioBufNumOfChannels,	PROCESS,	LOG_ERR, AUDIO_BUFFER, "An audio bus has a different number of channels than specified by IComponent."),\
	LOG_DEF(kLogIdUnknownEventType,				PROCESS,	LOG_ERR, EVENT_LIST, "Event has a type which is not specified."),\
	LOG_DEF(kLogIdInvalidEventVelocityValue,	PROCESS,	LOG_ERR, EVENT_LIST, "Event velocity is either < 0.0 or > 1.0."),\
	LOG_DEF(kLogIdInvalidEventPitchValue,		PROCESS,	LOG_ERR, EVENT_LIST, "Event pitch is either < 0 or > 127."),\
	LOG_DEF(kLogIdInvalidEventSampleOffset,		PROCESS,	LOG_ERR, EVENT_LIST, "Event sample offset either < 0 or >= max block size."),\
	LOG_DEF(kLogIdInvalidEventBusIndex,			PROCESS,	LOG_ERR, EVENT_LIST, "Event has a bus index which is different than specified by IComponent."),\
	LOG_DEF(kLogIdInvalidNoteOnChannelIndex,	PROCESS,	LOG_ERR, EVENT_LIST, "Note on event has a channel index which was not specified by IComponent."),\
	LOG_DEF(kLogIdInvalidNoteOffChannelIndex,	PROCESS,	LOG_ERR, EVENT_LIST, "Note off event has a channel index which was not specified by IComponent."),\
	LOG_DEF(kLogIdInvalidPolyPressChannelIndex,	PROCESS,	LOG_ERR, EVENT_LIST, "Poly pressure event has a channel index which was not specified by IComponent."),\
	LOG_DEF(kLogIdNumInputEventExceedsLimit,	PROCESS,	LOG_WARN, EVENT_LIST, "List contains more than 2048 events."),\
	LOG_DEF(kLogIdCouldNotGetAnInputEvent,		PROCESS,	LOG_WARN, EVENT_LIST, "Getting an event returned an error code."),\
	LOG_DEF(kLogIdEventsAreNotSortedBySampleOffset,	PROCESS, LOG_WARN, EVENT_LIST, "Events are not sorted by sample offset."),\
	LOG_DEF(kLogIdEventsAreNotSortedByPpqPosition,	PROCESS, LOG_WARN, EVENT_LIST, "Events are not sorted by PPQ position."),\
	LOG_DEF(kLogIdNoteOnWithPitchAlreadyTriggered,	PROCESS, LOG_INFO, EVENT_LIST, "An event occurred with a pitch currently already triggered."),\
	LOG_DEF(kLogIdNoteOnWithIdAlreadyTriggered,		PROCESS, LOG_WARN, EVENT_LIST, "An event occurred with an ID currently already triggered."),\
	LOG_DEF(kLogIdNoteOffWithIdNeverTriggered,		PROCESS, LOG_WARN, EVENT_LIST, "A note off event with no matching note on (ID)"),\
	LOG_DEF(kLogIdNoteOffWithPitchNeverTriggered,	PROCESS, LOG_WARN, EVENT_LIST, "A note off event with no matching note on (pitch)."),\
	LOG_DEF(kLogIdNoteExpressValNotNormalized,		PROCESS, LOG_ERR, EVENT_LIST,  "A note expression event value is either < 0.0 or > 1.0."),\
	LOG_DEF(kLogIdInvalidProcessContextSampleRate,	PROCESS, LOG_ERR, PROCESS_CONTEXT, "The sampleRate does not match the one in ProcessSetup."),\
	LOG_DEF(kLogIdInvalidParamValue,				PROCESS, LOG_ERR, PARAM_CHANGE, "Parameter value is < 0.0 or > 1.0"),\
	LOG_DEF(kLogIdInvalidParameterCount,			PROCESS, LOG_ERR, PARAM_CHANGE, "The number of changes is bigger than the number of parameters specified by IEditController."),\
	LOG_DEF(kLogIdInvalidParameterID,				PROCESS, LOG_ERR, PARAM_CHANGE, "A parameter change queue has a parameter ID which was not specified by IEditController."),\
	LOG_DEF(kLogIdParameterChangesPointerIsNull,	PROCESS, LOG_WARN, PARAM_CHANGE, "Pointer to parameter changes interface is null."),\
	LOG_DEF(kLogIdParameterQueueIsNullForValidIndex, PROCESS, LOG_ERR, PARAM_CHANGE, "Pointer to parameter value queue interface is null, although index is valid."),\
	LOG_DEF(kLogIdParametersAreNotSortedBySampleOffset, PROCESS, LOG_ERR, PARAM_CHANGE, "Parameter changes (for a ID) are not sorted by sample offset."),\
	LOG_DEF(kLogIdParametersHaveSameSampleOffset,   PROCESS, LOG_WARN, PARAM_CHANGE, "Parameter changes (for a ID) have more than one time the same sample offset."),\
	LOG_DEF(kLogIdIEditController2Supported,        CONTROL, LOG_INFO, FEATURE_SUPPORT, "IEditController2 supported!."), \
	LOG_DEF(kLogIdIComponentHandler2Supported,      CONTROL, LOG_INFO, FEATURE_SUPPORT, "IComponentHandler2 supported!"), \
	LOG_DEF(kLogIdIComponentHandler2SetDirtySupported, CONTROL, LOG_INFO, FEATURE_SUPPORT, "IComponentHandler2::setDirty supported!"), \
	LOG_DEF(kLogIdIComponentHandler2RequestOpenEditorSupported, CONTROL, LOG_INFO, FEATURE_SUPPORT, "IComponentHandler2::requestOpenEditor supported!"), \
	LOG_DEF(kLogIdIComponentHandler3Supported,		CONTROL, LOG_INFO, FEATURE_SUPPORT, "IComponentHandler3 (contextMenu) supported!"), \
	LOG_DEF(kLogIdIMidiMappingSupported,            CONTROL, LOG_INFO, FEATURE_SUPPORT, "IMidiMapping supported!"), \
	LOG_DEF(kLogIdUnitSupported,                    CONTROL, LOG_INFO, FEATURE_SUPPORT, "Unit supported!"), \
	LOG_DEF(kLogIdGetUnitByBusSupported,            CONTROL, LOG_INFO, FEATURE_SUPPORT, "IUnitInfo::getUnitByBus supported!"), \
	LOG_DEF(kLogIdChannelContextSupported,          CONTROL, LOG_INFO, FEATURE_SUPPORT, "ChannelContext::IInfoListener supported!"), \
	LOG_DEF(kLogIdINoteExpressionControllerSupported, CONTROL, LOG_INFO, FEATURE_SUPPORT, "INoteExpressionController supported!"), \
	LOG_DEF(kLogIdIXmlRepresentationControllerSupported, CONTROL,  LOG_INFO, FEATURE_SUPPORT, "XmlRepresentation supported!"),\
	LOG_DEF(kLogIdIAttributeListInSetStateSupported, PROCESS, LOG_INFO, FEATURE_SUPPORT, "IAttributeList in setState supported!"), \
	LOG_DEF(kLogIdAudioPresentationLatencySamplesSupported, PROCESS, LOG_INFO, FEATURE_PROCESSOR_SUPPORT, "IAudioPresentationLatency supported!"), \
	LOG_DEF(kLogIdIPrefetchableSupportSupported, PROCESS, LOG_INFO, FEATURE_PROCESSOR_SUPPORT, "IPrefetchableSupport supported!")


#define LOG_ID(a, b, c, d, e) a
#define LOG_SEVER(a, b, c, d, e) c
#define LOG_DESC(a, b, c, d, e) ("[" d"] " e) // "[category] description"
#define LOG_CONTEXT(a, b, c, d, e) b

// enum of all IDs
enum eLogIds
{
	LOG_EVENT_LIST(LOG_ID),
	kNumLogEvents
};

// array of bool process : 'true' or controller : 'false'
static const bool logEventContext[] =
{
	LOG_EVENT_LIST (LOG_CONTEXT)
};

// array of log descriptions
static const char *logEventDescriptions[] =
{
	LOG_EVENT_LIST(LOG_DESC)
};

// array of string 'error' or 'warning'
static const char* logEventSeverity[] =
{
	LOG_EVENT_LIST(LOG_SEVER)
};
