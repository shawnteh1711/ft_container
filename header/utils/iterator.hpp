/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:40:37 by codespace         #+#    #+#             */
/*   Updated: 2023/03/06 18:47:22 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/**
 * https://en.cppreference.com/w/cpp/iterator/iterator_traits
 * https://en.cppreference.com/w/cpp/iterator/reverse_iterator
 */
#include "type_traits.hpp"
#include <iostream>

namespace ft
{
	// Base class
	// iterator_traits - provides uniform interface to the properties of an iterator
	// iter - the iterator type to retrieve properties for
	template <class Iter> struct iterator_traits
	{
		typedef typename Iter::difference_type			difference_type;
		typedef typename Iter::value_type				value_type;
		typedef typename Iter::pointer					pointer;
		typedef typename Iter::reference				reference;
		typedef typename Iter::iterator_category		iterator_category;
	};
	
	// T* specializations class for user-provided types thay may be used as iterators
	template <class T> struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	// const T* specialization class
	template <class T> struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	/* Reverse_iterator class */
	template <class Iter>
	class reverse_iterator : public std::iterator<
		typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference>
	{
		// member types
		public:
			typedef Iter												iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iter>::value_type			value_type;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef typename iterator_traits<Iter>::reference			reference;
		
		// Construct a new iterator adaptor
		// Default constructor (since C++17, constexpr is introduced for more optimization)
		reverse_iterator() {}; 

		// Initialization constructor with X(iterator to adapt)
		explicit reverse_iterator( iterator_type x ) : _current(x)
		{
			// std::cout << "reverse constructor" << std::endl;
		};

		// Initialization constructor with other(iterator adoptor to copy)
		template <class U>
		reverse_iterator(const reverse_iterator<U>& other) : _current(other.base())
		{
			// std::cout << "iterator constructor" << std::endl;
		};

		// Assign another iterator adaptor
		reverse_iterator &operator=(const reverse_iterator& other)
		{
			if (this != &other)
				this->_current = other._current;
			return (*this);
		};

		// Accesses the underlying iterator
		iterator_type base() const
		{
			return (this->_current);
		};

		// Accesses the pointed-to element.
		// Return a reference or pointer to the element previous to current.
		// https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator*
		reference operator*() const
		{
			Iter tmp = _current;
			return (*(--tmp));
		};

		pointer operator->() const
		{
			// return std::addressof(operator*());
			return (&(this->operator*()));
		};

		// Accesses an element by index
		// Returns a reference to the element at the specified relative location
		// that is, base()[-n-1]
		reference operator[] (difference_type n) const
		{
			return (this->base()[-n - 1]);
		};

		// Advances or decrements the iterator
		// Parameters:
		// n - position relative to current location

		// Pre-increments by one (++it)
		// Return *this
		reverse_iterator& operator++()
		{
			_current--;
			return (*this);
		};

		// Pre-decrements by one (--it)
		// Return *this
		reverse_iterator& operator--()
		{
			_current++;
			return (*this);
		};

		// Post-increments by one (it++)
		// Return a copy of *this that was made before the change
		reverse_iterator operator++(int)
		{
			// Create a copy of this iterator.
			// reverse_iterator tmp(*this);
			// Decrement the underlying iterator by one.
			// --current;
			// Return the copy of the iterator.
			// return tmp;
			return (reverse_iterator(_current--));
		};

		// Post-decrements by one (it--)
		// Return a copy of *this that was made before the change
		reverse_iterator operator--(int)
		{
			return (reverse_iterator(_current++));
		};

		// Returns an iterator which is advanced by n position (it + n)
		// Return reverse_iterator(base() - n)
		reverse_iterator operator+(difference_type n) const
		{
			return (reverse_iterator(_current - n));
		};

		// Returns an iterator which is advanced by -n position (it - n)
		// Return reverse_iterator(base() + n)
		reverse_iterator operator-(difference_type n) const
		{
			return (reverse_iterator(_current + n));
		};

		// Advances the iterator by n positions (it += n)
		// Return *this
		reverse_iterator& operator+=(difference_type n)
		{
			_current -= n;
			return (*this);
		};

		// Advances the iterator by -n positions (it -= n)
		// Return *this
		reverse_iterator& operator-=(difference_type n)
		{
			_current += n;
			return (*this);
		};

		protected:
			Iter	_current;
	};

	// Non-member functions
	// Parameter:
	//	lhs, rhs - iterator adoptors to compare
	// reference: https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator_cmp
	template<class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iterator1, class Iterator2>
	bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	// Spaceship operator not cover (since C++20)

	// Advances the iterator
	// Returns the iterator it incremented by n
	// Parameters
	//	n - number of positions to increment the iterator
	//	it - the iterator adaptor to increment
	template <class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n,
									const reverse_iterator<Iter>& it)
	{
		return (reverse_iterator<Iter>(it.base() - n));
	}

	// Computes the distance
	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs,
	const reverse_iterator<Iterator2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
}

#endif
