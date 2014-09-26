add_library (CSPL_Stats SHARED CSPL_Stats_CDF.c CSPL_Stats.h CSPL_Stats_CDF.h)

target_include_directories (CSPL_Stats PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


