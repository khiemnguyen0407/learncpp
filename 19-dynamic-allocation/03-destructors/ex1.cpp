/* DESTRUCTORS */

/*
A destructor is another special kind of class member function that is executed when an object of 
that class is destroyed. Whereas constructors are designed to initialize a class, destructors are 
designed to help clean up.

When an object goes out of scope normally, or a dynamically allocated object is explicitly deleted 
using the delete keyword, the class destructor is automatically called (if it exists) to do any 
necessary clean up before the object is removed from memory. For simple classes (those that just 
initialize the values of normal member variables), a destructor is not needed because C++ will 
automatically clean up the memory for you.

However, if your class object is holding any resources (e.g. dynamic memory, or a file or database 
handle), or if you need to do any kind of maintenance before the object is destroyed, the 
destructor is the perfect place to do so, as it is typically the last thing to happen before the 
object is destroyed.

=================
Destructor naming
=================

Like constructors, destructors have specific naming rules:

    * The destructor must have the same name as the class, preceded by a tilde (~).
    * The destructor can not take arguments.
    * The destructor has no return type.

A class can only have a single destructor.

Generally you should not call a destructor explicitly (as it will be called automatically when 
the object is destroyed), since there are rarely cases where you’d want to clean up an object more 
than once. However, destructors may safely call other member functions since the object isn't 
destroyed until after the destructor executes.

*/

#include <iostream>
#include <cassert>
#include <cstddef>

class Vector
{
private:
	double* data{};
	int length{};

public:
	Vector(int length) // constructor
	{
		assert(length > 0);

		this->data = new double[static_cast<std::size_t>(length)]{};
		this->length = length;
	}

	~Vector() // destructor
	{
		// Dynamically delete the array we allocated earlier
		std::cout <<"Hello from destructor";
		delete[] this->data;
	}

	void set_value(int index, double value) { this->data[index] = value; }
	int get_value(int index) { return this->data[index]; }
    
	int get_length() { return this->length; }

    void print() {
        for (int index {0}; index < this->get_length(); ++index) {
            std::cout << this->data[index] << '\t';
        }
        std::cout << '\n';
    }
};

int main()
{
	Vector v ( 10 ); // allocate 10 double
	for (int count{ 0 }; count < v.get_length(); ++count)
        v.set_value(count, static_cast<double>(count) * 0.5);

	std::cout << "The value of element 5 is: " << v.get_value(5) << '\n';
    v.print();

	return 0;
} // vector is destroyed here, so the ~Vector() destructor function is called here