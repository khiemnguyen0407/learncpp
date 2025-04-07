/* Forward declarations and definitions */
/*
You would expect this program to produce the result.

But in fact, it doesn’t compile at all! Visual Studio produces the following compile error.

The reason this program does not compile is because the compiler compiles the contents of code 
files sequentially. When the compiler reaches the function call add() on line 5 of main, it does 
not know what add is, because we haven’t defined add until line 9! That produces the error, 
identifier not found.
*/
#include <iostream>

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}