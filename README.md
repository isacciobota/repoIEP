# Resources
Effective C++ 55 Specific Ways to Improve Your Programs and Designs  (Third Edition), Scott Meyers

# Lucrarea 4
### Item 4
Make sure that objects are initialized before they’re used.
### Item 5 
Know what functions C++ silently writes and calls.
* default constructor
* copy constructor
* destructor
* copy assignment operator
### Item 6
Explicitly disallow the use of compiler generated functions you do not want.
* copy constructor and copy assignment constructor can't be called
* class Uncopyable

# Lucrarea 5
### Item 10
Assignment operators return a reference to *this
### Item 11 
* operator= is well-behaved when an object is assigned to itself
* any function operating on more than one object behaves correctly if two or more of the objects are the same
### Item 12
* copying functions should be sure to copy all of an object’s data members and all of its base class parts
* don’t try to implement one of the copying functions in terms of the other. Instead, put common functionality in a third function that both call