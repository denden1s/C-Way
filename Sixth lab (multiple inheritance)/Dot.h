#pragma once
#include <string>
#include <iostream>
#include "Square.h"
using namespace std;
class Dot
{
	friend class Line;
	friend class Square;
private:
	int x, y;
	string color;
	void SetPos(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void Move(int _x = 0, int _y = 0)
	{
		x += _x;
		y += _y;
	}
	void SetColor(string _color)
	{
		color = _color;
	}
protected:
	
public:
	Dot(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	Dot(const Dot& dot)
	{
		x = dot.x;
		y = dot.y;
	}
	~Dot()
	{
		cout << "delete dot" << endl;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	string GetColor()
	{
		return color;
	}
	void View()
	{
		cout << "X: " << GetX() << " Y: " << GetY() << endl;
	}
};

