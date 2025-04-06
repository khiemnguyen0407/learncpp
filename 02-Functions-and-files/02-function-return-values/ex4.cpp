/* A value-returning function that does not return a value will produce undefined behavior */

/*
A function that returns a value is called a value-returning function. A function is value-returning 
if the return type is anything other than void. A value-returning function must return a value of 
that type (using a return statement), otherwise undefined behavior will result.

In most cases, compilers will detect if you’ve forgotten to return a value. However, in some 
complicated cases, the compiler may not be able to properly determine whether your function returns 
a value or not in all cases, so you should not rely on this.

Function main will implicitly return 0 if no return statement is provided
=========================================================================
The only exception to the rule that a value-returning function must return a value via a return 
statement is for function main(). The function main() will implicitly return the value 0 if no 
return statement is provided. That said, it is best practice to explicitly return a value from 
main, both to show your intent, and for consistency with other functions (which will exhibit 
undefined behavior if a return value is not specified).

Functions can only return a single value
========================================
A value-returning function can only return a single value back to the caller each time it is called.
Note that the value provided in a return statement doesn’t need to be literal -- it can be the 
result of any valid expression, including a variable or even a call to another function that 
returns a value. There are various ways to work around the limitation of functions only being able 
to return a single value, which we will cover in future lessons.



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