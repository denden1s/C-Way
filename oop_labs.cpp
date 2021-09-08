// oop_labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "arrays_head.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	//create_array(5);

	int nums[3] = {2,3,4};
	int second_nums[3] = { 2,1,4};

	int** matrix;
	
	int** s_matrix;//показать на второй работе
	//пересечение одномерных массивов
	//intersection_of_arrays(nums, second_nums);

	//объединение одномерных массивов 
	//unit_arrays(nums, second_nums);

	//сумма матриц
	matrix = create_matrix(2, 3);
	//matrix[0][0] = 1;
	//matrix[0][1] = 2;
	//matrix[0][2] = 3;
	s_matrix = create_matrix(3, 2);
	//s_matrix[0][0] = 4;
	//s_matrix[1][0] = 5;
	//s_matrix[2][0] = 6;
	//sum_matrix(matrix,s_matrix,2,5);
	multiply_matrix(matrix, 2,3, s_matrix, 3,2);
	return 0;
}
