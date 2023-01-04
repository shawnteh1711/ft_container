/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:08:21 by codespace         #+#    #+#             */
/*   Updated: 2023/01/04 16:03:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // for allocator
# include <cstddef> //size_t
# include <stdio.h>
# include <new>
# include <iterator>
# include "./utils/vector_iterator.hpp"
# include "./utils/type_traits.hpp"
# include "./utils/pair.hpp"


/**
 * @brief https://en.cppreference.com/w/cpp/container/vector
 * 
 */

namespace ft 
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		
		public:
			// Member types
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef std::size_t													size_type;
			typedef std::ptrdiff_t												difference_type;
			typedef value_type&													reference;
			typedef const value_type&											const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef vector_iterator<pointer, vector>							iterator;
			typedef vector_iterator<const_pointer, vector>						const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

			private:

				allocator_type		_alloc;
				size_type			_size;
				size_type			_capacity;
				T*					_data;
				pointer				_start;
				pointer				_end;

			public:
				// Member Function: Constructor

				// Default constructor. Constructs an empty container with a default-constructed allocator.
				vector();

				// Constructs an empty container with the given allocator alloc
				explicit vector(const allocator_type& alloc);

				// Constructs the container with count copies of elements with value value.
				explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type());

				// Constructs the container with the contents of the range [first, last).
				template <class InputIt>
				vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type* = NULL);

				// Copy constructor
				vector(const vector& x);
				
				// Member Function: Destructor
				~vector();

				// Member Function: Operator=
				vector& operator=(const vector &other);

				// Member Function: Assign
				// Replaces the contents with count copies of value's value
				// count - the new size of container
				// value - the value to initialize elements of the container with
				void assign(size_type count, const T& value);

				// Replaces the contents with copies of those in the rage [first, last]. The behaviour is undefined if either argument is an iterator *this.
				template<class InputIt>
				void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);

				// Member Function: Get_allocator
				// Returns the allocator associated with the container.
				allocator_type get_allocator() const;

				// Element access
				// Element access: at
				// Returns a reference to element at specific locoation pos with bounds checking. If the pos is not within the range of container, an exception of type std::out_of_range is throw.
				reference at(size_type pos);

				const_reference at(size_type pos) const;
				
				// Element access: operator []
				reference operator[](size_type index);
				
				const_reference operator[](size_type index) const;

				// Element access: front
				reference front();

				const_reference front() const;

				// Element access: back
				reference back();

				const_reference back() const;

				// Element access: data
				value_type* data();
				
				const value_type* data() const;
				// Iterators

				// Iterators:begin - return iterator to beginning
				// vector_iterator need to have default constructor
				// that accept the pointer
				iterator begin();
				
				const_iterator begin() const;

				// Iterators:end - return iterator to end
				iterator end();

				const_iterator end() const;

				// Iterators: rbegin - returns a reverse iterator to the beginning
				reverse_iterator rbegin();

				const_reverse_iterator rbegin() const;

				// Iterators: rend - returns a reverse iterator to the end
				reverse_iterator rend();

				const_reverse_iterator rend() const;

				// Capacity	

				// Capacity: empty
				bool empty() const;

				// Capacity: size
				size_type size() const;

				// Capacity: max_size
				size_type max_size(void) const;

				// Capacity: reserve
				void reserve(size_type new_cap);

				// Capacity: capacity
				size_type capacity() const;

				// Capacity: shrink_to_fit
				void shrink_to_fit();

				// Modifiers

				// Modifiers: clear
				void clear();
				
				// Modifiers: insert
				// Insert value before pos
				iterator insert(const_iterator pos, const value_type& value);

				iterator insert(const_iterator pos, value_type& value);
				// Insert count copies of the value before pos
				iterator insert(const_iterator pos, size_type count, const T& value );

				// Insert elements from range [first, last) before pos
				template <class InputIt>
				iterator insert(const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);

				// Modifiers: erase

				// Modifiers: push_back
				void	push_back(const T& value);

				// Modifier: pop_back
				void	pop_back();

				// Modifier: resize
				void	resize(size_type count);
	
				void	resize(size_type count, const value_type& value);

				// Modifier: swap
				void	swap(vector& other);
	};
	// Non-member functions
}

#endif
