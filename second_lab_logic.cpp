#include<iostream>
#include "second_lab.h"
#include "arrays_head.h"
using namespace std;

//Need to fill matrix by random nums
void Matrix::FillByRand()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() - rand() /2*(i + j^2);
		}
	}
}

//Standart constructor
Matrix::Matrix(int _rows, int _cols)
{
	cout << "Matrix standart constructor" << endl;
	rows = _rows;
	cols = _cols;
	matrix = new int*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	FillByRand();
}

//Copy constructor
Matrix::Matrix(const Matrix& copyMatrix)
{
	cout << "Matrix copy constructor" << endl;
	rows = copyMatrix.rows;
	cols = copyMatrix.cols;
	matrix = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = copyMatrix.matrix[i][j];
		}
	}
}

//Destructor
Matrix::~Matrix()
{
	cout << "Matrix destructor" << endl;
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int Matrix::GetCurrentElement(int row, int col)
{
	return this->matrix[row][col];
}
//Need to multiply two matrix, this method return matrix
Matrix* Matrix::MultiplyMatrix(Matrix f_matrix, Matrix s_matrix)//!!dont work normaly
{
	int cols = f_matrix.cols < s_matrix.cols ? f_matrix.cols : s_matrix.cols;
	cout << "Start multiply" << endl;
	if (f_matrix.cols == s_matrix.rows)
	{
		int cols = f_matrix.cols < s_matrix.cols ? f_matrix.cols : s_matrix.cols;
		Matrix* result_matrix = new Matrix(f_matrix.rows, cols);

		for (size_t q = 0; q < result_matrix->rows; q++)
		{
			for (size_t a = 0; a < result_matrix->cols; a++)
			{
				for (size_t i = 0; i < cols; i++)
				{
					result_matrix->matrix[q][a] += f_matrix.GetCurrentElement(a,i) * s_matrix.GetCurrentElement(i,q);
				}
			}
		}
		cout << "End multiply" << endl;
		return result_matrix;
	}
	else
		throw exception("Function cant work");

}

//Need ti find sum of two matrix
Matrix* Matrix::SumMatrix(Matrix f_matrix, Matrix s_matrix)
{
	Matrix* result;
	if (f_matrix.rows == s_matrix.rows && f_matrix.cols == s_matrix.cols)
	{
		int** result_matrix;
		Matrix* result = new Matrix(f_matrix.rows, f_matrix.cols);
		result->matrix = new int* [f_matrix.rows];

		for (size_t i = 0; i < f_matrix.rows; i++)
		{
			result->matrix[i] = new int[f_matrix.cols];
		};
		for (size_t i = 0; i < f_matrix.rows; i++)
		{
			for (size_t j = 0; j < f_matrix.cols; j++)
			{
				result->matrix[i][j] = f_matrix.matrix[i][j] + s_matrix.matrix[i][j];
			}
		}
		return result;
	}
	else
		return 0;
	
}

//Need to fill matrix by created array[][]
void Matrix::FillByMatrix(int** _matrix, int _rows, int _cols)
{
	//ѕроблемы
	if (rows == _rows && cols == _cols)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				matrix[i][j] = i + j;
			}
		}
	}
	else
	{
		FillByRand();
	}
}


//Need to print matrix in console
void Matrix::PrintMatrix(string text)
{
	cout << "Matrix: " << text << endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int Matrix::FindMinInUnderDiagonal()
{
	int min = 1000000000;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j <= i; j++)
		{
			min = min > matrix[i][j] ? matrix[i][j] : min;
		}
	}
	return min;
}

int Matrix::FindMaxUpperDiagonal()
{
	int max = -10000000;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = i; j < cols; j++)
		{
			max = max < matrix[i][j] ? matrix[i][j] : max;
		}
	}
	return max;
}

Array::Array(int _length)
{
	cout << "Array standart constructor" << endl;
	length = _length;
	mass = new int [length];
	for (size_t i = 0; i < length; i++)
	{
		mass[i] = rand();
	}
}

