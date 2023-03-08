/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:13:41 by codespace         #+#    #+#             */
/*   Updated: 2023/03/08 21:42:51 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cassert>
#include <iomanip> 
// #include "tester.hpp"
// #include "../header/vector.hpp"
#include "../header/utils/test.hpp"
// #include "../header/vector.tpp"
#include <ctime> // for clock

int main(void)
{
	{
		ft::print_headers("Default constructor");
		ft::vector<int> v;
		std::vector<int> sv;
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Constructer with the given allocator alloc");
		ft::vector<int> v((std::allocator<int>()));
		std::vector<int> sv;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Count value constructor");
		ft::vector<int> v(2, 100);
		std::vector<int> sv(2, 100);
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Range constructor");

		ft::vector<int> v(4,100);
		ft::vector<int> v2(v.begin(), v.end());
		std::vector<int> sv(4,100); 
		std::vector<int> sv2(sv.begin(),sv.end());
		ft::vector_check(v2, sv2);
	}
	
	{
		ft::print_headers("Copy constructor");

		ft::vector<int> v (4, 200);
		ft::vector<int> v2 (v);
		std::vector<int> sv (4, 200);
		std::vector<int> sv2 (sv);
		ft::vector_check(v2, sv2);
	}

	{
		ft::print_headers("Assign function");

		ft::vector<int> v;
		std::vector<int> sv;

		v.assign(5, 1);
		sv.assign(5, 1);
		ft::vector_check(v, sv);

		ft::print_headers("Range assign function");
		const std::vector<int> extra(6, 2);
		v.assign(extra.begin(), extra.end());
		sv.assign(extra.begin(), extra.end());
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Operator=");

		ft::vector<int> v;
		ft::vector<int> v2;
		std::vector<int> sv;
		std::vector<int> sv2;

		v.assign(5, 1);
		sv.assign(5, 1);
		v2 = v;
		sv2 = sv;
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Push_back function");

		ft::vector<int> v;
		std::vector<int> sv;
		v.push_back(2);
		sv.push_back(2);
		ft::vector_check(v, sv);
		v.push_back(3);
		sv.push_back(3);
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("At function");

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

		// Test elements out_of_range
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
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("operator[] function");

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
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Front function");

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
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Back function");

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
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Data function");

		ft::vector<int> v(1, 2);
		std::vector<int> sv(1, 2);

		// Check that data() returns a pointer to the first element of the vector
		ft::test_assert(v.data(), &v[0], "Data incorrect", "Passed");
		ft::test_assert(sv.data(), &sv[0], "Data incorrect", "Passed");

		// Check that data() returns a valid pointer even if ventor is empty
		ft::vector<int> empty;
		std::vector<int> empty2;
		ft::test_assert(empty.data(), (int *)nullptr, "Data incorrect", "Passed");
		ft::test_assert(empty2.data(), (int *)nullptr, "Data incorrect", "Passed");
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Begin function");

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
		ft::vector_check(v, sv);


	}

	{
		ft::print_headers("End function");

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
		ft::print_headers("Rbegin function");

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
		ft::print_headers("Rend function");

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
		ft::print_headers("Empty function");

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
		ft::print_headers("Size function");

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
		ft::print_headers("Max_size function");

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
		ft::print_headers("Reserve function");

		// Test the reserve() function for a std::vector object with an initial capacity of 0:
		ft::vector<int> v;
		std::vector<int> sv;

		v.reserve(10);
		sv.reserve(10);
		ft::test_assert(v.capacity(), (size_t)10, "Reserve incorrect", "Passed");
		ft::test_assert(sv.capacity(), (size_t)10, "Reserve incorrect", "Passed");
		ft::test_assert(v.size(),  sv.size(), "Size incorrect", "Passed");

		ft::vector<int> v2(20);
		std::vector<int> sv2(20);

		v2.reserve(10);
		sv2.reserve(10);
		ft::test_assert(v2.capacity(), (size_t)20, "Reserve incorrect", "Passed");
		ft::test_assert(sv2.capacity(), (size_t)20, "Reserve incorrect", "Passed");
		ft::test_assert(v2.size(),  sv2.size(), "Size incorrect", "Passed");

		ft::vector<int> v3(10);
		std::vector<int> sv3(10);

		v3.reserve(10);
		sv3.reserve(10);
		ft::test_assert(v3.capacity(), (size_t)10, "Reserve incorrect", "Passed");
		ft::test_assert(sv3.capacity(), (size_t)10, "Reserve incorrect", "Passed");ft::test_assert(v3.size(),  sv3.size(), "Size incorrect", "Passed");
		
		ft::vector<int> v4(10, 0);
		std::vector<int> sv4(10, 0);

		v4.reserve(20);
		sv4.reserve(20);
		ft::test_assert(v4.capacity(), (size_t)20, "Reserve incorrect", "Passed");
		ft::test_assert(sv4.capacity(), (size_t)20, "Reserve incorrect", "Passed");

		ft::vector<int> v5(10000);
		std::vector<int> sv5(10000);

		v5.reserve(20);
		sv5.reserve(20);
		ft::test_assert(v5.capacity(), (size_t)10000, "Reserve incorrect", "Passed");
		ft::test_assert(sv5.capacity(), (size_t)10000, "Reserve incorrect", "Passed");

		ft::vector<int> v6(v5);
		std::vector<int> sv6(sv5);

		v6.reserve(20);
		sv6.reserve(20);
		ft::test_assert(v6.capacity(), (size_t)10000, "Reserve incorrect", "Passed");
		ft::test_assert(sv6.capacity(), (size_t)10000, "Reserve incorrect", "Passed");

		v6.reserve(10001);
		sv6.reserve(10001);
		v6.push_back(1);
		sv6.push_back(1);
		ft::test_assert(v6.capacity(), (size_t)10001, "Reserve incorrect", "Passed");
		ft::test_assert(sv6.capacity(), (size_t)10001, "Reserve incorrect", "Passed");
	}

	{
		ft::print_headers("Capacity function");

		// Test 1: Default capacity of vector
		ft::vector<int> v;
		std::vector<int> sv;

		ft::test_assert(v.capacity(), (size_t)0, "Capacity incorrect", "Passed");
		ft::test_assert(sv.capacity(), (size_t)0, "Capacity incorrect", "Passed");

		// Test 2: capacity of vector after reserve
		v.reserve(10);
		sv.reserve(10);
		ft::test_assert(v.capacity(), (size_t)10, "Capacity incorrect", "Passed");
		ft::test_assert(sv.capacity(), (size_t)10, "Capacity incorrect", "Passed");


		// Test 3: capacity of vector after resizing
		v.resize(5);
		sv.resize(5);
		// ft::test_assert(v.capacity(), (size_t)10, "Capacity incorrect", "Passed");
		ft::test_assert(sv.capacity(), (size_t)10, "Capacity incorrect", "Passed");

		v.push_back(1);
		sv.push_back(1);
		ft::test_assert(v.capacity(), (size_t)10, "Capacity incorrect", "Passed");
		ft::test_assert(sv.capacity(), (size_t)10, "Capacity incorrect", "Passed");

		int	sz = 100;

		ft::vector <int>	v2;
		ft::vector<int>::size_type	cap = v2.capacity();
		std::cout << "Initial size: " << v2.size() << ", capacity: " << cap << '\n';
		std::cout << "\nDemonstrate the capacity's growth policy." "\nSize:  Capacity:  Ratio:\n" << std::left;
		while (sz-- > 0)
		{
			v2.push_back(sz);
			if (cap != v2.capacity())
			{
				std::cout << std::setw( 7) << v2.size()
						<< std::setw(11) << v2.capacity()
						<< std::setw(10) << static_cast<float>(v2.capacity()) / static_cast<float>(cap) << '\n';
				cap = v2.capacity();
			}
		}
		
		std::cout << "\nFinal size: " << v2.size() << ", capacity: " << v2.capacity() << '\n';
		int	sz2 = 100;

		std::cout << "\nFinal size: " << v2.size() << ", capacity: " << v2.capacity() << '\n';

		std::vector <int>	sv2;
		std::vector<int>::size_type	std_cap = sv2.capacity();
		std::cout << "Initial size: " << sv2.size() << ", capacity: " << std_cap << '\n';
		std::cout << "\nDemonstrate the capacity's growth policy." "\nSize:  Capacity:  Ratio:\n" << std::left;
		while (sz2-- > 0)
		{
			sv2.push_back(sz);
			if (cap != sv2.capacity())
			{
				std::cout << std::setw( 7) << sv2.size()
						<< std::setw(11) << sv2.capacity()
						<< std::setw(10) << static_cast<float>(sv2.capacity()) / static_cast<float>(std_cap) << '\n';
				std_cap = sv2.capacity();
			}
		}
		std::cout << "\nFinal size: " << sv2.size() << ", capacity: " << sv2.capacity() << '\n';
	}

	{
		ft::print_headers("Shrink_to_fit function");

		ft::vector<int> v(5);
		std::vector<int> sv(5);

		v.shrink_to_fit();
		sv.shrink_to_fit();
		ft::test_assert(v.size(), (size_t)5, "Capacity incorrect", "Passed");
		ft::test_assert(v.size(), v.capacity(), "Capacity incorrect", "Passed");
		ft::test_assert(sv.size(), (size_t)5, "Capacity incorrect", "Passed");
		ft::test_assert(sv.size(), sv.capacity(), "Capacity incorrect", "Passed");
		
		for (int i = 1000; i < 1300; ++i)
		{
			v.push_back(i);
			sv.push_back(i);
		}
		std::cout << "Capacity after adding 300 elements is ft: " << v.capacity() << '\n';
		std::cout << "Capacity after adding 300 elements is std: " << sv.capacity() << '\n';
		v.shrink_to_fit();
		sv.shrink_to_fit();
		std::cout << "Capacity after shrink_to_fit() is ft: " << v.capacity() << '\n';
		std::cout << "Capacity after shrink_to_fit() is ft: " << sv.capacity() << '\n';

	}

	{
		ft::print_headers("Clear function");

		ft::vector<int> v(5, 1);
		std::vector<int> sv(5, 1);

		v.clear();
		sv.clear();
		ft::test_assert(v.size(), (size_t)0, "Clear incorrect", "Passed");
		ft::test_assert(v.capacity(),  (size_t)5, "Clear incorrect", "Passed");
		ft::test_assert(sv.size(), (size_t)0, "Clear incorrect", "Passed");
		ft::test_assert(sv.capacity(), (size_t)5, "Clear incorrect", "Passed");
	}

	{
		ft::print_headers("Insert function");
		ft::vector<int> v(3, 300);
		std::vector<int> sv(3, 300);

		// Test 1: const value
		v.insert(v.begin(), 100);
		sv.insert(sv.begin(), 100);
		ft::vector_check(v, sv);

		// Test 2: const value and add into middle
		v.insert(v.begin() + 1, 200);
		// ft::print_vector(v);
		sv.insert(sv.begin() + 1, 200);
		ft::vector_check(v, sv);


		// Test 3: non_const value and end()
		int	value = 400;
		v.insert(v.end(), value);
		sv.insert(sv.end(), value);
		ft::vector_check(v, sv);

		// Test 4: inserting multiple values at beginning vector
		v.insert(v.begin(), 2, 50);
		sv.insert(sv.begin(), 2, 50);
		ft::vector_check(v, sv);

		// Test 5: inserting multiple value at middle vector
		v.insert(v.begin() + 2, 2, 70);
		sv.insert(sv.begin() + 2, 2, 70);
		ft::vector_check(v, sv);
		
		// Test 6: inserting multiple value at end vector
		v.insert(v.end(), 2, 500);
		sv.insert(sv.end(), 2, 500);
		ft::vector_check(v, sv);

		ft::vector<int>		v2;
		std::vector<int>	sv2;
		v2.insert(v2.begin(), v.begin(), v.end());
		sv2.insert(sv2.begin(), sv.begin(), sv.end());
		ft::vector_check(v2, sv2);

		// Test: Add the range at end
		ft::vector<int>		v3(2, 700);
		std::vector<int>	sv3(2, 700);
		v2.insert(v2.end(), v3.begin(), v3.end());
		sv2.insert(sv2.end(), sv3.begin(), sv3.end());
		ft::vector_check(v2, sv2);

		// Test: Add the second element of vector at middle 
		ft::vector<int>		v4(1, 250);
		v4.push_back(270);
		std::vector<int>	sv4(1, 250);
		sv4.push_back(270);
		v2.insert(v2.begin() + 6, v4.begin() + 1, v4.end());
		sv2.insert(sv2.begin() + 6, sv4.begin() + 1, sv4.end());
		ft::vector_check(v2, sv2);


		// Test: Multiple position insert using const insert value type
		v2.insert(v2.begin(), 20);
		sv2.insert(sv2.begin(), 20);
		v2.insert(v2.begin(), 10);
		sv2.insert(sv2.begin(), 10);
		v2.insert(v2.begin() + 4, 120);
		sv2.insert(sv2.begin() + 4, 120);
		v2.insert(v2.end(), 1000);
		sv2.insert(sv2.end(), 1000);
		ft::vector_check(v2, sv2);
	}

	{
		ft::print_headers("Erase function");
		ft::vector<int> v(1, 0);
		std::vector<int> sv(1, 0);

		v.push_back(1);
		sv.push_back(1);

		// Test1: remove elements at beginning of vector non_const
		v.erase(v.begin());
		sv.erase(sv.begin());
		ft::vector_check(v, sv);

		// Test2: remove elements at beginning of vector const
		v.insert(v.begin(), 0);
		sv.insert(sv.begin(), 0);
		ft::vector<int>::const_iterator pos = v.begin();
		std::vector<int>::const_iterator pos2 = sv.begin();
		v.erase(pos);
		sv.erase(pos2);
		ft::vector_check(v, sv);


		
		// Test3: remove elements at middle of vector non_const iterator
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.erase(v.begin() + 1);
		sv.push_back(2);
		sv.push_back(3);
		sv.push_back(4);
		sv.erase(sv.begin() + 1);
		ft::vector_check(v, sv);


		// Test4: remove elements at middle of vector const iterator
		v.insert(v.begin() + 1, 2);
		pos = v.begin() + 1;
		v.erase(pos);
		sv.insert(sv.begin() + 1, 2);
		pos2 = sv.begin() + 1;
		sv.erase(pos2);
		ft::vector_check(v, sv);

		// Test5: remove elements at end of vector non_const iterator
		v.insert(v.begin() + 1, 2);
		v.erase(v.end() - 1);
		sv.insert(sv.begin() + 1, 2);
		sv.erase(sv.end() - 1);
		ft::vector_check(v, sv);

		// Test6: remove elements at end of vector const iterator
		pos = v.end() - 1;
		v.erase(pos);
		pos2 = sv.end() - 1;
		sv.erase(pos2);
		ft::vector_check(v, sv);

		// Test7: test for range erase for non_const iterator
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		sv.push_back(3);
		sv.push_back(4);
		sv.push_back(5);
		v.erase(v.begin() + 2, v.end());
		sv.erase(sv.begin() + 2, sv.end());
		ft::vector_check(v, sv);


		// Test7: test for range erase for const iterator
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		sv.push_back(3);
		sv.push_back(4);
		sv.push_back(5);
		pos = v.begin() + 2;
		v.erase(pos, v.end());
		pos2 = sv.begin() + 2;
		sv.erase(pos2, sv.end());
		ft::vector_check(v, sv);


		// Test8: test for when first is greater than last in range erase
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		sv.push_back(3);
		sv.push_back(4);
		sv.push_back(5);
		ft::vector<int>::const_iterator first = v.begin() + 3;
		ft::vector<int>::const_iterator last = v.begin() + 1;
		v.erase(first, last);
		// std::vector<int>::const_iterator sfirst = sv.begin() + 1;
		// std::vector<int>::const_iterator slast = sv.begin() + 3;
		// standard vector do not handle first > last, throw segmentation fault
		// sv.erase(sfirst, slast);
		ft::test_assert(v.size(), size_t(5), "Erase incorrect", "Passed");

		
		// Test9: test erase all
		v.erase(v.begin(), v.end());
		sv.erase(sv.begin(), sv.end());
		ft::test_assert(v.size(), sv.size(), "Erase incorrect", "Passed");
	}

	{
		ft::print_headers("Push_back function");

		// test1: push_back with int
		ft::vector<int> v;
		std::vector<int> sv;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		ft::vector_check(v, sv);

		// test2: push_back with char
		ft::vector<char> v2;
		std::vector<char> sv2;

		v2.push_back('a');
		v2.push_back('b');
		v2.push_back('c');
		sv2.push_back('a');
		sv2.push_back('b');
		sv2.push_back('c');
		ft::vector_check(v, sv);
	}

	{
		ft::print_headers("Pop_back function");

		ft::vector<int> v;
		std::vector<int> sv;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);

		v.pop_back(); 
		sv.pop_back();
		ft::vector_check(v, sv);

		v.pop_back();
		sv.pop_back();
		ft::vector_check(v, sv);
	
		v.pop_back(); 
		sv.pop_back();
		ft::test_assert(v.size(), sv.size(), "Push_back incorrect", "Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Push_back incorrect", "Passed");
		for (size_t i = 0; i < v.size(); i++)
			ft::test_assert(v[i], sv[i], "Push_back incorrect", "Passed");
	}

	{
		ft::print_headers("Resize function");
		ft::vector<int>		v;
		std::vector<int>	sv;

		// Test1: resize a vector to a larger size, with a default value
		v.push_back(1);
		v.push_back(2);
		sv.push_back(1);
		sv.push_back(2);
		v.resize(4);
		sv.resize(4);
		ft::vector_check(v, sv);

		// Test2: resizing a vector to a larger size, with a specified value:
		v.resize(6, 3);
		sv.resize(6, 3);
		ft::vector_check(v, sv);

		// Test3: resizing a vector to smaller size
		v.resize(3);
		sv.resize(3);
		ft::vector_check(v, sv);

		// Test4: resizing a vector to same size
		v.resize(3);
		sv.resize(3);
		ft::vector_check(v, sv);

		// Test5: resizing a vector to a size larger than its maximum size
		try
		{
			v.resize(v.max_size() + 1);
			assert(false); // this line should not be reached
		} catch (const std::length_error& e) 
		{
			assert(std::string(e.what()) == "ft::vector::resize");
		}
		try
		{
			sv.resize(sv.max_size() + 1);
			assert(false); // this line should not be reached
		} catch (const std::length_error& e) 
		{
			assert(std::string(e.what()) == "vector");
		}
	}

	{
		ft::print_headers("Swap function");

		ft::vector<int>		v;
		ft::vector<int>		v2;
		std::vector<int>	sv;
		std::vector<int>	sv2;

		// Test1: Swap two vectors with different sizes:
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(6);
		v2.push_back(7);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		sv2.push_back(4);
		sv2.push_back(5);
		sv2.push_back(6);
		sv2.push_back(7);
		v.swap(v2);
		sv.swap(sv2);
		ft::vector_check(v, sv);
		ft::vector_check(v2, sv2);
		v.clear();
		v2.clear();
		sv.clear();
		sv2.clear();

		// Test2: Swap two vectors with same sizes:
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.push_back(6);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		sv2.push_back(4);
		sv2.push_back(5);
		sv2.push_back(6);
		v.swap(v2);
		sv.swap(sv2);
		ft::vector_check(v, sv);
		ft::vector_check(v2, sv2);
		v.clear();
		v2.clear();
		sv.clear();
		sv2.clear();

		// Test3: Swap a vector with an empty vector
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.swap(v2);
		sv.push_back(1);
		sv.push_back(2);
		sv.push_back(3);
		sv.swap(sv2);
		ft::test_assert(v.empty(), true, "Resize incorrect", "Passed");
		ft::test_assert(sv.empty(), true, "Resize incorrect", "Passed");
		ft::vector_check(v, sv);
		ft::vector_check(v2, sv2);
	}

	{
		ft::print_headers("Non-member function");

		ft::vector<int> v;
		ft::vector<int> v2;
		ft::vector<int> v3;

		v.push_back(1);
	
		v2.push_back(1);
		v2.push_back(2);

		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);

		assert(!(v == v2));
		assert(!(v2 == v3));
		assert(v != v2);
		assert(v2 != v3);
		assert(v < v2);
		assert(v2 < v3);
		assert(v <= v2);
		assert(v2 <= v3);
		assert(v3 > v2);
		assert(v2 > v);
		assert(v3 >= v2);
		assert(v2 >= v);
		std::cout << "All Non-member functions pass" << std::endl;
	}

	{
		ft::print_headers("Check Time Performance");

		clock_t	start_time, end_time;
		double	ft_vec_time, std_vec_time;
		bool	rv;

		start_time = clock();

		ft::vector<int>		v;
		ft::vector<int>		v2(42, 42);

		v.assign(v2.begin(), v2.end());
		v.get_allocator();
		v.at(0);
		v[0];
		v.front();
		v.back();
		v.data();
		v.begin();
		v.end();
		v.rbegin();
		v.rend();
		v.empty();
		v.size();
		v.max_size();
		v.reserve(42);
		v.capacity();
		v.shrink_to_fit();
		v.clear();
		v.insert(v.begin(), -1);
		v.insert(v.begin(), v2.begin(), v2.end());
		v.erase(v.begin());
		v.erase(v.begin(), v.end());
		v.push_back(42);
		v.pop_back();
		v.resize(42);
		v.swap(v2);
		rv = (v == v2);
		rv = (v != v2);
		rv = (v < v2);
		rv = (v <= v2);
		rv = (v > v2);
		rv = (v >= v2);
		
		end_time = clock();
		ft_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "ft_vec_time: " << ft_vec_time << std::endl;

		start_time = clock();

		std::vector<int>		sv;
		std::vector<int>		sv2(42, 42);

		sv.assign(sv2.begin(), sv2.end());
		sv.get_allocator();
		sv.at(0);
		sv[0];
		sv.front();
		sv.back();
		sv.data();
		sv.begin();
		sv.end();
		sv.rbegin();
		sv.rend();
		sv.empty();
		sv.size();
		sv.max_size();
		sv.reserve(42);
		sv.capacity();
		sv.shrink_to_fit();
		sv.clear();
		sv.insert(sv.begin(), -1);
		sv.insert(sv.begin(), sv2.begin(), sv2.end());
		sv.erase(sv.begin());
		sv.erase(sv.begin(), sv.end());
		sv.push_back(42);
		sv.pop_back();
		sv.resize(42);
		sv.swap(sv2);
		rv = (sv == sv2);
		rv = (sv != sv2);
		rv = (sv < sv2);
		rv = (sv <= sv2);
		rv = (sv > sv2);
		rv = (sv >= sv2);
		
		end_time = clock();
		std_vec_time = (start_time - end_time) / CLOCKS_PER_SEC;
		std::cout << "std vec time: " << std_vec_time << std::endl;
		std::cout << "Performance ratio of ft container compared to std container is: " << ft_vec_time / std_vec_time << " times\n" << std::endl;
	}
	// system("leaks ft_container");
	return (0);
}
