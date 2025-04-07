/* Local scope (block scope) */

/* 
An identifier's scope determines where the identifier can be seen and used within the source code. 
When an identifier can be seen and used, we say it is in scope. When an identifier can not be seen, 
we can not use it, and we say it is out of scope. Scope is a compile-time property, and trying to 
use an identifier when it is not in scope will result in a compile error.

The identifier of a local variable has local scope. An identifier with local scope (technically 
called block scope) is usable from the point of definition to the end of the innermost pair of 
curly braces containing the identifier (or for function parameters, at the end of the function). 
This ensures local variables cannot be used before the point of definition (even if the compiler 
opts to create them before then) or after they are destroyed. Local variables defined in one 
function are also not in scope in other functions that are called.
*/

// A program demonstrating the scope of a variable named x.

#include <iostream>

void say_hello()
{
    std::cout << "Hello!\n";
}

int main()
{
    // x can not be used here because it's not in scope yet

    int x{ 0 }; // x enters scope here and can now be used within this function

    say_hello();

    return 0;
} // x goes out of scope here and can no longer be used

// In the above program, variable x enters scope at the point of definition. x goes out of scope at 
// the end of the innermost pair of curly braces containing the identifier, which is the closing 
// curly brace of function main(). Note that variable x is not in scope anywhere inside of function 
// say_hello(). The fact that function main calls function say_hello() is irrelevant in this 
// context.

/* 
"Out of scope" vs "going out of scope"
======================================
The terms "out of scope" and "going out of scope" can be confusing to new programmers.

An identifier is out of scope anywhere it cannot be accessed within the code. In the example above, 
the identifier x is in scope from its point of definition to the end of the main function. The 
identifier x is out of scope outside of that code region.
The term "going out of scope" is typically applied to objects rather than identifiers. We say an 
object goes out of scope at the end of the scope (the end curly brace) in which the object was 
instantiated. In the example above, the object named x goes out of scope at the end of the 
function main.
*/