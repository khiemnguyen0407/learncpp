/* Nested Loop */

/*
It is also possible to nest loops inside of other loops. Nested loops tend to be a bit confusing 
to new programmers, so let's start with a slightly easier example in this cpp file. Then, we will 
write this by using a nested loop in the main() function in the next cpp file.

In this example, we have an outer loop with a counter named outer that counts from 1 to 5. For each 
iteration of the loop, the body of the loop calls print_up_to(int outer) using the outer loop 
variable as an argument, prints a newline, and increments outer. The print_up_to(int outer) 
function also has a loop which prints all the numbers between 1 and the value passed in.

Therefore, when outer is 1, the loop body calls print_up_to(1), which prints the number 1. The loop 
body then prints a newline and increments outer. Now outer is 2. The loop body executes again, 
calling print_up_to(2), which prints 1 2. The loop body prints another newline and increments 
outer. Successive iterations call print_up_to(3), print_up_to(4), print_up_to(5), and so on.
*/

#include <iostream>

void print_up_to(int outer)
{
    // loop between 1 and outer
    // note: inner will be created and destroyed at the end of the block
    int inner{ 1 };
    while (inner <= outer)
    {
        if (inner < 10)
            std::cout << '0';

        std::cout << inner << "  ";
        ++inner;
    }
} // inner destroyed here

int main()
{
    // outer loops between 1 and 5
    int outer{ 1 };
    while (outer <= 10)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // This function prints numbers between 1 and outer
        print_up_to(outer);

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    }

    return 0;
}