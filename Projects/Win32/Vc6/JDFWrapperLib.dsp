# Microsoft Developer Studio Project File - Name="JDFWrapperLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=JDFWrapperLib - Win32 Debug LineOnly
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperLib.mak" CFG="JDFWrapperLib - Win32 Debug LineOnly"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "JDFWrapperLib - Win32 Release DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperLib - Win32 Debug DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFWrapperLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFWrapperLib - Win32 Debug LineOnly" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "JDFWrapperLib"
# PROP Scc_LocalPath "..\.."

!IF  "$(CFG)" == "JDFWrapperLib - Win32 Release DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\ReleaseDLL"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\ReleaseDLL\obj\JDFWrapperDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /w /W0 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /YX /Fd"..\..\..\Build\Win32\VC6\ReleaseDLL\JDFWrapperDLL" /FD /c
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /map /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\ReleaseDLL/JDFWrapperDLL.dll" /libpath:"..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\DebugDLL"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\DebugDLL\obj\JDFWrapperDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /Fd"..\..\..\Build\Win32\VC6\DebugDLL\JDFWrapperDLL" /FD /GZ /c
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\DebugDLL/JDFWrapperDLLd.dll" /pdbtype:sept /libpath:"..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "JDFWrapperLib___Win32_Debug"
# PROP BASE Intermediate_Dir "JDFWrapperLib___Win32_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Debug\obj\JDFWrapperLib"
# PROP Target_Dir ""
LINK32=link.exe
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /w /W0 /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\src" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\src\jdf\wrappercore" /I "..\..\..\src\jdf\wrapper" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "PROJ_JDFWrapperLib" /D "PROJ_JDFTOOLSLIB" /D "_REENTRANT" /D "_STLP_NO_OWN_IOSTREAMS" /D "UNICODE" /D "_UNICODE" /FR /FD /GZ /c
# SUBTRACT BASE CPP /X /YX
# ADD CPP /nologo /MDd /w /W0 /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "_DEBUG" /D "UNICODE" /D "_UNICODE" /D "_WINDOWS" /D "WIN32" /D "_LIB" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /FR /Fd"..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib" /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib_D_STLP.lib"
# ADD LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib_D.lib"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "JDFWrapperLib___Win32_Release"
# PROP BASE Intermediate_Dir "JDFWrapperLib___Win32_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Release"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Release\obj\JDFWrapperLib"
# PROP Target_Dir ""
LINK32=link.exe
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\src" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\src\jdf\wrappercore" /I "..\..\..\src\jdf\wrapper" /D "NDEBUG" /D "UNICODE" /D "_UNICODE" /D "_LIB" /D "WIN32" /D "PROJ_JDFWrapperLib" /D "PROJ_JDFTOOLSLIB" /D "_REENTRANT" /D "_STLP_NO_OWN_IOSTREAMS" /FR /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "NDEBUG" /D "UNICODE" /D "_UNICODE" /D "_WINDOWS" /D "WIN32" /D "_LIB" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /FR /Fd"..\..\..\Build\Win32\VC6\Release\JDFWrapperLib" /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Release\JDFWrapperLib_STLP.lib"
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "JDFWrapperLib___Win32_Debug_LineOnly"
# PROP BASE Intermediate_Dir "JDFWrapperLib___Win32_Debug_LineOnly"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\DebugLineOnly"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\DebugLineOnly\obj\JDFWrapperLib"
# PROP Target_Dir ""
LINK32=link.exe
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /w /W0 /GX /Zi /Od /I "..\..\..\src" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\src\jdf\wrappercore" /I "..\..\..\src\jdf\wrapper" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "PROJ_JDFWrapperLib" /D "PROJ_JDFTOOLSLIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /FD /GZ /c
# SUBTRACT BASE CPP /X /YX
# ADD CPP /nologo /MDd /w /W0 /GX /Zd /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\src\jdf" /I "..\..\..\external\xerces\include" /I "..\..\..\src" /D "_DEBUG" /D "_WINDOWS" /D "WIN32" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /Fd"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperLib" /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\JDFWrapperLib_D.lib"
# ADD LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFWrapperLib_D.lib"

!ENDIF 

# Begin Target

