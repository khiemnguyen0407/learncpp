
/*
Using a friend function to overload an operator is convenient because it gives you direct access to 
the internal members of the classes you're operating on. In the initial Cents example above, our 
friend function version of operator+ accessed member variable cents directly.

However, if you do not need that access, you can write your overloaded operators as normal 
functions. Note that the Cents class above contains an access function (get_cents()) that allows us 
to get at cents without having to have direct access to private members. Because of this, we can 
write our overloaded operator+ as a non-friend.



*/
#include <iostream>

class Cents
{
private:
  int cents{};

public:
    Cents(int cents) : cents{ cents }
    {}

    int get_cents() const { return cents; }
};

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents& c1, const Cents& c2)
{
  // use the Cents constructor and operator+(int, int)
  // we don't need direct access to private members here
  return Cents{ c1.get_cents() + c2.get_cents() };
}

int main()
{
  Cents c1{ 24 };
  Cents c2{ 42 };
  Cents sum{ c1 + c2 };
  std::cout << "I have " << sum.get_cents() << " cents.\n";

  return 0;
}

/* 
Discussion:
Because the normal and friend functions work almost identically (they just have different levels of 
access to private members), we generally won’t differentiate them. The one difference is that the 
friend function declaration inside the class serves as a prototype as well. With the normal 
function version, you’ll have to provide your own function prototype.

See the three files "Cents.h", "Cents.cpp" and "ex2.cpp" to understand this point. To compile the
example using ex2.cpp, use the command:
    g++ .\ex2.cpp .\Cents.h .\Cents.cpp

In general, a normal function should be preferred over a friend function if it's possible to do 
so with the existing member functions available (the less functions touching your classes's 
internals, the better). However, do not add additional access functions just to overload an 
operator as a normal function instead of a friend function!
*/

/* Best practice
================
Prefer overloading operators as normal functions instead of friends if it's possible to do so 
without adding additional functions.

*/