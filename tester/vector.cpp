/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:13:41 by codespace         #+#    #+#             */
/*   Updated: 2023/01/01 22:53:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../header/vector.hpp"
#include "../header/utils/utility.hpp"
#include <vector>
#include <cassert>


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
		assert(v.size() == sv.size());
		assert(v.capacity() == sv.capacity());
		std::cout << "my vector size: " << v.size() << std::endl;
		std::cout << "my vector capacity: " << v.capacity() << std::endl;
		std::cout << "std vector size: " << sv.size() << std::endl;
		std::cout << "std vector capacity: " << sv.capacity() << std::endl;	
		if (v.size() == sv.size())
			std::cout << "Vector sizes match." << std::endl;
		else
			std::cout << "Vector sizes do not match." << std::endl;	
		if (v.capacity() == sv.capacity())
			std::cout << "Vector capacity match." << std::endl;
		else
			std::cout << "Vector capacity do not match." << std::endl;
		
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << "my vec[" << i << "] = " << v[i] << std::endl;
			std::cout << "std vec[" << i << "] = " << sv[i] << std::endl;
			if (v[i] == sv[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}
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
		assert(v.size() == sv.size());
		assert(v.capacity() == sv.capacity());
		std::cout << "my vector size: " << v.size() << std::endl;
		std::cout << "my vector capacity: " << v.capacity() << std::endl;
		std::cout << "std vector size: " << sv.size() << std::endl;
		std::cout << "std vector capacity: " << sv.capacity() << std::endl;	
		if (v.size() == sv.size())
			std::cout << "Vector sizes match." << std::endl;
		else
			std::cout << "Vector sizes do not match." << std::endl;	
		if (v.capacity() == sv.capacity())
			std::cout << "Vector capacity match." << std::endl;
		else
			std::cout << "Vector capacity do not match." << std::endl;
		
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << "my vec[" << i << "] = " << v[i] << std::endl;
			std::cout << "std vec[" << i << "] = " << sv[i] << std::endl;
			if (v[i] == sv[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}
	}

	{
		std::cout << std::endl <<  "Count value constructor" << std::endl;

		ft::vector<int> v(2, 100);
		std::vector<int> sv(2, 100);

		assert(v.size() == sv.size());
		assert(v.capacity() == sv.capacity());
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << "my vec[" << i << "] = " << v[i] << std::endl;
			std::cout << "std vec[" << i << "] = " << sv[i] << std::endl;
			if (v[i] == sv[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}
	}

	{
		std::cout << std::endl <<  "Range constructor" << std::endl;

		ft::vector<int>::iterator it;
		ft::vector<int> v (4,100);
		ft::vector<int> v2 (v.begin(), v.end());
		for (it = v2.begin(); it != v2.end(); ++it)
		{
			std::cout << "it: " << *it << std::endl;
		}
		std::vector<int> sv (4,100); 
		std::vector<int> sv2 (sv.begin(),sv.end());
		assert(v2.size() == sv2.size());
		assert(v2.capacity() == sv2.capacity());
		for (size_t i = 0; i < v2.size(); i++)
		{
			std::cout << "run program" << std::endl;
			std::cout << "my vec[" << i << "] = [" << v2[i] << std::endl;
			std::cout << "std vec[" << i << "] = [" << sv2[i] << std::endl;
			if (v2[i] == sv2[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}
	}
	
	{
		std::cout << std::endl <<  "Copy constructor" << std::endl;

		ft::vector<int> v (4, 200);
		ft::vector<int> v2 (v);
		std::vector<int> sv (4, 200);
		std::vector<int> sv2 (sv);
		assert(v2.size() == sv2.size());
		assert(v2.capacity() == sv2.capacity());
		for (size_t i = 0; i < v2.size(); i++)
		{
			std::cout << "my vec[" << i << "] = " << v2[i] << std::endl;
			std::cout << "std vec[" << i << "] = " << sv2[i] << std::endl;
			if (v2[i] == sv2[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}
	}

	{
		std::cout << std::endl <<  "Assign function" << std::endl;

		ft::vector<int> v;
		std::vector<int> sv;

		v.assign(5, 1);
		sv.assign(5, 1);
		assert(v.size() == sv.size());
		assert(v.capacity() == sv.capacity());
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << "my vec[" << i << "] = " << v[i] << std::endl;
			std::cout << "std vec[" << i << "] = " << sv[i] << std::endl;
			if (v[i] == sv[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}

		std::cout << std::endl <<  "Range assign function" << std::endl;
		const std::vector<int> extra(6, 2);
		v.assign(extra.begin(), extra.end());
		sv.assign(extra.begin(), extra.end());
			assert(v.size() == sv.size());
		assert(v.capacity() == sv.capacity());
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << "my vec[" << i << "] = " << v[i] << std::endl;
			std::cout << "std vec[" << i << "] = " << sv[i] << std::endl;
			if (v[i] == sv[i])
				std::cout << "Elements at index " << i << " match." << std::endl;
			else
				std::cout << "Elements at index " << i << " do not match." << std::endl;
		}
	}

	{
		std::cout << std::endl <<  "Reserve function" << std::endl;

		ft::vector<int> v;
		std::vector<int> sv;

		v.reserve(10);
		sv.reserve(10);
		assert(v.capacity() == 10);
		assert(v.size() == 0);
		assert(sv.size() == 0);
		assert(v.size() == sv.size());
		assert(v.capacity() == sv.capacity());
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
		ft::test_assert(v.size(), sv.size(), "Size same", "Passed");
		ft::test_assert(v.back(), sv.back(), "Back same", "Passed");

		v.push_back(3);
		sv.push_back(3);
		ft::test_assert(v.size(), (unsigned long)2, "Size incorrect", "Passed");
		ft::test_assert(sv.size(), (unsigned long)2, "Size incorrect", "Passed");
		ft::test_assert(v.back(), 3, "Back incorrect", "Passed");
		ft::test_assert(sv.back(), 3, "Back incorrect", "Passed");
		ft::test_assert(v.size(), sv.size(), "Size same", "Passed");
		ft::test_assert(v.back(), sv.back(), "Back same", "Passed");
	}
}
