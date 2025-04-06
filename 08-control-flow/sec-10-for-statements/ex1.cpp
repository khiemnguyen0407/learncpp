/* FOR LOOP */

/* The for-statement looks pretty simple in abstract: 

for (init-statement; condition; end-expression)
   statement;

The easiest way to initially understand how a for-statement works is 
to convert it into an equivalent while-statement:

{   // note the block here
    init-statement; // used to define variables used in the loop
    while (condition)
    {
        statement; 
        end-expression; // used to modify the loop variable prior to reassessment of the condition
    }
}   // variables defined inside the loop go out of scope here

Further Explanation:
=====================================================================================
First, the init-statement is executed. This only happens once when the 
loop is initiated. The init-statement is typically used for variable definition and 
initialization. These variables have “loop scope”, which really just is a form of 
block scope where these variables exist from the point of definition through the end
of the loop statement. In our while-loop equivalent, you can see that the 
init-statement is inside a block that contains the loop, so the variables defined 
in the init-statement go out of scope when the block containing the loop ends.

Second, with each loop iteration, the condition is evaluated. If this evaluates 
to true, the statement is executed. If this evaluates to false, the loop terminates
and execution continues with the next statement beyond the loop.

Finally, after the statement is executed, the end-expression is evaluated. Typically, 
this expression is used to increment or decrement the loop variables defined in the 
init-statement. After the end-expression has been evaluated, execution returns to 
the second step (and the condition is evaluated again).

The order of execution for the different parts of a for-statement is as follows:

    (1) Init-statement
    (2) Condition (if this is false, the loop terminates here).
    (3) Loop body
    (4) End-expression (then jumps back to condition)

*/


#include <iostream>
int main()
{
    // Compute summation of integers from 1 to 100.
    int sum { 0 };
    for (int i {1}; i <= 100; ++i)
        sum += i;

    std::cout << "sum (for-loop)   = " << sum << '\n';

    // We can perform this computation by using the while loop.

    {   // block here ensures block scope for i
        int i { 1 };
        sum = 0;
        while (i <= 100)
        {   
            sum += i;       // our statement
            ++i;            // our end-expression
        }

    }
    std::cout << "sum (while-loop) = " << sum << '\n';
}