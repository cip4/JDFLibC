
include(${CMAKE_CURRENT_LIST_DIR}/output_folder.cmake)

# Create imported target JDFTools
add_library(JDFTools SHARED IMPORTED)

# Create imported target JDFToolsWrapper
add_library(JDFToolsWrapper SHARED IMPORTED)

if(WIN32)
	# Import target "JDFTools" for configuration "Debug"
	set_property(TARGET JDFTools APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
	set_target_properties(JDFTools PROPERTIES
	  IMPORTED_IMPLIB_DEBUG "${JDF_LIBRARY_OUTPUT_PATH}/Debug/JDFTools_D.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "xerces-c-hd;ws2_32;Rpcrt4"
	  IMPORTED_LOCATION_DEBUG "${JDF_EXECUTABLE_OUTPUT_PATH}/Debug/JDFTools_D.dll"
	  )

	# Import target "JDFToolsWrapper" for configuration "Debug"
	set_property(TARGET JDFToolsWrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
	set_target_properties(JDFToolsWrapper PROPERTIES
	  IMPORTED_IMPLIB_DEBUG "${JDF_LIBRARY_OUTPUT_PATH}/Debug/JDFToolsWrapper_D.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_DEBUG "JDFTools"
	  IMPORTED_LOCATION_DEBUG "${JDF_EXECUTABLE_OUTPUT_PATH}/Debug/JDFToolsWrapper_D.dll"
	  )

	# Import target "JDFTools" for configuration "Release"
	set_property(TARGET JDFTools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
	set_target_properties(JDFTools PROPERTIES
	  IMPORTED_IMPLIB_RELEASE "${JDF_LIBRARY_OUTPUT_PATH}/Release/JDFTools.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "xerces-c-hd;ws2_32;Rpcrt4"
	  IMPORTED_LOCATION_RELEASE "${JDF_EXECUTABLE_OUTPUT_PATH}/Release/JDFTools.dll"
	  )

	# Import target "JDFToolsWrapper" for configuration "Release"
	set_property(TARGET JDFToolsWrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
	set_target_properties(JDFToolsWrapper PROPERTIES
	  IMPORTED_IMPLIB_RELEASE "${JDF_LIBRARY_OUTPUT_PATH}/Release/JDFToolsWrapper.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_RELEASE "JDFTools"
	  IMPORTED_LOCATION_RELEASE "${JDF_EXECUTABLE_OUTPUT_PATH}/Release/JDFToolsWrapper.dll"
	  )

	# Import target "JDFTools" for configuration "MinSizeRel"
	set_property(TARGET JDFTools APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
	set_target_properties(JDFTools PROPERTIES
	  IMPORTED_IMPLIB_MINSIZEREL "${JDF_LIBRARY_OUTPUT_PATH}/MinSizeRel/JDFTools.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "xerces-c-hd;ws2_32;Rpcrt4"
	  IMPORTED_LOCATION_MINSIZEREL "${JDF_EXECUTABLE_OUTPUT_PATH}/MinSizeRel/JDFTools.dll"
	  )

	# Import target "JDFToolsWrapper" for configuration "MinSizeRel"
	set_property(TARGET JDFToolsWrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
	set_target_properties(JDFToolsWrapper PROPERTIES
	  IMPORTED_IMPLIB_MINSIZEREL "${JDF_LIBRARY_OUTPUT_PATH}/MinSizeRel/JDFToolsWrapper.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_MINSIZEREL "JDFTools"
	  IMPORTED_LOCATION_MINSIZEREL "${JDF_EXECUTABLE_OUTPUT_PATH}/MinSizeRel/JDFToolsWrapper.dll"
	  )

	# Import target "JDFTools" for configuration "RelWithDebInfo"
	set_property(TARGET JDFTools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
	set_target_properties(JDFTools PROPERTIES
	  IMPORTED_IMPLIB_RELWITHDEBINFO "${JDF_LIBRARY_OUTPUT_PATH}/RelWithDebInfo/JDFTools.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "xerces-c-hd;ws2_32;Rpcrt4"
	  IMPORTED_LOCATION_RELWITHDEBINFO "${JDF_EXECUTABLE_OUTPUT_PATH}/RelWithDebInfo/JDFTools.dll"
	  )

	# Import target "JDFToolsWrapper" for configuration "RelWithDebInfo"
	set_property(TARGET JDFToolsWrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
	set_target_properties(JDFToolsWrapper PROPERTIES
	  IMPORTED_IMPLIB_RELWITHDEBINFO "${JDF_LIBRARY_OUTPUT_PATH}/RelWithDebInfo/JDFToolsWrapper.lib"
	  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "JDFTools"
	  IMPORTED_LOCATION_RELWITHDEBINFO "${JDF_EXECUTABLE_OUTPUT_PATH}/RelWithDebInfo/JDFToolsWrapper.dll"
	  )
else()	
	# Import target "JDFTools" for configuration ""
	SET_PROPERTY(TARGET JDFTools APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
	SET_TARGET_PROPERTIES(JDFTools PROPERTIES
	  IMPORTED_LINK_INTERFACE_LIBRARIES "xerces-c-hd;pthread;curl"
	  IMPORTED_LOCATION "${JDF_EXECUTABLE_OUTPUT_PATH}/libJDFTools.so"
	  IMPORTED_SONAME "libJDFTools.so"
	  )
	
	# Import target "JDFToolsWrapper" for configuration ""
	SET_PROPERTY(TARGET JDFToolsWrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
	SET_TARGET_PROPERTIES(JDFToolsWrapper PROPERTIES
	  IMPORTED_LINK_INTERFACE_LIBRARIES "JDFTools"
	  IMPORTED_LOCATION "${JDF_EXECUTABLE_OUTPUT_PATH}/libJDFToolsWrapper.so"
	  IMPORTED_SONAME "libJDFToolsWrapper.so"
	  )
endif()

include_directories(
	${CMAKE_CURRENT_LIST_DIR}/src
)

hd_install_imported_target(JDFTools)
hd_install_imported_target(JDFToolsWrapper)