cmake_minimum_required(VERSION 3.2.0)
project(test_package CXX)

set(input_files 01-simple 
                02-multipart-alternative
                03-multipart-mixed
                04-nested-multipart
                05-nested-message-rfc822
)

add_executable(parse-reproduce parse-reproduce.cpp)
target_link_libraries(parse-reproduce mimesis)
add_test(parse-reproduce parse-reproduce ${input_files})

add_executable(describe describe.cpp)
target_link_libraries(describe mimesis)
add_test(describe describe 01-simple)

add_executable(build-highlevel build-highlevel.cpp)
target_link_libraries(build-highlevel mimesis)
add_test(build-highlevel build-highlevel)

add_executable(build-lowlevel build-lowlevel.cpp)
target_link_libraries(build-lowlevel mimesis)
add_test(build-lowlevel build-lowlevel)

add_executable(headers headers.cpp)
target_link_libraries(headers mimesis)
add_test(headers headers)

add_executable(multipart multipart.cpp)
target_link_libraries(multipart mimesis)
add_test(multipart multipart)

add_executable(load-save load-save.cpp)
target_link_libraries(load-save mimesis)
add_test(load-save load-save ${input_files})

# we don't want to copy if we're building in the source dir
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

    foreach(item IN LISTS input_files)
        message(STATUS ${item})
        message(STATUS ${CMAKE_CURRENT_BINARY_DIR})
        FILE(COPY "input-clean/${item}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
    endforeach()
endif()