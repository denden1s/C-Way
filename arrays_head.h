#include<iostream>
using namespace std;
//include ...
//using ...
//void funct()

void create_array(int length);

//нужен для пересечения массивов
void intersection_of_arrays(int*, int*);

//нужен для объединения массивов
void unit_arrays(int*, int*);

//нужен для перемножения матриц
void multiply_matrix(int**, int fm_rows, int fm_cols, int **, int sm_rows, int sm_cols);

//нужен для определения суммы матриц
void sum_matrix(int**, int**, int, int);

int** create_matrix(int, int);