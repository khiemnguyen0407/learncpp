#include <iostream>

namespace constants
{
    constexpr int minRideHeightCM { 140 };
}

int main()
{
    std::cout << "Enter your height (in cm): ";
    int x{};
    std::cin >> x;

    if (x >= constants::minRideHeightCM)
        std::cout << "You are tall enough to ride.\n";
    else 
    {   // note addition block here
        // Remember that blocks are treated as a single statement,
        // so the statement std::cout << "Too bad!\n" is in the branching "else".
        std::cout << "You are not tall enough to ride.\nToo bad!!!";
        std::cout << "Too bad!\n";
    }

    return 0;
}