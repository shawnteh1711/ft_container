/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2023/01/05 20:00:52 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP
#include <iostream>
#include "../vector.hpp"
# define GRN "\033[0;32m"
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
			std::cerr << error_msg << std::endl;
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
}

#endif
