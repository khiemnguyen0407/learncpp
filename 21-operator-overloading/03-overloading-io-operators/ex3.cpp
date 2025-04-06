/* Overloading operator>> */

/* 
It is also possible to overload the input operator. This is done in a manner analogous to 
overloading the output operator. The key thing you need to know is that std::cin is an object of 
type std::istream. 
*/

#include <iostream>

class Point
{
private:
    double x {};
    double y {};
    double z {};

public:
    Point(double x=0.0, double y=0.0, double z=0.0) : x { x }, y { y}, z { z } {}

    // overloading operator<<
    friend std::ostream& operator<< (std::ostream& out, const Point& point);

    // overloading operator>>
    friend std::istream& operator>> (std::istream& in, Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // Since operator<< is a friend of the Point class, we can access Point's members directly.
    out << "Point(" << point.x << ", " << point.y << ", " << point.z << ")";

    return out;
}

// note that point must be non-const so we can modify the object
std::istream& operator>> (std::istream& in, Point& point)
{
    // This version subject to partial extraction issues (see below)
    in >> point.x >> point.y >> point.z;

    return in;
}

int main()
{
    std::cout << "Enter a point: ";
    Point point { 1.2, 2.3, 3.4 };  // non-zero test data
    std::cin >> point;
    std::cout << "You entered: " << point << '\n';

    return 0;
}
