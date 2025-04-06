#include <iostream>
#include <string>

void print_ref(const int& y) // y is a const reference
{
    std::cout << y << '\n';
}

void foo(int a, int& b, const std::string& c)
{
    std::cout << "integer a (pass-by-val) = " << a << '\n';
    std::cout << "integer b (pass-by-ref) = " << b << '\n';
    std::cout << "string c (pass-by-const-ref) = " << c << '\n';
}

int main()
{
    int x { 5 };
    print_ref(x);   // ok: x is a modifiable lvalue, y binds to x

    const int z { 5 };
    print_ref(z);   // ok: z is a non-modifiable lvalue, y binds to z

    print_ref(5);   // ok: 5 is rvalue literal, y binds to temporary int object

    const std::string s {"Hello world!"};
    foo(5, x, s);

    return 0;
}