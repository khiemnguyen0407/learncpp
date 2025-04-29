#include <iostream>
#include <memory>
void print_inc(std::shared_ptr<int> s)
{
    std::cout << ++*s << std::endl;
}
int main() 
{
    print_inc(std::shared_ptr<int>(new int {0}));
    std::shared_ptr<int> sip(new int {0});
    for (int i {0} ; i < 10 ; i++)
        print_inc(sip);
}