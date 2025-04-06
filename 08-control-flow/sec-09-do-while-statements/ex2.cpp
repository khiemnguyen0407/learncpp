/* DO-WHILE STATEMENT */

/* A do while statement is a looping construct that works just like a while loop, 
except the statement always executes at least once. After the statement has been 
executed, the do-while loop checks the condition. If the condition evaluates to 
true, the path of execution jumps back to the top of the do-while loop and 
executes it again. */

#include <iostream>

int main()
{
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection {};

    do
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    }
    while (selection < 1 || selection > 4);

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}

/* In this way, we’ve avoided both magic numbers and additional variables.

One thing worth discussing in the above example is that the selection variable 
must be declared outside of the do block. If the selection variable were to be 
declared inside the do block, it would be destroyed when the do block terminates, 
which happens before the conditional is evaluated. But we need the variable in
the while conditional -- consequently, the selection variable must be declared
outside the do block (even if it wasn’t used later in the body of the function). 

In practice, do-while loops aren’t commonly used. Having the condition at the 
bottom of the loop obscures the loop condition, which can lead to errors. Many 
developers recommend avoiding do-while loops altogether as a result. We’ll take 
a softer stance and advocate for preferring while loops over do-while when 
given an equal choice.
*/