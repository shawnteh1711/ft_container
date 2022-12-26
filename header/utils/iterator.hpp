/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:40:37 by codespace         #+#    #+#             */
/*   Updated: 2022/12/26 12:47:00 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/**
 * https://en.cppreference.com/w/cpp/iterator/iterator_traits
 * https://en.cppreference.com/w/cpp/iterator/reverse_iterator
 */

namespace ft
{
	template <class Iter> struct iterator_traits
	{
		typedef typename Iter::difference_type	difference_type;
	};

	/* Reverse_iterator class */
	template <class Iter>
	class reverse_iterator : public std::iterator<
		typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::reference,
		typename iterator_traits<Iter>::pointer
		>
	{
		public:
				typedef Iter		iterator_type;
		
		reverse_iterator() {};
	};
}

#endif
