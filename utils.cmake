
macro(check_gcc_version REQUIRED_VERSION)
	if(CMAKE_COMPILER_IS_GNUCC)
		# For cmake < 2.8.8
		if(NOT DEFINED CMAKE_C_COMPILER_VERSION)
			execute_process(
				COMMAND ${CMAKE_C_COMPILER} -dumpversion
				OUTPUT_VARIABLE CMAKE_C_COMPILER_VERSION
			)
		endif()
		if((CMAKE_C_COMPILER_VERSION VERSION_GREATER ${REQUIRED_VERSION}.9999999) OR (CMAKE_C_COMPILER_VERSION VERSION_LESS ${REQUIRED_VERSION}))
			message(SEND_ERROR "Only gcc ${REQUIRED_VERSION} is supported")
		endif()
	endif()
	if(CMAKE_COMPILER_IS_GNUCXX)
		# For cmake < 2.8.8
		if(NOT DEFINED CMAKE_CXX_COMPILER_VERSION)
			execute_process(
				COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
				OUTPUT_VARIABLE CMAKE_CXX_COMPILER_VERSION
			)
		endif()
		if((CMAKE_CXX_COMPILER_VERSION VERSION_GREATER ${REQUIRED_VERSION}.9999999) OR (CMAKE_CXX_COMPILER_VERSION VERSION_LESS ${REQUIRED_VERSION}))
			message(SEND_ERROR "Only g++ ${REQUIRED_VERSION} is supported")
		endif()
	endif()
endmacro()

macro(find_boost REQUIRED_VERSION)
	set(BOOST_COMPONENTS ${ARGN})

	# We have to use Boost 1.42 because Adobe is using this version. We can't upgrade.
	if(WIN32)
		set(BOOST_ROOT ${VOBS_ROOT}/devTools_Base/common/boost)
		find_package(Boost ${REQUIRED_VERSION} EXACT)
		
		if(CMAKE_SIZEOF_VOID_P EQUAL 8)
			set(BOOST_X64_SUFFIX X64)
		endif()
	
		set(BOOST_BASE_LIBRARY_DIR_RELEASE ${BOOST_ROOT}/lib/VC10_HD/release${BOOST_X64_SUFFIX})
		set(BOOST_BASE_LIBRARY_DIR_DEBUG ${BOOST_ROOT}/lib/VC10_HD/debug${BOOST_X64_SUFFIX})
		
		# We support only vc10 for now
		foreach(CUR ${BOOST_COMPONENTS})
			set(Boost_LIBRARIES ${Boost_LIBRARIES} optimized ${BOOST_BASE_LIBRARY_DIR_RELEASE}/libboost_${CUR}-vc100-mt.lib)	
			set(Boost_LIBRARIES ${Boost_LIBRARIES} debug     ${BOOST_BASE_LIBRARY_DIR_DEBUG}/libboost_${CUR}-vc100-mt-gd.lib)
		endforeach()	
	else()
		set(Boost_USE_STATIC_LIBS ON)
		#set(BOOST_ROOT ${VOBS_ROOT}/devTools_Base/common/boost)
		#find_package(Boost ${REQUIRED_VERSION} EXACT COMPONENTS ${BOOST_COMPONENTS____NOT_USED_FOR_NOW_THANKS_TO_ADOBE} REQUIRED)
		find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
		
		# We currently don't link to boost, because Adobe is exporting some parts of boost in libACR.so
		#set(Boost_LIBRARIES)	
	endif()
	
	#message("BOOST_ROOT: ${BOOST_ROOT}")
	#message("Boost_LIBRARIES_RELEASE: ${Boost_LIBRARIES_RELEASE}")
	#message("Boost_LIBRARIES_DEBUG: ${Boost_LIBRARIES_DEBUG}")
	
	include_directories(${Boost_INCLUDE_DIRS})
endmacro()

macro(hd_install_target TARGET)
	install(
		TARGETS ${TARGET}
		RUNTIME DESTINATION ${RUNTIME_DESTINATION}
		ARCHIVE DESTINATION ${ARCHIVE_DESTINATION}
		LIBRARY DESTINATION ${LIBRARY_DESTINATION}
	)
endmacro()

macro(hd_install_normal_or_imported_target_build_type TARGET _BUILD_TYPE FAIL_IF_NOT_FOUND)
	get_target_property(TMP_PROP ${TARGET} IMPORTED)
	if(TMP_PROP)
		hd_install_imported_target_build_type(${TARGET} "${_BUILD_TYPE}" ${FAIL_IF_NOT_FOUND})
	else()
		hd_install_target(${TARGET})
	endif()
endmacro()

macro(hd_install_imported_target_build_type TARGET _BUILD_TYPE _FAIL_IF_NOT_FOUND)
	string(TOLOWER ${_FAIL_IF_NOT_FOUND} FAIL_IF_NOT_FOUND)
	
	set(BUILD_TYPE ${_BUILD_TYPE})
	if(NOT "${BUILD_TYPE}" STREQUAL "")
		set(BUILD_TYPE "_${BUILD_TYPE}")
	endif()
	
	get_target_property(TMP_PROP ${TARGET} IMPORTED_LOCATION${BUILD_TYPE})
	if(NOT TMP_PROP STREQUAL "TMP_PROP-NOTFOUND")
		install(
			FILES ${TMP_PROP}
			DESTINATION ${LIBRARY_DESTINATION}
		)
		get_target_property(TMP_PROP ${TARGET} IMPORTED_LINK_DEPENDENT_LIBRARIES)
		if(NOT TMP_PROP STREQUAL "TMP_PROP-NOTFOUND")
			foreach(CUR ${TMP_PROP})
				if(TARGET ${CUR})
					hd_install_normal_or_imported_target_build_type(${CUR} "${_BUILD_TYPE}" ${_FAIL_IF_NOT_FOUND})
				else()
					if(UNIX)
						install(
							FILES ${CUR}
							DESTINATION ${LIBRARY_DESTINATION}
						)
					else()
						install(
							FILES ${CUR}
							DESTINATION ${RUNTIME_DESTINATION}
						)
					endif()
				endif()
			endforeach()
		endif()
	elseif(FAIL_IF_NOT_FOUND OR FAIL_IF_NOT_FOUND STREQUAL "true")
		message(SEND_ERROR "Failed to install imported target ${TARGET} with build type ${BUILD_TYPE}")
	endif()
endmacro()

macro(hd_install_imported_target TARGET)
	hd_install_imported_target_build_type(${TARGET} "" false)
	hd_install_imported_target_build_type(${TARGET} DEBUG false)
	hd_install_imported_target_build_type(${TARGET} RELEASE false)
endmacro()
