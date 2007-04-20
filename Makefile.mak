# *****************************************************************************
#      project :  Buildmanagement
#       system :  JDFOpenSrc
#   sub-system :  
#       module :  Makefile.mak
#
#  Copyright (c) 2003-2004 Heidelberger Druckmaschinen AG / BUPP 
#  Reproduction or disclosure of this file or its contents without the prior
#  written consent of Heidelberger Druckmaschinen AG is prohibited.
# -----------------------------------------------------------------------------
#  description :  This file contains the template for makefiles in the 
#                 specified project.
#
#  environment :  nmake / omake
# =============================================================================
#  date       | version |  author           |  description
# ------------+---------+-------------------+----------------------------------
#  04-Dec-2006             D.Hermsen/C.Behr    Fixed LIB/DLL Link Libraries for debuglineonly
#  20-Apr-2004             Mike Matthiesen     
#  22-Aug-2003    1.0      Mike Matthiesen     initial version.
#
# *****************************************************************************
#   - all lines that start with
#     #SET ...              : macro must be set
#     #OPT ...              : setting is optional
# *****************************************************************************

!IFDEF OS                                       # ***** DO NOT CHANGE THIS LINE
!IF ("$(OS)" == "NT")                           # ***** DO NOT CHANGE THIS LINE
!IF ("$(PROCESSOR_ARCHITECTURE)"=="x86")        # ***** DO NOT CHANGE THIS LINE
DIRSEP  = \                                     # ***** DO NOT CHANGE THIS LINE
DIRCUR  = .                                     # ***** DO NOT CHANGE THIS LINE
DIRUP   = ..                                    # ***** DO NOT CHANGE THIS LINE
PROCESSOR =$(DIRSEP)$(PROCESSOR_ARCHITECTURE)   # ***** DO NOT CHANGE THIS LINE
!ENDIF                                          # ***** DO NOT CHANGE THIS LINE
!ENDIF # End of '!IF ("$(OS)" == "NT")'         # ***** DO NOT CHANGE THIS LINE
!ENDIF # End of '!IFDEF OS'                     # ***** DO NOT CHANGE THIS LINE

###-------------------------------------------------------------------###
#  Using tools
#  This is necessary because all include paths of the tools are named 
#  in the ProjectBuildSettings.inc file. In this manner we reduce the 
#  include paths and increase the speed for compiling.
#  Set the tools to TRUE if you need the tool for your development
#  e.g.
#  TOOL_ACROBATSDK           = TRUE
#  TOOL_VISUAL_STUDIO        = TRUE
###-------------------------------------------------------------------###

USE_ACROBATSDK              = FALSE # OPT set to TRUE if you develop PlugIns for Acrobat
USE_ADOBE_PDF_LIBRARY       = FALSE # OPT set to TRUE if you have to use Adobe PDF libraries
USE_DRIVER_DEVELOPMENT_KIT  = FALSE # OPT set to TRUE if you develop a driver (DDK)
USE_VISUAL_STUDIO           = TRUE  # OPT set to TRUE if you want to build an exe, dll or lib
USE_DTP41                   = FALSE # OPT set to TRUE if you develop a linearization with the DTP41
USE_JAVA_HELP               = FALSE # OPT set to TRUE if you develop a helpdesk in Java
USE_JAVA_XMLPARSER          = FALSE # OPT set to TRUE if you need a xml parser in your subcomponent
USE_JAVA_DEVELOPMENT_KIT    = FALSE # OPT set to TRUE if you need some include pathes or jar files (JDK)
USE_JIKES                   = FALSE # OPT set to TRUE if you need a automatic dependencies generator
USE_LIBPNG                  = TRUE  # OPT set to TRUE for additional libs and headers from MatLab
USE_MATLAB                  = FALSE # OPT set to TRUE for additional libs and headers from MatLab
USE_MICO                    = FALSE # OPT set to TRUE for additional libs and headers from MatLab
USE_ORBIX_3                 = FALSE # OPT set to TRUE if you use Orbix 3 version or lower version
USE_ORBIX2000               = FALSE # OPT set to TRUE for Orbix 2000 compilation and include paths
USE_ORBIXWEB                = FALSE # OPT set to TRUE for Orbix clients (Java)
USE_PERL                    = TRUE  # OPT set to FALSE if you don't need Perl. You need it for the build scripts
USE_PYTHON                  = TRUE  # OPT set to FALSE if you don't need Python. You need it for the build scripts
USE_SIGNTOOL                = FALSE # OPT set to TRUE if you develop a signature for jar files
USE_XERCES-C                = TRUE  # OPT set to TRUE if you develop with the Xerces-C libs

###-------------------------------------------------------------------###
#  VOBNAME, COMPONENT and SUBCOMPONENT_NAME definition
#
###-------------------------------------------------------------------###

VOB_NAME            = $(DIRSEP)cmpINFRA_CommonParsers
COMPONENT_NAME      = $(DIRSEP)JDFOpenSrc
#SUBCOMPONENT_NAME   = $(DIRSEP)Projects\Win32\DFE

