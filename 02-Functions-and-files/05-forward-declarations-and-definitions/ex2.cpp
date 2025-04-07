/* Forward declaration */

/*
Option 2: Use a forward declaration

A forward declaration allows us to tell the compiler about the existence of an identifier before 
actually defining the identifier. In the case of functions, this allows us to tell the compiler 
about the existence of a function before we define the function’s body. This way, when the compiler 
encounters a call to the function, it will understand that we’re making a function call, and can 
check to ensure we are calling the function correctly, even if it doesn’t yet know how or where the 
function is defined.

To write a forward declaration for a function, we use a function declaration statement (also called 
a function prototype). The function declaration consists of the function’s return type, name, and 
parameter types, terminated with a semicolon. The names of the parameters can be optionally 
included. The function body is not included in the declaration.
*/

#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
    int a { 1.5 };
    int b { 5.1} ;
    std::cout << "a + b = " << add(a, b) << '\n';
    return 0;
}

// Actual definition of add which was declared before it was used in int main()
int add(int x, int y)
{
    return x + y;
}