/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2023/02/22 15:38:11 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include "../vector.hpp"
#include "../stack.hpp"
#include "../map.hpp"
#include "../set.hpp"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"


namespace ft
{

	// template <typename T, typename Alloc>
	// typename ft::vector<T, Alloc>::difference_type
	// distance2(ft::vector_iterator<T, ft::vector<T, Alloc> > first, ft::vector_iterator<T, ft::vector<T, Alloc> > last)
	// {
	// 	return last.base() - first.base();
	// }

	template <typename T>
	void	test_assert(const T& value, const T& expected, const char* error_msg, const char *success)
	{
		if (value != expected)
		{
			std::cerr << RED << error_msg << std::endl;
			assert(false);
		}
		std::cout << GRN << success << RST << std::endl;
	}

	// A functor is a type of object that behaves like a function. 
	// A print_functor is a specific type of functor that is designed to print the value of some object.

	template<typename T>
	struct	print_functor
	{
		void	operator() (const T& value)
		{			
			std::cout << " " << value;
		}
	};

	// for ft::vector
	template<typename T>
	void print_vector(const ft::vector<T>& v)
	{
		// ft::print_functor<T> printer;
		// std::for_each(v.begin(), v.end(), printer);
		std::cout << "[";
		std::for_each(v.begin(), v.end(), print_functor<T>());
		std::cout << " ]" << std::endl;
	}

	// for ft::stack
	template<typename T>
	void print_stack(const ft::stack<T>& v)
	{
		ft::stack<T>	temp(v); // create a copy of the input stack
	
		std::cout << "[ ";
		while (!temp.empty())    
		{
			std::cout << temp.top() << " ";
			temp.pop();
		}
		std::cout << " ]" << std::endl;
	}

	// for ft::stack
	template<typename T>
	void print_stack(const std::stack<T>& sv)
	{
		std::stack<T> temp(sv); // create a copy of the input stack
		std::cout << "[ ";
		while (!temp.empty())
		{
			std::cout << temp.top() << " ";
			temp.pop();
		}
		std::cout << " ]" << std::endl;
	}

	// for std::vector
	template<typename T>
	void print_vector(const std::vector<T>& v)
	{
		// ft::print_functor<T> printer;
		// std::for_each(v.begin(), v.end(), printer);
		std::cout << "[";
		std::for_each(v.begin(), v.end(), print_functor<T>());
		std::cout << " ]" << std::endl;
	}

	template<typename T, typename U>
	T as(U value)
	{
		return (static_cast<T>(value));
	}

	

	template <typename T>
	void	vector_check(ft::vector<T> const &v, std::vector<T> const &sv)
	{
		std::cout << "After operation" << std::endl;
		std::cout << "My container: ";
		ft::print_vector(v);
		std::cout << "Std container: ";
		ft::print_vector(sv);
		// ft::test_assert(*v.begin(), *sv.begin(), "Begin incorrect", "Begin Passed");
		// ft::test_assert(*(v.end() - 1), *(sv.end() - 1), "End incorrect", "End Passed");
		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Size Passed");
		ft::test_assert(v.capacity(), sv.capacity(), "Capacity incorrect", "Capacity Passed");
		ft::test_assert(v.empty(), sv.empty(), "Empty incorrect", "Empty Passed");
		for (size_t i = 0; i < v.size(); i++)
			assert(v[i] == sv[i]);
		std::cout << GRN << "All Elements passed" << RST << std::endl;
		std::cout << std::endl;
	}

	template <typename T>
	void	stack_check(ft::stack<T> const &v, std::stack<T> const &sv)
	{
		(void)v;
		(void)sv;
		std::cout << "After operation" << std::endl;
		std::cout << "My container: ";
		ft::print_stack(v);
		std::cout << "Std container: ";
		ft::print_stack(sv);
		ft::test_assert(v.size(), sv.size(), "Size incorrect", "Size Passed");
		ft::test_assert(v.empty(), sv.empty(), "Empty incorrect", "Empty Passed");
		if (!v.empty())
			ft::test_assert(v.top(), sv.top(), "Top incorrect", "Top Passed");
		ft::stack<T> temp_v = v;
		std::stack<T> temp_sv = sv;
		while (!temp_v.empty())
		{
			T my_val = temp_v.top();
			temp_v.pop();
			T std_val = temp_sv.top();
			temp_sv.pop();
			assert(my_val == std_val);
		}
		std::cout << GRN << "All Elements passed" << RST << std::endl;
		std::cout << std::endl;
	}

