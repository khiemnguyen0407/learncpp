/* Fallthrough */

/*

When a switch expression matches a case label or optional default label, 
execution begins at the first statement following the matching label. E
xecution will then continue sequentially until one of the following 
termination conditions happens:

    (1) The end of the switch block is reached.
    (2) Another control flow statement (typically a break or return) 
        causes the switch block or function to exit.
    (3) Something else interrupts the normal flow of the program 
        (e.g. the OS shuts the program down, the universe implodes, etc…)
*/

// Note that the presence of another case label is not one of these 
// terminating conditions -- thus, without a break or return, execution 
// will overflow into subsequent cases.

Here is a program that exhibits this behavior:

#include <iostream>

int main()
{
    switch (2)
    {
    case 1: // Does not match
        std::cout << 1 << '\n'; // Skipped
    case 2: // Match!
        std::cout << 2 << '\n'; // Execution begins here
    case 3:
        std::cout << 3 << '\n'; // This is also executed
    case 4:
        std::cout << 4 << '\n'; // This is also executed
    default:
        std::cout << 5 << '\n'; // This is also executed
    }

    return 0;
}

// This is probably not what we wanted! When execution flows from a statement 
// underneath a label into statements underneath a subsequent label, this is 
// called fallthrough.