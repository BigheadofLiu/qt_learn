# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TabWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TabWidget_autogen.dir\\ParseCache.txt"
  "TabWidget_autogen"
  )
endif()