	void	print_headers(std::string msg)
	{
		int	len;
		int num_dashes;

		len = msg.length();
		num_dashes = (80 - len) / 2;
		for (int i = 0; i < num_dashes; i++)
			std::cout << BLU << "-";
		std::cout << " " << msg;
		for (int i = 0; i < num_dashes; i++)
			std::cout << BLU << "-" << RST;
		std::cout << "\n";
	}

	template<typename T>
	struct	print_map_functor
	{
		void	operator() (const T& value)
		{			
			std::cout << " " << value.first;
			std::cout << " " << value.second;
		}
	};


	template<typename Key, typename T>
	void print_map(const ft::map<Key, T>& map)
	{
		std::cout << "[	";
		for (typename ft::map<Key, T>::const_iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << (*it).first << " :" << (*it).second << "\t";
		}
		std::cout << " ]" << std::endl;
	}

	template<typename Key, typename T>
	void print_map(const std::map<Key, T>& map)
	{
		std::cout << "[	";
		for (typename std::map<Key, T>::const_iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << (*it).first << " :" << (*it).second << "\t";
		}
		std::cout << " ]" << std::endl;
	}

	template<typename Key, typename T>
	void	map_check(ft::map<Key, T> const &map, std::map<Key, T> const &smap)
	{
		std::cout << "After operation" << std::endl;
		std::cout << "My container : ";
		ft::print_map(map);
		std::cout << "Std container: ";
		ft::print_map(smap);
		ft::test_assert(map.size(), smap.size(), "Size incorrect", "Size Passed");
		ft::test_assert(map.empty(), smap.empty(), "Empty incorrect", "Empty Passed");

		typename ft::map<Key, T>::const_iterator	it = map.begin();
		typename std::map<Key, T>::const_iterator	sit;
		for (sit = smap.begin(); sit != smap.end(); sit++, it++)
		{
			assert(it->first == sit->first);
			assert(it->second == sit->second);
			assert(map.at(it->first) == smap.at(sit->first));
			assert(map.count(it->first) == smap.count(sit->first));
			assert(map.empty() == smap.empty());
			assert(map.get_allocator() == smap.get_allocator());
			// std::cout<<"map max_size:"<<map.max_size()<<std::endl;
			// std::cout<<"smap max_size:"<<smap.max_size()<<std::endl;
			// assert(map.max_size() == smap.max_size());
			assert(map.size() == smap.size());
		}
		std::cout << GRN << "All Elements passed" << RST << std::endl;
		std::cout << std::endl;
	}

	template<typename Key>
	void print_set(const ft::set<Key>& set)
	{
		std::cout << "[	";
		for (typename ft::set<Key>::const_iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << (*it) << "\t";
		}
		std::cout << " ]" << std::endl;
	}

	template<typename Key>
	void print_set(const std::set<Key>& set)
	{
		std::cout << "[	";
		for (typename std::set<Key>::const_iterator it = set.begin(); it != set.end(); it++)
		{
			std::cout << (*it) << "\t";
		}
		std::cout << " ]" << std::endl;
	}

	template<typename Key>
	void	set_check(ft::set<Key> const &set, std::set<Key> const &sset)
	{
		std::cout << "After operation" << std::endl;
		std::cout << "My container : ";
		ft::print_set(set);
		std::cout << "Std container: ";
		ft::print_set(sset);
		ft::test_assert(set.size(), sset.size(), "Size incorrect", "Size Passed");
		ft::test_assert(set.empty(), sset.empty(), "Empty incorrect", "Empty Passed");

		typename ft::set<Key>::const_iterator	it = set.begin();
		typename std::set<Key>::const_iterator	sit;
		for (sit = sset.begin(); sit != sset.end(); sit++, it++)
		{
			assert(*it == *sit);
			assert(set.count(*it) == sset.count(*sit));
			assert(set.empty() == sset.empty());
			assert(set.get_allocator() == sset.get_allocator());
			// std::cout<<"set max_size:"<<set.max_size()<<std::endl;
			// std::cout<<"sset max_size:"<<sset.max_size()<<std::endl;
			// assert(set.max_size() == sset.max_size());
			assert(set.size() == sset.size());
		}
		std::cout << GRN << "All Elements passed" << RST << std::endl;
		std::cout << std::endl;
	}

}

#endif
