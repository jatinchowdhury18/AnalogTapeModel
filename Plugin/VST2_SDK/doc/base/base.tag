<?xml version='1.0' encoding='ISO-8859-1' standalone='yes' ?>
<tagfile>
  <compound kind="page">
    <name>index</name>
    <title>VST Module Architecture</title>
    <filename>index</filename>
    <docanchor file="index">funknown</docanchor>
    <docanchor file="index">piInterfaces</docanchor>
    <docanchor file="index">piVstMa</docanchor>
    <docanchor file="index">Categories</docanchor>
    <docanchor file="index">backward</docanchor>
    <docanchor file="index">plugunicode</docanchor>
    <docanchor file="index">piPlugins</docanchor>
    <docanchor file="index">Unicode</docanchor>
    <docanchor file="index">basic</docanchor>
    <docanchor file="index">direction</docanchor>
    <docanchor file="index">migrating</docanchor>
    <docanchor file="index">Locations</docanchor>
    <docanchor file="index">purpose</docanchor>
    <docanchor file="index">version</docanchor>
    <docanchor file="index">IPluginBase</docanchor>
    <docanchor file="index">module</docanchor>
    <docanchor file="index">com</docanchor>
    <docanchor file="index">helper</docanchor>
    <docanchor file="index">iid</docanchor>
  </compound>
  <compound kind="file">
    <name>conststringtable.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>conststringtable_8cpp</filename>
    <includes id="conststringtable_8cpp" name="conststringtable.cpp" local="yes" imported="no">conststringtable.h</includes>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>conststringtable.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>conststringtable_8h</filename>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">ftypes.h</includes>
    <class kind="class">Steinberg::ConstStringTable</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>doc.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>doc_8h</filename>
  </compound>
  <compound kind="file">
    <name>falignpop.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>falignpop_8h</filename>
  </compound>
  <compound kind="file">
    <name>falignpush.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>falignpush_8h</filename>
  </compound>
  <compound kind="file">
    <name>fplatform.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>fplatform_8h</filename>
    <member kind="define">
      <type>#define</type>
      <name>kLittleEndian</name>
      <anchorfile>fplatform_8h.html</anchorfile>
      <anchor>abfa3c6c92ac4ce1ce65133b421fee2fe</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>kBigEndian</name>
      <anchorfile>fplatform_8h.html</anchorfile>
      <anchor>a59154ea8599c8d0e7187be1c42889675</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fstrdefs.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>fstrdefs_8h</filename>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">ftypes.h</includes>
    <includes id="conststringtable_8h" name="conststringtable.h" local="yes" imported="no">conststringtable.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>STR16</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>a826c07705e0d6242387611986d74ee48</anchor>
      <arglist>(x)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>STR</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>a18d295a837ac71add5578860b55e5502</anchor>
      <arglist>(x)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>tStrBufferSize</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>a237b89af6a40bef74dff5b5e67efae92</anchor>
      <arglist>(buffer)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>str8BufferSize</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>aa2da887b221541aae95dc720e91f1563</anchor>
      <arglist>(buffer)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>str16BufferSize</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>ab60e7beaa39f0257d103524ccbb7aa9e</anchor>
      <arglist>(buffer)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FORMAT_INT64</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>a6fc06c408b7c51eb867462d2733051a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FORMAT_UINT64</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>ad76e8f81482f416ef999fa817c37d1d9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ENDLINE</name>
      <anchorfile>fstrdefs_8h.html</anchorfile>
      <anchor>a1f1b098f673669db04b6f4aa6a8fdc8e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>_tstrlen</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0f20517a819515665c6fbd35ece5a434</anchor>
      <arglist>(const T *wcs)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrlen</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a51fad7b4c1e3dfa032d4f638ecd68c7a</anchor>
      <arglist>(const char *str)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strlen8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a350bed0883f4792e7535252b3122dd5b</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strlen16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aae116b01b47bca8e67679337ef48d8d3</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>_tstrcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7023958e09487e98aaa402f6b4665212</anchor>
      <arglist>(const T *src, const T *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2f01ef81ad1c686ebb34a97ef4e2d098</anchor>
      <arglist>(const char *src, const char *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a90dd0a8f52813eb453f60ac1c49559bc</anchor>
      <arglist>(const char8 *src, const char8 *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9b47c8ef5ed96ca9034e87624f69b890</anchor>
      <arglist>(const char16 *src, const char16 *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmpT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a578edc38568fcccf2bbec8705f3c689d</anchor>
      <arglist>(const T *first, const T *last)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmpT&lt; char8 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8fcbc514f3212361e41daf160256a3e2</anchor>
      <arglist>(const char8 *first, const char8 *last)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmpT&lt; char16 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad6478b52a8c36d263b0f163eb04636af</anchor>
      <arglist>(const char16 *first, const char16 *last)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>_tstrncmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9472c661ae9df487057d848006bd12b1</anchor>
      <arglist>(const T *first, const T *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrncmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a25694d169804ad218b221f3e101eaee4</anchor>
      <arglist>(const char *first, const char *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8f3cca9e30bb739b30be3eca6b891c8f</anchor>
      <arglist>(const char8 *first, const char8 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a54115da13293d44eaae9ba44a4fa82e2</anchor>
      <arglist>(const char16 *first, const char16 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmpT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a415c030bc6c3e9c718a2a52fc812dbd7</anchor>
      <arglist>(const T *first, const T *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmpT&lt; char8 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a03f447e8dc074eadadbdf83d42a88bc0</anchor>
      <arglist>(const char8 *first, const char8 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmpT&lt; char16 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a95e46377021d0a18bbf3dcbb527334ac</anchor>
      <arglist>(const char16 *first, const char16 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>_tstrcpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0ed99e5e2d595d1fbb46be4af6bad16e</anchor>
      <arglist>(T *dst, const T *src)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>tstrcpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a406cfbdd4e67843189e729a50a22c952</anchor>
      <arglist>(char *dst, const char *src)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>strcpy8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa12723f519b8ecf7d99b4067b6f44344</anchor>
      <arglist>(char8 *dst, const char8 *src)</arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>strcpy16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a32880d14cc3ac2196ddd0859e4fb7bd6</anchor>
      <arglist>(char16 *dst, const char16 *src)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>_tstrncpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78d52df38c5128a70f98c9b832853ed9</anchor>
      <arglist>(T *dest, const T *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>tstrncpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae8ecddebc9de1d21e16eb0929574959a</anchor>
      <arglist>(char *dest, const char *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>strncpy8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6d93eaadf6a7fa89aa51c5ee8cdae132</anchor>
      <arglist>(char8 *dest, const char8 *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>strncpy16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a71e109979dde381bbba56500bbde60e8</anchor>
      <arglist>(char16 *dest, const char16 *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>_tstrcat</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a71213f60ea53751e1460a66919e526f4</anchor>
      <arglist>(T *dst, const T *src)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>tstrcat</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a64e0b47b3f8b466e2cb815d6662298e0</anchor>
      <arglist>(char *dst, const char *src)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>strcat8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac632cd3fa4f20541cabfb27d20ad2581</anchor>
      <arglist>(char8 *dst, const char8 *src)</arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>strcat16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a90f489c9a479d8c86d651dbe97f6f74f</anchor>
      <arglist>(char16 *dst, const char16 *src)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>str8ToStr16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a43172f2a5d34fc811021a16d1a38434d</anchor>
      <arglist>(char16 *dst, const char8 *src, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FIDStringsEqual</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae609f786a23774a473851d3eddaa22ff</anchor>
      <arglist>(FIDString id1, FIDString id2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ftypes.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ftypes_8h</filename>
    <includes id="fplatform_8h" name="fplatform.h" local="yes" imported="no">fplatform.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>UNICODE</name>
      <anchorfile>ftypes_8h.html</anchorfile>
      <anchor>a09ecca53f2cd1b8d1c566bedb245e141</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SWAP_32</name>
      <anchorfile>ftypes_8h.html</anchorfile>
      <anchor>ad0de6cd6cef290e9609feccdf002f51c</anchor>
      <arglist>(l)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SWAP_16</name>
      <anchorfile>ftypes_8h.html</anchorfile>
      <anchor>a178e2230dac3adf497d06c6f42abccad</anchor>
      <arglist>(w)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SWAP_64</name>
      <anchorfile>ftypes_8h.html</anchorfile>
      <anchor>ae7ff9262ec2cb91d49035bffbea62625</anchor>
      <arglist>(i)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SMTG_ALWAYS_INLINE</name>
      <anchorfile>ftypes_8h.html</anchorfile>
      <anchor>a3df4ece706682a504fa3d08c3b0a04a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>SMTG_NEVER_INLINE</name>
      <anchorfile>ftypes_8h.html</anchorfile>
      <anchor>af946828d11bb0aed103fac1d14b4b1b8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char</type>
      <name>int8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae47c588f3ab8c61121c1c7ab7edc47cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char</type>
      <name>uint8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adde6aaee8457bee49c2a92621fe22b79</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char</type>
      <name>uchar</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a65f85814a8290f9797005d3b28e7e5fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>short</type>
      <name>int16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4355d16fcf9f644c9ac84293f0b1801f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned short</type>
      <name>uint16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a05f6b0ae8f6a6e135b0e290c25fe0e4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>long</type>
      <name>int32</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4ca2d97e571b049be6f4cdcfaa1ab946</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long</type>
      <name>uint32</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4b435a49c74bb91f284f075e63416cb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>long long</type>
      <name>int64</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aecfc3c54bd29ad5964e1c1c3ccbf89df</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long long</type>
      <name>uint64</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a29940ae63ec06c9998bba873e25407ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>TSize</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>abc5a03f91bd781b5062f4fccaa7851f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>tresult</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a902761e005a6252e538c766de48fc957</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>TPtrInt</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1c25ab481e482aafa3e751e3d2ada928</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint8</type>
      <name>TBool</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1ea8addd740f35d207a1569dd38ef895</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char</type>
      <name>char8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac9e1c0f508ae0f5f8a2b704a91e1ae86</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16</type>
      <name>char16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad12e102dc50c08aa3136349a56e76fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char8</type>
      <name>char</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ada0030c3b477e12fa91f25eba5aa383f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>CStringA</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a435992556581fbc31a9bddb3bb2f787a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char16 *</type>
      <name>CStringW</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a81b4df0e8189d2f135f25919a6a90be2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char *</type>
      <name>CString</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6f37e0dbf8faed21d2658800d9db4583</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>FIDString</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad4c02134d1ee42389f3d94717935a1d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>UCoord</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>abf33a8b245f4634965116e9c25eb702a</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>strEmpty</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6df75d455350d4aaadc70786730f11fa</anchor>
      <arglist>(const char *str)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>str8Empty</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a107fdab7d7c86e4f5191a27005a6bbc3</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>str16Empty</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a51822113d808dc2e0594f7f1c61fa823</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformStringWin</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2ae80314db54c6bda33e1cf922effb47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformStringMac</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad5ffc071fd688ac833b5283777037278</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformStringIOS</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0e747a3b854268949a75a1c8e8fd070c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>funknown.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>funknown_8cpp</filename>
    <includes id="funknown_8cpp" name="funknown.cpp" local="yes" imported="no">funknown.h</includes>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">pluginterfaces/base/ftypes.h</includes>
    <includes id="smartpointer_8h" name="smartpointer.h" local="yes" imported="no">pluginterfaces/base/smartpointer.h</includes>
    <includes id="conststringtable_8h" name="conststringtable.h" local="yes" imported="no">conststringtable.h</includes>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::FUnknownPrivate</namespace>
    <member kind="function">
      <type>int32 PLUGIN_API</type>
      <name>atomicAdd</name>
      <anchorfile>namespaceSteinberg_1_1FUnknownPrivate.html</anchorfile>
      <anchor>ab48fd194b9633076ed1912cde5aeac46</anchor>
      <arglist>(int32 &amp;var, int32 d)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>funknown.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>funknown_8h</filename>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">pluginterfaces/base/ftypes.h</includes>
    <includes id="smartpointer_8h" name="smartpointer.h" local="yes" imported="no">pluginterfaces/base/smartpointer.h</includes>
    <class kind="class">Steinberg::FUID</class>
    <class kind="class">Steinberg::FUnknown</class>
    <class kind="class">Steinberg::FUnknownPtr</class>
    <class kind="struct">Steinberg::FReleaser</class>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::FUnknownPrivate</namespace>
    <member kind="define">
      <type>#define</type>
      <name>INLINE_UID</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a8024fad3ea7ecdd1ab3221d15e04aa52</anchor>
      <arglist>(l1, l2, l3, l4)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DECLARE_UID</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a5e349c26a022f90b3562eeb32976e6ed</anchor>
      <arglist>(name, l1, l2, l3, l4)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>EXTERN_UID</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a845c8fdb88f7f23c4060134a798a1e7d</anchor>
      <arglist>(name)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DECLARE_CLASS_IID</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>aae92a855975a91bb846f6e0f906745f1</anchor>
      <arglist>(ClassName, l1, l2, l3, l4)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DEF_CLASS_IID</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a8999be9dadfd41e1f563866e01e94d1c</anchor>
      <arglist>(ClassName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>INLINE_UID_OF</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>aaf419cd3f56488ae59cd1b9c8397377b</anchor>
      <arglist>(ClassName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>INLINE_UID_FROM_FUID</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>ae43645513f5c72529a3fb6c6d1e76b46</anchor>
      <arglist>(x)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DECLARE_FUNKNOWN_METHODS</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>acb6e5cc5e226c37c1fca4f5192fb80a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>DELEGATE_REFCOUNT</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a6d9d411a27dcc158df8ff1f5e73510d0</anchor>
      <arglist>(ClassName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMPLEMENT_REFCOUNT</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>ae3db5eac4c75b5199dcdc4462b6289aa</anchor>
      <arglist>(ClassName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FUNKNOWN_CTOR</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a2e898abff4a673feaa52f7ed20a42e50</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>FUNKNOWN_DTOR</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>ac31390eb834d3acfda3d871db3f9f959</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>QUERY_INTERFACE</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a1884893f6b75952d6e29bcd333f3ea40</anchor>
      <arglist>(iid, obj, InterfaceIID, InterfaceName)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMPLEMENT_QUERYINTERFACE</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a023a5c16eb6b8a0057d712343f9d752c</anchor>
      <arglist>(ClassName, InterfaceName, ClassIID)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>IMPLEMENT_FUNKNOWN_METHODS</name>
      <anchorfile>funknown_8h.html</anchorfile>
      <anchor>a3131ec3273dc17d39bef17154309b893</anchor>
      <arglist>(ClassName, InterfaceName, ClassIID)</arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>LARGE_INT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9cd1730908299276af7bc0baa8c5197e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int8</type>
      <name>TUID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a32680add5f0b1c8a81e5b1c4cfe6a30c</anchor>
      <arglist>[16]</arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoInterface</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba21f2c8af375a407ff9fb8d10e8e73a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kResultOk</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba941549edbe23d0f21851403ae03ad4df</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kResultTrue</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba9e60fad4624bee040985edebe1800372</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kResultFalse</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bab954d2583eb15d3a762c5df29270f483</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInvalidArgument</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bace91375677eb541c1a70e7ecd95f5698</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNotImplemented</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba598e4c5d4c234c1bf09367d64487519c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInternalError</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba3b287aa91111dd8aedf4bbf363e01525</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNotInitialized</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba1216e3377e943f8898e78c63422924aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOutOfMemory</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bac43d80137687fc5c1c4b60dc77202283</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>SMTG_ALWAYS_INLINE bool</type>
      <name>iidEqual</name>
      <anchorfile>namespaceSteinberg_1_1FUnknownPrivate.html</anchorfile>
      <anchor>aa492cc7f50f5f6bfb7bd727a115e211e</anchor>
      <arglist>(const void *iid1, const void *iid2)</arglist>
    </member>
    <member kind="function">
      <type>int32 PLUGIN_API</type>
      <name>atomicAdd</name>
      <anchorfile>namespaceSteinberg_1_1FUnknownPrivate.html</anchorfile>
      <anchor>ab48fd194b9633076ed1912cde5aeac46</anchor>
      <arglist>(int32 &amp;var, int32 d)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>futils.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>futils_8h</filename>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>const T &amp;</type>
      <name>Min</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adcde5fff9b5074d3e36fc411ee865dd9</anchor>
      <arglist>(const T &amp;a, const T &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>Max</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa4b9f4d937d8d865a8bfa86e6e392505</anchor>
      <arglist>(const T &amp;a, const T &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Abs</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>acbbd1cb9aa59aaa62572519d5e381549</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Sign</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8f0cb0def093b54ebe00691604f5a09b</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Bound</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a91ac21e99d77a7471db59984466167bb</anchor>
      <arglist>(T minval, T maxval, T x)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Swap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5d8f1525e15b2c83643fc473d75b6c19</anchor>
      <arglist>(T &amp;t1, T &amp;t2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsApproximateEqual</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa350c13f3025cc69274e38bbc39b5907</anchor>
      <arglist>(T t1, T t2, T epsilon)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>fvariant.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>fvariant_8h</filename>
    <includes id="fstrdefs_8h" name="fstrdefs.h" local="yes" imported="no">pluginterfaces/base/fstrdefs.h</includes>
    <class kind="class">Steinberg::FVariant</class>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2978443758ec8594b15872123119363a</anchor>
      <arglist>(const FVariant &amp;v1, const FVariant &amp;v2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa3bb730da3e8dd39c4b324d057e430c4</anchor>
      <arglist>(const FVariant &amp;v1, const FVariant &amp;v2)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>geoconstants.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>geoconstants_8h</filename>
    <namespace>Steinberg</namespace>
    <namespace>Steinberg::GeoConstants</namespace>
    <member kind="enumeration">
      <name>Direction</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNorth</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa89c5f7af4c1a4fe20ab7524369050200</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNorthEast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa80a10c4928ef7af3ce487d381e2420d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa37d01669db016bc15ed6fdab6fb6c790</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSouthEast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaadf50c366ce2690678d0e6290f52b4639</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSouth</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa515c12ec206b53ce5da86a402b3f4cf8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSouthWest</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa6a77137c947ac754a97274617a22afb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kWest</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa45b705ff067984bfd99c234d91386792</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNorthWest</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaaa67fc18f8f8b0ba3b792b46a1fa0c872</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoDirection</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa87e054da76bada3343762974c988e80a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumberOfDirections</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaabdba6353397f1b1654328de91f17e348</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>Orientation</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kHorizontal</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58ad4149164ae4bf90011d92a3dbfcce742</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVertical</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58a4764485d9d221af213bf2b2769cdfc54</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumberOfOrientations</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58a231632c3d1e6d53428167283534f1abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>Direction</type>
      <name>toOpposite</name>
      <anchorfile>namespaceSteinberg_1_1GeoConstants.html</anchorfile>
      <anchor>aff2eb279b5ae69049a3283a004a0fce2</anchor>
      <arglist>(Direction dir)</arglist>
    </member>
    <member kind="function">
      <type>Orientation</type>
      <name>toOrientation</name>
      <anchorfile>namespaceSteinberg_1_1GeoConstants.html</anchorfile>
      <anchor>a94f8ae4df9a9950ee4332d29456d12e9</anchor>
      <arglist>(Direction dir)</arglist>
    </member>
    <member kind="function">
      <type>Orientation</type>
      <name>toOrthogonalOrientation</name>
      <anchorfile>namespaceSteinberg_1_1GeoConstants.html</anchorfile>
      <anchor>a1f7b523a922afe5e4fc87ecc6dfd2a7d</anchor>
      <arglist>(Orientation dir)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ibstream.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ibstream_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">funknown.h</includes>
    <class kind="class">Steinberg::IBStream</class>
    <class kind="class">Steinberg::ISizeableStream</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>icloneable.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>icloneable_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">funknown.h</includes>
    <class kind="class">Steinberg::ICloneable</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>ierrorcontext.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ierrorcontext_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">pluginterfaces/base/funknown.h</includes>
    <class kind="class">Steinberg::IErrorContext</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>ipersistent.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ipersistent_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">pluginterfaces/base/funknown.h</includes>
    <class kind="class">Steinberg::IPersistent</class>
    <class kind="class">Steinberg::IAttributes</class>
    <class kind="class">Steinberg::IAttributes2</class>
    <namespace>Steinberg</namespace>
    <member kind="typedef">
      <type>FIDString</type>
      <name>IAttrID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae6eacc17e4382538d4af0d9993bc869a</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ipluginbase.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ipluginbase_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">funknown.h</includes>
    <includes id="fstrdefs_8h" name="fstrdefs.h" local="yes" imported="no">fstrdefs.h</includes>
    <class kind="class">Steinberg::IPluginBase</class>
    <class kind="struct">Steinberg::PFactoryInfo</class>
    <class kind="struct">Steinberg::PClassInfo</class>
    <class kind="class">Steinberg::IPluginFactory</class>
    <class kind="struct">Steinberg::PClassInfo2</class>
    <class kind="class">Steinberg::IPluginFactory2</class>
    <class kind="struct">Steinberg::PClassInfoW</class>
    <class kind="class">Steinberg::IPluginFactory3</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>LICENCE_UID</name>
      <anchorfile>ipluginbase_8h.html</anchorfile>
      <anchor>a15eabd5eb49e5ec7c8e2f6210f53ffdc</anchor>
      <arglist>(l1, l2, l3, l4)</arglist>
    </member>
    <member kind="typedef">
      <type>Steinberg::IPluginFactory *PLUGIN_API *</type>
      <name>GetFactoryProc</name>
      <anchorfile>ipluginbase_8h.html</anchorfile>
      <anchor>a4f0dff0358bb467bc24891afa07cdfc7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Steinberg::IPluginFactory *PLUGIN_API</type>
      <name>GetPluginFactory</name>
      <anchorfile>group__pluginBase.html</anchorfile>
      <anchor>gae1c930f4bfb3f7b08df00fb107c06091</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>iplugview.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/gui/</path>
    <filename>iplugview_8h</filename>
    <class kind="struct">Steinberg::ViewRect</class>
    <class kind="class">Steinberg::IPlugView</class>
    <class kind="class">Steinberg::IPlugFrame</class>
    <namespace>Steinberg</namespace>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeHWND</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>gaa1e68ac1f25da9c85c937d0360dbc601</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeHIView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga974cabea219cb31ad8218ba15d1f7071</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeNSView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga8ce69944b5475d65206469b9ebcbf755</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeUIView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga6362a7ca65b87d30c561dac986b757bd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>istringresult.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>istringresult_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">pluginterfaces/base/funknown.h</includes>
    <class kind="class">Steinberg::IStringResult</class>
    <class kind="class">Steinberg::IString</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>iupdatehandler.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>iupdatehandler_8h</filename>
    <includes id="funknown_8h" name="funknown.h" local="yes" imported="no">pluginterfaces/base/funknown.h</includes>
    <class kind="class">Steinberg::IUpdateHandler</class>
    <class kind="class">Steinberg::IDependent</class>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>keycodes.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>keycodes_8h</filename>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">pluginterfaces/base/ftypes.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="enumeration">
      <name>VirtualKeyCodes</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_BACK</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba363a5589e96b18dca6534e951baffdd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_TAB</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba60c75f9c8eded88ef76c0c94da27963c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_CLEAR</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baee7181a798c5753153051c0e1ace41c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_RETURN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baaefd064b1e5d75c429bed314ac18eba0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PAUSE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad26d172dc2cd90741c3939ca4fab0b84</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ESCAPE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba3a471c8b61a5f730dcbdd50fe53f3ab7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SPACE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba01d2889f9a7550008ad6140c41e733de</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NEXT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba82d61b2ebb1c5fee25aea8d69d325acc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_END</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa8adb6fcb92dec58fb19410eacfdd403</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_HOME</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad5b83418c285e43af5d3a87b4d4049d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_LEFT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba612120b69c7dfd46086db7aaebdbcf65</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_UP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba0848a442d907968b211b97bc2bd88acd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_RIGHT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6504370d9c6391e1a9da6a1a529b089d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DOWN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa9cdac7967bf7d88fdb761138a2a3416</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PAGEUP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba5d9c9ba1d8f2c6f6737db37d3f449071</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PAGEDOWN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba5996c34d86df2b3c1be741aeb35bdbc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SELECT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba3b37a163628bc7015aac5efab4a66ef5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PRINT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf6ff54b9651ca18045e4000c2d26f790</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ENTER</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba2a662d23aadd7106a3a2afdfd5d426ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SNAPSHOT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bacc39d60a35433541177dbd7bf01a8257</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_INSERT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba26f2c18a3a0a7eabf7bd11f0ec93be78</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DELETE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bae7a3a4540031b038014294aa6743a7a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_HELP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad729e81b40a3acb64b5a40b7fa459b09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD0</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba55aef83f557c4ed24e2847d38ea292b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD1</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba681b5574363c5d5a463af7e514172292</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD2</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba779490ca3da209736187a912cd8382dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD3</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bae58753ec4558e7b68f4aa07ed97d50d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD4</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba744226502b73227ed219a5142c232126</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD5</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba906fbf3011cae4b931d6fe6126147a82</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD6</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bac4e7f0a72c3594aa3d5b83f61b714e3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD7</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bae6d134db5bf54ae1d4b29f8a2cca8889</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba258d226c87d8446423d3214a59eb498b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD9</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6ab9d27201ffbdccabde9f5a0e9dedd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MULTIPLY</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa7ccd4f6c9a10fe36e0e7bd28d15bea3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ADD</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba88535ed64ae437ce31620dcb62c66c9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SEPARATOR</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba79459423b8bbe9f70949f464cd7a27ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SUBTRACT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf6ba424919235c2cbbac7184e3625395</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DECIMAL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bafce663586a7e53223158c5f4ce6033fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DIVIDE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba36a890023ae628d5c36ca010edffc59c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F1</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bafcf70bc39c0032de8a1c6452ac9860a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F2</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba87897fd25282941e1a9bf72b9f64559a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F3</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba965c99b1f4fc05cec09ef61b0af8e74a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F4</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba01bce78a73ad136a7b42941297aff373</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F5</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6a69ea34f5d1372692bf040637e57c8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F6</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba247a20a9998f080827dd34004abc2f9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F7</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba34a07203a0a4f3e996b44e9a4fcfd1c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba9eaf4e9e3d8451fd1332c013d12c1375</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F9</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba160e82eea885870bfa4924c27040cd7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F10</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba3b922025c26b38585ab140c7e40b291c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F11</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad54743bc4e7f9279abf671cc2a091ce1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F12</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba835f8397baa58fd73ff9c268d6458add</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMLOCK</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa98feaa9c2c57dc8e7b04cb8fddc1a61</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SCROLL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba10db988ee4f813d95a5b7cd2f96e3c48</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SHIFT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba7d538b177ab06797012e9ffb1449acd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_CONTROL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba48f64be40a1a166f83ec1cab14da6bdc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ALT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf22ac608afcf783bb841f664a2620ca6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_EQUALS</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf97f0846e149da44bbf962fa75680809</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_CONTEXTMENU</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba1992687fd833d3503080861864624e25</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_PLAY</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6322842e54ea558c670690f2715b45fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_STOP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baad3b9b6fd66ddf211586428be4479c43</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_PREV</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba29d798af827489cf5ab68c378b8a7ac8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_NEXT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bac80fc1b18bda12f7dfccbbe1b012798b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_VOLUME_UP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baedbb585f9e7ee87263a250c91542fb02</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_VOLUME_DOWN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba2304f457aba66febcf852dbf1cbae8b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F13</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba29161713f30649423d0ddefa16028396</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F14</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba7a39de2eb466cf269a7a34d0377cf326</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F15</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba57efdf8b5659ceaf5bda4be62e65ab56</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baabf57281e043880eb269a6a72368aca5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F17</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba5ce646467129e626c1ec8888f80045ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F18</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bab6e856fc1ebc35abda65fd30fe9deeca</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F19</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa385ff09ff5f05a4fedb1e75570baa8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VKEY_FIRST_CODE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba0abb06f320e406fbe76c08b2f5909ad6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VKEY_LAST_CODE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba219b7884c92935dc6365a7fec8b55bcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VKEY_FIRST_ASCII</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba39f030dbc1bfdb4a14a310acc744178f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>KeyModifier</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kShiftKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da7dee5096e7803ac26cee7abe740d777d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAlternateKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da8779d8eaee888493c6c5db7acc5d4a0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCommandKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da111880e47a70791b129ec7a46f988078</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kControlKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da6bd5ac36e7d960d29783e07406f3b15c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>VirtualKeyCodeToChar</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aac1c8cc4f206d2342fdd10c5c3d2fc6f</anchor>
      <arglist>(uint8 vKey)</arglist>
    </member>
    <member kind="function">
      <type>uint8</type>
      <name>CharToVirtualKeyCode</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af3106a92c99884d4eb8bef6f0f35e4b8</anchor>
      <arglist>(char character)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>pluginbasefwd.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>pluginbasefwd_8h</filename>
    <namespace>Steinberg</namespace>
  </compound>
  <compound kind="file">
    <name>smartpointer.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>smartpointer_8h</filename>
    <includes id="fplatform_8h" name="fplatform.h" local="yes" imported="no">pluginterfaces/base/fplatform.h</includes>
    <class kind="class">Steinberg::IPtr</class>
    <class kind="class">Steinberg::OPtr</class>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>IPtr&lt; I &gt;</type>
      <name>owned</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac927ea9345d334e9ee0ea8658c8cb9bb</anchor>
      <arglist>(I *p)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ustring.cpp</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ustring_8cpp</filename>
    <includes id="ustring_8cpp" name="ustring.cpp" local="yes" imported="no">ustring.h</includes>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">ftypes.h</includes>
    <namespace>Steinberg</namespace>
    <member kind="function">
      <type>void</type>
      <name>StringCopy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1640534b1632680ee56fd3d44ebbd3b2</anchor>
      <arglist>(TDstChar *dst, int32 dstSize, const TSrcChar *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>StringLength</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af7cbc74e5744ba3d03325a43d62d66c0</anchor>
      <arglist>(const TSrcChar *src, int32 srcSize=-1)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>ustring.h</name>
    <path>/Volumes/SSD/Builddata/agents/srv-buildmacmini3/recipes/111343890/base/VST3 SDK/pluginterfaces/base/</path>
    <filename>ustring_8h</filename>
    <includes id="ftypes_8h" name="ftypes.h" local="yes" imported="no">ftypes.h</includes>
    <class kind="class">Steinberg::UString</class>
    <class kind="class">Steinberg::UStringBuffer</class>
    <namespace>Steinberg</namespace>
    <member kind="define">
      <type>#define</type>
      <name>USTRING</name>
      <anchorfile>ustring_8h.html</anchorfile>
      <anchor>ac5f8dfe73b55c4ec26f12c071d67bffb</anchor>
      <arglist>(asciiString)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>USTRINGSIZE</name>
      <anchorfile>ustring_8h.html</anchorfile>
      <anchor>abbca26150973e505a5e42d3854b49750</anchor>
      <arglist>(var)</arglist>
    </member>
    <member kind="typedef">
      <type>UStringBuffer&lt; 128 &gt;</type>
      <name>UString128</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa92186fdeda699e7a0cc7ac6c45d07e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>UStringBuffer&lt; 256 &gt;</type>
      <name>UString256</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a71098a25fa252b10d271a11807153385</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>howtoClass</name>
    <title>How to derive a class from an interface</title>
    <filename>howtoClass</filename>
  </compound>
  <compound kind="page">
    <name>versionInheritance</name>
    <title>Interface Versions and Inheritance</title>
    <filename>versionInheritance</filename>
  </compound>
  <compound kind="page">
    <name>loadPlugin</name>
    <title>How the host will load a Plug-in</title>
    <filename>loadPlugin</filename>
  </compound>
  <compound kind="group">
    <name>pluginBase</name>
    <title>Basic Interfaces</title>
    <filename>group__pluginBase.html</filename>
    <class kind="class">Steinberg::FUID</class>
    <class kind="class">Steinberg::FUnknown</class>
    <class kind="class">Steinberg::FVariant</class>
    <class kind="class">Steinberg::IBStream</class>
    <class kind="class">Steinberg::ISizeableStream</class>
    <class kind="class">Steinberg::IPluginBase</class>
    <class kind="struct">Steinberg::PFactoryInfo</class>
    <class kind="struct">Steinberg::PClassInfo</class>
    <class kind="class">Steinberg::IPluginFactory</class>
    <class kind="struct">Steinberg::PClassInfo2</class>
    <class kind="class">Steinberg::IPluginFactory2</class>
    <class kind="class">Steinberg::IPluginFactory3</class>
    <class kind="class">Steinberg::IPtr</class>
    <class kind="class">Steinberg::OPtr</class>
    <member kind="function">
      <type>Steinberg::IPluginFactory *PLUGIN_API</type>
      <name>GetPluginFactory</name>
      <anchorfile>group__pluginBase.html</anchorfile>
      <anchor>gae1c930f4bfb3f7b08df00fb107c06091</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="group">
    <name>pluginGUI</name>
    <title>Graphical User Interface</title>
    <filename>group__pluginGUI.html</filename>
    <class kind="struct">Steinberg::ViewRect</class>
    <class kind="class">Steinberg::IPlugView</class>
    <class kind="class">Steinberg::IPlugFrame</class>
    <subgroup>platformUIType</subgroup>
  </compound>
  <compound kind="group">
    <name>platformUIType</name>
    <title>Platform UI Types</title>
    <filename>group__platformUIType.html</filename>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeHWND</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>gaa1e68ac1f25da9c85c937d0360dbc601</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeHIView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga974cabea219cb31ad8218ba15d1f7071</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeNSView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga8ce69944b5475d65206469b9ebcbf755</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeUIView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga6362a7ca65b87d30c561dac986b757bd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg</name>
    <filename>namespaceSteinberg.html</filename>
    <namespace>Steinberg::FUnknownPrivate</namespace>
    <namespace>Steinberg::GeoConstants</namespace>
    <class kind="class">Steinberg::ConstStringTable</class>
    <class kind="class">Steinberg::FUID</class>
    <class kind="class">Steinberg::FUnknown</class>
    <class kind="class">Steinberg::FUnknownPtr</class>
    <class kind="struct">Steinberg::FReleaser</class>
    <class kind="class">Steinberg::FVariant</class>
    <class kind="class">Steinberg::IBStream</class>
    <class kind="class">Steinberg::ISizeableStream</class>
    <class kind="class">Steinberg::ICloneable</class>
    <class kind="class">Steinberg::IErrorContext</class>
    <class kind="class">Steinberg::IPersistent</class>
    <class kind="class">Steinberg::IAttributes</class>
    <class kind="class">Steinberg::IAttributes2</class>
    <class kind="class">Steinberg::IPluginBase</class>
    <class kind="struct">Steinberg::PFactoryInfo</class>
    <class kind="struct">Steinberg::PClassInfo</class>
    <class kind="class">Steinberg::IPluginFactory</class>
    <class kind="struct">Steinberg::PClassInfo2</class>
    <class kind="class">Steinberg::IPluginFactory2</class>
    <class kind="struct">Steinberg::PClassInfoW</class>
    <class kind="class">Steinberg::IPluginFactory3</class>
    <class kind="class">Steinberg::IStringResult</class>
    <class kind="class">Steinberg::IString</class>
    <class kind="class">Steinberg::IUpdateHandler</class>
    <class kind="class">Steinberg::IDependent</class>
    <class kind="class">Steinberg::IPtr</class>
    <class kind="class">Steinberg::OPtr</class>
    <class kind="class">Steinberg::UString</class>
    <class kind="class">Steinberg::UStringBuffer</class>
    <class kind="struct">Steinberg::ViewRect</class>
    <class kind="class">Steinberg::IPlugView</class>
    <class kind="class">Steinberg::IPlugFrame</class>
    <member kind="typedef">
      <type>char</type>
      <name>int8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae47c588f3ab8c61121c1c7ab7edc47cd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char</type>
      <name>uint8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adde6aaee8457bee49c2a92621fe22b79</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char</type>
      <name>uchar</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a65f85814a8290f9797005d3b28e7e5fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>short</type>
      <name>int16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4355d16fcf9f644c9ac84293f0b1801f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned short</type>
      <name>uint16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a05f6b0ae8f6a6e135b0e290c25fe0e4e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>long</type>
      <name>int32</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4ca2d97e571b049be6f4cdcfaa1ab946</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long</type>
      <name>uint32</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a4b435a49c74bb91f284f075e63416cb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>long long</type>
      <name>int64</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aecfc3c54bd29ad5964e1c1c3ccbf89df</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long long</type>
      <name>uint64</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a29940ae63ec06c9998bba873e25407ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>TSize</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>abc5a03f91bd781b5062f4fccaa7851f0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>tresult</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a902761e005a6252e538c766de48fc957</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint32</type>
      <name>TPtrInt</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1c25ab481e482aafa3e751e3d2ada928</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>uint8</type>
      <name>TBool</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1ea8addd740f35d207a1569dd38ef895</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char</type>
      <name>char8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac9e1c0f508ae0f5f8a2b704a91e1ae86</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int16</type>
      <name>char16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad12e102dc50c08aa3136349a56e76fd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char8</type>
      <name>char</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ada0030c3b477e12fa91f25eba5aa383f</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>CStringA</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a435992556581fbc31a9bddb3bb2f787a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char16 *</type>
      <name>CStringW</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a81b4df0e8189d2f135f25919a6a90be2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char *</type>
      <name>CString</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6f37e0dbf8faed21d2658800d9db4583</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>const char8 *</type>
      <name>FIDString</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad4c02134d1ee42389f3d94717935a1d5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int32</type>
      <name>UCoord</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>abf33a8b245f4634965116e9c25eb702a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int64</type>
      <name>LARGE_INT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9cd1730908299276af7bc0baa8c5197e</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>int8</type>
      <name>TUID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a32680add5f0b1c8a81e5b1c4cfe6a30c</anchor>
      <arglist>[16]</arglist>
    </member>
    <member kind="typedef">
      <type>FIDString</type>
      <name>IAttrID</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae6eacc17e4382538d4af0d9993bc869a</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>UStringBuffer&lt; 128 &gt;</type>
      <name>UString128</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa92186fdeda699e7a0cc7ac6c45d07e5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>UStringBuffer&lt; 256 &gt;</type>
      <name>UString256</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a71098a25fa252b10d271a11807153385</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoInterface</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba21f2c8af375a407ff9fb8d10e8e73a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kResultOk</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba941549edbe23d0f21851403ae03ad4df</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kResultTrue</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba9e60fad4624bee040985edebe1800372</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kResultFalse</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bab954d2583eb15d3a762c5df29270f483</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInvalidArgument</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bace91375677eb541c1a70e7ecd95f5698</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNotImplemented</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba598e4c5d4c234c1bf09367d64487519c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInternalError</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba3b287aa91111dd8aedf4bbf363e01525</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNotInitialized</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55ba1216e3377e943f8898e78c63422924aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOutOfMemory</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a06fc87d81c62e9abb8790b6e5713c55bac43d80137687fc5c1c4b60dc77202283</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>Direction</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aa</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNorth</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa89c5f7af4c1a4fe20ab7524369050200</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNorthEast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa80a10c4928ef7af3ce487d381e2420d2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa37d01669db016bc15ed6fdab6fb6c790</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSouthEast</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaadf50c366ce2690678d0e6290f52b4639</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSouth</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa515c12ec206b53ce5da86a402b3f4cf8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSouthWest</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa6a77137c947ac754a97274617a22afb6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kWest</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa45b705ff067984bfd99c234d91386792</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNorthWest</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaaa67fc18f8f8b0ba3b792b46a1fa0c872</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoDirection</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaa87e054da76bada3343762974c988e80a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumberOfDirections</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a224b9163917ac32fc95a60d8c1eec3aaabdba6353397f1b1654328de91f17e348</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>Orientation</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kHorizontal</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58ad4149164ae4bf90011d92a3dbfcce742</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVertical</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58a4764485d9d221af213bf2b2769cdfc54</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNumberOfOrientations</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a871118a09520247c78a71ecd7b0abd58a231632c3d1e6d53428167283534f1abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>VirtualKeyCodes</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_BACK</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba363a5589e96b18dca6534e951baffdd3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_TAB</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba60c75f9c8eded88ef76c0c94da27963c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_CLEAR</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baee7181a798c5753153051c0e1ace41c9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_RETURN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baaefd064b1e5d75c429bed314ac18eba0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PAUSE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad26d172dc2cd90741c3939ca4fab0b84</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ESCAPE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba3a471c8b61a5f730dcbdd50fe53f3ab7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SPACE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba01d2889f9a7550008ad6140c41e733de</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NEXT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba82d61b2ebb1c5fee25aea8d69d325acc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_END</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa8adb6fcb92dec58fb19410eacfdd403</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_HOME</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad5b83418c285e43af5d3a87b4d4049d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_LEFT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba612120b69c7dfd46086db7aaebdbcf65</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_UP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba0848a442d907968b211b97bc2bd88acd</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_RIGHT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6504370d9c6391e1a9da6a1a529b089d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DOWN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa9cdac7967bf7d88fdb761138a2a3416</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PAGEUP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba5d9c9ba1d8f2c6f6737db37d3f449071</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PAGEDOWN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba5996c34d86df2b3c1be741aeb35bdbc4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SELECT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba3b37a163628bc7015aac5efab4a66ef5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_PRINT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf6ff54b9651ca18045e4000c2d26f790</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ENTER</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba2a662d23aadd7106a3a2afdfd5d426ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SNAPSHOT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bacc39d60a35433541177dbd7bf01a8257</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_INSERT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba26f2c18a3a0a7eabf7bd11f0ec93be78</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DELETE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bae7a3a4540031b038014294aa6743a7a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_HELP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad729e81b40a3acb64b5a40b7fa459b09</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD0</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba55aef83f557c4ed24e2847d38ea292b3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD1</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba681b5574363c5d5a463af7e514172292</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD2</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba779490ca3da209736187a912cd8382dc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD3</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bae58753ec4558e7b68f4aa07ed97d50d7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD4</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba744226502b73227ed219a5142c232126</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD5</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba906fbf3011cae4b931d6fe6126147a82</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD6</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bac4e7f0a72c3594aa3d5b83f61b714e3f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD7</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bae6d134db5bf54ae1d4b29f8a2cca8889</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba258d226c87d8446423d3214a59eb498b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMPAD9</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6ab9d27201ffbdccabde9f5a0e9dedd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MULTIPLY</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa7ccd4f6c9a10fe36e0e7bd28d15bea3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ADD</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba88535ed64ae437ce31620dcb62c66c9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SEPARATOR</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba79459423b8bbe9f70949f464cd7a27ae</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SUBTRACT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf6ba424919235c2cbbac7184e3625395</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DECIMAL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bafce663586a7e53223158c5f4ce6033fc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_DIVIDE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba36a890023ae628d5c36ca010edffc59c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F1</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bafcf70bc39c0032de8a1c6452ac9860a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F2</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba87897fd25282941e1a9bf72b9f64559a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F3</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba965c99b1f4fc05cec09ef61b0af8e74a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F4</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba01bce78a73ad136a7b42941297aff373</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F5</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6a69ea34f5d1372692bf040637e57c8f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F6</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba247a20a9998f080827dd34004abc2f9a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F7</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba34a07203a0a4f3e996b44e9a4fcfd1c6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba9eaf4e9e3d8451fd1332c013d12c1375</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F9</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba160e82eea885870bfa4924c27040cd7f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F10</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba3b922025c26b38585ab140c7e40b291c</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F11</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bad54743bc4e7f9279abf671cc2a091ce1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F12</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba835f8397baa58fd73ff9c268d6458add</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_NUMLOCK</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa98feaa9c2c57dc8e7b04cb8fddc1a61</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SCROLL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba10db988ee4f813d95a5b7cd2f96e3c48</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_SHIFT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba7d538b177ab06797012e9ffb1449acd9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_CONTROL</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba48f64be40a1a166f83ec1cab14da6bdc</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_ALT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf22ac608afcf783bb841f664a2620ca6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_EQUALS</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baf97f0846e149da44bbf962fa75680809</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_CONTEXTMENU</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba1992687fd833d3503080861864624e25</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_PLAY</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba6322842e54ea558c670690f2715b45fb</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_STOP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baad3b9b6fd66ddf211586428be4479c43</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_PREV</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba29d798af827489cf5ab68c378b8a7ac8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_MEDIA_NEXT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bac80fc1b18bda12f7dfccbbe1b012798b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_VOLUME_UP</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baedbb585f9e7ee87263a250c91542fb02</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_VOLUME_DOWN</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba2304f457aba66febcf852dbf1cbae8b0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F13</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba29161713f30649423d0ddefa16028396</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F14</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba7a39de2eb466cf269a7a34d0377cf326</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F15</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba57efdf8b5659ceaf5bda4be62e65ab56</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baabf57281e043880eb269a6a72368aca5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F17</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba5ce646467129e626c1ec8888f80045ed</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F18</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22bab6e856fc1ebc35abda65fd30fe9deeca</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>KEY_F19</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22baa385ff09ff5f05a4fedb1e75570baa8b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VKEY_FIRST_CODE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba0abb06f320e406fbe76c08b2f5909ad6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VKEY_LAST_CODE</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba219b7884c92935dc6365a7fec8b55bcf</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VKEY_FIRST_ASCII</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9380117707cebcb5a3cd9fa8b960e22ba39f030dbc1bfdb4a14a310acc744178f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>KeyModifier</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kShiftKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da7dee5096e7803ac26cee7abe740d777d</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kAlternateKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da8779d8eaee888493c6c5db7acc5d4a0a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCommandKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da111880e47a70791b129ec7a46f988078</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kControlKey</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a743f60968fa58cdae68b31a1a3eb493da6bd5ac36e7d960d29783e07406f3b15c</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>_tstrlen</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0f20517a819515665c6fbd35ece5a434</anchor>
      <arglist>(const T *wcs)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrlen</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a51fad7b4c1e3dfa032d4f638ecd68c7a</anchor>
      <arglist>(const char *str)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strlen8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a350bed0883f4792e7535252b3122dd5b</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strlen16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aae116b01b47bca8e67679337ef48d8d3</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>_tstrcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a7023958e09487e98aaa402f6b4665212</anchor>
      <arglist>(const T *src, const T *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrcmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2f01ef81ad1c686ebb34a97ef4e2d098</anchor>
      <arglist>(const char *src, const char *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a90dd0a8f52813eb453f60ac1c49559bc</anchor>
      <arglist>(const char8 *src, const char8 *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9b47c8ef5ed96ca9034e87624f69b890</anchor>
      <arglist>(const char16 *src, const char16 *dst)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmpT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a578edc38568fcccf2bbec8705f3c689d</anchor>
      <arglist>(const T *first, const T *last)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmpT&lt; char8 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8fcbc514f3212361e41daf160256a3e2</anchor>
      <arglist>(const char8 *first, const char8 *last)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strcmpT&lt; char16 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad6478b52a8c36d263b0f163eb04636af</anchor>
      <arglist>(const char16 *first, const char16 *last)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>_tstrncmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a9472c661ae9df487057d848006bd12b1</anchor>
      <arglist>(const T *first, const T *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>tstrncmp</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a25694d169804ad218b221f3e101eaee4</anchor>
      <arglist>(const char *first, const char *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmp8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8f3cca9e30bb739b30be3eca6b891c8f</anchor>
      <arglist>(const char8 *first, const char8 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmp16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a54115da13293d44eaae9ba44a4fa82e2</anchor>
      <arglist>(const char16 *first, const char16 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmpT</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a415c030bc6c3e9c718a2a52fc812dbd7</anchor>
      <arglist>(const T *first, const T *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmpT&lt; char8 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a03f447e8dc074eadadbdf83d42a88bc0</anchor>
      <arglist>(const char8 *first, const char8 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>strncmpT&lt; char16 &gt;</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a95e46377021d0a18bbf3dcbb527334ac</anchor>
      <arglist>(const char16 *first, const char16 *last, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>_tstrcpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0ed99e5e2d595d1fbb46be4af6bad16e</anchor>
      <arglist>(T *dst, const T *src)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>tstrcpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a406cfbdd4e67843189e729a50a22c952</anchor>
      <arglist>(char *dst, const char *src)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>strcpy8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa12723f519b8ecf7d99b4067b6f44344</anchor>
      <arglist>(char8 *dst, const char8 *src)</arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>strcpy16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a32880d14cc3ac2196ddd0859e4fb7bd6</anchor>
      <arglist>(char16 *dst, const char16 *src)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>_tstrncpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a78d52df38c5128a70f98c9b832853ed9</anchor>
      <arglist>(T *dest, const T *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>tstrncpy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae8ecddebc9de1d21e16eb0929574959a</anchor>
      <arglist>(char *dest, const char *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>strncpy8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6d93eaadf6a7fa89aa51c5ee8cdae132</anchor>
      <arglist>(char8 *dest, const char8 *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>strncpy16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a71e109979dde381bbba56500bbde60e8</anchor>
      <arglist>(char16 *dest, const char16 *source, uint32 count)</arglist>
    </member>
    <member kind="function">
      <type>T *</type>
      <name>_tstrcat</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a71213f60ea53751e1460a66919e526f4</anchor>
      <arglist>(T *dst, const T *src)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>tstrcat</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a64e0b47b3f8b466e2cb815d6662298e0</anchor>
      <arglist>(char *dst, const char *src)</arglist>
    </member>
    <member kind="function">
      <type>char8 *</type>
      <name>strcat8</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac632cd3fa4f20541cabfb27d20ad2581</anchor>
      <arglist>(char8 *dst, const char8 *src)</arglist>
    </member>
    <member kind="function">
      <type>char16 *</type>
      <name>strcat16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a90f489c9a479d8c86d651dbe97f6f74f</anchor>
      <arglist>(char16 *dst, const char16 *src)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>str8ToStr16</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a43172f2a5d34fc811021a16d1a38434d</anchor>
      <arglist>(char16 *dst, const char8 *src, int32 n=-1)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>FIDStringsEqual</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ae609f786a23774a473851d3eddaa22ff</anchor>
      <arglist>(FIDString id1, FIDString id2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>strEmpty</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a6df75d455350d4aaadc70786730f11fa</anchor>
      <arglist>(const char *str)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>str8Empty</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a107fdab7d7c86e4f5191a27005a6bbc3</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>str16Empty</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a51822113d808dc2e0594f7f1c61fa823</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>Min</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>adcde5fff9b5074d3e36fc411ee865dd9</anchor>
      <arglist>(const T &amp;a, const T &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>const T &amp;</type>
      <name>Max</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa4b9f4d937d8d865a8bfa86e6e392505</anchor>
      <arglist>(const T &amp;a, const T &amp;b)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Abs</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>acbbd1cb9aa59aaa62572519d5e381549</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Sign</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a8f0cb0def093b54ebe00691604f5a09b</anchor>
      <arglist>(const T &amp;value)</arglist>
    </member>
    <member kind="function">
      <type>T</type>
      <name>Bound</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a91ac21e99d77a7471db59984466167bb</anchor>
      <arglist>(T minval, T maxval, T x)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>Swap</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a5d8f1525e15b2c83643fc473d75b6c19</anchor>
      <arglist>(T &amp;t1, T &amp;t2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>IsApproximateEqual</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa350c13f3025cc69274e38bbc39b5907</anchor>
      <arglist>(T t1, T t2, T epsilon)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2978443758ec8594b15872123119363a</anchor>
      <arglist>(const FVariant &amp;v1, const FVariant &amp;v2)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aa3bb730da3e8dd39c4b324d057e430c4</anchor>
      <arglist>(const FVariant &amp;v1, const FVariant &amp;v2)</arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>VirtualKeyCodeToChar</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>aac1c8cc4f206d2342fdd10c5c3d2fc6f</anchor>
      <arglist>(uint8 vKey)</arglist>
    </member>
    <member kind="function">
      <type>uint8</type>
      <name>CharToVirtualKeyCode</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af3106a92c99884d4eb8bef6f0f35e4b8</anchor>
      <arglist>(char character)</arglist>
    </member>
    <member kind="function">
      <type>IPtr&lt; I &gt;</type>
      <name>owned</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ac927ea9345d334e9ee0ea8658c8cb9bb</anchor>
      <arglist>(I *p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>StringCopy</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a1640534b1632680ee56fd3d44ebbd3b2</anchor>
      <arglist>(TDstChar *dst, int32 dstSize, const TSrcChar *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>StringLength</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>af7cbc74e5744ba3d03325a43d62d66c0</anchor>
      <arglist>(const TSrcChar *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformStringWin</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a2ae80314db54c6bda33e1cf922effb47</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformStringMac</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>ad5ffc071fd688ac833b5283777037278</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformStringIOS</name>
      <anchorfile>namespaceSteinberg.html</anchorfile>
      <anchor>a0e747a3b854268949a75a1c8e8fd070c</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeHWND</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>gaa1e68ac1f25da9c85c937d0360dbc601</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeHIView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga974cabea219cb31ad8218ba15d1f7071</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeNSView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga8ce69944b5475d65206469b9ebcbf755</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const FIDString</type>
      <name>kPlatformTypeUIView</name>
      <anchorfile>group__platformUIType.html</anchorfile>
      <anchor>ga6362a7ca65b87d30c561dac986b757bd</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ConstStringTable</name>
    <filename>classSteinberg_1_1ConstStringTable.html</filename>
    <member kind="function">
      <type>const char16 *</type>
      <name>getString</name>
      <anchorfile>classSteinberg_1_1ConstStringTable.html</anchorfile>
      <anchor>a3b3c5fcbce3ade9cc856fb3c052ae472</anchor>
      <arglist>(const char8 *str) const </arglist>
    </member>
    <member kind="function">
      <type>const char16</type>
      <name>getString</name>
      <anchorfile>classSteinberg_1_1ConstStringTable.html</anchorfile>
      <anchor>a318f01bfc9b12a563fc5976434fefee9</anchor>
      <arglist>(const char8 str) const </arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ConstStringTable *</type>
      <name>instance</name>
      <anchorfile>classSteinberg_1_1ConstStringTable.html</anchorfile>
      <anchor>a7ed68ef8938393b1fc911313db64c804</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>ConstStringTable</name>
      <anchorfile>classSteinberg_1_1ConstStringTable.html</anchorfile>
      <anchor>acf88e43da1b31d3d425c80d747bbb1a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>~ConstStringTable</name>
      <anchorfile>classSteinberg_1_1ConstStringTable.html</anchorfile>
      <anchor>a99f647d997cd61d511fdf60560c5706b</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FUID</name>
    <filename>classSteinberg_1_1FUID.html</filename>
    <member kind="enumeration">
      <name>UIDPrintStyle</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4c6d5af58eee71460b173f2a3fc16e83</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kINLINE_UID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4c6d5af58eee71460b173f2a3fc16e83a9f131fba80cf6b9f835dbcd1893a8e2a</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDECLARE_UID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4c6d5af58eee71460b173f2a3fc16e83a0645d915ab71dfc6a46b46b2e0437b01</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kFUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4c6d5af58eee71460b173f2a3fc16e83a786d38db04f85fa7d41ffb4bfdb38283</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCLASS_UID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4c6d5af58eee71460b173f2a3fc16e83af0e94a5c0c5e442c941dedb3488540dd</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char8</type>
      <name>String</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a0f2fc16d77666544de6fbd65e184ced8</anchor>
      <arglist>[64]</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>aef4d827e945c171d056b9ed79a8964f8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a0a711b0b8889b1bb6631111104a6fff4</anchor>
      <arglist>(const TUID uid)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a29217891f71b9c22549ae79a894f480f</anchor>
      <arglist>(uint32 l1, uint32 l2, uint32 l3, uint32 l4)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a0404d1a9d834c21a3c91a2d9b8c1a361</anchor>
      <arglist>(const FUID &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~FUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a55b6f76b0487f0ceb85525b05fa4009f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>generate</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>aa854636edbaec64049039c593403bc70</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isValid</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>aac1b70a2ed67ead038c4d3f5ac4d8a81</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>FUID &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ac8fc81bf202c6eb2f5832bc9605bf0bc</anchor>
      <arglist>(const FUID &amp;f)</arglist>
    </member>
    <member kind="function">
      <type>FUID &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a90cf55f0b465c63bddf54b44fffeb512</anchor>
      <arglist>(FIDString uid)</arglist>
    </member>
    <member kind="function">
      <type>FUID &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ad4a05be7db1bacdd20d1f0836dedde07</anchor>
      <arglist>(TUID uid)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ad222698c02d66bed34ceee73510ccc47</anchor>
      <arglist>(const FUID &amp;f) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a5efb5a01d695c6c68e5e8ee4bab27423</anchor>
      <arglist>(FIDString uid) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a3b49350ae7a7acc3bef334fecbc0e084</anchor>
      <arglist>(TUID uid) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>aa6aec818004cd35db7a78987976d1fad</anchor>
      <arglist>(const FUID &amp;f) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a5411ae49350e1630462d44da173c4bce</anchor>
      <arglist>(FIDString uid) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator&lt;</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>aad39e662bce690775bfc2b630dda8304</anchor>
      <arglist>(TUID uid) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ad091599e39045804d00815f16d671944</anchor>
      <arglist>(const FUID &amp;f) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4fefe95b50514a83f8256dd7c0fa76e3</anchor>
      <arglist>(FIDString uid) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a63c7734ebe7af27eefb4d8af26b79dfd</anchor>
      <arglist>(TUID uid) const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator FIDString</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a06aa0c14df484ac130038af8c6444369</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator char *</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a2c2bebb89803c6d54e0fe24f41f24924</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getLong1</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a9ec11dc4635c50d3d550b70a5c35a776</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getLong2</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a4ad3ac87828b12b169e5d8f7dcb9d40c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getLong3</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ab172c58a94ae0771e47b53e85ce0c305</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint32</type>
      <name>getLong4</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ad34efd6a06e7dee8a404c024f0debde0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>from4Int</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ad4ecb2d9af5f8cf17d6ec497f871f13a</anchor>
      <arglist>(uint32 d1, uint32 d2, uint32 d3, uint32 d4)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>to4Int</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>aa8cc6a07a3f18cf01313393f7e5e8c87</anchor>
      <arglist>(uint32 &amp;d1, uint32 &amp;d2, uint32 &amp;d3, uint32 &amp;d4) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toString</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a04ad5872389ea0b0a8a4b5dfd3780d22</anchor>
      <arglist>(char8 *string) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>fromString</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a1e809eb52c1b13101a137f4f722d93ab</anchor>
      <arglist>(const char8 *string)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toRegistryString</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ab21b1a2ba3c9b29b35131450f9fc2bb1</anchor>
      <arglist>(char8 *string) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>fromRegistryString</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a8124e38def2946aa169b72c0fdb115bb</anchor>
      <arglist>(const char8 *string)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a2dec1c07af42dd3ef9195c4f35290903</anchor>
      <arglist>(char8 *string=0, int32 style=kINLINE_UID) const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>toTUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>abd37cfcc00bb93ae45b4e01f332c12d8</anchor>
      <arglist>(TUID result) const </arglist>
    </member>
    <member kind="function">
      <type>const TUID &amp;</type>
      <name>toTUID</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>ad2940cd2922179eb4a50cd3fe1965769</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TUID</type>
      <name>data</name>
      <anchorfile>classSteinberg_1_1FUID.html</anchorfile>
      <anchor>a5831f7a540668b040269fcc4a4634a6c</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FUnknown</name>
    <filename>classSteinberg_1_1FUnknown.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>queryInterface</name>
      <anchorfile>classSteinberg_1_1FUnknown.html</anchorfile>
      <anchor>ab6c66ef1a65611e850e40e1e1b45b7d5</anchor>
      <arglist>(const TUID _iid, void **obj)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual uint32 PLUGIN_API</type>
      <name>addRef</name>
      <anchorfile>classSteinberg_1_1FUnknown.html</anchorfile>
      <anchor>a94e0fe7a04d760786320cda2570c1d24</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual uint32 PLUGIN_API</type>
      <name>release</name>
      <anchorfile>classSteinberg_1_1FUnknown.html</anchorfile>
      <anchor>a8a3e8c264111714a3a1ce9eb059afa0a</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1FUnknown.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FUnknownPtr</name>
    <filename>classSteinberg_1_1FUnknownPtr.html</filename>
    <templarg></templarg>
    <base>Steinberg::IPtr</base>
    <member kind="function">
      <type></type>
      <name>FUnknownPtr</name>
      <anchorfile>classSteinberg_1_1FUnknownPtr.html</anchorfile>
      <anchor>ab0a0024a95295f9771675b21f78dc97f</anchor>
      <arglist>(FUnknown *unknown)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FUnknownPtr</name>
      <anchorfile>classSteinberg_1_1FUnknownPtr.html</anchorfile>
      <anchor>a2e3f1f023934674b6f10da8d9451bee0</anchor>
      <arglist>(const FUnknownPtr &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FUnknownPtr</name>
      <anchorfile>classSteinberg_1_1FUnknownPtr.html</anchorfile>
      <anchor>a24254b5cf187cab371540748f64d190d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>FUnknownPtr &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FUnknownPtr.html</anchorfile>
      <anchor>a932dfba34e2a9ea0e1c809b8ea218a38</anchor>
      <arglist>(const FUnknownPtr &amp;p)</arglist>
    </member>
    <member kind="function">
      <type>I *</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FUnknownPtr.html</anchorfile>
      <anchor>ac580abcf2012c88ed8c1023ce525610e</anchor>
      <arglist>(FUnknown *unknown)</arglist>
    </member>
    <member kind="function">
      <type>I *</type>
      <name>getInterface</name>
      <anchorfile>classSteinberg_1_1FUnknownPtr.html</anchorfile>
      <anchor>afbcc6839b0e53c7a4582393aba7ae538</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::FReleaser</name>
    <filename>structSteinberg_1_1FReleaser.html</filename>
    <member kind="function">
      <type></type>
      <name>FReleaser</name>
      <anchorfile>structSteinberg_1_1FReleaser.html</anchorfile>
      <anchor>a9aeee674f38393febf98f8cf953657f5</anchor>
      <arglist>(FUnknown *u)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FReleaser</name>
      <anchorfile>structSteinberg_1_1FReleaser.html</anchorfile>
      <anchor>aa5116d1833f098d611bf2336d869823d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>FUnknown *</type>
      <name>u</name>
      <anchorfile>structSteinberg_1_1FReleaser.html</anchorfile>
      <anchor>adcb624ac2e22762ff3ef4a83c423d84f</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::FVariant</name>
    <filename>classSteinberg_1_1FVariant.html</filename>
    <member kind="enumvalue">
      <name>kEmpty</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7a5460ad665310efd60a2352b2c347342f</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kInteger</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7aa1acc5720dd4e85ceea5578a6cf14ae6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kFloat</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7a5686197bafb177bdc82550848416a1ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kString8</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7a0f3df8a4ca30a3ad6b26e7f17a8032c2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kObject</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7ad74f4c7c6562dc3f8339a8bba2d28dd0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kOwner</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7a8748a0de195760963cc4a77e6b4c29d0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kString16</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adf764cbdea00d65edcd07bb9953ad2b7a3bbd3d3c841c519ed8d96eacdc2c1e69</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a3af413f4c05123f8a5a7e34085932fd2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>ac79d4fad10a7b9fd5d7ebe153133db47</anchor>
      <arglist>(const FVariant &amp;variant)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a6f1899f0b15a7da0117660534d4a761b</anchor>
      <arglist>(int64 v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a227515960e0625ca5bcadb86a2942147</anchor>
      <arglist>(double v)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a02221250eb24a108ec57297d5df2d9de</anchor>
      <arglist>(const char8 *str)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>aeba1661809a9fd72b790f577aea27c9c</anchor>
      <arglist>(const char16 *str)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>ae94cb75f5692368c85828de1d72e904b</anchor>
      <arglist>(FUnknown *obj, bool owner=false)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~FVariant</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>ac4f5a08fe96561b601a95584bbf05632</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>FVariant &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a702dcc8229c6a13ad5f342326905921d</anchor>
      <arglist>(const FVariant &amp;variant)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setInt</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>aac3ddf857b8f752aafc10aede06b641b</anchor>
      <arglist>(int64 v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFloat</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a465a9c6375b7b91e6a004bf4d13f6706</anchor>
      <arglist>(double v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setString8</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>adb629fad8700dcecfd40c2bc5cf2c6a4</anchor>
      <arglist>(const char8 *v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setString16</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>aa2822fca3d75d9e6cc4b10ab57de6597</anchor>
      <arglist>(const char16 *v)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setObject</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a299d0820a6de5c1f779d80772a49d654</anchor>
      <arglist>(FUnknown *obj)</arglist>
    </member>
    <member kind="function">
      <type>int64</type>
      <name>getInt</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a840c3af6e433b8b6de447aff90ee8516</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getFloat</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a13bb0beae475425743402581cf4cf2ce</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getNumber</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a142da9be8c10150a2f476f5cafea9347</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const char8 *</type>
      <name>getString8</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a1435d81de7e7dac745e0fd88faf6f3d7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>const char16 *</type>
      <name>getString16</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a41679e157116bc3a0eeac8803594b4d2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>FUnknown *</type>
      <name>getObject</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>aa857f9ed3b6a3fc6785d2f5e4e6dd8be</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>uint16</type>
      <name>getType</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a753ae87f3a50baca965b74bb3bdbc73b</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isEmpty</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a479432127ee77145cc19d6a2d1590821</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isOwner</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a6c975d7981c86e14801166e34183eec7</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isString</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a3ea0b05483601e9acd735f48ccf7ed80</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setOwner</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>abbdb20a51bdf78b0b5dfb245178897e4</anchor>
      <arglist>(bool state)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>empty</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>a9a4d7b0a805f99ab95362516ee336b3e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>uint16</type>
      <name>type</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>af9b2e23a8f32ca09cfeb7d828436fb01</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>union Steinberg::FVariant::@2</type>
      <name>@3</name>
      <anchorfile>classSteinberg_1_1FVariant.html</anchorfile>
      <anchor>af0a554ea39ab354538bc6d47ec687a3a</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int64</type>
      <name>intValue</name>
      <anchorfile>unionSteinberg_1_1FVariant_1_1@2.html</anchorfile>
      <anchor>a39e35889b44c08963c618eaf59304f22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>double</type>
      <name>floatValue</name>
      <anchorfile>unionSteinberg_1_1FVariant_1_1@2.html</anchorfile>
      <anchor>ab5e715b784ee991f6d64cf3ab3ff13d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const char8 *</type>
      <name>string8</name>
      <anchorfile>unionSteinberg_1_1FVariant_1_1@2.html</anchorfile>
      <anchor>adeedacf549c7fcf04323ea19dfa84244</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>const char16 *</type>
      <name>string16</name>
      <anchorfile>unionSteinberg_1_1FVariant_1_1@2.html</anchorfile>
      <anchor>a1264080af4e6271f01c888cc93953194</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>FUnknown *</type>
      <name>object</name>
      <anchorfile>unionSteinberg_1_1FVariant_1_1@2.html</anchorfile>
      <anchor>aa9cfc397af28aeb7d10c6e1ecee2c401</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IBStream</name>
    <filename>classSteinberg_1_1IBStream.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="enumeration">
      <name>IStreamSeekMode</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>a578603bbda4a0145412cb895b14efdd4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIBSeekSet</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>a578603bbda4a0145412cb895b14efdd4aa6df685ae526fa7efefe23ce2c5e6e97</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIBSeekCur</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>a578603bbda4a0145412cb895b14efdd4a38fe1bc7808828aa43282a56e5ed70f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kIBSeekEnd</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>a578603bbda4a0145412cb895b14efdd4aee2005d02e649de8da100c7f417cc2d8</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>read</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>ac7b122518f8a04b332fb981aceb8cf42</anchor>
      <arglist>(void *buffer, int32 numBytes, int32 *numBytesRead=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>write</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>ae25c60d4d450cfdaae6762514035789a</anchor>
      <arglist>(void *buffer, int32 numBytes, int32 *numBytesWritten=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>seek</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>a501ff1ec473fb836bc5709c4574a9595</anchor>
      <arglist>(int64 pos, int32 mode, int64 *result=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>tell</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>a02f7b92ea53473ad87bd8576892b99b7</anchor>
      <arglist>(int64 *pos)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IBStream.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ISizeableStream</name>
    <filename>classSteinberg_1_1ISizeableStream.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getStreamSize</name>
      <anchorfile>classSteinberg_1_1ISizeableStream.html</anchorfile>
      <anchor>ae3e4b08f4e19bf2dd59f54ad33b32858</anchor>
      <arglist>(int64 &amp;size)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>setStreamSize</name>
      <anchorfile>classSteinberg_1_1ISizeableStream.html</anchorfile>
      <anchor>afb30a2acea5439b916cfc1c526526564</anchor>
      <arglist>(int64 size)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1ISizeableStream.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::ICloneable</name>
    <filename>classSteinberg_1_1ICloneable.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual FUnknown *PLUGIN_API</type>
      <name>clone</name>
      <anchorfile>classSteinberg_1_1ICloneable.html</anchorfile>
      <anchor>a827aff9c42f5746cb7d1444ff2ec4352</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1ICloneable.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IErrorContext</name>
    <filename>classSteinberg_1_1IErrorContext.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual void PLUGIN_API</type>
      <name>disableErrorUI</name>
      <anchorfile>classSteinberg_1_1IErrorContext.html</anchorfile>
      <anchor>a558765678126411b6642a34b575e40cb</anchor>
      <arglist>(bool state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>errorMessageShown</name>
      <anchorfile>classSteinberg_1_1IErrorContext.html</anchorfile>
      <anchor>a58924bc1fd0c99504c7468b777d5fca6</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getErrorMessage</name>
      <anchorfile>classSteinberg_1_1IErrorContext.html</anchorfile>
      <anchor>a5e1e49899c99f5186b3a714eb6cd7675</anchor>
      <arglist>(IString *message)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IErrorContext.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPersistent</name>
    <filename>classSteinberg_1_1IPersistent.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getClassID</name>
      <anchorfile>classSteinberg_1_1IPersistent.html</anchorfile>
      <anchor>a2ede087b98315699a45baab12f264320</anchor>
      <arglist>(char8 *uid)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>saveAttributes</name>
      <anchorfile>classSteinberg_1_1IPersistent.html</anchorfile>
      <anchor>afc12a689d8a2f30518b1ecadead87108</anchor>
      <arglist>(IAttributes *)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>loadAttributes</name>
      <anchorfile>classSteinberg_1_1IPersistent.html</anchorfile>
      <anchor>ad7fd98ed18a409a1ea169eaa865e44ec</anchor>
      <arglist>(IAttributes *)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPersistent.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IAttributes</name>
    <filename>classSteinberg_1_1IAttributes.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>set</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a272cfeee5f96dce6afa0b432e8fc43ca</anchor>
      <arglist>(IAttrID attrID, const FVariant &amp;data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>queue</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a524f929a470b51d9fde34d123951cbe6</anchor>
      <arglist>(IAttrID listID, const FVariant &amp;data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>setBinaryData</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>aa45feca8380da87e0bc3f2869f68789c</anchor>
      <arglist>(IAttrID attrID, void *data, uint32 bytes, bool copyBytes)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>get</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a8827cafe9168e4d60b632cc7ed0ce0e9</anchor>
      <arglist>(IAttrID attrID, FVariant &amp;data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>unqueue</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>ab145370aed15e85d8f8f70f43b4d56e8</anchor>
      <arglist>(IAttrID listID, FVariant &amp;data)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32 PLUGIN_API</type>
      <name>getQueueItemCount</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a5ace177e8f3f6a06be438bf328a72a20</anchor>
      <arglist>(IAttrID)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>resetQueue</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a80afe7c67ba104e38ae88f44ebc256db</anchor>
      <arglist>(IAttrID attrID)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>resetAllQueues</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a35dbecb53f8f1c6f481482aae4e8cf5d</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getBinaryData</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>a469169b2a72212214d502a2752d145dd</anchor>
      <arglist>(IAttrID attrID, void *data, uint32 bytes)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual uint32 PLUGIN_API</type>
      <name>getBinaryDataSize</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>ae9594b1d143339f2c97e3d8f54d7909a</anchor>
      <arglist>(IAttrID attrID)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IAttributes.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IAttributes2</name>
    <filename>classSteinberg_1_1IAttributes2.html</filename>
    <base>Steinberg::IAttributes</base>
    <member kind="function" virtualness="pure">
      <type>virtual int32 PLUGIN_API</type>
      <name>countAttributes</name>
      <anchorfile>classSteinberg_1_1IAttributes2.html</anchorfile>
      <anchor>a42dfcf863fc78c31d3b71b1c8fa1a44b</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual IAttrID PLUGIN_API</type>
      <name>getAttributeID</name>
      <anchorfile>classSteinberg_1_1IAttributes2.html</anchorfile>
      <anchor>afda4d600c63756f7f1036cd3d9222d92</anchor>
      <arglist>(int32 index) const =0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IAttributes2.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPluginBase</name>
    <filename>classSteinberg_1_1IPluginBase.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>initialize</name>
      <anchorfile>classSteinberg_1_1IPluginBase.html</anchorfile>
      <anchor>a74e46aa2a4c6c7254564c83675a4c514</anchor>
      <arglist>(FUnknown *context)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>terminate</name>
      <anchorfile>classSteinberg_1_1IPluginBase.html</anchorfile>
      <anchor>af9bc6adf27fa838fe840c3615f563c95</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPluginBase.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PFactoryInfo</name>
    <filename>structSteinberg_1_1PFactoryInfo.html</filename>
    <member kind="enumeration">
      <name>FactoryFlags</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a618f56f095d5a47e04cb2a60c9fb7380</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNoFlags</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a618f56f095d5a47e04cb2a60c9fb7380aacc42d61d53f9b50d3f1f3b463ede0b5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kClassesDiscardable</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a618f56f095d5a47e04cb2a60c9fb7380a76b4fd07aeb307d814444f61a5284c36</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kLicenseCheck</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a618f56f095d5a47e04cb2a60c9fb7380a33a11b36601c0392f96fe277213bf94b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kComponentNonDiscardable</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a618f56f095d5a47e04cb2a60c9fb7380acb5680f6a81a74bdfe2cbd8c073df174</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kUnicode</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a618f56f095d5a47e04cb2a60c9fb7380aab221417e3c0a7c87707b0a5b80c9209</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kURLSize</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>adc29c2ff13d900c2f185ee95427fb06ca47905cffb4660c31c124c3689a597abe</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kEmailSize</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>adc29c2ff13d900c2f185ee95427fb06ca7659c914f304c03fe5bb5406644dd11b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNameSize</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>adc29c2ff13d900c2f185ee95427fb06ca5b9d2840f143c8288f728f5be29f638e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PFactoryInfo</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>ab8864fc4f15f667c386cef84c3abe3fe</anchor>
      <arglist>(const char8 *_vendor, const char8 *_url, const char8 *_email, int32 _flags)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PFactoryInfo</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a64254752d7cf245a6c28c7ff9429ed74</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>vendor</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>ac4707b8abe69c6961d88a0ea8d9689e0</anchor>
      <arglist>[kNameSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>url</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>aa4ccdd008796e1fda60a64aca8fc6a16</anchor>
      <arglist>[kURLSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>email</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a371bd4486f2314c56b0dc15665ac2825</anchor>
      <arglist>[kEmailSize]</arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>flags</name>
      <anchorfile>structSteinberg_1_1PFactoryInfo.html</anchorfile>
      <anchor>a8ffba1d4311e48ae488bc118f20d7edb</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PClassInfo</name>
    <filename>structSteinberg_1_1PClassInfo.html</filename>
    <member kind="enumeration">
      <name>ClassCardinality</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>aab16066f9ae5683da7458b67a11eeece</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kManyInstances</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>aab16066f9ae5683da7458b67a11eeecea5cd6f16a8a935a43a15d03e4c50782f2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kCategorySize</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea8f7919f981f4374ad578a660b8dbe01b</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kNameSize</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>a61dadd085c1777f559549e05962b2c9ea5b9d2840f143c8288f728f5be29f638e</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PClassInfo</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>abbb3f6602c841be320dfe0bc600aae0b</anchor>
      <arglist>(TUID _cid, int32 _cardinality, const char8 *_category, const char8 *_name)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PClassInfo</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>a9ac42914ded80ccb37fa6ac9d2f40d7a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>TUID</type>
      <name>cid</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>a418a6a237a27e446af982acc6cfa1f48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>cardinality</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>aaeac80bf9a3a2680cfec481edb605d5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>category</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>a32bb1f3165cfe0587146dd5a616af919</anchor>
      <arglist>[kCategorySize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1PClassInfo.html</anchorfile>
      <anchor>aa9227b03d6c37d746f40c59e671c7af1</anchor>
      <arglist>[kNameSize]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPluginFactory</name>
    <filename>classSteinberg_1_1IPluginFactory.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getFactoryInfo</name>
      <anchorfile>classSteinberg_1_1IPluginFactory.html</anchorfile>
      <anchor>a1e124d84ab835091076d89ffc9ed34a6</anchor>
      <arglist>(PFactoryInfo *info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int32 PLUGIN_API</type>
      <name>countClasses</name>
      <anchorfile>classSteinberg_1_1IPluginFactory.html</anchorfile>
      <anchor>aba7642c26ddda9eee670d8cb1589e77a</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getClassInfo</name>
      <anchorfile>classSteinberg_1_1IPluginFactory.html</anchorfile>
      <anchor>aa0b21f67e1c7089140892106126a1cf0</anchor>
      <arglist>(int32 index, PClassInfo *info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>createInstance</name>
      <anchorfile>classSteinberg_1_1IPluginFactory.html</anchorfile>
      <anchor>a95f1e3cd90ea6216b89326a1b9018598</anchor>
      <arglist>(FIDString cid, FIDString _iid, void **obj)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPluginFactory.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PClassInfo2</name>
    <filename>structSteinberg_1_1PClassInfo2.html</filename>
    <member kind="enumvalue">
      <name>kVendorSize</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a726ca809ffd3d67ab4b8476646f26635abc92cf67d5c5576b27e52051ee42eaa0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVersionSize</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a726ca809ffd3d67ab4b8476646f26635af639cc09cb2106bdbd63cc5a4be8bc89</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSubCategoriesSize</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a726ca809ffd3d67ab4b8476646f26635a9dfa52b0b8aabc14a4e753f1c2e37b5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PClassInfo2</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a7efe9cd3d1d1a1d43be9bc68ca394d74</anchor>
      <arglist>(const TUID _cid, int32 _cardinality, const char8 *_category, const char8 *_name, int32 _classFlags, const char8 *_subCategories, const char8 *_vendor, const char8 *_version, const char8 *_sdkVersion)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PClassInfo2</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a2ac28b5201097b3169efdf44e0e24620</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>TUID</type>
      <name>cid</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a418a6a237a27e446af982acc6cfa1f48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>cardinality</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>aaeac80bf9a3a2680cfec481edb605d5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>category</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a2d66c6812ef6fe8c155f83d3820e6fee</anchor>
      <arglist>[PClassInfo::kCategorySize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>aca8ccb4e8b6639590cbe65fc62cb2d91</anchor>
      <arglist>[PClassInfo::kNameSize]</arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>classFlags</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>ab5ab9135185421caad5ad8ae1d758409</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>subCategories</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a106c76c37c57aa35e42654278412ee90</anchor>
      <arglist>[kSubCategoriesSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>vendor</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a7540fc2f4cee3145736c7e3083367aba</anchor>
      <arglist>[kVendorSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>version</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>a10a16351d8da082eba2e5cbd16e6aed1</anchor>
      <arglist>[kVersionSize]</arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>sdkVersion</name>
      <anchorfile>structSteinberg_1_1PClassInfo2.html</anchorfile>
      <anchor>aefe2ed287dcf207d4f83b335ed2b78f5</anchor>
      <arglist>[kVersionSize]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPluginFactory2</name>
    <filename>classSteinberg_1_1IPluginFactory2.html</filename>
    <base>Steinberg::IPluginFactory</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getClassInfo2</name>
      <anchorfile>classSteinberg_1_1IPluginFactory2.html</anchorfile>
      <anchor>a4d8a77b545e5a30acb97e14a2b383937</anchor>
      <arglist>(int32 index, PClassInfo2 *info)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPluginFactory2.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::PClassInfoW</name>
    <filename>structSteinberg_1_1PClassInfoW.html</filename>
    <member kind="enumvalue">
      <name>kVendorSize</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a0411cd49bb5b71852cecd93bcbf0ca2dabc92cf67d5c5576b27e52051ee42eaa0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kVersionSize</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a0411cd49bb5b71852cecd93bcbf0ca2daf639cc09cb2106bdbd63cc5a4be8bc89</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kSubCategoriesSize</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a0411cd49bb5b71852cecd93bcbf0ca2da9dfa52b0b8aabc14a4e753f1c2e37b5f</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PClassInfoW</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>aa9bbacedf981912769dee51d9f2b05f0</anchor>
      <arglist>(const TUID _cid, int32 _cardinality, const char8 *_category, const char16 *_name, int32 _classFlags, const char8 *_subCategories, const char16 *_vendor, const char16 *_version, const char16 *_sdkVersion)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>PClassInfoW</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>ace7b45b143b16326d24f3783f28221ec</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fromAscii</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a4bf4cd78c431e64f21d4bd2005813e9d</anchor>
      <arglist>(const PClassInfo2 &amp;ci2)</arglist>
    </member>
    <member kind="variable">
      <type>TUID</type>
      <name>cid</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a418a6a237a27e446af982acc6cfa1f48</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>cardinality</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>aaeac80bf9a3a2680cfec481edb605d5e</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>category</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a2d66c6812ef6fe8c155f83d3820e6fee</anchor>
      <arglist>[PClassInfo::kCategorySize]</arglist>
    </member>
    <member kind="variable">
      <type>char16</type>
      <name>name</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a5ff0790e163ec6fb61e6f9f1dcc5d3ed</anchor>
      <arglist>[PClassInfo::kNameSize]</arglist>
    </member>
    <member kind="variable">
      <type>uint32</type>
      <name>classFlags</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>ab5ab9135185421caad5ad8ae1d758409</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char8</type>
      <name>subCategories</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a106c76c37c57aa35e42654278412ee90</anchor>
      <arglist>[kSubCategoriesSize]</arglist>
    </member>
    <member kind="variable">
      <type>char16</type>
      <name>vendor</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>abb5e59029c2e7b356dd264eae82de3a4</anchor>
      <arglist>[kVendorSize]</arglist>
    </member>
    <member kind="variable">
      <type>char16</type>
      <name>version</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a5361068d8071d34e2142025ab72bcc6b</anchor>
      <arglist>[kVersionSize]</arglist>
    </member>
    <member kind="variable">
      <type>char16</type>
      <name>sdkVersion</name>
      <anchorfile>structSteinberg_1_1PClassInfoW.html</anchorfile>
      <anchor>a2fb55f1840c1948ff8added4e4775684</anchor>
      <arglist>[kVersionSize]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPluginFactory3</name>
    <filename>classSteinberg_1_1IPluginFactory3.html</filename>
    <base>Steinberg::IPluginFactory2</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getClassInfoUnicode</name>
      <anchorfile>classSteinberg_1_1IPluginFactory3.html</anchorfile>
      <anchor>accec0bf7690799cf8e7c54bd4eb0f35d</anchor>
      <arglist>(int32 index, PClassInfoW *info)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>setHostContext</name>
      <anchorfile>classSteinberg_1_1IPluginFactory3.html</anchorfile>
      <anchor>a5bda020b6fbf16b7098893f85082a7bd</anchor>
      <arglist>(FUnknown *context)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPluginFactory3.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IStringResult</name>
    <filename>classSteinberg_1_1IStringResult.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual void PLUGIN_API</type>
      <name>setText</name>
      <anchorfile>classSteinberg_1_1IStringResult.html</anchorfile>
      <anchor>a78eaf1f33d72f61cc22a650d9cd42862</anchor>
      <arglist>(const char8 *text)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IStringResult.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IString</name>
    <filename>classSteinberg_1_1IString.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual void PLUGIN_API</type>
      <name>setText8</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>abf7e4c13aaa079bd4987e56faf16b05c</anchor>
      <arglist>(const char8 *text)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void PLUGIN_API</type>
      <name>setText16</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>a16d19a5fee0989684c899a2c644128b1</anchor>
      <arglist>(const char16 *text)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const char8 *PLUGIN_API</type>
      <name>getText8</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>abcc382c85b4635af91f21ac6e7864344</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const char16 *PLUGIN_API</type>
      <name>getText16</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>ad009e47ba8786fe5131ff0447b9d7f64</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void PLUGIN_API</type>
      <name>take</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>a0d918de3d760ce637f8e3aea4f0fa484</anchor>
      <arglist>(void *s, bool isWide)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual bool PLUGIN_API</type>
      <name>isWideString</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>ac9c6ce5645399ca3b21e1bb39da459ee</anchor>
      <arglist>() const =0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IString.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IUpdateHandler</name>
    <filename>classSteinberg_1_1IUpdateHandler.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>addDependent</name>
      <anchorfile>classSteinberg_1_1IUpdateHandler.html</anchorfile>
      <anchor>acb1dbf2f3ac5163422b2f27672e38523</anchor>
      <arglist>(FUnknown *object, IDependent *dependent)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>removeDependent</name>
      <anchorfile>classSteinberg_1_1IUpdateHandler.html</anchorfile>
      <anchor>a63c1f8065fe0558ee798b79b1c94bbff</anchor>
      <arglist>(FUnknown *object, IDependent *dependent)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>triggerUpdates</name>
      <anchorfile>classSteinberg_1_1IUpdateHandler.html</anchorfile>
      <anchor>a99a5bf551d3316a431568ce921feba7b</anchor>
      <arglist>(FUnknown *object, int32 message)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>deferUpdates</name>
      <anchorfile>classSteinberg_1_1IUpdateHandler.html</anchorfile>
      <anchor>a2fa8f8857db603a766ff0c355424d2e0</anchor>
      <arglist>(FUnknown *object, int32 message)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IUpdateHandler.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IDependent</name>
    <filename>classSteinberg_1_1IDependent.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="enumeration">
      <name>ChangeMessage</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a4b88d1d42482ecad4964cf7c7f35b8c1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kWillChange</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a4b88d1d42482ecad4964cf7c7f35b8c1a12898124f259d06a01da2fbec93b62b7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kChanged</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a4b88d1d42482ecad4964cf7c7f35b8c1a59b6e90764ca9aa343f99c0664410110</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kDestroyed</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a4b88d1d42482ecad4964cf7c7f35b8c1a3d6cbd03cda4f9fc9018d975f978a1f1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kWillDestroy</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a4b88d1d42482ecad4964cf7c7f35b8c1aefbe6c668f52e8e2dd07b06025691c9e</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>kStdChangeMessageLast</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a4b88d1d42482ecad4964cf7c7f35b8c1ad4ccb3c09b77e5ca9c19831a56d06712</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void PLUGIN_API</type>
      <name>update</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>a8089ea7d0dbec13b1888c754790e157d</anchor>
      <arglist>(FUnknown *changedUnknown, int32 message)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IDependent.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPtr</name>
    <filename>classSteinberg_1_1IPtr.html</filename>
    <templarg></templarg>
    <member kind="function">
      <type></type>
      <name>IPtr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a1319c719fbf775d7b691de74c00f7e74</anchor>
      <arglist>(I *ptr, bool addRef=true)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IPtr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>ab923ee4e03558fb6defc4420d53a2a09</anchor>
      <arglist>(const IPtr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IPtr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a2a1b90401eafe3554d118d398ca65d1d</anchor>
      <arglist>(const IPtr&lt; T &gt; &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IPtr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a0febc1cfbd249e5c625f0accf3879f2a</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~IPtr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>ac784799582d163bd4b0a10786dde5105</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>I *</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a4622db0a0823ec5e9801cd602f0fe794</anchor>
      <arglist>(I *ptr)</arglist>
    </member>
    <member kind="function">
      <type>IPtr &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a4b2a58247abf169f08870dc83ac941ab</anchor>
      <arglist>(const IPtr &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>IPtr &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a9206852ae8fbf62761b99fbbbecc43d8</anchor>
      <arglist>(const IPtr&lt; T &gt; &amp;other)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator I *</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a4941340f5c6521d726566bf0de9dfa75</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>I *</type>
      <name>operator-&gt;</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a93399dd839b3516b6474de96a0f8ba70</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>I *</type>
      <name>get</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a833176d8a4233f0989e7b24a44be4cfd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IPtr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>ab576e887c19d5f471fed84973232faae</anchor>
      <arglist>(const IPtr&lt; I &gt; &amp;other)</arglist>
    </member>
    <member kind="function">
      <type>IPtr&lt; I &gt; &amp;</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>af92d1664a2c1747b284ffa3b2490808c</anchor>
      <arglist>(const IPtr&lt; I &gt; &amp;_ptr)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>I *</type>
      <name>ptr</name>
      <anchorfile>classSteinberg_1_1IPtr.html</anchorfile>
      <anchor>a7c145f458643ff993b929f236d4a2ac0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::OPtr</name>
    <filename>classSteinberg_1_1OPtr.html</filename>
    <templarg></templarg>
    <base>Steinberg::IPtr</base>
    <member kind="function">
      <type></type>
      <name>OPtr</name>
      <anchorfile>classSteinberg_1_1OPtr.html</anchorfile>
      <anchor>a4b3a63e8c3856f12d05cf56956d98c13</anchor>
      <arglist>(I *p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>OPtr</name>
      <anchorfile>classSteinberg_1_1OPtr.html</anchorfile>
      <anchor>abc9725169c37ed88141040a66bd0bac8</anchor>
      <arglist>(const IPtr&lt; I &gt; &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>OPtr</name>
      <anchorfile>classSteinberg_1_1OPtr.html</anchorfile>
      <anchor>ac8069465a6cfb121a6dadcf7b0474bcf</anchor>
      <arglist>(const OPtr&lt; I &gt; &amp;p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>OPtr</name>
      <anchorfile>classSteinberg_1_1OPtr.html</anchorfile>
      <anchor>ae01694cf824294c53feba1db959e1a08</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>I *</type>
      <name>operator=</name>
      <anchorfile>classSteinberg_1_1OPtr.html</anchorfile>
      <anchor>a37a50240500e6c0d77e174c050286ca9</anchor>
      <arglist>(I *_ptr)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::UString</name>
    <filename>classSteinberg_1_1UString.html</filename>
    <member kind="function">
      <type></type>
      <name>UString</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a416d79c226552ab35ece769c8a5f59a3</anchor>
      <arglist>(char16 *buffer, int32 size)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getSize</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a89d7f5ba7151c50b9afa2e49a91cd07e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const char16 *</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a2c894a11fdd68a9206cddfc94c3c8e02</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getLength</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a3db7b83c3dfb1baa576feca0b40047d1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>UString &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a498cf35dd45ceb0bf1d20ae356204161</anchor>
      <arglist>(const char16 *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type>UString &amp;</type>
      <name>append</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a014ae12c2b6d6f3042855c5e411c0445</anchor>
      <arglist>(const char16 *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type>const UString &amp;</type>
      <name>copyTo</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a1372f0527ea276e275d9dfda80572fbe</anchor>
      <arglist>(char16 *dst, int32 dstSize) const </arglist>
    </member>
    <member kind="function">
      <type>UString &amp;</type>
      <name>fromAscii</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a3862d0f352b58aaf5159ff9751d1b3d1</anchor>
      <arglist>(const char *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type>UString &amp;</type>
      <name>assign</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>afb01c45e7e544d446309bb6f3d3c73ad</anchor>
      <arglist>(const char *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type>const UString &amp;</type>
      <name>toAscii</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a6d5a9bd9b704922faa0d453b2670068d</anchor>
      <arglist>(char *dst, int32 dstSize) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanInt</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a0a556f7bd9d9c75d72b02b0d1e3c2ab2</anchor>
      <arglist>(int64 &amp;value) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>printInt</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>ab1482d79e1ddf9a1cff1c41ea93df50e</anchor>
      <arglist>(int64 value)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>scanFloat</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a9af066c72d65f1039915061eb6fa1385</anchor>
      <arglist>(double &amp;value) const </arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>printFloat</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a0444f6da111b2df3c6289775e3eb24b6</anchor>
      <arglist>(double value, int32 precision=4)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char16 *</type>
      <name>thisBuffer</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a3c27fc65ab0075137e6846a73f0d5563</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int32</type>
      <name>thisSize</name>
      <anchorfile>classSteinberg_1_1UString.html</anchorfile>
      <anchor>a59ceecccb2f1154af32e79123fa041f4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::UStringBuffer</name>
    <filename>classSteinberg_1_1UStringBuffer.html</filename>
    <templarg>maxSize</templarg>
    <base>Steinberg::UString</base>
    <member kind="function">
      <type></type>
      <name>UStringBuffer</name>
      <anchorfile>classSteinberg_1_1UStringBuffer.html</anchorfile>
      <anchor>ad2c1eac721335328075dcbfb452dde55</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>UStringBuffer</name>
      <anchorfile>classSteinberg_1_1UStringBuffer.html</anchorfile>
      <anchor>a6f858761bd4a84aa683759e4cc4b5fbd</anchor>
      <arglist>(const char16 *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>UStringBuffer</name>
      <anchorfile>classSteinberg_1_1UStringBuffer.html</anchorfile>
      <anchor>a83089d05c32e18b3f50b2980859734cf</anchor>
      <arglist>(const char *src, int32 srcSize=-1)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char16</type>
      <name>data</name>
      <anchorfile>classSteinberg_1_1UStringBuffer.html</anchorfile>
      <anchor>afd98290b12cedfd1ec974a198bc20548</anchor>
      <arglist>[maxSize]</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>Steinberg::ViewRect</name>
    <filename>structSteinberg_1_1ViewRect.html</filename>
    <member kind="function">
      <type></type>
      <name>ViewRect</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>afcdde0147792d1103d06537c37e59ef0</anchor>
      <arglist>(int32 l=0, int32 t=0, int32 r=0, int32 b=0)</arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getWidth</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>a945705dce8930a0dc58dcb044729b1c0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>int32</type>
      <name>getHeight</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>a37bfccc82fc5f189f4de5ed444a38ed2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>left</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>ae08ef45a841fb76eef2ed11f7f6661ad</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>top</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>a5aea1a81a05b75bedc5d4c40373592d1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>right</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>a773c879226336b9859a3dec0a7f8e6ca</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int32</type>
      <name>bottom</name>
      <anchorfile>structSteinberg_1_1ViewRect.html</anchorfile>
      <anchor>a056cba400137ab9db43fdc7da2132a40</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPlugView</name>
    <filename>classSteinberg_1_1IPlugView.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>isPlatformTypeSupported</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a01def6d94a27ce545983cd6c620b1dc4</anchor>
      <arglist>(FIDString type)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>attached</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a2ead99f9833c6c607ddb4c234538bf23</anchor>
      <arglist>(void *parent, FIDString type)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>removed</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>ade7f2038d1c4688ec2817ed7c929025e</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>onWheel</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a14abcf69539cb27db99c996b7d1da538</anchor>
      <arglist>(float distance)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>onKeyDown</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a787b89b759b004b9db4c9f17d274a9bc</anchor>
      <arglist>(char16 key, int16 keyCode, int16 modifiers)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>onKeyUp</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a59b1f833385f8ee46579c6234d4fda26</anchor>
      <arglist>(char16 key, int16 keyCode, int16 modifiers)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>getSize</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>add8b0345464fd0c64d2f459308a8304e</anchor>
      <arglist>(ViewRect *size)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>onSize</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a43b99dc39f77c14ea4bfda02425a576f</anchor>
      <arglist>(ViewRect *newSize)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>onFocus</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a5043285caae8883ee50da5161a5fa3ba</anchor>
      <arglist>(TBool state)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>setFrame</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>af6462ad42a9cc3094d5784b745e95c50</anchor>
      <arglist>(IPlugFrame *frame)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>canResize</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>ad068143f3339368568b91a502da62d18</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>checkSizeConstraint</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>a042fa5aea6e389f483240b6ff6890477</anchor>
      <arglist>(ViewRect *rect)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPlugView.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Steinberg::IPlugFrame</name>
    <filename>classSteinberg_1_1IPlugFrame.html</filename>
    <base>Steinberg::FUnknown</base>
    <member kind="function" virtualness="pure">
      <type>virtual tresult PLUGIN_API</type>
      <name>resizeView</name>
      <anchorfile>classSteinberg_1_1IPlugFrame.html</anchorfile>
      <anchor>a6e59329eb18c3f160cd68fde84b5bd88</anchor>
      <arglist>(IPlugView *view, ViewRect *newSize)=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const FUID</type>
      <name>iid</name>
      <anchorfile>classSteinberg_1_1IPlugFrame.html</anchorfile>
      <anchor>ae78a44399218c930be44d3aa46521d0e</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::FUnknownPrivate</name>
    <filename>namespaceSteinberg_1_1FUnknownPrivate.html</filename>
    <member kind="function">
      <type>int32 PLUGIN_API</type>
      <name>atomicAdd</name>
      <anchorfile>namespaceSteinberg_1_1FUnknownPrivate.html</anchorfile>
      <anchor>ab48fd194b9633076ed1912cde5aeac46</anchor>
      <arglist>(int32 &amp;var, int32 d)</arglist>
    </member>
    <member kind="function">
      <type>SMTG_ALWAYS_INLINE bool</type>
      <name>iidEqual</name>
      <anchorfile>namespaceSteinberg_1_1FUnknownPrivate.html</anchorfile>
      <anchor>aa492cc7f50f5f6bfb7bd727a115e211e</anchor>
      <arglist>(const void *iid1, const void *iid2)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>Steinberg::GeoConstants</name>
    <filename>namespaceSteinberg_1_1GeoConstants.html</filename>
    <member kind="function">
      <type>Direction</type>
      <name>toOpposite</name>
      <anchorfile>namespaceSteinberg_1_1GeoConstants.html</anchorfile>
      <anchor>aff2eb279b5ae69049a3283a004a0fce2</anchor>
      <arglist>(Direction dir)</arglist>
    </member>
    <member kind="function">
      <type>Orientation</type>
      <name>toOrientation</name>
      <anchorfile>namespaceSteinberg_1_1GeoConstants.html</anchorfile>
      <anchor>a94f8ae4df9a9950ee4332d29456d12e9</anchor>
      <arglist>(Direction dir)</arglist>
    </member>
    <member kind="function">
      <type>Orientation</type>
      <name>toOrthogonalOrientation</name>
      <anchorfile>namespaceSteinberg_1_1GeoConstants.html</anchorfile>
      <anchor>a1f7b523a922afe5e4fc87ecc6dfd2a7d</anchor>
      <arglist>(Orientation dir)</arglist>
    </member>
  </compound>
</tagfile>
