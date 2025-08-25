# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QCheckBox_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QCheckBox_autogen.dir\\ParseCache.txt"
  "QCheckBox_autogen"
  )
endif()
