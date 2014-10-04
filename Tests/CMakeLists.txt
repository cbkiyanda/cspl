

add_executable( Test_Stats_Normal Test_Stats_Normal.c )
add_test( Stats_Normal-test Test_Stats_Normal )

target_link_libraries (Test_Stats_Normal LINK_PUBLIC CSPL)
