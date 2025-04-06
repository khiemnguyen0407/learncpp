/* Reducing constructors using default arguments */

/*
Default values can also sometimes be used to reduce multiple constructors into fewer constructors. 
For example, by putting a default value on our id parameter, we can create a single Employee 
constructor that requires a name argument but will optionally accept an id argument.
*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string name{};
    int id{ 0 }; // default member initializer

public:

    Employee(std::string_view name, int id = 0) // default argument for id
        : name{ name }, id{ id }
    {
        std::cout << "Employee " << name << " created\n";
    }
};

int main()
{
    Employee e1{ "James" };
    Employee e2{ "Dave", 42 };
}

/* Discussion
Since default values must be attached to the rightmost parameters in a function call, a good 
practice when defining classes is to define members for which a user must provide initialization 
values for first (and then make those the leftmost parameters of the constructor). Members for 
which the user can optionally provide (because the default values are acceptable) should be defined 
second (and then make those the rightmost parameters of the constructor).


Best practice:
============================
Members for which the user must provide initialization values should be defined first (and as the 
leftmost parameters of the constructor). Members for which the user can optionally provide 
initialization values (because the default values are acceptable) should be defined second (and as 
the rightmost parameters of the constructor).
============================

In the above examples, we used delegating constructors and then default arguments to reduce 
constructor redundancy. But both of these methods required us to duplicate initialization values 
for our members in various places. Unfortunately, there is currently no way to specify that a 
delegating constructor or default argument should use the default member initializer value.

There are various opinions about whether it is better to have fewer constructors (with duplication 
of initialization values) or more constructors (with no duplication of initialization values). Our 
opinion is that it is usually more straightforward to have fewer constructors, even if it results 
in duplication of initialization values.
*/