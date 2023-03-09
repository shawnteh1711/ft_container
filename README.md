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


## Container
In c++, a contianer is a data structure that is designed to hold and organize a collections of objects or values. It provides a way to store and access data efficiently and conveniently, and comes with a set of methods for manipulating the data it contains.


C++ provides several container types in its standard library including arrays, vectors, lists, maps, multimap (permit multiple entries with same key), sets, multisets(multiple keys with equivalent values are allowed.

Containers in C++ categorized into 2 main groups: sequence containers and associative containers.

Sequence containers: store elements in linear order, and the elements can be accessed using their position in the sequence. Examples: arrays, vector, lists, deques.

Associative containers: store elements in a way that allows for efficient searching and retrival based on some key value. Examples: maps, sets.

Using containers in C++ can help ,ake your code more organized, efficient and easier to maintain.hw
## Vector Dynamic array
Dynamic array is a type of data structure tha allow for the efficient allocation and deallocation of memory as needed. Unlike static arrays, which have fixed size that must be specified at the time of creation, dynamic arrays can grow or shrink in size during runtime. Similarlym if elements are removed from the array, and the remaining elements use less memory than the allocated memory, the dynamic array can free up the extra memory. Dynamic arrays are often used when the size of the data stored is not known ahead of time, or when the size of data may change over time.

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
In this example, the add function template is only enabled if the type T is integral.

## Simple red-black tree
A red-black tree is a binary search tree that is used to store data in a way that allows for efficient searching, insertion and deleteion operations.

5 rules
1. Every node is either red or black.
2. The root node is always black.
3. If a node is red, then both its children are black.
4. Every leak node (TNULL) is black.
5. Every path from a node to descendant leaf node contains the same number of black nodes.

These rules ensure that tree remains balanced.

## High level inserting a new node into a red-black tree
1. Color new node Red
2. Rebalance the tree as needed
    a. If the new node parent is BLACK, then tree is still valid and no further action.
    b. If the new node parent is RED, then you need to perform one or more of the following rotation and recolorings to restore rbtree properties.
    ```
    while (current_node->parent->color == red)
    {
        ....
    }
    ```
    Case i. new_node's parent and uncle are both RED.
    ```
    - Color the parent and uncle BLACK and the grandparent RED.
    - Move up tree to reconsider grandparent node

    if (uncle_node->color == red)
    {
        uncle_node->color = black;
        current_node->parent->color = black;
        current_node->parent->parent->color = red;
        current_node = current_node->parent->parent;
    }
    ```

    Case ii. new node's parent = RED, uncle = BLACK or NULL, new node = right child of its parent , parent = left child of grandparent.
    ```
    - Perform LEFT ROTATION on the parent node
    - This converts the situation to case iii

    if (current_node == current_node->parent->right)
    {
        current_node = current_node->parent;
        left_rotate(current_node);
    }
    ```

    Case iii. new node's parent = RED, uncle = BLACK or null, new node = left child of its parent,
    parent = left child of grandparent.
    ```
    - Color the parent BLACK and grandparent RED
    - Perform a RIGHT ROTATION on the grandparent node.

    current_node->parent->color = black;
    current_node->parent->parent->color = red;
    right_rotate(current_node->parent->parent);

    ```

    Case iv. new node's parent = RED, uncle = BLACK or null, new node = left child of its parent,
    parent = right child of grandparent.
    ```
    - Perform a RIGHT ROTATION on the parent node
    - This converts the situation to case v
    if (current_node == current_node->parent->left)
    {
        current_node = current_node->parent;
        right_rotate(current_node);
    }
    ```

    Case v. new node's parent = RED, uncle = BLACK or null, new node = right child of its parent,
    parent = right child of grandparent.
    ```
    - Color the parent BLACK and grandparent RED
    - Perform a LEFT ROTATION on the grandparent node.
    current_node->parent->color = black;
    current_node->parent->parent->color = red;
    left_rotate(current_node->parent->parent);
    ```


## Simple left rotate
Left rotation moves the right child of a node up one level and makes it the parent of current node. Current node becomes the left child of the new root. If the right child has a left child, that child becomes the right child of the current node. If the current node has a parent, the new root becomes the appropriate child of the parent.

```
// In a left rotation, the right child of the current node becomes the new root,
Node *right_child_of_current_node;
right_child_of_current_node = current_node->right;

// and the current node becomes the left child of the new root.
current_node->right = right_child_of_current_node->left;

// If the right child has a left child, that child becomes the right child of the current node.
if (right_child_of_current_node->left != _TNULL)
right_child_of_current_node->left->parent = current_node;

// right_child_of_current_node becomes the parent of current_node.
right_child_of_current_node->parent = current_node->parent;

// If the current node has a parent, the new root becomes the appropriate child of the parent.
if (current_node->parent == nullptr)
    this->_root = right_child_of_current_node;
else if (current_node == current_node->parent->left)
    current_node->parent->left = right_child_of_current_node;
else
    current_node->parent->right = right_child_of_current_node;

// The current_node becomes the left child of the right_child_of_current_node.
right_child_of_current_node->left = current_node;

// current_node's parent becomes right_child_of_current_node.
current_node->parent = right_child_of_current_node;
```


### Simple right rotation
In a right rotation, the left child of the current node becomes the new root, and the current node becomes the right child of the new root. If the left child has a right child, that child becomes the left child of the current node. If the current node has a parent, the new root becomes the appropriate child of the parent.

### Deletion in RBTRree
1. Transplant - helps us move subree within the tree.
- Properperly unlink the node to be deleted from its parent and link parent with replacement node

```
template <class T, class KeyofValue, class Compare, class Alloc>
void ft::RBTree<T, KeyofValue, Compare, Alloc>::rb_transplant(Node *node_to_replace, Node *replacement_node)
{
	if (node_to_replace->parent == nullptr)
		_root = replacement_node;
	else if (node_to_replace == node_to_replace->parent->left)
		node_to_replace->parent->left = replacement_node;
	else
		node_to_replace->parent->right = replacement_node;
	replacement_node->parent = node_to_replace->parent;
}
```

2. delete - delete the node
```
Locate the node to be deleted: Start at the root node and traverse the tree until the node to be deleted is found. Once the node is found, we must check whether it has zero, one or two children
3 Cases to handle
Case 1: node to delete has only one right child, replace it with its child
Case 2: node to delete has only one left child, replace it with its child
Case 3: the node has two children, replace it with its successor
        - Find the successor using minimum node in right subtree and save its color.
        - If the parent of the successor node is the node to be deleted, the child_of_deleted_node's parent is updated to point to the successor node.
        - otherwise, the successor node is unlinked from its current position in the tree and is transplanted to the position of the node to be deleted using rb_transplant function.
        - The successot of deleted node then linked to the node to be deleted's left child and is given the same color as the node to be deleted.
```



3. delete_fixup - fixes any violation
```
Delete the node while maintaining the properties of the RBTree: The process of deleting a node can be broken down into different cases based on whether the node has zero, one or two children. In each case, we must maintain the properties of the RBTree such as the color of the nodes and their relationships with their parent and children.
4 cases to fix 
case 1: sibling is red
case 2: sibling is black and both children are black
case 3: sibling is black, left childred is red,  right children is black
case 4: sibling is black and right children is red
```


## Reference
1. [Red Black Tree Transverse](https://www.youtube.com/watch?v=WLvU5EQVZqY)
2. [Red Black Tree Visualizer](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html)
