#include <iostream>

class Foo
{
private:
    int x {};
    int y {};

public:
    Foo(int x, int y) // here's our constructor function that takes two initializers
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
        this->x = x;
        this->y = y;
    }

    void print() const
    {
        std::cout << "Foo(" << x << ", " << y << ")\n";
    }
};

int main()
{
    Foo foo { 6, 7 }; // calls Foo(int, int) constructor
    foo.print();

    /* Constrcutor implicit conversion of arguments */
    Foo f {'a', true};      // will match Foo(int, int) constructor

    return 0;
}