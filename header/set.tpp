/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:14:50 by steh              #+#    #+#             */
/*   Updated: 2023/02/08 17:44:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
# include "./utils/utility.hpp"


template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>::set() : _rbtree()
{
	return ;
}

template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>::set( const Compare& comp, const Allocator& alloc)
: _rbtree(value_compare(comp), alloc)
{
	return ;
}

template <class Key, class Compare, class Allocator>
template< class InputIt >
ft::set<Key, Compare, Allocator>::set( InputIt first, InputIt last, const Compare& comp , const Allocator& alloc) : _rbtree(value_compare(comp), alloc)
{
	while (first != last)
		insert(*first++);
}

template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>::set( const set& other )
{
	const_iterator		cit;
	value_compare		comp;
	allocator_type		alloc;

	cit = other.begin();
	if (this != &other)
	{
		comp = other.value_comp();
		alloc = other.get_allocator();
		for (; cit != other.end(); ++cit)
			this->insert(*cit);
	}
	return;
}

template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>& ft::set<Key, Compare, Allocator>::operator=( const set& other )
{
	if (this != &other)
		_rbtree = other._rbtree;
	return (*this);
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::allocator_type	
ft::set<Key, Compare, Allocator>::get_allocator() const
{
	return (_rbtree.get_allocator());
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::begin()
{
	return (_rbtree.begin());
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	
ft::set<Key, Compare, Allocator>::begin() const
{
	return (_rbtree.begin());
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::iterator	
ft::set<Key, Compare, Alloc>::end()
{
	return (_rbtree.end());
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_iterator	
ft::set<Key, Compare, Alloc>::end() const
{
	return (_rbtree.end());
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::reverse_iterator ft::set<Key, Compare, Alloc>::rbegin()
{
	return (reverse_iterator(this->end()));
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_reverse_iterator ft::set<Key, Compare, Alloc>::rbegin() const
{
	return (const_reverse_iterator(this->end()));
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::reverse_iterator ft::set<Key, Compare, Alloc>::rend()
{
	return (reverse_iterator(this->begin()));
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::const_reverse_iterator ft::set<Key, Compare, Alloc>::rend() const
{
	return (const_reverse_iterator(this->begin()));
}

template<class Key, class Compare, class Alloc>
bool ft::set<Key, Compare, Alloc>::empty() const
{
	return (_rbtree.empty());
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::size() const
{
	return (_rbtree.size());
}

template<class Key, class Compare, class Alloc>
typename ft::set<Key, Compare, Alloc>::size_type ft::set<Key, Compare, Alloc>::max_size() const
{
	return (_rbtree.max_size());
}

template<class Key, class Compare, class Alloc>
void ft::set<Key, Compare, Alloc>::clear()
{
	return (_rbtree.clear());
}

template <class Key, class Compare, class Allocator>
ft::pair<typename ft::set<Key, Compare, Allocator>::iterator, bool>	
ft::set<Key, Compare, Allocator>::insert( const value_type& value )
{
	return (_rbtree.insert(value));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::insert( iterator pos, const value_type& value )
{
	return (_rbtree.insert(pos, value));
}

template <class Key, class Compare, class Allocator>
template< class InputIt >
void ft::set<Key, Compare, Allocator>::insert( InputIt first, InputIt last )
{
	return (_rbtree.insert(first, last));
}


template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::erase( iterator pos )
{
	return (_rbtree.erase(pos));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::erase( iterator first, iterator last )
{
	return (_rbtree.erase(first, last));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::size_type	
ft::set<Key, Compare, Allocator>::erase( const Key& key )
{
	return (_rbtree.erase(key));
}

template <class Key, class Compare, class Allocator>
void ft::set<Key, Compare, Allocator>::swap( set& other )
{
	return (_rbtree.swap(other._rbtree));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::size_type	
ft::set<Key, Compare, Allocator>::count( const Key& key ) const
{
	return (_rbtree.count(key));
}


template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::find( const Key& key )
{
	return (_rbtree.find(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	
ft::set<Key, Compare, Allocator>::find( const Key& key ) const
{
	return (_rbtree.find(key));
}

template <class Key, class Compare, class Allocator>
ft::pair<typename ft::set<Key, Compare, Allocator>::iterator,
 typename ft::set<Key, Compare, Allocator>::iterator>	
ft::set<Key, Compare, Allocator>::equal_range( const Key& key )
{
	return (_rbtree.equal_range(key));
}

template <class Key, class Compare, class Allocator>
ft::pair<typename ft::set<Key, Compare, Allocator>::const_iterator,
 typename ft::set<Key, Compare, Allocator>::const_iterator>	
ft::set<Key, Compare, Allocator>::equal_range( const Key& key ) const
{
	return (_rbtree.equal_range(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::lower_bound( const Key& key )
{
	return (_rbtree.lower_bound(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	
ft::set<Key, Compare, Allocator>::lower_bound( const Key& key ) const
{
	return (_rbtree.lower_bound(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::iterator	
ft::set<Key, Compare, Allocator>::upper_bound( const Key& key )
{
	return (_rbtree.upper_bound(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::const_iterator	
ft::set<Key, Compare, Allocator>::upper_bound( const Key& key ) const
{
	return (_rbtree.upper_bound(key));
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::key_compare	
ft::set<Key, Compare, Allocator>::key_comp() const
{
	return (_rbtree.key_comp());
}

template <class Key, class Compare, class Allocator>
typename ft::set<Key, Compare, Allocator>::value_compare	
ft::set<Key, Compare, Allocator>::value_comp() const
{
	return (value_compare(_rbtree.value_comp()));
}
