#pragma once

#ifndef SIZE
#define SIZE 9
#endif

int search_key (const unsigned v[], unsigned n_elements, unsigned key);
int basic_search (const unsigned v[], unsigned n_elements);

int check_rows(const unsigned sudoku[][SIZE]);
int check_cols(const unsigned sudoku[][SIZE]);
int check_regions(const unsigned sudoku[][SIZE]);