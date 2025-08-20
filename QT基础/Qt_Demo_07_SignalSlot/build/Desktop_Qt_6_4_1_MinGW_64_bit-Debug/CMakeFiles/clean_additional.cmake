# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtDemo07_SignalSlot_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtDemo07_SignalSlot_autogen.dir\\ParseCache.txt"
  "QtDemo07_SignalSlot_autogen"
  )
endif()
