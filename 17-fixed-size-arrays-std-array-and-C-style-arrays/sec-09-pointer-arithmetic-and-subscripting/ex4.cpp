/* Range-based for loops over C-style arrays are implemented using pointer arithmetic */

// If you look at the documentation
// https://en.cppreference.com/w/cpp/language/range-for
// for range-based for loops, you’ll see that they are typically 
// implemented something like this:
/*
{
    auto __begin = begin-expr;
    auto __end = end-expr;

    for ( ; __begin != __end; ++__begin)
    {
        range-declaration = *__begin;
        loop-statement;
    }
}
*/

#include <iostream>

int main()
{
	constexpr int array[]{ 9, 7, 5, 3, 1 };
    std::cout << "Print elements using range-based for loop:\n";
	for (auto element : array)         // iterate from `begin` up to (but excluding) `end`
	{
		std::cout << element << ' '; // dereference our loop variable to get the current element
	}
    std::cout << "\nReimplementation of range-based for loop using pointer arithmetic pointer:\n";
    // Let us replace the range-based for loop in the prior example 
    // with this implementation:
    auto __begin = array;                       // arr is our begin-expr
	auto __end = array + std::size(array);      // arr + std::size(arr) is our end-expr

	for ( ; __begin != __end; ++__begin)
	{
		auto element = *__begin;         // e is our range-declaration
		std::cout << element << ' ';     // here is our loop-statement
    }

	return 0;
}