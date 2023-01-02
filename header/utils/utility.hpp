/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:19:58 by codespace         #+#    #+#             */
/*   Updated: 2023/01/02 20:15:51 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP
#include <iostream>

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
		return size;
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
}

#endif
