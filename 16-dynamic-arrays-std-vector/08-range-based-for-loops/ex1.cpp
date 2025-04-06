#include <iostream>
#include <vector>

int main()
{
    std::vector fibonacci { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
    for (int num : fibonacci) // iterate over array fibonacci and copy each value into `num`
       std::cout << num << '\t'; // print the current value of `num`

    std::cout << '\n';

    // Because element_declaration should have the same type 
    // as the array elements (to prevent type conversion from occurring), 
    // this is an ideal case in which to use the auto keyword, and 
    // let the compiler deduce the type of the array elements for us.
    for (auto num : fibonacci)
        std::cout << num << '\t';
    std::cout << '\n';

    /* For each iteration of this loop, the next std::string element from the words array 
    will be assigned (copied) into the variable word. Copying a std::string is expensive, 
    which is why we typically pass std::string to functions by const reference. We want 
    to avoid making copies of things that are expensive to copy unless we really need 
    a copy. In this case, we’re just printing the value of the copy and then the copy 
    is destroyed. It would be better if we could avoid making a copy and just reference 
    the actual array element. */
    std::vector<std::string> words{ "This", "course", "is", "really", "suck!" };

    for (auto word : words) // word is now a const reference
        std::cout << word << ' ';

    std::cout << '\n';

    // We can avoid the copy by using a (const) reference in the transversing
    for (const auto& word : words) // word is now a const reference
        std::cout << word << ' ';
    std::cout << '\n';

    /* Normally we’d use auto for cheap-to-copy types, auto& when we want to modify 
    the elements, and const auto& for expensive-to-copy types. But with range-based 
    for loops, many developers believe it is preferable to always use const auto& 
    because it is more future-proof.*/


    // std::vector empty { };
    // for (int num : empty) {
    //     std::cout << "Hello empty world!";
    // }

    return 0;
}