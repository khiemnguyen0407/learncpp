/* Function templates */

/* 
Let's say you wanted to write a function to calculate the maximum of two numbers. You might want to 
write a max function for dealing with integers such as
    
    int max(int x, int y)

While the caller can pass different values into the function, the type of parameters is fixed, so
the caller can only pass in int values. That means this function really only works for integers 
(and types that can be converted/promoted to int).

So what happens later when you want to find max of two double values? Because C++ requires us to
specify the type of all functions parameters, the solution is then to create a new overloaded
version of max with parameters of type double:

    double max(double x, double y)

It is not surprising that the code for implementation of the double version of max is exactly the
same as for the int version of max (see the code below). In fact, this implementation works for 
many different data types: including int, double, long, long double, and even new data types that
we have created ourselves.

Having to create overloaded functions with the same implementation for each set of parameter types 
we want to support is a maintenance headache, a recipe for errors, and a clear violation of the 
DRY (don’t repeat yourself) principle. There’s a less-obvious challenge here as well: a programmer 
who wishes to use the max function may wish to call it with an argument type that the author of the 
max did not anticipate (and thus did not write an overloaded function for).

What we are really missing is some way to write a single version of max that can work with 
arguments of any type (even types that may not have been anticipated when the code for max was 
written). Normal functions are simply not up to the task here. Fortunately, C++ supports another 
feature that was designed specifically to solve this kind of problem.

The following code presents the problem described above. We shall present the solution to this
problem in the next cpp file using C++ templates.
*/
#include <iostream>

int max(int x, int y)
{
    return (x < y) ? y : x;
}

double max(double x, double y)
{
    return (x < y) ? y: x;
}

int main()
{
    std::cout << "WITH OVERLADING FUNCTION\n============================\n";
    int x1 { 10 };
    int x2 { 42 };
    int int_max { max(x1, x2) };
    std::cout << "max (int): " << int_max << '\n';
    std::cout << "max (int): " << max(x1, x2) << '\n';

    
    
    double d1 { 10.5 };
    double d2 { 42.0 };
    double double_max { max(d1, d2) };
    std::cout << "max (double): " << double_max << '\n';
    std::cout << "max (double): " << max(d1, d2) << '\n';
}