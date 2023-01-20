/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:18:59 by steh              #+#    #+#             */
/*   Updated: 2023/01/12 19:22:19 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "stack.hpp"
# include "./utils/vector_iterator.hpp"
# include "./utils/type_traits.hpp"
# include "./utils/algorithm.hpp"
# include "./utils/pair.hpp"
// # include "./utils/utility.hpp"

template <class T, class Container>
ft::stack<T, Container>::stack( const Container& cont) : _c(cont)
{
	return ;
}

template <class T, class Container>
ft::stack<T, Container>::stack( const stack& other ) : _c(other._c)
{
	return ;
}

template <class T, class Container>
ft::stack<T, Container>::~stack()
{
	while(!_c.empty())
	{
		_c.pop_back();
	}
	_c.clear();
	return ;
}

template <class T, class Container>
ft::stack<T, Container>& ft::stack<T, Container>::operator=(const stack& other)
{
	if (this != &other)
		_c = other._c;
	return (*this);
}

template <class T, class Container>
typename ft::stack<T, Container>::reference ft::stack<T, Container>::top()
{
	return (_c.back());
}

template <class T, class Container>
typename ft::stack<T, Container>::const_reference ft::stack<T, Container>::top() const
{
	return (_c.back());
}

template <class T, class Container>
bool ft::stack<T, Container>::empty() const
{
	return (_c.empty());
}

template <class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
	return (_c.size());
}

template <class T, class Container>
void ft::stack<T, Container>::push( const value_type& value )
{
	_c.push_back(value);
}

template <class T, class Container>
void ft::stack<T, Container>::pop()
{
	_c.pop_back();
}

// template <class T, class Container>
// bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
// {
// 	return (lhs._c == rhs._c);
// }

template <class T, class Container>
bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (!(lhs == rhs));
}

// template <class T, class Container>
// bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
// {
// 	return (lhs._c < rhs._c);
// }

template <class T, class Container>
bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (!(rhs < lhs));
}

template <class T, class Container>
bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs)
{
	return (!(lhs < rhs));
}
