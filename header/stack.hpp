/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:49:25 by steh              #+#    #+#             */
/*   Updated: 2023/01/11 16:13:21 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "./utils/pair.hpp"
# include "vector.hpp"

// https://en.cppreference.com/w/cpp/container/stack

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			// Member types
			typedef Container								container_type;
			typedef typename Container::value_type			value_type;
			typedef typename Container::size_type			size_type;
			typedef typename Container::reference			reference;
			typedef typename Container::const_reference		const_reference;

		protected:
			container_type	_c;
		
		public:
			explicit stack( const Container& cont = container_type() );
			stack( const stack& other );
			~stack();
			stack& operator=(const stack& other);
			reference top();
			const_reference top() const;
			bool empty() const;
			size_type size() const;
			void push( const value_type& value );
			void pop();
			// friend is used to access protected member _c
			template <class Type, class C>
			friend bool operator==(const ft::stack<Type, C>& lhs, const ft::stack<Type, C>& rhs)
			{
				return (lhs._c == rhs._c);
			};
			template <class Type, class C>
			friend bool operator<(const ft::stack<Type, C>& lhs, const ft::stack<Type, C>& rhs)
			{
				return (lhs._c < rhs._c);
			};
	};
}

# include "stack.tpp"

#endif
