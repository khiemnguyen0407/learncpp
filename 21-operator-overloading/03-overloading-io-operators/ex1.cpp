/* Overloading the I/O operators */
/*
For classes that have multiple member variables, printing each of the individual variables on the
screen can get tiresome fast. Of course, makes more sense to print member variables using a resuable
function. We have done that so far using print() functions. 
*/

// For example, we can print a Point using member function print()

#include<iostream>

class Point
{
private:
    double x {};
    double y {};
    double z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0) : x {x}, y { y }, z { z }
    {}

    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_z() const { return z; }

    void print() const
    {
        std::cout << "Point(" << x << ", " << y << ", " << z << ")";
    }
    // While this is much better, it still has some downsides. Because print() returns void, it 
    // cannot be called in the middle of an output statement.
};

int main()
{
    const Point point { 5.0, 6.0, 7.0 };

    // Without operator <<, we have to do this:
    std::cout << "My point is: ";
    point.print();
    std::cout << " in Cartesian space.\n";

    // Of course, we wish to do the following
    // cout << "My point is: " << point << " in Cartesian space.\n";
    // This will be done in ex2.cpp
}