Array::Array(const Array& copy_array)
{
	cout << "Array copy constructor" << endl;
	length = copy_array.length;
	mass = new int[length];
	for (size_t i = 0; i < length; i++)
	{
		mass[i] = copy_array.mass[i];
	}
	
}

Array::~Array()
{
	cout << "Array destructor" << endl;
	delete[] mass;
}

Array* Array::IntersectionOfArrays(Array f_array, Array s_array)
{
	Array* result_object;
	int* arr;
	int counter = 0;
	//проверка возможности пересечени€
	for (size_t i = 0; i < f_array.length; i++)
	{
		for (size_t j = 0; j < s_array.length; j++)
		{
			if (f_array.mass[i] == s_array.mass[j])
			{
				counter++;
			}
		}
	}
	// counter = 0 если элементы не пересекаютс€
	if (counter != 0)
	{
		result_object = new Array(counter);
		int index = 0;
		for (size_t i = 0; i < f_array.length; i++)
		{
			for (size_t j = 0; j < s_array.length; j++)
			{
				if (f_array.mass[i] == s_array.mass[j])
				{
					result_object->mass[index] = s_array.mass[j];
					index++;
				}
			}
		}
		return result_object;
	}
	else
		return result_object = new Array(0);
}

Array* Array::UnitArrays(Array f_array, Array s_array)
{
	Array* result_arr;
	int size = f_array.length + s_array.length;
	result_arr = new Array(size);
	for (size_t i = 0; i < result_arr->length; i++)
	{
		if (i < f_array.length)
		{
			result_arr->mass[i] = f_array.mass[i];
		}
		else
		{
			int index = i % (result_arr->length- 1);
			result_arr->mass[i] = s_array.mass[index];
		}
	}
	return result_arr;
}

void Array::Print(string text)
{
	cout << text << endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << mass[i] << "\t";
	}
	cout << endl;
}

void ViewSecondLab()
{
	//need to view all function and clear main
	cout << "Multiply" << endl;
	Matrix first_matrix(3, 2);
	Matrix second_matrix(2, 3);
	Matrix* multiply_matrix;
	first_matrix.FillByRand();
	first_matrix.PrintMatrix("first matrix");
	second_matrix.FillByRand();
	second_matrix.PrintMatrix("second matrix");
	multiply_matrix = Matrix::MultiplyMatrix(first_matrix, second_matrix);

	first_matrix.PrintMatrix("1");

	multiply_matrix->PrintMatrix("multiply");
	delete multiply_matrix;

	cout << "Sum of matrix" << endl;
	Matrix f_matrix(2, 2);
	Matrix s_matrix(2, 2);
	Matrix* sum_matrix;

	f_matrix.FillByRand();
	f_matrix.PrintMatrix("first matrix");
	s_matrix.FillByRand();
	s_matrix.PrintMatrix("second matrix");
	sum_matrix = Matrix::SumMatrix(f_matrix, s_matrix);

	sum_matrix->PrintMatrix("Sum matrix:");
	delete sum_matrix;
	
	cout << "Unit Array" << endl;
	Array first_mass(5);
	Array second_mass(5);
	first_mass.Print("first array");
	second_mass.Print("second array");
	Array* unit_object;
	unit_object = Array::UnitArrays(first_mass, second_mass);
	unit_object->Print("Unit array");
	delete unit_object;

	cout << "Intersection"<< endl;
	Array* intersection_array = Array::IntersectionOfArrays(first_mass, second_mass);
	intersection_array->Print("Array:");
	delete intersection_array;

	cout << "Finding min of under diagonal" << endl;
	Matrix matrix(5, 5);
	matrix.PrintMatrix("Matrix ");
	cout << "Minimum value under diagonal " << matrix.FindMinInUnderDiagonal() << endl;
	cout << "Maximum value upper diagonal " << matrix.FindMaxUpperDiagonal() << endl;
}