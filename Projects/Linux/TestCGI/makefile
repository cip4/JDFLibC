########################################
#
# Makefile for TestCGI
#
# TBD: (1) static lib in release version
#
########################################

LIBNAME = TestCGI

DLIB_MAJ_NR = 0
DLIB_MIN_NR = 0
DLIB_REL_NR = 0

INSTPATH = ../../../Build/Linux/$(LIBNAME)
SRCPATH = ../../../tests/TestCGI
OBJPATH = ../../../Build/Linux/$(LIBNAME)/obj

INCLUDES = -I/usr/include/stlport -I../../../src/jdf/wrapper -I../../../src/jdf/wrappercore -I../../../external/xerces/include -I../../../src -I../../../external/xerces/src -I../../../tests/TestCGI
LIBPATHS = -L../../../Build/Linux/JDFWrapperCoreLib -L../../../Build/Linux/JDFWrapperLib -L../../../Build/Linux/JDFToolsLib -L../../../external/xerces/lib
LIBS = /usr/lib/libxerces-c1_6_0.so -lJDFToolsLib -lstlport_gcc
##########################################
OPTIONS = -O -Wno-non-template-friend -w -lc -fpic -D_REENTRANT -DTYPESAFE

STATLIB := $(LIBNAME)

OPTS = $(OPTIONS)
LIBOUT = $(STATLIB)

CPP = g++

##########################################

OBJS = 	$(OBJPATH)/TestCGI.o


all: ObjDir $(LIBOUT) install

ObjDir:
	mkdir -p $(OBJPATH)
$(STATLIB):$(OBJPATH)/$(STATLIB)


install: $(LIBOUT)
	mkdir -p $(INSTPATH)
	cp $(OBJS) $(INSTPATH)

clean:
	rm -f $(OBJPATH)/$(STATLIB)
	rm -f $(OBJPATH)/*.o


$(OBJPATH)/passwd.o: $(SRCPATH)/passwd.cpp
	$(CPP) $(SRCPATH)/passwd.cpp  $(LIBPATHS) $(LIBS) $(INCLUDES) -o $(OBJPATH)/passwd.o

$(OBJPATH)/TestCGI.o: $(SRCPATH)/TestCGI.cpp
	$(CPP) $(SRCPATH)/TestCGI.cpp  $(LIBPATHS) $(LIBS) $(INCLUDES) -o $(OBJPATH)/TestCGI.o
