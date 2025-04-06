#include <iostream>

struct Date
{
    // struct members are public by default, can be accessed by anyone
    int year {};       // public by default
    int month {};      // public by default
    int day {};        // public by default

    void print() const // public by default
    {
        // public members can be accessed in member functions of the class type
        std::cout << year << '/' << month << '/' << day;
    }
};

// non-member function main is part of "the public"
int main()
{
    Date today { 2024, 02, 24 }; // aggregate initialize our struct

    // public members can be accessed by the public
    today.day = 16; // okay: the day member is public
    today.print();  // okay: the print() member function is public

    return 0;
}