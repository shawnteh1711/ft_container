/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2023/01/04 16:01:41 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP
#include <iostream>
#include "../vector.hpp"

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

	template <typename T>
	void	test_assert(const T& value, const T& expected, const char* error_msg, const char *success)
	{
		if (value != expected)
		{
			std::cerr << error_msg << std::endl;
			assert(false);
		}
		std::cout << success << std::endl;
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

	template<typename T>
	void print_vector(const ft::vector<T>& v)
	{
		// ft::print_functor<T> printer;
		// std::for_each(v.begin(), v.end(), printer);
		std::cout << "[";
		std::for_each(v.begin(), v.end(), print_functor<T>());
		std::cout << "]" << std::endl;
	}

	template<typename T>
	void print_vector(const std::vector<T>& v)
	{
		// ft::print_functor<T> printer;
		// std::for_each(v.begin(), v.end(), printer);
		std::cout << "[";
		std::for_each(v.begin(), v.end(), print_functor<T>());
		std::cout << "]" << std::endl;
	}
}

#endif
