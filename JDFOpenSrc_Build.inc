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
JDFOPENSRC_ROOT = \cmpINFRA_CommonParsers\JDFOpenSrc
!ENDIF

JDFOPENSRC_VOB  = \cmpINFRA_CommonParsers

JDFOPENSRC_VER       = 0.2
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
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\VC6\debuglineonly"
JDFTOOLSLIB          = JDFToolsLib_D.lib
JDFWRAPPERCORELIB    = JDFWrapperCoreLib_D.lib
JDFWRAPPERLIB        = JDFWrapperLib_D.lib
!ELSE
JDFOPENSRC_LIBPATH   = /LIBPATH:"$(JDFOPENSRC_ROOT)\bin\Win32\VC6\release"
JDFTOOLSLIB          = JDFToolsLib.lib
JDFWRAPPERCORELIB    = JDFWrapperCoreLib.lib
JDFWRAPPERLIB        = JDFWrapperLib.lib
!ENDIF

INCLUDE_PATH = $(INCLUDE_PATH) $(JDFOPENSRC_INC_PATH)
LIBRARY_PATH = $(LIBRARY_PATH) $(JDFOPENSRC_LIBPATH)

# Expand the path environment variable
# Don't add a colon to the equal sign (like PATH:= ...)
# PATH = $(JDFOPENSRC_ROOT)\bin;$(PATH)
