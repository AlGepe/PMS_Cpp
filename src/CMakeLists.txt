set(CMAKE_VERBOSE_MAKEFILE 1)

# CMAKE_POLICY(CMP0004 OLD)
# Files to compile and name of executable
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories(SYSTEM)

add_executable(PMS_C++ main.cpp Data.cpp Data.h EneryValue.cpp EneryValue.h LennarJones.cpp LennarJones.h Particle.cpp Particle.h R2.cpp R2.h R3.cpp R3.h Solid.cpp Solid.h)
