# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QScrollArea_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QScrollArea_autogen.dir\\ParseCache.txt"
  "QScrollArea_autogen"
  )
endif()
