/* DEFAULT CONSTRUCTORS AND DEFAULT ARGUMENTS */

/* A default constructor is a constructor that accepts no arguments.
Typically, this is a constructor that has been defined with no parameters. */

#include <iostream>

class Foo
{
public:
    Foo() // default constructor
    {
        std::cout << "Foo default constructed\n";
    }
};

int main()
{
    Foo foo{}; // No initialization values, calls Foo's default constructor


    /* Value initialization vs default initialization for class types */

    // If a class type has a default constructor, both value initialization
    // and default initialization will call the default constructor. Thus,
    // for such a class such as the Foo class in the example above, the 
    // following are essentially equivalent:

    Foo foo1 {};    // value initialization, calls Foo() default constructor
    Foo foo2 {};    // default initilization, calls Foo() default constructor    

    return 0;
}