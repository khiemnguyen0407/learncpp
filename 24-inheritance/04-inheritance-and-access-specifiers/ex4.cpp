/* Private inheritance */

/*
With private inheritance, all members from the base class are inherited as private. This means 
private members are inaccessible, and protected and public members become private.

Note that this does not affect the way that the derived class accesses members inherited from its
parent! It only affects the code trying to access those members through the derived class.

To summarize in table form:

Access specifier in base class  |   Access specifier when inherited privately
=============================================================================
Public	                        |   Private
Protected	                    |   Private
Private	                        |   Inaccessible

Private inheritance can be useful when the derived class has no obvious relationship to the base 
class, but uses the base class for implementation internally. In such a case, we probably do not 
want the public interface of the base class to be exposed through objects of the derived class (as 
it would be if we inherited publicly).
*/

class Base
{
public:
    double public_value {};
protected:
    double protected_value {};
private:
    double private_value {};
};

class Pri: private Base // note: private inheritance
{
    // Private inheritance means:
    // Public inherited members become private (so public_value is treated as private)
    // Protected inherited members become private (so protected_value is treated as private)
    // Private inherited members stay inaccessible (so private_value is inaccessible)
public:
    Pri()
    {
        public_value = 1; // okay: public_value is now private in Pri
        protected_value = 2; // okay: protected_value is now private in Pri
        private_value = 3; // not okay: derived classes can't access private members in the base class
    }
};

int main()
{
    // Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of base.
    Base base;
    base.public_value = 1; // okay: public_value is public in Base
    base.protected_value = 2; // not okay: protected_value is protected in Base
    base.private_value = 3; // not okay: private_value is private in Base

    Pri pri;
    pri.public_value = 1; // not okay: public_value is now private in Pri
    pri.protected_value = 2; // not okay: protected_value is now private in Pri
    pri.private_value = 3; // not okay: private_value is inaccessible in Pri

    return 0;
}