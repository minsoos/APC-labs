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

file(GLOB SOURCES "*.cpp")

add_executable(sudoku_tests ${SOURCES})
target_link_libraries(sudoku_tests PRIVATE sudoku GTest::GTest)
gtest_discover_tests(sudoku_tests)