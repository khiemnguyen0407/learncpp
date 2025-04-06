/* Function overload differentiation */

/*/
we introduced the concept of function overloading, which allows us to create multiple functions 
with the same name, so long as each identically named function has different parameter types (or 
the functions can be otherwise differentiated).

Now, we'll take a closer look at how overloaded functions are differentiated. Overloaded functions 
that are not properly differentiated will cause the compiler to issue a compile error.

How overloaded functions are differentiated

Function property       |      Used for differentiation
=======================================================
Number of parameters    |      Yes
Type of parameters      |      Yes
Return type             |      No

Later, we shall learn also reference and classes. For completeness, we must mention that for member 
functions defined in a class, additional function-level qualifiers are also considered:

Function-level qualifer     |       Used for overloading
========================================================
const or volatile           |       Yes
ref-qualifiers              |       Yes
*/

/* Overloading based on number of parameters 

An overloaded function is differentiated so long as each overloaded function has a different number 
of parameters. The compiler can easily tell that a function call with two integer parameters should 
go to sum(int, int) and a function call with three integer parameters should go to 
sum(int, int, int).
*/

#include<iostream>
int sum(int x1, int x2)
{
    return x1 + x2;
}
int sum(int x1, int x2, int x3)
{
    return x1 + x2 + x3;
}

/* Overloading based on type of parameters

A function can also be differentiated so long as each overloaded function’s list of parameter types 
is distinct. For example, all of the following overloads are differentiated:
*/
int add(int x, int y)               // integer version
{
    return x + y;
}
double add(double x, double y)      // floating point version
{
    return x + y;
}
double add(int x, double y)         // mixed version func(int, double)
{
    return static_cast<double>(x) + y;
}
double add(double x, int y)         // mixed version func(double, int)
{
    return x + static_cast<double>(y);
}

int main()
{
    int x1 {1}, x2 {2}, x3 {3};
    std::cout << "x1 + x2 = " << sum(x1, x2) << '\n';
    std::cout << "x1 + x2 + x3 = " << sum(x1, x2, x3) << '\n';

    int x { 1 };
    double y { 2 };
    std::cout << "x + x = " << add(x, x) << '\n';
    std::cout << "y + y = " << add(y, y) << '\n';
    std::cout << "x + y = " << add(x, y) << '\n';
    std::cout << "y + x = " << add(y, x) << '\n';
}

/* The return type of a function is not considered for differentiation

A function's return type is not considered when differentiating overloaded functions.

Consider the case where you want to write a function that returns a random number, but you need a 
version that will return an int, and another version that will return a double. You might be 
tempted to do this:

int get_random_value();

double get_random_value();

When you compile you will see the compilation error and this makes sense. Imagine that you were the
compiler, and you saw the statement
get_random_value();

Which of the overloaded functions would you call? It's not clear and you cannot make decision 
without a lucky guess.
*/

/* Type signature
=================
A function's type signature (generally called a signature) is defined as the parts of the function 
header that are used for differentiation of the function. In C++, this includes the function name, 
number of parameters, parameter type, and function-level qualifiers. It notably does not include 
the return type.
*/



