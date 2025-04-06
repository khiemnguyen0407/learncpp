/* The implicit copy assignment operator */

/*
Unlike other operators, the compiler will provide an implicit public copy assignment operator for 
your class if you do not provide a user-defined one. This assignment operator does memberwise 
assignment (which is essentially the same as the memberwise initialization that default copy 
constructors do).

Just like other constructors and operators, you can prevent assignments from being made by making 
your copy assignment operator private or using the delete keyword:
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
    Fraction(int numerator = 0, int denominator = 1)
        : numerator { numerator }, denominator { denominator }
    {
        assert(denominator != 0);
    }

	// Copy constructor
	Fraction(const Fraction &copy) = delete;

	// Overloaded assignment
	Fraction& operator= (const Fraction& fraction) = delete; // no copies through assignment!

	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.numerator << '/' << f1.denominator;
	return out;
}

int main()
{
    Fraction fiveThirds { 5, 3 };
    Fraction f;
    f = fiveThirds; // compile error, operator= has been deleted
    std::cout << f;

    return 0;
}