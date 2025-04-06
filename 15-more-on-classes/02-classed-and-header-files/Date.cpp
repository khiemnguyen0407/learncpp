#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) // Constructor definition
    : day { day }
    , month { month }
    , year { year }
{}

void Date::print() const   // print function definition
{
    std::cout << "Date: " << day << "/" << month << "/" << year << '\n';
};