#include <iostream>

template <typename T, typename U>
auto max(T x, U y) // ask compiler can figure out what the relevant return type is
{
    return (x < y) ? y : x;
}

auto min(auto x, auto y)
{
    return (x < y) ? x : y;
}

int main()
{
    std::cout << "max(2, 3.5) = " << max(2, 3.5) << '\n';
    
    std::cout << "min(2.5, 3) = " << min(2.5, 3) << '\n';
    return 0;
}