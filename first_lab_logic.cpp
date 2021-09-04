#include<iostream>
#include "arrays_head.h"
using namespace std;

void intersection_of_arrays(int* first_arr, int* second_arr)
{
	int* arr;
	int counter = 0;
	//проверка возможности пересечения
	for (size_t i = 0; i < sizeof(first_arr)-1; i++)
	{
		for (size_t j = 0; j < sizeof(second_arr)-1; j++)
		{
			if (first_arr[i] == second_arr[j])
			{
				counter++;
			}
		}
	}
	// counter = 0 если элементы не пересекаются
	if (counter != 0)
	{
		int index = 0;
		arr = new int[counter];
		for (size_t i = 0; i < sizeof(first_arr) - 1; i++)
		{
			for (size_t j = 0; j < sizeof(second_arr) - 1; j++)
			{
				if (first_arr[i] == second_arr[j])
				{
					arr[index] = second_arr[j];
					index++;
				}
			}
		}
		cout << "Пересечение массивов: ";
		for (size_t i = 0; i < counter; i++)
		{
			cout << arr[i] << " ";
		}
		delete[] arr;
	}
	else
	{
		cout << "Массивы не пересекаются";
	}
}

void create_array(int length)
{
	int* arr;
	arr = new int[length];
	for (size_t i = 0; i < length; i++)
	{
		cout << "Введите " << (i + 1) << " элемент массива: ";
		cin >> arr[i];
	}
	cout << "Элементы массива:";
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << " ";
	}
	delete [] arr;
}

//работает
void unit_arrays(int* first_arr, int* second_arr)
{
	int* result_arr;
	
	int size = sizeof(first_arr) - 1 + sizeof(second_arr) - 1;
	result_arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		if (i < sizeof(first_arr) - 1)
		{
			result_arr[i] = first_arr[i];
		}
		else
		{
			int index = i % (sizeof(second_arr)-1);
			result_arr[i] = second_arr[index];
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		cout << result_arr[i];
	}
	delete []result_arr;
}


void create_matrix(int rows, int cols)
{
	int** matrix;
	matrix = new int*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = rand();
		}
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	delete[] matrix;
}

void sum_matrix(int** f_matrix, int** s_matrix, int rows, int cols)
{
	int** result_matrix;
	result_matrix = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		result_matrix[i] = new int[cols];
	};
	cout << "Sum of matrix: \n";
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j= 0; j < cols; j++)
		{
			result_matrix[i][j] = f_matrix[i][j] + s_matrix[i][j];
			cout << result_matrix[i][j];
		}
		cout << endl;
	}
}