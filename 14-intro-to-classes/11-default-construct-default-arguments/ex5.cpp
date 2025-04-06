#include <iostream>

class User
{
private:
    int x; // note: no default initialization value
    int y {42};
    int z {};


public:
    User() {} // user-defined empty constructor

    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_z() const { return z; }
};

class Default
{
private:
    int x; // note: no default initialization value
    int y {42};
    int z {};

public:
    Default() = default; // explicitly defaulted default constructor

    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_z() const { return z; }
};

class Implicit
{
private:
    int x; // note: no default initialization value
    int y {42};
    int z {};

public:
    // implicit default constructor

    int get_x() const { return x; }
    int get_y() const { return y; }
    int get_z() const { return z; }
};

int main()
{
    User user{}; // default initialized
    std::cout << "User-defined default constructor\n";
    std::cout << user.get_x() << '\t' << user.get_y() << '\t' << user.get_z() << '\n';

    Default def{}; // zero initialized, then default initialized
    std::cout << "Explicit defaulted default constructor\n";
    std::cout << def.get_x() << '\t' << def.get_y() << '\t' << def.get_z() << '\n';

    Implicit imp{}; // zero initialized, then default initialized
    std::cout << "Implicit default constructor\n";
    std::cout << imp.get_x() << '\t' << imp.get_y() << '\t' << imp.get_z() << '\n';

    return 0;
}