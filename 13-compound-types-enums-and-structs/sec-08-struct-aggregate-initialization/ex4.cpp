#include <iostream>

struct ComplexNumber
{
    double re {};
    double im {};
};

std::ostream& operator<<(std::ostream& out, const ComplexNumber& c)
{
    if (c.re != 0)
    {
        out << c.re;
        if (c.im != 0) {
            out << " + " << c.im << "*i";
        }
    }
    else {
        if (c.im != 0) {
            out << c.im << "*i";
        }
        else
            out << '0';
    }
    out << '\n';
    return out;
}

int main()
{
    const ComplexNumber real_unit { 1.0, 0.0 };     // For const declaration, we must initilize
    const ComplexNumber imaginary_unit { 0.0, 1.0};
    const ComplexNumber a {1.0, 2.0};

    std::cout << "Real unit: " << real_unit << '\n';
    std::cout << "Imaginary unit: " << imaginary_unit << '\n';
    std::cout << "a = " << a;
    return 0;
}