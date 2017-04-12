cmake_minimum_required (VERSION 2.8)
project (PMS_translated)
# The version number.
set (Test_VERSION_MAJOR 0)
set (Test_VERSION_MINOR 1)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/ParticleMotionSimulator.h.in"
	"${PROJECT_BINARY_DIR}/ParticleMotionSimulator.h"
	)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


# Enable/disable testing
option(TESTS_ENABLED "Enable automatic tests" OFF)
# Enable/disable test coverage
option(COVERAGE_ENABLED "Enable test coverage" OFF)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
	message(FATAL_ERROR "Compiler does not support C++11")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE "Debug")


# add the binary tree to the search path for include files
# so that we will find TestConfig.h
include_directories("${PROJECT_BINARY_DIR}")
#include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/src")

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
#add_executable(PEPE src/main.cpp)
add_subdirectory(src)
