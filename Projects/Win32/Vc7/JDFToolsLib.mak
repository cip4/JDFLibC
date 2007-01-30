# Microsoft Developer Studio Generated NMAKE File, Based on JDFToolsLib.dsp
!IF "$(CFG)" == ""
CFG=JDFToolsLib - Win32 Debug LineOnly
!MESSAGE No configuration specified. Defaulting to JDFToolsLib - Win32 Debug LineOnly.
!ENDIF 

!IF "$(CFG)" != "JDFToolsLib - Win32 Release" && "$(CFG)" != "JDFToolsLib - Win32 Debug" && "$(CFG)" != "JDFToolsLib - Win32 Debug DLL" && "$(CFG)" != "JDFToolsLib - Win32 Release DLL" && "$(CFG)" != "JDFToolsLib - Win32 Debug LineOnly"
!MESSAGE Invalid configuration "$(CFG)" specified.
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
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"

OUTDIR=.\..\..\..\Build\Win32\VC6\Release
INTDIR=.\..\..\..\Build\Win32\VC6\Release\obj\JDFToolsLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\Release
# End Custom Macros

ALL : "$(OUTDIR)\JDFToolsLib.lib"


CLEAN :
	-@erase "$(INTDIR)\AuthenticationInfo.obj"
	-@erase "$(INTDIR)\Authenticator.obj"
	-@erase "$(INTDIR)\AutoPtr.obj"
	-@erase "$(INTDIR)\BASE64Decoder.obj"
	-@erase "$(INTDIR)\BASE64Encoder.obj"
	-@erase "$(INTDIR)\BasicAuthentication.obj"
	-@erase "$(INTDIR)\BoolJanitor.obj"
	-@erase "$(INTDIR)\BufferedInputStream.obj"
	-@erase "$(INTDIR)\BufferedOutputStream.obj"
	-@erase "$(INTDIR)\ByteArrayInputStream.obj"
	-@erase "$(INTDIR)\ByteArrayOutputStream.obj"
	-@erase "$(INTDIR)\ByteBuffer.obj"
	-@erase "$(INTDIR)\CharacterDecoder.obj"
	-@erase "$(INTDIR)\CharacterEncoder.obj"
	-@erase "$(INTDIR)\CharBuffer.obj"
	-@erase "$(INTDIR)\ChunkedInputStream.obj"
	-@erase "$(INTDIR)\CidURLStreamHandler.obj"
	-@erase "$(INTDIR)\DigestAuthentication.obj"
	-@erase "$(INTDIR)\File.obj"
	-@erase "$(INTDIR)\FileInputStream.obj"
	-@erase "$(INTDIR)\FileMIMEType.obj"
	-@erase "$(INTDIR)\FileOutputStream.obj"
	-@erase "$(INTDIR)\FileSystem.obj"
	-@erase "$(INTDIR)\FileURLConnection.obj"
	-@erase "$(INTDIR)\FileURLStreamHandler.obj"
	-@erase "$(INTDIR)\FilterInputStream.obj"
	-@erase "$(INTDIR)\FilterOutputStream.obj"
	-@erase "$(INTDIR)\HeaderParser.obj"
	-@erase "$(INTDIR)\HttpClient.obj"
	-@erase "$(INTDIR)\HttpsClient.obj"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpURLConnection.obj"
	-@erase "$(INTDIR)\HttpURLStreamHandler.obj"
	-@erase "$(INTDIR)\InetAddress.obj"
	-@erase "$(INTDIR)\InetAddressCachePolicy.obj"
	-@erase "$(INTDIR)\InetAddressImpl.obj"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\Integer.obj"
	-@erase "$(INTDIR)\Integer64.obj"
	-@erase "$(INTDIR)\mapWString.obj"
	-@erase "$(INTDIR)\md5.obj"
	-@erase "$(INTDIR)\MessageHeader.obj"
	-@erase "$(INTDIR)\MIMEBasicPart.obj"
	-@erase "$(INTDIR)\MIMEBodyPart.obj"
	-@erase "$(INTDIR)\MIMEHeader.obj"
	-@erase "$(INTDIR)\MIMEMessage.obj"
	-@erase "$(INTDIR)\MIMEMessagePart.obj"
	-@erase "$(INTDIR)\MIMEMultiPart.obj"
	-@erase "$(INTDIR)\MIMEParser.obj"
	-@erase "$(INTDIR)\MimeTableFileNameMap.obj"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\myuti.obj"
	-@erase "$(INTDIR)\NetworkClient.obj"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\PlainHttpOutputStream.obj"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpURLConnection.obj"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.obj"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\PrintStream.obj"
	-@erase "$(INTDIR)\PushbackInputStream.obj"
	-@erase "$(INTDIR)\QPDecoder.obj"
	-@erase "$(INTDIR)\QPEncoder.obj"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\RandomAccessInputStream.obj"
	-@erase "$(INTDIR)\RandomAccessOutputStream.obj"
	-@erase "$(INTDIR)\Regexp.obj"
	-@erase "$(INTDIR)\RegexpPool.obj"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\Socket.obj"
	-@erase "$(INTDIR)\SocketImpl.obj"
	-@erase "$(INTDIR)\SocketOptions.obj"
	-@erase "$(INTDIR)\SSLSocket.obj"
	-@erase "$(INTDIR)\SSLSocketInputStream.obj"
	-@erase "$(INTDIR)\SSLSocketOutputStream.obj"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StringTokenizer.obj"
	-@erase "$(INTDIR)\Synchronized.obj"
	-@erase "$(INTDIR)\Throwable.obj"
	-@erase "$(INTDIR)\Unicode.obj"
	-@erase "$(INTDIR)\URL.obj"
	-@erase "$(INTDIR)\URLConnection.obj"
	-@erase "$(INTDIR)\URLDecoder.obj"
	-@erase "$(INTDIR)\URLEncoder.obj"
	-@erase "$(INTDIR)\URLStreamHandler.obj"
	-@erase "$(INTDIR)\vdouble.obj"
	-@erase "$(INTDIR)\vint.obj"
	-@erase "$(INTDIR)\vMapWString.obj"
	-@erase "$(INTDIR)\vWString.obj"
	-@erase "$(INTDIR)\Win32FileSystem.obj"
	-@erase "$(INTDIR)\Win32InetAddressImpl.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32ProcessInputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.obj"
	-@erase "$(INTDIR)\Win32Shortcut.obj"
	-@erase "$(INTDIR)\Win32SocketFactoryService.obj"
	-@erase "$(INTDIR)\Win32SocketImpl.obj"
	-@erase "$(INTDIR)\Win32SocketImplFactory.obj"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.obj"
	-@erase "$(INTDIR)\Win32SocketInit.obj"
	-@erase "$(INTDIR)\WString.obj"
	-@erase "$(INTDIR)\WWWURLConnection.obj"
	-@erase "$(OUTDIR)\JDFToolsLib.lib"
	-@erase "..\..\..\Build\Win32\VC6\Release\JDFToolsLib.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MD /W3 /GR /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "JDF_TOOLS_LIB" /D "WIN32" /D "NDEBUG" /D "_LIB" /D "UNICODE" /D "_UNICODE" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\Release\JDFToolsLib" /FD /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFToolsLib.bsc" 
BSC32_SBRS= \
	
LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\JDFToolsLib.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Win32FileSystem.obj" \
	"$(INTDIR)\Win32Shortcut.obj" \
	"$(INTDIR)\BASE64Decoder.obj" \
	"$(INTDIR)\BASE64Encoder.obj" \
	"$(INTDIR)\BufferedInputStream.obj" \
	"$(INTDIR)\BufferedOutputStream.obj" \
	"$(INTDIR)\ByteArrayInputStream.obj" \
	"$(INTDIR)\ByteArrayOutputStream.obj" \
	"$(INTDIR)\CharacterDecoder.obj" \
	"$(INTDIR)\CharacterEncoder.obj" \
	"$(INTDIR)\File.obj" \
	"$(INTDIR)\FileInputStream.obj" \
	"$(INTDIR)\FileOutputStream.obj" \
	"$(INTDIR)\FileSystem.obj" \
	"$(INTDIR)\FilterInputStream.obj" \
	"$(INTDIR)\FilterOutputStream.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\PrintStream.obj" \
	"$(INTDIR)\PushbackInputStream.obj" \
	"$(INTDIR)\QPDecoder.obj" \
	"$(INTDIR)\QPEncoder.obj" \
	"$(INTDIR)\RandomAccessInputStream.obj" \
	"$(INTDIR)\RandomAccessOutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\Win32InetAddressImpl.obj" \
	"$(INTDIR)\Win32SocketFactoryService.obj" \
	"$(INTDIR)\Win32SocketImpl.obj" \
	"$(INTDIR)\Win32SocketImplFactory.obj" \
	"$(INTDIR)\Win32SocketImplInputStream.obj" \
	"$(INTDIR)\Win32SocketImplOutputStream.obj" \
	"$(INTDIR)\Win32SocketInit.obj" \
	"$(INTDIR)\FileURLConnection.obj" \
	"$(INTDIR)\FileURLStreamHandler.obj" \
	"$(INTDIR)\AuthenticationInfo.obj" \
	"$(INTDIR)\Authenticator.obj" \
	"$(INTDIR)\BasicAuthentication.obj" \
	"$(INTDIR)\ChunkedInputStream.obj" \
	"$(INTDIR)\DigestAuthentication.obj" \
	"$(INTDIR)\HttpClient.obj" \
	"$(INTDIR)\HttpURLConnection.obj" \
	"$(INTDIR)\HttpURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpOutputStream.obj" \
	"$(INTDIR)\PlainHttpURLConnection.obj" \
	"$(INTDIR)\HttpsClient.obj" \
	"$(INTDIR)\HttpsURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpsURLConnection.obj" \
	"$(INTDIR)\CidURLStreamHandler.obj" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.obj" \
	"$(INTDIR)\HeaderParser.obj" \
	"$(INTDIR)\InetAddress.obj" \
	"$(INTDIR)\InetAddressCachePolicy.obj" \
	"$(INTDIR)\InetAddressImpl.obj" \
	"$(INTDIR)\md5.obj" \
	"$(INTDIR)\MessageHeader.obj" \
	"$(INTDIR)\NetworkClient.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\Socket.obj" \
	"$(INTDIR)\SocketImpl.obj" \
	"$(INTDIR)\SocketOptions.obj" \
	"$(INTDIR)\SSLSocket.obj" \
	"$(INTDIR)\SSLSocketInputStream.obj" \
	"$(INTDIR)\SSLSocketOutputStream.obj" \
	"$(INTDIR)\URL.obj" \
	"$(INTDIR)\URLConnection.obj" \
	"$(INTDIR)\URLDecoder.obj" \
	"$(INTDIR)\URLEncoder.obj" \
	"$(INTDIR)\URLStreamHandler.obj" \
	"$(INTDIR)\WWWURLConnection.obj" \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32ProcessInputStream.obj" \
	"$(INTDIR)\Win32ProcessOutputStream.obj" \
	"$(INTDIR)\myuti.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\Regexp.obj" \
	"$(INTDIR)\RegexpPool.obj" \
	"$(INTDIR)\StringTokenizer.obj" \
	"$(INTDIR)\Unicode.obj" \
	"$(INTDIR)\FileMIMEType.obj" \
	"$(INTDIR)\MIMEBasicPart.obj" \
	"$(INTDIR)\MIMEBodyPart.obj" \
	"$(INTDIR)\MIMEHeader.obj" \
	"$(INTDIR)\MIMEMessage.obj" \
	"$(INTDIR)\MIMEMessagePart.obj" \
	"$(INTDIR)\MIMEMultiPart.obj" \
	"$(INTDIR)\MIMEParser.obj" \
	"$(INTDIR)\MimeTableFileNameMap.obj" \
	"$(INTDIR)\AutoPtr.obj" \
	"$(INTDIR)\BoolJanitor.obj" \
	"$(INTDIR)\ByteBuffer.obj" \
	"$(INTDIR)\CharBuffer.obj" \
	"$(INTDIR)\Integer.obj" \
	"$(INTDIR)\Integer64.obj" \
	"$(INTDIR)\mapWString.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\Synchronized.obj" \
	"$(INTDIR)\Throwable.obj" \
	"$(INTDIR)\vdouble.obj" \
	"$(INTDIR)\vint.obj" \
	"$(INTDIR)\vMapWString.obj" \
	"$(INTDIR)\vWString.obj" \
	"$(INTDIR)\WString.obj" \
	"..\..\..\external\xerces\lib\xerces-c_2.lib"

"$(OUTDIR)\JDFToolsLib.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"

OUTDIR=.\..\..\..\Build\Win32\VC6\Debug
INTDIR=.\..\..\..\Build\Win32\VC6\Debug\obj\JDFToolsLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\Debug
# End Custom Macros

