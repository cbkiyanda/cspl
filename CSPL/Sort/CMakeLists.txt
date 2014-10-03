# add files into this variable
set ( CSPL_Sort_Files 
    CSPL_Sort.c 
    CSPL_Sort.h )

add_library (CSPL_Sort OBJECT ${CSPL_Sort_Files})
install( FILES CSPL_Sort.h DESTINATION include )

# this is -fPIC
set_target_properties( CSPL_Sort PROPERTIES POSITION_INDEPENDENT_CODE TRUE )

