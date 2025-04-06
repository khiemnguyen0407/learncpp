#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void print_employee_info(Employee&  employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee frank = { 1, 32, 60000.0 }; // copy-list initialization using braced list
    Employee joe { 2, 28, 45000.0 };     // list initialization using braced list (preferred)
    std::cout << "Information of Frank:\n";
    print_employee_info(frank);

    std::cout << "Information of Joe:\n";
    print_employee_info(joe);

    return 0;
}