/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:13:41 by codespace         #+#    #+#             */
/*   Updated: 2023/01/03 21:40:04 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../header/vector.hpp"
#include "../header/utils/utility.hpp"
#include <vector>
#include <cassert>
#include "tester.hpp"

void vector_test(void)
{
	{
		std::cout << std::endl <<  "Default constructor" << std::endl;
		ft::vector<int> v;
		std::vector<int> sv;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Constructer with the given allocator alloc" << std::endl;
		ft::vector<int> v((std::allocator<int>()));
		std::vector<int> sv;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Count value constructor" << std::endl;

		ft::vector<int> v(2, 100);
		std::vector<int> sv(2, 100);

		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Range constructor" << std::endl;

		ft::vector<int>::iterator it;
		ft::vector<int> v (4,100);
		ft::vector<int> v2 (v.begin(), v.end());
		// for (it = v2.begin(); it != v2.end(); ++it)
		// {
		// 	std::cout << "it: " << *it << std::endl;
		// }
		std::vector<int> sv (4,100); 
		std::vector<int> sv2 (sv.begin(),sv.end());
		ft::test_assert(v2.size(), sv2.size(), "Size incorrect", "Passed");
		ft::test_assert(v2.capacity(), sv2.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v2.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");
	}
	
	{
		std::cout << std::endl <<  "Copy constructor" << std::endl;

		ft::vector<int> v (4, 200);
		ft::vector<int> v2 (v);
		std::vector<int> sv (4, 200);
		std::vector<int> sv2 (sv);
		ft::test_assert(v2.size(), sv2.size(), "Size incorrect", "Passed");
		ft::test_assert(v2.capacity(), sv2.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v2.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Assign function" << std::endl;

		ft::vector<int> v;
		std::vector<int> sv;

		v.assign(5, 1);
		sv.assign(5, 1);
		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");

		std::cout << std::endl <<  "Range assign function" << std::endl;
		const std::vector<int> extra(6, 2);
		v.assign(extra.begin(), extra.end());
		sv.assign(extra.begin(), extra.end());
		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Size incorrect", "Passed");
		for (size_t i = 0; i < v.size(); i++)
			ft::test_assert(v[i], sv[i], "Elements not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Push_back function" << std::endl;

		ft::vector<int> v;
		std::vector<int> sv;

		v.push_back(2);
		sv.push_back(2);
		ft::test_assert(v.size(), (unsigned long)1, "Size incorrect", "Passed");
		ft::test_assert(sv.size(), (unsigned long)1, "Size incorrect", "Passed");
		ft::test_assert(v.back(), 2, "Back incorrect", "Passed");
		ft::test_assert(sv.back(), 2, "Back incorrect", "Passed");
		ft::test_assert(v.size(), sv.size(), "Size not same", "Passed");
		ft::test_assert(v.back(), sv.back(), "Back not same", "Passed");

		v.push_back(3);
		sv.push_back(3);
		ft::test_assert(v.size(), (unsigned long)2, "Size incorrect", "Passed");
		ft::test_assert(sv.size(), (unsigned long)2, "Size incorrect", "Passed");
		ft::test_assert(v.back(), 3, "Back incorrect", "Passed");
		ft::test_assert(sv.back(), 3, "Back incorrect", "Passed");
		ft::test_assert(v.size(), sv.size(), "Size not same", "Passed");
		ft::test_assert(v.back(), sv.back(), "Back not same", "Passed");
	}

	{
		std::cout << std::endl <<  "At function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		ft::test_assert(v.at(0), 2, "At incorrect", "Passed");
		ft::test_assert(sv.at(0), 2, "At incorrect", "Passed");
		ft::test_assert(v.at(0), sv.at(0), "At not same", "Passed");

		// set elements index 0 from 2 to 3;
		v.at(0) = 3;
		sv.at(0) = 3;
		ft::test_assert(v.at(0), 3, "At incorrect", "Passed");
		ft::test_assert(sv.at(0), 3, "At incorrect", "Passed");
		ft::test_assert(v.at(0), sv.at(0), "At not same", "Passed");

		try
		{
			v.at(1) = 1;
		}
		catch (std::out_of_range const& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			sv.at(1) = 1;
		}
		catch (std::out_of_range const& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::cout << std::endl <<  "operator[] function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		ft::test_assert(v[0], 2, "operator[] incorrect", "Passed");
		ft::test_assert(sv[0], 2, "operator[] incorrect", "Passed");
		ft::test_assert(v[0], sv[0], "operator[] not same", "Passed");

		// set elements index 0 from 2 to 3;
		v[0] = 3;
		sv[0] = 3;
		ft::test_assert(v[0], 3, "operator[] incorrect", "Passed");
		ft::test_assert(sv[0], 3, "operator[] incorrect", "Passed");
		ft::test_assert(v[0], sv[0], "operator[] not same", "Passed");

		// show memory error if out of bound using fsanitize=address
		// v[1] = 1;
		// sv[1] = 1;
	}

	{
		std::cout << std::endl <<  "Front function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		ft::test_assert(v.front(), 2, "Front incorrect", "Passed");
		ft::test_assert(sv.front(), 2, "Front incorrect", "Passed");
		ft::test_assert(v.front(), sv.front(), "Front not same", "Passed");

		// set elements index 0 from 2 to 3;
		v[0] = 3;
		v.front() = 3;
		sv[0] = 3;
		sv.front() = 3;
		ft::test_assert(v.front(), 3, "Front incorrect", "Passed");
		ft::test_assert(sv.front(), 3, "Front incorrect", "Passed");
		ft::test_assert(v.front(), sv.front(), "Front not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Back function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		ft::test_assert(v.back(), 2, "Back incorrect", "Passed");
		ft::test_assert(sv.back(), 2, "Back incorrect", "Passed");
		ft::test_assert(v.back(), sv.back(), "Back not same", "Passed");

		// set elements index 0 from 2 to 3;
		v.push_back(3);
		v.back() = 3;
		sv.push_back(3);
		sv.back() = 3;
		ft::test_assert(v.back(), 3, "Back incorrect", "Passed");
		ft::test_assert(sv.back(), 3, "Back incorrect", "Passed");
		ft::test_assert(v.back(), sv.back(), "Back not same", "Passed");
	}

	{
		std::cout << std::endl <<  "Data function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		// Check that data() returns a pointer to te=he first element of the vector
		ft::test_assert(v.data(), &v[0], "Data incorrect", "Passed");
		ft::test_assert(sv.data(), &sv[0], "Data incorrect", "Passed");

		// Check that data() returns a valid pointer even if ventor is empty
		ft::vector<int> empty;
		std::vector<int> empty2;
		ft::test_assert(empty.data(), (int *)nullptr, "Data incorrect", "Passed");
		ft::test_assert(empty2.data(), (int *)nullptr, "Data incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "Begin function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		// Test 1: Check that begin() returns an iterator pointing to the first element of the vector

		ft::test_assert(std::addressof(*(v.begin())), std::addressof(*(v.data())), "Begin incorrect", "Passed");
		ft::test_assert(std::addressof(*(sv.begin())), std::addressof(*(sv.data())), "Begin incorrect", "Passed");
		
		// Test 2: Check that end() returns an iterator pointing to one past the last element of the vector

		ft::test_assert(std::addressof(*(v.end())), std::addressof(*(v.data() + v.size())), "Begin incorrect", "Passed");
		ft::test_assert(std::addressof(*(sv.end())), std::addressof(*(sv.data() + sv.size())), "Begin incorrect", "Passed");

		// Test 3: Check that begin() and end() return the same iterator for an empty vector
		ft::vector<int> empty;
		std::vector<int> empty2;
		ft::test_assert(empty.begin(), empty.end(), "Begin incorrect", "Passed");
		ft::test_assert(empty2.begin(), empty2.end(), "Begin incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "End function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		// Test 1: function correctly returns an iterator pointing to one past the last element in a vector of size 1.

		ft::test_assert(v.end(), v.begin() + 1, "End incorrect", "Passed");
		ft::test_assert(sv.end(), sv.begin() + 1, "End incorrect", "Passed");
		
		// Test 2: function correctly returns an iterator pointing to one past the last element in a vector of size greater than 1.

		ft::vector<int> v2(2, 2);
		std::vector<int> sv2(2, 2);

		ft::test_assert(v2.end(), v2.begin() + 2, "End incorrect", "Passed");
		ft::test_assert(sv2.end(), sv2.begin() + 2, "End incorrect", "Passed");

		// Test 3: function correctly handles an empty vector and returns an appropriate value (e.g., an iterator pointing to the beginning of the vector, or an error).
		ft::vector<int> v3;
		std::vector<int> sv3;
		ft::test_assert(v3.end(), v3.begin(), "End incorrect", "Passed");
		ft::test_assert(sv3.end(), sv3.begin(), "End incorrect", "Passed");

		// Test 4: function returns the correct iterator when passed a vector with both negative and positive values.
		ft::vector<int> v4(1, 1);
		std::vector<int> sv4(1, 1);

		v4.push_back(-1);
		sv4.push_back(-1);
		ft::test_assert(v4.end(), v4.begin() + 2, "End incorrect", "Passed");
		ft::test_assert(sv4.end(), sv4.begin() + 2, "End incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "Rbegin function" << std::endl;

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		// Test 1: function correctly returns an iterator pointing to one past the last element in a vector of size 1.

		ft::test_assert(*(v.rbegin()), 2, "Rbegin incorrect", "Passed");
		ft::test_assert(*(sv.rbegin()), 2, "Rbegin incorrect", "Passed");
		
		// Test 2: function correctly returns an iterator pointing to one past the last element in a vector of size greater than 1.

		ft::vector<int> v2(2, 3);
		std::vector<int> sv2(2, 3);

		ft::test_assert(*(v2.rbegin()), 3, "Rbegin incorrect", "Passed");
		ft::test_assert(*(sv2.rbegin()), 3, "Rbegin incorrect", "Passed");

		// Test 3: function correctly handles an empty vector and returns an appropriate value

		ft::vector<int> v3;
		std::vector<int> sv3;
		ft::test_assert(v3.rbegin(), v3.rend(), "Rbegin incorrect", "Passed");
		ft::test_assert(sv3.rbegin(), sv3.rend(), "Rbegin incorrect", "Passed");

		// Test 4: function returns the correct iterator when passed a vector with both negative and positive values.
		ft::vector<int> v4(1, 1);
		std::vector<int> sv4(1, 1);

		v4.push_back(-1);
		sv4.push_back(-1);
		ft::test_assert(*(v4.rbegin()), -1, "Rbegin incorrect", "Passed");
		ft::test_assert(*(sv4.rbegin()), -1, "Rbegin incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "Rend function" << std::endl;

		ft::vector<int> v(1, 42);
		std::vector<int> sv(1, 42);

		// Test 1: test that rend() returns an iterator pointing to the element just before the first element in the vector. --it is require for iterator to point to first element. By default,reverse iterator 
		ft::vector<int>::reverse_iterator it;
		std::vector<int>::reverse_iterator it2;
		it = v.rend();
		it2 = sv.rend();
		--it;
		--it2;
		ft::test_assert(*it, 42, "Rend incorrect", "Passed");
		ft::test_assert(*it2, 42, "Rend incorrect", "Passed");
		
		// Test 2: Test that rend() == rbegin() for an empty vector.
		ft::vector<int> v2;
		std::vector<int> sv2;

		ft::test_assert(v2.rend(), v2.rbegin(), "Rend incorrect", "Passed");
		ft::test_assert(sv2.rend(), sv2.rbegin(), "Rend incorrect", "Passed");

		// Test 3: function returns the correct iterator when passed a vector with both negative and positive values.
		ft::vector<int> v3(1, 1);
		std::vector<int> sv3(1, 1);

		v3.push_back(-1);
		sv3.push_back(-1);
		ft::test_assert(v3.rend(), v3.rbegin() + 2, "Rend incorrect", "Passed");
		ft::test_assert(sv3.rend(), sv3.rbegin() + 2, "Rend incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "Empty function" << std::endl;

		ft::vector<int> v;
		std::vector<int> sv;
		ft::test_assert(v.empty(), true, "Empty incorrect", "Passed");
		ft::test_assert(sv.empty(), true, "Empty incorrect", "Passed");

		v.push_back(1);
		sv.push_back(1);
		ft::test_assert(v.empty(), false, "Empty incorrect", "Passed");
		ft::test_assert(sv.empty(), false, "Empty incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "Size function" << std::endl;

		ft::vector<int> v;
		std::vector<int> sv;
		ft::test_assert(v.size(), (size_t)0, "Size incorrect", "Passed");
		ft::test_assert(sv.size(), (size_t)0, "Size incorrect", "Passed");

		v.push_back(1);
		sv.push_back(1);
		ft::test_assert(v.size(), (size_t)1, "Size incorrect", "Passed");
		ft::test_assert(sv.size(), (size_t)1, "Size incorrect", "Passed");

		ft::vector<int> v2(5, 100);
		std::vector<int> sv2(5, 100);
		ft::test_assert(v2.size(),  (size_t)5, "Size incorrect", "Passed");
		ft::test_assert(sv2.size(),  (size_t)5, "Size incorrect", "Passed");

		ft::vector<int> v3(v2.begin(), v2.end());
		std::vector<int> sv3(sv2.begin(), sv2.end());
		ft::test_assert(v3.size(),  (size_t)5, "Size incorrect", "Passed");
		ft::test_assert(sv3.size(),  (size_t)5, "Size incorrect", "Passed");
	}

	{
		std::cout << std::endl <<  "Max_size function" << std::endl;

		size_t		my_max_alloc_size;
		size_t		std_max_alloc_size;
	
		ft::vector<int> v;
		std::vector<int> sv;

		my_max_alloc_size = v.max_size();
		std_max_alloc_size = sv.max_size();
		ft::test_assert(my_max_alloc_size, std::min(my_max_alloc_size, static_cast<size_t>(std::numeric_limits<std::vector<int>::difference_type>::max())), "Max_size incorrect", "Passed");
		ft::test_assert(std_max_alloc_size, std::min(my_max_alloc_size, static_cast<size_t>(std::numeric_limits<std::vector<int>::difference_type>::max())), "Max_size incorrect", "Passed");
		ft::test_assert(my_max_alloc_size, std_max_alloc_size, "Max_size incorrect", "Passed");

		ft::vector<int> v2(10000, 0);
		std::vector<int> sv2(10000, 0);
	
		my_max_alloc_size = v2.max_size();
		std_max_alloc_size = sv2.max_size();
		ft::test_assert(my_max_alloc_size, std::min(my_max_alloc_size, static_cast<size_t>(std::numeric_limits<std::vector<int>::difference_type>::max())), "Max_size incorrect", "Passed");
		ft::test_assert(std_max_alloc_size, std::min(my_max_alloc_size, static_cast<size_t>(std::numeric_limits<std::vector<int>::difference_type>::max())), "Max_size incorrect", "Passed");
		ft::test_assert(my_max_alloc_size, std_max_alloc_size, "Max_size incorrect", "Passed");
	}


	{
		std::cout << std::endl <<  "Reserve function" << std::endl;

		// Test the reserve() function for a std::vector object with an initial capacity of 0:
		ft::vector<int> v;
		std::vector<int> sv;

		v.reserve(10);
		sv.reserve(10);
		ft::test_assert(v.capacity(),  (size_t)10, "Reserve incorrect", "Passed");
		ft::test_assert(sv.capacity(),  (size_t)10, "Reserve incorrect", "Passed");

		ft::vector<int> v2(20);
		std::vector<int> sv2(20);

		std::cout<<"capcity:"<<v2.capacity()<<std::endl;
		v2.reserve(10);
		std::cout<<"capcity:"<<v2.capacity()<<std::endl;
		sv2.reserve(10);
		ft::test_assert(v2.capacity(), (size_t)20, "Reserve incorrect", "Passed");
		ft::test_assert(sv2.capacity(), (size_t)20, "Reserve incorrect", "Passed");

		ft::vector<int> v3(10);
		std::vector<int> sv3(10);

		v3.reserve(10);
		sv3.reserve(10);
		ft::test_assert(v3.capacity(), (size_t)10, "Reserve incorrect", "Passed");
		ft::test_assert(sv3.capacity(), (size_t)10, "Reserve incorrect", "Passed");
		
		ft::vector<int> v4(10, 0);
		std::vector<int> sv4(10, 0);

		v4.reserve(20);
		sv4.reserve(20);
		ft::test_assert(v4.capacity(),  (size_t)20, "Reserve incorrect", "Passed");
		ft::test_assert(sv4.capacity(),  (size_t)20, "Reserve incorrect", "Passed");

		ft::vector<int> v5(10000);
		std::vector<int> sv5(10000);

		v5.reserve(20);
		sv5.reserve(20);
		ft::test_assert(v5.capacity(),  (size_t)10000, "Reserve incorrect", "Passed");
		ft::test_assert(sv5.capacity(),  (size_t)10000, "Reserve incorrect", "Passed");


	}
}
