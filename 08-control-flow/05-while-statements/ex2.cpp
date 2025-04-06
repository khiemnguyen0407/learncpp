/* Doing something every N iterations */

// The code below needs little explanation. You compile the code, run it and understand it easily.


// Often, we want to do something every 2nd, 3rd, or 4th iteration, such as print a newline. 
// This can easily be done by using the remainder operator on our counter

#include <iostream>

int main()
{
    int count{ 0 };
    while (count <= 99)
    {
        // print the number (pad numbers under 10 with a leading 0 for formatting purposes)
        if (count < 10)
        {
            std::cout << '0';
        }

        std::cout << count << '\t';

        // if the loop variable is divisible by 10, print a newline
        if ((count + 1) % 10 == 0 )
        {
            std::cout << '\n';
        }

        // increment the loop counter
        ++count;
    }

    return 0;
}