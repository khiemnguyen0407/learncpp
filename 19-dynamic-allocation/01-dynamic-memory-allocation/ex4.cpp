/* Null pointers and dynamic memory allocation */

/* Null pointers (pointers set to nullptr) are particularly useful when dealing with dynamic memory 
allocation. In the context of dynamic memory allocation, a null pointer basically says “no memory 
has been allocated to this pointer”. 

Deleting a null pointer has no effect. Thus, there is no need for the following:

if (ptr) // if ptr is not a null pointer
    delete ptr; // delete it
// otherwise do nothing

Instead, we can just simply write:

delete ptr; // no need to test.
*/

#include <iostream>

int main()
{
    int* ptr1 {nullptr};
    int x { 5 };
    int* ptr2 { &x };
    // Test a null pointer will return false, just like test 0:
    if (0) {
        std::cout << "Integer 0 is interpreted as true.\n";
    }
    else {
        std::cout << "Integer 0 is interpreted as false.\n";
    }

    if (nullptr)
        std::cout << "nullptr is interpreted as true.\n";
    else
        std::cout << "nullptr is interpreted as false.\n";

    // As you can see from the output, nullptr is interpreted as false in the if-statement.
    // For this reason, to test whether a pointer is a nullptr, we write 
    if (!ptr1) {
        std::cout << "ptr1 is a null pointer." << '\n';
    }
    else {
        std::cout << "ptr1 is not a null pointer: *ptr1 = " << *ptr1 << '\n';
    }

    if (!ptr2) {
        std::cout << "ptr2 is a null pointer." << '\n';
    }
    else {
        std::cout << "ptr2 is not a null pointer: *ptr2 = " << *ptr2 << '\n';
    }

    delete ptr1;    // this is fine -- no need to test whether it is null or not null.
}


