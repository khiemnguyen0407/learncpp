/* Polymorphism */

/*
In programming, polymorphism refers to the ability of an entity to have multiple forms (the term 
"polymorphism" literally means "many forms"). For example, consider the two function declarations:

int add(int, int)
double add(double, double)

The identifier "add" has two forms: add(int, int) and add(double, double)

Compile-time polymorphism:
==========================
Compile-time polymorphism refers to forms of polymorphism that are resolved by the compiler. These 
include function overload resolution, as well as template resolution.

Runtime polymorphism:
=====================
Runtime polymorphism refers to forms of polymorphism that are resolved at runtime. This includes 
virtual function resolution.

*/

// Let's take another look at the Animal example provided in the last Folder.

#include <iostream>
#include <string>
#include <string_view>

class Animal
{
protected:
    std::string name {};

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(std::string_view name)
        : name{ name }
    {
    }

public:
    const std::string& get_name() const { return name; }

    // Here's the equivalent class with the speak() function made virtual:
    virtual std::string_view speak() const { return "???"; }

    // To see the effect of "virtual", just delete "virtual" in the above function definition.
    // Uncomment the following function and comment out the above function.
    // std::string_view speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(std::string_view name)
        : Animal{ name }
    {
    }

    virtual std::string_view speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(std::string_view name)
        : Animal{ name }
    {
    }

    virtual std::string_view speak() const { return "Woof"; }
};

void report(const Animal& animal)
{
    std::cout << animal.get_name() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };

    report(cat);
    report(dog);


    // Similarly, the following array example now works as expected
    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };

    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };

    Animal* animals[] {&fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (const auto* animal : animals) {
        std::cout << animal->get_name() << "speaks " << animal->speak() << '\n';
    }

    return 0;
}

/* Discussion

When animal.speak() is evaluated, the program notes that Animal::speak() is a virtual function. In 
the case where animal is referencing the Animal portion of a Cat object, the program looks at all 
the classes between Animal and Cat to see if it can find a more derived function. In that case, it 
finds Cat::speak(). In the case where animal references the Animal portion of a Dog object, the 
program resolves the function call to Dog::speak().

Note that we did not make Animal::get_name() virtual. This is because get_name() is never 
overridden in any of the derived classes, therefore there is no need.

Even though these two examples only use Cat and Dog, any other classes we derive from Animal would 
also work with our report() function and animal array without further modification! This is perhaps 
the biggest benefit of virtual functions -- the ability to structure your code in such a way that 
newly derived classes will automatically work with the old code without modification!

A word of warning: the signature of the derived class function must exactly match the signature of 
the base class virtual function in order for the derived class function to be used. If the derived 
class function has different parameter types, the program will likely still compile fine, but the 
virtual function will not resolve as intended. In the next lesson, we'll discuss how to guard 
against this.

Note that if a function is marked as virtual, all matching overrides in derived classes are also 
implicitly considered virtual, even if they are not explicitly marked as such.
*/

/* 
Rule to remember
================

If a function is virtual, all matching overrides in derived classes are implicitly virtual. This 
does not work the other way around -- a virtual override in a derived class does not implicitly 
make the base class function virtual.

*/