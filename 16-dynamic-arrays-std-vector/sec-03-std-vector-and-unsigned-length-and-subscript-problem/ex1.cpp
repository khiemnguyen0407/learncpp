#include <iostream>
#include <vector>

int main()
{
    std::vector prime { 2, 3, 5, 7, 11 };
    // returns length as type `size_type` (alias for `std::size_t`)
    std::cout << "size of vector prime: " << prime.size() << "\n"; 
    std::cout << "size of vector prime: " << std::size(prime) << '\n'; // C++17, returns length as type `size_type` (alias for `std::size_t`)


    int length { static_cast<int>(prime.size()) };
    std::cout << "length = " << length;

    // C++20, returns length as a large signed integral type
    // To compile this code, one needs to use
    // g++ -std=c++20 .\ex1.cpp
    // std::cout << "length: " << std::ssize(primes); 
    return 0;
}