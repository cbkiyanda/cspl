
# CMake config for Stats examples

include_directories(../../CSPL/Stats, ../../CSPL/Array, ../../CSPL/Special, ../../CSPL )

add_executable( cdf cdf.c )
target_link_libraries (cdf LINK_PUBLIC CSPL)


add_executable( descriptive descriptive.c )
target_link_libraries (descriptive LINK_PUBLIC CSPL)




