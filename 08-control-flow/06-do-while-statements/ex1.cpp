/* Do while statements: Why? */

/*
Consider the case where we want to show the user a menu and ask them to make a selection -- and if 
the user chooses an invalid selection, to ask them again. Clearly the menu and selection should go 
inside a loop of some kind (so we can keep asking the user until they enter valid input), but what 
kind of loop should we choose?

To see do-while statements, please proceed to see the next cpp file, namely ex2.cpp file.

*/

#include <iostream>

int main()
{   
    /* Option #1:
    If we don't use do-while statement, we need to create selection initilized to a "magic number"
    which is outside the option numbers. For example, we have 4 options and the magic number can be 
    "0" or "5" or anything not in the set {1, 2, 3, 4}. This magic number may need to be changed if 
    we have more options. This works because our initial value of o for selection isn't in the set 
    of valid values. What if 0 was a valid choice. */
    // selection must be declared outside while-loop, so we can use it later
    int selection {}; // value initialized to 0

    while (selection < 1 || selection > 4)
    {
       std::cout << "1 -- Addition\n";
       std::cout << "2 -- Subtraction\n";
       std::cout << "3 -- Multiplication\n";
       std::cout << "4 -- Division\n";
       std::cout << "Please make a selection: ";
       std::cin >> selection;
    }

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << "\n\n";
    // Since a while loop evaluates the condition up front, it's an awkward choice. We could solve 
    // the issue like this by introducing the variable invalid.

    /* Option #2:
    If we don't want to use a magic number, we need a gate flag for the while condition. So, we 
    remove one trouble */
    bool invalid { true }; // new variable just to gate the loop

    while (invalid)
    {
        std::cout << "1 -- Addition\n";
        std::cout << "2 -- Subtraction\n";
        std::cout << "3 -- Multiplication\n";
        std::cout << "4 -- Division\n";
        std::cout << "Please make a selection: ";
        std::cin >> selection;
        invalid = (selection < 1 || selection > 4);
    }

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}