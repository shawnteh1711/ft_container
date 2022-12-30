/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:49:22 by steh              #+#    #+#             */
/*   Updated: 2022/12/30 17:07:26 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

// swap
// https://cplusplus.com/reference/utility/swap/

namespace ft
{
	template<class T>
	void swap (T& a, T& b)
	{
		T	c(a);
		a = b;
		b = c;
	}
	
} // namespace ft



#endif
