/* How parameters and return values work together */

/* 
By using both parameters and a return value, we can create functions that take data as input, do 
some calculation with it, and return the value to the caller.
*/

#include <iostream>

// add() takes two integers as parameters, and returns the result of their sum
// The values of x and y are determined by the function that calls add()
int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

// main takes no parameters
int main()
{
    std::cout << add(4, 5) << '\n'; // Arguments 4 and 5 are passed to function add()

    std::cout << add(1 + 2, 3 * 4) << '\n'; // within add() x=3, y=12, so x+y=15

    int a{ 5 };
    std::cout << add(a, a) << '\n'; // evaluates (5 + 5)

    std::cout << add(1, multiply(2, 3)) << '\n'; // evaluates 1 + (2 * 3)
    std::cout << add(1, add(2, 3)) << '\n'; // evaluates 1 + (2 + 3)
    return 0;
}

// Execution starts at the top of main. When add(4, 5) is evaluated, function add is called, with 
// parameter x being initialized with value 4, and parameter y being initialized with value 5. The 
// return statement in function add evaluates x + y to produce the value 9, which is then returned 
// back to main. This value of 9 is then sent to std::cout to be printed on the console.