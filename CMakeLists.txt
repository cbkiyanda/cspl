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
add_subdirectory (CSPL/Histogram)
add_subdirectory (CSPL/Regression)

set (CSPL_TARGET_OBJECTS
    $<TARGET_OBJECTS:CSPL_Stats>
    $<TARGET_OBJECTS:CSPL_Sort>	
    $<TARGET_OBJECTS:CSPL_Array>
    $<TARGET_OBJECTS:CSPL_Special>
    $<TARGET_OBJECTS:CSPL_Histogram>
    $<TARGET_OBJECTS:CSPL_Regression>
    )
         
add_library (CSPL ${CSPL_TARGET_OBJECTS})
install( TARGETS CSPL
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  )

find_library( LIBM m )
if( LIBM )
  target_link_libraries( CSPL ${LIBM} )
endif()

find_program(CTYPESGEN_FOUND ctypesgen.py)
if(NOT CTYPESGEN_FOUND)
  message(WARNING "Could not find ctypesgen.py command, python cannot be build")
  # put code here to build the python
endif(NOT CTYPESGEN_FOUND)

if( NOT BUILD_TESTS )
  set( BUILD_TESTS False
    CACHE BOOL "Whether to build the tests" )
endif()

if(BUILD_TESTS)
  enable_testing()
  add_subdirectory (Tests)
  add_executable( size size.c )
  add_test( size-test size )
endif(BUILD_TESTS)

if( NOT BUILD_EXAMPLES )
  set( BUILD_EXAMPLES FALSE
    CACHE BOOL "Whether to build the examples" )
endif()

if(BUILD_EXAMPLES)
  add_subdirectory(Examples)
endif(BUILD_EXAMPLES)
