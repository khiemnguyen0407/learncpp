// Now let us go back to ex1.cpp problem, and see how a smart pointer class can solve our challenge.

/* Smart pointer classes to the rescue??? */

/* Discussion
One of the best things about classes is that they contain destructors that automatically get 
executed when an object of the class goes out of scope. So if you allocate (or acquire) memory in 
your constructor, you can deallocate it in your destructor, and be guaranteed that the memory will 
be deallocated when the class object is destroyed (regardless of whether it goes out of scope, gets 
explicitly deleted, etc…).

So can we use a class to help us manage and clean up our pointers? We can!

Consider a class whose sole job was to hold and “own” a pointer passed to it, and then deallocate 
that pointer when the class object went out of scope. As long as objects of that class were only 
created as local variables, we could guarantee that the class would properly go out of scope 
(regardless of when or how our functions terminate) and the owned pointer would get destroyed.

*/

#include <iostream>


// Here’s a first draft of the idea:
template <typename T>
class AutoPointer1
{
	T* pointer {};
public:
	// Pass in a pointer to "own" via the constructor
	AutoPointer1(T* ptr=nullptr)
		: pointer(ptr)
	{
	}

	// The destructor will make sure it gets deallocated
	~AutoPointer1()
	{
		delete this->pointer;
	}

	// Overload dereference and operator-> so we can use AutoPointer1 like m_ptr.
	T& operator*() const { return *(this->pointer); }
	T* operator->() const { return this->pointer; }
};

class Vector3D
{
private:
    double x;
    double y;
    double z;
public:
    Vector3D(double x=0, double y=0, double z=0) 
    : x { x }
    , y { y }
    , z { z }
    {
        std::cout << "Vector3D(" << this->x << "," << this->y 
            << "," << this->z << ") is constructed!";
    }
	~Vector3D() { std::cout << "Vector3D destroyed\n"; }

    void print()
    {
        std::cout << "Vector3D(" << this->x << ", " << this->y << ", " << this->z << ")"; 
    }
};


int main()
{
    AutoPointer1<Vector3D> ptr { new Vector3D(1.5, 2.5, 3.5) };
    std::cout << "\nVector3D pointed by pointer ptr:\n";
    // using pointer pointing to the object
    ptr->print();
    std::cout << '\n';


    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
    {
        std::cout << "ptr has not been deleted yet! But return is reached.\n";
        return 0; // the function returns early, and ptr won't be deleted!
    }

    // do some stuff with ptr here.
    // We won't see the output of this statement as the function returns early.
    ptr->print();

    return 0;
} 