# Name "JDFWrapperLib - Win32 Release DLL"
# Name "JDFWrapperLib - Win32 Debug DLL"
# Name "JDFWrapperLib - Win32 Debug"
# Name "JDFWrapperLib - Win32 Release"
# Name "JDFWrapperLib - Win32 Debug LineOnly"
# Begin Group "JDFWrapper"

# PROP Default_Filter ""
# Begin Group "JDFNode"

# PROP Default_Filter ""
# Begin Group "src No.1"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAmountPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAuditPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBusinessInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCounterReset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreated.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeleted.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFError.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFCNKey.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLocation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMerged.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModified.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModulePhase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotification.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPartAmount.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPartStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPhaseTime.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProcessRun.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLinkPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpawned.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSystemTimeSet.cpp
# End Source File
# End Group
# Begin Group "include No.1"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAmountPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestorPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAuditPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcode.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBusinessInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCounterReset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreated.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeleted.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFError.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFCNKey.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLocation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMerged.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModified.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModulePhase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNode.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotification.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPartAmount.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPartStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPhaseTime.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProcessRun.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLinkPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpawned.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSystemTimeSet.h
# End Source File
# End Group
# End Group
# Begin Group "JDFJMF"

# PROP Default_Filter ""
# Begin Group "src No.3"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAcknowledge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdded.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChangedAttribute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChangedPath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCommand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreateLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreateResource.cpp
# End Source File
# Begin Source File
					
SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployeeDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlushedResources.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlushQueueParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlushResourceParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFController.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMF.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobPhase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFKnownMsgQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModuleStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMoveResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMsgFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNewComment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNewJDFCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNewJDFQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoResp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObservationTarget.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPipeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQuery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryDefList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPosParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPriParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueSubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRemoved.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRemoveLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRequestQueueEntryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePullParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResponse.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFReturnQueueEntryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShutDownCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStopPersChParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubscription.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackResult.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrigger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWakeUpCmdParams.cpp
# End Source File
# End Group
# Begin Group "include No.3"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAcknowledge.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdded.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChangedAttribute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChangedPath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCommand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreateLink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreateResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployeeDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlushedResources.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlushQueueParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlushResourceParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFController.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMF.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobPhase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFKnownMsgQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModuleStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMoveResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMsgFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNewComment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNewJDFCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNewJDFQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfoResp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObservationTarget.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPipeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQuery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryDefList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPosParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPriParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueSubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRemoved.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRemoveLink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRequestQueueEntryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePullParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResponse.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFReturnQueueEntryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShutDownCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStopPersChParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubscription.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackResult.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrigger.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWakeUpCmdParams.h
# End Source File
# End Group
# End Group
# Begin Group "JDFResources"

# PROP Default_Filter ""
# Begin Group "IntentResources"

# PROP Default_Filter ""
# Begin Group "src No.4"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArtDeliveryIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntentResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPackingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProductionIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSizeIntent.cpp
# End Source File
# End Group
# Begin Group "include No.4"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArtDeliveryIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntentResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPackingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProductionIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSizeIntent.h
# End Source File
# End Group
# End Group
# Begin Group "IntentSubelements"

# PROP Default_Filter ""
# Begin Group "src No.5"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArtDelivery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBookCase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsUsed.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreditCard.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItemIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEdgeGluing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHardCoverBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsert.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPayment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPricing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRingBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSoftCoverBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpan.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTabs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTape.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSealing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBinding.cpp
# End Source File
# End Group
# Begin Group "include No.5"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArtDelivery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBookCase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsUsed.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreditCard.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItemIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEdgeGluing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHardCoverBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsert.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPayment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPricing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRingBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSoftCoverBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpan.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTabs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTape.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSealing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBinding.h
# End Source File
# End Group
# End Group
# Begin Group "ProcessResources"

# PROP Default_Filter ".cpp"
# Begin Group "src No.6"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAddress.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalSuccess.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAssembly.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAssetListCreationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAutomatedOverprintParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcodeCompParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarCodeDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcodeReproParams.cpp
# End Source File
# Begin Source File
							
