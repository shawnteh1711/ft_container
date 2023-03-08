# ft_container
There are multiple containers in c++ and have different usage. We need to understand it (vector, map, stack) and re-implement it.

## Documentation: 
* Where is the Requirement Specification?
* Where is the Impact Analysis Document?
* Where is the Design Document?
* Have you documented all the assumptions and limitations
* Have you done review of all documents

## Few important document for future
* Design Approaches
* Tips and Tricks
* Special functions, commands and instructions
* Lesson learnt
* Peculiar situations
* Debugging methods
* Best Practices
* Anything which can help you in future


## Vector Dynamic array
Dynamic array is a type of data structure tha allow for the efficient allocation and deallocation of memory as needed. Unlike static arrays, which have fixed size that must be specified at the time of creation, dynamic arrays can grow or shrink in size during runtime. Similarlym if elements are removed from the array, and the remaining elements use less memory than the allocated memory, the dynamic array can free up the extra memory. Dynamic arrays are often used when the size of the data stored is not known ahead of time, or when the size of data may change over stime.

## What is an Iterator 
An iterator ia a programming concept that provides a way to acces the elements of a collection or container. An iterator can be thought of as a generalized pointer to an element of a collection, with additional functionaality for transveersing the collection. 

## Iterator comparison to Pointer
A pointer is a variable that stores the memory address of another variable or object. Pointers are a low-level programming construct and are used for memory manipulation, data structures, and low-level optimizations.

Some differences between iterators and pointers:
1. Type safety: iterators are safer than pointers because they are design to work with specific data structures and have built-in safety checks to ensure that they do not fo out of bounds. Pointers, on the other hand, are more low-level and do not have these safety checks, which can lead to errors and security vulnerabilities.

2. Abstraction: Iterator provide a higher level of abstration than pointers. They are designed to work with specific data structures and provide a consistent interface for accessing and transversing them. Pointer on the other hand are more general and can be used to manipulate any area of memory.

3. Functionality: Iterator provide function beyond pointer offer. For example, iterators may provide methods for  moving to next and previous elements which pointers so not. Iterators can alos be used to transver data structures that are not contigious in memory such as linked lists or trees while pointers are primariy designed for contigious memory access.

# Simple is_integral
is_integral is a type_trait that checks whether a given type is an integral type
```
template<typename T>
struct is_integral
{
    static const bool value = false;
};

template<>
struct is_integral<int>
{
    static const bool value = true;
};

template<>
struct is_integral<long>
{
    static const bool value = true;
};

template<>
struct is_integral<long long>
{
    static const bool value = true;
};

// Add more specializations for other integral types, if needed

// Usage example:
if (is_integral<int>::value) {
    // do something if int is an integral type
} else {
    // do something else if int is not an integral type
}

```

## enable_id

enable_if is a type_trait used in template metaprogramming to conditionally enable a funciton template or a class template based on a compile-time Boolean expression.
This is an example implementation of enable_if in C++
```
template<bool B, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true, T>
{
    typedef T type;
}
```

In this implementation, enable_if is a struct template that takes 2 template parameters. The first parameter is a boolean value(B), which is used to conditionally enable the type. The second parameter (T) is an optional type to be retured by struct template. The  general form of enable_if doesn't provide a type definition, so if the boolean value is False. the struct has no type member. However, if B is true, the struct specialization provides a type that is an allias for thse second template parameter T.

Example of usage of enable_if to conditionally enable a function template:

```
template <typename T>
typename std::enable_id<std::is_integral<T>::value, T>::type
add(T a, T b)
{
    return (a+b);
}
```

In this example, the add function template is only enabled if the type T is integral/

## Reference
1. [Red Black Tree Transverse](https://www.youtube.com/watch?v=WLvU5EQVZqY)
2. [Red Black Tree Visualizer](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
