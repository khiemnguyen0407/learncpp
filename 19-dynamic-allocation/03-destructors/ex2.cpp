/* Constructor and Destructor timing */

/* 
As mentioned previously, the constructor is called when an object is created, and the destructor is
called when an object is destroyed. In the following example, we use cout statements inside the 
constructor and destructor to show this:
*/

#include <iostream>

class Foo
{
private:
    int ID{};
    double value{};

public:
    Foo(int ID)
        : ID{ ID }
    {
        std::cout << "Constructing Foo " << this->ID << '\n';
    }

    ~Foo()
    {
        std::cout << "Destructing Foo " << this->ID << '\n';
    }

    void set_ID(int ID) { this->ID = ID; };
    int get_ID() { return this->ID; }

    void set_value(double value) { this->value = value; };
    double get_value() { return this->value; };
};

int main()
{
    // Allocate a Simple on the stack
    Foo foo{ 1 };
    std::cout << foo.get_ID() << '\n';

    // Allocate a Simple dynamically
    Foo* pFoo{ new Foo{ 2 } };

    std::cout << pFoo->get_ID() << '\n';

    // We allocated pSimple dynamically, so we have to delete it.
    delete pFoo;
    std::cout << "before return 0";
    return 0;
} // simple goes out of scope here