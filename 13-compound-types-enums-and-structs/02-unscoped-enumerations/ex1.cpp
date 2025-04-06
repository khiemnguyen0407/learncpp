#include <iostream>

// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

enum Pet
{
    cat,
    dog,
    pig,
    whale,
};

int main()
{
    // Define a few variables of enumerated type Color
    Color apple { red };   // my apple is red
    Color shirt { green }; // my shirt is green
    Color cup { blue };    // my cup is blue

    // Color socks { white }; // error: white is not an enumerator of Color
    // Color hat { 2 };       // error: 2 is not an enumerator of Color

    /* Because enumerated types are distinct, enumerators defined as part 
    of one enumerated type cannot be used with objects of another enumerated
    type */

    // Pet my_pet { black };       // compile error: black is not an enumerator of Pet
    // Color my_shirt { dog };     // compile error: pig is not an enumerator of Color
    Pet her_pet { cat };
    std::cout << "apple is " << apple;
    std::cout << "shirt is " << shirt;

    return 0;
}