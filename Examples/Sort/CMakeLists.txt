# CMake config for Array examples

add_executable( sort sort.c )
target_link_libraries (sort LINK_PUBLIC CSPL)
target_include_directories( sort PRIVATE ${INCLUDES} )

add_executable( gnomesort gnomesort.c )
target_link_libraries (gnomesort LINK_PUBLIC CSPL)
target_include_directories( gnomesort PRIVATE ${INCLUDES} )
