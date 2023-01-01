/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:17:23 by steh              #+#    #+#             */
/*   Updated: 2022/12/31 20:17:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils/algorithm.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

void	algorithms_test()
{

	{
		std::cout << std::endl << "standard" << std::endl;
		std::string str1 = "abc";
		std::string str2 = "abc";
		std::string str3 = "def";

		if (std::equal(str1.begin(), str1.end(), str2.begin())) {
			std::cout << "str1 and str2 are equal" << std::endl;
		}

		if (std::equal(str1.begin(), str1.end(), str3.begin())) {
			std::cout << "str1 and str3 are equal" << std::endl;
		}
		else
			std::cout << "str1 and str3 not equal" << std::endl;

		std::cout << std::endl << "own" << std::endl;
		if (ft::equal(str1.begin(), str1.end(), str2.begin())) {
			std::cout << "str1 and str2 are equal" << std::endl;
		}

		if (ft::equal(str1.begin(), str1.end(), str3.begin())) {
			std::cout << "str1 and str3 are equal" << std::endl;
		}
		else
			std::cout << "str1 and str3 not equal" << std::endl;
	}
	{
		std::string str1 = "abc";
		std::string str2 = "def";

		std::cout << std::endl << "standard" << std::endl;

		if (std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end())) {
			std::cout << str1 << " comes before " << str2 << " lexicographically" << std::endl;
		}
		else
		{
			std::cout << str1 << " comes after " << str2 << " lexicographically" << std::endl;
		}
		
		std::cout << std::endl << "own" << std::endl;
		
		if (ft::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
		{
			std::cout << str1 << " comes before " << str2 << " lexicographically" << std::endl;
		} 
		else
		{
			std::cout << str1 << " comes after " << str2 << " lexicographically" << std::endl;
		}
	}
	{	
		std::cout << std::endl << "standard" << std::endl;
		std::vector<char> v1;
		v1.push_back('a');
		v1.push_back('b');
		v1.push_back('c');
		v1.push_back('d');
		std::vector<char> v2;
		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');
		v2.push_back('d');

		// Seed the random number generator with the current time
		std::srand(std::time(nullptr));

		while (!std::lexicographical_compare(v1.begin(), v1.end(),
										v2.begin(), v2.end()))
		{
			for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
			std::cout << *it << ' ';
			std::cout << ">= ";
			for (std::vector<char>::iterator it = v2.begin(); it != v2.end(); ++it)
			std::cout << *it << ' ';
			std::cout << '\n';

			// Shuffle the elements of v1 and v2
			for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
			{
				// Generate a random index in the range [it, v1.end())
				std::vector<char>::iterator jt = it + std::rand() % (v1.end() - it);

				// Swap the elements at it and jt
				std::swap(*it, *jt);
			}
			for (std::vector<char>::iterator it = v2.begin(); it != v2.end(); ++it)
			{
				// Generate a random index in the range [it, v2.end())
				std::vector<char>::iterator jt = it + std::rand() % (v2.end() - it);

				// Swap the elements at it and jt
				std::swap(*it, *jt);
			}
		}

		for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << ' ';
		std::cout << "<  ";

		for (std::vector<char>::iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << ' ';
		std::cout << '\n';
	}
	{	
		std::cout << std::endl << "own" << std::endl;
		std::vector<char> v1;
		v1.push_back('a');
		v1.push_back('b');
		v1.push_back('c');
		v1.push_back('d');
		std::vector<char> v2;
		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');
		v2.push_back('d');

		// Seed the random number generator with the current time
		std::srand(std::time(nullptr));

		while (!ft::lexicographical_compare(v1.begin(), v1.end(),
										v2.begin(), v2.end()))
		{
			for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
			std::cout << *it << ' ';
			std::cout << ">= ";
			for (std::vector<char>::iterator it = v2.begin(); it != v2.end(); ++it)
			std::cout << *it << ' ';
			std::cout << '\n';

			// Shuffle the elements of v1 and v2
			for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
			{
				// Generate a random index in the range [it, v1.end())
				std::vector<char>::iterator jt = it + std::rand() % (v1.end() - it);

				// Swap the elements at it and jt
				std::swap(*it, *jt);
			}
			for (std::vector<char>::iterator it = v2.begin(); it != v2.end(); ++it)
			{
				// Generate a random index in the range [it, v2.end())
				std::vector<char>::iterator jt = it + std::rand() % (v2.end() - it);

				// Swap the elements at it and jt
				std::swap(*it, *jt);
			}
		}

		for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
		std::cout << *it << ' ';
		std::cout << "<  ";

		for (std::vector<char>::iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << ' ';
		std::cout << '\n';
	}
}
