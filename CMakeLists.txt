cmake_minimum_required (VERSION 2.6)
project (PMS_C++)
# The version number.
set (Test_VERSION_MAJOR 0)
set (Test_VERSION_MINOR 1)

include_directories(${CMAKE_SOURCE_DIR}/src)
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

set(CMAKE_CXX_FLAGS "-Wall -O0 -ggdb")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -O0 -ggdb")

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, defaulting to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
	"${PROJECT_SOURCE_DIR}/ParticleMotionSimulator.h.in"
		  "${PROJECT_BINARY_DIR}/ParticleMotionSimulator.h"
			  )
			 
# add the binary tree to the search path for include files
# so that we will find TestConfig.h
include_directories("${PROJECT_BINARY_DIR}")

