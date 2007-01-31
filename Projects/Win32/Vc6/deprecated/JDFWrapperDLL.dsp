# Microsoft Developer Studio Project File - Name="JDFWrapperDLL" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** NICHT BEARBEITEN **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=JDFWrapperDLL - Win32 Debug
!MESSAGE Dies ist kein gültiges Makefile. Zum Erstellen dieses Projekts mit NMAKE
!MESSAGE verwenden Sie den Befehl "Makefile exportieren" und führen Sie den Befehl
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperDLL.mak".
!MESSAGE 
!MESSAGE Sie können beim Ausführen von NMAKE eine Konfiguration angeben
!MESSAGE durch Definieren des Makros CFG in der Befehlszeile. Zum Beispiel:
!MESSAGE 
!MESSAGE NMAKE /f "JDFWrapperDLL.mak" CFG="JDFWrapperDLL - Win32 Debug"
!MESSAGE 
!MESSAGE Für die Konfiguration stehen zur Auswahl:
!MESSAGE 
!MESSAGE "JDFWrapperDLL - Win32 Release" (basierend auf  "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFWrapperDLL - Win32 Debug" (basierend auf  "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "JDFWrapperDLL"
# PROP Scc_LocalPath "..\..\.."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "JDFWrapperDLL - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Release"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Release\obj\JDFWrapperDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /w /W0 /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\src" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\src\jdf\wrapper" /I "..\..\..\src\jdf\wrappercore" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "PROJ_JDFTOOLS" /D "TYPESAFE" /D "_REENTRANT" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /map /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib"

!ELSEIF  "$(CFG)" == "JDFWrapperDLL - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Debug\obj\JDFWrapperDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\src" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\src\jdf\wrapper" /I "..\..\..\src\jdf\wrappercore" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /D "PROJ_JDFTOOLS" /D "TYPESAFE" /D "_STLP_USE_DEBUG_LIB" /D "_REENTRANT" /FR /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\Debug/JDFWrapperDLLd.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "JDFWrapperDLL - Win32 Release"
# Name "JDFWrapperDLL - Win32 Debug"
# Begin Group "JDFCore"

# PROP Default_Filter ""
# Begin Group "AutoSrc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdded.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAddress.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalSuccess.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBusinessInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoByteMap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedAttribute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCIELABMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorControlStrip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComment.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCostCenter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreated.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDensityMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisjointing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicInput.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployee.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEnumerationSpan.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentificationField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLocation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMarkObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaSource.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeProduct.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotification.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObservationTarget.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPartStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPhaseTime.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPixelColorant.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProcessRun.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoved.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRunList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpawned.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSurface.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurve.cpp
# End Source File
# End Group
# Begin Group "AutoH"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdded.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAddress.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAncestorPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalSuccess.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBusinessInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoByteMap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChangedAttribute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCIELABMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorControlStrip.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoComment.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoContentObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCostCenter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCreated.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCustomerInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDensityMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDevice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDisjointing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDynamicInput.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployee.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEnumerationSpan.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFileSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoIdentificationField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayoutElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLocation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMarkObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMediaSource.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObservationTarget.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPartStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPhaseTime.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPixelColorant.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProcessRun.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRegisterMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRemoved.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRunList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpawned.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSurface.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurve.h
# End Source File
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdded.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAddress.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalSuccess.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAuditPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBusinessInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFByteMap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChangedAttribute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCIELABMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorControlStrip.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComment.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFContentObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCostCenter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreated.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDensityMeasuringField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevice.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNColor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisjointing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicInput.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployee.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIdentificationField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRangeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntentResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMarkObject.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaSource.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCombined.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeProcessGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotification.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObservationTarget.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFParamsFactory.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPixelColorant.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProcessRun.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRange.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRefElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterMark.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRemoved.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceAudit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLink.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLinkPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRoot.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationSpec.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpan.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpawned.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSurface.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurve.cpp
# End Source File
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdded.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAddress.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAncestorPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalSuccess.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAuditPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBusinessInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFByteMap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChangedAttribute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCIELABMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorControlStrip.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFComment.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFCostCenter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCreated.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCustomerInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDensityMeasuringField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDevice.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDisjointing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDynamicInput.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployee.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIdentificationField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntegerRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFIntentResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMarkObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaSource.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCombined.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeProcessGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotification.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObservationTarget.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPhaseTime.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPixelColorant.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProcessRun.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRange.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRefElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRemoved.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceAudit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLink.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceLinkPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourcePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRoot.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationSpec.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpan.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpawned.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSurface.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurve.h
# End Source File
# End Group
# End Group
# Begin Group "JMFCore"

# PROP Default_Filter ""
# Begin Group "include No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAcknowledge.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCommand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMF.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQuery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResponse.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubscription.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrigger.h
# End Source File
# End Group
# Begin Group "src No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAcknowledge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCommand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMF.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQuery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResponse.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubscription.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrigger.cpp
# End Source File
# End Group
# Begin Group "AutoH No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAcknowledge.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCommand.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMF.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQuery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResponse.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubscription.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrigger.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAcknowledge.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCommand.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMF.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQuery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResponse.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubscription.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrigger.cpp
# End Source File
# End Group
# End Group
# Begin Group "JDFCommon"

# PROP Default_Filter ""
# Begin Group "src No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArtDelivery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBackPreparation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcode.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantOrder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantZoneDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceSubstitute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsUsed.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCounterReset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoverApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCrease.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutBlock.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceColorantOrder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNSpace.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDrop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFError.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFExposedMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFCNKey.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFold.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontPolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueLine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHole.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleList.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFInk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsert.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretedPDLData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLocation.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeProduct.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObjectResolution.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDLResourceAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerforate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPhaseTime.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlaceHolder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAnalysis.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInventory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPricing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProperties.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRingBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScore.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreenSelector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignature.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpineTaping.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFState.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSystemTimeSet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTabs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSeal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurvePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurveSet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferFunctionControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingOrder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrapRegion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBinding.cpp
# End Source File
# End Group
# Begin Group "include No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDF.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFArtDelivery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBackPreparation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFBarcode.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantZoneDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceSubstitute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsUsed.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFContentObject.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCounterReset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoverApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCrease.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCutBlock.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceColorantOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeviceNSpace.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDrop.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFError.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFExposedMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFCNKey.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFold.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGlueLine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHole.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleList.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFInk.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsert.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInterpretedPDLData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLocation.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeProduct.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParam.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFObjectResolution.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDLResourceAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPerforate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlaceHolder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightAnalysis.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightInventory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreview.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPricing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProperties.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRangeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRegisterMark.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRingBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFRunElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScore.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreenSelector.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSignature.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSizeIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSpineTaping.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFState.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSystemTimeSet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTabs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSeal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurvePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferCurveSet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTransferFunctionControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrapRegion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBinding.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalPerson.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDelivery.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBackPreparation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcode.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantOrder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantZoneDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionOp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceSubstitute.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorsUsed.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCounterReset.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoverApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCrease.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutBlock.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceColorantOrder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNSpace.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDrop.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoError.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExposedMedia.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFCNKey.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFold.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontPolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueApplication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueLine.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHole.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleList.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInk.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneProfile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsert.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretedPDLData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobSheet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayout.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParam.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObjectResolution.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLResourceAlias.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPipeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlaceHolder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBinding.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreview.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPricing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProperties.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScore.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreenSelector.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignature.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpineTaping.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSystemTimeSet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTabs.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSeal.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTile.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurvePool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurveSet.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferFunctionControl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingDetails.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingOrder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrapRegion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBinding.cpp
# End Source File
# End Group
# Begin Group "AutoH No. 2"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalPerson.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoArtDelivery.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBackPreparation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoBarcode.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantZoneDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionOp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceSubstitute.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorsUsed.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCounterReset.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoverApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCrease.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCutBlock.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceColorantOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeviceNSpace.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDrop.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoError.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoExposedMedia.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFCNKey.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFold.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontPolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueApplication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGlueLine.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHole.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleList.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInk.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneProfile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsert.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInterpretedPDLData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobPhase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobSheet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLayout.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeProduct.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParam.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoObjectResolution.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDLResourceAlias.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPerforate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlaceHolder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightAnalysis.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreview.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPricing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProperties.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScore.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreenSelector.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCut.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSignature.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSpineTaping.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSystemTimeSet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTabs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSeal.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTile.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurvePool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferCurveSet.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTransferFunctionControl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingDetails.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingOrder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrapRegion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBinding.h
# End Source File
# End Group
# End Group
# Begin Group "JDFIntent"

# PROP Default_Filter ""
# Begin Group "src No. 3"

# PROP Default_Filter ""
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

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItemIntent.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaIntent.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSizeIntent.cpp
# End Source File
# End Group
# Begin Group "include No. 3"

# PROP Default_Filter ""
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

SOURCE=..\..\..\src\jdf\wrapper\JDFDropIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDropItemIntent.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFLaminatingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLayoutIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMediaIntent.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFShapeCuttingIntent.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 3"

# PROP Default_Filter ""
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItemIntent.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingIntent.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSizeIntent.cpp
# End Source File
# End Group
# Begin Group "AutoH No. 3"

# PROP Default_Filter ""
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDropItemIntent.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProductionIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoShapeCuttingIntent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSizeIntent.h
# End Source File
# End Group
# End Group
# Begin Group "JDFJMF"

# PROP Default_Filter ""
# Begin Group "AutoH No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAAbortQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFACloseQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAFlushQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAHoldQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAHoldQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAOpenQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipeClose.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipePause.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipePull.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipePush.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFARemoveQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFARepeatMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResumeQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResumeQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFASetQueueEntryPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFASetQueueEntryPriority.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAStopPersistentChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFASubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCAbortQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCCloseQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCFlushQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCHoldQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCHoldQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCOpenQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipeClose.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipePause.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipePull.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipePush.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCRemoveQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCRepeatMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResumeQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResumeQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCSetQueueEntryPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCSetQueueEntryPriority.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCStopPersistentChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCSubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQEvents.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownControllers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownDevices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownJDFServices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQOccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQQueueEntryStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQQueueStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQTrack.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRAbortQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRCloseQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFREvents.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRFlushQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRHoldQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRHoldQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownControllers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownDevices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownJDFServices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFROccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFROpenQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipeClose.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipePause.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipePull.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipePush.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRQueueEntryStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRQueueStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRRemoveQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRRepeatMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResumeQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResumeQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSetQueueEntryPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSetQueueEntryPriority.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRStopPersistentChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRTrack.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSEvents.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownControllers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownDevices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownJDFServices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSOccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSQueueEntryStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSQueueStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSTrack.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAAbortQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFACloseQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAFlushQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAHoldQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAHoldQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAOpenQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipeClose.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipePause.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipePull.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAPipePush.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFARemoveQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFARepeatMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResumeQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAResumeQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFASetQueueEntryPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFASetQueueEntryPriority.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFAStopPersistentChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFASubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCAbortQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCCloseQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCFlushQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCHoldQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCHoldQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCOpenQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipeClose.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipePause.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipePull.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCPipePush.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCRemoveQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCRepeatMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResumeQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCResumeQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCSetQueueEntryPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCSetQueueEntryPriority.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCStopPersistentChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFCSubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQEvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownControllers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownDevices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownJDFServices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQKnownMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQOccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQQueueEntryStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQQueueStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFQTrack.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRAbortQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRCloseQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFREvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRFlushQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRHoldQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRHoldQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownControllers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownDevices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownJDFServices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRKnownMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFROccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFROpenQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipeClose.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipePause.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipePull.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRPipePush.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRQueueEntryStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRQueueStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRRemoveQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRRepeatMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResumeQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRResumeQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSetQueueEntryPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSetQueueEntryPriority.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRStopPersistentChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRSubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFRTrack.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSEvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownControllers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownDevices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownJDFServices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSKnownMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSOccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSQueueEntryStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSQueueStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJMFSTrack.cpp
# End Source File
# End Group
# Begin Group "include No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAAbortQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFACloseQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAFlushQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAHoldQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAHoldQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAOpenQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipeClose.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipePause.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipePull.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipePush.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFARemoveQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFARepeatMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResumeQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResumeQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFASetQueueEntryPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFASetQueueEntryPriority.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAStopPersistentChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFASubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCAbortQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCCloseQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCFlushQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCHoldQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCHoldQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCOpenQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipeClose.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipePause.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipePull.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipePush.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCRemoveQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCRepeatMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResumeQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResumeQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCSetQueueEntryPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCSetQueueEntryPriority.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCStopPersistentChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCSubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQEvents.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownControllers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownDevices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownJDFServices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQOccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQQueueEntryStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQQueueStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQTrack.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRAbortQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRCloseQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFREvents.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRFlushQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRHoldQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRHoldQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownControllers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownDevices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownJDFServices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFROccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFROpenQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipeClose.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipePause.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipePull.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipePush.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRQueueEntryStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRQueueStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRRemoveQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRRepeatMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResumeQueue.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResumeQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSetQueueEntryPosition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSetQueueEntryPriority.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRStopPersistentChannel.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSubmitQueueEntry.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRTrack.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSEvents.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownControllers.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownDevices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownJDFServices.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownMessages.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSOccupation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSQueueEntryStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSQueueStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSTrack.h
# End Source File
# End Group
# Begin Group "src No. 4"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAAbortQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFACloseQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAFlushQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAHoldQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAHoldQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAOpenQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipeClose.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipePause.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipePull.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAPipePush.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFARemoveQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFARepeatMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResumeQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAResumeQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFASetQueueEntryPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFASetQueueEntryPriority.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFAStopPersistentChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFASubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCAbortQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCCloseQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCFlushQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCHoldQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCHoldQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCOpenQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipeClose.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipePause.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipePull.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCPipePush.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCRemoveQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCRepeatMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResumeQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCResumeQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCSetQueueEntryPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCSetQueueEntryPriority.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCStopPersistentChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFCSubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQEvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownControllers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownDevices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownJDFServices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQKnownMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQOccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQQueueEntryStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQQueueStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFQTrack.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRAbortQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRCloseQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFREvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRFlushQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRHoldQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRHoldQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownControllers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownDevices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownJDFServices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRKnownMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFROccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFROpenQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipeClose.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipePause.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipePull.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRPipePush.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRQueueEntryStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRQueueStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRRemoveQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRRepeatMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResumeQueue.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRResumeQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSetQueueEntryPosition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSetQueueEntryPriority.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRStopPersistentChannel.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRSubmitQueueEntry.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFRTrack.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSEvents.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownControllers.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownDevices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownJDFServices.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSKnownMessages.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSOccupation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSQueueEntryStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSQueueStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJMFSTrack.cpp
# End Source File
# End Group
# End Group
# Begin Group "JDFNodes"

# PROP Default_Filter ""
# Begin Group "src No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeAdhesiveBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeChannelBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCoilBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCollecting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeColorCorrection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeColorSpaceConversion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeContoneCalibration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeConventionalPrinting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCutting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDBDocTemplateLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDBTemplateMerging.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDigitalPrinting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDividing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeEndSheetGluing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFilmToPlateCopying.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFolding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeGathering.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeHoleMaking.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeIDPrinting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeImageReplacement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeImageSetting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeImposition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInkZoneCalculation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInserting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInterpreting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeLayoutElementProduction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeLongitudinalRibbonOperations.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeNumbering.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePDFToPSConversion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePlasticCombBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePreflight.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePreviewGeneration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeProofing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePSToPDFConversion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeRendering.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeRingBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSaddleStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeScanning.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeScreening.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSeparation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSideSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSoftProofing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeThreadSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeTiling.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeTrapping.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeTrimming.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeVeloBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeWireCombBinding.cpp
# End Source File
# End Group
# Begin Group "include No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeAdhesiveBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeChannelBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCoilBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCollecting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeColorCorrection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeColorSpaceConversion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeContoneCalibration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeConventionalPrinting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeCutting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDBDocTemplateLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDBTemplateMerging.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDigitalPrinting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeDividing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeEndSheetGluing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFilmToPlateCopying.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeFolding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeGathering.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeHoleMaking.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeIDPrinting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeImageReplacement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeImageSetting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeImposition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInkZoneCalculation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInserting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeInterpreting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeLayoutElementProduction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeLongitudinalRibbonOperations.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeNumbering.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePDFToPSConversion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePlasticCombBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePreflight.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePreviewGeneration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeProofing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodePSToPDFConversion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeRendering.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeRingBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSaddleStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeScanning.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeScreening.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSeparation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSideSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeSoftProofing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeThreadSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeTiling.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeTrapping.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeTrimming.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeVeloBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNodeWireCombBinding.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeAdhesiveBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeChannelBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeCoilBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeCollecting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeColorCorrection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeColorSpaceConversion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeContoneCalibration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeConventionalPrinting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeCutting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDBDocTemplateLayout.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDBTemplateMerging.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDigitalPrinting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDividing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeEndSheetGluing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeFilmToPlateCopying.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeFolding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeGathering.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeHoleMaking.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeIDPrinting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeImageReplacement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeImageSetting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeImposition.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInkZoneCalculation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInserting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInterpreting.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeLayoutElementProduction.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeLongitudinalRibbonOperations.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeNumbering.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePDFToPSConversion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePlasticCombBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePreflight.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePreviewGeneration.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeProofing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePSToPDFConversion.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeRendering.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeRingBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSaddleStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeScanning.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeScreening.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSeparation.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSideSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSoftProofing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeStitching.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeThreadSewing.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeTiling.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeTrapping.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeTrimming.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeVeloBinding.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeWireCombBinding.cpp
# End Source File
# End Group
# Begin Group "AutoH No. 5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeAdhesiveBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeChannelBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeCoilBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeCollecting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeColorCorrection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeColorSpaceConversion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeContoneCalibration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeConventionalPrinting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeCutting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDBDocTemplateLayout.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDBTemplateMerging.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDigitalPrinting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeDividing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeEndSheetGluing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeFilmToPlateCopying.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeFolding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeGathering.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeHoleMaking.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeIDPrinting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeImageReplacement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeImageSetting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeImposition.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInkZoneCalculation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInserting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeInterpreting.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeLayoutElementProduction.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeLongitudinalRibbonOperations.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeNumbering.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePDFToPSConversion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePlasticCombBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePreflight.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePreviewGeneration.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeProofing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodePSToPDFConversion.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeRendering.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeRingBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSaddleStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeScanning.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeScreening.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSeparation.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSideSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeSoftProofing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeStitching.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeThreadSewing.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeTiling.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeTrapping.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeTrimming.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeVeloBinding.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNodeWireCombBinding.h
# End Source File
# End Group
# End Group
# Begin Group "JDFParams"

# PROP Default_Filter ""
# Begin Group "AutoH No. 6"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdvancedParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAutomatedOverprintParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollectingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoConventionalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBMergeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDividingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheetGluingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGatheringParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingParams.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneCalculationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoKnownMsgQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongitudinalRibbonOperationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOrderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFInterpretingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFToPSConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPipeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlateCopyParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreviewGenerationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPSToPDFConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRenderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceDefinitionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoRingBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScanParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationControlParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThinPDFParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrimmingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVeloBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVerificationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBindingParams.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 6"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdhesiveBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAdvancedParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoApprovalParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoAutomatedOverprintParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoChannelBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCoilBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoCollectingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorantParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorCorrectionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorSpaceConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoConventionalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDBMergeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDeliveryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDigitalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoDividingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEndSheetGluingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFoldingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoFontParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoGatheringParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoHoleMakingParams.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInkZoneCalculationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoInsertingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoLongitudinalRibbonOperationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNumberingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOrderingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFInterpretingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPDFToPSConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlasticCombBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPlateCopyParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreviewGenerationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoProofingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPSToPDFConversionParams.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSaddleStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScanParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoScreeningParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSeparationControlParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSideSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThinPDFParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoThreadSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrappingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrimmingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVeloBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoVerificationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoWireCombBindingParams.cpp
# End Source File
# End Group
# Begin Group "include No. 6"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdvancedParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAutomatedOverprintParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCollectingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFConventionalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDBMergeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalPrintingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDividingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheetGluingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingParams.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneCalculationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongitudinalRibbonOperationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOrderingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPackingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFInterpretingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFToPSConversionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPipeParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreviewGenerationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPSToPDFConversionParams.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScanParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationControlParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStitchingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThinPDFParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrimmingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFVeloBindingParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFVerificationParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBindingParams.h
# End Source File
# End Group
# Begin Group "src No. 6"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdhesiveBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAdvancedParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFApprovalParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAutomatedOverprintParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFChannelBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCoilBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFCollectingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorantParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorCorrectionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorSpaceConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFConventionalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDeliveryParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDigitalPrintingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDividingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEndSheetGluingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFoldingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFGatheringParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFHoleMakingParams.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFInkZoneCalculationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFInsertingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFLongitudinalRibbonOperationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNumberingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOrderingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPackingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFInterpretingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPDFToPSConversionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPipeParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlasticCombBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPlateCopyParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreviewGenerationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFProofingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPSToPDFConversionParams.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFSaddleStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScanParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFScreeningParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSeparationControlParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSideSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStitchingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThinPDFParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFThreadSewingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrappingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrimmingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFVeloBindingParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFVerificationParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFWireCombBindingParams.cpp
# End Source File
# End Group
# End Group
# Begin Group "JDFPool"

# PROP Default_Filter ""
# Begin Group "AutoH No. 7"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPagesResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightResultsPool.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 7"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoColorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoPreflightResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImagesConstraintsPool.cpp
# End Source File
# End Group
# Begin Group "include No. 7"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAmountPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDocumentConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDocumentResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileTypeConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileTypeResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontsConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontsResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImagesConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImagesResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPagesConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPagesResultsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraintsPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightGroup.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightResultsPool.h
# End Source File
# End Group
# Begin Group "src No. 7"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFAmountPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFColorsResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDocumentConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFDocumentResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileTypeConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFileTypeResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontsConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFFontsResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFImagesResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPagesConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPagesResultsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightConstraintsPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightGroup.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFPreflightResultsPool.cpp
# End Source File
# End Group
# End Group
# Begin Group "JMFCommon"

# PROP Default_Filter ""
# Begin Group "AutoH No. 8"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployeeDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFController.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFService.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOccupation.h
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackFilter.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 8"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoEmployeeDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFController.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJDFService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoJobPhase.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoNotificationDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoOccupation.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackResult.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoTrackResult.h
# End Source File
# End Group
# Begin Group "include No. 8"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployeeDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFController.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobPhase.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModuleStatus.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMsgFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationDef.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOccupation.h
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

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubmissionMethods.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackResult.h
# End Source File
# End Group
# Begin Group "src No. 8"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFEmployeeDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFController.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJDFService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFJobPhase.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMessageService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFModuleStatus.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFMsgFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFNotificationDef.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFOccupation.cpp
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

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFSubmissionMethods.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackFilter.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFTrackResult.cpp
# End Source File
# End Group
# End Group
# Begin Group "JMFParams"

# PROP Default_Filter ""
# Begin Group "AutoH No. 9"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPosParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPriParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueSubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStopPersChParams.h
# End Source File
# End Group
# Begin Group "AutoSrc No. 9"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoKnownMsgQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPosParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueEntryPriParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoQueueSubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResourceQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoResubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStatusQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\AutoJDF\JDFAutoStopPersChParams.cpp
# End Source File
# End Group
# Begin Group "include No. 9"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFKnownMsgQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPosParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPriParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueSubmissionParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceCmdParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusQuParams.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStopPersChParams.h
# End Source File
# End Group
# Begin Group "src No. 9"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFKnownMsgQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPosParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueEntryPriParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFQueueSubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceCmdParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResourceQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFResubmissionParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStatusQuParams.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrapper\JDFStopPersChParams.cpp
# End Source File
# End Group
# End Group
# Begin Group "wrappercore"

# PROP Default_Filter ""
# Begin Group "src No. 10"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KElement.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KNode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KNodeList.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\MyDate.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDoc.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDocUserData.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLstrm.cpp
# End Source File
# End Group
# Begin Group "include No. 10"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KElement.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KNode.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\KNodeList.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\MyDate.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDoc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLDocUserData.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\wrappercore\XMLstrm.h
# End Source File
# End Group
# End Group
# Begin Group "tools"

# PROP Default_Filter ""
# Begin Group "lang"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\AutoPtr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\AutoPtr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\BoolJanitor.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\BoolJanitor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\ByteBuffer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\ByteBuffer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\CharBuffer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\CharBuffer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Exception.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Integer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Integer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Integer64.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Integer64.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Janitor.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\JDFToolsDefs.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Mutex.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Mutex.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Synchronized.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Synchronized.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Throwable.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\Throwable.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\WString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\WString.h
# End Source File
# End Group
# Begin Group "mime"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\Exception.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\FileMIMEType.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\FileMIMEType.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\FileNameMap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEBasicPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEBasicPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEBodyPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEBodyPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEComponent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEHeader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEHeader.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMessage.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMessage.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMessagePart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMessagePart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMultiPart.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMultiPart.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEParser.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MimeTableFileNameMap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MimeTableFileNameMap.h
# End Source File
# End Group
# Begin Group "util"

# PROP Default_Filter ""
# Begin Group "Platforms"

# PROP Default_Filter ""
# Begin Group "Win32"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32PlatformUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32PlatformUtils.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32ProcessInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32ProcessInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32ProcessOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32ProcessOutputStream.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Cache.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Exception.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\hashfun.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\hmap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\myuti.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\myuti.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\PlatformUtils.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\PlatformUtils.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Random.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Random.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Regexp.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\RegExp.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\RegexpPool.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\RegexpPool.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\slist.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\StringTokenizer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\StringTokenizer.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Unicode.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\Unicode.h
# End Source File
# End Group
# Begin Group "net"

# PROP Default_Filter ""
# Begin Group "NetworkFactory"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32InetAddressImpl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32InetAddressImpl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketFactoryService.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketFactoryService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImpl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImpl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketInit.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketInit.h
# End Source File
# End Group
# Begin Group "StreamHandlerFactory"

# PROP Default_Filter ""
# Begin Group "File"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\net\FileURLConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\FileURLConnection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\FileURLStreamHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\FileURLStreamHandler.h
# End Source File
# End Group
# Begin Group "Http"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\net\AuthenticationInfo.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\AuthenticationInfo.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Authenticator.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Authenticator.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\BasicAuthentication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\BasicAuthentication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\ChunkedInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\ChunkedInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\DigestAuthentication.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\DigestAuthentication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpClient.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpClient.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpURLConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpURLConnection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpURLStreamHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpURLStreamHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainHttpOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainHttpOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainHttpURLConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainHttpURLConnection.h
# End Source File
# End Group
# Begin Group "Https"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpsClient.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpsClient.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpsURLStreamHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HttpsURLStreamHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainHttpsURLConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainHttpsURLConnection.h
# End Source File
# End Group
# Begin Group "Cid"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\net\CidURLStreamHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\CidURLStreamHandler.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainURLStreamHandlerFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PlainURLStreamHandlerFactory.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Exception.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HeaderParser.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\HeaderParser.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\InetAddress.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\InetAddress.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\InetAddressCachePolicy.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\InetAddressCachePolicy.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\InetAddressImpl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\InetAddressImpl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\md5.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\md5.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\MessageHeader.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\MessageHeader.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\NetworkClient.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\NetworkClient.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PasswordAuthentication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Socket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\Socket.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketFactoryService.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketImpl.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketImpl.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketImplFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketInit.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketOptions.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SocketOptions.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SSLSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SSLSocket.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SSLSocketInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SSLSocketInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SSLSocketOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\SSLSocketOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URL.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URL.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLConnection.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLDecoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLDecoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLEncoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLEncoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLStreamHandler.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLStreamHandler.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URLStreamHandlerFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\WWWURLConnection.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\WWWURLConnection.h
# End Source File
# End Group
# Begin Group "io"

# PROP Default_Filter ""
# Begin Group "FileSystem"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\src\jdf\io\Platforms\Win32\Win32FileSystem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\Platforms\Win32\Win32FileSystem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\Platforms\Win32\Win32Shortcut.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\Platforms\Win32\Win32Shortcut.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BASE64Decoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BASE64Decoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BASE64Encoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BASE64Encoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BufferedInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BufferedInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BufferedOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\BufferedOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\ByteArrayInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\ByteArrayInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\ByteArrayOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\ByteArrayOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\CharacterDecoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\CharacterDecoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\CharacterEncoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\CharacterEncoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\Exception.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\File.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\File.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileNameFilter.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileSystem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FileSystem.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FilterInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FilterInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FilterOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\FilterOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\InputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\InputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\OutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\OutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\PrintStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\PrintStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\PushbackInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\PushbackInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\QPDecoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\QPDecoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\QPEncoder.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\QPEncoder.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\RandomAccessInputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\RandomAccessInputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\RandomAccessOutputStream.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\RandomAccessOutputStream.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\StreamBuffer.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\io\StreamBuffer.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE="..\..\..\external\xerces\Build\Win32\VC6\Debug\xerces-c_1D.lib"

!IF  "$(CFG)" == "JDFWrapperDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperDLL - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\external\xerces\Build\Win32\VC6\Release\xerces-c_1.lib"

!IF  "$(CFG)" == "JDFWrapperDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "JDFWrapperDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\external\libpng\projects\msvc\win32\libpng\libMD\libpng.lib
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\..\external\libpng\projects\msvc\win32\libpng\libMD_dbg\libpng.lib
# End Source File
# Begin Source File

SOURCE=..\..\..\external\libpng\projects\msvc\win32\zlib\libMD\zlib.lib
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\..\external\libpng\projects\msvc\win32\zlib\libMD_dbg\zlib.lib
# End Source File
# Begin Source File

SOURCE=..\..\..\external\stlport\lib\stlport_vc6_debug.lib

!IF  "$(CFG)" == "JDFWrapperDLL - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFWrapperDLL - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\external\stlport\lib\stlport_vc6.lib

!IF  "$(CFG)" == "JDFWrapperDLL - Win32 Release"

!ELSEIF  "$(CFG)" == "JDFWrapperDLL - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Target
# End Project