SOURCE=..\..\..\src\jdf\wrapper\JDFBinderySignature.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBlockPreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxPackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBufferParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBundle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBundlingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFByteMap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCaseMakingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCasingInParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCIELABMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCollectingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorControlStrip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorMeasurementConditions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCompany.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComponent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContact.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContactCopyParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFConventionalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCostCenter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoverApplicationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreasingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutBlock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCuttingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBMergeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBRules.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBSchema.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBSelection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDensityMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevelopingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNSpace.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDieLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalDeliveryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisjointing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisposition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDividingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFElementColorParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployee.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheetGluingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFExposedMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeedingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFitPolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFold.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontPolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFormatConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGatheringParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueLine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGluingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHeadBandApplicationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHole.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleLine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIdentificationField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageCompressionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageReplacementParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageSetterParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFExternalImpositionTemplate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneCalculationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretedPDLData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJacketingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJBIG2Params.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJPEG2000Params.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLabelingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutPreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongitudinalRibbonOperationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFManualLaborParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaLayers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaSource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMISDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObjectResolution.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOCGControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOrderingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageAssignedList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPallet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPalletizingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFToPSConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDLResourceAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerforatingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlaceHolderResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlateCopyParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAnalysis.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInventory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightReport.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightReportRulePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreviewGenerationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPrintCondition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPrintRollingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPSToPDFConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQualityControlParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQualityControlResult.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterRibbon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRenderingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceDefinitionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRingBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRollStand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScanParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScavengerArea.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationControlParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShrinkingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpinePreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpineTapingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrappingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrippingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSurface.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSealingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurve.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurvePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferFunctionControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrapRegion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrimmingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFVerificationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWrappingParams.cpp
# End Source File
# End Group
# Begin Group "include No.6"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAddress.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalSuccess.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAssembly.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAssetListCreationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAutomatedOverprintParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcodeCompParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarCodeDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcodeReproParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBinderySignature.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBlockPreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxPackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBufferParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBundle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBundlingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFByteMap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCaseMakingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCasingInParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCIELABMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCollectingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorControlStrip.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorMeasurementConditions.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCompany.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComponent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContact.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContactCopyParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFConventionalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCostCenter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoverApplicationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreasingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutBlock.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCuttingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBMergeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBRules.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBSchema.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBSelection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDensityMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevelopingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNSpace.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDieLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalDeliveryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisjointing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisposition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDividingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFElementColorParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmbossingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployee.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheetGluingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFExposedMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFExternalImpositionTemplate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeedingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFitPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFold.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFormatConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGatheringParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueLine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGluingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHeadBandApplicationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHole.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleLine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIdentificationField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageCompressionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageReplacementParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageSetterParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInk.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneCalculationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretedPDLData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJacketingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJBIG2Params.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJPEG2000Params.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLabelingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutPreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongitudinalRibbonOperationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFManualLaborParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaLayers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaSource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMISDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObjectResolution.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOCGControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOrderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageAssignedList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPallet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPalletizingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFToPSConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDLResourceAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerforatingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlaceHolderResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlateCopyParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAnalysis.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInventory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightReport.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightReportRulePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreview.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreviewGenerationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPrintCondition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPrintRollingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPSToPDFConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQualityControlParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQualityControlResult.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterRibbon.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRenderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceDefinitionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRingBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRollStand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScanParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScavengerArea.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationControlParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShrinkingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpinePreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpineTapingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrappingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrippingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSurface.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSealingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurve.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurvePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferFunctionControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrapRegion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrimmingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFVerificationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWrappingParams.h
# End Source File
# End Group
# End Group
# Begin Group "ProcessSubelements"

