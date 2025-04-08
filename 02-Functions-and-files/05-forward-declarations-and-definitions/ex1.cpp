/* Option 1: Reorder the function definitions */

/*
One way to address the issue is to reorder the function definitions so add is defined before main. 
That way, by the time main calls add, the compiler will already know what add is. Because this is 
such a simple program, this change is relatively easy to do. However, in a larger program, it can 
be tedious trying to figure out which functions call which other functions (and in what order) so 
they can be declared sequentially.
*/

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}