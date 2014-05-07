!IFDEF JDFOPENSRC_ROOT
!MESSAGE ======================================================================
!MESSAGE
!MESSAGE You are redirecting the JDFOPENSRC_ROOT Environment variable to:
!MESSAGE $(JDFOPENSRC_ROOT)
!MESSAGE
!MESSAGE >>>>>>>>>>>>         This can falsify your build.        <<<<<<<<<<<<<
!MESSAGE
!MESSAGE ======================================================================
!ELSE
JDFOPENSRC_ROOT = $(DIRROOT)$(DIRSEP)cmpINFRA_CommonParsers$(DIRSEP)JDFOpenSrc
!ENDIF

#---
# Compatibility with different Visual Studio Versions
# This macro should be set in DevStudio_Build.inc
#---
!IFNDEF MSC_VERSION
MSC_VERSION = VC6
!ENDIF

JDFOPENSRC_VOB  = \cmpINFRA_CommonParsers

JDFOPENSRC_VER       = 2.1.4BLD126
JDFOPENSRC_INCLUDE   = $(JDFOPENSRC_ROOT)\src
JDFOPENSRC_INC_PATH  = /I "$(JDFOPENSRC_ROOT)\src" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\io" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\lang" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\mime" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\net" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\png" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\util" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\wrapper" \
                       /I "$(JDFOPENSRC_ROOT)\src\jdf\wrappercore"

#
# ADDITIONAL FOLDER WHICH DEPENDS ON "PLATFORM"
#
!IF ("$(PLATFORM)"=="WIN64")
JDFOPENSRC_WIN_DIR = Win64
!ELSE
JDFOPENSRC_WIN_DIR = Win32
!ENDIF

