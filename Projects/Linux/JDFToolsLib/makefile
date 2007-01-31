########################################
#
# Makefile for JDFToolsLib
#
########################################

# LIBTYPE = (stat | dyn)
LIBTYPE = stat

LIBNAME = JDFToolsLib

DLIB_MAJ_NR = 0
DLIB_MIN_NR = 0
DLIB_REL_NR = 0

INSTPATH = ../../lib/debug/

SRCPATH = ../../src/jdf

OBJPATH = ../../obj/$(LIBNAME)/debug

#STL_FLAGS        = -D_STLP_DEBUG -D_STLP_USE_STATIC_LIB
#STL_INCLUDE_PATH = -I../../../devTools/common/STLport/stlport
#STL_LIB          = -lstlport_gcc
#STL_LIB_PATH     = -L../../../devTools/common/STLport/lib

XERCES_INCLUDE_PATH = -I"../../../../devTools/common/Xerces-C/include" -I"../../../../devTools/common/Xerces-C/include/xercesc"

INCLUDES = -I../../src -I../../src/lang -I../../src/util -I../../src/io -I../../src/net $(XERCES_INCLUDE_PATH)

LINKP = -L../../lib/Linux

IO_OBJS = \
	$(OBJPATH)/BASE64Decoder.o \
	$(OBJPATH)/BASE64Encoder.o \
	$(OBJPATH)/BufferedInputStream.o \
	$(OBJPATH)/BufferedOutputStream.o \
	$(OBJPATH)/ByteArrayInputStream.o \
	$(OBJPATH)/ByteArrayOutputStream.o \
	$(OBJPATH)/CharacterDecoder.o \
	$(OBJPATH)/CharacterEncoder.o \
	$(OBJPATH)/File.o \
	$(OBJPATH)/FileInputStream.o \
	$(OBJPATH)/FileOutputStream.o \
	$(OBJPATH)/FileSystem.o \
	$(OBJPATH)/FilterInputStream.o \
	$(OBJPATH)/FilterOutputStream.o \
	$(OBJPATH)/InputStream.o \
	$(OBJPATH)/OutputStream.o \
	$(OBJPATH)/PrintStream.o \
	$(OBJPATH)/PushbackInputStream.o \
	$(OBJPATH)/QPDecoder.o \
	$(OBJPATH)/QPEncoder.o \
	$(OBJPATH)/RandomAccessInputStream.o \
	$(OBJPATH)/RandomAccessOutputStream.o \
	$(OBJPATH)/StreamBuffer.o

LANG_OBJS = \
	$(OBJPATH)/BoolJanitor.o \
	$(OBJPATH)/ByteBuffer.o \
	$(OBJPATH)/CharBuffer.o \
	$(OBJPATH)/Integer.o \
	$(OBJPATH)/Integer64.o \
	$(OBJPATH)/mapWString.o \
	$(OBJPATH)/Mutex.o \
	$(OBJPATH)/Synchronized.o \
	$(OBJPATH)/Throwable.o \
	$(OBJPATH)/vdouble.o \
	$(OBJPATH)/vint.o \
	$(OBJPATH)/vMapWString.o \
	$(OBJPATH)/vWString.o \
	$(OBJPATH)/WString.o \

#	$(OBJPATH)/AutoPtr.o \

MIME_OBJS = \
	$(OBJPATH)/FileMIMEType.o \
	$(OBJPATH)/MIMEBasicPart.o \
	$(OBJPATH)/MIMEBodyPart.o \
	$(OBJPATH)/MIMEHeader.o \
	$(OBJPATH)/MIMEMessage.o \
	$(OBJPATH)/MIMEMessagePart.o \
	$(OBJPATH)/MIMEMultiPart.o \
	$(OBJPATH)/MIMEParser.o \
	$(OBJPATH)/MimeTableFileNameMap.o

