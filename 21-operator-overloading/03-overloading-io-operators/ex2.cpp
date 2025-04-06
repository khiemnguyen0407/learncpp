/* Overloading operator << */

/*
Overloading operator<< is similar to overloading operator+ (they are both binary operators), except 
that the parameter types are different.

Consider the expression std::cout << point. If the operator is <<, what are the operands? The left 
operand is the std::cout object, and the right operand is your Point class object. std::cout is 
actually an object of type std::ostream. Therefore, our overloaded function will look like this:

friend std::ostream& operator<< (std::ostream& out, const Point& point);

Implementation of operator<< for our Point class is fairly straightforward because C++ already 
knows how to output doubles using operator<<, and our members are all doubles, we can simply use 
operator<< to output the data members of our Point.
*/

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
    // overloading operator<<
    friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.x << ", " << point.y << ", " << point.z << ')';    // actual output done here
    return out;     // return std::ostream so we can chain calls to operator<<
}


int main()
{
    const Point point { 5.0, 6.0, 7.0 };

    std::cout << "My point is: " << point << " in Cartesian space.\n";

    // Without operator <<, we have to do this:
    std::cout << "My point is: ";
    point.print();
    std::cout << " in Cartesian space.\n";

    Point p1 { 1.5, 2.5, 3.5 };
    Point p2 { 0.5, 1.5, 2.5 };
    std::cout << p1 << " and " << p2;
}

/* 
This is pretty straightforward -- note how similar our output line is to the line in the print() 
function we wrote previously. The most notable difference is that std::cout has become parameter 
out (which will be a reference to std::cout when the function is called).

The trickiest part here is the return type. With the arithmetic operators, we calculated and 
returned a single answer by value (because we were creating and returning a new result). However, 
if you try to return std::ostream by value, you'll get a compiler error. This happens because 
std::ostream specifically disallows being copied.

Consider what would happen if our operator<< returned void instead. When the compiler evaluates 
std::cout << point << '\n', due to the precedence/associativity rules, it evaluates this expression 
as (std::cout << point) << '\n';. std::cout << point would call our void-returning overloaded 
operator<< function, which returns void. Then the partially evaluated expression becomes: 
void << '\n';, which makes no sense!

By returning the out parameter as the return type instead, (std::cout << point) returns std::cout. 
Then our partially evaluated expression becomes: std::cout << '\n';, which then gets evaluated 
itself!

Any time we want our overloaded binary operators to be chainable in such a manner, the left operand 
should be returned (by reference). Returning the left-hand parameter by reference is okay in this 
case -- since the left-hand parameter was passed in by the calling function, it must still exist 
when the called function returns. Therefore, we don’t have to worry about referencing something 
that will go out of scope and get destroyed when the operator returns.
*/