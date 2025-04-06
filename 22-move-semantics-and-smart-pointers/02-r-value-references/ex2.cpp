/* R-value references as function parameters */

// R-value references are more often used as function parameters. This is most useful for function 
// overloads when you want to have different behavior for l-value and r-value arguments.

#include <iostream>

void print_out(const int& lref) // l-value arguments will select this function
{
	std::cout << "l-value reference to const: " << lref << '\n';
}

void print_out(int&& rref) // r-value arguments will select this function
{
	std::cout << "r-value reference: " << rref << '\n';
}

int main()
{
	int x { 5 };
	print_out(x); // l-value argument calls l-value version of function
	print_out(5); // r-value argument calls r-value version of function

    /* Rvalue reference variables are lvalues */
    int&& ref { 5 };
    print_out(ref); // print_out(const int& lref) is called.


	return 0;
}

/*
As you can see, when passed an l-value, the overloaded function resolved to the version with the 
l-value reference. When passed an r-value, the overloaded function resolved to the version with the 
r-value reference (this is considered a better match than an l-value reference to const).

Why would you ever want to do this? We'll discuss this in more detail in the next lesson. 
Needless to say, it's an important part of move semantics.
*/

/* Rvalue reference variables are lvalues

As you can see from the code above, when we write
int&& ref { 5 };
print_out(ref);
The version of fun(const int&) is called. Therefore, R-value reference variables are considered as 
L-values.
*/

/* Returning an r-value reference

You should almost never return an r-value reference, for the same reason you should almost never 
return an l-value reference. In most cases, you’ll end up returning a hanging reference when the 
referenced object goes out of scope at the end of the function.
*/