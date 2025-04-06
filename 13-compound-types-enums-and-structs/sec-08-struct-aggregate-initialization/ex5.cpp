#include <iostream>

struct ComplexNumber
{
    double re {};
    double im {};
};

std::ostream& operator<<(std::ostream& out, const ComplexNumber& c)
{
    if (c.re != 0) {
        out << c.re;
        if (c.im != 0) {
            out << " + " << c.im << "*i";
        }
    }
    else {
        if (c.im != 0) {
            out << c.im << "*i";
        }
        else {
            out << "0";
        }
    }

    return out;
}

int main()
{
    ComplexNumber a {1.0, 2.0};
    /* Designated initializers: avaliable from C++20 */
    ComplexNumber b {.re = 2.0, .im = 3.0};
    ComplexNumber c {.re {3.0}, .im {2.0}};

    std::cout << "a = " << a << '\n';
    std::cout << "b = " << b << '\n';
    std::cout << "c = " << c << "\n\n";


    /* Initialzing a struct with another struct of the same type */
    std::cout << "Initializing a struct with another structure of the same type:\n";
    ComplexNumber d1 = a;       // Copy initialization
    ComplexNumber d2 (a);       // direct initialization
    ComplexNumber d3 {a};       // direct-list-initialization --> PREFERABLE
    std::cout << "d1 = " << d1 << '\n';
    std::cout << "d2 = " << d2 << '\n';
    std::cout << "d3 = " << d3 << "\n\n";


    /* Assignment with designated initializers */
    ComplexNumber e {};
    std::cout << "before assigning e with new values:\n";
    std::cout << "e = " << e << '\n';
    e = {.re = e.re, .im = c.im};
    std::cout << "after assigning e with new values:\n";
    std::cout << "e = " << e << '\n';
}