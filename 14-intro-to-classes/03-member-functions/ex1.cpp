// Member function version
#include <iostream>

struct Date
{
    unsigned day {};
    unsigned month {};
    unsigned year {};

    void print() // defines a member function named print
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

// non-member version of print
void print(const Date& date)
{
    // member variables accessed using member selection operator (.)
    std::cout << date.year << "/" << date.month << '/' << date.day << '\n';
}

int main()
{

    Date yesterday = { 23, 02, 2025 };  // aggregate initilize our structure

    print(yesterday);

    Date today { 16, 02, 2025 }; // aggregate initialize our struct

    today.day = 24; // member variables accessed using member selection operator (.)
    today.print();  // member functions also accessed using member selection operator (.)

    
    return 0;
}