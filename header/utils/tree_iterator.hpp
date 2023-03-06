/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:05:24 by steh              #+#    #+#             */
/*   Updated: 2023/03/06 20:11:20 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include "RBTree.hpp"
# include "node.hpp"
# include "type_traits.hpp"
# include "RBTree.algorithms.hpp"

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define BLU "\033[1;34m"
# define RST "\033[0m"

namespace ft
{
	template<typename T>
	class const_tree_iterator;
	template<typename T>
	class tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef T												value_type; 
			typedef std::ptrdiff_t									difference_type;
			typedef value_type										node;
			typedef value_type*										pointer;
			typedef value_type&										reference;
			typedef Node<value_type>*								node_pointer;
			// typedef Node<value_type>								node;
			// typedef Node<value_type>*							tnull_pointer;
			// typedef Node<value_type>&							reference;
		
			// constructor

			tree_iterator() : _current_node(nullptr)
			{
				// std::cout<<"default tree iter constructor"<<std::endl;
			};

			tree_iterator(node_pointer node) : _current_node(node)
			{ 
				// std::cout<<"copy node constructor"<<std::endl;
			};

			// This is copy constructor
			// template <class It> 
			// tree_iterator(const tree_iterator<It>& other) : _current_node(other._current_node)
			// {
			// 	// std::cout<<"tree_iterator copy constructor"<<std::endl;
			// };

			template<class U>
			tree_iterator(tree_iterator<U>& other)
				: _current_node(static_cast<node_pointer>(other.get_node_pointer()))
			{
				// std::cout<<"tree template constructor"<<std::endl;
			}

			~tree_iterator() {}

			tree_iterator& operator=(const tree_iterator& other)
			{
				if (this != &other)
					_current_node = other._current_node;
				return (*this);
			};

			// tree_iterator(pointer ptr) : _current_node(static_cast<node_pointer>(ptr))
			// {
			// 	std::cout<<"pointer constructor"<<std::endl;
			// };

			const node_pointer& base() const
			{
				return (_current_node);
			};

			// dereference operator
			reference & operator*() const
			{
				return (_current_node->data);
			};

			// reference  operator->() const
			// {
			// 	return (&(operator*()));
			// };

			pointer operator->() const
			{
				// std::cout << "operator->" << std::endl;
				return (&_current_node->data);
			}

			tree_iterator& operator++()
			{
				_current_node = _current_node->successor(_current_node);
				return (*this);
			};

			tree_iterator operator++(int)
			{
				tree_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			tree_iterator& operator--()
			{
				_current_node = _current_node->predecessor(_current_node);;
				return (*this);
			};

			tree_iterator operator--(int)
			{
				tree_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator==(const tree_iterator &other) const
			{
				return (_current_node == other._current_node);
			};

			bool operator!=(const tree_iterator &other) const
			{
				return (_current_node != other._current_node);
			};

			bool operator>=(const tree_iterator &other) const
			{
				if (!_current_node)
					return (false);
				return (_current_node >= other._current_node);
			};

			node_pointer get_node_pointer() const
			{
				return (_current_node);
			};

		protected:
			node_pointer		_current_node;
	};

	template<typename T>
	class const_tree_iterator
	{
		public:
	
			typedef std::bidirectional_iterator_tag					iterator_category;
			typedef T												value_type; 
			typedef std::ptrdiff_t									difference_type;
			typedef const value_type								node;
			typedef const value_type*								pointer;
			typedef const value_type&								reference;
			typedef const Node<value_type>*							node_pointer;
		
			// constructor

			const_tree_iterator() : _current_node(nullptr)
			{
				// std::cout<<"default tree iter constructor"<<std::endl;
				
			};

			const_tree_iterator(const node_pointer node) : _current_node(node)
			{
				// std::cout<<"node constructro"<<std::endl;
			};

			// This is copy constructor
			template <class It> 
			const_tree_iterator(const const_tree_iterator<It>& other) : _current_node(other._current_node)
			{
				// std::cout<<"template constructor"<<std::endl;
			};

			template<typename U>
			const_tree_iterator(const tree_iterator<U>& other)
				: _current_node(const_cast<const node_pointer>(other.get_node_pointer()))
			{
				// std::cout<<"template constructor"<<std::endl;
			}


			~const_tree_iterator() {}

			const_tree_iterator& operator=(const const_tree_iterator& other)
			{
				// std::cout<<"const_tree_iterator operator="<<std::endl;
				if (this != &other)
					_current_node = other._current_node;
				return (*this);
			};

			const node_pointer& base() const
			{
				return (_current_node);
			};

			// dereference operator
			reference & operator*() const
			{
				return (_current_node->data);
			};

			pointer operator->() const
			{
				// std::cout << "operator->" << std::endl;
				return (&_current_node->data);
			}


			const_tree_iterator& operator++()
			{
				_current_node = _current_node->successor(_current_node);
				return (*this);
			};

			const_tree_iterator operator++(int)
			{
				const_tree_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			const_tree_iterator& operator--()
			{
				_current_node = _current_node->predecessor(_current_node);
				return (*this);
			};

			const_tree_iterator operator--(int)
			{
				const_tree_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator==(const const_tree_iterator &other) const
			{
				return (_current_node == other._current_node);
			};

			bool operator!=(const const_tree_iterator &other) const
			{
				return (_current_node != other._current_node);
			};

			bool operator>=(const const_tree_iterator &other) const
			{
				if (!_current_node)
					return (false);
				return (_current_node >= other._current_node);
			};

			node_pointer get_node_pointer() const
			{
				return (_current_node);
			};

		protected:
			node_pointer		_current_node;


	};
}

#endif
