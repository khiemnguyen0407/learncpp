#include <iostream>

class Date
{
// Any members defined here would default to private

public: // here's our public access specifier

    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << year << '/' << month << '/' << day;
    }

private: // here's our private access specifier

    int year { 2001 };  // private due to above private: specifier
    int month { 1 }; // private due to above private: specifier
    int day { 1 };   // private due to above private: specifier
};

// Since classes default to private access, you can omit a 
// leading private: access specifier:

class Foo
{
    // private access specifier not required 
    // here since classes default to private members
    int something {};  // private by default
};

/* However, because classes and structs have different access level 
defaults, many developers prefer to be explicit: */
class Foo2
{
private: // redundant, but makes it clear that what follows is private
    int something {};  // private by default
};


int main()
{
    Date d{};
    d.print();  // okay, main() allowed to access public members

    return 0;
}