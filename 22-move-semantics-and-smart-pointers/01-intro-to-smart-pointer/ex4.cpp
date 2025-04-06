/* Critical flaw in AutoPointer1 in ex3.cpp */

// The AutoPointer1 class has a critical flaw lurking behind some auto-generated code.
#include <iostream>

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

	// Overload dereference and operator-> so we can use AutoPointer1 like pointer.
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
    AutoPointer1<Vector3D> ptr1 { new Vector3D {1.0, 2.0, 3.0} };
    AutoPointer1<Vector3D> ptr2(ptr1);

    std::cout << "\nVector3D pointed by pointer ptr:\n";
    // using pointer ptr1 pointing to the object
    ptr1->print();
    std::cout << '\n';

    // using pointer ptr2 pointing to the object
    ptr2->print();
    std::cout << '\n';

    return 0;
} // ptr1 and ptr2 go out of scope here

/* Discussion
Very likely (but not necessarily) your program will crash at this point. See the problem now? 
Because we haven't supplied a copy constructor or an assignment operator, C++ provides one for us. 
And the functions it provides do shallow copies. So when we initialize ptr2 with ptr1, both 
AutoPointer1 variables are pointed at the same Vector3D object. When ptr2 goes out of the scope, 
it deletes the Vector3D object, leaving ptr1 with a dangling pointer. When ptr1 goes to delete its 
(already deleted) Vector3D, undefined behavior will result (probably a crash)!

You run into a similar problem with a function like this

void pass_by_value(AutoPointer1<Vector3> ptr)
{  // The parameter ptr is the copy of the input argument, so two pointers point to the same 
   // Vector3D object. Both ptr.pointer and out_ptr.pointer will hold the same address. When 
   // ptr is destroyed at the end of this function pass_by_value, out_ptr.pointer is left dangling.
   // When out_ptr.pointer is later deleted in the end of main function, undefined behavior will
   // result

   // Some code goes here.
}

int main()
{
    AutoPointer1<Vector3D> out_ptr { new Vector3D() };
    pass_by_value(out_ptr);

    return 0;
}

*/