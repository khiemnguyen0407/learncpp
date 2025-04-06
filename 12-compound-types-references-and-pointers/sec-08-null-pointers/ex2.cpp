#include <iostream>

void do_absolute_nothing(int* ptr)
{
    std::cout << "do absolute nothing" << '\n';
}

void print_value_pointed_by_pointer(int* ptr)
{
    std::cout << "Value pointed by pointer ptr: " << *ptr << '\n';
}



int main()
{
    int* ptr1 { nullptr }; // can use nullptr to initialize a pointer to be a null pointer
    do_absolute_nothing(ptr1);
    print_value_pointed_by_pointer(ptr1);

    int value { 5 };
    int* ptr2 { &value }; // ptr2 is a valid pointer
    print_value_pointed_by_pointer(ptr2);


    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer

    print_value_pointed_by_pointer(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    return 0;
}