/* Inheritance and access specifiers */

/* Quick recap:
In the previous lessons in this chapter, we have learned a bit about how base inheritance works. In 
all of our examples so far, we’ve used public inheritance. That is, our derived class publicly 
inherits the base class. In this lesson, we’ll take a closer look at public inheritance, as well as 
the two other kinds of inheritance (private and protected). We will also explore how the different 
kinds of inheritance interact with access specifiers to allow or restrict access to members.

To this point, we have seen the private and public access specifiers, which determine who can 
access the members of a class. As a quick refresher, public members can be accessed by anybody. 
Private members can only be accessed by member functions of the same class or friends. This means 
derived classes can not access private members of the base class directly!
*/

/* 
The access specifier "protected" 
================================

C++ has a third access specifier that we have yet to talk about because it’s only useful in an 
inheritance context. The protected access specifier allows the class the member belongs to, 
friends, and derived classes to access the member. However, protected members are not accessible 
from outside the class.
*/

#include<iostream>

class Base
{

private:
    // can only be accessed by Base members and friends (but not derived classes)
    double private_value {42};

protected:
    // can be accessed by Base members, friends, and derived classes
    double protected_value {};

public:
    // can be accessed by anybody
    double public_value {};

    double get_private_value() { return this->private_value; }

    double get_protected_value() { return this->protected_value; }

    void print_values()
    {
        std::cout << "public value    = " << this->public_value << '\n';
        std::cout << "protected value = " << this->protected_value << '\n';
        std::cout << "private value   = " << this->private_value << '\n';
    }
};

class Derived: public Base
{
public:
    Derived()
    {
        public_value = 1;       // allowed: can access public base members from derived class
        protected_value = 24;    // allowed: can access protected base members from derived class
        
        // not allowed: can not access private base members from derived class
        // private_value = 3;
    }
};

int main()
{
    Base base;
    // allowed: can access public members from outside class
    base.public_value = 0.5;

    // not allowed: can not access protected members from outside class
    base.protected_value = 2;

    // not allowed: can not access private members from outside class
    // base.private_value = 3;
    std::cout << "Values in base: \n";
    base.print_values();

    Derived derived;
    derived.public_value = 10;
    std::cout << "values in derived: \n";
    derived.print_values();
}

/* 
When should we use the protected access specifier?
==================================================
With a protected attribute in a base class, derived classes can access that member directly. 
This means that if you later change anything about that protected attribute (the type, what the 
value means, etc…), you'll probably need to change both the base class AND all of the derived 
classes.

Therefore, using the protected access specifier is most useful when you (or your team) are going to 
be the ones deriving from your own classes, and the number of derived classes is reasonable. That 
way, if you make a change to the implementation of the base class, and updates to the derived 
classes are necessary as a result, you can make the updates yourself (and have it not take forever, 
since the number of derived classes is limited).

Making your members private means the public and derived classes can’t directly make changes to the 
base class. This is good for insulating the public or derived classes from implementation changes, 
and for ensuring invariants are maintained properly. However, it also means your class may need a 
larger public (or protected) interface to support all of the functions that the public or derived 
classes need for operation, which has its own cost to build, test, and maintain.

In general, it’s better to make your members private if you can, and only use protected when 
derived classes are planned and the cost to build and maintain an interface to those private 
members is too high.

Best pratice:
=============
Favor private members over protected members.
*/