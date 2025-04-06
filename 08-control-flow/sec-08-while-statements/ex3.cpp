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