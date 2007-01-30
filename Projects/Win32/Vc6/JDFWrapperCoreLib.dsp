# Microsoft Developer Studio Project File - Name="JDFWrapperCoreLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=JDFWrapperCoreLib - Win32 Debug LineOnly
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperCoreLib.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "JDFWrapperCoreLib"
# PROP Scc_LocalPath "..\.."

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Release"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Release\obj\JDFWrapperCoreLib"
# PROP Target_Dir ""
LINK32=link.exe
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "NDEBUG" /D "UNICODE" /D "_UNICODE" /D "_WINDOWS" /D "WIN32" /D "_LIB" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /Fd"..\..\..\Build\Win32\VC6\Release\JDFWrapperCoreLib" /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Debug\obj\JDFWrapperCoreLib"
# PROP Target_Dir ""
LINK32=link.exe
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "_DEBUG" /D "UNICODE" /D "_UNICODE" /D "_WINDOWS" /D "WIN32" /D "_LIB" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /FR /Fd"..\..\..\Build\Win32\VC6\Debug\JDFWrapperCoreLib" /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\JDFWrapperCoreLib_D.lib"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\ReleaseDLL"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\ReleaseDLL\obj\JDFWrapperCoreDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /w /W0 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /YX /Fd"..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperCoreDLL" /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /map /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\ReleaseDLL/JDFWrapperCoreDLL.dll" /libpath:"..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\DebugDLL"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\DebugDLL\obj\JDFWrapperCoreDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /Fd"..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperCoreDLL" /FD /GZ /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /profile /map /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperCoreDLLd.dll" /libpath:"..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "JDFWrapperCoreLib___Win32_Debug_LineOnly"
# PROP BASE Intermediate_Dir "JDFWrapperCoreLib___Win32_Debug_LineOnly"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\DebugLineOnly"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\DebugLineOnly\obj\JDFWrapperCoreLib"
# PROP Target_Dir ""
LINK32=link.exe
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /w /W0 /Gm /GX /Zi /Od /I "..\..\..\src" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\src\jdf\wrappercore" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "PROJ_JDFWrapperCoreLib" /D "PROJ_JDFTOOLSLIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /FD /GZ /c
# SUBTRACT BASE CPP /X /YX
# ADD CPP /nologo /MDd /w /W0 /GX /Zd /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src\jdf\wrappercore" /I "..\..\..\src" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /Fd"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperCoreLib" /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\JDFWrapperCoreLib_D.lib"
# ADD LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperCoreLib_D.lib"

!ENDIF 

# Begin Target

# Name "JDFWrapperCoreLib - Win32 Release"
# Name "JDFWrapperCoreLib - Win32 Debug"
# Name "JDFWrapperCoreLib - Win32 Release DLL"
# Name "JDFWrapperCoreLib - Win32 Debug DLL"
# Name "JDFWrapperCoreLib - Win32 Debug LineOnly"
# Begin Group "wrappercore"

# PROP Default_Filter ""
# Begin Group "include"

# PROP Default_Filter ".h, .hpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDuration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\JDFException.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumTypeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\JDFParser.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KElementStrings.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\MyDate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\vElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDocUserData.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ".c, .cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDuration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumTypeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\JDFParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KElementStrings.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\MyDate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\vElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDocUserData.cpp
# End Source File
# End Group
# End Group
# Begin Group "lib"

# PROP Default_Filter ".lib"
# Begin Source File

SOURCE="..\..\..\external\xerces\lib\xerces-c_2D.lib"

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\external\xerces\lib\xerces-c_2.lib"

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLLd.lib

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\Build\Win32\VC6\ReleaseDLL\JDFToolsDLL.lib

!IF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperCoreLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
