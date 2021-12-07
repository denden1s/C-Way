#pragma once
#include "Dot.h"
#include "Line.h"
class Square
{
private:
	Line* lines[4];
	string color;
public:
	Square(Dot dots[4])
	{
		int xOrient = 0;
		int yOrient = 0;
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = i+1; j < 4; j++)
			{
				if (dots[i].GetX() == dots[j].GetX())
				{
					xOrient++;
				}
				if (dots[i].GetY() == dots[j].GetY())
				{
					yOrient++;
				}
			}
		}
		if (xOrient == 2 && yOrient == 2)
		{
			int index = 0;
			for (size_t i = 0; i < 3; i++)
			{
				for (size_t j = i + 1; j < 4; j++)
				{
					if (dots[i].GetX() == dots[j].GetX() || dots[i].GetY() == dots[j].GetY())
					{
						lines[index] = new Line(dots[i], dots[j]);
						index++;
					}
				}
				
			}
		}
		else
		{
			cout << "Square cant be created" << endl;
			delete this;
		}
	}
	~Square()
	{
		cout << "delete square" << endl;
		for (size_t i = 0; i < 4; i++)
		{
			delete lines[i];
		}
	}
	void ViewCoordinate()
	{
		for (size_t i = 0; i < 4; i++)
		{ 
			cout << "Dot " << i + 1 <<" ";
			lines[i]->ViewStartDot();
			lines[i]->ViewEndDot();
			cout << endl;
		}
	}
	void Move(int _x, int _y)
	{
		cout << "Move square" << endl;
		for (size_t i = 0; i < 4; i++)
		{
			lines[i]->MoveLine(_x, _y);
		}
	}
	void ChangeColor(string lineColor, string dotColor)
	{
		for (size_t i = 0; i < 4; i++)
		{
			lines[i]->ChangeLineColor(lineColor);
			lines[i]->ChangeDotsColor(dotColor);
		}
	}
};

