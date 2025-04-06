#include <iostream>

enum Color
{
    black,   // 0
    red,     // 1
    blue,    // 2
    green,   // 3
    white,   // 4
    cyan,    // 5
    yellow,  // 6
    magenta, // 7
};

enum Animal
{
    cat = -3,    // values can be negative
    dog,         // -2
    pig,         // -1
    horse = 5,
    giraffe = 5, // shares same value as horse
    chicken,     // 6
};

int main()
{
    Color shirt{ blue }; // shirt actually stores integral value 2

    std::cout << "shirt = " << shirt << '\n';

    Color apple{ red };
    std::cout << "apple = " << apple << '\n';

    Animal zero_animal {};
    std::cout << "zero_animal = " << zero_animal << '\n';

    Animal h { horse };
    std::cout << "h = " << horse << '\n';
    return 0;
}