/* Default arguments */

/*
A default argument is a default value provided for a function parameter. When making a function 
call, the caller can optionally provide an argument for any function parameter that has a default 
argument. If the caller provides an argument, the value of the argument in the function call is 
used. If the caller does not provide an argument, the value of the default argument is used. Note:
You have learned default arguments for function in Python programming.

*/


#include <iostream>

void print(int x, int y=42) // 42 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}

int main()
{
    print(1, 2); // y will use user-supplied argument 2
    print(3); // y will use default argument 4, as if we had called print(3, 4)

    return 0;
}

/* Further Dicussion

Perhaps surprisingly, default arguments are handled by the compiler at the call site. In the above 
example, when the compiler sees print(3), it will rewrite this function call as print(3, 4), so 
that the number of arguments matches the number of parameters. The rewritten function call then 
works as per usual.

When to use default arguments
=============================

Default arguments are an excellent option when a function needs a value that has a reasonable 
default value, but for which you want to let the caller override if they wish.

Default arguments are also useful in cases where we need to add a new parameter to an existing 
function. If we add a new parameter without a default argument, it will break all existing function 
calls (which aren’t supplying an argument for that parameter). This can result in a lot of updating 
of existing function calls (and may not even be possible if you don’t own the calling code). 
However, if we add a new parameter with a default argument instead, all existing function calls 
will still work (as they will use the default argument for the parameter), while still letting new 
calls to the function specify an explicit argument if desired.
*/