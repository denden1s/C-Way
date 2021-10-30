#pragma once
#include "Shape.h"
class Square final : public Shape
{
private:
	int side;
public:
	Square(int x, int y, int s) : Shape(x, y)
	{
		std::cout << "Square constructor" << std::endl;
		side = s;
	}
	~Square()
	{
		std::cout << "Square destructor" << std::endl;
		delete dots_x;
		delete dots_y;
	}
	void SetDots()
	{
		std::cout << "SetDots in square" << std::endl;
	}
	string GetType() override
	{
		return "Square";
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