ALL : "$(OUTDIR)\jdftoolslib_D.lib" "$(OUTDIR)\JDFToolsLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\AuthenticationInfo.obj"
	-@erase "$(INTDIR)\AuthenticationInfo.sbr"
	-@erase "$(INTDIR)\Authenticator.obj"
	-@erase "$(INTDIR)\Authenticator.sbr"
	-@erase "$(INTDIR)\AutoPtr.obj"
	-@erase "$(INTDIR)\AutoPtr.sbr"
	-@erase "$(INTDIR)\BASE64Decoder.obj"
	-@erase "$(INTDIR)\BASE64Decoder.sbr"
	-@erase "$(INTDIR)\BASE64Encoder.obj"
	-@erase "$(INTDIR)\BASE64Encoder.sbr"
	-@erase "$(INTDIR)\BasicAuthentication.obj"
	-@erase "$(INTDIR)\BasicAuthentication.sbr"
	-@erase "$(INTDIR)\BoolJanitor.obj"
	-@erase "$(INTDIR)\BoolJanitor.sbr"
	-@erase "$(INTDIR)\BufferedInputStream.obj"
	-@erase "$(INTDIR)\BufferedInputStream.sbr"
	-@erase "$(INTDIR)\BufferedOutputStream.obj"
	-@erase "$(INTDIR)\BufferedOutputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayInputStream.obj"
	-@erase "$(INTDIR)\ByteArrayInputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayOutputStream.obj"
	-@erase "$(INTDIR)\ByteArrayOutputStream.sbr"
	-@erase "$(INTDIR)\ByteBuffer.obj"
	-@erase "$(INTDIR)\ByteBuffer.sbr"
	-@erase "$(INTDIR)\CharacterDecoder.obj"
	-@erase "$(INTDIR)\CharacterDecoder.sbr"
	-@erase "$(INTDIR)\CharacterEncoder.obj"
	-@erase "$(INTDIR)\CharacterEncoder.sbr"
	-@erase "$(INTDIR)\CharBuffer.obj"
	-@erase "$(INTDIR)\CharBuffer.sbr"
	-@erase "$(INTDIR)\ChunkedInputStream.obj"
	-@erase "$(INTDIR)\ChunkedInputStream.sbr"
	-@erase "$(INTDIR)\CidURLStreamHandler.obj"
	-@erase "$(INTDIR)\CidURLStreamHandler.sbr"
	-@erase "$(INTDIR)\DigestAuthentication.obj"
	-@erase "$(INTDIR)\DigestAuthentication.sbr"
	-@erase "$(INTDIR)\File.obj"
	-@erase "$(INTDIR)\File.sbr"
	-@erase "$(INTDIR)\FileInputStream.obj"
	-@erase "$(INTDIR)\FileInputStream.sbr"
	-@erase "$(INTDIR)\FileMIMEType.obj"
	-@erase "$(INTDIR)\FileMIMEType.sbr"
	-@erase "$(INTDIR)\FileOutputStream.obj"
	-@erase "$(INTDIR)\FileOutputStream.sbr"
	-@erase "$(INTDIR)\FileSystem.obj"
	-@erase "$(INTDIR)\FileSystem.sbr"
	-@erase "$(INTDIR)\FileURLConnection.obj"
	-@erase "$(INTDIR)\FileURLConnection.sbr"
	-@erase "$(INTDIR)\FileURLStreamHandler.obj"
	-@erase "$(INTDIR)\FileURLStreamHandler.sbr"
	-@erase "$(INTDIR)\FilterInputStream.obj"
	-@erase "$(INTDIR)\FilterInputStream.sbr"
	-@erase "$(INTDIR)\FilterOutputStream.obj"
	-@erase "$(INTDIR)\FilterOutputStream.sbr"
	-@erase "$(INTDIR)\HeaderParser.obj"
	-@erase "$(INTDIR)\HeaderParser.sbr"
	-@erase "$(INTDIR)\HttpClient.obj"
	-@erase "$(INTDIR)\HttpClient.sbr"
	-@erase "$(INTDIR)\HttpsClient.obj"
	-@erase "$(INTDIR)\HttpsClient.sbr"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.sbr"
	-@erase "$(INTDIR)\HttpURLConnection.obj"
	-@erase "$(INTDIR)\HttpURLConnection.sbr"
	-@erase "$(INTDIR)\HttpURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpURLStreamHandler.sbr"
	-@erase "$(INTDIR)\InetAddress.obj"
	-@erase "$(INTDIR)\InetAddress.sbr"
	-@erase "$(INTDIR)\InetAddressCachePolicy.obj"
	-@erase "$(INTDIR)\InetAddressCachePolicy.sbr"
	-@erase "$(INTDIR)\InetAddressImpl.obj"
	-@erase "$(INTDIR)\InetAddressImpl.sbr"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\InputStream.sbr"
	-@erase "$(INTDIR)\Integer.obj"
	-@erase "$(INTDIR)\Integer.sbr"
	-@erase "$(INTDIR)\Integer64.obj"
	-@erase "$(INTDIR)\Integer64.sbr"
	-@erase "$(INTDIR)\mapWString.obj"
	-@erase "$(INTDIR)\mapWString.sbr"
	-@erase "$(INTDIR)\md5.obj"
	-@erase "$(INTDIR)\md5.sbr"
	-@erase "$(INTDIR)\MessageHeader.obj"
	-@erase "$(INTDIR)\MessageHeader.sbr"
	-@erase "$(INTDIR)\MIMEBasicPart.obj"
	-@erase "$(INTDIR)\MIMEBasicPart.sbr"
	-@erase "$(INTDIR)\MIMEBodyPart.obj"
	-@erase "$(INTDIR)\MIMEBodyPart.sbr"
	-@erase "$(INTDIR)\MIMEHeader.obj"
	-@erase "$(INTDIR)\MIMEHeader.sbr"
	-@erase "$(INTDIR)\MIMEMessage.obj"
	-@erase "$(INTDIR)\MIMEMessage.sbr"
	-@erase "$(INTDIR)\MIMEMessagePart.obj"
	-@erase "$(INTDIR)\MIMEMessagePart.sbr"
	-@erase "$(INTDIR)\MIMEMultiPart.obj"
	-@erase "$(INTDIR)\MIMEMultiPart.sbr"
	-@erase "$(INTDIR)\MIMEParser.obj"
	-@erase "$(INTDIR)\MIMEParser.sbr"
	-@erase "$(INTDIR)\MimeTableFileNameMap.obj"
	-@erase "$(INTDIR)\MimeTableFileNameMap.sbr"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\Mutex.sbr"
	-@erase "$(INTDIR)\myuti.obj"
	-@erase "$(INTDIR)\myuti.sbr"
	-@erase "$(INTDIR)\NetworkClient.obj"
	-@erase "$(INTDIR)\NetworkClient.sbr"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\OutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpOutputStream.obj"
	-@erase "$(INTDIR)\PlainHttpOutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.sbr"
	-@erase "$(INTDIR)\PlainHttpURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpURLConnection.sbr"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.obj"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.sbr"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\PlatformUtils.sbr"
	-@erase "$(INTDIR)\PrintStream.obj"
	-@erase "$(INTDIR)\PrintStream.sbr"
	-@erase "$(INTDIR)\PushbackInputStream.obj"
	-@erase "$(INTDIR)\PushbackInputStream.sbr"
	-@erase "$(INTDIR)\QPDecoder.obj"
	-@erase "$(INTDIR)\QPDecoder.sbr"
	-@erase "$(INTDIR)\QPEncoder.obj"
	-@erase "$(INTDIR)\QPEncoder.sbr"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\Random.sbr"
	-@erase "$(INTDIR)\RandomAccessInputStream.obj"
	-@erase "$(INTDIR)\RandomAccessInputStream.sbr"
	-@erase "$(INTDIR)\RandomAccessOutputStream.obj"
	-@erase "$(INTDIR)\RandomAccessOutputStream.sbr"
	-@erase "$(INTDIR)\Regexp.obj"
	-@erase "$(INTDIR)\Regexp.sbr"
	-@erase "$(INTDIR)\RegexpPool.obj"
	-@erase "$(INTDIR)\RegexpPool.sbr"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\ServerSocket.sbr"
	-@erase "$(INTDIR)\Socket.obj"
	-@erase "$(INTDIR)\Socket.sbr"
	-@erase "$(INTDIR)\SocketImpl.obj"
	-@erase "$(INTDIR)\SocketImpl.sbr"
	-@erase "$(INTDIR)\SocketOptions.obj"
	-@erase "$(INTDIR)\SocketOptions.sbr"
	-@erase "$(INTDIR)\SSLSocket.obj"
	-@erase "$(INTDIR)\SSLSocket.sbr"
	-@erase "$(INTDIR)\SSLSocketInputStream.obj"
	-@erase "$(INTDIR)\SSLSocketInputStream.sbr"
	-@erase "$(INTDIR)\SSLSocketOutputStream.obj"
	-@erase "$(INTDIR)\SSLSocketOutputStream.sbr"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StreamBuffer.sbr"
	-@erase "$(INTDIR)\StringTokenizer.obj"
	-@erase "$(INTDIR)\StringTokenizer.sbr"
	-@erase "$(INTDIR)\Synchronized.obj"
	-@erase "$(INTDIR)\Synchronized.sbr"
	-@erase "$(INTDIR)\Throwable.obj"
	-@erase "$(INTDIR)\Throwable.sbr"
	-@erase "$(INTDIR)\Unicode.obj"
	-@erase "$(INTDIR)\Unicode.sbr"
	-@erase "$(INTDIR)\URL.obj"
	-@erase "$(INTDIR)\URL.sbr"
	-@erase "$(INTDIR)\URLConnection.obj"
	-@erase "$(INTDIR)\URLConnection.sbr"
	-@erase "$(INTDIR)\URLDecoder.obj"
	-@erase "$(INTDIR)\URLDecoder.sbr"
	-@erase "$(INTDIR)\URLEncoder.obj"
	-@erase "$(INTDIR)\URLEncoder.sbr"
	-@erase "$(INTDIR)\URLStreamHandler.obj"
	-@erase "$(INTDIR)\URLStreamHandler.sbr"
	-@erase "$(INTDIR)\vdouble.obj"
	-@erase "$(INTDIR)\vdouble.sbr"
	-@erase "$(INTDIR)\vint.obj"
	-@erase "$(INTDIR)\vint.sbr"
	-@erase "$(INTDIR)\vMapWString.obj"
	-@erase "$(INTDIR)\vMapWString.sbr"
	-@erase "$(INTDIR)\vWString.obj"
	-@erase "$(INTDIR)\vWString.sbr"
	-@erase "$(INTDIR)\Win32FileSystem.obj"
	-@erase "$(INTDIR)\Win32FileSystem.sbr"
	-@erase "$(INTDIR)\Win32InetAddressImpl.obj"
	-@erase "$(INTDIR)\Win32InetAddressImpl.sbr"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.sbr"
	-@erase "$(INTDIR)\Win32ProcessInputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessInputStream.sbr"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.sbr"
	-@erase "$(INTDIR)\Win32Shortcut.obj"
	-@erase "$(INTDIR)\Win32Shortcut.sbr"
	-@erase "$(INTDIR)\Win32SocketFactoryService.obj"
	-@erase "$(INTDIR)\Win32SocketFactoryService.sbr"
	-@erase "$(INTDIR)\Win32SocketImpl.obj"
	-@erase "$(INTDIR)\Win32SocketImpl.sbr"
	-@erase "$(INTDIR)\Win32SocketImplFactory.obj"
	-@erase "$(INTDIR)\Win32SocketImplFactory.sbr"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketInit.obj"
	-@erase "$(INTDIR)\Win32SocketInit.sbr"
	-@erase "$(INTDIR)\WString.obj"
	-@erase "$(INTDIR)\WString.sbr"
	-@erase "$(INTDIR)\WWWURLConnection.obj"
	-@erase "$(INTDIR)\WWWURLConnection.sbr"
	-@erase "$(OUTDIR)\JDFToolsLib.bsc"
	-@erase "$(OUTDIR)\jdftoolslib_D.lib"
	-@erase "..\..\..\Build\Win32\VC6\Debug\JDFToolsLib.idb"
	-@erase "..\..\..\Build\Win32\VC6\Debug\JDFToolsLib.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GR /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "JDF_TOOLS_LIB" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\Debug\JDFToolsLib" /FD /GZ /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFToolsLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Win32FileSystem.sbr" \
	"$(INTDIR)\Win32Shortcut.sbr" \
	"$(INTDIR)\BASE64Decoder.sbr" \
	"$(INTDIR)\BASE64Encoder.sbr" \
	"$(INTDIR)\BufferedInputStream.sbr" \
	"$(INTDIR)\BufferedOutputStream.sbr" \
	"$(INTDIR)\ByteArrayInputStream.sbr" \
	"$(INTDIR)\ByteArrayOutputStream.sbr" \
	"$(INTDIR)\CharacterDecoder.sbr" \
	"$(INTDIR)\CharacterEncoder.sbr" \
	"$(INTDIR)\File.sbr" \
	"$(INTDIR)\FileInputStream.sbr" \
	"$(INTDIR)\FileOutputStream.sbr" \
	"$(INTDIR)\FileSystem.sbr" \
	"$(INTDIR)\FilterInputStream.sbr" \
	"$(INTDIR)\FilterOutputStream.sbr" \
	"$(INTDIR)\InputStream.sbr" \
	"$(INTDIR)\OutputStream.sbr" \
	"$(INTDIR)\PrintStream.sbr" \
	"$(INTDIR)\PushbackInputStream.sbr" \
	"$(INTDIR)\QPDecoder.sbr" \
	"$(INTDIR)\QPEncoder.sbr" \
	"$(INTDIR)\RandomAccessInputStream.sbr" \
	"$(INTDIR)\RandomAccessOutputStream.sbr" \
	"$(INTDIR)\StreamBuffer.sbr" \
	"$(INTDIR)\Win32InetAddressImpl.sbr" \
	"$(INTDIR)\Win32SocketFactoryService.sbr" \
	"$(INTDIR)\Win32SocketImpl.sbr" \
	"$(INTDIR)\Win32SocketImplFactory.sbr" \
	"$(INTDIR)\Win32SocketImplInputStream.sbr" \
	"$(INTDIR)\Win32SocketImplOutputStream.sbr" \
	"$(INTDIR)\Win32SocketInit.sbr" \
	"$(INTDIR)\FileURLConnection.sbr" \
	"$(INTDIR)\FileURLStreamHandler.sbr" \
	"$(INTDIR)\AuthenticationInfo.sbr" \
	"$(INTDIR)\Authenticator.sbr" \
	"$(INTDIR)\BasicAuthentication.sbr" \
	"$(INTDIR)\ChunkedInputStream.sbr" \
	"$(INTDIR)\DigestAuthentication.sbr" \
	"$(INTDIR)\HttpClient.sbr" \
	"$(INTDIR)\HttpURLConnection.sbr" \
	"$(INTDIR)\HttpURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpOutputStream.sbr" \
	"$(INTDIR)\PlainHttpURLConnection.sbr" \
	"$(INTDIR)\HttpsClient.sbr" \
	"$(INTDIR)\HttpsURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpsURLConnection.sbr" \
	"$(INTDIR)\CidURLStreamHandler.sbr" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" \
	"$(INTDIR)\HeaderParser.sbr" \
	"$(INTDIR)\InetAddress.sbr" \
	"$(INTDIR)\InetAddressCachePolicy.sbr" \
	"$(INTDIR)\InetAddressImpl.sbr" \
	"$(INTDIR)\md5.sbr" \
	"$(INTDIR)\MessageHeader.sbr" \
	"$(INTDIR)\NetworkClient.sbr" \
	"$(INTDIR)\ServerSocket.sbr" \
	"$(INTDIR)\Socket.sbr" \
	"$(INTDIR)\SocketImpl.sbr" \
	"$(INTDIR)\SocketOptions.sbr" \
	"$(INTDIR)\SSLSocket.sbr" \
	"$(INTDIR)\SSLSocketInputStream.sbr" \
	"$(INTDIR)\SSLSocketOutputStream.sbr" \
	"$(INTDIR)\URL.sbr" \
	"$(INTDIR)\URLConnection.sbr" \
	"$(INTDIR)\URLDecoder.sbr" \
	"$(INTDIR)\URLEncoder.sbr" \
	"$(INTDIR)\URLStreamHandler.sbr" \
	"$(INTDIR)\WWWURLConnection.sbr" \
	"$(INTDIR)\Win32PlatformUtils.sbr" \
	"$(INTDIR)\Win32ProcessInputStream.sbr" \
	"$(INTDIR)\Win32ProcessOutputStream.sbr" \
	"$(INTDIR)\myuti.sbr" \
	"$(INTDIR)\PlatformUtils.sbr" \
	"$(INTDIR)\Random.sbr" \
	"$(INTDIR)\Regexp.sbr" \
	"$(INTDIR)\RegexpPool.sbr" \
	"$(INTDIR)\StringTokenizer.sbr" \
	"$(INTDIR)\Unicode.sbr" \
	"$(INTDIR)\FileMIMEType.sbr" \
	"$(INTDIR)\MIMEBasicPart.sbr" \
	"$(INTDIR)\MIMEBodyPart.sbr" \
	"$(INTDIR)\MIMEHeader.sbr" \
	"$(INTDIR)\MIMEMessage.sbr" \
	"$(INTDIR)\MIMEMessagePart.sbr" \
	"$(INTDIR)\MIMEMultiPart.sbr" \
	"$(INTDIR)\MIMEParser.sbr" \
	"$(INTDIR)\MimeTableFileNameMap.sbr" \
	"$(INTDIR)\AutoPtr.sbr" \
	"$(INTDIR)\BoolJanitor.sbr" \
	"$(INTDIR)\ByteBuffer.sbr" \
	"$(INTDIR)\CharBuffer.sbr" \
	"$(INTDIR)\Integer.sbr" \
	"$(INTDIR)\Integer64.sbr" \
	"$(INTDIR)\mapWString.sbr" \
	"$(INTDIR)\Mutex.sbr" \
	"$(INTDIR)\Synchronized.sbr" \
	"$(INTDIR)\Throwable.sbr" \
	"$(INTDIR)\vdouble.sbr" \
	"$(INTDIR)\vint.sbr" \
	"$(INTDIR)\vMapWString.sbr" \
	"$(INTDIR)\vWString.sbr" \
	"$(INTDIR)\WString.sbr"

"$(OUTDIR)\JDFToolsLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\jdftoolslib_D.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Win32FileSystem.obj" \
	"$(INTDIR)\Win32Shortcut.obj" \
	"$(INTDIR)\BASE64Decoder.obj" \
	"$(INTDIR)\BASE64Encoder.obj" \
	"$(INTDIR)\BufferedInputStream.obj" \
	"$(INTDIR)\BufferedOutputStream.obj" \
	"$(INTDIR)\ByteArrayInputStream.obj" \
	"$(INTDIR)\ByteArrayOutputStream.obj" \
	"$(INTDIR)\CharacterDecoder.obj" \
	"$(INTDIR)\CharacterEncoder.obj" \
	"$(INTDIR)\File.obj" \
	"$(INTDIR)\FileInputStream.obj" \
	"$(INTDIR)\FileOutputStream.obj" \
	"$(INTDIR)\FileSystem.obj" \
	"$(INTDIR)\FilterInputStream.obj" \
	"$(INTDIR)\FilterOutputStream.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\PrintStream.obj" \
	"$(INTDIR)\PushbackInputStream.obj" \
	"$(INTDIR)\QPDecoder.obj" \
	"$(INTDIR)\QPEncoder.obj" \
	"$(INTDIR)\RandomAccessInputStream.obj" \
	"$(INTDIR)\RandomAccessOutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\Win32InetAddressImpl.obj" \
	"$(INTDIR)\Win32SocketFactoryService.obj" \
	"$(INTDIR)\Win32SocketImpl.obj" \
	"$(INTDIR)\Win32SocketImplFactory.obj" \
	"$(INTDIR)\Win32SocketImplInputStream.obj" \
	"$(INTDIR)\Win32SocketImplOutputStream.obj" \
	"$(INTDIR)\Win32SocketInit.obj" \
	"$(INTDIR)\FileURLConnection.obj" \
	"$(INTDIR)\FileURLStreamHandler.obj" \
	"$(INTDIR)\AuthenticationInfo.obj" \
	"$(INTDIR)\Authenticator.obj" \
	"$(INTDIR)\BasicAuthentication.obj" \
	"$(INTDIR)\ChunkedInputStream.obj" \
	"$(INTDIR)\DigestAuthentication.obj" \
	"$(INTDIR)\HttpClient.obj" \
	"$(INTDIR)\HttpURLConnection.obj" \
	"$(INTDIR)\HttpURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpOutputStream.obj" \
	"$(INTDIR)\PlainHttpURLConnection.obj" \
	"$(INTDIR)\HttpsClient.obj" \
	"$(INTDIR)\HttpsURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpsURLConnection.obj" \
	"$(INTDIR)\CidURLStreamHandler.obj" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.obj" \
	"$(INTDIR)\HeaderParser.obj" \
	"$(INTDIR)\InetAddress.obj" \
	"$(INTDIR)\InetAddressCachePolicy.obj" \
	"$(INTDIR)\InetAddressImpl.obj" \
	"$(INTDIR)\md5.obj" \
	"$(INTDIR)\MessageHeader.obj" \
	"$(INTDIR)\NetworkClient.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\Socket.obj" \
	"$(INTDIR)\SocketImpl.obj" \
	"$(INTDIR)\SocketOptions.obj" \
	"$(INTDIR)\SSLSocket.obj" \
	"$(INTDIR)\SSLSocketInputStream.obj" \
	"$(INTDIR)\SSLSocketOutputStream.obj" \
	"$(INTDIR)\URL.obj" \
	"$(INTDIR)\URLConnection.obj" \
	"$(INTDIR)\URLDecoder.obj" \
	"$(INTDIR)\URLEncoder.obj" \
	"$(INTDIR)\URLStreamHandler.obj" \
	"$(INTDIR)\WWWURLConnection.obj" \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32ProcessInputStream.obj" \
	"$(INTDIR)\Win32ProcessOutputStream.obj" \
	"$(INTDIR)\myuti.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\Regexp.obj" \
	"$(INTDIR)\RegexpPool.obj" \
	"$(INTDIR)\StringTokenizer.obj" \
	"$(INTDIR)\Unicode.obj" \
	"$(INTDIR)\FileMIMEType.obj" \
	"$(INTDIR)\MIMEBasicPart.obj" \
	"$(INTDIR)\MIMEBodyPart.obj" \
	"$(INTDIR)\MIMEHeader.obj" \
	"$(INTDIR)\MIMEMessage.obj" \
	"$(INTDIR)\MIMEMessagePart.obj" \
	"$(INTDIR)\MIMEMultiPart.obj" \
	"$(INTDIR)\MIMEParser.obj" \
	"$(INTDIR)\MimeTableFileNameMap.obj" \
	"$(INTDIR)\AutoPtr.obj" \
	"$(INTDIR)\BoolJanitor.obj" \
	"$(INTDIR)\ByteBuffer.obj" \
	"$(INTDIR)\CharBuffer.obj" \
	"$(INTDIR)\Integer.obj" \
	"$(INTDIR)\Integer64.obj" \
	"$(INTDIR)\mapWString.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\Synchronized.obj" \
	"$(INTDIR)\Throwable.obj" \
	"$(INTDIR)\vdouble.obj" \
	"$(INTDIR)\vint.obj" \
	"$(INTDIR)\vMapWString.obj" \
	"$(INTDIR)\vWString.obj" \
	"$(INTDIR)\WString.obj" \
	"..\..\..\external\xerces\lib\xerces-c_2D.lib"

"$(OUTDIR)\jdftoolslib_D.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"

OUTDIR=.\..\..\..\Build\Win32\VC6\DebugDLL
INTDIR=.\..\..\..\Build\Win32\VC6\DebugDLL\obj\JDFToolsDLL
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\DebugDLL
# End Custom Macros

