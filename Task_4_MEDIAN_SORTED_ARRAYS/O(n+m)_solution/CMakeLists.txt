cmake_minimum_required(VERSION 2.6)

project(LongestSubstring)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp solution.cpp solution.hpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)