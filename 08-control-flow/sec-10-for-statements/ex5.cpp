/* Nested for-loops */

// Like other types of loops, for-loops can be nested inside other loops. 
// In the following example, we’re nesting a for-loop inside another for-loop.

#include <iostream>
int main()
{
    // Print the multiplication table.
    for (int i { 1 }; i < 10; ++i) 
    {
        for (int j { 1 }; j < 10; ++j)
        {
            std::cout << i << " * " << j << " = " << i * j << '\t';
        }
        std::cout << '\n';
    }
}


