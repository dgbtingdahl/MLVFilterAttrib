#_______________________Pmake___________________________________________________
#
#	Makefile : 	Tutorial plugin
# 	Jan 2012	A.H. Bril
#	RCS :		$Id: CMakeLists.txt 29755 2013-05-13 11:30:34Z ranojay.sen@dgbes.com $
#_______________________________________________________________________________


cmake_minimum_required (VERSION 2.6)
project(OpendTect_MLV_Filter_Plugin)

set ( OD_SUBSYSTEM "wgm_plugin" )
set ( OpendTect_DIR "" CACHE PATH "OpendTect directory" )


#Setup output directory
option ( OD_BUILD_LOCAL "Build in local directory" ON )

#Find OpendTect
list(APPEND CMAKE_MODULE_PATH "${OpendTect_DIR}/CMakeModules")
find_package( OpendTect )


#Setup the modules
set ( PLUGINS MLVFilterAttrib uiMLVFilterAttrib )
OD_ADD_MODULES( plugins ${PLUGINS} )

#Add the plugins
foreach ( plugin ${PLUGINS} )
    list( APPEND RUNTIMEPATH ${OD_${plugin}_RUNTIMEPATH} )
endforeach()

list ( APPEND RUNTIMEPATH ${OD_EXEC_OUTPUT_PATH} )
list ( REMOVE_DUPLICATES RUNTIMEPATH )

if( OD_CREATE_LAUNCHERS )
    set ( OD_LAUNCHERS od_main od_process_attrib od_process_volume )
    foreach ( LAUNCHER ${OD_LAUNCHERS} )
	add_custom_target( ${LAUNCHER} ALL )
	foreach(CONFIG ${CMAKE_CONFIGURATION_TYPES})
	    set_target_properties( ${LAUNCHER}
		    PROPERTIES
		    LOCATION_${CONFIG}
	${OpendTect_DIR}/${OD_EXEC_OUTPUT_RELPATH}/${CONFIG}/${LAUNCHER}${OD_EXECUTABLE_EXTENSION} )
	endforeach()

	create_target_launcher( ${LAUNCHER}
	    RUNTIME_LIBRARY_DIRS
	 ${OpendTect_DIR}/${OD_EXEC_OUTPUT_RELPATH}
	 ${OD_BINARY_BASEDIR}/${OD_EXEC_OUTPUT_RELPATH} 
	    ENVIRONMENT
	    DTECT_APPL=${OpendTect_DIR}
	    WORK=${OpendTect_DIR} )
    endforeach()
endif( OD_CREATE_LAUNCHERS )

OD_WRITE_ALOFILES( ${CMAKE_CURRENT_BINARY_DIR} )
