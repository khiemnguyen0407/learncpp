/* Overloading unary operator ! */

/*
Here’s another example. The ! operator is the logical negation operator -- if an expression 
evaluates to "true", operator! will return false, and vice-versa. We commonly see this applied to 
boolean variables to test whether they are true or not.

For integers, 0 evaluates to false, and anything else to true, so operator! as applied to integers 
will return true for an integer value of 0 and false otherwise. Extending the concept, we can say 
that operator! should evaluate to true if the state of the object is "false", "zero", or whatever 
the default initialization state is.
*/

#include <iostream>

class Point3D
{
private:
    double x {};
    double y {};
    double z {};

public:
    Point3D(double x=0, double y=0, double z=0) 
        : x { x }, y { y }, z { z } {}

    Point3D operator-() const;

    bool operator!() const;

    double get_x() const { return this->x; }
    double get_y() const { return this->y; }
    double get_z() const { return this->z; }
};

// Convert a Point into its negative equivalent
Point3D Point3D::operator-() const
{
    Point3D p {-this->x, -this->y, -this->z};
    return p;
}

bool Point3D::operator!() const
{
    return (this->x == 0.0 && this->y == 0.0 && this->z == 0.0);
}

int main()
{
    Point3D p1 {};   // use default constructor to set to (0.0, 0.0, 0.0)
    Point3D p2 {0.5, 1.0, 1.5};

    if (!p1) 
        std::cout << "Point p1 is set at the origin!\n";
    else
        std::cout << "Point p1 is not set at the origin!\n";

    if (!p2)
        std::cout << "Point p2 is set at the origin!\n";
    else
        std::cout << "Point p2 is not set at the origin!\n";

    return 0;
    
}