/* Define your own copy constructor */

#include <iostream>

class Fraction
{
private:
    int numerator{ 0 };
    int denominator{ 1 };

public:
    // Default constructor
    Fraction(int numerator=0, int denominator=1)
        : numerator{numerator}, denominator{denominator}
    {
    }


    // Copy constructor
    Fraction(const Fraction& fraction)
        // Initialize our members using the corresponding member of the parameter
        : numerator{ fraction.numerator }
        , denominator{ fraction.denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    void print() const
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // Calls Fraction(const Fraction&) copy constructor

    f.print();
    fCopy.print();

    return 0;
}

/*
Prefer the implicit copy constructor: Unlike the implicit default constructor, which does nothing 
(and thus is rarely what we want), the memberwise initialization performed by the implicit copy 
constructor is usually exactly what we want. Therefore, in most cases, using the implicit copy 
constructor is perfectly fine.

Best practice:
==============
Prefer the implicit copy constructor, unless you have a specific reason to create your own.


The copy constructor’s parameter must be a reference
====================================================

It is a requirement that the parameter of a copy constructor be an lvalue reference or const lvalue 
reference. Because the copy constructor should not be modifying the parameter, using a const lvalue 
reference is preferred.
*/