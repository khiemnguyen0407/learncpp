#include <iostream>

// Iterate through every number between 1 and 50
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