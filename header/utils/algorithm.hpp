/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:49:22 by steh              #+#    #+#             */
/*   Updated: 2022/12/31 20:11:46 by steh             ###   ########.fr       */
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


	// equal
	// return true if range [first1, last1] is equal to range [first2, first2 + (last1 - first1)] and false otherwise


	// equal using  >
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1,
				InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
				return (false);
		}
		return (true);
	}


	// equal using binary predicate.
	// binary predicate is a function that takes two arguments and returns a boolean value indicating whether some condition is true or false.
	// https://en.cppreference.com/w/cpp/algorithm/equal
	template< class InputIt1,class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1,
				InputIt1 last1,
				InputIt2 first2,
				BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!p(*first1, *first2))
				return (false);
		}
		return (true);
	}

	// lexicographical_compare
	// Usually used in container to sort character data
	// Checks if the first range [first1, last1] is lexicographically (in alphabetical order, "c" comes before "d") less than the second range [first2, last2]
	// Elements are compared using < or comp function
	// Type requirements: InputIt1, InputIt2, ForwardIt1, ForwardIt2
	// return value: true if first range is lexicographically less than the
	// second, otherwise false
	// https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare

	// Elements compare using "<"
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2 )
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}

	// Elements compare using comp function
	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2, Compare comp )
	{
		for (; (first1 != last2) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1 && first2 != last2);
	}
	
} // namespace ft



#endif
