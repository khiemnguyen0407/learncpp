#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string name{};

public:
    void kisses(const Person& p) const
    {
        std::cout << name << " kisses " << p.name << '\n';
    }

    void set_name(std::string_view name_outside)
    {
        name = name_outside;
    }
};

int main()
{
    Person joe;
    joe.set_name("Joe");

    Person kate;
    kate.set_name("Kate");

    joe.kisses(kate);

    return 0;
}