/* Forward declaration */









#include <iostream>

double add(double x, double y); // forward declaration of add() (using a function declaration)

int main()
{
    double a { 1.5 };
    double b { 5.1} ;
    std::cout << "a + b = " << add(a, b) << '\n';
    return 0;
}

// Actual definition of add which was declared before it was used in int main()
double add(double x, double y)
{
    return x + y;
}