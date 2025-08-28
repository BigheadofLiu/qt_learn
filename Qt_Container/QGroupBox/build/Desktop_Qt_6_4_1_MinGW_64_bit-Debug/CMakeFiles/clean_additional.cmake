# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QGroupBox_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QGroupBox_autogen.dir\\ParseCache.txt"
  "QGroupBox_autogen"
  )
endif()
