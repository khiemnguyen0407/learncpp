#include <iostream>

int main()
{
    // Although most for-loops increment the loop variable 
    // by 1, we can decrement it as well:
    int sum { 0 };
    for (int i { 100 }; i > 0; --i)
        sum += i;
    
    std::cout << "sum (all numbers from 1 to 100)  = " << sum << '\n';

    // Alternately, we can change the value of our loop variable 
    // by more than 1 with each iteration. 

    // Let us compute the summation of all even numbers from 0 to 100:
    sum = 0;
    for (int i {0}; i <= 100; i += 2)   // increment by 2 each iteration
        sum += i;
    std::cout << "sum (even numbers from 0 to 100) = " << sum <<'\n';
}

// BEST PRACTICE:
/* 
Avoid operator!= when doing numeric comparisons in the for-loop condition. 
Prefer operator< or operator<= where possible.

See for example:
#include <iostream>

int main()
{
    for (int i { 0 }; i < 10; ++i) // uses <, still terminates
    {
         std::cout << i;
         if (i == 9) ++i; // jump over value 10
    }

    for (int i { 0 }; i != 10; ++i) // uses !=, infinite loop
    {
         std::cout << i;
         if (i == 9) ++i; // jump over value 10
    }

     return 0;
}

*/