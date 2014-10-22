# add files into this variable
set ( CSPL_MonteCarlo_Files 
    CSPL_Jackknife.c 
    CSPL_MonteCarlo.h )

add_library (CSPL_MonteCarlo OBJECT ${CSPL_MonteCarlo_Files})
install( FILES CSPL_MonteCarlo.h DESTINATION include )

# this is -fPIC
set_target_properties( CSPL_MonteCarlo PROPERTIES POSITION_INDEPENDENT_CODE TRUE )
