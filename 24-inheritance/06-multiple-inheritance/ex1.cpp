/* Multiple inheritance */

/*
So far, all of the examples of inheritance we’ve presented have been single inheritance -- that is, 
each inherited class has one and only one parent. However, C++ provides the ability to do multiple 
inheritance. Multiple inheritance enables a derived class to inherit members from more than one 
parent.


Let's say we wanted to write a program to keep track of a bunch of teachers. A teacher is a person. 
However, a teacher is also an employee (they are their own employer if working for themselves). 
Multiple inheritance can be used to create a Teacher class that inherits properties from both 
Person and Employee. To use multiple inheritance, simply specify each base class (just like in 
single inheritance), separated by a comma.
*/

#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string name {};
    int age {};

public:
    Person(std::string_view name, int age)
        : name { name }, age { age }
    {
        std::cout << "A person is born.\n";
    }

    const std::string& get_name() const { return name; }
    int get_age() const { return age; }

    void print_info()
    {
        std::cout << "Name: " << this->name << '\n';
        std::cout << "Age: " << this->age << '\n';
    }
};

class Employee
{
private:
    std::string employer {};
    double wage {};

public:
    Employee(std::string_view employer, double wage)
        : employer { employer}, wage { wage }
    {
        std::cout << "An employee is constructed\n";
    }
};

class Teacher : public Person, public Employee
{
private:
    int teaches_grade {1};
public:
    Teacher(std::string_view name, int age, std::string_view employer, double wage, 
        int teachers_grade)
        : Person { name, age }, Employee { employer, wage }, teaches_grade { teaches_grade}
    {
        std::cout << "A teacher is constructed.\n";
    }

    void print_info()
    {
        std::cout << "AHHHHH";
    }
};

int main()
{
    Person joe { "Joe", 24 };
    std::cout << "Info of Joe:\n";
    joe.print_info();
    Employee frank { "Uni of Glasgow", 36000 };
    Teacher scott { "Scott", 55, "University of Glasgow", 65000, 12};

    std::cout << "Info of teacher Scott:\n";
    scott.print_info();
}