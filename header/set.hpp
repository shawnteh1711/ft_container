/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:50:34 by steh              #+#    #+#             */
/*   Updated: 2023/02/07 22:32:18 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

#include "utils/RBTree.hpp"


// reference: https://en.cppreference.com/w/cpp/container/set
namespace ft
{
	template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
		public:

			typedef Key											key_type;
			typedef key_type									value_type;
			typedef std::size_t									size_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef Compare										key_compare;
			typedef key_compare									value_compare;
			typedef value_type&									reference;
			typedef const value_type&							const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

		private:

			typedef ft::RBTree<value_type, key_compare, value_compare, allocator_type>	tree;
			tree														_rbtree;

		public:

			// typedef typename tree::iterator						iterator;
			// typedef typename tree::const_iterator				const_iterator;
			typedef ft::tree_iterator<value_type>				iterator;
			typedef ft::const_tree_iterator<value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			set();

			explicit set( const Compare& comp, const Allocator& alloc = Allocator() );

			template< class InputIt >
			set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

			set( const set& other );

			set& operator=( const set& other );

			allocator_type get_allocator() const;


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

			void swap( set& other );

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


			

	};
}

#endif
