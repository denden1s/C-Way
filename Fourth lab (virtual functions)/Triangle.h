#pragma once
#include "Shape.h"
class Triangle final:
    public Shape
{
private:
    int firstSide, secondSide, angle, secondAngle;
public:
    Triangle(int x, int y, int side, int sSide, int _angle, int sAngle) : Shape(x, y)
    {
        std::cout << "Triangle constructor" << std::endl;
        firstSide = side;
        secondSide = sSide;
        angle = _angle;
        secondAngle = sAngle;
    }
    ~Triangle()
    {
        std::cout << "Triangle destructor" << std::endl;
        delete dots_x;
        delete dots_y;
    }
    void SetDots()
    {
        std::cout << "SetDots Triangle" << endl;
    }
    string GetType() override
    {
        return "Triangle";
    }
    void Intersect(Shape* figure) override
    {
        if (this == figure)
        {
            cout << "Cant take myself by arg" << endl;
            return;
        }
        cout << "Now method find intersect between " << this->GetType() << " and " << figure->GetType() << endl;
    }
};

