//-----------------------------------------------------------------------------
// Project     : VST SDK
// Version     : 3.6.5
//
// Category    : Examples
// Filename    : public.sdk/samples/vst/hostchecker/source/eventlistcheck.cpp
// Created by  : Steinberg, 12/2012
// Description : Event List check
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

#include "eventlistcheck.h"
#include "eventlogger.h"
#include "logevents.h"
#include "pluginterfaces/vst/ivstcomponent.h"
#include "pluginterfaces/vst/ivstevents.h"

//------------------------------------------------------------------------
//    EventListCheck
//------------------------------------------------------------------------
EventListCheck::EventListCheck ()
: mEventLogger (0)
, mComponent (0)
{

}

//------------------------------------------------------------------------
void EventListCheck::check (Steinberg::Vst::IEventList* events)
{
	if (events)
	{
		if (!checkEventCount (events))
			mEventLogger->addLogEvent (kLogIdNumInputEventExceedsLimit);

		Steinberg::int32 lastSampleOffset = 0;
		Steinberg::Vst::TQuarterNotes lastPpqPosition = 0;
		Steinberg::int32 eventCount = events->getEventCount ();
		for (Steinberg::int32 eventIdx = 0; eventIdx < eventCount; ++eventIdx)
		{
			Steinberg::Vst::Event event = {};
			Steinberg::tresult tResult = events->getEvent (eventIdx, event);
			if (tResult != Steinberg::kResultOk)
			{
				mEventLogger->addLogEvent (kLogIdCouldNotGetAnInputEvent);
				continue;
			}

			if (event.sampleOffset < lastSampleOffset)
			{
				mEventLogger->addLogEvent (kLogIdEventsAreNotSortedBySampleOffset);
				lastSampleOffset = event.sampleOffset;
			}

			if (event.ppqPosition < lastPpqPosition)
			{
				mEventLogger->addLogEvent (kLogIdEventsAreNotSortedByPpqPosition);
				event.ppqPosition = lastPpqPosition;
			}

			checkEventProperties (event);
		}
	}
}

//------------------------------------------------------------------------
bool EventListCheck::checkEventCount (Steinberg::Vst::IEventList* events)
{
	if (events)
	{
		return events->getEventCount () >= 0 || events->getEventCount () < kMaxEvents;
	}

	return true;
}

//------------------------------------------------------------------------
void EventListCheck::checkEventProperties (const Steinberg::Vst::Event& event)
{
	//! TODO: Make this method smaller
	if (!checkEventBusIndex (event.busIndex))
	{
		mEventLogger->addLogEvent (kLogIdInvalidEventBusIndex);
		return;
	}

	if (!checkEventSampleOffset (event.sampleOffset))
	{
		mEventLogger->addLogEvent (kLogIdInvalidEventSampleOffset);
	}

	switch (event.type)
	{
		case Steinberg::Vst::Event::kNoteOnEvent:
		{
			if (!checkEventChannelIndex (event.busIndex, event.noteOn.channel))
				mEventLogger->addLogEvent (kLogIdInvalidNoteOnChannelIndex);

			if (!isNormalized (event.noteOn.velocity))
				mEventLogger->addLogEvent (kLogIdInvalidEventVelocityValue);

			if (!checkValidPitch (event.noteOn.pitch))
				mEventLogger->addLogEvent (kLogIdInvalidEventPitchValue);

			if (mNotePitches.find (event.noteOn.pitch) != mNotePitches.end ())
			{
				mEventLogger->addLogEvent (kLogIdNoteOnWithPitchAlreadyTriggered);
			}

			mNotePitches.insert (event.noteOn.pitch);

			if (event.noteOn.noteId >= 0)
			{
				if (mNoteIDs.find (event.noteOn.noteId) != mNoteIDs.end ())
					mEventLogger->addLogEvent (kLogIdNoteOnWithIdAlreadyTriggered);
			}

			mNoteIDs.insert (event.noteOn.noteId);

			break;
		}

		case Steinberg::Vst::Event::kNoteOffEvent:				///< is \ref NoteOffEvent
		{
			if (!checkEventChannelIndex (event.busIndex, event.noteOff.channel))
				mEventLogger->addLogEvent (kLogIdInvalidNoteOffChannelIndex);

			if (!isNormalized (event.noteOff.velocity))
				mEventLogger->addLogEvent (kLogIdInvalidEventVelocityValue);

			if (!checkValidPitch (event.noteOff.pitch))
				mEventLogger->addLogEvent (kLogIdInvalidEventPitchValue);

			if (mNotePitches.find (event.noteOff.pitch) == mNotePitches.end ())
			{
				mEventLogger->addLogEvent (kLogIdNoteOffWithPitchNeverTriggered);
			}

			mNotePitches.erase (event.noteOff.pitch);

			if (event.noteOff.noteId >= 0)
			{
				if (mNoteIDs.find (event.noteOff.noteId) == mNoteIDs.end ())
				{
					mEventLogger->addLogEvent (kLogIdNoteOffWithIdNeverTriggered);
				}
			}

			mNoteIDs.erase (event.noteOff.noteId);

			break;
		}

		case Steinberg::Vst::Event::kDataEvent:					///< is \ref DataEvent
		{
			break;
		}

		case Steinberg::Vst::Event::kPolyPressureEvent:			///< is \ref PolyPressureEvent
		{
			if (!checkEventChannelIndex (event.busIndex, event.polyPressure.channel))
				mEventLogger->addLogEvent (kLogIdInvalidPolyPressChannelIndex);

			break;
		}

		case Steinberg::Vst::Event::kNoteExpressionValueEvent:	///< is \ref NoteExpressionValueEvent
		{
			if (!isNormalized (event.noteExpressionValue.value))
				mEventLogger->addLogEvent (kLogIdNoteExpressValNotNormalized);

			checkNoteExpressionValueEvent (event.noteExpressionValue.typeId, event.noteExpressionValue.noteId, event.noteExpressionValue.value);
			break;
		}

		default: 
		{
			mEventLogger->addLogEvent (kLogIdUnknownEventType);
			break;
		}
	}
}

