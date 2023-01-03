/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:08:21 by codespace         #+#    #+#             */
/*   Updated: 2023/01/02 16:04:54 by steh             ###   ########.fr       */
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
# include "./utils/algorithm.hpp"
# include "./utils/pair.hpp"
# include "./utils/utility.hpp"

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
			typedef vector_iterator<const pointer, vector>						const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

			// Member Function: Constructor

			// Default constructor. Constructs an empty container with a default-constructed allocator.
			vector() : _alloc(allocator_type()), _size(0), _capacity(0), _data(NULL), _start(NULL), _end(NULL) {};

			// Constructs an empty container with the given allocator alloc
			explicit vector(const allocator_type& alloc)
				: _alloc(alloc), _size(0), _capacity(0), _data(NULL), _start(NULL), _end(NULL) {
				};

			// Constructs the container with count copies of elements with value value.
			explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) 
				: _alloc(alloc), _size(n), _capacity(n)
			{
				clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}

			// Constructs the container with the contents of the range [first, last).
			template <class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type* = NULL)
			{
				_alloc = alloc;
				clear();
				// const size_t size = ft::distance(first, last);
				// reserve(size);
				for (; first != last; ++first)
					push_back(*first);
			}

			// Copy constructor
			vector(const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
			{
				if (_capacity == 0)
					return ;
				_data = this->_alloc.allocate(this->_capacity);
				// for (pointer q = x._start; q != x._end; ++q)
				// 	push_back(*q);
				for (size_type i = 0; i < this->size(); i++)
					_alloc.construct(&(_data[i]), x[i]);
				_start = _data;
				_end = _data + _size;
			}
			
			// Member Function: Destructor
			~vector()
			{
				for (size_type i = 0; i < this->_size; i++)
				{
					_alloc.destroy(_data + i);
				}
				if (_data)
				{
					_alloc.deallocate(_data, _capacity);
				}
				clear();
			};

			// Member Function: Operator=
			vector& operator=(const vector &other)
			{
				if (this != &other)
				{
					_alloc.deallocate(_start, _capacity);
					_size = other._size;
					_capacity = other._capacity;
					_data = _alloc.allocate(_capacity);
					_start = _data;
					_end = _start + _capacity;
					for (size_type i = 0; i < this->size(); i++)
						_alloc.construct(&(_data[i]), other[i]);
				}
				return (*this);
			};

			// Member Function: Assign
			// Replaces the contents with count copies of value's value
			// count - the new size of container
			// value - the value to initialize elements of the container with
			void assign(size_type count, const T& value)
			{
				clear();
				reserve(count);
				for (size_t i = 0; i < count; ++i)
				{
					push_back(value);
				}
			};

			// Replaces the contents with copies of those in the rage [first, last]. The behaviour is undefined if either argument is an iterator *this.
			template<class InputIt>
			void assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL)
			{
				clear();
				size_type count = ft::distance(first, last);
				reserve(count);
				while (first != last)
				{
					push_back(*first);
					++first;
				}
			};

			// Member Function: Get_allocator
			// Returns the allocator associated with the container.
			allocator_type get_allocator() const
			{
				return (_alloc);
			};

			// Element access

			// Element access: at
			// Returns a reference to element at specific locoation pos with bounds checking. If the pos is not within the range of container, an exception of type std::out_of_range is throw.
			reference at(size_type pos)
			{
				if (!(pos < this->size()))
					throw (std::out_of_range("ft::vector::at::out_of_range"));
				return ((*this)[pos]);
			};

			const_reference at(size_type pos) const
			{
				if (!(pos < this->size()))
					throw (std::out_of_range("ft::vector::at"));
				return ((*this)[pos]);
			};
			
			// Element access: operator []
			reference operator[](size_type index)
			{
				return _data[index];
			};
			
			const_reference operator[](size_type index) const
			{
				return _data[index];
			};

			// Element access: front
			// Element access: back
			reference back()
			{
				return (*(this->end() - 1));
			};

			const_reference back() const
			{
				return (*(this->end() - 1));
			};
			// Element access: data
			
			// Iterators

			// Iterators:begin - return iterator to beginning
			// vector_iterator need to have default constructor
			// that accept the pointer
			iterator begin()
			{
				return (iterator(_start));
			};
			
			const_iterator begin() const
			{
				return (const_iterator(_start));
			};

			// Iterators:end - return iterator to end
			iterator end()
			{
				return (iterator(_end));
			};

			const_iterator end() const
			{
				return (const_iterator(_end));
			};

			// Capacity	

			// Capacity: empty

			// Capacity: size
			size_type size() const { return (_size); }

			// Capacity: max_size
			size_type max_size(void) const { return (_alloc.max_size()); }

			// Capacity:  reserve
			void reserve(size_type new_cap)
			{
				pointer	new_data;
				pointer	p;

				if (new_cap > this->max_size())
					throw (std::length_error("ft::vector::reserve"));
				if (new_cap > _capacity)
				{
					new_data = _alloc.allocate(new_cap);
					p = new_data;
					for (pointer q = _start; q != _end; ++q)
						*p++ = *q;
					_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = new_cap;
					_start = new_data;
					_end = new_data + _size;
				}
			};

			// Capacity: capacity
			size_type capacity() const { return _capacity; };

			// Modifiers

			// Modifiers: clear
			void clear()
			{
				// this->_alloc.deallocate(_data, _capacity);
				// for (size_type i = 0; i < _size; i++)
				// 	_alloc.destroy(&(_data[i]));
				this->_data = nullptr;
				this->_start = nullptr;
				this->_end = nullptr;
				this->_size = 0;
				this->_capacity = 0;
			};
			
			// Modifiers: insert
			// Modifiers: erase

			// Modifiers: push_back
			void	push_back(const T& value)
			{
				if (_capacity == 0)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				*_end++ = value;
				++_size;
			};

			// Modifier: pop_back
			void	pop_back()
			{

			};

			// Modifier: resize
			// Modifier: swap
			void	swap(vector& other)
			{
				ft::swap(_alloc, other._alloc);
				ft::swap(_size, other._size);
				ft::swap(_capacity, other._capacity);
				ft::swap(_data, other._data);
				ft::swap(_start, other._start);
				ft::swap(_start, other._start);
				ft::swap(_end, other._end);
			};

		private:

			allocator_type		_alloc;
			size_type			_size;
			size_type			_capacity;
			T*					_data;
			pointer				_start;
			pointer				_end;

	};

	// Non-member functions
}

#endif
