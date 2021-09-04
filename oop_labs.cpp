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

	int matrix[3][3] = { {1,2,3},{1,1,1}, {2,2,3} };
	
	int s_matrix [3][3]= { {6,7,8},{1,1,1}, {0,0,3} };//показать на второй работе
	//intersection_of_arrays(nums, second_nums);

	//unit_arrays(nums, second_nums);

	create_matrix(2, 5);
	//sum_matrix((int**)matrix, (int**)s_matrix,3,3);
	return 0;
}
