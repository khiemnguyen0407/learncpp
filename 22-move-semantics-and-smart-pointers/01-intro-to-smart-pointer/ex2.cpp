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

// A sample class to prove the above works
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }

	void say_hello() { std::cout << "Hello there!\n"; }
};

int do_something()
{
	AutoPointer1<Resource> ptr (new Resource());		// ptr now owns the Resource
	int integer {42};
	std::cout << "Enter an integer: ";
	std::cin >> integer;
	if (integer == 0)
		std::cout << "You enter 0 and this function returns here";
		return integer;		// the function returs early
	// do stuff with ptr here
	ptr->say_hello();
}

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
	AutoPointer1<Resource> resource(new Resource()); // Note the allocation of memory here

        // ... but no explicit delete needed

	// Also note that we use <Resource>, not <Vector3D0*>
    // This is because we've defined m_ptr to have type T* (not T)

	AutoPointer1<Vector3D> vec(new Vector3D(1.5, 2.5, 3.5));
	std::cout << "\nPrint out Vector3D vec: ";
	vec->print();
	std::cout << '\n';

	return 0;
} 
// vector goes out of scope here, and destroys the allocated Vector3D for us
// resource goes out of scope here, and destroys the allocated Resource for us

/* Important discussion:

Consider how this program and class work. First, we dynamically create a Resource, and pass it as a 
parameter to our templated AutoPointer1 class. From that point forward, our AutoPointer1 variable 
res owns that Resource object (AutoPointer1 has a composition relationship with m_ptr). Because 
resource is declared as a local variable and has block scope, it will go out of scope when the 
block ends, and be destroyed (no worries about forgetting to deallocate it). And because it is a 
class, when it is destroyed, the AutoPointer1 destructor will be called. That destructor will 
ensure that the Resource pointer it is holding gets deleted!

As long as AutoPointer1 is defined as a local variable (with automatic duration, hence the "Auto" 
part of the class name), the Resource will be guaranteed to be destroyed at the end of the block 
it is declared in, regardless of how the function terminates (even if it terminates early).

All of the discussion applies to AutoPointer1<Vector3D> too.

Such a class is called a smart pointer. A Smart pointer is a composition class that is designed to 
manage dynamically allocated memory and ensure that memory gets deleted when the smart pointer 
object goes out of scope. (Relatedly, built-in pointers are sometimes called "dumb pointers" 
because they can't clean up after themselves).

*/