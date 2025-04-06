#include <iostream>
#include "Fraction.h"
// struct Fraction
// {
//     int numerator {};
//     int denominator {};
// };

void print(Fraction& frac)
{
    std::cout << frac.numerator << "/" << frac.denominator;
}

int main() 
{
    Fraction f { 3, 4 };    // this actually instantiates a fraction object named f
    std::cout << "fraction f = ";
    print(f);
    return 0;
}