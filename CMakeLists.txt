cmake_minimum_required(VERSION 3.10)
project(project-name)

enable_testing()

add_subdirectory(Codes)

add_executable(runTests Codes/tests/main_test.cpp)
target_link_libraries(runTests gtest gtest_main)

add_test(NAME MyTests COMMAND runTests)