#include <iostream>

class Foo
{
private:
    int x {};    // default member initializer (will be ignored)
    int y { 2 }; // default member initializer (will be used)
    int z;      // no initializer

public:
    Foo(int x)
        : x { x } // member initializer list
    {
        std::cout << "Foo(" << x << ", " << y << ", " << z << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << this->x << ", " << this->y << ", " << this->z << ")\n";
    }
};

int main()
{
    Foo foo { 6 };
    foo.print();

    return 0;
}