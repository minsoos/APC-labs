# social CMakeLists.txt


#### Uncomment these lines to compile all .cpp files in src ###
file(GLOB SOURCES "src/*.cpp") 
add_library(social ${SOURCES})
##############################################################

#### Uncomment these lines to compile only specific .cpp ###
# add_library(sudoku 
    #src/sudokuRB.cpp
#)
##############################################################

target_include_directories(social PUBLIC include)