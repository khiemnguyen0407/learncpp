/* Code block */

/*
In the last example ex1.cpp, you can see that there is no curly braces after if-statement and
else-statement. This is fine if we have only one statement right after if-statement or right after
else-statement. However, in order to execute a block of statements, we need the curly braces around 
the relevant statements

if (condition)
{
    statement 1;
    statement 2;
    ...
    statement n;
}
else
{
    statement 1;
    ...
    statement n;
}
*/


#include <iostream>

namespace constants
{
    constexpr int minRideHeightCM { 140 };
}

int main()
{
    std::cout << "Enter your height (in cm): ";
    int x{};
    std::cin >> x;

    if (x >= constants::minRideHeightCM)
        std::cout << "You are tall enough to ride.\n";
    else 
    {   // note addition block here
        // Remember that blocks are treated as a single statement,
        // so the statement std::cout << "Too bad!\n" is in the branching "else".
        std::cout << "You are not tall enough to ride.\nToo bad!!!";
        std::cout << "Too bad!\n";
    }

    return 0;
}