###--------------------------------------------------------------------------###
#
#  set the directory root relative to the current makefile
#
###--------------------------------------------------------------------------###

!IFDEF SUBCOMPONENT_NAME                                                # ***** DO NOT CHANGE THIS LINE
DIRROOT = $(DIRCUR)$(DIRSEP)$(DIRUP)$(DIRSEP)$(DIRUP)$(DIRSEP)$(DIRUP)  # ***** DO NOT CHANGE THIS LINE
!ELSE                                                                   # ***** DO NOT CHANGE THIS LINE
DIRROOT = $(DIRCUR)$(DIRSEP)$(DIRUP)$(DIRSEP)$(DIRUP)                   # ***** DO NOT CHANGE THIS LINE
!ENDIF                                                                  # ***** DO NOT CHANGE THIS LINE

COMPONENT_ROOT      = $(DIRROOT)$(VOB_NAME)$(COMPONENT_NAME)            # ***** DO NOT CHANGE THIS LINE
USER_MAKE_INCLUDE   = $(COMPONENT_ROOT)$(SUBCOMPONENT_NAME)$(SUBCOMPONENT_NAME).inc   # ***** DO NOT CHANGE THIS LINE

###--------------------------------------------------------------------------###
#  Current makefile directory name
#
###--------------------------------------------------------------------------###

MAKEFILE_DIR_NAME = $(COMPONENT_ROOT)$(SUBCOMPONENT_NAME)$(DIRSEP)$(MAKEFILE)   # ***** DO NOT CHANGE THIS LINE

###--------------------------------------------------------------------------###
#  Set the project VOB. For your current project
#
###--------------------------------------------------------------------------###
                                            # check if PRJ_VOB is already set by project makefile
                                            # (without this option we cannot assign another project to this component)
!IFNDEF PRJ_VOB                             # ***** DO NOT CHANGE THIS LINE
PRJ_VOB = $(DIRSEP)prjINFRA
!ENDIF                                      # ***** DO NOT CHANGE THIS LINE

PRJ_VOB_PATH = $(DIRROOT)$(PRJ_VOB)         # ***** DO NOT CHANGE THIS LINE

###-------------------------------------------------------------------###
#  PROJECT SETTINGS FOR THIS COMPONENT
#  do not edit this section
###-------------------------------------------------------------------###
#
# Any macros of global scope specified on the command line do not get passed
# down to lower level makefiles or batch files unless we copy them here.
# Macros defined as environment variables do get down
#
# Set a default configuration
!IFNDEF CFG
CFG = JDFWrapperCoreLib
!ENDIF

###-------------------------------------------------------------------###
#   Path definition for global makefiles
###-------------------------------------------------------------------###
#
!IFNDEF MAKEINCLUDES                            # **** DO NOT CHANGE NEXT LINE
MAKEINCLUDES = JDFOpenSrc                       # SET name of project specific path (example: PIL_JSS)
!ENDIF                                          # **** DO NOT CHANGE NEXT LINE

!IFNDEF GLOBAL_MAKEINCLUDES                     # **** DO NOT CHANGE NEXT LINE
GLOBAL_MAKEINCLUDES=config                      # SET name of non-project specific path (example: config)
!ENDIF                                          # **** DO NOT CHANGE NEXT LINE

MAKEFILE_INC_PATH = $(PRJ_VOB_PATH)$(DIRSEP)$(MAKEINCLUDES)                 # ***** DO NOT CHANGE THIS LINE
GLOBAL_MAKEFILE_INC_PATH = $(PRJ_VOB_PATH)$(DIRSEP)$(GLOBAL_MAKEINCLUDES)   # ***** DO NOT CHANGE THIS LINE
# This makefile's home directory
MAKEFILE_HOME_DIR = $(DIRROOT)$(DIRSEP)$(DIRUP)$(VOB_NAME)$(COMPONENT_NAME) # ***** DO NOT CHANGE THIS LINE

###-------------------------------------------------------------------###
# Special case for JDFOpenSrc
# the dll build needs a version string in the dll name for a better
# identification. The file pversion.inc should only be included if 
# JDFOpenSrc will be build by itself.
###-------------------------------------------------------------------###
!IF ("$(MAKEINCLUDES)"=="JDFOpenSrc")
!   IF (EXIST($(MAKEFILE_INC_PATH)$(DIRSEP)pversion.inc))
!   INCLUDE $(MAKEFILE_INC_PATH)$(DIRSEP)pversion.inc
JDFOPENSRC_VER_STRING = $(VER_s_major_str)$(VER_s_point)$(VER_s_minor_str)
!   ELSE
!   MESSAGE Error: Unable to include $(MAKEFILE_INC_PATH)$(DIRSEP)pversion.inc.
!   MESSAGE 1) Currently using $(PRJ_VOB). If this is not ok, then set PRJ_VOB to your project VOB.
!   MESSAGE 2) Please check that you are working on a mapped drive!
!   ERROR
!   ENDIF
!ENDIF