ALL : "$(OUTDIR)\JDFToolsDLLd.dll" "$(OUTDIR)\JDFToolsLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\AuthenticationInfo.obj"
	-@erase "$(INTDIR)\AuthenticationInfo.sbr"
	-@erase "$(INTDIR)\Authenticator.obj"
	-@erase "$(INTDIR)\Authenticator.sbr"
	-@erase "$(INTDIR)\AutoPtr.obj"
	-@erase "$(INTDIR)\AutoPtr.sbr"
	-@erase "$(INTDIR)\BASE64Decoder.obj"
	-@erase "$(INTDIR)\BASE64Decoder.sbr"
	-@erase "$(INTDIR)\BASE64Encoder.obj"
	-@erase "$(INTDIR)\BASE64Encoder.sbr"
	-@erase "$(INTDIR)\BasicAuthentication.obj"
	-@erase "$(INTDIR)\BasicAuthentication.sbr"
	-@erase "$(INTDIR)\BoolJanitor.obj"
	-@erase "$(INTDIR)\BoolJanitor.sbr"
	-@erase "$(INTDIR)\BufferedInputStream.obj"
	-@erase "$(INTDIR)\BufferedInputStream.sbr"
	-@erase "$(INTDIR)\BufferedOutputStream.obj"
	-@erase "$(INTDIR)\BufferedOutputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayInputStream.obj"
	-@erase "$(INTDIR)\ByteArrayInputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayOutputStream.obj"
	-@erase "$(INTDIR)\ByteArrayOutputStream.sbr"
	-@erase "$(INTDIR)\ByteBuffer.obj"
	-@erase "$(INTDIR)\ByteBuffer.sbr"
	-@erase "$(INTDIR)\CharacterDecoder.obj"
	-@erase "$(INTDIR)\CharacterDecoder.sbr"
	-@erase "$(INTDIR)\CharacterEncoder.obj"
	-@erase "$(INTDIR)\CharacterEncoder.sbr"
	-@erase "$(INTDIR)\CharBuffer.obj"
	-@erase "$(INTDIR)\CharBuffer.sbr"
	-@erase "$(INTDIR)\ChunkedInputStream.obj"
	-@erase "$(INTDIR)\ChunkedInputStream.sbr"
	-@erase "$(INTDIR)\CidURLStreamHandler.obj"
	-@erase "$(INTDIR)\CidURLStreamHandler.sbr"
	-@erase "$(INTDIR)\DigestAuthentication.obj"
	-@erase "$(INTDIR)\DigestAuthentication.sbr"
	-@erase "$(INTDIR)\File.obj"
	-@erase "$(INTDIR)\File.sbr"
	-@erase "$(INTDIR)\FileInputStream.obj"
	-@erase "$(INTDIR)\FileInputStream.sbr"
	-@erase "$(INTDIR)\FileMIMEType.obj"
	-@erase "$(INTDIR)\FileMIMEType.sbr"
	-@erase "$(INTDIR)\FileOutputStream.obj"
	-@erase "$(INTDIR)\FileOutputStream.sbr"
	-@erase "$(INTDIR)\FileSystem.obj"
	-@erase "$(INTDIR)\FileSystem.sbr"
	-@erase "$(INTDIR)\FileURLConnection.obj"
	-@erase "$(INTDIR)\FileURLConnection.sbr"
	-@erase "$(INTDIR)\FileURLStreamHandler.obj"
	-@erase "$(INTDIR)\FileURLStreamHandler.sbr"
	-@erase "$(INTDIR)\FilterInputStream.obj"
	-@erase "$(INTDIR)\FilterInputStream.sbr"
	-@erase "$(INTDIR)\FilterOutputStream.obj"
	-@erase "$(INTDIR)\FilterOutputStream.sbr"
	-@erase "$(INTDIR)\HeaderParser.obj"
	-@erase "$(INTDIR)\HeaderParser.sbr"
	-@erase "$(INTDIR)\HttpClient.obj"
	-@erase "$(INTDIR)\HttpClient.sbr"
	-@erase "$(INTDIR)\HttpsClient.obj"
	-@erase "$(INTDIR)\HttpsClient.sbr"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.sbr"
	-@erase "$(INTDIR)\HttpURLConnection.obj"
	-@erase "$(INTDIR)\HttpURLConnection.sbr"
	-@erase "$(INTDIR)\HttpURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpURLStreamHandler.sbr"
	-@erase "$(INTDIR)\InetAddress.obj"
	-@erase "$(INTDIR)\InetAddress.sbr"
	-@erase "$(INTDIR)\InetAddressCachePolicy.obj"
	-@erase "$(INTDIR)\InetAddressCachePolicy.sbr"
	-@erase "$(INTDIR)\InetAddressImpl.obj"
	-@erase "$(INTDIR)\InetAddressImpl.sbr"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\InputStream.sbr"
	-@erase "$(INTDIR)\Integer.obj"
	-@erase "$(INTDIR)\Integer.sbr"
	-@erase "$(INTDIR)\Integer64.obj"
	-@erase "$(INTDIR)\Integer64.sbr"
	-@erase "$(INTDIR)\mapWString.obj"
	-@erase "$(INTDIR)\mapWString.sbr"
	-@erase "$(INTDIR)\md5.obj"
	-@erase "$(INTDIR)\md5.sbr"
	-@erase "$(INTDIR)\MessageHeader.obj"
	-@erase "$(INTDIR)\MessageHeader.sbr"
	-@erase "$(INTDIR)\MIMEBasicPart.obj"
	-@erase "$(INTDIR)\MIMEBasicPart.sbr"
	-@erase "$(INTDIR)\MIMEBodyPart.obj"
	-@erase "$(INTDIR)\MIMEBodyPart.sbr"
	-@erase "$(INTDIR)\MIMEHeader.obj"
	-@erase "$(INTDIR)\MIMEHeader.sbr"
	-@erase "$(INTDIR)\MIMEMessage.obj"
	-@erase "$(INTDIR)\MIMEMessage.sbr"
	-@erase "$(INTDIR)\MIMEMessagePart.obj"
	-@erase "$(INTDIR)\MIMEMessagePart.sbr"
	-@erase "$(INTDIR)\MIMEMultiPart.obj"
	-@erase "$(INTDIR)\MIMEMultiPart.sbr"
	-@erase "$(INTDIR)\MIMEParser.obj"
	-@erase "$(INTDIR)\MIMEParser.sbr"
	-@erase "$(INTDIR)\MimeTableFileNameMap.obj"
	-@erase "$(INTDIR)\MimeTableFileNameMap.sbr"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\Mutex.sbr"
	-@erase "$(INTDIR)\myuti.obj"
	-@erase "$(INTDIR)\myuti.sbr"
	-@erase "$(INTDIR)\NetworkClient.obj"
	-@erase "$(INTDIR)\NetworkClient.sbr"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\OutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpOutputStream.obj"
	-@erase "$(INTDIR)\PlainHttpOutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.sbr"
	-@erase "$(INTDIR)\PlainHttpURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpURLConnection.sbr"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.obj"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.sbr"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\PlatformUtils.sbr"
	-@erase "$(INTDIR)\PrintStream.obj"
	-@erase "$(INTDIR)\PrintStream.sbr"
	-@erase "$(INTDIR)\PushbackInputStream.obj"
	-@erase "$(INTDIR)\PushbackInputStream.sbr"
	-@erase "$(INTDIR)\QPDecoder.obj"
	-@erase "$(INTDIR)\QPDecoder.sbr"
	-@erase "$(INTDIR)\QPEncoder.obj"
	-@erase "$(INTDIR)\QPEncoder.sbr"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\Random.sbr"
	-@erase "$(INTDIR)\RandomAccessInputStream.obj"
	-@erase "$(INTDIR)\RandomAccessInputStream.sbr"
	-@erase "$(INTDIR)\RandomAccessOutputStream.obj"
	-@erase "$(INTDIR)\RandomAccessOutputStream.sbr"
	-@erase "$(INTDIR)\Regexp.obj"
	-@erase "$(INTDIR)\Regexp.sbr"
	-@erase "$(INTDIR)\RegexpPool.obj"
	-@erase "$(INTDIR)\RegexpPool.sbr"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\ServerSocket.sbr"
	-@erase "$(INTDIR)\Socket.obj"
	-@erase "$(INTDIR)\Socket.sbr"
	-@erase "$(INTDIR)\SocketImpl.obj"
	-@erase "$(INTDIR)\SocketImpl.sbr"
	-@erase "$(INTDIR)\SocketOptions.obj"
	-@erase "$(INTDIR)\SocketOptions.sbr"
	-@erase "$(INTDIR)\SSLSocket.obj"
	-@erase "$(INTDIR)\SSLSocket.sbr"
	-@erase "$(INTDIR)\SSLSocketInputStream.obj"
	-@erase "$(INTDIR)\SSLSocketInputStream.sbr"
	-@erase "$(INTDIR)\SSLSocketOutputStream.obj"
	-@erase "$(INTDIR)\SSLSocketOutputStream.sbr"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StreamBuffer.sbr"
	-@erase "$(INTDIR)\StringTokenizer.obj"
	-@erase "$(INTDIR)\StringTokenizer.sbr"
	-@erase "$(INTDIR)\Synchronized.obj"
	-@erase "$(INTDIR)\Synchronized.sbr"
	-@erase "$(INTDIR)\Throwable.obj"
	-@erase "$(INTDIR)\Throwable.sbr"
	-@erase "$(INTDIR)\Unicode.obj"
	-@erase "$(INTDIR)\Unicode.sbr"
	-@erase "$(INTDIR)\URL.obj"
	-@erase "$(INTDIR)\URL.sbr"
	-@erase "$(INTDIR)\URLConnection.obj"
	-@erase "$(INTDIR)\URLConnection.sbr"
	-@erase "$(INTDIR)\URLDecoder.obj"
	-@erase "$(INTDIR)\URLDecoder.sbr"
	-@erase "$(INTDIR)\URLEncoder.obj"
	-@erase "$(INTDIR)\URLEncoder.sbr"
	-@erase "$(INTDIR)\URLStreamHandler.obj"
	-@erase "$(INTDIR)\URLStreamHandler.sbr"
	-@erase "$(INTDIR)\vdouble.obj"
	-@erase "$(INTDIR)\vdouble.sbr"
	-@erase "$(INTDIR)\vint.obj"
	-@erase "$(INTDIR)\vint.sbr"
	-@erase "$(INTDIR)\vMapWString.obj"
	-@erase "$(INTDIR)\vMapWString.sbr"
	-@erase "$(INTDIR)\vWString.obj"
	-@erase "$(INTDIR)\vWString.sbr"
	-@erase "$(INTDIR)\Win32FileSystem.obj"
	-@erase "$(INTDIR)\Win32FileSystem.sbr"
	-@erase "$(INTDIR)\Win32InetAddressImpl.obj"
	-@erase "$(INTDIR)\Win32InetAddressImpl.sbr"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.sbr"
	-@erase "$(INTDIR)\Win32ProcessInputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessInputStream.sbr"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.sbr"
	-@erase "$(INTDIR)\Win32Shortcut.obj"
	-@erase "$(INTDIR)\Win32Shortcut.sbr"
	-@erase "$(INTDIR)\Win32SocketFactoryService.obj"
	-@erase "$(INTDIR)\Win32SocketFactoryService.sbr"
	-@erase "$(INTDIR)\Win32SocketImpl.obj"
	-@erase "$(INTDIR)\Win32SocketImpl.sbr"
	-@erase "$(INTDIR)\Win32SocketImplFactory.obj"
	-@erase "$(INTDIR)\Win32SocketImplFactory.sbr"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketInit.obj"
	-@erase "$(INTDIR)\Win32SocketInit.sbr"
	-@erase "$(INTDIR)\WString.obj"
	-@erase "$(INTDIR)\WString.sbr"
	-@erase "$(INTDIR)\WWWURLConnection.obj"
	-@erase "$(INTDIR)\WWWURLConnection.sbr"
	-@erase "$(OUTDIR)\JDFToolsDLLd.dll"
	-@erase "$(OUTDIR)\JDFToolsDLLd.exp"
	-@erase "$(OUTDIR)\JDFToolsDLLd.lib"
	-@erase "$(OUTDIR)\JDFToolsDLLd.pdb"
	-@erase "$(OUTDIR)\JDFToolsLib.bsc"
	-@erase "$(OUTDIR)\obj\JDFToolsDLL\JDFToolsDLLd.map"
	-@erase "..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLL.idb"
	-@erase "..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLL.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GR /GX /Zi /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_USRDLL" /D "JDF_TOOLS" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\DebugDLL\JDFToolsDLL" /FD /GZ /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFToolsLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Win32FileSystem.sbr" \
	"$(INTDIR)\Win32Shortcut.sbr" \
	"$(INTDIR)\BASE64Decoder.sbr" \
	"$(INTDIR)\BASE64Encoder.sbr" \
	"$(INTDIR)\BufferedInputStream.sbr" \
	"$(INTDIR)\BufferedOutputStream.sbr" \
	"$(INTDIR)\ByteArrayInputStream.sbr" \
	"$(INTDIR)\ByteArrayOutputStream.sbr" \
	"$(INTDIR)\CharacterDecoder.sbr" \
	"$(INTDIR)\CharacterEncoder.sbr" \
	"$(INTDIR)\File.sbr" \
	"$(INTDIR)\FileInputStream.sbr" \
	"$(INTDIR)\FileOutputStream.sbr" \
	"$(INTDIR)\FileSystem.sbr" \
	"$(INTDIR)\FilterInputStream.sbr" \
	"$(INTDIR)\FilterOutputStream.sbr" \
	"$(INTDIR)\InputStream.sbr" \
	"$(INTDIR)\OutputStream.sbr" \
	"$(INTDIR)\PrintStream.sbr" \
	"$(INTDIR)\PushbackInputStream.sbr" \
	"$(INTDIR)\QPDecoder.sbr" \
	"$(INTDIR)\QPEncoder.sbr" \
	"$(INTDIR)\RandomAccessInputStream.sbr" \
	"$(INTDIR)\RandomAccessOutputStream.sbr" \
	"$(INTDIR)\StreamBuffer.sbr" \
	"$(INTDIR)\Win32InetAddressImpl.sbr" \
	"$(INTDIR)\Win32SocketFactoryService.sbr" \
	"$(INTDIR)\Win32SocketImpl.sbr" \
	"$(INTDIR)\Win32SocketImplFactory.sbr" \
	"$(INTDIR)\Win32SocketImplInputStream.sbr" \
	"$(INTDIR)\Win32SocketImplOutputStream.sbr" \
	"$(INTDIR)\Win32SocketInit.sbr" \
	"$(INTDIR)\FileURLConnection.sbr" \
	"$(INTDIR)\FileURLStreamHandler.sbr" \
	"$(INTDIR)\AuthenticationInfo.sbr" \
	"$(INTDIR)\Authenticator.sbr" \
	"$(INTDIR)\BasicAuthentication.sbr" \
	"$(INTDIR)\ChunkedInputStream.sbr" \
	"$(INTDIR)\DigestAuthentication.sbr" \
	"$(INTDIR)\HttpClient.sbr" \
	"$(INTDIR)\HttpURLConnection.sbr" \
	"$(INTDIR)\HttpURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpOutputStream.sbr" \
	"$(INTDIR)\PlainHttpURLConnection.sbr" \
	"$(INTDIR)\HttpsClient.sbr" \
	"$(INTDIR)\HttpsURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpsURLConnection.sbr" \
	"$(INTDIR)\CidURLStreamHandler.sbr" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" \
	"$(INTDIR)\HeaderParser.sbr" \
	"$(INTDIR)\InetAddress.sbr" \
	"$(INTDIR)\InetAddressCachePolicy.sbr" \
	"$(INTDIR)\InetAddressImpl.sbr" \
	"$(INTDIR)\md5.sbr" \
	"$(INTDIR)\MessageHeader.sbr" \
	"$(INTDIR)\NetworkClient.sbr" \
	"$(INTDIR)\ServerSocket.sbr" \
	"$(INTDIR)\Socket.sbr" \
	"$(INTDIR)\SocketImpl.sbr" \
	"$(INTDIR)\SocketOptions.sbr" \
	"$(INTDIR)\SSLSocket.sbr" \
	"$(INTDIR)\SSLSocketInputStream.sbr" \
	"$(INTDIR)\SSLSocketOutputStream.sbr" \
	"$(INTDIR)\URL.sbr" \
	"$(INTDIR)\URLConnection.sbr" \
	"$(INTDIR)\URLDecoder.sbr" \
	"$(INTDIR)\URLEncoder.sbr" \
	"$(INTDIR)\URLStreamHandler.sbr" \
	"$(INTDIR)\WWWURLConnection.sbr" \
	"$(INTDIR)\Win32PlatformUtils.sbr" \
	"$(INTDIR)\Win32ProcessInputStream.sbr" \
	"$(INTDIR)\Win32ProcessOutputStream.sbr" \
	"$(INTDIR)\myuti.sbr" \
	"$(INTDIR)\PlatformUtils.sbr" \
	"$(INTDIR)\Random.sbr" \
	"$(INTDIR)\Regexp.sbr" \
	"$(INTDIR)\RegexpPool.sbr" \
	"$(INTDIR)\StringTokenizer.sbr" \
	"$(INTDIR)\Unicode.sbr" \
	"$(INTDIR)\FileMIMEType.sbr" \
	"$(INTDIR)\MIMEBasicPart.sbr" \
	"$(INTDIR)\MIMEBodyPart.sbr" \
	"$(INTDIR)\MIMEHeader.sbr" \
	"$(INTDIR)\MIMEMessage.sbr" \
	"$(INTDIR)\MIMEMessagePart.sbr" \
	"$(INTDIR)\MIMEMultiPart.sbr" \
	"$(INTDIR)\MIMEParser.sbr" \
	"$(INTDIR)\MimeTableFileNameMap.sbr" \
	"$(INTDIR)\AutoPtr.sbr" \
	"$(INTDIR)\BoolJanitor.sbr" \
	"$(INTDIR)\ByteBuffer.sbr" \
	"$(INTDIR)\CharBuffer.sbr" \
	"$(INTDIR)\Integer.sbr" \
	"$(INTDIR)\Integer64.sbr" \
	"$(INTDIR)\mapWString.sbr" \
	"$(INTDIR)\Mutex.sbr" \
	"$(INTDIR)\Synchronized.sbr" \
	"$(INTDIR)\Throwable.sbr" \
	"$(INTDIR)\vdouble.sbr" \
	"$(INTDIR)\vint.sbr" \
	"$(INTDIR)\vMapWString.sbr" \
	"$(INTDIR)\vWString.sbr" \
	"$(INTDIR)\WString.sbr"

