#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <string_view>
#include "Point2D.h"

class Creature
{
private:
    std::string name;
    Point2D location;

public:
    Creature(std::string_view name, const Point2D& location)
        : name{ name }, location{ location }
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Creature& creature)
    {
        out << creature.name << " is at " << creature.location;
        return out;
    }

    void move_to(int x, int y)
    {
        location.set_point(x, y);
    }
};
#endif