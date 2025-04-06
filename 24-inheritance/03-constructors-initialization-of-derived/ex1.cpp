/* Constructors and initialization of derived classes */

/* 
In this lesson, we’ll take a closer look at the role of constructors in the initialization of 
derived classes.

In all of the examples so far, when we instantiate a Derived class object, the Base class portion 
has been created using the default Base constructor. Why does it always use the default Base 
constructor? Because we never told it to do otherwise!

Fortunately, C++ gives us the ability to explicitly choose which Base class constructor will be 
called! To do this, simply add a call to the Base class constructor in the member initializer list 
of the derived class.
*/

#include<iostream>
class Base
{
public:
    int id {};

    Base(int id=0)
        : id { id }
    {
    }

    int get_ID() const { return id; }
};

class Derived: public Base
{
public:
    double value {};

    Derived(double value=0.0, int id=1)
        : Base { id }
        , value{ value }
    {
    }

    double get_value() const { return value; }

    void set_value(double v)  { this->value = v; }

    int get_ID() const { return (id + 1); }
};

int main()
{
    Derived derived { 4.2, 42 };
    std::cout << "Id: " << derived.get_ID() << '\n';
    std::cout << "Value: " << derived.get_value() << '\n';

}

/* Discussion

In more detail, here's what happens in the above program.
(1) Memory for derived is allocated.
(2) The Derived(double, int) constructor is called, where cost = 4.2, and id = 42.
(3) The compiler looks to see if we’ve asked for a particular Base class constructor. 
    We have! So it calls Base(int) with id = 42.
(4) The base class constructor member initializer list sets id to 42.
(5) The base class constructor body executes, which does nothing.
(6) The base class constructor returns.
(7) The derived class constructor member initializer list sets value to 4.2.
(8) The derived class constructor body executes, which does nothing.
(9) The derived class constructor returns.

This may seem somewhat complex, but it’s actually very simple. All that's happening is that the 
Derived constructor is calling a specific Base constructor to initialize the Base portion of the 
object. Because id lives in the Base portion of the object, the Base constructor is the only 
constructor that can initialize that value.

Note that it doesn't matter where in the Derived constructor member initializer list the Base 
constructor is called -- it will always execute first.

*/