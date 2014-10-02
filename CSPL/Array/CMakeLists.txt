# add files into this variable
set ( CSPL_Array_Files 
    CSPL_Array.c 
    CSPL_Array.h )

add_library (CSPL_Array OBJECT ${CSPL_Array_Files})

# this is -fPIC
set_target_properties( CSPL_Array PROPERTIES POSITION_INDEPENDENT_CODE TRUE )

