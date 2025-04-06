#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string name;
    int age {};

public:
    Person(std::string_view name = "", int age = 0)
        : name { name }, age { age }
    {
    }

    const std::string& get_name() const { return name; }
    int get_age() const { return age; }

};
// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person
{
private:
    double batting_average {};
    int home_runs {};

public:
    BaseballPlayer(std::string_view name = "", int age = 0,
        double batting_average = 0.0, int home_runs = 0)
        : Person{ name, age } // call Person(std::string_view, int) to initialize these fields
        , batting_average { batting_average }, home_runs { home_runs }
    {
    }

    double get_batting_average() const { return batting_average; }
    int get_home_runs() const { return home_runs; }
};

int main()
{
    BaseballPlayer scott { "Scott Roy", 55, 0.42, 42};
    std::cout << "Information of baseball player defined by the object scott:\n";
    std::cout << "Name: " << scott.get_name() << '\n';
    std::cout << "Age: " << scott.get_age() << '\n';
    std::cout << "Batting average: " << scott.get_batting_average() << '\n';
    std::cout << "Home runs: " << scott.get_home_runs() << '\n';

    return 0;
}