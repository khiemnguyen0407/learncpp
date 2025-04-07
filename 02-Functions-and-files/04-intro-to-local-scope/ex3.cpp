/* Lifetime is a runtime property -- scope is a compile-time property */

/*
Remember, lifetime is a runtime property, and scope is a compile-time property, so although we are 
talking about both in the same program, they are enforced at different points.
*/

// Here's a slightly more complex example.

#include <iostream>

int add(int x, int y) // x and y are created and enter scope here
{
    // x and y are usable only within add()
    return x + y;
} // y and x go out of scope and are destroyed here

int main()
{
    int a{ 5 }; // a is created, initialized, and enters scope here
    int b{ 6 }; // b is created, initialized, and enters scope here

    // a and b are usable only within main()

    std::cout << add(a, b) << '\n'; // calls add(5, 6), where x=5 and y=6

    return 0;
} // b and a go out of scope and are destroyed here

// Parameters x and y are created when the add function is called, can only be seen/used within 
// function add, and are destroyed at the end of add. Variables a and b are created within function 
// main, can only be seen/used within function main, and are destroyed at the end of main.