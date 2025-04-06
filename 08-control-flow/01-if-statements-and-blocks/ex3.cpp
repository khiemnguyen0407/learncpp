/* if-else versus if-if */

/*
New programmers sometimes wonder when they should use if-else (if followed by one or more 
else-statements) or if-if (if followed by one or more additional if-statements).

    * Use if-else when you only want to execute the code after the first true condition.
    * Use if-if when you want to execute the code after all true conditions.
    
Frankly, I don't need to remember the mechanism of if-else versus if-if because the meaning is all
reflected in literal English. The if-else just mean that if this true, or otherwise... In the 
"otherwise" scenario, we can put another if-else statement or if-if statements. That's it. In the
end, there is no point to remember the mechanism. Once you are familiar with the C++ language or
programming language in general, you will get if-else and if-if naturally.
*/


#include <iostream>

void ifelse(bool a, bool b, bool c)
{
    if (a)      // always evaluates
        std::cout << "a";
    else if (b) // only evaluates when prior if-statement condition is false
        std::cout << "b";
    else if (c) // only evaluates when prior if-statement condition is false
        std::cout << "c";
    std::cout << '\n';
}

void ifif(bool a, bool b, bool c)
{
    if (a) // always evaluates
        std::cout << "a";
    if (b) // always evaluates
        std::cout << "b";
    if (c) // always evaluates
        std::cout << "c";
    std::cout << '\n';
}

int main()
{
    std::cout << "print ifelse(false, true, true): ";
    ifelse(false, true, true);
    std::cout << "print ifif(false, true, true):   ";
    ifif(false, true, true);

    return 0;
}