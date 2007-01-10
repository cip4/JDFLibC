# Microsoft Developer Studio Generated NMAKE File, Based on JDFWrapperCoreLib.dsp
!IF "$(CFG)" == ""
CFG=JDFWrapperCoreLib - Win32 Debug LineOnly
!MESSAGE No configuration specified. Defaulting to JDFWrapperCoreLib - Win32 Debug LineOnly.
!ENDIF 

!IF "$(CFG)" != "JDFWrapperCoreLib - Win32 Release" && "$(CFG)" != "JDFWrapperCoreLib - Win32 Debug" && "$(CFG)" != "JDFWrapperCoreLib - Win32 Release DLL" && "$(CFG)" != "JDFWrapperCoreLib - Win32 Debug DLL" && "$(CFG)" != "JDFWrapperCoreLib - Win32 Debug LineOnly"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperCoreLib.mak" CFG="JDFWrapperCoreLib - Win32 Debug LineOnly"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "JDFWrapperCoreLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFWrapperCoreLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFWrapperCoreLib - Win32 Release DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperCoreLib - Win32 Debug DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperCoreLib - Win32 Debug LineOnly" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"

OUTDIR=.\..\..\..\Build\Win32\VC6\Release
INTDIR=.\..\..\..\Build\Win32\VC6\Release\obj\JDFWrapperCoreLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\Release
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperCoreLib.lib"


CLEAN :
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib.lib"
	-@erase "..\..\..\Build\Win32\VC6\Release\JDFWrapperCoreLib.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "NDEBUG" /D "_LIB" /D "WIN32" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\Release\JDFWrapperCoreLib" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperCoreLib.bsc" 
BSC32_SBRS= \
	
LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFWrapperCoreLib.lib" 
LIB32_OBJS= \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj"

"$(OUTDIR)\JDFWrapperCoreLib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"

OUTDIR=.\..\..\..\Build\Win32\VC6\Debug
INTDIR=.\..\..\..\Build\Win32\VC6\Debug\obj\JDFWrapperCoreLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\Debug
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperCoreLib_D.lib" "$(OUTDIR)\JDFWrapperCoreLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib.bsc"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib_D.lib"
	-@erase "..\..\..\Build\Win32\VC6\Debug\JDFWrapperCoreLib.idb"
	-@erase "..\..\..\Build\Win32\VC6\Debug\JDFWrapperCoreLib.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\Debug\JDFWrapperCoreLib" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperCoreLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperCoreLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFWrapperCoreLib_D.lib" 
LIB32_OBJS= \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj"

"$(OUTDIR)\JDFWrapperCoreLib_D.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"

OUTDIR=.\..\..\..\Build\Win32\VC6\ReleaseDLL
INTDIR=.\..\..\..\Build\Win32\VC6\ReleaseDLL\obj\JDFWrapperCoreDLL
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\ReleaseDLL
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperCoreDLL.dll" "$(OUTDIR)\JDFWrapperCoreLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperCoreDLL.dll"
	-@erase "$(OUTDIR)\JDFWrapperCoreDLL.exp"
	-@erase "$(OUTDIR)\JDFWrapperCoreDLL.lib"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib.bsc"
	-@erase "$(OUTDIR)\obj\JDFWrapperCoreDLL\JDFWrapperCoreDLL.map"
	-@erase "..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperCoreDLL.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=xicl6.exe
CPP_PROJ=/nologo /MD /w /W0 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\JDFWrapperCoreLib.pch" /YX /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperCoreDLL" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperCoreLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperCoreLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=xilink6.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\JDFWrapperCoreDLL.pdb" /map:"$(INTDIR)\JDFWrapperCoreDLL.map" /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib" /out:"$(OUTDIR)\JDFWrapperCoreDLL.dll" /implib:"$(OUTDIR)\JDFWrapperCoreDLL.lib" /libpath:"..\..\..\external\stlport\lib" 
LINK32_OBJS= \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj" \
	"..\..\..\external\xerces\Build\Win32\VC6\Release\xerces-c_2.lib" \
	"$(OUTDIR)\JDFToolsDLL.lib"

