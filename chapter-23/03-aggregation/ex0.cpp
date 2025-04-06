/* Aggregation */

/* we noted that object composition is the process of creating complex objects from simpler ones.
We also talked about one type of object composition, called composition. In a composition
relationship, the whole object is responsible for the existence of the part.

In this cpp file, we'll take a look at the other subtype of object composition, called aggregation.

To qualify as an aggregation, a whole object and its parts must have the following relationship:
    * The part (member) is part of the object (class)
    * The part (member) can (if desired) belong to more than one object (class) at a time
    * The part (member) does not have its existence managed by the object (class)
    * The part (member) does not know about the existence of the object (class)

Like a composition, an aggregation is still a part-whole relationship, where the parts are
contained within the whole, and it is a unidirectional relationship. However, unlike a composition,
parts can belong to more than one object at a time, and the whole object is not responsible for the
existence and lifespan of the parts. When an aggregation is created, the aggregation is not
responsible for creating the parts. When an aggregation is destroyed, the aggregation is not
responsible for destroying the parts.

For example, consider the relationship between a person and their home address. In this example,
for simplicity, we’ll say every person has an address. However, that address can belong to more
than one person at a time: for example, to both you and your roommate or significant other.
However, that address isn’t managed by the person -- the address probably existed before the person
got there, and will exist after the person is gone. Additionally, a person knows what address they
live at, but the addresses don’t know what people live there. Therefore, this is an aggregate
relationship.
*/

/* Implementing aggregations */
/*
Because aggregations are similar to compositions in that they are both part-whole relationships,
they are implemented almost identically, and the difference between them is mostly semantic. In a
composition, we typically add our parts to the composition using normal member variables (or
pointers where the allocation and deallocation process is handled by the composition class).

In an aggregation, we also add parts as member variables. However, these member variables are
typically either references or pointers that are used to point at objects that have been created
outside the scope of the class. Consequently, an aggregation usually either takes the objects it is
going to point to as constructor parameters, or it begins empty and the subobjects are added later
via access functions or operators.

Because these parts exist outside of the scope of the class, when the class is destroyed, the pointer or reference member variable will be destroyed (but not deleted). Consequently, the parts themselves will still exist.
*/