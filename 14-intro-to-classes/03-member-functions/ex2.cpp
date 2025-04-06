#include <iostream>
#include <string>

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

void kisses(const Person& subject, const Person& object)
{
    std::cout << subject.name << " kises " << object.name << '\n';
}

int main()
{
    Person joe{ "Joe", 29 };
    Person kate{ "Kate", 27 };

    // Using explicit object
    kisses(joe, kate);
    kisses(kate, joe);


    // Using implicit object
    joe.kisses(kate);

    return 0;
}