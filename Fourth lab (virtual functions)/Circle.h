#pragma once
#include "Shape.h"
class Circle final : public Shape
{
private:
	int r;
public:
	Circle(int _x, int _y, int _r) :Shape(_x, _y)
	{
		std::cout << "Circle constructor" << std::endl;
		r = _r;
	}
	~Circle()
	{
		std::cout << "Circle destructor" << std::endl;
		delete dots_x;
		delete dots_y;
	}
	void SetDots()
	{
		std::cout << "SetDots in circle" << std::endl;
	}
	string GetType()
	{
		return "Circle";
	}
	void Intersect(Shape* figure) override
	{
		if (this == figure)
		{
			cout << "Cant take myself by arg" << endl;
			return;
		}
		cout << "Now method find intersect between " << this->GetType() << " and " << figure->GetType() << endl;
		
	}
};

