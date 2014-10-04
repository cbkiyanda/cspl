# add files into this variable
set ( CSPL_Stats_Files 
    CSPL_Stats_CDF.c 
    CSPL_Stats.h 
    CSPL_Stats.c 
    CSPL_Stats_CDF.h
    CSPL_Stats_Normal.c
    CSPL_Stats_Normal.h
 )

add_library (CSPL_Stats OBJECT ${CSPL_Stats_Files})
install( FILES CSPL_Stats.h CSPL_Stats_CDF.h DESTINATION include )

# this is -fPIC
set_target_properties( CSPL_Stats PROPERTIES POSITION_INDEPENDENT_CODE TRUE )
