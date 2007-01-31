# Microsoft Developer Studio Project File - Name="BookJDF" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=BOOKJDF - WIN32 DEBUG
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "BookJDF.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "BookJDF.mak" CFG="BOOKJDF - WIN32 DEBUG"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "BookJDF - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "BookJDF - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "BookJDF - Win32 Debug DLL" (based on "Win32 (x86) Console Application")
!MESSAGE "BookJDF - Win32 Release DLL" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "BookJDF"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\Release\"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Release\obj\test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\include" /I "..\..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "UNICODE" /D "_UNICODE" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /profile /machine:I386 /nodefaultlib:"libc.lib" /libpath:"..\..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Debug\obj\test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\include" /I "..\..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "UNICODE" /D "_UNICODE" /FR /YX"jdf.h" /FD /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /profile /debug /machine:I386 /nodefaultlib:"libc.lib" /libpath:"..\..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "BookJDF___Win32_Debug_DLL"
# PROP BASE Intermediate_Dir "BookJDF___Win32_Debug_DLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\DebugDLL"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\DebugDLL\obj\test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\src" /I "..\..\..\..\tests\TestWrapper" /I "..\..\..\..\src\jdf\wrapper" /I "..\..\..\..\src\jdf\wrappercore" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "TYPESAFE" /FR /YX"jdf.h" /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\include" /I "..\..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "UNICODE" /D "_UNICODE" /D "_REENTRANT" /FR /YX"jdf.h" /FD /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /profile /debug /machine:I386 /nodefaultlib:"libc.lib"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /profile /debug /machine:I386 /nodefaultlib:"libc.lib" /libpath:"..\..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "BookJDF___Win32_Release_DLL"
# PROP BASE Intermediate_Dir "BookJDF___Win32_Release_DLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\ReleaseDLL\"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\ReleaseDLL\obj\test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\src" /I "..\..\..\..\tests\TestWrapper" /I "..\..\..\..\src\jdf\wrapper" /I "..\..\..\..\src\jdf\wrappercore" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\include" /I "..\..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /profile /machine:I386 /nodefaultlib:"libc.lib" /out:"S:\cmpINFRA_CommonParsers\JDFOpenSrc\Build\Win32\VC6\Release\BookJDF.exe"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /profile /machine:I386 /nodefaultlib:"libc.lib" /libpath:"..\..\..\..\external\stlport\lib"

!ENDIF 

# Begin Target

# Name "BookJDF - Win32 Release"
# Name "BookJDF - Win32 Debug"
# Name "BookJDF - Win32 Debug DLL"
# Name "BookJDF - Win32 Release DLL"
# Begin Group "src"

# PROP Default_Filter ".cpp,.c"
# Begin Source File

SOURCE=..\..\..\..\tests\TestWrapper\BookJDF.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\tests\TestWrapper\MyArgs.cpp
# End Source File
# End Group
# Begin Group "include"

# PROP Default_Filter ".hpp,.h"
# Begin Source File

SOURCE=..\..\..\..\tests\TestWrapper\MyArgs.h
# End Source File
# End Group
# Begin Group "lib"

# PROP Default_Filter ".lib"
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\Vc6\Debug\jdftoolslib_D.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Release\JDFWrapperLib.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib_D.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\Vc6\Release\JDFToolsLib.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperDLLd.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLLd.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\ReleaseDLL\JDFToolsDLL.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperDLL.lib

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\external\xerces\lib\xerces-c_2.lib"

!IF  "$(CFG)" == "BookJDF - Win32 Release"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\external\xerces\lib\xerces-c_2D.lib"

!IF  "$(CFG)" == "BookJDF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "BookJDF - Win32 Release DLL"

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