"$(OUTDIR)\JDFToolsLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=xilink6.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\JDFToolsDLLd.pdb" /map:"$(INTDIR)\JDFToolsDLLd.map" /debug /machine:I386 /nodefaultlib:"libcmtd.lib" /nodefaultlib:"libcpmtd.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libc.lib" /out:"$(OUTDIR)\JDFToolsDLLd.dll" /implib:"$(OUTDIR)\JDFToolsDLLd.lib" /pdbtype:sept /libpath:"..\..\..\external\stlport\lib" 
LINK32_OBJS= \
	"$(INTDIR)\Win32FileSystem.obj" \
	"$(INTDIR)\Win32Shortcut.obj" \
	"$(INTDIR)\BASE64Decoder.obj" \
	"$(INTDIR)\BASE64Encoder.obj" \
	"$(INTDIR)\BufferedInputStream.obj" \
	"$(INTDIR)\BufferedOutputStream.obj" \
	"$(INTDIR)\ByteArrayInputStream.obj" \
	"$(INTDIR)\ByteArrayOutputStream.obj" \
	"$(INTDIR)\CharacterDecoder.obj" \
	"$(INTDIR)\CharacterEncoder.obj" \
	"$(INTDIR)\File.obj" \
	"$(INTDIR)\FileInputStream.obj" \
	"$(INTDIR)\FileOutputStream.obj" \
	"$(INTDIR)\FileSystem.obj" \
	"$(INTDIR)\FilterInputStream.obj" \
	"$(INTDIR)\FilterOutputStream.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\PrintStream.obj" \
	"$(INTDIR)\PushbackInputStream.obj" \
	"$(INTDIR)\QPDecoder.obj" \
	"$(INTDIR)\QPEncoder.obj" \
	"$(INTDIR)\RandomAccessInputStream.obj" \
	"$(INTDIR)\RandomAccessOutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\Win32InetAddressImpl.obj" \
	"$(INTDIR)\Win32SocketFactoryService.obj" \
	"$(INTDIR)\Win32SocketImpl.obj" \
	"$(INTDIR)\Win32SocketImplFactory.obj" \
	"$(INTDIR)\Win32SocketImplInputStream.obj" \
	"$(INTDIR)\Win32SocketImplOutputStream.obj" \
	"$(INTDIR)\Win32SocketInit.obj" \
	"$(INTDIR)\FileURLConnection.obj" \
	"$(INTDIR)\FileURLStreamHandler.obj" \
	"$(INTDIR)\AuthenticationInfo.obj" \
	"$(INTDIR)\Authenticator.obj" \
	"$(INTDIR)\BasicAuthentication.obj" \
	"$(INTDIR)\ChunkedInputStream.obj" \
	"$(INTDIR)\DigestAuthentication.obj" \
	"$(INTDIR)\HttpClient.obj" \
	"$(INTDIR)\HttpURLConnection.obj" \
	"$(INTDIR)\HttpURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpOutputStream.obj" \
	"$(INTDIR)\PlainHttpURLConnection.obj" \
	"$(INTDIR)\HttpsClient.obj" \
	"$(INTDIR)\HttpsURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpsURLConnection.obj" \
	"$(INTDIR)\CidURLStreamHandler.obj" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.obj" \
	"$(INTDIR)\HeaderParser.obj" \
	"$(INTDIR)\InetAddress.obj" \
	"$(INTDIR)\InetAddressCachePolicy.obj" \
	"$(INTDIR)\InetAddressImpl.obj" \
	"$(INTDIR)\md5.obj" \
	"$(INTDIR)\MessageHeader.obj" \
	"$(INTDIR)\NetworkClient.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\Socket.obj" \
	"$(INTDIR)\SocketImpl.obj" \
	"$(INTDIR)\SocketOptions.obj" \
	"$(INTDIR)\SSLSocket.obj" \
	"$(INTDIR)\SSLSocketInputStream.obj" \
	"$(INTDIR)\SSLSocketOutputStream.obj" \
	"$(INTDIR)\URL.obj" \
	"$(INTDIR)\URLConnection.obj" \
	"$(INTDIR)\URLDecoder.obj" \
	"$(INTDIR)\URLEncoder.obj" \
	"$(INTDIR)\URLStreamHandler.obj" \
	"$(INTDIR)\WWWURLConnection.obj" \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32ProcessInputStream.obj" \
	"$(INTDIR)\Win32ProcessOutputStream.obj" \
	"$(INTDIR)\myuti.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\Regexp.obj" \
	"$(INTDIR)\RegexpPool.obj" \
	"$(INTDIR)\StringTokenizer.obj" \
	"$(INTDIR)\Unicode.obj" \
	"$(INTDIR)\FileMIMEType.obj" \
	"$(INTDIR)\MIMEBasicPart.obj" \
	"$(INTDIR)\MIMEBodyPart.obj" \
	"$(INTDIR)\MIMEHeader.obj" \
	"$(INTDIR)\MIMEMessage.obj" \
	"$(INTDIR)\MIMEMessagePart.obj" \
	"$(INTDIR)\MIMEMultiPart.obj" \
	"$(INTDIR)\MIMEParser.obj" \
	"$(INTDIR)\MimeTableFileNameMap.obj" \
	"$(INTDIR)\AutoPtr.obj" \
	"$(INTDIR)\BoolJanitor.obj" \
	"$(INTDIR)\ByteBuffer.obj" \
	"$(INTDIR)\CharBuffer.obj" \
	"$(INTDIR)\Integer.obj" \
	"$(INTDIR)\Integer64.obj" \
	"$(INTDIR)\mapWString.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\Synchronized.obj" \
	"$(INTDIR)\Throwable.obj" \
	"$(INTDIR)\vdouble.obj" \
	"$(INTDIR)\vint.obj" \
	"$(INTDIR)\vMapWString.obj" \
	"$(INTDIR)\vWString.obj" \
	"$(INTDIR)\WString.obj" \
	"..\..\..\external\libpng\projects\msvc\win32\libpng\lib_dbg\LIBPNG.LIB" \
	"..\..\..\external\xerces\lib\xerces-c_2D.lib"

"$(OUTDIR)\JDFToolsDLLd.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"

OUTDIR=.\..\..\..\Build\Win32\VC6\ReleaseDLL
INTDIR=.\..\..\..\Build\Win32\VC6\ReleaseDLL\obj\JDFToolsDLL
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\ReleaseDLL
# End Custom Macros

ALL : "$(OUTDIR)\JDFToolsDLL.dll" "$(OUTDIR)\JDFToolsLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\AuthenticationInfo.obj"
	-@erase "$(INTDIR)\AuthenticationInfo.sbr"
	-@erase "$(INTDIR)\Authenticator.obj"
	-@erase "$(INTDIR)\Authenticator.sbr"
	-@erase "$(INTDIR)\AutoPtr.obj"
	-@erase "$(INTDIR)\AutoPtr.sbr"
	-@erase "$(INTDIR)\BASE64Decoder.obj"
	-@erase "$(INTDIR)\BASE64Decoder.sbr"
	-@erase "$(INTDIR)\BASE64Encoder.obj"
	-@erase "$(INTDIR)\BASE64Encoder.sbr"
	-@erase "$(INTDIR)\BasicAuthentication.obj"
	-@erase "$(INTDIR)\BasicAuthentication.sbr"
	-@erase "$(INTDIR)\BoolJanitor.obj"
	-@erase "$(INTDIR)\BoolJanitor.sbr"
	-@erase "$(INTDIR)\BufferedInputStream.obj"
	-@erase "$(INTDIR)\BufferedInputStream.sbr"
	-@erase "$(INTDIR)\BufferedOutputStream.obj"
	-@erase "$(INTDIR)\BufferedOutputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayInputStream.obj"
	-@erase "$(INTDIR)\ByteArrayInputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayOutputStream.obj"
	-@erase "$(INTDIR)\ByteArrayOutputStream.sbr"
	-@erase "$(INTDIR)\ByteBuffer.obj"
	-@erase "$(INTDIR)\ByteBuffer.sbr"
	-@erase "$(INTDIR)\CharacterDecoder.obj"
	-@erase "$(INTDIR)\CharacterDecoder.sbr"
	-@erase "$(INTDIR)\CharacterEncoder.obj"
	-@erase "$(INTDIR)\CharacterEncoder.sbr"
	-@erase "$(INTDIR)\CharBuffer.obj"
	-@erase "$(INTDIR)\CharBuffer.sbr"
	-@erase "$(INTDIR)\ChunkedInputStream.obj"
	-@erase "$(INTDIR)\ChunkedInputStream.sbr"
	-@erase "$(INTDIR)\CidURLStreamHandler.obj"
	-@erase "$(INTDIR)\CidURLStreamHandler.sbr"
	-@erase "$(INTDIR)\DigestAuthentication.obj"
	-@erase "$(INTDIR)\DigestAuthentication.sbr"
	-@erase "$(INTDIR)\File.obj"
	-@erase "$(INTDIR)\File.sbr"
	-@erase "$(INTDIR)\FileInputStream.obj"
	-@erase "$(INTDIR)\FileInputStream.sbr"
	-@erase "$(INTDIR)\FileMIMEType.obj"
	-@erase "$(INTDIR)\FileMIMEType.sbr"
	-@erase "$(INTDIR)\FileOutputStream.obj"
	-@erase "$(INTDIR)\FileOutputStream.sbr"
	-@erase "$(INTDIR)\FileSystem.obj"
	-@erase "$(INTDIR)\FileSystem.sbr"
	-@erase "$(INTDIR)\FileURLConnection.obj"
	-@erase "$(INTDIR)\FileURLConnection.sbr"
	-@erase "$(INTDIR)\FileURLStreamHandler.obj"
	-@erase "$(INTDIR)\FileURLStreamHandler.sbr"
	-@erase "$(INTDIR)\FilterInputStream.obj"
	-@erase "$(INTDIR)\FilterInputStream.sbr"
	-@erase "$(INTDIR)\FilterOutputStream.obj"
	-@erase "$(INTDIR)\FilterOutputStream.sbr"
	-@erase "$(INTDIR)\HeaderParser.obj"
	-@erase "$(INTDIR)\HeaderParser.sbr"
	-@erase "$(INTDIR)\HttpClient.obj"
	-@erase "$(INTDIR)\HttpClient.sbr"
	-@erase "$(INTDIR)\HttpsClient.obj"
	-@erase "$(INTDIR)\HttpsClient.sbr"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.sbr"
	-@erase "$(INTDIR)\HttpURLConnection.obj"
	-@erase "$(INTDIR)\HttpURLConnection.sbr"
	-@erase "$(INTDIR)\HttpURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpURLStreamHandler.sbr"
	-@erase "$(INTDIR)\InetAddress.obj"
	-@erase "$(INTDIR)\InetAddress.sbr"
	-@erase "$(INTDIR)\InetAddressCachePolicy.obj"
	-@erase "$(INTDIR)\InetAddressCachePolicy.sbr"
	-@erase "$(INTDIR)\InetAddressImpl.obj"
	-@erase "$(INTDIR)\InetAddressImpl.sbr"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\InputStream.sbr"
	-@erase "$(INTDIR)\Integer.obj"
	-@erase "$(INTDIR)\Integer.sbr"
	-@erase "$(INTDIR)\Integer64.obj"
	-@erase "$(INTDIR)\Integer64.sbr"
	-@erase "$(INTDIR)\mapWString.obj"
	-@erase "$(INTDIR)\mapWString.sbr"
	-@erase "$(INTDIR)\md5.obj"
	-@erase "$(INTDIR)\md5.sbr"
	-@erase "$(INTDIR)\MessageHeader.obj"
	-@erase "$(INTDIR)\MessageHeader.sbr"
	-@erase "$(INTDIR)\MIMEBasicPart.obj"
	-@erase "$(INTDIR)\MIMEBasicPart.sbr"
	-@erase "$(INTDIR)\MIMEBodyPart.obj"
	-@erase "$(INTDIR)\MIMEBodyPart.sbr"
	-@erase "$(INTDIR)\MIMEHeader.obj"
	-@erase "$(INTDIR)\MIMEHeader.sbr"
	-@erase "$(INTDIR)\MIMEMessage.obj"
	-@erase "$(INTDIR)\MIMEMessage.sbr"
	-@erase "$(INTDIR)\MIMEMessagePart.obj"
	-@erase "$(INTDIR)\MIMEMessagePart.sbr"
	-@erase "$(INTDIR)\MIMEMultiPart.obj"
	-@erase "$(INTDIR)\MIMEMultiPart.sbr"
	-@erase "$(INTDIR)\MIMEParser.obj"
	-@erase "$(INTDIR)\MIMEParser.sbr"
	-@erase "$(INTDIR)\MimeTableFileNameMap.obj"
	-@erase "$(INTDIR)\MimeTableFileNameMap.sbr"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\Mutex.sbr"
	-@erase "$(INTDIR)\myuti.obj"
	-@erase "$(INTDIR)\myuti.sbr"
	-@erase "$(INTDIR)\NetworkClient.obj"
	-@erase "$(INTDIR)\NetworkClient.sbr"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\OutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpOutputStream.obj"
	-@erase "$(INTDIR)\PlainHttpOutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.sbr"
	-@erase "$(INTDIR)\PlainHttpURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpURLConnection.sbr"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.obj"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.sbr"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\PlatformUtils.sbr"
	-@erase "$(INTDIR)\PrintStream.obj"
	-@erase "$(INTDIR)\PrintStream.sbr"
	-@erase "$(INTDIR)\PushbackInputStream.obj"
	-@erase "$(INTDIR)\PushbackInputStream.sbr"
	-@erase "$(INTDIR)\QPDecoder.obj"
	-@erase "$(INTDIR)\QPDecoder.sbr"
	-@erase "$(INTDIR)\QPEncoder.obj"
	-@erase "$(INTDIR)\QPEncoder.sbr"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\Random.sbr"
	-@erase "$(INTDIR)\RandomAccessInputStream.obj"
	-@erase "$(INTDIR)\RandomAccessInputStream.sbr"
	-@erase "$(INTDIR)\RandomAccessOutputStream.obj"
	-@erase "$(INTDIR)\RandomAccessOutputStream.sbr"
	-@erase "$(INTDIR)\Regexp.obj"
	-@erase "$(INTDIR)\Regexp.sbr"
	-@erase "$(INTDIR)\RegexpPool.obj"
	-@erase "$(INTDIR)\RegexpPool.sbr"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\ServerSocket.sbr"
	-@erase "$(INTDIR)\Socket.obj"
	-@erase "$(INTDIR)\Socket.sbr"
	-@erase "$(INTDIR)\SocketImpl.obj"
	-@erase "$(INTDIR)\SocketImpl.sbr"
	-@erase "$(INTDIR)\SocketOptions.obj"
	-@erase "$(INTDIR)\SocketOptions.sbr"
	-@erase "$(INTDIR)\SSLSocket.obj"
	-@erase "$(INTDIR)\SSLSocket.sbr"
	-@erase "$(INTDIR)\SSLSocketInputStream.obj"
	-@erase "$(INTDIR)\SSLSocketInputStream.sbr"
	-@erase "$(INTDIR)\SSLSocketOutputStream.obj"
	-@erase "$(INTDIR)\SSLSocketOutputStream.sbr"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StreamBuffer.sbr"
	-@erase "$(INTDIR)\StringTokenizer.obj"
	-@erase "$(INTDIR)\StringTokenizer.sbr"
	-@erase "$(INTDIR)\Synchronized.obj"
	-@erase "$(INTDIR)\Synchronized.sbr"
	-@erase "$(INTDIR)\Throwable.obj"
	-@erase "$(INTDIR)\Throwable.sbr"
	-@erase "$(INTDIR)\Unicode.obj"
	-@erase "$(INTDIR)\Unicode.sbr"
	-@erase "$(INTDIR)\URL.obj"
	-@erase "$(INTDIR)\URL.sbr"
	-@erase "$(INTDIR)\URLConnection.obj"
	-@erase "$(INTDIR)\URLConnection.sbr"
	-@erase "$(INTDIR)\URLDecoder.obj"
	-@erase "$(INTDIR)\URLDecoder.sbr"
	-@erase "$(INTDIR)\URLEncoder.obj"
	-@erase "$(INTDIR)\URLEncoder.sbr"
	-@erase "$(INTDIR)\URLStreamHandler.obj"
	-@erase "$(INTDIR)\URLStreamHandler.sbr"
	-@erase "$(INTDIR)\vdouble.obj"
	-@erase "$(INTDIR)\vdouble.sbr"
	-@erase "$(INTDIR)\vint.obj"
	-@erase "$(INTDIR)\vint.sbr"
	-@erase "$(INTDIR)\vMapWString.obj"
	-@erase "$(INTDIR)\vMapWString.sbr"
	-@erase "$(INTDIR)\vWString.obj"
	-@erase "$(INTDIR)\vWString.sbr"
	-@erase "$(INTDIR)\Win32FileSystem.obj"
	-@erase "$(INTDIR)\Win32FileSystem.sbr"
	-@erase "$(INTDIR)\Win32InetAddressImpl.obj"
	-@erase "$(INTDIR)\Win32InetAddressImpl.sbr"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.sbr"
	-@erase "$(INTDIR)\Win32ProcessInputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessInputStream.sbr"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.sbr"
	-@erase "$(INTDIR)\Win32Shortcut.obj"
	-@erase "$(INTDIR)\Win32Shortcut.sbr"
	-@erase "$(INTDIR)\Win32SocketFactoryService.obj"
	-@erase "$(INTDIR)\Win32SocketFactoryService.sbr"
	-@erase "$(INTDIR)\Win32SocketImpl.obj"
	-@erase "$(INTDIR)\Win32SocketImpl.sbr"
	-@erase "$(INTDIR)\Win32SocketImplFactory.obj"
	-@erase "$(INTDIR)\Win32SocketImplFactory.sbr"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketInit.obj"
	-@erase "$(INTDIR)\Win32SocketInit.sbr"
	-@erase "$(INTDIR)\WString.obj"
	-@erase "$(INTDIR)\WString.sbr"
	-@erase "$(INTDIR)\WWWURLConnection.obj"
	-@erase "$(INTDIR)\WWWURLConnection.sbr"
	-@erase "$(OUTDIR)\JDFToolsDLL.dll"
	-@erase "$(OUTDIR)\JDFToolsDLL.exp"
	-@erase "$(OUTDIR)\JDFToolsDLL.lib"
	-@erase "$(OUTDIR)\JDFToolsLib.bsc"
	-@erase "$(OUTDIR)\obj\JDFToolsDLL\JDFToolsDLL.map"
	-@erase "..\..\..\Build\Win32\VC6\ReleaseDLL\JDFToolsDLL.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=xicl6.exe
