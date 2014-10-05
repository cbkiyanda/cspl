

add_executable( Test_Stats_Normal Test_Stats_Normal.c )
add_test( Stats_Normal-test Test_Stats_Normal )
target_link_libraries (Test_Stats_Normal LINK_PUBLIC CSPL)

add_executable( Test_Stats Test_Stats.c )
add_test( Test_Stats-test Test_Stats )
target_link_libraries (Test_Stats LINK_PUBLIC CSPL)

