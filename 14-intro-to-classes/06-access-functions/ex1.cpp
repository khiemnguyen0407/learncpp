#include <iostream>

class Date
{
private:
    int m_year{ 2001 };
    int m_month{ 1 };
    int m_day{ 1 };

public:
    void print() const
    {
        std::cout << m_year << '/' << m_month << '/' << m_day << '\n';
    }
};

int main()
{
    Date d{};  // create a Date object
    d.print(); // print the date

    return 0;
}