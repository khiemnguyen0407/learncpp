/* Virtual functions: Continued */

/* Let us study a slightly more complicated example using virtual function. */

#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view get_name() const { return "A object"; }
};

class B: public A
{
public:
    virtual std::string_view get_name() const { return "B"; }
};

class C: public B
{
public:
    virtual std::string_view get_name() const { return "C"; }
};

class D: public C
{
public:
    virtual std::string_view get_name() const { return "D"; }
};

int main()
{
    C c {};
    A& base_ref{ c };
    std::cout << "base_ref is a " << base_ref.get_name() << '\n';

    // Calling a virtual member function directly on an object (not through a pointer or reference) 
    // will always invoke the member function belonging to the same type of that object.

    C c2 {};
    std::cout << "c2.get_name() = " << c2.get_name() << '\n';

    A a {c};
    std::cout << "a.get_name() = " << a.get_name() << '\n';      // will always call A::get_name()
    

    A& cameron_thing { a };
    std::cout << "a.get_name() = " << cameron_thing.get_name() << '\n';

    return 0;
}

/* 
Let's look at how this works. First, we instantiate a C class object. base_ref is an A reference,
which we set to reference the A portion of the C object. Finally, we call base_ref.get_name(). 
base_ref.get_name() evaluates to A::get_name(). However, A::get_name() is virtual, so the compiler 
will call the most-derived match between A and C. In this case, that is C::get_name(). Note that it 
will not call D::get_name(), because our original object was a C, not a D, so only functions 
between A and C are considered.

Note that virtual function resolution only works when a virtual member function is called through a 
pointer or reference to a class type object. This works because the compiler can differentiate the 
type of the pointer or reference from the type of the object being pointed to or referenced. We see 
this in example above.

Calling a virtual member function directly on an object (not through a pointer or reference) will 
always invoke the member function belonging to the same type of that object.
*/