###-------------------------------------------------------------------###
#   SUBDIRECTORIES
# add your subdirectories and seperate them with semicolon e.g.
#
# SOURCE_SUBDIRS = ;\SysUISExt;\MyNextSubDirectory
#
# The first semicolon ';' is needed !! The backslash '\' is necessary
###-------------------------------------------------------------------###
SOURCE_SUBDIRS =  ;.\..\src\jdf\wrapper \
                  ;.\..\src\jdf\wrappercore \
                  ;.\..\src\jdf\wrapper\AutoJDF \
                  ;.\..\src\jdf\io\Platforms\Win32 \
                  ;.\..\src\jdf\io \
                  ;.\..\src\jdf\net\Platforms\Win32 \
                  ;.\..\src\jdf\net \
                  ;.\..\src\jdf\util\Platforms\Win32 \
                  ;.\..\src\jdf\util \
                  ;.\..\src\jdf\mime \
                  ;.\..\src\jdf\lang

###-------------------------------------------------------------------###
#  include global project specific definitions (mostly paths)
###-------------------------------------------------------------------###
#
# **** DO NOT CHANGE NEXT SECTION
!IF (EXIST($(MAKEFILE_INC_PATH)$(DIRSEP)ProjectBuildSettings.inc))
!INCLUDE $(MAKEFILE_INC_PATH)$(DIRSEP)ProjectBuildSettings.inc
!ELSE
!MESSAGE Error: Unable to include $(MAKEFILE_INC_PATH)$(DIRSEP)ProjectBuildSettings.inc.
!MESSAGE 1) Currently using $(PRJ_VOB). If this is not ok, then set PRJ_VOB to your project VOB.
!MESSAGE 2) Please check that you are working on a mapped drive!
!ERROR
!ENDIF
# **** END OF SECTION

#---
# Compatibility with different Visual Studio Versions
# This macro should be set in DevStudio_Build.inc
#---
!IFNDEF MSC_VERSION
MSC_VERSION = VC6
!ENDIF

!IFDEF XERCES-C_DISTVER
JDFOPENSRC_EXT_STRING = X$(XERCES-C_DISTVER)_$(MSC_VERSION)
!ELSE
JDFOPENSRC_EXT_STRING = X$(XERCES-C_VER)
!ENDIF

!IF ("$(STL_TYPE)" == "STLPORT")
JDFOPENSRC_VER_STRING = $(JDFOPENSRC_VER_STRING)_P$(JDFOPENSRC_EXT_STRING)
!ENDIF
!IF ("$(STL_TYPE)" == "MICROSOFT")
JDFOPENSRC_VER_STRING = $(JDFOPENSRC_VER_STRING)_M$(JDFOPENSRC_EXT_STRING)
!ENDIF
!IF ("$(STL_TYPE)" == "DINKUMWARE")
JDFOPENSRC_VER_STRING = $(JDFOPENSRC_VER_STRING)_D$(JDFOPENSRC_EXT_STRING)
!ENDIF

###-------------------------------------------------------------------###
#   PREPROCESSOR AND LINKER DEFINITIONS
#  set the #define Variable for your project here e.g.
#
#  USER_COMPILER_DEFINES  = /D "MYDEFINE" /D "YOURDEFINE"
#  USER_COMPILER_SWITCHES = /Gx 
#  USER_COMPILER_INCLUDE  = /I ".\..\include"
###-------------------------------------------------------------------###

# Set some additional compiler settings
!IF ("$(BUILD_TYPE)"=="RELEASE")            # ***** DO NOT CHANGE THIS LINE
!    IF ("$(CFG)"=="JDFToolsLib")
USER_COMPILER_DEFINES  = /D "JDF_TOOLS_LIB"
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperLib")
USER_COMPILER_DEFINES  = /D "_REENTRANT" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB"
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperCoreLib")
USER_COMPILER_DEFINES  = /D "_REENTRANT" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB"
!    ENDIF
!    IF ("$(CFG)"=="JDFToolsDll")
USER_COMPILER_DEFINES  = /D "JDF_TOOLS" /D "_REENTRANT"
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperDll")
USER_COMPILER_DEFINES  = /D "JDFWrapperDLL_EXPORTS" \
                         /D "_REENTRANT" /D "JDF_WRAPPERCORE"
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperCoreDll")
USER_COMPILER_DEFINES  = /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT"
!    ENDIF
!ELSE                                       # ***** DO NOT CHANGE THIS LINE
!    IF ("$(CFG)"=="JDFToolsLib")
USER_COMPILER_DEFINES  = /D "JDF_TOOLS_LIB"
!    ENDIF
!    IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
USER_COMPILER_DEFINES  = /D "JDF_TOOLS_LIB"
USER_COMPILER_SWITCHES = /Zd
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperLib")
USER_COMPILER_DEFINES  = /D "_REENTRANT" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB"
!    ENDIF                         
!    IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
USER_COMPILER_DEFINES  = /D "_REENTRANT" /D "JDF_TOOLS_LIB" /D "JDF_WRAPPERCORE_LIB"
USER_COMPILER_SWITCHES = /Zd
!    ENDIF                         
!    IF ("$(CFG)"=="JDFWrapperCoreLib")
USER_COMPILER_DEFINES  = /D "_REENTRANT" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB"
!    ENDIF
!    IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
USER_COMPILER_DEFINES  = /D "_REENTRANT" /D "JDF_WRAPPERCORE_LIB" /D "JDF_TOOLS_LIB"
USER_COMPILER_SWITCHES = /Zd
!    ENDIF
!    IF ("$(CFG)"=="JDFToolsDll")
USER_COMPILER_DEFINES  = /D "JDF_TOOLS" /D "_REENTRANT"
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperDll")
USER_COMPILER_DEFINES  = /D "JDFWrapperDLL_EXPORTS" \
                         /D "_REENTRANT" /D "JDF_WRAPPERCORE"
