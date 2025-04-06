/* Overloading unary operators +, -, and ! */

/* Unlike the operators you’ve seen so far, the positive (+), negative (-) and logical not (!) 
operators all are unary operators, which means they only operate on one operand. Because they only 
operate on the object they are applied to, typically unary operator overloads are implemented as 
member functions. All three operators are implemented in an identical manner. */

#include <iostream>

class Cents
{
private:
    int cents {};
public:
    Cents(int cents) : cents { cents } {/* empty function body */}

    // Overload -Cents as a member function
    Cents operator-() const;

    int get_cents() const {return this->cents; }
};

// You can see this is a member function!!!
Cents Cents::operator-() const
{   
    // since return type is a Cents, this does an implicit conversion from int to Cents using 
    // the Cents(int) constructor
    // return -cents;

    // Otherwise, we can write explicitly
    Cents result { -(this->cents) };
    return result;
}

int main()
{
    const Cents nickle { 5 };
    std::cout << "A nickle of debt is worth " << (-nickle).get_cents() << " cents\n";

    return 0;
}