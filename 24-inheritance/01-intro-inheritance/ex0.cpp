/* Inheritance */

/*
In the last chapter, we discussed object composition, where complex classes are constructed from 
simpler classes and types. Object composition is perfect for building new objects that have a 
"has-a" relationship with their parts. However, object composition is just one of the two major 
ways that C++ lets you construct complex classes. The second way is through inheritance, which 
models an "is-a" relationship between two objects.

Unlike object composition, which involves creating new objects by combining and connecting other 
objects, inheritance involves creating new objects by directly acquiring the attributes and 
behaviors of other objects and then extending or specializing them. Like object composition, 
inheritance is everywhere in real life. When you were conceived, you inherited your parents genes, 
and acquired physical attributes from both of them -- but then you added your own personality on 
top. Technological products (computers, cell phones, etc…) inherit features from their predecessors 
(often used for backwards compatibility). For example, the Intel Pentium processor inherited many 
of the features defined by the Intel 486 processor, which itself inherited features from earlier 
processors. C++ inherited many features from C, the language upon which it is based, and C 
inherited many of its features from the programming languages that came before it.

Consider apples and bananas. Although apples and bananas are different fruits, both have in common 
that they are fruits. And because apples and bananas are fruits, simple logic tells us that 
anything that is true of fruits is also true of apples and bananas. For example, all fruits have a 
name, a color, and a size. Therefore, apples and bananas also have a name, a color, and a size. We 
can say that apples and bananas inherit (acquire) all of the properties of fruit because they are 
fruit. We also know that fruit undergoes a ripening process, by which it becomes edible. Because 
apples and bananas are fruit, we also know that apples and bananas will inherit the behavior of 
ripening.


*/