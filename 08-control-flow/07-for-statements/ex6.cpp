/* Variables used only inside a loop should be defined inside the loop */

/*
New programmers often think that creating variables is expensive, so that it is better to create 
a variable once (and then assign values to it) than create it many times (and use initialization). 
That leads to loops that look like some variation of the following.

However, creating a variable has no cost -- it is the initialization that has a cost, and there is 
typically no cost difference between initialization and assignment. The above example makes i 
available beyond the loop. Unless using a variable beyond the loop is required, defining a variable 
outside the loop is likely to have two consequences:

(1) It makes our program more complex, as we have to read more code to see where the variable is 
    used.
(2) It may actually be slower because the compiler may not be able to optimize a variable with a 
    larger scope as effectively.

Consistent with our best practice to define variables in the smallest reasonable scope possible, a 
variable that is only used within a loop should be defined inside the loop rather than outside.

Best practice:
==============
* Variables used only inside a loop should be defined inside the scope of the loop.
* Prefer for-loops over while-loops when there is an obvious loop variable.
* Prefer while-loops over for-loops when there is no obvious loop variable.

*/

#include <iostream>

int main()
{
    int i {}; // i defined outside loop
    int sum { 0 };
    for (i = 0; i <= 100; ++i) // i assigned value
    {
        sum += i;
    }

    // i can still be accessed here
    std::cout << "sum = " << sum << '\n';
    std::cout << "i = " << i << '\n';

    return 0;
}