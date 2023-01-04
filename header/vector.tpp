/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:08:21 by codespace         #+#    #+#             */
/*   Updated: 2023/01/04 20:59:15 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector.hpp"
# include "./utils/vector_iterator.hpp"
# include "./utils/type_traits.hpp"
# include "./utils/algorithm.hpp"
# include "./utils/utility.hpp"

// Member Function: Constructor

// Default constructor. Constructs an empty container with a default-constructed allocator.
template<typename T, typename Alloc>
ft::vector<T, Alloc>::vector() : _alloc(allocator_type()), _size(0), _capacity(0), _data(NULL), _start(NULL), _end(NULL)
{
	return ;
}

// Constructs an empty container with the given allocator alloc
template<typename T, typename Alloc>
ft::vector<T, Alloc>::vector(const allocator_type& alloc)
: _alloc(alloc), _size(0), _capacity(0), _data(NULL), _start(NULL), _end(NULL)
{
	return ;
}

// Constructs the container with count copies of elements with value value.
template<typename T, typename Alloc>
ft::vector<T, Alloc>::vector(size_type n, const value_type& val,
		const allocator_type& alloc)
{
	if (n <= 0 || n > this->max_size())
		return ;
	_alloc = alloc;
	_size = n;
	_capacity = n;
	_data = _alloc.allocate(_capacity);
	_start = _data;
	_end = _data + _size;
	for (size_t i = 0; i < _size; i++)
		_alloc.construct(&_data[i], val);
	// _alloc = alloc;
	// clear();
	// for (size_t i = 0; i < n; i++)
	// 	push_back(val);
}

// Constructs the container with the contents of the range [first, last).
template<typename T, typename Alloc>
template <class InputIt>
ft::vector<T, Alloc>::vector(InputIt first, InputIt last, const allocator_type& alloc, typename ft::enable_if<!ft::is_integral<InputIt>::value, void>::type*) : _data(NULL)
{
	// size_type	count;
	
	// count = ft::distance(first, last);
	// _size = count;
	// _capacity = count;
	// _alloc = alloc;
	// for (; first != last; ++first)
	// 	push_back(*first);
	// const size_t size = ft::distance(first, last);
	// reserve(size);
	// _alloc = alloc;
	// clear();
	// for (; first != last; ++first)
	// 	push_back(*first);


	const size_type size = std::distance(first, last);
	if (size < 0)
		return ;
	_alloc = alloc;
	_data = _alloc.allocate(size);
	_start = _data;
	_end = _data + size;
	_capacity = size;
	_size = size;
	for (InputIt it = first; it != last; ++it)
	{
		_alloc.construct(_start, *it);
		++_start;
	}
}

// Copy constructor
template<typename T, typename Alloc>
ft::vector<T, Alloc>::vector(const vector& x) : _alloc(x._alloc), _size(x._size), _capacity(x._capacity)
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
template<typename T, typename Alloc>
ft::vector<T, Alloc>::~vector()
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
}

// Member Function: Operator=
template<typename T, typename Alloc>
ft::vector<T, Alloc>& ft::vector<T, Alloc>::operator=(const vector &other)
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
}

// Member Function: Assign
// Replaces the contents with count copies of value's value
// count - the new size of container
// value - the value to initialize elements of the container with
template<typename T, typename Alloc>
void ft::vector<T, Alloc>::assign(size_type count, const T& value)
{
	clear();
	reserve(count);
	for (size_t i = 0; i < count; ++i)
	{
		push_back(value);
	}
}

// Replaces the contents with copies of those in the rage [first, last]. The behaviour is undefined if either argument is an iterator *this.
template<typename T, typename Alloc>
template<class InputIt>
void ft::vector<T, Alloc>::assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
{
	clear();
	size_type count = ft::distance(first, last);
	reserve(count);
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

// Member Function: Get_allocator
// Returns the allocator associated with the container.
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::allocator_type ft::vector<T, Alloc>::get_allocator() const
{
	return (_alloc);
}

// Element access

// Element access: at
// Returns a reference to element at specific locoation pos with bounds checking. If the pos is not within the range of container, an exception of typename std::out_of_range is throw.
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::at(size_type pos)
{
	if (!(pos < this->size()))
		throw (std::out_of_range("ft::vector::at::out_of_range"));
	return ((*this)[pos]);
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::at(size_type pos) const
{
	if (!(pos < this->size()))
		throw (std::out_of_range("ft::vector::at"));
	return ((*this)[pos]);
}

// Element access: operator []
// Returns a reference to the element at the specific location pos. No bounds checking is performed.
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::operator[](size_type index)
{
	return (_data[index]);
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::operator[](size_type index) const
{
	return (_data[index]);
}

// Element access: front

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::front()
{
	return (*(this->begin()));
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::front() const
{
	return (*(this->begin()));
}

// Element access: back
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::reference ft::vector<T, Alloc>::back()
{
	return (*(this->end() - 1));
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_reference ft::vector<T, Alloc>::back() const
{
	return (*(this->end() - 1));
}

// Element access: data
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data()
{
	return (_data);
}

template<typename T, typename Alloc>
const typename ft::vector<T, Alloc>::value_type* ft::vector<T, Alloc>::data() const
{
	return (_data);
}
// Iterators

// Iterators:begin - return iterator to beginning
// vector_iterator need to have default constructor
// that accept the pointer
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::begin()
{
	return (iterator(_start));
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::begin() const
{
	return (const_iterator(_start));
}

// Iterators:end - return iterator to end
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::end()
{
	return (iterator(_end));
}


template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_iterator ft::vector<T, Alloc>::end() const
{
	return (const_iterator(_end));
}

// Iterators: rbegin - returns a reverse iterator to the beginning
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin()
{
	return (reverse_iterator(this->end()));
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const
{
	return (reverse_iterator(this->end()));
}

// Iterators: rend - returns a reverse iterator to the end
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::reverse_iterator ft::vector<T, Alloc>::rend()
{
	return (reverse_iterator(this->begin()));
}

template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const
{
	return (reverse_iterator(this->begin()));
}


// Capacity

// Capacity: empty
template<typename T, typename Alloc>
bool ft::vector<T, Alloc>::empty() const
{
	return (this->begin() == this->end());
}

// Capacity: size
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::size() const 
{
	return (_size);
}

// Capacity: max_size
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::max_size(void) const
{
	size_type		max_alloc_size;
	difference_type	max_diff_type;

	max_alloc_size = _alloc.max_size();
	max_diff_type = std::numeric_limits<difference_type>::max();
	return (std::min(max_alloc_size, static_cast<size_type>(max_diff_type)));
}

// Capacity:  reserve
template<typename T, typename Alloc>
void ft::vector<T, Alloc>::reserve(size_type new_cap)
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
}

// Capacity: capacity
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::size_type ft::vector<T, Alloc>::capacity() const
{
	return (_capacity);
}

// Capacity: shrink_to_fit
// Requests the remocal of unused capacity
template<typename T, typename Alloc>
void ft::vector<T, Alloc>::shrink_to_fit()
{
	size_type	new_size;
	T*			new_data;

	if (_size == _capacity)
		return ;
	new_size = _end - _start;
	new_data = _alloc.allocate(new_size);
	for (size_type i = 0; i < new_size; i++)
		_alloc.construct(new_data + i, _data[i]);
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(_data + i);
	_alloc.deallocate(_data, _capacity);
	_data = new_data;
	_start = _data;
	_end = _data + new_size;
	_capacity = new_size;
	_size = new_size;
}

// Modifiers

// Modifiers: clear
template<typename T, typename Alloc>
void ft::vector<T, Alloc>::clear()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(&(_data[i]));
	// this->_alloc.deallocate(_data, _capacity);
	this->_data = nullptr;
	this->_start = nullptr;
	this->_end = nullptr;
	this->_size = 0;
}

// Modifiers: insert

// Insert value before pos
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(const_iterator pos, const value_type& value)
{
	(void)pos;
	(void)value;
	iterator	insert_pos = static_cast<iterator>(pos.base());
	iterator	temp = this->end();
	// ;
	if (_size == _capacity)
		reserve(_capacity == 0 ? 1 : _capacity * 2);
	if (pos == this->end())
	{
		_alloc.construct(_end, value);
		++_end;
		++_size;
		return (iterator(_end - 1));
	}
	else
	{
		_alloc.construct(_end, *(_end) - 1);
		std::copy_backward(insert_pos, temp, this->end());
		*insert_pos = std::move(value);
		++_size;
		++_end;
		return (insert_pos);
		// std::copy_backward(insert_pos, this->end() - 1, this->end());
		// return (ft::vector_iterator<pointer, vector>(_end - 1));

	}
	return (ft::vector_iterator<pointer, vector>(_end - 1));
	// return (pos);
	// if (pos == iterator(_end))
	// {
	// 	_alloc.construct(_end, value);
	// 	++_end;
	// 	++_size;
	// 	return (iterator(_end) - 1);
	// }
	// else
	// {
	// 	_alloc.construct(_end, *(_end - 1));
	// 	std::copy_backward(pos, _end - 1, _end);
	// 	*pos = value;
	// 	++_size;
	// 	++_end;
	// 	return (pos);
	// }
}

// template<typename T, typename Alloc>
// typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(const_iterator pos, value_type& value)
// {
// 	(void)pos;
// 	(void)value;
// 	;
// }

// Insert count copies of the value before pos
template<typename T, typename Alloc>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(const_iterator pos, size_type count, const T& value )
{
	(void)pos;
	(void)count;
	(void)value;
	;
}

// Insert elements from range [first, last) before pos
template<typename T, typename Alloc>
template <class InputIt>
typename ft::vector<T, Alloc>::iterator ft::vector<T, Alloc>::insert(const_iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type*)
{
	(void)pos;
	(void)first;
	(void)last;
	;
}
// Modifiers: erase

// Modifiers: push_back
template<typename T, typename Alloc>
void	ft::vector<T, Alloc>::push_back(const T& value)
{
	if (_capacity == 0)
		reserve(1);
	else if (_size == _capacity)
		reserve(_capacity * 2);
	*_end++ = value;
	++_size;
}

// Modifier: pop_back
template<typename T, typename Alloc>
void	ft::vector<T, Alloc>::pop_back()
{

}

// Modifier: resize
template<typename T, typename Alloc>
void	ft::vector<T, Alloc>::resize(size_type count)
{
	(void)count;
	if (count > _size)
		;
		// insert elements to increase size
	else if (count < _size)
		// erase elements to decrease size
		;
}

template<typename T, typename Alloc>
void	ft::vector<T, Alloc>::resize(size_type count, const value_type& value)
// void	ft::vector<T, Alloc>::resize(size_type count, const value_type& value, typename ft::enable_if<ft::is_integral<T>::value>::type*)
{
	(void)count;
	(void)value;
}

// Modifier: swap
template<typename T, typename Alloc>
void	ft::vector<T, Alloc>::swap(vector& other)
{
	ft::swap(_alloc, other._alloc);
	ft::swap(_size, other._size);
	ft::swap(_capacity, other._capacity);
	ft::swap(_data, other._data);
	ft::swap(_start, other._start);
	ft::swap(_start, other._start);
	ft::swap(_end, other._end);
}


