cmake_minimum_required(VERSION 2.6.2)

set(SERVER_TEST_FILES ./TestTests/Module1.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

foreach (_file ${SERVER_TEST_FILES})
    get_filename_component(SERVER_TEST_FILE_ABS ${_file} REALPATH)
    set(SERVER_TEST_FILES_ABS_G ${SERVER_TEST_FILES_ABS_G} ${SERVER_TEST_FILE_ABS} CACHE INTERNAL "")

    get_filename_component(TEST_SRC ${_file} NAME_WE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(TEST_SRC_PRE "UnitTestServer${TEST_SRC}")
    add_executable(${TEST_SRC_PRE} ../../UnitTests/gtest.cpp ${_file})
    target_link_libraries(${TEST_SRC_PRE} gtest)

    set(TEST_SRC "Server_${TEST_SRC}")
    add_test(NAME ${TEST_SRC} COMMAND $<TARGET_FILE:${TEST_SRC_PRE}>)
endforeach()