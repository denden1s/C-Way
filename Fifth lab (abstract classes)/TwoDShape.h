#pragma once
#include "Shape.h"
#include <string>
#include <iostream>
using namespace std;
class TwoDShape : 
	public Shape
{
protected: 
	double area;
public:
	TwoDShape() : Shape()
	{
		area = 0;
		type = "TwoDShape";
	}
	virtual double Area()
	{
		return area;
	}
	virtual void Draw() = 0;
};

