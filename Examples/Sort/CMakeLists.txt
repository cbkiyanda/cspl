
# CMake config for Array examples

include_directories(../../CSPL/Stats, ../../CSPL/Array, ../../CSPL/Special, ../../CSPL )

add_executable( sort sort.c )
target_link_libraries (sort LINK_PUBLIC CSPL)

add_executable( gnomesort gnomesort.c )
target_link_libraries (gnomesort LINK_PUBLIC CSPL)

