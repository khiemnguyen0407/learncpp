/* Introduction to function overloading */

/*
Function overlading
===================
Function overloading allows us to create multiple functions with the same name, so long as each 
identically named function has different parameter types (or the functions can be otherwise 
differentiated). Each function sharing a name (in the same scope) is called an overloaded function 
(sometimes called an overload for short).
*/

#include<iostream>

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

int main()
{   std::cout << "using int add(int, int):\n";
    std::cout << "1 + 1 = " << add(1, 1) << '\n';
    std::cout << "using double add(double, double):\n";
    std::cout << "1.5 + 2.5 = " << add(1.5, 2.5) << '\n';
}

/* Discussion
================
The above program will compile. Although you might expect these functions to result in a naming 
conflict, that is not the case here. Because the parameter types of these functions differ, the 
compiler is able to differentiate these functions, and will treat them as separate functions that 
just happen to share a name.

Operators can also be overloaded in a similar manner. We will discuss operator overloading later in 
the future lessons.

Overload resolution:
====================
Additionally, when a function call is made to a function that has been overloaded, the compiler 
will try to match the function call to the appropriate overload based on the arguments used in the 
function call. This is called overload resolution.

Key point to understand:
========================
Functions can be overloaded so long as each overloaded function can be differentiated by the 
compiler. If an overloaded function can not be differentiated, a compile error will result.


*/

/* 
Making it compile
=================
In order for a program using overloaded functions to compile, two things have to be true:
    (1) Each overloaded function has to be differentiated from the others. We discuss how functions 
        can be differentiated in the next lesson, of course written in the cpp files.
    (2) Each call to an overloaded function has to resolve to an overloaded function. We discuss 
        how the compiler matches function calls to overloaded functions in the subsequent lesson, 
        down the road.

If an overloaded function is not differentiated, or if a function call to an overloaded function 
can not be resolved to an overloaded function, then a compile error will result.

In the next lesson (again in cpp files), we'll explore how overloaded functions can be 
differentiated from each other. Then, in the following lesson, we'll explore how the compiler 
resolves function calls to overloaded functions.
*/