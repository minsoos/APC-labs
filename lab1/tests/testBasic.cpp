#include <gtest/gtest.h>
#include <sudoku.h>

TEST(SearchKeyTests, KeyFoundInArray) {
    unsigned arr[] = {1, 2, 3, 4, 5};
    unsigned key = 3;
    EXPECT_EQ(search_key(arr, 5, key), 1);
}

TEST(SearchKeyTests, KeyNotFoundInArray) {
    unsigned arr[] = {1, 2, 3, 4, 5};
    unsigned key = 6;
    EXPECT_EQ(search_key(arr, 5, key), 0);
}

TEST(BasicSearchTests, ValidSudokuRow) {
    unsigned arr[] = {1, 2, 3, 4, 5};
    EXPECT_EQ(basic_search(arr, 5), 1);
}

TEST(BasicSearchTests, InvalidSudokuRow) {
    unsigned arr[] = {1, 2, 3, 4, 4};
    EXPECT_EQ(basic_search(arr, 5), 0);
}




