# Resources
Effective C++ 55 Specific Ways to Improve Your Programs and Designs  (Third Edition), Scott Meyers

# Build commands
Modify CMakeLists.txt first!
```
cd build
cmake ../
MinGW32-make
```

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
Have assignment operators return a reference to *this.
### Item 11 
Handle assignment to self in operator=.
* operator= is well-behaved when an object is assigned to itself
* any function operating on more than one object behaves correctly if two or more of the objects are the same
### Item 12
Copy all parts of an object.
* copying functions should be sure to copy all of an object’s data members and all of its base class parts
* don’t try to implement one of the copying functions in terms of the other. Instead, put common functionality in a third function that both call

# Lucrarea 6
### Item 13
Use objects to manage resources/
* `auto_ptr` automatically deletes what it points to when the auto_ptr is destroyed
* `auto_ptr` has an unusual characteristic: copying them (via copy constructor or copy assignment operator) sets them to null, and the copying pointer assumes sole ownership of the resource
* `shared_ptr` is usually the better choice than `auto_ptr`, because its behavior when copied is intuitive
### Item 14
Think carefully about copying behavior in resource-managing classes.
* Copying an RAII object entails copying the resource it manages, so the copying behavior of the resource determines the copying behavior of the RAII object.
* Common RAII class copying behaviors are disallowing copying and performing reference counting, but other behaviors are possible.
