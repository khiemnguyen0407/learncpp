#include <iostream>

int main()
{
    // outer loops between 1 and 5
    int outer{ 1 };
    while (outer <= 10)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        // note: inner will be created and destroyed at the end of the block
        int inner{ 1 };
        while (inner <= outer)
        {   
            if (inner < 10)
                std::cout << '0';

            std::cout << inner << "  ";
            ++inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    } // inner destroyed here

    return 0;
}