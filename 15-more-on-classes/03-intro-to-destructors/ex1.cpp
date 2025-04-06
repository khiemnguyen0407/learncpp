/* Destructors */

/* In lesson "Constructors" we covered constructors, which are special member functions that are 
called when an object of a non-aggregate class type is created. Constructors are used to initialize 
members variables, and do any other set up tasks required to ensure objects of the class are ready 
for use.

Analogously, classes have another type of special member function that is called automatically when 
an object of a non-aggregate class type is destroyed. This function is called a destructor. 
Destructors are designed to allow a class to do any necessary clean up before an object of the 
class is destroyed.
*/

/* 
Destructor naming
=================

Like constructors, destructors have specific naming rules:

(1) The destructor must have the same name as the class, preceded by a tilde (~).
(2) The destructor can not take arguments.
(3) The destructor has no return type.

A class can only have a single destructor. Generally you should not call a destructor explicitly 
(as it will be called automatically when the object is destroyed), since there are rarely cases 
where you would want to clean up an object more than once.

Destructors may safely call other member functions since the object is not destroyed until after 
the destructor executes.
*/

#include <iostream>

class Simple
{
private:
    int id {};

public:
    Simple(int id)
        : id { id }
    {
        std::cout << "Constructing Simple " << id << '\n';
    }

    ~Simple() // here's our destructor
    {
        std::cout << "Destructing Simple " << id << '\n';
    }

    int get_ID() const { return id; }
};

int main()
{
    // Allocate a Simple
    Simple s1{ 1 };
    {
        Simple s2{ 2 };
    } // s2 dies here

    return 0;
} // s1 dies here

/* Discussion

Note that when each Simple object is destroyed, the destructor is called, which prints a message. 
"Destructing Simple 1" is printed after "Destructing Simple 2" because s2 was destroyed before the 
end of the function, whereas s1 was not destroyed until the end of main().
*/

/* 
An implicit destructor
======================

If a non-aggregate class type object has no user-declared destructor, the compiler will generate a 
destructor with an empty body. This destructor is called an implicit destructor, and it is 
effectively just a placeholder.

If your class does not need to do any cleanup on destruction, it's fine to not define a destructor 
at all, and let the compiler generate an implicit destructor for your class.
*/