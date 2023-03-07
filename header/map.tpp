/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:43:02 by steh              #+#    #+#             */
/*   Updated: 2023/03/07 19:59:33 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "map.hpp"
# include "./utils/utility.hpp"

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map() : _rbtree()
{
	return ;
}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map(const Compare& comp, const Alloc& alloc)
: _rbtree(value_compare(comp), alloc)
{
	// _rbtree(value_compare(comp), alloc);
	return ;
}

template<class Key, class T, class Compare, class Alloc>
template< class InputIt >
ft::map<Key, T, Compare, Alloc>::map( InputIt first, InputIt last,
	const Compare& comp, const Alloc& alloc) : _rbtree(value_compare(comp), alloc)
{
	while (first != last)
		insert(*first++);
}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::map( const map& other )
{
	// std::cout << "copyyyyyyyyyyyyyy" << std::endl;
	// const_iterator		cit;
	// value_compare		comp;
	// allocator_type		alloc;

	// cit = other.begin();
	// if (this != &other)
	// {
	// 	comp = other.value_comp();
	// 	alloc = other.get_allocator();
	// 	for (; cit != other.end(); ++cit)
	// 		this->insert(*cit);
	// }
	// return;
	// if (this == &other)
	// 	return (*this);
	// this->_rbtree = other._rbtree;
	// return (*this);
	_rbtree = other._rbtree;
}

template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>::~map()
{
	return ;
}


template<class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator=( const map& other )
{
	// std::cout << "operatorrrrrr" << std::endl;

	if (this != &other)
		_rbtree = other._rbtree;
	return (*this);
}


template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::allocator_type	
ft::map<Key, T, Compare, Alloc>::get_allocator() const
{
	return (_rbtree.get_allocator());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_value&	
ft::map<Key, T, Compare, Alloc>::at( const Key& key )
{
	iterator	it;

	it = this->find(key);
	if (it == this->end())
		throw (std::out_of_range("Map out of range"));
	return (it->second);
}


template<class Key, class T, class Compare, class Alloc>
const typename ft::map<Key, T, Compare, Alloc>::mapped_value&	
ft::map<Key, T, Compare, Alloc>::at( const Key& key ) const
{
	const_iterator	it;

	it = this->find(key);
	if (it == this->end())
		throw (std::out_of_range("Map out of range"));
	return (it->second);
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::mapped_value&	
ft::map<Key, T, Compare, Alloc>::operator[]( const Key& key )
{
	return (insert(ft::make_pair(key, mapped_value())).first->second);
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::begin()
{
	return (_rbtree.begin());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::begin() const
{
	return (_rbtree.begin());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::end()
{
	return (_rbtree.end());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator ft::map<Key, T, Compare, Alloc>::end() const
{
	return (_rbtree.end());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin()
{
	return (reverse_iterator(this->end()));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rbegin() const
{
	return (const_reverse_iterator(this->end()));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::reverse_iterator ft::map<Key, T, Compare, Alloc>::rend()
{
	return (reverse_iterator(this->begin()));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_reverse_iterator ft::map<Key, T, Compare, Alloc>::rend() const
{
	return (const_reverse_iterator(this->begin()));
}

template<class Key, class T, class Compare, class Alloc>
bool ft::map<Key, T, Compare, Alloc>::empty() const
{
	return (_rbtree.empty());
}


template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type	
ft::map<Key, T, Compare, Alloc>::size() const
{
	return (_rbtree.size());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::max_size() const
{
	return (_rbtree.max_size());
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool>	
ft::map<Key, T, Compare, Alloc>::insert( const value_type& value )
{
	return (_rbtree.insert(value));
}

template<class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::clear()
{
	return (_rbtree.clear());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::insert( iterator pos, const value_type& value )
{
	return (_rbtree.insert(pos, value));
}

template<class Key, class T, class Compare, class Alloc>
template< class InputIt >
void ft::map<Key, T, Compare, Alloc>::insert( InputIt first, InputIt last )
{
	return (_rbtree.insert(first, last));
}


template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator ft::map<Key, T, Compare, Alloc>::erase( iterator pos )
{
	return (_rbtree.erase(pos));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator	
ft::map<Key, T, Compare, Alloc>::erase( iterator first, iterator last )
{
	return (_rbtree.erase(first, last));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase( const Key& key )
{
	return (_rbtree.erase(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
void ft::map<Key, T, Compare, Alloc>::swap( map& other )
{
	return (_rbtree.swap(other._rbtree));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::size_type 
ft::map<Key, T, Compare, Alloc>::count( const Key& key ) const
{
	return (_rbtree.count(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator 
ft::map<Key, T, Compare, Alloc>::find( const Key& key )
{
	return (_rbtree.find(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator 
ft::map<Key, T, Compare, Alloc>::find( const Key& key ) const
{
	return (_rbtree.find(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator,
typename ft::map<Key, T, Compare, Alloc>::iterator> 
ft::map<Key, T, Compare, Alloc>::equal_range( const Key& key )
{
	return (_rbtree.equal_range(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
ft::pair<typename ft::map<Key, T, Compare, Alloc>::const_iterator ,
typename ft::map<Key, T, Compare, Alloc>::const_iterator > 
ft::map<Key, T, Compare, Alloc>::equal_range( const Key& key ) const
{
	return (_rbtree.equal_range(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator 
ft::map<Key, T, Compare, Alloc>::lower_bound( const Key& key )
{
	return (_rbtree.lower_bound(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator 
ft::map<Key, T, Compare, Alloc>::lower_bound( const Key& key ) const
{
	return (_rbtree.lower_bound(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::iterator 
ft::map<Key, T, Compare, Alloc>::upper_bound( const Key& key )
{
	return (_rbtree.upper_bound(value_type(key, mapped_value())));
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::const_iterator 
ft::map<Key, T, Compare, Alloc>::upper_bound( const Key& key ) const
{
	return (_rbtree.upper_bound(value_type(key, mapped_value())));
}

// Observer
template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::key_compare	
ft::map<Key, T, Compare, Alloc>::key_comp() const
{
	return (_rbtree.key_comp());
}

template<class Key, class T, class Compare, class Alloc>
typename ft::map<Key, T, Compare, Alloc>::value_compare	
ft::map<Key, T, Compare, Alloc>::value_comp() const
{
	return (value_compare(_rbtree.value_comp()));
}
