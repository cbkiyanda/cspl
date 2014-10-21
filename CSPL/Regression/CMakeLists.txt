# add files into this variable
set ( CSPL_Regression_Files 
    CSPL_Regression_TheilSen.c 
    CSPL_Regression.c
    CSPL_Regression.h )

add_library (CSPL_Regression OBJECT ${CSPL_Regression_Files})
install( FILES CSPL_Regression.h DESTINATION include )

# this is -fPIC
set_target_properties( CSPL_Regression PROPERTIES POSITION_INDEPENDENT_CODE TRUE )
