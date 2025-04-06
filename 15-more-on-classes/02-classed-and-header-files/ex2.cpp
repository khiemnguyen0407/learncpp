#include <iostream>

class Date
{
private:
    int day {};
    int month {};
    int year {};   

public:

    Date(int day, int month, int year); // constructor declaration

    void print() const;     // print function declaration

    int get_day() const { return this->day; }

    int get_month() const { return this->month; }

    int get_year() const { return this->year; }
};

Date::Date(int day, int month, int year)
: day { day }, month { month }, year { year }
{
    std::cout << "Date(" << this->day << "," << this->month << "," << this->year << ") constructed\n";
}

void Date::print() const 
{
    std::cout << "Date: " << day << "/" << month << "/" << year << '\n';
};

int main()
{
    const Date today { 03, 03, 2025 };
    today.print();

    return 0;
}