NET_OBJS = \
	$(OBJPATH)/AuthenticationInfo.o \
	$(OBJPATH)/Authenticator.o \
	$(OBJPATH)/BasicAuthentication.o \
	$(OBJPATH)/ChunkedInputStream.o \
	$(OBJPATH)/CidURLStreamHandler.o \
	$(OBJPATH)/DigestAuthentication.o \
	$(OBJPATH)/FileURLConnection.o \
	$(OBJPATH)/FileURLStreamHandler.o \
	$(OBJPATH)/HeaderParser.o \
	$(OBJPATH)/HttpClient.o \
	$(OBJPATH)/HttpsClient.o \
	$(OBJPATH)/HttpsURLStreamHandler.o \
	$(OBJPATH)/HttpURLConnection.o \
	$(OBJPATH)/HttpURLStreamHandler.o \
	$(OBJPATH)/InetAddress.o \
	$(OBJPATH)/InetAddressCachePolicy.o \
	$(OBJPATH)/InetAddressImpl.o \
	$(OBJPATH)/md5.o \
	$(OBJPATH)/MessageHeader.o \
	$(OBJPATH)/NetworkClient.o \
	$(OBJPATH)/PlainHttpOutputStream.o \
	$(OBJPATH)/PlainHttpsURLConnection.o \
	$(OBJPATH)/PlainHttpURLConnection.o \
	$(OBJPATH)/PlainURLStreamHandlerFactory.o \
	$(OBJPATH)/ServerSocket.o \
	$(OBJPATH)/Socket.o \
	$(OBJPATH)/SocketImpl.o \
	$(OBJPATH)/SocketOptions.o \
	$(OBJPATH)/SSLSocket.o \
	$(OBJPATH)/SSLSocketInputStream.o \
	$(OBJPATH)/SSLSocketOutputStream.o \
	$(OBJPATH)/URL.o \
	$(OBJPATH)/URLConnection.o \
	$(OBJPATH)/URLDecoder.o \
	$(OBJPATH)/URLEncoder.o \
	$(OBJPATH)/URLStreamHandler.o \
	$(OBJPATH)/WWWURLConnection.o

PNG_OBJS = \
	$(OBJPATH)/PNGFile.o \
	$(OBJPATH)/PNGFileImpl.o \
	$(OBJPATH)/PNGInfo.o

UTIL_OBJS = \
	$(OBJPATH)/myuti.o \
	$(OBJPATH)/PlatformUtils.o \
	$(OBJPATH)/Random.o \
	$(OBJPATH)/Regexp.o \
	$(OBJPATH)/RegexpPool.o \
	$(OBJPATH)/StringTokenizer.o \
	$(OBJPATH)/Unicode.o

OBJS = $(IO_OBJS) $(LANG_OBJS) $(NET_OBJS) $(UTIL_OBJS)


OPTIONS = $(STL_FLAGS) -pthread -Wno-non-template-friend -D__linux__ -DUNICODE -D_UNICODE

##########################################

DYNLIB  := lib$(LIBNAME).so.$(DLIB_MAJ_NR).$(DLIB_MIN_NR).$(DLIB_REL_NR)
STATLIB := lib$(LIBNAME).a

ifeq ($(LIBTYPE),dyn)
OPTS = $(OPTIONS) -fPIC -DPIC -DCOMPILER_GNU -w
LIBOUT = $(DYNLIB)
else
OPTS = $(OPTIONS)
LIBOUT = $(STATLIB)
endif
OPTS= $(OPTIONS)
CPP = g++

##########################################

all: ObjDir $(LIBOUT) install

ObjDir:
	mkdir -p $(OBJPATH)

$(STATLIB): $(OBJPATH)/$(STATLIB)
$(DYNLIB): $(OBJPATH)/$(DYNLIB)

$(OBJPATH)/$(STATLIB): $(OBJS)
	ar rcs $(OBJPATH)/$(STATLIB) $(OBJS)

$(OBJPATH)/$(DYNLIB): $(OBJS)
	$(CPP) -shared -Wl,-soname,lib$(LIBNAME).so.$(DLIB_MAJ_NR) -o $(OBJPATH)/$(DYNLIB) $(OBJS) $(LIBS) $(LINKP) 

install: $(LIBOUT) $(INSTPATH)
	cp $(OBJPATH)/$(LIBOUT) $(INSTPATH)

$(INSTPATH):
	mkdir -p $(INSTPATH)

#ifeq ($(LIBTYPE),dyn)
#	ln -sf $(INSTPATH)/lib$(LIBNAME).so.$(DLIB_MAJ_NR).$(DLIB_MIN_NR).$(DLIB_REL_NR) $(INSTPATH)/lib$(LIBNAME).so.$(DLIB_MAJ_NR)
#	ln -sf $(INSTPATH)/lib$(LIBNAME).so.$(DLIB_MAJ_NR) $(INSTPATH)/lib$(LIBNAME).so
#endif

clean:
	rm -f $(OBJPATH)/$(DYNLIB)
	rm -f $(OBJPATH)/$(STATLIB)
	rm -f $(OBJPATH)/*.o


$(OBJPATH)/%.o: $(SRCPATH)/io/%.cpp
	$(CPP) $(OPTS) $(INCLUDES) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/lang/%.cpp
	$(CPP) $(OPTS) $(INCLUDES) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/net/%.c
	$(CPP) $(OPTS) $(INCLUDES) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/net/%.cpp
	$(CPP) $(OPTS) $(INCLUDES) -c $< -o $@

$(OBJPATH)/%.o: $(SRCPATH)/util/%.cpp
	$(CPP) $(OPTS) $(INCLUDES) -c $< -o $@
