/* Use for pointers and references to base classes */

/* 
Now you might be saying, "The above examples seem kind of silly. Why would I set a pointer or 
reference to the base class of a derived object when I can just use the derived object?" It turns 
out that there are quite a few good reasons.

First, let's say you wanted to write a function that printed an animal's name and sound. Without 
using a pointer to a base class, you would have to write it using overloaded functions, like this:

void report(const Cat& cat)
{
    std::cout << cat.get_name() << " says " << cat.speak() << '\n';
}
void report(const Dog& dog)
{
    std::cout << dog.get_name() << " says " << dog.speak() << '\n';
}

Not too difficult, but consider what would happen if we had 30 different animal types instead of 2. 
You would have to write 30 almost identical functions! Plus, if you ever added a new type of animal,
you would have to write a new function for that one too. This is a huge waste of time considering 
the only real difference is the type of the parameter.

However, because Cat and Dog are derived from Animal, Cat and Dog have an Animal part. Therefore, 
it makes sense that we should be able to do something like this:

void report(const Animal& animal_ref)
{
    std::cout << animal_ref.get_name() << " says " << animal_ref.speak() << '\n';
}
This would let us pass in any class derived from Animal, even ones that we created after we wrote 
the function! Instead of one function per derived class, we get one function that works with all 
classes derived from Animal! 

The problem is, of course, that because animal_ref is an Animal reference, animal_ref.speak() will 
call Animal::speak() instead of the derived version of speak().
*/

#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Animal
{
protected:
    std::string name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name) : name{ name }
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;

public:
    std::string_view get_name() const { return name; }
    std::string_view speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    std::string_view speak() const { return "Woof"; }
};

// void report(const Cat& cat)
// {
//     std::cout << cat.get_name() << " says " << cat.speak() << '\n';
// }
// void report(const Dog& dog)
// {
//     std::cout << dog.get_name() << " says " << dog.speak() << '\n';
// }
/* 
This is what we wish to have and it can deal with all kinds of animal we have defined and may
define in the future.
======================================
void report(const Animal& animal)
{
    std::cout << animal.get_name() << " says " << animal.speak() << '\n';
}
*/
void report(const Animal& animal)
{
    std::cout << animal.get_name() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat {"Fred"};
    Dog dog {"Boo"};
    // report_yourself(cat);
    // report_yourself(dog);

    report(cat);
    report(dog);

}