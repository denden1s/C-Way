#pragma once
#include "ThreeDShape.h"
using namespace std;
class Pyramid :
    public ThreeDShape
{
	private:
		double h, s;
public:
	Pyramid(double _h, double _s): ThreeDShape()
	{
		x = 1;
		y = 1;
		z = 1;
		h = _h;
		s = _s;
		type = "ThreeDPyramid";
		volume = (s * h) / 3;
	}
	~Pyramid()
	{
		cout << "Pyramid destructor" << endl;
	}
	void Print()
	{
		cout << "Type: " << type << " Height: " << h << endl;
	}
	void Draw()
	{
		cout << "Draw ThreeDPyramid" << endl;
	}
};

