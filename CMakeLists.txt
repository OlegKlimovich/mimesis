cmake_minimum_required (VERSION 3.1)
project (mimesis)

set (CMAKE_CXX_STANDARD 11)

# BUILD_SHARED_LIBS is a standard CMake variable, but we declare it here to
# make it prominent since we are turning it off by default.
option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." OFF)

add_subdirectory(src)

include_directories(
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    ${OTHER_INCLUDE_DIRS}
    )


if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
   enable_testing() 
   add_subdirectory(test)
endif()