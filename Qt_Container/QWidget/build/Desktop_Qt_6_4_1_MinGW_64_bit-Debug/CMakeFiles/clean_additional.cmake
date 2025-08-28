# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QWidget_autogen.dir\\ParseCache.txt"
  "QWidget_autogen"
  )
endif()
