/* Constructors and initialization of derived classes: Continued */

/*
Now that we learn how to initialize base class members, there's no need to keep our member variables
public. We make our member variables private again, as they should be.

As a quick refresher, public members can be accessed by anybody. Private members can only be 
accessed by member functions of the same class. Note that this means derived classes can not 
access private members of the base class directly! Derived classes will need to use access 
functions to access private members of the base class.
*/

#include<iostream>

class Base
{
private:    // members are private in this example, and generally should be
    int id {};

public:
    Base(int id=0)
    : id { id }
    {
    }

    int get_ID() const { return id; }
};

class Derived: public Base
{
private:    // members are private in this example, and generally should be
    double value {};

public: 
    Derived(double value=0.0, int id=0)
        : Base { id }
        , value {value}
    {
    }

    double get_value() const { return value; }
};

int main()
{
    Derived derived {4.2, 42};
    std::cout << "ID: " << derived.get_ID() << '\n';
    std::cout << "Value: " << derived.get_value() << '\n';

    return 0;
}