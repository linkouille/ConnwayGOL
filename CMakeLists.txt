# CMake entry point
cmake_minimum_required (VERSION 3.0)
project ("Conway Game of Life" LANGUAGES C)

include_directories(include)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -O3 -I.")

set(SOURCES ./src/main.cpp)
set(INCLUDES ./include/*.hpp)

find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes -v --leak-check=full" )

file(GLOB SOURCES "src/*.c")
file(GLOB INCLUDES "include/*.h")

add_executable(main ${SOURCES})

# target_link_libraries(main ${ALL_LIBS})