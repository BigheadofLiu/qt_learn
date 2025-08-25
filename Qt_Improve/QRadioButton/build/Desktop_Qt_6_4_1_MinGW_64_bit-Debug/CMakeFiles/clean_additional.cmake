# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QRadioButton_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QRadioButton_autogen.dir\\ParseCache.txt"
  "QRadioButton_autogen"
  )
endif()