"$(OUTDIR)\JDFWrapperCoreDLL.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"

OUTDIR=.\..\..\..\Build\Win32\VC6\DebugDLL
INTDIR=.\..\..\..\Build\Win32\VC6\DebugDLL\obj\JDFWrapperCoreDLL
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\DebugDLL
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperCoreDLLd.dll" "$(OUTDIR)\JDFWrapperCoreLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperCoreDLLd.dll"
	-@erase "$(OUTDIR)\JDFWrapperCoreDLLd.exp"
	-@erase "$(OUTDIR)\JDFWrapperCoreDLLd.lib"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib.bsc"
	-@erase "$(OUTDIR)\obj\JDFWrapperCoreDLL\JDFWrapperCoreDLLd.map"
	-@erase "..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperCoreDLL.idb"
	-@erase "..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperCoreDLL.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperCoreDLL" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperCoreLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperCoreLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=xilink6.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /profile /map:"$(INTDIR)\JDFWrapperCoreDLLd.map" /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"$(OUTDIR)\JDFWrapperCoreDLLd.dll" /implib:"$(OUTDIR)\JDFWrapperCoreDLLd.lib" /libpath:"..\..\..\external\stlport\lib" 
LINK32_OBJS= \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj" \
	"..\..\..\external\xerces\lib\xerces-c_2D.lib" \
	"$(OUTDIR)\JDFToolsDLLd.lib"

"$(OUTDIR)\JDFWrapperCoreDLLd.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"

OUTDIR=.\..\..\..\Build\Win32\VC6\DebugLineOnly
INTDIR=.\..\..\..\Build\Win32\VC6\DebugLineOnly\obj\JDFWrapperCoreLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\DebugLineOnly
# End Custom Macros

ALL : "$(OUTDIR)\JDFWrapperCoreLib_D.lib" "$(OUTDIR)\JDFWrapperCoreLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\JDFIntegerRange.obj"
	-@erase "$(INTDIR)\JDFIntegerRange.sbr"
	-@erase "$(INTDIR)\JDFIntegerRangeList.obj"
	-@erase "$(INTDIR)\JDFIntegerRangeList.sbr"
	-@erase "$(INTDIR)\JDFNameRangeList.obj"
	-@erase "$(INTDIR)\JDFNameRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumberRangeList.obj"
	-@erase "$(INTDIR)\JDFNumberRangeList.sbr"
	-@erase "$(INTDIR)\JDFNumTypeList.obj"
	-@erase "$(INTDIR)\JDFNumTypeList.sbr"
	-@erase "$(INTDIR)\JDFParser.obj"
	-@erase "$(INTDIR)\JDFParser.sbr"
	-@erase "$(INTDIR)\JDFRange.obj"
	-@erase "$(INTDIR)\JDFRange.sbr"
	-@erase "$(INTDIR)\JDFRangeList.obj"
	-@erase "$(INTDIR)\JDFRangeList.sbr"
	-@erase "$(INTDIR)\JDFXYPairRangeList.obj"
	-@erase "$(INTDIR)\JDFXYPairRangeList.sbr"
	-@erase "$(INTDIR)\KElement.obj"
	-@erase "$(INTDIR)\KElement.sbr"
	-@erase "$(INTDIR)\KElementStrings.obj"
	-@erase "$(INTDIR)\KElementStrings.sbr"
	-@erase "$(INTDIR)\MyDate.obj"
	-@erase "$(INTDIR)\MyDate.sbr"
	-@erase "$(INTDIR)\vElement.obj"
	-@erase "$(INTDIR)\vElement.sbr"
	-@erase "$(INTDIR)\XMLDoc.obj"
	-@erase "$(INTDIR)\XMLDoc.sbr"
	-@erase "$(INTDIR)\XMLDocUserData.obj"
	-@erase "$(INTDIR)\XMLDocUserData.sbr"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib.bsc"
	-@erase "$(OUTDIR)\JDFWrapperCoreLib_D.lib"
	-@erase "..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperCoreLib.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /GX /Zd /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src\jdf\wrappercore" /I "..\..\..\src" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperCoreLib" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFWrapperCoreLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\JDFIntegerRange.sbr" \
	"$(INTDIR)\JDFIntegerRangeList.sbr" \
	"$(INTDIR)\JDFNameRangeList.sbr" \
	"$(INTDIR)\JDFNumberRangeList.sbr" \
	"$(INTDIR)\JDFNumTypeList.sbr" \
	"$(INTDIR)\JDFParser.sbr" \
	"$(INTDIR)\JDFRange.sbr" \
	"$(INTDIR)\JDFRangeList.sbr" \
	"$(INTDIR)\JDFXYPairRangeList.sbr" \
	"$(INTDIR)\KElement.sbr" \
	"$(INTDIR)\KElementStrings.sbr" \
	"$(INTDIR)\MyDate.sbr" \
	"$(INTDIR)\vElement.sbr" \
	"$(INTDIR)\XMLDoc.sbr" \
	"$(INTDIR)\XMLDocUserData.sbr"

