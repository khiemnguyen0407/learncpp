#include<iostream>

enum Color
{
    red,
    green,
    blue, // blue is put into the global namespace
};

enum Feeling
{
    happy,
    tired,
    // blue, // error: naming collision with the above blue
    sad,
};

int main()
{
    Color apple { red };        // my apple is red
    Color shirt { blue };
    Feeling me { happy };       // I'm happy right now (even though my program doesn't compile)

    Color rasberry { Color::red};   // also okay, accessing enumerator from scope of Color

    if (shirt == blue)  // if the shirt is blue
        std::cout << "Your shirt is blue";
    else
        std::cout << "Your shirt is not blue";
    
    return 0;
}