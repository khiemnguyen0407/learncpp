#include <iostream>
#include <bits/stdc++.h>
#include <vector>
class Fraction
{   
    // Question a --> 2 marks
    private:
        int nominator {};
        int denominator {};

    public:
        // Constructor
        Fraction(int nominator=0, int denominator=1):
            nominator {nominator}, denominator {denominator} 
        {
            if (this->denominator == 0) {
                std::cout << "You stupid dumb! Go back to learn fraction! ";
                std::cout << "I already set demonator to 1 for you.\n";
                this->denominator = 1;
            }

        }

        int get_nominator() const {return this->nominator; }
        int get_denominator() const {return this->denominator; }

        Fraction add (const Fraction& f)
        {
            Fraction result;
            result.nominator = this->denominator * f.nominator + this->nominator * f.denominator;
            result.denominator = this->denominator * f.denominator;
            return result;
        }       // f1.add(f2)

        Fraction multiply (const Fraction& f)
        {
            Fraction result;
            result.nominator = this->nominator * f.nominator;
            result.denominator = this->denominator * f.denominator;
            return result;
        }       // f1.multiply(f2)

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

std::ostream& operator<<(std::ostream& out, const Fraction& f)      // out << f -- resemble a + b with a corresponds to out, + correspond << f corresponds to b.
{
    int nom { f.get_nominator() };
    int denom { f.get_denominator() };
    if (nom == 0)
        out << nom;
    else 
    {
        if (denom == 1)
            out << nom;
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
    // int nominator {a.nominator * b.denominator + a.denominator * b.nominator};
    // int denominator {a.denominator * b.denominator};
    // Fraction result {nominator, denominator};
    Fraction result {a.nominator * b.denominator + a.denominator * b.nominator, a.denominator * b.denominator};
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
    std::cout << "a + b = " << a.add(b);
    std::cout << "a * b = " << a.multiply(b);

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