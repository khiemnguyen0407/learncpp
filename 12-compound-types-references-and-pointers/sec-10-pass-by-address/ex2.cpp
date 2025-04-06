#include <iostream>
#include <string>
void change_value(std::string* str_ptr, std::string str) // note: ptr is a pointer to non-const in this example
{
    *str_ptr = str;
}

int main()
{
    std::string str { "Hello world! "};

    std::cout << "str = " << str << '\n';

    change_value(&str, "This course is purely suck!"); // we're passing the address of x to the function

    std::cout << "str = " << str << '\n';

    std::string another_str {"This course cannot be sucker!"};

    change_value(&str, another_str);
    std::cout << "str = " << str << '\n';

    return 0;
}