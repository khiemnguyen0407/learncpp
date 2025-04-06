/* Nested functions are not supported */

/* 
A function whose definition is placed inside a nother function is a nested function. Unlike some 
other programming languages, in C++, functions cannot be nested. The following program is not 
legal. So, you will get error when you try to compile it. In fact, the modern IDE also informs that
the function foo is not found.
*/

/* Nomenclature
"foo" is a meaningless word that is often used as a placeholder name for a function or variable 
when the name is unimportant to the demonstration of some concept. Such words are called 
metasyntactic variables (though in common language they're often called "placeholder names" since 
nobody can remember the term "metasyntactic variable"). Other common metasyntactic variables in C++ 
include "bar", "baz", and 3-letter words that end in "oo", such as "goo", "moo", and "boo").

*/

#include <iostream>

int main()
{
    void foo() // Illegal: this function is nested inside function main()
    {
        std::cout << "foo!\n";
    }

    foo(); // function call to foo()
    // You will get error when you try to compile it. In fact, the modern IDE also informs that
    // the function foo is not found.
    // foo() is not declared in the scope of main()
    return 0;
}