# PROP Default_Filter ""
# Begin Group "src No.7"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdvancedParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArgumentValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAssemblySection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBasicPreflightTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindingQualityParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxArgument.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxFoldAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxToBoxDifference.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBundleItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCCITTFaxParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCollatingItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantZoneDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceSubstitute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCrease.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCylinderPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDCTParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDependencies.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDrop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicInput.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmboss.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeeder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeederQualityParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlateParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFolderProduction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIcon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIconList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPCover.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPFinishing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPFolding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPHoleMaking.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPImageShift.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPJobSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPTrimming.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageCompression.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageShift.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayerDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayerList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElementPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongFold.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongGlue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongPerforate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongSlit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLZWParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMarkObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageCell.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFInterpretingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFXParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerforate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPixelColorant.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightArgument.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightDetail.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInstance.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInstanceDetail.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRError.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroupOccurence.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroupOccurenceBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPrintConditionColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPROccurence.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProductionPath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProperties.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRRule.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRRuleAttr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQualityMeasurement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceParam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScore.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreenSelector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignature.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignatureCell.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStringListValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripCellParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThinPDFParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFEmbeddedFile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFFormatParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFtag.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurveSet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingOrder.cpp
# End Source File
# End Group
# Begin Group "include No.7"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdvancedParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArgumentValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAssemblySection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBasicPreflightTest.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBindingQualityParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxArgument.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxFoldAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBoxToBoxDifference.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBundleItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCCITTFaxParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCollatingItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantZoneDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceSubstitute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCrease.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCylinderPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDCTParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDependencies.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDrop.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicInput.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmboss.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeeder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeederQualityParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFlateParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFolderProduction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIcon.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIconList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPCover.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPFinishing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPFolding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPHoleMaking.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPImageShift.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPJobSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIDPTrimming.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageCompression.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImageShift.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayerDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayerList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElementPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongFold.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongGlue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongPerforate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongSlit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLZWParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMarkObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParam.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageCell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPageData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFInterpretingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFXParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerforate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPixelColorant.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightArgument.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraint.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightDetail.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInstance.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInstanceDetail.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRError.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroupOccurence.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRGroupOccurenceBase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPrintConditionColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPROccurence.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProductionPath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProperties.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRRule.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPRRuleAttr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQualityMeasurement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceParam.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScore.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreenSelector.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignature.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignatureCell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStringListValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStripCellParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThinPDFParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFEmbeddedFile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFFormatParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTIFFtag.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurveSet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\Module.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\ModulePool.h
# End Source File
# End Group
# End Group
# End Group
# Begin Group "JDFDeviceCapability"

# PROP Default_Filter ""
# Begin Group "src No.8"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFActionPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBooleanEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBooleanState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFcall.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFchoice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevCap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevCapPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevCaps.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceCap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisplayGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisplayGroupPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEnumerationEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEnumerationState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeatureAttribute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeaturePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIsPresentEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFmacro.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMacroPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMatrixEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMatrixState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModule.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModuleCap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModulePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFnot.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFotherwise.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFPathEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFPathState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerformance.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRectangleEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRectangleState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStringEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStringState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTestPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTestRef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFValueLoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFwhen.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFxor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairEvaluation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairState.cpp
# End Source File
# End Group
# Begin Group "include No.8"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFActionPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBooleanEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBooleanState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFcall.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFchoice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevCap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevCapPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevCaps.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceCap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisplayGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisplayGroupPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEnumerationEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEnumerationState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeatureAttribute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFeaturePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIsPresentEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFmacro.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMacroPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMatrixEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMatrixState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModule.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModuleCap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModulePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNameState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFnot.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFotherwise.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFPathEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFPathState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerformance.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRectangleEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRectangleState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStringEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStringState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTest.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTestPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTestRef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFValueLoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFwhen.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFxor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairEvaluation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFXYPairState.h
# End Source File
# End Group
# End Group
# Begin Group "JDFCore"