!    ENDIF
!    IF ("$(CFG)"=="JDFWrapperCoreDll")
USER_COMPILER_DEFINES  = /D "JDFWrapperDLL_EXPORTS" /D "JDF_WRAPPERCORE" /D "_REENTRANT"
!    ENDIF
!ENDIF                                      # ***** DO NOT CHANGE THIS LINE

!IF ("$(STL_TYPE)"=="DINKUMWARE")
USER_COMPILER_DEFINES  = $(USER_COMPILER_DEFINES) /D _CPP_LIBVER /D USING_DINKUMWARE_STL
!ENDIF


USER_COMPILER_INCLUDE  =  \
                        /I "$(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(DIRSEP)JDFOpenSrc$(DIRSEP)src" \
                        /I "$(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(DIRSEP)JDFOpenSrc$(DIRSEP)src$(DIRSEP)jdf" \
                        /I "$(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(DIRSEP)JDFOpenSrc$(DIRSEP)src$(DIRSEP)jdf$(DIRSEP)lang" \
                        /I "$(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(DIRSEP)JDFOpenSrc$(DIRSEP)src$(DIRSEP)jdf$(DIRSEP)wrapper" \
                        /I "$(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(DIRSEP)JDFOpenSrc$(DIRSEP)src$(DIRSEP)jdf$(DIRSEP)wrappercore"

# Set some additional linker settings
!IF ("$(BUILD_TYPE)"=="RELEASE")            # ***** DO NOT CHANGE THIS LINE
#USER_LINKER_SWITCHES   =                   # OPT additional linker switches
!ELSE                                       # ***** DO NOT CHANGE THIS LINE
USER_LINKER_SWITCHES   = /nologo /dll /profile                   # OPT additional linker switches
!ENDIF                                      # ***** DO NOT CHANGE THIS LINE
USER_LINKER_LIBPATHS   = /LIBPATH:"$(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(VOB_STRUCTURE_LIB)$(CMPVOB_STRUCTURE_BUILDTYPE:$(CFG)=)"
                  # OPT additional library pathes (e.g. /LIBPATH:"$(DIRROOT)$(DIRSEP)cmpXXXX_AnotherVOB$(VOB_STRUCTURE_LIB)$(CMPVOB_STRUCTURE_BUILDTYPE)"

# Set some additional idl compiler settings
# The IDL compiler does not accept '/' slashes
#
# e.g. USER_IDL_DEFINES       = -D NO_ESCAPED_IDENTIFIERS
#USER_IDL_DEFINES       =                   # OPT 
#USER_IDL_INCLUDE       =                   # OPT example: -I"$(DIRROOT)$(DIRSEP)cmpCDFE_ServerBase$(VOB_STRUCTURE_IDL)"

# Set some additional Microsoft idl compiler settings
#USER_MIDL_DEFINES      =                   # OPT
#USER_MIDL_INCLUDE      =                   # OPT

#USER_USE_PCH = THRUHEADER                  # OPT clear if you do not want to use pch-files
                                            # set to AUTO for automatic use of precompiled headers
                                            # set to THRUHEADER for use of precompiled headers thru a user selected file
#USER_USE_PCH_HEADER = MyCommonHeaderFile.h # SET IF USER_USE_PCH IS SET
                                            # This header file must exist in all 
                                            # *.cpp files and it must contain the 
                                            # '#pragma hdrstop' line
