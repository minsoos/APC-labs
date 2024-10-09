#include <iostream>
#include "sudokuRB.h"

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}


int basic_search (const unsigned v[], unsigned n_elements) {
    for (int i = 0; i < n_elements; i++) {
        if (!search_key(v, n_elements, i + 1)) {
            return 0;
        };
    };

    return 1;
}

int check_rows(const unsigned sudoku[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!basic_search(sudoku[i], SIZE)) {
            return 0;
        };
    };

    return 1;
}

void get_col(unsigned *col, int num, const unsigned sudoku[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        col[i] = sudoku[i][num];
    }
}

int check_cols(const unsigned sudoku[][SIZE]) {
    unsigned *col;
    for (int i = 0; i < SIZE; i++) {
        get_col(col, i, sudoku);

        if (!basic_search(col, SIZE)) {
            return 0;
        };
    };

    return 1;
}

void get_reg(unsigned *reg, int num, const unsigned sudoku[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int r = 3 * int(num / 3) + int(i / 3);
        int c = 3 * (num % 3) + (i % 3);

        reg[i] = sudoku[r][c];
    }    
}

int check_regions(const unsigned sudoku[][SIZE]) {
    unsigned *reg;
    for (int i = 0; i < SIZE; i++) {
        get_reg(reg, i, sudoku);

        if (!basic_search(reg, SIZE)) {
            return 0;
        };
    };

    return 1;
}