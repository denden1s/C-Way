#pragma once
#include <iostream>
#include "Dot.h"
#include "Square.h"
using namespace std;
class Line
{
	friend class Square;
private:
	string color;
	Dot *startDot;
	Dot *endDot;

private:
	void ChangeDotPos(Dot& _dot, int _x, int _y)
	{
		_dot.SetPos(_x, _y);
	}
	void MoveLine(int x, int y)
	{
		startDot->Move(x, y);
		endDot->Move(x, y);
	}
public:
	Line(Dot _start, Dot _end)
	{
		startDot = new Dot(_start);
		endDot = new Dot(_end);
		//color = _color;
	}
	~Line()
	{
		cout << "Line Destructor" << endl;
		delete startDot;
		delete endDot;
	}
	void ViewStartDot()
	{
		startDot->View();
	}
	void ViewEndDot()
	{
		endDot->View();
	}
	void ViewInfo()
	{
		cout << "Position of start dot - " << startDot->GetX() << "; " << startDot->GetY() << "), Position of end dot -" <<
			endDot->GetX() << "; " << endDot->GetY() << "), Color of Line: " << color << endl;
	}
	int** GetDots()
	{
		int** a = new int*[2];
		a[0] = new int[startDot->GetX(), startDot->GetY()];
		a[1] = new int[endDot->GetX(), endDot->GetY()];
		return a;
	}
	void ChangeLineColor(string _color)
	{
		color = _color;
	}
	void ChangeDotsColor(string _color)
	{
		startDot->SetColor(_color);
		endDot->SetColor(_color);
	}
};