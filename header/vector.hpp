/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 03:08:21 by codespace         #+#    #+#             */
/*   Updated: 2022/12/23 19:21:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // for allocator
# include <cstddef>

/**
 * @brief https://en.cppreference.com/w/cpp/container/vector
 * 
 */

namespace ft 
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        
        public:
            // Member types
            typedef T                                                   value_type;
			typedef Allocator                                           allocator_type;
            typedef std::size_t                                         size_type;
            typedef std::ptrdiff_t                                      difference_type;
            typedef value_type&                                         reference;
            typedef const value_type&                                   const_reference;
            typedef std::allocator_traits<Allocator>::pointer           pointer;
            typedef std::allocator_traits<Allocator>::const_pointer     const_pointer;
            typedef vector_iterator<pointer, vector>                    iterator;
            typedef vector_iterator<const pointer, vector>              const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
            
            // Member Function: Constructor
            vector() : _size(0), _capacity(0), _data(NULL) {}
            vector(size_type size) : _size(size), _capacity(size), _data(_alloc.allocate(size)) {}
            
            // Member Function: Destructor
            ~vector()
            {
                for (size_type i = 0; i < _size; i++)
                {
                    _alloc.destroy(_data + i);
                }
                _alloc.deallocate(_data, _capacity); 
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
            void    push_back(const T& value)
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