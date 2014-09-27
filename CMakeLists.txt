cmake_minimum_required(VERSION 2.8.3)
#cmake_policy(SET CMP0002 NEW)
if(POLICY CMP0042)	
  cmake_policy(SET CMP0042 NEW) # remove if CMake >= 2.8.11 required
endif()

project(CSPL)

add_subdirectory (CSPL)
add_subdirectory (CSPL/Stats)

add_library (CSPL SHARED $<TARGET_OBJECTS:CSPL_Stats>)

find_program(ctypesgen ctypesgen.py)
if(NOT ctypesgen)
  message(WARNING "Could not find ctypesgen.py command, python cannot be build")
  # put code here to build the python
endif(NOT ctypesgen)





