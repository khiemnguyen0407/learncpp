/* Overloading operators using member functions */

/*
you learned how to overload the arithmetic operators using friend functions. You also learned you 
can overload operators as normal functions. Many operators can be overloaded in a different way: 
as a member function.

Overloading operators using a member function is very similar to overloading operators using a 
friend function. When overloading an operator using a member function:

    * The overloaded operator must be added as a member function of the left operand.
    * The left operand becomes the implicit *this object.
    * All other operands become function parameters.

As a reminder, here's how we overloaded operator+ using a friend function:
class Cents
{
private:
    int cents {};

public:
    Cents(int cents)
        : cents { cents } { }

    // Overload Cents + int
    friend Cents operator+(const Cents& cents, int value);

    int get_cents() const { return this->cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& cents, int value)
{
    return Cents(cents.cents + value);
}
*/

/* 
Converting a friend overloaded operator to a member overloaded operator is easy:
(1) The overloaded operator is defined as a member instead of a friend 
    (Cents::operator+ instead of friend operator+)
(2) The left parameter is removed, because that parameter now becomes the implicit *this object.
(3) Inside the function body, all references to the left parameter can be removed (e.g. cents.cents
    becomes cents, which implicitly references the *this object).
*/

#include <iostream>

class Cents
{
private:
    int cents {};

public:
    Cents(int cents) : cents { cents } {}

    // Overload Cents + int
    Cents operator+(int value) const;
    
    int get_cents() const { return this->cents; }
};

Cents Cents::operator+(int value) const
{
    return Cents {this->cents + value};
}

int main()
{
    const Cents c1 { 24 };
    const Cents c2 { c1 + 18 }; // c1.operator+(18);

    std::cout << "I have " << c2.get_cents() << " cents.\n";
}

/*
If we can overload an operator as a friend or a member, which should we use? In order to answer 
that question, there's a few more things you will need to know.

Not everything can be overloaded as a friend function
=====================================================
The assignment (=), subscript ([]), function call (()), and member selection (->) operators must be 
overloaded as member functions, because the language requires them to be.


Not everything can be overloaded as a member function
=====================================================
We overloaded operator<< for our Point class using the friend function method. However, we are not 
able to overload operator<< as a member function. Why not? Because the overloaded operator must be 
added as a member of the left operand. In this case, the left operand is an object of type 
std::ostream. std::ostream is fixed as part of the standard library. We can’t modify the class 
declaration to add the overload as a member function of std::ostream. This necessitates that 
operator<< be overloaded as a normal function (preferred) or a friend.

Similarly, although we can overload operator+(Cents, int) as a member function (as we did above), 
we cannot overload operator+(int, Cents) as a member function, because int isn’t a class we can add 
members to.
*/