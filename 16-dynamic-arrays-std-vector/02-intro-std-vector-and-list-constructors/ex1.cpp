#include <iostream>
#include <vector>

int main()
{
	// Value initialization (uses default constructor)
	std::vector<int> empty{}; // vector containing 0 int elements


    // List construction (uses list constructor)

    // vector containing 6 int elements with values 
    // 2, 3, 5, 7, 11, and 13
	std::vector<int> primes{ 2, 3, 5, 7, 11, 13};          

    // vector containing 5 char elements with values 'a', 'e', 'i', 'o', and 'u'.
    // Uses CTAD (C++17) to deduce element type char (preferred).
	std::vector vowels { 'a', 'e', 'i', 'o', 'u' }; 

    /* In C++, the most common way to access array elements is by 
    using the name of the array along with the subscript operator 
    (operator[]). */
    std::cout << "First prime number = " << primes[0] << '\n';
    std::cout << "Second prime number = " << primes[1] << '\n';
    int s = 0;
    auto n {primes.size()};
    for (int j {0}; j < n; j++) {
        s += primes[j];
    }

    std::cout << "The sum of the first " << n << " primes = " << s << '\n';

	return 0;
}