# add files into this variable
set ( CSPL_Histogram_Files 
    CSPL_Histogram.c 
    CSPL_Histogram.h )

add_library (CSPL_Histogram OBJECT ${CSPL_Histogram_Files})
install( FILES CSPL_Histogram.h DESTINATION include )

# this is -fPIC
set_target_properties( CSPL_Histogram PROPERTIES POSITION_INDEPENDENT_CODE TRUE )
