/* Summary of inheritance and access specifiers */

/*
The way that the access specifiers, inheritance types, and derived classes interact causes a lot of 
confusion. To try and clarify things as much as possible:

* First, a class (and friends) can always access its own non-inherited members. The access 
  specifiers only affect whether outsiders and derived classes can access those members.
* Second, when derived classes inherit members, those members may change access specifiers in the 
  derived class. This does not affect the derived classes’ own (non-inherited) members (which have 
  their own access specifiers). It only affects whether outsiders and classes derived from the 
  derived class can access those inherited members.

Here's a table of all of the access specifier and inheritance types combinations:

Access specifier |  Access specifier when   |   Access specifier when   |   Access specifier when
in base class    |  inherited publicly      |   inherited privately     |   inherited protectedly
=================================================================================================
Public           |  Public                  |   Private                 |   Protected
Protected        |  Protected               |   Private                 |   Protected
Private          |  Inaccessible            |   Inaccessible            |   Inaccessible    

As a final note, although in the examples above, we've only shown examples using member variables
in the cpp files, these access rules hold true for all members (e.g. member functions and types 
declared inside the class).
*/