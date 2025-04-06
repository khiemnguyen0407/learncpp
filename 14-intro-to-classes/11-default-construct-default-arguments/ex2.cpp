/* CONSTRUCTORS WITH DEFAULT ARGUMENTS */
/*=====================================*/



#include <iostream>

class Foo
{
private:
    int x { };
    int y { };

public:
    // As with all functions, the rightmost parameters of constructors
    // can have default arguments. If all of the parameters in a constructor
    // have default arguments, the constructor is a default constructor 
    // (because it can be called with no arguments).

    Foo(int x=42, int y=42) // has default arguments
        : x { x }   // you cannot use this->x { x } here!
        , y { y }
    {
        std::cout << "Foo(" << this->x << ", " << this->y << ") constructed\n";
    }

    Foo()
    {
        std::cout << "something";
    }
};

int main()
{
    Foo foo1{};     // calls Foo(int, int) constructor using default arguments
    Foo foo2{6, 7}; // calls Foo(int, int) constructor

    return 0;
}