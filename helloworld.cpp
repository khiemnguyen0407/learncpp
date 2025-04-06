#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> msg {"Congratuations", "on", "running", "C++ code", "using CMake!"};
    for (const std::string& word : msg) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}