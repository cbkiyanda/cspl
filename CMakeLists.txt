cmake_minimum_required(VERSION 2.8.3)
#cmake_policy(SET CMP0002 NEW)
if(POLICY CMP0042)	
  cmake_policy(SET CMP0042 NEW) # remove if CMake >= 2.8.11 required
endif()

project(CSPL)

include( FindDoxygen )
if( DOXYGEN_FOUND )
  add_custom_target( doc ${DOXYGEN_EXECUTABLE} )
endif()

add_subdirectory (CSPL)
add_subdirectory (CSPL/Stats)
add_subdirectory (CSPL/Sort)
add_subdirectory (CSPL/Array)
add_subdirectory (CSPL/Special)

set (CSPL_TARGET_OBJECTS
    $<TARGET_OBJECTS:CSPL_Stats>
    $<TARGET_OBJECTS:CSPL_Sort>	
    $<TARGET_OBJECTS:CSPL_Array>
    $<TARGET_OBJECTS:CSPL_Special>	)
         
add_library (CSPL ${CSPL_TARGET_OBJECTS})

find_program(CTYPESGEN_LOCATION ctypesgen.py)
if(NOT CTYPESGEN_LOCATION)
  message(WARNING "Could not find ctypesgen.py command, python cannot be build")
  # put code here to build the python
endif(NOT CTYPESGEN_LOCATION)

enable_testing()

add_executable( size size.c )
add_test( size-test size )
