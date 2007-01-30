# Microsoft Developer Studio Project File - Name="JDFToolsLib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=JDFToolsLib - Win32 Debug LineOnly
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "JDFToolsLib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "JDFToolsLib.mak" CFG="JDFToolsLib - Win32 Debug LineOnly"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "JDFToolsLib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFToolsLib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "JDFToolsLib - Win32 Debug DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFToolsLib - Win32 Release DLL" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "JDFToolsLib - Win32 Debug LineOnly" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "JDFToolsLib"
# PROP Scc_LocalPath "..\.."

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Release"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Release\obj\JDFToolsLib"
# PROP Target_Dir ""
MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "NDEBUG" /D "UNICODE" /D "_UNICODE" /D "_WINDOWS" /D "WIN32" /D "_LIB" /D "JDF_TOOLS_LIB" /Fd"..\..\..\Build\Win32\VC6\Release\JDFToolsLib" /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "NDEBUG"
# ADD RSC /l 0x813 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\Debug"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\Debug\obj\JDFToolsLib"
# PROP Target_Dir ""
MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "_DEBUG" /D "UNICODE" /D "_UNICODE" /D "_WINDOWS" /D "WIN32" /D "_LIB" /D "JDF_TOOLS_LIB" /FR /Fd"..\..\..\Build\Win32\VC6\Debug\JDFToolsLib" /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\jdftoolslib_D.lib"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\DebugDLL"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\DebugDLL\obj\JDFToolsDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /w /W0 /Gm /GR /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDF_TOOLS" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR /Fd"..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLL" /FD /GZ /c
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /map /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\DebugDLL/JDFToolsDLLd.dll" /pdbtype:sept /libpath:"..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\Build\Win32\VC6\ReleaseDLL"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\ReleaseDLL\obj\JDFToolsDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "JDFWrapperDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /w /W0 /GR /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "TYPESAFE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /D "JDF_TOOLS" /FR /YX /Fd"..\..\..\Build\Win32\VC6\ReleaseDLL\JDFToolsDLL" /FD /c
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /map /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib" /out:"..\..\..\Build\Win32\VC6\ReleaseDLL/JDFToolsDLL.dll" /libpath:"..\..\..\external\stlport\lib"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "JDFToolsLib___Win32_Debug_LineOnly"
# PROP BASE Intermediate_Dir "JDFToolsLib___Win32_Debug_LineOnly"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\Build\Win32\VC6\DebugLineOnly"
# PROP Intermediate_Dir "..\..\..\Build\Win32\VC6\DebugLineOnly\obj\JDFToolsLib"
# PROP Target_Dir ""
MTL=midl.exe
LINK32=link.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /w /W0 /Gm /GR /GX /Zi /Od /I "..\..\..\external\xerces\src" /I "..\..\..\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\external\zlib" /I "..\..\..\external" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "PROJ_JDFTOOLSLIB" /D "UNICODE" /D "_UNICODE" /FR /FD /GZ /c
# SUBTRACT BASE CPP /X /YX
# ADD CPP /nologo /MDd /w /W0 /GR /GX /Zd /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\external\zlib" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "JDF_TOOLS_LIB" /D "UNICODE" /D "_UNICODE" /FR /Fd"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFToolsLib" /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x813 /d "_DEBUG"
# ADD RSC /l 0x813 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\Debug\jdftoolslib_D.lib"
# ADD LIB32 /nologo /out:"..\..\..\Build\Win32\VC6\DebugLineOnly\jdftoolslib_D.lib"

!ENDIF 

# Begin Target

# Name "JDFToolsLib - Win32 Release"
# Name "JDFToolsLib - Win32 Debug"
# Name "JDFToolsLib - Win32 Debug DLL"
# Name "JDFToolsLib - Win32 Release DLL"
# Name "JDFToolsLib - Win32 Debug LineOnly"
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

SOURCE=..\..\..\src\jdf\net\ParseUtil.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\ParseUtil.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\PasswordAuthentication.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\ServerSocket.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\ServerSocket.h
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

SOURCE=..\..\..\src\jdf\net\URI.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\net\URI.h
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

SOURCE=..\..\..\src\jdf\util\dtoa.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\dtoa.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\hashfun.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\hmap.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\util\JDFLibVersion.h
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
# Begin Group "mime"

# PROP Default_Filter ""
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

SOURCE=..\..\..\src\jdf\mime\MIMELocalResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMELocalResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMELocalResourceFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMELocalResourceFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMemResource.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMemResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMemResourceFactory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEMemResourceFactory.h
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

SOURCE=..\..\..\src\jdf\mime\MIMEResource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MIMEResourceFactory.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MimeTableFileNameMap.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\mime\MimeTableFileNameMap.h
# End Source File
# End Group
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

SOURCE=..\..\..\src\jdf\lang\KString.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\mapWString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\mapWString.h
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

SOURCE=..\..\..\src\jdf\lang\vdouble.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vdouble.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vint.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vint.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vMapWString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vMapWString.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vWString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\vWString.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\WString.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\WString.h
# End Source File
# Begin Source File

SOURCE=..\..\..\src\jdf\lang\WStringBase.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\external\libpng\projects\msvc\win32\libpng\lib\LIBPNG.LIB

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\external\libpng\projects\msvc\win32\libpng\lib_dbg\LIBPNG.LIB

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\external\xerces\lib\xerces-c_2D.lib"

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\external\xerces\lib\xerces-c_2.lib"

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Target
# End Project
