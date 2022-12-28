/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 06:43:01 by codespace         #+#    #+#             */
/*   Updated: 2022/12/28 20:59:37 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <typename Iter, typename Container>
	class vector_iterator
	{
		public:
			typedef Iter												iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iter>::value_type			value_type;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef typename iterator_traits<Iter>::reference			reference;


		vector_iterator() : _iter(iterator_type()){};
		explicit vector_iterator(const iterator_type& iter) : _iter(iter) {};
		// constructor accept pointer
		// vector_iterator(pointer ptr): _ptr(ptr) {}
		// vector_iterator(iterator_type &other): _ptr(other._ptr) {}
		template <class It>

		// template type constructor
		
		vector_iterator(const vector_iterator<It, typename std::enable_if<std::is_same<It, typename Container::pointer>::value, Container>::type>& iter) : _iter(iter.base()) {};
		~vector_iterator() {};

		vector_iterator &operator=(const vector_iterator& other)
		{
			if (this == &other)
				return (*this);
			this->_iter = other._iter;
			return (*this);
		};

		const iterator_type &base() const
		{
			return (this->_iter);
		};
		
		reference operator*() const
		{
			return (*this->_iter);
		};

		pointer operator->() const
		{
			return (this->_iter);
		};

		reference operator[] (difference_type n) const
		{
			return (*(this->_iter + n));
		};

		vector_iterator& operator++()
		{
			this->_iter++;
			return (*this);
		};

		vector_iterator& operator--()
		{
			this->_iter--;
			return (*this);
		};

		vector_iterator operator++(int)
		{
			return (vector_iterator(_iter++));
		};

		vector_iterator operator--(int)
		{
			return (vector_iterator(_iter--));
		};

		vector_iterator operator+(difference_type n) const
		{
			return (vector_iterator(this->_iter + n));
		};

		vector_iterator operator-(difference_type n) const
		{
			return (vector_iterator(this->_iter - n));
		};

		vector_iterator& operator+=(difference_type n)
		{
			this->_iter += n;
			return (*this);
		};

		vector_iterator& operator-=(difference_type n)
		{
			this->_iter -= n;
			return (*this);
		};

		protected:
			pointer	_ptr;
			Iter	_iter;
	};

	template <class Iterator1, class Iterator2, class Container>
	bool operator==(const vector_iterator<Iterator1, Container>& lhs,
					const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator1, class Iterator2, class Container>
	bool operator!=(const vector_iterator<Iterator1, Container>& lhs,
					const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator1, class Iterator2, class Container>
	bool operator<(const vector_iterator<Iterator1, Container>& lhs,
					const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator1, class Iterator2, class Container>
	bool operator<=(const vector_iterator<Iterator1, Container>& lhs,
					const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator1, class Iterator2, class Container>
	bool operator>(const vector_iterator<Iterator1, Container>& lhs,
					const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template <class Iterator1, class Iterator2, class Container>
	bool operator>=(const vector_iterator<Iterator1, Container>& lhs,
					const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	// Advances the iterator
	template <class Iterator, class Container>
	bool operator+(typename vector_iterator<Iterator, Container>::difference_type n,
					const vector_iterator<Iterator, Container>& it)
	{
		return (vector_iterator<Iterator, Container>(it.base() + n));
	}

	// Computes the distance
	template  <class Iterator1, class Iterator2, class Container>
	typename vector_iterator<Iterator1, Container>::difference_type operator-(const vector_iterator<Iterator1, Container>& lhs,
																				const vector_iterator<Iterator2, Container>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

# endif
