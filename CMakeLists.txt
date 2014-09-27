cmake_minimum_required(VERSION 2.8.3)
#cmake_policy(SET CMP0002 NEW)
#cmake_policy(SET CMP0042 NEW)

project(CSPL)

add_subdirectory (CSPL)
add_subdirectory (CSPL/Stats)

add_library (CSPL $<TARGET_OBJECTS:CSPL_Stats>)
