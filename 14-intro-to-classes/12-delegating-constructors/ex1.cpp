/* Introduction: Why do we need delegating constructors */

/* This cpp file gives a lot of reasoning for why we need constructor delegation which will be
demonstrated in the next cpp file example.

Whenever possible, we want to reduce redundant code (following the DRY principle -- 
Do not Repeat Yourself).

Consider the following functions:

    void A() { // statements that do task A }
    void B() {
        // statements that do task A
        // statements that do task B
    }
Both functions have a set of statements that do exactly the same thing (task A). In such a case, we 
can refactor like this:
    void A() { // statements that do task A }

    void B()
    {
        A();
        // statements that do task B
    }
In that way, we have removed redundant code that existed in functions A() and B(). This makes our 
code easier to maintain, as changes only need to be made in one place.
*/

/* When a class contains multiple constructors, it’s extremely common for the code in each 
constructor to be similar if not identical, with lots of repetition. We would similarly like to 
remove constructor redundancy where possible.

Consider the following example:
========================================
class Employee
{
private:
    std::string name { "???" };
    int id { 0 };
    bool is_manager { false };

public:
    Employee(std::string_view name, int id) // Employees must have a name and an id
        : name{ name }, id { id }
    {
        std::cout << "Employee " << this->name << " created\n";
    }

    Employee(std::string_view name, int id, bool is_manager) // They can optionally be a manager
        : name{ name }, id{ id }, is_manager { is_manager }
    {
        std::cout << "Employee " << this->id << " created\n";
    }
};
========================================
The body of each constructor has the exact same print statement.

A Quick Note: It's generally not a good idea to have a constructor print something (except for 
debugging purposes), as this means you cannot create an object using that constructor in cases 
where you do not want to print something. We’re doing it in this example to help illustrate what's 
happening.
*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string name { "???" };
    int id{ 0 };
    bool is_manager { false };

    void print_created() const // our new helper function
    {
        std::cout << "Employee " << name << " created\n";
    }

public:
    Employee(std::string_view name, int id)
        : name{ name }, id { id }
    {
        print_created(); // we call it here
    }

    Employee(std::string_view name, int id, bool isManager)
        : name{ name }, id{ id }, is_manager { isManager }
    {
        print_created(); // and here
    }
};

int main()
{
    Employee e1{ "James", 7 };
    Employee e2{ "Dave", 42, true };
}

/*
While this is better than the prior version (as the redundant statement has been replaced by a 
redundant function call), it requires introduction of a new function. And our two constructors are 
also both initializing name and id. Ideally we would remove this redundancy too.
*/
