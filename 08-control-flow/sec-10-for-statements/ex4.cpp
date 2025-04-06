/* For-loop with multiple counters */

/* Although for-loops typically iterate over only one variable, sometimes for-loops 
need to work with multiple variables. To assist with this, the programmer can 
define multiple variables in the init-statement, and can make use of the comma 
operator to change the value of multiple variables in the end-expression.
*/

#include <iostream>
int main()
{
    int s1 { 0 };
    int s2 { 0 };
    for (int i { 0 }, j { 100 }; i <= 100, j >= 0; ++i, j-=2)
    {
        s1 += i;
        s2 += j;
    }
    std::cout << "sum (all numbers from 0 to 100)  = " << s1 << '\n';
    std::cout << "sum (even numbers from 0 to 100) = " << s2 << '\n';

    // This is about the only place in C++ where defining multiple variables 
    // in the same statement, and use of the comma operator is considered an 
    // acceptable practice.
    for (int i { 1 }, j { 9 }; i < 10, j > 0; ++i, --j)
    {
        std::cout << i << " + " << j << " = " << i + j << '\n';
    }
}