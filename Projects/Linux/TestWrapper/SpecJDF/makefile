########################################
#
# Makefile for SpecJDF
#
# TBD: (1) static lib in release version
#
########################################

LIBNAME = SpecJDF

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

OBJS = 	$(OBJPATH)/SpecJDF.o \
	$(OBJPATH)/JDFSimulator.o

all: ObjDir $(LIBOUT) install

ObjDir:
	mkdir -p $(OBJPATH)

$(STATLIB): $(OBJPATH)/$(STATLIB)

$(OBJPATH)/$(STATLIB): $(OBJS)
	$(CPP) $(OBJPATH)/SpecJDF.o $(OBJPATH)/JDFSimulator.o $(LIBPATHS) $(LIBS) -o $(OBJPATH)/$(LIBOUT)
#	ar rcs $(OBJPATH)/$(STATLIB) $(OBJS)
install: $(LIBOUT)
	mkdir -p $(INSTPATH)
	cp $(OBJPATH)/$(LIBOUT) $(INSTPATH)

clean:
	rm -f $(OBJPATH)/$(STATLIB)
	rm -f $(OBJPATH)/*.o


$(OBJPATH)/SpecJDF.o: $(SRCPATH)/SpecJDF.cpp
	$(CPP) $(OPTS) -Wno-non-template-friend $(SRCPATH)/SpecJDF.cpp $(INCLUDES) -o $(OBJPATH)/SpecJDF.o

$(OBJPATH)/JDFSimulator.o: $(SRCPATH)/JDFSimulator.cpp
	$(CPP) $(OPTS) -c $(SRCPATH)/JDFSimulator.cpp $(INCLUDES) -o $(OBJPATH)/JDFSimulator.o

