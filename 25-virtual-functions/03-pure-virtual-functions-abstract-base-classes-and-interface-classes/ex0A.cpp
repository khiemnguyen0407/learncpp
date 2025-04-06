#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string name {};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : name{ name }
    {
    }

public:
    const std::string& get_name() const { return name; }
    virtual std::string_view speak() const { return "???"; }

    virtual ~Animal() = default;
};

class Cow : public Animal
{
public:
    Cow(std::string_view name)
        : Animal{ name }
    {
    }

    // We forgot to redefine speak
};

int main()
{
    Cow cow{"Betsy"};
    std::cout << cow.get_name() << " says " << cow.speak() << '\n';

    return 0;
}