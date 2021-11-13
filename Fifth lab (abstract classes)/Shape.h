#pragma once
#include <string>
#include <iostream>
using namespace std;
class Shape
{
protected:
	int x;
	int y;
	string type;
public:
	Shape()
	{
		x = 0;
		y = 0;
		type = "shape";
	}
	//pure virtual functions - чистая виртуальная функция
	virtual void Print()
	{
		cout << "Type: " << type<< endl;
	}
	virtual void Draw() = 0;
	virtual ~Shape()
	{
		cout << "call destructor" << endl;
	}
};

