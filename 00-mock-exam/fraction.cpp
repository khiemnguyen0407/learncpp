#include <iostream>
#include <bits/stdc++.h>
#include <vector>
class Fraction
{
    private:
        int nominator {};
        int denominator {};

    public:
        // Constructor
        Fraction(int nominator=0, int denominator=1):
            nominator {nominator}, denominator {denominator} 
        {}

        int get_nominator() const {return this->nominator; }
        int get_denominator() const {return this->denominator; }

        Fraction add (const Fraction& f)
        {
            Fraction result;
            result.nominator = this->nominator + f.nominator;
            result.denominator = this->denominator + f.denominator;
            return result;
        }

        Fraction multiply (const Fraction& f)
        {
            Fraction result;
            result.nominator = this->nominator * f.nominator;
            result.denominator = this->denominator * f.denominator;
            return result;
        }

        friend Fraction operator+(const Fraction& f1, const Fraction& f2);
        friend Fraction operator*(const Fraction& f1, const Fraction& f2);

        // Assignment operator must be defined as member function
        Fraction& operator=(const Fraction& f)
        {
            this->nominator = f.nominator;
            this->denominator = f.denominator;
            return *this;
        }

        Fraction reduce()
        {
            int gcd {std::__gcd(this->nominator, this->denominator)};
            this->nominator /= gcd;
            this->denominator /= gcd;

            Fraction result {this->nominator, this->denominator};
            return result;
        }
};

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    int nom { f.get_nominator() };
    int denom { f.get_denominator() };
    if (nom == 0)
        out << f.get_nominator();
    else 
    {
        if (denom == 1)
            out << f.get_nominator();
        else
        {
            if (nom > 0 & denom > 0)
                out << nom << "/" << denom;
            if (nom < 0 & denom < 0)
                out << -nom << "/" << -denom;
            if (nom > 0 & denom < 0)
                out << "-" << nom << "/" << -denom;
            if (nom < 0 & denom > 0)
                out << "-" << -nom << "/" << denom;
        }
    }
    out << "\n";
    return out;
}

Fraction operator+(const Fraction& a, const Fraction& b)
{
    int nominator {a.nominator * b.denominator + a.denominator * b.nominator};
    int denominator {a.denominator * b.denominator};
    Fraction result {nominator, denominator};
    // Fraction result {a.nominator * b.denominator + a.denominator * b.nominator, a.denominator * b.denominator};
    return result;
}

Fraction operator*(const Fraction& a, const Fraction& b)
{
    int nominator {a.nominator * b.nominator};
    int denominator {a.denominator * b.denominator};
    Fraction result {nominator, denominator};
    // Fraction result {a.nominator * b.nominator, a.denominator * b.denominator};
    return result;
}

int main()
{
    Fraction f0 {2, 3};
    std::cout << "f0 = " << f0;
    
    Fraction a {2, 3};
    Fraction b {3, 4};
    std::cout << "a + b = " << a + b;
    std::cout << "a * b = " << a * b;

    Fraction c1 = a + b;
    Fraction c2 = a * b;
    std::cout << "c1 = " << c1;
    std::cout << "c2 = " << c2;

    Fraction f {30 * 5, 30 * 15};
    std::cout << "Before reduction: f = " << f;
    std::cout << "After reduction:  f = " << f.reduce();

    std::vector<Fraction> list;
    Fraction prod {1, 1};
    for (int i {1}; i < 6; ++i) {
        Fraction f { 1, i + 1};
        list.push_back(f);

        prod = prod * f;
    }
    
    std::cout << "prod = " << prod;
    return 0;
}