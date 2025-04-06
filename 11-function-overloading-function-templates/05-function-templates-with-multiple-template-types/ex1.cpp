#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

template <typename T, typename U>
auto min(T x, U y)
{  
    return (x < y) ? x : y;
}

int main()
{
    std::cout << max(2, 3.5) << '\n'; // resolves to max<int, double>
    // But, then the result is misleading. Compile and see the result. It prints "3" because
    // 3.5 has been cast to integer and thus the value 3 is printed to the console.

    std::cout << min(2, 3.5) << '\n';
    return 0;
}