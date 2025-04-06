/* Range-based for loops in reverse */

/* Range-based for loops only iterate in forwards order. However, there are cases 
where we want to traverse an array in reverse order. Prior to C++20, range-based 
for loops could not be easily used for this purpose, and other solutions had to 
be employed (typically normal for-loops).

However, as of C++20, you can use the std::views::reverse capability of the Ranges 
library to create a reverse view of the elements that can be traversed:
*/
#include <iostream>
#include <ranges> // C++20
#include <string_view>
#include <vector>

int main()
{
    std::vector<std::string_view> words{ "suck!", "is", "course", "This" }; // sorted in alphabetical order

    for (const auto& word : std::views::reverse(words)) // create a reverse view
        std::cout << word << ' ';

    std::cout << '\n';

    return 0;
}