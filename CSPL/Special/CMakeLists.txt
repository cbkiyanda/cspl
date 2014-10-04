# add files into this variable
set ( CSPL_Special_Files 
    CSPL_ERF.c 
    CSPL_Special.h )

add_library (CSPL_Special OBJECT ${CSPL_Special_Files})

# this is -fPIC
set_target_properties( CSPL_Special PROPERTIES POSITION_INDEPENDENT_CODE TRUE )

