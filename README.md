## Item 4
Make sure that objects are initialized before they’re used.

## Item 5 
Know what functions C++ silently writes and calls.
    - default constructor
    - copy constructor
    - destructor
    - copy assignment operator
## Item 6
Explicitly disallow the use of compiler generated functions you do not want
* copy constructor and copy assignment constructor can't be called
* class Uncopyable
## Item 10
Aassignment operators return a reference to *this
## Item 11 
* operator= is well-behaved when an object is assigned to itself
* any function operating on more than one object behaves correctly if two or more of the objects are the same.
## Item 12
