/* Compile this example 
=======================
First thing first, to run this example, you need to compile three files. Assume that three files 
ex1.cpp, Point2D.h and Creature2D.h are in the same folder and your current working directory 
contains these three files. Then, you compile these files by using the command

g++ .\ex1.cpp .\Point2D.h .\Creature.h

The linker will connect them all.
*/

/* Problem description */

/* Many games and simulations have creatures or objects that move around a board, map, or screen. 
One thing that all of these creatures/objects have in common is that they all have a location. 
In this example, we are going to create a creature class that uses a point class to hold the 
creature's location.

First, let's design the point class. Our creature is going to live in a 2d world, so our point 
class will have 2 dimensions, X and Y. We will assume the world is made up of discrete squares, so 
these dimensions will always be integers. This class is implemented in the header file Point2D.h

Then, we design our Creature. Our Creature is going to have a few properties: a name, which will be 
a string, and a location, which will be our Point2D class. This class is implemented in the header
file Creature.h

Lastly, we write a main function to play the game. In this simple example, we create just one
creature and move it around using user inputs.
*/

#include <string>
#include <iostream>
#include "Creature.h"
#include "Point2D.h"

int main()
{
    std::cout << "Enter a name for your creature: ";
    std::string name;
    std::cin >> name;
    Creature creature{ name, { 4, 7 } };

    while (true)
    {
        // print the creature's name and location
        std::cout << creature << '\n';

        std::cout << "Enter new X location for creature (-1 to quit): ";
        int x{ 0 };
        std::cin >> x;
        if (x == -1)
            break;

        std::cout << "Enter new Y location for creature (-1 to quit): ";
        int y{ 0 };
        std::cin >> y;
        if (y == -1)
            break;

        creature.move_to(x, y);
    }

    return 0;
}