# PROP Default_Filter ""
# Begin Group "src No.9"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFParamsFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRefElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSourceResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrings.cpp
# End Source File
# End Group
# Begin Group "include No.9"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDF.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRefElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSourceResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStrings.h
# End Source File
# End Group
# End Group
# Begin Group "Auto"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcodeCompParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcodeCompParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarCodeDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarCodeDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcodeReproParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcodeReproParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBendingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBendingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxFoldAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxFoldAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxFoldingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxFoldingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreateLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreateLink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreateResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreateResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCylinderLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCylinderLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCylinderLayoutPreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCylinderLayoutPreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCylinderPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCylinderPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCapPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCapPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDieLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDieLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExternalImpositionTemplate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExternalImpositionTemplate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExtraValues.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExtraValues.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushQueueInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushQueueInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFolderProduction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFolderProduction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldOperation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldOperation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGangCmdFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGangCmdFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGangInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGangInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGangQuFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGangQuFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGeneralID.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGeneralID.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentical.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentical.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJBIG2Params.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJBIG2Params.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJPEG2000Params.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElementPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElementPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElementProductionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElementProductionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLot.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLot.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaLayers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaLayers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMiscConsumable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMiscConsumable.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModifyNodeCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModifyNodeCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModule.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModule.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModuleCap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModuleCap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModulePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModulePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMoveResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMoveResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewComment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewComment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOCGControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOCGControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageAssignedList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageAssignedList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLCreationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLCreationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionPath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionPath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPublishingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPublishingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRasterReadingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRasterReadingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegistration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegistration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoveLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoveLink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoUpdateJDFCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoUpdateJDFCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoUsageCounter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoUsageCounter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWebInlineFinishingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWebInlineFinishingParams.h
# End Source File

# Begin Group "AutoNode"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.1"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAmountPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBusinessInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCounterReset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreated.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeleted.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoError.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEvent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFCNKey.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLocation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMerged.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModified.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModulePhase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotification.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPartStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPhaseTime.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProcessRun.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpawned.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSystemTimeSet.cpp
# End Source File
# End Group
# Begin Group "AutoH No.1"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAmountPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestorPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcode.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBusinessInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCounterReset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreated.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeleted.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoError.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEvent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFCNKey.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLocation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMerged.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModified.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModulePhase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotification.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPartStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPhaseTime.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProcessRun.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpawned.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSystemTimeSet.h
# End Source File
# End Group
# End Group
# Begin Group "AutoJMF"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.3"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAcknowledge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdded.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedAttribute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedPath.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCommand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployeeDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushedResources.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushQueueParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushResourceParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFController.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMF.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobPhase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoKnownMsgQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessageService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModuleStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMsgFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewJDFCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewJDFQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoResp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObservationTarget.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPipeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQuery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryDefList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPosParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPriParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueSubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoved.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRequestQueueEntryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourcePullParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResponse.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoReturnQueueEntryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShutDownCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStopPersChParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubscription.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackResult.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrigger.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWakeUpCmdParams.cpp
# End Source File
# End Group
# Begin Group "AutoH No.3"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAcknowledge.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdded.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedAttribute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedPath.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCommand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployeeDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushedResources.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushQueueParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlushResourceParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFController.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMF.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobPhase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoKnownMsgQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessageService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoModuleStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMsgFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewJDFCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNewJDFQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInfoResp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObservationTarget.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPipeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQuery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryDefList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPosParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPriParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueSubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoved.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRequestQueueEntryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourcePullParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResponse.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoReturnQueueEntryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShutDownCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStopPersChParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubscription.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackResult.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrigger.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWakeUpCmdParams.h
# End Source File
# End Group
# End Group
# Begin Group "AutoResources"

