/* How parameters and arguments work together */

/*
When a function is called, all of the parameters of the function are created as variables, and the 
value of each of the arguments is copied into the matching parameter (using copy initialization). 
This process is called pass by value. Function parameters that utilize pass by value are called 
value parameters.
*/

#include <iostream>

// This function has two integer parameters, one named x, and one named y
// The values of x and y are passed in by the caller
void print_two_integers(int x, int y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

int main()
{
    print_two_integers(6, 7); // This function call has two arguments, 6 and 7

    return 0;
}

// When function print_two_integers is called with arguments 6 and 7, print_two_integers's parameter 
// x is created and initialized with the value of 6, and print_two_integers's parameter y is created
//  and initialized with the value of 7.