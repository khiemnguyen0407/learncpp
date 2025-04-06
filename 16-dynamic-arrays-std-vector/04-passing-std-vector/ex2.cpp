#include <iostream>
#include <vector>

template <typename T>
void print_array_pass_by_ref(const std::vector<T>& arr) // we must explicitly specify <int> here
{
    for (int j {0}; j < arr.size(); j++) 
        std::cout << arr[j] << "\t";
    std::cout << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    std::cout << "Array of integers:\n";
    print_array_pass_by_ref(primes);


    std::vector darray { 2.5, 3.5, 5.5, 7.5, 11.5};
    std::cout << "Array of doubles:\n";
    print_array_pass_by_ref(darray);

    std::vector<float> farray { 1.5, 3.5, 5.5, 7.5, 9.5};
    std::cout << "Array of floats:\n";
    print_array_pass_by_ref(farray);
    return 0;
}