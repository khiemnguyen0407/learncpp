/* Public inheritance */

/*
Public inheritance is by far the most commonly used type of inheritance. In fact, very rarely will 
you see or use the other types of inheritance, so your primary focus should be on understanding 
this section. Fortunately, public inheritance is also the easiest to understand. When you inherit 
a base class publicly, inherited public members stay public, and inherited protected members stay 
protected. Inherited private members, which were inaccessible because they were private in the base 
class, stay inaccessible.

Access specifier in base class	|   Access specifier when inherited publicly
============================================================================
Public	                        |   Public
Protected	                    |   Protected
Private	                        |   Inaccessible
*/

#include<iostream>

class Base
{
private:
    double private_value {};
protected:
    double protected_value {};
public:
    double public_value {};

    void print_values()
    {
        std::cout << "public value    = " << this->public_value << '\n';
        std::cout << "protected value = " << this->protected_value << '\n';
        std::cout << "private value   = " << this->private_value << '\n';
    }
};

class Pub: public Base
{
    // Public inheritance means:
    // Public inherited members stay public (so m_public is treated as public)
    // Protected inherited members stay protected (so m_protected is treated as protected)
    // Private inherited members stay inaccessible (so m_private is inaccessible)
public:
    Pub()
    {
        // okay: m_public was inherited as public
        public_value = 1;

        // okay: m_protected was inherited as protected
        protected_value = 2;

        // not okay: m_private is inaccessible from derived class
        // private_value = 3;
    }
};

int main()
{
    Base base;
    // okay: public_value is public in Base
    base.public_value = 1;

    // not okay: protected_value is protected in Base
    // base.protected_value = 2;

    // not okay: private_value is private in Base
    // base.private_value = 3;
    std::cout << "Info of the object base:\n";
    base.print_values();
    Pub pub;

    // okay: public_value is public in Pub
    pub.public_value = 1;

    // not okay: protected_value is protected in Pub
    // pub.protected_value = 2;

    // not okay: private_value is inaccessible in Pub
    // pub.private_value = 3;
    std::cout << "\nInfo of the object pub:\n";
    pub.print_values();

    return 0;
}