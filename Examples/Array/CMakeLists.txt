
# CMake config for Array examples

include_directories(../../CSPL/Stats, ../../CSPL/Array, ../../CSPL/Special, ../../CSPL )

#find_package(CSPL REQUIRED)
#include_directories(${CSPL_INCLUDE_DIRS})


add_executable( Array1 Array1.c )
target_link_libraries (Array1 LINK_PUBLIC CSPL)

add_executable( Array2 Array2.c )
target_link_libraries (Array1 LINK_PUBLIC CSPL)

