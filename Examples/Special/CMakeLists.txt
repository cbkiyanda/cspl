# CMake config for Special examples

add_executable( erf erf.c )
target_link_libraries (erf LINK_PUBLIC CSPL)
target_include_directories( erf PRIVATE ${INCLUDES} )
