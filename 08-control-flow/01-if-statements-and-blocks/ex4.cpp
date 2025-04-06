/* Using return in conditional statement */

/*
It is important to remember that when the execution path hits "return", it will return the value
after the return statement and get out of the function and return the to the caller (the program
that calls the function). For this reason, the following two functions, one of which uses if-else
statement and the other uses if-if statement, actually behave in the same way.
*/

#include <iostream>

char ifelse_return(bool a, bool b, bool c)
{
    if (a) // always evaluates
        return 'a';
    else if (b) // only evaluates when prior if-statement condition is false
        return 'b';
    else if (c) // only evaluates when prior if-statement condition is false
        return 'c';

    return 0;
}

char ifif_return(bool a, bool b, bool c)
{
    if (a) // always evaluates
        return 'a'; // returns when if-statement is true
    if (b) // only evaluates when prior if-statement condition is false
        return 'b'; // returns when if-statement is true
    if (c) // only evaluates when prior if-statement condition is false
        return 'c'; // returns when if-statement is true

    return 0;
}

int main()
{
    std::cout << "ifelse_return(false, true, true): " << ifelse_return(false, true, true);
    std::cout << '\n';
    std::cout << "ifif_return(false, true, true)  : " << ifif_return(false, true, true);
    std::cout << '\n';
}

/* Quick discussion

While this might superficially look like we want to execute the code after every true condition, as 
soon as we find the first true condition, the associated statement will cause the function to 
return. The remaining if-statements never have a chance to evaluate. Therefore, this behaves 
equivalently to the prior version. When every associated statement returns a value, many 
programmers prefer to omit the else keywords, as doing so avoids unnecessary clutter and the 
conditions line up better.

*/