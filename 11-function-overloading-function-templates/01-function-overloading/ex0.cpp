/*
Consider the following function:

int add(int x, int y)
{
    return x + y;
}

This trivial function adds two integers and returns an integer result. However, what if we also 
want a function that can add two floating point numbers? This add() function is not suitable, as 
any floating point parameters would be converted to integers, causing the floating point arguments 
to lose their fractional values.

One way to work around this issue is to define multiple functions with slightly different names:

int addInteger(int x, int y)
{
    return x + y;
}

double addDouble(double x, double y)
{
    return x + y;
}

However, for best effect, this requires that you define a consistent function naming standard for 
similar functions that have parameters of different types, remember the names of these functions, 
and actually call the correct one.

And then what happens when we want to have a similar function that adds 3 integers instead of 2? 
Managing unique names for each function quickly becomes burdensome.

Luckily, C++ provides a brilliant solution: Function overloading so that we can write multiple 
functions with the same function name. 

TODO:
Continue to read ex1.cpp to understand what function overloading means.
*/