/*
 *  mdafactory.cpp
 *  mda-vst3
 *
 *  Created by Arne Scheffler on 6/13/08.
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

#include "public.sdk/source/main/pluginfactoryvst3.h"
#include "mdaAmbienceController.h"
#include "mdaBandistoController.h"
#include "mdaBeatBoxController.h"
#include "mdaComboController.h"
#include "mdaDeEsserController.h"
#include "mdaDegradeController.h"
#include "mdaDelayController.h"
#include "mdaDetuneController.h"
#include "mdaDitherController.h"
#include "mdaDubDelayController.h"
#include "mdaDX10Controller.h"
#include "mdaDynamicsController.h"
#include "mdaEPianoController.h"
#include "mdaImageController.h"
#include "mdaJX10Controller.h"
#include "mdaLeslieController.h"
#include "mdaLimiterController.h"
#include "mdaLoudnessController.h"
#include "mdaMultiBandController.h"
#include "mdaOverdriveController.h"
#include "mdaPianoController.h"
#include "mdaRePsychoController.h"
#include "mdaRezFilterController.h"
#include "mdaRingModController.h"
#include "mdaRoundPanController.h"
#include "mdaShepardController.h"
#include "mdaSplitterController.h"
#include "mdaStereoController.h"
#include "mdaSubSynthController.h"
#include "mdaTalkBoxController.h"
#include "mdaTestToneController.h"
#include "mdaThruZeroController.h"
#include "mdaTrackerController.h"
#include "mdaSpecMeterController.h"
#include "helpers.h"
#include "version.h"

//-----------------------------------------------------------------------------
bool InitModule () { return true; }
bool DeinitModule () { return true; }

//-----------------------------------------------------------------------------
#define kVersionString	FULL_VERSION_STR

using namespace Steinberg::Vst;

BEGIN_FACTORY_DEF (stringCompanyName, 
				   "http://www.steinberg.net", 
				   "mailto:info@steinberg.de")

//-----------------------------------------------------------------------------
// -- Ambience
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::AmbienceProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Ambience",
			Vst::kDistributable,
			Vst::PlugType::kFxReverb,
			kVersionString,
			kVstVersionString,
			mda::AmbienceProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::AmbienceController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Ambience",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::AmbienceController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Bandisto
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::BandistoProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Bandisto",
			Vst::kDistributable,
			Vst::PlugType::kFxDistortion,
			kVersionString,
			kVstVersionString,
			mda::BandistoProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::BandistoController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Bandisto",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::BandistoController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- BeatBox
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::BeatBoxProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda BeatBox",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::BeatBoxProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::BeatBoxController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda BeatBox",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::BeatBoxController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Combo
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ComboProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Combo",
			Vst::kDistributable,
			Vst::PlugType::kFxDistortion,
			kVersionString,
			kVstVersionString,
			mda::ComboProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ComboController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Combo",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::ComboController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- DeEsser
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DeEsserProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda DeEsser",
			Vst::kDistributable,
			Vst::PlugType::kFxMastering,
			kVersionString,
			kVstVersionString,
			mda::DeEsserProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DeEsserController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda DeEsser",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DeEsserController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Degrade
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DegradeProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Degrade",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::DegradeProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DegradeController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Degrade",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DegradeController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Delay
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DelayProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Delay",
			Vst::kDistributable,
			Vst::PlugType::kFxDelay,
			kVersionString,
			kVstVersionString,
			mda::DelayProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DelayController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Delay",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DelayController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Detune
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DetuneProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Detune",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::DetuneProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DetuneController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Detune",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DetuneController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Dither
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DitherProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Dither",
			Vst::kDistributable,
			Vst::PlugType::kFxMastering,
			kVersionString,
			kVstVersionString,
			mda::DitherProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DitherController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Dither",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DitherController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- DubDelay
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DubDelayProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda DubDelay",
			Vst::kDistributable,
			Vst::PlugType::kFxDelay,
			kVersionString,
			kVstVersionString,
			mda::DubDelayProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DubDelayController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda DubDelay",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DubDelayController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- DX10
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DX10Processor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda DX10",
			Vst::kDistributable,
			Vst::PlugType::kInstrumentSynth,
			kVersionString,
			kVstVersionString,
			mda::DX10Processor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DX10Controller::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda DX10",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DX10Controller::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Dynamics
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DynamicsProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Dynamics",
			Vst::kDistributable,
			Vst::PlugType::kFxDynamics,
			kVersionString,
			kVstVersionString,
			mda::DynamicsProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::DynamicsController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Dynamics",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::DynamicsController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- EPiano
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::EPianoProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda EPiano",
			Vst::kDistributable,
			Vst::PlugType::kInstrumentSynth,
			kVersionString,
			kVstVersionString,
			mda::EPianoProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::EPianoController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda EPiano",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::EPianoController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Image
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ImageProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Image",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::ImageProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ImageController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Image",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::ImageController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- JX10
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::JX10Processor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda JX10",
			Vst::kDistributable,
			Vst::PlugType::kInstrumentSynth,
			kVersionString,
			kVstVersionString,
			mda::JX10Processor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::JX10Controller::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda JX10",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::JX10Controller::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Leslie
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::LeslieProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Leslie",
			Vst::kDistributable,
			Vst::PlugType::kFxModulation,
			kVersionString,
			kVstVersionString,
			mda::LeslieProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::LeslieController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Leslie",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::LeslieController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Limiter
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::LimiterProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Limiter",
			Vst::kDistributable,
			Vst::PlugType::kFxDynamics,
			kVersionString,
			kVstVersionString,
			mda::LimiterProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::LimiterController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Limiter",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::LimiterController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Loudness
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::LoudnessProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Loudness",
			Vst::kDistributable,
			Vst::PlugType::kFxDynamics,
			kVersionString,
			kVstVersionString,
			mda::LoudnessProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::LoudnessController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Loudness",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::LoudnessController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- MultiBand
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::MultiBandProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda MultiBand",
			Vst::kDistributable,
			Vst::PlugType::kFxDynamics,
			kVersionString,
			kVstVersionString,
			mda::MultiBandProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::MultiBandController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda MultiBand",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::MultiBandController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Overdrive
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::OverdriveProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Overdrive",
			Vst::kDistributable,
			Vst::PlugType::kFxDistortion,
			kVersionString,
			kVstVersionString,
			mda::OverdriveProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::OverdriveController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Overdrive",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::OverdriveController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Piano
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::PianoProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Piano",
			Vst::kDistributable,
			Vst::PlugType::kInstrumentSynth,
			kVersionString,
			kVstVersionString,
			mda::PianoProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::PianoController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Piano",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::PianoController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- RePsycho
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RePsychoProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda RePsycho!",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::RePsychoProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RePsychoController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda RePsycho!",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::RePsychoController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- RezFilter
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RezFilterProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda RezFilter",
			Vst::kDistributable,
			Vst::PlugType::kFxFilter,
			kVersionString,
			kVstVersionString,
			mda::RezFilterProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RezFilterController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda RezFilter",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::RezFilterController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- RingMod
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RingModProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda RingMod",
			Vst::kDistributable,
			Vst::PlugType::kFxModulation,
			kVersionString,
			kVstVersionString,
			mda::RingModProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RingModController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda RingMod",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::RingModController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Round Panner
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RoundPanProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Round Panner",
			Vst::kDistributable,
			Vst::PlugType::kFxModulation,
			kVersionString,
			kVstVersionString,
			mda::RoundPanProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::RoundPanController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Round Panner",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::RoundPanController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Shepard
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ShepardProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Shepard",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::ShepardProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ShepardController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Shepard",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::ShepardController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Splitter
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::SplitterProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Splitter",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::SplitterProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::SplitterController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Splitter",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::SplitterController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Stereo Simulator
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::StereoProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Stereo Simulator",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::StereoProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::StereoController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Stereo Simulator",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::StereoController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Sub-Bass Synthesizer
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::SubSynthProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Sub-Bass Synthesizer",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::SubSynthProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::SubSynthController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Sub-Bass Synthesizer",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::SubSynthController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- TalkBox
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::TalkBoxProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda TalkBox",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::TalkBoxProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::TalkBoxController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda TalkBox",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::TalkBoxController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- TestTone
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::TestToneProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda TestTone",
			Vst::kDistributable,
			Vst::PlugType::kFxGenerator,
			kVersionString,
			kVstVersionString,
			mda::TestToneProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::TestToneController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda TestTone",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::TestToneController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Thru-Zero Flanger
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ThruZeroProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Thru-Zero Flanger",
			Vst::kDistributable,
			Vst::PlugType::kFxModulation,
			kVersionString,
			kVstVersionString,
			mda::ThruZeroProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::ThruZeroController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Thru-Zero Flanger",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::ThruZeroController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- Tracker
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::TrackerProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda Tracker",
			Vst::kDistributable,
			Vst::PlugType::kFx,
			kVersionString,
			kVstVersionString,
			mda::TrackerProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::TrackerController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda Tracker",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::TrackerController::createInstance)
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// -- SpecMeter
DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::SpecMeterProcessor::uid),
			PClassInfo::kManyInstances,
			kVstAudioEffectClass,
			"mda SpecMeter",
			Vst::kDistributable,
			Vst::PlugType::kFxAnalyzer,
			kVersionString,
			kVstVersionString,
			mda::SpecMeterProcessor::createInstance)

DEF_CLASS2 (INLINE_UID_FROM_FUID (mda::SpecMeterController::uid),
			PClassInfo::kManyInstances,
			kVstComponentControllerClass,
			"mda SpecMeter",
			Vst::kDistributable,
			"",
			kVersionString,
			kVstVersionString,
			mda::SpecMeterController::createInstance)
//-----------------------------------------------------------------------------
END_FACTORY

