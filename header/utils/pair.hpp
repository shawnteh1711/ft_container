/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:31:21 by steh              #+#    #+#             */
/*   Updated: 2022/12/30 18:41:45 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include "algorithm.hpp" // for ft::swap
// https://en.cppreference.com/w/cpp/utility/pair
// https://cplusplus.com/reference/utility/pair/pair/

namespace ft
{
	// pair is a class template that provides a way to store two
	// heterogeneous objects as a single unit.
	template <class T1, class T2>
	struct pair
	{
		// Member types
		typedef T1	first_type;
		typedef T2	second_type;

		// Member objects
		first_type		first;
		second_type		second;

		// default constructor
		pair() : first(first_type()), second(second_type()) {};

		// initialization constructor
		pair(const first_type& a, const second_type& b): first(a), second(b) {};

		// copy constructor
		template <class U, class V>
		pair (const pair<U, V>&pr) : first(pr.first), second(pr.second) {};

		// pair::operator=
		pair& operator=(const pair& pr)
		{
			if (this == &pr)
				return (*this);
			first = pr.first;
			second = pr.second;
			return (*this);
		};

		// pair::swap
		// https://cplusplus.com/reference/utility/pair/swap/
		void swap(ft::pair<T1, T2>& pr)
		{
			ft::swap(first, pr.first);
			ft::swap(second, pr.second);
		}
	};

	// relational operators
	// https://cplusplus.com/reference/utility/pair/operators/
	template<class T1, class T2>
	bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.second && lhs.first == rhs.second);
	}

	template<class T1, class T2>
	bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2>
	bool operator< (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template<class T1, class T2>
	bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(rhs<lhs));
	}

	template<class T1, class T2>
	bool operator> (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs<lhs);
	}

	template<class T1, class T2>
	bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs<rhs));
	}

	// make_pair
	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (ft::pair<T1, T2>(t, u));
	}



} // namespace ft

# endif