CPP_PROJ=/nologo /MD /w /W0 /GR /GX /O2 /I "..\..\..\external\stlport\stlport" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_USRDLL" /D "TYPESAFE" /D "_REENTRANT" /D "UNICODE" /D "_UNICODE" /D "JDF_TOOLS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\JDFToolsLib.pch" /YX /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\ReleaseDLL\JDFToolsDLL" /FD /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFToolsLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Win32FileSystem.sbr" \
	"$(INTDIR)\Win32Shortcut.sbr" \
	"$(INTDIR)\BASE64Decoder.sbr" \
	"$(INTDIR)\BASE64Encoder.sbr" \
	"$(INTDIR)\BufferedInputStream.sbr" \
	"$(INTDIR)\BufferedOutputStream.sbr" \
	"$(INTDIR)\ByteArrayInputStream.sbr" \
	"$(INTDIR)\ByteArrayOutputStream.sbr" \
	"$(INTDIR)\CharacterDecoder.sbr" \
	"$(INTDIR)\CharacterEncoder.sbr" \
	"$(INTDIR)\File.sbr" \
	"$(INTDIR)\FileInputStream.sbr" \
	"$(INTDIR)\FileOutputStream.sbr" \
	"$(INTDIR)\FileSystem.sbr" \
	"$(INTDIR)\FilterInputStream.sbr" \
	"$(INTDIR)\FilterOutputStream.sbr" \
	"$(INTDIR)\InputStream.sbr" \
	"$(INTDIR)\OutputStream.sbr" \
	"$(INTDIR)\PrintStream.sbr" \
	"$(INTDIR)\PushbackInputStream.sbr" \
	"$(INTDIR)\QPDecoder.sbr" \
	"$(INTDIR)\QPEncoder.sbr" \
	"$(INTDIR)\RandomAccessInputStream.sbr" \
	"$(INTDIR)\RandomAccessOutputStream.sbr" \
	"$(INTDIR)\StreamBuffer.sbr" \
	"$(INTDIR)\Win32InetAddressImpl.sbr" \
	"$(INTDIR)\Win32SocketFactoryService.sbr" \
	"$(INTDIR)\Win32SocketImpl.sbr" \
	"$(INTDIR)\Win32SocketImplFactory.sbr" \
	"$(INTDIR)\Win32SocketImplInputStream.sbr" \
	"$(INTDIR)\Win32SocketImplOutputStream.sbr" \
	"$(INTDIR)\Win32SocketInit.sbr" \
	"$(INTDIR)\FileURLConnection.sbr" \
	"$(INTDIR)\FileURLStreamHandler.sbr" \
	"$(INTDIR)\AuthenticationInfo.sbr" \
	"$(INTDIR)\Authenticator.sbr" \
	"$(INTDIR)\BasicAuthentication.sbr" \
	"$(INTDIR)\ChunkedInputStream.sbr" \
	"$(INTDIR)\DigestAuthentication.sbr" \
	"$(INTDIR)\HttpClient.sbr" \
	"$(INTDIR)\HttpURLConnection.sbr" \
	"$(INTDIR)\HttpURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpOutputStream.sbr" \
	"$(INTDIR)\PlainHttpURLConnection.sbr" \
	"$(INTDIR)\HttpsClient.sbr" \
	"$(INTDIR)\HttpsURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpsURLConnection.sbr" \
	"$(INTDIR)\CidURLStreamHandler.sbr" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" \
	"$(INTDIR)\HeaderParser.sbr" \
	"$(INTDIR)\InetAddress.sbr" \
	"$(INTDIR)\InetAddressCachePolicy.sbr" \
	"$(INTDIR)\InetAddressImpl.sbr" \
	"$(INTDIR)\md5.sbr" \
	"$(INTDIR)\MessageHeader.sbr" \
	"$(INTDIR)\NetworkClient.sbr" \
	"$(INTDIR)\ServerSocket.sbr" \
	"$(INTDIR)\Socket.sbr" \
	"$(INTDIR)\SocketImpl.sbr" \
	"$(INTDIR)\SocketOptions.sbr" \
	"$(INTDIR)\SSLSocket.sbr" \
	"$(INTDIR)\SSLSocketInputStream.sbr" \
	"$(INTDIR)\SSLSocketOutputStream.sbr" \
	"$(INTDIR)\URL.sbr" \
	"$(INTDIR)\URLConnection.sbr" \
	"$(INTDIR)\URLDecoder.sbr" \
	"$(INTDIR)\URLEncoder.sbr" \
	"$(INTDIR)\URLStreamHandler.sbr" \
	"$(INTDIR)\WWWURLConnection.sbr" \
	"$(INTDIR)\Win32PlatformUtils.sbr" \
	"$(INTDIR)\Win32ProcessInputStream.sbr" \
	"$(INTDIR)\Win32ProcessOutputStream.sbr" \
	"$(INTDIR)\myuti.sbr" \
	"$(INTDIR)\PlatformUtils.sbr" \
	"$(INTDIR)\Random.sbr" \
	"$(INTDIR)\Regexp.sbr" \
	"$(INTDIR)\RegexpPool.sbr" \
	"$(INTDIR)\StringTokenizer.sbr" \
	"$(INTDIR)\Unicode.sbr" \
	"$(INTDIR)\FileMIMEType.sbr" \
	"$(INTDIR)\MIMEBasicPart.sbr" \
	"$(INTDIR)\MIMEBodyPart.sbr" \
	"$(INTDIR)\MIMEHeader.sbr" \
	"$(INTDIR)\MIMEMessage.sbr" \
	"$(INTDIR)\MIMEMessagePart.sbr" \
	"$(INTDIR)\MIMEMultiPart.sbr" \
	"$(INTDIR)\MIMEParser.sbr" \
	"$(INTDIR)\MimeTableFileNameMap.sbr" \
	"$(INTDIR)\AutoPtr.sbr" \
	"$(INTDIR)\BoolJanitor.sbr" \
	"$(INTDIR)\ByteBuffer.sbr" \
	"$(INTDIR)\CharBuffer.sbr" \
	"$(INTDIR)\Integer.sbr" \
	"$(INTDIR)\Integer64.sbr" \
	"$(INTDIR)\mapWString.sbr" \
	"$(INTDIR)\Mutex.sbr" \
	"$(INTDIR)\Synchronized.sbr" \
	"$(INTDIR)\Throwable.sbr" \
	"$(INTDIR)\vdouble.sbr" \
	"$(INTDIR)\vint.sbr" \
	"$(INTDIR)\vMapWString.sbr" \
	"$(INTDIR)\vWString.sbr" \
	"$(INTDIR)\WString.sbr"

"$(OUTDIR)\JDFToolsLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=xilink6.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\JDFToolsDLL.pdb" /map:"$(INTDIR)\JDFToolsDLL.map" /machine:I386 /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcpmt.lib" /nodefaultlib:"libc.lib" /out:"$(OUTDIR)\JDFToolsDLL.dll" /implib:"$(OUTDIR)\JDFToolsDLL.lib" /libpath:"..\..\..\external\stlport\lib" 
LINK32_OBJS= \
	"$(INTDIR)\Win32FileSystem.obj" \
	"$(INTDIR)\Win32Shortcut.obj" \
	"$(INTDIR)\BASE64Decoder.obj" \
	"$(INTDIR)\BASE64Encoder.obj" \
	"$(INTDIR)\BufferedInputStream.obj" \
	"$(INTDIR)\BufferedOutputStream.obj" \
	"$(INTDIR)\ByteArrayInputStream.obj" \
	"$(INTDIR)\ByteArrayOutputStream.obj" \
	"$(INTDIR)\CharacterDecoder.obj" \
	"$(INTDIR)\CharacterEncoder.obj" \
	"$(INTDIR)\File.obj" \
	"$(INTDIR)\FileInputStream.obj" \
	"$(INTDIR)\FileOutputStream.obj" \
	"$(INTDIR)\FileSystem.obj" \
	"$(INTDIR)\FilterInputStream.obj" \
	"$(INTDIR)\FilterOutputStream.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\PrintStream.obj" \
	"$(INTDIR)\PushbackInputStream.obj" \
	"$(INTDIR)\QPDecoder.obj" \
	"$(INTDIR)\QPEncoder.obj" \
	"$(INTDIR)\RandomAccessInputStream.obj" \
	"$(INTDIR)\RandomAccessOutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\Win32InetAddressImpl.obj" \
	"$(INTDIR)\Win32SocketFactoryService.obj" \
	"$(INTDIR)\Win32SocketImpl.obj" \
	"$(INTDIR)\Win32SocketImplFactory.obj" \
	"$(INTDIR)\Win32SocketImplInputStream.obj" \
	"$(INTDIR)\Win32SocketImplOutputStream.obj" \
	"$(INTDIR)\Win32SocketInit.obj" \
	"$(INTDIR)\FileURLConnection.obj" \
	"$(INTDIR)\FileURLStreamHandler.obj" \
	"$(INTDIR)\AuthenticationInfo.obj" \
	"$(INTDIR)\Authenticator.obj" \
	"$(INTDIR)\BasicAuthentication.obj" \
	"$(INTDIR)\ChunkedInputStream.obj" \
	"$(INTDIR)\DigestAuthentication.obj" \
	"$(INTDIR)\HttpClient.obj" \
	"$(INTDIR)\HttpURLConnection.obj" \
	"$(INTDIR)\HttpURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpOutputStream.obj" \
	"$(INTDIR)\PlainHttpURLConnection.obj" \
	"$(INTDIR)\HttpsClient.obj" \
	"$(INTDIR)\HttpsURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpsURLConnection.obj" \
	"$(INTDIR)\CidURLStreamHandler.obj" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.obj" \
	"$(INTDIR)\HeaderParser.obj" \
	"$(INTDIR)\InetAddress.obj" \
	"$(INTDIR)\InetAddressCachePolicy.obj" \
	"$(INTDIR)\InetAddressImpl.obj" \
	"$(INTDIR)\md5.obj" \
	"$(INTDIR)\MessageHeader.obj" \
	"$(INTDIR)\NetworkClient.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\Socket.obj" \
	"$(INTDIR)\SocketImpl.obj" \
	"$(INTDIR)\SocketOptions.obj" \
	"$(INTDIR)\SSLSocket.obj" \
	"$(INTDIR)\SSLSocketInputStream.obj" \
	"$(INTDIR)\SSLSocketOutputStream.obj" \
	"$(INTDIR)\URL.obj" \
	"$(INTDIR)\URLConnection.obj" \
	"$(INTDIR)\URLDecoder.obj" \
	"$(INTDIR)\URLEncoder.obj" \
	"$(INTDIR)\URLStreamHandler.obj" \
	"$(INTDIR)\WWWURLConnection.obj" \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32ProcessInputStream.obj" \
	"$(INTDIR)\Win32ProcessOutputStream.obj" \
	"$(INTDIR)\myuti.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\Regexp.obj" \
	"$(INTDIR)\RegexpPool.obj" \
	"$(INTDIR)\StringTokenizer.obj" \
	"$(INTDIR)\Unicode.obj" \
	"$(INTDIR)\FileMIMEType.obj" \
	"$(INTDIR)\MIMEBasicPart.obj" \
	"$(INTDIR)\MIMEBodyPart.obj" \
	"$(INTDIR)\MIMEHeader.obj" \
	"$(INTDIR)\MIMEMessage.obj" \
	"$(INTDIR)\MIMEMessagePart.obj" \
	"$(INTDIR)\MIMEMultiPart.obj" \
	"$(INTDIR)\MIMEParser.obj" \
	"$(INTDIR)\MimeTableFileNameMap.obj" \
	"$(INTDIR)\AutoPtr.obj" \
	"$(INTDIR)\BoolJanitor.obj" \
	"$(INTDIR)\ByteBuffer.obj" \
	"$(INTDIR)\CharBuffer.obj" \
	"$(INTDIR)\Integer.obj" \
	"$(INTDIR)\Integer64.obj" \
	"$(INTDIR)\mapWString.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\Synchronized.obj" \
	"$(INTDIR)\Throwable.obj" \
	"$(INTDIR)\vdouble.obj" \
	"$(INTDIR)\vint.obj" \
	"$(INTDIR)\vMapWString.obj" \
	"$(INTDIR)\vWString.obj" \
	"$(INTDIR)\WString.obj" \
	"..\..\..\external\libpng\projects\msvc\win32\libpng\lib\LIBPNG.LIB" \
	"..\..\..\external\xerces\lib\xerces-c_2.lib"

"$(OUTDIR)\JDFToolsDLL.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"

OUTDIR=.\..\..\..\Build\Win32\VC6\DebugLineOnly
INTDIR=.\..\..\..\Build\Win32\VC6\DebugLineOnly\obj\JDFToolsLib
# Begin Custom Macros
OutDir=.\..\..\..\Build\Win32\VC6\DebugLineOnly
# End Custom Macros

ALL : "$(OUTDIR)\jdftoolslib_D.lib" "$(OUTDIR)\JDFToolsLib.bsc"


