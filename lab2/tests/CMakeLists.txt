# CMakeLists.txt for tests
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
include(GoogleTest)

##file(GLOB SOURCES "*.cpp")

add_executable(basic_tests testBasic.cpp)
target_link_libraries(basic_tests PRIVATE sudoku GTest::GTest)
add_test(NAME BasicTests COMMAND basic_tests)

add_executable(row_tests testRows.cpp)
target_link_libraries(row_tests PRIVATE sudoku GTest::GTest)
add_test(NAME RowTests COMMAND row_tests)

add_executable(col_tests testCols.cpp)
target_link_libraries(col_tests PRIVATE sudoku GTest::GTest)
add_test(NAME ColTests COMMAND col_tests)

add_executable(reg_tests testRegs.cpp)
target_link_libraries(reg_tests PRIVATE sudoku GTest::GTest)
add_test(NAME RegTests COMMAND reg_tests)