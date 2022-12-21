/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:13:41 by codespace         #+#    #+#             */
/*   Updated: 2022/12/21 12:09:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include "./utils/utility.hpp"
#include <vector>
#include <cassert>

void vector_test(void)
{
    ft::vector<int> v;
    ft::vector<int> v2(2);
    std::vector<int> sv;
    ft::pair p;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    sv.push_back(1);
    sv.push_back(2);
    sv.push_back(3);

    assert(v.size() == sv.size());
	assert(v.capacity() == sv.capacity());

    // std::cout << "my vector size: " << v.size() << std::endl;
    // std::cout << "my vector capacity: " << v.capacity() << std::endl;
    // std::cout << "my vector2 size: " << v2.size() << std::endl;
    // std::cout << "my vector2 capacity: " << v2.capacity() << std::endl;
    // std::cout << "std vector size: " << sv.size() << std::endl;
    // std::cout << "std vector capacity: " << sv.capacity() << std::endl;

    // if (v.size() == sv.size())
    //     std::cout << "Vector sizes match." << std::endl;
    // else
    //     std::cout << "Vector sizes do not match." << std::endl;

    // if (v.capacity() == sv.capacity())
    //     std::cout << "Vector capacity match." << std::endl;
    // else
    //     std::cout << "Vector capacity do not match." << std::endl;
    
    // for (int i = 0; i < 3; i++)
    // {
    //     std::cout << "my vec[" << i << "] = " << v[i] << std::endl;
    //     std::cout << "std vec[" << i << "] = " << sv[i] << std::endl;
    //     if (v[i] == sv[i])
    //         std::cout << "Elements at index " << i << " match." << std::endl;
    //     else
    //         std::cout << "Elements at index " << i << " do not match." << std::endl;
    // }
    
    
}