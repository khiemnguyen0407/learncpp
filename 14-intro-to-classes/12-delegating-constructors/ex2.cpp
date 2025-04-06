/* Calling a constructor in the body of a function creates a temporary object */

/*
Analogous to how we had function B() call function A() in the example above, the obvious solution 
seems like it would be to call the Employee(std::string_view, int) constructor from the body of 
Employee(std::string_view, int, bool) in order to initialize name, id, and print the statement. 
Here is what that looks like:

*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
private:
    std::string name { "???" };
    int id { 0 };
    bool is_manager { false };

public:
    Employee(std::string_view name, int id)
        : name{ name }, id { id } // this constructor initializes name and id
    {
        std::cout << "Employee " << name << " created\n"; // our print statement is back here
    }

    Employee(std::string_view name, int id, bool isManager)
        : is_manager { isManager } // this constructor initializes is_manager
    {
        // Call Employee(std::string_view, int) to initialize name and id
        Employee(name, id); // this doesn't work as expected!
    }

    const std::string& get_name() const { return name; }
};

int main()
{
    Employee e2{ "Dave", 42, true };
    std::cout << "e2 has name: " << e2.get_name() << "\n"; // print e2.name
}

/* Discussion:
But this doesn’t work correctly, as the program outputs the following:
    Employee Dave created
    e2 has name: ???
Even though Employee Dave created printed, after e2 finished construction, e2.name still appears to 
be set to its initial value of "???". How is that possible?

We were expecting Employee(name, id) to call the constructor in order to continue initialization of 
the current implicit object (e2). But initialization of a class object is finished once the member 
initializer list has finished executing. By the time we begin executing the constructor’s body, it 
is too late to do more initialization.

When called from the body of a function, what looks like a function call to a constructor usually 
creates and direct-initializes a temporary object (in one other case, you’ll get a compile error 
instead). In our example above, Employee(name, id); creates a temporary (unnamed) Employee object. 
This temporary object is the one whose name is set to Dave, and is the one that prints Employee 
Dave created. Then the temporary is destroyed. e2 never has its name or id changed from the default 
values.
*/

/* 
Best practice

Constructors should not be called directly from the body of another function. Doing so will either 
result in a compilation error, or will direct-initialize a temporary object. If you do want a 
temporary object, prefer list-initialization (which makes it clear you are intending to create an 
object).

*/