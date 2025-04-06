/* A value-returning function that does not return a value will produce undefined behavior */

/*
A function that returns a value is called a value-returning function. A function is value-returning 
if the return type is anything other than void. A value-returning function must return a value of 
that type (using a return statement), otherwise undefined behavior will result.
*/

#include <iostream>

int get_value_from_user() // this function returns an integer value
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	// note: no return statement
}

// A modern compiler should generate a warning because get_value_from_user is defined as returning 
// an int but no return statement is provided. Running such a program would produce undefined 
// behavior, because get_value_from_user() is a value-returning function that does not return a 
// value.

int main()
{
	int num { get_value_from_user() }; // initialize num with the return value of get_value_from_user()

	std::cout << num << " doubled is: " << num * 2 << '\n';

	return 0;
}