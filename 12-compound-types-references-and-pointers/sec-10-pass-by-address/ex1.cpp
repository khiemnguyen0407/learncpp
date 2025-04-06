#include <iostream>
#include <string>

void print_by_value(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void print_by_reference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void print_by_address(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

int main()
{
    std::string my_str{ "This course is absolutely suck this semester!" };
    // pass by value: make a copy of the argument my_str
    print_by_value(my_str); 
    // pass by reference: DO NOT make a copy of the argument my_str
    print_by_reference(my_str); 
    // pass str by address: DO NOT make a copy of the argument my_str
    print_by_address(&my_str); 
    
    return 0;
}