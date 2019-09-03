cmake_minimum_required (VERSION 2.6)
project (mimesis)

find_package(Iconv)
if(Iconv_FOUND)
   include_directories(${Iconv_INCLUDE_DIRS})
   target_link_libraries(${Iconv_LIBRARIES})
   add_definitions(-DHAS_ICONV)
endif()

# BUILD_SHARED_LIBS is a standard CMake variable, but we declare it here to
# make it prominent since we are turning it off by default.
option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." OFF)

# This may not work on windows.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

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