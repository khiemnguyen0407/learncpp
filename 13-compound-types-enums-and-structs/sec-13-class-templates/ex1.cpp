#include <iostream>

// function to calculate the greater of two int values
template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

// almost identical function to calculate the greater of two double values
// the only difference is the type information
// double max(double x, double y)
// {
//     return (x < y) ? y : x;
// }

int main()
{
    std::cout << max<int>(5, 6);     // calls max(int, int)
    std::cout << '\n';
    std::cout << max<double>(1.2, 3.4); // calls max(double, double)

    return 0;
}