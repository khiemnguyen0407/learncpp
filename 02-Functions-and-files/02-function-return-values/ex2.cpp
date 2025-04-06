/* Revisit main() */

/*
You now have the conceptual tools to understand how the main() function actually works. When the 
program is executed, the operating system makes a function call to main(). Execution then jumps to 
the top of main(). The statements in main() are executed sequentially. Finally, main() returns an 
integer value (usually 0), and your program terminates.

In C++, there are two special requirements for main():

(1) main() is required to return an int.
(2) main() is required to be defined in the global scope (i.e., not inside another function). So, 
    explicit function calls to main() are disallowed.

For now, you should also define your main() function at the bottom of your code file, below other 
functions, and avoid calling it explicitly.
*/

/*
For advanced readers

It is a common misconception that main is always the first function that executes.

Global variables are initialized prior to the execution of main. If the initializer for such a 
variable invokes a function, then that function will execute prior to main.
*/

// Try to compile this code. You will get error when you try to compile it.

void foo()
{
    main(); // Compile error: main not allowed to be called explicitly
}

void main() // Compile error: main not allowed to have non-int return type
{
    foo();
}