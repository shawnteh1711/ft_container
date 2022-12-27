/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:08:21 by codespace         #+#    #+#             */
/*   Updated: 2022/12/27 21:07:54 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // for allocator
# include <cstddef> //size_t
# include "./utils/vector_iterator.hpp"
# include <stdio.h>
# include <new>
# include <iterator>

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

			// vector() : _size(0), _capacity(0), _data(NULL) {};
			explicit vector(const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _size(0), _capacity(0), _data(NULL) {};

			explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()) 
				: _alloc(alloc), _size(n), _capacity(n), _data(_alloc.allocate(n))
			{
				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(_data + i, val);
				}		
			}
		
			// this->_end = this->construct_from_start(this->_start, first, last);

			template <class InputIterator, class ForwardIt>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				ForwardIt	_first = first;
				ForwardIt	_last = last;
				size_type	n = std::distance(_first, _last);
				std::cout << "n: " << n <<std::endl;
				if (n == 0)
					return ;
				this->_alloc = alloc;
				this->_start = this->_alloc.allocate(n);
				// std::copy(first, last, _data);
				for ( ; first != last; first++, this->_start++)
				{
					this->_alloc.construct(this->_start, first);
				}
				this->_end = this->_start;
				this->_size = n;
				this->_capacity = this->_start + n;
			}

			vector (const vector& x)
			{
				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_data = this->_alloc.allocate(this->_capacity);
				std::uninitialized_copy(x._data, x._data + this->_size, this->_data);
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
				_size = 0;
				_capacity = 0;
			};

			// Member Function: Operator=

			// Member Function: Assign

			// Member Function: Get_allocator
			// Element access: at
			// Element access: operator []
			T& operator[](size_type index) {
				return _data[index];
			}
			
			const T& operator[](size_type index) const {
				return _data[index];
			}

			// Element access: front
			// Element access: back
			// Element access: data
			// Capacity
			// Size and capacity functions
			size_type size() const { return _size; }
			size_type capacity() const { return _capacity; }

			// Modifiers
			void	push_back(const T& value)
			{
				if (_size == _capacity)
				{
					// std::cout << "size: " << _size << std::endl;
					// std::cout << "capacity: " << _capacity << std::endl;
					size_type   new_capacity = _capacity == 0 ? 1 : _capacity * 2;
					// std::cout << "new_capacity: " << new_capacity << std::endl;
					T* new_data = _alloc.allocate(new_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(new_data + i, _data[i]);
					}
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.destroy(_data + i);
					}
					_alloc.deallocate(_data, _capacity);
					_data = new_data;
					_capacity = new_capacity;

				}
				_alloc.construct(_data + _size, value);
				_size++;
			}

			void	pop_back();

			// Iterators

			// begin: return iterator to beginning
			// vector_iterator need to have default constructor
			// that accept the pointer
			iterator begin()
			{
				return (iterator(this->_start));
			};
			
			const_iterator begin() const
			{
				return (const_iterator(this->_start));
			};

			// end: return iterator to end
			iterator end()
			{
				return (iterator(this->_end));
			};

			const_iterator end() const
			{
				return (const_iterator(this->end));
			};

		private:

		allocator_type		_alloc;
		size_type			_size;
		size_type			_capacity;
		T*					_data;
		pointer				_start;
		pointer				_end;

	};
}

#endif
