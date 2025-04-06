/* Continue */

/*
The continue statement provides a convenient way to end the current iteration of a loop without 
terminating the entire loop.
*/

#include <iostream>
int main()
{
    int s1 { 0 };
    for (int i { 0 }; i <= 100; ++i)
    {
        if (i % 2 == 1)
            continue;
        s1 += i;
    }
    std::cout << "s1 = " << s1 << '\n';

    int s2 { 0 };
    for (int i { 0 }; i <= 100; i += 2)
        s2 += i;
    std::cout << "s2 = " << s2 << '\n';
}