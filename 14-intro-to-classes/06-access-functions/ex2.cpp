#include <iostream>

class Date
{
private:
    int m_year { 2001 };
    int m_month { 1 };
    int m_day { 1 };

    // Data encapsulation.
public:
    void print()
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }

    int get_year() const { return m_year; }        // getter for year
    void set_year(int year) { m_year = year; }     // setter for year

    int get_month() const  { return m_month; }     // getter for month
    void set_month(int month) { m_month = month; } // setter for month

    int get_day() const { return m_day; }          // getter for day
    void set_day(int day) { m_day = day; }         // setter for day

};

int main()
{
    Date d{};
    std::cout << "Beforing using setters: \n=======================\n";
    std::cout << "year: " << d.get_year() << " -- " 
              << "month: " << d.get_month() << " -- " << "day: " << d.get_day() << '\n';
    d.print();

    d.set_year(2024);
    d.set_month(2);
    d.set_day(24);
    std::cout << "After using setters: \n=======================\n";
    std::cout << "year: " << d.get_year() << " -- " 
              << "month: " << d.get_month() << " -- " << "day: " << d.get_day() << '\n';
    d.print();

    return 0;
}