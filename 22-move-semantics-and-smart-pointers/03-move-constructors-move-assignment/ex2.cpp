/* Move constructors and move assignement */

/*
C++11 defines two new functions in service of move semantics: a move constructor, and a move 
assignment operator. Whereas the goal of the copy constructor and copy assignment is to make a copy 
of one object to another, the goal of the move constructor and move assignment is to move ownership 
of the resources from one object to another (which is typically much less expensive than making a 
copy).

Defining a move constructor and move assignment work analogously to their copy counterparts. 
However, whereas the copy flavors of these functions take a const l-value reference parameter 
(which will bind to just about anything), the move flavors of these functions use non-const rvalue 
reference parameters (which only bind to rvalues).

Here’s the same Auto_ptr3 class as above, with a move constructor and move assignment operator 
added. We’ve left in the deep-copying copy constructor and copy assignment operator for comparison 
purposes.

*/

#include <iostream>

template<typename T>
class AutoPointer4
{
	T* pointer {};
public:
	AutoPointer4(T* ptr = nullptr)
		: pointer { ptr }
	{
	}

	~AutoPointer4()
	{
		delete pointer;
	}

	// Copy constructor
	// Do deep copy of a.pointer to pointer
	AutoPointer4(const AutoPointer4& a)
	{
		pointer = new T;
		*pointer = *a.pointer;
	}

	// Move constructor
	// Transfer ownership of a.pointer to pointer
	AutoPointer4(AutoPointer4&& a) noexcept
		: pointer { a.pointer }
	{
		a.pointer = nullptr; // we'll talk more about this line below
	}

	// Copy assignment
	// Do deep copy of a.pointer to pointer
	AutoPointer4& operator=(const AutoPointer4& a)
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

	// Move assignment
	// Transfer ownership of a.pointer to pointer
	AutoPointer4& operator=(AutoPointer4&& a) noexcept
	{
		// Self-assignment detection
		if (&a == this)
			return *this;

		// Release any resource we're holding
		delete pointer;

		// Transfer ownership of a.pointer to pointer
		pointer = a.pointer;
		a.pointer = nullptr; // we'll talk more about this line below

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

AutoPointer4<Resource> generate_resource()
{
	AutoPointer4<Resource> res{new Resource};
	return res; // this return value will invoke the move constructor
}

int main()
{
	AutoPointer4<Resource> mainres;
	mainres = generate_resource(); // this assignment will invoke the move assignment

	return 0;
}

// When run this program, you see only two outputs

/*
That’s much better!

The flow of the program is exactly the same as before. However, instead of calling the copy 
constructor and copy assignment operators, this program calls the move constructor and move 
assignment operators. Looking a little more deeply:

    (1) Inside generate_resource(), local variable res is created and initialized with a dynamically
        allocated Resource, which causes the first "Resource acquired".
    (2) res is returned back to main() by value. Res is move constructed into a temporary object, 
        transferring the dynamically created object stored in res to the temporary object. 
        We'll talk about why this happens below.
    (3) res goes out of scope. Because res no longer manages a pointer (it was moved to the 
        temporary), nothing interesting happens here.
    (4) The temporary object is move assigned to mainres. This transfers the dynamically created 
        object stored in the temporary to mainres.
    (5) The assignment expression ends, and the temporary object goes out of expression scope and 
        is destroyed. However, because the temporary no longer manages a pointer (it was moved to 
        mainres), nothing interesting happens here either.
    (6) At the end of main(), mainres goes out of scope, and our final "Resource destroyed" is 
        displayed.

So instead of copying our Resource twice (once for the copy constructor and once for the copy 
assignment), we transfer it twice. This is more efficient, as Resource is only constructed and 
destroyed once instead of three times.
*/

/*
When are the move constructor and move assignment called?
=========================================================
The move constructor and move assignment are called when those functions have been defined, and the 
argument for construction or assignment is an rvalue. Most typically, this rvalue will be a literal 
or temporary value.

The copy constructor and copy assignment are used otherwise (when the argument is an lvalue, or 
when the argument is an rvalue and the move constructor or move assignment functions aren't 
defined).
*/