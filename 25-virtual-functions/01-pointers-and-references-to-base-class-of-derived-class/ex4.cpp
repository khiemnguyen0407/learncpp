/* Use for pointers and references to base classes: Continued */

/*
Let's say you had 3 cats and 3 dogs that you wanted to keep in an array for easy access. Because 
arrays can only hold objects of one type, without a pointer or reference to a base class, you would 
have to create a different array for each derived type.
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
    Animal(std::string_view name) : name{ name }
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

// Cat and Dog from the example above
int main()
{
    // After C++20
    // const auto& cats{ std::to_array<Cat>({{ "Fred" }, { "Misty" }, { "Zeke" }}) };
    // const auto& dogs{ std::to_array<Dog>({{ "Garbo" }, { "Pooky" }, { "Truffle" }}) };

    // Before C++20
    const std::array<Cat, 3> cats{{ { "Fred" }, { "Misty" }, { "Zeke" } }};
    const std::array<Dog, 3> dogs{{ { "Garbo" }, { "Pooky" }, { "Truffle" } }};

    for (const auto& cat : cats)
    {
        std::cout << cat.get_name() << " says " << cat.speak() << '\n';
    }

    for (const auto& dog : dogs)
    {
        std::cout << dog.get_name() << " says " << dog.speak() << '\n';
    }

    return 0;
}

/* Discussion:
Now, consider what would happen if you had 30 different types of animals. You’d need 30 arrays, one 
for each type of animal!
*/