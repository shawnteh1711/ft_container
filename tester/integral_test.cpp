/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:41 by steh              #+#    #+#             */
/*   Updated: 2022/12/30 14:00:16 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include "../header/utils/type_traits.hpp"

void	is_integral_test(void)
{
	// Test 1: Check that is_integral<int> if true
	// decltype(t) is used to determine the type of variable
	int x = 0;
	assert(ft::is_integral<decltype(x)>::value == true);

	// Test 2: Check that is_integral<double> is false
	double x2 = 0.0;
	assert(ft::is_integral<decltype(x2)>::value == false);

	// Test 3: Check that is_integral<bool> if true
	bool x3 = false;
	assert(ft::is_integral<decltype(x3)>::value == true);
}
