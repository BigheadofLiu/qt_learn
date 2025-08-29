# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QStackedWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QStackedWidget_autogen.dir\\ParseCache.txt"
  "QStackedWidget_autogen"
  )
endif()
