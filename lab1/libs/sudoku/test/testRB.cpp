#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sudokuRB.h>

TEST_CASE("search_key function tests", "[search_key]") {
    SECTION("Key found in the array") {
        unsigned arr[] = {1, 2, 3, 4, 5};
        unsigned key = 3;
        REQUIRE(search_key(arr, 5, key) == 1);
    }

    SECTION("Key not found in the array") {
        unsigned arr[] = {1, 2, 3, 4, 5};
        unsigned key = 6;
        REQUIRE(search_key(arr, 5, key) == 0);
    }
}