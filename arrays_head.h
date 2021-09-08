#include<iostream>
using namespace std;
//include ...
//using ...
//void funct()

void create_array(int length);
//нужен дл€ пересечени€ массивов
void intersection_of_arrays(int*, int*);

//нужен дл€ объединени€ массивов
void unit_arrays(int*, int*);

//нужен дл€ перемножени€ матриц
void multiply_matrix(int**, int fm_rows, int fm_cols, int **, int sm_rows, int sm_cols);

void sum_matrix(int**, int**, int, int);


int** create_matrix(int, int);