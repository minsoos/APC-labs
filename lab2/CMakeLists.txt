cmake_minimum_required(VERSION 3.14)
project(lab2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion")

file(GLOB SOURCES "src/*.cpp")

add_executable(lab2 ${SOURCES})

include(CTest)

add_subdirectory(src)
add_subdirectory(tests)
enable_testing()