"$(OUTDIR)\JDFWrapperCoreLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFWrapperCoreLib_D.lib" 
LIB32_OBJS= \
	"$(INTDIR)\JDFIntegerRange.obj" \
	"$(INTDIR)\JDFIntegerRangeList.obj" \
	"$(INTDIR)\JDFNameRangeList.obj" \
	"$(INTDIR)\JDFNumberRangeList.obj" \
	"$(INTDIR)\JDFNumTypeList.obj" \
	"$(INTDIR)\JDFParser.obj" \
	"$(INTDIR)\JDFRange.obj" \
	"$(INTDIR)\JDFRangeList.obj" \
	"$(INTDIR)\JDFXYPairRangeList.obj" \
	"$(INTDIR)\KElement.obj" \
	"$(INTDIR)\KElementStrings.obj" \
	"$(INTDIR)\MyDate.obj" \
	"$(INTDIR)\vElement.obj" \
	"$(INTDIR)\XMLDoc.obj" \
	"$(INTDIR)\XMLDocUserData.obj"

"$(OUTDIR)\JDFWrapperCoreLib_D.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("JDFWrapperCoreLib.dep")
!INCLUDE "JDFWrapperCoreLib.dep"
!ELSE 
!MESSAGE Warning: cannot find "JDFWrapperCoreLib.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "JDFWrapperCoreLib - Win32 Release" || "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug" || "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL" || "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL" || "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"
SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRange.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFIntegerRange.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFIntegerRange.obj"	"$(INTDIR)\JDFIntegerRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFIntegerRange.obj"	"$(INTDIR)\JDFIntegerRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFIntegerRange.obj"	"$(INTDIR)\JDFIntegerRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFIntegerRange.obj"	"$(INTDIR)\JDFIntegerRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRangeList.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFIntegerRangeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFIntegerRangeList.obj"	"$(INTDIR)\JDFIntegerRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFIntegerRangeList.obj"	"$(INTDIR)\JDFIntegerRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFIntegerRangeList.obj"	"$(INTDIR)\JDFIntegerRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFIntegerRangeList.obj"	"$(INTDIR)\JDFIntegerRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFNameRangeList.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFNameRangeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFNameRangeList.obj"	"$(INTDIR)\JDFNameRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFNameRangeList.obj"	"$(INTDIR)\JDFNameRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFNameRangeList.obj"	"$(INTDIR)\JDFNameRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFNameRangeList.obj"	"$(INTDIR)\JDFNameRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberRangeList.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFNumberRangeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFNumberRangeList.obj"	"$(INTDIR)\JDFNumberRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFNumberRangeList.obj"	"$(INTDIR)\JDFNumberRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFNumberRangeList.obj"	"$(INTDIR)\JDFNumberRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFNumberRangeList.obj"	"$(INTDIR)\JDFNumberRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFNumTypeList.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFNumTypeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFNumTypeList.obj"	"$(INTDIR)\JDFNumTypeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFNumTypeList.obj"	"$(INTDIR)\JDFNumTypeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFNumTypeList.obj"	"$(INTDIR)\JDFNumTypeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFNumTypeList.obj"	"$(INTDIR)\JDFNumTypeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\JDFParser.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFParser.obj"	"$(INTDIR)\JDFParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFParser.obj"	"$(INTDIR)\JDFParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFParser.obj"	"$(INTDIR)\JDFParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFParser.obj"	"$(INTDIR)\JDFParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFRange.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFRange.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFRange.obj"	"$(INTDIR)\JDFRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFRange.obj"	"$(INTDIR)\JDFRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFRange.obj"	"$(INTDIR)\JDFRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFRange.obj"	"$(INTDIR)\JDFRange.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFRangeList.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFRangeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFRangeList.obj"	"$(INTDIR)\JDFRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFRangeList.obj"	"$(INTDIR)\JDFRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFRangeList.obj"	"$(INTDIR)\JDFRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFRangeList.obj"	"$(INTDIR)\JDFRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairRangeList.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\JDFXYPairRangeList.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\JDFXYPairRangeList.obj"	"$(INTDIR)\JDFXYPairRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\JDFXYPairRangeList.obj"	"$(INTDIR)\JDFXYPairRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\JDFXYPairRangeList.obj"	"$(INTDIR)\JDFXYPairRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\JDFXYPairRangeList.obj"	"$(INTDIR)\JDFXYPairRangeList.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\KElement.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\KElement.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\KElement.obj"	"$(INTDIR)\KElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\KElement.obj"	"$(INTDIR)\KElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\KElement.obj"	"$(INTDIR)\KElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\KElement.obj"	"$(INTDIR)\KElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\KElementStrings.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\KElementStrings.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\KElementStrings.obj"	"$(INTDIR)\KElementStrings.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\KElementStrings.obj"	"$(INTDIR)\KElementStrings.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\KElementStrings.obj"	"$(INTDIR)\KElementStrings.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\KElementStrings.obj"	"$(INTDIR)\KElementStrings.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\MyDate.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\MyDate.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\MyDate.obj"	"$(INTDIR)\MyDate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\MyDate.obj"	"$(INTDIR)\MyDate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\MyDate.obj"	"$(INTDIR)\MyDate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\MyDate.obj"	"$(INTDIR)\MyDate.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\vElement.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\vElement.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\vElement.obj"	"$(INTDIR)\vElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\vElement.obj"	"$(INTDIR)\vElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\vElement.obj"	"$(INTDIR)\vElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\vElement.obj"	"$(INTDIR)\vElement.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\XMLDoc.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\XMLDoc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\XMLDoc.obj"	"$(INTDIR)\XMLDoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\XMLDoc.obj"	"$(INTDIR)\XMLDoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\XMLDoc.obj"	"$(INTDIR)\XMLDoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\XMLDoc.obj"	"$(INTDIR)\XMLDoc.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\wrappercore\XMLDocUserData.cpp

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"


"$(INTDIR)\XMLDocUserData.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"


"$(INTDIR)\XMLDocUserData.obj"	"$(INTDIR)\XMLDocUserData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"


"$(INTDIR)\XMLDocUserData.obj"	"$(INTDIR)\XMLDocUserData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"


"$(INTDIR)\XMLDocUserData.obj"	"$(INTDIR)\XMLDocUserData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"


"$(INTDIR)\XMLDocUserData.obj"	"$(INTDIR)\XMLDocUserData.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

