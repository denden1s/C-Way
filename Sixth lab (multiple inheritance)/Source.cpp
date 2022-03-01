using namespace std;
#include <iostream>
#include<iomanip>
#include <string>

class dot
{
	
public: 
	int x, y;
	dot(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void move(int _x, int _y)
	{
		x += _x;
		y += _y;
	}
	void view()
	{
		cout << x << " " << y << endl;
	}
};

class line
{
protected:
	int width;
public:
	dot* start;
	dot* end;
	line(int _width, dot s, dot e)
	{
		width = _width; 
		start = new dot(s);
		end = new dot(e);
	}
	line(int _width, dot* s, dot* e)
	{
		width = _width;
		start = s;
		end = e;
	}
};

class square : public dot,  public line
{
	dot* dots[4];
	line* lines[4];
	void SetSquare()
	{
		dots[0] = new dot(x, y);
		dots[1] = new dot(x + width, y);
		dots[3] = new dot(x, y + width);
		dots[2] = new dot(x + width, y + width);
		lines[0] = new line(width, start, end);
		int index = 2;
		for (size_t i = 1; i < 4; i++)
		{
			lines[i] = new line(width, dots[i], dots[index++ % 4]);
		}
	}
public:

	square(int _x, int _y, int _width) :dot(_x, _y), line(_width, new dot(_x,_y), new dot(_x+_width, _y))
	{
		SetSquare();
	}
	
	void viewSquare()
	{
		for (size_t i = 0; i < 4; i++)
		{
			cout << "Line start" << i << ": " << lines[i]->start->x << ";" << lines[i]->start->y << endl;
			cout << "Line end" << i << ": " << lines[i]->end->x << ";" << lines[i]->end->y << endl;
		}
	}
	void moveSquare(int posx, int posy)
	{
		for (size_t i = 0; i < 4; i++)
		{
			lines[i]->start->move(posx, posy);
			lines[i]->end->move(posx, posy);
		}
	}
};

int main()
{
	int flag = 0;
	setlocale(LC_ALL, "Russian");
	square sq(0, 0, 10);
}
