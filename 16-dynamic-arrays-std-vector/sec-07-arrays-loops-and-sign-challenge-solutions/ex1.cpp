#include <iostream>
#include <vector>

template <typename T>
void print_reverse(const std::vector<T>& arr)
{
    for (std::size_t index{ arr.size() - 1 }; index >= 1; --index) // index is unsigned
    {
        std::cout << arr[index] << '\t';
    }

    std::cout << '\n';
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    print_reverse(arr);


    std::size_t r {0};
    std::cout << r;
    return 0;
}