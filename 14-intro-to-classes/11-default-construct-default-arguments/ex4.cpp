#include <iostream>

class Foo
{
private:
    int x {42};
    int y {24};
    int z;
    // Note: no constructors declared
public:
    
    void print() {
        std::cout << "Foo(" << x << ", " << y << ", " << z << ")\n";
    }
};

int main()
{
    Foo foo{};
    foo.print();

    return 0;
}

/* 
The implicit default constructor is equivalent to a constructor that has
no parameters, no member initializer list, and no statements in the body 
of the constructor. In other words, for the above Foo class, the compiler 
generates this:

public:
    Foo() // implicitly generated default constructor
    {
    }
*/