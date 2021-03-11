# CMake entry point
cmake_minimum_required (VERSION 3.0)
project ("Conway Game of Life" LANGUAGES C)

find_package(SDL2 REQUIRED)

include_directories(include)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -O3 -I.")

set(SOURCES ./src/main.cpp)
set(INCLUDES ./include/*.hpp)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2_IMG REQUIRED SDL2_image)
pkg_search_module(SDL2_TTF REQUIRED SDL2_ttf)
set(SDL2_ALL_LIBS ${SDL2_LIBRARIES} ${SDL2_IMG_LIBRARIES} ${SDL2_TTF_LIBRARIES})
set(SDL2_ALL_INC ${SDL2_INCLUDE_DIRS} ${SDL2_IMG_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes -v --leak-check=full" )

file(GLOB SOURCES "src/*.c")
file(GLOB INCLUDES "include/*.h")

add_executable(main ${SOURCES})

target_link_libraries(main ${SDL2_ALL_LIBS} m)