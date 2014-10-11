# CMake file for the examples, enabled via BUILD_EXAMPLES=ON at the main level

set( INCLUDES ../../CSPL/Sort ../../CSPL/Stats ../../CSPL/Array ../../CSPL/Special ../../CSPL )

add_subdirectory(Array)
add_subdirectory(Sort)
add_subdirectory(Special)
add_subdirectory(Stats)
add_subdirectory(CSPLA)

