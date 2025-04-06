/* OVERLOADED CONSTRUCTORS */
/*=========================*/
// Because constructors are functions, they can be overloaded. 
// That is, we can have multiple constructors so that we can 
// construct objects in different ways:

#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    // Foo() // default constructor
    // {
    //     std::cout << "Foo constructed\n";
    // }
    Foo() // default constructor
    {
    }

    Foo(int x, int y) // non-default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

/* Remark 
A corollary of the above is that a class should only have one default constructor. 
If more than one default constructor is provided, the compiler will be unable 
to disambiguate which should be used. */

// Therefore, the following code would class would give error because it essentially
// has two default constructors. Therefore, the compiler does not know which constructor
// it should use when it sees the declaration without arguments.

/* =========================================================================
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() // DEFAULT CONSTRUCTOR
    {
        std::cout << "Foo constructed\n";
    }

    Foo(int x=1, int y=2) // DEFAULT CONSTRUCTOR
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};
int main()
{
    Foo foo{}; // compile error: ambiguous constructor function call

    return 0;
}
============================================================================ */

int main()
{
    Foo foo1{};     // Calls Foo() constructor
    Foo foo2{6, 7}; // Calls Foo(int, int) constructor

    return 0;
}

