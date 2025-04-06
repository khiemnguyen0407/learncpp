/* Overloading the assignment operator */

/*
The copy assignment operator (operator=) is used to copy values from one object to another already 
existing object.

Copy Assignment versus Copy Constructor
=======================================
The purpose of the copy constructor and the copy assignment operator are almost equivalent -- both 
copy one object to another. However, the copy constructor initializes new objects, whereas the 
assignment operator replaces the contents of existing objects.

The difference between the copy constructor and the copy assignment operator causes a lot of 
confusion for new programmers, but it's really not all that difficult. Summarizing:

* If a new object has to be created before the copying can occur, the copy constructor is used 
  (note: this includes passing or returning objects by value).

* If a new object does not have to be created before the copying can occur, the assignment operator 
  is used.

Overloading the assignment operator
===================================
Overloading the copy assignment operator (operator=) is fairly straightforward, with one specific 
caveat that we will get to. The copy assignment operator must be overloaded as a member function.
*/

#include <cassert>
#include <iostream>

class Fraction
{
private:
	int numerator { 0 };
	int denominator { 1 };

public:
	// Default constructor
	Fraction(int numerator = 0, int denominator = 1 )
		: numerator { numerator }, denominator { denominator }
	{
		assert(denominator != 0);
	}

	// Copy constructor
	Fraction(const Fraction& copy)
		: numerator { copy.numerator }, denominator { copy.denominator }
	{
		// no need to check for a denominator of 0 here since copy must already be a valid Fraction
		std::cout << "Copy constructor called\n"; // just to prove it works
	}

	// Overloaded assignment
	Fraction& operator= (const Fraction& fraction);

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.numerator << '/' << f1.denominator;
	return out;
}

// A simplistic implementation of operator=
Fraction& Fraction::operator= (const Fraction& fraction)
{
    // do the copy
    numerator = fraction.numerator;
    denominator = fraction.denominator;

    // return the existing object so we can chain this operator
    return *this;
}

int main()
{
    Fraction f1 { 5, 3 };
    Fraction f2;
    f2 = f1; // calls overloaded assignment
    std::cout << f2;

    return 0;
}