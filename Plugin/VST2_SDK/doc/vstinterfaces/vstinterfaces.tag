<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>VST 3 API Documentation</title>
    <filename>index</filename>
    <docanchor file="index">private</docanchor>
    <docanchor file="index">vst3Structure</docanchor>
    <docanchor file="index">vst3Contents</docanchor>
    <docanchor file="index">vst3Processing</docanchor>
    <docanchor file="index">Persistence</docanchor>
    <docanchor file="index">creation</docanchor>
    <docanchor file="index">vst3Editing</docanchor>
    <docanchor file="index">Initialize</docanchor>
    <docanchor file="index">initialization</docanchor>
    <docanchor file="index">vst3Communication</docanchor>
    <docanchor file="index">icomponent</docanchor>
    <docanchor file="index">iaudioprocessor</docanchor>
    <docanchor file="index">standard</docanchor>
    <docanchor file="index">Extensions</docanchor>
  </compound>
  <compound kind="file">
    <name>doc.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>doc_8h</filename>
  </compound>
  <compound kind="file">
    <name>ivstattributes.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstattributes_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">pluginterfaces/vst/vsttypes.h</includes>
    <class kind="class">Steinberg::Vst::IAttributeList</class>
    <class kind="class">Steinberg::Vst::IStreamAttributes</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstaudioprocessor.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstaudioprocessor_8h</filename>
    <includes id="ivstaudioprocessor_8h" name="ivstaudioprocessor.h" local="yes" imported="no">ivstcomponent.h</includes>
    <class kind="struct">Steinberg::Vst::ProcessSetup</class>
    <class kind="struct">Steinberg::Vst::AudioBusBuffers</class>
    <class kind="struct">Steinberg::Vst::ProcessData</class>
    <class kind="class">Steinberg::Vst::IAudioProcessor</class>
    <class kind="class">Steinberg::Vst::IAudioPresentationLatency</class>
    <namespace>Steinberg::Vst</namespace>
    <namespace>Steinberg::Vst::PlugType</namespace>
    <member kind="define">
      <type>#define</type>
      <name>kVstAudioEffectClass</name>
      <anchorfile>ivstaudioprocessor_8h.html</anchorfile>
      <anchor>ae55c95a44e931e1cd78998c94bc65ee1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ComponentFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a626a070dcd2e025250f41b9c3f9817cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDistributable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a626a070dcd2e025250f41b9c3f9817cda3185111648c1599241528f1a7f523396</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSimpleModeSupported</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a626a070dcd2e025250f41b9c3f9817cdabc2edc9bb281cebe9cc6dc00a7cac0ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>SymbolicSampleSizes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>addd8f2e89ed5a540c9fce2c002f35c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSample32</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>addd8f2e89ed5a540c9fce2c002f35c06a199093967f5a183f86bf92bd7e61e31f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSample64</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>addd8f2e89ed5a540c9fce2c002f35c06a85edf5095f2282be74fce43030f1b900</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ProcessModes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRealtime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31af21cd390d9ad5f7929f3f0a3ab972e13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPrefetch</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31a3b1caa5d658939c027cbb7759358a88a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOffline</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31a27042cfd9e04c874beea670ee64ac9ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>TailEnum</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a44451c855a6ae9e4ef150a8943f6bf80</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoTail</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a44451c855a6ae9e4ef150a8943f6bf80aff8084010aeec9469eab44f0c3ea2384</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInfiniteTail</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a44451c855a6ae9e4ef150a8943f6bf80ae5ba421c7a57bec9ca3a08b2c8b25d1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxAnalyzer</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1c5f3f4e7d5210a9d81e6dcd76c79c67</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDelay</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae3635bf778d4382234cbcfc30d71db16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDistortion</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gac923ee5b5ba8b5bddb285aad2be3ff35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDynamics</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa892f409ac4c930c1af59459372c167b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxEQ</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae94c37234a2f8bc1c54f85e4d70ad1a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxFilter</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa7061a3bd7a1ef48e14f97503e6c0b2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFx</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga0411b97bcc13d604e738a28aee43bb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxInstrument</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gabe030351fd22d14dad35c817e1849f59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxInstrumentExternal</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga21938bb5dc145f05b8a08669e7a74be5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxSpatial</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf5d6ce751eff5e1825c2e9cbf6de68a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxGenerator</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga09060af560cf34b87e14d5dbd839ad52</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxMastering</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga80ed69d85e565772a138ead6b8feff70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxModulation</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf7fec6a731df379ba73e26bcd72d6f9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxPitchShift</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga2b2725f60cbf68e604c85b125937f553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxRestoration</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf2357711fdb99757b6fd3248cbc4ac15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxReverb</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae45eb21e5afa4a9b2a4e5c789fcac18d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxSurround</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gad51565b155d38402b8660fca0d78927f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxTools</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga610bd26a1a9c791feeb94c3a01b85a3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxNetwork</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1644feff4e06fa14952bf64ee211003f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrument</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga93cb7a7100ac96cfafceb6216770c42d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentDrum</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gadf01865c24020885cb974f200403351c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSampler</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1a96d4882dec6d6cc809c6881456dafa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSynth</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga42c97cd14b97a2ea3052cc62ecc833f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSynthSampler</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa63699396d2e24978ad7a0f32f1a7187</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentExternal</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf0e00ca5cee8c5b4319fb7789bb4b919</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSpatial</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa334568999d986b4e50627646e51a8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSpatialFx</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga9439d03e5e14fb7a35976d2e37f34e31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOnlyRealTime</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae58eb0aafa16197f12c1a61428fd5584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOnlyOfflineProcess</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga0181f4f0a361e99c4afa139b47e3642d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNoOfflineProcess</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1e894c4b97ff99e52706cf3a67c35627</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUpDownMix</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga9b7a9613e51e1f218461d3167dd50306</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAnalyzer</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gadbe2a7d21efd81fbae4bb86fa428e900</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMono</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gad515322344056aab9256d76a6787eb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStereo</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae8acdf9398f33322690596dc2d00318f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSurround</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga6e4cc6e531ad93aa1d60021b82dcdbe9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstautomationstate.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstautomationstate_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">pluginterfaces/vst/vsttypes.h</includes>
    <class kind="class">Steinberg::Vst::IAutomationState</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstchannelcontextinfo.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstchannelcontextinfo_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">pluginterfaces/vst/vsttypes.h</includes>
    <includes id="ivstattributes_8h" name="ivstattributes.h" local="yes" imported="no">pluginterfaces/vst/ivstattributes.h</includes>
    <class kind="class">Steinberg::Vst::ChannelContext::IInfoListener</class>
    <namespace>Steinberg::Vst</namespace>
    <namespace>Steinberg::Vst::ChannelContext</namespace>
    <member kind="typedef">
      <type>uint32</type>
      <name>ColorSpec</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a5b13d028fba1eee386ec9ac208c6238d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint8</type>
      <name>ColorComponent</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>af1189c83b63820c6ccc3167402601fea</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ChannelPluginLocation</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168af</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPreVolumeFader</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168afa21f636e119b96f85db893e981c6d0fbb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPostVolumeFader</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168afa352f87b06111d7eb4502ca8884ba1bfb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUsedAsPanner</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168afab4d561ce249fb47b1411e92455468810</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetBlue</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a641c048e19cbdf7b753446f6e06b92e9</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetGreen</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a85a872d79e8879f75593a51a62e3c61b</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetRed</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a0631a9689c90dab1e9267681bc3d351a</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetAlpha</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a59f0bbea32d4ae966062be29a76bd969</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelUIDKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a68ad60e2a9bdcefda0e2296e7f9296f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelUIDLengthKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>af44825ca23e7c673682f438d8cf6283e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelNameKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a355d0e3fe55ba9c58ebe6cb29cf27ce5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelNameLengthKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a175778add2bfeafd5b184f4e47869e80</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelColorKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a218d5777a06f7780c7ded2a14c9f2922</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a42930b877ebbb27bf3daa78d02780be1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexNamespaceOrderKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>acd822b1c74f9c7e9afaa16b0ce578f7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexNamespaceKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a9dee889cb7b726bf9bf9f21c79334261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexNamespaceLengthKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a9b082b198abef61a8397bafcf4e30a72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelImageKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a6ba9324db0a3f814e6f41df444e0f7e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelPluginLocationKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a1836e6445deeff80efc1d389b8ba7ac5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstcomponent.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstcomponent_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="struct">Steinberg::Vst::BusInfo</class>
    <class kind="struct">Steinberg::Vst::RoutingInfo</class>
    <class kind="class">Steinberg::Vst::IComponent</class>
    <namespace>Steinberg::Vst</namespace>
    <member kind="define">
      <type>#define</type>
      <name>BEGIN_FACTORY_DEF</name>
      <anchorfile>ivstcomponent_8h.html</anchorfile>
      <anchor>a777e41b5a2df0f7e836856644a5982d3</anchor>
      <arglist>(vendor, url, email)</arglist>
    </member>
    <member kind="enumeration">
      <name>MediaTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga576e5da9bdc49812cf65f803bb303ad5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAudio</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5aacc820a81fe3b4e8045b839cca0b91d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEvent</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5ae6a97de99980aeac9312e818af337d6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumMediaTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5a803eb569c99a15c09609562d83577cfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>BusDirections</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga48a6eea2da1c202231eb653f3f764af2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInput</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga48a6eea2da1c202231eb653f3f764af2aa3512d23926af0e0dad8c3293443d04c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOutput</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga48a6eea2da1c202231eb653f3f764af2a1aeceb4d8bf67a4d84e082604da2cffd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>BusTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga4849e8fa0da1b39bd3e0af87b441675a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kMain</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga4849e8fa0da1b39bd3e0af87b441675aa388e1f905d2b8eb0f734c83d9356885b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAux</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga4849e8fa0da1b39bd3e0af87b441675aa0aedfd6f0f992c45d4f3620c9445292e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IoModes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSimple</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554ea66def9a432bacb7d44369f4694d38fc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAdvanced</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554ea9419e79f15763b134e99b963cad57fab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOfflineProcessing</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554ea069611c39f2a76f05446198e47ac9e35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const int32</type>
      <name>kDefaultFactoryFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a45d3e3dfb2fb99bbc186e4d9749f04ed</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstcontextmenu.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstcontextmenu_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="class">Steinberg::Vst::IComponentHandler3</class>
    <class kind="class">Steinberg::Vst::IContextMenuTarget</class>
    <class kind="class">Steinberg::Vst::IContextMenu</class>
    <class kind="struct">Steinberg::Vst::IContextMenu::Item</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivsteditcontroller.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivsteditcontroller_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="struct">Steinberg::Vst::ParameterInfo</class>
    <class kind="class">Steinberg::Vst::IComponentHandler</class>
    <class kind="class">Steinberg::Vst::IComponentHandler2</class>
    <class kind="class">Steinberg::Vst::IEditController</class>
    <class kind="class">Steinberg::Vst::IEditController2</class>
    <class kind="class">Steinberg::Vst::IMidiMapping</class>
    <class kind="class">Steinberg::Vst::IEditControllerHostEditing</class>
    <namespace>Steinberg::Vst</namespace>
    <namespace>Steinberg::Vst::ViewType</namespace>
    <member kind="typedef">
      <type>int32</type>
      <name>KnobMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a98965411c9e542b7c2a99a46c8c1dfa2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>RestartFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kReloadComponent</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a22ef5ace2e53c785283a595b6add28b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIoChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a47642f19b6da08e1bea896b6e06e630b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kParamValuesChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a67a358277112f9c5ac816474ae501a09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLatencyChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a560af1d548105a5e1c72f07a1b6fbd29</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kParamTitlesChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5af5308f6f5d92e718ccbd4cb0ca414907</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kMidiCCAssignmentChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5ae2e3ed4527f88e577a2aeb595bd853fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteExpressionChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5aa11fe6e24349c6d2f7e0035dbc01c10b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIoTitlesChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5abf3d2b0a3519f44507b88691c0e6555e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPrefetchableSupportChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a2f4bc9de12259020c78fa4225f1d90b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>KnobModes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCircularMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39a261944b6b143c6fc78fa1e9c783200ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRelativCircularMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39a98a7d7b1f331414876a55df149340e1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLinearMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39a248b4aaa79db639d5610c6e632269d7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEditor</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ViewType.html</anchorfile>
      <anchor>aaa62c4c32f0270a908eb20c7c7124dfc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstevents.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstevents_8h</filename>
    <includes id="ivstprocesscontext_8h" name="ivstprocesscontext.h" local="yes" imported="no">pluginterfaces/vst/ivstprocesscontext.h</includes>
    <includes id="ivstnoteexpression_8h" name="ivstnoteexpression.h" local="yes" imported="no">pluginterfaces/vst/ivstnoteexpression.h</includes>
    <class kind="struct">Steinberg::Vst::NoteOnEvent</class>
    <class kind="struct">Steinberg::Vst::NoteOffEvent</class>
    <class kind="struct">Steinberg::Vst::DataEvent</class>
    <class kind="struct">Steinberg::Vst::PolyPressureEvent</class>
    <class kind="struct">Steinberg::Vst::ChordEvent</class>
    <class kind="struct">Steinberg::Vst::ScaleEvent</class>
    <class kind="struct">Steinberg::Vst::Event</class>
    <class kind="class">Steinberg::Vst::IEventList</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivsthostapplication.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivsthostapplication_8h</filename>
    <includes id="ivstmessage_8h" name="ivstmessage.h" local="yes" imported="no">pluginterfaces/vst/ivstmessage.h</includes>
    <class kind="class">Steinberg::Vst::IHostApplication</class>
    <class kind="class">Steinberg::Vst::IVst3ToVst2Wrapper</class>
    <class kind="class">Steinberg::Vst::IVst3ToAUWrapper</class>
    <namespace>Steinberg::Vst</namespace>
    <member kind="function">
      <type>IMessage *</type>
      <name>allocateMessage</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a80587fa5437b07a138473ce70d3b7dda</anchor>
      <arglist>(IHostApplication *host)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstinterappaudio.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstinterappaudio_8h</filename>
    <class kind="class">Steinberg::Vst::IInterAppAudioHost</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioConnectionNotification</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioPresetManager</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstmessage.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstmessage_8h</filename>
    <includes id="ivstattributes_8h" name="ivstattributes.h" local="yes" imported="no">pluginterfaces/vst/ivstattributes.h</includes>
    <class kind="class">Steinberg::Vst::IMessage</class>
    <class kind="class">Steinberg::Vst::IConnectionPoint</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstmidicontrollers.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstmidicontrollers_8h</filename>
    <namespace>Steinberg::Vst</namespace>
    <member kind="enumeration">
      <name>ControllerNumbers</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBankSelectMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a400f9814a81c3cf0116c43434527a9b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlModWheel</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab9b1ff6e499682378110ba27ecdc0ef7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBreath</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a1a2c7165ea14ef8dd1368b6816eb2a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlFoot</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a9d0c8ad268af6aab096688928d2bf649</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPortaTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a3bd68e966f818c58396b3132c9b63146</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataEntryMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a1b7add291c074e6e281251bcacd386c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVolume</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a6a0386205b02a353f63eecc7b80688bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBalance</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a9db5606058725c95d7196bba2d0177cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPan</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a337d918eada6158b59bfca78fc6d4ce9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlExpression</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab9ded45859a4edeefb3f2c01c9bac04e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEffect1</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a223f411fa52e53c3ffd88031f2fcb359</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEffect2</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6acf538d0974d6427c61c3413b70bca9ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC1</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a53873b95c93a8a77720d0d86b2521afe</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC2</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ae2b54af4acafdabff72856fa0a2c21ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC3</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a619824c5021185046074a448dd2e1127</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC4</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a30724a1acbad4a35c4230d7b10ee5a5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBankSelectLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a04b8b07db0548b0419d9dfb3837ac140</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataEntryLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a94cfcf6be1a8525ce88b91a91b244001</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSustainOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a0f14ef4f47d122dd1f90179172798282</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPortaOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6afa5ea23fcf3bf9743c9c6565db31a9d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSustenutoOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a94bff95bfd75ce9c2afeae7e710a1f0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSoftPedalOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a7d6db0586803346d573647dd0f5c7d78</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlLegatoFootSwOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a3edac2ceee92969eae4c563b36a572c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlHold2OnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a2232d72f0d853ffd05502341446b6d9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSoundVariation</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a6ac02b45ad9fc7b0a06dbcb4b08d85e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlFilterCutoff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a0ffab21c076973287ee7989e951417a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlReleaseTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ae5def59ca1557626e92f98eba6bf677f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlAttackTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a415800319591ef39bb63da5d59c7b609</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlFilterResonance</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a461337f50eaa0cab0db2b3be464da521</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDecayTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a755907d022d33579f41ab3510c4a1e06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVibratoRate</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af7ef2c4385b727d4c937dab21e85f2ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVibratoDepth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a60de4c6db5a2ecc8696ef8a74c2d0604</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVibratoDelay</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab1c1e0685fcc46278fafff8036837bba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSoundCtrler10</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a35b80c1718f6464668b96df696efa264</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC5</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa88e418292a29bb46e148ab9dc999d4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC6</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a6c72ad975c1231c1657260fc7954b27e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC7</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a76823c9e4b6f55bd74b71096f1e7cb09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC8</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aede48ecdceaf4750c38194df4e3650d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPortaControl</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa56335dc1a7f013a779d79a2b0766260</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff1Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a215884f32ff11d44c0b26f641491d4f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff2Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a8c5c17883f573d79cfb912b8c18ddf86</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff3Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a93eb781dc5c8d3b0f3259da87ec7bd5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff4Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa1f3100a751b3bd3c521414eb4de9c09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff5Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a34db4b2b6bf408977eb0889be68dbacb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataIncrement</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a8054b74403fa8ea7932e2a28aa4ef570</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataDecrement</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a68ef732ce338bae442a4bb5214ddb1d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlNRPNSelectLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af71bc8cfbfd46ba99c8dd6c9b3c098b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlNRPNSelectMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a16c5df1bc05e33ee2568b6b903a4835a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlRPNSelectLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab1839eb3b7fd6e17a404d5c549647fcb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlRPNSelectMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ada4d74f05c77dc221713a293440695d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlAllSoundsOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af6d59e256dc288cf9012d8e14af1dd72</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlResetAllCtrlers</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a3ca0d4037f837edff5a519d759a6e2a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlLocalCtrlOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa2e16c34abda2b690c0ce04f71fba7ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlAllNotesOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ad27b2651ac1b6c1bedd2932fd7ceea1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlOmniModeOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ad98437cf5dc4611e63d7541e8de2767d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlOmniModeOn</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa6ecf7983324f4f64f82e49847306573</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPolyModeOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aca03cffe46b62bd2c4aab05493e73bb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPolyModeOn</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a9d27c8af6ca2742411edac39853d4063</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAfterTouch</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a999df7727e25b9ef9062b19f91a26cbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPitchBend</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a39b06e8637d7c40f7a845d1c191f6d8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCountCtrlNumber</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af6ba8b5a08c0e4e7c4d8f6603df78bd5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstnoteexpression.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstnoteexpression_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="struct">Steinberg::Vst::NoteExpressionValueDescription</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionValueEvent</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionTextEvent</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionTypeInfo</class>
    <class kind="class">Steinberg::Vst::INoteExpressionController</class>
    <class kind="struct">Steinberg::Vst::KeyswitchInfo</class>
    <class kind="class">Steinberg::Vst::IKeyswitchController</class>
    <namespace>Steinberg::Vst</namespace>
    <member kind="typedef">
      <type>uint32</type>
      <name>NoteExpressionTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a1f6dd3f1f6742382e7301c1db5587a4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>NoteExpressionValue</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a9e134142463a8ca477018e7f2c3220f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>KeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a62cc12c76af32650e16a6920962ddbf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>NoteExpressionTypeIDs</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVolumeTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa18860e42c73ce4d8d66d49d6a662ab56</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPanTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa7148e2b1e53d751df8801134fa2059f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kTuningTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fac196000d5497502327e2b4f69e5037be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVibratoTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa9fadf3f8d95dee835c8a0dcc9605b5af</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kExpressionTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa5e7ae2b2c476af4e9cdfd62902d68880</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kBrightnessTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa3eb020a0ad7005b2be7b70e373cc4431</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kTextTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa77f4a0bbec04c57e50441d58dddc753e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPhonemeTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa4ebd202862aff5265a6c1bcd901bd5b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCustomStart</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa1c30475ef992f89f37c2fe0aafcc6283</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>KeyswitchTypeIDs</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteOnKeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2a19aaecc29b830ac94b9804b3f6b1aebb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOnTheFlyKeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2a585a87fa2b02e4aaf5e3280df2bb41c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOnReleaseKeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2a0e2daa9cc892408b666cfdda855652c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kKeyRangeTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2abf9a3d392f6bd3ad7f0db013fd5dbc18</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstparameterchanges.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstparameterchanges_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="class">Steinberg::Vst::IParamValueQueue</class>
    <class kind="class">Steinberg::Vst::IParameterChanges</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstplugview.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstplugview_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="class">Steinberg::Vst::IParameterFinder</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstprefetchablesupport.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstprefetchablesupport_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">pluginterfaces/vst/vsttypes.h</includes>
    <includes id="ivstattributes_8h" name="ivstattributes.h" local="yes" imported="no">pluginterfaces/vst/ivstattributes.h</includes>
    <class kind="class">Steinberg::Vst::IPrefetchableSupport</class>
    <namespace>Steinberg::Vst</namespace>
    <member kind="typedef">
      <type>uint32</type>
      <name>PrefetchableSupport</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a8cd3dd5ea75e76ace81fd1a696544378</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ePrefetchableSupport</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsNeverPrefetchable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5a056d564a22f73e4649c99e1407a7585a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsYetPrefetchable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5aa43449cf5a0e596fa81b4a8498404f3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsNotYetPrefetchable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5a836dd1dc4f2a6ad88f87dd23cb0cbed6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumPrefetchableSupport</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5a24f726f3f3303a115cf6755b6df6c984</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstprocesscontext.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstprocesscontext_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="struct">Steinberg::Vst::FrameRate</class>
    <class kind="struct">Steinberg::Vst::Chord</class>
    <class kind="struct">Steinberg::Vst::ProcessContext</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>ivstrepresentation.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstrepresentation_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">pluginterfaces/vst/vsttypes.h</includes>
    <class kind="struct">Steinberg::Vst::RepresentationInfo</class>
    <class kind="class">Steinberg::Vst::IXmlRepresentationController</class>
    <namespace>Steinberg::Vst</namespace>
    <namespace>Steinberg::Vst::LayerType</namespace>
    <namespace>Steinberg::Vst::CurveType</namespace>
    <namespace>Steinberg::Vst::Attributes</namespace>
    <namespace>Steinberg::Vst::AttributesFunction</namespace>
    <namespace>Steinberg::Vst::AttributesStyle</namespace>
    <namespace>Steinberg::Vst::AttributesFlags</namespace>
    <member kind="define">
      <type>#define</type>
      <name>ROOTXML_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ad54c84678ca7e4ea9bb1159937436ff7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>COMMENT_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a52406a72fd0a2b4c0ea8e21e64083e3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CELL_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>af7a8d566c74f0a8425719114726b5dad</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CELLGROUP_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a26cf63d1632fb39912d0e6f7ef07776c</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CELLGROUPTEMPLATE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a0b67fcc8fdc102b43739731a1a4ed78a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CURVE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a75489eb37cac59460f44b8727ad2e9cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CURVETEMPLATE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a1292817e812b0012515e688ec13f276a</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DATE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a1f214170189173699f7b0ff4882f6300</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>LAYER_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ae9bb7fe3c8a5619a8a69a878a93cf053</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NAME_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a779bf02438888966f300fec40e088460</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ORIGINATOR_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>acb61e54e67a5a4847409bc4dfac2ffed</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PAGE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a59d44d7816c352100b7878c78eef424f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PAGETEMPLATE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a4c17cdb820810b06035ae875785ed8e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PLUGIN_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a36de320a5b0bada4cc045fc4fa55bce1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VALUE_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a747c80e9284ee593d9ce66f401e02345</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VALUEDISPLAY_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a8e4b999c47811dc211512bef5a92cec1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VALUELIST_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a790b90e20c11c052224362eb63dd6163</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>REPRESENTATION_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a1a019680fa393178818b157c21e29e28</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SEGMENT_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a570a4c08c415c55b57cef39fdabd3d22</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SEGMENTLIST_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a0f9873521d3416cbab754674efe85fec</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TITLEDISPLAY_TAG</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a53bd192ecfa746b168157c152f4dc34f</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_CATEGORY</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a329d3d2a27b8eacb050108da2f245423</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_CLASSID</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>aded6ca4574f3b22d2066cacb965f43ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_ENDPOINT</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ac8d1925c02f1207a0950611780e9262b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_INDEX</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ad616e16921da6a49a1bf519382e13245</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_FLAGS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ad2cd1c62113ed5e6c2e203d775ff338e</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_FUNCTION</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a9590a0c2004f425fccaf4c7e6ff7a2e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_HOST</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a4764dcdc2c0ac222bc2d0201b3acdca3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_LEDSTYLE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a954a36a2f03aae6010bfdd41c6da6972</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_LENGTH</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>accb6f184e609fc7fdc54ab62bfbac668</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_LINKEDTO</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ad16b8c3427dd375982dab3351f290d64</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_NAME</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a27fac62d5225fbd8f6f291b31fb7fb31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_ORDER</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ac4d68af01dcd4cfe84a0aa5b20d98194</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_PAGE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a6022fba1ba60768521d1fa0220469fd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_PARAMID</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a9d84498cdde3f98a22921bb9a923a474</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_STARTPOINT</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>aa1aebab1d267d4313b62991825ba8bf7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_STYLE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a387a251eaff4cd190247e642085fd96b</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_SWITCHSTYLE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ae524b0dbacda1e219ba64fd7be3ad6b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_TEMPLATE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>afa1103a0e4a646b28c535eb414ce4a51</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_TURNSPERFULLRANGE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a055c0598a38e2d851f599662ea4cd4c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_TYPE</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a812c1f8229033599f1e1fae7507c3317</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_UNITID</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>aaace784181400f00d657fd704f4b2940</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_VARIABLES</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a7baafba36b08b9bd80c2553be19e8ed1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_VENDOR</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a9bd6fb709bf8af52e045c0b892e3d567</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ATTR_VERSION</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>adf66b0f3c145cbff18e6eb7755cfee62</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GENERIC</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ac08cb533186434b5fc055cc0c72f8ef6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GENERIC_4_CELLS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ab8f4e746b0ac3234768751532fb4bbd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GENERIC_8_CELLS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>ac779df483213191a931a8492179dd1d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GENERIC_12_CELLS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a77c96b76aa184f810a9fb79631d5e725</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GENERIC_24_CELLS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>af99abe7f0c38cdafd01bd2102f9a5abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>GENERIC_N_CELLS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>aab48ed7abf8b84ed7365d8003402b208</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>QUICK_CONTROL_8_CELLS</name>
      <anchorfile>ivstrepresentation_8h.html</anchorfile>
      <anchor>a65f00cb7a5653e3c834c7f07ad1e8a37</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kKnob</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9eaed465fd2dd47fea2b560392552bf65a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPressedKnob</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea8c1ff139254d93782be7eaec45059110</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwitchKnob</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea75d5f413c5b9d0337515c307a5e10dcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwitch</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9eaaa243fb2b8aff16421d89868c811958a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLED</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea125690f72eb0478f1b83b9f17dc7c431</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLink</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ead5309d363b060cc3481f6e021b26f0d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDisplay</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea1c1b7a564dd807a7c1c4cffb88d8b100</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kFader</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9eae6364790e7803e2a147b5abeb9554c70</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEndOfLayerType</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea9a9bc943010bbc1e4d0df5442fd1612e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSegment</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1CurveType.html</anchorfile>
      <anchor>a01b326e51dd2497b0b1e4b3bb40f478d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kValueList</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1CurveType.html</anchorfile>
      <anchor>a8bfce81e77d68274fe7093871d1c7d5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>ac45345491383374f12e9e5a8835ef584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a9778507c4f8a0e63627745ba122e7355</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a69491a10333660073039f48933b19169</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKnobTurnsPerFullRange</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a94ab8536a4938e752a0831641d204bb4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFunction</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a085c04012e24b75391893fdc08a14212</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a55d73164cab645ef625b0906c5fd9b7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosCenterXFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>abc31d751bd54d024fb1d6a3a44c28972</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosCenterYFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a4bedaf7a553a7225d33b44e17392aa14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontLeftXFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a6124b199a105d4f0e924e5a2bab5916c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontLeftYFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>ad62884d321a9c158a652171f28966391</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontRightXFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a92ffcca6b5f41a5cbc0a8114f6207eb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontRightYFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>aca1665ab0b3971f5a0d77c4f80dbd08c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanRotationFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>af22d8c74678d445a5f8339261e960dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanLawFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>afb97a4db6eec1e1220525a26b21cb306</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanMirrorModeFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>add1e67399eb35139cf8142d892abe3f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanLfeGainFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>ac5774ffde117ba66d042211939fc92e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGainReductionFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a754bbe4a40d9ea477213c8d0f3a33011</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoloFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a561acb1a41d0b9c03050f3b33be9f6d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMuteFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a2714bad0648841cb021603303fb2cd17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVolumeFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>aa50a92256981837b639d8683d6cd65ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInverseStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>afdd9a4e103915db68761ddaf0ffb4aab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDWrapLeftStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a08381b7f0862de9edee14226b4540663</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDWrapRightStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>aa0c11f1f96f6ee66dce6b52513bb8d27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDSpreadStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a078a1072f0a79bf6dda79f84a83c7dd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDBoostCutStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a4a6426db9e25591301b5005332235884</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDSingleDotStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>af203ee426ecc4ffb31c7309a392ef807</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a0f25d2df1a1539b11c9cd5f4ea9ac1c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushIncLoopedStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>ab9e1b3d53a0bdb4735378bcabd135c00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushDecLoopedStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a7957b8090f444415be702a9a00375037</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushIncStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a2c044da4242800ee2b02a2b548cefca8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushDecStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a06b11bddeef4219b4d959f38570b58f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchLatchStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>ae91fd6e9d7298b55b0c73577db874f72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kHideableFlag</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFlags.html</anchorfile>
      <anchor>a802846cc44b7ee60a8f88e7deb81e7b6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ivstunits.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>ivstunits_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <class kind="struct">Steinberg::Vst::UnitInfo</class>
    <class kind="struct">Steinberg::Vst::ProgramListInfo</class>
    <class kind="class">Steinberg::Vst::IUnitHandler</class>
    <class kind="class">Steinberg::Vst::IUnitHandler2</class>
    <class kind="class">Steinberg::Vst::IUnitInfo</class>
    <class kind="class">Steinberg::Vst::IProgramListData</class>
    <class kind="class">Steinberg::Vst::IUnitData</class>
    <namespace>Steinberg::Vst</namespace>
  </compound>
  <compound kind="file">
    <name>vstpresetkeys.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>vstpresetkeys_8h</filename>
    <includes id="vsttypes_8h" name="vsttypes.h" local="yes" imported="no">vsttypes.h</includes>
    <namespace>Steinberg::Vst</namespace>
    <namespace>Steinberg::Vst::PresetAttributes</namespace>
    <namespace>Steinberg::Vst::StateType</namespace>
    <namespace>Steinberg::Vst::MusicalInstrument</namespace>
    <namespace>Steinberg::Vst::MusicalStyle</namespace>
    <namespace>Steinberg::Vst::MusicalCharacter</namespace>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlugInName</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gacbad3647c9f27b2777cb6a3cd24fe49e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlugInCategory</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga56f939f21fb570350d3360b1e7254245</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrument</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga93cb7a7100ac96cfafceb6216770c42d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStyle</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gac45345491383374f12e9e5a8835ef584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCharacter</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga166d8e939e25f23c6e1c5125e89d5f13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStateType</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gaefefe46f30651266cc9ccc8908409552</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFilePathStringType</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gad5fe1f71ae69e7b4daaf0e79130930c3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kProject</name>
      <anchorfile>group__stateType.html</anchorfile>
      <anchor>ga89eaf816243da36726dfe2656c266a4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDefault</name>
      <anchorfile>group__stateType.html</anchorfile>
      <anchor>ga4f34c8d0372a9d06a2713fd488ece66e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5bd8958e2d10a39961b9ac9d20ac1a3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionAccordion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4b3a7ca0aed4fd75c4c6de9da2c095b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionHarmonica</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga13f91d403c87da4936308cd2f94b3dce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga3f7c44f705388a781d442009341b50aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga99ad41c498b2d37a379907989842655a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassABass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7806c7198452bd9b38813e1254bffdde</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassEBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga722ff7ac1ffb92a922ef3f562117327f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassSynthBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabbbabe9b591bdfbc9e8613220d7ce829</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1835577b20a8f992869f11555b9c6c43</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaccf4a6cc04deede6234aa80f17494e62</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassFrenchHorn</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1a4ba62937d8347b92bd6a7fe2f0f203</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTrumpet</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga58aa80b0a42ce48f7868095cbf8af4af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTrombone</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1f2c119eb1f5ed7687375950e64a099a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTuba</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1e4a49eeaaedbf8487070bf20a06b119</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassSection</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae7c3bd91d4fb0872ab7db0ed74d91445</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassSynth</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0cc2d58842ce2dcad93a3f83a777a67d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae4e52f708efde91cf0f2a78cebbd351c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPerc</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5f48d90dba2837a9b0552446258746c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercBell</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7b4edfeeda6a06123409b3e5d704bd0c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercMallett</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaeee07c58574e18dd64d3be93f7088a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercWood</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga492b01fbc86bdb5131f84dcdb5f26f06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercPercussion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0e5caac1dbaa9755fdb06e89ed3b3895</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercTimpani</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga11ef28f0a9918a82c981b1fb8025bd8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga12eb4bbef0c030bbca1e861adc773334</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPerc</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabe15c8ed2a76ff3c9f9029278854dbef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumsetGM</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa41f951f74e972f53aab1a45d15c54aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumset</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9ea452ccf895de2e9a647aa85d40b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumMenues</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa441a52dd98f3b53affbc538eda46521</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercBeats</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5c77bf645fdb2afae554c3c6b48dc92</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercPercussion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga351f0ed74b2185f5acc3460021c203a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercKickDrum</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf85c8e569ae8d22ab2c233006a99f82e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercSnareDrum</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga13fca99a8c4598a5f66ef87242f70b27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercToms</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac756e1798f6f8ce4eed78adafcd6f8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercHiHats</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gadec30a0adbbd248d6573f64342feef77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercCymbals</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga82ee2aad1a847aea7c803b81a4d2598b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8dbf5e607efc62bfd0fb4044a943c399</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa946206a3ecfcc3423ea307de5efdd13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAsian</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga81ca43ff51517679540bbabce3f89254</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAfrican</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5de2bf50670628599940b4afba85fba1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicEuropean</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga841f031104f1230a568fb7246eb87fe0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicLatin</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8b04cbbaa98e561e20b7a966f58e9281</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAmerican</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga3c6dcb9ae2464cf7012aadb328c73fdb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAlien</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga86aa661200c00f7b44935e455d62b5f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga89d49bfa58ca9659367217ea187bd7bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga642a844eb43638962aec00dda572b724</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarAGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf907f1b0c6b112a7a7ef2c26d181345b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarEGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5bd16506f3db8c7cada37ac1030fdeec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarHarp</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga6077d4646f9ce2fcd14f40ee5f1fcfce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabac2c7c2f88a2511bcb9536a62847e64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga91eddfe8e8f1e826c887b57971600988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboard</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae87c28eecf427576aaba8dba45506307</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardClavi</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabeb1f764cd854f5f7b107a8f0b1fd4ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardEPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga326410320556a12f64c20f88c19373ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardHarpsichord</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga02d58cfc1dd6afe263d10ed615eb0d2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga20c97efa4d9bc8307bbd0375035c34ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2390a2a94e9904517ec9342ab0019fe7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXHitsStabs</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7827735f5bb526019207c524f487af0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXMotion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab9114e6b0673188dc5228aed3d3df2da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXSweeps</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf3cb2d886c19f654e5d4d8b25eb5477e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXBeepsBlips</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5378d54b89a50f2b659f4811d2925cc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXScratches</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gacbe3eb6871b48061d2c046d8b258a7a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5e9cb190b3c45ca56bb2e1adebb43fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrgan</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga84fec6760fef802a323b692a062b55b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganElectric</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2ec0df01bea69ecba86f5d891b1ad648</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganPipe</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga79ae6538d284af4c29bbd7cf4933b76e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga20f011a1e399ecacdb0e6e1cb7196e64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga41cb875c197b4036cc5ac03ca3721a08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoAPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4ad2adf116f63f68c278860b4d1d1f6d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoEGrand</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga37d4c3eca4f4d9c151ffa65609c79439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1af05a3bfb82be1b619388c384a6bf2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf2a091ea57274b72699e9f9df7715b17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXNature</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gad21b480ba2888b09f222c703fbb37a91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXMechanical</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8f75ccb3769fa4876436c45a09107fcd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXSynthetic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga341e53ab2df394405b3785850dad88e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaae916a5a813ecf7d856e61f456a24479</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStrings</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaafd56235b0b917a43d284202d30f4f0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsViolin</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf8cf7e44674db2aca92f56fd73f92006</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsViola</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9aa9476acbba419210667d658afabc6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsCello</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga265f017e0f464df3d4141dc319eff0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae18de76efc605860475b6323ef233cc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsSection</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac1d32b8a87a1fd03f9c1015160d7d3b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsSynth</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga51a61e68eba9a1cf51ad89242b9bc47f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab44336cb32a2e361969b84be167c6437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLead</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga65f99d06e1cdec2a31ced94c3e74e2b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8a11629221f0398068c261f7e82dbb3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5593b90f0b783f8c474534b1bfdece81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadArpeggio</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9f07e312d4b567cbeb9afc62663e799d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1baec415d4b38bfc63bfe37d4d8f998e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPad</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga09ada6780ac854e1a5f5fdeaeed3fb98</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadSynthChoir</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga459f7a40ee5ce2589b9c5b4e9a7dbc03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gafd8251cd1e2beb471fb880eff54122a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0624ae2a566ded387d13aa9b42b02e4f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadMotion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabb14045ba365551baf7d248ea496f627</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga21365983f34c81eb766d77a9f6c56542</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthComp</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac5ee81e33b8952b205664d8a7e6d3726</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga98b124c4c95e7d1f055a878c293036a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga58fd32018d0d25fa22a065fe293e4079</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab2577b8dac71b9e6d679cd5fd337fc70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocal</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2d5f12d8f479275a1ec1047877ad12f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalLeadVocal</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga33b0df9f2de9caa850ec8f42a690ea1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalAdlibs</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaeb469e5850a09e7863b3a411bd839185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalChoir</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf1c302e30ac59f819c846264553cbb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalSolo</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9fee846e3dac6a9c76f49236370104ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga01a286aebf174524ce6806266da52608</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalSpoken</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gad3c91ff5b7e51b5ed71479994af1f2b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga97b0787f7bc7a12d8aa9c451626252df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwinds</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab6f7ddec4db62d879f3d4147da295e5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4c985b65f095bd5bf25adb95490c26ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsFlute</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1b594039765ec814407ab25b574177e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsOboe</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga40a881c8d3a7bc7f6688195400ba35dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsEnglHorn</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaab8ddc7cc6aa5f6c1b3383b7ba109c65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsClarinet</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga76398345f57877810ceeb6db295a08a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsSaxophone</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga685ce7454b4f454c4f2e36b40d215fab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsBassoon</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa7909c8fc3a72ec802f1163f7bf78a1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga850425dd3f6d9938ccbbee6158316bbc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndie</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2283c2c777c7cbb21710e11ef2ceb6af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieGothRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5efb4dfb4fef27ded5062173093bbaa1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieGrunge</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga611a7833ad99ac643e6662ad0c735437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieNewWave</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0d9c9e5d1d7762b13270a0cd388b2d7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndiePunk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2b8b2179cf8d2b74f6c0eb2abb563a80</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieCollegeRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8881386092fc55d2c4ed31ca0d3acd22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieDarkWave</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4e60a460c89c2aa3f05c8e15c4a74b76</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieHardcore</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga080e7eebf7cfeef648604aab356d9249</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOut</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa5aa1cc4f7a5cf8fbcb025f426225676</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutNewAgeMeditation</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab17d3d9dbddf245300a0e581f27d2b21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutDarkAmbient</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga33320722a4e37a0dbe61f8957a77fcb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutDowntempo</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5af88b6815b44014176a2bf68aabca6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutLounge</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1abdca80184a162d425c61f053530dea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga070e85734aa0ebd786f2c8ff8dca8301</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesAcousticBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga427cc44ab600473801a7d50bef343e2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesCountryBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3ccf2f159b7b1becbe0d64f4688f7f4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesElectricBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga60c65b0575b241924ccfcc59fa7dccaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesChicagoBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5043e48daf7d4433d082c9d726b90a2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassical</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga00100f8944908f3f674b077b8e7bf5ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalBaroque</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga54a477d7f94dacdfa325bdf693d180ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalChamberMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga817fef9aabf571d6f91e357efc677040</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalMedieval</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaabb6cafa41915dc3a4ebb19d35aeb3be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalModernComposition</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa61b32582345fd12bd9d2140c174a25f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalOpera</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaaa8a189a2e24961319d1e26349aa8a9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalGregorian</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabd559febaa875cac883dc20517965d19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalRenaissance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8f9739caabbf232d50b1b1b449ab1491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalClassic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1a1b8c73dee78995dfc73a9cbe1855fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalRomantic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad822300e6782c9fc490f073c880403ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalSoundtrack</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad28cde471461898b52b6cd7aefe1fad9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountry</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaaa2fa8f51e39b78604c752001cbef8c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryCountryWestern</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga613bd6f52125a615d0e1bef58463e6cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryHonkyTonk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac05e574ca2ece383b72b5ee429506988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryUrbanCowboy</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabc94ae94e43d1ae9a453f5033f2f6bf4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryBluegrass</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga56cc1195da3ec7bc16d67a303c489c6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryAmericana</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8a240fc37b335deb7063b9bbf959ba90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountrySquaredance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7b9a2584ff4f1501c9a24a8754f1f526</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryNorthAmericanFolk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1578d35d598b30c1a8aca33c94e33213</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga9e3c1f6becf1b50e07e2d8212fadea0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceMinimal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2acd1ccf8c493d7055288674c243e7f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceClassicHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad2581a6189feb88d716b6c81c5efa79b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElektroHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad6c238193c96a2f320bb158fc0cb36b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceFunkyHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac697bd7d2476a3f522e0c12f4f9096c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceIndustrial</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga43aa90fa2a5718ec3f233186bef3b745</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElectronicBodyMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4c9fd026e505a151e4ebcb41a026a273</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTripHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga27a783d5bce0708e88414cd4de0ffc3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTechno</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga66d567db513649b64572ec56ec721a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceDrumNBassJungle</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa1a66bada350ea5f47e8c296bd3482b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElektro</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac613b9e387a4a4e424dbdd7925a842f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTrance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae1734ba060074a2d5f5bc4aadb1b4693</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceDub</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4bf8090a24491f751c9d75218ba8ffc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceBigBeats</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga04e06e3becb8bca4036fd5856682a393</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimental</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga13e10384c541982e7ebea23ae4cc0057</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalNewMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga9d42a1c28d4a1b6e725783290a949f04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalFreeImprovisation</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga988ed6ba9f31ff90849bfe159dbb56f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalElectronicArtMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad14a4491132f9255427a1dfbb53f684a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalNoise</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6d711a097823788b80c4373b0df67287</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae80ee561e4da8da1de90835e41f0fc7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzNewOrleansJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0ade597c6d17afc9e6cf4a7bdf34de9b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzTraditionalJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6099a9381244ca72562a7b8226c619b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzOldtimeJazzDixiland</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga04fc9ede978682cf37a56876ba9dba9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzFusion</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga847f04e92eee76df8f6c6592da0cea2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzAvantgarde</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac6cbbbd37ada9f3f26657db8cc6065f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzLatinJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0ee890f05a7479865af9eda6d34bc857</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzFreeJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5fcff8a8096b40b9e05427c944a2e295</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzRagtime</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac2b3067f7b9b92ffe14a1b15b0bed83b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga92057d09ae8339165840fd850e77868d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopBritpop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga886ab03c6a77598d7e78c3a6ec922441</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga772e326e01f9245ba8a8177301a55d4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopTeenPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7e047957551e02185723581a1880086e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopChartDance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6f9e30f2b18f2f639fefbb38b1d2d3e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPop80sPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6f3a96aeedf52ae2691056c3f1535578</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopDancehall</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gafdb7e50d604be148bcab627102c66a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopDisco</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4cfb53a16c9ad176d8c2a3b9a4a267a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gade4f6c22997daaed1a372dd09b358068</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalBluesRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac1c59279027338732b37420973755dd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalClassicRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga52b06f4c922bceb8a7af486f8f9e8ead</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalHardRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab7fc6fc1b343016898c32d9095895973</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalRockRoll</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaf044a0ecefea571e16b30b82a1becf04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalSingerSongwriter</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4c7fb7c56f3573b219287833e847113c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalHeavyMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1b66689bf69717c4af8ad85835737acf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalDeathBlackMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga370c692d8ab858d11bff12c0ea4c779c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalNuMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1e43c81772b3227d2239c4c869194733</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalReggae</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab7285dab701bff67bb281688a4c1b93a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalBallad</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3e6375ad794af9ad7c9e79f61ce422de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalAlternativeRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga679697a95e28deb4eb0ab2dcdeca114a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalRockabilly</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga646cb827580fbdb5631167f300e2d7c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalThrashMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4367d681da9e6a9259373fe33bd58162</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalProgressiveRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaf74e7f4e41c15f2e271cc15b512b2fbf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRB</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad9fdad7b31d648bbf64bc2333bc3ecab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBClassic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae828f62557a162b35e08774fe73e4b59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBModern</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3089241b92ddf52d670f6339c57ff321</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga03a11de347ee7fbfa80f6040e5838c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBWestCoastHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga31d1f86b5f8a0281d2a85f7ae6e40d10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBEastCoastHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga91a0592eb755912d7fbf4b7f78387707</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBRapHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3dd2ebf4652bdc7f67e804099495ad1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBSoul</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga853a4803393e2d1684fe32e5adafcffe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBFunk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gadab3d1a08820555d8cc2eccba5a2414d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7fc43124278803213779023493bec46b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAfrica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga24447081033911845dd5279102bf075b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAsia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga09caf2a39534495b771aa65a0d969ad1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicCeltic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga17f0e511cbcdedf14156ba499a54d615</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicEurope</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabbce5b2144aac1d57742c746de8ef78b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicKlezmer</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8db09e3dd05ef85ce88a038472cc04af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicScandinavia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3ae32b316261fa76c8d7ca0e9790871f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicEasternEurope</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaff54f68acdbdbbbed6054f5c9b17ba8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicIndiaOriental</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga33a8a991563a9d73923525ddd29e79a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicNorthAmerica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3d85eb586a37b5a6082a6d1708d91592</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicSouthAmerica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaad0a8d9f7a2cef071860eee02948c556</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAustralia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae08118ff90a70fbd90e1979aa1a33c9f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMono</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gad515322344056aab9256d76a6787eb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPoly</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga020e4d1023e2b9add2c637ebf4b75a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSplit</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga51e6bf04c8aaefb4fbbc45a114f147c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLayer</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga18049d58eeecea7c6fed4f727442430d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlide</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga94f8615dad159bf66390009ad9282249</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlissando</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae0732ea96679d73e821715b2be446261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMajor</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga18f27017b00ca4612f133f4e09d913e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMinor</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaccd54b1bfad544bac2ff54cfb56d7df2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSingle</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga516ace30c1fa46e55b8767b58c77a788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEnsemble</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gadb6de4949739c48baf2613e6965d1637</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAcoustic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf589c030507665591b7e57d677b350e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectric</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa924ea59d6457adaabe92b47048253aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAnalog</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga10904a318940018e74802140f840a4cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDigital</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf8f1ad8e2c507c80b75e20d94cbef219</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVintage</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gab86682f9fb5dd5c56199feba1afadc8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kModern</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga490b8908c7977aaca4e5a7fc1983f172</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOld</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0bbfdd92cc2b2313b3cf974c5b3f9760</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNew</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8ff57c7698535ab97bfc64a7bf3ea9ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClean</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae48573356356094da60ac761ac5ac51e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDistorted</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa8427782100432cfaf837a729195f1ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDry</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae4406a55f1a7b6f1d12e29bab8f576e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kProcessed</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0bc38b1dfd75d0ae9e6137d43c29068c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kHarmonic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8f5f55f753d25fbeec874ff7c873b050</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDissonant</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga3030eff3a0900a8cca1c6266716efe1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClear</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf8c102dba19d9bafb8d7ba312f812ad7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNoisy</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa57323ce9c0b4d417c6b36aa76570514</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kThin</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8da59e92e1c2609a302663aeeffc01cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRich</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa6c4d36725eb4226e02f5724ca420e24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDark</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaae40f2e630a0d26cdd3d862761b26d07</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBright</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0796a86633dd777869721cf5f2666aa5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCold</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga7c18fd830521824296dc8412e5420559</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWarm</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gac1766654d4a9b882b9890fce9483a733</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMetallic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga644e30da9b10ac15bcd313778d00d261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWooden</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gabea2ba5e271fab4f245baffae6fc7f20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlass</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa5eee886870365dcadc1105891130025</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlastic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga62ea7670ea954e012810004bb26369fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPercussive</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gac6b35eb8d6cf9178f4b428d523760e89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoft</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga280fd77ca4f703e3509ba81e6a4a7062</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFast</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gab5face7509d33a16c6be75f042d5f56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSlow</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga196114f5b784b26e46ca975e194a12cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kShort</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8b9663df42570d3f736896b881f348f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLong</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga1d83ca1c98b52785de6b205cf10ba2cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga6825831c83ffca20a7353fcf1f4ff3c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga85c4be48d6121e160ec3d864591f48ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDecay</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga310f8f745367f1fff3d176974abb507f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSustain</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga1b380d79f09e7bd56403f79f09514db9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFastAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8cd59e5d43ed1bd277845f9ed2f29351</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSlowAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga19fc8fcee1d6326b028fdeace97da264</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kShortRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0178603367ef122579d09173b02c275d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLongRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gadb9b1ab770dcdf2bb4d526b5aac6b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStatic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gabca0f72e85147ea95283eb9607c23332</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMoving</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga24192885baa2c896f4ac92a68e176802</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLoop</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga37e6e5e54e1d052d21d739a032593282</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOneShot</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga084d4ed63922f00549f31a1114ecd32c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>vstpshpack4.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>vstpshpack4_8h</filename>
  </compound>
  <compound kind="file">
    <name>vsttypes.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/vst/</path>
    <filename>vsttypes_8h</filename>
    <namespace>Steinberg::Vst</namespace>
    <namespace>Steinberg::Vst::SpeakerArr</namespace>
    <member kind="define">
      <type>#define</type>
      <name>kVstVersionMajor</name>
      <anchorfile>vsttypes_8h.html</anchorfile>
      <anchor>a307b16bcbe3263db838d1a65a1590775</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>kVstVersionMinor</name>
      <anchorfile>vsttypes_8h.html</anchorfile>
      <anchor>aad745365073e680343605ac17c381811</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>kVstVersionSub</name>
      <anchorfile>vsttypes_8h.html</anchorfile>
      <anchor>a6e91d244c8cfdd2b123d37e599043ca1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VST_VERSION</name>
      <anchorfile>vsttypes_8h.html</anchorfile>
      <anchor>a8f8e3e0f6ff1889cda8597884edccb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char16</type>
      <name>TChar</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga9cc7040d53a88b14ecab90ffb052276d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TChar</type>
      <name>String128</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga4b750afeaca8056101ac7952543dfd47</anchor>
      <arglist>[128]</arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>CString</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaf857b729bfca1b912196dd4ff5421420</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>MediaType</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga5f0d28213b308d786ef7a1541d88368f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>BusDirection</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga0dc035dac7916366d61df365731f7b63</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>BusType</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaa6029db01759d30cfcb3504b84d5d04f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>IoMode</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga479361a38cb42c6a07bc6845a5801e55</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>UnitID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga6569c340fc68115670ee0161dd73b3ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>ParamValue</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga11508dccaa352a24d0ae6585a93f4641</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>ParamID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga1dac5893f4a5c27f986d4e51741b544c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>ProgramListID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaac31a9d9a63927ad6927f2a298888c22</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16</type>
      <name>CtrlNumber</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaa67d0906fec66282a0c9488cb52162f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>TQuarterNotes</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gabf70aac64179b2b47bd877600a2e8c28</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>TSamples</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gad2e841097395dbff119029f4684dad8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>ColorSpec</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga5b13d028fba1eee386ec9ac208c6238d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>float</type>
      <name>Sample32</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga353ad4086d31e4b7c57c9124965379a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>Sample64</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga8887669e1feb9270b120bcd725d0d4c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>SampleRate</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga11249ca544d179e7fa61b2200a092407</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64</type>
      <name>SpeakerArrangement</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54884a26d0b6dfa18eb919ea004775ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64</type>
      <name>Speaker</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7a9fc6561fe897989fa3cea09ebb3250</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getChannelCount</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa8258a29fe4e3164d9239869c1afc1e0</anchor>
      <arglist>(SpeakerArrangement arr)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getSpeakerIndex</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5e43f8bd9b65e001e85706fb6229e54d</anchor>
      <arglist>(Speaker speaker, SpeakerArrangement arrangement)</arglist>
    </member>
    <member kind="function">
      <type>SpeakerArrangement</type>
      <name>getSpeakerArrangementFromString</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae59865c6f6e439696b408a8e3a35fb67</anchor>
      <arglist>(CString arrStr)</arglist>
    </member>
    <member kind="function">
      <type>CString</type>
      <name>getSpeakerArrangementString</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8f3040f601ddc82b7ff76bd0ac66b32b</anchor>
      <arglist>(SpeakerArrangement arr, bool withSpeakersName)</arglist>
    </member>
    <member kind="function">
      <type>CString</type>
      <name>getSpeakerShortName</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaea8fb2e63d819b83b1811645b5f5c0a0</anchor>
      <arglist>(const SpeakerArrangement &amp;arr, int32 index)</arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerL</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga851521dbd075cd021659099076c16157</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga65243b42de36e6437862e02afb83ca72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerC</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabe9f3f14a428188b0fd0a229f15bf580</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad73c9bd8399f3587e67bbaf199ae60a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga29b55e791de7fa8d4efdb6948d40db09</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6509637bddb202148260ec274274c878</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga77b0a85020c9d06cd53d92a9f87fe6ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae771dcd8cf33e293b56b78ea7693544c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6e55ae87f6e0a3e7cf8e66ad0e631774</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerCs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5bc2d21ba0124c11a763e86ab63679ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerSl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5380a69a0e649db11601a5841690ee2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerSr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae74ef8bbc9cc9012e28c09893fc80b6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTm</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga37de8204c4573cb6d90bbdedf356b978</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga51b0837ee59b85d8c61c7aaee975f55a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6da088d7aa080b79f6dfa9a868bdb022</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7289205c458e1f2ec529f75ec40f68e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaea0ef00845b9443a18b63572e3c6338a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6aa3de86b02b284c84c12c3e3a772a7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga97ce8834f00cbf7ffb2e4610f9aba296</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLfe2</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaac7d0cfc4cfa58abd88acd718b712f7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerM</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5756399f47d692e0e5e587bcc8a06a9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerW</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga74bc55608435bdfd690634768269607b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerX</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga96ad07e593be8c0801adaa19994225c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerY</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa3c5fe33b5315a6205c6a76596584d1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerZ</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2d5d470e4abab2cca2eff61d52bf3c64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTsl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae27ef071e8ea85bdb2d5e35cb72c4313</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTsr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac5f061a31de54df1c627e9ec947ac442</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLcs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac91567b9c8119eb78d51f6cc398bd97f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRcs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf9740e0213852cf05d6352dc4132b0df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0874c430db7340ecf1c48962eaf436d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac45ef96ed94ff6232edffe4924f63e39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2d6583c536b80d854cbd733eea9877f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerPl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafc605342356ba44807fd1fa424a2bfe5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerPr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5fb93993f0b3c038be5073e228dbb2b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kEmpty</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga85ed4946e3abe83c91baa3e14d6a5e54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kMono</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga571ff835d603ec5e98e54f1e0feca20e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereo</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9b5733786c71156513982991fa5f3c11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoSurround</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaad38856abd90805d1e85fe737677bbe8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga44710b9a538279e604b98213e8acdbec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoSide</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga98918bef7ba906d9b970ba49fb02a742</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoCLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabec483e2214863d8fbfd2f68815647a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga350fe92a4a9f185ff5a7141e7cbada14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga87a09b7b3ca62380f9203bcf6560a3a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab4b759bc9adbcb09a13453cab2916281</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoBF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadad8ca7e56a1171c6439875261ab1ce0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k30Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga32b8626cc036129ae6465115e7d33c5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k30Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8848385489d48df96843cd8022dbbfe1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k31Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga925534b26c3f13772f0363b44de830fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k31Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga34fbc53e44aafa8ca50155a58bd056fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k40Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac1c674ad48a47ead5c1bd0b4d0e6611a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k40Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2133b89c1fce6c11540a55ede3d00715</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k41Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa70d2ecf42316dbf7ea9147384b1d16b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k41Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac3ec49935f60ef5a877f21c6225274f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k50</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gada66cacb0407add2f87505ba08b98095</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k51</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5ed1fd3424cda0c720d08dab3cdacdec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k60Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5c5769c0eac0d76ff06cc2b95cf15ca9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k60Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadf94b622b8d58c498a49d37d9561f535</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k61Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf60226cc4b55554791dedf5ac9c6b46c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k61Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7c2a763f2db01800286568722f724c30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k70Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga957c53627e5492b9b62190be390255c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k70Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2fb8698f83d75be166b99fdbce9e82f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga153beb2d5d562ed4fc8643bf51c711d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFullFront</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga329178a60998946671c5de893797dddf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFullRear</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga50d89ea22e10fe3acadb02c071288776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0dbaa8d90949e4084abb7878a5d5f91b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineSideFill</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga27352e019fb6f0d3b4d10b643f79d813</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Proximity</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9ad1279216eaac4c4c2cd665e6d61c82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2ebfc79a0e5ef338247e31239967632d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae026a8a57e8a9a408320616a0d289ece</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafae2531e75a317dd357fa09074fab4f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga4c68f76511df6119eca847b005105cd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kBFormat1stOrder</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga976822b4dfee259ae8f59a25c9a971af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kBFormat</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1b2703b73a743bc1c75149acddeb42ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Cube</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga44ee3dd3579cc26082915d76a28be70f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineTopCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9c79cded90ddc1a1e366e1fbf4315334</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineCenterHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafca48c099db5b486edc4a79616b3f024</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFrontHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8e2c48c3830b09da02e7bb123f5916bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf21f025b23bb45133395657787f88a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineSideHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga300b4574ad12477ff99286519b754dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1d7c7f813f01cd3f4478ecc81e46e82c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k90</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab04f1f4652d14e277671a0b62a8e8373</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k91</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac29f63756f056bf266ba0e2d26f143d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71_2</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa6ebca6edf27a3858c2780043ee022e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k91Atmos</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga543a82154cd2675d7d8c4ef6680448dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k100</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6cadcafb161f16aa7edcc676604e4def</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k101</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga13c1699c11fba17352b83a1b3a7cfcc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k101MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad74c12ca20962432ba88df9807a9f156</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k102</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga07bcd44b9922095ccd79f2195ad80e2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k110</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf19e8a3b3f0d3a2c0e9587f6cc9b1411</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k111</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga740b694bcebcd228836a5610feeeb929</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k122</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadac6b9c961b9ffdf682f8ff85ea6be64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k130</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga58d4fdbfb02cceca73527bcbf17bf930</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k131</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac672a7aa5cabd6a5d4c4441e6aadc925</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k222</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga80683d5816c4db7345c6e25dfdbc87a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringEmpty</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga38c557da6a4db5884d2d688c30cc5553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringMono</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacc3c2f0d3a1a7cefebcd21afcaff0a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereo</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa8801dd84fb2f8566448a99c418d1185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7baad18ef660784d5ed89c95d0f16aa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoC</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2057f29b65596edf1cb80ccc6a041b83</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoSide</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabab50191c9f7c6a497f7d148cc3a9741</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa1f7cbf8a6fe0184d7ab51fcb3c4792a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga39cdd95afef98e1901ebdb99183e91f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf980dfe2b66f77f49e5cc064e29baf90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga31865a34aa4e3eca16df14729ff1629f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoBF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga50527ffdd77c1df3a01d2656abdcfaca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga546feab92a740e05c378ee7ac40f35cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga53f43e261801293edcef4a1ad84b279d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1e80c914f10746070e3ffe6e85eb5c1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga137e13924264d25e2b23315c90a1a735</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6bb5e6215f1f55441b2d63e1da3d826d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0f4c3361e3f81439c234f22f2c526829</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8b4f4ca5b48687d28d352f0fcfae57df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9a75f791d9b04c26b732bc3501c26ee6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString50</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga67879f0e2d9733cd1a725c10b6bd41ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString51</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad0d54db82db6123d96d1f586b443bca3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6a60a614644af6eb7185b1ca3c863146</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga792624a39e54bdeb84703f79b9180370</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7664212680fd954f8d3bdec7ee52a0a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac847eadaa1938e45601af71cb37737b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga605e76c32caeb4f0d85ada0ffd422b89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5bda8dedc7edcfa8f36b5a99509c9449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3475b1b161d22aca3939960e461307a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8840a665e6fa4dac19167726473d6072</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineTopCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6f792b0962f42ec4f133cb64de72d31e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineCenterHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabbfecee6091fbab1bbd2d3e073b86f5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFrontHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1447af9f22f48e0d039569b10a17aec2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineSideHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad8deb48b287d7520c56e233f8020243c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFullRear</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab78c124e88ad66fcd06aa09f3871320e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Proximity</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga30a288eb79dfa6b08afb569234e831d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae7259d85e37e87f3734e0645a890312b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga35c11fa95eb4ed5340307b725c53180d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Cube</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae9dde9509cd3485e2976e44ec37e2491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf949196ba6ad50b12f2522524ae2079a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga301aef980be40689f6a32d2f2ea5990d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString102</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab514f5233daf9f0d39022eaf6bc3ee39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString122</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac4932606e4ac1473f0da939a03172e4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString90</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6c5bc2454b2c47a01411fbddd25ee30a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaeb2f8e2f0aab973dbf138f73ff23661f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91Atmos</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga929f2c0539c237e4f67a11d46274e037</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString100</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga230095c9378b6f8cac9f14120786423f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString101</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab2d2b7fc9562b4aec27425a1f46e6b5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString110</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga403a29103a9bfa626785cfc61bcce1d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString111</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga05776481c1feeb8db0bd8a8f9fd7bcdc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString130</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac7d25b1cc65c51e76c225ae50c4116ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString131</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf610b7be568618c5d5c3aa20d4cf2ecb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MPEG</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga86ba0d184e2fd6b86e876d5a7343cc5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString222</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaad33c8ed818e1d8f2a30195dadf50af9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringBFormat1stOrder</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga68685cd555e022d616adae60c053ecc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringMonoS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga646cd09e52190d60f2d4ca83faf915aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54144ab0e1dd2babcf5e720950cf7e24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoRS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga63f3673e0a9ad13c3788b583d4fac61b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3cb0fc4337ff0f43bf119b20c7f5d810</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoSS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga22b0cac49e8ef5b3d9a1836abd021720</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCLfeS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa6cc8eae43caf89b778136bbb05fc09a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTFS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacff5991a9dd2a3d5a415d499bcfd681b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTSS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad25d6a1fe574b28440e6b95d94978edb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTRS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac777248ebd6fa592c82b7bcb78f9301e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoBFS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8a0f76c380e173edac9016a3dcfc45bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadf31296b53805c54ae5563807650b24e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaae88a2f1492097d9d64e073cd7943722</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7e65cdf6a6fc4d8aeffc59a7b1a66a1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1b7e67dba5f5333b64eb847d3d78668d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga531abc9ded9f3e0474010cdb22557d0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga51fdeb3143151508f6d94344431ce9de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3789962208da8454667b34aa666981db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54a60dca7c8b8556b398867c51dc1e00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString50S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab8903815699fa69a4fd8ec717317dc29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString51S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafbb743a8f1f0002bae234e2d5910ee8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga16ff5025a411dc1c3b7fc305dfe53073</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab2533387651492af2317e897bd94bf26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2f2f2eb56bcf2977ad670a752c69d793</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga81d034a4b036e9e9bd0be527711db6fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae72794cddb19856e3ec62e33d290176d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5f3a9a34dc5798908f848f0b881b8c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga4b10dc09ef678e66e90330f5b6b591d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaec8cf18e8bfd88584375e66b67fde24e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf3da1b6a98e9f9d01e8141f205f35764</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8204788aa5b2fce1730c157dc8a9239f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafe30ad0333248d38dfd6a162879a97a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5b7279077b689fa26044fc2520a413c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80CubeS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab5aedcc126b998d57c67be78255cd52b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringBFormat1stOrderS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafb8e3e488df5eda20ec2081c389af4ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineTopCenterS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga006f007337addc5c126777bc9e9b774d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineCenterHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf0c13b30d128debc8f8976927a321f48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFrontHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga19c9b28dd806c4a7cf532e33c4db7d1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineSideHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga708f2bb3ba7a3f624acf291960ca7788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFullRearS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5e313aadeb060bc3dc88d17ca2e81a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71ProximityS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga86fc6ff2265855e22d3573786e05af2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString90S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gace125bd22967cceb157097a44d258ef8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae2ada93ca05061ff875826bd2c44029c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91AtmosS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga91cfddb4f5981d77f3350655d67880c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString100S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaec0be9229bbb0796d8d1c69e059e7501</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString101S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5c88990128aeaf6e70cf777e2e2e07f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString110S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacd74a4610c5894723966b586ff76780b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString111S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6520dd17a30ba116ac2877b28a1b8cc9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString130S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaccdab4f0e651d4c1b0b850e6c8edb9f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString131S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9cdfa2ff878225396509ca7b25af7f1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString102S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga31de54f5e618a467f94a579550328644</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString122S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga800e2e69c905b5feaeda81ac24b3f653</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MPEGS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga78b0189e39c80c0bf5cec0ddcce73cf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString222S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab442cbf6e2447ea3a762e0c9c891d274</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>vst3Automation</name>
    <title>Parameters and Automation</title>
    <filename>vst3Automation</filename>
    <docanchor file="vst3Automation">vst3automationRecording</docanchor>
    <docanchor file="vst3Automation">vst3automationPlayback</docanchor>
    <docanchor file="vst3Automation">vst3AutomationIntro</docanchor>
    <docanchor file="vst3Automation">vst3ParameterIntro</docanchor>
  </compound>
  <compound kind="page">
    <name>vst3Units</name>
    <title>Units</title>
    <filename>vst3Units</filename>
    <docanchor file="vst3Units">vst3UnitsIntro</docanchor>
  </compound>
  <compound kind="page">
    <name>vst3Presets</name>
    <title>Presets &amp; Program Lists</title>
    <filename>vst3Presets</filename>
    <docanchor file="vst3Presets">vst3ProgramPitchNames</docanchor>
    <docanchor file="vst3Presets">vst3ProgramLists</docanchor>
    <docanchor file="vst3Presets">vst3ProgramListStructure</docanchor>
    <docanchor file="vst3Presets">vst3PrestsSimple</docanchor>
  </compound>
  <compound kind="page">
    <name>vst3Multitimbral</name>
    <title>Complex Plug-in Structures / Multi-timbral Instruments</title>
    <filename>vst3Multitimbral</filename>
    <docanchor file="vst3Multitimbral">vst3UnitsTracks</docanchor>
    <docanchor file="vst3Multitimbral">vst3MultitimbralIntro</docanchor>
    <docanchor file="vst3Multitimbral">vst3IoMode</docanchor>
    <docanchor file="vst3Multitimbral">vst3Routing</docanchor>
    <docanchor file="vst3Multitimbral">vst3MultitimbralPrograms</docanchor>
  </compound>
  <compound kind="page">
    <name>noteExpression</name>
    <title>Note Expression Support</title>
    <filename>noteExpression</filename>
    <docanchor file="noteExpression">nehowitwork</docanchor>
    <docanchor file="noteExpression">neintro</docanchor>
  </compound>
  <compound kind="page">
    <name>keyswitch</name>
    <title>Key Switch Support</title>
    <filename>keyswitch</filename>
    <docanchor file="keyswitch">kshowitwork</docanchor>
    <docanchor file="keyswitch">ksintro</docanchor>
  </compound>
  <compound kind="page">
    <name>representation</name>
    <title>Remote Representation of Parameters Support</title>
    <filename>representation</filename>
    <docanchor file="representation">reintro</docanchor>
    <docanchor file="representation">view</docanchor>
    <docanchor file="representation">table</docanchor>
    <docanchor file="vst3loc">win2000</docanchor>
    <docanchor file="vst3loc">mac</docanchor>
    <docanchor file="representation">example</docanchor>
    <docanchor file="vst3loc">win7</docanchor>
  </compound>
  <compound kind="page">
    <name>contextmenu</name>
    <title>Context Menu Support</title>
    <filename>contextmenu</filename>
  </compound>
  <compound kind="page">
    <name>vst3loc</name>
    <title>VST 3 Locations</title>
    <filename>vst3loc</filename>
    <docanchor file="vst3loc">win</docanchor>
    <docanchor file="vst3loc">win2000</docanchor>
    <docanchor file="vst3loc">mac</docanchor>
    <docanchor file="vst3loc">pluginloc</docanchor>
    <docanchor file="vst3loc">presetloc</docanchor>
    <docanchor file="vst3loc">win7</docanchor>
  </compound>
  <compound kind="page">
    <name>workflow</name>
    <title>Workflow Diagram</title>
    <filename>workflow</filename>
    <docanchor file="workflow">processorcallsequence</docanchor>
    <docanchor file="workflow">controllercallsequence</docanchor>
  </compound>
  <compound kind="group">
    <name>vstIPlug</name>
    <title>VST 3 Interfaces to be implemented by Plug-in</title>
    <filename>group__vstIPlug.html</filename>
    <class kind="class">Steinberg::Vst::IAudioProcessor</class>
    <class kind="class">Steinberg::Vst::IAudioPresentationLatency</class>
    <class kind="class">Steinberg::Vst::IAutomationState</class>
    <class kind="class">Steinberg::Vst::IComponent</class>
    <class kind="class">Steinberg::Vst::IContextMenuTarget</class>
    <class kind="class">Steinberg::Vst::IEditController</class>
    <class kind="class">Steinberg::Vst::IEditController2</class>
    <class kind="class">Steinberg::Vst::IMidiMapping</class>
    <class kind="class">Steinberg::Vst::IEditControllerHostEditing</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioConnectionNotification</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioPresetManager</class>
    <class kind="class">Steinberg::Vst::IConnectionPoint</class>
    <class kind="class">Steinberg::Vst::INoteExpressionController</class>
    <class kind="class">Steinberg::Vst::IKeyswitchController</class>
    <class kind="class">Steinberg::Vst::IPrefetchableSupport</class>
    <class kind="class">Steinberg::Vst::IXmlRepresentationController</class>
    <class kind="class">Steinberg::Vst::IUnitInfo</class>
    <class kind="class">Steinberg::Vst::IProgramListData</class>
    <class kind="class">Steinberg::Vst::IUnitData</class>
  </compound>
  <compound kind="group">
    <name>vstIHost</name>
    <title>VST 3 Interfaces to be implemented by Host</title>
    <filename>group__vstIHost.html</filename>
    <class kind="class">Steinberg::Vst::IAttributeList</class>
    <class kind="class">Steinberg::Vst::IStreamAttributes</class>
    <class kind="class">Steinberg::Vst::ChannelContext::IInfoListener</class>
    <class kind="class">Steinberg::Vst::IComponentHandler3</class>
    <class kind="class">Steinberg::Vst::IContextMenuTarget</class>
    <class kind="class">Steinberg::Vst::IContextMenu</class>
    <class kind="class">Steinberg::Vst::IComponentHandler</class>
    <class kind="class">Steinberg::Vst::IComponentHandler2</class>
    <class kind="class">Steinberg::Vst::IEventList</class>
    <class kind="class">Steinberg::Vst::IHostApplication</class>
    <class kind="class">Steinberg::Vst::IVst3ToVst2Wrapper</class>
    <class kind="class">Steinberg::Vst::IVst3ToAUWrapper</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioHost</class>
    <class kind="class">Steinberg::Vst::IMessage</class>
    <class kind="class">Steinberg::Vst::IParamValueQueue</class>
    <class kind="class">Steinberg::Vst::IParameterChanges</class>
    <class kind="class">Steinberg::Vst::IUnitHandler</class>
    <class kind="class">Steinberg::Vst::IUnitHandler2</class>
  </compound>
  <compound kind="group">
    <name>vst300</name>
    <title>VST 3 Interfaces defined in version 3.0.0</title>
    <filename>group__vst300.html</filename>
    <class kind="class">Steinberg::Vst::IAttributeList</class>
    <class kind="class">Steinberg::Vst::IAudioProcessor</class>
    <class kind="class">Steinberg::Vst::IComponent</class>
    <class kind="class">Steinberg::Vst::IComponentHandler</class>
    <class kind="class">Steinberg::Vst::IEditController</class>
    <class kind="class">Steinberg::Vst::IEventList</class>
    <class kind="class">Steinberg::Vst::IHostApplication</class>
    <class kind="class">Steinberg::Vst::IMessage</class>
    <class kind="class">Steinberg::Vst::IConnectionPoint</class>
    <class kind="class">Steinberg::Vst::IParamValueQueue</class>
    <class kind="class">Steinberg::Vst::IParameterChanges</class>
    <class kind="class">Steinberg::Vst::IUnitHandler</class>
    <class kind="class">Steinberg::Vst::IUnitInfo</class>
    <class kind="class">Steinberg::Vst::IProgramListData</class>
    <class kind="class">Steinberg::Vst::IUnitData</class>
  </compound>
  <compound kind="group">
    <name>vst301</name>
    <title>VST 3 Interfaces defined in version 3.0.1</title>
    <filename>group__vst301.html</filename>
    <class kind="class">Steinberg::Vst::IMidiMapping</class>
  </compound>
  <compound kind="group">
    <name>vst302</name>
    <title>VST 3 Interfaces defined in version 3.0.2</title>
    <filename>group__vst302.html</filename>
    <class kind="class">Steinberg::Vst::IParameterFinder</class>
  </compound>
  <compound kind="group">
    <name>vst310</name>
    <title>VST 3 Interfaces defined in version 3.1.0</title>
    <filename>group__vst310.html</filename>
    <class kind="class">Steinberg::Vst::IAudioPresentationLatency</class>
    <class kind="class">Steinberg::Vst::IComponentHandler2</class>
    <class kind="class">Steinberg::Vst::IEditController2</class>
    <class kind="class">Steinberg::Vst::IVst3ToVst2Wrapper</class>
    <class kind="class">Steinberg::Vst::IVst3ToAUWrapper</class>
  </compound>
  <compound kind="group">
    <name>vst350</name>
    <title>VST 3 Interfaces defined in version 3.5.0</title>
    <filename>group__vst350.html</filename>
    <class kind="class">Steinberg::Vst::IComponentHandler3</class>
    <class kind="class">Steinberg::Vst::IContextMenuTarget</class>
    <class kind="class">Steinberg::Vst::IContextMenu</class>
    <class kind="class">Steinberg::Vst::IEditControllerHostEditing</class>
    <class kind="class">Steinberg::Vst::INoteExpressionController</class>
    <class kind="class">Steinberg::Vst::IKeyswitchController</class>
    <class kind="class">Steinberg::Vst::IXmlRepresentationController</class>
  </compound>
  <compound kind="group">
    <name>vst360</name>
    <title>VST 3 Interfaces defined in version 3.6.0</title>
    <filename>group__vst360.html</filename>
    <class kind="class">Steinberg::Vst::IStreamAttributes</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioHost</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioConnectionNotification</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioPresetManager</class>
  </compound>
  <compound kind="group">
    <name>vst365</name>
    <title>VST 3 Interfaces defined in version 3.6.5</title>
    <filename>group__vst365.html</filename>
    <class kind="class">Steinberg::Vst::IAutomationState</class>
    <class kind="class">Steinberg::Vst::ChannelContext::IInfoListener</class>
    <class kind="class">Steinberg::Vst::IPrefetchableSupport</class>
    <class kind="class">Steinberg::Vst::IUnitHandler2</class>
  </compound>
  <compound kind="group">
    <name>plugType</name>
    <title>Plug-in Type used for subCategories</title>
    <filename>group__plugType.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxAnalyzer</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1c5f3f4e7d5210a9d81e6dcd76c79c67</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDelay</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae3635bf778d4382234cbcfc30d71db16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDistortion</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gac923ee5b5ba8b5bddb285aad2be3ff35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDynamics</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa892f409ac4c930c1af59459372c167b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxEQ</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae94c37234a2f8bc1c54f85e4d70ad1a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxFilter</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa7061a3bd7a1ef48e14f97503e6c0b2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFx</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga0411b97bcc13d604e738a28aee43bb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxInstrument</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gabe030351fd22d14dad35c817e1849f59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxInstrumentExternal</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga21938bb5dc145f05b8a08669e7a74be5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxSpatial</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf5d6ce751eff5e1825c2e9cbf6de68a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxGenerator</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga09060af560cf34b87e14d5dbd839ad52</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxMastering</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga80ed69d85e565772a138ead6b8feff70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxModulation</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf7fec6a731df379ba73e26bcd72d6f9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxPitchShift</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga2b2725f60cbf68e604c85b125937f553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxRestoration</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf2357711fdb99757b6fd3248cbc4ac15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxReverb</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae45eb21e5afa4a9b2a4e5c789fcac18d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxSurround</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gad51565b155d38402b8660fca0d78927f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxTools</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga610bd26a1a9c791feeb94c3a01b85a3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxNetwork</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1644feff4e06fa14952bf64ee211003f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrument</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga93cb7a7100ac96cfafceb6216770c42d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentDrum</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gadf01865c24020885cb974f200403351c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSampler</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1a96d4882dec6d6cc809c6881456dafa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSynth</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga42c97cd14b97a2ea3052cc62ecc833f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSynthSampler</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa63699396d2e24978ad7a0f32f1a7187</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentExternal</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf0e00ca5cee8c5b4319fb7789bb4b919</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSpatial</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa334568999d986b4e50627646e51a8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSpatialFx</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga9439d03e5e14fb7a35976d2e37f34e31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOnlyRealTime</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae58eb0aafa16197f12c1a61428fd5584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOnlyOfflineProcess</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga0181f4f0a361e99c4afa139b47e3642d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNoOfflineProcess</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1e894c4b97ff99e52706cf3a67c35627</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUpDownMix</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga9b7a9613e51e1f218461d3167dd50306</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAnalyzer</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gadbe2a7d21efd81fbae4bb86fa428e900</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMono</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gad515322344056aab9256d76a6787eb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStereo</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae8acdf9398f33322690596dc2d00318f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSurround</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga6e4cc6e531ad93aa1d60021b82dcdbe9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>vstBus</name>
    <title>VST Buses</title>
    <filename>group__vstBus.html</filename>
    <class kind="struct">Steinberg::Vst::BusInfo</class>
    <member kind="enumeration">
      <name>MediaTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga576e5da9bdc49812cf65f803bb303ad5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAudio</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5aacc820a81fe3b4e8045b839cca0b91d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEvent</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5ae6a97de99980aeac9312e818af337d6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumMediaTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5a803eb569c99a15c09609562d83577cfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>BusDirections</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga48a6eea2da1c202231eb653f3f764af2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInput</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga48a6eea2da1c202231eb653f3f764af2aa3512d23926af0e0dad8c3293443d04c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOutput</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga48a6eea2da1c202231eb653f3f764af2a1aeceb4d8bf67a4d84e082604da2cffd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>BusTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga4849e8fa0da1b39bd3e0af87b441675a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kMain</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga4849e8fa0da1b39bd3e0af87b441675aa388e1f905d2b8eb0f734c83d9356885b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAux</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga4849e8fa0da1b39bd3e0af87b441675aa0aedfd6f0f992c45d4f3620c9445292e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>presetAttributes</name>
    <title>Predefined Preset Attributes</title>
    <filename>group__presetAttributes.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlugInName</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gacbad3647c9f27b2777cb6a3cd24fe49e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlugInCategory</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga56f939f21fb570350d3360b1e7254245</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrument</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga93cb7a7100ac96cfafceb6216770c42d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStyle</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gac45345491383374f12e9e5a8835ef584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCharacter</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga166d8e939e25f23c6e1c5125e89d5f13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStateType</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gaefefe46f30651266cc9ccc8908409552</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFilePathStringType</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gad5fe1f71ae69e7b4daaf0e79130930c3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>stateType</name>
    <title>context of state restoration</title>
    <filename>group__stateType.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kProject</name>
      <anchorfile>group__stateType.html</anchorfile>
      <anchor>ga89eaf816243da36726dfe2656c266a4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDefault</name>
      <anchorfile>group__stateType.html</anchorfile>
      <anchor>ga4f34c8d0372a9d06a2713fd488ece66e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>musicalInstrument</name>
    <title>Predefined Musical Instrument</title>
    <filename>group__musicalInstrument.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5bd8958e2d10a39961b9ac9d20ac1a3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionAccordion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4b3a7ca0aed4fd75c4c6de9da2c095b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionHarmonica</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga13f91d403c87da4936308cd2f94b3dce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga3f7c44f705388a781d442009341b50aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga99ad41c498b2d37a379907989842655a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassABass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7806c7198452bd9b38813e1254bffdde</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassEBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga722ff7ac1ffb92a922ef3f562117327f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassSynthBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabbbabe9b591bdfbc9e8613220d7ce829</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1835577b20a8f992869f11555b9c6c43</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaccf4a6cc04deede6234aa80f17494e62</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassFrenchHorn</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1a4ba62937d8347b92bd6a7fe2f0f203</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTrumpet</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga58aa80b0a42ce48f7868095cbf8af4af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTrombone</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1f2c119eb1f5ed7687375950e64a099a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTuba</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1e4a49eeaaedbf8487070bf20a06b119</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassSection</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae7c3bd91d4fb0872ab7db0ed74d91445</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassSynth</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0cc2d58842ce2dcad93a3f83a777a67d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae4e52f708efde91cf0f2a78cebbd351c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPerc</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5f48d90dba2837a9b0552446258746c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercBell</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7b4edfeeda6a06123409b3e5d704bd0c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercMallett</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaeee07c58574e18dd64d3be93f7088a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercWood</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga492b01fbc86bdb5131f84dcdb5f26f06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercPercussion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0e5caac1dbaa9755fdb06e89ed3b3895</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercTimpani</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga11ef28f0a9918a82c981b1fb8025bd8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga12eb4bbef0c030bbca1e861adc773334</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPerc</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabe15c8ed2a76ff3c9f9029278854dbef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumsetGM</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa41f951f74e972f53aab1a45d15c54aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumset</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9ea452ccf895de2e9a647aa85d40b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumMenues</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa441a52dd98f3b53affbc538eda46521</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercBeats</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5c77bf645fdb2afae554c3c6b48dc92</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercPercussion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga351f0ed74b2185f5acc3460021c203a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercKickDrum</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf85c8e569ae8d22ab2c233006a99f82e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercSnareDrum</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga13fca99a8c4598a5f66ef87242f70b27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercToms</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac756e1798f6f8ce4eed78adafcd6f8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercHiHats</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gadec30a0adbbd248d6573f64342feef77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercCymbals</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga82ee2aad1a847aea7c803b81a4d2598b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8dbf5e607efc62bfd0fb4044a943c399</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa946206a3ecfcc3423ea307de5efdd13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAsian</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga81ca43ff51517679540bbabce3f89254</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAfrican</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5de2bf50670628599940b4afba85fba1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicEuropean</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga841f031104f1230a568fb7246eb87fe0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicLatin</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8b04cbbaa98e561e20b7a966f58e9281</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAmerican</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga3c6dcb9ae2464cf7012aadb328c73fdb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAlien</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga86aa661200c00f7b44935e455d62b5f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga89d49bfa58ca9659367217ea187bd7bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga642a844eb43638962aec00dda572b724</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarAGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf907f1b0c6b112a7a7ef2c26d181345b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarEGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5bd16506f3db8c7cada37ac1030fdeec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarHarp</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga6077d4646f9ce2fcd14f40ee5f1fcfce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabac2c7c2f88a2511bcb9536a62847e64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga91eddfe8e8f1e826c887b57971600988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboard</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae87c28eecf427576aaba8dba45506307</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardClavi</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabeb1f764cd854f5f7b107a8f0b1fd4ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardEPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga326410320556a12f64c20f88c19373ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardHarpsichord</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga02d58cfc1dd6afe263d10ed615eb0d2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga20c97efa4d9bc8307bbd0375035c34ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2390a2a94e9904517ec9342ab0019fe7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXHitsStabs</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7827735f5bb526019207c524f487af0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXMotion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab9114e6b0673188dc5228aed3d3df2da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXSweeps</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf3cb2d886c19f654e5d4d8b25eb5477e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXBeepsBlips</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5378d54b89a50f2b659f4811d2925cc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXScratches</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gacbe3eb6871b48061d2c046d8b258a7a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5e9cb190b3c45ca56bb2e1adebb43fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrgan</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga84fec6760fef802a323b692a062b55b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganElectric</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2ec0df01bea69ecba86f5d891b1ad648</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganPipe</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga79ae6538d284af4c29bbd7cf4933b76e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga20f011a1e399ecacdb0e6e1cb7196e64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga41cb875c197b4036cc5ac03ca3721a08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoAPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4ad2adf116f63f68c278860b4d1d1f6d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoEGrand</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga37d4c3eca4f4d9c151ffa65609c79439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1af05a3bfb82be1b619388c384a6bf2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf2a091ea57274b72699e9f9df7715b17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXNature</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gad21b480ba2888b09f222c703fbb37a91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXMechanical</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8f75ccb3769fa4876436c45a09107fcd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXSynthetic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga341e53ab2df394405b3785850dad88e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaae916a5a813ecf7d856e61f456a24479</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStrings</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaafd56235b0b917a43d284202d30f4f0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsViolin</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf8cf7e44674db2aca92f56fd73f92006</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsViola</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9aa9476acbba419210667d658afabc6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsCello</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga265f017e0f464df3d4141dc319eff0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae18de76efc605860475b6323ef233cc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsSection</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac1d32b8a87a1fd03f9c1015160d7d3b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsSynth</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga51a61e68eba9a1cf51ad89242b9bc47f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab44336cb32a2e361969b84be167c6437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLead</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga65f99d06e1cdec2a31ced94c3e74e2b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8a11629221f0398068c261f7e82dbb3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5593b90f0b783f8c474534b1bfdece81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadArpeggio</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9f07e312d4b567cbeb9afc62663e799d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1baec415d4b38bfc63bfe37d4d8f998e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPad</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga09ada6780ac854e1a5f5fdeaeed3fb98</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadSynthChoir</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga459f7a40ee5ce2589b9c5b4e9a7dbc03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gafd8251cd1e2beb471fb880eff54122a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0624ae2a566ded387d13aa9b42b02e4f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadMotion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabb14045ba365551baf7d248ea496f627</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga21365983f34c81eb766d77a9f6c56542</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthComp</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac5ee81e33b8952b205664d8a7e6d3726</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga98b124c4c95e7d1f055a878c293036a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga58fd32018d0d25fa22a065fe293e4079</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab2577b8dac71b9e6d679cd5fd337fc70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocal</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2d5f12d8f479275a1ec1047877ad12f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalLeadVocal</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga33b0df9f2de9caa850ec8f42a690ea1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalAdlibs</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaeb469e5850a09e7863b3a411bd839185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalChoir</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf1c302e30ac59f819c846264553cbb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalSolo</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9fee846e3dac6a9c76f49236370104ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga01a286aebf174524ce6806266da52608</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalSpoken</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gad3c91ff5b7e51b5ed71479994af1f2b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga97b0787f7bc7a12d8aa9c451626252df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwinds</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab6f7ddec4db62d879f3d4147da295e5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4c985b65f095bd5bf25adb95490c26ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsFlute</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1b594039765ec814407ab25b574177e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsOboe</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga40a881c8d3a7bc7f6688195400ba35dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsEnglHorn</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaab8ddc7cc6aa5f6c1b3383b7ba109c65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsClarinet</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga76398345f57877810ceeb6db295a08a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsSaxophone</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga685ce7454b4f454c4f2e36b40d215fab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsBassoon</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa7909c8fc3a72ec802f1163f7bf78a1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga850425dd3f6d9938ccbbee6158316bbc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>musicalStyle</name>
    <title>Predefined Musical Style</title>
    <filename>group__musicalStyle.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndie</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2283c2c777c7cbb21710e11ef2ceb6af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieGothRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5efb4dfb4fef27ded5062173093bbaa1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieGrunge</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga611a7833ad99ac643e6662ad0c735437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieNewWave</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0d9c9e5d1d7762b13270a0cd388b2d7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndiePunk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2b8b2179cf8d2b74f6c0eb2abb563a80</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieCollegeRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8881386092fc55d2c4ed31ca0d3acd22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieDarkWave</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4e60a460c89c2aa3f05c8e15c4a74b76</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieHardcore</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga080e7eebf7cfeef648604aab356d9249</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOut</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa5aa1cc4f7a5cf8fbcb025f426225676</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutNewAgeMeditation</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab17d3d9dbddf245300a0e581f27d2b21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutDarkAmbient</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga33320722a4e37a0dbe61f8957a77fcb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutDowntempo</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5af88b6815b44014176a2bf68aabca6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutLounge</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1abdca80184a162d425c61f053530dea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga070e85734aa0ebd786f2c8ff8dca8301</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesAcousticBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga427cc44ab600473801a7d50bef343e2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesCountryBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3ccf2f159b7b1becbe0d64f4688f7f4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesElectricBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga60c65b0575b241924ccfcc59fa7dccaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesChicagoBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5043e48daf7d4433d082c9d726b90a2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassical</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga00100f8944908f3f674b077b8e7bf5ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalBaroque</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga54a477d7f94dacdfa325bdf693d180ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalChamberMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga817fef9aabf571d6f91e357efc677040</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalMedieval</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaabb6cafa41915dc3a4ebb19d35aeb3be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalModernComposition</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa61b32582345fd12bd9d2140c174a25f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalOpera</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaaa8a189a2e24961319d1e26349aa8a9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalGregorian</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabd559febaa875cac883dc20517965d19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalRenaissance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8f9739caabbf232d50b1b1b449ab1491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalClassic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1a1b8c73dee78995dfc73a9cbe1855fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalRomantic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad822300e6782c9fc490f073c880403ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalSoundtrack</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad28cde471461898b52b6cd7aefe1fad9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountry</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaaa2fa8f51e39b78604c752001cbef8c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryCountryWestern</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga613bd6f52125a615d0e1bef58463e6cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryHonkyTonk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac05e574ca2ece383b72b5ee429506988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryUrbanCowboy</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabc94ae94e43d1ae9a453f5033f2f6bf4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryBluegrass</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga56cc1195da3ec7bc16d67a303c489c6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryAmericana</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8a240fc37b335deb7063b9bbf959ba90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountrySquaredance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7b9a2584ff4f1501c9a24a8754f1f526</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryNorthAmericanFolk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1578d35d598b30c1a8aca33c94e33213</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga9e3c1f6becf1b50e07e2d8212fadea0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceMinimal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2acd1ccf8c493d7055288674c243e7f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceClassicHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad2581a6189feb88d716b6c81c5efa79b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElektroHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad6c238193c96a2f320bb158fc0cb36b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceFunkyHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac697bd7d2476a3f522e0c12f4f9096c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceIndustrial</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga43aa90fa2a5718ec3f233186bef3b745</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElectronicBodyMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4c9fd026e505a151e4ebcb41a026a273</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTripHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga27a783d5bce0708e88414cd4de0ffc3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTechno</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga66d567db513649b64572ec56ec721a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceDrumNBassJungle</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa1a66bada350ea5f47e8c296bd3482b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElektro</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac613b9e387a4a4e424dbdd7925a842f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTrance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae1734ba060074a2d5f5bc4aadb1b4693</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceDub</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4bf8090a24491f751c9d75218ba8ffc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceBigBeats</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga04e06e3becb8bca4036fd5856682a393</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimental</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga13e10384c541982e7ebea23ae4cc0057</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalNewMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga9d42a1c28d4a1b6e725783290a949f04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalFreeImprovisation</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga988ed6ba9f31ff90849bfe159dbb56f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalElectronicArtMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad14a4491132f9255427a1dfbb53f684a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalNoise</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6d711a097823788b80c4373b0df67287</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae80ee561e4da8da1de90835e41f0fc7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzNewOrleansJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0ade597c6d17afc9e6cf4a7bdf34de9b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzTraditionalJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6099a9381244ca72562a7b8226c619b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzOldtimeJazzDixiland</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga04fc9ede978682cf37a56876ba9dba9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzFusion</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga847f04e92eee76df8f6c6592da0cea2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzAvantgarde</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac6cbbbd37ada9f3f26657db8cc6065f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzLatinJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0ee890f05a7479865af9eda6d34bc857</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzFreeJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5fcff8a8096b40b9e05427c944a2e295</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzRagtime</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac2b3067f7b9b92ffe14a1b15b0bed83b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga92057d09ae8339165840fd850e77868d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopBritpop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga886ab03c6a77598d7e78c3a6ec922441</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga772e326e01f9245ba8a8177301a55d4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopTeenPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7e047957551e02185723581a1880086e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopChartDance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6f9e30f2b18f2f639fefbb38b1d2d3e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPop80sPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6f3a96aeedf52ae2691056c3f1535578</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopDancehall</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gafdb7e50d604be148bcab627102c66a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopDisco</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4cfb53a16c9ad176d8c2a3b9a4a267a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gade4f6c22997daaed1a372dd09b358068</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalBluesRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac1c59279027338732b37420973755dd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalClassicRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga52b06f4c922bceb8a7af486f8f9e8ead</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalHardRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab7fc6fc1b343016898c32d9095895973</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalRockRoll</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaf044a0ecefea571e16b30b82a1becf04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalSingerSongwriter</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4c7fb7c56f3573b219287833e847113c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalHeavyMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1b66689bf69717c4af8ad85835737acf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalDeathBlackMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga370c692d8ab858d11bff12c0ea4c779c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalNuMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1e43c81772b3227d2239c4c869194733</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalReggae</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab7285dab701bff67bb281688a4c1b93a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalBallad</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3e6375ad794af9ad7c9e79f61ce422de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalAlternativeRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga679697a95e28deb4eb0ab2dcdeca114a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalRockabilly</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga646cb827580fbdb5631167f300e2d7c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalThrashMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4367d681da9e6a9259373fe33bd58162</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalProgressiveRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaf74e7f4e41c15f2e271cc15b512b2fbf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRB</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad9fdad7b31d648bbf64bc2333bc3ecab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBClassic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae828f62557a162b35e08774fe73e4b59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBModern</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3089241b92ddf52d670f6339c57ff321</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga03a11de347ee7fbfa80f6040e5838c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBWestCoastHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga31d1f86b5f8a0281d2a85f7ae6e40d10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBEastCoastHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga91a0592eb755912d7fbf4b7f78387707</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBRapHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3dd2ebf4652bdc7f67e804099495ad1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBSoul</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga853a4803393e2d1684fe32e5adafcffe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBFunk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gadab3d1a08820555d8cc2eccba5a2414d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7fc43124278803213779023493bec46b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAfrica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga24447081033911845dd5279102bf075b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAsia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga09caf2a39534495b771aa65a0d969ad1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicCeltic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga17f0e511cbcdedf14156ba499a54d615</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicEurope</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabbce5b2144aac1d57742c746de8ef78b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicKlezmer</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8db09e3dd05ef85ce88a038472cc04af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicScandinavia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3ae32b316261fa76c8d7ca0e9790871f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicEasternEurope</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaff54f68acdbdbbbed6054f5c9b17ba8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicIndiaOriental</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga33a8a991563a9d73923525ddd29e79a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicNorthAmerica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3d85eb586a37b5a6082a6d1708d91592</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicSouthAmerica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaad0a8d9f7a2cef071860eee02948c556</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAustralia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae08118ff90a70fbd90e1979aa1a33c9f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>musicalCharacter</name>
    <title>Predefined Musical Character</title>
    <filename>group__musicalCharacter.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kMono</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gad515322344056aab9256d76a6787eb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPoly</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga020e4d1023e2b9add2c637ebf4b75a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSplit</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga51e6bf04c8aaefb4fbbc45a114f147c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLayer</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga18049d58eeecea7c6fed4f727442430d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlide</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga94f8615dad159bf66390009ad9282249</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlissando</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae0732ea96679d73e821715b2be446261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMajor</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga18f27017b00ca4612f133f4e09d913e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMinor</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaccd54b1bfad544bac2ff54cfb56d7df2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSingle</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga516ace30c1fa46e55b8767b58c77a788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEnsemble</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gadb6de4949739c48baf2613e6965d1637</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAcoustic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf589c030507665591b7e57d677b350e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectric</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa924ea59d6457adaabe92b47048253aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAnalog</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga10904a318940018e74802140f840a4cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDigital</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf8f1ad8e2c507c80b75e20d94cbef219</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVintage</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gab86682f9fb5dd5c56199feba1afadc8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kModern</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga490b8908c7977aaca4e5a7fc1983f172</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOld</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0bbfdd92cc2b2313b3cf974c5b3f9760</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNew</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8ff57c7698535ab97bfc64a7bf3ea9ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClean</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae48573356356094da60ac761ac5ac51e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDistorted</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa8427782100432cfaf837a729195f1ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDry</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae4406a55f1a7b6f1d12e29bab8f576e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kProcessed</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0bc38b1dfd75d0ae9e6137d43c29068c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kHarmonic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8f5f55f753d25fbeec874ff7c873b050</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDissonant</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga3030eff3a0900a8cca1c6266716efe1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClear</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf8c102dba19d9bafb8d7ba312f812ad7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNoisy</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa57323ce9c0b4d417c6b36aa76570514</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kThin</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8da59e92e1c2609a302663aeeffc01cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRich</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa6c4d36725eb4226e02f5724ca420e24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDark</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaae40f2e630a0d26cdd3d862761b26d07</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBright</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0796a86633dd777869721cf5f2666aa5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCold</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga7c18fd830521824296dc8412e5420559</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWarm</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gac1766654d4a9b882b9890fce9483a733</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMetallic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga644e30da9b10ac15bcd313778d00d261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWooden</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gabea2ba5e271fab4f245baffae6fc7f20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlass</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa5eee886870365dcadc1105891130025</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlastic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga62ea7670ea954e012810004bb26369fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPercussive</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gac6b35eb8d6cf9178f4b428d523760e89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoft</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga280fd77ca4f703e3509ba81e6a4a7062</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFast</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gab5face7509d33a16c6be75f042d5f56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSlow</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga196114f5b784b26e46ca975e194a12cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kShort</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8b9663df42570d3f736896b881f348f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLong</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga1d83ca1c98b52785de6b205cf10ba2cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga6825831c83ffca20a7353fcf1f4ff3c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga85c4be48d6121e160ec3d864591f48ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDecay</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga310f8f745367f1fff3d176974abb507f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSustain</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga1b380d79f09e7bd56403f79f09514db9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFastAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8cd59e5d43ed1bd277845f9ed2f29351</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSlowAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga19fc8fcee1d6326b028fdeace97da264</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kShortRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0178603367ef122579d09173b02c275d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLongRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gadb9b1ab770dcdf2bb4d526b5aac6b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStatic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gabca0f72e85147ea95283eb9607c23332</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMoving</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga24192885baa2c896f4ac92a68e176802</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLoop</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga37e6e5e54e1d052d21d739a032593282</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOneShot</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga084d4ed63922f00549f31a1114ecd32c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>vst3typedef</name>
    <title>VST 3 Data Types</title>
    <filename>group__vst3typedef.html</filename>
    <member kind="typedef">
      <type>char16</type>
      <name>TChar</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga9cc7040d53a88b14ecab90ffb052276d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TChar</type>
      <name>String128</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga4b750afeaca8056101ac7952543dfd47</anchor>
      <arglist>[128]</arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>CString</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaf857b729bfca1b912196dd4ff5421420</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>MediaType</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga5f0d28213b308d786ef7a1541d88368f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>BusDirection</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga0dc035dac7916366d61df365731f7b63</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>BusType</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaa6029db01759d30cfcb3504b84d5d04f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>IoMode</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga479361a38cb42c6a07bc6845a5801e55</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>UnitID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga6569c340fc68115670ee0161dd73b3ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>ParamValue</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga11508dccaa352a24d0ae6585a93f4641</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>ParamID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga1dac5893f4a5c27f986d4e51741b544c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>ProgramListID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaac31a9d9a63927ad6927f2a298888c22</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16</type>
      <name>CtrlNumber</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaa67d0906fec66282a0c9488cb52162f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>TQuarterNotes</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gabf70aac64179b2b47bd877600a2e8c28</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>TSamples</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gad2e841097395dbff119029f4684dad8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>ColorSpec</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga5b13d028fba1eee386ec9ac208c6238d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>float</type>
      <name>Sample32</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga353ad4086d31e4b7c57c9124965379a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>Sample64</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga8887669e1feb9270b120bcd725d0d4c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>SampleRate</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga11249ca544d179e7fa61b2200a092407</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>speakerArrangements</name>
    <title>Speaker Arrangements</title>
    <filename>group__speakerArrangements.html</filename>
    <member kind="typedef">
      <type>uint64</type>
      <name>SpeakerArrangement</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54884a26d0b6dfa18eb919ea004775ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64</type>
      <name>Speaker</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7a9fc6561fe897989fa3cea09ebb3250</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getChannelCount</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa8258a29fe4e3164d9239869c1afc1e0</anchor>
      <arglist>(SpeakerArrangement arr)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getSpeakerIndex</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5e43f8bd9b65e001e85706fb6229e54d</anchor>
      <arglist>(Speaker speaker, SpeakerArrangement arrangement)</arglist>
    </member>
    <member kind="function">
      <type>SpeakerArrangement</type>
      <name>getSpeakerArrangementFromString</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae59865c6f6e439696b408a8e3a35fb67</anchor>
      <arglist>(CString arrStr)</arglist>
    </member>
    <member kind="function">
      <type>CString</type>
      <name>getSpeakerArrangementString</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8f3040f601ddc82b7ff76bd0ac66b32b</anchor>
      <arglist>(SpeakerArrangement arr, bool withSpeakersName)</arglist>
    </member>
    <member kind="function">
      <type>CString</type>
      <name>getSpeakerShortName</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaea8fb2e63d819b83b1811645b5f5c0a0</anchor>
      <arglist>(const SpeakerArrangement &amp;arr, int32 index)</arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerL</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga851521dbd075cd021659099076c16157</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga65243b42de36e6437862e02afb83ca72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerC</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabe9f3f14a428188b0fd0a229f15bf580</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad73c9bd8399f3587e67bbaf199ae60a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga29b55e791de7fa8d4efdb6948d40db09</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6509637bddb202148260ec274274c878</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga77b0a85020c9d06cd53d92a9f87fe6ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae771dcd8cf33e293b56b78ea7693544c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6e55ae87f6e0a3e7cf8e66ad0e631774</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerCs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5bc2d21ba0124c11a763e86ab63679ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerSl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5380a69a0e649db11601a5841690ee2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerSr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae74ef8bbc9cc9012e28c09893fc80b6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTm</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga37de8204c4573cb6d90bbdedf356b978</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga51b0837ee59b85d8c61c7aaee975f55a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6da088d7aa080b79f6dfa9a868bdb022</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7289205c458e1f2ec529f75ec40f68e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaea0ef00845b9443a18b63572e3c6338a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6aa3de86b02b284c84c12c3e3a772a7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga97ce8834f00cbf7ffb2e4610f9aba296</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLfe2</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaac7d0cfc4cfa58abd88acd718b712f7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerM</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5756399f47d692e0e5e587bcc8a06a9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerW</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga74bc55608435bdfd690634768269607b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerX</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga96ad07e593be8c0801adaa19994225c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerY</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa3c5fe33b5315a6205c6a76596584d1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerZ</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2d5d470e4abab2cca2eff61d52bf3c64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTsl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae27ef071e8ea85bdb2d5e35cb72c4313</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTsr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac5f061a31de54df1c627e9ec947ac442</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLcs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac91567b9c8119eb78d51f6cc398bd97f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRcs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf9740e0213852cf05d6352dc4132b0df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0874c430db7340ecf1c48962eaf436d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac45ef96ed94ff6232edffe4924f63e39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2d6583c536b80d854cbd733eea9877f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerPl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafc605342356ba44807fd1fa424a2bfe5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerPr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5fb93993f0b3c038be5073e228dbb2b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kEmpty</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga85ed4946e3abe83c91baa3e14d6a5e54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kMono</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga571ff835d603ec5e98e54f1e0feca20e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereo</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9b5733786c71156513982991fa5f3c11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoSurround</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaad38856abd90805d1e85fe737677bbe8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga44710b9a538279e604b98213e8acdbec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoSide</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga98918bef7ba906d9b970ba49fb02a742</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoCLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabec483e2214863d8fbfd2f68815647a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga350fe92a4a9f185ff5a7141e7cbada14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga87a09b7b3ca62380f9203bcf6560a3a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab4b759bc9adbcb09a13453cab2916281</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoBF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadad8ca7e56a1171c6439875261ab1ce0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k30Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga32b8626cc036129ae6465115e7d33c5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k30Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8848385489d48df96843cd8022dbbfe1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k31Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga925534b26c3f13772f0363b44de830fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k31Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga34fbc53e44aafa8ca50155a58bd056fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k40Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac1c674ad48a47ead5c1bd0b4d0e6611a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k40Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2133b89c1fce6c11540a55ede3d00715</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k41Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa70d2ecf42316dbf7ea9147384b1d16b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k41Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac3ec49935f60ef5a877f21c6225274f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k50</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gada66cacb0407add2f87505ba08b98095</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k51</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5ed1fd3424cda0c720d08dab3cdacdec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k60Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5c5769c0eac0d76ff06cc2b95cf15ca9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k60Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadf94b622b8d58c498a49d37d9561f535</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k61Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf60226cc4b55554791dedf5ac9c6b46c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k61Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7c2a763f2db01800286568722f724c30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k70Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga957c53627e5492b9b62190be390255c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k70Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2fb8698f83d75be166b99fdbce9e82f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga153beb2d5d562ed4fc8643bf51c711d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFullFront</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga329178a60998946671c5de893797dddf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFullRear</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga50d89ea22e10fe3acadb02c071288776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0dbaa8d90949e4084abb7878a5d5f91b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineSideFill</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga27352e019fb6f0d3b4d10b643f79d813</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Proximity</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9ad1279216eaac4c4c2cd665e6d61c82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2ebfc79a0e5ef338247e31239967632d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae026a8a57e8a9a408320616a0d289ece</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafae2531e75a317dd357fa09074fab4f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga4c68f76511df6119eca847b005105cd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kBFormat1stOrder</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga976822b4dfee259ae8f59a25c9a971af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kBFormat</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1b2703b73a743bc1c75149acddeb42ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Cube</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga44ee3dd3579cc26082915d76a28be70f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineTopCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9c79cded90ddc1a1e366e1fbf4315334</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineCenterHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafca48c099db5b486edc4a79616b3f024</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFrontHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8e2c48c3830b09da02e7bb123f5916bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf21f025b23bb45133395657787f88a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineSideHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga300b4574ad12477ff99286519b754dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1d7c7f813f01cd3f4478ecc81e46e82c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k90</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab04f1f4652d14e277671a0b62a8e8373</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k91</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac29f63756f056bf266ba0e2d26f143d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71_2</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa6ebca6edf27a3858c2780043ee022e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k91Atmos</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga543a82154cd2675d7d8c4ef6680448dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k100</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6cadcafb161f16aa7edcc676604e4def</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k101</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga13c1699c11fba17352b83a1b3a7cfcc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k101MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad74c12ca20962432ba88df9807a9f156</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k102</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga07bcd44b9922095ccd79f2195ad80e2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k110</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf19e8a3b3f0d3a2c0e9587f6cc9b1411</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k111</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga740b694bcebcd228836a5610feeeb929</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k122</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadac6b9c961b9ffdf682f8ff85ea6be64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k130</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga58d4fdbfb02cceca73527bcbf17bf930</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k131</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac672a7aa5cabd6a5d4c4441e6aadc925</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k222</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga80683d5816c4db7345c6e25dfdbc87a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringEmpty</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga38c557da6a4db5884d2d688c30cc5553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringMono</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacc3c2f0d3a1a7cefebcd21afcaff0a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereo</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa8801dd84fb2f8566448a99c418d1185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7baad18ef660784d5ed89c95d0f16aa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoC</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2057f29b65596edf1cb80ccc6a041b83</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoSide</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabab50191c9f7c6a497f7d148cc3a9741</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa1f7cbf8a6fe0184d7ab51fcb3c4792a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga39cdd95afef98e1901ebdb99183e91f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf980dfe2b66f77f49e5cc064e29baf90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga31865a34aa4e3eca16df14729ff1629f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoBF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga50527ffdd77c1df3a01d2656abdcfaca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga546feab92a740e05c378ee7ac40f35cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga53f43e261801293edcef4a1ad84b279d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1e80c914f10746070e3ffe6e85eb5c1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga137e13924264d25e2b23315c90a1a735</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6bb5e6215f1f55441b2d63e1da3d826d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0f4c3361e3f81439c234f22f2c526829</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8b4f4ca5b48687d28d352f0fcfae57df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9a75f791d9b04c26b732bc3501c26ee6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString50</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga67879f0e2d9733cd1a725c10b6bd41ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString51</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad0d54db82db6123d96d1f586b443bca3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6a60a614644af6eb7185b1ca3c863146</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga792624a39e54bdeb84703f79b9180370</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7664212680fd954f8d3bdec7ee52a0a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac847eadaa1938e45601af71cb37737b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga605e76c32caeb4f0d85ada0ffd422b89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5bda8dedc7edcfa8f36b5a99509c9449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3475b1b161d22aca3939960e461307a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8840a665e6fa4dac19167726473d6072</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineTopCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6f792b0962f42ec4f133cb64de72d31e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineCenterHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabbfecee6091fbab1bbd2d3e073b86f5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFrontHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1447af9f22f48e0d039569b10a17aec2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineSideHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad8deb48b287d7520c56e233f8020243c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFullRear</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab78c124e88ad66fcd06aa09f3871320e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Proximity</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga30a288eb79dfa6b08afb569234e831d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae7259d85e37e87f3734e0645a890312b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga35c11fa95eb4ed5340307b725c53180d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Cube</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae9dde9509cd3485e2976e44ec37e2491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf949196ba6ad50b12f2522524ae2079a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga301aef980be40689f6a32d2f2ea5990d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString102</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab514f5233daf9f0d39022eaf6bc3ee39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString122</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac4932606e4ac1473f0da939a03172e4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString90</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6c5bc2454b2c47a01411fbddd25ee30a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaeb2f8e2f0aab973dbf138f73ff23661f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91Atmos</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga929f2c0539c237e4f67a11d46274e037</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString100</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga230095c9378b6f8cac9f14120786423f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString101</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab2d2b7fc9562b4aec27425a1f46e6b5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString110</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga403a29103a9bfa626785cfc61bcce1d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString111</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga05776481c1feeb8db0bd8a8f9fd7bcdc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString130</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac7d25b1cc65c51e76c225ae50c4116ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString131</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf610b7be568618c5d5c3aa20d4cf2ecb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MPEG</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga86ba0d184e2fd6b86e876d5a7343cc5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString222</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaad33c8ed818e1d8f2a30195dadf50af9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringBFormat1stOrder</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga68685cd555e022d616adae60c053ecc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringMonoS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga646cd09e52190d60f2d4ca83faf915aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54144ab0e1dd2babcf5e720950cf7e24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoRS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga63f3673e0a9ad13c3788b583d4fac61b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3cb0fc4337ff0f43bf119b20c7f5d810</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoSS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga22b0cac49e8ef5b3d9a1836abd021720</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCLfeS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa6cc8eae43caf89b778136bbb05fc09a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTFS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacff5991a9dd2a3d5a415d499bcfd681b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTSS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad25d6a1fe574b28440e6b95d94978edb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTRS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac777248ebd6fa592c82b7bcb78f9301e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoBFS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8a0f76c380e173edac9016a3dcfc45bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadf31296b53805c54ae5563807650b24e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaae88a2f1492097d9d64e073cd7943722</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7e65cdf6a6fc4d8aeffc59a7b1a66a1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1b7e67dba5f5333b64eb847d3d78668d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga531abc9ded9f3e0474010cdb22557d0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga51fdeb3143151508f6d94344431ce9de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3789962208da8454667b34aa666981db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54a60dca7c8b8556b398867c51dc1e00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString50S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab8903815699fa69a4fd8ec717317dc29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString51S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafbb743a8f1f0002bae234e2d5910ee8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga16ff5025a411dc1c3b7fc305dfe53073</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab2533387651492af2317e897bd94bf26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2f2f2eb56bcf2977ad670a752c69d793</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga81d034a4b036e9e9bd0be527711db6fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae72794cddb19856e3ec62e33d290176d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5f3a9a34dc5798908f848f0b881b8c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga4b10dc09ef678e66e90330f5b6b591d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaec8cf18e8bfd88584375e66b67fde24e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf3da1b6a98e9f9d01e8141f205f35764</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8204788aa5b2fce1730c157dc8a9239f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafe30ad0333248d38dfd6a162879a97a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5b7279077b689fa26044fc2520a413c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80CubeS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab5aedcc126b998d57c67be78255cd52b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringBFormat1stOrderS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafb8e3e488df5eda20ec2081c389af4ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineTopCenterS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga006f007337addc5c126777bc9e9b774d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineCenterHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf0c13b30d128debc8f8976927a321f48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFrontHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga19c9b28dd806c4a7cf532e33c4db7d1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineSideHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga708f2bb3ba7a3f624acf291960ca7788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFullRearS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5e313aadeb060bc3dc88d17ca2e81a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71ProximityS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga86fc6ff2265855e22d3573786e05af2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString90S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gace125bd22967cceb157097a44d258ef8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae2ada93ca05061ff875826bd2c44029c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91AtmosS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga91cfddb4f5981d77f3350655d67880c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString100S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaec0be9229bbb0796d8d1c69e059e7501</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString101S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5c88990128aeaf6e70cf777e2e2e07f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString110S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacd74a4610c5894723966b586ff76780b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString111S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6520dd17a30ba116ac2877b28a1b8cc9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString130S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaccdab4f0e651d4c1b0b850e6c8edb9f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString131S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9cdfa2ff878225396509ca7b25af7f1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString102S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga31de54f5e618a467f94a579550328644</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString122S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga800e2e69c905b5feaeda81ac24b3f653</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MPEGS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga78b0189e39c80c0bf5cec0ddcce73cf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString222S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab442cbf6e2447ea3a762e0c9c891d274</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst</name>
    <filename>namespaceSteinberg_1_1Vst.html</filename>
    <namespace>Steinberg::Vst::PlugType</namespace>
    <namespace>Steinberg::Vst::ChannelContext</namespace>
    <namespace>Steinberg::Vst::ViewType</namespace>
    <namespace>Steinberg::Vst::LayerType</namespace>
    <namespace>Steinberg::Vst::CurveType</namespace>
    <namespace>Steinberg::Vst::Attributes</namespace>
    <namespace>Steinberg::Vst::AttributesFunction</namespace>
    <namespace>Steinberg::Vst::AttributesStyle</namespace>
    <namespace>Steinberg::Vst::AttributesFlags</namespace>
    <namespace>Steinberg::Vst::PresetAttributes</namespace>
    <namespace>Steinberg::Vst::StateType</namespace>
    <namespace>Steinberg::Vst::MusicalInstrument</namespace>
    <namespace>Steinberg::Vst::MusicalStyle</namespace>
    <namespace>Steinberg::Vst::MusicalCharacter</namespace>
    <namespace>Steinberg::Vst::SpeakerArr</namespace>
    <class kind="class">Steinberg::Vst::IAttributeList</class>
    <class kind="class">Steinberg::Vst::IStreamAttributes</class>
    <class kind="struct">Steinberg::Vst::ProcessSetup</class>
    <class kind="struct">Steinberg::Vst::AudioBusBuffers</class>
    <class kind="struct">Steinberg::Vst::ProcessData</class>
    <class kind="class">Steinberg::Vst::IAudioProcessor</class>
    <class kind="class">Steinberg::Vst::IAudioPresentationLatency</class>
    <class kind="class">Steinberg::Vst::IAutomationState</class>
    <class kind="struct">Steinberg::Vst::BusInfo</class>
    <class kind="struct">Steinberg::Vst::RoutingInfo</class>
    <class kind="class">Steinberg::Vst::IComponent</class>
    <class kind="class">Steinberg::Vst::IComponentHandler3</class>
    <class kind="class">Steinberg::Vst::IContextMenuTarget</class>
    <class kind="class">Steinberg::Vst::IContextMenu</class>
    <class kind="struct">Steinberg::Vst::ParameterInfo</class>
    <class kind="class">Steinberg::Vst::IComponentHandler</class>
    <class kind="class">Steinberg::Vst::IComponentHandler2</class>
    <class kind="class">Steinberg::Vst::IEditController</class>
    <class kind="class">Steinberg::Vst::IEditController2</class>
    <class kind="class">Steinberg::Vst::IMidiMapping</class>
    <class kind="class">Steinberg::Vst::IEditControllerHostEditing</class>
    <class kind="struct">Steinberg::Vst::NoteOnEvent</class>
    <class kind="struct">Steinberg::Vst::NoteOffEvent</class>
    <class kind="struct">Steinberg::Vst::DataEvent</class>
    <class kind="struct">Steinberg::Vst::PolyPressureEvent</class>
    <class kind="struct">Steinberg::Vst::ChordEvent</class>
    <class kind="struct">Steinberg::Vst::ScaleEvent</class>
    <class kind="struct">Steinberg::Vst::Event</class>
    <class kind="class">Steinberg::Vst::IEventList</class>
    <class kind="class">Steinberg::Vst::IHostApplication</class>
    <class kind="class">Steinberg::Vst::IVst3ToVst2Wrapper</class>
    <class kind="class">Steinberg::Vst::IVst3ToAUWrapper</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioHost</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioConnectionNotification</class>
    <class kind="class">Steinberg::Vst::IInterAppAudioPresetManager</class>
    <class kind="class">Steinberg::Vst::IMessage</class>
    <class kind="class">Steinberg::Vst::IConnectionPoint</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionValueDescription</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionValueEvent</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionTextEvent</class>
    <class kind="struct">Steinberg::Vst::NoteExpressionTypeInfo</class>
    <class kind="class">Steinberg::Vst::INoteExpressionController</class>
    <class kind="struct">Steinberg::Vst::KeyswitchInfo</class>
    <class kind="class">Steinberg::Vst::IKeyswitchController</class>
    <class kind="class">Steinberg::Vst::IParamValueQueue</class>
    <class kind="class">Steinberg::Vst::IParameterChanges</class>
    <class kind="class">Steinberg::Vst::IParameterFinder</class>
    <class kind="class">Steinberg::Vst::IPrefetchableSupport</class>
    <class kind="struct">Steinberg::Vst::FrameRate</class>
    <class kind="struct">Steinberg::Vst::Chord</class>
    <class kind="struct">Steinberg::Vst::ProcessContext</class>
    <class kind="struct">Steinberg::Vst::RepresentationInfo</class>
    <class kind="class">Steinberg::Vst::IXmlRepresentationController</class>
    <class kind="struct">Steinberg::Vst::UnitInfo</class>
    <class kind="struct">Steinberg::Vst::ProgramListInfo</class>
    <class kind="class">Steinberg::Vst::IUnitHandler</class>
    <class kind="class">Steinberg::Vst::IUnitHandler2</class>
    <class kind="class">Steinberg::Vst::IUnitInfo</class>
    <class kind="class">Steinberg::Vst::IProgramListData</class>
    <class kind="class">Steinberg::Vst::IUnitData</class>
    <member kind="typedef">
      <type>int32</type>
      <name>KnobMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a98965411c9e542b7c2a99a46c8c1dfa2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>NoteExpressionTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a1f6dd3f1f6742382e7301c1db5587a4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>NoteExpressionValue</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a9e134142463a8ca477018e7f2c3220f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>KeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a62cc12c76af32650e16a6920962ddbf1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>PrefetchableSupport</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a8cd3dd5ea75e76ace81fd1a696544378</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char16</type>
      <name>TChar</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga9cc7040d53a88b14ecab90ffb052276d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TChar</type>
      <name>String128</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga4b750afeaca8056101ac7952543dfd47</anchor>
      <arglist>[128]</arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>CString</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaf857b729bfca1b912196dd4ff5421420</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>MediaType</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga5f0d28213b308d786ef7a1541d88368f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>BusDirection</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga0dc035dac7916366d61df365731f7b63</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>BusType</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaa6029db01759d30cfcb3504b84d5d04f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>IoMode</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga479361a38cb42c6a07bc6845a5801e55</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>UnitID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga6569c340fc68115670ee0161dd73b3ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>ParamValue</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga11508dccaa352a24d0ae6585a93f4641</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>ParamID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga1dac5893f4a5c27f986d4e51741b544c</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>ProgramListID</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaac31a9d9a63927ad6927f2a298888c22</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16</type>
      <name>CtrlNumber</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gaa67d0906fec66282a0c9488cb52162f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>TQuarterNotes</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gabf70aac64179b2b47bd877600a2e8c28</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>TSamples</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>gad2e841097395dbff119029f4684dad8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>ColorSpec</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga5b13d028fba1eee386ec9ac208c6238d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>float</type>
      <name>Sample32</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga353ad4086d31e4b7c57c9124965379a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>Sample64</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga8887669e1feb9270b120bcd725d0d4c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>double</type>
      <name>SampleRate</name>
      <anchorfile>group__vst3typedef.html</anchorfile>
      <anchor>ga11249ca544d179e7fa61b2200a092407</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64</type>
      <name>SpeakerArrangement</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54884a26d0b6dfa18eb919ea004775ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint64</type>
      <name>Speaker</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7a9fc6561fe897989fa3cea09ebb3250</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ComponentFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a626a070dcd2e025250f41b9c3f9817cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDistributable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a626a070dcd2e025250f41b9c3f9817cda3185111648c1599241528f1a7f523396</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSimpleModeSupported</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a626a070dcd2e025250f41b9c3f9817cdabc2edc9bb281cebe9cc6dc00a7cac0ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>SymbolicSampleSizes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>addd8f2e89ed5a540c9fce2c002f35c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSample32</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>addd8f2e89ed5a540c9fce2c002f35c06a199093967f5a183f86bf92bd7e61e31f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSample64</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>addd8f2e89ed5a540c9fce2c002f35c06a85edf5095f2282be74fce43030f1b900</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ProcessModes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRealtime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31af21cd390d9ad5f7929f3f0a3ab972e13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPrefetch</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31a3b1caa5d658939c027cbb7759358a88a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOffline</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae514554bd822c5370bf9496c70302e31a27042cfd9e04c874beea670ee64ac9ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>TailEnum</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a44451c855a6ae9e4ef150a8943f6bf80</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoTail</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a44451c855a6ae9e4ef150a8943f6bf80aff8084010aeec9469eab44f0c3ea2384</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInfiniteTail</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a44451c855a6ae9e4ef150a8943f6bf80ae5ba421c7a57bec9ca3a08b2c8b25d1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>MediaTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga576e5da9bdc49812cf65f803bb303ad5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAudio</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5aacc820a81fe3b4e8045b839cca0b91d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEvent</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5ae6a97de99980aeac9312e818af337d6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumMediaTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga576e5da9bdc49812cf65f803bb303ad5a803eb569c99a15c09609562d83577cfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>BusDirections</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga48a6eea2da1c202231eb653f3f764af2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInput</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga48a6eea2da1c202231eb653f3f764af2aa3512d23926af0e0dad8c3293443d04c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOutput</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga48a6eea2da1c202231eb653f3f764af2a1aeceb4d8bf67a4d84e082604da2cffd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>BusTypes</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>ga4849e8fa0da1b39bd3e0af87b441675a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kMain</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga4849e8fa0da1b39bd3e0af87b441675aa388e1f905d2b8eb0f734c83d9356885b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAux</name>
      <anchorfile>group__vstBus.html</anchorfile>
      <anchor>gga4849e8fa0da1b39bd3e0af87b441675aa0aedfd6f0f992c45d4f3620c9445292e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>IoModes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSimple</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554ea66def9a432bacb7d44369f4694d38fc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAdvanced</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554ea9419e79f15763b134e99b963cad57fab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOfflineProcessing</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aec143ffe42b4aa77d9b2cf27183a554ea069611c39f2a76f05446198e47ac9e35</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>RestartFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kReloadComponent</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a22ef5ace2e53c785283a595b6add28b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIoChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a47642f19b6da08e1bea896b6e06e630b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kParamValuesChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a67a358277112f9c5ac816474ae501a09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLatencyChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a560af1d548105a5e1c72f07a1b6fbd29</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kParamTitlesChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5af5308f6f5d92e718ccbd4cb0ca414907</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kMidiCCAssignmentChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5ae2e3ed4527f88e577a2aeb595bd853fd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteExpressionChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5aa11fe6e24349c6d2f7e0035dbc01c10b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIoTitlesChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5abf3d2b0a3519f44507b88691c0e6555e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPrefetchableSupportChanged</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a17867782006f9fdb2b72c16b0420bed5a2f4bc9de12259020c78fa4225f1d90b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>KnobModes</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCircularMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39a261944b6b143c6fc78fa1e9c783200ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRelativCircularMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39a98a7d7b1f331414876a55df149340e1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLinearMode</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>aaf58222f7d58268cdbe5849fd0670b39a248b4aaa79db639d5610c6e632269d7a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ControllerNumbers</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBankSelectMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a400f9814a81c3cf0116c43434527a9b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlModWheel</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab9b1ff6e499682378110ba27ecdc0ef7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBreath</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a1a2c7165ea14ef8dd1368b6816eb2a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlFoot</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a9d0c8ad268af6aab096688928d2bf649</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPortaTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a3bd68e966f818c58396b3132c9b63146</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataEntryMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a1b7add291c074e6e281251bcacd386c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVolume</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a6a0386205b02a353f63eecc7b80688bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBalance</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a9db5606058725c95d7196bba2d0177cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPan</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a337d918eada6158b59bfca78fc6d4ce9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlExpression</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab9ded45859a4edeefb3f2c01c9bac04e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEffect1</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a223f411fa52e53c3ffd88031f2fcb359</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEffect2</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6acf538d0974d6427c61c3413b70bca9ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC1</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a53873b95c93a8a77720d0d86b2521afe</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC2</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ae2b54af4acafdabff72856fa0a2c21ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC3</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a619824c5021185046074a448dd2e1127</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC4</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a30724a1acbad4a35c4230d7b10ee5a5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlBankSelectLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a04b8b07db0548b0419d9dfb3837ac140</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataEntryLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a94cfcf6be1a8525ce88b91a91b244001</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSustainOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a0f14ef4f47d122dd1f90179172798282</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPortaOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6afa5ea23fcf3bf9743c9c6565db31a9d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSustenutoOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a94bff95bfd75ce9c2afeae7e710a1f0b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSoftPedalOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a7d6db0586803346d573647dd0f5c7d78</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlLegatoFootSwOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a3edac2ceee92969eae4c563b36a572c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlHold2OnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a2232d72f0d853ffd05502341446b6d9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSoundVariation</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a6ac02b45ad9fc7b0a06dbcb4b08d85e8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlFilterCutoff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a0ffab21c076973287ee7989e951417a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlReleaseTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ae5def59ca1557626e92f98eba6bf677f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlAttackTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a415800319591ef39bb63da5d59c7b609</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlFilterResonance</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a461337f50eaa0cab0db2b3be464da521</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDecayTime</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a755907d022d33579f41ab3510c4a1e06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVibratoRate</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af7ef2c4385b727d4c937dab21e85f2ee</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVibratoDepth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a60de4c6db5a2ecc8696ef8a74c2d0604</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlVibratoDelay</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab1c1e0685fcc46278fafff8036837bba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlSoundCtrler10</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a35b80c1718f6464668b96df696efa264</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC5</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa88e418292a29bb46e148ab9dc999d4b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC6</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a6c72ad975c1231c1657260fc7954b27e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC7</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a76823c9e4b6f55bd74b71096f1e7cb09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlGPC8</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aede48ecdceaf4750c38194df4e3650d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPortaControl</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa56335dc1a7f013a779d79a2b0766260</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff1Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a215884f32ff11d44c0b26f641491d4f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff2Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a8c5c17883f573d79cfb912b8c18ddf86</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff3Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a93eb781dc5c8d3b0f3259da87ec7bd5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff4Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa1f3100a751b3bd3c521414eb4de9c09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlEff5Depth</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a34db4b2b6bf408977eb0889be68dbacb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataIncrement</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a8054b74403fa8ea7932e2a28aa4ef570</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlDataDecrement</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a68ef732ce338bae442a4bb5214ddb1d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlNRPNSelectLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af71bc8cfbfd46ba99c8dd6c9b3c098b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlNRPNSelectMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a16c5df1bc05e33ee2568b6b903a4835a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlRPNSelectLSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ab1839eb3b7fd6e17a404d5c549647fcb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlRPNSelectMSB</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ada4d74f05c77dc221713a293440695d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlAllSoundsOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af6d59e256dc288cf9012d8e14af1dd72</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlResetAllCtrlers</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a3ca0d4037f837edff5a519d759a6e2a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlLocalCtrlOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa2e16c34abda2b690c0ce04f71fba7ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlAllNotesOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ad27b2651ac1b6c1bedd2932fd7ceea1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlOmniModeOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6ad98437cf5dc4611e63d7541e8de2767d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlOmniModeOn</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aa6ecf7983324f4f64f82e49847306573</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPolyModeOnOff</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6aca03cffe46b62bd2c4aab05493e73bb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCtrlPolyModeOn</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a9d27c8af6ca2742411edac39853d4063</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAfterTouch</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a999df7727e25b9ef9062b19f91a26cbd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPitchBend</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6a39b06e8637d7c40f7a845d1c191f6d8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCountCtrlNumber</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a70ee68a13248febed5047cfa0fddf4e6af6ba8b5a08c0e4e7c4d8f6603df78bd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>NoteExpressionTypeIDs</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVolumeTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa18860e42c73ce4d8d66d49d6a662ab56</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPanTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa7148e2b1e53d751df8801134fa2059f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kTuningTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fac196000d5497502327e2b4f69e5037be</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVibratoTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa9fadf3f8d95dee835c8a0dcc9605b5af</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kExpressionTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa5e7ae2b2c476af4e9cdfd62902d68880</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kBrightnessTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa3eb020a0ad7005b2be7b70e373cc4431</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kTextTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa77f4a0bbec04c57e50441d58dddc753e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPhonemeTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa4ebd202862aff5265a6c1bcd901bd5b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCustomStart</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ad0ffd0330ad7b273e149549dc3fc394fa1c30475ef992f89f37c2fe0aafcc6283</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>KeyswitchTypeIDs</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteOnKeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2a19aaecc29b830ac94b9804b3f6b1aebb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOnTheFlyKeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2a585a87fa2b02e4aaf5e3280df2bb41c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOnReleaseKeyswitchTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2a0e2daa9cc892408b666cfdda855652c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kKeyRangeTypeID</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>ae4ba9459c2e2a5cc9c25e73b5f69b5a2abf9a3d392f6bd3ad7f0db013fd5dbc18</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ePrefetchableSupport</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsNeverPrefetchable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5a056d564a22f73e4649c99e1407a7585a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsYetPrefetchable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5aa43449cf5a0e596fa81b4a8498404f3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsNotYetPrefetchable</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5a836dd1dc4f2a6ad88f87dd23cb0cbed6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumPrefetchableSupport</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a18aa40e583fe3a75b569e7129e0d89b5a24f726f3f3303a115cf6755b6df6c984</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>IMessage *</type>
      <name>allocateMessage</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a80587fa5437b07a138473ce70d3b7dda</anchor>
      <arglist>(IHostApplication *host)</arglist>
    </member>
    <member kind="variable">
      <type>const int32</type>
      <name>kDefaultFactoryFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst.html</anchorfile>
      <anchor>a45d3e3dfb2fb99bbc186e4d9749f04ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerL</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga851521dbd075cd021659099076c16157</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga65243b42de36e6437862e02afb83ca72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerC</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabe9f3f14a428188b0fd0a229f15bf580</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad73c9bd8399f3587e67bbaf199ae60a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga29b55e791de7fa8d4efdb6948d40db09</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6509637bddb202148260ec274274c878</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga77b0a85020c9d06cd53d92a9f87fe6ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae771dcd8cf33e293b56b78ea7693544c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6e55ae87f6e0a3e7cf8e66ad0e631774</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerCs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5bc2d21ba0124c11a763e86ab63679ea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerSl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5380a69a0e649db11601a5841690ee2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerSr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae74ef8bbc9cc9012e28c09893fc80b6e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTm</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga37de8204c4573cb6d90bbdedf356b978</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga51b0837ee59b85d8c61c7aaee975f55a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6da088d7aa080b79f6dfa9a868bdb022</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTfr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7289205c458e1f2ec529f75ec40f68e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaea0ef00845b9443a18b63572e3c6338a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6aa3de86b02b284c84c12c3e3a772a7d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTrr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga97ce8834f00cbf7ffb2e4610f9aba296</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLfe2</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaac7d0cfc4cfa58abd88acd718b712f7b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerM</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5756399f47d692e0e5e587bcc8a06a9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerW</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga74bc55608435bdfd690634768269607b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerX</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga96ad07e593be8c0801adaa19994225c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerY</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa3c5fe33b5315a6205c6a76596584d1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerZ</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2d5d470e4abab2cca2eff61d52bf3c64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTsl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae27ef071e8ea85bdb2d5e35cb72c4313</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerTsr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac5f061a31de54df1c627e9ec947ac442</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerLcs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac91567b9c8119eb78d51f6cc398bd97f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerRcs</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf9740e0213852cf05d6352dc4132b0df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0874c430db7340ecf1c48962eaf436d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfc</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac45ef96ed94ff6232edffe4924f63e39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerBfr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2d6583c536b80d854cbd733eea9877f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerPl</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafc605342356ba44807fd1fa424a2bfe5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const Speaker</type>
      <name>kSpeakerPr</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5fb93993f0b3c038be5073e228dbb2b7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IAttributeList</name>
    <filename>classSteinberg_1_1Vst_1_1IAttributeList.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="typedef">
      <type>const char *</type>
      <name>AttrID</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>afbcb28dffd98773ba0287d888f16d00a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setInt</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>a25f64b8d44505736988478be3c3ea3db</anchor>
      <arglist>(AttrID id, int64 value)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getInt</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>aa17533c77e99f8fc18c7fb0dac5b1810</anchor>
      <arglist>(AttrID id, int64 &amp;value)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setFloat</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>a5fcd359925f64b686e4e7e08113aae97</anchor>
      <arglist>(AttrID id, double value)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getFloat</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>ab6b5900e7149bdf8a032ed98397f9cec</anchor>
      <arglist>(AttrID id, double &amp;value)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setString</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>a1e207585ce257192e8746924baaa9a7c</anchor>
      <arglist>(AttrID id, const TChar *string)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getString</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>aeae8fbbf7102a6af2c9d719007828f21</anchor>
      <arglist>(AttrID id, TChar *string, uint32 size)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setBinary</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>a42758e20e04c74cfddb895afd451fcb1</anchor>
      <arglist>(AttrID id, const void *data, uint32 size)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getBinary</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>a953759daf726675227113063aae1e5da</anchor>
      <arglist>(AttrID id, const void *&amp;data, uint32 &amp;size)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAttributeList.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IStreamAttributes</name>
    <filename>classSteinberg_1_1Vst_1_1IStreamAttributes.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getFileName</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IStreamAttributes.html</anchorfile>
      <anchor>ad8d90e182b51e387734f307c2c12a2f4</anchor>
      <arglist>(String128 name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IAttributeList *</type>
      <name>getAttributes</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IStreamAttributes.html</anchorfile>
      <anchor>a97646f7e4a63e3ba42454b35f80cd336</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IStreamAttributes.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ProcessSetup</name>
    <filename>structSteinberg_1_1Vst_1_1ProcessSetup.html</filename>
    <member kind="variable">
      <type>int32</type>
      <name>processMode</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessSetup.html</anchorfile>
      <anchor>a0f85383979879cac64621f4ffb25cae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>symbolicSampleSize</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessSetup.html</anchorfile>
      <anchor>a9392481e4890fb9c08015eed7c2655e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>maxSamplesPerBlock</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessSetup.html</anchorfile>
      <anchor>a41cd06a0c942a1b3f283092b893d0de3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SampleRate</type>
      <name>sampleRate</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessSetup.html</anchorfile>
      <anchor>afb7316112f9d8e74b30331957e7ca9b3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::AudioBusBuffers</name>
    <filename>structSteinberg_1_1Vst_1_1AudioBusBuffers.html</filename>
    <member kind="function">
      <type></type>
      <name>AudioBusBuffers</name>
      <anchorfile>structSteinberg_1_1Vst_1_1AudioBusBuffers.html</anchorfile>
      <anchor>a9b1b17da17d0a50b82b03273caae2b8b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>numChannels</name>
      <anchorfile>structSteinberg_1_1Vst_1_1AudioBusBuffers.html</anchorfile>
      <anchor>a84d2b789db2747bbef5244d1d15343a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint64</type>
      <name>silenceFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1AudioBusBuffers.html</anchorfile>
      <anchor>a2c73b926e22ddb05193b6edd16a008f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>union Steinberg::Vst::AudioBusBuffers::@0</type>
      <name>@1</name>
      <anchorfile>structSteinberg_1_1Vst_1_1AudioBusBuffers.html</anchorfile>
      <anchor>a304f3a50470e125560aa53899c152791</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Sample32 **</type>
      <name>channelBuffers32</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1AudioBusBuffers_1_1@0.html</anchorfile>
      <anchor>abac2239417d88a091cad5b4f917dc49a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Sample64 **</type>
      <name>channelBuffers64</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1AudioBusBuffers_1_1@0.html</anchorfile>
      <anchor>a0bbcd9a3e75d01b547097c91f9f659cf</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ProcessData</name>
    <filename>structSteinberg_1_1Vst_1_1ProcessData.html</filename>
    <member kind="function">
      <type></type>
      <name>ProcessData</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a100f97803b72565daedee80e34bbb7f0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>processMode</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a0f85383979879cac64621f4ffb25cae0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>symbolicSampleSize</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a9392481e4890fb9c08015eed7c2655e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>numSamples</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>aeb42971a4bd34d7baa27cff8d7e3cf26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>numInputs</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a852a74fc4e461ef086bac048313d2de9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>numOutputs</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a1338255f88bad5cf4fb714c71f92b61a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AudioBusBuffers *</type>
      <name>inputs</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a753be8bb50d436efaf9108959cb00cc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AudioBusBuffers *</type>
      <name>outputs</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a28fedbd059e95b0d0c0ebfe3b081b4e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IParameterChanges *</type>
      <name>inputParameterChanges</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a2c04010f689fda04c547aea84d894b3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IParameterChanges *</type>
      <name>outputParameterChanges</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>af08c4f7dfd9e456cc98ba0eb325993ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IEventList *</type>
      <name>inputEvents</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a55878a119a399f3e35f46272faac21b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>IEventList *</type>
      <name>outputEvents</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>a96d006aea0bdbfe90120674e485f0c1a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ProcessContext *</type>
      <name>processContext</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessData.html</anchorfile>
      <anchor>ad27334aa1361d4ff3b139ca305bf1fad</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IAudioProcessor</name>
    <filename>classSteinberg_1_1Vst_1_1IAudioProcessor.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setBusArrangements</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>ad3bc7bac3fd3b194122669be2a1ecc42</anchor>
      <arglist>(SpeakerArrangement *inputs, int32 numIns, SpeakerArrangement *outputs, int32 numOuts)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getBusArrangement</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>adac76e90d4a18622d818c8204f937f94</anchor>
      <arglist>(BusDirection dir, int32 index, SpeakerArrangement &amp;arr)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>canProcessSampleSize</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>aa1a6f9c030b9b2f5c0602dca309bb23b</anchor>
      <arglist>(int32 symbolicSampleSize)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual uint32</type>
      <name>getLatencySamples</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>af8884671ccefe68e0a86e72413a0fcf8</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setupProcessing</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>aefb5731b94dbc899a4a7e9cd1c96e6a2</anchor>
      <arglist>(ProcessSetup &amp;setup)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setProcessing</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>af252fd721b195b793f3a5dfffc069401</anchor>
      <arglist>(TBool state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>process</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>a6b98eb31cf38ba96a28b303c13c64e13</anchor>
      <arglist>(ProcessData &amp;data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual uint32</type>
      <name>getTailSamples</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>abb6b16a66b2356a4038a778b815dbbf3</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioProcessor.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IAudioPresentationLatency</name>
    <filename>classSteinberg_1_1Vst_1_1IAudioPresentationLatency.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setAudioPresentationLatencySamples</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioPresentationLatency.html</anchorfile>
      <anchor>a835590540d23f3bdc831cfdad872196e</anchor>
      <arglist>(BusDirection dir, int32 busIndex, uint32 latencyInSamples)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAudioPresentationLatency.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IAutomationState</name>
    <filename>classSteinberg_1_1Vst_1_1IAutomationState.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="enumeration">
      <name>AutomationStates</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>a787ff792c6d9eaf7652cef4454750adb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoAutomation</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>a787ff792c6d9eaf7652cef4454750adba50593589ab3b2b6bc94d914caf926e8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kReadState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>a787ff792c6d9eaf7652cef4454750adba27168d4bbe8c328ccc1c61c18e5e86cf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kWriteState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>a787ff792c6d9eaf7652cef4454750adbad3b29f3c6c1d4b45e32c9782ac13b4ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kReadWriteState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>a787ff792c6d9eaf7652cef4454750adba91c9e6284228f8fed9c09539698ff6c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setAutomationState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>a94a3fc5cff03de098873a4495a4d4c07</anchor>
      <arglist>(int32 state)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IAutomationState.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::BusInfo</name>
    <filename>structSteinberg_1_1Vst_1_1BusInfo.html</filename>
    <member kind="enumeration">
      <name>BusFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>a764af5c5b921de1cab2eca6565ea5d1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDefaultActive</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>a764af5c5b921de1cab2eca6565ea5d1eace2379dbcd61f72660abb9243cb55bc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>MediaType</type>
      <name>mediaType</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>ac12e8d0c4308238a04fefe98e39b1514</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>BusDirection</type>
      <name>direction</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>abb6aef5950e795ec6507d07a5c8bd4fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>channelCount</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>ab22e24964d55652336d526a41e5a2309</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>a1b0ba9a9710fe4cbad60cb03e38a02d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>BusType</type>
      <name>busType</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>a795177c339bd0b25de0ea4189aa6c893</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1BusInfo.html</anchorfile>
      <anchor>a81a27ce50e78368b0d0de1e8767fd32d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::RoutingInfo</name>
    <filename>structSteinberg_1_1Vst_1_1RoutingInfo.html</filename>
    <member kind="variable">
      <type>MediaType</type>
      <name>mediaType</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RoutingInfo.html</anchorfile>
      <anchor>ac12e8d0c4308238a04fefe98e39b1514</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>busIndex</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RoutingInfo.html</anchorfile>
      <anchor>acd2bbbb2eae99e9e00ac1517dbf7958d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>channel</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RoutingInfo.html</anchorfile>
      <anchor>ac94d05ff826555bbf47fdfe8d3e4cd2d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IComponent</name>
    <filename>classSteinberg_1_1Vst_1_1IComponent.html</filename>
    <base>Steinberg::IPluginBase</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getControllerClassId</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a8aa65685068ad033af57b1497926b689</anchor>
      <arglist>(TUID classId)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setIoMode</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a4618e7358890d549f990010bea4a4137</anchor>
      <arglist>(IoMode mode)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getBusCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a5a0edc226a66259a6b8fe6f693101d77</anchor>
      <arglist>(MediaType type, BusDirection dir)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getBusInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a41b0e971a0ff153a4eb34274750b0c91</anchor>
      <arglist>(MediaType type, BusDirection dir, int32 index, BusInfo &amp;bus)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getRoutingInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>aa0ffeccad3c44364a199ce56365a4c12</anchor>
      <arglist>(RoutingInfo &amp;inInfo, RoutingInfo &amp;outInfo)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>activateBus</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a3ab7d06aaefe03da1fcd1819f1261050</anchor>
      <arglist>(MediaType type, BusDirection dir, int32 index, TBool state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setActive</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a0a840e8077eb74ec429b8007c7b83517</anchor>
      <arglist>(TBool state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a77ac39bcc5c4b15818b1a87de2573805</anchor>
      <arglist>(IBStream *state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>a10db03106be8ba89d23859fa6be5d9f6</anchor>
      <arglist>(IBStream *state)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponent.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IComponentHandler3</name>
    <filename>classSteinberg_1_1Vst_1_1IComponentHandler3.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual IContextMenu *</type>
      <name>createContextMenu</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler3.html</anchorfile>
      <anchor>a0c91e0b43003a34a7f43d0c4b33aa604</anchor>
      <arglist>(IPlugView *plugView, const ParamID *paramID)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler3.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
    <docanchor file="classSteinberg_1_1Vst_1_1IComponentHandler3">IContextMenuExample</docanchor>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IContextMenuTarget</name>
    <filename>classSteinberg_1_1Vst_1_1IContextMenuTarget.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>executeMenuItem</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenuTarget.html</anchorfile>
      <anchor>a4a1e98d2d18ded53b636b7f36cb9f83f</anchor>
      <arglist>(int32 tag)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenuTarget.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IContextMenu</name>
    <filename>classSteinberg_1_1Vst_1_1IContextMenu.html</filename>
    <base>Steinberg::FUnknown</base>
    <class kind="struct">Steinberg::Vst::IContextMenu::Item</class>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getItemCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenu.html</anchorfile>
      <anchor>ac0c7c1da210637ba2bb458b21580272f</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getItem</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenu.html</anchorfile>
      <anchor>a241e6e88af766e7075c675215a62c82d</anchor>
      <arglist>(int32 index, Item &amp;item, IContextMenuTarget **target)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>addItem</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenu.html</anchorfile>
      <anchor>ac172d5fa00b2028a352c704dd906f236</anchor>
      <arglist>(const Item &amp;item, IContextMenuTarget *target)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>removeItem</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenu.html</anchorfile>
      <anchor>aa52f902d26c33aebde2ee96beb9fae28</anchor>
      <arglist>(const Item &amp;item, IContextMenuTarget *target)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>popup</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenu.html</anchorfile>
      <anchor>a8d6e113be32dfccabcacca0c81ee6f10</anchor>
      <arglist>(UCoord x, UCoord y)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IContextMenu.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::IContextMenu::Item</name>
    <filename>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</filename>
    <member kind="enumeration">
      <name>Flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>aa705cf7e79a21c2352b00ffe20cd295f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsSeparator</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>aa705cf7e79a21c2352b00ffe20cd295faeeede7e231c10707303ad1084bb20519</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsDisabled</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>aa705cf7e79a21c2352b00ffe20cd295fa2206f46f57bc94b30fe890f42c64c303</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsChecked</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>aa705cf7e79a21c2352b00ffe20cd295fa877e05e66286af1b983c061e6d46dda0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsGroupStart</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>aa705cf7e79a21c2352b00ffe20cd295fa9d61fc687d4b6b50d56db8afe6011d57</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsGroupEnd</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>aa705cf7e79a21c2352b00ffe20cd295fade2b2aeffaec861931cf871d56e22bcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>a1b0ba9a9710fe4cbad60cb03e38a02d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>tag</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>a7cba719b5e6843c30b66241e6181688b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1IContextMenu_1_1Item.html</anchorfile>
      <anchor>a8ffba1d4311e48ae488bc118f20d7edb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ParameterInfo</name>
    <filename>structSteinberg_1_1Vst_1_1ParameterInfo.html</filename>
    <member kind="enumeration">
      <name>ParameterFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCanAutomate</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645af38562ef6dde00a339d67f9be4ec3a31</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsReadOnly</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645a6d0f0315e38602bca6847abb752ab10f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsWrapAround</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645ab6db0c541e451f24f819ab231f3ecf96</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsList</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645a1d80e03f3f6f05a10b4bd1778c00e901</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsProgramChange</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645a517665185bca1f4f3d77ce0a6468b8e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsBypass</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ae3a5143ca8d0e271dbc259645a4ae645af9d12238330266160c4c36bac7a76622</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ParamID</type>
      <name>id</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a35a8e8c7048fc190f19479b6210eaf08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>title</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a2a11c98c9656a37e74885b25aa4e1bb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>shortTitle</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a1e6fd281b54c5303b365a179c567bdce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>units</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a1c553556d9764875c3e04ac9eea2f247</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>stepCount</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>ac1efeff62e4ba9aea101c3327e0b5c4d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ParamValue</type>
      <name>defaultNormalizedValue</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a768a5f1990023d227c5162eab6a99376</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UnitID</type>
      <name>unitId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a4d2e0574df0f6d36f26fae1ad759a14f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ParameterInfo.html</anchorfile>
      <anchor>a8ffba1d4311e48ae488bc118f20d7edb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IComponentHandler</name>
    <filename>classSteinberg_1_1Vst_1_1IComponentHandler.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>beginEdit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler.html</anchorfile>
      <anchor>a8456ad739430267a12dda11a53fe9223</anchor>
      <arglist>(ParamID id)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>performEdit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler.html</anchorfile>
      <anchor>a135d4e76355ef0ba0a4162a0546d5f93</anchor>
      <arglist>(ParamID id, ParamValue valueNormalized)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>endEdit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler.html</anchorfile>
      <anchor>ae380206486b11f000cad7c0d9b6e877c</anchor>
      <arglist>(ParamID id)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>restartComponent</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler.html</anchorfile>
      <anchor>a1f283573728cf0807224c5ebdf3ec3a6</anchor>
      <arglist>(int32 flags)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IComponentHandler2</name>
    <filename>classSteinberg_1_1Vst_1_1IComponentHandler2.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setDirty</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler2.html</anchorfile>
      <anchor>aa457d0550984879c4094c578b914fb6d</anchor>
      <arglist>(TBool state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>requestOpenEditor</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler2.html</anchorfile>
      <anchor>ac7d37d88b53e9517e1b696bef2d47fa5</anchor>
      <arglist>(FIDString name=ViewType::kEditor)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>startGroupEdit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler2.html</anchorfile>
      <anchor>aba339113df404a6b3c557774d4aa9102</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>finishGroupEdit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler2.html</anchorfile>
      <anchor>adbdc10ff7ecd96fa365ad4f98d57b55e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IComponentHandler2.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IEditController</name>
    <filename>classSteinberg_1_1Vst_1_1IEditController.html</filename>
    <base>Steinberg::IPluginBase</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setComponentState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>a4c2e1cafd88143fda2767a9c7ba5d48f</anchor>
      <arglist>(IBStream *state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>a77ac39bcc5c4b15818b1a87de2573805</anchor>
      <arglist>(IBStream *state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getState</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>a10db03106be8ba89d23859fa6be5d9f6</anchor>
      <arglist>(IBStream *state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getParameterCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>ab6ffbb8e3bf6f4829ab1c9c23fe935a1</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getParameterInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>a0ba78602ecf2f5e8d747d8b01d4cfb6c</anchor>
      <arglist>(int32 paramIndex, ParameterInfo &amp;info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getParamStringByValue</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>aab2f0b853e75361d331b667e7893962e</anchor>
      <arglist>(ParamID id, ParamValue valueNormalized, String128 string)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getParamValueByString</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>af4254a0360b21f8871a61c62fb317058</anchor>
      <arglist>(ParamID id, TChar *string, ParamValue &amp;valueNormalized)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ParamValue</type>
      <name>normalizedParamToPlain</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>a849747dc98909312b4cdbdeea82dbae0</anchor>
      <arglist>(ParamID id, ParamValue valueNormalized)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ParamValue</type>
      <name>plainParamToNormalized</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>ae9706616ae6d938bbf102954f8f2f110</anchor>
      <arglist>(ParamID id, ParamValue plainValue)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ParamValue</type>
      <name>getParamNormalized</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>ac5abbadd4c8326fae66fd1e63bdc15b3</anchor>
      <arglist>(ParamID id)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setParamNormalized</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>aded549c5b0f342a23dee18cc41ece6b8</anchor>
      <arglist>(ParamID id, ParamValue value)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setComponentHandler</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>aab5ccab5fd1cc1cd0a59afd90279dd81</anchor>
      <arglist>(IComponentHandler *handler)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IPlugView *</type>
      <name>createView</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>a1fa4ed10cc0979e5559045104c998b1a</anchor>
      <arglist>(FIDString name)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IEditController2</name>
    <filename>classSteinberg_1_1Vst_1_1IEditController2.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setKnobMode</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController2.html</anchorfile>
      <anchor>ad38ac70a9efcc0cfee8ac0cc2b80e648</anchor>
      <arglist>(KnobMode mode)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>openHelp</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController2.html</anchorfile>
      <anchor>a749ceb08d2f33b5b12cdc59172d8a7c3</anchor>
      <arglist>(TBool onlyCheck)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>openAboutBox</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController2.html</anchorfile>
      <anchor>aa52846d39014c3ca95224fa98930e7a8</anchor>
      <arglist>(TBool onlyCheck)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditController2.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IMidiMapping</name>
    <filename>classSteinberg_1_1Vst_1_1IMidiMapping.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getMidiControllerAssignment</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IMidiMapping.html</anchorfile>
      <anchor>a62b10d017d6b2bc0e390e30d0e2a823b</anchor>
      <arglist>(int32 busIndex, int16 channel, CtrlNumber midiControllerNumber, ParamID &amp;id)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IMidiMapping.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IEditControllerHostEditing</name>
    <filename>classSteinberg_1_1Vst_1_1IEditControllerHostEditing.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>beginEditFromHost</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditControllerHostEditing.html</anchorfile>
      <anchor>a97cc85e97b22ff0d4fb9b5109a1a2bf2</anchor>
      <arglist>(ParamID paramID)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>endEditFromHost</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditControllerHostEditing.html</anchorfile>
      <anchor>a589c94be69d4ee5ed29cf62e437fecbb</anchor>
      <arglist>(ParamID paramID)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEditControllerHostEditing.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::NoteOnEvent</name>
    <filename>structSteinberg_1_1Vst_1_1NoteOnEvent.html</filename>
    <member kind="variable">
      <type>int16</type>
      <name>channel</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOnEvent.html</anchorfile>
      <anchor>a24c684341d44436846644b0dcbb0c6f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>pitch</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOnEvent.html</anchorfile>
      <anchor>ac8fce98a527fd344e62bf8e259ff00a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>tuning</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOnEvent.html</anchorfile>
      <anchor>a0fb775127789ce2215c83775414e6f37</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>velocity</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOnEvent.html</anchorfile>
      <anchor>ac46e821ae08930cc9e257642e34275a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>length</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOnEvent.html</anchorfile>
      <anchor>ab91fc0c68b937719298bf91ba200640c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>noteId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOnEvent.html</anchorfile>
      <anchor>a10cb194b5adb5b7bd968688cdd58de53</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::NoteOffEvent</name>
    <filename>structSteinberg_1_1Vst_1_1NoteOffEvent.html</filename>
    <member kind="variable">
      <type>int16</type>
      <name>channel</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOffEvent.html</anchorfile>
      <anchor>a24c684341d44436846644b0dcbb0c6f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>pitch</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOffEvent.html</anchorfile>
      <anchor>ac8fce98a527fd344e62bf8e259ff00a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>velocity</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOffEvent.html</anchorfile>
      <anchor>ac46e821ae08930cc9e257642e34275a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>noteId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOffEvent.html</anchorfile>
      <anchor>a10cb194b5adb5b7bd968688cdd58de53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>tuning</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteOffEvent.html</anchorfile>
      <anchor>a0fb775127789ce2215c83775414e6f37</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::DataEvent</name>
    <filename>structSteinberg_1_1Vst_1_1DataEvent.html</filename>
    <member kind="enumeration">
      <name>DataTypes</name>
      <anchorfile>structSteinberg_1_1Vst_1_1DataEvent.html</anchorfile>
      <anchor>afb6eb4f28419b652027fad41104a6d22</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kMidiSysEx</name>
      <anchorfile>structSteinberg_1_1Vst_1_1DataEvent.html</anchorfile>
      <anchor>afb6eb4f28419b652027fad41104a6d22ab06d86440be6a85eccce4df100ce8e79</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>size</name>
      <anchorfile>structSteinberg_1_1Vst_1_1DataEvent.html</anchorfile>
      <anchor>a0d40f1591c12f359c3fa3f982f9a221d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>type</name>
      <anchorfile>structSteinberg_1_1Vst_1_1DataEvent.html</anchorfile>
      <anchor>af356674bbaaf9bb782af79059eef1346</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const uint8 *</type>
      <name>bytes</name>
      <anchorfile>structSteinberg_1_1Vst_1_1DataEvent.html</anchorfile>
      <anchor>ab0e4bfcd0606119dacd07fd9388de747</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::PolyPressureEvent</name>
    <filename>structSteinberg_1_1Vst_1_1PolyPressureEvent.html</filename>
    <member kind="variable">
      <type>int16</type>
      <name>channel</name>
      <anchorfile>structSteinberg_1_1Vst_1_1PolyPressureEvent.html</anchorfile>
      <anchor>a24c684341d44436846644b0dcbb0c6f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>pitch</name>
      <anchorfile>structSteinberg_1_1Vst_1_1PolyPressureEvent.html</anchorfile>
      <anchor>ac8fce98a527fd344e62bf8e259ff00a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>float</type>
      <name>pressure</name>
      <anchorfile>structSteinberg_1_1Vst_1_1PolyPressureEvent.html</anchorfile>
      <anchor>ac870e1249bab4a2a68cc4126761d24ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>noteId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1PolyPressureEvent.html</anchorfile>
      <anchor>a10cb194b5adb5b7bd968688cdd58de53</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ChordEvent</name>
    <filename>structSteinberg_1_1Vst_1_1ChordEvent.html</filename>
    <member kind="variable">
      <type>int16</type>
      <name>root</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ChordEvent.html</anchorfile>
      <anchor>a109c9addbf0865629fcb10fede22de26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>bassNote</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ChordEvent.html</anchorfile>
      <anchor>a4f5c7e14d27cd2000f90c5fca2adb9a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>mask</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ChordEvent.html</anchorfile>
      <anchor>a831873f40a39122089d004e06f800d17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint16</type>
      <name>textLen</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ChordEvent.html</anchorfile>
      <anchor>a4f6335dfe1239867b906eb8a304b5984</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const TChar *</type>
      <name>text</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ChordEvent.html</anchorfile>
      <anchor>aa87f60a3f4718be230eba436bdd0d610</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ScaleEvent</name>
    <filename>structSteinberg_1_1Vst_1_1ScaleEvent.html</filename>
    <member kind="variable">
      <type>int16</type>
      <name>root</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ScaleEvent.html</anchorfile>
      <anchor>a109c9addbf0865629fcb10fede22de26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>mask</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ScaleEvent.html</anchorfile>
      <anchor>a831873f40a39122089d004e06f800d17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint16</type>
      <name>textLen</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ScaleEvent.html</anchorfile>
      <anchor>a4f6335dfe1239867b906eb8a304b5984</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const TChar *</type>
      <name>text</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ScaleEvent.html</anchorfile>
      <anchor>aa87f60a3f4718be230eba436bdd0d610</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::Event</name>
    <filename>structSteinberg_1_1Vst_1_1Event.html</filename>
    <member kind="enumeration">
      <name>EventFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>ab52fb080a2898a94efbd54969f61e5d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsLive</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>ab52fb080a2898a94efbd54969f61e5d5a8b9e49c3d94641913c8098c23c25b125</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUserReserved1</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>ab52fb080a2898a94efbd54969f61e5d5a62708aba77581182dffd7458cf6b621e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUserReserved2</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>ab52fb080a2898a94efbd54969f61e5d5aa0fac77d8173c8ca51fb73ae6177181b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>EventTypes</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteOnEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a6969fd08df9f0611a6566e93c0c31e42</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteOffEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a1cabbcf11ce8779b94e6cfa480d87b09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDataEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a62a25bd1cd5f061e9897cc7315f6763a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPolyPressureEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a5800a14018dee96cd41f5f10691b8b85</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteExpressionValueEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a18b62187f591a8e615ef6c934461db2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoteExpressionTextEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a494e407c199f55129c93f53bd5cada93</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kChordEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a4e0a8c28a95df34b9c12c0f226e6923d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kScaleEvent</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a914d2da0ec9f0e22cd5e400bc1f968b8a1fcf9cd0ded093f84e9b0a8177679ad4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>busIndex</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>acd2bbbb2eae99e9e00ac1517dbf7958d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>sampleOffset</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a9b2081be7783cb98c534aa1ff955ac5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TQuarterNotes</type>
      <name>ppqPosition</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a5da7304404b66954c04f2c61242b4336</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint16</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>ae15f0808741c35cb9a8d231105d8beea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint16</type>
      <name>type</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>af9b2e23a8f32ca09cfeb7d828436fb01</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>union Steinberg::Vst::Event::@2</type>
      <name>@3</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Event.html</anchorfile>
      <anchor>a79b8d4d8b2ded17b614c2fac7bb88406</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteOnEvent</type>
      <name>noteOn</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>aa7ce3c35c89b80c286a732eb1794307c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteOffEvent</type>
      <name>noteOff</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>a21c98848a005b27ed5ed3951555d94a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>DataEvent</type>
      <name>data</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>a4f0bc42a72c611ac6c177661d617b6dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>PolyPressureEvent</type>
      <name>polyPressure</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>acc27ddf2b1e504795c7724921eb57286</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionValueEvent</type>
      <name>noteExpressionValue</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>a0f35f105b944d86baed64153c9544b38</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionTextEvent</type>
      <name>noteExpressionText</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>a7bd5bf2b37708149b2c318f8fd669d50</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ChordEvent</type>
      <name>chord</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>a990c632f42079b7d085d2b3747e2e919</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ScaleEvent</type>
      <name>scale</name>
      <anchorfile>unionSteinberg_1_1Vst_1_1Event_1_1@2.html</anchorfile>
      <anchor>aa5ba30ca69cff19d9c45599238388230</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IEventList</name>
    <filename>classSteinberg_1_1Vst_1_1IEventList.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getEventCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEventList.html</anchorfile>
      <anchor>a2e0abd231c54bd5c5a5e6f455169311e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getEvent</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEventList.html</anchorfile>
      <anchor>a604181f48ab23957b7b9fcbb09c97fc1</anchor>
      <arglist>(int32 index, Event &amp;e)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>addEvent</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEventList.html</anchorfile>
      <anchor>aa58736dbdfb425c6c8f12b2129626370</anchor>
      <arglist>(Event &amp;e)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IEventList.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IHostApplication</name>
    <filename>classSteinberg_1_1Vst_1_1IHostApplication.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getName</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IHostApplication.html</anchorfile>
      <anchor>a701520a52c46a25fdaca39ca4a28177f</anchor>
      <arglist>(String128 name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>createInstance</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IHostApplication.html</anchorfile>
      <anchor>a931e5a2ff8867bd8dfdbae1e42b78106</anchor>
      <arglist>(TUID cid, TUID _iid, void **obj)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IHostApplication.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IVst3ToVst2Wrapper</name>
    <filename>classSteinberg_1_1Vst_1_1IVst3ToVst2Wrapper.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IVst3ToVst2Wrapper.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IVst3ToAUWrapper</name>
    <filename>classSteinberg_1_1Vst_1_1IVst3ToAUWrapper.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IVst3ToAUWrapper.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IInterAppAudioHost</name>
    <filename>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getScreenSize</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>a36e1db0db800560f4c70031e3ebc0a31</anchor>
      <arglist>(ViewRect *size, float *scale)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>connectedToHost</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>a85482697be15b427dd93a5488beaf9a8</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>switchToHost</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>a8b0ced23b7d8e83d9bae5dcbc324f403</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>sendRemoteControlEvent</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>a8d4eef17f1de81905a5936f9849de029</anchor>
      <arglist>(uint32 event)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getHostIcon</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>a4ec60e594f7ad548f697c39c252191d0</anchor>
      <arglist>(void **icon)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>scheduleEventFromUI</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>a83a79b604432e251a09cbfcdc0b367a8</anchor>
      <arglist>(Event &amp;event)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IInterAppAudioPresetManager *</type>
      <name>createPresetManager</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>ae2524b3ead8126059bc897d1a97047e5</anchor>
      <arglist>(const TUID &amp;cid)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>showSettingsView</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>aa6d66ecd68a991b8c12c40f39a5799c1</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioHost.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IInterAppAudioConnectionNotification</name>
    <filename>classSteinberg_1_1Vst_1_1IInterAppAudioConnectionNotification.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>onInterAppAudioConnectionStateChange</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioConnectionNotification.html</anchorfile>
      <anchor>a57d886cb53419b840fe75049f3f4d6a6</anchor>
      <arglist>(TBool newState)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioConnectionNotification.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IInterAppAudioPresetManager</name>
    <filename>classSteinberg_1_1Vst_1_1IInterAppAudioPresetManager.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>runLoadPresetBrowser</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioPresetManager.html</anchorfile>
      <anchor>a74e27f28ba190ed2834ddcf99f8b13f7</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>runSavePresetBrowser</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioPresetManager.html</anchorfile>
      <anchor>a236a03d49a8c928c39c4191881ba5406</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>loadNextPreset</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioPresetManager.html</anchorfile>
      <anchor>a6d707548076cb27d64e04c155ccba7d2</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>loadPreviousPreset</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioPresetManager.html</anchorfile>
      <anchor>a726a6db5c25f476bcb9d0f8bc7f24245</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IInterAppAudioPresetManager.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IMessage</name>
    <filename>classSteinberg_1_1Vst_1_1IMessage.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual FIDString</type>
      <name>getMessageID</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IMessage.html</anchorfile>
      <anchor>a56ba9d2e0ca1aa0d7f56a32e6f5d06f3</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setMessageID</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IMessage.html</anchorfile>
      <anchor>a5a8458da03aa22462a3cfdb33af08dfe</anchor>
      <arglist>(FIDString id)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IAttributeList *</type>
      <name>getAttributes</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IMessage.html</anchorfile>
      <anchor>a97646f7e4a63e3ba42454b35f80cd336</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IMessage.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IConnectionPoint</name>
    <filename>classSteinberg_1_1Vst_1_1IConnectionPoint.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>connect</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IConnectionPoint.html</anchorfile>
      <anchor>aa65d68182357737c7a1f7736400565c2</anchor>
      <arglist>(IConnectionPoint *other)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>disconnect</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IConnectionPoint.html</anchorfile>
      <anchor>ad85bd437968bec6e403fb3cba699b01e</anchor>
      <arglist>(IConnectionPoint *other)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>notify</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IConnectionPoint.html</anchorfile>
      <anchor>a870cdbe19a2c9798e1e68fab65e72a77</anchor>
      <arglist>(IMessage *message)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IConnectionPoint.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::NoteExpressionValueDescription</name>
    <filename>structSteinberg_1_1Vst_1_1NoteExpressionValueDescription.html</filename>
    <member kind="variable">
      <type>NoteExpressionValue</type>
      <name>defaultValue</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueDescription.html</anchorfile>
      <anchor>ab03e603a79dcaa73a796db8b64eb04c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionValue</type>
      <name>minimum</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueDescription.html</anchorfile>
      <anchor>a8833b2425f0317bad726e4c6414b0e79</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionValue</type>
      <name>maximum</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueDescription.html</anchorfile>
      <anchor>aa016d7a46efed60f91695a5159ecfbcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>stepCount</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueDescription.html</anchorfile>
      <anchor>ac1efeff62e4ba9aea101c3327e0b5c4d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::NoteExpressionValueEvent</name>
    <filename>structSteinberg_1_1Vst_1_1NoteExpressionValueEvent.html</filename>
    <member kind="variable">
      <type>NoteExpressionTypeID</type>
      <name>typeId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueEvent.html</anchorfile>
      <anchor>a8cecee2171d29eb98141c9364baa346e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>noteId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueEvent.html</anchorfile>
      <anchor>a10cb194b5adb5b7bd968688cdd58de53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionValue</type>
      <name>value</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionValueEvent.html</anchorfile>
      <anchor>af14764c28881d46fddcda927a2c107ce</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::NoteExpressionTextEvent</name>
    <filename>structSteinberg_1_1Vst_1_1NoteExpressionTextEvent.html</filename>
    <member kind="variable">
      <type>NoteExpressionTypeID</type>
      <name>typeId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTextEvent.html</anchorfile>
      <anchor>a8cecee2171d29eb98141c9364baa346e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>noteId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTextEvent.html</anchorfile>
      <anchor>a10cb194b5adb5b7bd968688cdd58de53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>textLen</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTextEvent.html</anchorfile>
      <anchor>abb89858832dfc88064874fe14e4ed2ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const TChar *</type>
      <name>text</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTextEvent.html</anchorfile>
      <anchor>aa87f60a3f4718be230eba436bdd0d610</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::NoteExpressionTypeInfo</name>
    <filename>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</filename>
    <member kind="enumeration">
      <name>NoteExpressionTypeFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1de059ac90343b011aac2c14646d7ec8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsBipolar</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1de059ac90343b011aac2c14646d7ec8a0cf6a1d666d333bc4c2863557e013245</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsOneShot</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1de059ac90343b011aac2c14646d7ec8aa9c080ea5298ee26364097f0ebc2c736</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIsAbsolute</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1de059ac90343b011aac2c14646d7ec8aef666cae7e4e80d922765cfe99da015f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAssociatedParameterIDValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1de059ac90343b011aac2c14646d7ec8a357469987a4f81967855bfc6358a3f39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionTypeID</type>
      <name>typeId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a8cecee2171d29eb98141c9364baa346e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>title</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a2a11c98c9656a37e74885b25aa4e1bb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>shortTitle</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1e6fd281b54c5303b365a179c567bdce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>units</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a1c553556d9764875c3e04ac9eea2f247</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>unitId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a95d91e1e4eb7bc92946f7ab1e55ef1ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NoteExpressionValueDescription</type>
      <name>valueDesc</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>afc1ccb5fcb79e9799e93d05f443ff165</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ParamID</type>
      <name>associatedParameterId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>aae480d52fcccd8e7b0891f6a7b1d1527</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1NoteExpressionTypeInfo.html</anchorfile>
      <anchor>a8ffba1d4311e48ae488bc118f20d7edb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::INoteExpressionController</name>
    <filename>classSteinberg_1_1Vst_1_1INoteExpressionController.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getNoteExpressionCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1INoteExpressionController.html</anchorfile>
      <anchor>a197a1b66cc45ba1935d9ce0894b1ee02</anchor>
      <arglist>(int32 busIndex, int16 channel)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getNoteExpressionInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1INoteExpressionController.html</anchorfile>
      <anchor>ab12d543cbd83560a9f098ed4a5c76af8</anchor>
      <arglist>(int32 busIndex, int16 channel, int32 noteExpressionIndex, NoteExpressionTypeInfo &amp;info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getNoteExpressionStringByValue</name>
      <anchorfile>classSteinberg_1_1Vst_1_1INoteExpressionController.html</anchorfile>
      <anchor>a457f017fc3566d143914e44523425d23</anchor>
      <arglist>(int32 busIndex, int16 channel, NoteExpressionTypeID id, NoteExpressionValue valueNormalized, String128 string)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getNoteExpressionValueByString</name>
      <anchorfile>classSteinberg_1_1Vst_1_1INoteExpressionController.html</anchorfile>
      <anchor>ab79e988315e33b4c30c8f2bd47a0cffc</anchor>
      <arglist>(int32 busIndex, int16 channel, NoteExpressionTypeID id, const TChar *string, NoteExpressionValue &amp;valueNormalized)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1INoteExpressionController.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::KeyswitchInfo</name>
    <filename>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</filename>
    <member kind="variable">
      <type>KeyswitchTypeID</type>
      <name>typeId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>adc03aa09c3341a6a08543d04e31897ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>title</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>a2a11c98c9656a37e74885b25aa4e1bb7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>shortTitle</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>a1e6fd281b54c5303b365a179c567bdce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>keyswitchMin</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>a7e41662b9becfa89e607e82e3b38d264</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>keyswitchMax</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>a5d0850732b1e666e3290b647f9ecf827</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>keyRemapped</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>aaa5123c15f3514c8e4db594017c44130</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>unitId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>a95d91e1e4eb7bc92946f7ab1e55ef1ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1KeyswitchInfo.html</anchorfile>
      <anchor>a8ffba1d4311e48ae488bc118f20d7edb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IKeyswitchController</name>
    <filename>classSteinberg_1_1Vst_1_1IKeyswitchController.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getKeyswitchCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IKeyswitchController.html</anchorfile>
      <anchor>aa98a707edb1b58d05da0c50e38983a4e</anchor>
      <arglist>(int32 busIndex, int16 channel)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getKeyswitchInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IKeyswitchController.html</anchorfile>
      <anchor>a8193190849039a70d08b084241d29e38</anchor>
      <arglist>(int32 busIndex, int16 channel, int32 keySwitchIndex, KeyswitchInfo &amp;info)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IKeyswitchController.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IParamValueQueue</name>
    <filename>classSteinberg_1_1Vst_1_1IParamValueQueue.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual ParamID</type>
      <name>getParameterId</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParamValueQueue.html</anchorfile>
      <anchor>abe1cf3f748932181aa3a80a10feb3d2b</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getPointCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParamValueQueue.html</anchorfile>
      <anchor>a89cf5bac536a4a0a97ab81c8903ff3d7</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getPoint</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParamValueQueue.html</anchorfile>
      <anchor>ac10774ecd1a00877d5d1b315894be1a7</anchor>
      <arglist>(int32 index, int32 &amp;sampleOffset, ParamValue &amp;value)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>addPoint</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParamValueQueue.html</anchorfile>
      <anchor>acf78c435afe4e71b1be548aa03ef4e3a</anchor>
      <arglist>(int32 sampleOffset, ParamValue value, int32 &amp;index)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParamValueQueue.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IParameterChanges</name>
    <filename>classSteinberg_1_1Vst_1_1IParameterChanges.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getParameterCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParameterChanges.html</anchorfile>
      <anchor>ab6ffbb8e3bf6f4829ab1c9c23fe935a1</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IParamValueQueue *</type>
      <name>getParameterData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParameterChanges.html</anchorfile>
      <anchor>a6afbd15adb1f5b2f6d2101ad73b5c375</anchor>
      <arglist>(int32 index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IParamValueQueue *</type>
      <name>addParameterData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParameterChanges.html</anchorfile>
      <anchor>af8399d51b057de8ac28ccaa88b9a88e5</anchor>
      <arglist>(const Vst::ParamID &amp;id, int32 &amp;index)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParameterChanges.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IParameterFinder</name>
    <filename>classSteinberg_1_1Vst_1_1IParameterFinder.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>findParameter</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParameterFinder.html</anchorfile>
      <anchor>afd8d9733eee7b052280d7ddd0057b8ea</anchor>
      <arglist>(int32 xPos, int32 yPos, ParamID &amp;resultTag)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IParameterFinder.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IPrefetchableSupport</name>
    <filename>classSteinberg_1_1Vst_1_1IPrefetchableSupport.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getPrefetchableSupport</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IPrefetchableSupport.html</anchorfile>
      <anchor>a127acb45e09dda596a2cdb7cf31b5a32</anchor>
      <arglist>(PrefetchableSupport &amp;prefetchable)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IPrefetchableSupport.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::FrameRate</name>
    <filename>structSteinberg_1_1Vst_1_1FrameRate.html</filename>
    <member kind="enumeration">
      <name>FrameRateFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1FrameRate.html</anchorfile>
      <anchor>a0e1b90fc53cc88f751388bc4466a4665</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPullDownRate</name>
      <anchorfile>structSteinberg_1_1Vst_1_1FrameRate.html</anchorfile>
      <anchor>a0e1b90fc53cc88f751388bc4466a4665aa2055ed514ccc81c537ca60ddbdaa226</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDropRate</name>
      <anchorfile>structSteinberg_1_1Vst_1_1FrameRate.html</anchorfile>
      <anchor>a0e1b90fc53cc88f751388bc4466a4665a859f363f2bc4f6bb60331d4106870722</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>framesPerSecond</name>
      <anchorfile>structSteinberg_1_1Vst_1_1FrameRate.html</anchorfile>
      <anchor>a9f29f1e74507c8ad3d1be129fc8b7b53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1FrameRate.html</anchorfile>
      <anchor>a81a27ce50e78368b0d0de1e8767fd32d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::Chord</name>
    <filename>structSteinberg_1_1Vst_1_1Chord.html</filename>
    <member kind="enumeration">
      <name>Masks</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Chord.html</anchorfile>
      <anchor>a15c053e1a487c607ed4f57d29a07e117</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kChordMask</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Chord.html</anchorfile>
      <anchor>a15c053e1a487c607ed4f57d29a07e117a7eebe88f8cafca853fd115af0e1939ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kReservedMask</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Chord.html</anchorfile>
      <anchor>a15c053e1a487c607ed4f57d29a07e117a4604f8115055d6e83aa00610b65a290c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8</type>
      <name>keyNote</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Chord.html</anchorfile>
      <anchor>a4aaf84930c8913e7e3712874f2a5e04a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint8</type>
      <name>rootNote</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Chord.html</anchorfile>
      <anchor>a618acffbc29c4bc4ba7ffd114686c235</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int16</type>
      <name>chordMask</name>
      <anchorfile>structSteinberg_1_1Vst_1_1Chord.html</anchorfile>
      <anchor>aeaf52509d7189fb85cfab0c24549bfce</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ProcessContext</name>
    <filename>structSteinberg_1_1Vst_1_1ProcessContext.html</filename>
    <member kind="enumeration">
      <name>StatesAndFlags</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPlaying</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a5b645fba782b3b038ecc301c60b65114</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCycleActive</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03ae43d6ac7d9f03c335ac275483cd8f303</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRecording</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a7c3dd7bb52ddb9f7557a8cb32d38ea2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSystemTimeValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a53fb5555d770366b370d9cf1dce63785</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kContTimeValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03af574e5e5705f9295d830c4b0de3c3b11</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kProjectTimeMusicValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a4ef3fb8e987fdda3228d0a2ab40ffce5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kBarPositionValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a77d6596070548ddebaab07813805b959</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCycleValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03ab5d7cb7ea333235f0050b65f6865c420</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kTempoValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03aede1cd4db7eec7e4680d7cc50dffc965</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kTimeSigValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03ab1b4bad2bca898aadd1c5c352d72af3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kChordValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a2c5aebc70c00b5acda15d34a7d8e6b5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSmpteValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a2326f930282bcaa6323a4482b3772ce3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kClockValid</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7ac64bdb8f6c1e2d67da949940d46d03a03449069245e2637f73ef75f0cadc2b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>state</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a0a213e749fd32870b11cffff1c0c2e53</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>sampleRate</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a2bd79d2ab2dfb6aeaf75c2878ad30e1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TSamples</type>
      <name>projectTimeSamples</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a359d649ae34734b9876ad5a6a2f691f7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int64</type>
      <name>systemTime</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a6dca674d990cf41493918b226fcf5dde</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TSamples</type>
      <name>continousTimeSamples</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>aa442da3063c73885d2f386deb479d870</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TQuarterNotes</type>
      <name>projectTimeMusic</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a4c1e16437e0c0858fa5288107e5b187f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TQuarterNotes</type>
      <name>barPositionMusic</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a9081efe983722f59098a542b149bb07f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TQuarterNotes</type>
      <name>cycleStartMusic</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a550eb08cd5228700273d59d3d0ee19c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TQuarterNotes</type>
      <name>cycleEndMusic</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>afc2ff5534156a67b58ead0eb0370b45a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>tempo</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>aff2f6d52166217d13f9b2072c9e67c13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>timeSigNumerator</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>ac7c0bf22aeb016dfe8143bd1f261585a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>timeSigDenominator</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a7087d1fca166b09add2184085299de21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Chord</type>
      <name>chord</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a8a97acf6c5676d31de6ceac2483ecf3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>smpteOffsetSubframes</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>af46e5ad510319f6dd5687519ae47c76b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>FrameRate</type>
      <name>frameRate</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a59b215ec89870d5ac40b08400806c906</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>samplesToNextClock</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProcessContext.html</anchorfile>
      <anchor>a01be967abff36568fab07ab7d4eac7d9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::RepresentationInfo</name>
    <filename>structSteinberg_1_1Vst_1_1RepresentationInfo.html</filename>
    <member kind="enumvalue">
      <name>kNameSize</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>adc29c2ff13d900c2f185ee95427fb06ca5b9d2840f143c8288f728f5be29f638e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RepresentationInfo</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>a8b44829c5f48c94bb855c021db577bf4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RepresentationInfo</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>a76266d49ec6676565dbb87e68c4176bb</anchor>
      <arglist>(char8 *_vendor, char8 *_name=0, char8 *_version=0, char8 *_host=0)</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>vendor</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>ac4707b8abe69c6961d88a0ea8d9689e0</anchor>
      <arglist>[kNameSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>aa9227b03d6c37d746f40c59e671c7af1</anchor>
      <arglist>[kNameSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>version</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>a06bc80e15444b5693748235a704a58c6</anchor>
      <arglist>[kNameSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>host</name>
      <anchorfile>structSteinberg_1_1Vst_1_1RepresentationInfo.html</anchorfile>
      <anchor>a74766a169cd1c18bc001b99e1984a901</anchor>
      <arglist>[kNameSize]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IXmlRepresentationController</name>
    <filename>classSteinberg_1_1Vst_1_1IXmlRepresentationController.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getXmlRepresentationStream</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IXmlRepresentationController.html</anchorfile>
      <anchor>a12aaff5f46c6f620fb724e9c9763ac21</anchor>
      <arglist>(RepresentationInfo &amp;info, IBStream *stream)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IXmlRepresentationController.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
    <docanchor file="classSteinberg_1_1Vst_1_1IXmlRepresentationController">Example</docanchor>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::UnitInfo</name>
    <filename>structSteinberg_1_1Vst_1_1UnitInfo.html</filename>
    <member kind="variable">
      <type>UnitID</type>
      <name>id</name>
      <anchorfile>structSteinberg_1_1Vst_1_1UnitInfo.html</anchorfile>
      <anchor>aca967f4b7c7079db501398a822d0c69f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UnitID</type>
      <name>parentUnitId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1UnitInfo.html</anchorfile>
      <anchor>a5cd97a596c57f5f28ebad702f2d6f06a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1Vst_1_1UnitInfo.html</anchorfile>
      <anchor>a1b0ba9a9710fe4cbad60cb03e38a02d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ProgramListID</type>
      <name>programListId</name>
      <anchorfile>structSteinberg_1_1Vst_1_1UnitInfo.html</anchorfile>
      <anchor>afef3772baf373fc218c8b091d9eeb6bb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::Vst::ProgramListInfo</name>
    <filename>structSteinberg_1_1Vst_1_1ProgramListInfo.html</filename>
    <member kind="variable">
      <type>ProgramListID</type>
      <name>id</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProgramListInfo.html</anchorfile>
      <anchor>aeeee23609c5e1add56038262d378784f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>String128</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProgramListInfo.html</anchorfile>
      <anchor>a1b0ba9a9710fe4cbad60cb03e38a02d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>programCount</name>
      <anchorfile>structSteinberg_1_1Vst_1_1ProgramListInfo.html</anchorfile>
      <anchor>aa480d0c44ff2b505ebf3581427dd8c05</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IUnitHandler</name>
    <filename>classSteinberg_1_1Vst_1_1IUnitHandler.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>notifyUnitSelection</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitHandler.html</anchorfile>
      <anchor>ab05a9a8dcca888caeabdb8ed74766bc6</anchor>
      <arglist>(UnitID unitId)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>notifyProgramListChange</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitHandler.html</anchorfile>
      <anchor>a3f4dc142ae3d50a04aa416fee14d4da4</anchor>
      <arglist>(ProgramListID listId, int32 programIndex)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitHandler.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IUnitHandler2</name>
    <filename>classSteinberg_1_1Vst_1_1IUnitHandler2.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>notifyUnitByBusChange</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitHandler2.html</anchorfile>
      <anchor>ad1f48213839cc5b28a612a2baaba6584</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitHandler2.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IUnitInfo</name>
    <filename>classSteinberg_1_1Vst_1_1IUnitInfo.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getUnitCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a23fd4bc09e5bfee39c31bbba1ab2385b</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getUnitInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>ad32cdcda859f588c84e76133f2d62923</anchor>
      <arglist>(int32 unitIndex, UnitInfo &amp;info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>getProgramListCount</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a2d04f6147a8c2d4b11e9cb9aae39514b</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getProgramListInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a0db929591fd4fc242935edb91e65ed30</anchor>
      <arglist>(int32 listIndex, ProgramListInfo &amp;info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getProgramName</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a4417b27a9a3730bc49a933bc0d2bde7d</anchor>
      <arglist>(ProgramListID listId, int32 programIndex, String128 name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getProgramInfo</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>ac40c799f1f52837c311ac153d7a8ead7</anchor>
      <arglist>(ProgramListID listId, int32 programIndex, CString attributeId, String128 attributeValue)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>hasProgramPitchNames</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a63c02601259d4e8690f26eefaad53195</anchor>
      <arglist>(ProgramListID listId, int32 programIndex)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getProgramPitchName</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a6126c4506f7981b5e800c6b4daa1e66b</anchor>
      <arglist>(ProgramListID listId, int32 programIndex, int16 midiPitch, String128 name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual UnitID</type>
      <name>getSelectedUnit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a6f1b43425ba894764f35b7d492e81c53</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>selectUnit</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a2504c2bb3c57742102577f34cb58e257</anchor>
      <arglist>(UnitID unitId)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getUnitByBus</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a718fa905d04d7d559bc89c7ca761413b</anchor>
      <arglist>(MediaType type, BusDirection dir, int32 busIndex, int32 channel, UnitID &amp;unitId)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setUnitProgramData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>a7cbc86917a614918938277be9bb52e6f</anchor>
      <arglist>(int32 listOrUnitId, int32 programIndex, IBStream *data)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitInfo.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IProgramListData</name>
    <filename>classSteinberg_1_1Vst_1_1IProgramListData.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>programDataSupported</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IProgramListData.html</anchorfile>
      <anchor>abc46e67ff37c30223ab01b70fe49a2e3</anchor>
      <arglist>(ProgramListID listId)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getProgramData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IProgramListData.html</anchorfile>
      <anchor>aaff57861e6da9c4026a0737b300df28f</anchor>
      <arglist>(ProgramListID listId, int32 programIndex, IBStream *data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setProgramData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IProgramListData.html</anchorfile>
      <anchor>ac81ba6ad1e5d49d7a9884b6dc7d27507</anchor>
      <arglist>(ProgramListID listId, int32 programIndex, IBStream *data)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IProgramListData.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::IUnitData</name>
    <filename>classSteinberg_1_1Vst_1_1IUnitData.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>unitDataSupported</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitData.html</anchorfile>
      <anchor>a77520fed67487e60b57cebde871d7f48</anchor>
      <arglist>(UnitID unitID)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>getUnitData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitData.html</anchorfile>
      <anchor>a0ea283ed20afcc7f1b860abd05064bbb</anchor>
      <arglist>(UnitID unitId, IBStream *data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setUnitData</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitData.html</anchorfile>
      <anchor>aa01ffe25404ad1810e9076e205ce25fa</anchor>
      <arglist>(UnitID unitId, IBStream *data)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1IUnitData.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::Attributes</name>
    <filename>namespaceSteinberg_1_1Vst_1_1Attributes.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>ac45345491383374f12e9e5a8835ef584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a9778507c4f8a0e63627745ba122e7355</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a69491a10333660073039f48933b19169</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKnobTurnsPerFullRange</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a94ab8536a4938e752a0831641d204bb4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFunction</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a085c04012e24b75391893fdc08a14212</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFlags</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1Attributes.html</anchorfile>
      <anchor>a55d73164cab645ef625b0906c5fd9b7e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::AttributesFlags</name>
    <filename>namespaceSteinberg_1_1Vst_1_1AttributesFlags.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kHideableFlag</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFlags.html</anchorfile>
      <anchor>a802846cc44b7ee60a8f88e7deb81e7b6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::AttributesFunction</name>
    <filename>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosCenterXFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>abc31d751bd54d024fb1d6a3a44c28972</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosCenterYFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a4bedaf7a553a7225d33b44e17392aa14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontLeftXFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a6124b199a105d4f0e924e5a2bab5916c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontLeftYFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>ad62884d321a9c158a652171f28966391</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontRightXFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a92ffcca6b5f41a5cbc0a8114f6207eb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanPosFrontRightYFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>aca1665ab0b3971f5a0d77c4f80dbd08c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanRotationFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>af22d8c74678d445a5f8339261e960dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanLawFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>afb97a4db6eec1e1220525a26b21cb306</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanMirrorModeFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>add1e67399eb35139cf8142d892abe3f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPanLfeGainFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>ac5774ffde117ba66d042211939fc92e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGainReductionFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a754bbe4a40d9ea477213c8d0f3a33011</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoloFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a561acb1a41d0b9c03050f3b33be9f6d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMuteFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>a2714bad0648841cb021603303fb2cd17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVolumeFunc</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesFunction.html</anchorfile>
      <anchor>aa50a92256981837b639d8683d6cd65ef</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::AttributesStyle</name>
    <filename>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kInverseStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>afdd9a4e103915db68761ddaf0ffb4aab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDWrapLeftStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a08381b7f0862de9edee14226b4540663</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDWrapRightStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>aa0c11f1f96f6ee66dce6b52513bb8d27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDSpreadStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a078a1072f0a79bf6dda79f84a83c7dd1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDBoostCutStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a4a6426db9e25591301b5005332235884</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLEDSingleDotStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>af203ee426ecc4ffb31c7309a392ef807</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a0f25d2df1a1539b11c9cd5f4ea9ac1c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushIncLoopedStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>ab9e1b3d53a0bdb4735378bcabd135c00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushDecLoopedStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a7957b8090f444415be702a9a00375037</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushIncStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a2c044da4242800ee2b02a2b548cefca8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchPushDecStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>a06b11bddeef4219b4d959f38570b58f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSwitchLatchStyle</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1AttributesStyle.html</anchorfile>
      <anchor>ae91fd6e9d7298b55b0c73577db874f72</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::ChannelContext</name>
    <filename>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</filename>
    <class kind="class">Steinberg::Vst::ChannelContext::IInfoListener</class>
    <member kind="typedef">
      <type>uint32</type>
      <name>ColorSpec</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a5b13d028fba1eee386ec9ac208c6238d</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint8</type>
      <name>ColorComponent</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>af1189c83b63820c6ccc3167402601fea</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ChannelPluginLocation</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168af</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPreVolumeFader</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168afa21f636e119b96f85db893e981c6d0fbb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPostVolumeFader</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168afa352f87b06111d7eb4502ca8884ba1bfb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUsedAsPanner</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>ac6ac8886bd59deb9f997179931a168afab4d561ce249fb47b1411e92455468810</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetBlue</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a641c048e19cbdf7b753446f6e06b92e9</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetGreen</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a85a872d79e8879f75593a51a62e3c61b</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetRed</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a0631a9689c90dab1e9267681bc3d351a</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="function">
      <type>ColorComponent</type>
      <name>GetAlpha</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a59f0bbea32d4ae966062be29a76bd969</anchor>
      <arglist>(ColorSpec cs)</arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelUIDKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a68ad60e2a9bdcefda0e2296e7f9296f9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelUIDLengthKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>af44825ca23e7c673682f438d8cf6283e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelNameKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a355d0e3fe55ba9c58ebe6cb29cf27ce5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelNameLengthKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a175778add2bfeafd5b184f4e47869e80</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelColorKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a218d5777a06f7780c7ded2a14c9f2922</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a42930b877ebbb27bf3daa78d02780be1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexNamespaceOrderKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>acd822b1c74f9c7e9afaa16b0ce578f7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexNamespaceKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a9dee889cb7b726bf9bf9f21c79334261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelIndexNamespaceLengthKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a9b082b198abef61a8397bafcf4e30a72</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelImageKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a6ba9324db0a3f814e6f41df444e0f7e7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChannelPluginLocationKey</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ChannelContext.html</anchorfile>
      <anchor>a1836e6445deeff80efc1d389b8ba7ac5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Vst::ChannelContext::IInfoListener</name>
    <filename>classSteinberg_1_1Vst_1_1ChannelContext_1_1IInfoListener.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>setChannelContextInfos</name>
      <anchorfile>classSteinberg_1_1Vst_1_1ChannelContext_1_1IInfoListener.html</anchorfile>
      <anchor>a976da6f002de26e9431f1189f7d75b00</anchor>
      <arglist>(IAttributeList *list)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1Vst_1_1ChannelContext_1_1IInfoListener.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::CurveType</name>
    <filename>namespaceSteinberg_1_1Vst_1_1CurveType.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kSegment</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1CurveType.html</anchorfile>
      <anchor>a01b326e51dd2497b0b1e4b3bb40f478d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kValueList</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1CurveType.html</anchorfile>
      <anchor>a8bfce81e77d68274fe7093871d1c7d5b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::LayerType</name>
    <filename>namespaceSteinberg_1_1Vst_1_1LayerType.html</filename>
    <member kind="enumvalue">
      <name>kKnob</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9eaed465fd2dd47fea2b560392552bf65a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kPressedKnob</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea8c1ff139254d93782be7eaec45059110</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwitchKnob</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea75d5f413c5b9d0337515c307a5e10dcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwitch</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9eaaa243fb2b8aff16421d89868c811958a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLED</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea125690f72eb0478f1b83b9f17dc7c431</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLink</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ead5309d363b060cc3481f6e021b26f0d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDisplay</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea1c1b7a564dd807a7c1c4cffb88d8b100</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kFader</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9eae6364790e7803e2a147b5abeb9554c70</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEndOfLayerType</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1LayerType.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea9a9bc943010bbc1e4d0df5442fd1612e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::MusicalCharacter</name>
    <filename>namespaceSteinberg_1_1Vst_1_1MusicalCharacter.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kMono</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gad515322344056aab9256d76a6787eb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPoly</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga020e4d1023e2b9add2c637ebf4b75a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSplit</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga51e6bf04c8aaefb4fbbc45a114f147c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLayer</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga18049d58eeecea7c6fed4f727442430d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlide</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga94f8615dad159bf66390009ad9282249</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlissando</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae0732ea96679d73e821715b2be446261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMajor</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga18f27017b00ca4612f133f4e09d913e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMinor</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaccd54b1bfad544bac2ff54cfb56d7df2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSingle</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga516ace30c1fa46e55b8767b58c77a788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEnsemble</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gadb6de4949739c48baf2613e6965d1637</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAcoustic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf589c030507665591b7e57d677b350e0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectric</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa924ea59d6457adaabe92b47048253aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAnalog</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga10904a318940018e74802140f840a4cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDigital</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf8f1ad8e2c507c80b75e20d94cbef219</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVintage</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gab86682f9fb5dd5c56199feba1afadc8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kModern</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga490b8908c7977aaca4e5a7fc1983f172</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOld</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0bbfdd92cc2b2313b3cf974c5b3f9760</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNew</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8ff57c7698535ab97bfc64a7bf3ea9ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClean</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae48573356356094da60ac761ac5ac51e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDistorted</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa8427782100432cfaf837a729195f1ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDry</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gae4406a55f1a7b6f1d12e29bab8f576e1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kProcessed</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0bc38b1dfd75d0ae9e6137d43c29068c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kHarmonic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8f5f55f753d25fbeec874ff7c873b050</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDissonant</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga3030eff3a0900a8cca1c6266716efe1e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClear</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaf8c102dba19d9bafb8d7ba312f812ad7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNoisy</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa57323ce9c0b4d417c6b36aa76570514</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kThin</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8da59e92e1c2609a302663aeeffc01cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRich</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa6c4d36725eb4226e02f5724ca420e24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDark</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaae40f2e630a0d26cdd3d862761b26d07</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBright</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0796a86633dd777869721cf5f2666aa5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCold</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga7c18fd830521824296dc8412e5420559</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWarm</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gac1766654d4a9b882b9890fce9483a733</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMetallic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga644e30da9b10ac15bcd313778d00d261</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWooden</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gabea2ba5e271fab4f245baffae6fc7f20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGlass</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gaa5eee886870365dcadc1105891130025</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlastic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga62ea7670ea954e012810004bb26369fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPercussive</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gac6b35eb8d6cf9178f4b428d523760e89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoft</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga280fd77ca4f703e3509ba81e6a4a7062</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFast</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gab5face7509d33a16c6be75f042d5f56a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSlow</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga196114f5b784b26e46ca975e194a12cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kShort</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8b9663df42570d3f736896b881f348f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLong</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga1d83ca1c98b52785de6b205cf10ba2cc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga6825831c83ffca20a7353fcf1f4ff3c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga85c4be48d6121e160ec3d864591f48ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDecay</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga310f8f745367f1fff3d176974abb507f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSustain</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga1b380d79f09e7bd56403f79f09514db9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFastAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga8cd59e5d43ed1bd277845f9ed2f29351</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSlowAttack</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga19fc8fcee1d6326b028fdeace97da264</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kShortRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga0178603367ef122579d09173b02c275d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLongRelease</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gadb9b1ab770dcdf2bb4d526b5aac6b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStatic</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>gabca0f72e85147ea95283eb9607c23332</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMoving</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga24192885baa2c896f4ac92a68e176802</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kLoop</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga37e6e5e54e1d052d21d739a032593282</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOneShot</name>
      <anchorfile>group__musicalCharacter.html</anchorfile>
      <anchor>ga084d4ed63922f00549f31a1114ecd32c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::MusicalInstrument</name>
    <filename>namespaceSteinberg_1_1Vst_1_1MusicalInstrument.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5bd8958e2d10a39961b9ac9d20ac1a3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionAccordion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4b3a7ca0aed4fd75c4c6de9da2c095b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionHarmonica</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga13f91d403c87da4936308cd2f94b3dce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAccordionOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga3f7c44f705388a781d442009341b50aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga99ad41c498b2d37a379907989842655a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassABass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7806c7198452bd9b38813e1254bffdde</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassEBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga722ff7ac1ffb92a922ef3f562117327f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassSynthBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabbbabe9b591bdfbc9e8613220d7ce829</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBassOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1835577b20a8f992869f11555b9c6c43</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaccf4a6cc04deede6234aa80f17494e62</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassFrenchHorn</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1a4ba62937d8347b92bd6a7fe2f0f203</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTrumpet</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga58aa80b0a42ce48f7868095cbf8af4af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTrombone</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1f2c119eb1f5ed7687375950e64a099a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassTuba</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1e4a49eeaaedbf8487070bf20a06b119</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassSection</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae7c3bd91d4fb0872ab7db0ed74d91445</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassSynth</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0cc2d58842ce2dcad93a3f83a777a67d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBrassOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae4e52f708efde91cf0f2a78cebbd351c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPerc</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5f48d90dba2837a9b0552446258746c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercBell</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7b4edfeeda6a06123409b3e5d704bd0c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercMallett</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaeee07c58574e18dd64d3be93f7088a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercWood</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga492b01fbc86bdb5131f84dcdb5f26f06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercPercussion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0e5caac1dbaa9755fdb06e89ed3b3895</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercTimpani</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga11ef28f0a9918a82c981b1fb8025bd8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kChromaticPercOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga12eb4bbef0c030bbca1e861adc773334</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPerc</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabe15c8ed2a76ff3c9f9029278854dbef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumsetGM</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa41f951f74e972f53aab1a45d15c54aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumset</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9ea452ccf895de2e9a647aa85d40b1ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercDrumMenues</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa441a52dd98f3b53affbc538eda46521</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercBeats</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5c77bf645fdb2afae554c3c6b48dc92</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercPercussion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga351f0ed74b2185f5acc3460021c203a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercKickDrum</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf85c8e569ae8d22ab2c233006a99f82e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercSnareDrum</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga13fca99a8c4598a5f66ef87242f70b27</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercToms</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac756e1798f6f8ce4eed78adafcd6f8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercHiHats</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gadec30a0adbbd248d6573f64342feef77</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercCymbals</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga82ee2aad1a847aea7c803b81a4d2598b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDrumPercOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8dbf5e607efc62bfd0fb4044a943c399</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa946206a3ecfcc3423ea307de5efdd13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAsian</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga81ca43ff51517679540bbabce3f89254</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAfrican</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5de2bf50670628599940b4afba85fba1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicEuropean</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga841f031104f1230a568fb7246eb87fe0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicLatin</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8b04cbbaa98e561e20b7a966f58e9281</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAmerican</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga3c6dcb9ae2464cf7012aadb328c73fdb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicAlien</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga86aa661200c00f7b44935e455d62b5f8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kEthnicOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga89d49bfa58ca9659367217ea187bd7bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga642a844eb43638962aec00dda572b724</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarAGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf907f1b0c6b112a7a7ef2c26d181345b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarEGuitar</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5bd16506f3db8c7cada37ac1030fdeec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarHarp</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga6077d4646f9ce2fcd14f40ee5f1fcfce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabac2c7c2f88a2511bcb9536a62847e64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kGuitarOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga91eddfe8e8f1e826c887b57971600988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboard</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae87c28eecf427576aaba8dba45506307</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardClavi</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabeb1f764cd854f5f7b107a8f0b1fd4ec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardEPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga326410320556a12f64c20f88c19373ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardHarpsichord</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga02d58cfc1dd6afe263d10ed615eb0d2e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kKeyboardOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga20c97efa4d9bc8307bbd0375035c34ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2390a2a94e9904517ec9342ab0019fe7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXHitsStabs</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga7827735f5bb526019207c524f487af0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXMotion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab9114e6b0673188dc5228aed3d3df2da</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXSweeps</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf3cb2d886c19f654e5d4d8b25eb5477e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXBeepsBlips</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5378d54b89a50f2b659f4811d2925cc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXScratches</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gacbe3eb6871b48061d2c046d8b258a7a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMusicalFXOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab5e9cb190b3c45ca56bb2e1adebb43fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrgan</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga84fec6760fef802a323b692a062b55b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganElectric</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2ec0df01bea69ecba86f5d891b1ad648</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganPipe</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga79ae6538d284af4c29bbd7cf4933b76e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOrganOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga20f011a1e399ecacdb0e6e1cb7196e64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga41cb875c197b4036cc5ac03ca3721a08</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoAPiano</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4ad2adf116f63f68c278860b4d1d1f6d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoEGrand</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga37d4c3eca4f4d9c151ffa65609c79439</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPianoOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1af05a3bfb82be1b619388c384a6bf2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf2a091ea57274b72699e9f9df7715b17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXNature</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gad21b480ba2888b09f222c703fbb37a91</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXMechanical</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8f75ccb3769fa4876436c45a09107fcd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXSynthetic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga341e53ab2df394405b3785850dad88e9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSoundFXOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaae916a5a813ecf7d856e61f456a24479</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStrings</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaafd56235b0b917a43d284202d30f4f0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsViolin</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf8cf7e44674db2aca92f56fd73f92006</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsViola</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9aa9476acbba419210667d658afabc6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsCello</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga265f017e0f464df3d4141dc319eff0c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsBass</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gae18de76efc605860475b6323ef233cc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsSection</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac1d32b8a87a1fd03f9c1015160d7d3b2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsSynth</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga51a61e68eba9a1cf51ad89242b9bc47f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringsOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab44336cb32a2e361969b84be167c6437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLead</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga65f99d06e1cdec2a31ced94c3e74e2b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga8a11629221f0398068c261f7e82dbb3c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga5593b90f0b783f8c474534b1bfdece81</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadArpeggio</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9f07e312d4b567cbeb9afc62663e799d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthLeadOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1baec415d4b38bfc63bfe37d4d8f998e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPad</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga09ada6780ac854e1a5f5fdeaeed3fb98</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadSynthChoir</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga459f7a40ee5ce2589b9c5b4e9a7dbc03</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gafd8251cd1e2beb471fb880eff54122a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga0624ae2a566ded387d13aa9b42b02e4f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadMotion</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gabb14045ba365551baf7d248ea496f627</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthPadOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga21365983f34c81eb766d77a9f6c56542</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthComp</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gac5ee81e33b8952b205664d8a7e6d3726</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompAnalog</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga98b124c4c95e7d1f055a878c293036a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompDigital</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga58fd32018d0d25fa22a065fe293e4079</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSynthCompOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab2577b8dac71b9e6d679cd5fd337fc70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocal</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga2d5f12d8f479275a1ec1047877ad12f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalLeadVocal</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga33b0df9f2de9caa850ec8f42a690ea1c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalAdlibs</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaeb469e5850a09e7863b3a411bd839185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalChoir</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaf1c302e30ac59f819c846264553cbb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalSolo</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga9fee846e3dac6a9c76f49236370104ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalFX</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga01a286aebf174524ce6806266da52608</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalSpoken</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gad3c91ff5b7e51b5ed71479994af1f2b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kVocalOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga97b0787f7bc7a12d8aa9c451626252df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwinds</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gab6f7ddec4db62d879f3d4147da295e5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsEthnic</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga4c985b65f095bd5bf25adb95490c26ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsFlute</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga1b594039765ec814407ab25b574177e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsOboe</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga40a881c8d3a7bc7f6688195400ba35dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsEnglHorn</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaab8ddc7cc6aa5f6c1b3383b7ba109c65</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsClarinet</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga76398345f57877810ceeb6db295a08a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsSaxophone</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga685ce7454b4f454c4f2e36b40d215fab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsBassoon</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>gaa7909c8fc3a72ec802f1163f7bf78a1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWoodwindsOther</name>
      <anchorfile>group__musicalInstrument.html</anchorfile>
      <anchor>ga850425dd3f6d9938ccbbee6158316bbc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::MusicalStyle</name>
    <filename>namespaceSteinberg_1_1Vst_1_1MusicalStyle.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndie</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2283c2c777c7cbb21710e11ef2ceb6af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieGothRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5efb4dfb4fef27ded5062173093bbaa1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieGrunge</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga611a7833ad99ac643e6662ad0c735437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieNewWave</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0d9c9e5d1d7762b13270a0cd388b2d7e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndiePunk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2b8b2179cf8d2b74f6c0eb2abb563a80</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieCollegeRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8881386092fc55d2c4ed31ca0d3acd22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieDarkWave</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4e60a460c89c2aa3f05c8e15c4a74b76</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAlternativeIndieHardcore</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga080e7eebf7cfeef648604aab356d9249</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOut</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa5aa1cc4f7a5cf8fbcb025f426225676</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutNewAgeMeditation</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab17d3d9dbddf245300a0e581f27d2b21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutDarkAmbient</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga33320722a4e37a0dbe61f8957a77fcb8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutDowntempo</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5af88b6815b44014176a2bf68aabca6f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAmbientChillOutLounge</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1abdca80184a162d425c61f053530dea</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga070e85734aa0ebd786f2c8ff8dca8301</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesAcousticBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga427cc44ab600473801a7d50bef343e2f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesCountryBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3ccf2f159b7b1becbe0d64f4688f7f4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesElectricBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga60c65b0575b241924ccfcc59fa7dccaf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kBluesChicagoBlues</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5043e48daf7d4433d082c9d726b90a2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassical</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga00100f8944908f3f674b077b8e7bf5ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalBaroque</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga54a477d7f94dacdfa325bdf693d180ab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalChamberMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga817fef9aabf571d6f91e357efc677040</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalMedieval</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaabb6cafa41915dc3a4ebb19d35aeb3be</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalModernComposition</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa61b32582345fd12bd9d2140c174a25f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalOpera</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaaa8a189a2e24961319d1e26349aa8a9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalGregorian</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabd559febaa875cac883dc20517965d19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalRenaissance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8f9739caabbf232d50b1b1b449ab1491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalClassic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1a1b8c73dee78995dfc73a9cbe1855fa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalRomantic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad822300e6782c9fc490f073c880403ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kClassicalSoundtrack</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad28cde471461898b52b6cd7aefe1fad9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountry</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaaa2fa8f51e39b78604c752001cbef8c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryCountryWestern</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga613bd6f52125a615d0e1bef58463e6cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryHonkyTonk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac05e574ca2ece383b72b5ee429506988</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryUrbanCowboy</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabc94ae94e43d1ae9a453f5033f2f6bf4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryBluegrass</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga56cc1195da3ec7bc16d67a303c489c6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryAmericana</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8a240fc37b335deb7063b9bbf959ba90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountrySquaredance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7b9a2584ff4f1501c9a24a8754f1f526</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCountryNorthAmericanFolk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1578d35d598b30c1a8aca33c94e33213</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga9e3c1f6becf1b50e07e2d8212fadea0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceMinimal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga2acd1ccf8c493d7055288674c243e7f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceClassicHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad2581a6189feb88d716b6c81c5efa79b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElektroHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad6c238193c96a2f320bb158fc0cb36b6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceFunkyHouse</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac697bd7d2476a3f522e0c12f4f9096c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceIndustrial</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga43aa90fa2a5718ec3f233186bef3b745</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElectronicBodyMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4c9fd026e505a151e4ebcb41a026a273</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTripHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga27a783d5bce0708e88414cd4de0ffc3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTechno</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga66d567db513649b64572ec56ec721a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceDrumNBassJungle</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaa1a66bada350ea5f47e8c296bd3482b1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceElektro</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac613b9e387a4a4e424dbdd7925a842f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceTrance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae1734ba060074a2d5f5bc4aadb1b4693</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceDub</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4bf8090a24491f751c9d75218ba8ffc6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kElectronicaDanceBigBeats</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga04e06e3becb8bca4036fd5856682a393</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimental</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga13e10384c541982e7ebea23ae4cc0057</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalNewMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga9d42a1c28d4a1b6e725783290a949f04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalFreeImprovisation</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga988ed6ba9f31ff90849bfe159dbb56f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalElectronicArtMusic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad14a4491132f9255427a1dfbb53f684a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kExperimentalNoise</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6d711a097823788b80c4373b0df67287</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae80ee561e4da8da1de90835e41f0fc7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzNewOrleansJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0ade597c6d17afc9e6cf4a7bdf34de9b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzTraditionalJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6099a9381244ca72562a7b8226c619b9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzOldtimeJazzDixiland</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga04fc9ede978682cf37a56876ba9dba9d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzFusion</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga847f04e92eee76df8f6c6592da0cea2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzAvantgarde</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac6cbbbd37ada9f3f26657db8cc6065f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzLatinJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga0ee890f05a7479865af9eda6d34bc857</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzFreeJazz</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga5fcff8a8096b40b9e05427c944a2e295</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kJazzRagtime</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac2b3067f7b9b92ffe14a1b15b0bed83b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga92057d09ae8339165840fd850e77868d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopBritpop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga886ab03c6a77598d7e78c3a6ec922441</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga772e326e01f9245ba8a8177301a55d4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopTeenPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7e047957551e02185723581a1880086e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopChartDance</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6f9e30f2b18f2f639fefbb38b1d2d3e3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPop80sPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga6f3a96aeedf52ae2691056c3f1535578</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopDancehall</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gafdb7e50d604be148bcab627102c66a3b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPopDisco</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4cfb53a16c9ad176d8c2a3b9a4a267a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gade4f6c22997daaed1a372dd09b358068</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalBluesRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gac1c59279027338732b37420973755dd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalClassicRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga52b06f4c922bceb8a7af486f8f9e8ead</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalHardRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab7fc6fc1b343016898c32d9095895973</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalRockRoll</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaf044a0ecefea571e16b30b82a1becf04</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalSingerSongwriter</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4c7fb7c56f3573b219287833e847113c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalHeavyMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1b66689bf69717c4af8ad85835737acf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalDeathBlackMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga370c692d8ab858d11bff12c0ea4c779c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalNuMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga1e43c81772b3227d2239c4c869194733</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalReggae</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gab7285dab701bff67bb281688a4c1b93a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalBallad</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3e6375ad794af9ad7c9e79f61ce422de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalAlternativeRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga679697a95e28deb4eb0ab2dcdeca114a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalRockabilly</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga646cb827580fbdb5631167f300e2d7c5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalThrashMetal</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga4367d681da9e6a9259373fe33bd58162</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kRockMetalProgressiveRock</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaf74e7f4e41c15f2e271cc15b512b2fbf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRB</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gad9fdad7b31d648bbf64bc2333bc3ecab</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBClassic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae828f62557a162b35e08774fe73e4b59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBModern</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3089241b92ddf52d670f6339c57ff321</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBPop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga03a11de347ee7fbfa80f6040e5838c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBWestCoastHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga31d1f86b5f8a0281d2a85f7ae6e40d10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBEastCoastHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga91a0592eb755912d7fbf4b7f78387707</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBRapHipHop</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3dd2ebf4652bdc7f67e804099495ad1b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBSoul</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga853a4803393e2d1684fe32e5adafcffe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUrbanHipHopRBFunk</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gadab3d1a08820555d8cc2eccba5a2414d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga7fc43124278803213779023493bec46b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAfrica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga24447081033911845dd5279102bf075b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAsia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga09caf2a39534495b771aa65a0d969ad1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicCeltic</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga17f0e511cbcdedf14156ba499a54d615</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicEurope</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gabbce5b2144aac1d57742c746de8ef78b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicKlezmer</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga8db09e3dd05ef85ce88a038472cc04af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicScandinavia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3ae32b316261fa76c8d7ca0e9790871f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicEasternEurope</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaff54f68acdbdbbbed6054f5c9b17ba8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicIndiaOriental</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga33a8a991563a9d73923525ddd29e79a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicNorthAmerica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>ga3d85eb586a37b5a6082a6d1708d91592</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicSouthAmerica</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gaad0a8d9f7a2cef071860eee02948c556</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kWorldEthnicAustralia</name>
      <anchorfile>group__musicalStyle.html</anchorfile>
      <anchor>gae08118ff90a70fbd90e1979aa1a33c9f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::PlugType</name>
    <filename>namespaceSteinberg_1_1Vst_1_1PlugType.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxAnalyzer</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1c5f3f4e7d5210a9d81e6dcd76c79c67</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDelay</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae3635bf778d4382234cbcfc30d71db16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDistortion</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gac923ee5b5ba8b5bddb285aad2be3ff35</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxDynamics</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa892f409ac4c930c1af59459372c167b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxEQ</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae94c37234a2f8bc1c54f85e4d70ad1a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxFilter</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa7061a3bd7a1ef48e14f97503e6c0b2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFx</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga0411b97bcc13d604e738a28aee43bb61</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxInstrument</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gabe030351fd22d14dad35c817e1849f59</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxInstrumentExternal</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga21938bb5dc145f05b8a08669e7a74be5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxSpatial</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf5d6ce751eff5e1825c2e9cbf6de68a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxGenerator</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga09060af560cf34b87e14d5dbd839ad52</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxMastering</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga80ed69d85e565772a138ead6b8feff70</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxModulation</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf7fec6a731df379ba73e26bcd72d6f9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxPitchShift</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga2b2725f60cbf68e604c85b125937f553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxRestoration</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf2357711fdb99757b6fd3248cbc4ac15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxReverb</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae45eb21e5afa4a9b2a4e5c789fcac18d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxSurround</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gad51565b155d38402b8660fca0d78927f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxTools</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga610bd26a1a9c791feeb94c3a01b85a3e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFxNetwork</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1644feff4e06fa14952bf64ee211003f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrument</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga93cb7a7100ac96cfafceb6216770c42d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentDrum</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gadf01865c24020885cb974f200403351c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSampler</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1a96d4882dec6d6cc809c6881456dafa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSynth</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga42c97cd14b97a2ea3052cc62ecc833f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentSynthSampler</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa63699396d2e24978ad7a0f32f1a7187</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrumentExternal</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaf0e00ca5cee8c5b4319fb7789bb4b919</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSpatial</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gaa334568999d986b4e50627646e51a8b4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSpatialFx</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga9439d03e5e14fb7a35976d2e37f34e31</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOnlyRealTime</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae58eb0aafa16197f12c1a61428fd5584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kOnlyOfflineProcess</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga0181f4f0a361e99c4afa139b47e3642d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kNoOfflineProcess</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga1e894c4b97ff99e52706cf3a67c35627</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kUpDownMix</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga9b7a9613e51e1f218461d3167dd50306</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kAnalyzer</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gadbe2a7d21efd81fbae4bb86fa428e900</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kMono</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gad515322344056aab9256d76a6787eb42</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStereo</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>gae8acdf9398f33322690596dc2d00318f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kSurround</name>
      <anchorfile>group__plugType.html</anchorfile>
      <anchor>ga6e4cc6e531ad93aa1d60021b82dcdbe9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::PresetAttributes</name>
    <filename>namespaceSteinberg_1_1Vst_1_1PresetAttributes.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlugInName</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gacbad3647c9f27b2777cb6a3cd24fe49e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kPlugInCategory</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga56f939f21fb570350d3360b1e7254245</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kInstrument</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga93cb7a7100ac96cfafceb6216770c42d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStyle</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gac45345491383374f12e9e5a8835ef584</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kCharacter</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>ga166d8e939e25f23c6e1c5125e89d5f13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStateType</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gaefefe46f30651266cc9ccc8908409552</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kFilePathStringType</name>
      <anchorfile>group__presetAttributes.html</anchorfile>
      <anchor>gad5fe1f71ae69e7b4daaf0e79130930c3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::SpeakerArr</name>
    <filename>namespaceSteinberg_1_1Vst_1_1SpeakerArr.html</filename>
    <member kind="function">
      <type>int32</type>
      <name>getChannelCount</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa8258a29fe4e3164d9239869c1afc1e0</anchor>
      <arglist>(SpeakerArrangement arr)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getSpeakerIndex</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5e43f8bd9b65e001e85706fb6229e54d</anchor>
      <arglist>(Speaker speaker, SpeakerArrangement arrangement)</arglist>
    </member>
    <member kind="function">
      <type>SpeakerArrangement</type>
      <name>getSpeakerArrangementFromString</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae59865c6f6e439696b408a8e3a35fb67</anchor>
      <arglist>(CString arrStr)</arglist>
    </member>
    <member kind="function">
      <type>CString</type>
      <name>getSpeakerArrangementString</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8f3040f601ddc82b7ff76bd0ac66b32b</anchor>
      <arglist>(SpeakerArrangement arr, bool withSpeakersName)</arglist>
    </member>
    <member kind="function">
      <type>CString</type>
      <name>getSpeakerShortName</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaea8fb2e63d819b83b1811645b5f5c0a0</anchor>
      <arglist>(const SpeakerArrangement &amp;arr, int32 index)</arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kEmpty</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga85ed4946e3abe83c91baa3e14d6a5e54</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kMono</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga571ff835d603ec5e98e54f1e0feca20e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereo</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9b5733786c71156513982991fa5f3c11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoSurround</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaad38856abd90805d1e85fe737677bbe8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga44710b9a538279e604b98213e8acdbec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoSide</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga98918bef7ba906d9b970ba49fb02a742</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoCLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabec483e2214863d8fbfd2f68815647a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga350fe92a4a9f185ff5a7141e7cbada14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga87a09b7b3ca62380f9203bcf6560a3a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoTR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab4b759bc9adbcb09a13453cab2916281</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kStereoBF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadad8ca7e56a1171c6439875261ab1ce0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k30Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga32b8626cc036129ae6465115e7d33c5a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k30Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8848385489d48df96843cd8022dbbfe1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k31Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga925534b26c3f13772f0363b44de830fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k31Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga34fbc53e44aafa8ca50155a58bd056fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k40Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac1c674ad48a47ead5c1bd0b4d0e6611a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k40Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2133b89c1fce6c11540a55ede3d00715</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k41Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa70d2ecf42316dbf7ea9147384b1d16b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k41Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac3ec49935f60ef5a877f21c6225274f5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k50</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gada66cacb0407add2f87505ba08b98095</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k51</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5ed1fd3424cda0c720d08dab3cdacdec</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k60Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5c5769c0eac0d76ff06cc2b95cf15ca9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k60Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadf94b622b8d58c498a49d37d9561f535</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k61Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf60226cc4b55554791dedf5ac9c6b46c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k61Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7c2a763f2db01800286568722f724c30</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k70Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga957c53627e5492b9b62190be390255c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k70Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2fb8698f83d75be166b99fdbce9e82f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga153beb2d5d562ed4fc8643bf51c711d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFullFront</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga329178a60998946671c5de893797dddf</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFullRear</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga50d89ea22e10fe3acadb02c071288776</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0dbaa8d90949e4084abb7878a5d5f91b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineSideFill</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga27352e019fb6f0d3b4d10b643f79d813</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71Proximity</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9ad1279216eaac4c4c2cd665e6d61c82</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2ebfc79a0e5ef338247e31239967632d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae026a8a57e8a9a408320616a0d289ece</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafae2531e75a317dd357fa09074fab4f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga4c68f76511df6119eca847b005105cd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kBFormat1stOrder</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga976822b4dfee259ae8f59a25c9a971af</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>kBFormat</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1b2703b73a743bc1c75149acddeb42ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k80Cube</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga44ee3dd3579cc26082915d76a28be70f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineTopCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9c79cded90ddc1a1e366e1fbf4315334</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineCenterHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafca48c099db5b486edc4a79616b3f024</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineFrontHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8e2c48c3830b09da02e7bb123f5916bd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf21f025b23bb45133395657787f88a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71CineSideHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga300b4574ad12477ff99286519b754dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k81MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1d7c7f813f01cd3f4478ecc81e46e82c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k90</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab04f1f4652d14e277671a0b62a8e8373</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k91</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac29f63756f056bf266ba0e2d26f143d4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k71_2</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa6ebca6edf27a3858c2780043ee022e6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k91Atmos</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga543a82154cd2675d7d8c4ef6680448dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k100</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6cadcafb161f16aa7edcc676604e4def</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k101</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga13c1699c11fba17352b83a1b3a7cfcc8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k101MPEG3D</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad74c12ca20962432ba88df9807a9f156</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k102</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga07bcd44b9922095ccd79f2195ad80e2b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k110</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf19e8a3b3f0d3a2c0e9587f6cc9b1411</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k111</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga740b694bcebcd228836a5610feeeb929</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k122</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadac6b9c961b9ffdf682f8ff85ea6be64</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k130</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga58d4fdbfb02cceca73527bcbf17bf930</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k131</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac672a7aa5cabd6a5d4c4441e6aadc925</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const SpeakerArrangement</type>
      <name>k222</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga80683d5816c4db7345c6e25dfdbc87a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringEmpty</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga38c557da6a4db5884d2d688c30cc5553</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringMono</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacc3c2f0d3a1a7cefebcd21afcaff0a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereo</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa8801dd84fb2f8566448a99c418d1185</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7baad18ef660784d5ed89c95d0f16aa9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoC</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2057f29b65596edf1cb80ccc6a041b83</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoSide</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabab50191c9f7c6a497f7d148cc3a9741</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCLfe</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa1f7cbf8a6fe0184d7ab51fcb3c4792a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga39cdd95afef98e1901ebdb99183e91f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf980dfe2b66f77f49e5cc064e29baf90</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTR</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga31865a34aa4e3eca16df14729ff1629f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoBF</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga50527ffdd77c1df3a01d2656abdcfaca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga546feab92a740e05c378ee7ac40f35cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga53f43e261801293edcef4a1ad84b279d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1e80c914f10746070e3ffe6e85eb5c1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga137e13924264d25e2b23315c90a1a735</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6bb5e6215f1f55441b2d63e1da3d826d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga0f4c3361e3f81439c234f22f2c526829</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8b4f4ca5b48687d28d352f0fcfae57df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9a75f791d9b04c26b732bc3501c26ee6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString50</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga67879f0e2d9733cd1a725c10b6bd41ac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString51</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad0d54db82db6123d96d1f586b443bca3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6a60a614644af6eb7185b1ca3c863146</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga792624a39e54bdeb84703f79b9180370</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7664212680fd954f8d3bdec7ee52a0a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac847eadaa1938e45601af71cb37737b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga605e76c32caeb4f0d85ada0ffd422b89</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5bda8dedc7edcfa8f36b5a99509c9449</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3475b1b161d22aca3939960e461307a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8840a665e6fa4dac19167726473d6072</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineTopCenter</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6f792b0962f42ec4f133cb64de72d31e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineCenterHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gabbfecee6091fbab1bbd2d3e073b86f5d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFrontHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1447af9f22f48e0d039569b10a17aec2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineSideHigh</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad8deb48b287d7520c56e233f8020243c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFullRear</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab78c124e88ad66fcd06aa09f3871320e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71Proximity</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga30a288eb79dfa6b08afb569234e831d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae7259d85e37e87f3734e0645a890312b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga35c11fa95eb4ed5340307b725c53180d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80Cube</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae9dde9509cd3485e2976e44ec37e2491</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81Cine</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf949196ba6ad50b12f2522524ae2079a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81Music</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga301aef980be40689f6a32d2f2ea5990d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString102</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab514f5233daf9f0d39022eaf6bc3ee39</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString122</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac4932606e4ac1473f0da939a03172e4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString90</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6c5bc2454b2c47a01411fbddd25ee30a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaeb2f8e2f0aab973dbf138f73ff23661f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91Atmos</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga929f2c0539c237e4f67a11d46274e037</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString100</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga230095c9378b6f8cac9f14120786423f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString101</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab2d2b7fc9562b4aec27425a1f46e6b5b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString110</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga403a29103a9bfa626785cfc61bcce1d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString111</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga05776481c1feeb8db0bd8a8f9fd7bcdc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString130</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac7d25b1cc65c51e76c225ae50c4116ba</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString131</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf610b7be568618c5d5c3aa20d4cf2ecb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MPEG</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga86ba0d184e2fd6b86e876d5a7343cc5c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString222</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaad33c8ed818e1d8f2a30195dadf50af9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringBFormat1stOrder</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga68685cd555e022d616adae60c053ecc1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringMonoS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga646cd09e52190d60f2d4ca83faf915aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54144ab0e1dd2babcf5e720950cf7e24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoRS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga63f3673e0a9ad13c3788b583d4fac61b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3cb0fc4337ff0f43bf119b20c7f5d810</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoSS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga22b0cac49e8ef5b3d9a1836abd021720</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoCLfeS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaa6cc8eae43caf89b778136bbb05fc09a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTFS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacff5991a9dd2a3d5a415d499bcfd681b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTSS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gad25d6a1fe574b28440e6b95d94978edb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoTRS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gac777248ebd6fa592c82b7bcb78f9301e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringStereoBFS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8a0f76c380e173edac9016a3dcfc45bb</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gadf31296b53805c54ae5563807650b24e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString30MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaae88a2f1492097d9d64e073cd7943722</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga7e65cdf6a6fc4d8aeffc59a7b1a66a1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString31MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga1b7e67dba5f5333b64eb847d3d78668d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga531abc9ded9f3e0474010cdb22557d0d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString40MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga51fdeb3143151508f6d94344431ce9de</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga3789962208da8454667b34aa666981db</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString41MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga54a60dca7c8b8556b398867c51dc1e00</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString50S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab8903815699fa69a4fd8ec717317dc29</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString51S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafbb743a8f1f0002bae234e2d5910ee8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga16ff5025a411dc1c3b7fc305dfe53073</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString60MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab2533387651492af2317e897bd94bf26</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga2f2f2eb56bcf2977ad670a752c69d793</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString61MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga81d034a4b036e9e9bd0be527711db6fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae72794cddb19856e3ec62e33d290176d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString70MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5f3a9a34dc5798908f848f0b881b8c06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga4b10dc09ef678e66e90330f5b6b591d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaec8cf18e8bfd88584375e66b67fde24e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf3da1b6a98e9f9d01e8141f205f35764</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga8204788aa5b2fce1730c157dc8a9239f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81CineS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafe30ad0333248d38dfd6a162879a97a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MusicS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5b7279077b689fa26044fc2520a413c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString80CubeS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab5aedcc126b998d57c67be78255cd52b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kStringBFormat1stOrderS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gafb8e3e488df5eda20ec2081c389af4ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineTopCenterS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga006f007337addc5c126777bc9e9b774d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineCenterHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaf0c13b30d128debc8f8976927a321f48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFrontHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga19c9b28dd806c4a7cf532e33c4db7d1d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineSideHighS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga708f2bb3ba7a3f624acf291960ca7788</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71CineFullRearS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5e313aadeb060bc3dc88d17ca2e81a06</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString71ProximityS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga86fc6ff2265855e22d3573786e05af2d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString90S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gace125bd22967cceb157097a44d258ef8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gae2ada93ca05061ff875826bd2c44029c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString91AtmosS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga91cfddb4f5981d77f3350655d67880c0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString100S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaec0be9229bbb0796d8d1c69e059e7501</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString101S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga5c88990128aeaf6e70cf777e2e2e07f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString110S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gacd74a4610c5894723966b586ff76780b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString111S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga6520dd17a30ba116ac2877b28a1b8cc9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString130S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gaccdab4f0e651d4c1b0b850e6c8edb9f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString131S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga9cdfa2ff878225396509ca7b25af7f1f</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString102S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga31de54f5e618a467f94a579550328644</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString122S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga800e2e69c905b5feaeda81ac24b3f653</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString81MPEGS</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>ga78b0189e39c80c0bf5cec0ddcce73cf9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kString222S</name>
      <anchorfile>group__speakerArrangements.html</anchorfile>
      <anchor>gab442cbf6e2447ea3a762e0c9c891d274</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::StateType</name>
    <filename>namespaceSteinberg_1_1Vst_1_1StateType.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kProject</name>
      <anchorfile>group__stateType.html</anchorfile>
      <anchor>ga89eaf816243da36726dfe2656c266a4c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const CString</type>
      <name>kDefault</name>
      <anchorfile>group__stateType.html</anchorfile>
      <anchor>ga4f34c8d0372a9d06a2713fd488ece66e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Vst::ViewType</name>
    <filename>namespaceSteinberg_1_1Vst_1_1ViewType.html</filename>
    <member kind="variable">
      <type>const CString</type>
      <name>kEditor</name>
      <anchorfile>namespaceSteinberg_1_1Vst_1_1ViewType.html</anchorfile>
      <anchor>aaa62c4c32f0270a908eb20c7c7124dfc</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
