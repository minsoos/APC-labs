#include <iostream>
#include <sudoku.h>


int search_key (const unsigned v[], unsigned n_elements, unsigned key)
{
    unsigned key_found = 0;

    for (size_t i=0; i<n_elements; ++i)
        if (v[i] == key)
            key_found = 1;

    return key_found;
}


int basic_search(const unsigned v[], unsigned n_elements) {
    int check=1, to_check=1;
    //check is treated like boolean, to_check becomes values to check, from 1 to n_elements
    while(check==1 && to_check<=n_elements) {
        //search_key=1 if element exists, 0 otherwise. To parallelize take product of returns?
        //if check becomes 0 break from cycle, return 0; if there are no more checks return 1
        check=search_key(v, n_elements, to_check);
        to_check++;
    }
    return check;
}

int basic_search_autonoma(const unsigned v[], unsigned n_elements) {
    int check=1, to_check=1, i=0;
    //check is treated like boolean, to_check are values from 1 to n_elem, i is index of v
    while(check==1 && to_check<=n_elements) {
        check=0;
        //if check is not set to 1 in 2nd while break, return 0
        while(i<n_elements) {
            //check if element to_check is in the vector, if so check=1
            if(v[i]==to_check) {
                check=1;
            }
            i++;
        }
        to_check++;
    }
    return check;
}

/*
//####### V2 ##########
int check_rows (const unsigned sudoku[][SIZE]) {
    unsigned vec[SIZE];
    int check=1, i=0;
    while(check==1 && i<SIZE){
        for(int j=0;j<SIZE;j++){
            vec[j]=sudoku[i][j];
        }
        check = basic_search(vec, SIZE);
        i++;
    }
    return check;
}

int check_cols (const unsigned sudoku[][SIZE]) {
    unsigned vec[SIZE];
    int check=1, i=0;
    while(check==1 && i<SIZE){
        for(int j=0;j<SIZE;j++){
            vec[j]=sudoku[j][i];
        }
        check = basic_search(vec, SIZE);
        i++;
    }
    return check;
}

int check_regions (const unsigned sudoku[][SIZE]) {
    unsigned vec[SIZE];
    int check=1, i=0, x, y;
    while(check==1 && i<SIZE){
        for(int j=0;j<SIZE;j++){
            x=i;
            y=j;
            compute_box_idx(x,y);
            vec[j]=sudoku[x][y];
        }
        check = basic_search(vec, SIZE);
        i++;
    }
    return check;
}

void compute_box_idx(int &x,int &y){ //x input is number of box, y input is position in box
                                //x output is x coord in sudoku, y output is coord in sudoku
    int box=x, pos=y;

    int add_term_x = (box - (box)%3);
    int add_term_y = ((box)%3)*3;

    x=(pos-pos%3)/3 + add_term_x;
    y=pos%3 + add_term_y;
}
//###### END ##########
*/


//###### V1 ###########
int check_rows (const unsigned sudoku[][SIZE]) {
    int check=1;
    //could be optimized for 1 core using while(check==1 && row<SIZE)
    //can be parallelized for n cores giving each core 1 row to check
    for(int row=0; row<SIZE; row++) {
        //check all rows, if some rows are wrong check=0
        if(!check_row(row,sudoku)) {
            check=0;
        }
    }
    return check;
}
int check_cols (const unsigned sudoku[][SIZE]){
    int check=1;
    //could be optimized for 1 core using while(check==1 && row<SIZE)
    //can be parallelized for n cores giving each core 1 row to check
    for(int col=0; col<SIZE; col++) {
        //check all cols, if some cols are wrong check=0
        if(!check_col(col,sudoku)) {
            check=0;
        }
    }
    return check;
}
int check_regions (const unsigned sudoku[][SIZE]){
    int check=1;
    //could be optimized for 1 core using while(check==1 && row<SIZE)
    //can be parallelized for n cores giving each core 1 row to check
    for(int box=0; box<SIZE; box++) {
        //check all boxes, if some boxes are wrong check=0
        if(!check_box(box,sudoku)) {
            check=0;
        }
    }
    return check;
}
bool check_row(const unsigned row, const unsigned sudoku[][SIZE]) {
    unsigned check=1, i=0, num_hap=0;
    //check is boolean, i is index in row, num_hap counts if number happens twice
    do {
        //for each number count how often it happens, if=2 at any point or if=0 at end of cycle
        //break and return 0
        num_hap=0;
        i=0;
        do {
            //if num_hap=2 at any point break
            if(sudoku[row][i]==check) {
                num_hap++;
            }
            i++;
        }while(num_hap<2&&i<SIZE);
        check++;
    }while(num_hap==1&&check<=SIZE);
    //return 1 if exited because check>SIZE and all good, return 0 otherwise
    return num_hap==1;
}

