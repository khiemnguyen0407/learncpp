/* Where to define local variables */

/* 
In modern C++, the best practice is that local variables inside the function body should be defined 
as close to their first use as reasonable.
*/

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int x{};       // x defined here
	std::cin >> x; // and used here

	std::cout << "Enter another integer: ";
	int y{};       // y defined here
	std::cin >> y; // and used here

	int sum{ x + y }; // sum can be initialized with intended value
	std::cout << "The sum is: " << sum << '\n';

	return 0;
}

// In the above example, each variable is defined just before it is first used. There is no need to 
// be strict about this -- if you prefer to swap lines 5 and 6, that’s fine.

/* Best practice:
=================
Define your local variables as close to their first use as reasonable.

When a variable is needed within a function:
(*) Use a function parameter when the caller will pass in the initialization value for the variable 
    as an argument.
(*) Use a local variable otherwise.
*/