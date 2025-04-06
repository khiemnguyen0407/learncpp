/* Overloading operator << to print a struct */
#include <iostream>
#include <string>

struct Employee
{
    unsigned int id {};
    unsigned int  age {};
    unsigned int salary_grade {42};
    double wage;
    std::string position {"Lecturer"};
    std::string admin_role;
};

std::ostream& operator<<(std::ostream& out, const Employee& employee)
{
    out << "ID: " << employee.id << '\n';
    out << "Age: " << employee.age << '\n';
    out << "Salary grade: " << employee.salary_grade << '\n';
    out << "Wage: " << employee.wage << '\n';
    out << "Position: " << employee.position << '\n';
    out << "Admin Role: " << employee.admin_role << '\n';

    return out;
}

int main()
{
    Employee joe { 2, 28 }; // joe.admin_role will be value-initialized to empty string
    std::cout << joe << '\n';

    return 0;
}