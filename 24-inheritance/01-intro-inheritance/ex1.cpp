/* Basic inheritance in C++ */

/* 
Inheritance in C++ takes place between classes. In an inheritance (is-a) relationship, the class 
being inherited from is called the parent class, base class, or superclass, and the class doing the 
inheriting is called the child class, derived class, or subclass.

A child class inherits both behaviors (member functions) and properties (member variables) from the 
parent (subject to some access restrictions that we’ll cover in a future lesson). These variables 
and functions become members of the derived class. 

Because child classes are full-fledged classes, they can (of course) have their own members that 
are specific to that class. 
*/

#include <iostream>
#include <string>
#include <string_view>

class Person
{
// In this example, we're making our members public for simplicity
public:
    std::string name{};
    int age{};

    Person(std::string_view name = "", int age = 0)
        : name { name }, age { age }
    {
        std::cout << "a person is born!";
    }

    const std::string& get_name() const { return this->name; }
    int get_age() const { return this->age; }

};

/* To have BaseballPlayer inherit from our Person class, the syntax is fairly simple. After the 
class BaseballPlayer declaration, we use a colon, the word “public”, and the name of the class we 
wish to inherit. This is called public inheritance. We'll talk more about what public inheritance 
means in a future lesson.*/

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
public:
    double batting_average{};
    int home_runs{};

    BaseballPlayer(double batting_average = 0.0, int home_runs = 0)
       : batting_average { batting_average }, home_runs { home_runs }
    {
        std::cout << "a guy has just become a baseball player!";
    }
};

/* When BaseballPlayer inherits from Person, BaseballPlayer acquires the member functions and 
variables from Person. Additionally, BaseballPlayer defines two members of its own: batting_average 
and home_runs. This makes sense, since these properties are specific to a BaseballPlayer, not to 
any Person.

Thus, BaseballPlayer objects will have 4 member variables: batting_average and home_runs from 
BaseballPlayer, and name and age from Person.
*/

/* Let's write another class that also inherits from Person. This time, we'll write an Employee
class. An employee "is a" person, so using inheritance is apporpriate. */

class Employee: public Person
{
public:
    double hourly_salary {};
    long employeID {};

    Employee(double hourly_salary = 0.0, long employeeID = 0) 
        : hourly_salary {hourly_salary}, employeID { employeID }
    {
    }

    void print_name_and_salary() const
    {
        std::cout << this->name << ": " << this->hourly_salary << '\n';
    }
};

/* It’s possible to inherit from a class that is itself derived from another class. There is 
nothing noteworthy or special when doing so -- everything proceeds as in the examples above. 

For example, let's write a Supervisor class. A Supervisor is an Employee, which is a Person. 
We've already written an Employee class, so let’s use that as the base class from which to derive 
Supervisor. 

All Supervisor objects inherit the functions and variables from both Employee and Person, and add 
their own m_overseesIDs member variable. By constructing such inheritance chains, we can create a 
set of reusable classes that are very general (at the top) and become progressively more specific 
at each level of inheritance.
*/

class Supervisor: public Employee
{
public:
    // This Supervisor can oversee a max of 5 employees
    long overseeIDs[5]{};

    void print_info() 
    {
        std::cout << "Name: " << this->name << '\n';
        std::cout << "Age: " << this->age << '\n';
        std::cout << "Employee ID: " << this->employeID << '\n';
        std::cout << "Hourly salary: " << this->hourly_salary << '\n';
        std::cout << "oversee IDs: ";
        for (int i {0}; i < 5; ++i) {
            std::cout << this->overseeIDs[i] << "  ";
        }
    }
};



int main()
{
    // Create a new BaseballPlayer object
    BaseballPlayer joe {};
    joe.name = "Joe";

    // use the get_name() function we've acquired from the Person base class
    std::cout << "object joe has name: " << joe.get_name() << '\n';

    // Create a new Employee object
    Employee frank {20.25, 42};

    // we can do this because name is public - otherwise define set_name() in Person
    frank.name = "Frank";
    std::cout << "Info about frank object --> ";
    frank.print_name_and_salary();

    // Create a Supervisor object
    Supervisor scott;

    scott.name = "Scott";
    scott.hourly_salary = 32;
    scott.employeID = 36;
    for (int i {0}; i < 5; ++i)
        scott.overseeIDs[i] = i + 1;

    std::cout << "Infomation of Scott:\n";
    scott.print_info();

    return 0;
}

/*
Why is this kind of inheritance useful?
=======================================
Inheriting from a base class means we don’t have to redefine the information from the base class in 
our derived classes. We automatically receive the member functions and member variables of the base 
class through inheritance, and then simply add the additional functions or member variables we 
want. This not only saves work, but also means that if we ever update or modify the base class 
(e.g. add new functions, or fix a bug), all of our derived classes will automatically inherit the 
changes!

For example, if we ever added a new function to Person, then Employee, Supervisor, and 
BaseballPlayer would automatically gain access to it. If we added a new variable to Employee, then 
Supervisor would also gain access to it. This allows us to construct new classes in an easy, 
intuitive, and low-maintenance way!

Conclusion:
===========
Inheritance allows us to reuse classes by having other classes inherit their members.
*/