/* Breaking a loop */
// In the context of a loop, a break statement can be used to end the loop 
// early. Execution continues with the next statement after the end of the loop.

#include <iostream>

int main()
{
    int sum { 0 };
    for (int count { 0 }; count < 10; ++count) 
    {
        std::cout << "Enter a number to add, or 0 to exit: ";
        int num {};
        std::cin >> num;

        // exit loop if the user enters 0
        if (num == 0)
            break;

        // Otherwise add the number to the sum
        sum += num;
    }

    // Excution will continue here after the break
    // or after 10 numbers are supplied.
    std::cout << "Sum of all numbers you entered so far is: " << sum << '\n';

    return 0;
}