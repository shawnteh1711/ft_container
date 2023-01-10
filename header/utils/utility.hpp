/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2023/01/10 22:37:24 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP
#include <iostream>
#include <string>
#include <stack>
#include "../vector.hpp"
#include "../stack.hpp"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"

namespace ft
{
	// class pair
	// {
	// 	public:
	// 	/*Constructor*/
	// 		pair()
	// 		{
	// 			std::cout << "pair construct" << std::endl;
	// 		}
	// 	private:
	// };

	template <class InputIt>
	size_t distance(InputIt first, InputIt last)
	{
		size_t	size;
		size = 0;
		for (; first != last; ++first)
		{
			++size;
		}
		return (size);
	}

	template <typename T, typename Alloc>
	typename ft::vector<T, Alloc>::difference_type
	distance2(ft::vector_iterator<T, ft::vector<T, Alloc> > first, ft::vector_iterator<T, ft::vector<T, Alloc> > last)
	{
		return last.base() - first.base();
	}

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
		ft::stack<T> temp(v); // create a copy of the input stack
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
	void print_stack(const std::stack<T>& v)
	{
		std::stack<T> temp(v); // create a copy of the input stack
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

	template <typename InputIterator, typename ForwardIterator>
	ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator dest)
	{
		ForwardIterator current = dest;

		for (; first != last; ++first, ++current) {
			*current = *first;
		}
		return (current);
	}
}

#endif
