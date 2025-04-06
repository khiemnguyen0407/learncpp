#include <iostream>

struct Employee
{
    int id{};
    int age{};
    double wage{};
};

void print_employee(const Employee& employee)
{
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "Id: " << employee.id << '\n';
    std::cout << "Age: " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main()
{
    Employee joe{ 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    print_employee(joe);

    Employee frank { 2, 32, 80000.0};
    Employee* ptr { &frank };
    /* The following lines of code would give error 
    because the ptr is the pointer, not the Employee object*/
    // std::cout << ptr.id << '\n';
    // std::cout << ptr.age << '\n';
    // std::cout << ptr.wage << '\n';

    // However, this would work then
    std::cout << "Frank's information";
    std::cout << (*ptr).id << '\n';
    std::cout << (*ptr).age << '\n';
    std::cout << (*ptr).wage << '\n';

    Employee* ptr2 { &frank };
    ptr = nullptr;
    std::cout << "Frank's information:\n";
    std::cout << ptr2->id << '\n';
    std::cout << ptr2->age << '\n';
    std::cout << ptr2->wage << '\n';

    return 0;
}