###-------------------------------------------------------------------###
#  TARGET DEFINITION
#  Declare your target by removing the '#' that preceds the target name
#  You are able to build different targets in one subcomponent in one 
#  build process
#  e.g.
#  You can build a static library and than a dynamic library
#  If you use this method you have to call your makefile with the '-a'
#  option
###-------------------------------------------------------------------###
!IF ("$(CFG)"=="JDFToolsLib")
USER_TARGET_LIB     = $(DIRSEP)JDFToolsLib$(BUILD_EXTENSION).lib
!ENDIF
!IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
USER_TARGET_LIB     = $(DIRSEP)JDFToolsLib$(BUILD_EXTENSION).lib
!ENDIF
!IF ("$(CFG)"=="JDFWrapperLib")
USER_TARGET_LIB     = $(DIRSEP)JDFWrapperLib$(BUILD_EXTENSION).lib
!ENDIF
!IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
USER_TARGET_LIB     = $(DIRSEP)JDFWrapperLib$(BUILD_EXTENSION).lib
!ENDIF
!IF ("$(CFG)"=="JDFWrapperCoreLib")
USER_TARGET_LIB     = $(DIRSEP)JDFWrapperCoreLib$(BUILD_EXTENSION).lib
!ENDIF
!IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
USER_TARGET_LIB     = $(DIRSEP)JDFWrapperCoreLib$(BUILD_EXTENSION).lib
!ENDIF
!IF ("$(CFG)"=="JDFToolsDll")
USER_TARGET_DLL     = $(DIRSEP)JDFToolsDll$(JDFOPENSRC_VER_STRING)$(BUILD_EXTENSION).dll    # SET if you want to build a dynamic library
USER_TARGET_DLL_LIB = $(DIRSEP)JDFToolsDll$(BUILD_EXTENSION).lib     # SET this also if you want to build a DLL
!ENDIF
!IF ("$(CFG)"=="JDFWrapperDll")
USER_TARGET_DLL     = $(DIRSEP)JDFWrapperDll$(JDFOPENSRC_VER_STRING)$(BUILD_EXTENSION).dll    # SET if you want to build a dynamic library
USER_TARGET_DLL_LIB = $(DIRSEP)JDFWrapperDll$(BUILD_EXTENSION).lib     # SET this also if you want to build a DLL
!ENDIF
!IF ("$(CFG)"=="JDFWrapperCoreDll")
USER_TARGET_DLL     = $(DIRSEP)JDFWrapperCoreDll$(JDFOPENSRC_VER_STRING)$(BUILD_EXTENSION).dll    # SET if you want to build a dynamic library
USER_TARGET_DLL_LIB = $(DIRSEP)JDFWrapperCoreDll$(BUILD_EXTENSION).lib     # SET this also if you want to build a DLL
!ENDIF
#USER_TARGET_EXE     = $(SUBCOMPONENT_NAME)$(BUILD_EXTENSION).exe     # SET if you want to build an executable
#USER_TARGET_TEST    = $(SUBCOMPONENT_NAME)$(BUILD_EXTENSION).py      # SET if you want to test your code
#USER_TARGET_DRIVER  = $(SUBCOMPONENT_NAME)$(BUILD_EXTENSION).sys     # SET if you want to build a driver


###-------------------------------------------------------------------###
#  FILE LISTS
#  File names should include the path name (absolute or relative)
#
#  Delete all other File lists which are not needed for the specified 
#  target.
###-------------------------------------------------------------------###


# Single file compilation
#
#USER_SF_OBJS       = $(CMPO_OBJ_DIR)$(DIRSEP)MyFile1.obj


# LIB OBJ File List
#
###########################   Begin of JDFToolsLib   ###########################
!IF ("$(CFG)"=="JDFToolsLib")
!INCLUDE Objects_Of_JDFTools.inc
USER_LIB_OBJS = $(USER_OBJS)
!ENDIF
!IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
!INCLUDE Objects_Of_JDFTools.inc
USER_LIB_OBJS = $(USER_OBJS)
!ENDIF
############################   End of JDFToolsLib   ############################

##########################   Begin of JDFWrapperLib   ##########################
!IF ("$(CFG)"=="JDFWrapperLib")
!INCLUDE Objects_Of_JDFWrapper.inc
USER_LIB_OBJS = $(USER_OBJS)
!ENDIF                      
!IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
!INCLUDE Objects_Of_JDFWrapper.inc
USER_LIB_OBJS = $(USER_OBJS)
!ENDIF                      
###########################   End of JDFWrapperLib   ###########################

########################   Begin of JDFWrapperCoreLib   ########################
!IF ("$(CFG)"=="JDFWrapperCoreLib")
!INCLUDE Objects_Of_JDFWrapperCore.inc
USER_LIB_OBJS = $(USER_OBJS)
!ENDIF
!IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
!INCLUDE Objects_Of_JDFWrapperCore.inc
USER_LIB_OBJS = $(USER_OBJS)
!ENDIF
#########################   End of JDFWrapperCoreLib   #########################

# DLL OBJ File List
#
###########################   Begin of JDFToolsDll   ###########################
!IF ("$(CFG)"=="JDFToolsDll")
!INCLUDE Objects_Of_JDFTools.inc
USER_DLL_OBJS = $(USER_OBJS)
!ENDIF
############################   End of JDFToolsDll   ############################

##########################   Begin of JDFWrapperDll   ##########################
!IF ("$(CFG)"=="JDFWrapperDll")
!INCLUDE Objects_Of_JDFWrapper.inc
USER_DLL_OBJS = $(USER_OBJS)
!ENDIF
###########################   End of JDFWrapperDll   ###########################

########################   Begin of JDFWrapperCoreDll   ########################
!IF ("$(CFG)"=="JDFWrapperCoreDll")
!INCLUDE Objects_Of_JDFWrapperCore.inc
USER_DLL_OBJS = $(USER_OBJS)
!ENDIF
#########################   End of JDFWrapperCoreDll   #########################


