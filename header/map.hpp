/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:43:02 by steh              #+#    #+#             */
/*   Updated: 2023/01/17 21:34:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional> // std::less
#include "./utils/pair.hpp"
#include "./utils/iterator.hpp"
#include "./utils/RBTree.hpp"
#include "./utils/tree_iterator.hpp"

// https://en.cppreference.com/w/cpp/container/map

// key_type	Key
// mapped_type	T
// value_type	std::pair<const Key, T>
// size_type	Unsigned integer type (usually std::size_t)
// difference_type	Signed integer type (usually std::ptrdiff_t)
// key_compare	Compare
// allocator_type	Allocator
// reference	value_type&
// const_reference	const value_type&
// pointer	 Allocator::pointer	(until C++11)	std::allocator_traits<Allocator>::pointer	(since C++11) 
// const_pointer	 Allocator::const_pointer	(until C++11)	std::allocator_traits<Allocator>::const_pointer	(since C++11) 
// iterator	LegacyBidirectionalIterator to value_type
// const_iterator	LegacyBidirectionalIterator to const value_type
// reverse_iterator	std::reverse_iterator<iterator>
// const_reverse_iterator	std::reverse_iterator<const_iterator>
// node_type (since C++17)	a specialization of node handle representing a container node
namespace ft
{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator =  std::allocator<ft::pair<const Key, T> > > 
	class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_value;
			typedef ft::pair<const key_type, mapped_value>		value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference 			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type 			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename ft::tree_iterator<key_type, mapped_value>												 iterator;
			typedef typename ft::tree_iterator					const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		// you mean
			private:
				_base RBTree // can create RBTtree class here when ur map class is constructed. 
				// then iterator here to point a node from RBTree class here. 
				// how the iterator point to tree
				// did u done the vector?
				// i need to create a map_iterator , with protected Node*
				
		

	};
	
}

# endif
