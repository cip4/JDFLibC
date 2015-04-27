cmake_minimum_required (VERSION 2.8)
project (JDFOpenSrc C CXX)

include(utils.cmake)

if(NOT DEFINED RUNTIME_DESTINATION)
	set(RUNTIME_DESTINATION .)
endif()
if(NOT DEFINED LIBRARY_DESTINATION)
	set(LIBRARY_DESTINATION .)
endif()
if(NOT DEFINED ARCHIVE_DESTINATION)
	set(ARCHIVE_DESTINATION lib)
endif()

#############################################

include(${CMAKE_CURRENT_LIST_DIR}/external/Xerces-C/Xerces-C_Import.cmake)

include(${CMAKE_CURRENT_LIST_DIR}/output_folder.cmake)
set(EXECUTABLE_OUTPUT_PATH ${JDF_EXECUTABLE_OUTPUT_PATH})
set(LIBRARY_OUTPUT_PATH ${JDF_LIBRARY_OUTPUT_PATH})
set(CMAKE_DEBUG_POSTFIX ${JDF_CMAKE_DEBUG_POSTFIX})

include_directories("src")

if (WIN32)
    add_definitions(-DWIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /wd4244")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-non-template-friend -fPIC -fvisibility=hidden")
endif()

################## JDFTools ##################

file(GLOB JDFTOOLSLIB_SOURCES 
    "src/jdf/io/*.cpp"
    "src/jdf/lang/*.cpp"
    "src/jdf/mime/*.cpp"
    "src/jdf/net/*.cpp"
    "src/jdf/net/*.c"
#   "src/jdf/png/*.cpp"
    "src/jdf/util/*.cpp"
)

if (WIN32)
    file(GLOB JDFTOOLSLIB_PLATFORM_SOURCES
        "src/jdf/io/Platforms/Win32/*.cpp"
        "src/jdf/net/Platforms/Win32/*.cpp"
        "src/jdf/util/Platforms/Win32/*.cpp"
    )
else()
    file(GLOB JDFTOOLSLIB_PLATFORM_SOURCES
        "src/jdf/io/Platforms/Posix/*.cpp"
        "src/jdf/net/Platforms/Posix/*.cpp"
        "src/jdf/util/Platforms/Posix/PosixPlatformUtils.cpp"	
    )
endif()

add_library(JDFTools SHARED ${JDFTOOLSLIB_SOURCES} ${JDFTOOLSLIB_PLATFORM_SOURCES})
target_link_libraries(JDFTools xerces-c-hd)

if(WIN32)
	target_link_libraries(JDFTools ws2_32 Rpcrt4)
else()
	target_link_libraries(JDFTools pthread curl)
endif()

set_target_properties(
	JDFTools PROPERTIES
	COMPILE_DEFINITIONS JDF_TOOLS
)

if(APPLE)
    find_library(CARBON_LIBRARY Carbon REQUIRED)
    target_link_libraries(JDFTools ${CARBON_LIBRARY})
endif()

################## JDFToolsWrapper ##################
		
set(PRECOMPILED_HEADER ${CMAKE_CURRENT_BINARY_DIR}/precomp_header.h)
	
file(GLOB 
    JDFToolsWrapper_sources 
    "src/jdf/util/myuti.cpp"
    "src/jdf/wrapper/*.cpp"
    "src/jdf/wrapper/AutoJDF/*.cpp"
    "src/jdf/wrappercore/*.cpp"
    )

if(CMAKE_VERSION VERSION_GREATER 2.8.7 AND MSVC)
	# A small hack to speed up compilation in Visual Studio. Split JDFToolsWrapper into more then one
	# project and then compile the projects in parallel (VS2010 seems to be unable to do this on source level)
	set(NUM_SPLITS 8)
	set(JDFToolsWrapper_sources_i 0)
	foreach(CUR ${JDFToolsWrapper_sources})
		math(EXPR JDFToolsWrapper_sources_i2 "(${JDFToolsWrapper_sources_i} % ${NUM_SPLITS}) + 1")
		set(JDFToolsWrapper_sources_split_${JDFToolsWrapper_sources_i2} ${JDFToolsWrapper_sources_split_${JDFToolsWrapper_sources_i2}} ${CUR})
		math(EXPR JDFToolsWrapper_sources_i "${JDFToolsWrapper_sources_i} + 1")
	endforeach()
		
	foreach(CUR RANGE 1 ${NUM_SPLITS})
