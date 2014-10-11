# add files into this variable
set ( CSPL_Array_Files 
    CSPL_Array.c 
    CSPL_Array.h )

set ( CSPLA_Files 
    CSPLA.c 
    CSPLA.h )

add_library (CSPL_Array OBJECT ${CSPL_Array_Files})
install( FILES CSPL_Array.h DESTINATION include )

add_library (CSPLA OBJECT ${CSPLA_Files})
install( FILES CSPLA.h DESTINATION include )

# this is -fPIC
set_target_properties( CSPL_Array PROPERTIES POSITION_INDEPENDENT_CODE TRUE )
set_target_properties( CSPLA PROPERTIES POSITION_INDEPENDENT_CODE TRUE )
