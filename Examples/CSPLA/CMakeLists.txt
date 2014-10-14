# CMake config for CSPLA examples

#find_package(CSPL REQUIRED)
#include_directories(${CSPL_INCLUDE_DIRS})

add_executable( CSPLA_ex1 CSPLA_ex1.c )
target_link_libraries (CSPLA_ex1 LINK_PUBLIC CSPL)
target_include_directories( CSPLA_ex1 PRIVATE ${INCLUDES} )

add_executable( CSPLA_multiD CSPLA_multiD.c )
target_link_libraries (CSPLA_multiD LINK_PUBLIC CSPL)
target_include_directories( CSPLA_multiD PRIVATE ${INCLUDES} )


