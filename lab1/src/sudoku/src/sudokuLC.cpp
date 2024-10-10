#include <iostream>
#include <sudoku.h>

using std::cout;
using std::endl;

int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}

int basic_search (const unsigned v[], unsigned n_elements) {
    int res;
    unsigned j=1;
    while (j<10) {
        res = search_key (v, n_elements, j);
        if (res==1)
            ++j;
        else
            return 0;
    }
    return 1;
}

int check_rows (const unsigned sudoku[][SIZE]) {
    int res = 0;
    for(unsigned i=0; i<SIZE; ++i) {
        res = basic_search(sudoku[i],SIZE);
            if (res==0) {
                return res;
            }
    }
    res=1;
    return res;
}

int check_cols (const unsigned sudoku[][SIZE]) {
    int res = 0;
    // Itera attraverso ciascuna colonna
    for (unsigned j = 0; j < SIZE; ++j) { // j rappresenta l'indice della colonna
        unsigned column[SIZE]; // Array per memorizzare gli elementi della colonna

        // Estrai la colonna dalla matrice e memorizzala nell'array
        for (unsigned i = 0; i < SIZE; ++i) { // i rappresenta l'indice della riga
            column[i] = sudoku[i][j]; // Accedi alla colonna j della riga i
                }
        // Controlla la colonna usando basic_search
                res = basic_search(column, SIZE);
                if (res == 0) {
                    return res; // Ritorna 0 se la colonna non è valida
                }
            }
    return 1;
}

int check_regions (const unsigned sudoku[][SIZE]) {
    int res=0;
    unsigned block[SIZE];

    for( unsigned k=0; k<SIZE; k+=3) {   // itero blocchi righe
        for( unsigned l=0; l<SIZE; l+=3) {  //itero su blocchi colonne
            unsigned index = 0; // Indice per il blocco

            // Estraggo gli elementi del blocco 3x3
            for (unsigned i = 0; i < 3; ++i) {
                for (unsigned j = 0; j < 3; ++j) {
                    block[index++] = sudoku[k + i][l + j]; // Accedi al blocco
                }
            }

            res= basic_search( block, SIZE);
            if (res==0) {
                return res;
                        }
        }
    }
   res=1;
    return res;
}

// Function to print the Sudoku matrix
void print_sudoku(unsigned sudoku[][SIZE]) {
    for (size_t row = 0; row < SIZE; ++row) {
        for (size_t col = 0; col < SIZE; ++col) {
            cout << sudoku[row][col] << " ";
        }
        cout << endl; // New line after each row
    }
}
