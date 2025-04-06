/* Overloading the operator == and the operator != */

/*
Because the comparison operators are all binary operators that do not modify their left operands, 
we will make our overloaded comparison operators friend functions.
*/

#include <iostream>
#include <string>
#include <string_view>

class Car
{
private:
    std::string make;
    std::string model;

public:
    Car(std::string_view make, std::string_view model)
        : make{ make }, model{ model }
    {
    }

    friend bool operator== (const Car& c1, const Car& c2);
    friend bool operator!= (const Car& c1, const Car& c2);
};

bool operator== (const Car& c1, const Car& c2)
{
    return (c1.make == c2.make &&
            c1.model == c2.model);
}

bool operator!= (const Car& c1, const Car& c2)
{
    return (c1.make != c2.make ||
            c1.model != c2.model);
}

int main()
{
    Car corolla{ "Toyota", "Corolla" };
    Car camry{ "Toyota", "Camry" };

    if (corolla == camry)
        std::cout << "a Corolla and Camry are the same.\n";

    if (corolla != camry)
        std::cout << "a Corolla and Camry are not the same.\n";

    return 0;
}