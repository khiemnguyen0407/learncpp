/* std::make_unique */

/* C++14 comes with an additional function named std::make_unique(). This templated function 
constructs an object of the template type and initializes it with the arguments passed into the 
function.
*/

#include <memory> // for std::unique_ptr and std::make_unique
#include <iostream>

class Fraction
{
private:
	int numerator{ 0 };
	int denominator{ 1 };

public:
	Fraction(int numerator = 0, int denominator = 1) :
		numerator{ numerator }, denominator{ denominator }
	{
	}

	friend std::ostream& operator<<(std::ostream& out, const Fraction &f1)
	{
		out << f1.numerator << '/' << f1.denominator;
		return out;
	}
};


int main()
{
	// Create a single dynamically allocated Fraction with numerator 3 and denominator 5
	// We can also use automatic type deduction to good effect here
	auto f1{ std::make_unique<Fraction>(3, 5) };
	std::cout << *f1 << '\n';

	// Create a dynamically allocated array of Fractions of length 4
	auto f2{ std::make_unique<Fraction[]>(4) };
    for (int i {0}; i < 4; ++i)
	    std::cout << f2[i] << '\t';
    std::cout << '\n';

	return 0;
}