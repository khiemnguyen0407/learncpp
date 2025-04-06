#include <iostream>

int main()
{
    int selection {};
    bool invalid { true }; // new variable just to gate the loop

    while (invalid)
    {
        std::cout << "Please make a selection: \n";
        std::cout << "1> Addition\n";
        std::cout << "2> Subtraction\n";
        std::cout << "3> Multiplication\n";
        std::cout << "4> Division\n";

        std::cin >> selection;
        invalid = (selection < 1 || selection > 4);
    }

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    return 0;
}