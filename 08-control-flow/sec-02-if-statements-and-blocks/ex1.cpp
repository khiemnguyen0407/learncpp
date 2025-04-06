#include <iostream>

int main()
{
    std::cout << "Enter a number: ";
    int x {};
    std::cin >> x;

    if (x > 42)
        std::cout << x << " is greater than 42\n";
    else
        std::cout << x << " is smaller than 42\n";

    return 0;
}