# PROP Default_Filter ""
# Begin Group "AutoIntentResources"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.4"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDeliveryIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLaminatingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSizeIntent.cpp
# End Source File
# End Group
# Begin Group "AutoH No.4"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDeliveryIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLaminatingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSizeIntent.h
# End Source File
# End Group
# End Group
# Begin Group "AutoIntentSubelements"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.5"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDelivery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBookCase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorsUsed.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreditCard.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItemIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEdgeGluing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHardCoverBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsert.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPayment.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPricing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSoftCoverBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTabs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTape.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSealing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBinding.cpp
# End Source File
# End Group
# Begin Group "AutoH No.5"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDelivery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBookCase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorsUsed.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreditCard.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItemIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEdgeGluing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHardCoverBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsert.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPayment.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPricing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSoftCoverBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTabs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTape.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSealing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBinding.h
# End Source File
# End Group
# End Group
# Begin Group "AutoProcessResources"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.6"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAddress.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalSuccess.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssembly.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssetListCreationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAutomatedOverprintParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBinderySignature.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBlockPreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxPackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBufferParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundle.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundlingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoByteMap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCaseMakingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCasingInParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCIELABMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollectingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorControlStrip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorMeasurementConditions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCompany.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComponent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContact.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContactCopyParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoConventionalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCostCenter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoverApplicationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreasingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutBlock.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCuttingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBMergeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBRules.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBSchema.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBSelection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDensityMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevelopingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNSpace.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalDeliveryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisjointing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisposition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDividingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoElementColorParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployee.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheetGluingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExposedMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeedingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFitPolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFold.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontPolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFormatConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGatheringParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueLine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGluingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHeadBandApplicationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHole.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleLine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentificationField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageCompressionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageReplacementParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageSetterParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneCalculationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretedPDLData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJacketingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLabelingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLaminatingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutPreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongitudinalRibbonOperationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoManualLaborParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaSource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMISDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObjectResolution.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOrderingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPallet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPalletizingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFToPSConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLResourceAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforatingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlaceHolderResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlateCopyParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAnalysis.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInventory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightReport.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightReportRulePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreviewGenerationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintCondition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintRollingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPSToPDFConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityControlParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityControlResult.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterRibbon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRenderingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceDefinitionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRollStand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRunList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScanParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScavengerArea.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationControlParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShrinkingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpinePreparationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpineTapingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrappingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrippingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSurface.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSealingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurve.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurvePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferFunctionControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrapRegion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrimmingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVerificationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWrappingParams.cpp
# End Source File
# End Group
# Begin Group "AutoH No.6"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAddress.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalSuccess.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssembly.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssetListCreationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAutomatedOverprintParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBinderySignature.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBlockPreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxPackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBufferParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundle.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundlingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoByteMap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCaseMakingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCasingInParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCIELABMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollectingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorControlStrip.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorMeasurementConditions.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCompany.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComponent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContact.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContactCopyParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoConventionalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCostCenter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoverApplicationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreasingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutBlock.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCuttingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBMergeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBRules.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBSchema.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBSelection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDensityMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevelopingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNSpace.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalDeliveryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisjointing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisposition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDividingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoElementColorParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmbossingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployee.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheetGluingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExposedMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeedingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFitPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFold.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFormatConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGatheringParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueLine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGluingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHeadBandApplicationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHole.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleLine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentificationField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageCompressionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageReplacementParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageSetterParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInk.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneCalculationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretedPDLData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJacketingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJPEG2000Params.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLabelingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLaminatingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutPreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongitudinalRibbonOperationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoManualLaborParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaSource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMISDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObjectResolution.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOrderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPallet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPalletizingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFToPSConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLResourceAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforatingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlaceHolderResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlateCopyParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAnalysis.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInventory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightReport.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightReportRulePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreview.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreviewGenerationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintCondition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintRollingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPSToPDFConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityControlParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityControlResult.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterRibbon.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRenderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceDefinitionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRollStand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRunList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScanParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScavengerArea.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationControlParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShrinkingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpinePreparationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpineTapingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrappingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStrippingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSurface.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSealingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurve.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurvePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferFunctionControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrapRegion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrimmingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVerificationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWrappingParams.h
# End Source File
# End Group
# End Group
# Begin Group "AutoProcessSubelements"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.7"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdvancedParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArgumentValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssemblySection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBasicPreflightTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindingQualityParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxArgument.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxToBoxDifference.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundleItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCCITTFaxParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollatingItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantZoneDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceSubstitute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContainer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCrease.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDCTParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDependencies.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDrop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicInput.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmboss.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeeder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeederQualityParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlateParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIcon.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIconList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPCover.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPFinishing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPFolding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPHoleMaking.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPImageShift.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPJobSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPTrimming.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageCompression.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageShift.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayerDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayerList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongFold.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongGlue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongPerforate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongSlit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLZWParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMarkObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageCell.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFInterpretingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFXParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPixelColorant.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightArgument.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightConstraint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightDetail.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInstance.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInstanceDetail.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRError.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroupOccurence.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroupOccurenceBase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintConditionColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPROccurence.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProperties.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRRule.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRRuleAttr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityMeasurement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceParam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScore.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreenSelector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignature.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignatureCell.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStringListValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripCellParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThinPDFParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFEmbeddedFile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFFormatParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFtag.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurveSet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingOrder.cpp
# End Source File
# End Group
# Begin Group "AutoH No.7"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdvancedParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArgumentValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAssemblySection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBasicPreflightTest.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBindingQualityParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxArgument.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBoxToBoxDifference.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBundleItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCCITTFaxParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollatingItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantZoneDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceSubstitute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContainer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCrease.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDCTParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDependencies.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDrop.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicInput.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmboss.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeeder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeederQualityParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFlateParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIcon.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIconList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPCover.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPFinishing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPFolding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPHoleMaking.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPImageShift.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPJobSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIDPTrimming.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageCompression.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoImageShift.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayerDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayerList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongFold.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongGlue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongPerforate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongSlit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLZWParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMarkObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParam.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageCell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPageData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFInterpretingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFXParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPixelColorant.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightArgument.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightConstraint.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightDetail.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInstance.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightInstanceDetail.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRError.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroupOccurence.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRGroupOccurenceBase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPrintConditionColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPROccurence.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProperties.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRRule.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPRRuleAttr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQualityMeasurement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceParam.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScore.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreenSelector.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignature.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignatureCell.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStringListValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStripCellParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThinPDFParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFEmbeddedFile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFFormatParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTIFFtag.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurveSet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingOrder.h
# End Source File
# End Group
# End Group
# End Group
# Begin Group "AutoDeviceCapability"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.8"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoActionPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutocall.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutochoice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCaps.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceCap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisplayGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisplayGroupPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeatureAttribute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeaturePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutomacro.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMacroPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutonot.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutootherwise.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerformance.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTest.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTestPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTestRef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoValue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoValueLoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutowhen.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoxor.cpp
# End Source File
# End Group
# Begin Group "AutoH No.8"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoActionPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutocall.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutochoice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevCaps.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceCap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisplayGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisplayGroupPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeatureAttribute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFeaturePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutomacro.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMacroPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutonot.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutootherwise.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerformance.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTest.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTestPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTestRef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoValue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoValueLoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutowhen.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoxor.h
# End Source File
# End Group
# End Group
# Begin Group "AutoCore"

# PROP Default_Filter ""
# Begin Group "AutoSrc No.9"

# PROP Default_Filter ".cpp"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEnumerationSpan.cpp
# End Source File
# End Group
# Begin Group "AutoH No.9"

# PROP Default_Filter ".h"
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEnumerationSpan.h
# End Source File
# End Group
# End Group
# End Group
# Begin Group "New"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightResultsPool.h
# End Source File
# End Group
# End Group
# Begin Group "wrappercore"

# PROP Default_Filter ""
# Begin Group "src No. 9"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDuration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationRangeList.cpp
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
# Begin Group "include No. 9"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDateTimeRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDuration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDurationRangeList.h
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
# End Group
# Begin Group "Lib"

# PROP Default_Filter ".lib"
# Begin Source File

SOURCE="..\..\..\external\xerces\lib\xerces-c_2D.lib"

!IF  "$(CFG)" == "JDFWrapperLib - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\external\xerces\lib\xerces-c_2.lib"

!IF  "$(CFG)" == "JDFWrapperLib - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Release"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\Build\Win32\VC6\ReleaseDLL\JDFToolsDLL.lib

!IF  "$(CFG)" == "JDFWrapperLib - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLLd.lib

!IF  "$(CFG)" == "JDFWrapperLib - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
