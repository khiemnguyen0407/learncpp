#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> msg {"Congratuations", "on", "running", "C++ code", "using CMake!"};
    for (const std::string& word : msg) {
        std::cout << word << " ";
    }
    std::cout << '\n';

    std::cout << "This is a simple C++ program." << std::endl;
    std::cout << "It demonstrates the use of CMake for building C++ projects." << std::endl;
}