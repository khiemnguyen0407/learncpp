#include <iostream>

class Date // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int year {};     // private by default
    int month {};    // private by default
    int day {};      // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

    // private members can not be accessed by the public
    today.day = 16; // compile error: the day member is private
    today.print();    // compile error: the print() member function is private

    return 0;
}