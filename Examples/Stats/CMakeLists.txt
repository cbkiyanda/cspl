# CMake config for Stats examples

add_executable( cdf cdf.c )
target_link_libraries (cdf LINK_PUBLIC CSPL)
target_include_directories( cdf PRIVATE ${INCLUDES} )

add_executable( descriptive descriptive.c )
target_link_libraries (descriptive LINK_PUBLIC CSPL)
target_include_directories( descriptive PRIVATE ${INCLUDES} )

add_executable( median median.c )
target_link_libraries (median LINK_PUBLIC CSPL)
target_include_directories( median PRIVATE ${INCLUDES} )

