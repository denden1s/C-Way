#pragma once
#include "Shape.h"
#include <iostream>
class ThreeDShape : public Shape
{
protected:
	int z;
	double volume;
public:
	ThreeDShape(): Shape()
	{
		z = 0;
		volume = 0;
		type = "ThreeDShape";
	}
	virtual double Volume()
	{
		return volume;
	}
	virtual void Draw() = 0;
};