# EXE OBJ File List
#
#USER_EXE_OBJS      = $(CMPO_OBJ_DIR)$(DIRSEP)MyFile1.obj \
#                     $(CMPO_OBJ_DIR)$(DIRSEP)MyFile2.obj


# OBJ list for a device driver
#
#USER_DRIVER_OBJS   = $(CMPO_OBJ_DIR)$(DIRSEP)MyFile1.obj \
#                     $(CMPO_OBJ_DIR)$(DIRSEP)MyFile2.obj


# IDL Files List
#
#USER_IDL_H_FILES   = $(CMPO_IDLOUT_DIR)$(DIRSEP)MyFile1_idl.h \
#                     $(CMPO_IDLOUT_DIR)$(DIRSEP)MyFile2_idl.h


# RES File List
#
#USER_RES_FILES     = $(CMPO_OBJ_DIR)$(SUBCOMPONENT_NAME).res


# MC File List
#
#USER_MC_FILES      = $(CMPO_IDLOUT_DIR)$(SUBCOMPONENT_NAME)1_mdf.h \
#                     $(CMPO_IDLOUT_DIR)$(SUBCOMPONENT_NAME)2_mdf.h


# HTML Doc source files
#
#USER_HTML_FILES    = $(VOB_INCLUDE_DIR)$(DIRSEP)MyFile1.h \
#                     $(VOB_INCLUDE_DIR)$(DIRSEP)MyFile2.h


# JNI Files list
#
#USER_JNI_OBJS = $(CMPO_IDLOUT_DIR)$(DIRSEP)LutCalculator.h 
#

# Pathes for the JNI objs
#USER_JNI_CLASSPATH     = net.nexpress.linearization.LutCalculator
#USER_CMPO_CLASSPATH    = net.nexpress.linearization

###-------------------------------------------------------------------###
#  LIB FILE LISTS
#  List of .lib files to be linked to the target
#
#  If you want to add libraries from third party tools you should define
#  a macro and add this macro to the USER_XXX_LINK_LIBS
###-------------------------------------------------------------------###
#

!IF ("$(BUILD_TYPE)"=="DEBUG")  # ***** DO NOT CHANGE THIS LINE
#MFC_LIBRARIES = mfcd.lib       # OPT create macros and name third party libraries. Use the macro in USER_XXX_LINK_LIBS
!ELSE                           # ***** DO NOT CHANGE THIS LINE
#MFC_LIBRARIES = mfc.lib        # OPT create macros and name third party libraries. Use the macro in USER_XXX_LINK_LIBS
!ENDIF                          # ***** DO NOT CHANGE THIS LINE

# =====================================================
# LIB Link Libs
# =====================================================

# -----------------------------------------------------
# JDFToolsLib (LIB)
# -----------------------------------------------------
!IF (("$(CFG)"=="JDFToolsLib") || ("$(CFG)"=="debuglineonlyJDFToolsLib"))
USER_LIB_LINK_LIBS = \
                     $(XERCES-C_LIBNAME) \
!IF ("$(MSC_VERSION)" == "VC8")
                     rpcrt4.lib \
!ENDIF
                     WS2_32.lib
!ENDIF
# -----------------------------------------------------
# JDFWrapperLib (LIB)
# -----------------------------------------------------
!IF (("$(CFG)"=="JDFWrapperLib") || ("$(CFG)"=="debuglineonlyJDFWrapperLib"))
!ENDIF
# -----------------------------------------------------
# JDFWrapperCoreLib (LIB)
# -----------------------------------------------------
!IF (("$(CFG)"=="JDFWrapperCoreLib") || ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib"))
!ENDIF

# =====================================================
# DLL Link Libs
# =====================================================

# -----------------------------------------------------
# JDFToolsDll (DLL)
# -----------------------------------------------------
!IF ("$(CFG)"=="JDFToolsDll")
USER_DLL_LINK_LIBS = \
                     $(XERCES-C_LIBNAME) \
                     $(LIBPNGLIB) \
!IF ("$(MSC_VERSION)" != "VC8")
                     WS2_32.lib largeint.lib ole32.lib
!ELSE
                     rpcrt4.lib WS2_32.lib ole32.lib
!ENDIF
!ENDIF

# -----------------------------------------------------
# JDFWrapperDll (DLL)
# -----------------------------------------------------
!IF ("$(CFG)"=="JDFWrapperDll")
USER_DLL_LINK_LIBS = \
                     JDFToolsDll$(BUILD_EXTENSION).lib \
                     $(XERCES-C_LIBNAME) \
!IF ("$(MSC_VERSION)" != "VC8")
                     largeint.lib ole32.lib oleaut32.lib
!ELSE
                     ole32.lib oleaut32.lib
!ENDIF
!ENDIF

# -----------------------------------------------------
# JDFWrapperCoreDll (DLL)
# -----------------------------------------------------
!IF ("$(CFG)"=="JDFWrapperCoreDll")
USER_DLL_LINK_LIBS = \
                     kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib wsock32.lib \
                     JDFToolsDll$(BUILD_EXTENSION).lib \
                     $(XERCES-C_LIBNAME)
!ENDIF


#USER_EXE_LINK_LIBS = $(MFC_LIBRARIES)                                  # OPT add all additional libraries from other VOBs for a EXE

###-------------------------------------------------------------------###
# name all libs which should not be linked to the dll or exe by default
# if you want to use this macro set USE_PRJRTLIBS=FALSE default is TRUE
# which suppresses the use of the macro NODEFAULTLIBS
###-------------------------------------------------------------------###
#NODEFAULTLIBS = msvcrtd.lib    # OPT select the libs which should not be linked to the dll or exe by default


# **** DO NOT CHANGE NEXT SECTION
!IF (EXIST($(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)BuildFlags.inc))
!INCLUDE $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)BuildFlags.inc
!ELSE
!MESSAGE Error: Unable to include $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)BuildFlags.inc
!ERROR
!ENDIF
# **** END OF SECTION

