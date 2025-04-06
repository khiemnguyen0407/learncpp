/* Introduction to functions */

/*
A function is a reusable sequence of statements designed to do a particular job.

You already know that every executable program must have a function named main() (which is where 
the program starts execution when it is run). However, as programs start to get longer and longer, 
putting all the code inside the main() function becomes increasingly hard to manage. Functions 
provide a way for us to split our programs into small, modular chunks that are easier to organize, 
test, and use. Most programs use many functions. The C++ standard library comes with plenty of 
already-written functions for you to use -- however, it's just as common to write your own. 
Functions that you write yourself are called user-defined functions.

First, let's start with the most basic syntax to define a user-defined function. For the next few 
lessons, all user-defined functions will take the following form:
==========================================
// This is the function header (tells the compiler about the existence of the function)
return_type function_name() 
{
    // This is the function body (tells the compiler what the function does)
}
==========================================
The first line is informally called the function header, and it tells the compiler about the 
existence of a function, the function's name, and some other information that we'll cover in future 
lessons (like the return type).
    * In this lesson, we’ll use a returnType of int (for function main()) or void (otherwise). For 
      now, do not worry about these, as we’ll talk more about return types and return values in the 
      next lesson (Function return values (value-returning functions)).
    * Just like variables have names, so do user-defined functions. The functionName is the name 
      (identifier) of your user-defined function.
    * The parentheses after the identifier tell the compiler that we're defining a function.
The curly braces and statements in-between are called the function body. This is where the 
statements that determine what your function does will go.

To call a function, we use the function’s name followed by a set of parentheses (e.g. 
function_name() calls the function whose name is function_name). Conventionally, the parenthesis 
are placed adjacent to the function name (with no whitespace between them).

For now, a function must be defined before it can be called. We will discuss ways to work around 
this in the Lession: Forward Declarations and Definitions.
*/

#include <iostream> // for std::cout

// Definition of user-defined function do_print()
// do_print() is the called function in this example
void do_print()
{
    std::cout << "In do_print()\n";
}

void say_hello()
{
    std::cout << "Hello world\n";
}

// Definition of user-defined function main()
int main()
{
    std::cout << "Starting main()\n";
    do_print();     // Interrupt main() by making a function call to do_print().  
                    // main() is the caller.

    // One useful thing about functions is that they can be called more than once.
    std::cout << "2nd do_print(): ";
    do_print();

    std::cout << "1st say_hello(): ";
    say_hello();
    std::cout << "2nd say_hello(): ";
    say_hello();
    std::cout << "3rd say_hello(): ";
    say_hello();
    std::cout << "Ending main()\n";   // This statement is executed after do_print() ends

    return 0;
}