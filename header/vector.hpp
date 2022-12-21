/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:08:21 by codespace         #+#    #+#             */
/*   Updated: 2022/12/21 05:17:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // for allocator
# include <cstddef>

namespace ft 
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:

            typedef size_t      size_type;
            typedef T           value_type;
			typedef Alloc       allocator_type;

            // Constructor
            vector() : _size(0), _capacity(0), _data(NULL) {}
            vector(size_type size) : _size(size), _capacity(size), _data(_alloc.allocate(size)) {}
            
            // Destructor
            ~vector()
            {
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.destroy(_data + i);
                }
                _alloc.deallocate(_data, _capacity); 
            };
            
            // Size and capacity functions
            size_type size() const { return _size; }
            size_type capacity() const { return _capacity; }

            // Element access functions

            // Modifiers
            void    push_back(const T& value)
            {
                if (_size == _capacity)
                {
                    std::cout << "size: " << _size << std::endl;
                    std::cout << "capacity: " << _capacity << std::endl;
                    size_type   new_capacity = _capacity == 0 ? 1 : _capacity * 2;
                    std::cout << "new_capacity: " << new_capacity << std::endl;
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
            
            void    pop_back();

            // Iterators

        private:

            size_type             _size;
            size_type             _capacity;
            T*                    _data;
            allocator_type        _alloc;
        
        
    };    
}

#endif