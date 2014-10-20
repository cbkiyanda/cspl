add_executable( Test_Stats_Normal Test_Stats_Normal.c )
add_test( Stats_Normal-test Test_Stats_Normal )
target_link_libraries (Test_Stats_Normal LINK_PUBLIC CSPL)

add_executable( Test_Stats Test_Stats.c )
add_test( Test_Stats-test Test_Stats )
target_link_libraries (Test_Stats LINK_PUBLIC CSPL)

add_executable( Test_Array Test_Array.c )
add_test( Array-test Test_Array )
target_link_libraries (Test_Array LINK_PUBLIC CSPL)

add_executable( Test_Histogram Test_Histogram.c )
add_test( Histogram-test Test_Histogram )
target_link_libraries (Test_Histogram LINK_PUBLIC CSPL)

add_executable( Test_Sort Test_Sort.c )
add_test( Sort-test Test_Sort )
target_link_libraries (Test_Sort LINK_PUBLIC CSPL)

add_executable( Test_Stats_Median Test_Stats_Median.c )
add_test( Stats_Median-test Test_Stats_Median )
target_link_libraries (Test_Stats_Median LINK_PUBLIC CSPL)

add_executable( Test_Special Test_Special.c )
add_test( Special-test Test_Special )
target_link_libraries (Test_Special LINK_PUBLIC CSPL)

add_executable( Test_Regression Test_Regression.c )
add_test( Regression-test Test_Regression )
target_link_libraries (Test_Regression LINK_PUBLIC CSPL)
