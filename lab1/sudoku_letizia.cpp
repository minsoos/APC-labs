/*
 * Check sudoku matrix
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const size_t SIZE = 9;




/*
 * YOUR CODE GOES HERE
 */





// Return:
//         1 if sudoku matrix complies to all Sudoku rules
//        -1 if a row violates the game rules
//        -2 if a column violates the game rules
//        -3 if a region violates the game rules
int check_sudoku(const unsigned sudoku[][SIZE]);

// Create a Sudoku matrix by Lewis' Algorithm
// (https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)
void generate_sudoku(unsigned sudoku[][SIZE]);
void print_sudoku(unsigned sudoku[][SIZE]);

int search_key (const unsigned v[], unsigned n_elements, unsigned key);
int basic_search (const unsigned v[], unsigned n_elements);

int check_rows (const unsigned sudoku[][SIZE]);
int check_cols (const unsigned sudoku[][SIZE]);
int check_regions (const unsigned sudoku[][SIZE]);

int main()
{
    // initialize a sudoku matrix
    unsigned sudoku[SIZE][SIZE] = {
            {1,2,3,4,5,6,7,8,9},
            {2,3,4,5,6,7,8,9,1},
            {3,4,5,6,7,8,9,1,2},
            {4,5,6,7,8,9,1,2,3},
            {5,6,7,8,9,1,2,3,4},
            {6,7,8,9,1,2,3,4,5},
            {7,8,9,1,2,3,4,5,6},
            {8,9,1,2,3,4,5,6,7},
            {9,1,2,3,4,5,6,7,8}
    };
// I try if basic_search works properly
    // unsigned x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int res_arr;
    // res_arr= basic_search( x,9);
    // cout << "basic search returns:" << res_arr << endl;

    // check
    int res = check_sudoku(sudoku);
    cout << "check_sudoku returns: " <<  res << endl;

    // initialize another sudoku matrix
    unsigned sudoku2[SIZE][SIZE];
    generate_sudoku(sudoku2);
    // Print the generated Sudoku
    // cout << "Generated Sudoku: " << endl;
    // print_sudoku(sudoku2);
    // cout << endl;

    //check2
    int res2 = check_sudoku(sudoku2);
    cout << "check_sudoku2 returns: " << res2 << endl;

    return 0;
}

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



int check_sudoku(const unsigned sudoku[][SIZE])
{
    int res_r,res_c, res_R;
    res_r= check_rows(sudoku);
    res_c= check_cols(sudoku);
    res_R= check_regions(sudoku);

    if ( res_r!=0 && res_c !=0 && res_R != 0) {
        cout<< "the sudoku is correct!"<< endl;
        return 1;
    }
    if (res_r==0 && res_c !=0 && res_R != 0) {
        cout<< "the sudoku doesn't complies the row rule!"<< endl;
        return -1;
    }
    if (res_r!=0 && res_c ==0 && res_R != 0) {
        cout<< "the sudoku doesn't complies the column rule!"<< endl;
        return -2;
    }
    if (res_r!=0 && res_c !=0 && res_R == 0) {
        cout<< "the sudoku doesn't complies the regions rule!"<< endl;
        return -3;
    }
}

void generate_sudoku(unsigned sudoku[][SIZE])
{
    int x = 0;
    for (size_t i=1; i<=3; ++i)
    {
        for (size_t j=1; j<=3; ++j)
        {
            for (size_t k=1; k<=SIZE; ++k)
            {
                sudoku[3*(i-1)+j-1][k-1] = (x % SIZE) + 1;
                x++;
            }
            x += 3;
        }
        x++;
    }
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
