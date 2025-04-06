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