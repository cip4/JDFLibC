########################################
#
# Makefile for SpawnJDF
#
# TBD: (1) static lib in release version
#
########################################

LIBNAME = SpawnJDF

DLIB_MAJ_NR = 0
DLIB_MIN_NR = 0
DLIB_REL_NR = 0

INSTPATH = ../../../../Build/Linux/$(LIBNAME)
SRCPATH = ../../../../tests/TestWrapper
OBJPATH = ../../../../Build/Linux/$(LIBNAME)/obj

INCLUDES = -I../../../../external/stlport/stlport -I../../../../src/jdf/wrapper -I../../../../src/jdf/wrappercore -I../../../../external/xerces/include -I../../../../src -I../../../../external/xerces/include/xercesc
LIBPATHS = -L../../../../Build/Linux/JDFWrapperCoreLib -L../../../../Build/Linux/JDFWrapperLib -L../../../../Build/Linux/JDFToolsLib -L../../../../external/xerces/lib -L../../../../external/stlport/lib
LIBS = -lJDFWrapperLib -lJDFWrapperCoreLib -lJDFToolsLib -lxerces-c1_7_0 -lstlport_gcc
##########################################
OPTIONS = -Wno-non-template-friend

STATLIB := $(LIBNAME)

OPTS = $(OPTIONS)
LIBOUT = $(STATLIB)

CPP = g++

##########################################

OBJS = 	$(OBJPATH)/temp.o


all: ObjDir $(LIBOUT) install

ObjDir:
	mkdir -p $(OBJPATH)

$(STATLIB): $(OBJPATH)/$(STATLIB)

$(OBJPATH)/$(STATLIB): $(OBJS)
	strip --strip-all $(OBJPATH)/temp.o -o $(OBJPATH)/$(LIBOUT)

install: $(LIBOUT)
	mkdir -p $(INSTPATH)
	cp $(OBJPATH)/$(LIBOUT) $(INSTPATH)

clean:
	rm -f $(OBJPATH)/$(STATLIB)
	rm -f $(OBJPATH)/*.o


$(OBJPATH)/temp.o: $(SRCPATH)/SpawnJDF.cpp
	$(CPP) $(OPTS) -Wno-non-template-friend $(SRCPATH)/SpawnJDF.cpp  $(LIBPATHS) $(LIBS) $(INCLUDES) -o $(OBJPATH)/temp.o

