/* Delegating constructors */

/*
Constructors are allowed to delegate (transfer responsibility for) initialization to another 
constructor from the same class type. This process is sometimes called constructor chaining and 
such constructors are called delegating constructors.

To make one constructor delegate initialization to another constructor, simply call the constructor 
in the member initializer list.
*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string name { "???" };
    int id { 0 };

public:
    Employee(std::string_view name)
        : Employee{ name, 0 } // delegate initialization to Employee(std::string_view, int) constructor
    {
    }

    Employee(std::string_view name, int id)
        : name{ name }, id { id } // actually initializes the members
    {
        std::cout << "Employee " << name << " created\n";
    }

};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}
