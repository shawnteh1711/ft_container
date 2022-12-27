/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:43:01 by codespace         #+#    #+#             */
/*   Updated: 2022/12/27 21:08:02 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <typename Iter, typename Container>
	class vector_iterator
	{
		public:
			typedef Iter										iterator_type;
			typedef typename iterator_traits<Iter>::pointer		pointer;

		// constructor accept pointer
		vector_iterator(pointer ptr): _ptr(ptr) {}
		// vector_iterator(iterator_type &other): _ptr(other._ptr) {}

		protected:
			pointer	_ptr;

	};
}

# endif
