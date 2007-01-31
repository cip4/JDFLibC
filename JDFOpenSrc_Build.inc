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

JDFOPENSRC_VER       = 2.1.3BLD086
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
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)_MSSTL\debuglineonly"
!ELIF ("$(TOOL_STLPORT)"      =="TRUE")
!ELIF ("$(TOOL_DINKUMWARESTL)"=="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)_DinkumwareSTL\debug"
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)\debuglineonly"
!ENDIF                          # !IF   ("$(TOOL_MICROSOFTSTL) "=="TRUE")

!ELIF ("$(BUILD_TYPE)" == "RELEASEEXTRA")
#releaseextra build: lib names for libraries
JDFTOOLSLIB             = JDFToolsLib.lib
JDFWRAPPERCORELIB       = JDFWrapperCoreLib.lib
JDFWRAPPERLIB           = JDFWrapperLib.lib
#releaseextra build: lib names for dlls
JDFTOOLSDLLLIB          = JDFToolsDll.lib
JDFWRAPPERCOREDLLLIB    = JDFWrapperCoreDll.lib
JDFWRAPPERDLLLIB        = JDFWrapperDll.lib
!IF   ("$(TOOL_MICROSOFTSTL)" =="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)_MSSTL\releaseextra"
!ELIF ("$(TOOL_STLPORT)"      =="TRUE")
!ELIF ("$(TOOL_DINKUMWARESTL)"=="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)_DinkumwareSTL\releaseextra"
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)\releaseextra"
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
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)_MSSTL\release"
!ELIF ("$(TOOL_STLPORT)"      =="TRUE")
!ELIF ("$(TOOL_DINKUMWARESTL)"=="TRUE")
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)_DinkumwareSTL\release"
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\$(MSC_VERSION)\release"
!ENDIF
!ENDIF

INCLUDE_PATH = $(INCLUDE_PATH) $(JDFOPENSRC_INC_PATH)
LIBRARY_PATH = $(LIBRARY_PATH) $(JDFOPENSRC_LIBPATH)

# Expand the path environment variable
# Don't add a colon to the equal sign (like PATH:= ...)
# PATH = $(JDFOPENSRC_ROOT)\bin;$(PATH)
