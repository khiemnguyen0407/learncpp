#include <iostream>
#include <string_view>
enum Pet // no specified base
{
    cat, // assigned 0
    dog, // assigned 1
    pig, // assigned 2
    whale, // assigned 3
};

enum Color
{
    black,
    red,
    blue,
};


constexpr std::string_view get_color_name(Color color)
{
    switch (color)
    {
        case black: return "black";
        case red: return "red";
        case blue: return "blue";
        default:
            return "???";
    }
}
int main()
{
    // Pet pet { 2 }; // compile error: integer value 2 won't implicitly convert to a Pet
    // pet = 3;       // compile error: integer value 3 won't implicitly convert to a Pet


    Pet pet { static_cast<Pet>(2) }; // convert integer 2 to a Pet
    pet = static_cast<Pet>(3);       // our pig evolved into a whale!

    std::cout << "pet = " << pet << '\n';

    Color shirt { blue };
    std::cout << "Your shirt is " << get_color_name(shirt) << '\n';

    return 0;
}