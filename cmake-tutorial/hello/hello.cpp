#include <iostream>
#include <vector>

int main() 
{
    std::cout << "Example using std::vector:\n";
    std::vector<double> numbers {1.2, 2.1, 3.2, 2.3};

    for (double value : numbers)
        std::cout << value << '\t';
    std::cout << std::endl;
    return 0; 
}