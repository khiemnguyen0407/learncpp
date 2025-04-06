/* R-value references */

/*
C++11 adds a new type of reference called an r-value reference. An r-value reference is a reference 
that is designed to be initialized with an r-value (only). While an l-value reference is created 
using a single ampersand, an r-value reference is created using a double ampersand.

R-value references have two properties that are useful. First, r-value references extend the 
lifespan of the object they are initialized with to the lifespan of the r-value reference (l-value 
references to const objects can do this too). Second, non-const r-value references allow you to 
modify the r-value!
*/

#include <iostream>

class Fraction
{
private:
	int numerator { 0 };
	int denominator { 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		numerator{ numerator }, denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
	{
		out << f1.numerator << '/' << f1.denominator;
		return out;
	}
};

int main()
{
	auto&& rref{ Fraction{ 3, 5 } }; // r-value reference to temporary Fraction

    // This will give error as we cannot bind non-const lvalue reference to an rvalue
    // auto& lref { Fraction{ 4, 5 } }; 

	// f1 of operator<< binds to the temporary, no copies are created.
	std::cout << rref << '\n';

    // Now, let us take a look at a less intuitive example
    int&& rref_int { 5 };
    rref_int = 10;
    std::cout << rref_int << '\n';

	return 0;
} // rref (and the temporary Fraction) goes out of scope here

/* As an anonymous object, Fraction(3, 5) would normally go out of scope at the end of the 
expression in which it is defined. However, since we’re initializing an r-value reference with it, 
its duration is extended until the end of the block. We can then use that r-value reference to 
print the Fraction’s value.

While it may seem weird to initialize an r-value reference with a literal value and then be able 
to change that value, when initializing an r-value reference with a literal, a temporary object is 
constructed from the literal so that the reference is referencing a temporary object, not a literal 
value.

R-value references are not very often used in either of the manners illustrated above.
*/