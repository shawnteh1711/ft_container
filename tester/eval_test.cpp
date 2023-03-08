/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:10:36 by steh              #+#    #+#             */
/*   Updated: 2023/03/08 21:25:24 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.hpp"
#include "../header/utils/test.hpp"

void    eval_test(void)
{
    ft::print_headers("iterator and const iterator comparison");

    ft::vector<int>                 v;
    ft::vector<int>                 v2;
    ft::vector<int>::iterator       it;
    ft::vector<int>::iterator       it2;
    ft::vector<int>::const_iterator cit;;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    it = v.begin();
    cit = v.begin();

    if (it == cit)
        std::cout << "iterator and const_iterator are equal" << std::endl;
    else
        std::cout << "iterator and const_iterator are not equal" << std::endl;

    cit = v.begin() + 1;

    if (it == cit)
        std::cout << "iterator and const_iterator are equal" << std::endl;
    else
        std::cout << "iterator and const_iterator are not equal" << std::endl;

    
    // iterator can modify elements
    *it = 42;

    for (; it != v.end(); it++)
    {
       std::cout << *it << std::endl;
    }

    // const_iterator cannot modify elements
    
    // try
    // {
    //     *cit = 10
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }


    // dynamic reallocation of memory
    ft::print_headers("dynamic reallocation memory");
    ft::vector<int> vec;

    // Output the initial capacity of the vector
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    // Add a large number of elements to the vector
    for (int i = 0; i < 100000; i++) {
        vec.push_back(i);
    }

    // Output the final capacity of the vector
    std::cout << "Final capacity: " << vec.capacity() << std::endl;

    // swap
    ft::print_headers("Swap");

    it = v.begin();

    it2 = v2.begin();

    int* ptr1 = &v[1];
    int* ptr2 = &v2[2];
    int& ref1 = v[0];
    int& ref2 = v2[1];

     // Output the initial state of the iterators, pointers, and references
    std::cout << "Before swap():\n";
    std::cout << "*it1 = " << *it << ", *it2 = " << *it2 << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << std::endl;
    std::cout << "ref1 = " << ref1 << ", ref2 = " << ref2 << std::endl;

    // Swap the vectors
    v.swap(v2);

    // Output the final state of the iterators, pointers, and references
    std::cout << "After swap():\n";
    std::cout << "*it1 = " << *it << ", *it2 = " << *it2 << std::endl;
    std::cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << std::endl;
    std::cout << "ref1 = " << ref1 << ", ref2 = " << ref2 << std::endl;

    std::cout << "Elements of v after swap: ";
    for (it = v.begin(); it != v.end(); it++)
    {
       std::cout << *it << ",";
    }
    std::cout << std::endl;

    std::cout << "Elements of v2 after swap: ";
    for (it2 = v2.begin(); it2 != v2.end(); it2++)
    {
       std::cout << *it2 << ",";
    }

    ft::print_headers("Deep copy");

    // In C++98. the only way to check deep copied it to compare memory
    // address of original and copied objects. If address are different means
    // that a deep copy was made, since the copued object has its own memory space

    bool                isDeepCopy;
    ft::vector<int>     v3;

    v3 = v;
    isDeepCopy = true;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (&v3[i] == &v[i])
        {
            isDeepCopy = false;
            break;
        }
    }

    if (isDeepCopy)
        std::cout << "Deep Copy" << std::endl;
    else
        std::cout << "Not Deep Copy" << std::endl;
        
    
    ft::print_headers("Map valid iterator after delete and insert");

    ft::map<int, int>           map;
    ft::map<int, int>::iterator mit;

    map.insert(ft::make_pair(1, 10));
    map.insert(ft::make_pair(2, 20));
    map.insert(ft::make_pair(3, 30));

    // Create an iterator pointing to the second element
    mit = map.begin();
    std::advance(mit, 1);

    // Erase the second element
    mit = map.erase(mit);

    // Check that the iterator is still valid and pointing to the third element
    if (mit != map.end() && mit->first == 3 && mit->second == 30) {
        std::cout << "Iterator is still valid after erase()\n";
    } else {
        std::cout << "Iterator is invalid after erase()\n";
    }

    // Insert a new element
    map.insert(ft::make_pair(4, 40));

    // Check that the iterator is still valid and pointing to the third element
    if (mit != map.end() && mit->first == 3 && mit->second == 30) {
        std::cout << "Iterator is still valid after insert()\n";
    } else {
        std::cout << "Iterator is invalid after insert()\n";
    }
    
}
