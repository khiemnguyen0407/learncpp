/* Recapping copy constructors and copy assignment */
/*
Copy constructors are used to initialize a class by making a copy of an object of the same class. 
Copy assignment is used to copy one class object to another existing class object. By default, 
C++ will provide a copy constructor and copy assignment operator if one is not explicitly provided. 
These compiler-provided functions do shallow copies, which may cause problems for classes that 
allocate dynamic memory. So classes that deal with dynamic memory should override these functions 
to do deep copies.


Returning back to our AutoPointer smart pointer class example from the first lesson in this chapter, 
let’s look at a version that implements a copy constructor and copy assignment operator that do deep copies, and a sample program that exercises them:
*/

#include <iostream>

template<typename T>
class AutoPointer3
{
	T* pointer {};
public:
	AutoPointer3(T* ptr = nullptr)
		: pointer { ptr }
	{
	}

	~AutoPointer3()
	{
		delete pointer;
	}

	// Copy constructor
	// Do deep copy of a.pointer to pointer
	AutoPointer3(const AutoPointer3& a)
	{
		pointer = new T;
		*pointer = *a.pointer;
	}

	// Copy assignment
	// Do deep copy of a.pointer to pointer
	AutoPointer3& operator=(const AutoPointer3& a)
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete pointer;

		// Copy the resource
		pointer = new T;
		*pointer = *a.pointer;

		return *this;
	}

	T& operator*() const { return *pointer; }
	T* operator->() const { return pointer; }
	bool isNull() const { return pointer == nullptr; }
};

class Resource
{
public:
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};

AutoPointer3<Resource> generate_resource()
{
	AutoPointer3<Resource> res{new Resource};
	return res; // this return value will invoke the copy constructor
}

int main()
{
	AutoPointer3<Resource> mainres;
	mainres = generate_resource(); // this assignment will invoke the copy assignment

	return 0;
}

// You may only get 4 outputs if your compiler elides the return value from function 
// generate_resource(). On my computer, I get 4 outputs. You may have 6 outputs.

/* Further discussion
Let’s take a closer look. There are 6 key steps that happen in this program (one for each printed 
message):

    (1) Inside generate_resource(), local variable res is created and initialized with a dynamically 
        allocated Resource, which causes the first "Resource acquired".
    (2) Res is returned back to main() by value. We return by value here because res is a local 
        variable -- it can’t be returned by address or reference because res will be destroyed when 
        generate_resource() ends. So res is copy constructed into a temporary object. Since our 
        copy constructor does a deep copy, a new Resource is allocated here, which causes the 
        second "Resource acquired".
    (3) Res goes out of scope, destroying the originally created Resource, which causes the first 
        "Resource destroyed".
    (4) The temporary object is assigned to mainres by copy assignment. Since our copy assignment 
        also does a deep copy, a new Resource is allocated, causing yet another "Resource acquired".
    (5) The assignment expression ends, and the temporary object goes out of expression scope and 
        is destroyed, causing a "Resource destroyed".
    (6) At the end of main(), mainres goes out of scope, and our final "Resource destroyed" 
    is displayed.

So, in short, because we call the copy constructor once to copy construct res to a temporary, and 
copy assignment once to copy the temporary into mainres, we end up allocating and destroying 3 
separate objects in total.

Inefficient, but at least it doesn’t crash! However, with move semantics, we can do better.

*/