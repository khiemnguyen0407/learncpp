/* If statements and blocks */

/*
The first category of control flow statements we’ll talk about is conditional statements. A 
conditional statement is a statement that specifies whether some associated statement(s) should be 
executed or not.


Quick if-statement syntax

An if statement takes the form:alignas
if (condition)
    true_statement;

or with an optinal else statement:
if (condition)
    true_statement;
else
    false_statement;

If the condition evaluates to true, the true_statement executes. If the condition evaluates to 
false and the optional else statement exists, the false_statement executes.
*/


#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x {};
    std::cin >> x;

    if (x > 42)
        std::cout << x << " is greater than 42\n";
    else
        std::cout << x << " is smaller than 42\n";

    return 0;
}