###-------------------------------------------------------------------###
###                                                                   ###
###   Define some User targets for the dependency list                ###
###   You can use these targets                                       ###
###                                                                   ###
###   USER_CLEAN::                                                    ###
###   USER_LIB_PRE::        USER_LIB_POST::                           ###
###   USER_DLL_PRE::        USER_DLL_POST::                           ###
###   USER_EXE_PRE::        USER_EXE_POST::                           ###
###   USER_MC_PRE::         USER_MC_POST::                            ###
###   USER_DRIVER_PRE::     USER_DRIVER_POST::                        ###
###   USER_TEST::                                                     ###
###   USER_MAC_PRE::        USER_MAC_POST                             ###
###   USER_PRE_BUILD::      USER_POST_BUILD::                         ###
###   USER_JNI_PRE::        USER_JNI_POST::                           ###
###                                                                   ###
###-------------------------------------------------------------------###

#USER_CLEAN::
#   @echo :=====================================================================
#   @echo Executing USER_CLEAN in $(VOB_NAME)$(COMPONENT_NAME)$(SUBCOMPONENT_NAME)
#   @echo :=====================================================================
                                                                      
#USER_EXE_PRE:: $(USER_RES_FILES)

USER_LIB_PRE::
!IF ("$(MAKEINCLUDES)"=="JDFOpenSrc") # if the makefile will be executed in JDFOpenSrc context
!   IF ("$(STL_TYPE)"=="STLPORT")
!      IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC) mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB) > NUL 2>>&1
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb) cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC) > NUL 2>>&1
!      ENDIF
!   ENDIF
!   IF ("$(STL_TYPE)"=="MICROSOFT")
!      IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly
#           @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly
#           @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly
#           @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC) mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)
#           @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB) > NUL 2>>&1
#           @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb) cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC) > NUL 2>>&1
!      ENDIF
!   ENDIF
!   IF ("$(STL_TYPE)"=="DINKUMWARE")
!      IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB) > NUL 2>>&1
!      ELSE
           @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC) mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB) > NUL 2>>&1
           -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb) cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC) > NUL 2>>&1
!      ENDIF
!   ENDIF
!ENDIF    # end of "$(MAKEINCLUDES)"=="JDFOpenSrc"

USER_LIB_POST::
!IF ("$(MAKEINCLUDES)"=="JDFOpenSrc") # if the makefile will be executed in JDFOpenSrc context
!   IF ("$(STL_TYPE)"=="STLPORT")
!      IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB:.lib=.pdb) copy $(VOB_LIB_DIR)$(USER_TARGET_LIB:.lib=.pdb) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb) cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC)
!          ENDIF
!      ENDIF
!   ENDIF
!   IF ("$(STL_TYPE)"=="MICROSOFT")
!      IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
#               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
#               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
#               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB:.lib=.pdb) copy $(VOB_LIB_DIR)$(USER_TARGET_LIB:.lib=.pdb) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC)
!          IFNDEF JDFLIB_NOBINCHECKIN
#               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)
#               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb) cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC)
!          ENDIF
!      ENDIF
!   ENDIF
!   IF ("$(STL_TYPE)"=="DINKUMWARE")
!      IF ("$(CFG)"=="debuglineonlyJDFToolsLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DINKUMWARESTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DINKUMWARESTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE IF ("$(CFG)"=="debuglineonlyJDFWrapperCoreLib")
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DINKUMWARESTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)debuglineonly$(USER_TARGET_LIB)
!          ENDIF
!      ELSE
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB)           copy $(VOB_LIB_DIR)$(USER_TARGET_LIB) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)
           @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_LIB:.lib=.pdb) copy $(VOB_LIB_DIR)$(USER_TARGET_LIB:.lib=.pdb) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC)
!          IFNDEF JDFLIB_NOBINCHECKIN
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DINKUMWARESTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB)
               @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DINKUMWARESTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb) cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_LIB:.lib=.pdb,LC)
!          ENDIF
!      ENDIF
!   ENDIF
!ENDIF    # end of "$(MAKEINCLUDES)"=="JDFOpenSrc"

