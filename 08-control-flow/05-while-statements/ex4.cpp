/* Nested loop */

/*
Before reading this cpp file, you may want to have a quick look at ex3.cpp. At this point of time, 
I assume that you have some experience in programming nested loop in Python. So, I hope that the 
following code in C++ apears natural to you. Essentially, this is just a way to rewrite the code
presented in ex3.cpp.

Because we have a while-loop nested directly within another while-loop, this looks a bit more 
confusing. However, all we have done is put the code that used to be inside the print_up_to(int) 
function directly inside the outer loop body. Nothing fancier than ex3.cpp!!
*/
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
/* 
Debugging to understand the process
===================================

If you’re still finding this confusing, stepping through this program in a debugger line-by-line 
and watching the values of inner and outer is a good way to get a better understanding of what's 
happening.
*/