/* Different kinds of inheritance, and their impact on access */

/*
There are three different ways for classes to inherit from other classes: 
(1) public
(2) protected
(3) private

To do so, simply specify which type of access you want when choosing the class to inherit from:

// Inherit from Base publicly
class Pub: public Base
{
};

// Inherit from Base protectedly
class Pro: protected Base
{
};

// Inherit from Base privately
class Pri: private Base
{
};

class Def: Base // Defaults to private inheritance
{
};

That gives us 9 combinations: 3 member access specifiers (public, private, and protected), 
and 3 inheritance types (public, private, and protected).

Keep in mind the following rules as we step through the examples in the subsequent cpp files:
* A class can always access its own (non-inherited) members.
* The public accesses the members of a class based on the access specifiers of the class 
  it is accessing.
* A derived class accesses inherited members based on the access specifier inherited from the 
  parent class. This varies depending on the access specifier and type of inheritance used.
*/