# Microsoft Developer Studio Project File - Name="drawtest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=drawtest - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "drawtest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "drawtest.mak" CFG="drawtest - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "drawtest - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "drawtest - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "drawtest - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DRAWTEST_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\..\.." /I "..\..\vstgui" /I "..\..\..\public.sdk\source\vst2.x" /I "..\..\libpng" /I "..\..\zlib" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DRAWTEST_EXPORTS" /D USE_LIBPNG=1 /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"../../../public.sdk/samples/vst2.x/win.vc6/Release/drawtest.dll"

!ELSEIF  "$(CFG)" == "drawtest - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DRAWTEST_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\..\.." /I "..\..\vstgui" /I "..\..\..\public.sdk\source\vst2.x" /I "..\..\libpng" /I "..\..\zlib" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DRAWTEST_EXPORTS" /D USE_LIBPNG=1 /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"../../../public.sdk/samples/vst2.x/win.vc6/Debug/drawtest.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "drawtest - Win32 Release"
# Name "drawtest - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "libpng"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\libpng\png.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\png.h
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngconf.h
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngerror.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pnggccrd.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngget.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngmem.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngpread.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngread.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngrio.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngrtran.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngrutil.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngset.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngtrans.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngvcrd.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwio.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwrite.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwtran.c
# End Source File
# Begin Source File

SOURCE=..\..\libpng\pngwutil.c
# End Source File
# End Group
# Begin Group "zlib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\zlib\adler32.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\compress.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\crc32.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\deflate.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\gzio.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\infback.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\inffast.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\inflate.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\inftrees.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\trees.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\uncompr.c
# End Source File
# Begin Source File

SOURCE=..\..\zlib\zlib.h
# End Source File
# Begin Source File

SOURCE=..\..\zlib\zutil.c
# End Source File
# End Group
# Begin Group "vst2.x"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\PUBLIC.SDK\source\vst2.x\aeffeditor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\public.sdk\source\vst2.x\audioeffect.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PUBLIC.SDK\source\vst2.x\audioeffect.h
# End Source File
# Begin Source File

SOURCE=..\..\..\public.sdk\source\vst2.x\audioeffectx.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PUBLIC.SDK\source\vst2.x\audioeffectx.h
# End Source File
# End Group
# Begin Group "vstgui"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\vstgui\aeffguieditor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\aeffguieditor.h
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\cfileselector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\cfileselector.h
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\cscrollview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\cscrollview.h
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\ctabview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\ctabview.h
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\vstcontrols.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\vstcontrols.h
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\vstgui.cpp
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\vstgui.h
# End Source File
# Begin Source File

SOURCE=..\..\vstgui\vstkeycode.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\source\controlsgui.cpp
# End Source File
# Begin Source File

SOURCE=..\source\controlsgui.h
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtesteditor.cpp
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtesteditor.h
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtesteffect.cpp
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtesteffect.h
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtestmain.cpp
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtestview.cpp
# End Source File
# Begin Source File

SOURCE=..\source\pdrawtestview.h
# End Source File
# Begin Source File

SOURCE=..\source\pprimitivesviews.cpp
# End Source File
# Begin Source File

SOURCE=..\source\pprimitivesviews.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\win\drawtest.def
# End Source File
# Begin Source File

SOURCE=..\win\drawtest.rc
# End Source File
# End Target
# End Project
