#include <iostream>
#include <string>
void print_integer_pass_by_value(int y)
{
    std::cout << y << '\n';
} // y is destroyed here

void print_integer_pass_by_reference(int& y)
{
    std::cout << y << '\n';
}

void print_str_pass_by_ref(std::string& y)
{
    std::cout << y << '\n';
}   // y is destroyed ahere

void print_str_pass_by_value(std::string y)
{
    std::cout << y << '\n';
}

void print_addresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

void add_two_by_value(int y)
{
    y += 2;
}

void add_two_by_reference(int& y)
{
    y += 2;
}

int main()
{
    int x1 { 2 };
    print_integer_pass_by_value(x1);     // x is passed by value (copied) into parameter y (expensive)

    std::string my_str { "Hello world!" };

    print_str_pass_by_value(my_str);    // my_str is passed by value into value parameter y (expensive)
    print_str_pass_by_ref(my_str);      // my_str is now passed by reference into reference parameter y (inexpensive)

    int x2 { 5 };
    std::cout << "The address of x2 is: " << &x2 << '\n';

    print_addresses(x2, x2);

    int x3 { 42 };

    add_two_by_value(x3);
    std::cout << "value of x3 (after pass by value)     = " << x3 << '\n';

    add_two_by_reference(x3);
    std::cout << "value of x3 (after pass by reference) = " << x3 << '\n';

    
    print_integer_pass_by_value(x1);    // ok: x1 is a modifable lvalue
    // const int x4 { 10 };
    // print_integer_pass_by_reference(x4);    // error: x4 is non-modifiable lvalue
    // print_integer_pass_by_reference(5);     // error: 5 is an rvalue
    
}