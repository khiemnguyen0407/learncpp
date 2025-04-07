/* Forward declaration */

/*
It is worth noting that function declarations do not need to specify the names of the parameters 
(as they are not considered to be part of the function declaration). In the above code, you can 
also forward declare your function like this.
*/

#include <iostream>

int add(int, int); // forward declaration of add() (using a function declaration)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}

/* 
However, we prefer to name our parameters (using the same names as the actual function). This 
allows you to understand what the function parameters are just by looking at the declaration. For 
example, if you were to see the declaration void do_something(int, int, int), you may think you 
remember what each of the parameters represent, but you may also get it wrong.

Also many automated documentation generation tools will generate documentation from the content of 
header files, which is where declarations are often placed.
*/

/* 
Why forward declarations?

You may be wondering why we would use a forward declaration if we could just reorder the functions 
to make our programs work. Most often, forward declarations are used to tell the compiler about the 
existence of some function that has been defined in a different code file. Reordering is not 
possible in this scenario because the caller and the callee are in completely different files! 

Forward declarations can also be used to define our functions in an order-agnostic manner. This 
allows us to define functions in whatever order maximizes organization (e.g. by clustering related 
functions together) or reader understanding.

Less often, there are times when we have two functions that call each other. Reordering is not 
possible in this case either, as there is no way to reorder the functions such that each is before 
the other. Forward declarations give us a way to resolve such circular dependencies.
*/