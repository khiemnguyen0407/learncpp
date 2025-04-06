/* Introduction to smart pointers and move semantics */

#include <iostream>

class Vector3D
{
private:
    double x;
    double y;
    double z;
public:
    Vector3D(double x=0, double y=0, double z=0) 
    : x { x }
    , y { y }
    , z { z }
    {
        std::cout << "Vector3D(" << this->x << "," << this->y 
            << "," << this->z << ") is constructed!";
    }

    void print()
    {
        std::cout << "Vector3D(" << this->x << ", " << this->y << ", " << this->z << ")"; 
    }
};


int main()
{
    Vector3D* ptr {new Vector3D {1, 2, 3}};
    Vector3D v {*ptr};
    std::cout << "\nVector3D pointed by pointer ptr:\n";
    // using object
    v.print();
    std::cout << '\n';
    // using pointer pointing to the object
    ptr->print();
    std::cout << '\n';


    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
    {
        std::cout << "ptr has not been deleted yet! But return is reached.";
        return 0; // the function returns early, and ptr won't be deleted!
    }

    // or via throw exeption
    if (x == 1)
    {
        std::cout << "ptr has not been deleted yet! But an exception is thrown.";
        throw 0;
    }

    // do stuff with ptr here
    delete ptr;

    return 0;
}
/* Discussion:
Although the above code seems fairly straightforward, it’s fairly easy to forget to deallocate ptr. 
Even if you do remember to delete ptr at the end of the function, there are a myriad of ways that 
ptr may not be deleted if the function exits early. This can happen via an early return.
*/

