/* Overloading operators for operands of different types */

/*
Often it is the case that you want your overloaded operators to work with operands that are 
different types. For example, if we have Cents(4), we may want to add the integer 6 to this to 
produce the result Cents(10).

When C++ evaluates the expression x + y, x becomes the first parameter, and y becomes the second 
parameter. When x and y have the same type, it does not matter if you add x + y or y + x -- either 
way, the same version of operator+ gets called. However, when the operands have different types, 
x + y does not call the same function as y + x.

For example, Cents(4) + 6 would call operator+(Cents, int), and 6 + Cents(4) would call 
operator+(int, Cents). Consequently, whenever we overload binary operators for operands of 
different types, we actually need to write two functions -- one for each case. 
*/

#include <iostream>

class Cents
{
private:
	int cents {};

public:
	explicit Cents(int cents) : cents{ cents } { }

	// add Cents + int using a friend function
	friend Cents operator+(const Cents& c1, int value);

	// add int + Cents using a friend function
	friend Cents operator+(int value, const Cents& c1);


	int get_cents() const { return cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, int value)
{
	// use the Cents constructor and operator+(int, int)
	// we can access cents directly because this is a friend function
	return Cents { c1.cents + value };
}

// note: this function is not a member function!
Cents operator+(int value, const Cents& c1)
{
	// use the Cents constructor and operator+(int, int)
	// we can access cents directly because this is a friend function
	return Cents { c1.cents + value };
}

int main()
{
	Cents c1{ Cents{ 23 } + 1 };
	Cents c2{ 20 + Cents{ 22 } };

	std::cout << "c1.cents = " << c1.get_cents() << " cents.\n";
	std::cout << "c2.cents = " << c2.get_cents() << " cents.\n";

	return 0;
}