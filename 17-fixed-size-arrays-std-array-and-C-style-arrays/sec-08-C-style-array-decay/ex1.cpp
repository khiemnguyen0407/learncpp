/* C-style Array Decay */
#include <iostream>

void print_element_zero(int array[1000])        // does not make a copy
{
    std::cout << array[0];
}

int main()
{
    int x[7] { 5 };     // define an array with 7 elements, the first element = 5.
    std::cout << "values of array x:\n";
    for (int i { 0 }; i < 7; ++i) {
        std::cout << x[7] << '\t';
    }
    std::cout << "\n\n";
    std::cout << "x[0] = ";
    print_element_zero(x);      // somehow it works!!!
    return 0;
}

/* 
First, copying a 1000 element array every time a function is called is expensive 
(and even more so if the elements are an expensive-to-copy type), so we want to
avoid that. But how? C doesn’t have references, so using pass by reference to 
avoid making a copy of function arguments wasn’t an option.

Second, we want to be able to write a single function that can accept array 
arguments of different lengths. Ideally, our printElementZero() function in the 
example above should be callable with arrays arguments of any length (since element 
0 is guaranteed to exist). We don't want to have to write a different function 
for every possible array length that we want to use as an argument. But how? C has
no syntax to specify “any length” arrays, nor does it support templates, nor can 
arrays of one length be converted to arrays of another length (presumably because 
doing so would involve making an expensive copy).

The designers of the C language came up with a clever solution (inherited by C++ 
for compatibility reasons) that solves for both of these issues:

Somehow, the above example passes a 7 element array to a function expecting 
a 1000 element array, without any copies being made. In this lesson, we'll explore 
how this works.
*/