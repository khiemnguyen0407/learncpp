/* Overloading the arithmetic operators using friend functions */

/* 
Some of the most commonly used operators in C++ are the arithmetic operators -- that is, the plus 
operator (+), minus operator (-), multiplication operator (*), and division operator (/). Note that 
all of the arithmetic operators are binary operators -- meaning they take two operands -- one on 
each side of the operator. All four of these operators are overloaded in the exact same way.

It turns out that there are three different ways to overload operators: the member function way, 
the friend function way, and the normal function way. In this lesson, we’ll cover the friend 
function way (because it’s more intuitive for most binary operators). Next lesson, we’ll discuss 
the normal function way. Finally, in a later lesson in this chapter, we’ll cover the member 
function way. 
*/

/* Overloading operators using friend functions */


#include <iostream>

class Cents
{
private:
	int cents {};

public:
	Cents(int cents=0) : cents{ cents } { }
	

    // Overloading the plus operator (+) is as simple as declaring a function named operator+, giving 
    // it two parameters of the type of the operands we want to add, picking an appropriate return type, 
    // and then writing the function.

    // add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2);

    // Overloading the subtraction operator (-) is simple as well:
    friend Cents operator-(const Cents& c1, const Cents& c2);

    // See the difference between friend function
    friend void print_friend(const Cents& c);
    // and member function
    void print();
	int get_cents() const { return this->cents; }
};

// note: this function is not a member function!

Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access cents directly because this is a friend function
    // Cents result {c1.cents + c2.cents};
    // return result;
	return Cents { c1.cents + c2.cents };
}

void something(const Cents& c1)
{   
    return c1.cents;
}

Cents operator-(const Cents& c1, const Cents& c2)
{
    // use the Cents constructor and operator-(int, int)
	// we can access cents directly because this is a friend function
    return Cents { c1.cents - c2.cents };
}

void print_friend(const Cents& c)
{
    std::cout << "cents = " << c.cents << '\n';
}

void Cents::print()
{
    std::cout << "cents = " << this->cents << '\n';
}

int main()
{
    Cents* ptr;
    ptr = new Cents[2] { 24, 42 };
	Cents sum{ ptr[0] + ptr[1] };
	std::cout << "sum = " << sum.get_cents() << " cents.\n";

    Cents diff{ ptr[0] - ptr[1] };
    std::cout << "difference = " << diff.get_cents() << " cents.\n";

    std::cout << "For ptr[0] (using friend function): "; 
    print_friend(ptr[0]);
    std::cout << "For ptr[1] (using member function): "; 
    ptr[1].print();
    Cents c {42};
    // something(c);
    delete[] ptr;
	return 0;
}

/* 
Dicussion:
==========
In the case of our Cents object, implementing our operator+() function is very simple. First, the 
parameter types: in this version of operator+, we are going to add two Cents objects together, so 
our function will take two objects of type Cents. Second, the return type: our operator+ is going 
to return a result of type Cents, so that’s our return type.

Finally, implementation: to add two Cents objects together, we really need to add the cents member 
from each Cents object. Because our overloaded operator+() function is a friend of the class, we 
can access the cents member of our parameters directly. Also, because cents is an integer, and 
C++ knows how to add integers together using the built-in version of the plus operator that works
with integer operands, we can simply use the + operator to do the adding.
*/