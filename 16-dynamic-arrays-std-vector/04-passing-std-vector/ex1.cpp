#include <iostream>
#include <vector>


/* With a std::vector, the element type is part of the type information of the 
object. Therefore, when we use a std::vector as a function parameter, we have 
to explicitly specify the element type:
*/
void print_array_pass_by_ref(const std::vector<int>& arr) // we must explicitly specify <int> here
{
    for (int j {0}; j < arr.size(); j++) 
        std::cout << arr[j] << "\t";
    std::cout << '\n';
}

int main()
{
    std::vector primes{ 2, 3, 5, 7, 11 };
    print_array_pass_by_ref(primes);


    // Because print_array_pass_by_ref() expects a std::vector<int>, we are unable to pass
    // vectors with different element types
    std::vector dbl {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    // compile error: std::vector<double> is not convertible to std::vector<int>
    // print_array_pass_by_ref(dbl);   
    return 0;
}