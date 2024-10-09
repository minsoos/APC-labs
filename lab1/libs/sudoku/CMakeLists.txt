# sudoku CMakeLists.txt

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

include(CTest)
include(Catch)

file(GLOB SOURCES "src/*.cpp")

add_library(sudoku ${SOURCES})

add_subdirectory(test)

target_include_directories(sudoku PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
    

