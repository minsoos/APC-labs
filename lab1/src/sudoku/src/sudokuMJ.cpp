#include "sudoku.h"

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}

int basic_search (const unsigned v[], unsigned n_elements){
    int every = 1;
    for (unsigned int i=1; i<SIZE+1; i++){
        every = search_key(v, n_elements, i);
    }
    return every;
}

int check_rows (const unsigned sudoku[][SIZE]){
    int every = 1;
    for (unsigned int i=0; i<SIZE; i++){
        every = basic_search(sudoku[i], SIZE);
    }
    return every;
}

int check_cols (const unsigned sudoku[][SIZE]){
    int every = 1;
    for (unsigned int i=0; i<SIZE; i++){
        unsigned v[SIZE];
        for (unsigned int e=0; e<SIZE; e++){
            v[e] = sudoku[e][i];
        }
        every = basic_search(v, SIZE);
    }
    return every;
}

int check_regions (const unsigned sudoku[][SIZE]){
    int every = 1;
    for (unsigned int cuadr=0; cuadr<SIZE; cuadr++){
        unsigned v[SIZE];
        for (unsigned int i=0; i<SIZE; i++){
            for (unsigned int e=0; e<SIZE; e++){
                if (cuadr == i/3*3+e/3){
                    v[i%3*3+e%3] = sudoku[i][e];
                }
            }   
        }
        every = basic_search(v, SIZE);
    }
    return every;
}