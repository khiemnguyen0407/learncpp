/* Return values */

/*
When you write a user-defined function, you get to determine whether your function will return a 
value back to the caller or not. To return a value back to the caller, two things are needed.

(1) First, your function has to indicate what type of value will be returned. This is done by setting 
the function's return type, which is the type that is defined before the function's name.

(2) Second, inside the function that will return a value, we use a return statement to indicate the 
specific value being returned to the caller. The return statement consists of the return keyword, 
followed by an expression (sometimes called the return expression), ending with a semicolon.

When the return statement is executed:
(1) The return expression is evaluated to produce a value.
(2) The value produced by the return expression is copied back to the caller. This copy is called 
    the return value of the function.
(3) The function exits, and control returns to the caller.

The process of returning a copied value back to the caller is named return by value.

Nomenclature:
=============
The return expression produces the value to be returned. The return value is a copy of that value.

*/

#include <iostream>

int get_value_from_user()
{
    // get a value from the user
    std::cout << "Enter a number: ";
    int x {};
    std::cin >> x;

    return x; // return the value to the caller
}

int main()
{
    int x { get_value_from_user() }; // call the function and store the return value in x
    
    // print the value doubled
    std::cout << "The double of " << x << " is " << 2 * x << '\n';
    // print the value tripled
    std::cout << "The triple of " << x << " is " << 3 * x << '\n';
    // print the value squared
    std::cout << "The square of " << x << " is " << x * x << '\n';

    return 0;
}