#
# ADDITIONAL PATHES WHICH ARE DEPENDENT FROM "BUILD_TYPE"
#
!IF ("$(BUILD_TYPE)" == "DEBUG")
#debug build: lib names for libraries
JDFTOOLSLIB             = JDFToolsLib_D.lib
JDFWRAPPERCORELIB       = JDFWrapperCoreLib_D.lib
JDFWRAPPERLIB           = JDFWrapperLib_D.lib
#debug build: lib names for dlls
JDFTOOLSDLLLIB          = JDFToolsDll_D.lib
JDFWRAPPERCOREDLLLIB    = JDFWrapperCoreDll_D.lib
JDFWRAPPERDLLLIB        = JDFWrapperDll_D.lib
!IF   ("$(TOOL_MICROSOFTSTL)" =="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\debug"
!ELSEIF ("$(TOOL_STLPORT)"      =="TRUE")
!    MESSAGE Error  : The STL type 'STLPORT' is not supported for tool 'TOOL_STLPORT'
!ELSEIF ("$(TOOL_DINKUMWARESTL)"=="TRUE")
!    MESSAGE Error  : The STL type 'DINKUMWARE' is not supported for tool 'TOOL_DINKUMWARESTL'
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\debug"
!ENDIF                          # !IF   ("$(TOOL_MICROSOFTSTL) "=="TRUE")

!ELSEIF ("$(BUILD_TYPE)" == "RELEASEEXTRA")
#releaseextra build: lib names for libraries
JDFTOOLSLIB             = JDFToolsLib.lib
JDFWRAPPERCORELIB       = JDFWrapperCoreLib.lib
JDFWRAPPERLIB           = JDFWrapperLib.lib
#releaseextra build: lib names for dlls
JDFTOOLSDLLLIB          = JDFToolsDll.lib
JDFWRAPPERCOREDLLLIB    = JDFWrapperCoreDll.lib
JDFWRAPPERDLLLIB        = JDFWrapperDll.lib
!IF   ("$(TOOL_MICROSOFTSTL)" =="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\releaseextra"
!ELSEIF ("$(TOOL_STLPORT)"      =="TRUE")
!    MESSAGE Error  : The STL type 'STLPORT' is not supported for tool 'TOOL_STLPORT'
!ELSEIF ("$(TOOL_DINKUMWARESTL)"=="TRUE")
!    MESSAGE Error  : The STL type 'DINKUMWARE' is not supported for tool 'TOOL_DINKUMWARESTL'
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\releaseextra"
!ENDIF

!ELSE
# release build: lib names for libraries
JDFTOOLSLIB             = JDFToolsLib.lib
JDFWRAPPERCORELIB       = JDFWrapperCoreLib.lib
JDFWRAPPERLIB           = JDFWrapperLib.lib
# release build: lib names for dlls
JDFTOOLSDLLLIB          = JDFToolsDll.lib
JDFWRAPPERCOREDLLLIB    = JDFWrapperCoreDll.lib
JDFWRAPPERDLLLIB        = JDFWrapperDll.lib
!IF   ("$(TOOL_MICROSOFTSTL)" =="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\release"
!ELSEIF ("$(TOOL_STLPORT)"      =="TRUE")
!    MESSAGE Error  : The STL type 'STLPORT' is not supported for tool 'TOOL_STLPORT'
!ELSEIF ("$(TOOL_DINKUMWARESTL)"=="TRUE")
!    MESSAGE Error  : The STL type 'DINKUMWARE' is not supported for tool 'TOOL_DINKUMWARESTL'
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\release"
!ENDIF
!ENDIF

!IF ("$(JDFLIB_TYPE)" == "DLL")
     JDF_COMPILER_DEFINES = 
     JDF_LIBRARIES = $(JDFTOOLSDLLLIB) $(JDFWRAPPERCOREDLLLIB) $(JDFWRAPPERDLLLIB)
!ELSE
     JDF_COMPILER_DEFINES = /D"JDF_TOOLS_LIB" /D"JDF_WRAPPERCORE_LIB"
     JDF_LIBRARIES = $(JDFTOOLSLIB) $(JDFWRAPPERCORELIB) $(JDFWRAPPERLIB)
!ENDIF

# START-Section needed for e.g. C-Unit tests (only support for VC8) Section
JDFOPENSRC_BIN_DIR  = $(JDFOPENSRC_ROOT)\bin\$(JDFOPENSRC_WIN_DIR)\$(MSC_VERSION)\$(BUILD_TYPE,LC)
!IF ((("$(MSC_VERSION)" == "") || ("$(MSC_VERSION)" == "VC7")) && ("$(BUILD_CUNIT_EXE)" == "TRUE")) 
!       MESSAGE WARNING JDFOpenSrc_Build.inc / $(JDFOPENSRC_VER): DLL definition`s for Visual Studio version`s older than Visual Studio 2005 (VC8) are not supported (found: MSC_VERSION=$(MSC_VERSION))
!ELSEIF ("$(MSC_VERSION)" == "VC8")
!   IF ("$(BUILD_TYPE,UC)" == "DEBUG")
        JDFOPENSRC-TOOL_DLLNAME         = JDFToolsDll2.1_MX2.6.0_VC8_D.dll
        JDFOPENSRC-WRAPCORE_DLLNAME     = JDFWrapperCoreDll2.1_MX2.6.0_VC8_D.dll
        JDFOPENSRC-WRAP_DLLNAME         = JDFWrapperDll2.1_MX2.6.0_VC8_D.dll
        JDFOPENSRC-TOOL_PDBNAME         = $(JDFOPENSRC-TOOL_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAPCORE_PDBNAME     = $(JDFOPENSRC-WRAPCORE_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAP_PDBNAME         = $(JDFOPENSRC-WRAP_DLLNAME,.dll=.pdb)
!   ELSEIF ("$(BUILD_TYPE,UC)" == "RELEASEEXTRA")
        JDFOPENSRC-TOOL_DLLNAME         = JDFToolsDll2.1_MX2.6.0_VC8.dll
        JDFOPENSRC-WRAPCORE_DLLNAME     = JDFWrapperCoreDll2.1_MX2.6.0_VC8.dll
        JDFOPENSRC-WRAP_DLLNAME         = JDFWrapperDll2.1_MX2.6.0_VC8.dll
        JDFOPENSRC-TOOL_PDBNAME         = $(JDFOPENSRC-TOOL_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAPCORE_PDBNAME     = $(JDFOPENSRC-WRAPCORE_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAP_PDBNAME         = $(JDFOPENSRC-WRAP_DLLNAME,.dll=.pdb)
!   ELSE
        JDFOPENSRC-TOOL_DLLNAME         = JDFToolsDll2.1_MX2.6.0_VC8.dll
        JDFOPENSRC-WRAPCORE_DLLNAME     = JDFWrapperCoreDll2.1_MX2.6.0_VC8.dll
        JDFOPENSRC-WRAP_DLLNAME         = JDFWrapperDll2.1_MX2.6.0_VC8.dll
!   ENDIF
!ELSE
!   IF ("$(BUILD_TYPE,UC)" == "DEBUG")
        JDFOPENSRC-TOOL_DLLNAME         = JDFToolsDll2.1_MX3.1.1_D.dll
        JDFOPENSRC-WRAPCORE_DLLNAME     = JDFWrapperCoreDll2.1_MX3.1.1_D.dll
        JDFOPENSRC-WRAP_DLLNAME         = JDFWrapperDll2.1_MX3.1.1_D.dll
        JDFOPENSRC-TOOL_PDBNAME         = $(JDFOPENSRC-TOOL_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAPCORE_PDBNAME     = $(JDFOPENSRC-WRAPCORE_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAP_PDBNAME         = $(JDFOPENSRC-WRAP_DLLNAME,.dll=.pdb)
!   ELSEIF ("$(BUILD_TYPE,UC)" == "RELEASEEXTRA")
        JDFOPENSRC-TOOL_DLLNAME         = JDFToolsDll2.1_MX3.1.1.dll
        JDFOPENSRC-WRAPCORE_DLLNAME     = JDFWrapperCoreDll2.1_MX3.1.1.dll
        JDFOPENSRC-WRAP_DLLNAME         = JDFWrapperDll2.1_MX3.1.1.dll
        JDFOPENSRC-TOOL_PDBNAME         = $(JDFOPENSRC-TOOL_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAPCORE_PDBNAME     = $(JDFOPENSRC-WRAPCORE_DLLNAME,.dll=.pdb)
        JDFOPENSRC-WRAP_PDBNAME         = $(JDFOPENSRC-WRAP_DLLNAME,.dll=.pdb)
!   ELSE
        JDFOPENSRC-TOOL_DLLNAME         = JDFToolsDll2.1_MX3.1.1.dll
        JDFOPENSRC-WRAPCORE_DLLNAME     = JDFWrapperCoreDll2.1_MX3.1.1.dll
        JDFOPENSRC-WRAP_DLLNAME         = JDFWrapperDll2.1_MX3.1.1.dll
!   ENDIF
!ENDIF

!IF ("$(BUILD_TYPE,UC)" != "RELEASE")
    JDFOPENSRC_BINARY = \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-TOOL_DLLNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-WRAPCORE_DLLNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-WRAP_DLLNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-TOOL_PDBNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-WRAPCORE_PDBNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-WRAP_PDBNAME)
!ELSE                           
    JDFOPENSRC_BINARY = \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-TOOL_DLLNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-WRAPCORE_DLLNAME) \
        $(JDFOPENSRC_BIN_DIR)\$(JDFOPENSRC-WRAP_DLLNAME)
!ENDIF

BINARY_LIST  = $(BINARY_LIST) $(JDFOPENSRC_BINARY)
# END-Section needed for e.g. C-Unit tests (only support for VC8)

INCLUDE_PATH = $(INCLUDE_PATH) $(JDFOPENSRC_INC_PATH)
LIBRARY_PATH = $(LIBRARY_PATH) $(JDFOPENSRC_LIBPATH)

# Expand the path environment variable
# Don't add a colon to the equal sign (like PATH:= ...)
# PATH = $(JDFOPENSRC_ROOT)\bin;$(PATH)
