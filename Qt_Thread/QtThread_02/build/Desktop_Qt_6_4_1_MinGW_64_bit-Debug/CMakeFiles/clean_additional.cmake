# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtThread_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtThread_autogen.dir\\ParseCache.txt"
  "QtThread_autogen"
  )
endif()
