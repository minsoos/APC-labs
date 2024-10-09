cmake_minimum_required(VERSION 3.14)
project(lab1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion")

file(GLOB SOURCES "src/*.cpp")

add_executable(lab1 ${SOURCES})

add_subdirectory(libs/sudoku)
target_link_libraries(${PROJECT_NAME} PRIVATE sudoku)

enable_testing()
