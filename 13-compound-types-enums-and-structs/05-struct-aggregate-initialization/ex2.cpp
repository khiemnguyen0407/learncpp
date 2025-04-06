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

void print_employee_info(const Employee& employee)
{
    std::cout << "ID: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Salary grade: " << employee.salary_grade << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
    std::cout << "Position: " << employee.position << '\n';
    std::cout << "Admin Role: " << employee.admin_role << '\n';
}

int main()
{
    Employee joe { 2, 28 }; // joe.whatever will be value-initialized to 0.0

    print_employee_info(joe);
    return 0;
}