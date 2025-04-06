#include <iostream>

class Fraction
{
private:
    int numerator{ 0 };
    int denominator{ 1 };

public:
    Fraction() = default;
    Fraction(int numerator, int denominator)
        : numerator{ numerator }
        , denominator{ denominator }
    {
    }

    void print() const
    {
        if (numerator != 0)
            std::cout << numerator << '/' << denominator << '\n';
        else
            std::cout << 0 << '\n';
    }
};

int main()
{
    Fraction f1 {3, 5};
    f1.print();

    Fraction f2 {}; // will get Fraction 0/1
    f2.print();

    return 0;
}