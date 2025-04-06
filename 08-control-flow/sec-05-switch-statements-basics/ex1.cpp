/* SWITCH STATEMENT */
#include <iostream>

void print_digit_in_word(int x)
{
    // There is no practical limit to the number of case labels you can have, 
    // but all case labels in a switch must be unique. That is, you can not do this:

    // case 54:
    // case 54:  // error: already used value 54!
    // case '6': // error: '6' converts to integer value 54, which is already used
    switch (x)
    {
    case 1:
        std::cout << "One";
        return;
    case 2:
        std::cout << "Two";
        return;
    case 3:
        std::cout << "Three";
        return;

    // The default label is optional, and there can only be one default label 
    // per switch statement. By convention, the default case is placed last 
    // in the switch block.
    default:
        std::cout << "I don't know how to write this number in word!";
        return;
    }
}

int main()
{
    print_digit_in_word(2);
    std::cout << '\n';

    print_digit_in_word(42);

    return 0;
}