bool check_col(const unsigned col, const unsigned sudoku[][SIZE] ) {
    unsigned check=1, i=0, num_hap=0;
    //check is boolean, i is index in col, num_hap counts if number happens twice
    do {
        //for each number count how often it happens, if=2 at any point or if=0 at end of cycle
        //break and return 0
        num_hap=0;
        i=0;
        do {
            //if num_hap=2 at any point break
            if(sudoku[i][col]==check) {
                num_hap++;
            }
            i++;
        }while(num_hap<2&&i<SIZE);
        check++;
    }while(num_hap==1&&check<=SIZE);
    //return 1 if exited because check>SIZE and all good, return 0 otherwise
    return num_hap==1;
}

bool check_box(const unsigned box, const unsigned sudoku[][SIZE]) {
    unsigned check=1, i=0, x=0, y=0, num_hap=0;
    //check is boolean, i is index in box, x is row index, y is col index, num_hap counts if
    //number happens twice. NB: box 3->check_box(2,...). Box order, and order in box, are:
    // 1 2 3
    // 4 5 6
    // 7 8 9
    unsigned add_term_x = (box - (box)%3);
    //rows: for box 1,2,3 add 0, for box 4,5,6 add 3, for box 7,8,9 add 6
    unsigned add_term_y = ((box)%3)*3;
    //cols: for box 1,4,7 add 0, for box 2,6,8 add 3, for box 3,6,9 add 6
    do {
        //for each number count how often it happens, if=2 at any point or if=0 at end of cycle
        //break and return 0
        num_hap=0;
        i=0;
        do {
            //if num_hap=2 at any point break
            x=(i-i%3)/3 + add_term_x;
        //rows: for pos 1,2,3 add 0, for pos 4,5,6 add 1, for pos 7,8,9 add 2, then add_term_x
            y=i%3 + add_term_y;
        //cols: for pos 1,4,7 add 0, for pos 2,6,8 add 1, for pos 3,6,9 add 2, then add_term_y
            if(sudoku[x][y]==check) {
                num_hap++;
            }
            i++;
        }while(num_hap<2&&i<SIZE);
        check++;
    }while(num_hap==1&&check<=SIZE);
    //return 1 if exited because check>SIZE and all good, return 0 otherwise
    return num_hap==1;
}

void display_board(const unsigned board[][SIZE]) {
    bool printed=false; //used to print horizontal line
    for(int i=0; i<9; i++) {
        printed=false;
        for(int j=0; j<9; j++) {
            //every 3 numbers print vertical line
            if(j%3==0&&j!=0) {
                std::cout<<"| ";
            }
            //every 3 rows print horizontal line
            if(i%3==0&&i!=0&&printed==false) {
                std::cout<<"- - - - - - - - - - -"<<std::endl;
                printed=true;
            }
            //print numbers
            std::cout<<board[i][j]<<" ";
            //every 9 numbers end line
            if(j==8)
                std::cout<<std::endl;
        }
    }
}