#include <iostream>
#include <string>
#include <string_view>

class Animal // This Animal is an abstract base class
{
protected:
    std::string name {};

public:
    Animal(std::string_view name)
        : name{ name }
    {
    }

    const std::string& get_name() const { return name; }
    virtual std::string_view speak() const = 0; // note that speak is now a pure virtual function

    virtual ~Animal() = default;
};

class Cow: public Animal
{
public:
    Cow(std::string_view name)
        : Animal(name)
    {
    }

    std::string_view speak() const override { return "Moo"; }
};

int main()
{
    Cow cow{ "Betsy" };
    std::cout << cow.get_name() << " says " << cow.speak() << '\n';

    return 0;
}