CLEAN :
	-@erase "$(INTDIR)\AuthenticationInfo.obj"
	-@erase "$(INTDIR)\AuthenticationInfo.sbr"
	-@erase "$(INTDIR)\Authenticator.obj"
	-@erase "$(INTDIR)\Authenticator.sbr"
	-@erase "$(INTDIR)\AutoPtr.obj"
	-@erase "$(INTDIR)\AutoPtr.sbr"
	-@erase "$(INTDIR)\BASE64Decoder.obj"
	-@erase "$(INTDIR)\BASE64Decoder.sbr"
	-@erase "$(INTDIR)\BASE64Encoder.obj"
	-@erase "$(INTDIR)\BASE64Encoder.sbr"
	-@erase "$(INTDIR)\BasicAuthentication.obj"
	-@erase "$(INTDIR)\BasicAuthentication.sbr"
	-@erase "$(INTDIR)\BoolJanitor.obj"
	-@erase "$(INTDIR)\BoolJanitor.sbr"
	-@erase "$(INTDIR)\BufferedInputStream.obj"
	-@erase "$(INTDIR)\BufferedInputStream.sbr"
	-@erase "$(INTDIR)\BufferedOutputStream.obj"
	-@erase "$(INTDIR)\BufferedOutputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayInputStream.obj"
	-@erase "$(INTDIR)\ByteArrayInputStream.sbr"
	-@erase "$(INTDIR)\ByteArrayOutputStream.obj"
	-@erase "$(INTDIR)\ByteArrayOutputStream.sbr"
	-@erase "$(INTDIR)\ByteBuffer.obj"
	-@erase "$(INTDIR)\ByteBuffer.sbr"
	-@erase "$(INTDIR)\CharacterDecoder.obj"
	-@erase "$(INTDIR)\CharacterDecoder.sbr"
	-@erase "$(INTDIR)\CharacterEncoder.obj"
	-@erase "$(INTDIR)\CharacterEncoder.sbr"
	-@erase "$(INTDIR)\CharBuffer.obj"
	-@erase "$(INTDIR)\CharBuffer.sbr"
	-@erase "$(INTDIR)\ChunkedInputStream.obj"
	-@erase "$(INTDIR)\ChunkedInputStream.sbr"
	-@erase "$(INTDIR)\CidURLStreamHandler.obj"
	-@erase "$(INTDIR)\CidURLStreamHandler.sbr"
	-@erase "$(INTDIR)\DigestAuthentication.obj"
	-@erase "$(INTDIR)\DigestAuthentication.sbr"
	-@erase "$(INTDIR)\File.obj"
	-@erase "$(INTDIR)\File.sbr"
	-@erase "$(INTDIR)\FileInputStream.obj"
	-@erase "$(INTDIR)\FileInputStream.sbr"
	-@erase "$(INTDIR)\FileMIMEType.obj"
	-@erase "$(INTDIR)\FileMIMEType.sbr"
	-@erase "$(INTDIR)\FileOutputStream.obj"
	-@erase "$(INTDIR)\FileOutputStream.sbr"
	-@erase "$(INTDIR)\FileSystem.obj"
	-@erase "$(INTDIR)\FileSystem.sbr"
	-@erase "$(INTDIR)\FileURLConnection.obj"
	-@erase "$(INTDIR)\FileURLConnection.sbr"
	-@erase "$(INTDIR)\FileURLStreamHandler.obj"
	-@erase "$(INTDIR)\FileURLStreamHandler.sbr"
	-@erase "$(INTDIR)\FilterInputStream.obj"
	-@erase "$(INTDIR)\FilterInputStream.sbr"
	-@erase "$(INTDIR)\FilterOutputStream.obj"
	-@erase "$(INTDIR)\FilterOutputStream.sbr"
	-@erase "$(INTDIR)\HeaderParser.obj"
	-@erase "$(INTDIR)\HeaderParser.sbr"
	-@erase "$(INTDIR)\HttpClient.obj"
	-@erase "$(INTDIR)\HttpClient.sbr"
	-@erase "$(INTDIR)\HttpsClient.obj"
	-@erase "$(INTDIR)\HttpsClient.sbr"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpsURLStreamHandler.sbr"
	-@erase "$(INTDIR)\HttpURLConnection.obj"
	-@erase "$(INTDIR)\HttpURLConnection.sbr"
	-@erase "$(INTDIR)\HttpURLStreamHandler.obj"
	-@erase "$(INTDIR)\HttpURLStreamHandler.sbr"
	-@erase "$(INTDIR)\InetAddress.obj"
	-@erase "$(INTDIR)\InetAddress.sbr"
	-@erase "$(INTDIR)\InetAddressCachePolicy.obj"
	-@erase "$(INTDIR)\InetAddressCachePolicy.sbr"
	-@erase "$(INTDIR)\InetAddressImpl.obj"
	-@erase "$(INTDIR)\InetAddressImpl.sbr"
	-@erase "$(INTDIR)\InputStream.obj"
	-@erase "$(INTDIR)\InputStream.sbr"
	-@erase "$(INTDIR)\Integer.obj"
	-@erase "$(INTDIR)\Integer.sbr"
	-@erase "$(INTDIR)\Integer64.obj"
	-@erase "$(INTDIR)\Integer64.sbr"
	-@erase "$(INTDIR)\mapWString.obj"
	-@erase "$(INTDIR)\mapWString.sbr"
	-@erase "$(INTDIR)\md5.obj"
	-@erase "$(INTDIR)\md5.sbr"
	-@erase "$(INTDIR)\MessageHeader.obj"
	-@erase "$(INTDIR)\MessageHeader.sbr"
	-@erase "$(INTDIR)\MIMEBasicPart.obj"
	-@erase "$(INTDIR)\MIMEBasicPart.sbr"
	-@erase "$(INTDIR)\MIMEBodyPart.obj"
	-@erase "$(INTDIR)\MIMEBodyPart.sbr"
	-@erase "$(INTDIR)\MIMEHeader.obj"
	-@erase "$(INTDIR)\MIMEHeader.sbr"
	-@erase "$(INTDIR)\MIMEMessage.obj"
	-@erase "$(INTDIR)\MIMEMessage.sbr"
	-@erase "$(INTDIR)\MIMEMessagePart.obj"
	-@erase "$(INTDIR)\MIMEMessagePart.sbr"
	-@erase "$(INTDIR)\MIMEMultiPart.obj"
	-@erase "$(INTDIR)\MIMEMultiPart.sbr"
	-@erase "$(INTDIR)\MIMEParser.obj"
	-@erase "$(INTDIR)\MIMEParser.sbr"
	-@erase "$(INTDIR)\MimeTableFileNameMap.obj"
	-@erase "$(INTDIR)\MimeTableFileNameMap.sbr"
	-@erase "$(INTDIR)\Mutex.obj"
	-@erase "$(INTDIR)\Mutex.sbr"
	-@erase "$(INTDIR)\myuti.obj"
	-@erase "$(INTDIR)\myuti.sbr"
	-@erase "$(INTDIR)\NetworkClient.obj"
	-@erase "$(INTDIR)\NetworkClient.sbr"
	-@erase "$(INTDIR)\OutputStream.obj"
	-@erase "$(INTDIR)\OutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpOutputStream.obj"
	-@erase "$(INTDIR)\PlainHttpOutputStream.sbr"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpsURLConnection.sbr"
	-@erase "$(INTDIR)\PlainHttpURLConnection.obj"
	-@erase "$(INTDIR)\PlainHttpURLConnection.sbr"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.obj"
	-@erase "$(INTDIR)\PlainURLStreamHandlerFactory.sbr"
	-@erase "$(INTDIR)\PlatformUtils.obj"
	-@erase "$(INTDIR)\PlatformUtils.sbr"
	-@erase "$(INTDIR)\PrintStream.obj"
	-@erase "$(INTDIR)\PrintStream.sbr"
	-@erase "$(INTDIR)\PushbackInputStream.obj"
	-@erase "$(INTDIR)\PushbackInputStream.sbr"
	-@erase "$(INTDIR)\QPDecoder.obj"
	-@erase "$(INTDIR)\QPDecoder.sbr"
	-@erase "$(INTDIR)\QPEncoder.obj"
	-@erase "$(INTDIR)\QPEncoder.sbr"
	-@erase "$(INTDIR)\Random.obj"
	-@erase "$(INTDIR)\Random.sbr"
	-@erase "$(INTDIR)\RandomAccessInputStream.obj"
	-@erase "$(INTDIR)\RandomAccessInputStream.sbr"
	-@erase "$(INTDIR)\RandomAccessOutputStream.obj"
	-@erase "$(INTDIR)\RandomAccessOutputStream.sbr"
	-@erase "$(INTDIR)\Regexp.obj"
	-@erase "$(INTDIR)\Regexp.sbr"
	-@erase "$(INTDIR)\RegexpPool.obj"
	-@erase "$(INTDIR)\RegexpPool.sbr"
	-@erase "$(INTDIR)\ServerSocket.obj"
	-@erase "$(INTDIR)\ServerSocket.sbr"
	-@erase "$(INTDIR)\Socket.obj"
	-@erase "$(INTDIR)\Socket.sbr"
	-@erase "$(INTDIR)\SocketImpl.obj"
	-@erase "$(INTDIR)\SocketImpl.sbr"
	-@erase "$(INTDIR)\SocketOptions.obj"
	-@erase "$(INTDIR)\SocketOptions.sbr"
	-@erase "$(INTDIR)\SSLSocket.obj"
	-@erase "$(INTDIR)\SSLSocket.sbr"
	-@erase "$(INTDIR)\SSLSocketInputStream.obj"
	-@erase "$(INTDIR)\SSLSocketInputStream.sbr"
	-@erase "$(INTDIR)\SSLSocketOutputStream.obj"
	-@erase "$(INTDIR)\SSLSocketOutputStream.sbr"
	-@erase "$(INTDIR)\StreamBuffer.obj"
	-@erase "$(INTDIR)\StreamBuffer.sbr"
	-@erase "$(INTDIR)\StringTokenizer.obj"
	-@erase "$(INTDIR)\StringTokenizer.sbr"
	-@erase "$(INTDIR)\Synchronized.obj"
	-@erase "$(INTDIR)\Synchronized.sbr"
	-@erase "$(INTDIR)\Throwable.obj"
	-@erase "$(INTDIR)\Throwable.sbr"
	-@erase "$(INTDIR)\Unicode.obj"
	-@erase "$(INTDIR)\Unicode.sbr"
	-@erase "$(INTDIR)\URL.obj"
	-@erase "$(INTDIR)\URL.sbr"
	-@erase "$(INTDIR)\URLConnection.obj"
	-@erase "$(INTDIR)\URLConnection.sbr"
	-@erase "$(INTDIR)\URLDecoder.obj"
	-@erase "$(INTDIR)\URLDecoder.sbr"
	-@erase "$(INTDIR)\URLEncoder.obj"
	-@erase "$(INTDIR)\URLEncoder.sbr"
	-@erase "$(INTDIR)\URLStreamHandler.obj"
	-@erase "$(INTDIR)\URLStreamHandler.sbr"
	-@erase "$(INTDIR)\vdouble.obj"
	-@erase "$(INTDIR)\vdouble.sbr"
	-@erase "$(INTDIR)\vint.obj"
	-@erase "$(INTDIR)\vint.sbr"
	-@erase "$(INTDIR)\vMapWString.obj"
	-@erase "$(INTDIR)\vMapWString.sbr"
	-@erase "$(INTDIR)\vWString.obj"
	-@erase "$(INTDIR)\vWString.sbr"
	-@erase "$(INTDIR)\Win32FileSystem.obj"
	-@erase "$(INTDIR)\Win32FileSystem.sbr"
	-@erase "$(INTDIR)\Win32InetAddressImpl.obj"
	-@erase "$(INTDIR)\Win32InetAddressImpl.sbr"
	-@erase "$(INTDIR)\Win32PlatformUtils.obj"
	-@erase "$(INTDIR)\Win32PlatformUtils.sbr"
	-@erase "$(INTDIR)\Win32ProcessInputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessInputStream.sbr"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.obj"
	-@erase "$(INTDIR)\Win32ProcessOutputStream.sbr"
	-@erase "$(INTDIR)\Win32Shortcut.obj"
	-@erase "$(INTDIR)\Win32Shortcut.sbr"
	-@erase "$(INTDIR)\Win32SocketFactoryService.obj"
	-@erase "$(INTDIR)\Win32SocketFactoryService.sbr"
	-@erase "$(INTDIR)\Win32SocketImpl.obj"
	-@erase "$(INTDIR)\Win32SocketImpl.sbr"
	-@erase "$(INTDIR)\Win32SocketImplFactory.obj"
	-@erase "$(INTDIR)\Win32SocketImplFactory.sbr"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplInputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.obj"
	-@erase "$(INTDIR)\Win32SocketImplOutputStream.sbr"
	-@erase "$(INTDIR)\Win32SocketInit.obj"
	-@erase "$(INTDIR)\Win32SocketInit.sbr"
	-@erase "$(INTDIR)\WString.obj"
	-@erase "$(INTDIR)\WString.sbr"
	-@erase "$(INTDIR)\WWWURLConnection.obj"
	-@erase "$(INTDIR)\WWWURLConnection.sbr"
	-@erase "$(OUTDIR)\JDFToolsLib.bsc"
	-@erase "$(OUTDIR)\jdftoolslib_D.lib"
	-@erase "..\..\..\Build\Win32\VC6\DebugLineOnly\JDFToolsLib.idb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

MTL=midl.exe
LINK32=link.exe
CPP=xicl6.exe
CPP_PROJ=/nologo /MDd /w /W0 /GR /GX /Zd /Od /I "..\..\..\external\stlport\stlport" /I "..\..\..\external\xerces\src" /I "..\..\..\external\xerces\src\xercesc" /I "..\..\..\external\zlib" /I "..\..\..\external" /I "..\..\..\src" /I "..\..\..\external\xerces\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "JDF_TOOLS_LIB" /D "UNICODE" /D "_UNICODE" /FR"$(INTDIR)\\" /Fo"$(INTDIR)\\" /Fd"..\..\..\Build\Win32\VC6\DebugLineOnly\JDFToolsLib" /FD /GZ /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\JDFToolsLib.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Win32FileSystem.sbr" \
	"$(INTDIR)\Win32Shortcut.sbr" \
	"$(INTDIR)\BASE64Decoder.sbr" \
	"$(INTDIR)\BASE64Encoder.sbr" \
	"$(INTDIR)\BufferedInputStream.sbr" \
	"$(INTDIR)\BufferedOutputStream.sbr" \
	"$(INTDIR)\ByteArrayInputStream.sbr" \
	"$(INTDIR)\ByteArrayOutputStream.sbr" \
	"$(INTDIR)\CharacterDecoder.sbr" \
	"$(INTDIR)\CharacterEncoder.sbr" \
	"$(INTDIR)\File.sbr" \
	"$(INTDIR)\FileInputStream.sbr" \
	"$(INTDIR)\FileOutputStream.sbr" \
	"$(INTDIR)\FileSystem.sbr" \
	"$(INTDIR)\FilterInputStream.sbr" \
	"$(INTDIR)\FilterOutputStream.sbr" \
	"$(INTDIR)\InputStream.sbr" \
	"$(INTDIR)\OutputStream.sbr" \
	"$(INTDIR)\PrintStream.sbr" \
	"$(INTDIR)\PushbackInputStream.sbr" \
	"$(INTDIR)\QPDecoder.sbr" \
	"$(INTDIR)\QPEncoder.sbr" \
	"$(INTDIR)\RandomAccessInputStream.sbr" \
	"$(INTDIR)\RandomAccessOutputStream.sbr" \
	"$(INTDIR)\StreamBuffer.sbr" \
	"$(INTDIR)\Win32InetAddressImpl.sbr" \
	"$(INTDIR)\Win32SocketFactoryService.sbr" \
	"$(INTDIR)\Win32SocketImpl.sbr" \
	"$(INTDIR)\Win32SocketImplFactory.sbr" \
	"$(INTDIR)\Win32SocketImplInputStream.sbr" \
	"$(INTDIR)\Win32SocketImplOutputStream.sbr" \
	"$(INTDIR)\Win32SocketInit.sbr" \
	"$(INTDIR)\FileURLConnection.sbr" \
	"$(INTDIR)\FileURLStreamHandler.sbr" \
	"$(INTDIR)\AuthenticationInfo.sbr" \
	"$(INTDIR)\Authenticator.sbr" \
	"$(INTDIR)\BasicAuthentication.sbr" \
	"$(INTDIR)\ChunkedInputStream.sbr" \
	"$(INTDIR)\DigestAuthentication.sbr" \
	"$(INTDIR)\HttpClient.sbr" \
	"$(INTDIR)\HttpURLConnection.sbr" \
	"$(INTDIR)\HttpURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpOutputStream.sbr" \
	"$(INTDIR)\PlainHttpURLConnection.sbr" \
	"$(INTDIR)\HttpsClient.sbr" \
	"$(INTDIR)\HttpsURLStreamHandler.sbr" \
	"$(INTDIR)\PlainHttpsURLConnection.sbr" \
	"$(INTDIR)\CidURLStreamHandler.sbr" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" \
	"$(INTDIR)\HeaderParser.sbr" \
	"$(INTDIR)\InetAddress.sbr" \
	"$(INTDIR)\InetAddressCachePolicy.sbr" \
	"$(INTDIR)\InetAddressImpl.sbr" \
	"$(INTDIR)\md5.sbr" \
	"$(INTDIR)\MessageHeader.sbr" \
	"$(INTDIR)\NetworkClient.sbr" \
	"$(INTDIR)\ServerSocket.sbr" \
	"$(INTDIR)\Socket.sbr" \
	"$(INTDIR)\SocketImpl.sbr" \
	"$(INTDIR)\SocketOptions.sbr" \
	"$(INTDIR)\SSLSocket.sbr" \
	"$(INTDIR)\SSLSocketInputStream.sbr" \
	"$(INTDIR)\SSLSocketOutputStream.sbr" \
	"$(INTDIR)\URL.sbr" \
	"$(INTDIR)\URLConnection.sbr" \
	"$(INTDIR)\URLDecoder.sbr" \
	"$(INTDIR)\URLEncoder.sbr" \
	"$(INTDIR)\URLStreamHandler.sbr" \
	"$(INTDIR)\WWWURLConnection.sbr" \
	"$(INTDIR)\Win32PlatformUtils.sbr" \
	"$(INTDIR)\Win32ProcessInputStream.sbr" \
	"$(INTDIR)\Win32ProcessOutputStream.sbr" \
	"$(INTDIR)\myuti.sbr" \
	"$(INTDIR)\PlatformUtils.sbr" \
	"$(INTDIR)\Random.sbr" \
	"$(INTDIR)\Regexp.sbr" \
	"$(INTDIR)\RegexpPool.sbr" \
	"$(INTDIR)\StringTokenizer.sbr" \
	"$(INTDIR)\Unicode.sbr" \
	"$(INTDIR)\FileMIMEType.sbr" \
	"$(INTDIR)\MIMEBasicPart.sbr" \
	"$(INTDIR)\MIMEBodyPart.sbr" \
	"$(INTDIR)\MIMEHeader.sbr" \
	"$(INTDIR)\MIMEMessage.sbr" \
	"$(INTDIR)\MIMEMessagePart.sbr" \
	"$(INTDIR)\MIMEMultiPart.sbr" \
	"$(INTDIR)\MIMEParser.sbr" \
	"$(INTDIR)\MimeTableFileNameMap.sbr" \
	"$(INTDIR)\AutoPtr.sbr" \
	"$(INTDIR)\BoolJanitor.sbr" \
	"$(INTDIR)\ByteBuffer.sbr" \
	"$(INTDIR)\CharBuffer.sbr" \
	"$(INTDIR)\Integer.sbr" \
	"$(INTDIR)\Integer64.sbr" \
	"$(INTDIR)\mapWString.sbr" \
	"$(INTDIR)\Mutex.sbr" \
	"$(INTDIR)\Synchronized.sbr" \
	"$(INTDIR)\Throwable.sbr" \
	"$(INTDIR)\vdouble.sbr" \
	"$(INTDIR)\vint.sbr" \
	"$(INTDIR)\vMapWString.sbr" \
	"$(INTDIR)\vWString.sbr" \
	"$(INTDIR)\WString.sbr"

"$(OUTDIR)\JDFToolsLib.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=xilink6.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\jdftoolslib_D.lib" 
LIB32_OBJS= \
	"$(INTDIR)\Win32FileSystem.obj" \
	"$(INTDIR)\Win32Shortcut.obj" \
	"$(INTDIR)\BASE64Decoder.obj" \
	"$(INTDIR)\BASE64Encoder.obj" \
	"$(INTDIR)\BufferedInputStream.obj" \
	"$(INTDIR)\BufferedOutputStream.obj" \
	"$(INTDIR)\ByteArrayInputStream.obj" \
	"$(INTDIR)\ByteArrayOutputStream.obj" \
	"$(INTDIR)\CharacterDecoder.obj" \
	"$(INTDIR)\CharacterEncoder.obj" \
	"$(INTDIR)\File.obj" \
	"$(INTDIR)\FileInputStream.obj" \
	"$(INTDIR)\FileOutputStream.obj" \
	"$(INTDIR)\FileSystem.obj" \
	"$(INTDIR)\FilterInputStream.obj" \
	"$(INTDIR)\FilterOutputStream.obj" \
	"$(INTDIR)\InputStream.obj" \
	"$(INTDIR)\OutputStream.obj" \
	"$(INTDIR)\PrintStream.obj" \
	"$(INTDIR)\PushbackInputStream.obj" \
	"$(INTDIR)\QPDecoder.obj" \
	"$(INTDIR)\QPEncoder.obj" \
	"$(INTDIR)\RandomAccessInputStream.obj" \
	"$(INTDIR)\RandomAccessOutputStream.obj" \
	"$(INTDIR)\StreamBuffer.obj" \
	"$(INTDIR)\Win32InetAddressImpl.obj" \
	"$(INTDIR)\Win32SocketFactoryService.obj" \
	"$(INTDIR)\Win32SocketImpl.obj" \
	"$(INTDIR)\Win32SocketImplFactory.obj" \
	"$(INTDIR)\Win32SocketImplInputStream.obj" \
	"$(INTDIR)\Win32SocketImplOutputStream.obj" \
	"$(INTDIR)\Win32SocketInit.obj" \
	"$(INTDIR)\FileURLConnection.obj" \
	"$(INTDIR)\FileURLStreamHandler.obj" \
	"$(INTDIR)\AuthenticationInfo.obj" \
	"$(INTDIR)\Authenticator.obj" \
	"$(INTDIR)\BasicAuthentication.obj" \
	"$(INTDIR)\ChunkedInputStream.obj" \
	"$(INTDIR)\DigestAuthentication.obj" \
	"$(INTDIR)\HttpClient.obj" \
	"$(INTDIR)\HttpURLConnection.obj" \
	"$(INTDIR)\HttpURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpOutputStream.obj" \
	"$(INTDIR)\PlainHttpURLConnection.obj" \
	"$(INTDIR)\HttpsClient.obj" \
	"$(INTDIR)\HttpsURLStreamHandler.obj" \
	"$(INTDIR)\PlainHttpsURLConnection.obj" \
	"$(INTDIR)\CidURLStreamHandler.obj" \
	"$(INTDIR)\PlainURLStreamHandlerFactory.obj" \
	"$(INTDIR)\HeaderParser.obj" \
	"$(INTDIR)\InetAddress.obj" \
	"$(INTDIR)\InetAddressCachePolicy.obj" \
	"$(INTDIR)\InetAddressImpl.obj" \
	"$(INTDIR)\md5.obj" \
	"$(INTDIR)\MessageHeader.obj" \
	"$(INTDIR)\NetworkClient.obj" \
	"$(INTDIR)\ServerSocket.obj" \
	"$(INTDIR)\Socket.obj" \
	"$(INTDIR)\SocketImpl.obj" \
	"$(INTDIR)\SocketOptions.obj" \
	"$(INTDIR)\SSLSocket.obj" \
	"$(INTDIR)\SSLSocketInputStream.obj" \
	"$(INTDIR)\SSLSocketOutputStream.obj" \
	"$(INTDIR)\URL.obj" \
	"$(INTDIR)\URLConnection.obj" \
	"$(INTDIR)\URLDecoder.obj" \
	"$(INTDIR)\URLEncoder.obj" \
	"$(INTDIR)\URLStreamHandler.obj" \
	"$(INTDIR)\WWWURLConnection.obj" \
	"$(INTDIR)\Win32PlatformUtils.obj" \
	"$(INTDIR)\Win32ProcessInputStream.obj" \
	"$(INTDIR)\Win32ProcessOutputStream.obj" \
	"$(INTDIR)\myuti.obj" \
	"$(INTDIR)\PlatformUtils.obj" \
	"$(INTDIR)\Random.obj" \
	"$(INTDIR)\Regexp.obj" \
	"$(INTDIR)\RegexpPool.obj" \
	"$(INTDIR)\StringTokenizer.obj" \
	"$(INTDIR)\Unicode.obj" \
	"$(INTDIR)\FileMIMEType.obj" \
	"$(INTDIR)\MIMEBasicPart.obj" \
	"$(INTDIR)\MIMEBodyPart.obj" \
	"$(INTDIR)\MIMEHeader.obj" \
	"$(INTDIR)\MIMEMessage.obj" \
	"$(INTDIR)\MIMEMessagePart.obj" \
	"$(INTDIR)\MIMEMultiPart.obj" \
	"$(INTDIR)\MIMEParser.obj" \
	"$(INTDIR)\MimeTableFileNameMap.obj" \
	"$(INTDIR)\AutoPtr.obj" \
	"$(INTDIR)\BoolJanitor.obj" \
	"$(INTDIR)\ByteBuffer.obj" \
	"$(INTDIR)\CharBuffer.obj" \
	"$(INTDIR)\Integer.obj" \
	"$(INTDIR)\Integer64.obj" \
	"$(INTDIR)\mapWString.obj" \
	"$(INTDIR)\Mutex.obj" \
	"$(INTDIR)\Synchronized.obj" \
	"$(INTDIR)\Throwable.obj" \
	"$(INTDIR)\vdouble.obj" \
	"$(INTDIR)\vint.obj" \
	"$(INTDIR)\vMapWString.obj" \
	"$(INTDIR)\vWString.obj" \
	"$(INTDIR)\WString.obj" \
	"..\..\..\external\xerces\lib\xerces-c_2D.lib"

