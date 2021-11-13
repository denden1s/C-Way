// oop_labs.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "arrays_head.h"
#include "second_lab.h"
#include "third_lab.h"
#include "Shape.h"
#include "TwoDShape.h"
#include "ThreeDShape.h"
#include "Circle.h"
#include "Pyramid.h"
#include<iomanip>
#include "Square.h"
#include "Cube.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	Circle c(5);
	Square sq(2);
	TwoDShape *TwoD[] = { &c, &sq };
	Pyramid pyr(10, 15);
	Cube cb(11);
	ThreeDShape* ThreeD[] = { &pyr, &cb };

	for (size_t i = 0; i < 2; i++)
	{
		cout << "Area: " << TwoD[i]->Area() << endl;
		TwoD[i]->Print();
		TwoD[i]->Draw();
		cout << endl;
	}
	for (size_t i = 0; i < 2; i++)
	{
		cout << "Volume: " << ThreeD[i]->Volume() << endl;
		ThreeD[i]->Print();
		ThreeD[i]->Draw();
		cout << endl;
	}

	cin.get();

	return 0;
}
