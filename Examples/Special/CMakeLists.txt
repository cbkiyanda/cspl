
# CMake config for Special examples

include_directories(../../CSPL/Stats, ../../CSPL/Array, ../../CSPL/Special, ../../CSPL )


add_executable( erf erf.c )
target_link_libraries (erf LINK_PUBLIC CSPL)

