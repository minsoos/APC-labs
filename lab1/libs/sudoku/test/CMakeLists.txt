# CMakeLists.txt for Sudoku library tests

# Collect all test source files in the current directory
file(GLOB SOURCES "*.cpp")

# Define the test target with the collected source files
add_executable(sudoku_tests ${SOURCES})

# Link the Sudoku library target to the test target
target_link_libraries(sudoku_tests PRIVATE sudoku Catch2::Catch2WithMain)

# Add the test target to the test suite

catch_discover_tests(sudoku_tests)
