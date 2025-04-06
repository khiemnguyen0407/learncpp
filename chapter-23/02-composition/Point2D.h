#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D
{
private:
    int x;
    int y;

public:
    // A default constructor
    Point2D()
        : x{ 0 }, y{ 0 }
    {
    }

    // A specific constructor
    Point2D(int x, int y)
        : x{ x }, y{ y }
    {
    }

    // An overloaded output operator
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point)
    {
        out << '(' << point.x << ", " << point.y << ')';
        return out;
    }

    // Access functions
    void set_point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

};

#endif