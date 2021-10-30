#pragma once
#include <iostream>
#include <typeinfo>
class Shape
{
private:
	int x, y;
protected:
	int* dots_x;
	int* dots_y;
public:
	Shape(int _x,int _y)
	{
		std::cout << "Shape constructor"<<std::endl;
		x = _x;
		y = _y;
	}
	~Shape()
	{
		std::cout << "Shape destructor" << std::endl;
		delete dots_x;
		delete dots_y;
	}

	virtual void SetDots()
	{
		std::cout << "SetDots in Shape" << std::endl;
	}
	virtual string GetType() { return ""; }
	virtual void Intersect(Shape*) {}
};