USER_DLL_PRE::
!IF ("$(MAKEINCLUDES)"=="JDFOpenSrc") # if the makefile will be executed in JDFOpenSrc context
!   IF ("$(STL_TYPE)"=="STLPORT")
      @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC) mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)
      -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL) > NUL 2>>&1
      -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)       cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB) > NUL 2>>&1
      -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb) cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb,LC) > NUL 2>>&1
!   ENDIF
!   IF ("$(STL_TYPE)"=="MICROSOFT")
      @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC) mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)
#      @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL) > NUL 2>>&1
#      @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)       cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB) > NUL 2>>&1
#      @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb) cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb,LC) > NUL 2>>&1
!   ENDIF
!   IF ("$(STL_TYPE)"=="DINKUMWARE")
      @IF NOT EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC) mkdir .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)
      -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)           cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL) > NUL 2>>&1
      -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)       cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB) > NUL 2>>&1
      -@IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb) cleartool co -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb,LC) > NUL 2>>&1
!   ENDIF
!ENDIF    # end of "$(MAKEINCLUDES)"=="JDFOpenSrc"

USER_DLL_POST::
!IF ("$(MAKEINCLUDES)"=="JDFOpenSrc") # if the makefile will be executed in JDFOpenSrc context
!   IF ("$(STL_TYPE)"=="STLPORT")
      @IF EXIST $(VOB_BIN_DIR)$(USER_TARGET_DLL)           copy $(VOB_BIN_DIR)$(USER_TARGET_DLL)           .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)
      @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_DLL_LIB)       copy $(VOB_LIB_DIR)$(USER_TARGET_DLL_LIB)       .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)
      @IF EXIST $(VOB_BIN_DIR)$(USER_TARGET_DLL:.dll=.pdb) copy $(VOB_BIN_DIR)$(USER_TARGET_DLL:.dll=.pdb) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb)
!     IFNDEF JDFLIB_NOBINCHECKIN
          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)
          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)       cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)
          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb) cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb,LC)
!     ENDIF
!   ENDIF
!   IF ("$(STL_TYPE)"=="MICROSOFT")
      @IF EXIST $(VOB_BIN_DIR)$(USER_TARGET_DLL)           copy $(VOB_BIN_DIR)$(USER_TARGET_DLL)             .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)
      @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_DLL_LIB)       copy $(VOB_LIB_DIR)$(USER_TARGET_DLL_LIB)         .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)
      @IF EXIST $(VOB_BIN_DIR)$(USER_TARGET_DLL:.dll=.pdb) copy $(VOB_BIN_DIR)$(USER_TARGET_DLL:.dll=.pdb) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb)
!     IFNDEF JDFLIB_NOBINCHECKIN
#          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)
#          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)       cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)
#          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb) cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_MSSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb,LC)
!     ENDIF
!   ENDIF
!   IF ("$(STL_TYPE)"=="DINKUMWARE")
      @IF EXIST $(VOB_BIN_DIR)$(USER_TARGET_DLL)           copy $(VOB_BIN_DIR)$(USER_TARGET_DLL)           .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)
      @IF EXIST $(VOB_LIB_DIR)$(USER_TARGET_DLL_LIB)       copy $(VOB_LIB_DIR)$(USER_TARGET_DLL_LIB)       .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)
      @IF EXIST $(VOB_BIN_DIR)$(USER_TARGET_DLL:.dll=.pdb) copy $(VOB_BIN_DIR)$(USER_TARGET_DLL:.dll=.pdb) .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb)
!     IFNDEF JDFLIB_NOBINCHECKIN
          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)           cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL)
          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)       cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL_LIB)
          @IF EXIST .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb) cleartool ci -nc .$(VOB_STRUCTURE_BIN)$(DIRSEP)Win32$(DIRSEP)$(MSC_VERSION)_DinkumwareSTL$(DIRSEP)$(BUILD_TYPE,LC)$(USER_TARGET_DLL:.dll=.pdb,LC)
!     ENDIF
!   ENDIF
!ENDIF    # end of "$(MAKEINCLUDES)"=="JDFOpenSrc"

# **** DO NOT CHANGE NEXT SECTION
!IF (EXIST($(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)Dependencies.inc))
!INCLUDE $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)Dependencies.inc
!ELSE
!MESSAGE Error: Unable to include $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)Dependencies.inc
!ERROR
!ENDIF
# **** END OF SECTION

# **** DO NOT CHANGE NEXT SECTION
!IF (EXIST($(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)InferenceRules.inc))
!INCLUDE $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)InferenceRules.inc
!ELSE
!MESSAGE Error: Unable to include $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)InferenceRules.inc
!ERROR
!ENDIF
# **** END OF SECTION

# **** DO NOT CHANGE NEXT SECTION
#!IF (EXIST($(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)GenerateRemoteMakefile.inc))
#!INCLUDE $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)GenerateRemoteMakefile.inc
#!ELSE
#!MESSAGE Error: Unable to include $(GLOBAL_MAKEFILE_INC_PATH)$(DIRSEP)GenerateRemoteMakefile.inc
#!ERROR
#!ENDIF
# **** END OF SECTION
