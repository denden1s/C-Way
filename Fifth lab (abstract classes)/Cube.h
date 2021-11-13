#pragma once
#include "ThreeDShape.h"
#include <iostream>
using namespace std;
class Cube :public ThreeDShape
{
private: 
	double a;
public:
	Cube(double _a)
	{
		x = 1;
		y = 2;
		z = 3;
		a = _a;
		volume = a * a * a;
	}
	~Cube()
	{
		cout << "Destructor Cube" << endl;
	}
	void Draw()
	{
		cout << "Draw square" << endl;
	}
};

