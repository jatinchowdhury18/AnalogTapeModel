<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>Base Module</title>
    <filename>index</filename>
    <docanchor file="index">baseDependencies</docanchor>
    <docanchor file="index">baseFObject</docanchor>
    <docanchor file="index">baseOtherUsefulClasses</docanchor>
    <docanchor file="index">baseINITIALIZE_TERMINATE</docanchor>
    <docanchor file="index">baseContainers</docanchor>
    <docanchor file="index">baseIPtr</docanchor>
    <docanchor file="index">compilerSystemRequirements</docanchor>
    <docanchor file="index">baseIntro</docanchor>
    <docanchor file="index">basefdebug_h</docanchor>
    <docanchor file="index">baseFThread</docanchor>
    <docanchor file="index">baseString</docanchor>
  </compound>
  <compound kind="file">
    <name>basefwd.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>basefwd_8h</filename>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>baseiids.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>baseiids_8cpp</filename>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>classfactory.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>classfactory_8cpp</filename>
    <includes id="classfactory_8h" name="classfactory.h" local="yes" imported="no">base/source/classfactory.h</includes>
    <includes id="thashtable_8h" name="thashtable.h" local="yes" imported="no">base/source/thashtable.h</includes>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::MetaClasses</namespace>
    <member kind="function">
      <type>uint32</type>
      <name>hashByName</name>
      <anchorfile>namespaceSteinberg_1_1MetaClasses.html</anchorfile>
      <anchor>aa36d57d2425cf2320163c4139c59a763</anchor>
      <arglist>(const SorterByName &amp;s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashByCID</name>
      <anchorfile>namespaceSteinberg_1_1MetaClasses.html</anchorfile>
      <anchor>af7ac2e96cfdbaf215cc0340b3f558dfa</anchor>
      <arglist>(const SorterByCID &amp;s, uint32 m)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>classfactory.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>classfactory_8h</filename>
    <includes id="fobject_8h" name="fobject.h" local="yes" imported="no">base/source/fobject.h</includes>
    <class kind="class">Steinberg::MetaClass</class>
    <class kind="class">Steinberg::ClassFactory</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::MetaClasses</namespace>
    <member kind="define">
      <type>#define</type>
      <name>META_CREATE_FUNC</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>afab65b35bec1c0222e99218f057b0a2c</anchor>
      <arglist>(funcName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CLASS_CREATE_FUNC</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>ae92c46dda6d8a5e8b0862006d1722484</anchor>
      <arglist>(className)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SINGLE_CREATE_FUNC</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>a00b4a846a7ea809e79966dbb26cf86c0</anchor>
      <arglist>(className)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_META_CLASS</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>a46dabd263537e5305c29e252e9d4e0df</anchor>
      <arglist>(className)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_META_CLASS_IFACE</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>acc4233582b4e6b60c26daffd4e9d3573</anchor>
      <arglist>(className, Interface)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>META_CLASS</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>af57be3698f87fcd9b59da1379350b19b</anchor>
      <arglist>(className)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>META_CLASS_IFACE</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>a865cf36ad2027604dad50327bf9761b5</anchor>
      <arglist>(className, Interface)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>META_CLASS_SINGLE</name>
      <anchorfile>classfactory_8h.html</anchorfile>
      <anchor>a63944ca72c7a04d6ec65301936202ffe</anchor>
      <arglist>(className, Interface)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>doc.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>doc_8h</filename>
  </compound>
  <compound kind="file">
    <name>fatomic.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fatomic_8cpp</filename>
    <includes id="fatomic_8h" name="fatomic.h" local="yes" imported="no">base/source/fatomic.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicIncrement</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1447efd051f60e8b5ca8b0eac63cf657</anchor>
      <arglist>(volatile int32 &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicDecrement</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad257b30a64ed76acd91513dcf9f40445</anchor>
      <arglist>(volatile int32 &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicAdd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a799093e0dd4b67b24eb541361c22d826</anchor>
      <arglist>(volatile int32 &amp;var, int32 d)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FAtomicCompareAndSwap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aba9c29c332271f636c7136b6457fc801</anchor>
      <arglist>(volatile int32 &amp;var, int32 oldVar, int32 newVar)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FAtomicCompareAndSwap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a066ac9ced0201a19b880421c1e1d820a</anchor>
      <arglist>(volatile void *&amp;var, void *oldVar, void *newVar)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fatomic.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fatomic_8h</filename>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicIncrement</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1447efd051f60e8b5ca8b0eac63cf657</anchor>
      <arglist>(volatile int32 &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicDecrement</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad257b30a64ed76acd91513dcf9f40445</anchor>
      <arglist>(volatile int32 &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicAdd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a799093e0dd4b67b24eb541361c22d826</anchor>
      <arglist>(volatile int32 &amp;var, int32 d)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FAtomicCompareAndSwap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aba9c29c332271f636c7136b6457fc801</anchor>
      <arglist>(volatile int32 &amp;var, int32 oldVar, int32 newVar)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FAtomicCompareAndSwap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a066ac9ced0201a19b880421c1e1d820a</anchor>
      <arglist>(volatile void *&amp;var, void *oldVar, void *newVar)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fbitset.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fbitset_8cpp</filename>
    <includes id="fbitset_8h" name="fbitset.h" local="yes" imported="no">base/source/fbitset.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fbitset.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fbitset_8h</filename>
    <class kind="class">Steinberg::BitSet</class>
    <class kind="class">Steinberg::IDSet</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fbuffer.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fbuffer_8cpp</filename>
    <includes id="fbuffer_8h" name="fbuffer.h" local="yes" imported="no">base/source/fbuffer.h</includes>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fbuffer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fbuffer_8h</filename>
    <includes id="basefwd_8h" name="basefwd.h" local="yes" imported="no">base/source/basefwd.h</includes>
    <class kind="class">Steinberg::Buffer</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fcleanup.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcleanup_8h</filename>
    <class kind="struct">Steinberg::FDeleter</class>
    <class kind="struct">Steinberg::FArrayDeleter</class>
    <class kind="struct">Steinberg::FPtrNuller</class>
    <class kind="struct">Steinberg::FNuller</class>
    <class kind="struct">Steinberg::FBooleanSetter</class>
    <class kind="struct">Steinberg::FConditionalBoolSetter</class>
    <class kind="struct">Steinberg::FCloser</class>
    <class kind="class">Steinberg::FMallocReleaser</class>
    <namespace>Steinberg</namespace>
    <member kind="typedef">
      <type>FBooleanSetter&lt; bool &gt;</type>
      <name>FBoolSetter</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9dfa5cbdeaed453253a4694a712e95cb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fcommandline.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcommandline_8h</filename>
    <class kind="class">Steinberg::CommandLine::VariablesMap</class>
    <class kind="class">Steinberg::CommandLine::Description</class>
    <class kind="class">Steinberg::CommandLine::Descriptions</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::CommandLine</namespace>
    <member kind="typedef">
      <type>std::vector&lt; std::string &gt;</type>
      <name>FilesVector</name>
      <anchorfile>namespaceSteinberg_1_1CommandLine.html</anchorfile>
      <anchor>ada2a5cd694be1a12f043c986d6e24803</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>parse</name>
      <anchorfile>namespaceSteinberg_1_1CommandLine.html</anchorfile>
      <anchor>a620ed44558399aa89cd3203045114c89</anchor>
      <arglist>(int ac, char *av[], const Descriptions &amp;desc, VariablesMap &amp;result, FilesVector *files=0)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceSteinberg_1_1CommandLine.html</anchorfile>
      <anchor>a6a38965238a994bf87587aac0b83a5be</anchor>
      <arglist>(std::ostream &amp;os, const Descriptions &amp;desc)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fcontainer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcontainer_8h</filename>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <includes id="tlist_8h" name="tlist.h" local="yes" imported="no">base/source/tlist.h</includes>
    <includes id="tqueue_8h" name="tqueue.h" local="yes" imported="no">base/source/tqueue.h</includes>
    <includes id="fobject_8h" name="fobject.h" local="yes" imported="no">base/source/fobject.h</includes>
    <class kind="class">Steinberg::FSortablePtr</class>
    <class kind="class">Steinberg::FComparablePtr</class>
    <class kind="struct">Steinberg::TSorterFunc</class>
    <class kind="class">Steinberg::TSortablePtr</class>
    <class kind="class">Steinberg::ISortablePtr</class>
    <class kind="class">Steinberg::TSortable</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_O</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gab464e7f172584b13fe02ec3831d16681</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_O_REVERSE</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gac6d1411942386bbd9e83dbe95716774d</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_CAST</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga423849b9bfdadc6541a6304561500cee</anchor>
      <arglist>(baseType, type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_CAST_REVERSE</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga727ead8a2b99bf761d038813f92c012f</anchor>
      <arglist>(baseType, type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_CAST</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf5e8a614a354a64b93fd491f6f2e3eef</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_REVERSE_CAST</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf6e5d666b60746c5b852577e1b8f907d</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="typedef">
      <type>TArray&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FArray</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf03da6b1bd24c4c22bc71db173e450b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TLinkedList&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FLinkedList</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga1ec614a366dd32414af8d66a36569d86</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TContainer&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FContainer</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gae7d9cf7c944bca93b440811da5f692d9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fcpu.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcpu_8cpp</filename>
    <includes id="fcpu_8h" name="fcpu.h" local="yes" imported="no">base/source/fcpu.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fcpu.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcpu_8h</filename>
    <class kind="class">Steinberg::FCpuInfo</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fcriticalperformance.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcriticalperformance_8cpp</filename>
    <includes id="fcriticalperformance_8h" name="fcriticalperformance.h" local="yes" imported="no">base/source/fcriticalperformance.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fcriticalperformance.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fcriticalperformance_8h</filename>
    <class kind="class">Steinberg::Performance::Mode</class>
    <class kind="class">Steinberg::FCriticalPerformanceEnabler</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::Performance</namespace>
    <member kind="typedef">
      <type>enum Steinberg::Performance::_AVRT_PRIORITY</type>
      <name>AVRT_PRIORITY</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>aab7ffd9aef3aea93c2118af7463a5346</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum Steinberg::Performance::_AVRT_PRIORITY *</type>
      <name>PAVRT_PRIORITY</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>a8783330040ce351d3984a8ecd302552d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>_AVRT_PRIORITY</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_LOW</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a82f37aa1743cab1c69da7d5ff49d6a8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_NORMAL</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a9ddb04ddf34535472b8f54f043d3a652</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_HIGH</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a3d1e82a3e67940c08fff4233d7ec928f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_CRITICAL</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a9868458188819915b729402bfa060ba2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fdebug.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fdebug_8cpp</filename>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
  </compound>
  <compound kind="file">
    <name>fdebug.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fdebug_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>ASSERT</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a79da58dac9dcdbcd4005f1d440e363ba</anchor>
      <arglist>(f)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>WARNING</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a3dee4af8b0fd4925fc10f13a67ce61ba</anchor>
      <arglist>(s)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PRINTSYSERROR</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>ad48f9d61b00fa2397b11eb977c7785dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUGSTR</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>ae69e6846ddfd99b3f190961851c4503d</anchor>
      <arglist>(s)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VERIFY</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a5de907e07dd6433a750df8008c401755</anchor>
      <arglist>(f)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VERIFY_IS</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a3bbad7c5d165445926888e1d4a7d7e76</anchor>
      <arglist>(f, r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>VERIFY_NOT</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>ab75274746844cb9543447f719c762f0f</anchor>
      <arglist>(f, r)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DBPRT0</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a2f013bfa17e5cb0bd5862f0d080ea14c</anchor>
      <arglist>(a)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DBPRT1</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a2e4b32cfde5e0a19d72edb87782d9b67</anchor>
      <arglist>(a, b)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DBPRT2</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a00277439f4c9047cc504b15606acb54f</anchor>
      <arglist>(a, b, c)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DBPRT3</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a658c71ee64ed6ab44027b43be64a6290</anchor>
      <arglist>(a, b, c, d)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DBPRT4</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a78cb615acc200cca7666a3f57e652733</anchor>
      <arglist>(a, b, c, d, e)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DBPRT5</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a48286714bdcb0de021ab6a4bc8b49fd1</anchor>
      <arglist>(a, b, c, d, e, f)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NEW</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>ab6bca16ed021b1e211fde8669758f199</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>NEWVEC</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>afb65a67a21fbcdc32ced37642a0ba690</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SMTG_IS_TEST</name>
      <anchorfile>fdebug_8h.html</anchorfile>
      <anchor>a7d20c982526ebd75fb56ca5511380b4c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fdynlib.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fdynlib_8cpp</filename>
    <includes id="fdynlib_8h" name="fdynlib.h" local="yes" imported="no">base/source/fdynlib.h</includes>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fdynlib.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fdynlib_8h</filename>
    <includes id="fobject_8h" name="fobject.h" local="yes" imported="no">base/source/fobject.h</includes>
    <class kind="class">Steinberg::FDynLibrary</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fgeoconstants.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fgeoconstants_8h</filename>
  </compound>
  <compound kind="file">
    <name>finitializer.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>finitializer_8cpp</filename>
    <includes id="finitializer_8h" name="finitializer.h" local="yes" imported="no">base/source/finitializer.h</includes>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>PRINT_INITIALIZER_NAMES</name>
      <anchorfile>finitializer_8cpp.html</anchorfile>
      <anchor>ae46c65e53e121c28d04ba656ceccdaf6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PRINT_TERMINATOR_NAMES</name>
      <anchorfile>finitializer_8cpp.html</anchorfile>
      <anchor>afa18362ea3e3ac449bc719c5c4fcb1d3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>finitializer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>finitializer_8h</filename>
    <class kind="class">Steinberg::OneTimeProcedure</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>INIT_FUNCTION_NAME</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>aad6b1f2aca6d49aef24df0af8276d6b7</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>INIT_FUNCTION</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>ae7494da79c0b1bc0418eb5d20f9a9ae1</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TERM_FUNCTION_NAME</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>ad5a2a463be50fe5c491ca38c9393225a</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TERM_FUNCTION</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a80b6da026cfba1d3e7d9d759b26e5c1d</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>INITIALIZE</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a61d07473d7aad61d78c66301b2f2f19b</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>INITIALIZE_LEVEL</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a197d2987c3e08d30effe09131ce8bc73</anchor>
      <arglist>(name, level)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TERMINATE</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>ab131614bce6e5fb96030f3aee406adf0</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TERMINATE_LEVEL</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a504230cf410c56fd58aab5498ed6212f</anchor>
      <arglist>(name, level)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FRIEND_INITIALIZE</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a5d4ca21e4983483557a4345b2320f600</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FRIEND_TERMINATE</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a152b0536754b386a8453c9d19181d310</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PRE_INITIALIZE</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>a60eeeaa81d83f7115a526f7062b5e6c9</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>POST_INITIALIZE</name>
      <anchorfile>finitializer_8h.html</anchorfile>
      <anchor>ab9c80b377bb381201c68049a1e21e107</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="typedef">
      <type>bool(*</type>
      <name>InitTermFunc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>afae821f317f9d4ecb80a53179d4509d7</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="enumeration">
      <name>InitLevel</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelFirst</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a669724ea6e5eaca89fc8b94ab51a61c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelBelowStd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a3ff40e43f61cfb4478e6a38ea25c00c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelStd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a202de6b09e239b07e54c2c85a6df2523</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelAboveStd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a15816862dbc061fb5515fe76a9e94b19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelLast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a32b7b870dd7c75226d8c8e99399d10f0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fmemory.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fmemory_8cpp</filename>
    <includes id="fmemory_8h" name="fmemory.h" local="yes" imported="no">base/source/fmemory.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>void *</type>
      <name>alignedMalloc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0866afd2bc00609bc7949dd71f2d090e</anchor>
      <arglist>(int32 size, int32 alignment=16)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>alignedFree</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a40dd1b19a72841fbbab3c3ab73a93b35</anchor>
      <arglist>(void *buffer)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fmemory.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fmemory_8h</filename>
    <includes id="fthread_8h" name="fthread.h" local="yes" imported="no">base/source/fthread.h</includes>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <class kind="class">Steinberg::FMemoryPool</class>
    <class kind="class">Steinberg::FMemoryBlockPool</class>
    <class kind="class">Steinberg::FBlockAllocator</class>
    <class kind="class">Steinberg::FObjectPool</class>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>void *</type>
      <name>alignedMalloc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0866afd2bc00609bc7949dd71f2d090e</anchor>
      <arglist>(int32 size, int32 alignment=16)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>alignedFree</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a40dd1b19a72841fbbab3c3ab73a93b35</anchor>
      <arglist>(void *buffer)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fobject.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fobject_8cpp</filename>
    <includes id="fobject_8h" name="fobject.h" local="yes" imported="no">base/source/fobject.h</includes>
    <includes id="fatomic_8h" name="fatomic.h" local="yes" imported="no">base/source/fatomic.h</includes>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <includes id="fthread_8h" name="fthread.h" local="yes" imported="no">base/source/fthread.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::Singleton</namespace>
    <member kind="function">
      <type>bool</type>
      <name>isTerminated</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a84acfabb69fd8f78cc6afad4301357b7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lockRegister</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a1612cf2b7b00489ee4cd0af7999ff7ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unlockRegister</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a2aad80bf0469cb9153a7666f2b2b4817</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>registerInstance</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ad6e6c857d3abf9d8ef37ef8d465c9977</anchor>
      <arglist>(FObject **o)</arglist>
    </member>
    <member kind="variable">
      <type>struct Steinberg::FObjectIIDInitializer</type>
      <name>gFObjectIidInitializer</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a716e8faa9615ce0d3a3b357275d14868</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TArray&lt; FObject ** &gt; *</type>
      <name>singletonInstances</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ac26b4464420aabba88684fe40d11edff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>singletonsTerminated</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ae52f18a708ab305abe54c48ffc1c9840</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>FLock *</type>
      <name>singletonsLock</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a29266b1d4111658632fadb4ef9b57b23</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct Steinberg::Singleton::Deleter</type>
      <name>deleter</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ad6199b16f89340fdc59b661207d8ae40</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fobject.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fobject_8h</filename>
    <includes id="basefwd_8h" name="basefwd.h" local="yes" imported="no">base/source/basefwd.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <class kind="class">Steinberg::FObject</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::Singleton</namespace>
    <member kind="define">
      <type>#define</type>
      <name>SINGLETON</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a69f2b09f8941011cb853819558eff4a7</anchor>
      <arglist>(ClassName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OBJ_METHODS</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a5a6e2365f969f95aee286638cf6164c7</anchor>
      <arglist>(className, baseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>REFCOUNT_METHODS</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>aebbb3846780fdaf18f8ee89b73ff149d</anchor>
      <arglist>(BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_INTERFACES</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a3c0ce0ce836f44d269b414624e3e0971</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEF_INTERFACE</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a53e7d200032b573e38e925748fdb89e3</anchor>
      <arglist>(InterfaceName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>END_DEFINE_INTERFACES</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a7991876302dbc825f493930c856dbd83</anchor>
      <arglist>(BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEF_INTERFACES_1</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>aba57dd99d0ef259ecc04fc3d05734e88</anchor>
      <arglist>(InterfaceName, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEF_INTERFACES_2</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a334b586ec792ec3bcd90863cc61eb27c</anchor>
      <arglist>(InterfaceName1, InterfaceName2, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEF_INTERFACES_3</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a06f8f8494473247c3a89e0627600b0ad</anchor>
      <arglist>(InterfaceName1, InterfaceName2, InterfaceName3, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEF_INTERFACES_4</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a8fa73969db52bf1e78aaea1b2175128e</anchor>
      <arglist>(InterfaceName1, InterfaceName2, InterfaceName3, InterfaceName4, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FUNKNOWN_METHODS</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a1ad212b9357c288b64de6b6a46c19a57</anchor>
      <arglist>(InterfaceName, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FUNKNOWN_METHODS2</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>ad07f904465df9375353c5ca367a5dfb2</anchor>
      <arglist>(InterfaceName1, InterfaceName2, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FUNKNOWN_METHODS3</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>aa888a63aad080dec3651edbb764cd8bd</anchor>
      <arglist>(InterfaceName1, InterfaceName2, InterfaceName3, BaseClass)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FUNKNOWN_METHODS4</name>
      <anchorfile>fobject_8h.html</anchorfile>
      <anchor>a41a8ea197ab9208b554473144f6572fd</anchor>
      <arglist>(InterfaceName1, InterfaceName2, InterfaceName3, InterfaceName4, BaseClass)</arglist>
    </member>
    <member kind="typedef">
      <type>FIDString</type>
      <name>FClassID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0ef7984d607f98b4a18eb2acdf2d4858</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0dcd9f1c6ef7535727383eb61d29bd80</anchor>
      <arglist>(const FObject *object)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8d57d3b99295e8f84b87e51cf01e9f61</anchor>
      <arglist>(FUnknown *unknown)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FUCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa778c9fbf69ebf5e9373a9fd5599f05b</anchor>
      <arglist>(FObject *object)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FUCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2d7f6fc1f95cff2a8e80b0f539c191ff</anchor>
      <arglist>(FUnknown *object)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AssignShared</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a859d56e4a26f41f6e300e2326ed4707f</anchor>
      <arglist>(T *&amp;dest, T *newPtr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AssignSharedDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa8252fcff23467a221d6f4ee41140bf0</anchor>
      <arglist>(IDependent *_this, T *&amp;dest, T *newPtr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AssignSharedDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>afdcaf76ae8554fbcbeb20942947ba17e</anchor>
      <arglist>(IDependent *_this, IPtr&lt; T &gt; &amp;dest, T *newPtr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeReleaseDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae960ca0a477b1a5c9a1c21dcb284d039</anchor>
      <arglist>(IDependent *_this, T *&amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeReleaseDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a3568ca6d87f19ef4a712982beaa7b7be</anchor>
      <arglist>(IDependent *_this, IPtr&lt; T &gt; &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>registerInstance</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ad6e6c857d3abf9d8ef37ef8d465c9977</anchor>
      <arglist>(FObject **o)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTerminated</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a84acfabb69fd8f78cc6afad4301357b7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lockRegister</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a1612cf2b7b00489ee4cd0af7999ff7ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unlockRegister</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a2aad80bf0469cb9153a7666f2b2b4817</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeRelease</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af8fe5ae0451e2f5b7ca20ac44615bd39</anchor>
      <arglist>(I *&amp;ptr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeRelease</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4ad3ac400880f6a870d30ff35a26ea1d</anchor>
      <arglist>(IPtr&lt; I &gt; &amp;ptr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeDelete</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a00e2bc527488c121724d164b86d5d8f7</anchor>
      <arglist>(T *&amp;ptr)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fpoint.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fpoint_8cpp</filename>
    <includes id="fpoint_8h" name="fpoint.h" local="yes" imported="no">base/source/fpoint.h</includes>
    <includes id="frect_8h" name="frect.h" local="yes" imported="no">base/source/frect.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fpoint.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fpoint_8h</filename>
    <class kind="class">Steinberg::Point</class>
    <namespace>Steinberg</namespace>
    <member kind="typedef">
      <type>Point</type>
      <name>UPoint</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a078b3f23313b653d7999a87b7bc281f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adfd0944abddbf6bf17c4194bde712469</anchor>
      <arglist>(const Point &amp;p1, const Point &amp;p2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5a4e69c52d9dd5bc464f4a9dc81b3205</anchor>
      <arglist>(const Point &amp;p1, const Point &amp;p2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frect.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>frect_8cpp</filename>
    <includes id="frect_8h" name="frect.h" local="yes" imported="no">base/source/frect.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>frect.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>frect_8h</filename>
    <includes id="fpoint_8h" name="fpoint.h" local="yes" imported="no">base/source/fpoint.h</includes>
    <class kind="class">Steinberg::Rect</class>
    <namespace>Steinberg</namespace>
    <member kind="typedef">
      <type>Rect</type>
      <name>URect</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a17b21e67d7630839e08ca56301f63261</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6ea493ebfd7b9d7275da30ea42ea6ae7</anchor>
      <arglist>(const Rect &amp;r1, const Rect &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af1d581514e75e4ec77e2b0825698adde</anchor>
      <arglist>(const Rect &amp;r1, const Rect &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae063f682609badf81ee491be7b154c64</anchor>
      <arglist>(const Rect &amp;r1, const Rect &amp;r2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fregion.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fregion_8cpp</filename>
    <includes id="fregion_8h" name="fregion.h" local="yes" imported="no">base/source/fregion.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="typedef">
      <type>void(*</type>
      <name>OverlapFunc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a90ff542030e7656c47268564c1918c0f</anchor>
      <arglist>)(register Region &amp;dest, register const Rect *r1, const Rect *r1End, register const Rect *r2, const Rect *r2End, register UCoord y1, register UCoord y2)</arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>NonOverlapFunc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a01cfb8fb1d76142b3e6dda36f7d56111</anchor>
      <arglist>)(register Region &amp;dest, register const Rect *r, const Rect *rEnd, register UCoord y1, register UCoord y2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MergeRect</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab5ccf32250bacd4eb4ef0c4d2355007b</anchor>
      <arglist>(register TArray&lt; Rect &gt; &amp;destRects, const Rect *&amp;r, register int32 y1, register int32 y2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fregion.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fregion_8h</filename>
    <includes id="frect_8h" name="frect.h" local="yes" imported="no">base/source/frect.h</includes>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <class kind="class">Steinberg::Region</class>
    <namespace>Steinberg</namespace>
    <member kind="typedef">
      <type>TArray&lt; Rect &gt;</type>
      <name>RectangleArray</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a142b899ad309a2cea5e842afad33c872</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>frwlock_generic.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>frwlock__generic_8h</filename>
    <class kind="class">Steinberg::RWLockRecursion</class>
    <class kind="struct">Steinberg::RWLockRecursion::RecursionCount</class>
    <class kind="struct">Steinberg::RWLockRecursion::RecursionCounts</class>
    <class kind="struct">Steinberg::RWLockRecursion::TLS</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>frwlock_macosx.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>frwlock__macosx_8h</filename>
    <includes id="frwlock__generic_8h" name="frwlock_generic.h" local="yes" imported="no">base/source/frwlock_generic.h</includes>
    <class kind="struct">Steinberg::PThreadWriterPreferenceRWLock</class>
    <class kind="struct">Steinberg::PThreadSlimWriterPreferenceRWLock</class>
    <class kind="struct">Steinberg::PThreadReaderPreferenceRWLock</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>frwlock_windows.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>frwlock__windows_8h</filename>
    <includes id="frwlock__generic_8h" name="frwlock_generic.h" local="yes" imported="no">base/source/frwlock_generic.h</includes>
    <class kind="struct">Steinberg::WindowsWriterPreferenceRWLock</class>
    <class kind="struct">Steinberg::WindowsWriterPreferenceRWLock::SlimRWLockProcs</class>
    <class kind="struct">Steinberg::WindowsReaderPreferenceRWLock</class>
    <class kind="class">Steinberg::WindowsCompatibilityRWLock</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fstdmethods.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fstdmethods_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_VARIABLE</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>ac7b33405a809656816db90c2e08874fc</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_POINTER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a1ca15419dc50b5ec2cc22adad87ed510</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a7bdc96c0dcfb2b23658d8f985a83048b</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>COMPARE_BY_MEMBER_METHODS</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>aca2d3c80e58016d970e75479136fe8bf</anchor>
      <arglist>(className, memberName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>COMPARE_BY_MEMORY_METHODS</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a236e4ee9734fadabedc1f4d6e877e2ab</anchor>
      <arglist>(className)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>COMPARE_BY_COMPARE_METHOD</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>ad013585d1ece4615f652ec6bf5929cef</anchor>
      <arglist>(className, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_STATE</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a3aa7211bde6c894d83fb000e32667c45</anchor>
      <arglist>(flagVar, methodName, value)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_FLAG</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>ad2fa6d3fa7d143009198b5b4d744c2dc</anchor>
      <arglist>(flagVar, methodName, value)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEFINE_FLAG_STATIC</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a5d0a2bb91ac8f0fc96153c610f872a92</anchor>
      <arglist>(flagVar, methodName, value)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DATA_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a796d97a5cd47b9a00411cf71ab6ebf71</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>CLASS_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a8bc055fe95609ed757fbc5f03b5c28c1</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>POINTER_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a894c0fe14fa8fad008264abe4a3660b1</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SHARED_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a9fe746aafac5178bf27bf6ac3fcaca4c</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>OWNED_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a5c19e8bb326e36e0ffd0ec5447c38dd4</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>STRING_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a0efb389fce03cc1bc8190565a8adaa0a</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>STRING8_MEMBER</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a7f1231ffc827e3c4244a9b30c43ed5e2</anchor>
      <arglist>(type, varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>STRING_MEMBER_STD</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>a19e11906d2147132f158e03e253398a1</anchor>
      <arglist>(varName, methodName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>STRING8_MEMBER_STD</name>
      <anchorfile>fstdmethods_8h.html</anchorfile>
      <anchor>ac846c65c8e67ae789595f6dd95cba54c</anchor>
      <arglist>(varName, methodName)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fstreamer.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fstreamer_8cpp</filename>
    <includes id="fstreamer_8cpp" name="fstreamer.cpp" local="yes" imported="no">fstreamer.h</includes>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <includes id="fbuffer_8h" name="fbuffer.h" local="yes" imported="no">base/source/fbuffer.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>fstreamer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fstreamer_8h</filename>
    <class kind="class">Steinberg::FStreamer</class>
    <class kind="class">Steinberg::FStreamSizeHolder</class>
    <class kind="class">Steinberg::IBStreamer</class>
    <namespace>Steinberg</namespace>
    <member kind="enumeration">
      <name>FSeekMode</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24db</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSeekSet</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24dbad9fe3df36943c836f26fd55f2e800384</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSeekCurrent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24dbaff1a9d5b4238462a49619084e8324b85</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSeekEnd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24dbaa2d1805ccbf869dc4a610f9571d83d7f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fstring.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fstring_8cpp</filename>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>uint32</type>
      <name>hashString8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a166ebc6677e19253cda1f55ead2b8106</anchor>
      <arglist>(const char8 *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a61e26dc8165fa82a90f930a1f8367a3c</anchor>
      <arglist>(const char16 *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrnatcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8da7606964bc54f792be75edb50d5731</anchor>
      <arglist>(const T *s1, const T *s2, bool caseSensitive=true)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab16cda4272acda12af7fe328eb3abbfa</anchor>
      <arglist>(const char8 *s1, const char8 *s2, bool caseSensitive)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a026eef900ab2e9f3c1390d73992a48a2</anchor>
      <arglist>(const char16 *s1, const char16 *s2, bool caseSensitive)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fstring.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fstring_8h</filename>
    <includes id="fobject_8h" name="fobject.h" local="yes" imported="no">base/source/fobject.h</includes>
    <class kind="class">Steinberg::ConstString</class>
    <class kind="class">Steinberg::String</class>
    <class kind="class">Steinberg::StringObject</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>SMTG_STRING_CHECK_CONVERSION</name>
      <anchorfile>fstring_8h.html</anchorfile>
      <anchor>a4d8936bba50eec59bad21b4d3ba3ccd2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>MBCodePage</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_ANSI</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a4bc87ed163042e19a3c8c857f320e601</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_MAC_ROMAN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198aece485d20e1f11025207f5d03331170b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_ANSI_WEL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198ae306671b758491ebea5651afc41faf06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_MAC_CEE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198afdfb28513dca7897ba46509177f3f295</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_Utf8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a42fe778326afe1a478de66fa0ae88053</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_ShiftJIS</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a800fe314d21309f85659ee3c8ff41fba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_US_ASCII</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a68f73e16ffd280be8ea415937c17901e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_Default</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198ab93a845dd7dd03d5e296ffff03a78aa2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>UnicodeNormalization</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormC</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5a5ab93cdbd8bb16cc7261b7d02f656426</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormD</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5a719813623d8e0a706e6ab6cd2a0fb0f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormKC</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5a6bc71341f3a88c030bc7f46992d39c99</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormKD</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5ad8daa621694a792a6b4368b2e1caccad</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a166ebc6677e19253cda1f55ead2b8106</anchor>
      <arglist>(const char8 *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a61e26dc8165fa82a90f930a1f8367a3c</anchor>
      <arglist>(const char16 *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab9e1f71a717bf28978e67938cf197360</anchor>
      <arglist>(const char *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ada25fd2a2681fec14af4507826ffdfe8</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2c3adccbf0361ed1e35dc58f474aa783</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0047a2ab78ce4594023b5691eda91128</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adafb26f233ad745fb7503011697a8d89</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4d79863da188e183ae4150116906ad6b</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1a02a54515930b11df9cb7c05ed0a663</anchor>
      <arglist>(const ConstString &amp;s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af032c74c6993e1abfbd7bccda3fea33d</anchor>
      <arglist>(const String &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac18cc72253d13ec535ba0187d07759af</anchor>
      <arglist>(const String &amp;s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa19edede938efc8875df07e2079cb898</anchor>
      <arglist>(const String &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae356517d1995baa9053ae4cbec848b85</anchor>
      <arglist>(const String &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a86f7c6c4e0f84a11e5583452e809debe</anchor>
      <arglist>(const char8 *s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a484a5c7b2980c3eddde1777f4f8740e2</anchor>
      <arglist>(const char16 *s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad5ce23c4f9cca43a9f66ef23d9325159</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>afc04c8ac4717595b641a119f8e1f4c08</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac98deb5a1f36329c44edeee647d46431</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a98082cddf36f42dae42928aab7b7d704</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af65b89110f91b435a658a09cde45ee6b</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aaad28d7939d8454ba62e2ed43e6b6a07</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>acf5c2d96088a26678de1f7ba2b0610a9</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab4e3d70dc9e542aa4830d9026f49e318</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a296a0841f7c8f2fc3a5708556c720a5a</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a111fe3210982295b10c2b0a6c64f8849</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8e6d100fac4f2e9011a595eb516d21ea</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>acf534ee8bc3f7368a3a21e666eb87e88</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7e81e3384f1e73b68dba43f8ca561b27</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7784e17f867a990478e8b3a25216f047</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7792b96abbdb52f88644a2d7fdc0635d</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a763dcfcbf62f158517e3265575e09b03</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af532a1fe0c1fa0b787fb1c6fa58048e4</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a294195888b30e4aa51ac89171313dddd</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7a3ef53c29d18481261d4ad40fbd93d8</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5dac4595f7ec9120e736fc4a72b263a4</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a59823787882c26e6dc2a849a23785b22</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1bfad3a77225793f845ad097c4b694a6</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5998cbea9b1218b35018328826e6a40d</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a34e7201686726b43099edeabc6e64b02</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4a5e176ffe4e3d42b9dbdd5ff6b6a232</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab43ab059cf7a1b2eee6dcf7db9429f72</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af8868f64b08e62fc4ca89095b748dcb3</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a70fa44d88af75be3d8d5402aa761370c</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a645271d1621265af41557ff516b67961</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a262d596d26d40f41fab24af7162c7020</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab16cda4272acda12af7fe328eb3abbfa</anchor>
      <arglist>(const char8 *s1, const char8 *s2, bool caseSensitive)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a026eef900ab2e9f3c1390d73992a48a2</anchor>
      <arglist>(const char16 *s1, const char16 *s2, bool caseSensitive)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af813b691586a7d0180f9275b88d8ce86</anchor>
      <arglist>(const char *s1, const char *s2, bool caseSensitive=true)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fstringmethods.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fstringmethods_8h</filename>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <includes id="tcontainer_8h" name="tcontainer.h" local="yes" imported="no">base/source/tcontainer.h</includes>
    <includes id="basefwd_8h" name="basefwd.h" local="yes" imported="no">base/source/basefwd.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::StringMethods</namespace>
    <namespace>Steinberg::StringMethods::Detail</namespace>
    <member kind="function">
      <type>void</type>
      <name>doSplit</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods_1_1Detail.html</anchorfile>
      <anchor>a808022834ff91954daef97b53362d962</anchor>
      <arglist>(const ConstString &amp;string, const ConstString &amp;separatorString, Structure &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>parseVersionString</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods.html</anchorfile>
      <anchor>a7f6e8b98fa44d2679fa6941a216961b7</anchor>
      <arglist>(const ConstString &amp;string, int32 &amp;major, int32 &amp;sub, int32 &amp;release)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>split</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods.html</anchorfile>
      <anchor>a35f4f5cf5fb596c8397fe265fbd2d5c7</anchor>
      <arglist>(const ConstString &amp;string, const ConstString &amp;separatorString, TContainer&lt; String &gt; &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tsplit</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods.html</anchorfile>
      <anchor>ac4f527ba056a1ce2c6fbab16304d02f0</anchor>
      <arglist>(const ConstString &amp;string, const ConstString &amp;separatorString, Structure &amp;result)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fthread.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fthread_8cpp</filename>
    <includes id="fthread_8h" name="fthread.h" local="yes" imported="no">base/source/fthread.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <includes id="frwlock__macosx_8h" name="frwlock_macosx.h" local="yes" imported="no">base/source/frwlock_macosx.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_LOCK</name>
      <anchorfile>fthread_8cpp.html</anchorfile>
      <anchor>a7480a62cb6d1de6cc68d75ffc1d901bf</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEBUG_RWLOCK</name>
      <anchorfile>fthread_8cpp.html</anchorfile>
      <anchor>a44ded526eda22577e1e9434d21b24bc5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>FThreadSleep</name>
      <anchorfile>group__baseThread.html</anchorfile>
      <anchor>ga898954af0718c9e046380393ccc3457d</anchor>
      <arglist>(int32 milliseconds)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fthread.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>fthread_8h</filename>
    <includes id="fstring_8h" name="fstring.h" local="yes" imported="no">base/source/fstring.h</includes>
    <includes id="fatomic_8h" name="fatomic.h" local="yes" imported="no">base/source/fatomic.h</includes>
    <class kind="class">Steinberg::FThread</class>
    <class kind="struct">Steinberg::IThreadSpy</class>
    <class kind="struct">Steinberg::ILock</class>
    <class kind="class">Steinberg::FLock</class>
    <class kind="class">Steinberg::FLockObject</class>
    <class kind="class">Steinberg::FCondition</class>
    <class kind="class">Steinberg::FRwLock</class>
    <class kind="class">Steinberg::FGuard</class>
    <class kind="class">Steinberg::FConditionalGuard</class>
    <class kind="class">Steinberg::FConditionalReadGuard</class>
    <class kind="class">Steinberg::FConditionalWriteGuard</class>
    <class kind="class">Steinberg::FSemaphore</class>
    <class kind="class">Steinberg::FSemaphoreGuard</class>
    <class kind="class">Steinberg::FReadGuardT</class>
    <class kind="class">Steinberg::FWriteGuardT</class>
    <class kind="class">Steinberg::FRecursionCounter</class>
    <class kind="class">Steinberg::FRecursionGuard</class>
    <class kind="class">Steinberg::FLocalThreadStorage</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::FPanicAssert</namespace>
    <member kind="define">
      <type>#define</type>
      <name>PANIC_ASSERT</name>
      <anchorfile>fthread_8h.html</anchorfile>
      <anchor>aaeb6ff43b6bff770d8e7ccb77ab759fc</anchor>
      <arglist>(test, code)</arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>PANIC_FUNC</name>
      <anchorfile>namespaceSteinberg_1_1FPanicAssert.html</anchorfile>
      <anchor>ac6f1befc1b6dca867d7b014492799131</anchor>
      <arglist>)(int32 code)</arglist>
    </member>
    <member kind="typedef">
      <type>FReadGuardT&lt; FRwLock &gt;</type>
      <name>FReadGuard</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a55c03694e8f66a604d8024bb568cc252</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>FWriteGuardT&lt; FRwLock &gt;</type>
      <name>FWriteGuard</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a76b91d2c3ab69f871c58df19427526a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>FThreadPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLowPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5a557242830eb32b4ce0f4ae1781dcee13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kBelowNormalPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5aa6524724fa22dca5e975d298ca947dc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNormalPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5a187b8784f46ca737896c5ce69d852ee0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAboveNormalPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5acb0997c29c3ed1a5d4104a0d42145831</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kHighPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5aee02c07a356b561b0de2b686b62eab58</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRealtimePriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5ac2aa2b44836895a62a02a77adfb8226f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPanicHook</name>
      <anchorfile>namespaceSteinberg_1_1FPanicAssert.html</anchorfile>
      <anchor>a3203e0fe6b98563ef3aaf1cabc1280d1</anchor>
      <arglist>(PANIC_FUNC newPanicHook)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>panic</name>
      <anchorfile>namespaceSteinberg_1_1FPanicAssert.html</anchorfile>
      <anchor>a34cf34c5ab9282e581609733723ff6fd</anchor>
      <arglist>(int32 code)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>FThreadSleep</name>
      <anchorfile>group__baseThread.html</anchorfile>
      <anchor>ga898954af0718c9e046380393ccc3457d</anchor>
      <arglist>(int32 milliseconds)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>funknownfactory.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>funknownfactory_8h</filename>
    <includes id="classfactory_8h" name="classfactory.h" local="yes" imported="no">base/source/classfactory.h</includes>
    <class kind="class">Steinberg::FUnknownFactory</class>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>IPtr&lt; T &gt;</type>
      <name>newFUnknown</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a29c88637282342c2f52064ea8dc264d4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>hexbinary.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>hexbinary_8h</filename>
    <includes id="fbuffer_8h" name="fbuffer.h" local="yes" imported="no">base/source/fbuffer.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::HexBinary</namespace>
    <member kind="function">
      <type>bool</type>
      <name>decode</name>
      <anchorfile>namespaceSteinberg_1_1HexBinary.html</anchorfile>
      <anchor>a567d62615b1d9ccab3b175b4b9fc61f0</anchor>
      <arglist>(const void *input, int32 inputSize, Buffer &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>encode</name>
      <anchorfile>namespaceSteinberg_1_1HexBinary.html</anchorfile>
      <anchor>a409cabd0268ae39045fe68f7816a06af</anchor>
      <arglist>(const void *input, int32 inputSize, Buffer &amp;result)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>istreamwrapper.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>istreamwrapper_8cpp</filename>
    <includes id="istreamwrapper_8h" name="istreamwrapper.h" local="yes" imported="no">base/source/istreamwrapper.h</includes>
  </compound>
  <compound kind="file">
    <name>istreamwrapper.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>istreamwrapper_8h</filename>
  </compound>
  <compound kind="file">
    <name>tarray.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tarray_8h</filename>
    <includes id="tcontainer_8h" name="tcontainer.h" local="yes" imported="no">base/source/tcontainer.h</includes>
    <class kind="class">Steinberg::TArrayBase</class>
    <class kind="class">Steinberg::TArray</class>
    <class kind="class">Steinberg::TOrderedArray</class>
    <class kind="class">Steinberg::TSortableArray</class>
    <class kind="class">Steinberg::TArrayIterator</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>gac05ce36beacc8c92ac6772e708df6fb8</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE_REVERSE</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga6a014628854e4ad80b0c8d1f33316ce9</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE_I</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga77a77f6817cb347fb029db4bdb346782</anchor>
      <arglist>(type, obj, containter, index)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE_REVERSE_I</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>gac189dace85d9abe6facda2f6d8d86866</anchor>
      <arglist>(type, obj, containter, index)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>tassociation.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tassociation_8h</filename>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <class kind="class">Steinberg::TAssociation</class>
    <class kind="class">Steinberg::TAssociationArray</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tbag.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tbag_8h</filename>
    <includes id="thashtable_8h" name="thashtable.h" local="yes" imported="no">base/source/thashtable.h</includes>
    <includes id="thashset_8h" name="thashset.h" local="yes" imported="no">base/source/thashset.h</includes>
    <class kind="class">Steinberg::TBag</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tbinarytree.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tbinarytree_8h</filename>
    <includes id="tqueue_8h" name="tqueue.h" local="yes" imported="no">base/source/tqueue.h</includes>
    <includes id="tstack_8h" name="tstack.h" local="yes" imported="no">base/source/tstack.h</includes>
    <class kind="class">Steinberg::TBinaryTree</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tbtree.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tbtree_8h</filename>
    <includes id="tcontainer_8h" name="tcontainer.h" local="yes" imported="no">base/source/tcontainer.h</includes>
    <class kind="class">Steinberg::TBTree</class>
    <class kind="class">Steinberg::TBTreeNode</class>
    <class kind="class">Steinberg::TBTreeIterator</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tbtreedictionary.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tbtreedictionary_8h</filename>
    <includes id="tbtree_8h" name="tbtree.h" local="yes" imported="no">base/source/tbtree.h</includes>
    <includes id="tassociation_8h" name="tassociation.h" local="yes" imported="no">base/source/tassociation.h</includes>
    <class kind="class">Steinberg::TBTreeDictionary</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tbtreeset.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tbtreeset_8h</filename>
    <includes id="tbtree_8h" name="tbtree.h" local="yes" imported="no">base/source/tbtree.h</includes>
    <class kind="class">Steinberg::TBTreeSet</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tcontainer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tcontainer_8h</filename>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <includes id="fcleanup_8h" name="fcleanup.h" local="yes" imported="no">base/source/fcleanup.h</includes>
    <class kind="class">Steinberg::TContainer</class>
    <class kind="class">Steinberg::TIterator</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_T</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga5a0c840cc58a642f080299f635fe8d98</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_T_REVERSE</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>gaad0f4b4780f077eac799aab2d117c80c</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ENDFOR</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga62c7f2ec15cb2bc858f3135f52094880</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>tdeque.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tdeque_8h</filename>
    <includes id="tlist_8h" name="tlist.h" local="yes" imported="no">base/source/tlist.h</includes>
    <class kind="class">Steinberg::TDeque</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tdictionary.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tdictionary_8h</filename>
    <includes id="tdlist_8h" name="tdlist.h" local="yes" imported="no">base/source/tdlist.h</includes>
    <includes id="thashtable_8h" name="thashtable.h" local="yes" imported="no">base/source/thashtable.h</includes>
    <includes id="tassociation_8h" name="tassociation.h" local="yes" imported="no">base/source/tassociation.h</includes>
    <class kind="class">Steinberg::TDictionary</class>
    <class kind="class">Steinberg::TDictionaryIterator</class>
    <class kind="class">Steinberg::THashDictionary</class>
    <class kind="class">Steinberg::THashDictionaryIterator</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tdlist.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tdlist_8h</filename>
    <includes id="tcontainer_8h" name="tcontainer.h" local="yes" imported="no">base/source/tcontainer.h</includes>
    <class kind="class">Steinberg::TDLinkedList</class>
    <class kind="struct">Steinberg::TDLinkedList::TDLink</class>
    <class kind="class">Steinberg::TDLinkedListIterator</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>thashset.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>thashset_8h</filename>
    <includes id="thashtable_8h" name="thashtable.h" local="yes" imported="no">base/source/thashtable.h</includes>
    <class kind="class">Steinberg::THashSet</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>thashtable.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>thashtable_8h</filename>
    <includes id="tcontainer_8h" name="tcontainer.h" local="yes" imported="no">base/source/tcontainer.h</includes>
    <class kind="class">Steinberg::THashTable</class>
    <class kind="class">Steinberg::THashBucket</class>
    <class kind="class">Steinberg::THashNode</class>
    <class kind="class">Steinberg::THashTableIterator</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>timer.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>timer_8cpp</filename>
    <includes id="timer_8h" name="timer.h" local="yes" imported="no">base/source/timer.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::SystemTime</namespace>
    <member kind="function">
      <type>int32</type>
      <name>getTicks</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>ae994ceba61021313d4200996d46787f5</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>timer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>timer_8h</filename>
    <includes id="timer_8h" name="timer.h" local="yes" imported="no">fobject.h</includes>
    <includes id="basefwd_8h" name="basefwd.h" local="yes" imported="no">base/source/basefwd.h</includes>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <class kind="class">Steinberg::ITimerCallback</class>
    <class kind="class">Steinberg::Timer</class>
    <class kind="class">Steinberg::DisableDispatchingTimers</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::SystemTime</namespace>
    <member kind="function">
      <type>uint64</type>
      <name>getTicks64</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>a758d89b702e93eb7d4acd84bf1c99c4a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint64</type>
      <name>getTicksDuration</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>a5eb6e497830d117c9591a9d18faa3816</anchor>
      <arglist>(uint64 old, uint64 now)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getTicks</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>ae994ceba61021313d4200996d46787f5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ITimerCallback *</type>
      <name>newTimerCallback</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2399dea34bada017854bf0391c44c3d9</anchor>
      <arglist>(const Call &amp;call)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>tlist.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tlist_8h</filename>
    <includes id="tcontainer_8h" name="tcontainer.h" local="yes" imported="no">base/source/tcontainer.h</includes>
    <class kind="class">Steinberg::TLinkedList</class>
    <class kind="struct">Steinberg::TLinkedList::TLink</class>
    <class kind="class">Steinberg::TLinkedListIterator</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tqueue.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tqueue_8h</filename>
    <includes id="tlist_8h" name="tlist.h" local="yes" imported="no">base/source/tlist.h</includes>
    <class kind="class">Steinberg::TQueue</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tringbuffer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tringbuffer_8h</filename>
    <class kind="class">Steinberg::TRingBuffer</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tstack.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tstack_8h</filename>
    <includes id="tlist_8h" name="tlist.h" local="yes" imported="no">base/source/tlist.h</includes>
    <class kind="class">Steinberg::TStack</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>tvector.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>tvector_8h</filename>
    <includes id="fdebug_8h" name="fdebug.h" local="yes" imported="no">base/source/fdebug.h</includes>
    <class kind="class">Steinberg::TVector</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>updatehandler.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>updatehandler_8cpp</filename>
    <includes id="updatehandler_8h" name="updatehandler.h" local="yes" imported="no">base/source/updatehandler.h</includes>
    <includes id="classfactory_8h" name="classfactory.h" local="yes" imported="no">base/source/classfactory.h</includes>
    <includes id="tarray_8h" name="tarray.h" local="yes" imported="no">base/source/tarray.h</includes>
    <includes id="tlist_8h" name="tlist.h" local="yes" imported="no">base/source/tlist.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::Meta</namespace>
    <member kind="define">
      <type>#define</type>
      <name>NON_EXISTING_DEPENEDENCY_CHECK</name>
      <anchorfile>updatehandler_8cpp.html</anchorfile>
      <anchor>a1f82933a3a3097c5b19b3c7515e987ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DYNAMIC_DEPENDENTS_MAPSIZE</name>
      <anchorfile>updatehandler_8cpp.html</anchorfile>
      <anchor>a7063984dea5f4c2eaef23d22f1aa945e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DEF_CLASS_IID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a03374ef5cb2e4ca5d36313f4c3dd85e2</anchor>
      <arglist>(IUpdateManager) namespace Update</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>updatehandler.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/base/source/</path>
    <filename>updatehandler_8h</filename>
    <includes id="fobject_8h" name="fobject.h" local="yes" imported="no">base/source/fobject.h</includes>
    <includes id="fthread_8h" name="fthread.h" local="yes" imported="no">base/source/fthread.h</includes>
    <class kind="class">Steinberg::IUpdateManager</class>
    <class kind="class">Steinberg::UpdateHandler</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="group">
    <name>adt</name>
    <title>Abstract Data Types</title>
    <filename>group__adt.html</filename>
    <class kind="class">Steinberg::BitSet</class>
    <class kind="class">Steinberg::Buffer</class>
    <class kind="class">Steinberg::Point</class>
    <class kind="class">Steinberg::Rect</class>
    <class kind="class">Steinberg::ConstString</class>
    <class kind="class">Steinberg::String</class>
  </compound>
  <compound kind="group">
    <name>baseUnknownContainer</name>
    <title>FUnknown/FObject Containers</title>
    <filename>group__baseUnknownContainer.html</filename>
    <class kind="class">Steinberg::FSortablePtr</class>
    <class kind="class">Steinberg::FComparablePtr</class>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_O</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gab464e7f172584b13fe02ec3831d16681</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_O_REVERSE</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gac6d1411942386bbd9e83dbe95716774d</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_CAST</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga423849b9bfdadc6541a6304561500cee</anchor>
      <arglist>(baseType, type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_CAST_REVERSE</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga727ead8a2b99bf761d038813f92c012f</anchor>
      <arglist>(baseType, type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_CAST</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf5e8a614a354a64b93fd491f6f2e3eef</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_REVERSE_CAST</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf6e5d666b60746c5b852577e1b8f907d</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="typedef">
      <type>TArray&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FArray</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf03da6b1bd24c4c22bc71db173e450b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TLinkedList&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FLinkedList</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga1ec614a366dd32414af8d66a36569d86</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TContainer&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FContainer</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gae7d9cf7c944bca93b440811da5f692d9</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>baseThread</name>
    <title>Thread Handling</title>
    <filename>group__baseThread.html</filename>
    <class kind="class">Steinberg::FThread</class>
    <class kind="struct">Steinberg::IThreadSpy</class>
    <class kind="struct">Steinberg::ILock</class>
    <class kind="class">Steinberg::FLock</class>
    <class kind="class">Steinberg::FLockObject</class>
    <class kind="class">Steinberg::FCondition</class>
    <class kind="class">Steinberg::FRwLock</class>
    <class kind="class">Steinberg::FGuard</class>
    <class kind="class">Steinberg::FConditionalGuard</class>
    <class kind="class">Steinberg::FConditionalReadGuard</class>
    <class kind="class">Steinberg::FConditionalWriteGuard</class>
    <class kind="class">Steinberg::FSemaphore</class>
    <class kind="class">Steinberg::FSemaphoreGuard</class>
    <class kind="class">Steinberg::FReadGuardT</class>
    <class kind="class">Steinberg::FWriteGuardT</class>
    <class kind="class">Steinberg::FRecursionCounter</class>
    <class kind="class">Steinberg::FRecursionGuard</class>
    <class kind="class">Steinberg::FLocalThreadStorage</class>
    <member kind="function">
      <type>void</type>
      <name>FThreadSleep</name>
      <anchorfile>group__baseThread.html</anchorfile>
      <anchor>ga898954af0718c9e046380393ccc3457d</anchor>
      <arglist>(int32 milliseconds)</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>baseContainer</name>
    <title>Template Containers</title>
    <filename>group__baseContainer.html</filename>
    <class kind="class">Steinberg::TArrayBase</class>
    <class kind="class">Steinberg::TArray</class>
    <class kind="class">Steinberg::TOrderedArray</class>
    <class kind="class">Steinberg::TSortableArray</class>
    <class kind="class">Steinberg::TBag</class>
    <class kind="class">Steinberg::TBinaryTree</class>
    <class kind="class">Steinberg::TBTree</class>
    <class kind="class">Steinberg::TBTreeIterator</class>
    <class kind="class">Steinberg::TBTreeDictionary</class>
    <class kind="class">Steinberg::TBTreeSet</class>
    <class kind="class">Steinberg::TContainer</class>
    <class kind="class">Steinberg::TIterator</class>
    <class kind="class">Steinberg::TDLinkedList</class>
    <class kind="class">Steinberg::THashTable</class>
    <class kind="class">Steinberg::TLinkedList</class>
    <class kind="class">Steinberg::TQueue</class>
    <class kind="class">Steinberg::TRingBuffer</class>
    <class kind="class">Steinberg::TVector</class>
    <class kind="class">Steinberg::TAssociation</class>
    <class kind="class">Steinberg::TAssociationArray</class>
    <class kind="class">Steinberg::TDeque</class>
    <class kind="class">Steinberg::THashSet</class>
    <class kind="class">Steinberg::TStack</class>
    <subgroup>baseUnknownContainer</subgroup>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>gac05ce36beacc8c92ac6772e708df6fb8</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE_REVERSE</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga6a014628854e4ad80b0c8d1f33316ce9</anchor>
      <arglist>(type, obj, containter)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE_I</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga77a77f6817cb347fb029db4bdb346782</anchor>
      <arglist>(type, obj, containter, index)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ARRAY_FOR_EACH_TYPE_REVERSE_I</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>gac189dace85d9abe6facda2f6d8d86866</anchor>
      <arglist>(type, obj, containter, index)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_T</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga5a0c840cc58a642f080299f635fe8d98</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FOREACH_T_REVERSE</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>gaad0f4b4780f077eac799aab2d117c80c</anchor>
      <arglist>(type, varName, cont)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ENDFOR</name>
      <anchorfile>group__baseContainer.html</anchorfile>
      <anchor>ga62c7f2ec15cb2bc858f3135f52094880</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg</name>
    <filename>namespaceSteinberg.html</filename>
    <namespace>Steinberg::MetaClasses</namespace>
    <namespace>Steinberg::CommandLine</namespace>
    <namespace>Steinberg::Performance</namespace>
    <namespace>Steinberg::Singleton</namespace>
    <namespace>Steinberg::StringMethods</namespace>
    <namespace>Steinberg::FPanicAssert</namespace>
    <namespace>Steinberg::HexBinary</namespace>
    <namespace>Steinberg::SystemTime</namespace>
    <namespace>Steinberg::Meta</namespace>
    <class kind="class">Steinberg::MetaClass</class>
    <class kind="class">Steinberg::ClassFactory</class>
    <class kind="class">Steinberg::BitSet</class>
    <class kind="class">Steinberg::IDSet</class>
    <class kind="class">Steinberg::Buffer</class>
    <class kind="struct">Steinberg::FDeleter</class>
    <class kind="struct">Steinberg::FArrayDeleter</class>
    <class kind="struct">Steinberg::FPtrNuller</class>
    <class kind="struct">Steinberg::FNuller</class>
    <class kind="struct">Steinberg::FBooleanSetter</class>
    <class kind="struct">Steinberg::FConditionalBoolSetter</class>
    <class kind="struct">Steinberg::FCloser</class>
    <class kind="class">Steinberg::FMallocReleaser</class>
    <class kind="class">Steinberg::FSortablePtr</class>
    <class kind="class">Steinberg::FComparablePtr</class>
    <class kind="struct">Steinberg::TSorterFunc</class>
    <class kind="class">Steinberg::TSortablePtr</class>
    <class kind="class">Steinberg::ISortablePtr</class>
    <class kind="class">Steinberg::TSortable</class>
    <class kind="class">Steinberg::FCpuInfo</class>
    <class kind="class">Steinberg::FCriticalPerformanceEnabler</class>
    <class kind="class">Steinberg::FDynLibrary</class>
    <class kind="class">Steinberg::OneTimeProcedure</class>
    <class kind="class">Steinberg::FMemoryPool</class>
    <class kind="class">Steinberg::FMemoryBlockPool</class>
    <class kind="class">Steinberg::FBlockAllocator</class>
    <class kind="class">Steinberg::FObjectPool</class>
    <class kind="class">Steinberg::FObject</class>
    <class kind="class">Steinberg::Point</class>
    <class kind="class">Steinberg::Rect</class>
    <class kind="class">Steinberg::Region</class>
    <class kind="class">Steinberg::RWLockRecursion</class>
    <class kind="struct">Steinberg::PThreadWriterPreferenceRWLock</class>
    <class kind="struct">Steinberg::PThreadSlimWriterPreferenceRWLock</class>
    <class kind="struct">Steinberg::PThreadReaderPreferenceRWLock</class>
    <class kind="struct">Steinberg::WindowsWriterPreferenceRWLock</class>
    <class kind="struct">Steinberg::WindowsReaderPreferenceRWLock</class>
    <class kind="class">Steinberg::WindowsCompatibilityRWLock</class>
    <class kind="class">Steinberg::FStreamer</class>
    <class kind="class">Steinberg::FStreamSizeHolder</class>
    <class kind="class">Steinberg::IBStreamer</class>
    <class kind="class">Steinberg::ConstString</class>
    <class kind="class">Steinberg::String</class>
    <class kind="class">Steinberg::StringObject</class>
    <class kind="class">Steinberg::FThread</class>
    <class kind="struct">Steinberg::IThreadSpy</class>
    <class kind="struct">Steinberg::ILock</class>
    <class kind="class">Steinberg::FLock</class>
    <class kind="class">Steinberg::FLockObject</class>
    <class kind="class">Steinberg::FCondition</class>
    <class kind="class">Steinberg::FRwLock</class>
    <class kind="class">Steinberg::FGuard</class>
    <class kind="class">Steinberg::FConditionalGuard</class>
    <class kind="class">Steinberg::FConditionalReadGuard</class>
    <class kind="class">Steinberg::FConditionalWriteGuard</class>
    <class kind="class">Steinberg::FSemaphore</class>
    <class kind="class">Steinberg::FSemaphoreGuard</class>
    <class kind="class">Steinberg::FReadGuardT</class>
    <class kind="class">Steinberg::FWriteGuardT</class>
    <class kind="class">Steinberg::FRecursionCounter</class>
    <class kind="class">Steinberg::FRecursionGuard</class>
    <class kind="class">Steinberg::FLocalThreadStorage</class>
    <class kind="class">Steinberg::FUnknownFactory</class>
    <class kind="class">Steinberg::TArrayBase</class>
    <class kind="class">Steinberg::TArray</class>
    <class kind="class">Steinberg::TOrderedArray</class>
    <class kind="class">Steinberg::TSortableArray</class>
    <class kind="class">Steinberg::TArrayIterator</class>
    <class kind="class">Steinberg::TAssociation</class>
    <class kind="class">Steinberg::TAssociationArray</class>
    <class kind="class">Steinberg::TBag</class>
    <class kind="class">Steinberg::TBinaryTree</class>
    <class kind="class">Steinberg::TBTree</class>
    <class kind="class">Steinberg::TBTreeNode</class>
    <class kind="class">Steinberg::TBTreeIterator</class>
    <class kind="class">Steinberg::TBTreeDictionary</class>
    <class kind="class">Steinberg::TBTreeSet</class>
    <class kind="class">Steinberg::TContainer</class>
    <class kind="class">Steinberg::TIterator</class>
    <class kind="class">Steinberg::TDeque</class>
    <class kind="class">Steinberg::TDictionary</class>
    <class kind="class">Steinberg::TDictionaryIterator</class>
    <class kind="class">Steinberg::THashDictionary</class>
    <class kind="class">Steinberg::THashDictionaryIterator</class>
    <class kind="class">Steinberg::TDLinkedList</class>
    <class kind="class">Steinberg::TDLinkedListIterator</class>
    <class kind="class">Steinberg::THashSet</class>
    <class kind="class">Steinberg::THashTable</class>
    <class kind="class">Steinberg::THashBucket</class>
    <class kind="class">Steinberg::THashNode</class>
    <class kind="class">Steinberg::THashTableIterator</class>
    <class kind="class">Steinberg::ITimerCallback</class>
    <class kind="class">Steinberg::Timer</class>
    <class kind="class">Steinberg::DisableDispatchingTimers</class>
    <class kind="class">Steinberg::TLinkedList</class>
    <class kind="class">Steinberg::TLinkedListIterator</class>
    <class kind="class">Steinberg::TQueue</class>
    <class kind="class">Steinberg::TRingBuffer</class>
    <class kind="class">Steinberg::TStack</class>
    <class kind="class">Steinberg::TVector</class>
    <class kind="class">Steinberg::IUpdateManager</class>
    <class kind="class">Steinberg::UpdateHandler</class>
    <member kind="typedef">
      <type>FBooleanSetter&lt; bool &gt;</type>
      <name>FBoolSetter</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9dfa5cbdeaed453253a4694a712e95cb</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TArray&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FArray</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gaf03da6b1bd24c4c22bc71db173e450b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TLinkedList&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FLinkedList</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>ga1ec614a366dd32414af8d66a36569d86</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TContainer&lt; IPtr&lt; FUnknown &gt; &gt;</type>
      <name>FContainer</name>
      <anchorfile>group__baseUnknownContainer.html</anchorfile>
      <anchor>gae7d9cf7c944bca93b440811da5f692d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>bool(*</type>
      <name>InitTermFunc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>afae821f317f9d4ecb80a53179d4509d7</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="typedef">
      <type>FIDString</type>
      <name>FClassID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0ef7984d607f98b4a18eb2acdf2d4858</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Point</type>
      <name>UPoint</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a078b3f23313b653d7999a87b7bc281f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Rect</type>
      <name>URect</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a17b21e67d7630839e08ca56301f63261</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>OverlapFunc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a90ff542030e7656c47268564c1918c0f</anchor>
      <arglist>)(register Region &amp;dest, register const Rect *r1, const Rect *r1End, register const Rect *r2, const Rect *r2End, register UCoord y1, register UCoord y2)</arglist>
    </member>
    <member kind="typedef">
      <type>void(*</type>
      <name>NonOverlapFunc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a01cfb8fb1d76142b3e6dda36f7d56111</anchor>
      <arglist>)(register Region &amp;dest, register const Rect *r, const Rect *rEnd, register UCoord y1, register UCoord y2)</arglist>
    </member>
    <member kind="typedef">
      <type>TArray&lt; Rect &gt;</type>
      <name>RectangleArray</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a142b899ad309a2cea5e842afad33c872</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>FReadGuardT&lt; FRwLock &gt;</type>
      <name>FReadGuard</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a55c03694e8f66a604d8024bb568cc252</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>FWriteGuardT&lt; FRwLock &gt;</type>
      <name>FWriteGuard</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a76b91d2c3ab69f871c58df19427526a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>InitLevel</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelFirst</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a669724ea6e5eaca89fc8b94ab51a61c4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelBelowStd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a3ff40e43f61cfb4478e6a38ea25c00c8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelStd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a202de6b09e239b07e54c2c85a6df2523</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelAboveStd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a15816862dbc061fb5515fe76a9e94b19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInitLevelLast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a84f2ccb8fa0b2f65416fd33bca428518a32b7b870dd7c75226d8c8e99399d10f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>FSeekMode</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24db</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSeekSet</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24dbad9fe3df36943c836f26fd55f2e800384</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSeekCurrent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24dbaff1a9d5b4238462a49619084e8324b85</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSeekEnd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78e5e10c2df97a6a5a6096069ade24dbaa2d1805ccbf869dc4a610f9571d83d7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>MBCodePage</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_ANSI</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a4bc87ed163042e19a3c8c857f320e601</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_MAC_ROMAN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198aece485d20e1f11025207f5d03331170b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_ANSI_WEL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198ae306671b758491ebea5651afc41faf06</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_MAC_CEE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198afdfb28513dca7897ba46509177f3f295</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_Utf8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a42fe778326afe1a478de66fa0ae88053</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_ShiftJIS</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a800fe314d21309f85659ee3c8ff41fba</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_US_ASCII</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198a68f73e16ffd280be8ea415937c17901e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCP_Default</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a879b9da0475eafb05527d00a3e87e198ab93a845dd7dd03d5e296ffff03a78aa2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>UnicodeNormalization</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormC</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5a5ab93cdbd8bb16cc7261b7d02f656426</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormD</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5a719813623d8e0a706e6ab6cd2a0fb0f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormKC</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5a6bc71341f3a88c030bc7f46992d39c99</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicodeNormKD</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ade9b236510365125beb73ce8c7347fd5ad8daa621694a792a6b4368b2e1caccad</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>FThreadPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLowPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5a557242830eb32b4ce0f4ae1781dcee13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kBelowNormalPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5aa6524724fa22dca5e975d298ca947dc3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNormalPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5a187b8784f46ca737896c5ce69d852ee0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAboveNormalPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5acb0997c29c3ed1a5d4104a0d42145831</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kHighPriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5aee02c07a356b561b0de2b686b62eab58</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kRealtimePriority</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a812f897633141d1e92811c9c5d10a2e5ac2aa2b44836895a62a02a77adfb8226f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicIncrement</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1447efd051f60e8b5ca8b0eac63cf657</anchor>
      <arglist>(volatile int32 &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicDecrement</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad257b30a64ed76acd91513dcf9f40445</anchor>
      <arglist>(volatile int32 &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>FAtomicAdd</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a799093e0dd4b67b24eb541361c22d826</anchor>
      <arglist>(volatile int32 &amp;var, int32 d)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FAtomicCompareAndSwap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aba9c29c332271f636c7136b6457fc801</anchor>
      <arglist>(volatile int32 &amp;var, int32 oldVar, int32 newVar)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FAtomicCompareAndSwap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a066ac9ced0201a19b880421c1e1d820a</anchor>
      <arglist>(volatile void *&amp;var, void *oldVar, void *newVar)</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>alignedMalloc</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0866afd2bc00609bc7949dd71f2d090e</anchor>
      <arglist>(int32 size, int32 alignment=16)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>alignedFree</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a40dd1b19a72841fbbab3c3ab73a93b35</anchor>
      <arglist>(void *buffer)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0dcd9f1c6ef7535727383eb61d29bd80</anchor>
      <arglist>(const FObject *object)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8d57d3b99295e8f84b87e51cf01e9f61</anchor>
      <arglist>(FUnknown *unknown)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FUCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa778c9fbf69ebf5e9373a9fd5599f05b</anchor>
      <arglist>(FObject *object)</arglist>
    </member>
    <member kind="function">
      <type>C *</type>
      <name>FUCast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2d7f6fc1f95cff2a8e80b0f539c191ff</anchor>
      <arglist>(FUnknown *object)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AssignShared</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a859d56e4a26f41f6e300e2326ed4707f</anchor>
      <arglist>(T *&amp;dest, T *newPtr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AssignSharedDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa8252fcff23467a221d6f4ee41140bf0</anchor>
      <arglist>(IDependent *_this, T *&amp;dest, T *newPtr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>AssignSharedDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>afdcaf76ae8554fbcbeb20942947ba17e</anchor>
      <arglist>(IDependent *_this, IPtr&lt; T &gt; &amp;dest, T *newPtr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeReleaseDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae960ca0a477b1a5c9a1c21dcb284d039</anchor>
      <arglist>(IDependent *_this, T *&amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeReleaseDependent</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a3568ca6d87f19ef4a712982beaa7b7be</anchor>
      <arglist>(IDependent *_this, IPtr&lt; T &gt; &amp;dest)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adfd0944abddbf6bf17c4194bde712469</anchor>
      <arglist>(const Point &amp;p1, const Point &amp;p2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5a4e69c52d9dd5bc464f4a9dc81b3205</anchor>
      <arglist>(const Point &amp;p1, const Point &amp;p2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6ea493ebfd7b9d7275da30ea42ea6ae7</anchor>
      <arglist>(const Rect &amp;r1, const Rect &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af1d581514e75e4ec77e2b0825698adde</anchor>
      <arglist>(const Rect &amp;r1, const Rect &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae063f682609badf81ee491be7b154c64</anchor>
      <arglist>(const Rect &amp;r1, const Rect &amp;r2)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MergeRect</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab5ccf32250bacd4eb4ef0c4d2355007b</anchor>
      <arglist>(register TArray&lt; Rect &gt; &amp;destRects, const Rect *&amp;r, register int32 y1, register int32 y2)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a166ebc6677e19253cda1f55ead2b8106</anchor>
      <arglist>(const char8 *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a61e26dc8165fa82a90f930a1f8367a3c</anchor>
      <arglist>(const char16 *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrnatcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8da7606964bc54f792be75edb50d5731</anchor>
      <arglist>(const T *s1, const T *s2, bool caseSensitive=true)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab16cda4272acda12af7fe328eb3abbfa</anchor>
      <arglist>(const char8 *s1, const char8 *s2, bool caseSensitive)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a026eef900ab2e9f3c1390d73992a48a2</anchor>
      <arglist>(const char16 *s1, const char16 *s2, bool caseSensitive)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashString</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab9e1f71a717bf28978e67938cf197360</anchor>
      <arglist>(const char *s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ada25fd2a2681fec14af4507826ffdfe8</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2c3adccbf0361ed1e35dc58f474aa783</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0047a2ab78ce4594023b5691eda91128</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adafb26f233ad745fb7503011697a8d89</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4d79863da188e183ae4150116906ad6b</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1a02a54515930b11df9cb7c05ed0a663</anchor>
      <arglist>(const ConstString &amp;s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af032c74c6993e1abfbd7bccda3fea33d</anchor>
      <arglist>(const String &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac18cc72253d13ec535ba0187d07759af</anchor>
      <arglist>(const String &amp;s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa19edede938efc8875df07e2079cb898</anchor>
      <arglist>(const String &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae356517d1995baa9053ae4cbec848b85</anchor>
      <arglist>(const String &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a86f7c6c4e0f84a11e5583452e809debe</anchor>
      <arglist>(const char8 *s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>String</type>
      <name>operator+</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a484a5c7b2980c3eddde1777f4f8740e2</anchor>
      <arglist>(const char16 *s1, const String &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad5ce23c4f9cca43a9f66ef23d9325159</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>afc04c8ac4717595b641a119f8e1f4c08</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac98deb5a1f36329c44edeee647d46431</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a98082cddf36f42dae42928aab7b7d704</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af65b89110f91b435a658a09cde45ee6b</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aaad28d7939d8454ba62e2ed43e6b6a07</anchor>
      <arglist>(const ConstString &amp;s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>acf5c2d96088a26678de1f7ba2b0610a9</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab4e3d70dc9e542aa4830d9026f49e318</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a296a0841f7c8f2fc3a5708556c720a5a</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a111fe3210982295b10c2b0a6c64f8849</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8e6d100fac4f2e9011a595eb516d21ea</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>acf534ee8bc3f7368a3a21e666eb87e88</anchor>
      <arglist>(const ConstString &amp;s1, const char8 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7e81e3384f1e73b68dba43f8ca561b27</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7784e17f867a990478e8b3a25216f047</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7792b96abbdb52f88644a2d7fdc0635d</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a763dcfcbf62f158517e3265575e09b03</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af532a1fe0c1fa0b787fb1c6fa58048e4</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a294195888b30e4aa51ac89171313dddd</anchor>
      <arglist>(const char8 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7a3ef53c29d18481261d4ad40fbd93d8</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5dac4595f7ec9120e736fc4a72b263a4</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a59823787882c26e6dc2a849a23785b22</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1bfad3a77225793f845ad097c4b694a6</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5998cbea9b1218b35018328826e6a40d</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a34e7201686726b43099edeabc6e64b02</anchor>
      <arglist>(const ConstString &amp;s1, const char16 *s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4a5e176ffe4e3d42b9dbdd5ff6b6a232</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ab43ab059cf7a1b2eee6dcf7db9429f72</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af8868f64b08e62fc4ca89095b748dcb3</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a70fa44d88af75be3d8d5402aa761370c</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a645271d1621265af41557ff516b67961</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a262d596d26d40f41fab24af7162c7020</anchor>
      <arglist>(const char16 *s1, const ConstString &amp;s2)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strnatcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af813b691586a7d0180f9275b88d8ce86</anchor>
      <arglist>(const char *s1, const char *s2, bool caseSensitive=true)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>FThreadSleep</name>
      <anchorfile>group__baseThread.html</anchorfile>
      <anchor>ga898954af0718c9e046380393ccc3457d</anchor>
      <arglist>(int32 milliseconds)</arglist>
    </member>
    <member kind="function">
      <type>IPtr&lt; T &gt;</type>
      <name>newFUnknown</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a29c88637282342c2f52064ea8dc264d4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ITimerCallback *</type>
      <name>newTimerCallback</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2399dea34bada017854bf0391c44c3d9</anchor>
      <arglist>(const Call &amp;call)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DEF_CLASS_IID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a03374ef5cb2e4ca5d36313f4c3dd85e2</anchor>
      <arglist>(IUpdateManager) namespace Update</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeRelease</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af8fe5ae0451e2f5b7ca20ac44615bd39</anchor>
      <arglist>(I *&amp;ptr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeRelease</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4ad3ac400880f6a870d30ff35a26ea1d</anchor>
      <arglist>(IPtr&lt; I &gt; &amp;ptr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>SafeDelete</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a00e2bc527488c121724d164b86d5d8f7</anchor>
      <arglist>(T *&amp;ptr)</arglist>
    </member>
    <member kind="variable">
      <type>struct Steinberg::FObjectIIDInitializer</type>
      <name>gFObjectIidInitializer</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a716e8faa9615ce0d3a3b357275d14868</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::MetaClass</name>
    <filename>classSteinberg_1_1MetaClass.html</filename>
    <member kind="typedef">
      <type>FUnknown *(*</type>
      <name>CreateFunc</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a42fe723d038016ae5ecf46394fdb1517</anchor>
      <arglist>)()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MetaClass</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>ae988a7dafb5ead83edfe4fdd8b0a760b</anchor>
      <arglist>(FClassID className, CreateFunc=0, FIDString cid=0, MetaClass *parent=0, int16 version=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MetaClass</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a312e835fcef8db453406090aadaf3b23</anchor>
      <arglist>(MetaClass *sourceClass, FClassID persistentName)</arglist>
    </member>
    <member kind="function">
      <type>FClassID</type>
      <name>getName</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a7b220ce5778a9e29172b1c55a41d087f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>FClassID</type>
      <name>getPersistentName</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a1a6a5dc0a732f803fe4bea5d1810c715</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const FUID &amp;</type>
      <name>getID</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a3feb9122815c35f1131984edd72cd911</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>MetaClass *</type>
      <name>getParent</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a9ce1f87cf60335fa00f5b45dc7639e76</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int16</type>
      <name>getVersion</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>ab8ad336feb61becff8d8a72a719344ba</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isTypeOf</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>af1df84586307591bcada6bf380d5d252</anchor>
      <arglist>(FClassID)</arglist>
    </member>
    <member kind="function">
      <type>FUnknown *</type>
      <name>createUnknown</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>a952029a12731a3f10d6adda53d892952</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>createObject</name>
      <anchorfile>classSteinberg_1_1MetaClass.html</anchorfile>
      <anchor>aa95a15adb7ff8d700e61349a3ed27361</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ClassFactory</name>
    <filename>classSteinberg_1_1ClassFactory.html</filename>
    <base>Steinberg::FObject</base>
    <member kind="function">
      <type></type>
      <name>ClassFactory</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>a9a0b7dfb619dfaad6aa7c4fde48c141c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ClassFactory</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>a07bc0d4689b6ab6a7fd36aafd9afd75a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>MetaClass *</type>
      <name>getMetaClassByName</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>ad582ca222532806c9a40e1c39ec67222</anchor>
      <arglist>(FIDString className)</arglist>
    </member>
    <member kind="function">
      <type>MetaClass *</type>
      <name>getMetaClassByID</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>a0c7021927783bc0ac473ec5f086ec83f</anchor>
      <arglist>(const TUID classID)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getStorageID</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>ae54402e0e245213f5f269da10b7ecdd3</anchor>
      <arglist>(FUnknown *unknown, IString &amp;result, bool checkForMetaClass=true)</arglist>
    </member>
    <member kind="function">
      <type>FUnknown *</type>
      <name>createObjectByName</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>a02bee71e4b8885b8406d491ee9959119</anchor>
      <arglist>(FClassID className)</arglist>
    </member>
    <member kind="function">
      <type>FUnknown *</type>
      <name>createObjectByID</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>adc478a96a5a29ddbe112c714b0d817ba</anchor>
      <arglist>(const TUID classID)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>createByName</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>a35ec904cf964920a691445e87bcf2b2f</anchor>
      <arglist>(FClassID className)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>OBJ_METHODS</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>ac926e57e542d58307ea5630b45addc63</anchor>
      <arglist>(ClassFactory, FObject) SINGLETON(ClassFactory) void registerMetaClass(MetaClass *mc)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unregisterMetaClass</name>
      <anchorfile>classSteinberg_1_1ClassFactory.html</anchorfile>
      <anchor>a0c9842fe8f1d44e2a4fcf0fcf1ad2cb4</anchor>
      <arglist>(MetaClass *mc)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::BitSet</name>
    <filename>classSteinberg_1_1BitSet.html</filename>
    <member kind="enumeration">
      <name>ReturnTypes</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>ac0c7b3ae2c9e1bac24f95a21b978ad20</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEmptySize</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>ac0c7b3ae2c9e1bac24f95a21b978ad20af95c106a7adbd6ac8c26c85e42e22ce4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kBitNotFound</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>ac0c7b3ae2c9e1bac24f95a21b978ad20ae638423ce98e7c0c39896d664ef48cd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BitSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a49ac9998574ed3ef5c487e15b4a0a613</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BitSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a4a1076c7b9eeb7b92bfaa7436deebeb8</anchor>
      <arglist>(uint32 size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>BitSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a1d436b62dd61e5faee55912b6aad8672</anchor>
      <arglist>(const BitSet &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~BitSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>af2ad9d56d7b2fb2506a3ff4953b24154</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>BitSet &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a2ade772aff853b9ccce5a9d5f3785dc7</anchor>
      <arglist>(const BitSet &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a5f5e04cb3d9b45c7eec2f3afe6a9951c</anchor>
      <arglist>(const BitSet &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>ade05bb869c3dffd446a301be4d25a250</anchor>
      <arglist>(const BitSet &amp;)</arglist>
    </member>
    <member kind="function">
      <type>BitSet &amp;</type>
      <name>operator&amp;=</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>af8a0e27389d9e54e2b7054ae47758e35</anchor>
      <arglist>(const BitSet &amp;toAnd)</arglist>
    </member>
    <member kind="function">
      <type>BitSet &amp;</type>
      <name>operator|=</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a048077d9b2bac0111aefe5a35f233ea0</anchor>
      <arglist>(const BitSet &amp;toOr)</arglist>
    </member>
    <member kind="function">
      <type>BitSet &amp;</type>
      <name>operator^=</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>aed24de8f9fb939ab34d15c4b411f0512</anchor>
      <arglist>(const BitSet &amp;toXOr)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSize</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a076b564923a13c163b182909e6d2c2ef</anchor>
      <arglist>(uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getSize</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a2322b68822fc3a7cbda23787a6b9ed43</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setBit</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a8487d91c80b604e06dc66712bfe25f31</anchor>
      <arglist>(uint32 which)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearBit</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a28fa28999c9d599b6a1cb37867ac5223</anchor>
      <arglist>(uint32 which)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toggleBit</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a70224e48dbcc86378b7c11c6dc614050</anchor>
      <arglist>(uint32 which)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAll</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a82d74f99e5cd27828f015bdb1c334341</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clearAll</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a798729dca95209ecdc609807a653a2bf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getBit</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>ac173a02084559708d9977a2281e62cff</anchor>
      <arglist>(uint32 which) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>countSetBits</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>abf1c205ee57ad3e374ad2a1bc716ed31</anchor>
      <arglist>(int32 toPos=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>getFirstSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a061b7cc8e329ba719d9ca67127dfb3f5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>getFirstNotSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a9ff760948a712c56de94d5652a65f905</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>getLastSet</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a2c04f56ed5b2c1202dcc9ab9a463ad64</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="typedef" protection="protected">
      <type>uint32</type>
      <name>BSChunkType</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a3be9ed21f03bf40395e5bd63c50d7275</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual void</type>
      <name>onChange</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a15877c27c50db627ff997ddf5c88e9c4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>uint32</type>
      <name>getChunkCount</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>aea2c7587f938ce1011b6bc93a492bd98</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>BSChunkType</type>
      <name>getChunk</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>aba533878c6ff69be9ce49831248ba8d9</anchor>
      <arglist>(uint32 n) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>setChunk</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>aa44f36849bf99db4039686444a58ea78</anchor>
      <arglist>(uint32 n, BSChunkType chunk)</arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static const uint32</type>
      <name>kChunkSize</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>abe3a470633ad805d77e5f9072f0ea5ef</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static const uint32</type>
      <name>kChunkByteSize</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a2f24373229f63b6c68b7d1e931457a44</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static const BSChunkType</type>
      <name>kFullChunk</name>
      <anchorfile>classSteinberg_1_1BitSet.html</anchorfile>
      <anchor>a842d989aa1d23391f17811c4e74ffdfc</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IDSet</name>
    <filename>classSteinberg_1_1IDSet.html</filename>
    <base protection="private">Steinberg::BitSet</base>
    <member kind="function">
      <type></type>
      <name>IDSet</name>
      <anchorfile>classSteinberg_1_1IDSet.html</anchorfile>
      <anchor>aca99acabb329090135eb6750f1567076</anchor>
      <arglist>(int32 startOffset=0, int32 growSize=128)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>newID</name>
      <anchorfile>classSteinberg_1_1IDSet.html</anchorfile>
      <anchor>ab1bd843ffde88bc6e540697f6e1c38a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>releaseID</name>
      <anchorfile>classSteinberg_1_1IDSet.html</anchorfile>
      <anchor>ade406caab5a1d67a30e03329575b088d</anchor>
      <arglist>(int32 id)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Buffer</name>
    <filename>classSteinberg_1_1Buffer.html</filename>
    <member kind="enumeration">
      <name>swapSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a24e80486061f2d500092ee60eb3a21a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwap16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a24e80486061f2d500092ee60eb3a21a5a0de688fd6dd63aec086c2004e20cdced</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwap32</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a24e80486061f2d500092ee60eb3a21a5a89f97cdfea8dbe86ba7b2f6a8e1f73d3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSwap64</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a24e80486061f2d500092ee60eb3a21a5a6df3cbd095d4dacb56f3fa2095382edc</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a47587d18a394fb4b9508c61e3d5f0260</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>abfbc60030ca169331f33b68b052677c7</anchor>
      <arglist>(const void *b, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a7d37d8ae2357c047daeba8de0cbe7425</anchor>
      <arglist>(uint32 size, uint8 initVal)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a9ceade440770339ca2768ff71ad8927f</anchor>
      <arglist>(uint32 size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ac0d4f265450e68c7cd8e4df9a6a7150c</anchor>
      <arglist>(const Buffer &amp;buff)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ac72b418d40e29411ac044a49a20be750</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>af108b63e6b6c4d37ad7ca8aa38f91722</anchor>
      <arglist>(const Buffer &amp;buff)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a1c37122bf2c72e4d79858f3724cbce84</anchor>
      <arglist>(const Buffer &amp;buff) const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a2322b68822fc3a7cbda23787a6b9ed43</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5db5816376f3e60cbe277ed6f714f5b4</anchor>
      <arglist>(uint32 newSize)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>grow</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a61fc1961d3b66e3bdb23cc8da86872d4</anchor>
      <arglist>(uint32 memSize)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setMaxSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5316d719cfefa42f2e4e29ecfadea185</anchor>
      <arglist>(uint32 memSize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillup</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ab4c01847d01bd569b8f00a95dd852968</anchor>
      <arglist>(uint8 initVal=0)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getFillSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a10c0d01aaeb0cc20519fb59289d44483</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setFillSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aeb44fb76e1d019848f6e3fae79232254</anchor>
      <arglist>(uint32 c)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>flush</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>adac116554b543b7c4228c018a85882f5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>truncateToFillSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a1a3b64cb526cc540ab6e7e533ab07efd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isFull</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a7ffe8a6212a0eb3fc7bbc8e9bc51dfcd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getFree</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>acca53d5476057ec4aab5cefc33710760</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>shiftStart</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a79b7870538d70d8e72427d8cb1504917</anchor>
      <arglist>(int32 amount)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>shiftAt</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ac3d0af936a5a4f5f9aa26b378e9f3ff5</anchor>
      <arglist>(uint32 position, int32 amount)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>move</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a0a728693e22178550b0bda95b139e684</anchor>
      <arglist>(int32 amount, uint8 initVal=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>copy</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a9ee54180cb05034c130c3328c2617c85</anchor>
      <arglist>(uint32 from, uint32 to, uint32 bytes)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>get</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad9f85b2a73d3c78663a595b3790a268c</anchor>
      <arglist>(void *b, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDelta</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a1331a84eeb64cb0ab5a92826a3f61f7a</anchor>
      <arglist>(uint32 d)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a9cf73b2a1331acbbe6b1be8539e4236f</anchor>
      <arglist>(uint8)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5afd335e2217f540340d3992b77976d0</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a244c4ccf1bce32c9d8c58565e99ea7a7</anchor>
      <arglist>(char c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad31fbc079d7d6d528336744b24c5329e</anchor>
      <arglist>(const void *, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a1ddf189b20aeaf992c269b92f2178924</anchor>
      <arglist>(void *, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ab3ff373695d7d49be1a96c7991251708</anchor>
      <arglist>(uint8 *, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>afa5babad6752cc4ab2f3a537cff90143</anchor>
      <arglist>(char8 *, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>abd2c137bca66738bab879a130915f350</anchor>
      <arglist>(const uint8 *, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad11514107292a2033f0ac67ceb3d06ed</anchor>
      <arglist>(const char8 *, uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>put</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a92aee5c5993e158144843f5adea15213</anchor>
      <arglist>(const String &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ac51e247714f6833a9a56ae181cf9bc23</anchor>
      <arglist>(uint8 value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aa7103c38867a7a83a2de3f8d32a0017c</anchor>
      <arglist>(const char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a474a14913e4b4c828cd03526c8424a9e</anchor>
      <arglist>(char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>af3a74022bfba9a0d1d72edd374e3aa64</anchor>
      <arglist>(char c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ab75e024e20c6803e223d1901081e8ad7</anchor>
      <arglist>(const char8 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a0c371b54df60e3f5f952a344c99ae8e9</anchor>
      <arglist>(const char16 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad6b171f5e02e782a693c78058242ac12</anchor>
      <arglist>(char8 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ada178b76cfdca76e3f5f2e72e0d75e80</anchor>
      <arglist>(unsigned char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aea650e455e820edeeefcca21e3e0dc30</anchor>
      <arglist>(const unsigned char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a00b9566f11157ea3cdd2a60763106813</anchor>
      <arglist>(char8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a432a94deb1ef653480c234596372d29a</anchor>
      <arglist>(unsigned char c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a869841b0e5c51a1fad8b6d7b8255a023</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>appendString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a0d0c8edd6a4712962cb5a114fb70a754</anchor>
      <arglist>(char16 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5a6c749087e39a155dbfa68142e62231</anchor>
      <arglist>(const char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a175a4813b165d61a9dd7362d242f67b5</anchor>
      <arglist>(char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a0a300c804244e59c525ea96c0aee80e1</anchor>
      <arglist>(char c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a32a98866cea235d36c99b7ab68fe1368</anchor>
      <arglist>(const char8 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a0b084cf73146b68fd85d411cafe02465</anchor>
      <arglist>(const char16 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5a30b522f8105c19e3748badecc5c1e0</anchor>
      <arglist>(char8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5e3b2d2909e45c472d86390a1ced9337</anchor>
      <arglist>(unsigned char c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a8ae0a64a6ea715f157f6612d339253a7</anchor>
      <arglist>(char8 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad7a76bee549fe98d9de67a5cf40e43b9</anchor>
      <arglist>(unsigned char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a25229e8dc072c6fd12fe2f842f25a920</anchor>
      <arglist>(const unsigned char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a6b4fe835e9a14bb7f1f2e67ca3e6ba7b</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prependString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a4daa5336dd993fca07ba45b6dae92a6e</anchor>
      <arglist>(char16 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ae2b6ce9c093e49b39fceab9f8f546874</anchor>
      <arglist>(const char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aca9260d196dd4ec64a43fb143b5f1023</anchor>
      <arglist>(char c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a0e6e550f673e57e20d13687c4899e7e4</anchor>
      <arglist>(const char16 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ac4a1150f070f27758448a37b44cd4906</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>af720d2e7b68280f0021a2d0bb60e0bcb</anchor>
      <arglist>(const char *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a242d18cd2364dd753e6759639f5f02fb</anchor>
      <arglist>(const char16 *s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad4f0dac69471a52927cf9a2f0e75b438</anchor>
      <arglist>(char8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a8782a69f0de3929147f537cfc25d3873</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>endString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a50de18138bdd773dfc112c841c8597a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>endString8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a4ddfa41c4e0f46580c84664c30f46fca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>endString16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad487b6b6fedb84790a3820aa27b407ad</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>makeHexString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a22c9694174100cb1feff3900a2b826cf</anchor>
      <arglist>(String &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>fromHexString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a47d47e5af0c48f358ca67d09148c572c</anchor>
      <arglist>(const char8 *string)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator void *</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a85e97bb6a6c26e0e6b56592ce809427b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>str</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aa64fafcd623e080b547d8991bb530065</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>str8</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a346fb4a8d04b8868c9ed415dffb45ed6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>str16</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a7e192a4079b1e532d13b72e2bd20e6d9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int8 *</type>
      <name>int8Ptr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>abf0e48e344b0cc8e2e719b12a29e194e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint8 *</type>
      <name>uint8Ptr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>abbb913fe62f0afb32ddbbabae2d4907c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int16 *</type>
      <name>int16Ptr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a3948221f29d91cb858a4cceddc117390</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint16 *</type>
      <name>uint16Ptr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a991504f8d15bb8d0020fceaed1551a47</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32 *</type>
      <name>int32Ptr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a571fa3f4781d2cdf4b5175b72a352598</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint32 *</type>
      <name>uint32Ptr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aaf304ef4cd4166e06626c366cd95a1c4</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>float *</type>
      <name>floatPtr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a2075409561630bbbb0094655e86e473e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double *</type>
      <name>doublePtr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a40c9f71c904bbae8bc7c48c8078a3c6a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>wcharPtr</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ad32ab4b9a15354044fccb6927820f24e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int8 *</type>
      <name>operator+</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ab1f9c3c721c22713ec76cdb702c25a85</anchor>
      <arglist>(uint32 i)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>operator!</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>ae65e18c2973e69dc67b518e399d5f43e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>swap</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a78970931ab3488ad189d421140692228</anchor>
      <arglist>(int16 swapSize)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>take</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>acfa5f874d6e079d5dd3ff1a19746cb03</anchor>
      <arglist>(Buffer &amp;from)</arglist>
    </member>
    <member kind="function">
      <type>int8 *</type>
      <name>pass</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>afa32c58b633cbb67448023400d78b11d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>toWideString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a74cec25c301d7fc9037c2831909325aa</anchor>
      <arglist>(int32 sourceCodePage)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>toMultibyteString</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>abc435345b9e229e7dbfc09c51854890d</anchor>
      <arglist>(int32 destCodePage)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>swap</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a8499ff64797ee5f037de8529841fdee2</anchor>
      <arglist>(void *buffer, uint32 bufferSize, int16 swapSize)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int8 *</type>
      <name>buffer</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>afef95cf6c683b6331e76f83606c53d55</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint32</type>
      <name>memSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>aafd1ae1da95950e08d65aa4025690aff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint32</type>
      <name>fillSize</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>abf40bac133b6bd7a1cb243fe235f0f96</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint32</type>
      <name>delta</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a51785d72370a4b435e5863a25705f6c7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static const uint32</type>
      <name>defaultDelta</name>
      <anchorfile>classSteinberg_1_1Buffer.html</anchorfile>
      <anchor>a5ddbcd843e127d9a3b72dd34642eccb4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FDeleter</name>
    <filename>structSteinberg_1_1FDeleter.html</filename>
    <templarg>T</templarg>
    <member kind="function">
      <type></type>
      <name>FDeleter</name>
      <anchorfile>structSteinberg_1_1FDeleter.html</anchorfile>
      <anchor>a8d904032d15002f7232451f551053c29</anchor>
      <arglist>(T *_toDelete)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FDeleter</name>
      <anchorfile>structSteinberg_1_1FDeleter.html</anchorfile>
      <anchor>af7025fb8b71b21b2b945a99a326aae46</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>T *</type>
      <name>toDelete</name>
      <anchorfile>structSteinberg_1_1FDeleter.html</anchorfile>
      <anchor>a96acfe8f38200ad7c85bff6c9032fc95</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FArrayDeleter</name>
    <filename>structSteinberg_1_1FArrayDeleter.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FArrayDeleter</name>
      <anchorfile>structSteinberg_1_1FArrayDeleter.html</anchorfile>
      <anchor>a43cb3155da3a95365940b11cc42cbba8</anchor>
      <arglist>(T *_arrayToDelete)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FArrayDeleter</name>
      <anchorfile>structSteinberg_1_1FArrayDeleter.html</anchorfile>
      <anchor>a34f230dc8f23cd2085bcc7ccf23f7b3f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>T *</type>
      <name>arrayToDelete</name>
      <anchorfile>structSteinberg_1_1FArrayDeleter.html</anchorfile>
      <anchor>a0af642d63ab48f6c3075a40cba9935e5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FPtrNuller</name>
    <filename>structSteinberg_1_1FPtrNuller.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FPtrNuller</name>
      <anchorfile>structSteinberg_1_1FPtrNuller.html</anchorfile>
      <anchor>a965668bcd07a18ad817d591cdfe2c3d5</anchor>
      <arglist>(T *&amp;_toNull)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FPtrNuller</name>
      <anchorfile>structSteinberg_1_1FPtrNuller.html</anchorfile>
      <anchor>a31801922b2fb31bd9d56ef48f1abe8da</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>T *&amp;</type>
      <name>toNull</name>
      <anchorfile>structSteinberg_1_1FPtrNuller.html</anchorfile>
      <anchor>a791d6bee42c812d34ecfcac333ab33c0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FNuller</name>
    <filename>structSteinberg_1_1FNuller.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FNuller</name>
      <anchorfile>structSteinberg_1_1FNuller.html</anchorfile>
      <anchor>a9fd1a507ebc6f2535cd3130e5bf7cb04</anchor>
      <arglist>(T &amp;_toNull)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FNuller</name>
      <anchorfile>structSteinberg_1_1FNuller.html</anchorfile>
      <anchor>ab9191536eaf9f59f8fe55bad97cf001d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>T &amp;</type>
      <name>toNull</name>
      <anchorfile>structSteinberg_1_1FNuller.html</anchorfile>
      <anchor>ab041bd5c32608007e7a8f433b9d9e861</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FBooleanSetter</name>
    <filename>structSteinberg_1_1FBooleanSetter.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FBooleanSetter</name>
      <anchorfile>structSteinberg_1_1FBooleanSetter.html</anchorfile>
      <anchor>a184b4f0acbd0515534b0a8c161f9ee38</anchor>
      <arglist>(T &amp;_toSet)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FBooleanSetter</name>
      <anchorfile>structSteinberg_1_1FBooleanSetter.html</anchorfile>
      <anchor>ab457975e1c24aeed9865251280280ca2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>T &amp;</type>
      <name>toSet</name>
      <anchorfile>structSteinberg_1_1FBooleanSetter.html</anchorfile>
      <anchor>ad3d8bf7a93c1977f4c20dd6f66bd1f7c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FConditionalBoolSetter</name>
    <filename>structSteinberg_1_1FConditionalBoolSetter.html</filename>
    <member kind="function">
      <type></type>
      <name>FConditionalBoolSetter</name>
      <anchorfile>structSteinberg_1_1FConditionalBoolSetter.html</anchorfile>
      <anchor>a46c5ce3d2063724dc2cac0a21fef7529</anchor>
      <arglist>(bool &amp;_toSet, bool condition)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FConditionalBoolSetter</name>
      <anchorfile>structSteinberg_1_1FConditionalBoolSetter.html</anchorfile>
      <anchor>a619a26a5580c9ea4043a887063b8b6b7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>bool &amp;</type>
      <name>toSet</name>
      <anchorfile>structSteinberg_1_1FConditionalBoolSetter.html</anchorfile>
      <anchor>a9ace53f30ba43c34f8512bf5e92d2097</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FCloser</name>
    <filename>structSteinberg_1_1FCloser.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FCloser</name>
      <anchorfile>structSteinberg_1_1FCloser.html</anchorfile>
      <anchor>a46a490c0e086deff18fe1a1d484b2910</anchor>
      <arglist>(T *_obj)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FCloser</name>
      <anchorfile>structSteinberg_1_1FCloser.html</anchorfile>
      <anchor>a2187198e46898e7a63b0db52f9e2bf03</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>T *</type>
      <name>obj</name>
      <anchorfile>structSteinberg_1_1FCloser.html</anchorfile>
      <anchor>a370d397cf44fe716a1016d49f41defe1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FMallocReleaser</name>
    <filename>classSteinberg_1_1FMallocReleaser.html</filename>
    <member kind="function">
      <type></type>
      <name>FMallocReleaser</name>
      <anchorfile>classSteinberg_1_1FMallocReleaser.html</anchorfile>
      <anchor>a005dcedf7047776009c4437b8219a407</anchor>
      <arglist>(void *_data)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FMallocReleaser</name>
      <anchorfile>classSteinberg_1_1FMallocReleaser.html</anchorfile>
      <anchor>aa6a5aeac7205ddffc9a5d5515479f3e7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>void *</type>
      <name>data</name>
      <anchorfile>classSteinberg_1_1FMallocReleaser.html</anchorfile>
      <anchor>a735984d41155bc1032e09bece8f8d66d</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FSortablePtr</name>
    <filename>classSteinberg_1_1FSortablePtr.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FSortablePtr</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>a585b8d8c4c20b7099f7e5b57c96c1247</anchor>
      <arglist>(I *_ptr, bool addRef=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FSortablePtr</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>a786f12dc33c6bfb939c1588e9fcc3975</anchor>
      <arglist>(const FSortablePtr &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FSortablePtr</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>a266ad48ab71925d0d5f06dbc25711f1a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FSortablePtr</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>ad5940eee1402de6e0cae87341dd926e8</anchor>
      <arglist>(const T2 &amp;t2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>a0e1a30d83545af6c33a677b86eac25bc</anchor>
      <arglist>(const FSortablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>a71e7c8c7947e9e440e3b140f761a2e7e</anchor>
      <arglist>(const FSortablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>aa25b190bbc83003c9e0f82771a764239</anchor>
      <arglist>(const FSortablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>a5efca77ecf8eb01a84339dae89000f0a</anchor>
      <arglist>(const FSortablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>ae6ac965f58bd1f85d9335cf9a87f59d8</anchor>
      <arglist>(const FSortablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classSteinberg_1_1FSortablePtr.html</anchorfile>
      <anchor>acbcc38dfe9c2296063496c20a1e59d95</anchor>
      <arglist>(const FSortablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FComparablePtr</name>
    <filename>classSteinberg_1_1FComparablePtr.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FComparablePtr</name>
      <anchorfile>classSteinberg_1_1FComparablePtr.html</anchorfile>
      <anchor>ab54e5a4928fc27661cde779075317a56</anchor>
      <arglist>(I *_ptr, bool addRef=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FComparablePtr</name>
      <anchorfile>classSteinberg_1_1FComparablePtr.html</anchorfile>
      <anchor>a15fc5819f350476b097e7662efc8b2fc</anchor>
      <arglist>(const FComparablePtr &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FComparablePtr</name>
      <anchorfile>classSteinberg_1_1FComparablePtr.html</anchorfile>
      <anchor>ac5d28c8aecf1b563627f9b61f6f06c2d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FComparablePtr</name>
      <anchorfile>classSteinberg_1_1FComparablePtr.html</anchorfile>
      <anchor>abd0e8f17df8eb85dcff1ca9622ffa6c2</anchor>
      <arglist>(const T2 &amp;t2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1FComparablePtr.html</anchorfile>
      <anchor>a6c4891e0bd91ac116730a0d795222549</anchor>
      <arglist>(const FComparablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1FComparablePtr.html</anchorfile>
      <anchor>a5e0dc11618b9d72fe096f8739a39fb37</anchor>
      <arglist>(const FComparablePtr&lt; I &gt; &amp;other) const </arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::TSorterFunc</name>
    <filename>structSteinberg_1_1TSorterFunc.html</filename>
    <templarg></templarg>
    <member kind="typedef">
      <type>const T &amp;</type>
      <name>ConstTRef</name>
      <anchorfile>structSteinberg_1_1TSorterFunc.html</anchorfile>
      <anchor>a9eae3fff1d2fbf9f7008f481f0d139d6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32(*</type>
      <name>TCompareRefFunc</name>
      <anchorfile>structSteinberg_1_1TSorterFunc.html</anchorfile>
      <anchor>a35b6943ac287945715d9c3a5add95785</anchor>
      <arglist>)(ConstTRef, ConstTRef)</arglist>
    </member>
    <member kind="typedef">
      <type>T *</type>
      <name>TPtr</name>
      <anchorfile>structSteinberg_1_1TSorterFunc.html</anchorfile>
      <anchor>a5c9c750f096775ff21fdf1bcdc42bb6a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32(*</type>
      <name>TComparePtrFunc</name>
      <anchorfile>structSteinberg_1_1TSorterFunc.html</anchorfile>
      <anchor>aa44072117a347707cccd9969be4909cb</anchor>
      <arglist>)(TPtr, TPtr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TSortablePtr</name>
    <filename>classSteinberg_1_1TSortablePtr.html</filename>
    <templarg></templarg>
    <templarg>CompareFunc</templarg>
    <member kind="typedef">
      <type>const TSortablePtr&lt; T, CompareFunc &gt;</type>
      <name>ConstRef</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a049df44b78260521ac6865a93fad6d65</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TSortablePtr</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>aadaf32ac1b864fba8e318af87c86b397</anchor>
      <arglist>(T *d=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TSortablePtr</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a6ca8f5885ad4f5d9789da2d7f3d48b02</anchor>
      <arglist>(const TSortablePtr &amp;s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>ada84fa9cc7613a66dfe87b54d11b7171</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>abfe118bdbd7e45f5a6d65b86ec76828b</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a9f37b23ed3e2f9cd4e8ef12cdedabfda</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>abeca573e2800cfa9982dc7b5519e7d24</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a7300bccd962c483d7461b1c76ba293af</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>ad129df2d7da04bf8ebd0b1fcaefa51da</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator T *</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a826c82b72ca2d624342ce5c06405af8d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>operator-&gt;</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>ac0ddd007dfcfef3121f74d0665dfd0cd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const TSortablePtr &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a320aa09553a88f0eb5fee9a342b7986b</anchor>
      <arglist>(T *_ptr)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>T *</type>
      <name>ptr</name>
      <anchorfile>classSteinberg_1_1TSortablePtr.html</anchorfile>
      <anchor>a4e0fab5bba27ff507e909503f0770e58</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ISortablePtr</name>
    <filename>classSteinberg_1_1ISortablePtr.html</filename>
    <templarg></templarg>
    <templarg>CompareFunc</templarg>
    <member kind="typedef">
      <type>const ISortablePtr&lt; T, CompareFunc &gt;</type>
      <name>ConstRef</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>a0567f2d3682da3a29428e448cab00a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ISortablePtr</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>a0a603967ce0ea24cc3c558d44fd3fff5</anchor>
      <arglist>(T *_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ISortablePtr</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>ab64da6bc6a268926740ce9f9d50f9480</anchor>
      <arglist>(const ISortablePtr &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ISortablePtr</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>a192167f17c4be24dbe4adab9ba8c92c6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ISortablePtr</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>aa084a097893607ab255c97b18293ab31</anchor>
      <arglist>(const T2 &amp;t2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>ada84fa9cc7613a66dfe87b54d11b7171</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>abfe118bdbd7e45f5a6d65b86ec76828b</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>a9f37b23ed3e2f9cd4e8ef12cdedabfda</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>abeca573e2800cfa9982dc7b5519e7d24</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>a7300bccd962c483d7461b1c76ba293af</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classSteinberg_1_1ISortablePtr.html</anchorfile>
      <anchor>ad129df2d7da04bf8ebd0b1fcaefa51da</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TSortable</name>
    <filename>classSteinberg_1_1TSortable.html</filename>
    <templarg></templarg>
    <templarg>CompareFunc</templarg>
    <member kind="typedef">
      <type>const TSortable&lt; T, CompareFunc &gt;</type>
      <name>ConstRef</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>a6e442bddd923512e7ea1ae094e2f8be0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TSortable</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>a80fbc0ec57ceaf7dd82b8305e1d335eb</anchor>
      <arglist>(const T &amp;d)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TSortable</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>a5cdd840245bf6098c9f23ca072e09c91</anchor>
      <arglist>(const TSortable &amp;s)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>ada84fa9cc7613a66dfe87b54d11b7171</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>abfe118bdbd7e45f5a6d65b86ec76828b</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>a9f37b23ed3e2f9cd4e8ef12cdedabfda</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>abeca573e2800cfa9982dc7b5519e7d24</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>a7300bccd962c483d7461b1c76ba293af</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>ad129df2d7da04bf8ebd0b1fcaefa51da</anchor>
      <arglist>(ConstRef &amp;other) const </arglist>
    </member>
    <member kind="variable">
      <type>T</type>
      <name>data</name>
      <anchorfile>classSteinberg_1_1TSortable.html</anchorfile>
      <anchor>aa3ff051a47d9e18487e7b819852521c5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FCpuInfo</name>
    <filename>classSteinberg_1_1FCpuInfo.html</filename>
    <member kind="function">
      <type></type>
      <name>FCpuInfo</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a795542dd25e1964cb4de85de792d4efc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FCpuInfo</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>affa83dd7ea0ac600f5cefd6849b8ccab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countLogical</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a7704f3ae57456365f32597fabe1d7921</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countAvailable</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a219a1ddae61dcad28dc63d22cb67c2bf</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLogicalAvailable</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a3b2439e882496c06bb11eede8124adb7</anchor>
      <arglist>(int32 index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>initialize</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a25a40b6614565f755233080a384c35f1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>numLogical</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a750712ad6f9413691de370991263f8ce</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>numAvailable</name>
      <anchorfile>classSteinberg_1_1FCpuInfo.html</anchorfile>
      <anchor>a700fe0e1bfcbd435b71d36df3722d5c1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FCriticalPerformanceEnabler</name>
    <filename>classSteinberg_1_1FCriticalPerformanceEnabler.html</filename>
    <member kind="function">
      <type>void *</type>
      <name>useCriticalPerformanceMode</name>
      <anchorfile>classSteinberg_1_1FCriticalPerformanceEnabler.html</anchorfile>
      <anchor>aa789742d8a7dcf77b3831aafc7312999</anchor>
      <arglist>(const Performance::Mode &amp;mode, uint64 timeConstraintNanoSeconds, void *handle)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isCriticalPerformanceModeSupported</name>
      <anchorfile>classSteinberg_1_1FCriticalPerformanceEnabler.html</anchorfile>
      <anchor>ac0eb0f3760ffb3eeb654c82dfa8bdfe1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static FCriticalPerformanceEnabler &amp;</type>
      <name>getInstance</name>
      <anchorfile>classSteinberg_1_1FCriticalPerformanceEnabler.html</anchorfile>
      <anchor>aa6944643b16c3d645e3d89c5334a7598</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>FCriticalPerformanceEnabler</name>
      <anchorfile>classSteinberg_1_1FCriticalPerformanceEnabler.html</anchorfile>
      <anchor>ac9aa81f0f0068731dd335db904a4ae14</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>~FCriticalPerformanceEnabler</name>
      <anchorfile>classSteinberg_1_1FCriticalPerformanceEnabler.html</anchorfile>
      <anchor>a16041696aaaef999a14ee9218e2e2eee</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FDynLibrary</name>
    <filename>classSteinberg_1_1FDynLibrary.html</filename>
    <base>Steinberg::FObject</base>
    <member kind="function">
      <type></type>
      <name>FDynLibrary</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a0d07def5c50009216865b5d442d189ee</anchor>
      <arglist>(const char *name=0, bool addExtension=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FDynLibrary</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a316c1ee139e497b2bbb0978aae56814d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>init</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a8f36f17c29d5a7cc5f29677a6093ac5f</anchor>
      <arglist>(const char *name, bool addExtension=true)</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>getProcAddress</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a8060fef6fd902c5aeda63d7d1898e2ff</anchor>
      <arglist>(const char *name)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLoaded</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a7ffa9fcfaa7e93495a34c760b8270731</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>unload</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a506a572d1bf8ada0f9a767c00e580f53</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>getPlatformInstance</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a51db49946dc76430c7cc9dadd047caea</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>OBJ_METHODS(FDynLibrary, FObject) protected void *</type>
      <name>instance</name>
      <anchorfile>classSteinberg_1_1FDynLibrary.html</anchorfile>
      <anchor>a65d5dd0c24f120a3b2c0b6d2e2038d58</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::OneTimeProcedure</name>
    <filename>classSteinberg_1_1OneTimeProcedure.html</filename>
    <member kind="function">
      <type></type>
      <name>OneTimeProcedure</name>
      <anchorfile>classSteinberg_1_1OneTimeProcedure.html</anchorfile>
      <anchor>a474526396ff8c0958353c515033267a1</anchor>
      <arglist>(bool isInit, InitTermFunc f=0, FIDString name=0, uint32 level=kInitLevelStd)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>initialize</name>
      <anchorfile>classSteinberg_1_1OneTimeProcedure.html</anchorfile>
      <anchor>aa5a2862ee91fb3c21b1124279630e59c</anchor>
      <arglist>(uint32 untilLevel=kInitLevelLast)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>terminate</name>
      <anchorfile>classSteinberg_1_1OneTimeProcedure.html</anchorfile>
      <anchor>ab78db397b67d1ccfc887c0e11218f94d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>cancel</name>
      <anchorfile>classSteinberg_1_1OneTimeProcedure.html</anchorfile>
      <anchor>a02d5fa6b14e221f3012a794b905be166</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FMemoryPool</name>
    <filename>classSteinberg_1_1FMemoryPool.html</filename>
    <member kind="function">
      <type></type>
      <name>FMemoryPool</name>
      <anchorfile>classSteinberg_1_1FMemoryPool.html</anchorfile>
      <anchor>a0f14f1a102ceb4395c1e73a804b9cb61</anchor>
      <arglist>(int32 maxElements, int32 elementSize)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FMemoryPool</name>
      <anchorfile>classSteinberg_1_1FMemoryPool.html</anchorfile>
      <anchor>ac7fffa6f37ef7a232fd2575528478869</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>newElement</name>
      <anchorfile>classSteinberg_1_1FMemoryPool.html</anchorfile>
      <anchor>a91dcc759c7c6d8d98c34424a235ccddf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteElement</name>
      <anchorfile>classSteinberg_1_1FMemoryPool.html</anchorfile>
      <anchor>a38a206b5238d6ec9495ae628c17582d9</anchor>
      <arglist>(void *el)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FMemoryBlockPool</name>
    <filename>classSteinberg_1_1FMemoryBlockPool.html</filename>
    <member kind="function">
      <type></type>
      <name>FMemoryBlockPool</name>
      <anchorfile>classSteinberg_1_1FMemoryBlockPool.html</anchorfile>
      <anchor>a35899d74a4ba7918942c24ee7dc9d6fa</anchor>
      <arglist>(uint32 delta, uint32 elementSize)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FMemoryBlockPool</name>
      <anchorfile>classSteinberg_1_1FMemoryBlockPool.html</anchorfile>
      <anchor>a16f47d04a63c2a8312d3cd557d6afab0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>newElement</name>
      <anchorfile>classSteinberg_1_1FMemoryBlockPool.html</anchorfile>
      <anchor>a91dcc759c7c6d8d98c34424a235ccddf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteElement</name>
      <anchorfile>classSteinberg_1_1FMemoryBlockPool.html</anchorfile>
      <anchor>a38a206b5238d6ec9495ae628c17582d9</anchor>
      <arglist>(void *el)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FBlockAllocator</name>
    <filename>classSteinberg_1_1FBlockAllocator.html</filename>
    <member kind="function">
      <type></type>
      <name>FBlockAllocator</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a2663dce42f9cb104b2df23a7a6bbd83c</anchor>
      <arglist>(uint32 blockSize)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FBlockAllocator</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a06991fae6958b93df9141eb0377f4c83</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>allocate</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a17f1344f4411c3a6e56322a8c916eb2c</anchor>
      <arglist>(uint32 size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>free</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a9f850d0608418aea291e4c0fdab93826</anchor>
      <arglist>(void *p)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TArray&lt; Block &gt;</type>
      <name>blocks</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a67e573fbffaf77eab64805d69dc36aa6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint32</type>
      <name>blockSize</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a46e19d5fda11ba7882b319a8bf47cf8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>FLock</type>
      <name>lock</name>
      <anchorfile>classSteinberg_1_1FBlockAllocator.html</anchorfile>
      <anchor>a73d04912f0af10195de965a59121f822</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FObjectPool</name>
    <filename>classSteinberg_1_1FObjectPool.html</filename>
    <member kind="function">
      <type></type>
      <name>FObjectPool</name>
      <anchorfile>classSteinberg_1_1FObjectPool.html</anchorfile>
      <anchor>a3030210414f478482c4969066bb25caf</anchor>
      <arglist>(uint16 elementSize)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FObjectPool</name>
      <anchorfile>classSteinberg_1_1FObjectPool.html</anchorfile>
      <anchor>a1f6a1325ac012601ba3e3254ce530f43</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>newElement</name>
      <anchorfile>classSteinberg_1_1FObjectPool.html</anchorfile>
      <anchor>a91dcc759c7c6d8d98c34424a235ccddf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>deleteElement</name>
      <anchorfile>classSteinberg_1_1FObjectPool.html</anchorfile>
      <anchor>a38a206b5238d6ec9495ae628c17582d9</anchor>
      <arglist>(void *el)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FObject</name>
    <filename>classSteinberg_1_1FObject.html</filename>
    <member kind="function">
      <type></type>
      <name>FObject</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>ab7341803014915b228a4b265371d951a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FObject</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a0df169f35093cd89cf30109783cc900b</anchor>
      <arglist>(const FObject &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~FObject</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a01c1d9f71d1af78d2576bb56ecab58d2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>FObject &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>af6c944b30efba40e7bbd2ab51df630b5</anchor>
      <arglist>(const FObject &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual FClassID</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a61cdbaf28157389877062a96a85eeb88</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a6f9af69d8deb84ca7c9f3dcd5a8c9e70</anchor>
      <arglist>(FClassID s) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isTypeOf</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a37fd18f3794dac0b78ae51253e2d4c25</anchor>
      <arglist>(FClassID s, bool=true) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getRefCount</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a127b5517d355d7870c5bc96d52ef9ef0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>FUnknown *</type>
      <name>unknownCast</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a802669246b5bbc85558f472a9c179af0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>queryInterface</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>ab44df242c5d49b1d0efc5ac673380592</anchor>
      <arglist>(const TUID _iid, void **obj)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual uint32</type>
      <name>addRef</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>af5147c9d251c3a3609bfcbeb3629ec53</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual uint32</type>
      <name>release</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a0055a153bf18130e4534a5427b2be876</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>update</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a5ec7f203cbe494d37da08af5c53d7e1d</anchor>
      <arglist>(FUnknown *, int32)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>addDependent</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>aad64a1f592d31c920bc72505ab860576</anchor>
      <arglist>(IDependent *dep)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeDependent</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a4a343976011506b85607300a4bd97832</anchor>
      <arglist>(IDependent *dep)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>changed</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a72f44c7bf8ec3cab12b95dde13542194</anchor>
      <arglist>(int32 msg=kChanged)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>deferUpdate</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>ad0cb02215c1c6e44b53f177e7844a9f5</anchor>
      <arglist>(int32 msg=kChanged)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>updateDone</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a0be193466912191a8ebbd75354edd935</anchor>
      <arglist>(int32)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEqualInstance</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>aa719bd1d2cd364ea5f3eea2d465f958a</anchor>
      <arglist>(IDependent *d)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static FClassID</type>
      <name>getFClassID</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a61fe4989547b521dfcac968665c376d9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setUpdateHandler</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>abf312648bf542a9d35fd34e1564b07cb</anchor>
      <arglist>(IUpdateHandler *handler)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static IUpdateHandler *</type>
      <name>getUpdateHandler</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>ae2039f0b388fde926f5adeba0111e3d1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>classIDsEqual</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>af59fc037df86c95566a2f9874be552a4</anchor>
      <arglist>(FClassID ci1, FClassID ci2)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static FObject *</type>
      <name>unknownToObject</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>a0a25d706b3e3dabc9e4c0d026f925d73</anchor>
      <arglist>(FUnknown *unknown)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>refCount</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>abc6aaa0595fa788544c4b18e9bf93850</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static IUpdateHandler *</type>
      <name>gUpdateHandler</name>
      <anchorfile>classSteinberg_1_1FObject.html</anchorfile>
      <anchor>acee1b675f92ac47a457fc7692dfd3a67</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Point</name>
    <filename>classSteinberg_1_1Point.html</filename>
    <member kind="function">
      <type></type>
      <name>Point</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a832736592702d81cff7d2f204a3be5bd</anchor>
      <arglist>(UCoord h=0, UCoord v=0)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>inside</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a04924c7d3e681732c4898aaab653c1f0</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>distance</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ab3844d024c5d669d868641489b9d881d</anchor>
      <arglist>(const Point &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>angle</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ae35ffb9404ea599a4869e263bb95ed1f</anchor>
      <arglist>(const Point &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>length</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ad207cb443e371f73f07e874c504f60c1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>projection</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a5109b9a8d7561873331a69a6723bb64c</anchor>
      <arglist>(const Point &amp;other) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isLocated</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a2d82f3bf094da1b373f323710787525b</anchor>
      <arglist>(Direction dir, const Point &amp;from)</arglist>
    </member>
    <member kind="function">
      <type>UCoord</type>
      <name>getH</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ab9563948434e337ee7f4535f447bc014</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>UCoord</type>
      <name>getV</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ae69fed0f48e87d71c3c9427a435cea8c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setH</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a7533b60fd95ab34a12353cf4644619ba</anchor>
      <arglist>(UCoord h)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setV</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>af030f3c3b8d58ee97160f5b8d0fd9460</anchor>
      <arglist>(UCoord v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>offset</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>aef9ab4a5543ba0f333264cda1c92f0c9</anchor>
      <arglist>(UCoord h, UCoord v=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>offset</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>adc8909a7aaa3ad1da2edf54b6b96c855</anchor>
      <arglist>(const Point &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>bound</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a538f481afbcc180609d5a735efd038f9</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>aea898ef08fe0fd4bd52ac443793e22e2</anchor>
      <arglist>(UCoord h, UCoord v)</arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>operator+</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>aadb189d4f3fad36e2f0de12d6567d966</anchor>
      <arglist>(const Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>operator-</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ae5588008b6777502c28ffdea76008862</anchor>
      <arglist>(const Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>operator/</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>aa4b7d89f909884fd39a0603b28e65d28</anchor>
      <arglist>(int32 n) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>operator*</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a8564322b6af258a840a43ac12008ac03</anchor>
      <arglist>(int32 n) const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>abe5fd3bfead0a1776a237e0f401849d8</anchor>
      <arglist>(const Point &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>operator-=</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a6a34e93a1ddd60bcbaa92d100eed3c5c</anchor>
      <arglist>(const Point &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>operator*=</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a7b63d6acb14aef491355fb194d9d0510</anchor>
      <arglist>(int32 n)</arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>operator/=</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>ac0532b1f7a65612b9ea8915be3d11629</anchor>
      <arglist>(int32 n)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>operator*</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a1e3c1372243223efb016656986cc00d5</anchor>
      <arglist>(const Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>af82120999c83c099bce7f9d6dfd3bd25</anchor>
      <arglist>(const Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>aa0813f77ff3be7522b5d559aade56ef7</anchor>
      <arglist>(const Point &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>operator-</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>adbd7a6716b2ed81c8d2429a5f33337dd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>UCoord</type>
      <name>h</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a0fb348f2ed5da034e9e1dd03e75e1bfc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UCoord</type>
      <name>v</name>
      <anchorfile>classSteinberg_1_1Point.html</anchorfile>
      <anchor>a252c8d7f746743c33bc393518858d14b</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Rect</name>
    <filename>classSteinberg_1_1Rect.html</filename>
    <member kind="function">
      <type></type>
      <name>Rect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ae436fd0322c99157c5443a3385961e22</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aa6e492bf78613c30047d7dce523dfe49</anchor>
      <arglist>(UCoord left, UCoord top, UCoord right, UCoord bottom)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>acb5ab1defb11664080b2666cdca869ea</anchor>
      <arglist>(UCoord w, UCoord h)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aa923c188e9a3d6da9a5e4bdaeda1738e</anchor>
      <arglist>(const Point &amp;topLeft, const Point &amp;bottomRight)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ad317016244a78a8609a96dfe55221411</anchor>
      <arglist>(const Point &amp;topLeft, UCoord width, UCoord height)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Rect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ad90906ec605927abed98c2df3c4de80d</anchor>
      <arglist>(const ViewRect &amp;vr)</arglist>
    </member>
    <member kind="function">
      <type>UCoord</type>
      <name>getWidth</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aeebcf80260d1290c154bf3cf71d2eb6a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>UCoord</type>
      <name>getHeight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a25b8fc5c6f437e4cfbc5f2a9150cab87</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>setWidth</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ab886351e17fcfe92fcfb3005c030df19</anchor>
      <arglist>(const UCoord w)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>setHeight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aef5469ef32a9a088adcfb6c1f6fb9593</anchor>
      <arglist>(const UCoord h)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmpty</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac95684b9162e286c96faf0f6cefe7ea0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getTopLeft</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a992f3163dd11b8e3125f341d4e95449a</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>getTopLeft</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ad64efed0e30ce2d00c973ad653489218</anchor>
      <arglist>(Point &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getBottomRight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a1ab7f4cc6c9030ffd29caa5c3a32a7ea</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>getBottomRight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>af1a09aec00740aa0edc04dc584022b91</anchor>
      <arglist>(Point &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getTopRight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aecc93ed4fd67fbfd9510e89e218cb3ef</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>getTopRight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a50fce0f54c771bdc9d7766d23519d4ce</anchor>
      <arglist>(Point &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getBottomLeft</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac204b269ebd6bce0f493ab0e7206be0b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>getBottomLeft</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a68d7b11964db787c5ca33cf664faad28</anchor>
      <arglist>(Point &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>toPoint</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ad34d7d4b8837d226974b1c59a8d305e7</anchor>
      <arglist>(Direction dir, Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>toPoint</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aaa5a10d9bfe7d1eb98b7e11c6cee231a</anchor>
      <arglist>(Direction dir) const </arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>setTopLeft</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a6c1302ead04c79f99bb9a92805a96a0e</anchor>
      <arglist>(const UCoord left, const UCoord top)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>setBottomRight</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ad94be0234a9d8d1a540b92a42d8ee672</anchor>
      <arglist>(const UCoord right, const UCoord bottom)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>setSize</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a66c5747d8645e301d3ac89fb0b2a064d</anchor>
      <arglist>(const UCoord w, const UCoord h)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac8deb95d13df015d859bb6f92918ae31</anchor>
      <arglist>(UCoord left, UCoord top, UCoord right, UCoord bottom)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a78f32c51d1a8e0066b9e94503328a209</anchor>
      <arglist>(const Point &amp;topLeft, const Point &amp;bottomRight)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ace43908c63609dc9e8c6d0f60db164db</anchor>
      <arglist>(UCoord left, UCoord top, UCoord right, UCoord bottom)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>moveTo</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aa0535502c925b12517c107187c466024</anchor>
      <arglist>(const Point &amp;where)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>offset</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac34708e73f4a53294c0108eb86e645bf</anchor>
      <arglist>(UCoord x, UCoord y=0)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>offset</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>af035ac0d772d6ddd7efc370ef523aec3</anchor>
      <arglist>(const Point &amp;where)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>inset</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a67f52c54b797ee7e4a7ae3f58674b32d</anchor>
      <arglist>(UCoord delta)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>inset</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a53023b3bf5455da5344580669e628840</anchor>
      <arglist>(UCoord deltaH, UCoord deltaV)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>inset</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a34d5ef9b4211cbfb8da4231341cf2179</anchor>
      <arglist>(UCoord deltaL, UCoord deltaT, UCoord deltaR, UCoord deltaB)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>originize</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>acaf590154f6cfcc070f501bbd3352f82</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>normalize</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aa90bfc53ab65b4581741dbecb80f74ec</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>center</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ab079a75b222642824bb584f37fe841f6</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>centerH</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ada9db12882986bee533582339f31667d</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>centerV</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>af4f3adffb30659773c8c8acf73df3a11</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>bound</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a538f481afbcc180609d5a735efd038f9</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>slideInside</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a8968a11970049716cc549c47d3c56b50</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>join</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a2c20067a76a7a81f2a9d266f428920c8</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>joinEvenIfEmpty</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ae8b12fd2af5658d24ec3ce72a4a62c50</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>subtract</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a967853ac2c805ff7c07524bd663cb99a</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>rectInside</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>addebdb56c10d9f342829a6b10ca7dce0</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>rectIntersect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac359263556932ab1301a303254829f5b</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>rectIntersect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a948e29de118c6b117e21311a52de2038</anchor>
      <arglist>(const Rect &amp;rect, Rect &amp;result) const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getCenter</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a9e97a8efe26be94cbe5202c7f345e175</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getLeftCenter</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a377ba4170a66c8957437fd4a896cdf2b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getRightCenter</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac75807c6f09bf9295adc588c2555680f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getTopCenter</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>af77c0370f0ec46177ddb3c4336de3069</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>Point</type>
      <name>getBottomCenter</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ae29d4bb71436a7b3a8177347671a5aa1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>overlapHorizontal</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a15bdc2e0a6f697d2ac513d121dc774b8</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>overlapVertical</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aedb13c24d2d6d3487f7e6a9abdb39174</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>UCoord</type>
      <name>getOverlapHorizontal</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a9fa4acdc2260d15e57d97886e1f99a47</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>UCoord</type>
      <name>getOverlapVertical</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a8c7d153283ed9f0fcd55f34439f6bc92</anchor>
      <arglist>(const Rect &amp;rect) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pointInside</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a187ade82dddf80df8704e9e819ebc521</anchor>
      <arglist>(const Point &amp;where) const </arglist>
    </member>
    <member kind="function">
      <type>Point &amp;</type>
      <name>constrain</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>aa1bb31fb6fba6efd6edde8aa31c47ab4</anchor>
      <arglist>(Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>lineInside</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ad6b91f517b705c5655df819332bb196f</anchor>
      <arglist>(const Point &amp;p1, const Point &amp;p2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>lineIntersect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a1acbae3c1d9644087a18c1b23696ca78</anchor>
      <arglist>(const Point &amp;p1, const Point &amp;p2) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>boundLine</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a349e6a650a2c3ce3c0292e49cde4dfca</anchor>
      <arglist>(Point &amp;p1, Point &amp;p2) const </arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ae788563763ebfde34617092221f2b6c2</anchor>
      <arglist>(const Point &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a13cc08428d42cab705a05c90b1fec62c</anchor>
      <arglist>(const Rect &amp;rect)</arglist>
    </member>
    <member kind="function">
      <type>ViewRect &amp;</type>
      <name>toViewRect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>ac2f07ebafc2218e32a198f161887a664</anchor>
      <arglist>(ViewRect &amp;vr) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fromViewRect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>af62fbf11865b1a6323240257d8038038</anchor>
      <arglist>(const ViewRect &amp;vr)</arglist>
    </member>
    <member kind="function">
      <type>Rect &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a12c0e0fba88fa2d2edf5d6418c5721f9</anchor>
      <arglist>(const ViewRect &amp;vr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator ViewRect</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>abe59258744988be41f438c05c3ffde48</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>UCoord</type>
      <name>left</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a3f8c54ce0c1f34e3719086cc8b326376</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UCoord</type>
      <name>top</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a6ca75ca7be40ebeef0142d46e30ebe47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UCoord</type>
      <name>right</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>af18ce306c59b6a0b1eae59e9c59a3a86</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>UCoord</type>
      <name>bottom</name>
      <anchorfile>classSteinberg_1_1Rect.html</anchorfile>
      <anchor>a6b844e97322deb0c82ba673d498b190e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Region</name>
    <filename>classSteinberg_1_1Region.html</filename>
    <member kind="function">
      <type></type>
      <name>Region</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ab0affbdd5f40d4d9d7f4cd1fe6d816ca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Region</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ac3400cd9e6cadd22c1e5f0a98f5cd3ee</anchor>
      <arglist>(const Rect &amp;r)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Region</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>acc5b4f9de497d67fe91985db0bab3dce</anchor>
      <arglist>(const Region &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>Region &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a24087abaf5fefae3e5508422eceebc38</anchor>
      <arglist>(const Region &amp;src)</arglist>
    </member>
    <member kind="function">
      <type>Region &amp;</type>
      <name>copyFrom</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a9e9dcb9d2ef0a6a17ba3c192821175b4</anchor>
      <arglist>(const Region &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countRects</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>aa09a99946af4865ffe7f6829e1dc056d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ac8bb3912a3ce86b15842e79d0b421204</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fromRect</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a7948aa70315b1f04dc75551b9e69619a</anchor>
      <arglist>(const Rect &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fromRects</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>afc61c24c6c2ab667582b89c573453691</anchor>
      <arglist>(const TContainer&lt; Rect &gt; &amp;rects)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getRects</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ae37812b4af8bdaaec0f89eb72f8b8ab7</anchor>
      <arglist>(TContainer&lt; Rect &gt; &amp;rects, bool left2right=true, bool topdown=true, int32 maxArea=0) const </arglist>
    </member>
    <member kind="function">
      <type>const Rect &amp;</type>
      <name>getBoundingRect</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>adb509064a01eda765c763ebd0e514870</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>equals</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>addced07c6420ce3de09751dc5d49b6ad</anchor>
      <arglist>(const Region &amp;r) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a6b29e75ebc03d3daca38cf709e45a7bf</anchor>
      <arglist>(const Region &amp;r) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>af5dbb962d82817f98c1041cbcfcf758e</anchor>
      <arglist>(const Region &amp;r) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pointInside</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a9664c03f71f412a2e29c9d4530543636</anchor>
      <arglist>(const Point &amp;p) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>rectInside</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a9d713f74ee2275233b834975baefad63</anchor>
      <arglist>(const Rect &amp;r) const </arglist>
    </member>
    <member kind="function">
      <type>Region &amp;</type>
      <name>offset</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a1eeb189236159b782d845a0b994921c8</anchor>
      <arglist>(const Point &amp;off)</arglist>
    </member>
    <member kind="function">
      <type>Region &amp;</type>
      <name>assignIntersection</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ad8e84b9cd0b502c36f83262f30e89c15</anchor>
      <arglist>(const Region &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>Region &amp;</type>
      <name>assignUnion</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a43460d867c58ca280559c6c1b712f48f</anchor>
      <arglist>(const Region &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>Region &amp;</type>
      <name>assignSubtraction</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>a960aeee06e12a25b1a11f4f0c5e782bc</anchor>
      <arglist>(const Region &amp;r)</arglist>
    </member>
    <member kind="function">
      <type>Region</type>
      <name>getIntersection</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ade46838a1a5012c23e1b54b12415f21e</anchor>
      <arglist>(const Region &amp;r) const </arglist>
    </member>
    <member kind="function">
      <type>Region</type>
      <name>getUnion</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>ad91daf4e85daedc9ce60902227ab1ce6</anchor>
      <arglist>(const Region &amp;r) const </arglist>
    </member>
    <member kind="function">
      <type>Region</type>
      <name>getSubtraction</name>
      <anchorfile>classSteinberg_1_1Region.html</anchorfile>
      <anchor>aca3eec3c7cd5f06078ff98937f4ce171</anchor>
      <arglist>(const Region &amp;r) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::RWLockRecursion</name>
    <filename>classSteinberg_1_1RWLockRecursion.html</filename>
    <class kind="struct">Steinberg::RWLockRecursion::RecursionCount</class>
    <class kind="struct">Steinberg::RWLockRecursion::RecursionCounts</class>
    <class kind="struct">Steinberg::RWLockRecursion::TLS</class>
    <member kind="enumvalue">
      <name>kMaxRWLocksPerThread</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba6bcd457458e06d33182cd93d13c5b27f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoAccess</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bac7d8e4ecf59e5d736b337c8bf1adcee9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kReadAccess</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bacaca1f8be65b8d29c8710e04ac7629f3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kWriteAccess</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba6c8aa74b13e6c53c03527cac24060e4f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kArbitraryRelease</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba832f95a5c48f4388892a882dcd095d3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kErrorLockInbalance</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba2490a2b2631ea99fa343fbfa079a449f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kErrorLockThreadLocalStorage</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bae7d31945d26a9ce67c7b6de12669f1d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kErrorReadToWriteUpgrade</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba8673131ea17a4a5039d0bd702e5566d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kErrorOutOfMemory</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba240aa6b8e6e3c694dc49c77c778e0584</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>initializeGlobalRecursionData</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a81734c2d49a24525be8726c20364376e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int32</type>
      <name>acquireRecursionCount</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>a610fef1a7f8e79836b7812f3ac901166</anchor>
      <arglist>(void *lockKey, int32 accessType)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int32</type>
      <name>releaseRecursionCount</name>
      <anchorfile>classSteinberg_1_1RWLockRecursion.html</anchorfile>
      <anchor>af3ceab7dcfe8da9f616875272c14cd0f</anchor>
      <arglist>(void *lockKey, int accessType, int32 optionFlags=0)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PThreadWriterPreferenceRWLock</name>
    <filename>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</filename>
    <member kind="function">
      <type></type>
      <name>PThreadWriterPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>a48bd0b164225947a1fe9f2f11256919f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~PThreadWriterPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>afa7a2335a789ec203ab9bfaee046bc7f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitToRead</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>a4e95b72f7602bd9a2f48fcb4de644cb0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doneReading</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>a4f07c5e24f7ca63b2bfebcc4ec04773f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitToWrite</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>a39c97f509c7044b733fd9b7825908100</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doneWriting</name>
      <anchorfile>structSteinberg_1_1PThreadWriterPreferenceRWLock.html</anchorfile>
      <anchor>a56e68c384dadb4e6ff11c4f4161628a2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PThreadSlimWriterPreferenceRWLock</name>
    <filename>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</filename>
    <member kind="function">
      <type></type>
      <name>PThreadSlimWriterPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>a90bb9c5dddc83ea50e835c4386507508</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~PThreadSlimWriterPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>afdefd58a48eed14b464533eeaf74798e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitToRead</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>a4e95b72f7602bd9a2f48fcb4de644cb0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doneReading</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>a4f07c5e24f7ca63b2bfebcc4ec04773f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitToWrite</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>a39c97f509c7044b733fd9b7825908100</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doneWriting</name>
      <anchorfile>structSteinberg_1_1PThreadSlimWriterPreferenceRWLock.html</anchorfile>
      <anchor>a56e68c384dadb4e6ff11c4f4161628a2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PThreadReaderPreferenceRWLock</name>
    <filename>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</filename>
    <member kind="function">
      <type></type>
      <name>PThreadReaderPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a451c1e0a6ea2eb453a8310ba145214fe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~PThreadReaderPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a8df4b12cd515d5d3d78c4ca9acf89826</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitToRead</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a4e95b72f7602bd9a2f48fcb4de644cb0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doneReading</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a4f07c5e24f7ca63b2bfebcc4ec04773f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitToWrite</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a39c97f509c7044b733fd9b7825908100</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>doneWriting</name>
      <anchorfile>structSteinberg_1_1PThreadReaderPreferenceRWLock.html</anchorfile>
      <anchor>a56e68c384dadb4e6ff11c4f4161628a2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::WindowsWriterPreferenceRWLock</name>
    <filename>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</filename>
    <class kind="struct">Steinberg::WindowsWriterPreferenceRWLock::SlimRWLockProcs</class>
    <member kind="enumvalue">
      <name>kErrorNotAvailable</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7add53bcccba2c3792c2a75faf62957190</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>WindowsWriterPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>aad8c0b74007113a51ad9d668cb1140fd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToRead</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>a73391ead11985ba50eeabfc559ae018e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneReading</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>ad25ddc7f6c296f23f3b656da5084b544</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToWrite</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>ab3f0dfd5f2f49946816ee7a02b007a84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneWriting</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>a2dd22e95b520182b7b52c7160d051d19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>supported</name>
      <anchorfile>structSteinberg_1_1WindowsWriterPreferenceRWLock.html</anchorfile>
      <anchor>a5eff92f237de5d3ac45f87eb424e78b3</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::WindowsReaderPreferenceRWLock</name>
    <filename>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</filename>
    <member kind="function">
      <type></type>
      <name>WindowsReaderPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>ac34a21b68850833fd41db33b706ff141</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~WindowsReaderPreferenceRWLock</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>a4a95ab6c957a02617bbed81da82846f6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToRead</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>a73391ead11985ba50eeabfc559ae018e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneReading</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>ad25ddc7f6c296f23f3b656da5084b544</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToWrite</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>ab3f0dfd5f2f49946816ee7a02b007a84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneWriting</name>
      <anchorfile>structSteinberg_1_1WindowsReaderPreferenceRWLock.html</anchorfile>
      <anchor>a2dd22e95b520182b7b52c7160d051d19</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::WindowsCompatibilityRWLock</name>
    <filename>classSteinberg_1_1WindowsCompatibilityRWLock.html</filename>
    <member kind="function">
      <type></type>
      <name>WindowsCompatibilityRWLock</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>ad08200aaa5caab885c0419ebc2baf358</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~WindowsCompatibilityRWLock</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>ac27d3805de702ac4bede0ffd0beb579f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToRead</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>a73391ead11985ba50eeabfc559ae018e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneReading</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>ad25ddc7f6c296f23f3b656da5084b544</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToWrite</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>ab3f0dfd5f2f49946816ee7a02b007a84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneWriting</name>
      <anchorfile>classSteinberg_1_1WindowsCompatibilityRWLock.html</anchorfile>
      <anchor>a2dd22e95b520182b7b52c7160d051d19</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FStreamer</name>
    <filename>classSteinberg_1_1FStreamer.html</filename>
    <member kind="function">
      <type></type>
      <name>FStreamer</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a326b593fe85c31981865746c8cf0303d</anchor>
      <arglist>(int16 byteOrder=BYTEORDER)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~FStreamer</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a939394fecf611c7d3b31016175d4e0e6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>skip</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a28410ce59c7f96b01d34cbb996ba9d07</anchor>
      <arglist>(uint32 bytes)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pad</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a63372447ec8258db1b7d5e2b624c6ec0</anchor>
      <arglist>(uint32 bytes)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual TSize</type>
      <name>readRaw</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>af7b1f1806480071cbe0822ca3b19240e</anchor>
      <arglist>(void *, TSize)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual TSize</type>
      <name>writeRaw</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ad9301dcce91b6366a1ebf1673998c673</anchor>
      <arglist>(const void *, TSize)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int64</type>
      <name>seek</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a80ed73a703e084b355627d8966daf77f</anchor>
      <arglist>(int64, FSeekMode)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int64</type>
      <name>tell</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a1ba197f3c51297c9c18e64a27fb51c19</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setByteOrder</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>afd8f7d6bb97d1020c32fcb1beb49986a</anchor>
      <arglist>(int32 e)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getByteOrder</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ae1b4be37a4192f7688653a8999399711</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeChar8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a998c6902fdd8b21bbebc626dd4d63120</anchor>
      <arglist>(char8)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readChar8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a49117f69772f84b75ac6eb3ca72c4f33</anchor>
      <arglist>(char8 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeUChar8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a3d2ae068d6eece63ec3f95bc42efb5ed</anchor>
      <arglist>(unsigned char)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readUChar8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a050044d61e58a580dbe8955e78e59715</anchor>
      <arglist>(unsigned char &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeChar16</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a3843e29715ce30dbbc2cfd15e0e213d3</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readChar16</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a8367a9a0969af33c39aa4e307bf80708</anchor>
      <arglist>(char16 &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ad77412c80fcf33ff6b234644f6049953</anchor>
      <arglist>(int8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>aaffe413db58e603c4e185a89bbaa5b1e</anchor>
      <arglist>(int8 &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt8u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>aeb4e434ddc84c1ed48329ca603d97c58</anchor>
      <arglist>(uint8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt8u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a0b787b493ecdccc6978a34b42945ef5f</anchor>
      <arglist>(uint8 &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt16</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a5370cf9ca403ed7933976cf59423d309</anchor>
      <arglist>(int16)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt16</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a3254224fd4c495000e4b18538f42ece1</anchor>
      <arglist>(int16 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt16Array</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a51f8744e0f55375577c51c062168f79f</anchor>
      <arglist>(const int16 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt16Array</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a27b993ce8d89e96688949124845dad2f</anchor>
      <arglist>(int16 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt16u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ad6ad0e47c8f4c10459184131d10bd1ef</anchor>
      <arglist>(uint16)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt16u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a7d425607375843e893b80c65a67c165d</anchor>
      <arglist>(uint16 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt16uArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a242bb719494fb5ce34101f781630f218</anchor>
      <arglist>(const uint16 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt16uArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ad6ad574460786ee6a7c4f7fbc2261690</anchor>
      <arglist>(uint16 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt32</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a0ade9fcb607318bf3e2e3e61128dc5dd</anchor>
      <arglist>(int32)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt32</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>afdc3408bcec5a81b9ce74521836bc97f</anchor>
      <arglist>(int32 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt32Array</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a3b9f76b17804e930c08aa0801329498c</anchor>
      <arglist>(const int32 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt32Array</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a7a832e7546b61a35e0d80c7cfcddc896</anchor>
      <arglist>(int32 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt32u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>acd7e32e72765009e13ad7dbbcfd7e1ee</anchor>
      <arglist>(uint32)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt32u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>abe21610fed6d57bde1d0c99896ca9545</anchor>
      <arglist>(uint32 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt32uArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a8afcc5dbaa740a01e9efdb87728c0f9d</anchor>
      <arglist>(const uint32 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt32uArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ac903b1420b673af2b7c6f4502c4a8157</anchor>
      <arglist>(uint32 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt64</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a8990f73a83e3d804d15b65617330a0a8</anchor>
      <arglist>(int64)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt64</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a6529510e2a381d0e01f508d7a4157a71</anchor>
      <arglist>(int64 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt64Array</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a0ac8492c1507e7270e81ec46244f38dd</anchor>
      <arglist>(const int64 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt64Array</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a5b64179d43d284a94d222f4a9b64fd6b</anchor>
      <arglist>(int64 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt64u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ae36bcbad11f652166fc31678095b232e</anchor>
      <arglist>(uint64)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt64u</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a17565258ffde08c20df60711320854ec</anchor>
      <arglist>(uint64 &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeInt64uArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a079a7a951eee3154e9e89808d02ecc3d</anchor>
      <arglist>(const uint64 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readInt64uArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>acdb427c2448fc4fb7674a0aa1e80dab3</anchor>
      <arglist>(uint64 *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeFloat</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a199a188e7f68fb5b5fe509ecbf4b4606</anchor>
      <arglist>(float)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readFloat</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a96a61e2accf8796303c0f37c2d626b77</anchor>
      <arglist>(float &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeFloatArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a034a8ce9c05cf23de6a80d273fd8f348</anchor>
      <arglist>(const float *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readFloatArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a725fcef271dd11d905db76d21098f6eb</anchor>
      <arglist>(float *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeDouble</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a60ef5ff94413517ac820dcae06812f5b</anchor>
      <arglist>(double)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readDouble</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>ad1c67fedd9d297f986ebd22a7d3082c0</anchor>
      <arglist>(double &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeDoubleArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a83b6820c68b00e34f496e31563c9eb88</anchor>
      <arglist>(const double *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readDoubleArray</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a323cfa378914ea23f11731826b9a79e9</anchor>
      <arglist>(double *array, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeBool</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a51e2b25f25db4ceab194d6b3ef65288c</anchor>
      <arglist>(bool)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>readBool</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>aed6f8d7c8792eff4db6c1403b33bbaa4</anchor>
      <arglist>(bool &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int16</type>
      <name>byteOrder</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a1f29a6ebae4e2b64b0ac03ce73924b46</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>TSize</type>
      <name>writeString8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a863db218e6a751e68deaed25f39c2b20</anchor>
      <arglist>(const char8 *ptr, bool terminate=false)</arglist>
    </member>
    <member kind="function">
      <type>TSize</type>
      <name>readString8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a38a8c350f3e1bd0af0fd8dfc249fa09b</anchor>
      <arglist>(char8 *ptr, TSize size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeStr8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a4d15efd853e1aaa127fb1b13c7c92485</anchor>
      <arglist>(const char8 *ptr)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>readStr8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a51bb89aefae6e4e19d87f10d964da75f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>writeStringUtf8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>afb8d3abe460f1380f258137419ee5d10</anchor>
      <arglist>(const char *ptr)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>readStringUtf8</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a6f192015be51ec795ab0b07ee1bd5e17</anchor>
      <arglist>(char *ptr, int32 maxSize)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int32</type>
      <name>getStr8Size</name>
      <anchorfile>classSteinberg_1_1FStreamer.html</anchorfile>
      <anchor>a59d0c7f0e826e1e043b6c25dd1cb183d</anchor>
      <arglist>(const char8 *ptr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FStreamSizeHolder</name>
    <filename>classSteinberg_1_1FStreamSizeHolder.html</filename>
    <member kind="function">
      <type></type>
      <name>FStreamSizeHolder</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a2acf6a3a07f1a39929e171f3db5f3e92</anchor>
      <arglist>(FStreamer &amp;s)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>beginWrite</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a27d15dc56498ede0bb029d7a17c1f4e9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>endWrite</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a82e84d6d19330d005490af6a0a18951e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>beginRead</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a404df28133b15e6aeff1272dc319a75a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>endRead</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a1143ed396d1273198dd270fd13a1d1fb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>FStreamer &amp;</type>
      <name>stream</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a826abaebde6da276f12b3250c52ad90a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int64</type>
      <name>sizePos</name>
      <anchorfile>classSteinberg_1_1FStreamSizeHolder.html</anchorfile>
      <anchor>a4ed2befe00e711ba9345b04f59d18a69</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IBStreamer</name>
    <filename>classSteinberg_1_1IBStreamer.html</filename>
    <base>Steinberg::FStreamer</base>
    <member kind="function">
      <type></type>
      <name>IBStreamer</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>a845d37e3a5e1ef478b7c44527a8ebd9c</anchor>
      <arglist>(IBStream *stream, int16 byteOrder=BYTEORDER)</arglist>
    </member>
    <member kind="function">
      <type>IBStream *</type>
      <name>getStream</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>aa119920e997774dcbfdcabeffcbc231b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TSize</type>
      <name>readRaw</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>a30c5d72899e925b78e7fcccc9c7bff27</anchor>
      <arglist>(void *, TSize)</arglist>
    </member>
    <member kind="function">
      <type>TSize</type>
      <name>writeRaw</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>a8b0b36e7030ef93b2f442c4c1d8ef3fe</anchor>
      <arglist>(const void *, TSize)</arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>seek</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>ab5476a1dd552c04ca3b0d77dcd033d0c</anchor>
      <arglist>(int64, FSeekMode)</arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>tell</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>a76f3809a9ad84bf7a50bef8cdca46d1d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IBStream *</type>
      <name>stream</name>
      <anchorfile>classSteinberg_1_1IBStreamer.html</anchorfile>
      <anchor>a78d49eed9e150f042fe1e0434fb52102</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ConstString</name>
    <filename>classSteinberg_1_1ConstString.html</filename>
    <member kind="enumeration">
      <name>CompareMode</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af4045f11e8887dda083d0122d24df4f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCaseSensitive</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af4045f11e8887dda083d0122d24df4f6a911f62948153a9586282e653020aed16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCaseInsensitive</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af4045f11e8887dda083d0122d24df4f6ae7f1d84f9d3ed914e475b63b04d2c3ff</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ConstString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a927687036677870519dd1a500e160edb</anchor>
      <arglist>(const char8 *str, int32 length=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ConstString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af313334a239c94dd7ed44bb7a78d4e02</anchor>
      <arglist>(const char16 *str, int32 length=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ConstString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a79f3283eec000755f3ec870a252ea177</anchor>
      <arglist>(const ConstString &amp;str, int32 offset=0, int32 length=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ConstString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a45c99750b35e507bfb2d69a8ee0db3e9</anchor>
      <arglist>(const FVariant &amp;var)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ConstString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae772e034332b4e5123c75abd3b926e66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ConstString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ad522b88dd7b89b8b980b084c36293f82</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>length</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a343677eca1ee05d095bebdff58348b73</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const char8 *</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ad4488edbb6dee9d4bccf82f4bc13fbc3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const char16 *</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2c894a11fdd68a9206cddfc94c3c8e02</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aef5ba11f44485c0a4fab5c2e6f0ac9d5</anchor>
      <arglist>(short idx) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a084dcbcff85e622327d6938f2035d726</anchor>
      <arglist>(long idx) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2bd25e5086b29e8b17fb1dd002336b8d</anchor>
      <arglist>(int idx) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a812522b17b2a8a4d7d0f8fb096413cb7</anchor>
      <arglist>(unsigned short idx) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ad65d02448773ae8bf7e4a5f45ee5d068</anchor>
      <arglist>(unsigned long idx) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ab28491546340c76436c1a60f62c01370</anchor>
      <arglist>(unsigned int idx) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char8 *</type>
      <name>text8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aaa3593cad3287eafd543ae6a85445526</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char16 *</type>
      <name>text16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a1ded2433ce7af42df3bff49606529ad0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>text</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ac52682c350fb4245e90d3ac1be1d155e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const void *</type>
      <name>ptr</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2e302848abdece2d6e387a86b44077b2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char8</type>
      <name>getChar8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af0e78884ebac29c6e826ddf15db0dfa3</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char16</type>
      <name>getChar16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a28cf09b108d405ff58e08301483c14fa</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>getChar</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aaa12290060a0f8c8826540b2fa073463</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>getCharAt</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a318708aa04ac3d612f81e12b1ce8bf54</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>testChar8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a45a9fd048f0a452f7ba5c6caeb8c5462</anchor>
      <arglist>(uint32 index, char8 c) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>testChar16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae48a76e8f52719a06055177d79b35a3a</anchor>
      <arglist>(uint32 index, char16 c) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>testChar</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae712cb173de08c3c3caadd78591b24c4</anchor>
      <arglist>(uint32 index, char8 c) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>testChar</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af127c4c265ce53bc53f8e437f5de9863</anchor>
      <arglist>(uint32 index, char16 c) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>extract</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ac4be51b49d782bc940d79ddc3ed788f4</anchor>
      <arglist>(String &amp;result, uint32 idx, int32 n=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>copyTo8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a93dd74c1b2c0c84cc852fecbeaa83880</anchor>
      <arglist>(char8 *str, uint32 idx=0, int32 n=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>copyTo16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aac71be1002205b2c53ca7f7c378b9c36</anchor>
      <arglist>(char16 *str, uint32 idx=0, int32 n=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>copyTo</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a9ddcf9f419638cba18aac44b3b202c73</anchor>
      <arglist>(char *str, uint32 idx=0, int32 n=-1) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copyTo</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ab50a653acec89ee5d20c2bc00c611aa9</anchor>
      <arglist>(IStringResult *result) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>copyTo</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aca87d8dcd019e6ef9091fe4219e91a2b</anchor>
      <arglist>(IString &amp;string) const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hash</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae323ccf00110eb824e30f5400c821c35</anchor>
      <arglist>(uint32 tsize) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>compareAt</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a49cf0bbdb39256a42d3abad96a29c115</anchor>
      <arglist>(uint32 index, const ConstString &amp;str, int32 n=-1, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>compare</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a37ab19f36fa0fe84d6198fbb915e1a3e</anchor>
      <arglist>(const ConstString &amp;str, int32 n, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>compare</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aeed08aa651816eb40362380571b67119</anchor>
      <arglist>(const ConstString &amp;str, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>naturalCompare</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ad6da0e3b06d428d995c3a3da5d5fc239</anchor>
      <arglist>(const ConstString &amp;str, CompareMode mode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>startsWith</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a04ad3a9b67c46f78ad5808ffa5c613f5</anchor>
      <arglist>(const ConstString &amp;str, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>endsWith</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a273ee693035845d82a22faeb4c291bc2</anchor>
      <arglist>(const ConstString &amp;str, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a818353cdd0df3a345f3cf24643936c9d</anchor>
      <arglist>(const ConstString &amp;str, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findLast</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>acb273bc482410679fd5a7f9501dc9f04</anchor>
      <arglist>(const ConstString &amp;str, int32 n=-1, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findLast</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a9c3c1d36a9b3cee6f8de1d862ab3d627</anchor>
      <arglist>(char8 c, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findLast</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a6a39c1424ccfe87f6991d86dd01754f2</anchor>
      <arglist>(char16 c, CompareMode m=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countOccurences</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a705c95a6de98886fb4f5909433223394</anchor>
      <arglist>(char8 c, uint32 startIndex, CompareMode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countOccurences</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a8e0d653da81e7df4840e6e06a26d27fe</anchor>
      <arglist>(char16 c, uint32 startIndex, CompareMode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getFirstDifferent</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a8ccd4cb578b3a6a6f9df91b1a55eab8a</anchor>
      <arglist>(const ConstString &amp;str, CompareMode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isDigit</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a70bf0639db6a1f8738af56f7d3f68756</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanFloat</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a045368615304df6f06c4963a22452a3b</anchor>
      <arglist>(double &amp;value, uint32 offset=0, bool scanToEnd=true) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanInt64</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae398df8a810d645d79c9c8ea2dffb056</anchor>
      <arglist>(int64 &amp;value, uint32 offset=0, bool scanToEnd=true) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanUInt64</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a753ee80dd774f6a622042c8a93931345</anchor>
      <arglist>(uint64 &amp;value, uint32 offset=0, bool scanToEnd=true) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanInt32</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a88c19d27780dec4cb83adbc8d641cf61</anchor>
      <arglist>(int32 &amp;value, uint32 offset=0, bool scanToEnd=true) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanUInt32</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a5c399d97209fefd578975aff3b7c4d8d</anchor>
      <arglist>(uint32 &amp;value, uint32 offset=0, bool scanToEnd=true) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanHex</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a233352a12386e71c582f6a6d3bca5285</anchor>
      <arglist>(uint8 &amp;value, uint32 offset=0, bool scanToEnd=true) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getTrailingNumberIndex</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ad7260ccc76f97b0bc8b8f28c4c40a10b</anchor>
      <arglist>(uint32 width=0) const </arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>getTrailingNumber</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a59df2a71cee3d7a3c9a3435a7e2ce602</anchor>
      <arglist>(int64 fallback=0) const </arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>getNumber</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a36503ac8299b143575e6a15185659239</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toVariant</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>abc7d8f8deb90f6f1f7db8d3023aecfb3</anchor>
      <arglist>(FVariant &amp;var) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isWideString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a9f51ffda3dea7bfd701b339d0cbc25ac</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isAsciiString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a295655282f71e36076d13d30fd8ed49c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isNormalized</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aabde9540d808cb7f31588d772c05cb30</anchor>
      <arglist>(UnicodeNormalization=kUnicodeNormC)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findFirst</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a06be0d67995b3109d577c75475bd25ce</anchor>
      <arglist>(const ConstString &amp;str, int32 n=-1, CompareMode m=kCaseSensitive, int32 endIndex=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findFirst</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a29df4b5399422f630084a024b386349f</anchor>
      <arglist>(char8 c, CompareMode m=kCaseSensitive, int32 endIndex=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findFirst</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae0c0c3f14a1beb3e274e7fe56aa1afe1</anchor>
      <arglist>(char16 c, CompareMode m=kCaseSensitive, int32 endIndex=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findNext</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2f120e062c872928abd7ab6f48669c85</anchor>
      <arglist>(int32 startIndex, const ConstString &amp;str, int32 n=-1, CompareMode=kCaseSensitive, int32 endIndex=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findNext</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a98f7aab7d0600687564482efdad85bbb</anchor>
      <arglist>(int32 startIndex, char8 c, CompareMode=kCaseSensitive, int32 endIndex=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findNext</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ab7a7278cb3b7739d6cf90445c20001b4</anchor>
      <arglist>(int32 startIndex, char16 c, CompareMode=kCaseSensitive, int32 endIndex=-1) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findPrev</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a56c59e934a36bdd71450f477b36bc813</anchor>
      <arglist>(int32 startIndex, const ConstString &amp;str, int32 n=-1, CompareMode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findPrev</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a7997fa78a12a24b7a52a0603f2e20952</anchor>
      <arglist>(int32 startIndex, char8 c, CompareMode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>findPrev</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a54ac0a44bad4f79c6301bf5dcbe1a393</anchor>
      <arglist>(int32 startIndex, char16 c, CompareMode=kCaseSensitive) const </arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharSpace</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a558f9643b112a9e296034f4b5c104da4</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharSpace</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>afc1738b9f2705034218d299e33afbb0e</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharAlpha</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a6447bfca9b9d31ed9ce96a35fb987206</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharAlpha</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ac2291ddfae0133dedde40a26dbd51099</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharAlphaNum</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2b48d0f2b9de6a59ee41f6029f030dfa</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharAlphaNum</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af748287f5024af4c82b3e6225660f88d</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharDigit</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a60d921d7240987538c237a8c5a315e73</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharDigit</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a1561e3f288d0886f47344379e2f0fa49</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharAscii</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af506286b5d395d5b6e5918eba7f71486</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharAscii</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af0143d0862af1c86a44f42708b7d6fce</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharUpper</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a15c5156f789b384961e95ed427c62e9b</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharUpper</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a1735df81440afee9f39ffa303acfcc80</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharLower</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a6288d7b8b62d464b8cda5cdc86054bc8</anchor>
      <arglist>(char8 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>isCharLower</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>af69b5c5f85db7bf8e88f94fd541c2eda</anchor>
      <arglist>(char16 character)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanInt64_8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae46cb29a2fe9015768110c6e8a2bf3a1</anchor>
      <arglist>(const char8 *text, int64 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanInt64_16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a6c893b487dfe24d9678302794e8c08d3</anchor>
      <arglist>(const char16 *text, int64 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanInt64</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ada807776c00d43a2be387ef88614127f</anchor>
      <arglist>(const char *text, int64 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanUInt64_8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ae520c42b0edc50aed97977a73c592f75</anchor>
      <arglist>(const char8 *text, uint64 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanUInt64_16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2426d33f600572497fb3e4954caaf20d</anchor>
      <arglist>(const char16 *text, uint64 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanUInt64</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a50186e229b1da9121661a54240747ecb</anchor>
      <arglist>(const char *text, uint64 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanInt32_8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a3a230a4b3bd90078a4c7f22080ffad82</anchor>
      <arglist>(const char8 *text, int32 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanInt32_16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a06b4a788c1d6d1f32c3dfaac162b11ac</anchor>
      <arglist>(const char16 *text, int32 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanInt32</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a2911ac52c6c2ad63d4ef0b65e4a0d107</anchor>
      <arglist>(const char *text, int32 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanUInt32_8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a1b111b6a67a73953b9aec2f6afc11661</anchor>
      <arglist>(const char8 *text, uint32 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanUInt32_16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ac19286d8f082ef76774460eb7933b947</anchor>
      <arglist>(const char16 *text, uint32 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanUInt32</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a72534f72b582b95ec762ec61940875f8</anchor>
      <arglist>(const char *text, uint32 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanHex_8</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a202229a2718b4c6e8f6720df328b27a0</anchor>
      <arglist>(const char8 *text, uint8 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanHex_16</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>ad408b57b46dd39329c244d1e59ad3eeb</anchor>
      <arglist>(const char16 *text, uint8 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static bool</type>
      <name>scanHex</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>adcee4e2680b55bb072b8ea4658dcb775</anchor>
      <arglist>(const char *text, uint8 &amp;value, bool scanToEnd=true)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static char8</type>
      <name>toLower</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aa1bd71cbb5c91ad80af441549e445659</anchor>
      <arglist>(char8 c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static char8</type>
      <name>toUpper</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a1e2802d0abf81576c53da9c30aacf969</anchor>
      <arglist>(char8 c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static char16</type>
      <name>toLower</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a69028c11ba44bc35dff982bb2120f38e</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static char16</type>
      <name>toUpper</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a62c158cae29f219f5a14384024dc69a7</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int32</type>
      <name>multiByteToWideString</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>aae9eb74628356d91bdd0e50426577d02</anchor>
      <arglist>(char16 *dest, const char8 *source, int32 wcharCount, uint32 sourceCodePage=kCP_Default)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static int32</type>
      <name>wideStringToMultiByte</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a81838f3369304321ab595bc000368f14</anchor>
      <arglist>(char8 *dest, const char16 *source, int32 char8Count, uint32 destCodePage=kCP_Default)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>union Steinberg::ConstString::@2</type>
      <name>@3</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>afdb2b553f2c25b477ce9ab1261654906</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void *</type>
      <name>buffer</name>
      <anchorfile>unionSteinberg_1_1ConstString_1_1@2.html</anchorfile>
      <anchor>a368f7094dc38acca20612bbb392552f4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char8 *</type>
      <name>buffer8</name>
      <anchorfile>unionSteinberg_1_1ConstString_1_1@2.html</anchorfile>
      <anchor>abb93591ce1f1696318386689faa7627b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char16 *</type>
      <name>buffer16</name>
      <anchorfile>unionSteinberg_1_1ConstString_1_1@2.html</anchorfile>
      <anchor>a8d780846d765cbb997ce79cafa832cac</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint32</type>
      <name>len</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a63941c3a03dc9736f3234bb756d9a305</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>uint32</type>
      <name>isWide</name>
      <anchorfile>classSteinberg_1_1ConstString.html</anchorfile>
      <anchor>a75060976753e877247e364d1816245d7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::String</name>
    <filename>classSteinberg_1_1String.html</filename>
    <base>Steinberg::ConstString</base>
    <member kind="enumeration">
      <name>CharGroup</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>af76aa92cca3a7f4f1cc9bfd804a3c873</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSpace</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>af76aa92cca3a7f4f1cc9bfd804a3c873aab823bcc5d8d26fafa6ada800ab21f74</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNotAlphaNum</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>af76aa92cca3a7f4f1cc9bfd804a3c873a7e67f6171578b087aaa7b475ccf1b7a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNotAlpha</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>af76aa92cca3a7f4f1cc9bfd804a3c873a34415afe7e8fb63d801a1fce28628e8d</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a8db865e64c3c3f65ec6a0b6fd8c09a94</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aa9bbe6b09b629570004c874e08f76615</anchor>
      <arglist>(const char8 *str, MBCodePage codepage, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a9e3843f45b00dbd34481e62c1ecaf782</anchor>
      <arglist>(const char8 *str, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ada7aea976019ca074da1c9f91a8c05b0</anchor>
      <arglist>(const char16 *str, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a1733e560575975097871b5aed67a2c01</anchor>
      <arglist>(const String &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a49f71cca276a33db442c6d583d2f9b8f</anchor>
      <arglist>(const ConstString &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>af9b8fc3f312ec00a3f2ed3cade53d6db</anchor>
      <arglist>(const FVariant &amp;var)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a59f9b66e14775bdb1662cd88074f80d5</anchor>
      <arglist>(IString *str)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~String</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a998ab66c7adb23a76179eec57d05de9d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateLength</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aeaaaf7e3d412ec741fc91722eaaceb13</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char8 *</type>
      <name>text8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aaa3593cad3287eafd543ae6a85445526</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char16 *</type>
      <name>text16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a1ded2433ce7af42df3bff49606529ad0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char8</type>
      <name>getChar8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>af0e78884ebac29c6e826ddf15db0dfa3</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char16</type>
      <name>getChar16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a28cf09b108d405ff58e08301483c14fa</anchor>
      <arglist>(uint32 index) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setChar8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a9821aa4f05d40a996f008636dbb0326c</anchor>
      <arglist>(uint32 index, char8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setChar16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a579d2fd2b9b46c78bdd5383da12ee020</anchor>
      <arglist>(uint32 index, char16 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setChar</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ac141e6f97efe87a6952acae14cd938a1</anchor>
      <arglist>(uint32 index, char8 c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setChar</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a23bc2b1e6f1dec3921353722c4fbd2e6</anchor>
      <arglist>(uint32 index, char16 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ae2055bf8225e1ae1062abf2b2f63503c</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a9762fc85a717c44f1772dfd1933894b1</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a2d987a6d658b7e43497c9521ee809ea3</anchor>
      <arglist>(const ConstString &amp;str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aa7694556e438408131523c949aeecdd0</anchor>
      <arglist>(const String &amp;str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a47163cdae5fe81ac503214ea71360686</anchor>
      <arglist>(char8 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a0b5b8173bdf45815f7ed64ae5a4235a2</anchor>
      <arglist>(char16 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a72ebe09b8abd759e9acb67d8fb44a104</anchor>
      <arglist>(const ConstString &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ad182eaf955c0d87fda7047bfe8c8586e</anchor>
      <arglist>(const char8 *str, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a155c3b3d218859544ed3ec4691b5f694</anchor>
      <arglist>(const char16 *str, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a305b80fea895a175ff15dfa9fca9dbdc</anchor>
      <arglist>(char8 c, int32 n=1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ae4e046ac0b58d1bac992d9316d8ff088</anchor>
      <arglist>(char16 c, int32 n=1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a7f5057b04cc5fd42d4e841560c48ce17</anchor>
      <arglist>(const ConstString &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a8ce343c3a11cb06f11ceb3e543e7bc03</anchor>
      <arglist>(const char8 *str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a96cbbb5efbaffcbb1f48f12dda2b8581</anchor>
      <arglist>(const char16 *str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a03eb941bf059e950699670e38bb54a94</anchor>
      <arglist>(const char8 c, int32 n=1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a5c4d9baf29b4ea315f447ad52d6c5239</anchor>
      <arglist>(const char16 c, int32 n=1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ab4203737065fd753214e0b65d61a874d</anchor>
      <arglist>(uint32 idx, const ConstString &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aea25de79cbc2237412bd253cdc2836be</anchor>
      <arglist>(uint32 idx, const char8 *str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a5afc7b36bf978427835538018f6f6bc5</anchor>
      <arglist>(uint32 idx, const char16 *str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a48cffef1dd37fc734c322b8366bf45fe</anchor>
      <arglist>(uint32 idx, char8 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a92cfef5cae8cad95b4420998cc1298c3</anchor>
      <arglist>(uint32 idx, char16 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a8c09167d2a0ffed51ebea0865b3e16e9</anchor>
      <arglist>(const String &amp;str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a0bc1eea72b69a361d5bee4c854018d07</anchor>
      <arglist>(const ConstString &amp;str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>acd7565e31ea9c44072a2de110f214c88</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ab59e7ce2cba8e051f7f529136b697948</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a7f29feb0fa3ced3574c7bbf3cded1ab4</anchor>
      <arglist>(const char8 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ac40b69e1365cf11d0fdde38466acb6df</anchor>
      <arglist>(const char16 c)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ac1d26f09a0f4f6c084f03b843bc11c19</anchor>
      <arglist>(uint32 idx, int32 n1, const ConstString &amp;str, int32 n2=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a2d2030439e7cb36eb5674ef6c9525565</anchor>
      <arglist>(uint32 idx, int32 n1, const char8 *str, int32 n2=-1)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a54eb203ea602d6ffea70b28070675060</anchor>
      <arglist>(uint32 idx, int32 n1, const char16 *str, int32 n2=-1)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a605f3f03d1f4c26f8b6e9db9d77379b4</anchor>
      <arglist>(const char8 *toReplace, const char8 *toReplaceWith, bool all=false)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ab6167bfe7190139d8fe5c2be429a25a9</anchor>
      <arglist>(const char16 *toReplace, const char16 *toReplaceWith, bool all=false)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a43e88f4cca43c27ed5d24ef94e5af91b</anchor>
      <arglist>(const char8 *toReplace, char8 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a58a8e5496343516f41a73c2230e86122</anchor>
      <arglist>(const char16 *toReplace, char16 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a61ff75394ec5a0912c1308c23cd07d9e</anchor>
      <arglist>(char8 toReplace, char8 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a512d9ef3766c15768ae7f75debeb4d11</anchor>
      <arglist>(char16 toReplace, char16 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a356590acdce80db07f9eb77b6de98324</anchor>
      <arglist>(char8 toReplace, char8 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a8a25396b718a5609eb42fc1d61ea1fa4</anchor>
      <arglist>(char16 toReplace, char16 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a6d0b5c39ee8a41d84da38f83f4a6606e</anchor>
      <arglist>(const char8 *toReplace, char8 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a674fdd0d0499a7bc150e9b3d379164f0</anchor>
      <arglist>(const char16 *toReplace, char16 toReplaceBy)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a01c841b84afa55d724019512fd7af8f5</anchor>
      <arglist>(uint32 index=0, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>trim</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a80d652fd1a09fe0c4e667c670f9b2dd5</anchor>
      <arglist>(CharGroup mode=kSpace)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a5c04ba944704a95ddd92fc9d7afd10e1</anchor>
      <arglist>(CharGroup mode=kSpace)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a1936a7b4d4ccd408551b8a0fdf2a7c9f</anchor>
      <arglist>(const char8 *which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>adcd7ed15ae18cf7c3178ac36e6f4e36e</anchor>
      <arglist>(const char16 *which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a79629fec102b32f037dfb109552d4a3d</anchor>
      <arglist>(const char8 which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars16</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aa82260d28382fd80696eb4e42e4bd21c</anchor>
      <arglist>(const char16 which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a0056c28bddfa9d61b7b18c498fc73157</anchor>
      <arglist>(const char8 *which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a029e8327149ae92c67968bc0a58ad9fc</anchor>
      <arglist>(const char16 *which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a2e8359042c52c36d914af3592145519c</anchor>
      <arglist>(const char8 which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeChars</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a507ff5666ca801779d21fca6569bd60f</anchor>
      <arglist>(const char16 which)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeSubString</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a51c672fff69360fbef073080071fb7b0</anchor>
      <arglist>(const ConstString &amp;subString, bool allOccurences=true)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>printf</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ac75a7887729b9c2e5684363dc687f335</anchor>
      <arglist>(const char8 *format,...)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>printf</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a537197b902c970c72b087ff9f869be2c</anchor>
      <arglist>(const char16 *format,...)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>vprintf</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a09b2e8a8b96a7cdf1c149514d773d7dc</anchor>
      <arglist>(const char8 *format, va_list args)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>vprintf</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ad45799a3ed3869d8996555f78175c4de</anchor>
      <arglist>(const char16 *format, va_list args)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>printInt64</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a76fce2f426ae58e98a6c9722a7a219a2</anchor>
      <arglist>(int64 value)</arglist>
    </member>
    <member kind="function">
      <type>String &amp;</type>
      <name>printFloat</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a02ade24a8128f57c7c1682f7c4e193e2</anchor>
      <arglist>(double value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>incrementTrailingNumber</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a784e9e7df7086386504a8935b9e39879</anchor>
      <arglist>(uint32 width=2, char separator=STR(&apos; &apos;), uint32 minNumber=1, bool applyOnlyFormat=false)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>fromVariant</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a3b4c47d6b39b4499f0fe5bf9c2e289a7</anchor>
      <arglist>(const FVariant &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toVariant</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>abc7d8f8deb90f6f1f7db8d3023aecfb3</anchor>
      <arglist>(FVariant &amp;var) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>fromAttributes</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>afa3a283b87647a8898b8847993972884</anchor>
      <arglist>(IAttributes *a, IAttrID attrID)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>toAttributes</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>afdfaa3b6d6a266c6dc41ad1843a5f804</anchor>
      <arglist>(IAttributes *a, IAttrID attrID)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>swapContent</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a57f507c68a120a81db668613a1ee1b73</anchor>
      <arglist>(String &amp;s)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>take</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ae23d51189d31f93126db6c62eddabe86</anchor>
      <arglist>(String &amp;str)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>take</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aae43edfabf05c02e0f0fc7c64056f382</anchor>
      <arglist>(void *_buffer, bool wide)</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>pass</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>adec058d1c3e667b7f0f964b11265033c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>passToVariant</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ae2263181a009962d02fd25b33b05a1d9</anchor>
      <arglist>(FVariant &amp;var)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toLower</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>acc83ba4d9ccff6a513ed942b1449b783</anchor>
      <arglist>(uint32 index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toLower</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>adb7e069688aa84f251961a1e7714e355</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toUpper</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a351fa9427bdbda2d4eeeec25347937e7</anchor>
      <arglist>(uint32 index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toUpper</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>aced434f03c0594b74bcd7453184b95a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned char *</type>
      <name>toPascalString</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a29369eb464b0594fbafba3c17ee8b5e4</anchor>
      <arglist>(unsigned char *buf)</arglist>
    </member>
    <member kind="function">
      <type>const String &amp;</type>
      <name>fromPascalString</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a95b58bddd98010222da389ed9548ad07</anchor>
      <arglist>(const unsigned char *buf)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>toWideString</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>ad140992bdbbaf77940afbf992d0b13df</anchor>
      <arglist>(uint32 sourceCodePage=kCP_Default)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>toMultiByte</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>acf18f38c6096b9f7fdff3089febf5e7e</anchor>
      <arglist>(uint32 destCodePage=kCP_Default)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fromUTF8</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>abe9d4e30a36a330f0b75b6ea31bd0820</anchor>
      <arglist>(const char8 *utf8String)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>normalize</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a629eb76fcaf20205ab6c2482f85816eb</anchor>
      <arglist>(UnicodeNormalization=kUnicodeNormC)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>resize</name>
      <anchorfile>classSteinberg_1_1String.html</anchorfile>
      <anchor>a3f9845a9817eca153fc40325e9261318</anchor>
      <arglist>(uint32 newSize, bool wide, bool fill=false)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::StringObject</name>
    <filename>classSteinberg_1_1StringObject.html</filename>
    <base>Steinberg::FObject</base>
    <base>Steinberg::String</base>
    <member kind="function">
      <type></type>
      <name>StringObject</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>ac8b931dc2f0f7f581b341ee12747ef4b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>StringObject</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a4a8dd8b0035061f846ba7430b359753f</anchor>
      <arglist>(const char16 *str, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>StringObject</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a9496bb3a6cc76187b76608d07dab9f0a</anchor>
      <arglist>(const char8 *str, int32 n=-1, bool isTerminated=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>StringObject</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a343601d416df223b32a452756f4faf5c</anchor>
      <arglist>(const StringObject &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>StringObject</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a0cd28b016185969e68afc36f019ab680</anchor>
      <arglist>(const String &amp;str, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>StringObject</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a0dfc44527b214ea38efbc5e20b7bc3c7</anchor>
      <arglist>(const FVariant &amp;var)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setText</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>aa40126ff3e70d59587347f61c90f70ce</anchor>
      <arglist>(const char8 *text)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setText8</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a91c17054877e6cbbc2a0ced0b1ad4e64</anchor>
      <arglist>(const char8 *text)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setText16</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>ae6c1e3301ba6350c6c750b8dcf3259f3</anchor>
      <arglist>(const char16 *text)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char8 *</type>
      <name>getText8</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a94df150af5e6fd6cb68e47c84ea8d29c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char16 *</type>
      <name>getText16</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>ab444884814ba344520063ded1f4424b2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>take</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>ada917963707274f589ddd791cdbf1705</anchor>
      <arglist>(void *s, bool _isWide)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isWideString</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a9f51ffda3dea7bfd701b339d0cbc25ac</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::FClassID</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>aebd6fe798b7f779276de6a3d915584a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a46dce08d6692acffe85184067f428789</anchor>
      <arglist>(Steinberg::FClassID s) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isTypeOf</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>af06af9d341f10cae74baabbdb3b2e329</anchor>
      <arglist>(Steinberg::FClassID s, bool askBaseClass=true) const </arglist>
    </member>
    <member kind="function">
      <type>Steinberg::tresult</type>
      <name>queryInterface</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a07585cc7a70e8ccebd48daa5b3f27e24</anchor>
      <arglist>(const Steinberg::TUID iid, void **obj)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::uint32</type>
      <name>addRef</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>aaadbfe041311eca2f8797e1bf5500471</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::uint32</type>
      <name>release</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>a2732d980d20982666c17690a2abe13ba</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Steinberg::FClassID</type>
      <name>getFClassID</name>
      <anchorfile>classSteinberg_1_1StringObject.html</anchorfile>
      <anchor>ab4fb0797983d1f5a1fcf335e4f464480</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FThread</name>
    <filename>classSteinberg_1_1FThread.html</filename>
    <member kind="function">
      <type></type>
      <name>FThread</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a466c98e2ef6d858e8cf29ed30154f46d</anchor>
      <arglist>(const char8 *name=&quot;FThread&quot;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~FThread</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a685e56861b1d5104188f5c649a16f4ce</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>run</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a13a43e6d814de94978c515cb084873b1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>terminate</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a74a45d2648335936561898c390281a6a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isRunning</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a40e5881f9c001c5cc38554084751adbc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitDead</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>adb9780a4e9f3ff814348dd27d4c87a2c</anchor>
      <arglist>(int32 timeOut)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>setPriority</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a9c11ad2e9568fc01a5afeb919f8f5c44</anchor>
      <arglist>(int32 priority)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getPriority</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a1d51fed1cc813d10ae3fbe9ba4ff0051</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>cleanup</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a4b66d5e31b5dc18b314c8a68163263bd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual uint32</type>
      <name>entry</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a38e060546eb8ad9800cbc884dd1de982</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const String &amp;</type>
      <name>getName</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>aaee0f2845288173de9f6ad47e6ad31d5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>getThreadReference</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>ae24693db8563166af86a9e4f2cd70b5b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setCpuAffinity</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>acde8f1b6d22a57e22ca949fb42b5e253</anchor>
      <arglist>(int32 cpu)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isInThreadContext</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a77b408aa0ddeea328bc665abcca249af</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>setSpy</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a5c6998482439023aa6cb99c6be7450ec</anchor>
      <arglist>(IThreadSpy *spy)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>priority</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a7b233c1672ede368db8184135452d45e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>cpu</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>aab9d07131decf6aa697ef056f51b41fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>bool</type>
      <name>running</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>a36f7b6be7108281af77939ceaec42fd6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>static IThreadSpy *</type>
      <name>gSpy</name>
      <anchorfile>classSteinberg_1_1FThread.html</anchorfile>
      <anchor>af56c36d3366ea299bea71540918b3bb8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::IThreadSpy</name>
    <filename>structSteinberg_1_1IThreadSpy.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>threadAdded</name>
      <anchorfile>structSteinberg_1_1IThreadSpy.html</anchorfile>
      <anchor>a8f1ea50458fc2e375108694ece1973a8</anchor>
      <arglist>(FThread *f)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>threadRemoved</name>
      <anchorfile>structSteinberg_1_1IThreadSpy.html</anchorfile>
      <anchor>abc220ba70e202683baf4086d993c6401</anchor>
      <arglist>(FThread *f)=0</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::ILock</name>
    <filename>structSteinberg_1_1ILock.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ILock</name>
      <anchorfile>structSteinberg_1_1ILock.html</anchorfile>
      <anchor>a0a6a52637f67bba0dc5c1469bdb8ffe3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>lock</name>
      <anchorfile>structSteinberg_1_1ILock.html</anchorfile>
      <anchor>a820f01a693f2f9a8afeb0d62061c1382</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unlock</name>
      <anchorfile>structSteinberg_1_1ILock.html</anchorfile>
      <anchor>a31262d17e02fcf1524984b10d72dee3e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>trylock</name>
      <anchorfile>structSteinberg_1_1ILock.html</anchorfile>
      <anchor>a160dc7c751dbf45484e0ecd8fb50e66d</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FLock</name>
    <filename>classSteinberg_1_1FLock.html</filename>
    <base>Steinberg::ILock</base>
    <member kind="function">
      <type></type>
      <name>FLock</name>
      <anchorfile>classSteinberg_1_1FLock.html</anchorfile>
      <anchor>a97fe91f6c76709cb4d71ecabfad4b170</anchor>
      <arglist>(const char8 *name=&quot;FLock&quot;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FLock</name>
      <anchorfile>classSteinberg_1_1FLock.html</anchorfile>
      <anchor>a11c963234a659a3f5b1930c646068a4d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>lock</name>
      <anchorfile>classSteinberg_1_1FLock.html</anchorfile>
      <anchor>aa81aed607133209dade63a226818224d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unlock</name>
      <anchorfile>classSteinberg_1_1FLock.html</anchorfile>
      <anchor>a9278be8203e1c42e2619179882ae4403</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>trylock</name>
      <anchorfile>classSteinberg_1_1FLock.html</anchorfile>
      <anchor>a79ba6f06a91dbeaa8b6086f7ccec53f7</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FLockObject</name>
    <filename>classSteinberg_1_1FLockObject.html</filename>
    <base>Steinberg::FObject</base>
    <base>Steinberg::FLock</base>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::FClassID</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1FLockObject.html</anchorfile>
      <anchor>aebd6fe798b7f779276de6a3d915584a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1FLockObject.html</anchorfile>
      <anchor>a46dce08d6692acffe85184067f428789</anchor>
      <arglist>(Steinberg::FClassID s) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isTypeOf</name>
      <anchorfile>classSteinberg_1_1FLockObject.html</anchorfile>
      <anchor>af06af9d341f10cae74baabbdb3b2e329</anchor>
      <arglist>(Steinberg::FClassID s, bool askBaseClass=true) const </arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Steinberg::FClassID</type>
      <name>getFClassID</name>
      <anchorfile>classSteinberg_1_1FLockObject.html</anchorfile>
      <anchor>ab4fb0797983d1f5a1fcf335e4f464480</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FCondition</name>
    <filename>classSteinberg_1_1FCondition.html</filename>
    <member kind="function">
      <type></type>
      <name>FCondition</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>ab58f3a521a2e714824e286f9eba31ba7</anchor>
      <arglist>(const char8 *name=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FCondition</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>acfd0660c3131ab39cc6df6d27acdc170</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>signal</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>a2a0f4bfac2f24aa0a07de86141381aec</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>signalAll</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>a3aa5209d93a4530ad365718512f920e9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>wait</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>aa3b21853f890838c88d047d6c2786917</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>waitTimeout</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>a339b50cd4a797e4f9fe753e1b50c3e73</anchor>
      <arglist>(int32 timeout=-1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchorfile>classSteinberg_1_1FCondition.html</anchorfile>
      <anchor>ad20897c5c8bd47f5d4005989bead0e55</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FRwLock</name>
    <filename>classSteinberg_1_1FRwLock.html</filename>
    <member kind="function">
      <type></type>
      <name>FRwLock</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>a8a734e8567d994055c7d3b403b8944de</anchor>
      <arglist>(const char8 *name=&quot;FRwLock&quot;, bool writerPreference=false)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FRwLock</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>ac9863cb32e530f67865967707c0b1024</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToRead</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>a73391ead11985ba50eeabfc559ae018e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneReading</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>ad25ddc7f6c296f23f3b656da5084b544</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>waitToWrite</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>ab3f0dfd5f2f49946816ee7a02b007a84</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>doneWriting</name>
      <anchorfile>classSteinberg_1_1FRwLock.html</anchorfile>
      <anchor>a2dd22e95b520182b7b52c7160d051d19</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FGuard</name>
    <filename>classSteinberg_1_1FGuard.html</filename>
    <member kind="function">
      <type></type>
      <name>FGuard</name>
      <anchorfile>classSteinberg_1_1FGuard.html</anchorfile>
      <anchor>a805e846c8f56f0871f214af31b613e39</anchor>
      <arglist>(ILock &amp;_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FGuard</name>
      <anchorfile>classSteinberg_1_1FGuard.html</anchorfile>
      <anchor>a0725ecf1da567992f659c2132522fa6b</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FConditionalGuard</name>
    <filename>classSteinberg_1_1FConditionalGuard.html</filename>
    <member kind="function">
      <type></type>
      <name>FConditionalGuard</name>
      <anchorfile>classSteinberg_1_1FConditionalGuard.html</anchorfile>
      <anchor>a21e430b048bb32da0139b8036ef7b9a5</anchor>
      <arglist>(FLock *_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FConditionalGuard</name>
      <anchorfile>classSteinberg_1_1FConditionalGuard.html</anchorfile>
      <anchor>a5f809cc3f2ab4d106e4836afeef02c14</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FConditionalReadGuard</name>
    <filename>classSteinberg_1_1FConditionalReadGuard.html</filename>
    <member kind="function">
      <type></type>
      <name>FConditionalReadGuard</name>
      <anchorfile>classSteinberg_1_1FConditionalReadGuard.html</anchorfile>
      <anchor>ac81da6b6a97fc580e91753b05b4d51dc</anchor>
      <arglist>(FRwLock *_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FConditionalReadGuard</name>
      <anchorfile>classSteinberg_1_1FConditionalReadGuard.html</anchorfile>
      <anchor>ae96f6b77eb7f31f7f79517b18e8751c4</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FConditionalWriteGuard</name>
    <filename>classSteinberg_1_1FConditionalWriteGuard.html</filename>
    <member kind="function">
      <type></type>
      <name>FConditionalWriteGuard</name>
      <anchorfile>classSteinberg_1_1FConditionalWriteGuard.html</anchorfile>
      <anchor>adbb22a7e0ce2c18533fa03acd5549ece</anchor>
      <arglist>(FRwLock *_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FConditionalWriteGuard</name>
      <anchorfile>classSteinberg_1_1FConditionalWriteGuard.html</anchorfile>
      <anchor>aac87a323504168b694f93dd7a38e4887</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FSemaphore</name>
    <filename>classSteinberg_1_1FSemaphore.html</filename>
    <member kind="function">
      <type></type>
      <name>FSemaphore</name>
      <anchorfile>classSteinberg_1_1FSemaphore.html</anchorfile>
      <anchor>a9dd76a970ace0d504c1dd0b5f415f325</anchor>
      <arglist>(int32 initialCount, const char8 *name)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FSemaphore</name>
      <anchorfile>classSteinberg_1_1FSemaphore.html</anchorfile>
      <anchor>a379fdaeae5beb3761f9e82142702109a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>verify</name>
      <anchorfile>classSteinberg_1_1FSemaphore.html</anchorfile>
      <anchor>a8af5038360da3cdd202091591ffde915</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>acquire</name>
      <anchorfile>classSteinberg_1_1FSemaphore.html</anchorfile>
      <anchor>af41148c6503c1e27b6ed87e0c27e6e35</anchor>
      <arglist>(int32 millisecondsTimeOut=-1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>release</name>
      <anchorfile>classSteinberg_1_1FSemaphore.html</anchorfile>
      <anchor>a7e33bab5521d9c1d032348258f241643</anchor>
      <arglist>(int32 count=1)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FSemaphoreGuard</name>
    <filename>classSteinberg_1_1FSemaphoreGuard.html</filename>
    <member kind="function">
      <type></type>
      <name>FSemaphoreGuard</name>
      <anchorfile>classSteinberg_1_1FSemaphoreGuard.html</anchorfile>
      <anchor>afb8dc70a845b68af552e7e1150019b56</anchor>
      <arglist>(FSemaphore &amp;s, int32 timeOut=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FSemaphoreGuard</name>
      <anchorfile>classSteinberg_1_1FSemaphoreGuard.html</anchorfile>
      <anchor>a3105e26d6fb3b1596bb63f2cc7d22d40</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FReadGuardT</name>
    <filename>classSteinberg_1_1FReadGuardT.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FReadGuardT</name>
      <anchorfile>classSteinberg_1_1FReadGuardT.html</anchorfile>
      <anchor>a5c1d86291cf610fcf1452cdbf99cba77</anchor>
      <arglist>(T &amp;_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FReadGuardT</name>
      <anchorfile>classSteinberg_1_1FReadGuardT.html</anchorfile>
      <anchor>a85e7faa089d95980ebc6ae715aa592b2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FWriteGuardT</name>
    <filename>classSteinberg_1_1FWriteGuardT.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>FWriteGuardT</name>
      <anchorfile>classSteinberg_1_1FWriteGuardT.html</anchorfile>
      <anchor>a1d622a18679dbcdea5ca8d9b029066d1</anchor>
      <arglist>(T &amp;_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FWriteGuardT</name>
      <anchorfile>classSteinberg_1_1FWriteGuardT.html</anchorfile>
      <anchor>aac5d713adc576d71714554c9a4fe38b2</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FRecursionCounter</name>
    <filename>classSteinberg_1_1FRecursionCounter.html</filename>
    <member kind="function">
      <type></type>
      <name>FRecursionCounter</name>
      <anchorfile>classSteinberg_1_1FRecursionCounter.html</anchorfile>
      <anchor>a0c3c9eb4343581c9830247db0640ebf5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>enter</name>
      <anchorfile>classSteinberg_1_1FRecursionCounter.html</anchorfile>
      <anchor>a450d15a24958fbfaf3a2a3941150428b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>leave</name>
      <anchorfile>classSteinberg_1_1FRecursionCounter.html</anchorfile>
      <anchor>afe1abdb6d5a98b8e65cf99d2eb20112c</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FRecursionGuard</name>
    <filename>classSteinberg_1_1FRecursionGuard.html</filename>
    <member kind="function">
      <type></type>
      <name>FRecursionGuard</name>
      <anchorfile>classSteinberg_1_1FRecursionGuard.html</anchorfile>
      <anchor>a4a66ed67970a72ac22c7737fcdce5cbe</anchor>
      <arglist>(FRecursionCounter &amp;_lock)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FRecursionGuard</name>
      <anchorfile>classSteinberg_1_1FRecursionGuard.html</anchorfile>
      <anchor>a430fda0d0c860ea3ad7181014023d0e7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isInRecursion</name>
      <anchorfile>classSteinberg_1_1FRecursionGuard.html</anchorfile>
      <anchor>ab61dc843c1709b3cee047546a8145297</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FLocalThreadStorage</name>
    <filename>classSteinberg_1_1FLocalThreadStorage.html</filename>
    <member kind="function">
      <type></type>
      <name>~FLocalThreadStorage</name>
      <anchorfile>classSteinberg_1_1FLocalThreadStorage.html</anchorfile>
      <anchor>a15fd1e4643efece44f6bf549d1b97f68</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setData</name>
      <anchorfile>classSteinberg_1_1FLocalThreadStorage.html</anchorfile>
      <anchor>a008c75ce243b9bc335effa698f9439d7</anchor>
      <arglist>(FUnknown *data)</arglist>
    </member>
    <member kind="function">
      <type>FUnknown *</type>
      <name>getData</name>
      <anchorfile>classSteinberg_1_1FLocalThreadStorage.html</anchorfile>
      <anchor>a2824bd46cabf76bab4c57b2a773f1bcc</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" static="yes">
      <type>static void</type>
      <name>initStates</name>
      <anchorfile>classSteinberg_1_1FLocalThreadStorage.html</anchorfile>
      <anchor>ab98355dc8e9e552eec7a7a430507bc97</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static FLocalThreadStorage *</type>
      <name>create</name>
      <anchorfile>classSteinberg_1_1FLocalThreadStorage.html</anchorfile>
      <anchor>a11e42f648a650175c6695571817945dd</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FUnknownFactory</name>
    <filename>classSteinberg_1_1FUnknownFactory.html</filename>
    <member kind="function">
      <type>IHostClasses *</type>
      <name>getHostClasses</name>
      <anchorfile>classSteinberg_1_1FUnknownFactory.html</anchorfile>
      <anchor>ae9ab0a2c838127d2a01b09d4d3b44fe7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setHostClasses</name>
      <anchorfile>classSteinberg_1_1FUnknownFactory.html</anchorfile>
      <anchor>ac7cad3ec9ef0aaf13721bf1be45a6add</anchor>
      <arglist>(IHostClasses *classes)</arglist>
    </member>
    <member kind="function">
      <type>Interface *</type>
      <name>createFUnknownClass</name>
      <anchorfile>classSteinberg_1_1FUnknownFactory.html</anchorfile>
      <anchor>a4050ebf648a9fe893480ea2b4bc98163</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void *</type>
      <name>createClass</name>
      <anchorfile>classSteinberg_1_1FUnknownFactory.html</anchorfile>
      <anchor>a1b5dbbee5c7f037e064c575573d1d473</anchor>
      <arglist>(FIDString iid)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateHostClasses</name>
      <anchorfile>classSteinberg_1_1FUnknownFactory.html</anchorfile>
      <anchor>abbb87ca771207c9445b2b0129db50dd1</anchor>
      <arglist>(FUnknown *context)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static FUnknownFactory &amp;</type>
      <name>get</name>
      <anchorfile>classSteinberg_1_1FUnknownFactory.html</anchorfile>
      <anchor>a60255e036358a7136eb76f6ec09a8360</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TArrayBase</name>
    <filename>classSteinberg_1_1TArrayBase.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TContainer</base>
    <member kind="function">
      <type></type>
      <name>TArrayBase</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a9ff00267025051ab1da97fe003bab638</anchor>
      <arglist>(int32 initSize=0, int32 delta=kDefaultDelta)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TArrayBase</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a66ef34bc4ea94414364ce07bbc59e178</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TArrayBase&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>ac7925aae665240ad2dd344d6d094065a</anchor>
      <arglist>(const TArrayBase&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>delta</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>ae92c808126581de51af394c097c8a946</anchor>
      <arglist>(int32 d)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>delta</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a2380275e8c9dfdf7002c581ae11a1e07</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>enableExponentialGroth</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a004bd98922e9d22b2f5c8bc65a9ef61f</anchor>
      <arglist>(bool state)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasExponentialGroth</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a1295482b68b3f60ffca00c8025818861</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>resize</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a0be642fd8bd54109772620acd432b5a6</anchor>
      <arglist>(int32 newSize)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>total</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a3e14bc0618d2942f538b771104268bef</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a439ff3ec772a4368701d9caed3bb913a</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a730508376cbfbb168c5e28ab0799f856</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a25e199b824d288c9546291434fc07beb</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a5df60feeaffc29039a4dc1df002bf5a8</anchor>
      <arglist>(int32 index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a9b0a5a3ad9972ab0e8eb0b54873aac6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeRange</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>aa30457cf7dfa7d94c9d9bdd136c4dd3c</anchor>
      <arglist>(int32 from, int32 to)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>at</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a80d3fb80f1e699473386b01f80c612bd</anchor>
      <arglist>(int32) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a64a15b8a7ecde0913c0e6c5907d16da8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a2f75c0547f349c25cdc6aee96b76b1b8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a51ca7f01199add32688b0d7241590aab</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a9ebeca86a63471fe63a086c64401e542</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>shouldGo</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a06c5ecd92bac0c4c6d23e921d92be11a</anchor>
      <arglist>(const T &amp;item) const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32</type>
      <name>index</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>aff946d2f3134042163c6edb271dea4de</anchor>
      <arglist>(const T &amp;item) const =0</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a3860c161481fcb66b798c06e7b52ccf9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a7511096b856e2288b3e5fd5358399387</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int32</type>
      <name>kDefaultDelta</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>ab9bc85ad3252763e47aa753751cd0dfe</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const int32</type>
      <name>kExponentialDelta</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>aa811dd9d819bf2ab4a4d0ede709cec4a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int32</type>
      <name>indexSorted</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a06439c093017cbb545529ff873dc5046</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int32</type>
      <name>indexUnsorted</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>ac0815359938b78bec5ca3e3f68080425</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int32</type>
      <name>shouldGoSorted</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a33403b938ebd25a640134d5ea65d87a2</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int32</type>
      <name>shouldGoUnsorted</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>ac44c3fa02ebf885130bb7a77acbd73c4</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>doQuickSort</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a57c7ba0400518b7f397479a71da816ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>bool</type>
      <name>doInsertAt</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>ab832111dd1b3b01987c95183ff424bbb</anchor>
      <arglist>(int32 index, const T &amp;)</arglist>
    </member>
    <member kind="function" protection="protected" static="yes">
      <type>static int</type>
      <name>cmpData</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>acad3a3a461ff57b235a20df9ca1fbb89</anchor>
      <arglist>(const void *, const void *)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>_delta</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a5566c07b716f6b62c094d159812d6298</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>_total</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>a59c916784df3701441d368b050e2b437</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>T *</type>
      <name>_entries</name>
      <anchorfile>classSteinberg_1_1TArrayBase.html</anchorfile>
      <anchor>afd7bc10249c9c53a611fdaa84d3cc766</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TArray</name>
    <filename>classSteinberg_1_1TArray.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TArrayBase</base>
    <member kind="function">
      <type></type>
      <name>TArray</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>a5c90a21d5023fca75f3de4f5bfa5eb13</anchor>
      <arglist>(int32 initSize=0, int32 delta=TArrayBase&lt; T &gt;::kDefaultDelta)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TArray</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>a8021e4f0a52ff4107b63c881a7d3d0bd</anchor>
      <arglist>(const TArray&lt; T &gt; &amp;a)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TArray</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>aff7b210d4a81198c7f0c760d1b25208b</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;c)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>a81d66ca4925505fed739d988153407ee</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>index</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>acd4430054c935f2b0a003e24c9dac327</anchor>
      <arglist>(const T &amp;t) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>shouldGo</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>ad09944b9a431ecdf7018914df9505654</anchor>
      <arglist>(const T &amp;t) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>a001f974c4c8f35be4872f0179aadbf9b</anchor>
      <arglist>(int32 index, const T &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceAt</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>a5ba86ca374437bb219a06847b848f600</anchor>
      <arglist>(int32 index, const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>quickSort</name>
      <anchorfile>classSteinberg_1_1TArray.html</anchorfile>
      <anchor>a0e4fac10110a44e8858684e5e9f6cf12</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TOrderedArray</name>
    <filename>classSteinberg_1_1TOrderedArray.html</filename>
    <templarg></templarg>
    <base>Steinberg::TArrayBase</base>
    <member kind="function">
      <type></type>
      <name>TOrderedArray</name>
      <anchorfile>classSteinberg_1_1TOrderedArray.html</anchorfile>
      <anchor>ae92bef7e1744d1aa43b812b27a649495</anchor>
      <arglist>(int32 initSize=0, int32 delta=TArrayBase&lt; T &gt;::kDefaultDelta)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TOrderedArray</name>
      <anchorfile>classSteinberg_1_1TOrderedArray.html</anchorfile>
      <anchor>a1844ea70515db7c0034066099fe88340</anchor>
      <arglist>(const TOrderedArray&lt; T &gt; &amp;a)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TOrderedArray</name>
      <anchorfile>classSteinberg_1_1TOrderedArray.html</anchorfile>
      <anchor>ac5c437e1b4ce20bd67f9d308af8fc141</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;c)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TOrderedArray.html</anchorfile>
      <anchor>a81d66ca4925505fed739d988153407ee</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>index</name>
      <anchorfile>classSteinberg_1_1TOrderedArray.html</anchorfile>
      <anchor>acd4430054c935f2b0a003e24c9dac327</anchor>
      <arglist>(const T &amp;t) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>shouldGo</name>
      <anchorfile>classSteinberg_1_1TOrderedArray.html</anchorfile>
      <anchor>ad09944b9a431ecdf7018914df9505654</anchor>
      <arglist>(const T &amp;t) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TSortableArray</name>
    <filename>classSteinberg_1_1TSortableArray.html</filename>
    <templarg></templarg>
    <base>Steinberg::TArrayBase</base>
    <member kind="function">
      <type></type>
      <name>TSortableArray</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>a3160dccf32b8b9056c09f0b9f6184b04</anchor>
      <arglist>(int32 initSize=0, int32 delta=TArrayBase&lt; T &gt;::kDefaultDelta)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TSortableArray</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>aa644b1f83afd7fbef0b531f61e1d210b</anchor>
      <arglist>(const TSortableArray&lt; T &gt; &amp;a)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TSortableArray</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>a6870b76fa4eec74967419874ea481fbe</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>enableSorting</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>ab7f08e98c505a8ecf8989c9bf25a7a20</anchor>
      <arglist>(bool state)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>sortingEnabled</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>a6f2c240f5af07f7ece104b247528bff7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>a81d66ca4925505fed739d988153407ee</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>index</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>acd4430054c935f2b0a003e24c9dac327</anchor>
      <arglist>(const T &amp;t) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>shouldGo</name>
      <anchorfile>classSteinberg_1_1TSortableArray.html</anchorfile>
      <anchor>ad09944b9a431ecdf7018914df9505654</anchor>
      <arglist>(const T &amp;t) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TArrayIterator</name>
    <filename>classSteinberg_1_1TArrayIterator.html</filename>
    <templarg></templarg>
    <base>Steinberg::TIterator</base>
    <member kind="function">
      <type></type>
      <name>TArrayIterator</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>abb8f6a64aa80575ac6851053e7816dd6</anchor>
      <arglist>(const TArrayBase&lt; T &gt; &amp;arr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>done</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>a6db83072bdb45ff66ab856903170c40d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>ae572ed60e4de48af0b9513fc69c47ef2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>a059289c65c56eb50b72c9b160431d8f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>current</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>a2c975b9b9ddd9d1cafb5b1c0f4a197cb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>a394ecb3ba8dcea0cbcc3fba8d2306ec3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>ab8ab6458b874d68a456b82dd9df83bab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const TArrayBase&lt; T &gt; &amp;</type>
      <name>array</name>
      <anchorfile>classSteinberg_1_1TArrayIterator.html</anchorfile>
      <anchor>ad6d3f2b881174057f1edbc9b31bded89</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TAssociation</name>
    <filename>classSteinberg_1_1TAssociation.html</filename>
    <templarg>T</templarg>
    <templarg>O</templarg>
    <member kind="function">
      <type></type>
      <name>TAssociation</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a043957df8414af80e0184ed0596c4524</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAssociation</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a4cdf82cfe73dcb70f9e4afdf3c31e87f</anchor>
      <arglist>(const T &amp;, const O &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAssociation</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a17d13111a384127a02eed98b4488fdd0</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAssociation</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a55c716cbd0126f904659be6292af1453</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAssociation&lt; T, O &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a0dcfe8f7f97eed7d955245ee864a7068</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a08fd8362319e8fb0dbe054ca87ed9b73</anchor>
      <arglist>(const T &amp;, const O &amp;)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>key</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>ab77c4c8730a993b4ed27533b3513d6af</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>key</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>ac61f4b6f931081482fde5145922b937c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>key</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>ae886569524350b235f9d6bd26736213a</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>O &amp;</type>
      <name>object</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a7e178072ac82c8d94de5ba3aaf3a54f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const O &amp;</type>
      <name>object</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>afe09b7afd3c5baae0bf0191e6fe1bd7c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>object</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>abbb6645ae876df3ef455d0b46941a3c8</anchor>
      <arglist>(const O &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>ac6ca7b49a8be842ca1ecdb2540739e73</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a92acf492bdaba92d63849e1bd8075f08</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a05230353449dcb53ac99dc403c9903b7</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a33ce6dea0d955656e55f7365af6a4518</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;=</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a8a84d50656bcace3948722a318530f66</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&gt;=</name>
      <anchorfile>classSteinberg_1_1TAssociation.html</anchorfile>
      <anchor>a8244e0ea22b4b54dbe822bea2af6f507</anchor>
      <arglist>(const TAssociation&lt; T, O &gt; &amp;) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TAssociationArray</name>
    <filename>classSteinberg_1_1TAssociationArray.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base protection="private">TArray&lt; TAssociation&lt; K, O &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>TAssociationArray</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>aacd1d704e5b3b18fe0f410a9a136e2a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAssociationArray&lt; K, O &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a833dfb531a884b091e57a1913bb5b109</anchor>
      <arglist>(const TAssociationArray&lt; K, O &gt; &amp;t)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a1cf7a0624ee6d704c2b9758d4f0d59a1</anchor>
      <arglist>(const K &amp;key, const O &amp;object)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>afe4f142a7f9ca7d08de6deb852b86ee3</anchor>
      <arglist>(int32 atIndex, const K &amp;key, const O &amp;object)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>aea21340b3480f32fd80ad64b54d1a6ab</anchor>
      <arglist>(const K &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>acb42c01c57901722f5d87e80182416ba</anchor>
      <arglist>(const K &amp;key, const O &amp;object)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>containsKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>af7548e70e65a5f63d653ef542085cade</anchor>
      <arglist>(const K &amp;key, const O &amp;object)</arglist>
    </member>
    <member kind="function">
      <type>O</type>
      <name>lookupObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a54fd196083de2c9049b80ef928298cde</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
    <member kind="function">
      <type>K</type>
      <name>lookupKey</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>ab30b1f4ec51476cd2ff3ae770d8ac630</anchor>
      <arglist>(const O &amp;object) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getObjectIndex</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a9c4428f9e8e3a444b4dc0b3c3418deda</anchor>
      <arglist>(const O &amp;object) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getKeyIndex</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a85d4b370cec6088a1510cf2e864480a8</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>containsKey</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a96a35cc736f118dd7a428e1e8fbd4b87</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
    <member kind="function">
      <type>K</type>
      <name>getKey</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a73abb1038143666d2dd6694bafaf7bb2</anchor>
      <arglist>(int32 index) const </arglist>
    </member>
    <member kind="function">
      <type>O</type>
      <name>getObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>a96e1f5a80a5be8dac5eb72731b48ff55</anchor>
      <arglist>(int32 index) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setKey</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>aadf1671f32c0da9b2b815464652229dc</anchor>
      <arglist>(int32 index, const K &amp;k)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setObject</name>
      <anchorfile>classSteinberg_1_1TAssociationArray.html</anchorfile>
      <anchor>ad7b66cf4aa58cdad5b69af489dfe9529</anchor>
      <arglist>(int32 index, const O &amp;o)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBag</name>
    <filename>classSteinberg_1_1TBag.html</filename>
    <templarg></templarg>
    <base>Steinberg::THashTable</base>
    <member kind="typedef">
      <type>uint32(*</type>
      <name>THashFunc</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a0cd62f156ea9d5de7efbd4868f96e665</anchor>
      <arglist>)(const T &amp;, uint32)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBag</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a75f903b584f4d32af82dce6c13574468</anchor>
      <arglist>(int32 size=10)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBag</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a0ff5d419faeee45799bd84a394f2229b</anchor>
      <arglist>(THashFunc hashFunction, int32 size=10)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBag</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a73e5a089707ff90fc5377b16bca8f779</anchor>
      <arglist>(THashTable&lt; T &gt; &amp;hashTable)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBag</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a9578783ddc1bffb3a074fff69a9195c5</anchor>
      <arglist>(THashFunc hashFunction, const TContainer&lt; T &gt; &amp;container)</arglist>
    </member>
    <member kind="function">
      <type>TBag&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a73c910ed9a09d97cd9188687176f4a8e</anchor>
      <arglist>(const THashTable&lt; T &gt; &amp;hashTable)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a3959135fcebc4b6848dbd252e56fe51d</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>af51d8b8486e16b9d5dcbff22e678c9a8</anchor>
      <arglist>(const T &amp;item, int32 numCopies)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>afe1c191d56c3efa5bb838af438ffa154</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a848278d62dcc81f8acc9626481cf9adf</anchor>
      <arglist>(const T &amp;item, int32 numCopies)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>adbcf9f6849cb71e6f4a7d47a1c810471</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a9b0a5a3ad9972ab0e8eb0b54873aac6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getCount</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a5aeb4ce0ed1700790ec682b5db3908a1</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>THashSet&lt; T &gt; *</type>
      <name>createUniqueSet</name>
      <anchorfile>classSteinberg_1_1TBag.html</anchorfile>
      <anchor>a13246ddfdd4bc830493a77083c90ba54</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBinaryTree</name>
    <filename>classSteinberg_1_1TBinaryTree.html</filename>
    <templarg></templarg>
    <base>Steinberg::TContainer</base>
    <member kind="function">
      <type></type>
      <name>TBinaryTree</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>afe8e43d89e3dcd9324f296494d6554a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBinaryTree</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>aaef9ae043e4ae564ec72186e3da129be</anchor>
      <arglist>(const TBinaryTree&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBinaryTree</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a135753eaaa03cba5f3c4dece0afcadcc</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TBinaryTree</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a808c8919d2667f15501a6e4b500861f3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a81d66ca4925505fed739d988153407ee</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>TBinaryTree&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a1a81e9cf276273e3b3e5b40fd012da63</anchor>
      <arglist>(const TBinaryTree&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>aa47b780d1570c78f92e48e035c3c5779</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>ad1bfa2b4331cf00a9f1efa853a6f1bea</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>ac95bd6a8ad444bd747aa5d1a5f9528fd</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a45a95b00e5442756bd8204b5b2a9f2b3</anchor>
      <arglist>(int32 index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a4e62c805a8478320f1e650e6a635b31a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>root</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a3ccd8e87c854604dfb42add6a9b45341</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>balance</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>aeceb989c9c8ba1acf0e2864e67351dc6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>aeee41c0ab6cfc1f0760c17ef3e37103b</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>ab3fb29d1143da9edb3c146c922e90a8b</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a7fbd7e8261755c3ac465520060b34928</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1TBinaryTree.html</anchorfile>
      <anchor>a64c84d18b820871850b97efa7b11608e</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBTree</name>
    <filename>classSteinberg_1_1TBTree.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TContainer</base>
    <member kind="function">
      <type></type>
      <name>TBTree</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a5b3d838d3aa6466c99d01c78f07ec78e</anchor>
      <arglist>(int32=3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBTree</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a33570812db943afd2742e585d363ec5e</anchor>
      <arglist>(const TBTree&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBTree</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a55dc3e402eadb4ccd1a1c53168ff7ba6</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TBTree</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a4725db16bd0261c9743388d14ca84a0a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>aabb472783fd46b065773d549539ba0f0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>TBTree&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a605b9816de5b476f813d6eaff84443c5</anchor>
      <arglist>(const TBTree&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>order</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>abe4645b317770ee613d058ccb0d53b55</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>height</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>abd9d4329c7b45ed438cb8139bce1e563</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a439ff3ec772a4368701d9caed3bb913a</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a730508376cbfbb168c5e28ab0799f856</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a25e199b824d288c9546291434fc07beb</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a3c7669c12c3f5dff6a43023e29050aa1</anchor>
      <arglist>(int32)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a9b0a5a3ad9972ab0e8eb0b54873aac6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a1904b46fb5b8a29a7ad293d0c4f5f4ae</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a9986d2e7ac55af317c987fa58aba2e21</anchor>
      <arglist>(const T &amp;, TBTreeIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>lookupLowerEqual</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a896cd92ac930a81a175f2969e242c824</anchor>
      <arglist>(const T &amp;, TBTreeIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a6316d4cad22d95539d7831f775afbf84</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>aa15e0e72a10a8a2a3d863a5edb93b17a</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>TIterator&lt; T &gt; *</type>
      <name>lookupIterator</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a459f6b874398637085758fa8e84175ec</anchor>
      <arglist>(const T &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1TBTree.html</anchorfile>
      <anchor>a9ebeca86a63471fe63a086c64401e542</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBTreeNode</name>
    <filename>classSteinberg_1_1TBTreeNode.html</filename>
    <templarg>T</templarg>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBTreeIterator</name>
    <filename>classSteinberg_1_1TBTreeIterator.html</filename>
    <templarg></templarg>
    <base>Steinberg::TIterator</base>
    <member kind="function">
      <type></type>
      <name>TBTreeIterator</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a45c7fd5cabf8e1a9170cdab4824a8dc4</anchor>
      <arglist>(const TBTree&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>done</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a6db83072bdb45ff66ab856903170c40d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>ae572ed60e4de48af0b9513fc69c47ef2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a059289c65c56eb50b72c9b160431d8f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>current</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a2c975b9b9ddd9d1cafb5b1c0f4a197cb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a394ecb3ba8dcea0cbcc3fba8d2306ec3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>ab8ab6458b874d68a456b82dd9df83bab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const TBTree&lt; T &gt; &amp;</type>
      <name>tree</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a26c640a2c4f17201606daaea88d7ac17</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>setCurrent</name>
      <anchorfile>classSteinberg_1_1TBTreeIterator.html</anchorfile>
      <anchor>a27b3a2552b582a4a14fce45ba5fd8e81</anchor>
      <arglist>(TBTreeNode&lt; T &gt; *node, int32 index2)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBTreeDictionary</name>
    <filename>classSteinberg_1_1TBTreeDictionary.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>TBTree&lt; TAssociation&lt; K, O &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>TBTreeDictionary</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>ad4d617af4e1ba287d404366378deaa9a</anchor>
      <arglist>(int32 order=3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBTreeDictionary</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a14040c2894188dd8bce00b0ddea7f7ef</anchor>
      <arglist>(const TBTreeDictionary&lt; K, O &gt; &amp;dict)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TBTreeDictionary</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>afb5a7ec5390c7a522a4a4bbe7d959469</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TBTreeDictionary&lt; K, O &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a3d24fe9cd2ae2fbf52fd33df849ea732</anchor>
      <arglist>(const TBTreeDictionary&lt; K, O &gt; &amp;dict)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKey</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a6ad5686626fd73c5aea2c82519f878ff</anchor>
      <arglist>(const K &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a1cf7a0624ee6d704c2b9758d4f0d59a1</anchor>
      <arglist>(const K &amp;key, const O &amp;object)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addAssoc</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a53ad937c2392a41984bd2eb24074e388</anchor>
      <arglist>(const TAssociation&lt; K, O &gt; &amp;assoc)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a96c68c2fbbbe4abd5d405d06bc3c25b6</anchor>
      <arglist>(const K &amp;key, const O &amp;object)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeKey</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a5139415b1e18752a4761b5a01c834579</anchor>
      <arglist>(const K &amp;key)</arglist>
    </member>
    <member kind="function">
      <type>const K &amp;</type>
      <name>lookupKey</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a5647dfbcf4f9f42176aedc7662ec2ee1</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
    <member kind="function">
      <type>const O &amp;</type>
      <name>lookupObject</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a8725a790bb1c027fb6e74898c508e666</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>containsKey</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>a96a35cc736f118dd7a428e1e8fbd4b87</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
    <member kind="function">
      <type>const TAssociation&lt; K, O &gt; &amp;</type>
      <name>lookupAssoc</name>
      <anchorfile>classSteinberg_1_1TBTreeDictionary.html</anchorfile>
      <anchor>adc8437862ec6b012d64ca9e24d10315d</anchor>
      <arglist>(const K &amp;key) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TBTreeSet</name>
    <filename>classSteinberg_1_1TBTreeSet.html</filename>
    <templarg></templarg>
    <base>Steinberg::TBTree</base>
    <member kind="function">
      <type></type>
      <name>TBTreeSet</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>a71640281eefa5396781e7381ad20d35f</anchor>
      <arglist>(int32 order=3)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBTreeSet</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>aef7db52f7a9b0b41b15212eea76ee9fa</anchor>
      <arglist>(const TBTreeSet&lt; T &gt; &amp;set)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TBTreeSet</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>a6f7dbc1601d4668f469904d4155528a4</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;container)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TBTreeSet</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>a02c69ed471a2743490b2f559169e7893</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TBTreeSet&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>a27b61b684c9467b526132fdf5e624852</anchor>
      <arglist>(const TBTreeSet&lt; T &gt; &amp;set)</arglist>
    </member>
    <member kind="function">
      <type>TBTreeSet&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>adc5784dd3d987a02776e8689497945cf</anchor>
      <arglist>(const TBTreeSet&lt; T &gt; &amp;set) const </arglist>
    </member>
    <member kind="function">
      <type>TBTreeSet&lt; T &gt;</type>
      <name>operator&amp;</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>abe3d7ce8bb7ef5679756dc56f76fa9a8</anchor>
      <arglist>(const TBTreeSet&lt; T &gt; &amp;set) const </arglist>
    </member>
    <member kind="function">
      <type>TBTreeSet&lt; T &gt;</type>
      <name>operator|</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>ab621ac8d19cc5c11f0f8d72f804adf49</anchor>
      <arglist>(const TBTreeSet&lt; T &gt; &amp;set) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TBTreeSet.html</anchorfile>
      <anchor>a3959135fcebc4b6848dbd252e56fe51d</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TContainer</name>
    <filename>classSteinberg_1_1TContainer.html</filename>
    <templarg>T</templarg>
    <member kind="function">
      <type></type>
      <name>TContainer</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a59404ad7f364d1b0ad6ece661aa21c5e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TContainer</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>aa2d7c632dbb5f85d151492cbc33880aa</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TContainer</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a4a63641c2127b4609383e015770ba0c7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a5feff0b4a480179abe18c71c2ba33fde</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a084d05756d56fbfe0ffc540ee330b9e3</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;) const </arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>ad564d980bb8746b5455909c27fa252be</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a0268cefe8c1265beeff9c8567186f496</anchor>
      <arglist>(int32) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>total</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a3e14bc0618d2942f538b771104268bef</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>size</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>ae0de3f5d4514b90b8e820a65bc8aaa0c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a3a199295546dbf397b4f7e16f1f70fc5</anchor>
      <arglist>(const T &amp;item)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>ad201beb1be0c9e716e96f605e34b907f</anchor>
      <arglist>(const T &amp;item)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>aa03390faafc424d888802198077444a0</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>adcdbec0d3b12ddc20a9598517301ea3c</anchor>
      <arglist>(int32 index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a05d9d3ac4ec18b1278a856ead91e3fc0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>at</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a4d31c181b7b77d57272b50f3be503923</anchor>
      <arglist>(int32 index) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a64a15b8a7ecde0913c0e6c5907d16da8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a2f75c0547f349c25cdc6aee96b76b1b8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a51ca7f01199add32688b0d7241590aab</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a071efd77a98f78c576ccb2464122c7f3</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function">
      <type>TContainer&lt; T &gt; *</type>
      <name>lookupAll</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>affac97043aa349a7ff92346af2d8fd9e</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addAllFrom</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>abdf1d7b1e337a48c95e9863c720cd38d</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;container)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addNewFrom</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a71da82c699643a25aa326bef86de0388</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;container)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>error</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a3b3c5a6af597e8239d5f4721946a9639</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>copy</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a7fe286f333f6f2caf60065e49bab95e7</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;container)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>T</type>
      <name>errorObject</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>a70cf89aea2a0e2488bb5c9b43a032e48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>_size</name>
      <anchorfile>classSteinberg_1_1TContainer.html</anchorfile>
      <anchor>aee81fc560e52347f3a9ff88537292be5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TIterator</name>
    <filename>classSteinberg_1_1TIterator.html</filename>
    <templarg>T</templarg>
    <member kind="function">
      <type></type>
      <name>TIterator</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a078235f26db5d2b3d381a42c105efe3f</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;cont)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TIterator</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a265a23ee3d876526a41ddbc63324aacd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool</type>
      <name>done</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a9eb31d81c63fb49a9713300dad2dc905</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>aa2e80a100481d7cb8950442b2fed1fa5</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>aff950bc19e1956238c3713d98c5c1a7e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual T &amp;</type>
      <name>current</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>ab478a90b629c2271d8f4ecdbd8811c40</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a0a7bc62db395c0b23d0c143961ab23c1</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a7e50299b7c58e0e780af5ecd4867fdfc</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>af84ecee3083942f26d475c8d6f7a643c</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a1a877be35a57009e7f6dee6bcdd000af</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>const TContainer&lt; T &gt; &amp;</type>
      <name>container</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>ab28d583460cee3cac8412c138fe95fbd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator int32</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a4971bc0b65af17f5154f7a6e568df8f1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator++</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>aa29485401da13541006709967a893818</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator++</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a589f1f489defa7a68ed00a244d9656bd</anchor>
      <arglist>(int)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>aa9c3e31a4094e95662c27851c2ad5149</anchor>
      <arglist>(int32 n)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator--</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a9ff98dddfbf0d677b76e66461d9cbe24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator--</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>acc758c6d1234b7827e244d97c72d411e</anchor>
      <arglist>(int)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator-=</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>a6af5508c763c9cd6353cea6e7b7c208c</anchor>
      <arglist>(int32)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>abe6a97573683a2a067ea982516d4da1d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const TContainer&lt; T &gt; &amp;</type>
      <name>_container</name>
      <anchorfile>classSteinberg_1_1TIterator.html</anchorfile>
      <anchor>acf598d56af757c81c61123bac237df29</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TDeque</name>
    <filename>classSteinberg_1_1TDeque.html</filename>
    <templarg></templarg>
    <base>Steinberg::TLinkedList</base>
    <member kind="function">
      <type></type>
      <name>TDeque</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>a776c4a77a7305c3d53725888a28b8b02</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TDeque</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>a09e699e6ba8eb78ddb66e3c23164fded</anchor>
      <arglist>(const TDeque&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TDeque</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>ab52d36e41089a9ec410f098e696413b8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TDeque&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>a4dfd910e4fd6d6f9131772b0d76aec90</anchor>
      <arglist>(const TDeque&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pushLeft</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>af8f16679bb4c563db16b8bc6f22f6a02</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>pushRight</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>a1f34c95fde0b367cbc9fcb81131f559a</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>popLeft</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>ab06502bdcf9b383fb99e5aa7b97e38ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>popRight</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>a3d76fb2e9a240865eaa577e60c799f23</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>peekLeft</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>af710147f0116575e646022de433b283e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>peekRight</name>
      <anchorfile>classSteinberg_1_1TDeque.html</anchorfile>
      <anchor>adf167c780405388dd6b8c23bd6149cd6</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TDictionary</name>
    <filename>classSteinberg_1_1TDictionary.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>TDLinkedList&lt; TAssociation&lt; TKey, TObject &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>TDictionary</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>af5b39b6c922fbadaf420598ba7f2d279</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TDictionary</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a8e4e1dbafd551da6e9be50269c093770</anchor>
      <arglist>(const TKey &amp;errKey, const TObject &amp;errObj)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TDictionary</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a3306977a4aec8056a72482f009ad95b0</anchor>
      <arglist>(const TDictionary&lt; TKey, TObject &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TDictionary</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a57f314d34f3b6b455037260c4726afa5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TDictionary&lt; TKey, TObject &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a4a9d8a3b2f7316ed4c855e4bd40cfb07</anchor>
      <arglist>(const TDictionary&lt; TKey, TObject &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKey</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a200a46f65bde84cc3c29598a6a1acd6f</anchor>
      <arglist>(const TKey &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKeyAndObject</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a0ced88f430eaf7aec1ea255eeaedc83d</anchor>
      <arglist>(const TKey &amp;, const TObject &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addAssoc</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>ab0c03f7dcdf0cf17b67fd1e713972f5f</anchor>
      <arglist>(const TAssociation&lt; TKey, TObject &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>ae7c0c0729a82e0e36fff2f4c13a3aa63</anchor>
      <arglist>(const TKey &amp;, const TObject &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeKey</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a93980006e2151a92f88524b934eff514</anchor>
      <arglist>(const TKey &amp;)</arglist>
    </member>
    <member kind="function">
      <type>const TKey &amp;</type>
      <name>lookupKey</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a1cc73db4f14df210d3e9c48a3956b14c</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>const TObject &amp;</type>
      <name>lookupObject</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a65bc5a819bc4216b13e35b207ac4c6de</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>containsKey</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a77d12ec2782870f49782516b89b9b0fe</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>occurrencesOfKey</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a1d2b9c4e5392d87cfe65b3a361edd85c</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>const TAssociation&lt; TKey, TObject &gt; &amp;</type>
      <name>lookupAssoc</name>
      <anchorfile>classSteinberg_1_1TDictionary.html</anchorfile>
      <anchor>a9aaf5ce8d02c5f654ff0f751da10634c</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TDictionaryIterator</name>
    <filename>classSteinberg_1_1TDictionaryIterator.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>TDLinkedListIterator&lt; TAssociation&lt; TKey, TObject &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>TDictionaryIterator</name>
      <anchorfile>classSteinberg_1_1TDictionaryIterator.html</anchorfile>
      <anchor>ad8e10e354910c426172b87b23f8df4d1</anchor>
      <arglist>(const TDictionary&lt; TKey, TObject &gt; &amp;dict)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashDictionary</name>
    <filename>classSteinberg_1_1THashDictionary.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>THashTable&lt; TAssociation&lt; TKey, TObject &gt; &gt;</base>
    <member kind="typedef">
      <type>uint32(*</type>
      <name>THashFunc</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a5d3109f8dcd36b4bb391c06857d76de0</anchor>
      <arglist>)(const TAssociation&lt; TKey, TObject &gt; &amp;, uint32)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashDictionary</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>aab5bec4ba9a453e3fe2d631bc64bacea</anchor>
      <arglist>(THashFunc hashFunc, int32=10)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashDictionary</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a2357b07489803f8be391eb381de17fc8</anchor>
      <arglist>(const THashDictionary&lt; TKey, TObject &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~THashDictionary</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a48a3ad176c0209a53df65b77b5410eb3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>THashDictionary&lt; TKey, TObject &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a43067ac08b7b4239cd17f8f630a6a54c</anchor>
      <arglist>(const THashDictionary&lt; TKey, TObject &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKey</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a200a46f65bde84cc3c29598a6a1acd6f</anchor>
      <arglist>(const TKey &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addKeyAndObject</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a0ced88f430eaf7aec1ea255eeaedc83d</anchor>
      <arglist>(const TKey &amp;, const TObject &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>addAssoc</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>ab0c03f7dcdf0cf17b67fd1e713972f5f</anchor>
      <arglist>(const TAssociation&lt; TKey, TObject &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replace</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>ae7c0c0729a82e0e36fff2f4c13a3aa63</anchor>
      <arglist>(const TKey &amp;, const TObject &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>removeKey</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a93980006e2151a92f88524b934eff514</anchor>
      <arglist>(const TKey &amp;)</arglist>
    </member>
    <member kind="function">
      <type>const TKey &amp;</type>
      <name>lookupKey</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a1cc73db4f14df210d3e9c48a3956b14c</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>const TObject &amp;</type>
      <name>lookupObject</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a65bc5a819bc4216b13e35b207ac4c6de</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>containsKey</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a77d12ec2782870f49782516b89b9b0fe</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>occurrencesOfKey</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a1d2b9c4e5392d87cfe65b3a361edd85c</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>const TAssociation&lt; TKey, TObject &gt; &amp;</type>
      <name>lookupAssoc</name>
      <anchorfile>classSteinberg_1_1THashDictionary.html</anchorfile>
      <anchor>a9aaf5ce8d02c5f654ff0f751da10634c</anchor>
      <arglist>(const TKey &amp;) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashDictionaryIterator</name>
    <filename>classSteinberg_1_1THashDictionaryIterator.html</filename>
    <templarg></templarg>
    <templarg></templarg>
    <base>THashTableIterator&lt; TAssociation&lt; TKey, TObject &gt; &gt;</base>
    <member kind="function">
      <type></type>
      <name>THashDictionaryIterator</name>
      <anchorfile>classSteinberg_1_1THashDictionaryIterator.html</anchorfile>
      <anchor>a6687d23c6900ca0726d05573972ebfb5</anchor>
      <arglist>(const THashDictionary&lt; TKey, TObject &gt; &amp;dict)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TDLinkedList</name>
    <filename>classSteinberg_1_1TDLinkedList.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TContainer</base>
    <class kind="struct">Steinberg::TDLinkedList::TDLink</class>
    <member kind="function">
      <type></type>
      <name>TDLinkedList</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>ac2dfdc5a8217ce2b82b3dd9b4dfb4727</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TDLinkedList</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a5eb45efcd57b3ccb88c6ed94135d4df8</anchor>
      <arglist>(const TDLinkedList&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TDLinkedList</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>ace4195acb91f09061917721b0245fbf4</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TDLinkedList</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a90610be2640aac8836db617ee2d29262</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TDLinkedList&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a7c423cae63f2fddbe78a545b40e35638</anchor>
      <arglist>(const TDLinkedList&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>aabb472783fd46b065773d549539ba0f0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a3959135fcebc4b6848dbd252e56fe51d</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a7157034b4aa94bfab8313035471e962b</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prepend</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a7c5b3728c53b7eb63414a43c89102921</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a70ef9fe33146448a1c9d8ea01ee0fd73</anchor>
      <arglist>(int32 index, const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceAt</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a5ba86ca374437bb219a06847b848f600</anchor>
      <arglist>(int32 index, const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>afe1c191d56c3efa5bb838af438ffa154</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a25e199b824d288c9546291434fc07beb</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a5df60feeaffc29039a4dc1df002bf5a8</anchor>
      <arglist>(int32 index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a9b0a5a3ad9972ab0e8eb0b54873aac6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>removeFirst</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a2cc5cfd1a4619aa97164089bbada2864</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>removeLast</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a0320e164c37ff1df9f9311231d75e5a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertAfter</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a17ca2c885b4879edb346d77635ca10f4</anchor>
      <arglist>(const T &amp;after, const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertBefore</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>ae15e0d086155ec01f7455ee0dbbd91da</anchor>
      <arglist>(const T &amp;before, const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a30a82c2584c175f15cc8049d7607d0af</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a046d3bf1c5bdab8dfa3173c5e71e685f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>index</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a6b4ee5ddc5a2726865ed3878e5375426</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>at</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a4d31c181b7b77d57272b50f3be503923</anchor>
      <arglist>(int32 index) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a64a15b8a7ecde0913c0e6c5907d16da8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a2f75c0547f349c25cdc6aee96b76b1b8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a51ca7f01199add32688b0d7241590aab</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1TDLinkedList.html</anchorfile>
      <anchor>a9ebeca86a63471fe63a086c64401e542</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TDLinkedListIterator</name>
    <filename>classSteinberg_1_1TDLinkedListIterator.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TIterator</base>
    <member kind="function">
      <type></type>
      <name>TDLinkedListIterator</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>a6d49fdbd8e682d2f89b773f824ff5441</anchor>
      <arglist>(const TDLinkedList&lt; T &gt; &amp;list)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>done</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>a6db83072bdb45ff66ab856903170c40d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>ae572ed60e4de48af0b9513fc69c47ef2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>a059289c65c56eb50b72c9b160431d8f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>current</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>a2c975b9b9ddd9d1cafb5b1c0f4a197cb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>a394ecb3ba8dcea0cbcc3fba8d2306ec3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>ab8ab6458b874d68a456b82dd9df83bab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const TDLinkedList&lt; T &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classSteinberg_1_1TDLinkedListIterator.html</anchorfile>
      <anchor>a58a613d3bb938f912885ed234f86be8a</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashSet</name>
    <filename>classSteinberg_1_1THashSet.html</filename>
    <templarg></templarg>
    <base>Steinberg::THashTable</base>
    <member kind="typedef">
      <type>uint32(*</type>
      <name>THashFunc</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a0cd62f156ea9d5de7efbd4868f96e665</anchor>
      <arglist>)(const T &amp;, uint32)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashSet</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a68b1281ade975528a937e6adfc2fbc31</anchor>
      <arglist>(int32=10)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashSet</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a240fcb436862c603ad0c1467468c400d</anchor>
      <arglist>(THashFunc, int32=10)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashSet</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a0516038dae18439081ee560c91501e3c</anchor>
      <arglist>(const THashSet&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashSet</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a6fee6b218bf25348705f4205d87d9b0b</anchor>
      <arglist>(THashFunc, const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~THashSet</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a3e92ea335f9d59bb14cdf67c6497d737</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>THashSet&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a31bedb98a59714fc691f990738845686</anchor>
      <arglist>(const THashTable&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>THashSet&lt; T &gt;</type>
      <name>operator-</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a057cf6be1701d2dafae36f090944f781</anchor>
      <arglist>(const THashSet&lt; T &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>THashSet&lt; T &gt;</type>
      <name>operator&amp;</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a3892bd1b1244c6c57b09f61653a6fb06</anchor>
      <arglist>(const THashSet&lt; T &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>THashSet&lt; T &gt;</type>
      <name>operator|</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a695f2495c6330f2a56a1594fc5cfee63</anchor>
      <arglist>(const THashSet&lt; T &gt; &amp;) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1THashSet.html</anchorfile>
      <anchor>a439ff3ec772a4368701d9caed3bb913a</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashTable</name>
    <filename>classSteinberg_1_1THashTable.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TContainer</base>
    <member kind="typedef">
      <type>uint32(*</type>
      <name>THashFunc</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a0cd62f156ea9d5de7efbd4868f96e665</anchor>
      <arglist>)(const T &amp;, uint32)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashTable</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a6047bf307a37108a86efabde2b0d1724</anchor>
      <arglist>(THashFunc, int32=10)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashTable</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>aad88b895ab1c60e1f9ddf6f2d61c8887</anchor>
      <arglist>(const THashTable&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>THashTable</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>ae5b7a56ed75d562a770db839d04fcaae</anchor>
      <arglist>(THashFunc, const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~THashTable</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a4a91809281c6e7e7631874b807b14dca</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>THashTable&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a76927822a294c51550be849218f193bc</anchor>
      <arglist>(const THashTable&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setHashFunction</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a1f6f9bc1308657476c981a20b09c2c54</anchor>
      <arglist>(THashFunc)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>resize</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a97865a81f6183b7ea5cd0ec6c3651957</anchor>
      <arglist>(int32)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>aabb472783fd46b065773d549539ba0f0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>total</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a3e14bc0618d2942f538b771104268bef</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a3959135fcebc4b6848dbd252e56fe51d</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>afe1c191d56c3efa5bb838af438ffa154</anchor>
      <arglist>(const T &amp;item)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a15f6f76c4a01884c9d1dc6f34f919ca6</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;iter)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a5df60feeaffc29039a4dc1df002bf5a8</anchor>
      <arglist>(int32 index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a9b0a5a3ad9972ab0e8eb0b54873aac6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a64a15b8a7ecde0913c0e6c5907d16da8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a2f75c0547f349c25cdc6aee96b76b1b8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a51ca7f01199add32688b0d7241590aab</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1THashTable.html</anchorfile>
      <anchor>a9ebeca86a63471fe63a086c64401e542</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashBucket</name>
    <filename>classSteinberg_1_1THashBucket.html</filename>
    <templarg>T</templarg>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashNode</name>
    <filename>classSteinberg_1_1THashNode.html</filename>
    <templarg>T</templarg>
  </compound>
  <compound kind="class">
    <name>Steinberg::THashTableIterator</name>
    <filename>classSteinberg_1_1THashTableIterator.html</filename>
    <templarg>T</templarg>
    <base>Steinberg::TIterator</base>
    <member kind="function">
      <type></type>
      <name>THashTableIterator</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>a0a78587fc6c5bb8b713f022d1f5f7a6e</anchor>
      <arglist>(const THashTable&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>done</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>a6db83072bdb45ff66ab856903170c40d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>ae572ed60e4de48af0b9513fc69c47ef2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>a059289c65c56eb50b72c9b160431d8f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>current</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>a2c975b9b9ddd9d1cafb5b1c0f4a197cb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>a394ecb3ba8dcea0cbcc3fba8d2306ec3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>ab8ab6458b874d68a456b82dd9df83bab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const THashTable&lt; T &gt; &amp;</type>
      <name>table</name>
      <anchorfile>classSteinberg_1_1THashTableIterator.html</anchorfile>
      <anchor>a0f258d6b5960a4bcd06601b18e49b361</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ITimerCallback</name>
    <filename>classSteinberg_1_1ITimerCallback.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ITimerCallback</name>
      <anchorfile>classSteinberg_1_1ITimerCallback.html</anchorfile>
      <anchor>af00a1cccbd3849f94399eb9ddb8367b1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>onTimer</name>
      <anchorfile>classSteinberg_1_1ITimerCallback.html</anchorfile>
      <anchor>a99358b05e5917c71cb033737c57bed49</anchor>
      <arglist>(Timer *timer)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Timer</name>
    <filename>classSteinberg_1_1Timer.html</filename>
    <base>Steinberg::FObject</base>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>stop</name>
      <anchorfile>classSteinberg_1_1Timer.html</anchorfile>
      <anchor>a0efff8623a2fb79dad94a96dcf16d966</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Timer *</type>
      <name>create</name>
      <anchorfile>classSteinberg_1_1Timer.html</anchorfile>
      <anchor>a65d64aa9a45908da2c3b8c6dfffa00b0</anchor>
      <arglist>(ITimerCallback *callback, uint32 intervalMilliseconds)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::DisableDispatchingTimers</name>
    <filename>classSteinberg_1_1DisableDispatchingTimers.html</filename>
    <member kind="function">
      <type></type>
      <name>DisableDispatchingTimers</name>
      <anchorfile>classSteinberg_1_1DisableDispatchingTimers.html</anchorfile>
      <anchor>a59be662c23adc93f540b980f63e5c446</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DisableDispatchingTimers</name>
      <anchorfile>classSteinberg_1_1DisableDispatchingTimers.html</anchorfile>
      <anchor>ac20207d5c81a874be61fcb9621104a0d</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TLinkedList</name>
    <filename>classSteinberg_1_1TLinkedList.html</filename>
    <templarg></templarg>
    <base>Steinberg::TContainer</base>
    <class kind="struct">Steinberg::TLinkedList::TLink</class>
    <member kind="function">
      <type></type>
      <name>TLinkedList</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a8811da63ff20be46992cce690b91641f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TLinkedList</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a85bd41e38acac800c7655b95da123afe</anchor>
      <arglist>(const TLinkedList&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TLinkedList</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a24758a62708a556539ac37b021cce26e</anchor>
      <arglist>(const TContainer&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TLinkedList</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a317a3c5c92affb71749977ecd519caac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TContainer&lt; T &gt; *</type>
      <name>newInstance</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>aabb472783fd46b065773d549539ba0f0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>TLinkedList&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>afe0f64fcbd3045e338adbbf4814764da</anchor>
      <arglist>(const TLinkedList&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>add</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a439ff3ec772a4368701d9caed3bb913a</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a049a64652d180d479500bc3a4d4e0db8</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>prepend</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a8ff35e921f8199bb6015d3462c0c2f04</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertAt</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a2af6d430ace441599f469119b205adf0</anchor>
      <arglist>(int32 index, const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>replaceAt</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a0089072df8534b8e4be9b40eebd151a8</anchor>
      <arglist>(int32 index, const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a730508376cbfbb168c5e28ab0799f856</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a25e199b824d288c9546291434fc07beb</anchor>
      <arglist>(const TIterator&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>removeAt</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a3c7669c12c3f5dff6a43023e29050aa1</anchor>
      <arglist>(int32)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>removeAll</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a9b0a5a3ad9972ab0e8eb0b54873aac6b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>removeFirst</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a2cc5cfd1a4619aa97164089bbada2864</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>removeLast</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a0320e164c37ff1df9f9311231d75e5a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertAfter</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>af1c072ccafe8836d28817d04f7697836</anchor>
      <arglist>(const T &amp;after, const T &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>insertBefore</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a3ca678378182db1018d02c5bff90ce8e</anchor>
      <arglist>(const T &amp;before, const T &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a30a82c2584c175f15cc8049d7607d0af</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a046d3bf1c5bdab8dfa3173c5e71e685f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>index</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a6b4ee5ddc5a2726865ed3878e5375426</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>at</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a4d31c181b7b77d57272b50f3be503923</anchor>
      <arglist>(int32 index) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>lookup</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a64a15b8a7ecde0913c0e6c5907d16da8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>contains</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a2f75c0547f349c25cdc6aee96b76b1b8</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int32</type>
      <name>occurrences</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a51ca7f01199add32688b0d7241590aab</anchor>
      <arglist>(const T &amp;item) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TIterator&lt; T &gt; *</type>
      <name>newIterator</name>
      <anchorfile>classSteinberg_1_1TLinkedList.html</anchorfile>
      <anchor>a9ebeca86a63471fe63a086c64401e542</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TLinkedListIterator</name>
    <filename>classSteinberg_1_1TLinkedListIterator.html</filename>
    <templarg></templarg>
    <base>Steinberg::TIterator</base>
    <member kind="function">
      <type></type>
      <name>TLinkedListIterator</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>af19f0512dfc0fce97ffb873fc32e2ce1</anchor>
      <arglist>(const TLinkedList&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>done</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>a6db83072bdb45ff66ab856903170c40d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>next</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>ae572ed60e4de48af0b9513fc69c47ef2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>previous</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>a059289c65c56eb50b72c9b160431d8f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual T &amp;</type>
      <name>current</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>a2c975b9b9ddd9d1cafb5b1c0f4a197cb</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>first</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>a394ecb3ba8dcea0cbcc3fba8d2306ec3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>last</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>ab8ab6458b874d68a456b82dd9df83bab</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const TLinkedList&lt; T &gt; &amp;</type>
      <name>list</name>
      <anchorfile>classSteinberg_1_1TLinkedListIterator.html</anchorfile>
      <anchor>aa4de4a2bebccc22bdeccbeebc7700689</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TQueue</name>
    <filename>classSteinberg_1_1TQueue.html</filename>
    <templarg></templarg>
    <base>Steinberg::TLinkedList</base>
    <member kind="function">
      <type></type>
      <name>TQueue</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>ab6552bc2117f0d61f9ca590fb0fbd054</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TQueue</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>ac3dcba9aad4de293b6af26f7e92489ba</anchor>
      <arglist>(const TQueue&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TQueue</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>a65b04e825ae487211ea607e26afafceb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TQueue&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>a3fb9a96a139f5661cc8d57ca8124f85e</anchor>
      <arglist>(const TQueue&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>enqueue</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>af9344e312601b4f2cfdea8c71f6612f2</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>dequeue</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>ad219b7947b6c6b7f3cd9d5d6c76d0f2f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>peek</name>
      <anchorfile>classSteinberg_1_1TQueue.html</anchorfile>
      <anchor>a40e8a77a93ae4f3872f51e94a57d571a</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TRingBuffer</name>
    <filename>classSteinberg_1_1TRingBuffer.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>TRingBuffer</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a5160b8503b03543135f9d82e07d57b5a</anchor>
      <arglist>(int32 n=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TRingBuffer</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a54907b7aec24051b99750dbb16171b75</anchor>
      <arglist>(T *data, int32 n)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TRingBuffer</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>ad8f47463ec473bf68e7ea7e22e1c1520</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>setBuffer</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a630307adf654b0be1250004ef49417e2</anchor>
      <arglist>(T *data, int32 n)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>resize</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a1f2eb65f0fa33deae6f8fc03969c8eab</anchor>
      <arglist>(int32 n)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countFree</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>ade644585cbcd74b0320bd5cb2009b387</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>countFilled</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a0a5eb4be9d24bfadf00222d0400c77b6</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>size</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>ae0de3f5d4514b90b8e820a65bc8aaa0c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>write</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a8f59b2d9ee258eeb28bbcd0a4071ee6c</anchor>
      <arglist>(const T *data)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>write</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a2bf728fa343f5b8fbf34d38766f0c00f</anchor>
      <arglist>(const T *data, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>write</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a1b8a32b23f5973510e2186ec96ce94ee</anchor>
      <arglist>(const T &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>read</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a65bc4b8d9753377474cfbf01147759d8</anchor>
      <arglist>(T *data, int32 count)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>read</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a6d13d5ba12e1bf31c48324b5459fca51</anchor>
      <arglist>(T &amp;data)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>peek</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a726e918864bab95f5eafd050bd1bb053</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>peek</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>aa7a1b14931a786857d608720f5b97179</anchor>
      <arglist>(T *data, int32 count) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>flush</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>adac116554b543b7c4228c018a85882f5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>trash</name>
      <anchorfile>classSteinberg_1_1TRingBuffer.html</anchorfile>
      <anchor>a0f16b5f4bfdb1a27793d64e01e23da7c</anchor>
      <arglist>(int32 count)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TStack</name>
    <filename>classSteinberg_1_1TStack.html</filename>
    <templarg></templarg>
    <base>Steinberg::TLinkedList</base>
    <member kind="function">
      <type></type>
      <name>TStack</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>aa6fcc7ab78b7b0cb8059a088a0d7ed43</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TStack</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>ab33160da5fb6371645abd0e7f2a47606</anchor>
      <arglist>(const TStack&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TStack</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>ac01f1c73161c55b9000e43d668bbba4d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TStack&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>a49acbb4d676a8c335e3e7e3e509cd5a8</anchor>
      <arglist>(const TStack&lt; T &gt; &amp;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>push</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>a90b45f68481b4779e69e98c49bb4fd34</anchor>
      <arglist>(const T &amp;)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>pop</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>ad702374ab51a03308e76cc7305f42582</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>peek</name>
      <anchorfile>classSteinberg_1_1TStack.html</anchorfile>
      <anchor>a726e918864bab95f5eafd050bd1bb053</anchor>
      <arglist>() const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::TVector</name>
    <filename>classSteinberg_1_1TVector.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>TVector</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a35173dc44fc5e7ed6ff99b776761b7f9</anchor>
      <arglist>(int32 size=0, const T *items=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TVector</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a752856f0b37a2fae6823420dd1058d26</anchor>
      <arglist>(int32 size, const T &amp;item)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TVector</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a51518b8ca9836a9622d1267c1793a4c4</anchor>
      <arglist>(const TVector&lt; T &gt; &amp;otherVector)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TVector</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a4f6db7027e899293a01b21bf15340cbc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>ac5a84a83b35447e32ab4cd1378bc8e73</anchor>
      <arglist>(const TVector&lt; T &gt; &amp;otherVector)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>operator+=</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a2cff042faf3fc4f6b976d4ebb7ecf3d8</anchor>
      <arglist>(const TVector&lt; T &gt; &amp;otherVector)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt;</type>
      <name>operator+</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a4501211c2e66ae89aebed443df62e530</anchor>
      <arglist>(const TVector&lt; T &gt; &amp;otherVector) const </arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>adfd19c533c2123be58afcdd1c3caa6a5</anchor>
      <arglist>(int32 idx)</arglist>
    </member>
    <member kind="function">
      <type>T &amp;</type>
      <name>at</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>ae76480513eeaa66e4466f2003049e6ca</anchor>
      <arglist>(int32 idx)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a808d0a6e9bc2c9140d55f6682e845f65</anchor>
      <arglist>(int32 idx, int32 size) const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>size</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>ae0de3f5d4514b90b8e820a65bc8aaa0c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const T *</type>
      <name>array</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a52b26969d605e04890755d3cc3ef58b8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>acbf179c9a4ea046cc4d5388ea85df1bb</anchor>
      <arglist>(const T *items, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>ad5476017916a6d386748525fc8b3926d</anchor>
      <arglist>(const T &amp;item, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a819e1c510a77bc600f5bef47267044cd</anchor>
      <arglist>(const T *items, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a4fb9da98f38251cb7ab29ab10b5211c8</anchor>
      <arglist>(const T &amp;item, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>insert</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a62766d8cdcfd89dc87172417a1a4ff16</anchor>
      <arglist>(int32 idx, const TVector&lt; T &gt; &amp;otherVector)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>insert</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a536eaddb43ec60f1864ad70295167c7b</anchor>
      <arglist>(int32 idx, const T *items, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>insert</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>aea82533c42b39f328c3a1b510f450907</anchor>
      <arglist>(int32 idx, const T &amp;item, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt; &amp;</type>
      <name>remove</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a9be8c4a7ceb074fef433e28d2152a89a</anchor>
      <arglist>(int32 idx, int32 size=1)</arglist>
    </member>
    <member kind="function">
      <type>TVector&lt; T &gt;</type>
      <name>subVector</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a5a3399311490663d6a010689508f2cae</anchor>
      <arglist>(int32 idx, int32 size) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>ac8bb3912a3ce86b15842e79d0b421204</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>resize</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a722aff9bec64ecb2cfd7ed005fa97b62</anchor>
      <arglist>(int32 size)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>grow</name>
      <anchorfile>classSteinberg_1_1TVector.html</anchorfile>
      <anchor>a1678ed50ddaed55228e790c7cd534f88</anchor>
      <arglist>(int32 minSize, int32 delta=-1)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IUpdateManager</name>
    <filename>classSteinberg_1_1IUpdateManager.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>cancelUpdates</name>
      <anchorfile>classSteinberg_1_1IUpdateManager.html</anchorfile>
      <anchor>a1a25afc436e4a6a71ea723fb87dd5e17</anchor>
      <arglist>(FUnknown *object)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult</type>
      <name>triggerDeferedUpdates</name>
      <anchorfile>classSteinberg_1_1IUpdateManager.html</anchorfile>
      <anchor>a47fd80f102481477faa93ed170a7f7f9</anchor>
      <arglist>(FUnknown *object=0)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IUpdateManager.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::UpdateHandler</name>
    <filename>classSteinberg_1_1UpdateHandler.html</filename>
    <base>Steinberg::FObject</base>
    <base>Steinberg::IUpdateManager</base>
    <member kind="function">
      <type></type>
      <name>UpdateHandler</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a5cb070dc5b6e125ca7dd0f609a266f0b</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~UpdateHandler</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>ab3416815aefc3484de55b14892ae73dd</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>addDependent</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>ae8cc85f106ff04fd5e5801393b1a3cf6</anchor>
      <arglist>(FUnknown *object, IDependent *dependent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>removeDependent</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a3fedf2f7566cbf09a6ccf35f2da95609</anchor>
      <arglist>(FUnknown *object, IDependent *dependent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>triggerUpdates</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a40ab61aee33901fbc1538faa77cddcbb</anchor>
      <arglist>(FUnknown *object, int32 message)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>deferUpdates</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>ae8512e3b7d993cd3175cedaa534b778d</anchor>
      <arglist>(FUnknown *object, int32 message)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>cancelUpdates</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>ae81bcf6b0a787b89900f19c2099397e3</anchor>
      <arglist>(FUnknown *object)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual tresult</type>
      <name>triggerDeferedUpdates</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a2a320f861716a66fd0eecbebbae21317</anchor>
      <arglist>(FUnknown *object=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::FClassID</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>aebd6fe798b7f779276de6a3d915584a5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isA</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a46dce08d6692acffe85184067f428789</anchor>
      <arglist>(Steinberg::FClassID s) const </arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual bool</type>
      <name>isTypeOf</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>af06af9d341f10cae74baabbdb3b2e329</anchor>
      <arglist>(Steinberg::FClassID s, bool askBaseClass=true) const </arglist>
    </member>
    <member kind="function">
      <type>Steinberg::tresult</type>
      <name>queryInterface</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a07585cc7a70e8ccebd48daa5b3f27e24</anchor>
      <arglist>(const Steinberg::TUID iid, void **obj)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::uint32</type>
      <name>addRef</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>aaadbfe041311eca2f8797e1bf5500471</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Steinberg::uint32</type>
      <name>release</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a2732d980d20982666c17690a2abe13ba</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Steinberg::FClassID</type>
      <name>getFClassID</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>ab4fb0797983d1f5a1fcf335e4f464480</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static UpdateHandler *</type>
      <name>instance</name>
      <anchorfile>classSteinberg_1_1UpdateHandler.html</anchorfile>
      <anchor>a4473ab1e4c6953fde427bf63f1a338a5</anchor>
      <arglist>(bool create=true)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::CommandLine</name>
    <filename>namespaceSteinberg_1_1CommandLine.html</filename>
    <class kind="class">Steinberg::CommandLine::VariablesMap</class>
    <class kind="class">Steinberg::CommandLine::Description</class>
    <class kind="class">Steinberg::CommandLine::Descriptions</class>
    <member kind="typedef">
      <type>std::vector&lt; std::string &gt;</type>
      <name>FilesVector</name>
      <anchorfile>namespaceSteinberg_1_1CommandLine.html</anchorfile>
      <anchor>ada2a5cd694be1a12f043c986d6e24803</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>parse</name>
      <anchorfile>namespaceSteinberg_1_1CommandLine.html</anchorfile>
      <anchor>a620ed44558399aa89cd3203045114c89</anchor>
      <arglist>(int ac, char *av[], const Descriptions &amp;desc, VariablesMap &amp;result, FilesVector *files=0)</arglist>
    </member>
    <member kind="function">
      <type>std::ostream &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>namespaceSteinberg_1_1CommandLine.html</anchorfile>
      <anchor>a6a38965238a994bf87587aac0b83a5be</anchor>
      <arglist>(std::ostream &amp;os, const Descriptions &amp;desc)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::CommandLine::VariablesMap</name>
    <filename>classSteinberg_1_1CommandLine_1_1VariablesMap.html</filename>
    <member kind="function">
      <type></type>
      <name>VariablesMap</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1VariablesMap.html</anchorfile>
      <anchor>abd055542f549cbbfbf227f22f49f3295</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>hasError</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1VariablesMap.html</anchorfile>
      <anchor>a94df1eb3588ee1df5f590817d48553b5</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setError</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1VariablesMap.html</anchorfile>
      <anchor>a4f9dcc805975eb9dcf2579cd3886091e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>std::string &amp;</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1VariablesMap.html</anchorfile>
      <anchor>a6ec5f288dc5570a8d3be7e1dad3a1f8d</anchor>
      <arglist>(const VariablesMapContainer::key_type k)</arglist>
    </member>
    <member kind="function">
      <type>const std::string &amp;</type>
      <name>operator[]</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1VariablesMap.html</anchorfile>
      <anchor>a55d19fd881d8cb63db3c49d4d9691425</anchor>
      <arglist>(const VariablesMapContainer::key_type k) const </arglist>
    </member>
    <member kind="function">
      <type>VariablesMapContainer::size_type</type>
      <name>count</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1VariablesMap.html</anchorfile>
      <anchor>afb7655963db9a7c2d91d1216ccbb3e26</anchor>
      <arglist>(const VariablesMapContainer::key_type k) const </arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::CommandLine::Description</name>
    <filename>classSteinberg_1_1CommandLine_1_1Description.html</filename>
    <member kind="function">
      <type></type>
      <name>Description</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Description.html</anchorfile>
      <anchor>ad22e14e4e415962ac43d552ed282c9fc</anchor>
      <arglist>(const std::string &amp;name, const std::string &amp;help, const std::string &amp;valueType)</arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>mHelp</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Description.html</anchorfile>
      <anchor>aec239d2835b6febb1c0c7096896f4ee7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>std::string</type>
      <name>mType</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Description.html</anchorfile>
      <anchor>a3437227e441ef7e6d2b63197b26023ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kBool</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Description.html</anchorfile>
      <anchor>a2d50e9061f301e53c3dd5d51ed45b92b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const std::string</type>
      <name>kString</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Description.html</anchorfile>
      <anchor>a8cd538caaf9f8e5e8a721c6efd58e75f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::CommandLine::Descriptions</name>
    <filename>classSteinberg_1_1CommandLine_1_1Descriptions.html</filename>
    <member kind="function">
      <type>Descriptions &amp;</type>
      <name>addOptions</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Descriptions.html</anchorfile>
      <anchor>a81879d1223ae544bd1b70993d09f7291</anchor>
      <arglist>(const std::string &amp;caption=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>parse</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Descriptions.html</anchorfile>
      <anchor>a01211aa5c3c666ed49da40954d2cd4e3</anchor>
      <arglist>(int ac, char *av[], VariablesMap &amp;result, FilesVector *files=0) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Descriptions.html</anchorfile>
      <anchor>aa230a2d18799b9cd3d177081b4a843d1</anchor>
      <arglist>(std::ostream &amp;os) const </arglist>
    </member>
    <member kind="function">
      <type>Descriptions &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Descriptions.html</anchorfile>
      <anchor>ac88217d791c334de62e8f01564ccae24</anchor>
      <arglist>(const std::string &amp;name, const std::string &amp;help)</arglist>
    </member>
    <member kind="function">
      <type>Descriptions &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Descriptions.html</anchorfile>
      <anchor>a04068b49b3684a0e56e8c059fa6029c1</anchor>
      <arglist>(const std::string &amp;name, const Type &amp;inType, std::string help)</arglist>
    </member>
    <member kind="function">
      <type>Descriptions &amp;</type>
      <name>operator()</name>
      <anchorfile>classSteinberg_1_1CommandLine_1_1Descriptions.html</anchorfile>
      <anchor>aca56440e94817a63ab39aee4f16591ec</anchor>
      <arglist>(const std::string &amp;name, const std::string &amp;inType, std::string help)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::FPanicAssert</name>
    <filename>namespaceSteinberg_1_1FPanicAssert.html</filename>
    <member kind="typedef">
      <type>void(*</type>
      <name>PANIC_FUNC</name>
      <anchorfile>namespaceSteinberg_1_1FPanicAssert.html</anchorfile>
      <anchor>ac6f1befc1b6dca867d7b014492799131</anchor>
      <arglist>)(int32 code)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPanicHook</name>
      <anchorfile>namespaceSteinberg_1_1FPanicAssert.html</anchorfile>
      <anchor>a3203e0fe6b98563ef3aaf1cabc1280d1</anchor>
      <arglist>(PANIC_FUNC newPanicHook)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>panic</name>
      <anchorfile>namespaceSteinberg_1_1FPanicAssert.html</anchorfile>
      <anchor>a34cf34c5ab9282e581609733723ff6fd</anchor>
      <arglist>(int32 code)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::HexBinary</name>
    <filename>namespaceSteinberg_1_1HexBinary.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>decode</name>
      <anchorfile>namespaceSteinberg_1_1HexBinary.html</anchorfile>
      <anchor>a567d62615b1d9ccab3b175b4b9fc61f0</anchor>
      <arglist>(const void *input, int32 inputSize, Buffer &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>encode</name>
      <anchorfile>namespaceSteinberg_1_1HexBinary.html</anchorfile>
      <anchor>a409cabd0268ae39045fe68f7816a06af</anchor>
      <arglist>(const void *input, int32 inputSize, Buffer &amp;result)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Meta</name>
    <filename>namespaceSteinberg_1_1Meta.html</filename>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::MetaClasses</name>
    <filename>namespaceSteinberg_1_1MetaClasses.html</filename>
    <member kind="function">
      <type>uint32</type>
      <name>hashByName</name>
      <anchorfile>namespaceSteinberg_1_1MetaClasses.html</anchorfile>
      <anchor>aa36d57d2425cf2320163c4139c59a763</anchor>
      <arglist>(const SorterByName &amp;s, uint32 m)</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>hashByCID</name>
      <anchorfile>namespaceSteinberg_1_1MetaClasses.html</anchorfile>
      <anchor>af7ac2e96cfdbaf215cc0340b3f558dfa</anchor>
      <arglist>(const SorterByCID &amp;s, uint32 m)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Performance</name>
    <filename>namespaceSteinberg_1_1Performance.html</filename>
    <class kind="class">Steinberg::Performance::Mode</class>
    <member kind="typedef">
      <type>enum Steinberg::Performance::_AVRT_PRIORITY</type>
      <name>AVRT_PRIORITY</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>aab7ffd9aef3aea93c2118af7463a5346</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>enum Steinberg::Performance::_AVRT_PRIORITY *</type>
      <name>PAVRT_PRIORITY</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>a8783330040ce351d3984a8ecd302552d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>_AVRT_PRIORITY</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_LOW</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a82f37aa1743cab1c69da7d5ff49d6a8a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_NORMAL</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a9ddb04ddf34535472b8f54f043d3a652</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_HIGH</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a3d1e82a3e67940c08fff4233d7ec928f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AVRT_PRIORITY_CRITICAL</name>
      <anchorfile>namespaceSteinberg_1_1Performance.html</anchorfile>
      <anchor>add7d79439251a024ba77c19ad515b8f6a9868458188819915b729402bfa060ba2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::Performance::Mode</name>
    <filename>classSteinberg_1_1Performance_1_1Mode.html</filename>
    <member kind="function">
      <type></type>
      <name>Mode</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>aac4e1e06f7bfc7293167496108220a9c</anchor>
      <arglist>(bool windowsEnable, bool macEnable, bool critical, const char *avrtThreadCharacteristics, _AVRT_PRIORITY threadPriority, uint32 expectedWindowsThreadPriority)</arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>windowsEnable</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>adca261e3c983fcded5f05ebd18995015</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>macEnable</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>a53ac34843f50686b71ae92e54742f817</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>critical</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>a6c78147dd870c0fe7beeb39cfe9812a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const char *</type>
      <name>avrtThreadCharacteristics</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>a00604b16388613baf51673aad4e032df</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>_AVRT_PRIORITY</type>
      <name>threadPriority</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>a72d388f6ec5f1fce581ba05fef5b054b</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>expectedWindowsThreadPriority</name>
      <anchorfile>classSteinberg_1_1Performance_1_1Mode.html</anchorfile>
      <anchor>a1b07a00efa388f2072d394f395e5fc9e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::Singleton</name>
    <filename>namespaceSteinberg_1_1Singleton.html</filename>
    <member kind="function">
      <type>bool</type>
      <name>isTerminated</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a84acfabb69fd8f78cc6afad4301357b7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>lockRegister</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a1612cf2b7b00489ee4cd0af7999ff7ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unlockRegister</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a2aad80bf0469cb9153a7666f2b2b4817</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>registerInstance</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ad6e6c857d3abf9d8ef37ef8d465c9977</anchor>
      <arglist>(FObject **o)</arglist>
    </member>
    <member kind="variable">
      <type>TArray&lt; FObject ** &gt; *</type>
      <name>singletonInstances</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ac26b4464420aabba88684fe40d11edff</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>bool</type>
      <name>singletonsTerminated</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ae52f18a708ab305abe54c48ffc1c9840</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>FLock *</type>
      <name>singletonsLock</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>a29266b1d4111658632fadb4ef9b57b23</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>struct Steinberg::Singleton::Deleter</type>
      <name>deleter</name>
      <anchorfile>namespaceSteinberg_1_1Singleton.html</anchorfile>
      <anchor>ad6199b16f89340fdc59b661207d8ae40</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::StringMethods</name>
    <filename>namespaceSteinberg_1_1StringMethods.html</filename>
    <namespace>Steinberg::StringMethods::Detail</namespace>
    <member kind="function">
      <type>bool</type>
      <name>parseVersionString</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods.html</anchorfile>
      <anchor>a7f6e8b98fa44d2679fa6941a216961b7</anchor>
      <arglist>(const ConstString &amp;string, int32 &amp;major, int32 &amp;sub, int32 &amp;release)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>split</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods.html</anchorfile>
      <anchor>a35f4f5cf5fb596c8397fe265fbd2d5c7</anchor>
      <arglist>(const ConstString &amp;string, const ConstString &amp;separatorString, TContainer&lt; String &gt; &amp;result)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tsplit</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods.html</anchorfile>
      <anchor>ac4f527ba056a1ce2c6fbab16304d02f0</anchor>
      <arglist>(const ConstString &amp;string, const ConstString &amp;separatorString, Structure &amp;result)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::StringMethods::Detail</name>
    <filename>namespaceSteinberg_1_1StringMethods_1_1Detail.html</filename>
    <member kind="function">
      <type>void</type>
      <name>doSplit</name>
      <anchorfile>namespaceSteinberg_1_1StringMethods_1_1Detail.html</anchorfile>
      <anchor>a808022834ff91954daef97b53362d962</anchor>
      <arglist>(const ConstString &amp;string, const ConstString &amp;separatorString, Structure &amp;result)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::SystemTime</name>
    <filename>namespaceSteinberg_1_1SystemTime.html</filename>
    <member kind="function">
      <type>int32</type>
      <name>getTicks</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>ae994ceba61021313d4200996d46787f5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint64</type>
      <name>getTicks64</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>a758d89b702e93eb7d4acd84bf1c99c4a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint64</type>
      <name>getTicksDuration</name>
      <anchorfile>namespaceSteinberg_1_1SystemTime.html</anchorfile>
      <anchor>a5eb6e497830d117c9591a9d18faa3816</anchor>
      <arglist>(uint64 old, uint64 now)</arglist>
    </member>
  </compound>
</tagfile>
