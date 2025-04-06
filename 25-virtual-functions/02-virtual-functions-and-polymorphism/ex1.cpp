/* Virtual functions */

/* 
A quick recap: 
==============
In the previous lesson on "pointers and references to the base class of derived objects" (see cpp
files in the previous folder), we took at a look at a number of examples where using pointers or
references to a base class had the potential to simplify code. However, in every case, we ran up
against the problem that the base pointer or reference was only able to call the base version of a
function, not a derived version. In this lesson, we learn how to address this issue using virtual
functions.
*/

/*
Virtual functions
=================

A virtual function is a special type of member function that, when called, resolves to the 
most-derived version of the function for the actual type of the object being referenced or pointed 
to.

A derived function is considered a match if it has the same signature (name, parameter types, and 
whether it is const) and return type as the base version of the function. Such functions are called 
overrides.

To make a function virtual, simply place the "virtual" keyword before the function declaration.
*/

#include <iostream>
#include <string_view>

class Base
{
public:
    virtual std::string_view get_name() const   // note addition of virtual keyword
        { return "Base object"; } 
};

class Derived: public Base
{
public:
    virtual std::string_view get_name() const { return "Derived object"; }
};

int main()
{
    Base base {};
    Base& rBase { base };
    Base* pBase { &base };
    std::cout << "rBase is a " << rBase.get_name() << '\n';
    std::cout << "pBase points to a " << pBase->get_name() << '\n';
    std::cout << std::string (30, '=') << '\n';
    Derived derived {};
    Base& base_ref{ derived };
    Base* base_ptr{ &derived };
    std::cout << "base_ref is a " << base_ref.get_name() << '\n';
    std::cout << "base_ptr points to a " << base_ptr->get_name();

    return 0;
}

/* Discussion 

Because base_ref is a reference to the Base portion of a Derived object, when base_ref.get_name() 
is evaluated, it would normally resolve to Base::get_name(). However, Base::get_name() is virtual, 
which tells the program to go look and see if there are any more-derived versions of the function 
available for a Derived object. In this case, it will resolve to Derived::get_name()!
*/
