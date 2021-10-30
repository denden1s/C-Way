#include <iostream>
#include "arrays_head.h"
#include "second_lab.h"
#include "third_lab.h"
#include<iomanip>
#include "Circle.h"
#include "Shape.h"
#include "Triangle.h"
#include "Square.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Circle circle(100, 100, 50);
	Triangle triangle(100, 100, 25, 12, 45, 45);
	Square square(100, 100, 25);

	Square* s = new Square(square);
	Triangle* t = new Triangle(triangle);
	Circle* c = new Circle(circle);
	Shape* shapes[] = { c, s, t };

	for (size_t i = 0; i < 3; i++)
	{
		shapes[i]->SetDots();
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			shapes[i]->Intersect(shapes[j]);
			cout << endl;
		}
	}
	cin.get();

	return 0;
}
