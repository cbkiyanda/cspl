# CMake config for Array examples

#find_package(CSPL REQUIRED)
#include_directories(${CSPL_INCLUDE_DIRS})

add_executable( regression1 regression1.c )
target_link_libraries (regression1 LINK_PUBLIC CSPL)
target_include_directories( regression1 PRIVATE ${INCLUDES} )

