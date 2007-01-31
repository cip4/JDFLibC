# Microsoft Developer Studio Project File - Name="cppunit" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=cppunit - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cppunit.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cppunit.mak" CFG="cppunit - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cppunit - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "cppunit - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "cppunit"
# PROP Scc_LocalPath "..\..\..\..\.."
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "cppunit - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\..\Build\Win32\VC6\CPPUnit\Release"
# PROP Intermediate_Dir "..\..\..\..\..\Build\Win32\VC6\CPPUnit\Release\obj\cppunit"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GX /O2 /I "..\..\..\..\..\external\stlport\stlport" /I "..\..\..\..\..\external\xerces\include" /I "..\..\..\..\..\..\..\devTools_Base\common\CppUnit\include" /I "..\..\..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "UNICODE" /D "_UNICODE" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 stlport_vc6.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib JDFWrapperLib.lib JDFWrapperCoreLib.lib JDFToolsLib.lib wsock32.lib cppunit.lib /nologo /subsystem:console /machine:I386 /libpath:"..\..\..\..\..\external\stlport\lib" /libpath:"..\..\..\..\..\..\..\devTools_Base\common\CppUnit\lib" /libpath:"..\..\..\..\..\Build\Win32\VC6\Release"

!ELSEIF  "$(CFG)" == "cppunit - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\..\Build\Win32\VC6\CPPUnit\Debug"
# PROP Intermediate_Dir "..\..\..\..\..\Build\Win32\VC6\CPPUnit\Debug\obj\cppunit"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\..\..\..\..\external\stlport\stlport" /I "..\..\..\..\..\external\xerces\include" /I "..\..\..\..\..\..\..\devTools_Base\common\CppUnit\include" /I "..\..\..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "UNICODE" /D "_UNICODE" /D "JDFWRAPPER_LIB" /FR /YX /FD /GZ /c
# SUBTRACT CPP /X
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 stlport_vc6.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib cppunitd.lib jdftoolslib_D.lib JDFWrapperCoreLib_D.lib JDFWrapperLib_D.lib wsock32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept /libpath:"..\..\..\..\..\external\stlport\lib" /libpath:"..\..\..\..\..\..\..\devTools_Base\common\CppUnit\lib" /libpath:"..\..\..\..\..\Build\Win32\VC6\Debug"

!ENDIF 

# Begin Target

# Name "cppunit - Win32 Release"
# Name "cppunit - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFAuditPoolTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFElementTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFNodeProductTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFNodeTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFResourceTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFStateTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\KElementTest.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\main.cpp"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\XMLDocTest.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFAuditPoolTest.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFElementTest.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFNodeProductTest.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFNodeTest.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFResourceTest.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\JDFStateTest.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\KElementTest.h"

!IF  "$(CFG)" == "cppunit - Win32 Release"

!ELSEIF  "$(CFG)" == "cppunit - Win32 Debug"

# PROP Intermediate_Dir "..\..\..\..\Build\Win32\VC6\Debug\obj\cppunit"

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\cppunit-tests\XMLDocTest.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
