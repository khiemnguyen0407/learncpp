/* Order of construction of derived classes */

/* In this lesson, we’re going to take a closer look at the order of construction that happens when 
a derived class is instantiated. First, let's introduce some new classes that will help us 
illustrate some important points. */

/*
Base Class --> Derived Class
Super Class --> Sub Class
Parent Class --> Child Class

*/





#include<iostream>
class Base
{
public:
    int id {};

    Base(int id=0)
        : id { id }
    {   
        std::cout << "Base is constructed.\n";
    }

    int get_ID() const { return id; }
};

class Derived: public Base
{
public:
    double value {};

    Derived(double value=0.0)
        : value { value }
    {
        std::cout << "Derived is constructed.\n";
    }

    double get_value() const { return value; }
};

/* Discussion:

Because Derived inherits functions and variables from Base, you may assume that the members of 
Base are copied into Derived. However, this is not true. Instead, we can consider Derived as a two 
part class: one part Derived, and one part Base.
*/


int main()
{
    std::cout << "Instantiating Base:\n";
    Base base;

    std::cout << "\nInstantiating Derived:\n";
    Derived derived;
    return 0;
}

/* Further discussion:

As mentioned above, Derived is really two parts: a Base part, and a Derived part. When C++ 
constructs derived objects, it does so in phases. First, the most-base class (at the top of the 
inheritance tree) is constructed. Then each child class is constructed in order, until the 
most-child class (at the bottom of the inheritance tree) is constructed last.

So when we instantiate an instance of Derived, first the Base portion of Derived is constructed 
(using the Base default constructor). Once the Base portion is finished, the Derived portion is 
constructed (using the Derived default constructor). At this point, there are no more derived 
classes, so we are done.

As you can see, when we constructed Derived, the Base portion of Derived got constructed first. 
This makes sense: logically, a child can not exist without a parent. It’s also the safe way to do 
things: the child class often uses variables and functions from the parent, but the parent class 
knows nothing about the child. Instantiating the parent class first ensures those variables are 
already initialized by the time the derived class is created and ready to use them.
*/