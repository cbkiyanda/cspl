# CMake config for Histogram examples

#find_package(CSPL REQUIRED)
#include_directories(${CSPL_INCLUDE_DIRS})

add_executable( histogram histogram.c )
target_link_libraries (histogram LINK_PUBLIC CSPL)
target_include_directories( histogram PRIVATE ${INCLUDES} )


