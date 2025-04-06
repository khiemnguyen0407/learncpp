/* Use for pointers and references to base classes: Continued */

/*
Because both Cat and Dog are derived from Animal, it makes sense that we should be able to do
something like this:
*/

// Cat and Dog from example above
#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Animal
{
protected:
    std::string name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : name{ name }
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    std::string_view get_name() const { return name; }
    std::string_view speak() const { return "???"; }
};


class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Woof"; }
};

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    // To use to_array, we need to use C++20, so the compilation command is
    // g++ -std=c++20 .\ex4.cpp
    // const auto animals{ std::to_array<const Animal*>({&fred, &garbo, &misty, &pooky, &truffle, &zeke }) };
    const std::array<const Animal*, 6> animals {&fred, &garbo, &misty, &pooky, &zeke, &truffle};

    // Before C++20, with the array size being explicitly specified
    // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->get_name() << " says " << animal->speak() << '\n';
    }

    return 0;
}
/*
While this compiles and executes, unfortunately the fact that each element of array "animals" is a 
pointer to an Animal means that animal->speak() will call Animal::speak() instead of the derived 
class version of speak() that we want. The output is
-----------------------
Fred says ???
Garbo says ???
Misty says ???
Pooky says ???
Zeke says ???
Truffle says ???
-----------------------

Although both of these techniques could save us a lot of time and energy, they have the same 
problem. The pointer or reference to the base class calls the base version of the function rather 
than the derived version. If only there was some way to make those base pointers call the derived 
version of a function instead of the base version. 

Want to take a guess what virtual functions are for? :)
*/