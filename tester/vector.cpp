/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:20:25 by schuah            #+#    #+#             */
/*   Updated: 2023/03/08 18:09:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vector.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <chrono>

template <class T>
void	ft_vector_print(ft::vector<T> const &v)
{
	typename ft::vector<T>::const_iterator	b = v.begin();
	typename ft::vector<T>::const_iterator	e = v.end();

	std::cout << "Size: " << v.size() << std::endl;
	std::cout << "Capacity: " << v.capacity() << std::endl;	
	std::cout << "Content: " << std::endl;
	for (; b != e; ++b)
		std::cout << *b << " ";
	std::cout << "\n" << std::endl;
}

template <class T>
void	std_vector_print(std::vector<T> const &v)
{
	typename std::vector<T>::const_iterator	b = v.begin();
	typename std::vector<T>::const_iterator	e = v.end();

	std::cout << "Size: " << v.size() << std::endl;
	std::cout << "Capacity: " << v.capacity() << std::endl;
	std::cout << "Content: " << std::endl;
	for (; b != e; ++b)
		std::cout << *b << " ";
	std::cout << "\n" << std::endl;
}

void	print_break(std::string text)
{
	int	count = (75 - text.length()) / 2;
	for (int i = 0; i < count; i++)
		std::cout << "-";
	std::cout << " " << text << " ";
	for (int i = 0; i < count; i++)
		std::cout << "-";
	std::cout << "\n" << std::endl;
}

template <class T>
void	vector_check(ft::vector<T> const &ft_v, std::vector<T> const &std_v)
{
	ft_vector_print(ft_v);
	for (size_t i = 0; i < std_v.size(); i++)
	{
		assert(ft_v[i] == std_v[i]);
		assert(ft_v.capacity() == std_v.capacity());
		assert(ft_v.empty() == std_v.empty());
		assert(ft_v.get_allocator() == std_v.get_allocator());
		assert(ft_v.max_size() == std_v.max_size());
		assert(ft_v.size() == std_v.size());
	}
}

int	main(void)
{
	{
		print_break("Constructors");
		ft::vector<int> 					ft_v1;
		ft::vector<int> 					ft_v2(10);
		ft::vector<int> 					ft_v3(10, 42);
		ft::vector<int> 					ft_v4 = ft_v3;
		ft::vector<int> 					ft_v5(ft_v4.begin(), ft_v4.end());
		ft::vector<int> 					ft_v6(ft_v5);
		ft::vector<int>						ft_temp;
		ft::vector<int>						ft_cap;
		ft::vector<int>						ft_clear;

		std::vector<int> 					std_v1;
		std::vector<int> 					std_v2(10);
		std::vector<int> 					std_v3(10, 42);
		std::vector<int> 					std_v4 = std_v3;
		std::vector<int> 					std_v5(std_v4.begin(), std_v4.end());
		std::vector<int> 					std_v6(std_v5);
		std::vector<int> 					std_temp;
		std::vector<int>					std_cap;
		std::vector<int>					std_clear;

		ft::vector<int>::iterator			it;
		ft::vector<int>::iterator			eit;
		ft::vector<int>::reverse_iterator	rit;
		ft::vector<int>::reverse_iterator	erit;


		vector_check(ft_v1, std_v1);
		vector_check(ft_v2, std_v2);
		vector_check(ft_v3, std_v3);
		vector_check(ft_v4, std_v4);
		vector_check(ft_v5, std_v5);
		vector_check(ft_v6, std_v6);

		try
		{
			ft::vector<int>	ft_v7(-1);
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
		try
		{
			ft::vector<int>	ft_v7(ft_v4.begin(), ft_v1.end());
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }

		print_break("Assign");
		for (int i = 0; i < 5; i++)
			std_temp.push_back(i);

		ft_v1.assign(std_temp.begin(), std_temp.end());
		std_v1.assign(std_temp.begin(), std_temp.end());
		vector_check(ft_v1, std_v1);

		ft_v1.assign(10, 42);
		std_v1.assign(10, 42);
		vector_check(ft_v1, std_v1);

		ft_v1.assign(20, 42);
		std_v1.assign(20, 42);
		vector_check(ft_v1, std_v1);

		ft_v1.assign(1, 42);
		std_v1.assign(1, 42);
		vector_check(ft_v1, std_v1);

		try
		{
			ft_v1.assign(-1, 42);
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
		
		print_break("Get_allocator");
		std::allocator<int> a = ft_temp.get_allocator();
		ft_vector_print(ft_v1);
		assert(a == ft_v1.get_allocator());

		ft_v1.push_back(1);
		ft_vector_print(ft_v1);
		assert(a == ft_v1.get_allocator());

		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		assert(a == ft_v1.get_allocator());

		ft_v1.resize(10);
		ft_vector_print(ft_v1);
		assert(a == ft_v1.get_allocator());

		ft_v1.resize(5);
		ft_vector_print(ft_v1);
		assert(a == ft_v1.get_allocator());
		
		print_break("At");
		ft_v1.clear();
		std_v1.clear();
		ft_v1.assign(std_temp.begin(), std_temp.end());
		std_v1.assign(std_temp.begin(), std_temp.end());

		ft_vector_print(ft_v1);
		for (size_t i = 0; i < ft_v1.size(); i++)
			assert(ft_v1.at(i) == (int)i);

		ft_v1.push_back(5);
		ft_vector_print(ft_v1);
		for (size_t i = 0; i < ft_v1.size(); i++)
			assert(ft_v1.at(i) == (int)i);

		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		for (size_t i = 0; i < ft_v1.size(); i++)
			assert(ft_v1.at(i) == (int)i);

		try
		{
			ft_v1.at(5);
			assert(false);
		}
		catch(const std::exception& e) {std::cerr << e.what() << "\n\n";}
		try
		{
			ft_v1.at(-1);
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }

		print_break("Operator[]");
		ft_vector_print(ft_v1);
		for (int i = 0; i < 5; i++)
			assert(ft_v1[i] == i);

		ft_v1[0] = 6;
		ft_vector_print(ft_v1);
		assert(ft_v1[0] == 6);
		for (size_t i = 1; i < ft_v1.size(); i++)
			assert(ft_v1.at(i) == (int)i);

		ft_v1[4] = 7;
		ft_vector_print(ft_v1);
		assert(ft_v1[4] == 7);
		for (size_t i = 1; i < ft_v1.size() - 1; i++)
			assert(ft_v1.at(i) == (int)i);
		
		ft_v1[2] = 8;
		ft_vector_print(ft_v1);
		assert(ft_v1[4] == 7);
		for (size_t i = 1; i < ft_v1.size() - 1; i++)
			if (i != 2) assert(ft_v1.at(i) == (int)i);

		print_break("Front");
		ft_v1.clear();
		for (int i = 0; i < 5; i++)
			ft_v1.push_back(i);
		ft_vector_print(ft_v1);
		assert(ft_v1.front() == 0);

		ft_v1.push_back(5);
		ft_vector_print(ft_v1);
		assert(ft_v1.front() == 0);
		
		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		assert(ft_v1.front() == 0);

		ft_v1[0] = 2;
		ft_vector_print(ft_v1);
		assert(ft_v1.front() == 2);
		ft_v1[0] = 0;
		ft_vector_print(ft_v1);
		assert(ft_v1.front() == 0);

		print_break("Back");
		ft_vector_print(ft_v1);
		assert(ft_v1.back() == 4);
		
		ft_v1.push_back(5);
		ft_vector_print(ft_v1);
		assert(ft_v1.back() == 5);

		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		assert(ft_v1.back() == 4);

		ft_v1[4] = 2;
		ft_vector_print(ft_v1);
		assert(ft_v1.back() == 2);
		ft_v1[4] = 4;
		ft_vector_print(ft_v1);
		assert(ft_v1.back() == 4);

		print_break("Data");
		ft_vector_print(ft_v1);
		assert(ft_v1.data() == &ft_v1[0]);

		ft_v1.push_back(5);
		ft_vector_print(ft_v1);
		assert(ft_v1.data() == &ft_v1[0]);

		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		assert(ft_v1.data() == &ft_v1[0]);

		ft_vector_print(ft_temp);
		assert(ft_temp.data() == nullptr);

		print_break("Begin and End");
		ft_vector_print(ft_v1);
		it = ft_v1.begin();
		eit = ft_v1.end();
		assert(*ft_v1.begin() == 0);
		assert(*(ft_v1.end() - 1) == 4);
		assert(it == ft_v1.begin());
		assert(eit == ft_v1.end());

		ft_v1.push_back(5);
		ft_vector_print(ft_v1);
		assert(*ft_v1.begin() == 0);
		assert(*(ft_v1.end() - 1) == 5);
		assert(it == ft_v1.begin());
		assert(eit == --ft_v1.end());

		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		assert(*ft_v1.begin() == 0);
		assert(*(ft_v1.end() - 1) == 4);
		assert(it == ft_v1.begin());
		assert(eit == ft_v1.end());

		ft_vector_print(ft_v1);
		for (int i = 0; it != ft_v1.end(); it++, i++)
		{
			if (i == (int)ft_v1.size() - 1)
				assert(*(ft_v1.end() - 1) == (int)i);
			assert(*it == i);
		}

		it = ft_v1.begin();
		*ft_v1.begin() = 6;
		ft_vector_print(ft_v1);
		assert(ft_v1[0] == 6);
		assert(it == ft_v1.begin());

		*it = 0;
		ft_vector_print(ft_v1);
		assert(ft_v1[0] == 0);
		assert(it == ft_v1.begin());

		eit = ft_v1.end();
		*(ft_v1.end() - 1) = 5;
		ft_vector_print(ft_v1);
		assert(ft_v1[4] == 5);
		assert(eit == ft_v1.end());

		eit = (ft_v1.end() - 1);
		*eit = 4;
		ft_vector_print(ft_v1);
		assert(ft_v1[4] == 4);
		assert(eit + 1 == ft_v1.end());

		ft_vector_print(ft_temp);
		assert(ft_temp.begin() == ft_temp.end());

		print_break("Rbegin and Rend");
		ft_vector_print(ft_v1);
		rit = ft_v1.rbegin();
		erit = ft_v1.rend();
		assert(*ft_v1.rbegin() == 4);
		assert(*(ft_v1.rend() - 1) == 0);
		assert(rit == ft_v1.rbegin());
		assert(erit == ft_v1.rend());

		ft_v1.push_back(5);
		ft_vector_print(ft_v1);
		assert(*ft_v1.rbegin() == 5);
		assert(*(ft_v1.rend() - 1) == 0);
		assert(rit == ++ft_v1.rbegin());
		assert(erit == ft_v1.rend());

		ft_v1.pop_back();
		ft_vector_print(ft_v1);
		assert(*ft_v1.rbegin() == 4);
		assert(*(ft_v1.rend() - 1) == 0);
		assert(rit == ft_v1.rbegin());
		assert(erit == ft_v1.rend());

		ft_vector_print(ft_v1);
		for (int i = 4; rit != ft_v1.rend(); rit++, i--)
		{
			if (i == (int)ft_v1.size() - 1)
				assert(*(ft_v1.rbegin()) == i);
			std::cout << *rit << " " << i << std::endl;
			assert(*rit == i);
		}

		rit = ft_v1.rbegin();
		erit = ft_v1.rend();
		*ft_v1.rbegin() = 6;
		ft_vector_print(ft_v1);
		assert(ft_v1[4] == 6);
		assert(rit == ft_v1.rbegin());
		assert(erit == ft_v1.rend());

		*rit = 4;
		ft_vector_print(ft_v1);
		assert(ft_v1[4] == 4);
		assert(rit == ft_v1.rbegin());
		assert(erit == ft_v1.rend());

		erit = ft_v1.rend();
		*(ft_v1.rend() - 1) = 5;
		ft_vector_print(ft_v1);
		assert(ft_v1[0] == 5);
		assert(rit == ft_v1.rbegin());
		assert(erit == ft_v1.rend());

		erit = (ft_v1.rend() - 1);
		*erit = 0;
		ft_vector_print(ft_v1);
		assert(ft_v1[0] == 0);
		assert(rit == ft_v1.rbegin());
		assert(erit + 1 == ft_v1.rend());

		ft_vector_print(ft_temp);
		assert(ft_temp.rbegin() == ft_temp.rend());

		print_break("Empty");
		ft_vector_print(ft_temp);
		assert(ft_temp.empty() == true);

		ft_vector_print(ft_v1);
		assert(ft_v1.empty() == false);

		ft_temp.push_back(1);
		ft_vector_print(ft_temp);
		assert(ft_temp.empty() == false);
		
		ft_temp.pop_back();
		ft_vector_print(ft_temp);
		assert(ft_temp.empty() == true);

		ft_temp.push_back(1);
		ft_temp.push_back(2);
		ft_vector_print(ft_temp);
		assert(ft_temp.empty() == false);

		ft_temp.clear();
		ft_vector_print(ft_temp);
		assert(ft_temp.empty() == true);

		print_break("Size");
		ft_vector_print(ft_temp);
		assert(ft_temp.size() == 0);
			
		ft_vector_print(ft_v1);
		assert(ft_v1.size() == 5);

		ft_temp.push_back(1);
		ft_vector_print(ft_temp);
		assert(ft_temp.size() == 1);

		ft_temp.pop_back();
		ft_vector_print(ft_temp);
		assert(ft_temp.size() == 0);

		ft_temp.push_back(1);
		ft_temp.push_back(2);
		ft_vector_print(ft_temp);
		assert(ft_temp.size() == 2);

		ft_temp.clear();
		ft_vector_print(ft_temp);
		assert(ft_temp.size() == 0);

		print_break("Max_size");
		ft_vector_print(ft_temp);
		assert(ft_temp.max_size() > 0);
		assert(ft_temp.max_size() == std_temp.max_size());
		assert(ft_v1.max_size() == std_v1.max_size());

		ft_temp.push_back(1);
		ft_vector_print(ft_temp);
		assert(ft_temp.max_size() == std_temp.max_size());

		ft_temp.pop_back();
		ft_vector_print(ft_temp);
		assert(ft_temp.max_size() == std_temp.max_size());

		ft_temp.push_back(1);
		ft_temp.push_back(2);
		ft_vector_print(ft_temp);
		assert(ft_temp.max_size() == std_temp.max_size());
		
		ft_temp.clear();
		ft_vector_print(ft_temp);
		assert(ft_temp.max_size() == std_temp.max_size());

		print_break("Reserve");
		ft_v2.reserve(10);
		std_v2.reserve(10);
		vector_check(ft_v2, std_v2);
		
		ft_v2.reserve(0);
		std_v2.reserve(0);
		vector_check(ft_v2, std_v2);

		try
		{
			ft_v2.reserve(-1);
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }
		try
		{
			ft_v2.reserve(ft_v2.max_size() + 1);
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }

		print_break("Capacity");
		vector_check(ft_cap, std_cap);

		ft_cap.push_back(1);
		std_cap.push_back(1);
		vector_check(ft_cap, std_cap);

		ft_cap.pop_back();
		std_cap.pop_back();
		vector_check(ft_cap, std_cap);

		ft_cap.push_back(1);
		ft_cap.push_back(2);
		std_cap.push_back(1);
		std_cap.push_back(2);
		vector_check(ft_cap, std_cap);

		ft_cap.clear();
		std_cap.clear();
		vector_check(ft_cap, std_cap);

		print_break("Clear");
		ft_v1.clear();
		std_v1.clear();
		vector_check(ft_v1, std_v1);

		ft_v1.assign(std_temp.begin(), std_temp.end());
		std_v1.assign(std_temp.begin(), std_temp.end());
		vector_check(ft_v1, std_v1);
		it = ft_v1.begin();
		ft_v1.clear();
		assert(it == ft_v1.begin());

		ft_clear.clear();
		std_clear.clear();
		vector_check(ft_clear, std_clear);

		print_break("Insert");
		ft_v1.assign(std_temp.begin(), std_temp.end());
		std_v1.assign(std_temp.begin(), std_temp.end());
		ft_v1.insert(ft_v1.begin(), -1);
		std_v1.insert(std_v1.begin(), -1);
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.end(), 5);
		std_v1.insert(std_v1.end(), 5);
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.begin() + 2, 42);
		std_v1.insert(std_v1.begin() + 2, 42);
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.begin() + 3, 5, 10);
		std_v1.insert(std_v1.begin() + 3, 5, 10);
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.begin(), ft_v3.begin(), ft_v3.end());
		std_v1.insert(std_v1.begin(), std_v3.begin(), std_v3.end());
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.end(), ft_v3.begin(), ft_v3.end());
		std_v1.insert(std_v1.end(), std_v3.begin(), std_v3.end());
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.begin(), ft_v1.begin(), ft_v1.end());
		std_v1.insert(std_v1.begin(), std_v1.begin(), std_v1.end());
		vector_check(ft_v1, std_v1);

		ft_v1.insert(ft_v1.end(), ft_v1.begin(), ft_v1.end());
		std_v1.insert(std_v1.end(), std_v1.begin(), std_v1.end());
		vector_check(ft_v1, std_v1);

		print_break("Erase");
		ft_v1.erase(ft_v1.begin());
		std_v1.erase(std_v1.begin());
		vector_check(ft_v1, std_v1);

		ft_v1.erase(ft_v1.begin() + 10);
		std_v1.erase(std_v1.begin() + 10);
		vector_check(ft_v1, std_v1);

		ft_v1.erase(ft_v1.end() - 1);
		std_v1.erase(std_v1.end() - 1);
		vector_check(ft_v1, std_v1);

		ft_v1.erase(ft_v1.end() - 10);
		std_v1.erase(std_v1.end() - 10);
		vector_check(ft_v1, std_v1);

		ft_v1.erase(ft_v1.begin(), ft_v1.begin() + 2);
		std_v1.erase(std_v1.begin(), std_v1.begin() + 2);
		vector_check(ft_v1, std_v1);

		ft_v1.erase(ft_v1.begin() + 10, ft_v1.begin() + 15);
		std_v1.erase(std_v1.begin() + 10, std_v1.begin() + 15);
		vector_check(ft_v1, std_v1);

		ft_v1.erase(ft_v1.end() - 10, ft_v1.end() - 5);
		std_v1.erase(std_v1.end() - 10, std_v1.end() - 5);
		vector_check(ft_v1, std_v1);

		print_break("Push_back");
		ft_v1.push_back(1);
		std_v1.push_back(1);
		vector_check(ft_v1, std_v1);

		ft_v1.push_back(2);
		std_v1.push_back(2);
		vector_check(ft_v1, std_v1);

		print_break("Pop_back");
		ft_v1.pop_back();
		std_v1.pop_back();
		vector_check(ft_v1, std_v1);

		print_break("Resize");
		ft_v1.resize(5);
		std_v1.resize(5);
		vector_check(ft_v1, std_v1);

		ft_v1.resize(10);
		std_v1.resize(10);
		vector_check(ft_v1, std_v1);

		ft_v1.resize(0);
		std_v1.resize(0);
		vector_check(ft_v1, std_v1);

		try
		{
			ft_v1.resize(-1);
			assert(false);
		}
		catch(const std::exception& e) {std::cerr << e.what() << "\n\n";}
		try
		{
			ft_v2.resize(ft_v2.max_size() + 1);
			assert(false);
		}
		catch(const std::exception& e) { std::cerr << e.what() << "\n\n"; }

		print_break("Swap");
		ft_v1.swap(ft_v2);
		std_v1.swap(std_v2);
		vector_check(ft_v1, std_v1);
		vector_check(ft_v2, std_v2);

		ft_v1.swap(ft_v2);
		std_v1.swap(std_v2);
		vector_check(ft_v1, std_v1);
		vector_check(ft_v2, std_v2);

		print_break("Operators");
		ft_v1.assign(std_temp.begin(), std_temp.end());
		std_v1.assign(std_temp.begin(), std_temp.end());
		ft_v2.assign(std_temp.begin(), std_temp.end());
		std_v2.assign(std_temp.begin(), std_temp.end());
		ft_v3.assign(std_temp.begin(), std_temp.end() - 1);
		std_v3.assign(std_temp.begin(), std_temp.end() - 1);

		ft_vector_print(ft_v1);
		ft_vector_print(ft_v2);
		ft_vector_print(ft_v3);
		ft_vector_print(ft_v4);

		assert(ft_v1 == ft_v1);
		assert(ft_v1 == ft_v2);
		assert(!(ft_v1 == ft_v3));
		assert(!(ft_v1 == ft_v4));

		assert(!(ft_v1 != ft_v1));
		assert(!(ft_v1 != ft_v2));
		assert(ft_v1 != ft_v3);
		assert(ft_v1 != ft_v4);

		assert(!(ft_v1 < ft_v1));
		assert(!(ft_v1 < ft_v2));
		assert(!(ft_v1 < ft_v3));
		assert(ft_v1 < ft_v4);

		assert(ft_v1 <= ft_v1);
		assert(ft_v1 <= ft_v2);
		assert(!(ft_v1 <= ft_v3));
		assert(ft_v1 <= ft_v4);

		assert(!(ft_v1 > ft_v1));
		assert(!(ft_v1 > ft_v2));
		assert(ft_v1 > ft_v3);
		assert(!(ft_v1 > ft_v4));

		assert(ft_v1 >= ft_v1);
		assert(ft_v1 >= ft_v2);
		assert(ft_v1 >= ft_v3);
		assert(!(ft_v1 >= ft_v4));

		print_break("Std::swap");
		ft::swap(ft_v1, ft_v3);
		std::swap(std_v1, std_v3);
		vector_check(ft_v1, std_v1);
		vector_check(ft_v3, std_v3);

		ft::swap(ft_v1, ft_v3);
		std::swap(std_v1, std_v3);
		vector_check(ft_v1, std_v1);
		vector_check(ft_v3, std_v3);
	}
	{
		clock_t	start_time, end_time;
		double	ft_elapsed_time, std_elapsed_time;
		int	i;
		print_break("Performance");
		start_time = clock();

		ft::vector<int> 					ft_v1;
		ft::vector<int> 					ft_v2(42);
		ft::vector<int> 					ft_v3(42, 42);
		ft::vector<int> 					ft_v4 = ft_v3;
		ft::vector<int> 					ft_v5(ft_v4.begin(), ft_v4.end());
		ft::vector<int> 					ft_v6(ft_v5);

		ft_v1.assign(42, 42);
		ft_v1.assign(ft_v1.begin(), ft_v1.end());
		ft_v1.get_allocator();
		ft_v1.at(0);
		ft_v1[0];
		ft_v1.front();
		ft_v1.back();
		ft_v1.data();
		ft_v1.begin();
		ft_v1.end();
		ft_v1.rbegin();
		ft_v1.rend();
		ft_v1.empty();
		ft_v1.size();
		ft_v1.max_size();
		ft_v1.reserve(42);
		ft_v1.capacity();
		ft_v1.clear();
		ft_v1.insert(ft_v1.begin(), -1);
		ft_v1.insert(ft_v1.begin(), ft_v2.begin(), ft_v2.end());
		ft_v1.erase(ft_v1.begin());
		ft_v1.erase(ft_v1.begin(), ft_v1.end());
		ft_v1.push_back(42);
		ft_v1.pop_back();
		ft_v1.resize(42);
		ft_v1.swap(ft_v2);
		i = (ft_v1 == ft_v1);
		i = (ft_v1 != ft_v1);
		i = (ft_v1 < ft_v1);
		i = (ft_v1 <= ft_v1);
		i = (ft_v1 > ft_v1);
		i = (ft_v1 >= ft_v1);
		std::swap(ft_v1, ft_v2);
		
		end_time = clock();
		ft_elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << "ft elapsed time: " << std::fixed << std::setprecision(6) << ft_elapsed_time << " seconds" << std::endl;
		start_time = clock();

		std::vector<int> 					std_v1;
		std::vector<int> 					std_v2(42);
		std::vector<int> 					std_v3(42, 42);
		std::vector<int> 					std_v4 = std_v3;
		std::vector<int> 					std_v5(std_v4.begin(), std_v4.end());
		std::vector<int> 					std_v6(std_v5);

		std_v1.assign(42, 42);
		std_v1.assign(std_v1.begin(), std_v1.end());
		std_v1.get_allocator();
		std_v1.at(0);
		std_v1[0];
		std_v1.front();
		std_v1.back();
		std_v1.data();
		std_v1.begin();
		std_v1.end();
		std_v1.rbegin();
		std_v1.rend();
		std_v1.empty();
		std_v1.size();
		std_v1.max_size();
		std_v1.reserve(42);
		std_v1.capacity();
		std_v1.clear();
		std_v1.insert(std_v1.begin(), -1);
		std_v1.insert(std_v1.begin(), std_v2.begin(), std_v2.end());
		std_v1.erase(std_v1.begin());
		std_v1.erase(std_v1.begin(), std_v1.end());
		std_v1.push_back(42);
		std_v1.pop_back();
		std_v1.resize(42);
		std_v1.swap(std_v2);
		i = (std_v1 == std_v1);
		i = (std_v1 != std_v1);
		i = (std_v1 < std_v1);
		i = (std_v1 <= std_v1);
		i = (std_v1 > std_v1);
		i = (std_v1 >= std_v1);
		std::swap(std_v1, std_v2);
		
		end_time = clock();
		std_elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
		std::cout << "std elapsed time: " << std::fixed << std::setprecision(6) << std_elapsed_time << " seconds" << std::endl;
		std::cout << "Slower by: " << ft_elapsed_time / std_elapsed_time << "x times\n" << std::endl; 
		print_break("All test finished: Vector OK");
	}
	return (0);
}
