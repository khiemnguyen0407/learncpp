#include <iostream>
#include <vector>

int main()
{
    std::vector test_score { 40, 45, 42, 60, 55, 80, 74, 85, 99, 92 };
    std::size_t length { test_score.size() };

    int average { 0 };
    for (std::size_t index{ 0 }; index < length; ++index) // index from 0 to length-1
        average += test_score[index];                      // add the value of element with index `index`
    average /= static_cast<int>(length);                  // calculate the average

    std::cout << "The class average is: " << average << '\n';

    return 0;
}