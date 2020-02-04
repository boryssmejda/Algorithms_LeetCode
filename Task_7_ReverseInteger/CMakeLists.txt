cmake_minimum_required(VERSION 3.9)

project(ReverseInteger VERSION 1.0.0 DESCRIPTION "Program reverses digits of a given a 32-bit signed integer.")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Detect compiler and set proper flags
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Wshadow")
endif()


# Set a default build type if none was specified
set(default_build_type "Release")
if(EXISTS "${CMAKE_SOURCE_DIR}/../.git")
  set(default_build_type "Debug")
endif()
 
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(LIB_NAME SolutionLib)
add_library(${LIB_NAME} SHARED
            solution.cpp)

set_target_properties(${LIB_NAME} PROPERTIES
VERSION ${PROJECT_VERSION}
SOVERSION 1
PUBLIC_HEADER solution.hpp)

include(GNUInstallDirs)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread ${LIB_NAME})

#include(CTest)
enable_testing()
add_test(NAME runTests COMMAND runTests)

INSTALL(FILES solution.hpp DESTINATION ${PROJECT_BINARY_DIR}/include)
INSTALL(TARGETS runTests RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)