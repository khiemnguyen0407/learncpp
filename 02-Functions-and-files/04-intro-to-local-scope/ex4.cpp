/* Functional separation */

// In the last example in ex3.cpp, it's easy to see that variables a and b are different variables
// from x and y.

#include <iostream>

int add(int x, int y) // add's x and y are created and enter scope here
{
    // add's x and y are visible/usable within this function only
    return x + y;
} // add's y and x go out of scope and are destroyed here

int main()
{
    int x{ 5 }; // main's x is created, initialized, and enters scope here
    int y{ 6 }; // main's y is created, initialized, and enters scope here

    // main's x and y are usable within this function only
    std::cout << add(x, y) << '\n'; // calls function add() with x=5 and y=6

    return 0;
} // main's y and x go out of scope and are destroyed here

/* Explanation:
In this example, all we've done is change the names of variables a and b inside of function main to 
x and y. This program compiles and runs identically, even though functions main and add both have 
variables named x and y. Why does this work?

First, we need to recognize that even though functions main and add both have variables named x and 
y, these variables are distinct. The x and y in function main have nothing to do with the x and y 
in function add -- they just happen to share the same names.

Second, when inside of function main, the names x and y refer to main’s locally scoped variables x 
and y. Those variables can only be seen (and used) inside of main. Similarly, when inside function 
add, the names x and y refer to function parameters x and y, which can only be seen (and used) 
inside of add.

In short, neither add nor main know that the other function has variables with the same names. 
Because the scopes do not overlap, it’s always clear to the compiler which x and y are being 
referred to at any time.

KEY POINTS:
===========
Names used for function parameters or variables declared in a function body are only visible within 
the function that declares them. This means local variables within a function can be named without 
regard for the names of variables in other functions. This helps keep functions independent.
*/