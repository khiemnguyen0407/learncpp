// #ifndef DATE_H
// #define DATE_H

class Date
{
private:
    int day {};
    int month {};
    int year {};

public:
    Date(int day, int month, int year);
    void print() const;
    int get_day() const { return this->day; }
    int get_month() const { return this->month; }
    int get_year() const { return this->year; }
};