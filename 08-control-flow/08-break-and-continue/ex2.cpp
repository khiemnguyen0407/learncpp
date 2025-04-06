/* Break vs Return */

/* 
A break statement terminates the switch or loop, and execution continues at the first statement 
beyond the switch or loop. A return statement terminates the entire function that the loop is 
within, and execution continues at point where the function was called.
*/

#include <iostream>

int break_or_return()
{
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            // return will cause the function to immediately return to the 
            // caller (in this case, main())
            return 1; 
    }

    // breaking the loop causes execution to resume here

    std::cout << "We broke out of the loop\n";

    return 0;
}

int main()
{
    int return_value{ break_or_return() };
    std::cout << "Function break_or_return returned " << return_value << '\n';

    return 0;
}