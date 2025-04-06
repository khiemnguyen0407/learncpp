/* The pointer "this" always points to the object being operated on */

/*
New programmers are sometimes confused about how many this pointers exist. Each member function has 
a single this pointer parameter that points to the implicit object.
*/

#include <iostream>

class Simple
{
private:
    int id {};

public:
    Simple(int id)
        : id { id }
    {
    }

    int get_ID() const { return id; }   // implicitly: return this->id;
    void set_ID(int id) { this->id = id; }  

    void print() const { std::cout << this->id; } 

};

int main()
{
    Simple a { 24 };    // this = &a inside the Simple constructor
    Simple b { 42 };    // this = &b inside the Simple constructor

    a.set_ID(42);       // this = &a inside member function set_ID()
    b.set_ID(24);       // this = &b inside member function set_ID()
    
    std::cout << "ID of a: "; 
    a.print();          // this = &a inside member function print()
    std::cout << std::endl;
    std::cout << "ID of b: "; 
    b.print();          // this = &b inside member function print() 

    return 0;
}

/* Discussion:
Most of the time, you won’t need to explicitly reference the this pointer. However, there are a 
few occasions where doing so can be useful:
(1) First, if you have a member function that has a parameter with the same name as a data member, 
    you can disambiguate them by using this.
*/