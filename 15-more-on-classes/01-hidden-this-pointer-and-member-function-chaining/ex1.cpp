/* The hidden "this" pointer and member function chaining */

/*
One of the questions about classes that new programmers often ask is, "When a member function is 
called, how does C++ keep track of which object it was called on?".

Let us define a simple class to work with. This class encapsulates an integer value, and provides 
some access functions to get and set that value.

Inside every member function, the keyword this is a const pointer that holds the address of the 
current implicit object.
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

    // If we don't have the pointer "this" to refer to the "current" object, we need to use a 
    // different input argument name. 
    void set_ID(int id) { this->id = id; }  

    // use "this" pointer to access the implicit object and operator-> to select member id
    void print() const { std::cout << this->id; } 

    // void print() const { std::cout << id; }       // implicit use of this
};

int main()
{
    Simple simple{ 1 };
    simple.set_ID(2);

    simple.print();

    return 0;
}

/* Discussion
Look at two statements:

(1) void print() const { std::cout << id; }         // implicit use of this
(2) void print() const { std::cout << this->id; }   // explicit use of this

It turns out that the former is shorthand for the latter. When we compile our programs, the 
compiler will implicitly prefix any member referencing the implicit object with this->. This helps 
keep our code more concise and prevents the redundancy from having to explicitly write this-> over 
and over.

A reminder:
We use -> to select a member from a pointer to an object. For this reason, this->id is the 
equivalent of (*this).id.
*/