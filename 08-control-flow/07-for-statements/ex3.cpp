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

/*
Further discussion
==================

Although you do not see it very often, it is worth noting that the following example produces an 
infinite loop:

for (;;)
    statement;

The above example is equivalent to:
while (true)
    statement;

This might be a little unexpected, as you’d probably expect an omitted condition-expression to be 
treated as false. However, the C++ standard explicitly (and inconsistently) defines that an omitted 
condition-expression in a for-loop should be treated as true.

Of course, this form of for loop should be avoided altogether. In case you need an infinite loop, 
use while (true) instead.
*/