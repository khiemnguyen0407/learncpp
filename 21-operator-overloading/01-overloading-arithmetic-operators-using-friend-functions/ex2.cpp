/* Friend functions can be defined inside the class */

/* Even though friend functions are not members of the class, they can still be defined inside the
class if desired. */

#include <iostream>

class Cents
{
private:
	int cents {};

public:
	explicit Cents(int cents) : cents{ cents } { }

	// add Cents + Cents using a friend function
        // This function is not considered a member of the class, even though the definition is inside the class
	friend Cents operator+(const Cents& c1, const Cents& c2)
	{
		// use the Cents constructor and operator+(int, int)
		// we can access cents directly because this is a friend function
		return Cents { c1.cents + c2.cents };
	}
    // This is fine for overloaded operators with trivial implementations.

	int get_cents() const { return cents; }
};

int main()
{
	Cents c1{ 24 };
	Cents c2{ 42 };
	Cents sum{ c1 + c2 };
	std::cout << "I have " << sum.get_cents() << " cents.\n";

	return 0;
}