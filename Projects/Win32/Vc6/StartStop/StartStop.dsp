# Microsoft Developer Studio Project File - Name="StartStop" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=StartStop - Win32 DebugDLL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "StartStop.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "StartStop.mak" CFG="StartStop - Win32 DebugDLL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "StartStop - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "StartStop - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "StartStop - Win32 DebugDLL" (based on "Win32 (x86) Console Application")
!MESSAGE "StartStop - Win32 ReleaseDLL" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "StartStop"
# PROP Scc_LocalPath "."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "StartStop - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\Release"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Release\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "PROJ_JDFTOOLS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"libc.lib" /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Release" /libpath:"..\..\..\..\Build\Win32\Vc6\Release"

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Debug\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "PROJ_JDFTOOLS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /nodefaultlib:"libc.lib" /pdbtype:sept /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Debug" /libpath:"..\..\..\..\Build\Win32\Vc6\Debug"

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "StartStop___Win32_Debug_DLL"
# PROP BASE Intermediate_Dir "StartStop___Win32_Debug_DLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\DebugDLL"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\DebugDLL\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT BASE CPP /YX /Yc /Yu
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Od /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib wsock32.lib xerces-c_1D.lib jdftools_D.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Debug" /libpath:"..\..\..\..\Build\Win32\Vc6\Debug"
# ADD LINK32 kernel32.lib user32.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Debug" /libpath:"..\..\..\..\Build\Win32\Vc6\Debug"

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "StartStop___Win32_Release_DLL"
# PROP BASE Intermediate_Dir "StartStop___Win32_Release_DLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\Build\Win32\VC6\ReleaseDLL"
# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\ReleaseDLL\Test\obj"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\..\external\stlport\stlport" /I "..\..\..\..\external\xerces\src" /I "..\..\..\..\external\xerces\src\xercesc" /I "..\..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib xerces-c_1.lib jdftools.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Release" /libpath:"..\..\..\..\Build\Win32\Vc6\Release"
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\..\..\external\xerces\Build\Win32\VC6\Release" /libpath:"..\..\..\..\Build\Win32\Vc6\Release"

!ENDIF 

# Begin Target

# Name "StartStop - Win32 Release"
# Name "StartStop - Win32 Debug"
# Name "StartStop - Win32 DebugDLL"
# Name "StartStop - Win32 ReleaseDLL"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\..\tests\StartStop\StartStop.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Debug\jdftools_D.lib

!IF  "$(CFG)" == "StartStop - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Debug\jdftoolslib_D.lib

!IF  "$(CFG)" == "StartStop - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\external\xerces\Build\Win32\VC6\Debug\XERCES-C_1D.LIB"

!IF  "$(CFG)" == "StartStop - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\external\xerces\Build\Win32\VC6\Release\XERCES-C_1.LIB"

!IF  "$(CFG)" == "StartStop - Win32 Release"

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Release\jdftools.lib

!IF  "$(CFG)" == "StartStop - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\Build\Win32\VC6\Release\JDFToolsLib.lib

!IF  "$(CFG)" == "StartStop - Win32 Release"

!ELSEIF  "$(CFG)" == "StartStop - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 DebugDLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "StartStop - Win32 ReleaseDLL"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Target
# End Project
