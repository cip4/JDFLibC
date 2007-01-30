########################################
#
# Makefile for JDFWrapperCoreLib
#
# TBD: (1) static lib in release version
#
########################################

LIBNAME = JDFWrapperCoreLib

DLIB_MAJ_NR = 0
DLIB_MIN_NR = 0
DLIB_REL_NR = 0

INSTPATH = ../../../Build/Linux/$(LIBNAME)
SRCPATH = ../../../src/jdf
OBJPATH = ../../../Build/Linux/$(LIBNAME)/obj

INCLUDES = -I../../../external/stlport/stlport -I../../../src -I../../../src/jdf -I../../../src/jdf/wrappercore -I../../../external/xerces/src/xercesc -I../../../external/xerces/src -I../../../src/jdf/wrapper -I../../../src/jdf/wrapper/AutoJDF -DPROJ_JDFTOOLSLIB 


##########################################
OPTIONS = -O -Wno-non-template-friend -w -DTYPESAFE

STATLIB := lib$(LIBNAME).a

OPTS = $(OPTIONS)
LIBOUT = $(STATLIB)

CPP = g++

##########################################

OBJS = 	$(OBJPATH)/KElement.o \
	$(OBJPATH)/KNode.o \
	$(OBJPATH)/KNodeList.o \
	$(OBJPATH)/MyDate.o \
	$(OBJPATH)/XMLDoc.o \
	$(OBJPATH)/XMLDocUserData.o \
	$(OBJPATH)/XMLstrm.o

all: ObjDir $(LIBOUT) install

ObjDir:
	mkdir -p $(OBJPATH)

$(STATLIB): $(OBJPATH)/$(STATLIB)

$(OBJPATH)/$(STATLIB): $(OBJS)
	ar rcs $(OBJPATH)/$(STATLIB) $(OBJS)

install: $(LIBOUT)
	mkdir -p $(INSTPATH)
	cp $(OBJPATH)/$(LIBOUT) $(INSTPATH)

clean:
	rm -f $(OBJPATH)/$(STATLIB)
	rm -f $(OBJPATH)/*.o

# Example from coslib
#							# proceeds every file in the directory
# $(OBJPATH)/%.o: $(SRCPATH)/wrapper/%.cpp			# Dependency Rule, create object file if source file has changed
#	$(CPP) -c $(OPTS) $(INCLUDES) -o $@ $<		# compile single source file

$(OBJPATH)/KElement.o: $(SRCPATH)/wrappercore/KElement.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/KElement.o $(SRCPATH)/wrappercore/KElement.cpp

$(OBJPATH)/KNode.o: $(SRCPATH)/wrappercore/KNode.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/KNode.o $(SRCPATH)/wrappercore/KNode.cpp

$(OBJPATH)/KNodeList.o: $(SRCPATH)/wrappercore/KNodeList.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/KNodeList.o $(SRCPATH)/wrappercore/KNodeList.cpp

$(OBJPATH)/MyDate.o: $(SRCPATH)/wrappercore/MyDate.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/MyDate.o $(SRCPATH)/wrappercore/MyDate.cpp

$(OBJPATH)/XMLDoc.o: $(SRCPATH)/wrappercore/XMLDoc.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/XMLDoc.o $(SRCPATH)/wrappercore/XMLDoc.cpp

$(OBJPATH)/XMLDocUserData.o: $(SRCPATH)/wrappercore/XMLDocUserData.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/XMLDocUserData.o $(SRCPATH)/wrappercore/XMLDocUserData.cpp


$(OBJPATH)/XMLstrm.o: $(SRCPATH)/wrappercore/XMLstrm.cpp
	$(CPP) -c $(OPTS) $(INCLUDES) -o $(OBJPATH)/XMLstrm.o $(SRCPATH)/wrappercore/XMLstrm.cpp

