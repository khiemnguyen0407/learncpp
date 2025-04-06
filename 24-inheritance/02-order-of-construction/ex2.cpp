/* Order of construction for inheritance chains */

/* It is sometimes the case that classes are derived from other classes, which are themselves 
derived from other classes. In such cases, we have a chain of constructors. Let us look at a simple
example. */
#include<iostream>

class A
{
private: double va {1};
public:
    A()
    {
        std::cout << "A is constructed:\t";
        std::cout << "va = " << this->get_va() << '\n';
    }

    double get_va() { return this-> va; };
};

class B : public A
{
private: double vb {2};
public:
    B() 
    { 
        std::cout << "B is constructed:\t";
        std::cout << "va = " << this->get_va() << ", vb = " << this->get_vb() << '\n';
    }

    double get_vb() { return this->vb; };

};

class C : public B
{
private: double vc {3};
public:
    C() 
    { 
        std::cout << "C is constructed:\t";
        std::cout << "va = " << this->get_va() << ", vb = " << this->get_vb() 
            << ", vc = " << this->get_vc() << '\n';
    }
    
    double get_vc() { return this-> vc; };
};

class D : public C
{
private: double vd {4};
public:
    D()
    {
        std::cout << "D is constructed:\t";
        std::cout << "va = " << this->get_va() << ", vb = " << this->get_vb() << 
            ", vc = " << this->get_vc() << ", vd = " << this->get_vd() << '\n';
    }

    double get_vd() { return this-> vd; }
};

/* Remember that C++ always constructs the “first” or “most base” class first. It then walks 
through the inheritance tree in order and constructs each successive derived class.*/

int main()
{
    std::cout << "Instantiating A: \n";
    A a;

    std::cout << "Instantiating B: \n";
    B b;

    std::cout << "Instantiating C: \n";
    C c;

    std::cout << "Instantiating D: \n";
    D d;
}

/* 
Conclusion:

C++ constructs derived classes in phases, starting with the most-base class (at the top of the 
inheritance tree) and finishing with the most-child class (at the bottom of the inheritance tree). 
As each class is constructed, the appropriate constructor from that class is called to initialize 
that part of the class.

You will note that our example classes in this section have all used base class default 
constructors (for simplicity). In the next lesson, we will take a closer look at the role of 
constructors in the process of constructing derived classes (including how to explicitly choose 
which base class constructor you want your derived class to use).
*/