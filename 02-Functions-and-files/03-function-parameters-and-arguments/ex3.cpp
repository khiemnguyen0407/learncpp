/* Using return values as arguments */

/*
We can transport the return value of a function to another function by using the return value as an 
argument in the function call. This is called chaining function calls.

For example, if we have a function that returns an integer, we can use the return value of that 
function as an argument in another function call. This is useful when we want to pass the result of 
one function to another function for further processing.
*/

#include <iostream>

int get_value_from_user()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void print_double(int value)
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
    // Without function chaining
    int num { get_value_from_user() }; // initialize num with the return value of get_value_from_user()
    print_double(num);
    // With function chaining
    // We can use the return value of get_value_from_user() as an argument in print_double()
	print_double(get_value_from_user());

	return 0;
}