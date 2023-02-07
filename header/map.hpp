/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:43:02 by steh              #+#    #+#             */
/*   Updated: 2023/02/07 19:10:01 by steh             ###   ########.fr       */
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
			typedef Key														key_type;
			typedef T														mapped_value;
			typedef ft::pair<const key_type, mapped_value>					value_type;
			typedef std::size_t												size_type;
			// typedef std::ptrdiff_t										difference_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef typename allocator_type::difference_type				difference_type;
			typedef value_type& 											reference;
			typedef const value_type& 										const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::tree_iterator<value_type>							iterator;
			typedef const_tree_iterator<value_type>							const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;


			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				protected:
					key_compare	_comp;
				
				public:
					typedef bool		result_type;
					typedef value_type	first_argument_type;
					typedef value_type	second_argument_type;

					value_compare() {};
					value_compare(const key_compare& c) : _comp(c) {};
					value_compare& operator=(const value_compare& other)
					{
						if (this != &other)
							_comp = other._comp;
						return (*this);
					}
					bool	operator()(const value_type& lhs, const value_type& rhs) const
					{
						if (_comp(lhs.first, rhs.first))
							return (true);
						else if (_comp(rhs.first, lhs.first))
							return (false);
						else
							return (false); //equal keys
					}
			};

			// typedef ft::RBTree<value_type, value_compare, key_compare, allocator_type>	tree;
			typedef ft::RBTree<value_type, key_compare, value_compare, allocator_type>	tree;
			// typedef typename tree::iterator												iterator;
			// typedef typename tree::const_iterator										const_iterator;

			
			map();

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
	
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			map( const map& other );

			~map();
			
			map& operator=( const map& other );

			allocator_type get_allocator() const;

			// Element access
			mapped_value& at( const Key& key );

			const mapped_value& at( const Key& key ) const;

			mapped_value& operator[]( const Key& key );

			// Iterators
			iterator begin();

			const_iterator begin() const;

			iterator end();

			const_iterator end() const;

			reverse_iterator rbegin();

			const_reverse_iterator rbegin() const;

			reverse_iterator rend();

			const_reverse_iterator rend() const;

			// Capacity
			bool empty() const;

			size_type size() const;
			
			size_type max_size() const;

			// Modifiers

			void clear();

			ft::pair<iterator, bool> insert( const value_type& value );

			iterator insert( iterator pos, const value_type& value );

			template< class InputIt >
			void insert( InputIt first, InputIt last );

			iterator erase( iterator pos );

			iterator erase( iterator first, iterator last );

			size_type erase( const Key& key );

			void swap( map& other );

			// Lookup
			size_type count( const Key& key ) const;

			iterator find( const Key& key );

			const_iterator find( const Key& key ) const;

			ft::pair<iterator,iterator> equal_range( const Key& key );

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

			iterator lower_bound( const Key& key );

			const_iterator lower_bound( const Key& key ) const;

			iterator upper_bound( const Key& key );

			const_iterator upper_bound( const Key& key ) const;

			// Observer
			key_compare key_comp() const;
	
			value_compare value_comp() const;

		private:
			tree _rbtree;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs == rhs));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(rhs < lhs));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
					const map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(lhs < rhs));
	}
	
	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs,
			map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
}

# endif