"$(OUTDIR)\jdftoolslib_D.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("JDFToolsLib.dep")
!INCLUDE "JDFToolsLib.dep"
!ELSE 
!MESSAGE Warning: cannot find "JDFToolsLib.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "JDFToolsLib - Win32 Release" || "$(CFG)" == "JDFToolsLib - Win32 Debug" || "$(CFG)" == "JDFToolsLib - Win32 Debug DLL" || "$(CFG)" == "JDFToolsLib - Win32 Release DLL" || "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"
SOURCE=..\..\..\src\jdf\io\Platforms\Win32\Win32FileSystem.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32FileSystem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32FileSystem.obj"	"$(INTDIR)\Win32FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32FileSystem.obj"	"$(INTDIR)\Win32FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32FileSystem.obj"	"$(INTDIR)\Win32FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32FileSystem.obj"	"$(INTDIR)\Win32FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\Platforms\Win32\Win32Shortcut.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32Shortcut.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32Shortcut.obj"	"$(INTDIR)\Win32Shortcut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32Shortcut.obj"	"$(INTDIR)\Win32Shortcut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32Shortcut.obj"	"$(INTDIR)\Win32Shortcut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32Shortcut.obj"	"$(INTDIR)\Win32Shortcut.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\BASE64Decoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\BASE64Decoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\BASE64Decoder.obj"	"$(INTDIR)\BASE64Decoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\BASE64Decoder.obj"	"$(INTDIR)\BASE64Decoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\BASE64Decoder.obj"	"$(INTDIR)\BASE64Decoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\BASE64Decoder.obj"	"$(INTDIR)\BASE64Decoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\BASE64Encoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\BASE64Encoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\BASE64Encoder.obj"	"$(INTDIR)\BASE64Encoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\BASE64Encoder.obj"	"$(INTDIR)\BASE64Encoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\BASE64Encoder.obj"	"$(INTDIR)\BASE64Encoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\BASE64Encoder.obj"	"$(INTDIR)\BASE64Encoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\BufferedInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\BufferedInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\BufferedInputStream.obj"	"$(INTDIR)\BufferedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\BufferedInputStream.obj"	"$(INTDIR)\BufferedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\BufferedInputStream.obj"	"$(INTDIR)\BufferedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\BufferedInputStream.obj"	"$(INTDIR)\BufferedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\BufferedOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\BufferedOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\BufferedOutputStream.obj"	"$(INTDIR)\BufferedOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\BufferedOutputStream.obj"	"$(INTDIR)\BufferedOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\BufferedOutputStream.obj"	"$(INTDIR)\BufferedOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\BufferedOutputStream.obj"	"$(INTDIR)\BufferedOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\ByteArrayInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\ByteArrayInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\ByteArrayInputStream.obj"	"$(INTDIR)\ByteArrayInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\ByteArrayInputStream.obj"	"$(INTDIR)\ByteArrayInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\ByteArrayInputStream.obj"	"$(INTDIR)\ByteArrayInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\ByteArrayInputStream.obj"	"$(INTDIR)\ByteArrayInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\ByteArrayOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\ByteArrayOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\ByteArrayOutputStream.obj"	"$(INTDIR)\ByteArrayOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\ByteArrayOutputStream.obj"	"$(INTDIR)\ByteArrayOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\ByteArrayOutputStream.obj"	"$(INTDIR)\ByteArrayOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\ByteArrayOutputStream.obj"	"$(INTDIR)\ByteArrayOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\CharacterDecoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\CharacterDecoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\CharacterDecoder.obj"	"$(INTDIR)\CharacterDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\CharacterDecoder.obj"	"$(INTDIR)\CharacterDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\CharacterDecoder.obj"	"$(INTDIR)\CharacterDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\CharacterDecoder.obj"	"$(INTDIR)\CharacterDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\CharacterEncoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\CharacterEncoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\CharacterEncoder.obj"	"$(INTDIR)\CharacterEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\CharacterEncoder.obj"	"$(INTDIR)\CharacterEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\CharacterEncoder.obj"	"$(INTDIR)\CharacterEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\CharacterEncoder.obj"	"$(INTDIR)\CharacterEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\File.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\File.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\File.obj"	"$(INTDIR)\File.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\File.obj"	"$(INTDIR)\File.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\File.obj"	"$(INTDIR)\File.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\File.obj"	"$(INTDIR)\File.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\FileInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FileInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FileInputStream.obj"	"$(INTDIR)\FileInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FileInputStream.obj"	"$(INTDIR)\FileInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FileInputStream.obj"	"$(INTDIR)\FileInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FileInputStream.obj"	"$(INTDIR)\FileInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\FileOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FileOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FileOutputStream.obj"	"$(INTDIR)\FileOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FileOutputStream.obj"	"$(INTDIR)\FileOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FileOutputStream.obj"	"$(INTDIR)\FileOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FileOutputStream.obj"	"$(INTDIR)\FileOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\FileSystem.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FileSystem.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FileSystem.obj"	"$(INTDIR)\FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FileSystem.obj"	"$(INTDIR)\FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FileSystem.obj"	"$(INTDIR)\FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FileSystem.obj"	"$(INTDIR)\FileSystem.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\FilterInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FilterInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FilterInputStream.obj"	"$(INTDIR)\FilterInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FilterInputStream.obj"	"$(INTDIR)\FilterInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FilterInputStream.obj"	"$(INTDIR)\FilterInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FilterInputStream.obj"	"$(INTDIR)\FilterInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\FilterOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FilterOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FilterOutputStream.obj"	"$(INTDIR)\FilterOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FilterOutputStream.obj"	"$(INTDIR)\FilterOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FilterOutputStream.obj"	"$(INTDIR)\FilterOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FilterOutputStream.obj"	"$(INTDIR)\FilterOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\InputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\InputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\InputStream.obj"	"$(INTDIR)\InputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\InputStream.obj"	"$(INTDIR)\InputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\InputStream.obj"	"$(INTDIR)\InputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\InputStream.obj"	"$(INTDIR)\InputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\OutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\OutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\OutputStream.obj"	"$(INTDIR)\OutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\OutputStream.obj"	"$(INTDIR)\OutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\OutputStream.obj"	"$(INTDIR)\OutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\OutputStream.obj"	"$(INTDIR)\OutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\PrintStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PrintStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PrintStream.obj"	"$(INTDIR)\PrintStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PrintStream.obj"	"$(INTDIR)\PrintStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PrintStream.obj"	"$(INTDIR)\PrintStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PrintStream.obj"	"$(INTDIR)\PrintStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\PushbackInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PushbackInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PushbackInputStream.obj"	"$(INTDIR)\PushbackInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PushbackInputStream.obj"	"$(INTDIR)\PushbackInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PushbackInputStream.obj"	"$(INTDIR)\PushbackInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PushbackInputStream.obj"	"$(INTDIR)\PushbackInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\QPDecoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\QPDecoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\QPDecoder.obj"	"$(INTDIR)\QPDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\QPDecoder.obj"	"$(INTDIR)\QPDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\QPDecoder.obj"	"$(INTDIR)\QPDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\QPDecoder.obj"	"$(INTDIR)\QPDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\QPEncoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\QPEncoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\QPEncoder.obj"	"$(INTDIR)\QPEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\QPEncoder.obj"	"$(INTDIR)\QPEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\QPEncoder.obj"	"$(INTDIR)\QPEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\QPEncoder.obj"	"$(INTDIR)\QPEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\RandomAccessInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\RandomAccessInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\RandomAccessInputStream.obj"	"$(INTDIR)\RandomAccessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\RandomAccessInputStream.obj"	"$(INTDIR)\RandomAccessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\RandomAccessInputStream.obj"	"$(INTDIR)\RandomAccessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\RandomAccessInputStream.obj"	"$(INTDIR)\RandomAccessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\RandomAccessOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\RandomAccessOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\RandomAccessOutputStream.obj"	"$(INTDIR)\RandomAccessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\RandomAccessOutputStream.obj"	"$(INTDIR)\RandomAccessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\RandomAccessOutputStream.obj"	"$(INTDIR)\RandomAccessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\RandomAccessOutputStream.obj"	"$(INTDIR)\RandomAccessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\io\StreamBuffer.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\StreamBuffer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\StreamBuffer.obj"	"$(INTDIR)\StreamBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\StreamBuffer.obj"	"$(INTDIR)\StreamBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\StreamBuffer.obj"	"$(INTDIR)\StreamBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\StreamBuffer.obj"	"$(INTDIR)\StreamBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32InetAddressImpl.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32InetAddressImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32InetAddressImpl.obj"	"$(INTDIR)\Win32InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32InetAddressImpl.obj"	"$(INTDIR)\Win32InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32InetAddressImpl.obj"	"$(INTDIR)\Win32InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32InetAddressImpl.obj"	"$(INTDIR)\Win32InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketFactoryService.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32SocketFactoryService.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32SocketFactoryService.obj"	"$(INTDIR)\Win32SocketFactoryService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32SocketFactoryService.obj"	"$(INTDIR)\Win32SocketFactoryService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32SocketFactoryService.obj"	"$(INTDIR)\Win32SocketFactoryService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32SocketFactoryService.obj"	"$(INTDIR)\Win32SocketFactoryService.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImpl.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32SocketImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32SocketImpl.obj"	"$(INTDIR)\Win32SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32SocketImpl.obj"	"$(INTDIR)\Win32SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32SocketImpl.obj"	"$(INTDIR)\Win32SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32SocketImpl.obj"	"$(INTDIR)\Win32SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplFactory.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32SocketImplFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32SocketImplFactory.obj"	"$(INTDIR)\Win32SocketImplFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32SocketImplFactory.obj"	"$(INTDIR)\Win32SocketImplFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32SocketImplFactory.obj"	"$(INTDIR)\Win32SocketImplFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32SocketImplFactory.obj"	"$(INTDIR)\Win32SocketImplFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32SocketImplInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32SocketImplInputStream.obj"	"$(INTDIR)\Win32SocketImplInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32SocketImplInputStream.obj"	"$(INTDIR)\Win32SocketImplInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32SocketImplInputStream.obj"	"$(INTDIR)\Win32SocketImplInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32SocketImplInputStream.obj"	"$(INTDIR)\Win32SocketImplInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketImplOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32SocketImplOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32SocketImplOutputStream.obj"	"$(INTDIR)\Win32SocketImplOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32SocketImplOutputStream.obj"	"$(INTDIR)\Win32SocketImplOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32SocketImplOutputStream.obj"	"$(INTDIR)\Win32SocketImplOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32SocketImplOutputStream.obj"	"$(INTDIR)\Win32SocketImplOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Platforms\Win32\Win32SocketInit.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32SocketInit.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32SocketInit.obj"	"$(INTDIR)\Win32SocketInit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32SocketInit.obj"	"$(INTDIR)\Win32SocketInit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32SocketInit.obj"	"$(INTDIR)\Win32SocketInit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32SocketInit.obj"	"$(INTDIR)\Win32SocketInit.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\FileURLConnection.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FileURLConnection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FileURLConnection.obj"	"$(INTDIR)\FileURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FileURLConnection.obj"	"$(INTDIR)\FileURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FileURLConnection.obj"	"$(INTDIR)\FileURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FileURLConnection.obj"	"$(INTDIR)\FileURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\FileURLStreamHandler.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FileURLStreamHandler.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FileURLStreamHandler.obj"	"$(INTDIR)\FileURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FileURLStreamHandler.obj"	"$(INTDIR)\FileURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FileURLStreamHandler.obj"	"$(INTDIR)\FileURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FileURLStreamHandler.obj"	"$(INTDIR)\FileURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\AuthenticationInfo.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\AuthenticationInfo.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\AuthenticationInfo.obj"	"$(INTDIR)\AuthenticationInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\AuthenticationInfo.obj"	"$(INTDIR)\AuthenticationInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\AuthenticationInfo.obj"	"$(INTDIR)\AuthenticationInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\AuthenticationInfo.obj"	"$(INTDIR)\AuthenticationInfo.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Authenticator.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Authenticator.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Authenticator.obj"	"$(INTDIR)\Authenticator.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Authenticator.obj"	"$(INTDIR)\Authenticator.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Authenticator.obj"	"$(INTDIR)\Authenticator.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Authenticator.obj"	"$(INTDIR)\Authenticator.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\BasicAuthentication.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\BasicAuthentication.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\BasicAuthentication.obj"	"$(INTDIR)\BasicAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\BasicAuthentication.obj"	"$(INTDIR)\BasicAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\BasicAuthentication.obj"	"$(INTDIR)\BasicAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\BasicAuthentication.obj"	"$(INTDIR)\BasicAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\ChunkedInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\ChunkedInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\ChunkedInputStream.obj"	"$(INTDIR)\ChunkedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\ChunkedInputStream.obj"	"$(INTDIR)\ChunkedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\ChunkedInputStream.obj"	"$(INTDIR)\ChunkedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\ChunkedInputStream.obj"	"$(INTDIR)\ChunkedInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\DigestAuthentication.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\DigestAuthentication.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\DigestAuthentication.obj"	"$(INTDIR)\DigestAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\DigestAuthentication.obj"	"$(INTDIR)\DigestAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\DigestAuthentication.obj"	"$(INTDIR)\DigestAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\DigestAuthentication.obj"	"$(INTDIR)\DigestAuthentication.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\HttpClient.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\HttpClient.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\HttpClient.obj"	"$(INTDIR)\HttpClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\HttpClient.obj"	"$(INTDIR)\HttpClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\HttpClient.obj"	"$(INTDIR)\HttpClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\HttpClient.obj"	"$(INTDIR)\HttpClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\HttpURLConnection.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\HttpURLConnection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\HttpURLConnection.obj"	"$(INTDIR)\HttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\HttpURLConnection.obj"	"$(INTDIR)\HttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\HttpURLConnection.obj"	"$(INTDIR)\HttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\HttpURLConnection.obj"	"$(INTDIR)\HttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\HttpURLStreamHandler.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\HttpURLStreamHandler.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\HttpURLStreamHandler.obj"	"$(INTDIR)\HttpURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\HttpURLStreamHandler.obj"	"$(INTDIR)\HttpURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\HttpURLStreamHandler.obj"	"$(INTDIR)\HttpURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\HttpURLStreamHandler.obj"	"$(INTDIR)\HttpURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\PlainHttpOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PlainHttpOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PlainHttpOutputStream.obj"	"$(INTDIR)\PlainHttpOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PlainHttpOutputStream.obj"	"$(INTDIR)\PlainHttpOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PlainHttpOutputStream.obj"	"$(INTDIR)\PlainHttpOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PlainHttpOutputStream.obj"	"$(INTDIR)\PlainHttpOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\PlainHttpURLConnection.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PlainHttpURLConnection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PlainHttpURLConnection.obj"	"$(INTDIR)\PlainHttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PlainHttpURLConnection.obj"	"$(INTDIR)\PlainHttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PlainHttpURLConnection.obj"	"$(INTDIR)\PlainHttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PlainHttpURLConnection.obj"	"$(INTDIR)\PlainHttpURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\HttpsClient.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\HttpsClient.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\HttpsClient.obj"	"$(INTDIR)\HttpsClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\HttpsClient.obj"	"$(INTDIR)\HttpsClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\HttpsClient.obj"	"$(INTDIR)\HttpsClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\HttpsClient.obj"	"$(INTDIR)\HttpsClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\HttpsURLStreamHandler.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\HttpsURLStreamHandler.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\HttpsURLStreamHandler.obj"	"$(INTDIR)\HttpsURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\HttpsURLStreamHandler.obj"	"$(INTDIR)\HttpsURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\HttpsURLStreamHandler.obj"	"$(INTDIR)\HttpsURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\HttpsURLStreamHandler.obj"	"$(INTDIR)\HttpsURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\PlainHttpsURLConnection.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PlainHttpsURLConnection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PlainHttpsURLConnection.obj"	"$(INTDIR)\PlainHttpsURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PlainHttpsURLConnection.obj"	"$(INTDIR)\PlainHttpsURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PlainHttpsURLConnection.obj"	"$(INTDIR)\PlainHttpsURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PlainHttpsURLConnection.obj"	"$(INTDIR)\PlainHttpsURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\CidURLStreamHandler.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\CidURLStreamHandler.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\CidURLStreamHandler.obj"	"$(INTDIR)\CidURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\CidURLStreamHandler.obj"	"$(INTDIR)\CidURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\CidURLStreamHandler.obj"	"$(INTDIR)\CidURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\CidURLStreamHandler.obj"	"$(INTDIR)\CidURLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\PlainURLStreamHandlerFactory.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PlainURLStreamHandlerFactory.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PlainURLStreamHandlerFactory.obj"	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PlainURLStreamHandlerFactory.obj"	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PlainURLStreamHandlerFactory.obj"	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PlainURLStreamHandlerFactory.obj"	"$(INTDIR)\PlainURLStreamHandlerFactory.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\HeaderParser.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\HeaderParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\HeaderParser.obj"	"$(INTDIR)\HeaderParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\HeaderParser.obj"	"$(INTDIR)\HeaderParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\HeaderParser.obj"	"$(INTDIR)\HeaderParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\HeaderParser.obj"	"$(INTDIR)\HeaderParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\InetAddress.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\InetAddress.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\InetAddress.obj"	"$(INTDIR)\InetAddress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\InetAddress.obj"	"$(INTDIR)\InetAddress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\InetAddress.obj"	"$(INTDIR)\InetAddress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\InetAddress.obj"	"$(INTDIR)\InetAddress.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\InetAddressCachePolicy.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\InetAddressCachePolicy.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\InetAddressCachePolicy.obj"	"$(INTDIR)\InetAddressCachePolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\InetAddressCachePolicy.obj"	"$(INTDIR)\InetAddressCachePolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\InetAddressCachePolicy.obj"	"$(INTDIR)\InetAddressCachePolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\InetAddressCachePolicy.obj"	"$(INTDIR)\InetAddressCachePolicy.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\InetAddressImpl.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\InetAddressImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\InetAddressImpl.obj"	"$(INTDIR)\InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\InetAddressImpl.obj"	"$(INTDIR)\InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\InetAddressImpl.obj"	"$(INTDIR)\InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\InetAddressImpl.obj"	"$(INTDIR)\InetAddressImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\md5.c

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\md5.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\md5.obj"	"$(INTDIR)\md5.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\md5.obj"	"$(INTDIR)\md5.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\md5.obj"	"$(INTDIR)\md5.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\md5.obj"	"$(INTDIR)\md5.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\MessageHeader.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MessageHeader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MessageHeader.obj"	"$(INTDIR)\MessageHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MessageHeader.obj"	"$(INTDIR)\MessageHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MessageHeader.obj"	"$(INTDIR)\MessageHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MessageHeader.obj"	"$(INTDIR)\MessageHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\NetworkClient.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\NetworkClient.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\NetworkClient.obj"	"$(INTDIR)\NetworkClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\NetworkClient.obj"	"$(INTDIR)\NetworkClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\NetworkClient.obj"	"$(INTDIR)\NetworkClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\NetworkClient.obj"	"$(INTDIR)\NetworkClient.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\ServerSocket.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\ServerSocket.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\ServerSocket.obj"	"$(INTDIR)\ServerSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\ServerSocket.obj"	"$(INTDIR)\ServerSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\ServerSocket.obj"	"$(INTDIR)\ServerSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\ServerSocket.obj"	"$(INTDIR)\ServerSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\Socket.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Socket.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Socket.obj"	"$(INTDIR)\Socket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Socket.obj"	"$(INTDIR)\Socket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Socket.obj"	"$(INTDIR)\Socket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Socket.obj"	"$(INTDIR)\Socket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\SocketImpl.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\SocketImpl.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\SocketImpl.obj"	"$(INTDIR)\SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\SocketImpl.obj"	"$(INTDIR)\SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\SocketImpl.obj"	"$(INTDIR)\SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\SocketImpl.obj"	"$(INTDIR)\SocketImpl.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\SocketOptions.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\SocketOptions.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\SocketOptions.obj"	"$(INTDIR)\SocketOptions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\SocketOptions.obj"	"$(INTDIR)\SocketOptions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\SocketOptions.obj"	"$(INTDIR)\SocketOptions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\SocketOptions.obj"	"$(INTDIR)\SocketOptions.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\SSLSocket.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\SSLSocket.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\SSLSocket.obj"	"$(INTDIR)\SSLSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\SSLSocket.obj"	"$(INTDIR)\SSLSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\SSLSocket.obj"	"$(INTDIR)\SSLSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\SSLSocket.obj"	"$(INTDIR)\SSLSocket.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\SSLSocketInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\SSLSocketInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\SSLSocketInputStream.obj"	"$(INTDIR)\SSLSocketInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\SSLSocketInputStream.obj"	"$(INTDIR)\SSLSocketInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\SSLSocketInputStream.obj"	"$(INTDIR)\SSLSocketInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\SSLSocketInputStream.obj"	"$(INTDIR)\SSLSocketInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\SSLSocketOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\SSLSocketOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\SSLSocketOutputStream.obj"	"$(INTDIR)\SSLSocketOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\SSLSocketOutputStream.obj"	"$(INTDIR)\SSLSocketOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\SSLSocketOutputStream.obj"	"$(INTDIR)\SSLSocketOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\SSLSocketOutputStream.obj"	"$(INTDIR)\SSLSocketOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\URL.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\URL.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\URL.obj"	"$(INTDIR)\URL.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\URL.obj"	"$(INTDIR)\URL.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\URL.obj"	"$(INTDIR)\URL.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\URL.obj"	"$(INTDIR)\URL.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\URLConnection.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\URLConnection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\URLConnection.obj"	"$(INTDIR)\URLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\URLConnection.obj"	"$(INTDIR)\URLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\URLConnection.obj"	"$(INTDIR)\URLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\URLConnection.obj"	"$(INTDIR)\URLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\URLDecoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\URLDecoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\URLDecoder.obj"	"$(INTDIR)\URLDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\URLDecoder.obj"	"$(INTDIR)\URLDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\URLDecoder.obj"	"$(INTDIR)\URLDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\URLDecoder.obj"	"$(INTDIR)\URLDecoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\URLEncoder.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\URLEncoder.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\URLEncoder.obj"	"$(INTDIR)\URLEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\URLEncoder.obj"	"$(INTDIR)\URLEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\URLEncoder.obj"	"$(INTDIR)\URLEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\URLEncoder.obj"	"$(INTDIR)\URLEncoder.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\URLStreamHandler.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\URLStreamHandler.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\URLStreamHandler.obj"	"$(INTDIR)\URLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\URLStreamHandler.obj"	"$(INTDIR)\URLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\URLStreamHandler.obj"	"$(INTDIR)\URLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\URLStreamHandler.obj"	"$(INTDIR)\URLStreamHandler.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\net\WWWURLConnection.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\WWWURLConnection.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\WWWURLConnection.obj"	"$(INTDIR)\WWWURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\WWWURLConnection.obj"	"$(INTDIR)\WWWURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\WWWURLConnection.obj"	"$(INTDIR)\WWWURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\WWWURLConnection.obj"	"$(INTDIR)\WWWURLConnection.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32PlatformUtils.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32PlatformUtils.obj"	"$(INTDIR)\Win32PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32PlatformUtils.obj"	"$(INTDIR)\Win32PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32PlatformUtils.obj"	"$(INTDIR)\Win32PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32PlatformUtils.obj"	"$(INTDIR)\Win32PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32ProcessInputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32ProcessInputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32ProcessInputStream.obj"	"$(INTDIR)\Win32ProcessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32ProcessInputStream.obj"	"$(INTDIR)\Win32ProcessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32ProcessInputStream.obj"	"$(INTDIR)\Win32ProcessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32ProcessInputStream.obj"	"$(INTDIR)\Win32ProcessInputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\Platforms\Win32\Win32ProcessOutputStream.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Win32ProcessOutputStream.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Win32ProcessOutputStream.obj"	"$(INTDIR)\Win32ProcessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Win32ProcessOutputStream.obj"	"$(INTDIR)\Win32ProcessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Win32ProcessOutputStream.obj"	"$(INTDIR)\Win32ProcessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Win32ProcessOutputStream.obj"	"$(INTDIR)\Win32ProcessOutputStream.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\myuti.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\myuti.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\myuti.obj"	"$(INTDIR)\myuti.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\myuti.obj"	"$(INTDIR)\myuti.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\myuti.obj"	"$(INTDIR)\myuti.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\myuti.obj"	"$(INTDIR)\myuti.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\PlatformUtils.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\PlatformUtils.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\PlatformUtils.obj"	"$(INTDIR)\PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\PlatformUtils.obj"	"$(INTDIR)\PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\PlatformUtils.obj"	"$(INTDIR)\PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\PlatformUtils.obj"	"$(INTDIR)\PlatformUtils.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\Random.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Random.obj"	"$(INTDIR)\Random.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Random.obj"	"$(INTDIR)\Random.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Random.obj"	"$(INTDIR)\Random.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Random.obj"	"$(INTDIR)\Random.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\Regexp.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Regexp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Regexp.obj"	"$(INTDIR)\Regexp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Regexp.obj"	"$(INTDIR)\Regexp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Regexp.obj"	"$(INTDIR)\Regexp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Regexp.obj"	"$(INTDIR)\Regexp.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\RegexpPool.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\RegexpPool.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\RegexpPool.obj"	"$(INTDIR)\RegexpPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\RegexpPool.obj"	"$(INTDIR)\RegexpPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\RegexpPool.obj"	"$(INTDIR)\RegexpPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\RegexpPool.obj"	"$(INTDIR)\RegexpPool.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\StringTokenizer.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\StringTokenizer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\StringTokenizer.obj"	"$(INTDIR)\StringTokenizer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\StringTokenizer.obj"	"$(INTDIR)\StringTokenizer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\StringTokenizer.obj"	"$(INTDIR)\StringTokenizer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\StringTokenizer.obj"	"$(INTDIR)\StringTokenizer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\util\Unicode.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Unicode.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Unicode.obj"	"$(INTDIR)\Unicode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Unicode.obj"	"$(INTDIR)\Unicode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Unicode.obj"	"$(INTDIR)\Unicode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Unicode.obj"	"$(INTDIR)\Unicode.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\FileMIMEType.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\FileMIMEType.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\FileMIMEType.obj"	"$(INTDIR)\FileMIMEType.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\FileMIMEType.obj"	"$(INTDIR)\FileMIMEType.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\FileMIMEType.obj"	"$(INTDIR)\FileMIMEType.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\FileMIMEType.obj"	"$(INTDIR)\FileMIMEType.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEBasicPart.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEBasicPart.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEBasicPart.obj"	"$(INTDIR)\MIMEBasicPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEBasicPart.obj"	"$(INTDIR)\MIMEBasicPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEBasicPart.obj"	"$(INTDIR)\MIMEBasicPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEBasicPart.obj"	"$(INTDIR)\MIMEBasicPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEBodyPart.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEBodyPart.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEBodyPart.obj"	"$(INTDIR)\MIMEBodyPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEBodyPart.obj"	"$(INTDIR)\MIMEBodyPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEBodyPart.obj"	"$(INTDIR)\MIMEBodyPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEBodyPart.obj"	"$(INTDIR)\MIMEBodyPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEHeader.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEHeader.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEHeader.obj"	"$(INTDIR)\MIMEHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEHeader.obj"	"$(INTDIR)\MIMEHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEHeader.obj"	"$(INTDIR)\MIMEHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEHeader.obj"	"$(INTDIR)\MIMEHeader.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEMessage.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEMessage.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEMessage.obj"	"$(INTDIR)\MIMEMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEMessage.obj"	"$(INTDIR)\MIMEMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEMessage.obj"	"$(INTDIR)\MIMEMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEMessage.obj"	"$(INTDIR)\MIMEMessage.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEMessagePart.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEMessagePart.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEMessagePart.obj"	"$(INTDIR)\MIMEMessagePart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEMessagePart.obj"	"$(INTDIR)\MIMEMessagePart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEMessagePart.obj"	"$(INTDIR)\MIMEMessagePart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEMessagePart.obj"	"$(INTDIR)\MIMEMessagePart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEMultiPart.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEMultiPart.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEMultiPart.obj"	"$(INTDIR)\MIMEMultiPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEMultiPart.obj"	"$(INTDIR)\MIMEMultiPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEMultiPart.obj"	"$(INTDIR)\MIMEMultiPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEMultiPart.obj"	"$(INTDIR)\MIMEMultiPart.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MIMEParser.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MIMEParser.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MIMEParser.obj"	"$(INTDIR)\MIMEParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MIMEParser.obj"	"$(INTDIR)\MIMEParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MIMEParser.obj"	"$(INTDIR)\MIMEParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MIMEParser.obj"	"$(INTDIR)\MIMEParser.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\mime\MimeTableFileNameMap.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\MimeTableFileNameMap.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\MimeTableFileNameMap.obj"	"$(INTDIR)\MimeTableFileNameMap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\MimeTableFileNameMap.obj"	"$(INTDIR)\MimeTableFileNameMap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\MimeTableFileNameMap.obj"	"$(INTDIR)\MimeTableFileNameMap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\MimeTableFileNameMap.obj"	"$(INTDIR)\MimeTableFileNameMap.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\AutoPtr.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\AutoPtr.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\AutoPtr.obj"	"$(INTDIR)\AutoPtr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\AutoPtr.obj"	"$(INTDIR)\AutoPtr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\AutoPtr.obj"	"$(INTDIR)\AutoPtr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\AutoPtr.obj"	"$(INTDIR)\AutoPtr.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\BoolJanitor.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\BoolJanitor.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\BoolJanitor.obj"	"$(INTDIR)\BoolJanitor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\BoolJanitor.obj"	"$(INTDIR)\BoolJanitor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\BoolJanitor.obj"	"$(INTDIR)\BoolJanitor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\BoolJanitor.obj"	"$(INTDIR)\BoolJanitor.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\ByteBuffer.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\ByteBuffer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\ByteBuffer.obj"	"$(INTDIR)\ByteBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\ByteBuffer.obj"	"$(INTDIR)\ByteBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\ByteBuffer.obj"	"$(INTDIR)\ByteBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\ByteBuffer.obj"	"$(INTDIR)\ByteBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\CharBuffer.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\CharBuffer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\CharBuffer.obj"	"$(INTDIR)\CharBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\CharBuffer.obj"	"$(INTDIR)\CharBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\CharBuffer.obj"	"$(INTDIR)\CharBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\CharBuffer.obj"	"$(INTDIR)\CharBuffer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\Integer.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Integer.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Integer.obj"	"$(INTDIR)\Integer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Integer.obj"	"$(INTDIR)\Integer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Integer.obj"	"$(INTDIR)\Integer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Integer.obj"	"$(INTDIR)\Integer.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\Integer64.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Integer64.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Integer64.obj"	"$(INTDIR)\Integer64.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Integer64.obj"	"$(INTDIR)\Integer64.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Integer64.obj"	"$(INTDIR)\Integer64.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Integer64.obj"	"$(INTDIR)\Integer64.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\mapWString.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\mapWString.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\mapWString.obj"	"$(INTDIR)\mapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\mapWString.obj"	"$(INTDIR)\mapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\mapWString.obj"	"$(INTDIR)\mapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\mapWString.obj"	"$(INTDIR)\mapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\Mutex.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Mutex.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Mutex.obj"	"$(INTDIR)\Mutex.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Mutex.obj"	"$(INTDIR)\Mutex.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Mutex.obj"	"$(INTDIR)\Mutex.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Mutex.obj"	"$(INTDIR)\Mutex.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\Synchronized.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Synchronized.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Synchronized.obj"	"$(INTDIR)\Synchronized.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Synchronized.obj"	"$(INTDIR)\Synchronized.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Synchronized.obj"	"$(INTDIR)\Synchronized.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Synchronized.obj"	"$(INTDIR)\Synchronized.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\Throwable.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\Throwable.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\Throwable.obj"	"$(INTDIR)\Throwable.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\Throwable.obj"	"$(INTDIR)\Throwable.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\Throwable.obj"	"$(INTDIR)\Throwable.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\Throwable.obj"	"$(INTDIR)\Throwable.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\vdouble.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\vdouble.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\vdouble.obj"	"$(INTDIR)\vdouble.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\vdouble.obj"	"$(INTDIR)\vdouble.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\vdouble.obj"	"$(INTDIR)\vdouble.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\vdouble.obj"	"$(INTDIR)\vdouble.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\vint.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\vint.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\vint.obj"	"$(INTDIR)\vint.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\vint.obj"	"$(INTDIR)\vint.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\vint.obj"	"$(INTDIR)\vint.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\vint.obj"	"$(INTDIR)\vint.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\vMapWString.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\vMapWString.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\vMapWString.obj"	"$(INTDIR)\vMapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\vMapWString.obj"	"$(INTDIR)\vMapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\vMapWString.obj"	"$(INTDIR)\vMapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\vMapWString.obj"	"$(INTDIR)\vMapWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\vWString.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\vWString.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\vWString.obj"	"$(INTDIR)\vWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\vWString.obj"	"$(INTDIR)\vWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\vWString.obj"	"$(INTDIR)\vWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\vWString.obj"	"$(INTDIR)\vWString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\..\..\src\jdf\lang\WString.cpp

!IF  "$(CFG)" == "JDFToolsLib - Win32 Release"


"$(INTDIR)\WString.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug"


"$(INTDIR)\WString.obj"	"$(INTDIR)\WString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug DLL"


"$(INTDIR)\WString.obj"	"$(INTDIR)\WString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Release DLL"


"$(INTDIR)\WString.obj"	"$(INTDIR)\WString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "JDFToolsLib - Win32 Debug LineOnly"


"$(INTDIR)\WString.obj"	"$(INTDIR)\WString.sbr" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 


!ENDIF 

