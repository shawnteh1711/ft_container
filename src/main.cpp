/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:13:41 by codespace         #+#    #+#             */
/*   Updated: 2022/12/21 05:09:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

int main(void)
{
    ft::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::cout << "Vector size: " << v.size() << std::endl;
    std::cout << "Vector capacity: " << v.capacity() << std::endl;
    
}