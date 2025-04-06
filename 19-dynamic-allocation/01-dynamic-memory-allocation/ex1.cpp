/* Dynamic memory allocation */

/* 
The need for dynamic memory allocation

C++ supports three basic types of memory allocation, of which you’ve already seen two.

    (1) Static memory allocation happens for static and global variables. Memory for these 
        types of variables is allocated once when your program is run and persists 
        throughout the life of your program.
    (2) Automatic memory allocation happens for function parameters and local variables. 
        Memory for these types of variables is allocated when the relevant block is entered, 
        and freed when the block is exited, as many times as necessary.
    (3) Dynamic memory allocation is the topic of this Chapter and all the cpp files you will 
        see

Both static and automatic allocation have two things in common:
    * The size of the variable / array must be known at compile time.
    * Memory allocation and deallocation happens automatically (when the variable 
      is instantiated / destroyed).

Most of the time, this is just fine. However, you will come across situations where one or 
both of these constraints cause problems, usually when dealing with external (user or 
file) input.

For example, we may want to use a string to hold someone’s name, but we do not know 
how long their name is until they enter it. Or we may want to read in a number of 
records from disk, but we don’t know in advance how many records there are. Or we 
may be creating a game, with a variable number of monsters (that changes over time 
as some monsters die and new ones are spawned) trying to kill the player.

If we have to declare the size of everything at compile time, the best we can do is 
try to make a guess the maximum size of variables we’ll need and hope that’s enough:

Code Example: 
    char name[25]; // let's hope their name is less than 25 chars!
    Record record[500]; // let's hope there are less than 500 records!
    Monster monster[40]; // 40 monsters maximum
    Polygon rendering[30000]; // this 3d rendering better not have more than 30,000 polygons!

This is a poor solution for at least four reasons:

(1) First, it leads to wasted memory if the variables aren’t actually used. For example, 
    if we allocate 25 chars for every name, but names on average are only 12 chars long, 
    we’re using over twice what we really need. Or consider the rendering array above: 
    if a rendering only uses 10,000 polygons, we have 20,000 Polygons worth of memory 
    not being used!
(2) Second, how do we tell which bits of memory are actually used? For strings, it’s 
    easy: a string that starts with a \0 is clearly not being used. But what about 
    monster[24]? Is it alive or dead right now? Has it even been initialized in the 
    first place? That necessitates having some way to tell the status of each monster, 
    which adds complexity and can use up additional memory.
(3) Third, most normal variables (including fixed arrays) are allocated in a portion 
    of memory called the stack. The amount of stack memory for a program is generally quite 
    small -- Visual Studio defaults the stack size to 1MB. If you exceed this number, 
    stack overflow will result, and the operating system will probably close down 
    the program. Being limited to just 1MB of memory would be problematic for many 
    programs, especially those that deal with graphics.
(4) Fourth, and most importantly, it can lead to artificial limitations and/or array 
    overflows. What happens when the user tries to read in 600 records from disk, 
    but we’ve only allocated memory for a maximum of 500 records? Either we have 
    to give the user an error, only read the 500 records, or (in the worst case where 
    we don’t handle this case at all) overflow the record array and watch something 
    bad happen.
*/

// Dynamically allocating single variables
#include <iostream>
int main()
{
    // int* ptr { new int };   // dynamically allocate an integer

    int* ptr;
    ptr = new int;
    *ptr = 42;               // put a value in that memory location
    std::cout << "ptr = " << ptr << '\n';
    std::cout << "*ptr = " << *ptr << '\n';
    // return the memory to the operating system. ptr is now a dangling pointer.
    delete ptr;

    // Dereferencing a dangling pointer will cause undefined behavior
    // std::cout << *ptr; 

    // trying to deallocate the memory again will also lead to undefined behavior.
    // delete ptr; 

    return 0;
}
/*
In the above program, the value of 42 that was previously assigned to the allocated 
memory will probably still be there, but it’s possible that the value at that memory 
address could have changed. It's also possible the memory could be allocated to 
another application (or for the operating system’s own usage), and trying to access 
that memory will cause the operating system to shut the program down.
*/