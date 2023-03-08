/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2023/03/08 13:21:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP
#include <iostream>
#include <memory>
#include <string>
// #include <stack>
// #include <map>
// #include <set>
// #include "../vector.hpp"
// #include "../stack.hpp"
// #include "../map.hpp"
// #include "../set.hpp"
// # define RED "\033[0;31m"
// # define GRN "\033[0;32m"
// # define BLU "\033[1;34m"
// # define RST "\033[0m"

namespace ft
{
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

	template <typename InputIterator, typename ForwardIterator>
	ForwardIterator uninitialized_copy(InputIterator first, InputIterator last, ForwardIterator dest)
	{
		ForwardIterator current = dest;

		for (; first != last; ++first, ++current)
		{
			*current = *first;
		}
		return (current);
	}

	// https://en.cppreference.com/w/cpp/memory/uninitialized_copy
	// template <typename InputIterator, typename ForwardIterator>
	// ForwardIterator uninitialized_copy( InputIterator first, InputIterator last, ForwardIterator result)
	// {
	// 	typedef typename ft::iterator_traits<ForwardIterator>::value_type value_type;
	// 	ForwardIterator current = result;
	// 	try 
	// 	{
	// 		for (; first != last; ++first, (void)++current)
	// 		{
	// 			std::cout << "first:" << *first << std::endl;
	// 			std::cout << "last:" << *last << std::endl;
	// 			std::cout << "curre:" << *current << std::endl;
	// 			::new (static_cast<void*>(&*current)) value_type(*first);
	// 			// new (static_cast<void*>(std::addressof(*current))) value_type(*first);
	// 		}
	// 		std::cout << "current" << *current << std::endl;
	// 		return (current);
	// 	}
	// 	catch (...) 
	// 	{
	// 		for (; result != current; ++result)
	// 		{
	// 			result->~value_type();
	// 		}
	// 		throw;
	// 	}
	// }
}

#endif
