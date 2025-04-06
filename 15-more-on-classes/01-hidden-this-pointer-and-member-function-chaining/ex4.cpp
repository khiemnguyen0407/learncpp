/* Resetting a class back to default state */

/*
If your class has a default constructor, you may be interested in providing a way to return an 
existing object back to its default state.
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

/* Discussion

When e1 { "James" } is initialized, matching constructor Employee(std::string_view) is called with 
parameter name set to "James". The member initializer list of this constructor delegates 
initialization to other constructor, so Employee(std::string_view, int) is then called. The value 
of name ("James") is passed as the first argument, and literal 0 is passed as the second argument. 
The member initializer list of the delegated constructor then initializes the members. The body of 
the delegated constructor then runs. Then control returns to the initial constructor, whose (empty) 
body runs. Finally, control returns to the caller.

The downside of this method is that it sometimes requires duplication of initialization values. In 
the delegation to the Employee(std::string_view, int) constructor, we need an initialization value 
for the int parameter. We had to hardcode literal 0, as there is no way to reference the default 
member initializer.

A few additional notes about delegating constructors:

(1) First, a constructor that delegates to another constructor is not allowed to do any member 
    initialization itself. So your constructors can delegate or initialize, but not both.

(2) Second, it’s possible for one constructor to delegate to another constructor, which delegates 
    back to the first constructor. This forms an infinite loop, and will cause your program to run 
    out of stack space and crash. You can avoid this by ensuring all of your constructors resolve 
    to a non-delegating constructor.

*/