cmake_minimum_required(VERSION 3.10)
project(SampleTest)

set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(sample_test sample_test.cpp)
target_link_libraries(sample_test GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main pthread)
