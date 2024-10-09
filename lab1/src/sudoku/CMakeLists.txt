# sudoku CMakeLists.txt

file(GLOB SOURCES "src/*.cpp")

add_library(sudoku ${SOURCES})

target_include_directories(sudoku PUBLIC include)
    

