/* Introduction to loops and while statements */

/*
Introduction to loops
=====================
And now the real fun begins -- in the next set of lessons, we’ll cover loops. Loops are control 
flow constructs that allow a piece of code to execute repeatedly until some condition is met. Loops 
add a significant amount of flexibility into your programming toolkit, allowing you to do many 
things that would otherwise be difficult.

At this point of time, you are third-year students. Therefore, I don't think I need to explain why 
we need loops in programming. If we don't use loops in programming, the whole point of using 
computer to compute complex and repeated operations becomes nonsense. Therefore, I don't need to
spend time convincing you why we need loops.

We shall learn three important loop constructs
    (1) while statements
    (2) do-whilte statements
    (3) for statements

We start with while statements in this file.
*/

/*
The while statement (also called a while loop) is the simplest of the three loop types that C++ 
provides, and it has a definition very similar to that of an if-statement:
------------------------------
while (condition)
    statement;
------------------------------

A while statement is declared using the while keyword. When a while-statement is executed, the 
expression condition is evaluated. If the condition evaluates to true, the associated statement 
executes. However, unlike an if-statement, once the statement has finished executing, control 
returns to the top of the while-statement and the process is repeated. This means a while-statement 
will keep looping as long as the condition continues to evaluate to true.
*/

#include <iostream>

int main()
{
    int count{ 1 };
    while (count <= 10)
    {
        std::cout << count << ' ';
        ++count;
    }

    std::cout << "\ndone!\n";

    return 0;
}