//------------------------------------------------------------------------
bool EventListCheck::checkEventBusIndex (Steinberg::int32 busIndex)
{
	if (mComponent)
	{
		Steinberg::int32 busCount = mComponent->getBusCount (Steinberg::Vst::kEvent, Steinberg::Vst::kInput);
		return busCount >= 0 && busIndex < busCount;
	}

	return false;
}

//------------------------------------------------------------------------
bool EventListCheck::checkEventSampleOffset (Steinberg::int32 sampleOffset)
{
	return sampleOffset >= 0 && sampleOffset < mSetup.maxSamplesPerBlock;
}

//------------------------------------------------------------------------
bool EventListCheck::checkEventChannelIndex (Steinberg::int32 busIndex, Steinberg::int32 channelIndex)
{
	if (mComponent)
	{
		Steinberg::int32 busCount = mComponent->getBusCount (Steinberg::Vst::kEvent, Steinberg::Vst::kInput);
		if (busCount >= 0 && busIndex < busCount)
		{
			Steinberg::Vst::BusInfo busInfo = { 0 };
			Steinberg::tresult tResult = mComponent->getBusInfo (Steinberg::Vst::kEvent, Steinberg::Vst::kInput, busIndex, busInfo);
			if (tResult == Steinberg::kResultOk)
			{
				return channelIndex >= 0 && channelIndex < busInfo.channelCount;
			}
		}
	}

	return false;
}

//------------------------------------------------------------------------
bool EventListCheck::checkValidPitch (Steinberg::int16 pitch)
{
	return pitch >= 0 && pitch <= 127;
}

//------------------------------------------------------------------------
bool EventListCheck::isNormalized (float normVal) const
{
	return normVal >= 0. && normVal <= 1.;
}

//------------------------------------------------------------------------
void EventListCheck::checkNoteExpressionValueEvent (Steinberg::Vst::NoteExpressionTypeID type, Steinberg::int32 id, Steinberg::Vst::NoteExpressionValue exprVal) const
{
	if (!isNormalized (exprVal))
	{
		//! Todo
	}
}

//------------------------------------------------------------------------
void EventListCheck::setProcessSetup (Steinberg::Vst::ProcessSetup setup)
{
	mSetup = setup;
}

//------------------------------------------------------------------------
void EventListCheck::setEventLogger (EventLogger* eventLogger)
{
	mEventLogger = eventLogger;
}
