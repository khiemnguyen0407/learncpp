/* Object composition */
/*
In real-life, complex objects are often built from smaller, simpler objects. For example, a car is 
built using a metal frame, an engine, some tires, a transmission, a steering wheel, and a large 
number of other parts. A personal computer is built from a CPU, a motherboard, some memory, etc...
Even you are built from smaller parts: you have a head, a body, some legs, arms, and so on. This 
process of building complex objects from simpler ones is called object composition.

Broadly speaking, object composition models a “has-a” relationship between two objects. A car 
"has-a" transmission. Your computer "has-a" CPU. You "have-a" heart. The complex object is 
sometimes called the whole, or the parent. The simpler object is often called the part, child, or 
component.

In C++, you've already seen that structs and classes can have data members of various types (such 
as fundamental types or other classes). When we build classes with data members, we’re essentially 
constructing a complex object from simpler parts, which is object composition. For this reason, 
structs and classes are sometimes referred to as composite types.

Object Composition is useful in a C++ context because it allows us to create complex classes by 
combining simpler, more easily manageable parts. This reduces complexity, and allows us to write 
code faster and with less errors because we can reuse code that has already been written, tested, 
and verified as working.
*/

/* Types of object composition 

There are two basic subtypes of object composition: composition and aggregation. We'll examine 
composition in section, and aggregation in the next. */

/* Composition 

To qualify as a composition, an object and a part must have the following relationship:
    * The part (member) is part of the object (class)
    * The part (member) can only belong to one object (class) at a time
    * The part (member) has its existence managed by the object (class)
    * The part (member) does not know about the existence of the object (class)

A good real-life example of a composition is the relationship between a person’s body and a heart. 
Let's examine these in more detail.

Composition relationships are part-whole relationships where the part must constitute part of the 
whole object. For example, a heart is a part of a person’s body. The part in a composition can only 
be part of one object at a time. A heart that is part of one person’s body can not be part of 
someone else’s body at the same time.

In a composition relationship, the object is responsible for the existence of the parts. Most 
often, this means the part is created when the object is created, and destroyed when the object is 
destroyed. But more broadly, it means the object manages the part’s lifetime in such a way that the 
user of the object does not need to get involved. For example, when a body is created, the heart is 
created too. When a person’s body is destroyed, their heart is destroyed too. Because of this, 
composition is sometimes called a "death relationship".

And finally, the part doesn’t know about the existence of the whole. Your heart operates blissfully 
unaware that it is part of a larger structure. We call this a unidirectional relationship, because 
the body knows about the heart, but not the other way around.

Note that composition has nothing to say about the transferability of parts. A heart can be 
transplanted from one body to another. However, even after being transplanted, it still meets the 
requirements for a composition (the heart is now owned by the recipient, and can only be part of 
the recipient object unless transferred again).
*/

/* Implementing compositions 

Compositions are one of the easiest relationship types to implement in C++. They are typically 
created as structs or classes with normal data members. Because these data members exist directly 
as part of the struct/class, their lifetimes are bound to that of the class instance itself.

Compositions that need to do dynamic allocation or deallocation may be implemented using pointer 
data members. In this case, the composition class should be responsible for doing all necessary 
memory management itself (not the user of the class).

In general, if you can design a class using composition, you should design a class using 
composition. Classes designed using composition are straightforward, flexible, and robust (in that 
they clean up after themselves nicely).

To understand better the explanation in this ex0.cpp file, you can move to the example described in
ex1.cpp. However, since the example demonstrate the "has-a" relationship, the example needs at 
least two classes, one of which "has" the other as its member. In order to compile the first 
example in ex1.cpp, you must use

g++ .\ex1.cpp .\Creature.h .\Point2D.h
*/

