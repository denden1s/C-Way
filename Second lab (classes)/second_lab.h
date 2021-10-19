#include<iostream>
#include<iomanip>
using namespace std;

class Matrix
{
private:
	int** matrix;
	int rows;
	int cols;
	//C++ Like Pascal Case in functions
	
	
public:
	//�����������
	Matrix(int, int);


	//����������� �����������
	Matrix(const Matrix &);

	//����������
	~Matrix();
	void FillByRand();

	static Matrix* MultiplyMatrix(Matrix, Matrix);

	static Matrix* SumMatrix(Matrix, Matrix);

	void PrintMatrix(string);

	void FillByMatrix(int**, int, int);

	int FindMinInUnderDiagonal();
	int FindMaxUpperDiagonal();
	int GetCurrentElement(int, int);
};


class Array
{
private:
	int length;
	int* mass;
public:
	Array(int);
	Array(const Array&);
	~Array();
	static Array* IntersectionOfArrays(Array, Array);
	static Array* UnitArrays(Array, Array); 

	void Print(string);
};

void ViewSecondLab();