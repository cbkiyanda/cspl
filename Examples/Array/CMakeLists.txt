# CMake config for Array examples

#find_package(CSPL REQUIRED)
#include_directories(${CSPL_INCLUDE_DIRS})

add_executable( Array1 Array1.c )
target_link_libraries (Array1 LINK_PUBLIC CSPL)
target_include_directories( Array1 PRIVATE ${INCLUDES} )

add_executable( Array2 Array2.c )
target_link_libraries (Array2 LINK_PUBLIC CSPL)
target_include_directories( Array2 PRIVATE ${INCLUDES} )

add_executable( quickselect quickselect.c )
target_link_libraries (quickselect LINK_PUBLIC CSPL)
target_include_directories( quickselect PRIVATE ${INCLUDES} )

add_executable( bisect bisect.c )
target_link_libraries (bisect LINK_PUBLIC CSPL)
target_include_directories( bisect PRIVATE ${INCLUDES} )
