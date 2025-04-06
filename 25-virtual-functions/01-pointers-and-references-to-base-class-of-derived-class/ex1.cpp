/* Pointers and references to the base class of derived objects */

/* 
We learned all about how to use inheritance to derive new classes from existing classes. In this
chapter, we are going to focus on one of the most important and powerful aspects of inheritance:
virtual functions. Before we discuss what virtual functions are, let us first set the table for why
we need them.

In the section on Construction of Derived Classes, we learned that when we create a derived class,
it is composed of multiple parts.

*/
#include <iostream>
#include <string_view>

class Base
{
protected:
    int value {};

public:
    Base(int value)
        : value{ value }
    {
    }

    std::string_view get_name() const { return "Base"; }
    int get_value() const { return value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    std::string_view get_name() const { return "Derived"; }
    int get_value_doubled() const { return value * 2; }
};

/* 
Pointers, references, and derived classes
=========================================
It should be fairly intuitive that we can set Derived pointers and references to Derived 
objects. 
*/

int main()
{
    Derived derived { 5 };
    std::cout << "derived is a " << derived.get_name() << " and has value " 
        << derived.get_value() << '\n';

    Base& derived_ref { derived };
    std::cout << "derived_ref is a " << derived_ref.get_name() << " and has value "
        << derived_ref.get_value() << '\n';

    Base* derived_ptr { &derived };
    std::cout << "derived_ptr is a " << derived_ptr->get_name() << " and has value "
        << derived_ptr->get_value() << '\n';

    // Since Derived has a Base part, a more interesting question is whether C++ will let us set
    // a Base pointer or reference to a Derived object.

    // Base& base_ref { derived };
    // Base* base_ptr { &derived };

    // std::cout << "derived is a " << derived.get_name() << " and has value" 
    //     << derived.get_value() << '\n';
    // std::cout << "base_ref is a " << base_ref.get_name() << " and has value " 
    //     << base_ref.get_value() << '\n';
    // std::cout << "base_ptr is a " << base_ptr->get_name() << " and has value " 
    //     << base_ptr->get_value() << '\n';

    // Note that this also means it is not possible to call Derived::get_value_doubled() using 
    // base_ref and base_ptr. They are unable to see anything in Derived.
    return 0;
}

/* Discussion:
As for the part using Base reference Base&, and Base pointer Base*, the result may not be quite 
what you were expecting at first! It turns out that because base_ref and base_ptr are a Base 
reference and pointer, they can only see members of Base (or any classes that Base inherited). So 
even though Derived::get_name() shadows (hides) Base::get_name() for Derived objects, the Base 
pointer/reference can not see Derived::get_name(). Consequently, they call Base::get_name(), which 
is why base_ref and base_ptr report that they are a Base rather than a Derived.

*/