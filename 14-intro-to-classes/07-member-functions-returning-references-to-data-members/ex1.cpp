#include <iostream>
#include <string>

class Employee
{
	std::string name{};

public:
	void set_name(std::string_view name) { this->name = name; }
	std::string get_name() const { return name; } //  getter returns by value
};

int main()
{
	Employee joe{};
	joe.set_name("Joe");
	std::cout << joe.get_name();

	return 0;
}