/* Omitted expressions in for statements */

/* It is possible to write for loops that omit any or all of the statements 
or expressions. For example, in the following example, we’ll omit the 
init-statement and end-expression, leaving only the condition: */

#include <iostream>

int main()
{
    int sum { 0 };
    int i { 0 };        // We need to declare the loop variable here.
    for ( ; i <= 100; ) // no init-statement or end-expression
    {
        sum += i;
        ++i;
    }
    std::cout << "sum = " << sum << '\n';
}