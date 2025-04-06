/* Inheritance chains of constructors */

/* 
We have learned about the order of the constructors and how to execute a particular constructor
of the base class inside the constructor of the derived class. TClasses in an inheritance chan work
in exactly the same logic of order and initialization we've learned in the last cpp files.
*/

#include<iostream>

class A
{
private:
    double va {};
public:
    A(double va) : va {va}
    {
        std::cout << "A: va = " << va << '\n';
    }
    ~A()
    {
        std::cout << "A is destroyed!" << '\n';
    }
};

class B: public A
{
private:
    double vb {};
public: 
    B(double va, double vb) 
    : A {va}
    , vb { vb}
    {
        std::cout << "B: va = " << va << ", vb = " << vb << '\n';
    }
    ~B()
    {
        std::cout << "B is destroyed!" << '\n';
    }
};

class C: public B
{
private:
    double vc {};
public:
    C(double va, double vb, double vc)
    : B {va, vb},
    vc { vc }
    {
        std::cout << "C: va = " << va << ", vb = " << vb << ", vc = " << vc << '\n';
    }
    ~C()
    {
        std::cout << "C is destroyed!" << '\n';
    }
};

int main()
{
    C c { 0.5, 1.5, 2.5 };
    return 0;
}

/* Remark: 
==========
It is worth mentioning that constructors can only call constructors from their immediate 
parent/base class. Consequently, the C constructor could not call or pass parameters to the A 
constructor directly. The C constructor can only call the B constructor (which has the 
responsibility of calling the A constructor).
*/

/* 
Destructors:
============
When a derived class is destroyed, each destructor is called in the reverse order of construction. 
In the above example, when c is destroyed, the C destructor is called first, then the B destructor, 
then the A destructor.
*/

/* 
SUMMARY:
========
When constructing a derived class, the derived class constructor is responsible for determining 
which base class constructor is called. If no base class constructor is specified, the default base 
class constructor will be used. In that case, if no default base class constructor can be found (or 
created by default), the compiler will display an error. The classes are then constructed in order 
from most base to most derived.
*/