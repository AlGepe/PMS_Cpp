set(CMAKE_VERBOSE_MAKEFILE 1)

# Files to compile and name of executable
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")
add_executable(PMS main.cpp Data.cpp Data.h EneryValue.cpp EneryValue.h LennarJones.cpp LennarJones.h Particle.cpp Particle.h R2.cpp R2.h R3.cpp R3.h Solid.cpp Solid.h)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
