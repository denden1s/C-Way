#pragma once
#include "TwoDShape.h"
class Square :
    public TwoDShape
{
private:
    int width;
public:
    Square(int _width): TwoDShape()
    {
        x = 2;
        y = 2;
        width = _width;
        area = width * width;
    }
    ~Square()
    {
        cout << "Destructor Square" << endl;
    }
    void Draw()
    {
        cout << "Draw square" << endl;
    }
};

