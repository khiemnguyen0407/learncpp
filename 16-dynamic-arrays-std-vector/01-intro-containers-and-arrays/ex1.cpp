#include <iostream>
#include <string>

int main()
{
    std::string name{ "Alex" }; // strings are a container for characters
    std::cout << name; // output our string as a sequence of characters

    std::cout << name << " has " << name.length() << " characters.\n";

    return 0;
}