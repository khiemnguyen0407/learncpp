/* Return types of virtual function */

/*
Under normal circumstances, the return type of a virtual function and its override must match.

Consider the following example. In this case, Derived::get_value() is not considered a matching 
override for Base::get_value() and compilation will fail. So, if you try to compile the file, the
compiler will issue the error. Do it to see the effect!
*/
#include <iostream>
class Base
{
public:
    virtual int get_value() const { return 5; }
};

class Derived: public Base
{
public:
    virtual double get_value() const { return 6.78; }
};

int main()
{
    return 0;
}

/* Do not call virtual functions from constructors or destructors
=================================================================
Here's another gotcha that often catches unsuspecting new programmers. You should not call virtual 
functions from constructors or destructors. Why?

Remember that when a Derived class is created, the Base portion is constructed first. If you were 
to call a virtual function from the Base constructor, and Derived portion of the class hadn't even 
been created yet, it would be unable to call the Derived version of the function because there's no 
Derived object for the Derived function to work on. In C++, it will call the Base version instead.

A similar issue exists for destructors. If you call a virtual function in a Base class destructor, 
it will always resolve to the Base class version of the function, because the Derived portion of 
the class will already have been destroyed.
*/

/* 
The downside of virtual functions
=================================

Since most of the time you'll want your functions to be virtual, why not just make all functions 
virtual? The answer is because it's inefficient -- resolving a virtual function call takes longer 
than resolving a regular one.

Furthermore, to make virtual functions work, the compiler has to allocate an extra pointer for each 
object of a class that has virtual functions. This adds a lot of overhead to objects that otherwise 
have a small size. We'll talk about this more in future lessons in this chapter.
*/