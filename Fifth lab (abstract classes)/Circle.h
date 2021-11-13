#pragma once
#include "TwoDShape.h"
class Circle : public TwoDShape
{
private: 
	int r;
public: 
	Circle(int _r): TwoDShape()
	{
		x = 1;
		y = 1;	
		r = _r;
		area = r*r * 3.14;
		type = "TDCircle";
	}
	~Circle()
	{
		cout << "Destructor Circle" << endl;
	}
	void Draw()
	{
		cout << "Draw circle" << endl;
	}
};