#		if(NOT EXISTS ${PRECOMPILED_HEADER}_${CUR}.cpp)
#			file(WRITE ${PRECOMPILED_HEADER}_${CUR}.cpp
#				"#include \"${PRECOMPILED_HEADER}\"\n"
#			)
#		endif()
#		
#		set_source_files_properties(${PRECOMPILED_HEADER}_${CUR}.cpp
#			PROPERTIES COMPILE_FLAGS "/Yc${PRECOMPILED_HEADER} /Fp$(TargetDir)/precompiled_header.pch"
#		)
#
#		foreach(CUR2 ${JDFToolsWrapper_sources_split_${CUR}})
#			set_source_files_properties(${CUR2}
#				PROPERTIES COMPILE_FLAGS "/Yu${PRECOMPILED_HEADER} /Fp$(TargetDir)/precompiled_header.pch /FI${PRECOMPILED_HEADER}"
#			)
#		endforeach()		
#
#		list(APPEND JDFToolsWrapper_sources_split_${CUR} ${PRECOMPILED_HEADER}_${CUR}.cpp)
		
		add_library(JDFToolsWrapper_split_object_lib_${CUR} OBJECT ${JDFToolsWrapper_sources_split_${CUR}})
		set_target_properties(
			JDFToolsWrapper_split_object_lib_${CUR} PROPERTIES
			COMPILE_DEFINITIONS JDF_WRAPPERCORE
		)
		set(JDFToolsWrapper_split_all_objects ${JDFToolsWrapper_split_all_objects} $<TARGET_OBJECTS:JDFToolsWrapper_split_object_lib_${CUR}>)
	endforeach()
	
	add_library(JDFToolsWrapper SHARED ${JDFToolsWrapper_split_all_objects})
	target_link_libraries(JDFToolsWrapper JDFTools)
else()
#	list(APPEND JDFToolsWrapper_sources ${PRECOMPILED_HEADER_CPP})
	add_library(JDFToolsWrapper SHARED ${JDFToolsWrapper_sources})
	target_link_libraries(JDFToolsWrapper JDFTools)
	set_target_properties(
		JDFToolsWrapper PROPERTIES
		COMPILE_DEFINITIONS JDF_WRAPPERCORE
	)	
endif()

#if(MSVC)
#	file(GLOB 
#		JDFToolsWrapper_headers
#		"${CMAKE_CURRENT_LIST_DIR}/src/jdf/lang/*.h"
#		)
#	list(REMOVE_ITEM JDFToolsWrapper_headers
#		"${CMAKE_CURRENT_LIST_DIR}/src/jdf/lang/WString.h"
#		"${CMAKE_CURRENT_LIST_DIR}/src/jdf/lang/WStringBase.h"
#	)
#	
#	if(NOT EXISTS ${PRECOMPILED_HEADER})
#		foreach(CUR ${JDFToolsWrapper_headers})
#			file(APPEND ${PRECOMPILED_HEADER}
#				"#include \"${CUR}\"\n"
#			)
#		endforeach()
#		file(APPEND ${PRECOMPILED_HEADER}
#			"#include <Windows.h>\n"
#		)
#	endif()
#endif()

################## tests ##################

file (GLOB TESTS_COMMON_SOURCES
	tests/TestWrapper/MyTime.cpp
    tests/TestWrapper/MyArgs.cpp 
)

add_executable(CheckJDF ${TESTS_COMMON_SOURCES} tests/TestWrapper/CheckJDF.cpp)
target_link_libraries(CheckJDF JDFToolsWrapper)

add_executable(AddJDF ${TESTS_COMMON_SOURCES} tests/TestWrapper/addJDF.cpp)
target_link_libraries(AddJDF JDFToolsWrapper)

add_executable(BookJDF ${TESTS_COMMON_SOURCES} tests/TestWrapper/bookJDF.cpp)
target_link_libraries(BookJDF JDFToolsWrapper)

add_executable(MergeJDF ${TESTS_COMMON_SOURCES} tests/TestWrapper/mergeJDF.cpp)
target_link_libraries(MergeJDF JDFToolsWrapper)

add_executable(SpawnJDF ${TESTS_COMMON_SOURCES} tests/TestWrapper/SpawnJDF.cpp)
target_link_libraries(SpawnJDF JDFToolsWrapper)

add_executable(SpecJDF ${TESTS_COMMON_SOURCES} tests/TestWrapper/SpecJDF.cpp tests/TestWrapper/JDFSimulator.cpp)
target_link_libraries(SpecJDF JDFToolsWrapper)

hd_install_target(JDFTools)
hd_install_target(JDFToolsWrapper)
