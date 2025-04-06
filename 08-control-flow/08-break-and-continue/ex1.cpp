/* Breaking a loop */

/*
In the context of a loop, a break statement can be used to end the loop early. Execution 
continues with the next statement after the end of the loop. We have learned "break" and "continue"
in Python programming language. The use of "break" and "continue".alignas

We can use a break in a switch statement or a loop. We have learned using "break" in a switch 
statement. In this example, we illustrate the use of "break" in a for-loop. When "break" is hit, 
the execution goes out of the loop. Yeah! As simple as that.
*/

#include <iostream>

int main()
{
    std::cout << "=================\n";
    std::cout << "Stupid problem #1\n";
    std::cout << "=================\n";
    char ch {};
    int x { 1 };
    int y { 2 };
    std::cout << "Input a operator character for computation of (1 operator 2):" ;
    std::cout << "+ for plus\n";
    std::cout << "- for minus\n";
    std::cout << "* for multiplication\n";
    std::cout << "/ for division\n";
    std::cin >> ch;
    switch (ch)
    {
    case '+':
        std::cout << x << " + " << y << " = " << x + y << '\n';
        break; // don't fall-through to next case
    case '-':
        std::cout << x << " - " << y << " = " << x - y << '\n';
        break; // don't fall-through to next case
    case '*':
        std::cout << x << " * " << y << " = " << x * y << '\n';
        break; // don't fall-through to next case
    case '/':
        std::cout << x << " / " << y << " = " << x / y << '\n';
        break;
    }
    std::cout << "======================\n";
    std::cout << "Less stupid problem #2\n";
    std::cout << "======================\n";
    std::cout << "Compute the sum of integers input by the user (maximum 10 numbers).\n";
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